// Fill out your copyright notice in the Description page of Project Settings.


#include "Pot.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"

APot::APot()
{
	Capsule->SetCollisionProfileName("BlockAll");
	Capsule->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Capsule->SetNotifyRigidBodyCollision(true);
	//Capsule->SetSimulatePhysics(true);

	UPaperSpriteComponent* p = GetRenderComponent();
	ConstructorHelpers::FObjectFinder<UPaperSprite> PotRef(TEXT("PaperSprite'/Game/Sprites/Pot'"));
	p->SetSprite(PotRef.Object);
	Capsule->SetSphereRadius(p->GetSprite()->GetSourceSize().X / 2); //GOING with x, Arbitrary decision
}