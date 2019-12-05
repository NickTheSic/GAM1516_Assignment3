// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawner.generated.h"

UCLASS()
class NLDUNGEON_API AItemSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemSpawner();

private:
    class ADungeonGameState* DungeonState;
    class UWorld* World;

    void SpawnGem();
    void SpawnHeart();

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        TSubclassOf<class AHealthPickup> HealthTemplate;

    UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
        TSubclassOf<class AGemPickup> GemTemplate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
