// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnTiles.h"
#include "Tile.h"
#include "Goal.h"
#include "ProcGenGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpawnTiles::ASpawnTiles() {
	// Set this actor to call Tick() every frame.  
	PrimaryActorTick.bCanEverTick = false;
	xGap = yGap = 10.0f;
	xStart = yStart = zStart = 0.0f;
	numHorizTiles = numVertTiles = 5;

	grid = CreateDefaultSubobject<AGridLevel>(TEXT("grid"));
}

// Called when the game starts or when spawned
void ASpawnTiles::BeginPlay()
{
	Super::BeginPlay();
	UProcGenGameInstance* GameInstanceRef = Cast<UProcGenGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	grid->initConnections(numHorizTiles, numVertTiles);
	TArray<FConnections> connections = grid->createGrid(GameInstanceRef->newSeed, FVector2D(0, 0)); //start with seed, and init cell
	FString newSeedAsString = FString::FromInt(GameInstanceRef->newSeed);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, newSeedAsString);


	RandomStream.Initialize(GameInstanceRef->newSeed);
	int goalPos = RandomStream.RandRange(numHorizTiles * numVertTiles / 2, numHorizTiles * numVertTiles - 1);
	for (int i = 0; i < connections.Num(); i++) {
		int x = xStart + float(i % numHorizTiles) * xGap;
		int y = yStart + float(i / numHorizTiles) * yGap;
		if (i == goalPos) {
			spawnGoal(goal, x, y, zStart);
			continue; //get out of loop, but carry on
		}
		spawnATile(floorTile, x, y, zStart);
		for (int j = 0; j < 4; j++) {
			int dx = grid->NEIGHBOURS[j].dx;
			int dy = grid->NEIGHBOURS[j].dy;
			int idx = grid->NEIGHBOURS[j].index;
			if (connections[i].directions[j] != 1) {
				if (dx != 0)
					spawnATile(vertWall, x + (float)dx * (xGap + 2.0f) / 2.0f, y, zStart);
				else
					spawnATile(horizWall, x, y + (float)dy * (yGap + 2.0f) / 2.0f, zStart);
			}
		}
	}
}

// Called every frame
void ASpawnTiles::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void ASpawnTiles::spawnATile(TSubclassOf<class ATile>tileClass, float x, float y, float z) {
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = GetInstigator();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	FVector spawnLoc = FVector(x, y, z);
	FRotator rot = FRotator::ZeroRotator;
	AActor* a = GetWorld()->SpawnActor<ATile>(tileClass, spawnLoc, rot, spawnParams);

}

void ASpawnTiles::spawnGoal(TSubclassOf<class AGoal> goalClass, float x, float y, float z) {
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = GetInstigator();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	FVector spawnLoc = FVector(x, y, z);
	FRotator rot = FRotator::ZeroRotator;
	AActor* a = GetWorld()->SpawnActor<AGoal>(goalClass, spawnLoc, rot, spawnParams);
}

void ASpawnTiles::changeSeed(int newSeed)
{
	if(newSeed)
		seed = newSeed;
}



