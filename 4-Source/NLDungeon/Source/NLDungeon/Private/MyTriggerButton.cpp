// Assignment 3 by Nick Lemmon


#include "MyTriggerButton.h"

// Sets default values
AMyTriggerButton::AMyTriggerButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTriggerButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

