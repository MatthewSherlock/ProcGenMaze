// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridLevel.h"
#include "SpawnTiles.generated.h"

UCLASS()
class AGPPROCEDURALPROJECT_API ASpawnTiles : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnTiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere, Category = Tile)
		AGridLevel* grid;

	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> floorTile;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class AGoal> goal;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> vertWall;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> horizWall;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		int seed;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		int numHorizTiles;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		int numVertTiles;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float xGap;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float yGap;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float xStart;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float yStart;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float zStart;
	void spawnATile(TSubclassOf<class ATile> tileClass, float x, float y, float z);
	void spawnGoal(TSubclassOf<class AGoal> goalClass, float x, float y, float z);


	UFUNCTION(BlueprintCallable)
		void changeSeed(int newSeed);

	FRandomStream RandomStream;

};
