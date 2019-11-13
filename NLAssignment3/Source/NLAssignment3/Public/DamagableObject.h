// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "DamagableObject.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API ADamagableObject : public APaperSpriteActor
{
	GENERATED_BODY()
	
public:
	ADamagableObject();

	UPROPERTY(EditAnywhere, Category = "Collision")
		class UCapsuleComponent* Capsule;

	void TakeDamage();

	//OnDestory

private:
	int ObjectHealth;
};
