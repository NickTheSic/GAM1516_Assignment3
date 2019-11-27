// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GemSpawner.generated.h"

UCLASS()
class NLASSIGNMENT3_API AGemSpawner : public AActor
{
	GENERATED_BODY()
	
        /*********This is now my Item spawner**********/

public:	
	// Sets default values for this actor's properties
	AGemSpawner();


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
		TSubclassOf<class AGem> GemTemplate;


    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
        TSubclassOf<class AHeartPickup> HeartTemplate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnGem();
    void SpawnHeart();
	class ADungeonGameState* ADGameState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
