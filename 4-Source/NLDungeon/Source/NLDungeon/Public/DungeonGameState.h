// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DungeonGameState.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API ADungeonGameState : public AGameStateBase
{
	GENERATED_BODY()

private:
	FVector ItemSpawnLocation;
	bool bCanSpawnItem;
	
	FVector PlayerCheckpointLocation;

public:
	void SetCanSpawnItem(bool canSpawn) { bCanSpawnItem = canSpawn; }
	bool GetCanSpawnItem() { return bCanSpawnItem; }
	
	void SetItemSpawnLocation(FVector location) { ItemSpawnLocation = location; }
	FVector GetItemSpawnLocation() { return ItemSpawnLocation; }

	void SetCheckpointLocation(FVector location) { PlayerCheckpointLocation = location; }
	FVector GetCheckpointLocation() { return PlayerCheckpointLocation; }

};

