// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBasePickup.h"
#include "InventorySlotUpgrade.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API AInventorySlotUpgrade : public AMyBasePickup
{
	GENERATED_BODY()

	void ServerAttemptUse_Implementation(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass) override;
	bool ServerAttemptUse_Validate(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass) override;

public:

	// Optional prerequisite slot count.  Force players to buy all of the upgrades, and prevent them from just buying the biggest one first.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	int32 requiredInventorySlotsToUse;

	// How many inventory slots to update this user to.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 inventorySlotsAfterUse;

	void OnItemUsed(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass) override;
	
};
