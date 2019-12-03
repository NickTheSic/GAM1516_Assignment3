// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "DamagableObject.h"
#include "EnemyClass.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API AEnemyClass : public ADamagableObject
{
	GENERATED_BODY()
	
public:
    AEnemyClass();

    virtual void Tick(float deltaSeconds) override;

protected:

    virtual void BeginPlay() override;

    UFUNCTION()
    virtual void OnPawnSeen(class APawn* player);
    UFUNCTION()
    virtual void OnPawnHeard(APawn* NoiseInstigator, const FVector& Location, float Volume);

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
    class UAnimationController* AnimationController;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
    class UPawnSensingComponent* PawnSensingComponent;

};
