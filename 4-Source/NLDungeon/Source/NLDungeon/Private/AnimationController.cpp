// Assignment 3 by Nick Lemmon


#include "AnimationController.h"
#include "PaperFlipbook.h"


void UAnimationController::SetIdleDown()
{
	if (IdleDown != nullptr)
	{
		SetFlipbook(IdleDown);
		SetLooping(false);
		Stop();
	}
}

void UAnimationController::SetIdleUp()
{
	if (IdleUp != nullptr)
	{
		SetFlipbook(IdleUp);
		SetLooping(false);
		Stop();
	}
}

void UAnimationController::SetIdleRight()
{
	if (IdleRight != nullptr)
	{
		SetFlipbook(IdleRight);
		SetLooping(false);
		Stop();
	}
}

void UAnimationController::SetWalkingDown()
{
	if (WalkDown != nullptr)
	{
		SetFlipbook(WalkDown);
		SetLooping(true);
		Play();
	}
}

void UAnimationController::SetWalkingUp()
{
	if (WalkUp != nullptr)
	{
		SetFlipbook(WalkUp);
		SetLooping(true);
		Play();
	}
}

void UAnimationController::SetWalkingRight()
{
	if (WalkRight != nullptr)
	{
		SetFlipbook(WalkRight);
		SetLooping(true);
		Play();
	}
}