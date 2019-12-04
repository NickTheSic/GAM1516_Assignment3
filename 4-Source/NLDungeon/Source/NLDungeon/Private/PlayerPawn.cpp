// Assignment 3 by Nick Lemmon


#include "PlayerPawn.h"
#include "BPFunctionLib.h"
#include "DungeonGameState.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "SwordObject.h"
#include "ShieldObject.h"
#include "ItemPickup.h"
#include "MainAudioComponent.h"
#include "AnimationController.h"
#include "Components/PawnNoiseEmitterComponent.h"


APlayerPawn::APlayerPawn()
{
	//Gonna have to remove the sprite component and everything that I setup from inheriting from the DamagleObject
	//Maybe Inheriting was wrong
}

void APlayerPawn::BeginPlay()
{
    //Create the Sword
}


void APlayerPawn::Tick(float deltaSeconds)
{

}

void APlayerPawn::OnNoHealth()
{
    //Go to last checkpoint and lose a life
}

void APlayerPawn::ActivateAttack()
{
    
}

void APlayerPawn::StopAttack()
{

}

void APlayerPawn::ActivateBlock()
{

}

void APlayerPawn::StopBlock()
{

}

void APlayerPawn::MainCapsuleOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void APlayerPawn::MainCapsuleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void APlayerPawn::OnPickupTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void APlayerPawn::OnPickupTriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void APlayerPawn::MoveUp(float val)
{

}

void APlayerPawn::MoveDown(float val)
{

}

void APlayerPawn::Pickup()
{
    if (bCanPickup)
    {

    }
}

void APlayerPawn::Throw()
{
    if (bIsHolding)
    {

    }
}


void APlayerPawn::IncrementHealth(int health)
{
    ObjectHealth += health;
    if (ObjectHealth > MaxHealth)
        ObjectHealth = MaxHealth;
}

int APlayerPawn::GetCurrentHealth()
{
    return ObjectHealth;
}

void APlayerPawn::IncrementLives(int lives)
{
    Lives += lives;
}

void APlayerPawn::DecrementLives(int lives)
{
    Lives -= lives;
}

int APlayerPawn::GetCurrentLives()
{
    return Lives;
}

void APlayerPawn::IncrementMaxHealth(int health)
{
    MaxHealth += health;
}

void APlayerPawn::DecrementMaxHealth(int health)
{
    MaxHealth -= health;
}

int APlayerPawn::GetCurrentMaxHealth()
{
    return MaxHealth;
}

void APlayerPawn::IncrementGemCount(int gem)
{
    GemCount += gem;
}

void APlayerPawn::DecrementGemCount(int gem)
{
    GemCount -= gem;
}

int APlayerPawn::GetCurrentGemCount()
{
    return GemCount;
}

void APlayerPawn::SetHasShield(bool hasShield)
{
    bPlayerHasShield = hasShield;
}
