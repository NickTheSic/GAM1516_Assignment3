// Assignment 3 by Nick Lemmon


#include "DoorObject.h"
#include "Components/BoxComponent.h"
#include "BPFunctionLib.h"
#include "PaperSpriteComponent.h"


ADoorObject::ADoorObject()
{
    UBPFunctionLib::FindSpriteAndSetupBox(SpriteComponent, BoxComponent, "/Game/Sprites/Door");
}

void ADoorObject::ActivateTrigger()
{
    BoxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SpriteComponent->SetVisibility(false);

    //I would delete but then the reference would be null for the button
}

//void ADoorObject::DeactivateTrigger()
//{
//    //Do nothing here, the plan was to hold down the button with a barrel but puzzles seem like they will take a little long to mark
//    //Can't have you stuck on a puzzle while marking
//}
