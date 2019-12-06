// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SwordHitComponent.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API USwordHitComponent : public UBoxComponent
{
	GENERATED_BODY()
public:
    USwordHitComponent();
	UFUNCTION()
    void ActivateAttack();
	UFUNCTION()
    void StopAttack();
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
