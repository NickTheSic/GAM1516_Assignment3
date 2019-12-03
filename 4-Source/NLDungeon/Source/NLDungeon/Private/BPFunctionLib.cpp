// Assignment 3 by Nick Lemmon


#include "BPFunctionLib.h"
#include "ConstructorHelpers.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"

void UBPFunctionLib::FindSpriteAndSetupCapsule(UPaperSpriteComponent* sprite, UCapsuleComponent* capsule, FString name)
{
	ConstructorHelpers::FObjectFinder<UPaperSprite> spRef(*name); //Have to dereference the name for it to work

	if (spRef.Succeeded())
	{
		if (sprite != nullptr)
		{
			sprite->SetSprite(spRef.Object);
#if WITH_EDITOR
			if (capsule != nullptr)
			{
				FVector2D size = sprite->GetSprite()->GetSourceSize();
				float x = size.X * 0.5;
				float z = size.Y * 0.5;
				capsule->SetCapsuleRadius(x);
				capsule->SetCapsuleHalfHeight(z);
			}
#endif
		}
	}
}

void UBPFunctionLib::FindSpriteAndSetupBox(UPaperSpriteComponent* sprite, UBoxComponent* box, FString name)
{
	ConstructorHelpers::FObjectFinder<UPaperSprite> spRef(*name); //Have to dereference the name for it to work

	if (spRef.Succeeded())
	{
		if (sprite != nullptr)
		{
			sprite->SetSprite(spRef.Object);
#if WITH_EDITOR
			if (box != nullptr)
			{
				FVector2D size = sprite->GetSprite()->GetSourceSize();
				float x = size.X * 0.5;
				float z = size.Y * 0.5;
				box->SetBoxExtent(FVector(x, z, 5));
			}
#endif
		}
	}
}

void UBPFunctionLib::SetupSpritePhysics(UPaperSpriteComponent* sprite)
{
	if (sprite != nullptr) 
	{
		sprite->SetCollisionProfileName("NoCollision");
		sprite->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		sprite->SetGenerateOverlapEvents(false);
		sprite->SetNotifyRigidBodyCollision(false);
	}
}

void UBPFunctionLib::LockPhysicsTo2DAxis(UPrimitiveComponent* comp)
{
	comp->GetBodyInstance()->bLockRotation = true;
	comp->GetBodyInstance()->bLockXRotation = true;
	comp->GetBodyInstance()->bLockYRotation = true;
	comp->GetBodyInstance()->bLockZRotation = true;
	comp->GetBodyInstance()->bLockYTranslation = true;
}
