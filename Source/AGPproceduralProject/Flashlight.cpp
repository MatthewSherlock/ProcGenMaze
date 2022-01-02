// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AFlashlight::AFlashlight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AFlashlight::BeginPlay()
{
	Super::BeginPlay();
	USpotLightComponent* light = FindComponentByClass<USpotLightComponent>();
	light->SetVisibility(false);
}

// Called every frame
void AFlashlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	if (isOn)
	{
		if (currBatteryLife >= 0)
		{
			currBatteryLife -= batteryDepleteRate;
		}
	}
}

void AFlashlight::TurnOff()
{
	//set light to  inactive
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Light OFF");
	isOn = false;
	USpotLightComponent* light = FindComponentByClass<USpotLightComponent>();
	light->ToggleVisibility();
}

void AFlashlight::TurnOn()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Light ON");
	isOn = true;
	//set light to active
	USpotLightComponent* light = FindComponentByClass<USpotLightComponent>();
	light->ToggleVisibility();

}

void AFlashlight::ToggleFlashlight()
{
	if (isOn)
	{
		TurnOff();
	}
	else
		TurnOn();
}

void AFlashlight::RefillBattery(float amt)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "REFILL");
	currBatteryLife += amt;

	if (currBatteryLife > 100)
	{
		currBatteryLife = 100;
	}
}

