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
	GetWorldTimerManager().SetTimer(timerHandle, this, &AGuard::UpdateDestinationIndex, changeDirectionInterval, true, 0.0f);
}

// Inverts speed
void AGuard::UpdateDestinationIndex() {
	//speed = -speed;

	if (patrollPoints.Num() == 0){
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Black, "Array has not been initialized yet");
		return;
	}

	switch(destinationIndex){
		case 0: 
			destinationIndex = 1;
			break;
		case 1: 
			destinationIndex = 0;
			break;
	}

	SetActorLocation(patrollPoints[destinationIndex]->GetActorLocation());

}

// Called every frame
void AGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector newLocation = GetActorLocation();

	//newLocation.X += speed * DeltaTime;
	//SetActorLocation(newLocation);
}

