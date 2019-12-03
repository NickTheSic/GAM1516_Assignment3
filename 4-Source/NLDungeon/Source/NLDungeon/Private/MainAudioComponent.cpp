// Assignment 3 by Nick Lemmon


#include "MainAudioComponent.h"

void UMainAudioComponent::PlayDestroySound()
{
    SetSound(DestroySound);
    Play();
}
