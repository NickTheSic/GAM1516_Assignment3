// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HeartPickup.generated.h"

UCLASS()
class NLASSIGNMENT3_API AHeartPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeartPickup();

    UPROPERTY(EditAnywhere, Category = "Sprite Component")
		class UPaperSpriteComponent* PaperSprite;

	UPROPERTY(EditAnywhere, Category = "Capsule Collider")
		class UCapsuleComponent* CapsuleComponent;

	UFUNCTION()
		void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
};
