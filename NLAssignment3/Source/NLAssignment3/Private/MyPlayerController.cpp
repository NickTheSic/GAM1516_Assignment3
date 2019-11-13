// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "PlayerPawn.h"


void AMyPlayerController::OnPossess(APawn* apawn)
{
	if (apawn != nullptr)
	{
		Super::OnPossess(apawn);
		Player = Cast<APlayerPawn>(apawn);
	}
}

void AMyPlayerController::OnUnPossess()
{
	if (Player != nullptr)
	{
		Player = nullptr;
	}
	Super::OnUnPossess();
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent != nullptr)
	{
		//InputComponent->BindAxis("MoveUp", this, &APlayerPaddleController::MoveUp);
	}
}

void AMyPlayerController::MoveUp(float val)
{

}