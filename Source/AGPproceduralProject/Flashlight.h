// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SpotLightComponent.h"

#include "Flashlight.generated.h"

UCLASS()
class AGPPROCEDURALPROJECT_API AFlashlight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlashlight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float currBatteryLife;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxBatteryLife;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float batteryDepleteRate;

	bool isOn;

	void TurnOff();

	void TurnOn();

	void ToggleFlashlight();

	void RefillBattery(float amt);

	bool outOfBattery;
};
