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
private:

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        bool bDoesClose;

public:
    ADoorObject();

    virtual void ActivateTrigger() override;
    virtual void DeactivateTrigger() override;
};
