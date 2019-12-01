// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagePlayerComponent.h"
#include "PlayerPawn.h"


UDamagePlayerComponent::UDamagePlayerComponent()
{
    DamageToDeal = 1; //A Default value for an attack
}

void UDamagePlayerComponent::ActivateAttack()
{

}

void UDamagePlayerComponent::Deactivate()
{

}

void UDamagePlayerComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor != nullptr)
    {
        if (OtherActor->ActorHasTag("Player"))
        {
            APlayerPawn* player = Cast<APlayerPawn>(OtherActor);
            if (player != nullptr)
            {
                player->DecrementHealth(DamageToDeal);
                Deactivate();
            }
        }
    }
}
