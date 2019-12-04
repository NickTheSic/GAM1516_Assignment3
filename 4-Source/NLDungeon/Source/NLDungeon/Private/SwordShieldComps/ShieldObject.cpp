// Assignment 3 by Nick Lemmon


#include "ShieldObject.h"
#include "BlockComponent.h"
#include "BPFunctionLib.h"
#include "PaperSpriteComponent.h"

// Sets default values
AShieldObject::AShieldObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    BlockComponent = CreateDefaultSubobject<UBlockComponent>("Block");
    SetRootComponent(BlockComponent);

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
    UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
    UBPFunctionLib::FindSpriteAndSetupBox(SpriteComponent, BlockComponent, "/Game/Sprites/Shield");

}

void AShieldObject::ActivateBlock()
{
    BlockComponent->ActivateBlock();
    SpriteComponent->SetVisibility(false);
}

void AShieldObject::StopBlock()
{
    BlockComponent->StopBlock();
    SpriteComponent->SetVisibility(false);
}

// Called when the game starts or when spawned
void AShieldObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShieldObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

