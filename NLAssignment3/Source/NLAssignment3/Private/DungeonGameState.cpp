// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonGameState.h"


void ADungeonGameState::SetLocationToSpawnGem(FVector loc)
{
	LocationToSpawnGem = loc;
}

FVector ADungeonGameState::GetLocationToSpawnGem()
{
	return LocationToSpawnGem;
}

void ADungeonGameState::SetCanSpawnGem(bool can)
{
	bCanSpawnGem = can;
}

bool ADungeonGameState::GetCanSpawnGem()
{
	return bCanSpawnGem;
}
