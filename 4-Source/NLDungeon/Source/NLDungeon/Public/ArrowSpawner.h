// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowSpawner.generated.h"

UCLASS()
class NLDUNGEON_API AArrowSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowSpawner();

private:

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AArrowProjectile> ArrowTemplate;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* Sprite;
	
	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* SpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
	FTimerHandle SpawnTimer;

	void SpawnArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
