// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagableObject.h"
#include "Components/SphereComponent.h"
#include "DungeonGameState.h"
#include "Engine/World.h"
#include "PaperSpriteComponent.h"

ADamagableObject::ADamagableObject()
{
	Capsule = CreateDefaultSubobject<USphereComponent>("Capsule Component");
	SetRootComponent(Capsule);

	//I Can setup some base stuff for the sprite here
	UPaperSpriteComponent* p = GetRenderComponent();
	p->SetCollisionProfileName("NoCollision");
	p->SetNotifyRigidBodyCollision(false);
	p->SetupAttachment(RootComponent);
	ObjectHealth = 1; //Default Value
}

void ADamagableObject::BeginPlay()
{
	AGameState = Cast<ADungeonGameState>(GetWorld()->GetGameState());
}

void ADamagableObject::TakeDamage()
{
	ObjectHealth--;

	if (ObjectHealth <= 0)
	{
		OnNoHealth();
	}
}

void ADamagableObject::OnNoHealth()
{
	if (AGameState)
	{
		AGameState->SetLocationToSpawnGem(GetActorLocation());
		AGameState->SetCanSpawnGem(true);
	}
}