// Assignment 3 by Nick Lemmon


#include "ItemPickup.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "BPFunctionLib.h"
#include "MainAudioComponent.h"
#include "TimerManager.h"

// Sets default values
AItemPickup::AItemPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
    UBPFunctionLib::LockPhysicsTo2DAxis(CapsuleComponent);
    SetRootComponent(CapsuleComponent);

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
    UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
    SpriteComponent->SetupAttachment(RootComponent);

    AudioComponent = CreateDefaultSubobject<UMainAudioComponent>("Audio");

    Tags.Add("Pickup");

}

void AItemPickup::PickupItem(APlayerPawn* player)
{
    AudioComponent->PlayDestroySound(this, this->GetActorLocation());
    CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SpriteComponent->SetVisibility(false);

    FTimerManager& TimerManager = GetWorldTimerManager();
    TimerManager.SetTimer(ToDestroy, this, &AItemPickup::SetToDestroy, 2.5, false, 2.5);
}

// Called when the game starts or when spawned
void AItemPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemPickup::SetToDestroy()
{
    Destroy();
}

// Called every frame
void AItemPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

