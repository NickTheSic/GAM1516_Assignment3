// Assignment 3 by Nick Lemmon


#include "MainAudioComponent.h"


UMainAudioComponent::UMainAudioComponent()
{

}

void UMainAudioComponent::PlayDestroySound()
{
    SetSound(DestroySound);
    Play();
}
