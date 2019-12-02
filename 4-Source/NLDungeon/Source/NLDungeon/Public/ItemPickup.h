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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
