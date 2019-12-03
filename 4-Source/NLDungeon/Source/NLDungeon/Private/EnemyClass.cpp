// Assignment 3 by Nick Lemmon


#include "EnemyClass.h"
#include "BPFunctionLib.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "AnimationController.h"
#include "Perception/PawnSensingComponent.h"


AEnemyClass::AEnemyClass()
{
    AnimationController = CreateDefaultSubobject<UAnimationController>("AnimationController");
    AnimationController->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    AnimationController->SetupAttachment(RootComponent);

    PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("Pawn Sensor");
}

void AEnemyClass::Tick(float deltaSeconds)
{
    Super::Tick(deltaSeconds);
}

void AEnemyClass::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyClass::OnPawnSeen(APlayerPawn* player)
{

}

void AEnemyClass::OnPawnHeard()
{

}
