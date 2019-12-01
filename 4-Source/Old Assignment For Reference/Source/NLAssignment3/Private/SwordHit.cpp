// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordHit.h"
#include "DamagableObject.h"
#include "PaperSpriteComponent.h"
#include "MyBPFunctionLib.h"

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
		ADamagableObject* d = Cast<ADamagableObject>(OtherActor);

		if (d != nullptr)
		{
			d->TakeHitDamage();
		}
	}
}
