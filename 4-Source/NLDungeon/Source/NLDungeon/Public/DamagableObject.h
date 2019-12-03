// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DamagableObject.generated.h"

UCLASS()
class NLDUNGEON_API ADamagableObject : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADamagableObject();

	void ObjectTakeDamage(int damage);
	virtual void OnNoHealth();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* SpriteComponent;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CapsuleComponent;

	int ObjectHealth;

	class ADungeonGameState* DungeonGameState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
