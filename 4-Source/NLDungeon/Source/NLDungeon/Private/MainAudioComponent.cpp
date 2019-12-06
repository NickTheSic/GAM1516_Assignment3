// Assignment 3 by Nick Lemmon


#include "MainAudioComponent.h"
#include "Components/PawnNoiseEmitterComponent.h"
#include "ConstructorHelpers.h"
#include "Gameframework/Actor.h"

UMainAudioComponent::UMainAudioComponent()
{
	ConstructorHelpers::FObjectFinder<USoundBase> DestroySFX(TEXT("/Game/Audio/SimpleBreak"));

	if (DestroySFX.Succeeded())
		DestroySound = DestroySFX.Object;

	NoiseEmitter = CreateDefaultSubobject<UPawnNoiseEmitterComponent>("Noise Emitter");
}

void UMainAudioComponent::PlayDestroySound(AActor* maker, FVector loc)
{
    SetSound(DestroySound);
	NoiseEmitter->MakeNoise(maker, 0.8f, loc);
    Play();
}
