// Assignment 3 by Nick Lemmon


#include "HealthPickup.h"
#include "BPFunctionLib.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "PlayerPawn.h"


AHealthPickup::AHealthPickup()
{
    UBPFunctionLib::FindSpriteAndSetupCapsule(SpriteComponent, CapsuleComponent, "/Game/Sprites/Heart");
    HealthValue = 1;
}

void AHealthPickup::PickupItem(APlayerPawn* player)
{
    if (player != nullptr)
    {
        player->IncrementHealth(HealthValue);
    }
    Destroy();
}
