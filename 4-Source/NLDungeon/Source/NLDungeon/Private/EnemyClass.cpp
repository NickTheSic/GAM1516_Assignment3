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
    /*
    
        //TODO Week 10b:
    //SUBSCRIBE to the PawnSensingComponent's OnSeePawn event passing in (this, &AAIGuard::OnPawnSeen)
    PawnSensingComponent->OnSeePawn.AddDynamic(this, &AAIGuard::OnPawnSeen);
    //TODO Week 10b:
    //SUBSCRIBE to the PawnSensingComponent's OnHearNoise event passing in (this, &AAIGuard::OnNoiseHeard)
    PawnSensingComponent->OnHearNoise.AddDynamic(this, &AAIGuard::OnNoiseHeard);
    
    */

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
