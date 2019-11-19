// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "Gem.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API AGem : public AActor
{
	GENERATED_BODY()
	
public:
	AGem();

	UPROPERTY(EditAnywhere, Category = "Sprite Component")
		class UPaperSpriteComponent* PaperSprite;

	UPROPERTY(EditAnywhere, Category = "Capsule Collider")
		class UCapsuleComponent* CapsuleComponent;

	int GetValue();

private:
	int GemValue;
};
