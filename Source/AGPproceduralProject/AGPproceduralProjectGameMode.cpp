// Copyright Epic Games, Inc. All Rights Reserved.

#include "AGPproceduralProjectGameMode.h"
#include "AGPproceduralProjectHUD.h"
#include "AGPproceduralProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h" //for ActorIterator


AAGPproceduralProjectGameMode::AAGPproceduralProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAGPproceduralProjectHUD::StaticClass();
}

void AAGPproceduralProjectGameMode::BeginPlay() {
	Super::BeginPlay();

		for (TActorIterator<ASpawnPickup> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			spawner = *ActorItr;
			SpawnPickups(spawner);
		}
}

void AAGPproceduralProjectGameMode::SpawnPickups(ASpawnPickup* pspawn)
{
	if (pspawn)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "pspawn");

		pspawn->SpawnPickup(pspawn->pickupArray[RandomNumInArray(pspawn)]);
	}

}

int AAGPproceduralProjectGameMode::RandomNumInArray(ASpawnPickup* pspawn)
{
	int randArrayNum = FMath::RandRange(0, pspawn->pickupArray.Num() - 1);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan,pspawn->GetName());
	return randArrayNum;
}