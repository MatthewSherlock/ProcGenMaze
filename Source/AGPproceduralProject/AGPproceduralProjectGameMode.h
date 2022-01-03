// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpawnPickup.h"
#include "SpawnEnemy.h"
#include "AGPproceduralProjectGameMode.generated.h"

UCLASS(minimalapi)
class AAGPproceduralProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAGPproceduralProjectGameMode();

	virtual void BeginPlay() override;

	void SpawnPickups(ASpawnPickup* pspawn);

	int RandomNumInArray(ASpawnPickup* pspawn);

	void SpawnEnemy(ASpawnEnemy* pspawn);


	UPROPERTY(EditAnywhere)
		ASpawnPickup* spawner;


	UPROPERTY(EditAnywhere)
		ASpawnEnemy* enemySpawner;

	FTimerHandle gameTimer;
	FTimerHandle secondsTimer;
	void UpdateTimer();

	UPROPERTY(EditAnywhere)
		float gameDuration;

	UFUNCTION(BlueprintCallable)
		void CalculateFinalScore();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Score)
		float totalScore;
};



