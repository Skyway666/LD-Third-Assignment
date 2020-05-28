// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Guard.generated.h"

UCLASS()
class THIRDASSIGNMENT_API AGuard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
	int speed = 50;

	// In seconds. Time before the speed is reverted
	UPROPERTY(EditAnywhere, Category = "Movement")
	float changeDirectionInterval = 2.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InvertSpeed();

};
