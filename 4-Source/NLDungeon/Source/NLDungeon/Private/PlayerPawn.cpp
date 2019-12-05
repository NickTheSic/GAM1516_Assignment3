// Assignment 3 by Nick Lemmon


#include "PlayerPawn.h"
#include "BPFunctionLib.h"
#include "DungeonGameState.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "SwordObject.h"
#include "ShieldObject.h"
#include "ItemPickup.h"
#include "MainAudioComponent.h"
#include "AnimationController.h"
#include "Components/PawnNoiseEmitterComponent.h"


APlayerPawn::APlayerPawn()
{
	//Gonna have to remove the sprite component and everything that I setup from inheriting from the DamagleObject
	//Maybe Inheriting was wrong
	PrimaryActorTick.bCanEverTick = true;

	UPaperSpriteComponent* pscomp = Cast<UPaperSpriteComponent>(GetComponentByClass(UPaperSpriteComponent::StaticClass()));
	if (pscomp)
	{
		pscomp->DestroyComponent();
		pscomp->SetActive(false);
	}

	UBPFunctionLib::FindSpriteAndSetupCapsule(nullptr, CapsuleComponent, "/Game/Sprites/LinkIdleDown");
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->OnComponentHit.AddDynamic(this, &APlayerPawn::MainCapsuleOnHit);
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &APlayerPawn::MainCapsuleOverlap);

	PlayerAnimController = CreateDefaultSubobject<UAnimationController>("Animation Controller");
	PlayerAnimController->SetupAttachment(RootComponent);

	PickupArea = CreateDefaultSubobject<UCapsuleComponent>("PickupArea");
	PickupArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PickupArea->SetCollisionProfileName("OverlapAll");
	PickupArea->SetupAttachment(RootComponent);
	PickupArea->OnComponentBeginOverlap.AddDynamic(this, &APlayerPawn::OnPickupTriggerEnter);
	PickupArea->OnComponentEndOverlap.AddDynamic(this, &APlayerPawn::OnPickupTriggerExit);

	Camera = CreateDefaultSubobject<UCameraComponent>("Follow Camera");
	Camera->SetOrthoWidth(1800.f);
	Camera->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	Camera->SetRelativeLocation(FVector(0.f, 500.f, 0.f));
	Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	Camera->SetupAttachment(RootComponent);

	bCanPickup = false;
	bIsAttacking = false;
	bIsDefending = false;
	bIsHolding = false;
	bPlayerHasShield = false;

	PlayerDirection = EPlayerDirection::Down;

	MaxHealth = 5;
	GemCount = 0;
	Lives = 5;

    Tags.Add("Player");
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	DungeonGameState = Cast<ADungeonGameState>(World->GetGameState());

    //Create the Sword
	if (SwordClass != nullptr)
	{
		FActorSpawnParameters sParams;
		sParams.Owner = this;

		FTransform sTransform = FTransform(GetActorLocation());
		Sword = World->SpawnActor<ASwordObject>(SwordClass, sTransform, sParams);
	}
	//Create Shield
	if (ShieldClass != nullptr)
	{
		FActorSpawnParameters shParams;
		shParams.Owner = this;

		FTransform shTransform = FTransform(GetActorLocation());
		Shield = World->SpawnActor<AShieldObject>(ShieldClass, shTransform, shParams);
	}

	bCanPickup = false;
	bIsAttacking = false;
	bIsDefending = false;
	bIsHolding = false;
	bPlayerHasShield = false;
	bUpDownMovement = false;
	bLeftRightMovement = false;

	PlayerDirection = EPlayerDirection::Down;

	MaxHealth = 5;
	ObjectHealth = MaxHealth;
	GemCount = 0;
	Lives = 5;

}


void APlayerPawn::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
	if (HeldObject != nullptr)
	{
		FVector pos = GetActorLocation();
		pos.Z += 100;
		HeldObject->SetActorLocation(pos);
	}

    //if (bIsAttacking || bIsDefending)
	    SetSwordAndShieldPosition();

}

void APlayerPawn::OnNoHealth()
{
    //Go to last checkpoint and lose a life
	SetActorLocation(DungeonGameState->GetCheckpointLocation());
	IncrementHealth(MaxHealth);
	DecrementGemCount(GemCount * 0.5);
	DecrementLives(1);
}

