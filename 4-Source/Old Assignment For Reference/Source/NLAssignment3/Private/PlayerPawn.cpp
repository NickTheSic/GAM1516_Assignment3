// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "SwordHit.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Camera/CameraComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "MyBPFunctionLib.h"
#include "Engine/Engine.h"
#include "Gem.h"
#include "MyBPFunctionLib.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //Capsule Component
    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
    CapsuleComponent->SetCollisionProfileName("BlockAll");
    CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    CapsuleComponent->SetNotifyRigidBodyCollision(true);
    CapsuleComponent->GetBodyInstance()->bLockXRotation = true;
    CapsuleComponent->GetBodyInstance()->bLockYRotation = true;
    CapsuleComponent->GetBodyInstance()->bLockZRotation = true;
    CapsuleComponent->GetBodyInstance()->bLockYTranslation = true;
    CapsuleComponent->SetSimulatePhysics(true);
    CapsuleComponent->SetEnableGravity(false);
    SetRootComponent(CapsuleComponent);
    CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &APlayerPawn::OnTriggerEnter);
    CapsuleComponent->OnComponentHit.AddDynamic(this, &APlayerPawn::OnHit);

    //Animated Component
    AnimatedComponent = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>("Animated Component");
    AnimatedComponent->SetupAttachment(RootComponent);
    UMyBPFunctionLib::SpriteCollisionSetup(AnimatedComponent);

    //Pickup Component
    PickupComponent = CreateDefaultSubobject<UCapsuleComponent>("Pickup");
    PickupComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    PickupComponent->SetCollisionProfileName("Overlap");
    PickupComponent->OnComponentBeginOverlap.AddDynamic(this, &APlayerPawn::OnPickupEnter);
    PickupComponent->OnComponentEndOverlap.AddDynamic(this, &APlayerPawn::OnPickupExit);
    PickupComponent->SetupAttachment(RootComponent);

    //SwordHit Component
    SwordHitComponent = CreateDefaultSubobject<USwordHit>("Attack Box");

    SwordHitComponent->SetupAttachment(RootComponent);

    ConstructorHelpers::FObjectFinder<UPaperSprite> SwordRef(TEXT("PaperSprite'/Game/Sprites/Sword'"));
    SwordSprite = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
    UMyBPFunctionLib::SpriteCollisionSetup(SwordSprite);
    SwordSprite->SetupAttachment(SwordHitComponent);
    SwordSprite->SetRelativeRotation(FRotator(0.f, -180.f, 0.f));
    SwordSprite->SetSprite(SwordRef.Object);
    SwordSprite->SetVisibility(false);
    FVector2D swordSize = SwordSprite->GetSprite()->GetSourceSize();
    SwordHitComponent->SetBoxExtent(FVector(swordSize.X / 2.f, 0.f, swordSize.Y / 2.f));

    //Setup the Camera
    Camera = CreateDefaultSubobject<UCameraComponent>("The player Camera for now");
    Camera->SetOrthoWidth(1800.f);
    Camera->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
    Camera->SetRelativeLocation(FVector(0.f, 500.f, 0.f));
    Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
    Camera->SetupAttachment(RootComponent);

    if (false) {
#if WITH_EDITOR
        ConstructorHelpers::FObjectFinder<UPaperSprite> PlayerRef(TEXT("PaperSprite'/Game/Sprites/Link/Walking/Down/Link_Sprite_10.Link_Sprite_10'"));
        if (PlayerRef.Succeeded())
        {
            FVector2D size = PlayerRef.Object->GetSourceSize();
            CapsuleComponent->SetCapsuleHalfHeight(size.Y / 2);
            CapsuleComponent->SetCapsuleRadius(size.X / 2);
            //Make it a little larger of an area to pickup
            PickupComponent->SetCapsuleHalfHeight(size.Y / 1.4f);
            PickupComponent->SetCapsuleRadius(size.X / 1.4f);
        }
#endif
    }

    else {
        UMyBPFunctionLib::Test(nullptr, CapsuleComponent, "PaperSprite'/Game/Sprites/Link/Walking/Down/Link_Sprite_10.Link_Sprite_10'");
    }

	HeldObject = nullptr;

	Tags.Add("Player");
	PlayerActionState = EPlayerActionState::Idle;
    SetAnimState(EPlayerAnimState::Idle);
    SetDirectionState(EPlayerDirection::Down);
    SetIdleDirectionSprite();

    nMaxHealth = 5;
}


// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
    AnimatedComponent->Stop();
    nCurrentHealth = nMaxHealth;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    UpdateAnimatedSprite();
	SetSwordLocationAndRotation();

	if (HeldObject != nullptr)
	{
		FVector pos = GetActorLocation();
		pos.Z += 100;
		HeldObject->SetActorLocation(pos);
	}

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPawn::Attack()
{
	

}

void APlayerPawn::StopAttack()
{
	SetActionState(EPlayerActionState::Idle);
	SwordSprite->SetVisibility(false);
	SwordHitComponent->StopAttack();
}

void APlayerPawn::MoveUp(float val)
{
	if (val != 0.0f && PlayerActionState != EPlayerActionState::Attacking)
	{
        FVector PlayerVelocity = GetVelocity();
        TravelDirectionY = -val;
		bUpDownMovement = true;

        if (TravelDirectionY < 0.0f)
        {
			if (!bLeftRightMovement)
			{
				SetDirectionState(EPlayerDirection::Up);
				SetAnimState(EPlayerAnimState::Up);
				AnimatedComponent->SetFlipbook(UpWalk);
				AnimatedComponent->Play();
			}
        }

        else if (TravelDirectionY > 0.0f)
        {
				if (!bLeftRightMovement)
				{
					SetDirectionState(EPlayerDirection::Down);
					SetAnimState(EPlayerAnimState::Down);
					AnimatedComponent->SetFlipbook(DownWalk);
					AnimatedComponent->Play();
				}
        }        
		FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
		SetActionState(EPlayerActionState::Walking);
        //If it is less speed up?
        //if (FMath::Abs(currentVel.Z) < MaxVel)
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
		bUpDownMovement = false;
        FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
        FVector newVel = currentVel;
        newVel.Z = 0;
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
	if (val != 0.f && PlayerActionState != EPlayerActionState::Attacking)
	{
		bLeftRightMovement = true;
		FVector PlayerVelocity = GetVelocity();
        TravelDirectionX = -val;
        //GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::FromInt(val));

		if (!bUpDownMovement)
		{
			if (TravelDirectionX < 0.0f)
			{
				SetDirectionState(EPlayerDirection::Right);
				SetAnimState(EPlayerAnimState::Right);
				AnimatedComponent->SetRelativeRotation(FRotator::ZeroRotator);
				AnimatedComponent->SetFlipbook(RightWalk);
				AnimatedComponent->Play();
			}

			else if (TravelDirectionX > 0.0f)
			{
				SetDirectionState(EPlayerDirection::Left);
				SetAnimState(EPlayerAnimState::Left);
				AnimatedComponent->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));
				AnimatedComponent->SetFlipbook(RightWalk);
				AnimatedComponent->Play();
			}
		}
        FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
		//GEngine->AddOnScreenDebugMessage(1, .5f, FColor::Green, FString::FromInt(currentVel.X));

		SetActionState(EPlayerActionState::Walking);
		//If it is less speed up?
		//if (FMath::Abs(currentVel.X) < MaxVel)
		//{
		//	CapsuleComponent->BodyInstance.AddForce(FVector(1.f, 0.f, 0.f) * MovementForce * val);
		//}
		//else
		{
			FVector newVel = FVector(MaxVel * val, 0.0f, currentVel.Z);
			CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);
		}
	}
    else
    {
		bLeftRightMovement = false;
		FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
		FVector newVel = currentVel;
		newVel.X = 0;
		CapsuleComponent->BodyInstance.SetLinearVelocity(newVel,false);
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
	if (bCanPickUp && !bIsHolding)
	{
		//Pickup
		HeldObject = ObjectThatCanBeHeld;
		UCapsuleComponent* heldCapsule = Cast<UCapsuleComponent>(HeldObject->GetDefaultSubobjectByName("Capsule Component"));
		
		heldCapsule->SetSimulatePhysics(false);
		heldCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		bCanPickUp = false;
		bIsHolding = true;

		SetActionState(EPlayerActionState::Holding);
	}
}

