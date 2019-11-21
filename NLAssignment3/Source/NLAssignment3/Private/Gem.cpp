// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "Components/CapsuleComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "MyBPFunctionLib.h"
#include "PlayerPawn.h"

AGem::AGem()
{
	GemValue = 1; //Maybe later I will randomize it but for now I wont

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	CapsuleComponent->SetCollisionProfileName("Overlap");
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CapsuleComponent->SetNotifyRigidBodyCollision(true);
	//CapsuleComponent->SetSimulatePhysics(true);
	//CapsuleComponent->SetEnableGravity(false);
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AGem::OnTriggerEnter);
	SetRootComponent(CapsuleComponent);

	ConstructorHelpers::FObjectFinder<UPaperSprite> GemRef (TEXT("PaperSprite'/Game/Sprites/RedGem'"));
	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>("PaperSprite");
    UMyBPFunctionLib::SpriteCollisionSetup(PaperSprite);
	PaperSprite->SetupAttachment(RootComponent);

	if (GemRef.Succeeded())
	{
		PaperSprite->SetSprite(GemRef.Object);
		FVector2D size = PaperSprite->GetSprite()->GetSourceSize();
		CapsuleComponent->SetCapsuleRadius(size.X / 2);
		CapsuleComponent->SetCapsuleHalfHeight(size.Y / 2);
	}

	Tags.Add("Gem");
}

int AGem::GetValue()
{
	return GemValue;
}

void AGem::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		//if (OtherActor->ActorHasTag("Player"))
		//{
		//	APlayerPawn* g = Cast<APlayerPawn>(OtherActor);
		//	int Gvalue = GetValue();
		//	g->IncrementGems(Gvalue);
		//	Destroy();
		//}
	}
}
