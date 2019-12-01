// Fill out your copyright notice in the Description page of Project Settings.


#include "GemSpawner.h"
#include "Gem.h"
#include "Engine/World.h"
#include "DungeonGameState.h"
#include "HeartPickup.h"

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
	
	if (ADGameState->GetCanSpawnItem())
	{
		ADGameState->SetCanSpawnItem(false);

        //This will work for now
        if (FMath::RandBool()) SpawnGem();
        else SpawnHeart();
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

			FTransform GemSpawnTransform = FTransform(ADGameState->GetLocationToSpawnItem());
			World->SpawnActor<AGem>(GemTemplate, GemSpawnTransform, GemSpawnParams);
		}
	}
}

void AGemSpawner::SpawnHeart()
{
    UWorld* World = GetWorld();
    if (World)
    {
        if (HeartTemplate != nullptr)
        {
            FActorSpawnParameters HeartSpawnParams;

            HeartSpawnParams.Owner = this;

            FTransform HeartSpawnTransform = FTransform(ADGameState->GetLocationToSpawnItem());
            World->SpawnActor<AGem>(HeartTemplate, HeartSpawnTransform, HeartSpawnParams);
        }
    }
}
