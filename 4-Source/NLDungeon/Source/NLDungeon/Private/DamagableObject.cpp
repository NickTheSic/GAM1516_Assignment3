// Assignment 3 by Nick Lemmon


#include "DamagableObject.h"

// Sets default values
ADamagableObject::ADamagableObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADamagableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamagableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADamagableObject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

