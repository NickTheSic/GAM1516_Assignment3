// Assignment 3 by Nick Lemmon


#include "CheckpointArea.h"
#include "DungeonGameState.h"
#include "Components/SphereComponent.h"
#include "Components/SphereComponent.h"
#include "PaperSpriteComponent.h"
#include "BPFunctionLib.h"

// Sets default values
ACheckpointArea::ACheckpointArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
    Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointArea::OnOverlap);
    SetRootComponent(Sphere);

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
    UBPFunctionLib::SetupSpritePhysics(SpriteComponent);
    SpriteComponent->SetupAttachment(RootComponent);

    Tags.Add("Checkpoint");

}

void ACheckpointArea::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor != nullptr)
    {
        if (OtherActor->ActorHasTag("Player"))
        {
            if (DungeonState == nullptr) Cast<ADungeonGameState>(GetWorld()->GetGameState());
            if (DungeonState != nullptr)
            {
                DungeonState->SetCheckpointLocation(GetActorLocation());
            }
        }
    }
}

// Called when the game starts or when spawned
void ACheckpointArea::BeginPlay()
{
	Super::BeginPlay();
	
    DungeonState = Cast<ADungeonGameState>(GetWorld()->GetGameState());

}


