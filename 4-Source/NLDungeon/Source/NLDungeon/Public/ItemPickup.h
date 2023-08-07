// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPickup.generated.h"

UCLASS()
class NLDUNGEON_API AItemPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemPickup();

    virtual void PickupItem(class APlayerPawn* player);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UPaperSpriteComponent* SpriteComponent;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UCapsuleComponent* CapsuleComponent;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UMainAudioComponent* AudioComponent;

    void SetToDestroy(); 
    FTimerHandle ToDestroy;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
