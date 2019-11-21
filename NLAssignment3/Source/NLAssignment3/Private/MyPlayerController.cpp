// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "PlayerPawn.h"
#include "Engine/Engine.h"


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
		InputComponent->BindAction("Pickup", EInputEvent::IE_Pressed, this, &AMyPlayerController::Throw);
		InputComponent->BindAction("Pickup", EInputEvent::IE_Pressed, this, &AMyPlayerController::Pickup);
	}
}

void AMyPlayerController::MoveUp(float val)
{
	if (val > 1)
		val = 1;
	if (val < -1)
		val = -1;

    //GEngine->AddOnScreenDebugMessage(0, .5f, FColor::Blue, FString::FromInt(val));

	Player->MoveUp(val);
}

void AMyPlayerController::MoveRight(float val)
{
	if (val > 1)
		val = 1;
	if (val < -1)
		val = -1;

    //GEngine->AddOnScreenDebugMessage(1, .5f, FColor::Green, FString::FromInt(val));

    Player->MoveRight(val);
}

void AMyPlayerController::Pickup()
{
	if (Player->GetCanPickup())
		Player->Pickup();
}

void AMyPlayerController::Throw()
{
	if (Player->GetIsHolding())
		Player->Throw();
}

void AMyPlayerController::OnAttack()
{
	Player->Attack();
}

void AMyPlayerController::StopAttack()
{
	Player->StopAttack();
}

