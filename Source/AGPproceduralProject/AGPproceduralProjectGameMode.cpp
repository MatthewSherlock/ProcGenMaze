// Copyright Epic Games, Inc. All Rights Reserved.

#include "AGPproceduralProjectGameMode.h"
#include "AGPproceduralProjectHUD.h"
#include "AGPproceduralProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAGPproceduralProjectGameMode::AAGPproceduralProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAGPproceduralProjectHUD::StaticClass();
}
