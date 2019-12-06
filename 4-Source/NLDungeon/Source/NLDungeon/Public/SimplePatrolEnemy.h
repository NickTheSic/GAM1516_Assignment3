// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "EnemyClass.h"
#include "SimplePatrolEnemy.generated.h"

enum class EDirection : uint8
{
	Up,
	Down,
	Left,
	Right,
};

/**
 * 
 */
UCLASS()
class NLDUNGEON_API ASimplePatrolEnemy : public AEnemyClass
{
	GENERATED_BODY()
	
public:
	ASimplePatrolEnemy();

	virtual void Tick(float deltaSeconds) override;

		virtual void OnPawnSeen(class APawn* player);

		virtual void OnPawnHeard(APawn* NoiseInstigator, const FVector& Location, float Volume);

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		TArray<FVector> PositionsToPatrol;

	EDirection Direction;

	bool Pause;
	float PauseTimer;

	float Speed;
	int CurrentPosition;
};
