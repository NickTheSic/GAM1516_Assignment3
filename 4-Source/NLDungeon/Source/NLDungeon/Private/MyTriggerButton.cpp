// Assignment 3 by Nick Lemmon


#include "MyTriggerButton.h"
#include "BPFunctionLib.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "MyTriggerObject.h"

// Sets default values
AMyTriggerButton::AMyTriggerButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComponent->SetCollisionProfileName("OverlapAll");
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerButton::OnTriggerEnter);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AMyTriggerButton::OnTriggerExit);
	SetRootComponent(BoxComponent);

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite Comp");
	UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
	UBPFunctionLib::FindSpriteAndSetupBox(SpriteComponent, BoxComponent, "/Game/Sprites/Button");
	SpriteComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyTriggerButton::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyTriggerButton::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && !OtherActor->ActorHasTag("Pickup"))
	{
        //if (!OtherActor->GetDefaultSubobjectByName("PickupArea"))
        ActorsOnButton.Add(OtherActor);

		if (TriggerObject != nullptr)
		{
			TriggerObject->ActivateTrigger();
		}
	}
}

void AMyTriggerButton::OnTriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != nullptr && !OtherActor->ActorHasTag("Pickup"))
	{
        ActorsOnButton.Remove(OtherActor);
		if (TriggerObject != nullptr && ActorsOnButton.Num() == 0)
		{
			TriggerObject->DeactivateTrigger();
		}
	}
}


