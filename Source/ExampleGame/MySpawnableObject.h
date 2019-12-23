// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine.h"
//#include "RamaSaveComponent.h"
#include "MySpawnableObject.generated.h"

UCLASS()
class EXAMPLEGAME_API AMySpawnableObject : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

private:
	/** movement component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		UProjectileMovementComponent* MovementComp;
	/** collisions */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComp;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class USceneComponent* DummyRoot;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class UStaticMeshComponent* SphereVisual;

public:
	// Sets default values for this actor's properties
	//AMySpawnableObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** cube component */
	UPROPERTY(VisibleAnywhere, Category = "UETOPIA")
	class UBoxComponent* Cube1;

	//UPROPERTY(Category = "Rama Save Component", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//URamaSaveComponent* OurSaveComponent;



};
