// Fill out your copyright notice in the Description page of Project Settings.


#include "ShieldPickup.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AShieldPickup::AShieldPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Tags.Add("ShieldPickup");
}

// Called when the game starts or when spawned
void AShieldPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShieldPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AShieldPickup::OnPickupEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}
