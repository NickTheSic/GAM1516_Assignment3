// Assignment 3 by Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"
#include "AnimationController.generated.h"

class UPaperFlipbook;

/**
 * 
 */
UCLASS()
class NLDUNGEON_API UAnimationController : public UPaperFlipbookComponent
{
	GENERATED_BODY()

public:
	
	void SetIdleDown();
	void SetIdleUp();
	void SetIdleRight();

	void SetWalkingDown();
	void SetWalkingUp();
	void SetWalkingRight();

private:
	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		UPaperFlipbook* WalkDown;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		UPaperFlipbook* WalkUp;
	
	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		UPaperFlipbook* WalkRight;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		UPaperFlipbook* IdleDown;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		UPaperFlipbook* IdleUp;

	UPROPERTY(EditAnywhere, Category = "Config", meta = (AllowPrivateAccess = "true"))
		UPaperFlipbook* IdleRight;
};
