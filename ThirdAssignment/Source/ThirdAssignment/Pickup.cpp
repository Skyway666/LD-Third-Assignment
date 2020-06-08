// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"

#include "ThirdAssignmentCharacter.h"
#include "Components/ShapeComponent.h"
#include "Components/BoxComponent.h"




// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	transform = CreateDefaultSubobject<USceneComponent>("Transform");
	RootComponent = transform;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->AttachToComponent(transform, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	collider = CreateDefaultSubobject<UBoxComponent>("Collider");
	collider->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnPlayerTouchPickup);
	collider->AttachToComponent(transform, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickup::OnPlayerTouchPickup(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult) {
	
	// Ignore actors which are not named player. This is awful, I should be setting the collision channels, or at least filtering by type, but I don't feel like it.
	if (*otherActor->GetName() != FString("Player"))
		return;

	AThirdAssignmentCharacter* player = (AThirdAssignmentCharacter*)otherActor;
	switch (pickupType) {
		case PickupType::TIME_STOP: 
		{
			player->timeStopCharges++;
			break;
		}
		case PickupType::DISABLER:
		{
			player->disablerCharges++;
			break;
		}
	}

	Destroy();
}
