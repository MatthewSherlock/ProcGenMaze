// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AGPproceduralProjectHUD.generated.h"

UCLASS()
class AAGPproceduralProjectHUD : public AHUD
{
	GENERATED_BODY()

public:
	AAGPproceduralProjectHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

