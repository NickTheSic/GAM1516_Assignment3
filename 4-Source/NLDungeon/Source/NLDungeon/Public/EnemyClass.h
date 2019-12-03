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

    virtual void OnPawnSeen(class APlayerPawn* player);
    virtual void OnPawnHeard();

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
    class UAnimationController* AnimationController;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
    class UPawnSensingComponent* PawnSensingComponent;

};
