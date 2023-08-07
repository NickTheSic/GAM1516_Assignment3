// Assignment 3 by Nick Lemmon


#include "ShieldPickup.h"
#include "Components/CapsuleComponent.h"
#include "PlayerPawn.h"
#include "PaperSpriteComponent.h"
#include "BPFunctionLib.h"


AShieldPickup::AShieldPickup()
{
    UBPFunctionLib::FindSpriteAndSetupCapsule(SpriteComponent, CapsuleComponent, "/Game/Sprites/Shield");
}

void AShieldPickup::PickupItem(APlayerPawn* player)
{
    AItemPickup::PickupItem(player);
    if (player != nullptr)
    {
        player->SetHasShield(true);
    }
    //Destroy();
}
