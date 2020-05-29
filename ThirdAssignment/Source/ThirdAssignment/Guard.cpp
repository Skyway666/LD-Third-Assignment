// Fill out your copyright notice in the Description page of Project Settings.


#include "Guard.h"


// Sets default values
AGuard::AGuard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	

}

// Called when the game starts or when spawned
void AGuard::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle timerHandle;
	//GetWorldTimerManager().SetTimer(timerHandle, this, &AGuard::UpdateDestinationIndex, changeDirectionInterval, true, 0.0f);
}

// Inverts speed
//void AGuard::UpdateDestinationIndex() {
//	//speed = -speed;
//
//	if (patrollPoints.Num() == 0){
//		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Black, "Array has not been initialized yet");
//		return;
//	}
//
//	switch(destinationIndex){
//		case 0: 
//			destinationIndex = 1;
//			break;
//		case 1: 
//			destinationIndex = 0;
//			break;
//	}
//
//	SetActorLocation(patrollPoints[destinationIndex]->GetActorLocation());
//
//}

void AGuard::patrollPointReached() {

	switch(destinationIndex){
	case 0: 
		destinationIndex = 1;
		break;
	case 1: 
		destinationIndex = 0;
		break;
	}
}

// Called every frame
void AGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (patrollPoints.Num() == 0) {
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Black, "Array has not been initialized yet");
		return;
	}

	// Compute points
	FVector destination3D = patrollPoints[destinationIndex]->GetActorLocation();
	FVector location3D = GetActorLocation();

	// Compute diff vector
	FVector2D diffVector = FVector2D(destination3D.X, destination3D.Y) - FVector2D(location3D.X, location3D.Y);

	// Compute velocity
	FVector2D direction(diffVector);
	direction.Normalize();
	FVector velocity = FVector(direction * speed, 0) * DeltaTime;

	// Update position
	SetActorLocation(location3D + velocity);

	// Check if the actor has rached the destination
	if (diffVector.Size() < 1.0f) {
		patrollPointReached();
	}
}

