// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "MyTriggerObject.h"
#include "TriggerWall.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API ATriggerWall : public AMyTriggerObject
{
	GENERATED_BODY()
	
public:
    ATriggerWall();

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void ActivateTrigger() override;
    virtual void DeactivateTrigger() override;

private:

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        FVector Start;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        FVector End;

    bool bTriggerIsActive;
};
