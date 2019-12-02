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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
