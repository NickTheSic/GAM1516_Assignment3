// Assignment 3 by Nick Lemmon


#include "TriggerWall.h"
#include "BPFunctionLib.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"

ATriggerWall::ATriggerWall()
{
    bTriggerIsActive = false;
}

void ATriggerWall::ActivateTrigger()
{
    bTriggerIsActive = true;
}

void ATriggerWall::DeactivateTrigger()
{
    bTriggerIsActive = false;
}

// Called every frame
void ATriggerWall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //Math LErP

    if (bTriggerIsActive)
    {
        //Move to end
    }
    
    else
    {
        //Move to start
    }

}
