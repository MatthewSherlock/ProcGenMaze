// Fill out your copyright notice in the Description page of Project Settings.


#include "Battery.h"
#include "AGPproceduralProjectCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABattery::BeginPlay()
{
	Super::BeginPlay();

}

void ABattery::UsePickup()
{
	AAGPproceduralProjectCharacter* player = Cast<AAGPproceduralProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (player)
	{
		UGameplayStatics::PlaySound2D(this, pickupSound);

		player->flashlight->RefillBattery(batteryChange);
		Destroy();

	}
}
