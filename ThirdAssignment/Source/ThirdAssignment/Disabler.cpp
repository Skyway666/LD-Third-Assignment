// Fill out your copyright notice in the Description page of Project Settings.


#include "Disabler.h"
#include "UObject/ConstructorHelpers.h"

#include "Guard.h"

// Sets default values
ADisabler::ADisabler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetSimulatePhysics(true);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ball(TEXT
	("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	if (ball.Succeeded()) {
		StaticMesh->SetStaticMesh(ball.Object);
		StaticMesh->SetWorldScale3D(FVector(0.3f));
		StaticMesh->SetNotifyRigidBodyCollision(true);
	}


	// TODO: Configure collision to call a function that disables the guard (if collided with one) and destroys the ball

}

// Called when the game starts or when spawned
void ADisabler::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->AddImpulse(GetActorForwardVector() * 2500.0f, "None", true);
	
}

void ADisabler::NotifyHit(UPrimitiveComponent * MyComp, AActor * otherActor, UPrimitiveComponent * OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult & Hit) {
	GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, FString::Printf(TEXT("I collided with %s"), *otherActor->GetName()));

	if (otherActor->Tags.Num() != 0) {
		if(otherActor->Tags[0] == "GUARD")
			((AGuard*)otherActor)->Disable(5.0f);

		if (otherActor->Tags[0] == "PLAYER")
			return; // Don't destroy disabler on collision with player
	}
		

	Destroy();
}


// Called every frame
void ADisabler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

