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

	void SetLocationToSpawnGem(FVector loc);
	FVector GetLocationToSpawnGem();

	void SetCanSpawnGem(bool can);
	bool GetCanSpawnGem();

private:
	bool bCanSpawnGem;
	FVector LocationToSpawnGem;

};
