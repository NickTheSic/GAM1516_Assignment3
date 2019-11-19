// Fill out your copyright notice in the Description page of Project Settings.


#include "Pot.h"
#include "Components/CapsuleComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"

APot::APot()
{
	Capsule->SetCollisionProfileName("BlockAll");
	Capsule->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Capsule->SetNotifyRigidBodyCollision(true);
	//Capsule->SetSimulatePhysics(true);

	ConstructorHelpers::FObjectFinder<UPaperSprite> PotRef(TEXT("PaperSprite'/Game/Sprites/Barrel'"));
	if (PotRef.Succeeded())
	{
		PaperSprite->SetSprite(PotRef.Object);
		FVector2D size = PaperSprite->GetSprite()->GetSourceSize();
		Capsule->SetCapsuleRadius(size.X / 2);
		Capsule->SetCapsuleHalfHeight(size.Y / 2);
	}
}
