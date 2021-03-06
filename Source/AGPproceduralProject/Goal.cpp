// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AGPproceduralProjectCharacter.h"

// Sets default values
AGoal::AGoal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	collisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("collisionComponent"));
	RootComponent = collisionComponent;
	collisionComponent->SetCollisionProfileName(TEXT("OverlapAll"));
	collisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	collisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OnBeginOverlap);
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoal::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	AAGPproceduralProjectCharacter* player = Cast<AAGPproceduralProjectCharacter>(OtherActor);
	if (OtherActor != this && player)
	{
		if (player->keyFound)
		{
			UGameplayStatics::PlaySound2D(this, winSound);
			player->GameOver(true);
		}
	}

}

