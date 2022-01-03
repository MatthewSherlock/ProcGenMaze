// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemy.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
ASpawnEnemy::ASpawnEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Use a Box for the spawn volume.
	whereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	whereToSpawn->SetBoxExtent(FVector(200.0, 200.0, 10.0));
	whereToSpawn->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ASpawnEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnEnemy::getRandomPtInVolume()
{
	FVector spawnOrigin = whereToSpawn->Bounds.Origin;
	FVector spawnExtent = whereToSpawn->Bounds.BoxExtent;
	return UKismetMathLibrary::RandomPointInBoundingBox(spawnOrigin, spawnExtent);
}

void ASpawnEnemy::SpawnEnemy(TSubclassOf<class AActor> enemy)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = GetInstigator();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	FVector spawnLoc = getRandomPtInVolume();
	FRotator rot = FRotator::ZeroRotator;
	AActor* a = GetWorld()->SpawnActor<AActor>(enemy, spawnLoc, rot, spawnParams);

	if (a == nullptr)
	{
		SpawnEnemy(enemyToSpawn);
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "spawnPickup");

}