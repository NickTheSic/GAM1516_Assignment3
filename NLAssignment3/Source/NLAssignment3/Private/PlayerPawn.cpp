// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "SwordHit.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "MyBPFunctionLib.h"
#include "Engine/Engine.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Capsule Component
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	CapsuleComponent->SetCollisionProfileName("BlockAll");
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly); //This Component hits things
	CapsuleComponent->SetNotifyRigidBodyCollision(true);
    CapsuleComponent->GetBodyInstance()->bLockXRotation = true;
    CapsuleComponent->GetBodyInstance()->bLockYRotation = true;
    CapsuleComponent->GetBodyInstance()->bLockZRotation = true;
    CapsuleComponent->GetBodyInstance()->bLockYTranslation = true;
    CapsuleComponent->SetSimulatePhysics(true);
    CapsuleComponent->SetEnableGravity(false);
	SetRootComponent(CapsuleComponent);

    //Animated Component
	AnimatedComponent = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>("Animated Component");
	AnimatedComponent->SetupAttachment(RootComponent);
    UMyBPFunctionLib::SpriteCollisionSetup(AnimatedComponent);

    //Pickup Component
	PickupComponent = CreateDefaultSubobject<UCapsuleComponent>("Pickup");

	PickupComponent->SetupAttachment(RootComponent);

    //SwordHit Component
	SwordHitComponent = CreateDefaultSubobject<USwordHit>("Attack Box");

	SwordHitComponent->SetupAttachment(RootComponent);

    //Setup the Camera
    Camera = CreateDefaultSubobject<UCameraComponent>("The player Camera for now");
    Camera->SetOrthoWidth(2800.f);
    Camera->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
    Camera->SetRelativeLocation(FVector(0.f, 500.f, 0.f));
    Camera->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UPaperSprite> PlayerRef(TEXT("PaperSprite'/Game/Sprites/Link/Walking/Down/Link_Sprite_10.Link_Sprite_10'"));
	if (PlayerRef.Succeeded())
	{
		FVector2D size = PlayerRef.Object->GetSourceSize();
		CapsuleComponent->SetCapsuleHalfHeight(size.Y / 2);
		CapsuleComponent->SetCapsuleRadius(size.X / 2);
		//Make it a little larger of an area to pickup
		PickupComponent->SetCapsuleHalfHeight(size.Y / 1.4f);
		PickupComponent->SetCapsuleRadius(size.X / 1.4f);

		SwordHitComponent->SetBoxExtent(FVector(size.X / 4, 0.f, size.Y / 3.f));
	}

	PlayerActionState = EPlayerActionState::Idle;
    SetAnimState(EPlayerAnimState::Idle);
    SetDirectionState(EPlayerDirection::Down);
    SetIdleDirectionSprite();
}


// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
    AnimatedComponent->Stop();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    UpdateAnimatedSprite();
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPawn::Attack()
{
	SwordHitComponent->ActivateAttack();
}

void APlayerPawn::StopAttack()
{
	SwordHitComponent->StopAttack();
}

void APlayerPawn::MoveUp(float val)
{
	if (val != 0.0f)
	{
        FVector PlayerVelocity = GetVelocity();
        TravelDirectionY = -PlayerVelocity.Z;

        if (TravelDirectionY < 0.0f)
        {
            SetDirectionState(EPlayerDirection::Up);
        }

        else if (TravelDirectionY > 0.0f)
        {
            SetDirectionState(EPlayerDirection::Down);
        }

        FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();

        //If it is less speed up?
        //if (FMath::Abs(currentVel.Y) < MaxVel)
        //{
        //    CapsuleComponent->BodyInstance.AddForce(FVector(0.f, 0.f, 1.f) * MovementForce * val);
        //}
        //else
        {
            FVector newVel = FVector(currentVel.X, 0.0f, MaxVel * val);
            CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);
        }

	}
    else
    {
        FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
        FVector newVel = currentVel;
        newVel.Y = 0;
        CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);
        TravelDirectionY = 0.f;
        if (TravelDirectionX == 0.f && PlayerActionState != EPlayerActionState::Attacking)
        {
            SetAnimState(EPlayerAnimState::Idle);
            SetActionState(EPlayerActionState::Idle);
        }
    }
}

void APlayerPawn::MoveRight(float val)
{
	if (val != 0.f)
	{
		FVector PlayerVelocity = GetVelocity();
        TravelDirectionX = -PlayerVelocity.X;
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::FromInt(val));
		if (TravelDirectionX < 0.0f)
		{
            SetDirectionState(EPlayerDirection::Right);
			AnimatedComponent->SetRelativeRotation(FRotator::ZeroRotator);
		}

		else if (TravelDirectionX > 0.0f)
		{
            SetDirectionState(EPlayerDirection::Left);
			AnimatedComponent->SetRelativeRotation(FRotator(0.f,180.f,0.f));
		}

        FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();

		//If it is less speed up?
		if (FMath::Abs(currentVel.X) < MaxVel)
		{
			CapsuleComponent->BodyInstance.AddForce(FVector(1.f, 0.f, 0.f) * MovementForce * val);
		}
		else
		{
			FVector newVel = FVector(MaxVel * val, 0.0f, currentVel.Z);
			CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);
		}
	}
    else
    {
        TravelDirectionX = 0.f;
        if (TravelDirectionY == 0.f && PlayerActionState != EPlayerActionState::Attacking)
        {
            SetAnimState(EPlayerAnimState::Idle);
            SetActionState(EPlayerActionState::Idle);
        }
    }
}

void APlayerPawn::Pickup()
{

}

void APlayerPawn::Throw()
{

}

void APlayerPawn::UpdateAnimatedSprite()
{
    if (PlayerAnimState == EPlayerAnimState::Idle)
    {
        SetIdleDirectionSprite();
        return;
    }

    float velocity = GetVelocity().Size();

    if (velocity > 0)
    {
        if (PlayerAnimState == EPlayerAnimState::Right || PlayerAnimState == EPlayerAnimState::Left)
        {
            AnimatedComponent->SetFlipbook(RightWalk);
            AnimatedComponent->Play();
        }
    }

}

void APlayerPawn::SetIdleDirectionSprite()
{
    if (PlayerDirection == EPlayerDirection::Down) AnimatedComponent->SetFlipbook(IdleDown);
    if (PlayerDirection == EPlayerDirection::Up) AnimatedComponent->SetFlipbook(IdleUp);
    if (PlayerDirection == EPlayerDirection::Right || PlayerDirection == EPlayerDirection::Left) AnimatedComponent->SetFlipbook(IdleRight);
}

void APlayerPawn::IncrementGems(int gems)
{
	nCurrentGems += gems;
}

void APlayerPawn::DecrementGems(int gems)
{
	nCurrentGems -= gems;
}

int APlayerPawn::GetGems()
{
	return nCurrentGems;
}

void APlayerPawn::IncrementHealth(int health)
{
	nCurrentHealth += health;
}

void APlayerPawn::DecrementHealth(int health)
{
	nCurrentHealth -= health;
}

int APlayerPawn::GetHealth()
{
	return nCurrentHealth;
}
