// Assignment 3 by Nick Lemmon


#include "ItemSpawner.h"
#include "DungeonGameState.h"
#include "ConstructorHelpers.h"
#include "GemPickup.h"
#include "HealthPickup.h"
#include "Engine/Engine.h"

// Sets default values
AItemSpawner::AItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Find the Gem and the Heart OBJ?
    ConstructorHelpers::FClassFinder<AHealthPickup> health(TEXT("/Game/Blueprints/BP_HealthPickup"));
    if (health.Succeeded())
        HealthTemplate = health.Class;

    ConstructorHelpers::FClassFinder<AGemPickup> gem(TEXT("/Game/Blueprints/BP_GemPickup"));
    if (gem.Succeeded())
        HealthTemplate = gem.Class;
}

// Called when the game starts or when spawned
void AItemSpawner::BeginPlay()
{
	Super::BeginPlay();
    World = GetWorld();
    DungeonState = Cast<ADungeonGameState>(World->GetGameState());
}

void AItemSpawner::SpawnGem()
{
    if (World && DungeonState && GemTemplate)
    {
        FActorSpawnParameters params;
        params.Owner = this;
        FTransform trans = FTransform(DungeonState->GetItemSpawnLocation());
        World->SpawnActor<AGemPickup>(GemTemplate, trans, params);
    }
}

void AItemSpawner::SpawnHeart()
{
    if (World && DungeonState && HealthTemplate)
    {
        FActorSpawnParameters params;
        params.Owner = this;
        World->SpawnActor<AHealthPickup>(HealthTemplate, DungeonState->GetItemSpawnLocation(), FRotator::ZeroRotator, params);
    }
}

// Called every frame
void AItemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (DungeonState)
    {
        if (DungeonState->GetCanSpawnItem())
        {
            DungeonState->SetCanSpawnItem(false);

            //Easy way to spawn one or spawn the other for now. That way it spawns an item everytime and spawns a gem more often than health
            if (FMath::RandRange(0, 100) > 30.f) SpawnGem();
            else SpawnHeart();
        }
    }
}

