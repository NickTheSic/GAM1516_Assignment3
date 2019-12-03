// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
    AGameHUD();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Config")
        TSubclassOf<class UUserWidget> PlayerGui;

    UPROPERTY(EditAnywhere, Category = "Config")
        UUserWidget* Gui;
	
};
