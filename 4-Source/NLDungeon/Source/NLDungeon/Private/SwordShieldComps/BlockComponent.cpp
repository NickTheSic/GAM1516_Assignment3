// Assignment 3 by Nick Lemmon


#include "BlockComponent.h"

UBlockComponent::UBlockComponent()
{
    SetCollisionProfileName("BlockAll");
    SetNotifyRigidBodyCollision(true);
    //SetEnableGravity(false);
    StopBlock();
}

void UBlockComponent::ActivateBlock()
{
    SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    //SetSimulatePhysics(true);
}

void UBlockComponent::StopBlock()
{
    SetCollisionEnabled(ECollisionEnabled::NoCollision);
    //SetSimulatePhysics(false);
}
