// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SwordHit.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API USwordHit : public UBoxComponent
{
	GENERATED_BODY()
	
public:
	USwordHit();

    void ActivateAttack(); //On Key Press
	void StopAttack();

	UPROPERTY(EditAnywhere, Category = "Config")
		float AttackDamage = 1.f;

	UPROPERTY(EditAnywhere, Category = "Config")
		float AttackPush = 100.f;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	bool bIsAttacking;
};
