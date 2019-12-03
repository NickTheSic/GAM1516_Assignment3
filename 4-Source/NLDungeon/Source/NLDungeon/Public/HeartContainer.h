// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "ItemPickup.h"
#include "HeartContainer.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API AHeartContainer : public AItemPickup
{
	GENERATED_BODY()
public:
    AHeartContainer();

    virtual void PickupItem(class APlayerPawn* player);
};
