// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank() {
	this->Arm = CreateDefaultSubobject<USpringArmComponent>("Arm Component");
	Arm->SetupAttachment(RootComponent);
	this->Camera = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	Camera->SetupAttachment(Arm);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float Value) {
	
	FVector DeltaLocation{FVector::ZeroVector};
	//X = Value * DeltaTime * Speed;
	DeltaLocation.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float Value) {
	FRotator DeltaRotation{FRotator::ZeroRotator};
	DeltaRotation.Yaw = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;
	AddActorLocalRotation(DeltaRotation, true);
}

