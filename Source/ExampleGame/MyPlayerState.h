// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Online.h"
#include "Engine.h"
#include "MyTravelApprovedActor.h"
#include "MyTypes.h"
#include "AbilitySystemInterface.h" 
#include "GameplayAbility.h"
#include "MyAttributeSet.h"
#include "MyAbilitySystemComponent.h"
#include "MyPlayerState.generated.h"

/**
*
*/


// Instanced servers have to be handled on a per-user basis
USTRUCT(BlueprintType)
struct FMyApprovedServerLink {
	GENERATED_USTRUCT_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString targetServerKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString hostConnectionLink;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetInstanced;
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTextDelegate, FText, chatSender, FText, chatMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerInventoryChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameplayEffectChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerEquipmentChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerTitleChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowMatchResults);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityInterfaceChangedDelegate);



UCLASS()
class EXAMPLEGAME_API AMyPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay();
	virtual void CopyProperties(class APlayerState* PlayerState) override;

	/** Our ability system */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
		class UMyAbilitySystemComponent* AbilitySystem;

	static FName AbilitySystemName;

private:
	UPROPERTY()
		UMyAttributeSet* AttributeSet;

	void ClientInitialize(class AController* C) override;

public:


	UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		//return AbilitySystem;
		UAbilitySystemComponent* aSC = Cast<UAbilitySystemComponent>(AbilitySystem);
		return aSC;
	}

	// Since the ASC lives on player state, but input is connected to the character, there are edge cases where binding does not work
	// As a workaround if it fails, retry after a delay.
	UFUNCTION()
	void AttemptBindInputToASC();
	// We need a timer delegate for this
	FTimerHandle AttemptBindInputToASCHandle;
	FTimerDelegate AttemptBindInputToASCDel;

	// We need something to track when the player has successfully gone through the login and character selection process
	// Because on respawn, we want to skip loading screens and go immediately back to the spawn room.
	UPROPERTY(Replicated, BlueprintReadOnly)
		bool playerLoginFlowCompleted;


	//UPROPERTY(BlueprintAssignable)
	//	FTextDelegate OnTextDelegate;

	UPROPERTY(BlueprintReadOnly)
		FString playerIdUEInternal;

	UPROPERTY(Replicated, BlueprintReadOnly)
		FString playerKeyId;
	UPROPERTY(Replicated, BlueprintReadOnly)
		FString playerTitle;
	UPROPERTY(Replicated, BlueprintReadOnly)
		FString serverTitle;

	UPROPERTY(Replicated, BlueprintReadOnly)
		int32 Currency;

	UPROPERTY(Replicated, BlueprintReadOnly)
		int32 Level;

	UPROPERTY(Replicated, BlueprintReadOnly)
		int32 Experience; // total experience all time

	UPROPERTY(Replicated, BlueprintReadOnly)
		int32 ExperienceThisLevel;  // Experience so far in this level

	UPROPERTY(Replicated, BlueprintReadOnly)
		int32 TeamId;

	UPROPERTY(Replicated, BlueprintReadOnly)
		FString teamTitle;

	// this is used with teamId to find the correct place to spawn the player
	UPROPERTY(Replicated, BlueprintReadOnly)
		int32 TeamPlayerIndex;

	// For the match results screen we want to pass in the winning team's title
	// And maybe more?  
	// Issues:  We are changing maps so gameState will be lost.
	// GameInstance is server side only.  Could do a client rpc or something
	// For now, just sticking this into playerState which will replicate and survive map change.
	//  This is a simplistic approach, and should be thought through a bit more 
	// for more complex match results screens.
	// 
	UPROPERTY(Replicated, BlueprintReadOnly)
		FString winningTeamTitle;

	UPROPERTY(Replicated, BlueprintReadOnly)
		bool allowPickup;
	UPROPERTY(Replicated, BlueprintReadOnly)
		bool allowDrop;
	// Is combat enabled on this server.  It makes way more sense to put this in game mode, but it does not work on the client.
	UPROPERTY(Replicated, BlueprintReadOnly)
		bool bCombatEnabled = true;

	// Variables set via get game player api call

	// doubles are not supported.
	//UPROPERTY(BlueprintReadOnly)
	double savedCoordLocationX;
	//UPROPERTY(BlueprintReadOnly)
	double savedCoordLocationY;
	//UPROPERTY(BlueprintReadOnly)
	double savedCoordLocationZ;

	UPROPERTY(BlueprintReadOnly)
		FString savedZoneName;
	UPROPERTY(BlueprintReadOnly)
		FString savedZoneKey;

	UPROPERTY(BlueprintReadOnly)
		FString savedInventory;
	UPROPERTY(BlueprintReadOnly)
		FString savedEquipment;
	UPROPERTY(BlueprintReadOnly)
		FString savedAbilities;
	UPROPERTY(BlueprintReadOnly)
		FString savedInterface;
	UPROPERTY(BlueprintReadOnly)
		FString savedCraftingSlots;
	UPROPERTY(BlueprintReadOnly)
		FString savedRecipes; // for crafting

	// Customized and validated character data
	UPROPERTY(BlueprintReadOnly)
		FString savedCharacter;

	// Player selected character data - Needs to be validated before use.
	// WARNING - this may contain invalid data.  CHECK IT FIRST!
	UPROPERTY(BlueprintReadOnly)
		FString savedCharacterCustom;

	// Store character customizations so we have access to them across respawn
	// Add any other character customizations here.
	// Use ints whenever possible to store this data, to keep sizes down
	UPROPERTY(BlueprintReadOnly)
		bool CharacterSetup;
	UPROPERTY(BlueprintReadOnly)
		int32 CharacterClass;

	// ABILITIES

	// Moved in from controller

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the hotbar
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnAbilityInterfaceChangedDelegate OnAbilityInterfaceChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 AbilityCapacity;

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_OnAbilityInterfaceChange, Category = "UETOPIA")
		TArray<FMyAbilitySlot> MyAbilitySlots;

	UFUNCTION(Client, Reliable)
		void OnRep_OnAbilityInterfaceChange();

	UPROPERTY(BlueprintReadOnly, Replicated, Category = "UETOPIA")
		int32 AbilitySlotsPerRow;

	// when this fires, refresh the character attribute UI
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnGameplayEffectChangedDelegate OnGameplayEffectChangedDelegate;

	// Function to bind into the ability system to detect new gameplay effects
	// This ends up running on the server
	void OnGameplayEffectAppliedToSelf(class UAbilitySystemComponent* FromInstigator, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle);
	void OnGameplayEffectRemoved(FActiveGameplayEffectHandle Handle);

	// RPC down to the client in order to fire the delegate
	UFUNCTION(Client, Reliable)
		void OnGameplayEffectsChanged();

	// Delegate to switch the UI state to Match Results
	// This is moved to playerstate because players that are dead when match ends do not have a pawn, and we use pawn to signal UI State change
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnShowMatchResults FOnShowMatchResultsDelegate;

	// RPC down to the client in order to fire the delegate
	UFUNCTION(Client, Reliable)
		void TriggerShowMatchResults();

	// Inventory

	// Delegate to alert the pawn/controller to reload the inventory.
	// DEPRECATED - DELETE
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnPlayerInventoryChange FOnPlayerInventoryChangeDelegate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_OnInventoryChange, Category = "UETOPIA")
		TArray<FMyInventorySlot> InventorySlots;

	// this function just calls the playerController function.
	UFUNCTION()
		void OnRep_OnInventoryChange();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 InventoryCapacity;

	// Equipment
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnPlayerEquipmentChange FOnPlayerEquipmentChangeDelegate;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_OnEquipmentChange, Category = "UETOPIA")
		TArray<FMyInventorySlot> MyEquipment;

	UFUNCTION()
		void OnRep_OnEquipmentChange();

	// Once they are granted, they are stored here.
	// Additionally, they are copied over to the playerController so that the UI/HUD can be updated.
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_OnAbilitiesChange, Category = "UETOPIA")
	TArray< FMyGrantedAbility > GrantedAbilities;

	UFUNCTION(Client, Reliable)
		void OnRep_OnAbilitiesChange();

	// DEPRECATED - TODO delete
	// Is it though?  We are using it to re-apply abilites after map travel
	TArray< FMyGrantedAbility > CachedAbilities;

	// Return a granted ability from an Ability Class PAth
	FMyGrantedAbility GetGrantedAbilityByClassPath(FString classPathIn);

	// Return and remove a granted ability from an Ability Class PAth
	FMyGrantedAbility RemoveGrantedAbilityByClassPath(FString classPathIn);

	// Instanced servers have a different key than the originating server template and we need to keep track of them on a per-user basis.
	// We need to keep track of the server link information and the mapping from the origin key.
	UPROPERTY(Replicated, BlueprintReadOnly)
		TArray<FMyApprovedServerLink> ServerLinksAuthorized;

	UPROPERTY(BlueprintReadOnly)
		TArray< AMyTravelApprovedActor* >  ServerTravelApprovedActors;


	// Custom texture url strings.
	// THis is set via getServerInfo, and normally stored in gamestate or game instance
	// the duplicate here is because the player needs to have a hard notification that this changes.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_OnCustomTextureChange, Category = "UETOPIA")
		TArray<FString> customTextures;

	UFUNCTION(Client, Reliable)
		virtual void OnRep_OnCustomTextureChange();

	UFUNCTION(Client, Reliable)
		virtual void LoadTexturesOntoActors();

	TArray<UTexture2D*> LoadedTextures;

	/**
	* Delegate called when a Http request completes for reading a cloud file
	*/
	void ReadCustomTexture_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	/**
	* Save a file from a given user to disk
	*
	* @param FileName name of file being saved
	* @param Data data to write to disk
	*/
	void SaveCloudFileToDisk(const FString& Filename, const TArray<uint8>& Data);

	/**
	* Converts filename into a local file cache path
	*
	* @param FileName name of file being loaded
	*
	* @return unreal file path to be used by file manager
	*/
	FString GetLocalFilePath(const FString& FileName);

	// Keep track of this player's drops
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_OnDropsChange, Category = "UETOPIA")
		TArray<FLootDrop> MyDrops;

	UFUNCTION()
		void OnRep_OnDropsChange();


};
