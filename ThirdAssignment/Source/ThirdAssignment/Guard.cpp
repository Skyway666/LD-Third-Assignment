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
	GetWorldTimerManager().SetTimer(timerHandle, this, &AGuard::InvertSpeed, changeDirectionInterval, true, 0.0f);
}

// Inverts speed
void AGuard::InvertSpeed() {
	speed = -speed;
}

// Called every frame
void AGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();

	newLocation.X += speed * DeltaTime;
	SetActorLocation(newLocation);

}

