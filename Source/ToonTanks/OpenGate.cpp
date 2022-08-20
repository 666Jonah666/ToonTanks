// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenGate.h"
#include "Engine/TriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
UOpenGate::UOpenGate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenGate::BeginPlay()
{
	Super::BeginPlay();

	InitialX = GetOwner()->GetActorLocation().X;
	TargetX += InitialX;
	CurrentX = InitialX;

	Test();
	
}


// Called every frame
void UOpenGate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	TArray<AActor*> Actors;
	PressurePlate->GetOverlappingActors(Actors);
	if (PressurePlate && Actors.Num() > 0) {
		UE_LOG(LogTemp, Warning, TEXT("Is overlapping %s"), *Actors[0]->GetName())
		OpenDoor(DeltaTime);
	} 
}

void UOpenGate::OpenDoor(float DeltaTime) {

	if (bPlayed && AudioComponent) {
		AudioComponent->Play();
		bPlayed = false;
	}
	
	CurrentX = FMath::FInterpConstantTo(CurrentX, TargetX, DeltaTime, Speed); //linear interpolation
	
	FVector DoorLocation{GetOwner()->GetActorLocation()};
	DoorLocation.X = CurrentX;
	GetOwner()->SetActorLocation(DoorLocation);

	
}


void UOpenGate::Test() {
	
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	
	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("No pressure plate set on actor %s"), *GetOwner()->GetName());
	}
	if (!AudioComponent) {
		UE_LOG(LogTemp, Error, TEXT("No audio component set on actor %s"), *GetOwner()->GetName());
	}
}
