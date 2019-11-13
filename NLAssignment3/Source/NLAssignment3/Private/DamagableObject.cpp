// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagableObject.h"

ADamagableObject::ADamagableObject()
{

}

void ADamagableObject::TakeDamage()
{
	ObjectHealth--;
}
