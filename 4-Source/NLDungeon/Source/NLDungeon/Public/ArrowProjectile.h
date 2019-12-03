// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowProjectile.generated.h"

UCLASS()
class NLDUNGEON_API AArrowProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowProjectile();

private:
	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* Movement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
