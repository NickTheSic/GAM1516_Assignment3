// Assignment 3 by Nick Lemmon


#include "MyTriggerObject.h"

// Sets default values
AMyTriggerObject::AMyTriggerObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTriggerObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

