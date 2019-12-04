// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTriggerButton.generated.h"

UCLASS()
class NLDUNGEON_API AMyTriggerButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerButton();

private:
	    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UPaperSpriteComponent* SpriteComponent;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class AMyTriggerObject* TriggerObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 
	
	UFUNCTION()
		void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:	

};
