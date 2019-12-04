// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwordObject.generated.h"

UCLASS()
class NLDUNGEON_API ASwordObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwordObject();

    void ActivateAttack();
    void StopAttack();

private:
    class USwordHitComponent* SwordComponent;
    class UPaperSpriteComponent* SpriteComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
