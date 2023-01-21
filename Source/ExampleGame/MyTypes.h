// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameplayEffectTypes.h"
//#include "Engine.h"
#include "GameplayEffect.h"
#include "GameplayAbilitiesModule.h"
#include "Online.h"
#include "MyBasePickup.h"
#include "MyTypes.generated.h"


UENUM()
enum class EMyActorFilterMatchType : uint8
{
	/** Skip this check completely. */
	Skip,
	/** Actor must pass this check (true) */
	MustPass,
	/** Actor must fail this check (not true) */
	MustFail,
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EConnectUIState : uint8
{
	Play 	UMETA(DisplayName = "Play"),
	Loading 	UMETA(DisplayName = "Loading"),
	CharacterCustomize	UMETA(DisplayName = "CharacterCustomize"),
	MatchResults 	UMETA(DisplayName = "MatchResults"),
	Lobby 	UMETA(DisplayName = "Lobby")
};

/** Structure to store the different loot settings - only applies to loot at or above the threshold */
UENUM(BlueprintType)
enum class ELootSetting : uint8
{
	RANDOM 	UMETA(DisplayName = "RANDOM"),
	NEEDGREED 	UMETA(DisplayName = "NEED VS GREED"),
	MASTER 	UMETA(DisplayName = "MASTER LOOTER"),
	GKP  	UMETA(DisplayName = "GUILD KILL PARTICIPATION"),
};

/** Structure to store the loot threshold */
UENUM(BlueprintType)
enum class ELootThreshold : uint8
{
	TIER1 	UMETA(DisplayName = "TIER 1"),
	TIER2 	UMETA(DisplayName = "TIER 2"),
	TIER3 	UMETA(DisplayName = "TIER 3"),
	TIER4  	UMETA(DisplayName = "TIER 4"),
};

USTRUCT(BlueprintType)
struct FMyActorFilter
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	EMyActorFilterMatchType AllowSelf = EMyActorFilterMatchType::Skip;

	bool PassesFilter(UAbilitySystemComponent* Source, UAbilitySystemComponent* Target);
};

// ----------------------------------------

USTRUCT(BlueprintType)
struct FMyEffectItem
{
	GENERATED_USTRUCT_BODY()

	FMyEffectItem() : Level(1.f), StackCount(1)
	{

	}

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere)
	float Level;

	UPROPERTY(EditAnywhere)
	int32 StackCount;

	UPROPERTY()
	FGameplayEffectSpecHandle GeneratedSpec;
};

USTRUCT(BlueprintType)
struct FMyEffectApplicationItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FMyActorFilter	Filter;

	UPROPERTY(EditAnywhere)
	TArray<FMyEffectItem>	Effects;
};

/** A generic utility struct that can hold a list of "Apply this GE (Spec, Level, StackCount) to actors matching this filter". */
USTRUCT(BlueprintType)
struct FMyEffectApplicationContainer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FMyEffectApplicationItem> Items;

	/** Cached source when specs are generated */
	UPROPERTY(BlueprintReadWrite)
	UAbilitySystemComponent* SourceAbilitySystemComponent = nullptr;

	void GenerateEffectSpecs(AActor* Source, float LevelOverride=0.f, int32 StackOverride=0);

	void AddHitResult(FHitResult Result);

	TArray<FActiveGameplayEffectHandle> ApplyEffectApplicationContainerToTarget(AActor* Target);
};


USTRUCT(BlueprintType)
struct FMyFriend {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 playerID = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString playerKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString playerTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsOnline = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsPlayingThisGame = false;
};

USTRUCT(BlueprintType)
struct FMyFriends {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyFriend> MyFriends;
};

USTRUCT(BlueprintType)
struct FMyRecentPlayer {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString playerKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString playerTitle;
};

USTRUCT(BlueprintType)
struct FMyRecentPlayers {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyRecentPlayer> MyRecentPlayers;
};

USTRUCT(BlueprintType)
struct FMyPartyInvitation {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString playerKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString partyTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString partyKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString senderUserTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString senderUserKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsInvited = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsInviteAccepted = false;
};

USTRUCT(BlueprintType)
struct FMyPartyInvitations {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyPartyInvitation> MyPartyInvitations;
};

USTRUCT(BlueprintType)
struct FMyChatChannel {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString chatChannelKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString chatChannelTitle;
};

USTRUCT(BlueprintType)
struct FMyChatChannels {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyChatChannel> MyChatChannels;
};


/** Tournaments have a heirarchy of data:
* Tournament List
* -- Tournament
* ---- Tournament Configuration
* ---- Tournament Team List
* ------ Tournament Team
* ---- Tournament Round List
* ------ Tournament Round
* -------- Tournament Round Match List
* ---------- Tournament Round Match
*/

USTRUCT(BlueprintType)
struct FMyTournamentRoundMatch {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Status;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Team1Title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Team1KeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool Team1Winner = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool Team1Loser = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Team2Title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Team2KeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool Team2Winner = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool Team2Loser = false;

};

