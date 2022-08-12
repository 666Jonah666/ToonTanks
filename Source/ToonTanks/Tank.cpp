// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank() {
	this->Arm = CreateDefaultSubobject<USpringArmComponent>("Arm Component");
	Arm->SetupAttachment(RootComponent);
	this->Camera = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	Camera->SetupAttachment(Arm);
}


