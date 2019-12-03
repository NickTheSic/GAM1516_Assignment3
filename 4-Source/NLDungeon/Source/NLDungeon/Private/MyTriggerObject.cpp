// Assignment 3 by Nick Lemmon


#include "MyTriggerObject.h"
#include "BPFunctionLib.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
AMyTriggerObject::AMyTriggerObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Component");
    BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
    BoxComponent->SetCollisionProfileName("BlockAll");
    SetRootComponent(BoxComponent);

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite Comp");
    UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
    SpriteComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyTriggerObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyTriggerObject::ActivateTrigger()
{

}

void AMyTriggerObject::DeactivateTrigger()
{

}
