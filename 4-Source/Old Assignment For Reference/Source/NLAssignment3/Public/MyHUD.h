// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();

	UPROPERTY(EditAnywhere, Category = "Game Hud")
		TSubclassOf<class UUserWidget> GuiClass;

	UPROPERTY()
		class UUserWidget* Gui;

protected:
	virtual void BeginPlay() override;
};
