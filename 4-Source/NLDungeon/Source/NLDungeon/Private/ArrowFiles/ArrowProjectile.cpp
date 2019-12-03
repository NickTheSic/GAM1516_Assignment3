// Assignment 3 by Nick Lemmon


#include "ArrowProjectile.h"
#include "BPFunctionLib.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "DamagableObject.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AArrowProjectile::AArrowProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	//Setup Physics
	CapsuleComponent->SetCollisionProfileName("BlockAll");
	UBPFunctionLib::LockPhysicsTo2DAxis(CapsuleComponent);
	CapsuleComponent->OnComponentHit.AddDynamic(this, &AArrowProjectile::OnHit);
	SetRootComponent(CapsuleComponent);

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite Component");
	UBPFunctionLib::SetupSpritePhysics(Sprite);
	Sprite->SetupAttachment(RootComponent);

	UBPFunctionLib::FindSpriteAndSetupCapsule(Sprite, CapsuleComponent, "/Game/Sprites/Arrow");

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");
	Movement->UpdatedComponent = CapsuleComponent;
	Movement->InitialSpeed = 700.f;
	Movement->MaxSpeed = 700.f;
	Movement->bShouldBounce = false;
	//Movement->ShouldApplyGravity = false;

	InitialLifeSpan = 5.f;

}

// Called when the game starts or when spawned
void AArrowProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArrowProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag("DamagableObject"))
		{
			ADamagableObject* d = Cast<ADamagableObject>(OtherActor);
			if (d != nullptr)
			{
				d->ObjectTakeDamage(1);
				//Destroy();
			}
		}
		//Destroy(); //Destroy object so the player doesn't run into it?
	}
}

