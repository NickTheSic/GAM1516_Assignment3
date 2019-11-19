// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "Components/CapsuleComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"

AGem::AGem()
{
	GemValue = 1; //Maybe later I will randomize it but for now I wont

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	CapsuleComponent->SetCollisionProfileName("BlockAll");
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->SetNotifyRigidBodyCollision(true);
	SetRootComponent(CapsuleComponent);

	ConstructorHelpers::FObjectFinder<UPaperSprite> GemRef (TEXT("PaperSprite'/Game/Sprites/RedGem'"));
	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>("PaperSprite");
	PaperSprite->SetCollisionProfileName("NoCollision");
	PaperSprite->SetNotifyRigidBodyCollision(false);
	PaperSprite->SetupAttachment(RootComponent);

	if (GemRef.Succeeded())
	{
		PaperSprite->SetSprite(GemRef.Object);
		FVector2D size = PaperSprite->GetSprite()->GetSourceSize();
		CapsuleComponent->SetCapsuleRadius(size.X / 2);
		CapsuleComponent->SetCapsuleHalfHeight(size.Y / 2);
	}
}

int AGem::GetValue()
{
	return GemValue;
}