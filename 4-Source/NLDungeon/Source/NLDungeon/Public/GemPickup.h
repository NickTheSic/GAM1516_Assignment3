// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "ItemPickup.h"
#include "GemPickup.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API AGemPickup : public AItemPickup
{
	GENERATED_BODY()
public:
    AGemPickup();
    virtual void PickupItem(class APlayerPawn* player);

private:
    int GemValue;
};
