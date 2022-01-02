// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPickup.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
ASpawnPickup::ASpawnPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Use a Box for the spawn volume.
	whereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	whereToSpawn->SetBoxExtent(FVector(200.0, 200.0, 10.0));
	whereToSpawn->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpawnPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ASpawnPickup::getRandomPtInVolume()
{
	FVector spawnOrigin = whereToSpawn->Bounds.Origin;
	FVector spawnExtent = whereToSpawn->Bounds.BoxExtent;
	return UKismetMathLibrary::RandomPointInBoundingBox(spawnOrigin, spawnExtent);
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

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "spawnPickup");

}

// Called every frame
void ASpawnPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

