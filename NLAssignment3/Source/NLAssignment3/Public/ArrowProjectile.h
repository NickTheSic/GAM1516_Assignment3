// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowProjectile.generated.h"

UCLASS()
class NLASSIGNMENT3_API AArrowProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowProjectile();

    UPROPERTY(EditAnywhere, Category = "Sprite")
        class UPaperSpriteComponent* SpriteComponent;

    class UDamagePlayerComponent* HitBox;

    class UArrowProjectileComponent* ArrowMovement;


    UPROPERTY(EditAnywhere, Category = "BoxComponent")
        class UBoxComponent* StickToWallComponent;

    UFUNCTION()
        void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
