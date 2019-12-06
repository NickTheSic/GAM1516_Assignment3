// Assignment 3 by Nick Lemmon


#include "DoorObject.h"
#include "Components/BoxComponent.h"
#include "BPFunctionLib.h"
#include "PaperSpriteComponent.h"
#include "DungeonGameState.h"

ADoorObject::ADoorObject()
{
    UBPFunctionLib::FindSpriteAndSetupBox(SpriteComponent, BoxComponent, "/Game/Sprites/Door");
    bDoesClose = false; //Default to a not reclosing door
}

void ADoorObject::ActivateTrigger()
{
	if (SpriteComponent->IsVisible())
	{
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SpriteComponent->SetVisibility(false);

		UWorld* w = GetWorld();
		if (w)
		{
			ADungeonGameState* d = Cast<ADungeonGameState>(w->GetGameState());
			if (d)
			{
				d->SetCanPlayAudio(true);
				d->SetAudioLocation(GetActorLocation());
			}
		}
	}
}

void ADoorObject::DeactivateTrigger()
{
    if (bDoesClose)
    {
        BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
        SpriteComponent->SetVisibility(true);
    }
}
