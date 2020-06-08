// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DetectionLaser.generated.h"

class APatrollPoint;
class AGameManager;

UCLASS()
class THIRDASSIGNMENT_API ADetectionLaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADetectionLaser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Patrolling")
	APatrollPoint* laserEnd = nullptr;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AGameManager* gameManager;

};
