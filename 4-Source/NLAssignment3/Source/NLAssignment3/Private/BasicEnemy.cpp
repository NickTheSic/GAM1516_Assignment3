// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemy.h"
#include "MyFlipbookControlComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABasicEnemy::ABasicEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mfcc = CreateDefaultSubobject<UMyFlipbookControlComponent>("Flipbook");

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	SetRootComponent(CapsuleComponent);

	mfcc->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABasicEnemy::BeginPlay()
{
	Super::BeginPlay();
	//mfcc->Play();
}

// Called every frame
void ABasicEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	mfcc->CustomUpdate(DeltaTime);
}

