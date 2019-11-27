// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"


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

	UPROPERTY(Category = "Character", VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
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
	UFUNCTION()
		void Throw();

	UPROPERTY(EditAnywhere, Category = "Sword Sprite")
		class UPaperSpriteComponent* SwordSprite; 
	
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnPickupEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 
	UFUNCTION()
		void OnPickupExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

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

	void SetSwordLocationAndRotation();

private:
	bool bIsHolding; //For picking up objects
	bool bCanPickUp;
	bool bIsAttacking; //So the player can't attack until the attack is done.  Assuming I have animatioon for the attack

	int nCurrentHealth;
	int nMaxHealth;

	int nCurrentGems;

    float TravelDirectionX;
    float TravelDirectionY;

	float MovementForce = 5000.f; 
	float MaxVel = 200.f;

	bool bLeftRightMovement;
	bool bUpDownMovement;

	class AActor* HeldObject;
	AActor* ObjectThatCanBeHeld;

public:
	void IncrementGems(int gems);
	void DecrementGems(int gems);

	bool GetIsHolding() { return bIsHolding; }
	bool GetCanPickup() { return bCanPickUp; }

	UFUNCTION(BlueprintCallable, Category = "UI")
		int GetGems();

	void IncrementHealth(int health);
	void DecrementHealth(int health);

	UFUNCTION(BlueprintCallable, Category = "UI")
		int GetHealth();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

