// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "MyRewardItemActor.generated.h"

/**
 *
 */
UCLASS()
class EXAMPLEGAME_API AMyRewardItemActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

public:

	/** sphere component */
	UPROPERTY(VisibleAnywhere, Category = "UEtopia")
	class USphereComponent* Sphere1;

	/** called when something enters the sphere component */
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptClaimReward(class AActor* OtherActor);


private:
	UPROPERTY(EditAnywhere)
	class UMaterial* Material;

	UPROPERTY(EditAnywhere)
	class UMaterialInstanceDynamic* MaterialInstance;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	float RotationSpeed;



};
