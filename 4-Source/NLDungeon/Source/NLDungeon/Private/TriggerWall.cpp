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
        FVector targetLocation = FMath::VInterpConstantTo(GetActorLocation(), End, DeltaTime, 600.0f);
        SetActorLocation(targetLocation);
    }
    
    else
    {
        FVector targetLocation = FMath::VInterpConstantTo(GetActorLocation(), Start, DeltaTime, 600.0f);
        SetActorLocation(targetLocation);
    }

}
