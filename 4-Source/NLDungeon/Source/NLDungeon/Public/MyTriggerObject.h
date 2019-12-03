// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTriggerObject.generated.h"

UCLASS()
class NLDUNGEON_API AMyTriggerObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UPaperSpriteComponent* SpriteComponent;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UBoxComponent* BoxComponent;

    virtual void ActivateTrigger();
    virtual void DeactivateTrigger();

public:	

    //virtual void Tick

};
