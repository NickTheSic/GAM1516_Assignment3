// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void OnPossess(APawn* pawn);
	void OnUnPossess();

	void SetupInputComponent();

	UFUNCTION()
	void MoveRight(float val);
	UFUNCTION()
	void MoveUp(float val);
	UFUNCTION()
	void ActivateAttack();
	UFUNCTION()
	void DeactivateAttack();
	UFUNCTION()
	void ActivateBlock();
	UFUNCTION()
	void DeactivateBlock();
	UFUNCTION()
	void PickupObject();
	UFUNCTION()
	void ThrowObject();

private:
	class APlayerPawn* Player;
};
