// Fill out your copyright notice in the Description page of Project Settings.

#include "HeartPickup.h"
#include "Components/CapsuleComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "MyBPFunctionLib.h"
#include "PlayerPawn.h"

// Sets default values
AHeartPickup::AHeartPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
    CapsuleComponent->SetCollisionProfileName("Overlap");
    CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CapsuleComponent->SetNotifyRigidBodyCollision(true);
    //CapsuleComponent->SetSimulatePhysics(true);
    //CapsuleComponent->SetEnableGravity(false);
    CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AHeartPickup::OnTriggerEnter);
    SetRootComponent(CapsuleComponent);

    ConstructorHelpers::FObjectFinder<UPaperSprite> HeartRef(TEXT("PaperSprite'/Game/Sprites/HeartSprite'"));
    PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>("PaperSprite");
    UMyBPFunctionLib::SpriteCollisionSetup(PaperSprite);
    PaperSprite->SetupAttachment(RootComponent);

#if WITH_EDITOR
    if (HeartRef.Succeeded())
    {
        PaperSprite->SetSprite(HeartRef.Object);
        FVector2D size = PaperSprite->GetSprite()->GetSourceSize();
        CapsuleComponent->SetCapsuleRadius(size.X / 2);
        CapsuleComponent->SetCapsuleHalfHeight(size.Y / 2);
    }
#endif
    Tags.Add("Pickup");
    Tags.Add("Heart");
}


void AHeartPickup::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}
