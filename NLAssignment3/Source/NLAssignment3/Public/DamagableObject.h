// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "DamagableObject.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API ADamagableObject : public AActor
{
	GENERATED_BODY()
	
public:
	ADamagableObject();

	UPROPERTY(EditAnywhere, Category = "Sprite Component")
		class UPaperSpriteComponent* PaperSprite;

	UPROPERTY(EditAnywhere, Category = "Collision")
		class USphereComponent* Capsule;

	void TakeDamage();
	void OnNoHealth();
	//OnDestory

private:
	int ObjectHealth;
	class ADungeonGameState* AGameState;

protected:
	void BeginPlay() override;
};
