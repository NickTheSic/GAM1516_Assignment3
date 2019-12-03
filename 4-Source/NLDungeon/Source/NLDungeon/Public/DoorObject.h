// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "MyTriggerObject.h"
#include "DoorObject.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API ADoorObject : public AMyTriggerObject
{
	GENERATED_BODY()
	
public:
    ADoorObject();

protected:
    virtual void ActivateTrigger() override;
};
