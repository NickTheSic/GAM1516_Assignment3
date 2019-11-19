// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "SwordHit.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	CapsuleComponent->SetCollisionProfileName("BlockAll");
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly); //This Component hits things
	CapsuleComponent->SetNotifyRigidBodyCollision(true);
	SetRootComponent(CapsuleComponent);

	AnimatedComponent = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>("Animated Component");
	AnimatedComponent->SetupAttachment(RootComponent);
	AnimatedComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AnimatedComponent->SetGenerateOverlapEvents(false);

	PickupComponent = CreateDefaultSubobject<UCapsuleComponent>("Pickup");

	PickupComponent->SetupAttachment(RootComponent);


	SwordHitComponent = CreateDefaultSubobject<USwordHit>("Attack Box");

	SwordHitComponent->SetupAttachment(RootComponent);


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
	//AnimatedComponent->Stop();

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerActionState == EPlayerActionState::Idle)
	{
		//AnimatedComponent->Stop();
	}
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

	}
}

void APlayerPawn::MoveRight(float val)
{
	if (val != 0.f)
	{
		const FVector PlayerVelocity = GetVelocity();
		TravelDirectionX = -PlayerVelocity.X;

		if (TravelDirectionX < 0.0f)
		{
			AnimatedComponent->SetRelativeRotation(FRotator::ZeroRotator);
		}
		else if (TravelDirectionX > 0.0f)
		{
			AnimatedComponent->SetRelativeRotation(FRotator(0.f,180.f,0.f));
		}

		FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();

		//If it is less speed up?
		if (FMath::Abs(currentVel.X) < MaxVelX)
		{
			CapsuleComponent->BodyInstance.AddForce(FVector(1.f, 0.f, 0.f) * MovementForce * val);
		}
		else
		{
			FVector newVel = FVector(MaxVelX * val, 0.0f, currentVel.Z);
			CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);
		}
	}
}

void APlayerPawn::Pickup()
{

}

void APlayerPawn::Throw()
{

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
