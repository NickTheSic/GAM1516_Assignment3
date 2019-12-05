// Assignment 3 by Nick Lemmon


#include "Barrel.h"
#include "BPFunctionLib.h"
#include "Components/CapsuleComponent.h"

ABarrel::ABarrel()
{
    CapsuleComponent->SetLinearDamping(20.f);
	UBPFunctionLib::FindSpriteAndSetupCapsule(SpriteComponent, CapsuleComponent, "/Game/Sprites/Barrel");

    Tags.Add("Holdable");
}

