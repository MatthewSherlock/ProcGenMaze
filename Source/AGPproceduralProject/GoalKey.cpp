// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalKey.h"
#include "AGPproceduralProjectCharacter.h"
#include "Kismet/GameplayStatics.h"

void AGoalKey::BeginPlay()
{
	Super::BeginPlay();
}



void AGoalKey::UsePickup()
{
	AAGPproceduralProjectCharacter* player = Cast<AAGPproceduralProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (player)
	{
		UGameplayStatics::PlaySound2D(this, pickupSound);

		player->keyFound = true;
		Destroy();
	}

}
