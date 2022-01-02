// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "Battery.generated.h"

/**
 * 
 */
UCLASS()
class AGPPROCEDURALPROJECT_API ABattery : public APickupBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void UsePickup() override; //MUST define virtual func!

	UPROPERTY(EditAnywhere)
		float batteryChange;
};
