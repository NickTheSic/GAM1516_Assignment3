// Assignment 3 by Nick Lemmon


#include "GameHUD.h"
#include "Blueprint/UserWidget.h"
#include "ConstructorHelpers.h"

AGameHUD::AGameHUD()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> Hud(TEXT("Blueprint'/Game/Blueprints/UI/GameHUD'"));
    if (Hud.Succeeded())
        PlayerGui = Hud.Class;
}

void AGameHUD::BeginPlay()
{
    Gui = CreateWidget<UUserWidget>(GetGameInstance(), PlayerGui);
    Gui->AddToViewport();
}
