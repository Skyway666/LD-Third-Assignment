// Fill out your copyright notice in the Description page of Project Settings.


#include "Disabler.h"
#include "UObject/ConstructorHelpers.h"

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
	}
	else
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, "FUCK");
	// TODO: Configure collision to call a function that disables the guard (if collided with one) and destroys the ball

}

// Called when the game starts or when spawned
void ADisabler::BeginPlay()
{
	Super::BeginPlay();

	// TODO: Impulse the ball in the forward direction of the player that owns it
	
}

// Called every frame
void ADisabler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

