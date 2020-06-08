// Fill out your copyright notice in the Description page of Project Settings.


#include "Guard.h"
#include "PatrollPoint.h"
#include "ThirdAssignmentCharacter.h"
#include "GameManager.h"


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

	for (TActorIterator<AGameManager> It(world, AGameManager::StaticClass()); It; ++It) {
		gameManager = *It;
	}

	if (!gameManager)
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, "GameManager has not been found");
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
	// Compute points
	FVector destination3D = patrollPoints[destinationIndex]->GetActorLocation();
	FVector location3D = GetActorLocation();

	// Compute diff vector
	FVector2D diffVector = FVector2D(destination3D.X, destination3D.Y) - FVector2D(location3D.X, location3D.Y);

	// Compute velocity
	FVector2D direction(diffVector);
	direction.Normalize();
	FVector velocity = FVector(direction * speed, 0) * DeltaTime;
	FVector newPosition = location3D + velocity;

	// Compute new transform (forward in speed direction)
	FQuat newRotation = FQuat::MakeFromEuler(FVector(0, 0, atan2(direction.Y, direction.X) * 180 / PI));

	// Update position and rotation
	FTransform transform = GetActorTransform();

	transform.SetRotation(newRotation);
	transform.SetLocation(newPosition);

	SetActorTransform(transform);
	

	// Check if the actor has rached the destination
	if (diffVector.Size() < changePatrollPointDistance) {
		patrollPointReached();
	}
}

void AGuard::checkRaycast() {

	// Get player and guard location
	FVector target = player->GetActorLocation();
	FVector origin = GetActorLocation();

	// Compute angle between forward and ray direction
	FVector rayDirection = target - origin;
	FVector2D rayDirection2D = FVector2D(rayDirection.X, rayDirection.Y);
	rayDirection2D.Normalize();

	FVector actorForward = GetActorForwardVector();
	FVector2D actorForward2D = FVector2D(actorForward.X, actorForward.Y);
	actorForward2D.Normalize();

	float dotProduct = FVector2D::DotProduct(actorForward2D, rayDirection2D);
	float playerAngle = acos(dotProduct) * 180 / PI;

	// Compute player distance from guard
	float playerDistance = FVector::Dist(target, origin);

	// If the player is out of the guard's vision, don't bother throwing the ray
	if (playerAngle > visionAngle || playerDistance > visionRange)
		return;

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

	if (playerFound){
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, FString::Printf(TEXT("The player is in -> x: %f, y: %f"), target.X, target.Y));
		gameManager->OnPlayerSpotted();
	}

}

// Called every frame
void AGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If there are no patroll points the guard is static, don't attempt to move him
	if (patrollPoints.Num() != 0) {
		move(DeltaTime);
	}
	if(!gameManager->timeStopped)
		checkRaycast();

}

