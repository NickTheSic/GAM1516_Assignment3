// Fill out your copyright notice in the Description page of Project Settings.


#include "Pot.h"

// Sets default values
APot::APot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

