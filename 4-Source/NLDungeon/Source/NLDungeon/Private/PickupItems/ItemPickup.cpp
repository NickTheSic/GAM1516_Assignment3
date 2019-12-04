// Assignment 3 by Nick Lemmon


#include "ItemPickup.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "BPFunctionLib.h"


// Sets default values
AItemPickup::AItemPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
    SetRootComponent(CapsuleComponent);

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
    UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
    SpriteComponent->SetupAttachment(RootComponent);

    Tags.Add("Pickup");

}

void AItemPickup::PickupItem(APlayerPawn* player)
{

}

// Called when the game starts or when spawned
void AItemPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
