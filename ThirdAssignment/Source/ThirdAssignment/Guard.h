// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Guard.generated.h"

class APatrollPoint;
class AThirdAssignmentCharacter;
class AGameManager;


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

	UPROPERTY(EditAnywhere, Category = "Aspect")
	UStaticMeshComponent* StaticMesh;


	UPROPERTY(EditAnywhere, Category = "Movement")
	int speed = 400;
	UPROPERTY(EditAnywhere, Category = "Movement")
	TArray<APatrollPoint*> patrollPoints;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float changePatrollPointDistance = 10.0f;

	// In degrees. Angle of vision, from forward to the sides (the total angle is double this)
	UPROPERTY(EditAnywhere, Category = "Vision")
	float visionAngle = 45.0f;

	UPROPERTY(EditAnywhere, Category = "Vision")
	float visionRange = 1000.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	int destinationIndex = 0;
	AThirdAssignmentCharacter* player;
	AGameManager* gameManager;

	void patrollPointReached();
	void move(float DeltaTime);
	void checkRaycast();

};
