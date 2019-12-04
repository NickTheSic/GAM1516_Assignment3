// Assignment 3 by Nick Lemmon


#include "SwordHitComponent.h"
#include "DamagableObject.h"

USwordHitComponent::USwordHitComponent()
{
    SetCollisionProfileName("BlockAll");
    OnComponentHit.AddDynamic(this, &USwordHitComponent::OnHit);
}

void USwordHitComponent::ActivateAttack()
{
    SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
}

void USwordHitComponent::StopAttack()
{
    SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void USwordHitComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor != nullptr)
    {
        if (OtherActor->ActorHasTag("DamagableObject") && !OtherActor->ActorHasTag("Player"))
        {
            ADamagableObject* d = Cast<ADamagableObject>(OtherActor);
            d->ObjectTakeDamage(1);
        }
    }
}
