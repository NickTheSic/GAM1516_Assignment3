// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Blueprint/UserWidget.h"
#include "ConstructorHelpers.h"

AMyHUD::AMyHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> Hud(TEXT("Blueprint'/Game/Blueprints/UI/GameUI'"));

	if (Hud.Succeeded())
		GuiClass = Hud.Class;
}

void AMyHUD::BeginPlay()
{
	Gui = CreateWidget<UUserWidget>(GetGameInstance(), GuiClass);
	Gui->AddToViewport();
}
