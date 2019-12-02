// Assignment 3 by Nick Lemmon


#include "SwordObject.h"

// Sets default values
ASwordObject::ASwordObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASwordObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwordObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

