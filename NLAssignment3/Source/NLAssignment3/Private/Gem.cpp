// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "Components/CapsuleComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "MyBPFunctionLib.h"

AGem::AGem()
{
	GemValue = 1; //Maybe later I will randomize it but for now I wont

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	CapsuleComponent->SetCollisionProfileName("BlockAll");
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CapsuleComponent->SetNotifyRigidBodyCollision(true);
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