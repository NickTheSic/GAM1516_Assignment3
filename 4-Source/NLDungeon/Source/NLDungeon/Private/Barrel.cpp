// Assignment 3 by Nick Lemmon


#include "Barrel.h"
#include "BPFunctionLib.h"
#include "Components/CapsuleComponent.h"

ABarrel::ABarrel()
{
	UBPFunctionLib::FindSpriteAndSetupCapsule(SpriteComponent, CapsuleComponent, "/Game/Sprites/Barrel");
}

