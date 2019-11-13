// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SwordHit.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API USwordHit : public UBoxComponent
{
	GENERATED_BODY()
	
public:

    void ActivateAttack(); //On Key Press

};
