// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagableObject.h"
#include "DungeonGameState.h"
#include "Engine/World.h"

ADamagableObject::ADamagableObject()
{
	
}

void ADamagableObject::BeginPlay()
{
	AGameState = Cast<ADungeonGameState>(GetWorld()->GetGameState());
}

void ADamagableObject::TakeDamage()
{
	ObjectHealth--;

	if (ObjectHealth <= 0)
	{
		OnNoHealth();
	}
}

void ADamagableObject::OnNoHealth()
{
	if (AGameState)
	{
		AGameState->SetLocationToSpawnGem(GetActorLocation());
		AGameState->SetCanSpawnGem(true);
	}
}