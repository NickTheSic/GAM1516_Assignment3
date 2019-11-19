// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void OnPossess(APawn* apawn);
	void OnUnPossess();

	void SetupInputComponent();

	void MoveUp(float val); //Will have to set this up for physics based movement
	void MoveRight(float val);

	void OnAttack();
	void StopAttack();
	
private:
	class APlayerPawn* Player;
};
