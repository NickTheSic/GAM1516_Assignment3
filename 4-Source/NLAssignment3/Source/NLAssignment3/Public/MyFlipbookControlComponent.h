// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"
#include "MyFlipbookControlComponent.generated.h"

/**
 * 
 */
UCLASS()
class NLASSIGNMENT3_API UMyFlipbookControlComponent : public UPaperFlipbookComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* UpWalk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* DownWalk;

	void CustomUpdate(float deltaSeconds);
	void ChangeTheActiveFlipbook();

	float timer = 5.f;
	bool book;

};
