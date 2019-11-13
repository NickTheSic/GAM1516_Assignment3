// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "ConstructorHelpers.h"

AGem::AGem()
{
	GemValue = 1; //Maybe later I will randomize it but for now I wont
}

int AGem::GetValue()
{
	return GemValue;
}