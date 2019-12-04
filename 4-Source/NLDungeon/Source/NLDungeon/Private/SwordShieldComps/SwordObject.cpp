// Assignment 3 by Nick Lemmon


#include "SwordObject.h"
#include "BPFunctionLib.h"
#include "PaperSpriteComponent.h"
#include "SwordHitComponent.h"

// Sets default values
ASwordObject::ASwordObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SwordComponent = CreateDefaultSubobject<USwordHitComponent>("SwordHitComp");

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");

    UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
    UBPFunctionLib::FindSpriteAndSetupBox(SpriteComponent, SwordComponent, "/Game/Sprites/Sword");

}

void ASwordObject::ActivateAttack()
{

    SwordComponent->ActivateAttack();
    SpriteComponent->SetVisibility(true);
}

void ASwordObject::StopAttack()
{
    SwordComponent->StopAttack();
    SpriteComponent->SetVisibility(false);
}

// Called when the game starts or when spawned
void ASwordObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwordObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

