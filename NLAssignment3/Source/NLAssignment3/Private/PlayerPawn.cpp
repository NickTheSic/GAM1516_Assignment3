// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "SwordHit.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPawn::Attack()
{
	SwordHit->ActivateAttack();
}

void APlayerPawn::StopAttack()
{
	SwordHit->StopAttack();
}

void MoveUp(float val)
{
	if (val != 0.0f)
	{

	}
}

void MoveRight(float val)
{
	if (val != 0.f)
	{

	}
}

void Pickup()
{

}

void Throw()
{

}

void APlayerPawn::IncrementGems(int gems)
{
	nCurrentGems += gems;
}

void APlayerPawn::DecrementGems(int gems)
{
	nCurrentGems -= gems;
}

int APlayerPawn::GetGems()
{
	return nCurrentGems;
}

void APlayerPawn::IncrementHealth(int health)
{
	nCurrentHealth += health;
}

void APlayerPawn::DecrementHealth(int health)
{
	nCurrentHealth -= health;
}

int APlayerPawn::GetHealth()
{
	return nCurrentHealth;
}
