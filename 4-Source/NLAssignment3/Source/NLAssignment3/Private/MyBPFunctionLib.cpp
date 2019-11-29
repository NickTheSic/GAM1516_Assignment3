// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBPFunctionLib.h"
#include "Components/PrimitiveComponent.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"

void UMyBPFunctionLib::SpriteCollisionSetup(UPrimitiveComponent* paper2d)
{
    paper2d->SetCollisionProfileName("NoCollision");
    paper2d->SetNotifyRigidBodyCollision(false);
    paper2d->SetGenerateOverlapEvents(false);
}

void UMyBPFunctionLib::Test(class UPaperSpriteCmponent* sprite, class UCapsuleComponent* cap, FString str)
{
    ConstructorHelpers::FObjectFinder<UPaperSprite> PlayerRef(*str);
    if (PlayerRef.Succeeded())
    {
        FVector2D size = PlayerRef.Object->GetSourceSize();
        cap->SetCapsuleHalfHeight(size.Y / 2);
        cap->SetCapsuleRadius(size.X / 2);
    }
}
