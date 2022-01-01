// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPickup.h"

// Sets default values
ASpawnPickup::ASpawnPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ASpawnPickup::getRandomPtInVolume()
{
	return FVector();
}

void ASpawnPickup::SpawnPickup(TSubclassOf<class AActor> pickup)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = GetInstigator();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	FVector spawnLoc = getRandomPtInVolume();
	FRotator rot = FRotator::ZeroRotator;
	AActor* a = GetWorld()->SpawnActor<AActor>(pickup, spawnLoc, rot, spawnParams);
}

// Called every frame
void ASpawnPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

