// Assignment 3 by Nick Lemmon


#include "ArrowSpawner.h"
#include "ArrowProjectile.h"
#include "BPFunctionLib.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "TimerManager.h"

// Sets default values
AArrowSpawner::AArrowSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Component");
	UBPFunctionLib::LockPhysicsTo2DAxis(BoxComponent);
	BoxComponent->SetCollisionProfileName("BlockAll");
	//BoxComponent->SetSimulatePhysics(true);
	//BoxComponent->SetEnableGravity(false);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
    SetRootComponent(BoxComponent);

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
	UBPFunctionLib::SetupSpritePhysics(Sprite);
	UBPFunctionLib::FindSpriteAndSetupBox(Sprite, BoxComponent, "/Game/Sprites/ArrowSpawner");
    Sprite->SetupAttachment(RootComponent);

	SpawnPoint = CreateDefaultSubobject<UArrowComponent>("SpawnArrow");
	SpawnPoint->SetupAttachment(RootComponent);
    SpawnPoint->SetupAttachment(RootComponent);

    TimeDelay = 0.f;
    TimeBetween = 3.0;

	//Tags.Add("Holdable");
}

void AArrowSpawner::SpawnArrow()
{
	UWorld* World = GetWorld();
	if (World)
	{
		if (ArrowTemplate != nullptr)
		{
			FActorSpawnParameters params;
			params.Owner = this;
			params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			FTransform spawn = SpawnPoint->GetComponentTransform();

			AArrowProjectile* arrow = World->SpawnActor<AArrowProjectile>(ArrowTemplate, spawn, params);
		}
	}
}

// Called when the game starts or when spawned
void AArrowSpawner::BeginPlay()
{
	Super::BeginPlay();

	FTimerManager& TimerManager = GetWorldTimerManager();
	TimerManager.SetTimer(SpawnTimer, this, &AArrowSpawner::SpawnArrow, TimeBetween, true, TimeDelay);
}

// Called every frame
void AArrowSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

