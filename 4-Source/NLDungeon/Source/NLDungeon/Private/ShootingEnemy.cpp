// Assignment 3 by Nick Lemmon


#include "ShootingEnemy.h"
#include "Perception/PawnSensingComponent.h"
#include "AnimationController.h"
#include "ArrowProjectile.h"
#include "BPFunctionLib.h"
#include "Components/ArrowComponent.h"
#include "PaperSpriteComponent.h"
#include "TimerManager.h"
#include "Components/CapsuleComponent.h"

AShootingEnemy::AShootingEnemy()
{
	SpawnPoint = CreateDefaultSubobject<UArrowComponent>("SpawnArrow");
	SpawnPoint->SetupAttachment(RootComponent);
    
	TimeDelay = 0.f;
	TimeBetween = 3.0;
	CapsuleComponent->SetLinearDamping(20.f);
}

void AShootingEnemy::Tick(float deltaSeconds)
{
    Super::Tick(deltaSeconds);

   //FVector Direction = Location - GetActorLocation();
   //Direction.Normalize();
   //FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
   //NewLookAt.Pitch = 0.0f;
   //NewLookAt.Roll = 0.0f;
   //SpawnPoint->SetRelativeRotation(NewLookAt);

}

void AShootingEnemy::BeginPlay()
{
    Super::BeginPlay();
}

void AShootingEnemy::OnPawnSeen(APawn* player)
{
	AnimationController->SetWalkingDown(); //Since I didn't make an Active function for the sprite
	if (player->ActorHasTag("Player"))
	{
		FTimerManager& TimerManager = GetWorldTimerManager();
		TimerManager.SetTimer(SpawnTimer, this, &AShootingEnemy::SpawnProjectileAttack, TimeBetween, true, TimeDelay);
        Location = player->GetActorLocation();
	}
}

void AShootingEnemy::OnPawnHeard(APawn* NoiseInstigator, const FVector& Location, float Volume)
{

}

void AShootingEnemy::SpawnProjectileAttack()
{
    UWorld* World = GetWorld();
    if (World)
    {
        if (FireballTemplate != nullptr)
        {
            FActorSpawnParameters params;
            params.Owner = this;
            params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
            FTransform spawn = SpawnPoint->GetComponentTransform();

            AArrowProjectile* arrow = World->SpawnActor<AArrowProjectile>(FireballTemplate, spawn, params);
        }
    }
}
