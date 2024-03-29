// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "DamagableObject.h"
#include "PlayerPawn.generated.h"

/**
 * 
 */

enum class EPlayerDirection : uint8
{
	Up,
	Right,
	Down,
	Left,
};

UCLASS()
class NLDUNGEON_API APlayerPawn : public ADamagableObject
{
	GENERATED_BODY()

private:
    //Health Derived from DamagableObject
    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UCapsuleComponent* PickupArea;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UAnimationController* PlayerAnimController;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        TSubclassOf<class ASwordObject> SwordClass;
	ASwordObject* Sword;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        TSubclassOf<class AShieldObject> ShieldClass;
	AShieldObject* Shield;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UMainAudioComponent* AudioComponent;

    class AActor* HeldObject;
    AActor* ReferenceToHold;

    bool bPlayerHasShield;
    bool bCanPickup;
    bool bIsHolding;
	bool bIsAttacking;
	bool bIsDefending;
	bool bLeftRightMovement;
	bool bUpDownMovement;

	EPlayerDirection PlayerDirection;

    int MaxHealth;
    int GemCount;
    int Lives;
	float MaxVel = 600.f;

    class UPawnNoiseEmitter* NoiseEmitter;

	void SetupIdleAnimation();

protected:
    virtual void BeginPlay() override;

public:
	APlayerPawn();
	
    virtual void Tick(float deltaSeconds) override;

    virtual void OnNoHealth() override;
    void IncrementHealth(int health);
    //TakeDamage Derived from DamagableObject
    UFUNCTION(BlueprintCallable, Category = "UI")
        int GetCurrentHealth();

    void IncrementLives(int lives);
    void DecrementLives(int lives);
    UFUNCTION(BlueprintCallable, Category = "UI")
        int GetCurrentLives();

    void IncrementMaxHealth(int health);
    void DecrementMaxHealth(int health);
    UFUNCTION(BlueprintCallable, Category = "UI")
        int GetCurrentMaxHealth();

    void IncrementGemCount(int gem);
    void DecrementGemCount(int gem);
    UFUNCTION(BlueprintCallable)
        int GetCurrentGemCount();

	UFUNCTION()
	void SetSwordAndShieldPosition();
    void SetHasShield(bool hasShield);
    void ActivateAttack();
    void StopAttack();
    void ActivateBlock();
    void StopBlock();

    UFUNCTION()
    void MainCapsuleOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    UFUNCTION()
    void MainCapsuleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
    void OnPickupTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
    void OnPickupTriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    void MoveUp(float val);
    void MoveRight(float val);

    void Pickup();
    void Throw();

};
