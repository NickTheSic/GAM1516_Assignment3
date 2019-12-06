// Assignment 3 by Nick Lemmon


#include "SimplePatrolEnemy.h"
#include "Perception/PawnSensingComponent.h"
#include "AnimationController.h"

ASimplePatrolEnemy::ASimplePatrolEnemy()
{

}


void ASimplePatrolEnemy::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (Pause)
	{
		if (Direction == EDirection::Down) AnimationController->SetIdleDown();
		if (Direction == EDirection::Left || Direction == EDirection::Right) AnimationController->SetIdleRight();
		if (Direction == EDirection::Up) AnimationController->SetIdleUp();

		PauseTimer -= deltaSeconds;

		if (PauseTimer <= 0)
		{
			Pause = false;
			PauseTimer = 2.5f;
		}

	}

		FVector targetLocation = FMath::VInterpConstantTo(GetActorLocation(), PositionsToPatrol[CurrentPosition], deltaSeconds, Speed);
		SetActorLocation(targetLocation);

		if (GetActorLocation() == PositionsToPatrol[CurrentPosition])
		{
			if (bSeenPlayer)
			{
				bSeenPlayer = false;
				Speed = 300.f;
				PositionsToPatrol.RemoveAt(CurrentPosition);
			}

			CurrentPosition++;
			if (CurrentPosition >= PositionsToPatrol.Num())
				CurrentPosition = 0;

			if (PositionsToPatrol[CurrentPosition].X > GetActorLocation().X)
			{
				SetActorRotation(FRotator::ZeroRotator);
				Direction = EDirection::Right;
				AnimationController->SetWalkingRight();
			}
			else if (PositionsToPatrol[CurrentPosition].X < GetActorLocation().X)
			{
				SetActorRotation(FRotator(0, 0, 180));
				Direction = EDirection::Left;
				AnimationController->SetWalkingRight();
			}

			if (PositionsToPatrol[CurrentPosition].Z < GetActorLocation().Z)
			{

			}
			if (PositionsToPatrol[CurrentPosition].Z > GetActorLocation().Z)
			{

			}
		}

}

void ASimplePatrolEnemy::OnPawnSeen(class APawn* player)
{
	if (player->ActorHasTag("Player"))
	{
		CurrentPosition = PositionsToPatrol.Num();
		Speed = 450.f;
		bSeenPlayer = true;
		PositionsToPatrol.Add(player->GetActorLocation());
	}
}


 void ASimplePatrolEnemy::OnPawnHeard(APawn* NoiseInstigator, const FVector& Location, float Volume)
{
	 Pause = true;
}

 void ASimplePatrolEnemy::BeginPlay()
 {
	 Super::BeginPlay();
	 Direction = EDirection::Down;
	 CurrentPosition = PositionsToPatrol.Num(); //Get the current point so that he changes directions on update
	 PositionsToPatrol.Add(GetActorLocation()); //A Default Start
	 CurrentPosition = 0;
	 Speed = 300;
	 Pause = false;
	 PauseTimer = 2.5f;
 }
