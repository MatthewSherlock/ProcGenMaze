// Fill out your copyright notice in the Description page of Project Settings.


#include "Battery.h"
#include "AGPproceduralProjectCharacter.h"

void ABattery::BeginPlay()
{
	Super::BeginPlay();

}

void ABattery::UsePickup()
{
	AAGPproceduralProjectCharacter* player = Cast<AAGPproceduralProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (player)
	{
		player->flashlight->RefillBattery(batteryChange);
		Destroy();

	}
}
