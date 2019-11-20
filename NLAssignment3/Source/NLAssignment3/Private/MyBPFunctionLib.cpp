// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBPFunctionLib.h"
#include "Components/PrimitiveComponent.h"


void UMyBPFunctionLib::SpriteCollisionSetup(UPrimitiveComponent* paper2d)
{
    paper2d->SetCollisionProfileName("NoCollision");
    paper2d->SetNotifyRigidBodyCollision(false);
    paper2d->SetGenerateOverlapEvents(false);
}


