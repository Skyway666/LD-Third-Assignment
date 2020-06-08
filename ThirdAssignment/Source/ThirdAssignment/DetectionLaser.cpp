// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectionLaser.h"
#include "PatrollPoint.h"
#include "GameManager.h"

#include "EngineUtils.h"
#include "DrawDebugHelpers.h"

// Sets default values
ADetectionLaser::ADetectionLaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");

}

// Called when the game starts or when spawned
void ADetectionLaser::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();

	for (TActorIterator<AGameManager> It(world, AGameManager::StaticClass()); It; ++It) {
		gameManager = *It;
	}
	
}

// Called every frame
void ADetectionLaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!laserEnd) {
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, "Laser is not initialized, skipping frame");
		return;
	}


	// Get player and guard location
	FVector target = laserEnd->GetActorLocation();
	FVector origin = GetActorLocation();

	DrawDebugLine(GetWorld(), target, origin, gameManager->timeStopped ? FColor::Blue : FColor::Red, false, 0.1, '\000', 5.0f);

	// If time is stopped player can't be detected
	if (gameManager->timeStopped)
		return;


	FHitResult hit;
	FCollisionQueryParams result;

	// Player is the only pawn, so a LineTraceSingle, in the pawn channel should do
	if (GetWorld()->LineTraceSingleByObjectType(hit, origin, target, ECollisionChannel::ECC_Pawn, result))
		gameManager->OnPlayerSpotted();
	

}

