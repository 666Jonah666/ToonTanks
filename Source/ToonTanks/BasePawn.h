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

protected:
	void RotateTurret(FVector LookAtTarget);

private:
	//add class because we dont need all things from header, we add include in implementation file
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"), BlueprintReadOnly)
	class UCapsuleComponent* CapsuleComp{nullptr};

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"), BlueprintReadOnly)
	UStaticMeshComponent* BaseMesh{nullptr};

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"), BlueprintReadOnly)
	UStaticMeshComponent* TurretMesh{nullptr};

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"), BlueprintReadOnly)
	USceneComponent* ProjectileSpawnPoint{nullptr};


};
