// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ProcGenGameState.generated.h"

/**
 * 
 */
UCLASS()
class AGPPROCEDURALPROJECT_API AProcGenGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AProcGenGameState();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Timer)
		float gameTime;
};
