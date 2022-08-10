// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnywhere);
	int32 VisibleAnywhere{12};

	UPROPERTY(EditAnywhere)
	int32 EditAnywhere{1};

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleInstance{4};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//add class because we dont need all things from header, we add include in implementation file
	UPROPERTY()
	class UCapsuleComponent* CapsuleComp{nullptr};

	UPROPERTY()
	UStaticMeshComponent* BaseMesh{nullptr};

	UPROPERTY()
	UStaticMeshComponent* TurretMesh{nullptr};

	UPROPERTY()
	USceneComponent* ProjectileSpawnPoint{nullptr};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
