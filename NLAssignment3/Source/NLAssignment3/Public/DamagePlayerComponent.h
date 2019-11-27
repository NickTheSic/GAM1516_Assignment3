// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "DamagePlayerComponent.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API UDamagePlayerComponent : public UBoxComponent
{
	GENERATED_BODY()
	
public:
    UDamagePlayerComponent();

    void ActivateAttack();
    void Deactivate();

    UFUNCTION()
        void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
    int DamageToDeal;

private:
};
