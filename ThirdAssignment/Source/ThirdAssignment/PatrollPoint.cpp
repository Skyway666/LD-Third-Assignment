// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrollPoint.h"

// Sets default values
APatrollPoint::APatrollPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	transform = CreateDefaultSubobject<USceneComponent>("Transform");
}

// Called when the game starts or when spawned
void APatrollPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrollPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

