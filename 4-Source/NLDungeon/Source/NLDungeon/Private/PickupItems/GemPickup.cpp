// Assignment 3 by Nick Lemmon


#include "GemPickup.h"
#include "BPFunctionLib.h"
#include "PlayerPawn.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"


AGemPickup::AGemPickup()
{
    UBPFunctionLib::FindSpriteAndSetupCapsule(SpriteComponent, CapsuleComponent, "/Game/Sprites/Gem");
    GemValue = 1;
}

void AGemPickup::PickupItem(APlayerPawn* player)
{
    AItemPickup::PickupItem(player);
    if (player != nullptr)
    {
        player->IncrementGemCount(GemValue);
    }
    //Destroy();
}