void APlayerPawn::SetSwordAndShieldPosition()
{
	if (PlayerDirection == EPlayerDirection::Down)
	{
		if (Sword != nullptr)
		{
			Sword->SetActorLocation(GetActorLocation() + FVector(0, 1, -120));
			Sword->SetActorRotation(FRotator(180, 0, 0));
		}

		if (Shield != nullptr)
		{
			Shield->SetActorLocation(FVector(0, 1, -90) + GetActorLocation());
            Shield->SetActorRotation(FRotator(0, 0, 0));
		}
	}

	if (PlayerDirection == EPlayerDirection::Up)
	{
		if (Sword != nullptr)
		{
			Sword->SetActorLocation(FVector(0, -1, 120) + GetActorLocation());
			Sword->SetActorRotation(FRotator(0, 0, 0));
		}	
		if (Shield != nullptr)
		{
			Shield->SetActorLocation(FVector(0, -1, 120) + GetActorLocation());
           Shield->SetActorRotation(FRotator(180, 0, 0));
		}
	}

	if (PlayerDirection == EPlayerDirection::Right)
	{
		if (Sword != nullptr)
		{
			Sword->SetActorLocation(FVector(90, -0, -10) + GetActorLocation());
			Sword->SetActorRotation(FRotator(-90, 0, 0));
		}
		if (Shield != nullptr)
		{
			Shield->SetActorLocation(FVector(90, -0, -10) + GetActorLocation());
            Shield->SetActorRotation(FRotator(90, 0, 0));
		}
	}

	if (PlayerDirection == EPlayerDirection::Left)
	{
		if (Sword != nullptr)
		{
			Sword->SetActorLocation(FVector(-90, 0, -10) + GetActorLocation());
			Sword->SetActorRotation(FRotator(90, 0, 0));
		}
		if (Shield != nullptr)
		{
			Shield->SetActorLocation(FVector(-90, 0, -10) + GetActorLocation());
            Shield->SetActorRotation(FRotator(-90, 0, 0));
		}
	}
}

void APlayerPawn::ActivateAttack()
{
	if (!bIsHolding && !bIsDefending)
	{
		if (Sword != nullptr)
		{
			bIsAttacking = true;
			Sword->ActivateAttack();
		}
	}
}

void APlayerPawn::StopAttack()
{
	if (bIsAttacking && Sword != nullptr)
	{
		bIsAttacking = false;
		Sword->StopAttack();
	}
}

void APlayerPawn::ActivateBlock()
{
	if (!bIsHolding && !bIsAttacking && bPlayerHasShield)
	{
		if (Shield != nullptr)
		{
			bIsDefending = true;
			Shield->ActivateBlock();
		}
	}
}

void APlayerPawn::StopBlock()
{
	if (bPlayerHasShield && bIsDefending && Shield != nullptr)
	{
		bIsDefending = false;
		Shield->StopBlock();
	}
}

void APlayerPawn::MainCapsuleOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void APlayerPawn::MainCapsuleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag("Pickup"))
		{
			AItemPickup* ip = Cast<AItemPickup>(OtherActor);
			if(ip)
			{
				ip->PickupItem(this);
			}
		}
	}
}

void APlayerPawn::OnPickupTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag("Holdable"))
		{
			bCanPickup = true;
			ReferenceToHold = OtherActor;
		}
	}
}

void APlayerPawn::OnPickupTriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag("Holdable"))
		{
			bCanPickup = false;
			ReferenceToHold = false;
		}
	}
}

void APlayerPawn::MoveUp(float val)
{
	if (val != 0.0f && !bIsAttacking)
	{
		//FVector PlayerVelocity = GetVelocity();
		//TravelDirectionY = -val;
		bUpDownMovement = true;

		if (val > 0.0f)
		{
			if (!bLeftRightMovement)
			{
				PlayerDirection = EPlayerDirection::Up;
				PlayerAnimController->SetWalkingUp();
			}
		}

		else if (val < 0.0f)
		{
			if (!bLeftRightMovement)
			{
				PlayerDirection = EPlayerDirection::Down;
				PlayerAnimController->SetWalkingDown();
			}
		}
		FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();

        float Speed = MaxVel - ((MaxVel * 0.5f) * bIsDefending);

		FVector newVel = FVector(currentVel.X, 0.0f, Speed * val);
		CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);


	}
	else
	{
		bUpDownMovement = false;
		FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
		FVector newVel = currentVel;
		newVel.Z = 0;
		CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);
		if (!bLeftRightMovement)
		{
			SetupIdleAnimation();
		}
	}
}

