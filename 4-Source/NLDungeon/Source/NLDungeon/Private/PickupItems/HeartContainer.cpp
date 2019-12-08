// Assignment 3 by Nick Lemmon


#include "HeartContainer.h"
#include "BPFunctionLib.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "PlayerPawn.h"

AHeartContainer::AHeartContainer()
{
    UBPFunctionLib::FindSpriteAndSetupCapsule(SpriteComponent, CapsuleComponent, "/Game/Sprites/HeartContainer");
    SpriteComponent->SetSpriteColor(FLinearColor::Blue);
}

void AHeartContainer::PickupItem(APlayerPawn* player)
{
    AItemPickup::PickupItem(player);
    if (player != nullptr)
    {
        player->IncrementMaxHealth(1);
        player->IncrementHealth(player->GetCurrentMaxHealth());
    }
    //Destroy();
}
