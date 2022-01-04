// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFlashlight::AFlashlight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	outOfBattery = false;
	isOn = true;
}

// Called when the game starts or when spawned
void AFlashlight::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFlashlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currBatteryLife > 0)
	{
		outOfBattery = false;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "> 0");

	}

	if (isOn)
	{
		if (currBatteryLife > 0)
		{
			currBatteryLife -= batteryDepleteRate;
			outOfBattery = false;

		}
		if (currBatteryLife <= 0)
		{
			TurnOff();
			outOfBattery = true;
		}
	}
}

void AFlashlight::TurnOff()
{
	UGameplayStatics::PlaySound2D(this, toggleSound);

	isOn = false;
	USpotLightComponent* light = FindComponentByClass<USpotLightComponent>();
	light->SetVisibility(false);
}

void AFlashlight::TurnOn()
{
	if (!outOfBattery)
	{
		UGameplayStatics::PlaySound2D(this, toggleSound);
		isOn = true;
		USpotLightComponent* light = FindComponentByClass<USpotLightComponent>();
		light->SetVisibility(true);
	}
	else
		TurnOff();
}

void AFlashlight::ToggleFlashlight()
{
	if (isOn)
	{
		TurnOff();
	}
	else
	{
		TurnOn();
	}
		
}

void AFlashlight::RefillBattery(float amt)
{
	currBatteryLife += amt;

	if (currBatteryLife > 100)
	{
		currBatteryLife = 100;
	}
}

