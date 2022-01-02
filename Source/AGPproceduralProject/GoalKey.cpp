// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalKey.h"
#include "AGPproceduralProjectCharacter.h"

void AGoalKey::BeginPlay()
{
	Super::BeginPlay();
}



void AGoalKey::UsePickup()
{
	AAGPproceduralProjectCharacter* player = Cast<AAGPproceduralProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (player)
	{

		player->keyFound = true;
		Destroy();
	}

}
