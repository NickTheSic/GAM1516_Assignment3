// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagableObject.h"
#include "Components/CapsuleComponent.h"
#include "DungeonGameState.h"
#include "Engine/World.h"
#include "PaperSpriteComponent.h"

ADamagableObject::ADamagableObject()
{
	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	SetRootComponent(Capsule);

	//I Can setup some base stuff for the sprite here
	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>("PaperSprite");
	PaperSprite->SetCollisionProfileName("NoCollision");
	PaperSprite->SetNotifyRigidBodyCollision(false);
	PaperSprite->SetupAttachment(RootComponent);
	ObjectHealth = 1; //Default Value

	Tags.Add("DamagableObject");
}

void ADamagableObject::BeginPlay()
{
	AGameState = Cast<ADungeonGameState>(GetWorld()->GetGameState());
}

void ADamagableObject::TakeHitDamage(float damage)
{
    ObjectHealth -= damage;

	if (ObjectHealth <= 0)
	{
		OnNoHealth();
	}
}

void ADamagableObject::OnNoHealth()
{
	if (AGameState)
	{
		AGameState->SetLocationToSpawnItem(GetActorLocation());
		AGameState->SetCanSpawnItem(true);
	}
	Destroy();
}