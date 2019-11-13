// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Blueprint/UserWidget.h"
#include "ConstructorHelpers.h"

AMyHUD::AMyHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> Hud(TEXT("Blueprint'/Game/Blueprints/UI/GameUI'"));
}

void AMyHUD::BeginPlay()
{

}
