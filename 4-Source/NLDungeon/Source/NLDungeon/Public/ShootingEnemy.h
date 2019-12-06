// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "EnemyClass.h"
#include "ShootingEnemy.generated.h"

/**
 * 
 */
UCLASS()
class NLDUNGEON_API AShootingEnemy : public AEnemyClass
{
	GENERATED_BODY()
	
public:
	AShootingEnemy();

	virtual void Tick(float deltaSeconds) override;

protected:

	virtual void BeginPlay() override;

		virtual void OnPawnSeen(class APawn* player);

		virtual void OnPawnHeard(APawn* NoiseInstigator, const FVector& Location, float Volume);

	void SpawnProjectileAttack();

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* SpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		FTimerHandle SpawnTimer;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		float TimeDelay;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		float TimeBetween;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AArrowProjectile> FireballTemplate;
};