USTRUCT(BlueprintType)
struct FMyTournamentRound {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 RoundIndex = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyTournamentRoundMatch> RoundMatchList;

};

USTRUCT(BlueprintType)
struct FMyTournamentTeam {

	GENERATED_USTRUCT_BODY()

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString KeyId;


};


USTRUCT(BlueprintType)
struct FMyTournament {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 tournamentId = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString tournamentKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString tournamentTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsGroupTournament = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString groupTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString PrizeDistributionType;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString region;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString GameMode;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 donationAmount = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 playerBuyIn = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyTournamentTeam> TeamList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyTournamentRound> RoundList;

};


/**
* Inventory contains the commonly used variables, as well as Inventory "stats" that can be customized for eash game without modifying the cpp code
*/


USTRUCT(BlueprintType)
struct FMyInventoryItemStat {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemStatKey;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 itemStatValue = 0;

};

USTRUCT(BlueprintType)
struct FMyInventorySlot {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = 0))
		int32 quantity = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemDescription;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString itemClassTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString itemClassPath;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeUsed = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FText UseText;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeStacked = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 MaxStackSize = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<float> Attributes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 Tier = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 DataTableId = 0;

	// Other things you might want to include in your Inventory slot data:
	/*
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<int32> InventoryGrantedAbilities;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<int32> EquipmentGrantedAbilities;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<int32> EquipmentGrantedAbilitiesKeyIndex;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	//	TSubclassOf<UGameplayEffect> InventoryEffect;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TSubclassOf<UGameplayEffect> EquipmentEffect;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<int32> ValidEquipmentMeshes;
	///
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray <int32> EquipHidesOtherSlots;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray <int32> EquipBlocksOtherSlots;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsEquipHidden;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsEquipBlocked;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FActiveGameplayEffectHandle GamePlayEffectHandle;
	*/
};


USTRUCT(BlueprintType)
struct FLootRoll {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString  UserKeyId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float RollValue = 0.0f;

};


USTRUCT(BlueprintType)
struct FLootUIDataItem {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FMyInventorySlot Item;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray< FLootRoll>  NeedBids;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray< FLootRoll>  GreedBids;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray< FLootRoll>  GKPBids;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString AssignedToUserKeyId;
};

USTRUCT(BlueprintType)
struct FLootUIData {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray< FLootUIDataItem>  Items;
};

USTRUCT(BlueprintType)
struct FMyVendorItem {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = 0))
		int32 quantity = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemDescription;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString itemClassTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString itemClassPath;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 PricePerUnit = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString itemKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString buyingOfferExpires;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool buyingOffer = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool selling = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool claimable = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<float> Attributes;
};



USTRUCT(BlueprintType)
struct FMyGrantedAbility {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		struct FGameplayAbilitySpecHandle AbilityHandle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString classPath; // used to reference this ability from the Ability Slot.  TODO maybe do this differently.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString description;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TSubclassOf<UGameplayAbility> Ability;
};

USTRUCT(BlueprintType)
struct FMyAbilitySlot {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString description;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString classTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString classPath;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeUsed = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FText UseText;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FKey Key;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsValid = false; // true is a ability slot that is in use.  False is empty.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FMyGrantedAbility GrantedAbility;
};

USTRUCT(BlueprintType)
struct FMyCharacterRecord {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString key_id;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString description;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString characterType; // regular, hardcore, etc
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString characterState; // creating, sleeping, etc
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool characterAlive = false; // Permadeath.  Character can't be selected or used.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool currentlySelectedActive = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon = nullptr;

	// These are just used for UI - Add whatever you need.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 gender = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 mesh = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 rank = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 score = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 level = 0;

};


USTRUCT(BlueprintType)
struct FMySessionSearchResult {
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite)
		FString OwningUserName;

	UPROPERTY(BlueprintReadWrite)
		FString ServerTitle;
	// TODO - add more data that we care about
	UPROPERTY(BlueprintReadWrite)
		FString ServerKey;

	UPROPERTY(BlueprintReadWrite)
		int32 SearchIdx = 0;
};

USTRUCT(BlueprintType)
struct FUserEvent {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString EventIcon;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString EventType;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString EventSummary;
};

// KEY ID is actually an INT, but we'll keep it as a string for now.
USTRUCT(BlueprintType)
struct FMyServerLink {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString targetServerTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString targetServerKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetStatusIsContinuous = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetStatusCreating = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetStatusProvisioned = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetStatusOnline = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetStatusFull = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetStatusDead = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool permissionCanMount = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool permissionCanUserTravel = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool permissionCanDismount = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString resourcesUsedToTravel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString resourceAmountsUsedToTravel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 currencyCostToTravel = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float coordLocationX = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float coordLocationY = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float coordLocationZ = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float rotationX = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float rotationY = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float rotationZ = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString hostConnectionLink;
	// Testing to see if this will work
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	//	AMyServerPortalActor* ServerPortalActorReference;

