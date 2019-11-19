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
		InputComponent->BindAxis("MoveUp", this, &AMyPlayerController::MoveUp);
		InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
		InputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMyPlayerController::OnAttack);
		InputComponent->BindAction("Attack", EInputEvent::IE_Released, this, &AMyPlayerController::StopAttack);
	}
}

void AMyPlayerController::MoveUp(float val)
{
	if (val > 1)
		val = 1;
	if (val < -1)
		val = -1;

	Player->MoveUp(val);
}

void AMyPlayerController::MoveRight(float val)
{
	if (val > 1)
		val = 1;
	if (val < -1)
		val = -1;

	Player->MoveRight(val);
}

void AMyPlayerController::OnAttack()
{
	Player->Attack();
}

void AMyPlayerController::StopAttack()
{
	Player->StopAttack();
}

