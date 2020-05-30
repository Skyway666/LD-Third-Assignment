// Fill out your copyright notice in the Description page of Project Settings.


#include "Guard.h"
#include "PatrollPoint.h"
#include "ThirdAssignmentCharacter.h"


#include "EngineUtils.h"
#include "DrawDebugHelpers.h"





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

	//FTimerHandle timerHandle;
	//GetWorldTimerManager().SetTimer(timerHandle, this, &AGuard::UpdateDestinationIndex, changeDirectionInterval, true, 0.0f);

	UWorld* world = GetWorld();

	for (TActorIterator<AThirdAssignmentCharacter> It(world, AThirdAssignmentCharacter::StaticClass()); It; ++It) {
		player = *It;
	}

	if(!player)
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, "Player has not been found");
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

	destinationIndex++;

	if (destinationIndex == patrollPoints.Num()) {
		destinationIndex = 0;
	}
}
void AGuard::move(float DeltaTime) {
	if (patrollPoints.Num() == 0) {
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, "Array has not been initialized yet");
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

void AGuard::checkRaycast() {

	// Get player location and display in 
	FVector target = player->GetActorLocation();
	FVector origin = GetActorLocation();
	TArray<FHitResult> hits;
	FCollisionQueryParams result;

	bool hitCube = GetWorld()->LineTraceMultiByChannel(hits, target, origin, ECollisionChannel::ECC_Visibility, result);

	DrawDebugLine(GetWorld(), target, origin, FColor::Red, false, 2.0f);

	bool playerFound = true;
	for (auto& hit : hits) {
		FString hitActorName = *hit.GetActor()->GetName();

		// The guard has found himself, ignore it
		if (hitActorName == GetName())
			continue;


		// If anything but the guard itself is found, there is something blocking the raycast to the player
		playerFound = false;
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, FString::Printf(TEXT("I see: %s, can't find player :("), *hitActorName));
		DrawDebugBox(GetWorld(), hit.ImpactPoint, FVector(5, 5, 5), FColor::Emerald, false, 2.0f);

	}

	if (playerFound)
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, FString::Printf(TEXT("The player is in -> x: %f, y: %f"), target.X, target.Y));


}

// Called every frame
void AGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	move(DeltaTime);
	checkRaycast();

}