void APlayerPawn::Throw()
{
	if (bIsHolding || PlayerActionState == EPlayerActionState::Holding)
	{
		if (HeldObject != nullptr)
		{
			bIsHolding = false;

			FVector playerLoc = GetActorLocation();

			FVector dir(0,0,0);
			if (PlayerDirection == EPlayerDirection::Up){ dir = FVector(0, 0, 1); /*HeldObject->SetActorLocation(FVector(playerLoc.X, playerLoc.Y, playerLoc.Z));*/}
			if (PlayerDirection == EPlayerDirection::Down) { dir = FVector(0, 0, -1); HeldObject->SetActorLocation(FVector(playerLoc.X, playerLoc.Y, playerLoc.Z - 90)); }
			if (PlayerDirection == EPlayerDirection::Left) { dir = FVector(-1, 0, 0);  HeldObject->SetActorLocation(FVector(playerLoc.X - 30, playerLoc.Y, playerLoc.Z));}
			if (PlayerDirection == EPlayerDirection::Right) { dir = FVector(1, 0, 0);  HeldObject->SetActorLocation(FVector(playerLoc.X + 30, playerLoc.Y, playerLoc.Z));
			}

			SetActionState(EPlayerActionState::Idle);

			UCapsuleComponent* heldCapsule = Cast<UCapsuleComponent>(HeldObject->GetDefaultSubobjectByName("Capsule Component"));

			heldCapsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			heldCapsule->SetSimulatePhysics(true);
			heldCapsule->AddImpulse(dir * 500000); //I think I need a big number since it hasn't been working

			HeldObject = nullptr;
		}
	}
}

void APlayerPawn::UpdateAnimatedSprite()
{

	float velocity = GetVelocity().Size();

	if (velocity != 0.f && PlayerActionState != EPlayerActionState::Attacking)
	{
		if (PlayerAnimState == EPlayerAnimState::Right || PlayerAnimState == EPlayerAnimState::Left)
		{
			AnimatedComponent->SetFlipbook(RightWalk);
			AnimatedComponent->Play();
		}
	}

		if (PlayerActionState == EPlayerActionState::Idle || PlayerActionState == EPlayerActionState::Attacking)
		{
			SetIdleDirectionSprite();
			return;
		}


}

void APlayerPawn::SetIdleDirectionSprite()
{
    if (PlayerDirection == EPlayerDirection::Down) AnimatedComponent->SetFlipbook(IdleDown);
    if (PlayerDirection == EPlayerDirection::Up) AnimatedComponent->SetFlipbook(IdleUp);
    if (PlayerDirection == EPlayerDirection::Right || PlayerDirection == EPlayerDirection::Left) AnimatedComponent->SetFlipbook(IdleRight);

	AnimatedComponent->Stop();
}

void APlayerPawn::SetSwordLocationAndRotation()
{
	if (PlayerDirection == EPlayerDirection::Down)
	{
		SwordHitComponent->SetRelativeLocation(FVector(0,10,-90));
		SwordHitComponent->SetRelativeRotation(FRotator(180, 0, 0));
	}															
																
	if (PlayerDirection == EPlayerDirection::Up)				
	{															
		SwordHitComponent->SetRelativeLocation(FVector(0,-10,90));
		SwordHitComponent->SetRelativeRotation(FRotator(0, 0, 0));
	}															
																
	if (PlayerDirection == EPlayerDirection::Right)				
	{															
		SwordHitComponent->SetRelativeLocation(FVector(90, -0, -10));
		SwordHitComponent->SetRelativeRotation(FRotator(-90, 0, 0));
	}															
																
	if (PlayerDirection == EPlayerDirection::Left)				
	{															
		SwordHitComponent->SetRelativeLocation(FVector(-90, 0, -10));
		SwordHitComponent->SetRelativeRotation(FRotator(90, 0, 0));
	}

}

void APlayerPawn::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr)
	{

	}
}

void APlayerPawn::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag("Gem"))
		{
			AGem* g = Cast<AGem>(OtherActor);
			int Gvalue = g->GetValue();
			IncrementGems(Gvalue);
			g->Destroy();
		}
	}
}

void APlayerPawn::OnPickupEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag("Pot"))
		{
			bCanPickUp = true;
			ObjectThatCanBeHeld = OtherActor;
		}
	}
}

void APlayerPawn::OnPickupExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag("Pot"))
		{
			bCanPickUp = false;
			ObjectThatCanBeHeld = false;
		}
	}
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

    if (nCurrentHealth > nMaxHealth) nCurrentHealth = nMaxHealth;
}

void APlayerPawn::DecrementHealth(int health)
{
	nCurrentHealth -= health;
}

int APlayerPawn::GetHealth()
{
	return nCurrentHealth;
}
