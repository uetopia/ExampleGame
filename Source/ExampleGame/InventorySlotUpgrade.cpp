// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotUpgrade.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"

void AInventorySlotUpgrade::OnItemUsed(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AInventorySlotUpgrade OnItemUsed"));

	ServerAttemptUse(SpawnTransform, UserKeyId, BPSubClass);

	return;
}

void AInventorySlotUpgrade::ServerAttemptUse_Implementation(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AInventorySlotUpgrade] [ServerAttemptUse_Implementation]  "));

	// Check to see if the player has the prerequisite
	// update the inventory slots
	// Fill the new slots with empty
	// delete the item out of the inventory

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(((UGameEngine*)GEngine)->GameInstance);
	if (TheGameInstance)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AInventorySlotUpgrade] [ServerAttemptUse_Implementation] Got Game instance "));

		// We need the player state
		FMyActivePlayer* ActivePlayer = TheGameInstance->getPlayerByPlayerKey(UserKeyId);

		if (ActivePlayer)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AInventorySlotUpgrade] [ServerAttemptUse_Implementation] Got ActivePlayer "));

			APlayerState* thisPlayerState = ActivePlayer->PlayerController->PlayerState;
			AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);

			if (playerS)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AInventorySlotUpgrade] ServerAttemptUse_Implementation - Found PlayerState"));

				if (requiredInventorySlotsToUse > playerS->InventoryCapacity)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AInventorySlotUpgrade] ServerAttemptUse_Implementation - Did not meet prerequisite requirements"));
					return;
				}

				// Player met the requirements
				// we need to keep track of how many new slots were added so we can fill them with empty later
				int32 newSlotsAdded = inventorySlotsAfterUse - playerS->InventoryCapacity;

				// update the capacity
				playerS->InventoryCapacity = inventorySlotsAfterUse;

				// Fill with empties

				FMyInventorySlot emptySlot;
				FString ActorClassFullPath = "/Game/UI/Inventory/Blueprints/ItemClasses/ItemHealthPotion.ItemHealthPotion_C";
				UClass* LoadedActorOwnerClass;

				LoadedActorOwnerClass = LoadClassFromPath(ActorClassFullPath);

				if (LoadedActorOwnerClass)
				{
					UE_LOG(LogTemp, Log, TEXT("Found LoadedActorOwnerClass"));

					AMyBasePickup* basePickupBP = Cast<AMyBasePickup>(LoadedActorOwnerClass->GetDefaultObject());
					if (basePickupBP) {
						UE_LOG(LogTemp, Log, TEXT("Found basePickupBP"));
						//emptySlot.itemClass = basePickupBP->GetClass();
						//emptySlot.itemClass = basePickupBP;
						emptySlot.itemClassTitle = basePickupBP->GetName();
						emptySlot.itemClassPath = ActorClassFullPath;
						emptySlot.Icon = basePickupBP->Icon;
						emptySlot.itemTitle = basePickupBP->Title.ToString();
					}

				}
				else {
					UE_LOG(LogTemp, Log, TEXT("Did not find LoadedActorOwnerClass"));
				}

				emptySlot.itemId = 0;

				emptySlot.quantity = 0;

				for (int32 inventoryIndex = 0; inventoryIndex < newSlotsAdded; inventoryIndex++)
				{
					//playerC->InventorySlots.Add(emptySlot);
					playerS->InventorySlots.Add(emptySlot);
				}

			}
		}
	}
}

bool AInventorySlotUpgrade::ServerAttemptUse_Validate(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBaseVendor] [ServerAttemptPickUp_Validate]  "));
	return true;
}