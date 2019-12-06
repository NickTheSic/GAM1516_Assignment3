// Assignment 3 by Nick Lemmon

#include "DamagableObject.h"
#include "BPFunctionLib.h"
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "DungeonGameState.h"
#include "PaperSpriteComponent.h"
//#include "Engine/Engine.h"

// Sets default values
ADamagableObject::ADamagableObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->SetCollisionProfileName("BlockAll");
	CapsuleComponent->SetSimulatePhysics(true);
	CapsuleComponent->SetEnableGravity(false);
	UBPFunctionLib::LockPhysicsTo2DAxis(CapsuleComponent);
	SetRootComponent(CapsuleComponent);

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite Component");
    UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
	SpriteComponent->SetupAttachment(RootComponent);

	ObjectHealth = 1; //DEFAULT VALUE HEALTH

	Tags.Add("DamagableObject");

}

void ADamagableObject::ObjectTakeDamage(int damage)
{
 	ObjectHealth -= damage;
	if (ObjectHealth <= 0) OnNoHealth();
}

void ADamagableObject::OnNoHealth()
{
	// should this be overridden by the derived class?
	//for the most part other than the player they die and spawn an item

	if (DungeonGameState != nullptr)
	{
		DungeonGameState->SetItemSpawnLocation(GetActorLocation());
		DungeonGameState->SetCanSpawnItem(true);
		DungeonGameState->SetCanPlayAudio(true);
 		DungeonGameState->SetAudioLocation(GetActorLocation());
	}

	Destroy();
}

// Called when the game starts or when spawned
void ADamagableObject::BeginPlay()
{
	Super::BeginPlay();
	
	DungeonGameState = Cast<ADungeonGameState>(GetWorld()->GetGameState());
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

