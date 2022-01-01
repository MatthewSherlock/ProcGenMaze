// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"

// Sets default values
AFlashlight::AFlashlight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticMesh"));
	staticMesh->SetSimulatePhysics(true);
	RootComponent = staticMesh;
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

}

void AFlashlight::TurnOff()
{
	//set light to  inactive
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Light OFF");

}

void AFlashlight::TurnOn()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Light ON");

	//set light to active
	//deplete battery over time
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
	currBatteryLife += amt;
}

