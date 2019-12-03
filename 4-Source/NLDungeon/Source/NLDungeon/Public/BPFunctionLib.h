// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctionLib.generated.h"

class UPaperSpriteComponent;
class UCapsuleComponent;
class UBoxComponent;

/**
 * 
 */
UCLASS()
class NLDUNGEON_API UBPFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static void FindSpriteAndSetupCapsule(UPaperSpriteComponent* sprite, UCapsuleComponent* capsule, FString name);
	static void FindSpriteAndSetupBox(UPaperSpriteComponent* sprite, UBoxComponent* box, FString name);
	static void SetupSpritePhysics(UPaperSpriteComponent* sprite);
	static void LockPhysicsTo2DAxis(class UPrimitiveComponent* comp);
	
};
