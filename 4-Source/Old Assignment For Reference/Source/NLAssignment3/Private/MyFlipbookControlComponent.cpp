// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFlipbookControlComponent.h"

void UMyFlipbookControlComponent::CustomUpdate(float deltaSeconds)
{
	timer -= deltaSeconds;

	if (timer <= 0) ChangeTheActiveFlipbook();
}

void UMyFlipbookControlComponent::ChangeTheActiveFlipbook() 
{
	timer = 5;

	book = !book;

	if (book) SetFlipbook(UpWalk);
	else SetFlipbook(DownWalk);

	Play();
}
