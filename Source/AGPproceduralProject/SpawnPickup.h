// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.h"
#include "SpawnPickup.generated.h"

UCLASS()
class AGPPROCEDURALPROJECT_API ASpawnPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPickup();

	UPROPERTY(EditAnywhere)
		class UBoxComponent* whereToSpawn;

	FVector getRandomPtInVolume();

	void SpawnPickup(TSubclassOf<class AActor> pickup);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<class APickupBase>> pickupArray;

	UPROPERTY(EditAnywhere)
		int numOfPickups;

};
