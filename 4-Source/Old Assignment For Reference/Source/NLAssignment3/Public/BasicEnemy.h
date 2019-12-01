// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicEnemy.generated.h"

UCLASS()
class NLASSIGNMENT3_API ABasicEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicEnemy();

	UPROPERTY(EditAnywhere, Category = "Flipbook")
	class UMyFlipbookControlComponent* mfcc;

	UPROPERTY(VisibleAnywhere, Category = "PlayerCollider")
		class UCapsuleComponent* CapsuleComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
