// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Disabler.generated.h"


UCLASS()
class THIRDASSIGNMENT_API ADisabler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisabler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Aspect")
	UStaticMeshComponent* StaticMesh;

	//UFUNCTION()
	void NotifyHit
	(
		class UPrimitiveComponent * MyComp,
		AActor * Other,
		class UPrimitiveComponent * OtherComp,
		bool bSelfMoved,
		FVector HitLocation,
		FVector HitNormal,
		FVector NormalImpulse,
		const FHitResult & Hit
	);

	// To be set from the player that throws it
	AActor* player;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
