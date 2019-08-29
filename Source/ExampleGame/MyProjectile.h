// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "MyTypes.h"
#include "Engine.h"
#include "MyProjectile.generated.h"

class UProjectileMovementComponent;

UCLASS(config=Game)
class AMyProjectile : public AActor
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay() override;


	void Launch(const FVector& Dir, float Speed);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	float GetLaunchSpeed() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile, meta = (ExposeOnSpawn = true))
	FMyEffectApplicationContainer OnHitEffectsContainer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(Replicated)
	FVector SpawnOrigin;

	UPROPERTY(Replicated)
	FRotator SpawnRotation;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	float LaunchSpeed;
};
