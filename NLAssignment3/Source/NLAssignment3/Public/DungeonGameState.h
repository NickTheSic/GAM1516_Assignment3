// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DungeonGameState.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API ADungeonGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	void SetLocationToSpawnItem(FVector loc);
	FVector GetLocationToSpawnItem();

	void SetCanSpawnItem(bool can);
	bool GetCanSpawnItem();

private:
	bool bCanSpawnItem;
	FVector LocationToSpawnItem;

};
