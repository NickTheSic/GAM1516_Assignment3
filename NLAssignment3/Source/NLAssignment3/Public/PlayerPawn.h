// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

//Don't entirely understand but it is in the reference I am using form class
/******************************TODO**************/
enum class EPlayerAnimState : uint8
{
	Idle,
	Right,
	Left,
	Up,
	Down,
	Attack,
	//Pickup,
	//Throw,
};

enum class EPlayerActionState : uint8
{
	Idle,
	Walking,
	Attacking,
    Holding,
	OutOfHealth,
	OutOfLives,
};

enum class EPlayerDirection : uint8
{
	Up,
	Right,
	Down,
	Left,
};


UCLASS()
class NLASSIGNMENT3_API APlayerPawn : public APawn
{

	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

    UPROPERTY(VisibleAnywhere, Category = "PlayerCollider")
        class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, Category = "Player Trigger")
		class UCapsuleComponent* PickupComponent;

    UPROPERTY(EditAnywhere, Category = "Attack Component")
        class USwordHit* SwordHitComponent;

    UPROPERTY(EditAnywhere, Category = "Folow Cam")
        class UCameraComponent* Camera;

	//FLIP BOOK

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* AnimatedComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* RightWalk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* UpWalk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* DownWalk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* IdleUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* IdleDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* IdleRight;

	void Attack();
	void StopAttack();

	void MoveUp(float val);
	void MoveRight(float val);

	void Pickup();
	void Throw();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	EPlayerAnimState PlayerAnimState;
	EPlayerActionState PlayerActionState;
	void SetAnimState(EPlayerAnimState astate) { PlayerAnimState = astate; }
	void SetActionState(EPlayerActionState astate) { PlayerActionState = astate; }

	EPlayerDirection PlayerDirection;
    void SetDirectionState(EPlayerDirection adir) { PlayerDirection = adir; }

    void SetIdleDirectionSprite();

    void UpdateAnimatedSprite();

private:
	bool bIsHolding; //For picking up objects
	bool bIsAttacking; //So the player can't attack until the attack is done.  Assuming I have animatioon for the attack

	int nCurrentHealth;
	int nMaxHealth;

	int nCurrentGems;

    float TravelDirectionX;
    float TravelDirectionY;

	float MovementForce = 1000.f; 
	float MaxVel = 100.f;


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

