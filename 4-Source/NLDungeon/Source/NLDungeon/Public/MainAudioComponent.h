// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "MainAudioComponent.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API UMainAudioComponent : public UAudioComponent
{
	GENERATED_BODY()
public:
    UMainAudioComponent();
    void PlayDestroySound();

private:
    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class USoundBase* DestroySound;
};
