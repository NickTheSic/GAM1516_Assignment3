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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