void APlayerPawn::MoveRight(float val)
{
	if (val != 0.0f && !bIsAttacking)
	{
		//FVector PlayerVelocity = GetVelocity();
		//TravelDirectionY = -val;
		bLeftRightMovement = true;

		if (val > 0.0f)
		{
			if (!bUpDownMovement)
			{
				PlayerDirection = EPlayerDirection::Right;
				PlayerAnimController->SetWalkingRight();
				PlayerAnimController->SetRelativeRotation(FRotator::ZeroRotator);
			}
		}

		else if (val < 0.0f)
		{
			if (!bUpDownMovement)
			{
				PlayerDirection = EPlayerDirection::Left;
				PlayerAnimController->SetWalkingRight();
				PlayerAnimController->SetRelativeRotation(FRotator(0.f,180.f,0.f));
			}
		}
		FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
        float Speed = MaxVel - ((MaxVel * 0.5f) * bIsDefending);
		FVector newVel = FVector(Speed * val, 0.0f, currentVel.Z);
		CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);


	}
	else
	{
		bLeftRightMovement = false;
		FVector currentVel = CapsuleComponent->BodyInstance.GetUnrealWorldVelocity();
		FVector newVel = currentVel;
		newVel.X = 0;
		CapsuleComponent->BodyInstance.SetLinearVelocity(newVel, false);
		if (!bUpDownMovement)
		{
			SetupIdleAnimation();
		}
	}
}

void APlayerPawn::SetupIdleAnimation()
{

	if (PlayerDirection == EPlayerDirection::Up)
	{
		PlayerAnimController->SetIdleUp();
	}

	if (PlayerDirection == EPlayerDirection::Down)
	{
		PlayerAnimController->SetIdleDown();
	}

	if (PlayerDirection == EPlayerDirection::Right || PlayerDirection == EPlayerDirection::Left)
	{
		PlayerAnimController->SetIdleRight();
	}

}

void APlayerPawn::Pickup()
{
    if (bCanPickup && !bIsHolding)
    {
		HeldObject = ReferenceToHold;
		UCapsuleComponent* heldCapsule = Cast<UCapsuleComponent>(HeldObject->GetDefaultSubobjectByName("Capsule Component"));

        if (heldCapsule)
        {
            heldCapsule->SetSimulatePhysics(false);
            heldCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);

            bCanPickup = false;
            bIsHolding = true;
        }
    }
}

void APlayerPawn::Throw()
{
    if (bIsHolding)
    {
		if (HeldObject != nullptr)
		{
			bIsHolding = false;

			FVector playerLoc = GetActorLocation();

			FVector dir(0, 0, 0);
			if (PlayerDirection == EPlayerDirection::Up) 
			{ dir = FVector(0, 0, 1);
			/*HeldObject->SetActorLocation(FVector(playerLoc.X, playerLoc.Y, playerLoc.Z));*/ 
			}

			if (PlayerDirection == EPlayerDirection::Down)
			{ 
				dir = FVector(0, 0, -1);
			HeldObject->SetActorLocation(FVector(playerLoc.X, playerLoc.Y, playerLoc.Z - 90)); 
			}

			if (PlayerDirection == EPlayerDirection::Left) 
			{ 
				dir = FVector(-1, 0, 0); 
			HeldObject->SetActorLocation(FVector(playerLoc.X - 30, playerLoc.Y, playerLoc.Z));
			}

			if (PlayerDirection == EPlayerDirection::Right) {
				dir = FVector(1, 0, 0);
				HeldObject->SetActorLocation(FVector(playerLoc.X + 30, playerLoc.Y, playerLoc.Z));
			}

			UCapsuleComponent* heldCapsule = Cast<UCapsuleComponent>(HeldObject->GetDefaultSubobjectByName("Capsule Component"));

			heldCapsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			heldCapsule->SetSimulatePhysics(true);
			heldCapsule->AddImpulse(dir * 550000); //I need the big number so it moves farther

			HeldObject = nullptr;
		}
    }
}


void APlayerPawn::IncrementHealth(int health)
{
    ObjectHealth += health;
    if (ObjectHealth > MaxHealth)
        ObjectHealth = MaxHealth;
}

int APlayerPawn::GetCurrentHealth()
{
    return ObjectHealth;
}

void APlayerPawn::IncrementLives(int lives)
{
    Lives += lives;
}

void APlayerPawn::DecrementLives(int lives)
{
    Lives -= lives;
	if (Lives <= 0)
	{
		check(false); //I don't know how to code an end game yet but I know that it will happen
	}
}

int APlayerPawn::GetCurrentLives()
{
    return Lives;
}

void APlayerPawn::IncrementMaxHealth(int health)
{
    MaxHealth += health;
}

void APlayerPawn::DecrementMaxHealth(int health)
{
    MaxHealth -= health;
}

int APlayerPawn::GetCurrentMaxHealth()
{
    return MaxHealth;
}

void APlayerPawn::IncrementGemCount(int gem)
{
    GemCount += gem;
}

void APlayerPawn::DecrementGemCount(int gem)
{
    GemCount -= gem;
}

int APlayerPawn::GetCurrentGemCount()
{
    return GemCount;
}

void APlayerPawn::SetHasShield(bool hasShield)
{
    bPlayerHasShield = hasShield;
}
