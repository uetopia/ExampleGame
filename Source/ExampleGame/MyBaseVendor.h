// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBasePickup.h"
#include "MyBaseVendor.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API AMyBaseVendor : public AMyBasePickup
{
	GENERATED_BODY()

	AMyBaseVendor();

	// This is the function that gets called on the server when an object is used
	//UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptUse_Implementation(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass) override;
	bool ServerAttemptUse_Validate(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass) override;
public:
	
	
	virtual void OnItemUsed(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass) override;

	virtual void OnItemPickedUp(const FString& UserKeyId) override;
	
	// The key from the UEtopia backend.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category = "UETOPIA")
		FString VendorKeyId;

	// The vendor type key from the UEtopia backend.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString VendorTypeKeyId;

};
