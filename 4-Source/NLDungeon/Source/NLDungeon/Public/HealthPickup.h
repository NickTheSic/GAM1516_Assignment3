// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "ItemPickup.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API AHealthPickup : public AItemPickup
{
	GENERATED_BODY()
public:
    AHealthPickup();
    virtual void PickupItem(class APlayerPawn* player);

private:
    int HealthValue;
};
