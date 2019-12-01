// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonGameState.h"


void ADungeonGameState::SetLocationToSpawnItem(FVector loc)
{
	LocationToSpawnItem = loc;
}

FVector ADungeonGameState::GetLocationToSpawnItem()
{
	return LocationToSpawnItem;
}

void ADungeonGameState::SetCanSpawnItem(bool can)
{
	bCanSpawnItem = can;
}

bool ADungeonGameState::GetCanSpawnItem()
{
	return bCanSpawnItem;
}
