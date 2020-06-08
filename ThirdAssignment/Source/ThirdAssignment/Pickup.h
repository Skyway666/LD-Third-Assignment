// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

class UShapeComponent;

UENUM()
enum PickupType {
	TIME_STOP UMETA(DisplayName = "Time Stop"),
	DISABLER  UMETA(DisplayName = "Disabler")
};

UCLASS()
class THIRDASSIGNMENT_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	UPROPERTY(EditAnywhere, Category = "Transform")
	USceneComponent* transform;

	UPROPERTY(EditAnywhere, Category = "Aspect")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Collision")
	UShapeComponent* collider;

	UPROPERTY(EditAnywhere, Category = "Logic")
	TEnumAsByte<PickupType> pickupType;

	UFUNCTION()
	void OnPlayerTouchPickup(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
