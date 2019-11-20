// Fill out your copyright notice in the Description page of Project Settings.


#include "GemSpawner.h"
#include "Gem.h"
#include "Engine/World.h"
#include "DungeonGameState.h"

// Sets default values
AGemSpawner::AGemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGemSpawner::BeginPlay()
{
	Super::BeginPlay();
	ADGameState = Cast<ADungeonGameState>(GetWorld()->GetGameState());
}

// Called every frame
void AGemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (ADGameState->GetCanSpawnGem())
	{
		ADGameState->SetCanSpawnGem(false);
		SpawnGem();
	}
}

void AGemSpawner::SpawnGem()
{
	UWorld* World = GetWorld();
	if (World)
	{
		if (GemTemplate != nullptr)
		{
			FActorSpawnParameters GemSpawnParams;

			GemSpawnParams.Owner = this;

			FTransform GemSpawnTransform = FTransform(ADGameState->GetLocationToSpawnGem());
			World->SpawnActor<AGem>(GemTemplate, GemSpawnTransform, GemSpawnParams);

		}
	}
}
