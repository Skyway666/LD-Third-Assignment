// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrollPoint.generated.h"

UCLASS()
class THIRDASSIGNMENT_API APatrollPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrollPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Transform")
	USceneComponent* transform;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
