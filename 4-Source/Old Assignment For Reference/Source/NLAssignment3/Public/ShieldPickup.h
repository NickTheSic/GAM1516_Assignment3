// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShieldPickup.generated.h"

UCLASS()
class NLASSIGNMENT3_API AShieldPickup : public AActor
{
	GENERATED_BODY()
	
        /********This is an upgrade that the player can recieve*********/

public:	
	// Sets default values for this actor's properties
	AShieldPickup();

    UPROPERTY(EditAnywhere, Category = "Sprite")
        class UPaperSpriteComponent* Sprite;

    UPROPERTY(EditAnywhere, Category = "Pickup Area")
        class UBoxComponent* Box;

    UFUNCTION()
        void OnPickupEnter(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
