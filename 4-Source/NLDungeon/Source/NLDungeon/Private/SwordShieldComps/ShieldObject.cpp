// Assignment 3 by Nick Lemmon


#include "ShieldObject.h"

// Sets default values
AShieldObject::AShieldObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShieldObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShieldObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

