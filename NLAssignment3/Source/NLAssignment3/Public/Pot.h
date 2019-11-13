// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pot.generated.h"

UCLASS()
class NLASSIGNMENT3_API APot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APot();

	UPROPERTY(EditAnywhere, Category = "Sprite")
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, Category = "BoxComponent")
		class UBillboardComponent* BoxComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
