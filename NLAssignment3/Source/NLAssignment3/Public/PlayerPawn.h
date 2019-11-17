// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

//Don't entirely understand but it is in the reference I am using form class
/******************************TODO**************/
//enum class EPlayerAnimState
//{
//	Idle,
//	Right,
//	Left,
//	Up,
//	Down,
//	Attack,
//	//Pickup,
//	//Throw,
//};
//
//enum class EPlayerActionState
//{
//	Idle,
//	Walking,
//	Attacking,
//	OutOfHealth,
//	OutOfLives,
//	InTransition, //From moving from room to room?
//};



UCLASS()
class NLASSIGNMENT3_API APlayerPawn : public APawn
{

	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

    UPROPERTY(EditAnywhere, Category = "PlayerCollider")
        class UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere, Category = "Attack Component")
        class USwordHit* SwordHit;

	//FLIP BOOKS*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* RightWalk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* UpWalk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* DownWalk;

	void Attack();
	void StopAttack();

	void MoveUp(float val);
	void MoveRight(float val);


	void Pickup();
	void Throw();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool bIsHolding; //For picking up objects
	bool bIsAttacking; //So the player can't attack until the attack is done.  Assuming I have animatioon for the attack

	int nCurrentHealth;
	int nMaxHealth;

	int nCurrentGems;

public:
	void IncrementGems(int gems);
	void DecrementGems(int gems);

	UFUNCTION()
		int GetGems();

	void IncrementHealth(int health);
	void DecrementHealth(int health);

	UFUNCTION()
		int GetHealth();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

