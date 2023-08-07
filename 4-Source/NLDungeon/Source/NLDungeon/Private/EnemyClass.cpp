// Assignment 3 by Nick Lemmon


#include "EnemyClass.h"
#include "BPFunctionLib.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "AnimationController.h"
#include "Perception/PawnSensingComponent.h"


AEnemyClass::AEnemyClass()
{
	UPaperSpriteComponent* pscomp = Cast<UPaperSpriteComponent>(GetComponentByClass(UPaperSpriteComponent::StaticClass()));
	if (pscomp)
	{
		pscomp->DestroyComponent();
		pscomp->SetActive(false);
	}

    AnimationController = CreateDefaultSubobject<UAnimationController>("AnimationController");
    AnimationController->SetupAttachment(RootComponent);

    PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("Pawn Sensor");
    PawnSensingComponent->OnSeePawn.AddDynamic(this, &AEnemyClass::OnPawnSeen);
    PawnSensingComponent->OnHearNoise.AddDynamic(this, &AEnemyClass::OnPawnHeard);

    Tags.Add("Enemy");

}

void AEnemyClass::Tick(float deltaSeconds)
{
    Super::Tick(deltaSeconds);
}

void AEnemyClass::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyClass::OnPawnSeen(APawn* player)
{

}

void AEnemyClass::OnPawnHeard(APawn* NoiseInstigator, const FVector& Location, float Volume)
{

}
