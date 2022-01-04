// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ProcGenGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class AGPPROCEDURALPROJECT_API UProcGenGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int newSeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int finalScore;
};
