// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordHit.h"

USwordHit::USwordHit()
{
	SetCollisionProfileName("BlockAll");
	SetNotifyRigidBodyCollision(true);
	OnComponentHit.AddDynamic(this, &USwordHit::OnHit);

	StopAttack();
}

void USwordHit::StopAttack()
{
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void USwordHit::ActivateAttack()
{
	//Make sure this is facing the proper direction for attack
	SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void USwordHit::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr)
	{
		//Cast actor as DamagableObject

		//If it is not null

		//if it has the tag Enemy
		//Add force, take damage
		//return
	}
}
