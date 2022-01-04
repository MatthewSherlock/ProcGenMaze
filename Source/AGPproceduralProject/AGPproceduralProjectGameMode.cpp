// Copyright Epic Games, Inc. All Rights Reserved.

#include "AGPproceduralProjectGameMode.h"
#include "AGPproceduralProjectHUD.h"
#include "AGPproceduralProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h" //for ActorIterator
#include "ProcGenGameState.h"
#include "ProcGenGameInstance.h"
#include "Kismet/GameplayStatics.h"

AAGPproceduralProjectGameMode::AAGPproceduralProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAGPproceduralProjectHUD::StaticClass();
}

void AAGPproceduralProjectGameMode::BeginPlay() {
	Super::BeginPlay();

		for (TActorIterator<ASpawnPickup> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			
			spawner = *ActorItr;
			for (int i = 0; i < spawner->numOfPickups; i++)
				SpawnPickups(spawner);
		}
		for (TActorIterator<ASpawnEnemy> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			enemySpawner = *ActorItr;
			SpawnEnemy(enemySpawner);
		}
		GetWorldTimerManager().SetTimer(secondsTimer, this, &AAGPproceduralProjectGameMode::UpdateTimer, 1.0f, true);
}

void AAGPproceduralProjectGameMode::SpawnPickups(ASpawnPickup* pspawn)
{
	if (pspawn)
	{

		pspawn->SpawnPickup(pspawn->pickupArray[RandomNumInArray(pspawn)]);
	}

}

int AAGPproceduralProjectGameMode::RandomNumInArray(ASpawnPickup* pspawn)
{
	int randArrayNum = FMath::RandRange(0, pspawn->pickupArray.Num() - 1);
	
	return randArrayNum;
}

void AAGPproceduralProjectGameMode::SpawnEnemy(ASpawnEnemy* espawn)
{
	if (espawn)
	{
		espawn->SpawnEnemy(espawn->enemyToSpawn);
	}

}

void AAGPproceduralProjectGameMode::UpdateTimer()
{
	AProcGenGameState* gs = GetGameState<AProcGenGameState>();
	gs->gameTime += 1.0f;	//incr time
}

void AAGPproceduralProjectGameMode::CalculateFinalScore()
{
	AProcGenGameState* gs = GetGameState<AProcGenGameState>();
	AAGPproceduralProjectCharacter* chr = Cast<AAGPproceduralProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	UProcGenGameInstance* gi = Cast<UProcGenGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	totalScore = (gs->gameTime);

	gi->finalScore = totalScore;
}
