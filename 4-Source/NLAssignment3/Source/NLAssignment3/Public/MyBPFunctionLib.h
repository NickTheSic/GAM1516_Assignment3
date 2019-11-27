// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBPFunctionLib.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API UMyBPFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

    static void SpriteCollisionSetup(class UPrimitiveComponent* paper2d);

};