	// Additions to support parallel/instanced servers
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetInstanced = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString targetInstanceConfiguration;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 targetInstancePartySizeMaximum = 0;
};

// KEY ID is actually an INT, but we'll keep it as a string for now.
USTRUCT(BlueprintType)
struct FMyServerShard {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString targetServerKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool online = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString hostConnectionLink;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 shardId = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 playerCount = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 playerCapacityMaximum = 0;
};

USTRUCT(BlueprintType)
struct FMyServerLinks {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyServerLink> links;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyServerShard> shards;
};


USTRUCT(BlueprintType)
struct FMyServerClusterSearchResult {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
		FString Title;
	UPROPERTY(BlueprintReadWrite)
		FString Description;
	// TODO - add more data that we care about
	UPROPERTY(BlueprintReadWrite)
		FString key_id_str; // previous engine versions would always add .0 to int keys, so we pass them as strings as well.
	UPROPERTY(BlueprintReadWrite)
		int32 key_id = 0;
	UPROPERTY(BlueprintReadWrite)
		FString travelMode; // "free" or "restricted"
	// There are more fields avaialble here if you need them.  Cheack the API docs
};

USTRUCT(BlueprintType)
struct FMyServerClusterSearchResults {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyServerClusterSearchResult> server_clusters;
};

USTRUCT(BlueprintType)
struct FMyServerSearchResult {
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite)
		FString Title;
	UPROPERTY(BlueprintReadWrite)
		FString Description;
	// TODO - add more data that we care about
	UPROPERTY(BlueprintReadWrite)
		FString key_id_str; // previous engine versions would always add .0 to int keys, so we pass them as strings as well.
	UPROPERTY(BlueprintReadWrite)
		int32 key_id = 0; 
	UPROPERTY(BlueprintReadWrite)
		bool continuous_server_provisioned = false;
	// There are more fields avaialble here if you need them.  Cheack the API docs
};

USTRUCT(BlueprintType)
struct FMyServerSearchResults {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyServerSearchResult> servers;
};

USTRUCT(BlueprintType)
struct FLootDrop {

	GENERATED_USTRUCT_BODY()

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString key_id;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString description;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString uiIcon;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString expires;

};

USTRUCT(BlueprintType)
struct FZoneDetails {

	GENERATED_USTRUCT_BODY()

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 control = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 energy = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 materials = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString customTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString factionTag;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString mapTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool validZone = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 regionKeyId = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 mapKeyId = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 key_id = 0;
};


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EGameStateHUDType : uint8
{
	None 	UMETA(DisplayName = "None"),
	Deathmatch 	UMETA(DisplayName = "Deathmatch"),
	KOTH  	UMETA(DisplayName = "King Of The Hill"),
	Payload	UMETA(DisplayName = "Payload/Escort"),
	ThreeCP	UMETA(DisplayName = "ThreeCP"),
};

USTRUCT(BlueprintType)
struct FScoreboardKOTH {

	GENERATED_USTRUCT_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float ClaimPercentageSpeed = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float CapturePercentageSpeed = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Team1Title;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Team2Title;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float Team1Percentage = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float Team2Percentage = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float Team1ClaimPercentage = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float Team2ClaimPercentage = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bTeam1HasControl = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bTeam2HasControl = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bTeam1Claiming = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bTeam2Claiming = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsContested = false;

};

USTRUCT(BlueprintType)
struct FStoreItem {

	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Description;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString PrerequisiteDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bAutoActivate = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 credPrice = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 gameCurrencyPrice = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 DataTableId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 Quantity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<float> Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString consignmentId;

};

/** Structure to store the lookup of GameObjects for use in a UDataTable */
USTRUCT(BlueprintType)
struct FIngredientsTable : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString Title;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString Description;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA", meta = (MakeStructureDefaultValue = "Empty"))
		FString ClassPath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TSoftObjectPtr<UTexture2D> Icon;

	//UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	//	FString Category;

	//UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	//	FString Subcategory;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeUsed = false;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString UseText;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeStacked = false;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		int32 MaxStackSize = 0;

	// Might want to use this for crafting
	//UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	//	bool bCanBeMixed;
};


// Match Storyline allows us to quickly and cheaply add all game events into a list
// Then at the end of the match we can go through them, and add them all up for GameData and achievements
// TODO:  Add all of the statistics that you want to track for your game.
USTRUCT(BlueprintType)
struct FMatchStoryEvent {
	GENERATED_USTRUCT_BODY()

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString eventSummary;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float eventImportance;

	// Unreal Engine playerIds:  256, 257, etc
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 sourcePlayerId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 targetPlayerId;

	// UETOPIA playerKeyIds: 03756205629054265, 219056280957628095, etc
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString sourcePlayerKeyId;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString targetPlayerKeyId;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	//	FString targetPlayerKeyIdStr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int64 timestamp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 hitCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		float damageDone;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool targetKilled;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	//	bool targetKillAssist;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool roundStart;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool pointActivated;

};