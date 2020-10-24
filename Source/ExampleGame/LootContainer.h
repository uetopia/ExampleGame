// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include "Particles/ParticleSystem.h"
#include "MyTypes.h"
#include "UnrealNetwork.h"
#include "LootContainer.generated.h"

/**
 *
 */
UCLASS()
class EXAMPLEGAME_API ALootContainer : public ASkeletalMeshActor
{
	GENERATED_UCLASS_BODY()

public:

		//UPROPERTY(VisibleAnywhere, Category = "UEtopia")
		//USkeletalMeshComponent* MySkeletalMesh;

	UParticleSystemComponent* MyParticleSystemComponent;
	UParticleSystem* MyParticleSystem;

	/** sphere component */
	UPROPERTY(VisibleAnywhere, Category = "UEtopia")
		class USphereComponent* Sphere1;

	/** called when something enters the sphere component */
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptOverlapBegin(class AActor* OtherActor);

	// The contents of the container
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "UETOPIA")
		TArray<FMyInventorySlot> Contents;

	// Locked State
	// Instead of this, I'm just going to put them behind the barriers which already go down when the boss (or miniboss) is killed.
	//UPROPERTY(VisibleAnywhere, Replicated, BlueprintReadOnly, Category = "UETOPIA")
	//	bool Locked;

	// Tier to use for loot rolls
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UETOPIA")
		int32 Tier;

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void GenerateContents(int32 contentsCount);

	// prevent duplicates
	bool lootStarted = false;

	int32 ChooseDTIDByWeight(TArray<int32> LootDTIDs, TArray<int32> LootWeights);
};
