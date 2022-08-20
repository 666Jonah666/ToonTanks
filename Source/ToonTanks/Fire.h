// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fire.generated.h"

UCLASS()
class TOONTANKS_API AFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Combat", meta = (AllowPrivateAccess = "true"), BlueprintReadOnly)
	UStaticMeshComponent* FireMesh{nullptr};

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* MovementComponent{nullptr};

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult &Hit);

	UPROPERTY(EditAnywhere)
	float Damage{50.f};

	UPROPERTY(EditAnywhere, Category = "Combat")
	UParticleSystem* HitParticles{nullptr};

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	UParticleSystemComponent* ParticleSystemComponent{nullptr};

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* LaunchSound{nullptr};

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound{nullptr};

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass{nullptr};
	
};
