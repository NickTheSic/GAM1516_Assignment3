// Assignment 3 by Nick Lemmon


#include "MyPlayerController.h"
#include "PlayerPawn.h"
#include "DungeonGameState.h"
#include "Engine/Engine.h"

void AMyPlayerController::OnPossess(APawn* pawn)
{
	if (pawn != nullptr)
	{
		Super::OnPossess(pawn);
		Player = Cast<APlayerPawn>(pawn);
		ADungeonGameState* d = Cast<ADungeonGameState>(GetWorld()->GetGameState());
		if (d != nullptr)
			d->SetCheckpointLocation(Player->GetActorLocation());
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
		InputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMyPlayerController::ActivateAttack);
		InputComponent->BindAction("Attack", EInputEvent::IE_Released, this, &AMyPlayerController::DeactivateAttack);
		InputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMyPlayerController::ThrowObject); //When it is on the same button as pickup it doesn't work
		InputComponent->BindAction("Pickup", EInputEvent::IE_Pressed, this, &AMyPlayerController::PickupObject);
		InputComponent->BindAction("Block", EInputEvent::IE_Pressed, this, &AMyPlayerController::ActivateBlock);
		InputComponent->BindAction("Block", EInputEvent::IE_Released, this, &AMyPlayerController::DeactivateBlock);
	}
}

void AMyPlayerController::MoveRight(float val)
{
	if (Player != nullptr) Player->MoveRight(val);
}

void AMyPlayerController::MoveUp(float val)
{
	if (Player != nullptr) Player->MoveUp(val);
}

void AMyPlayerController::ActivateAttack()
{
	if (Player != nullptr) Player->ActivateAttack();
}

void AMyPlayerController::DeactivateAttack()
{
	if (Player != nullptr) Player->StopAttack();
}

void AMyPlayerController::ActivateBlock()
{
	if (Player != nullptr) Player->ActivateBlock();
}

void AMyPlayerController::DeactivateBlock()
{
	if (Player != nullptr) Player->StopBlock();
}

void AMyPlayerController::PickupObject()
{
	if (Player != nullptr) Player->Pickup();
}

void AMyPlayerController::ThrowObject()
{
	if (Player != nullptr) Player->Throw();
}
