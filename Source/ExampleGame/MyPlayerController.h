// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Online.h"
#include "Base64.h"
#include "math.h"
//#include "Online.h"
#include "OnlineFriendsInterface.h"
#include "OnlineTournamentInterface.h"
#include "ILoginFlowManager.h"
#include "MyBasePickup.h"
#include "MyBaseVendor.h"
#include "MyGameStore.h"
#include "GameplayAbilitySpec.h"
#include "MyTypes.h"
#include "MyPlayerController.generated.h"

// 4.16 login flow thing
#ifndef UETOPIA_SUBSYSTEM
#define UETOPIA_SUBSYSTEM FName(TEXT("UEtopia"))
#endif

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFriendsChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFriendInviteReceivedUETopiaDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFriendInviteReceivedUETopiaDisplayUIDelegate, FString, SenderUserTitle, FString, SenderUserKeyId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRecentPlayersChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyJoinedUETopiaDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyInviteReceivedUETopiaDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyInviteReceivedUETopiaDisplayUIDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartyInviteResponseReceivedUETopiaDisplayUIDelegate, FString, SenderUserTitle, FString, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyDataReceivedUETopiaDisplayUIDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnChatChannelsChangedUETopiaDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnChatRoomMessageReceivedDisplayUIDelegate, FString, SenderUserKeyId, FString, ChatMessage, FString, chatRoomId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChatPrivateMessageReceivedDisplayUIDelegate, FString, SenderUserKeyId, FString, ChatMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTournamentListChangedUETopiaDisplayUIDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTournamentDataReadUETopiaDisplayUIDelegate);
// These delegates were not working reliably, so I moved to a direct RPC approach instead.
// TODO EXAMPLE GAME - delete unused
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryItemSellStartedDelegate, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVendorInteractDisplayUIDelegate, AMyBaseVendor*, VendorRef);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnVendorInfoCompleteDelegate);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVendorInteractChangedDelegate, FString, VendorKeyId, bool, bIsInteracting);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilitiesChangedDelegate);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityInterfaceChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetCharacterListCompleteDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetServerClustersCompleteDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectServerClusterCompleteDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetServersCompleteDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStoreInteractDisplayUIDelegate, AMyGameStore*, GameStoreRef);

/**
* Info associated with a party identifier
* THis is a duplicate that is also declared in the UEtopia plugin
* I could not get the include to work, so I'm putting this here for now
* TODO delete this and import it properly.
*/
class FOnlinePartyIdUEtopiaDup :
	public FOnlinePartyId
{
public:
	FOnlinePartyIdUEtopiaDup(const FString& InKeyId)
		: key_id(InKeyId)
	{
	}
	//~FOnlinePartyId() {};
	const uint8* GetBytes() const override;
	int32 GetSize() const override;
	bool IsValid() const override;
	FString ToString() const override;
	FString ToDebugString() const override;
private:
	const FString key_id;
};

/**
*
*/
UCLASS()
class EXAMPLEGAME_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	//Constructor
	AMyPlayerController();

	// Load from path
	static FORCEINLINE UClass* LoadClassFromPath(const FString& Path)
	{
		if (Path == "") return NULL;

		return StaticLoadClass(UObject::StaticClass(), NULL, *Path, NULL, LOAD_None, NULL);
	}

	//Get Path
	static FORCEINLINE FString GetClassPath(UClass* ClassPtr)
	{
		return FStringClassReference(ClassPtr).ToString();
	}

	// Array to keep track of how many pickup items are in the level
	TArray<AMyBasePickup*> BasePickupsInLevel;

	// Bypasses all online subsystem calls when true, and inserts fake data
	// For normal operations, this should be false.
	// There is also a variable in GameInstance
	bool PIE_Bypass = false;


public:

	// These are just temporary vars to hold data until we are ready to activate player.
	FUniqueNetIdRepl UniqueId;
	FString playerKeyId;
	int32 playerIDTemp;

	UPROPERTY(BlueprintReadOnly)
		bool UEtopiaCharactersEnabled; // Switch for running with or without characters


	///////////////////////////////////////////////////////////
	// This section from
	// https://wiki.unrealengine.com/UMG,_Referencing_UMG_Widgets_in_Code

	// Note: that am using forward declaration Because am not including the
	// widget in the header and to prevent circular dependency.
	// you dont need to do that if you include the Widget Class in the .h
	// forward declaration is just putting "class" before the class name so the compiler know its a
	// class but its not included in the header and don't freak out. Ex. �class UUserWidget�

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wMainMenu;

	// Variable to hold the widget After Creating it.
	UUserWidget* MyMainMenu;

	// Override BeginPlay()
	virtual void BeginPlay() override;


	///////////////////////////////////////////////////////////


	// Unused in Most MMOs
	// This can be used if servers should have a lobby before gameplay begins.
	UFUNCTION(BlueprintCallable, Category = "UETOPIA", Server, Reliable, WithValidation)
		void RequestBeginPlay();

	FString PlayerUniqueNetId;

	// We need to keep track of the Access token for each user.
	// The server needs to be able to send this token along with certain requests for user validation
	FString CurrentAccessTokenFromOSS;

	// Set this player's access token on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetCurrentAccessTokenFromOSS(const FString& CurrentAccessTokenFromOSSIn);

	// Tell the client to update the player access token
	UFUNCTION(Client, Reliable)
		void ClientGetCurrentAccessTokenFromOSS();

	FTimerHandle RespawnTimerHandle;

	//////////////////////////////////

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void TravelPlayer(const FString& ServerUrl);

	// Client function which the server calls when travel is approved and the client should ClientTravel
	UFUNCTION(Client, Reliable)
		void ExecuteClientTravel(const FString& serverUrl);

	// Portal Travel Approved Actor
	// This is a little confusing, because the travel portals are spawned on the server, in gameInstance
	// But each player needs a separate indicator for each server.
	// So these travel approved actors are purely client side, unreplicated, and destroyed as soon as the
	// player logs out or travels to another server.
	// The authority is still the server, and the list of approved actors is in playerState and replicated.

	// Client function which will spawn the local only travel approved actor.
	UFUNCTION(Client, Reliable)
		void ClientTravelApprovedSpawnActor(FTransform SpawnTransform);

	// DEPRECATED - Moved to playerState
	//UPROPERTY(Replicated, BlueprintReadOnly)
	//	int32 Experience; // total experience all time

	//UPROPERTY(Replicated, BlueprintReadOnly)
	//	int32 ExperienceThisLevel;  // Experience so far in this level

	// Keep track of the state of this player's persistent data
	// Prevent the case of a user disconnecting before the data has been populated and leading to a data wipe.
	bool PlayerDataLoaded;

	/////////////////
	// Shard Related
	/////////////////

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "UETOPIA")
		bool bIsShardedServer;

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptShardSwitch(const FString& ShardKeyId);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptShardSwitch(const FString& ShardKeyId);

	///////////////////
	// Friend Functions
	///////////////////

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void InviteUserToFriends(const FString& UserKeyId);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void RejectFriendInvite(const FString& senderUserKeyId);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AcceptFriendInvite(const FString& senderUserKeyId);

	//////////////////////////
	// Party Related Functions
	//////////////////////////

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void CreateParty(const FString& PartyTitle, const FString& TournamentKeyId, bool TournamentParty);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void RejectPartyInvite(const FString& senderUserKeyId);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void InviteUserToParty(const FString& PartyKeyId, const FString& UserKeyId);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AcceptPartyInvite(const FString& senderUserKeyId);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void LeaveParty(const FString& PartyKeyId);

	/////////////////////////
	// Chat related Functions
	/////////////////////////

	void RefreshChatChannelList(); // this one fabricates the uniqueid on the fly
	void RefreshChatChannelList(const FUniqueNetId& LocalUserId);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void CreateChatChannel(const FString& ChatChannelTitle);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void JoinChatChannel(const FString& ChatChannelTitle);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void SendChatMessage(int32 CurrentChannelIndex, FString ChatMessage);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void ExitChatChannel(int32 CurrentChannelIndex);

	// this function sends a local chat message - does not go through the server or backend.
	UFUNCTION(Client, Reliable)
		void SendLocalChatMessage(const FString& ChatMessageIn);

	//////////////////////////////
	// Loot
	//////////////////////////////

	// Loot stuff
	// WE need a temporary place to store party data.
	// The online subsystem handles party for the client side
	// But we also need a way for the server to query the backend to get party state and party members

	// when a loot box is opened, a request goes out for the party data.
	// when that request comes back, the process to begin loot assignment can continue

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptChangeLootSettings(ELootThreshold LootThreshold, ELootSetting LootSetting);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptChangeLootSettings(ELootThreshold LootThreshold, ELootSetting LootSetting);

	UFUNCTION(BlueprintNativeEvent)
		void OnLootSettingsChangedBP();

	UFUNCTION()
		bool DistributeLoot(TArray<FMyInventorySlot> Contents);

	// all we really need is an array of strings with the player ids inside.
	// this does not need to replicate or anything, just lives serverside.
	TArray<FString> PartyMemberUserKeyIds;

	// we also need a temporary place to put the contents of the loot item.
	// Server side only, not replicated.
	TArray<FMyInventorySlot> TempContents;

	// This is a little bit confusing because we are switching back and forth beween controller and game instance.
	// The reason for this is that we need the delegates to originate from the controller, but run on the game instance.
	// We need delgate for each player basically.  If it's on instance we'd only have one.

	FTimerHandle MasterLooterStartDelayHandle;
	FTimerDelegate MasterLooterStartTimerDel;
	FTimerHandle MasterLooterTimeoutDelayHandle;
	FTimerDelegate MasterLooterTimeoutTimerDel;

	UFUNCTION()
		void StartLootMasterLooter();

	UFUNCTION()
		void FinalizeMasterLooter();

	FTimerHandle NeedVGreedStartDelayHandle;
	FTimerDelegate NeedVGreedStartTimerDel;
	FTimerHandle NeedVGreedTimeoutDelayHandle;
	FTimerDelegate NeedVGreedTimeoutTimerDel;

	UFUNCTION()
		void StartLootNeedVGreed();

	UFUNCTION()
		void FinalizeNeedVGreed();

	FTimerHandle GKPLootStartDelayHandle;
	FTimerDelegate GKPLootStarttTimerDel;
	FTimerHandle GKPLootTimeoutDelayHandle;
	FTimerDelegate GKPLootTimeoutTimerDel;

	UFUNCTION()
		void StartLootGKP();

	UFUNCTION()
		void FinalizeGKPLoot();


	UFUNCTION(BlueprintNativeEvent)
		void OnShowNeedVGreedUIBP(); // running client side

	// this just calls the BP native function on the client
	UFUNCTION(Client, Reliable, Category = "UETOPIA")
		void SendClientShowNeedVGreedUI();

	// Register a Roll on an item
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptNeedVGreedRoll(int32 LootIndex, bool NeedPressed);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptNeedVGreedRoll(int32 LootIndex, bool NeedPressed);

	UFUNCTION(BlueprintNativeEvent)
		void OnShowMasterLooterUIBP(); // running client side

	// this just calls the BP native function on the client
	UFUNCTION(Client, Reliable, Category = "UETOPIA")
		void SendClientShowMasterLooterUI();

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptAssignLootMasterLooter(int32 LootIndex, const FString& UserKeyId);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptAssignLootMasterLooter(int32 LootIndex, const FString& UserKeyId);

	UFUNCTION(BlueprintNativeEvent)
		void OnShowGKPConfirmUIBP(); // running client side

	// this just calls the BP native function on the client
	UFUNCTION(Client, Reliable, Category = "UETOPIA")
		void SendClientShowGKPConfirmUI();

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void ConfirmGKPStart(const FString& title, const FString& description, bool vettingEnabled);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerConfirmGKPStart(const FString& title, const FString& description, bool vettingEnabled);

	UFUNCTION(BlueprintNativeEvent)
		void OnShowGKPUIBP(); // running client side

	// this just calls the BP native function on the client
	UFUNCTION(Client, Reliable, Category = "UETOPIA")
		void SendClientShowGKPUI();

	// Register a Roll on an item
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptGKPBid(int32 LootIndex, float Bid);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptGKPBid(int32 LootIndex, float Bid);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void OnShowGKPConfirmEndUIBP(); // running client side

	// this just calls the BP native function on the client
	UFUNCTION(Client, Reliable, Category = "UETOPIA")
		void SendClientShowGKPConfirmEndUI();

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void ConfirmGKPEnd(bool processAsValid);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerConfirmGKPEnd(bool processAsValid);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "UETOPIA")
		void ClientRequestChatChannelRefresh();

	///////////////////////////////
	// TOURNAMENT related Functions
	///////////////////////////////

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void FetchJoinableTournaments();

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void CreateTournament(const FString& TournamentTitle, const FString& GameMode, const FString& Region, int32 TeamMin, int32 TeamMax, int32 donationAmount, int32 playerBuyIn);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void ReadTournamentDetails(const FString& TournamentKeyId);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void JoinTournament(const FString& TournamentKeyId);

	//////////////////////////////
	// Inventory related functions
	//////////////////////////////

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool IsSlotEmpty(const int32 Index);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		int32 SearchEmptySlot();

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		int32 SearchSlotWithAvailableSpace(AMyBasePickup* ClassTypeIn);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool AddItem( AMyBasePickup* ClassTypeIn, int32 quantity, bool checkOnly);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool RemoveItemAtIndex( int32 index, int32 quantity);

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptRemoveItemAtIndex(int32 index, int32 quantity);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool SwapSlots(int32 index1, int32 index2);

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptSwapSlots(int32 index1, int32 index2);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool SplitStack(int32 index, int32 quantity);

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptSplitStack(int32 index, int32 quantity);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool SplitStackToIndex(int32 indexFrom, int32 indexTo, int32 quantity);

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptSplitStackToIndex(int32 indexFrom, int32 indexTo, int32 quantity);

	// This is the blueprint function used to drop an item.
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool DropItem(int32 index);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptDropItem(int32 index);

	// This is the blueprint function used to drop an item.
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool UseItem(int32 index);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptUseItem(int32 index);

	// This is the blueprint function used to drag a stackable item on top of another stack.
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool AddToIndex(int32 indexFrom, int32 indexTo);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptAddToIndex(int32 indexFrom, int32 indexTo);

	/////////////////////////////////////////
	// Drops
	/////////////////////////////////////////

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerAttemptClaimDrop(const FString& dropKeyId);

	///////////////////////////
	// VENDOR RELATED FUNCTIONS
	///////////////////////////

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptSetVendorInteract(AMyBaseVendor* VendorRef);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptVendorInteract(AMyBaseVendor* VendorRef);

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptVendorUpdate(const FString& Title, const FString& Description, const FString& DiscordWebhook, bool bIsSelling, bool bIsBuying, bool bDisableForPickup);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptVendorUpdate(const FString& Title, const FString& Description, const FString& DiscordWebhook, bool bIsSelling, bool bIsBuying, bool bDisableForPickup);

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "UETOPIA")
		bool bInteractingWithVendor;

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "UETOPIA")
		FString InteractingWithVendorKeyId;

	// This is the blueprint function used to add an item into a vendor
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool AddItemToVendor(int32 indexFrom, int32 quantity, int32 pricePerUnit, const FString& vendorKeyId);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptAddItemToVendor(int32 indexFrom, int32 quantity, int32 pricePerUnit, const FString& vendorKeyId);

	// This is the blueprint function used to add an item into a vendor
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool RemoveItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerRemoveItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId);

	// This is the blueprint function used to buy an item from a vendor
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool BuyItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId, int32 quantity);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerBuyItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId, int32 quantity);

	// This is the blueprint function used to withdraw currency from a vendor
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool WithdrawFromVendor(const FString& vendorKeyId);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerWithdrawFromVendor(const FString& vendorKeyId);

	// This is the blueprint function used to add an item into a vendor
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool DeclineOfferFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerDeclineOfferFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId);

	// This is the blueprint function used to add an item into a vendor
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool ClaimItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerClaimItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId);

	///////////////////////////
	// GAME STORE RELATED FUNCTIONS
	///////////////////////////

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptSetGameStoreInteract(AMyGameStore* GameStoreRef);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void AttemptGameStoreInteract(AMyGameStore* GameStoreRef);

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "UETOPIA")
		bool bInteractingWithGameStore;

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "UETOPIA")
		AMyGameStore* InteractingWithGameStore;

	// This is the blueprint function used to buy an item from a game store
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool BuyItemFromGameStore(AMyGameStore* GameStoreRef, int32 itemIndex, int32 quantity);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerBuyItemFromGameStore(AMyGameStore* GameStoreRef, int32 itemIndex, int32 quantity);

	////////////////////////////
	// Ability Related Functions
	////////////////////////////

	// This is the blueprint function used to clear an ability slot
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool RemoveAbilityFromBar(int32 index);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptRemoveAbilityFromBar(int32 index);

	// This is the blueprint function used to add an ability to a slot
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool AddAbilityToBar(int32 index, FMyGrantedAbility GrantedAbility);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptAddAbilityToBar(int32 index, FMyGrantedAbility GrantedAbility);

	// This is the blueprint function used to swap ability slots
	// It will ultimately perform the function on the server, and replicate the data back to the client(s)
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool SwapAbilityBarLocations(int32 indexFrom, int32 indexTo);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptSwapAbilityBarLocations(int32 index, int32 indexTo);

	/////////////////////////////////////////
	// HTTP calls which are performed on client
	/////////////////////////////////////////

	FString APIURL;
	bool PerformJsonHttpRequest(void(AMyPlayerController::*delegateCallback)(FHttpRequestPtr, FHttpResponsePtr, bool), FString APIURI, FString ArgumentString);

	/**
	*	List Server Clusters
	*	Configure server clusters on the backend.
	*	Clusters are containers that contain servers
	*
	*	@param UserId user that initiated the request
	*/
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool FindServerClusters();

	void FindServerClustersComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	UPROPERTY(BlueprintReadOnly)
		FMyServerClusterSearchResults MyServerClusterResults;

	/**
	*	Select Server Cluster
	*	Choose a server cluster on the backend.
	*
	*	@param serverClusterKeyId THe key of the server cluster to select
	*/
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool SelectServerCluster(const FString& serverClusterKeyId);

	void SelectServerClusterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);


	/**
	*	List Servers
	*	These are different than sessions, because they might not be online/provisioned yet.
	*	If they are not provisioned, There is no IP address, or session information associated with it, so you can't initiate travel there.
	*	Use xxxxx function to request that the server be brought online.
	*
	*	@param UserId user that initiated the request
	*/
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool FindServers(const FString& serverClusterKeyId);

	void FindServersComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	UPROPERTY(BlueprintReadOnly)
		FMyServerSearchResults MyServerResults;

	// Server allocate
	// This is used to bring up ANY server in the game
	// It uses the players currently selected server cluser (or assigns one at random)
	// Then it uses the rules in the cluster:
	// Try to bring up the server the user was last on
	// If none, then find a starting server to bring up.
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool ServerAllocate();

	// Allocate a specific server
	// This will also check the currently selected server cluster
	// If server travel mode is set to FREE, it will bring up the specified server.
	// If the cluster is set to restricted, this will have no effect.
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		bool ServerAllocateByKey(const FString& serverKeyId);

	void ServerAllocateComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);



	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
	bool GetVendorInfo(FString vendorKeyId);
	void GetVendorInfoComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);


	/////////////////////////////////////////
	// Character list, create, delete, and select are performed on the client before connecting to the server
	/////////////////////////////////////////


	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
	bool GetCharacterList();
	void GetCharacterListComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
	bool CreateCharacter(FString title, FString description, FString characterType, FString characterState, FString characterClass);
	void CreateCharacterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
	bool DeleteCharacter(FString characterKeyId);
	void DeleteCharacterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
	bool SelectCharacter(FString characterKeyId);
	void SelectCharacterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	// Save Character Customization is performed (if it has not been completed already) after login, after getGamePlayerComplete, after the user saves in the char customize UI
	// Usually this is a fallback in the case that the player submitted character create (and CharacterCustom) is invalid.
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void SaveCharacterCustomization(FString characterClass);

	UFUNCTION(Server, Reliable, WithValidation)
		void SaveCharacterCustomizationServer(int32 characterClass);


	// DELEGATES

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the friends list
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnFriendsChangedDelegate OnFriendsChanged;

	// when this fires, display the friend invitation UI
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnFriendInviteReceivedUETopiaDisplayUIDelegate OnFriendInviteReceivedDisplayUI;

	// When this fires, it signals that you should refresh the recent player's list
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnRecentPlayersChangedDelegate OnRecentPlayersChanged;
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnPartyJoinedUETopiaDelegate OnPartyJoined;
	// when this fires, the OSS has received a party invite.
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnPartyInviteReceivedUETopiaDelegate OnPartyInviteReceived;

	// when this fires, display the party invitation UI
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnPartyInviteReceivedUETopiaDisplayUIDelegate OnPartyInviteReceivedDisplayUI;

	// when this fires, display the party invitation response UI
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnPartyInviteResponseReceivedUETopiaDisplayUIDelegate OnPartyInviteResponseReceivedDisplayUI;

	// when this fires, update the party UI widget
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnPartyDataReceivedUETopiaDisplayUIDelegate OnPartyDataReceivedUETopiaDisplayUI;

	// when this fires, update the Chat Channel List
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnChatChannelsChangedUETopiaDelegate OnChatChannelsChangedUETopia;

	// when this fires, add a chat room message to the chat list
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnChatRoomMessageReceivedDisplayUIDelegate OnChatRoomMessageReceivedDisplayUIDelegate;

	// And this one is a private or system chat - not coming from a room.
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnChatPrivateMessageReceivedDisplayUIDelegate OnChatPrivateMessageReceivedDisplayUIDelegate;

	// when this fires, refresh the tournament UI list
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnTournamentListChangedUETopiaDisplayUIDelegate OnTournamentListChangedUETopiaDisplayUIDelegate;

	// when this fires, refresh the tournament details panel
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnTournamentDataReadUETopiaDisplayUIDelegate OnTournamentDataReadUETopiaDisplayUIDelegate;

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the inventory
	//UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	//	FOnInventoryChangedDelegate OnInventoryChanged;



	// Delegate which signals that a user has clicked the sell button in the inventory interface.  Vendors respond by populating the sell dialog
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnInventoryItemSellStartedDelegate FOnInventoryItemSellStarted;

	// this just fires the delegate
	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
	void InventoryItemSellStart(int32 index);

	// Delegate which signals that a vendor interaction event has occurred, and we need to display the Vendor UI
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnVendorInteractDisplayUIDelegate FOnVendorInteractDisplayUI;

	// Delegate which signals that a vendor Infor request has finished, and we need to update the vendor UI
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnVendorInfoCompleteDelegate FOnVendorInfoComplete;


	//Delegate which signals that a game store interaction has occurred and we need to display the Game Store UI
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnGameStoreInteractDisplayUIDelegate FOnGameStoreInteractDisplayUI;

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the abilities
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
		FOnAbilitiesChangedDelegate OnAbilitiesChanged;


	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the hotbar
	// Moved to player state
	//UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	//FOnAbilityInterfaceChangedDelegate OnAbilityInterfaceChanged;

	// Rep notify to tell the client to load the new inventory
	//UPROPERTY(ReplicatedUsing = OnRep_OnAbilityInterfaceChange)
	//	bool DoRep_AbilityInterfaceChanged;

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the character list
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnGetCharacterListCompleteDelegate OnGetCharacterListCompleteDelegate;

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the server cluster list
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnGetServerClustersCompleteDelegate OnGetServerClustersCompleteDelegate;

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that a new cluster has been selected
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnSelectServerClusterCompleteDelegate OnSelectServerClusterCompleteDelegate;

	// This is the delegate to grab on to in the UI
	// When it fires, it signals that you should refresh the server list
	UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	FOnGetServersCompleteDelegate OnGetServersCompleteDelegate;

	// Delegate which is triggered whenever a vendor interaction starts or ends
	//UPROPERTY(BlueprintAssignable, Category = "UETOPIA")
	//	FOnVendorInteractChangedDelegate FOnVendorInteractChanged;

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void InventoryItemSellConfirm(int32 index, int32 pricePerUnit);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptInventoryItemSellConfirm(int32 index, int32 pricePerUnit);

	// Handle to our external delegates
	// This is bound into the online subsystem.

	FOnReadFriendsListComplete OnReadFriendsListCompleteDelegate;
	FOnQueryRecentPlayersComplete OnQueryRecentPlayersCompleteDelegate;
	FOnCreatePartyComplete OnCreatePartyCompleteDelegate;
	FOnSendPartyInvitationComplete OnSendPartyInvitationComplete;
	//FOnPartyJoined FOnPartyJoinedUETopiaDelegate;
	FOnPartyInviteReceived OnPartyInviteReceivedUEtopiaDelegate;
	//FOnPartyInviteResponseReceived OnPartyInviteResponseReceivedComplete;
	//FOnChatRoomMessageReceivedDisplayUIDelegate OnChatRoomMessageReceivedDisplayUIDelegate;

	FOnCreateTournamentComplete OnCreateTournamentCompleteDelegate;

	// CACHED DATA FOR PASSING IN TO UI
	// This is data that exists only locally via the online subsystem
	// Because of this, it needs to be manually refreshed after a map travel, or respawn.

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	TArray<FMyFriend> MyCachedFriends;
	//FMyFriends MyCachedFriends;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	FMyRecentPlayers MyCachedRecentPlayers;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	TArray<FMyPartyInvitation> MyCachedPartyInvitations;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	TArray<FMyFriend> MyCachedPartyMembers;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	FMyChatChannels MyCachedChatChannels;

	// tournament cache
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyTournament> MyCachedTournaments;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FMyTournament MyCachedTournament;

	// General Party Data

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString MyPartyTitle;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString MyPartyKeyId;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		int32 MyPartyMaxMemberCount;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		int32 MyPartyCurrentMemberCount;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		bool IAmCaptain;

	// Blueprint Native functions are used to trigger actions inside the HUD
	// These are only going to run on the client.
	// But, they cannot be declared as client only, so we need to trigger them from a Client RPC or OnRep Function

	UFUNCTION(BlueprintNativeEvent)
		void OnInventoryChangedBP();

	// We still need this equipment changed function in order to set the icon in player overhead.
	UFUNCTION(BlueprintNativeEvent)
		void OnEquipmentChangedBP();

	UFUNCTION(BlueprintNativeEvent)
		void OnUIStateChange(EConnectUIState UIState);
	UFUNCTION(BlueprintNativeEvent)
		void OnChatChannelsChangedChangedBP();
	UFUNCTION(BlueprintNativeEvent)
		void OnAttributesChangedBP();
	UFUNCTION(BlueprintNativeEvent)
		void OnDropsChangedBP();
	UFUNCTION(BlueprintNativeEvent)
		void OntitleChangedBP();

	// UI STATE
	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "UETOPIA")
		void ClientChangeUIState(EConnectUIState NewState);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UETOPIA")
		EConnectUIState CurrentUIState;


	// Inventory

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_OnInventoryChange, Category = "UETOPIA")
	//	TArray<FMyInventorySlot> InventorySlots;

	// Rep notify to tell the client to load the new inventory
	//UPROPERTY(ReplicatedUsing = OnRep_OnInventoryChange)
	//	bool DoRep_InventoryChanged;

	// this function just calls the delegate.
	//UFUNCTION(Client, Reliable)
	//	void OnRep_OnInventoryChange();

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	//	int32 InventoryCapacity;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category = "UETOPIA")
	//	TArray<FMyAbilitySlot> AbilitySlots;

	

	//UPROPERTY(BlueprintReadOnly, Replicated, Category = "UETOPIA")
	//	int32 CurrencyAvailable;

	// Vendors
	// We cache the currently in-use vendor's information locally on each client.  Requests for purchases or sales go through the server.
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString MyCurrentVendorTitle;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString MyCurrentVendorDescription;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString MyCurrentVendorDiscordWebhook;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString MyCurrentVendorKeyId;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		int32 MyCurrentVendorCurrency;
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		bool MyCurrentVendorIsOwnedByMe;
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "UETOPIA")
		AMyBaseVendor* MyCurrentVendorRef;

	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyVendorItem> MyCurrentVendorInventory;

	// Abilities
	// This should move to PS 
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	//	int32 AbilityCapacity;

	//UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_OnAbilityInterfaceChange, Category = "UETOPIA")
	//	TArray<FMyAbilitySlot> MyAbilitySlots;

	//UFUNCTION(Client, Reliable)
	//	void OnRep_OnAbilityInterfaceChange();

	//UPROPERTY(BlueprintReadOnly, Replicated, Category = "UETOPIA")
	//	int32 AbilitySlotsPerRow;

	// THis is confusing, but neccesary.
	// This array of granted abilities exists for the client to set up the UI
	// Server side the cached and granted abilities lists live inside playerState
	// The reason is that we need to re-grant the abilities on respawn, which happens server side.
	// After abilities have been granted, this array is updated, which triggers the UI refresh client side.

	// moved to player state
	//UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_OnAbilitiesChange, Category = "UETOPIA")
	//	TArray<FMyGrantedAbility> MyGrantedAbilities;

	// TODO move this to player state too
	UFUNCTION(Server, Reliable, WithValidation)
		void GrantCachedAbilities();

	// Rep notify to tell the client to load the new abilities
	//UPROPERTY(ReplicatedUsing = OnRep_OnAbilitiesChange)
	//	bool DoRep_AbilitiesChanged;

	// this function activates after replication
	//UFUNCTION(Client, Reliable)
	//	void OnRep_OnAbilitiesChange();

	// Characters
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		TArray<FMyCharacterRecord> MyCachedCharacters;


	ILoginFlowManager::FOnPopupDismissed OnPopupDismissedUEtopiaDelegate;

	/** respawn after dying */
	virtual void UnFreeze() override;

	UFUNCTION(Client, Reliable, Category = "UETOPIA")
		void ClearHUDWidgets();
	virtual void ClearHUDWidgets_Implementation();


	// This is fired by the Online subsystem after it polls the friend list.
	// It is also used after map travel to relaod the friends list from the actual friends data inside the OSS
	void OnReadFriendsComplete(int32 LocalPlayer, bool bWasSuccessful, const FString& ListName, const FString& ErrorStr);

	// This is fired by the Online subsystem after it polls the recent players list.
	// It is also used after map travel to relaod the recent player list from the actual friends data inside the OSS
	void OnReadRecentPlayersComplete(const FUniqueNetId& UserId, const FString& ListName, bool bWasSuccessful, const FString& ErrorStr);

private:

	TSharedPtr<ILoginFlowManager> LoginFlowManager;
	TSharedPtr<SWidget> DisplayWidgetRef;


	

	// This function is called by a delegate whenever the friends list changes.
	// The purpose of this is to emit a delegate which we can grab onto in the UI
	void OnFriendsChange();

	// THis is called when the OSS sees a friend request
	void OnFriendInviteReceivedComplete(const FUniqueNetId& LocalUserId, const FUniqueNetId& SenderId);

	// This is fired by the Online subsystem after it polls the recent players list.
	//(FOnQueryRecentPlayersComplete, const FUniqueNetId& /*UserId*/, const FString& /*Namespace*/, bool /*bWasSuccessful*/, const FString& /*Error*/);
	//UFUNCTION()
	//void OnReadRecentPlayersComplete(const FUniqueNetId& UserId, const FString& ListName, bool bWasSuccessful, const FString& ErrorStr);

	// This function is called by a delegate whenever the RecentPlayers list changes.
	// The purpose of this is to emit a delegate which we can grab onto in the UI
	void OnRecentPlayersChange();

	// This is fired by the Online subsystem after it Creates a party.
	void OnCreatePartyComplete(const FUniqueNetId& UserId, const TSharedPtr<const FOnlinePartyId>&, const ECreatePartyCompletionResult);

	void OnPartyJoinedComplete(const FUniqueNetId& UserId, const FOnlinePartyId& PartyId);

	void OnPartyInviteReceivedComplete(const FUniqueNetId& LocalUserId, const FOnlinePartyId& PartyId, const FUniqueNetId& SenderId);

	void OnPartyInviteResponseReceivedComplete(const FUniqueNetId& LocalUserId, const FOnlinePartyId& PartyId, const FUniqueNetId& SenderId, const EInvitationResponse Response);

	// This is fired by the online subsystem when it receives new party data
	// DECLARE_MULTICAST_DELEGATE_ThreeParams(F_PREFIX(OnPartyDataReceived), const FUniqueNetId& /*LocalUserId*/, const FOnlinePartyId& /*PartyId*/, const TSharedRef<FOnlinePartyData>& /*PartyData*/);

	void OnPartyDataReceivedComplete(const FUniqueNetId& LocalUserId, const FOnlinePartyId& PartyId, const TSharedRef<FOnlinePartyData>& PartyData);

	// THis is fired by the online subsystem when it receives notification that the user's chat room list has changed.
	// ADD THIS TO /Engine/Plugins/Online/OnlineSubsystem/Source/Public/Interfaces/OnlineChatInterface.h
	// DECLARE_MULTICAST_DELEGATE_TwoParams(FOnChatRoomListChanged, const FUniqueNetId& /*UserId*/, const FString& /*Error*/);
	void OnChatRoomListReadComplete(const FUniqueNetId& LocalUserId, const FString& ErrorStr);

	// This is fired by the online subsystem when it receives a new chat message coming from a room
	//DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnChatRoomMessageReceived, const FUniqueNetId& /*UserId*/, const FChatRoomId& /*RoomId*/, const TSharedRef<FChatMessage>& /*ChatMessage*/);
	void OnChatRoomMessageReceivedComplete(const FUniqueNetId& SenderUserId, const FChatRoomId& RoomId, const TSharedRef<FChatMessage>& ChatMessage);

	// THis one is a private/system chat - not originating from a room
	//DECLARE_MULTICAST_DELEGATE_TwoParams(FOnChatPrivateMessageReceived, const FUniqueNetId& /*UserId*/, const TSharedRef<FChatMessage>& /*ChatMessage*/);
	void OnChatPrivateMessageReceivedComplete(const FUniqueNetId& SenderUserId, const TSharedRef<FChatMessage>& ChatMessage);

	// Tournament stuff
	//DECLARE_MULTICAST_DELEGATE_OneParam(F_PREFIX(OnTournamentListDataChanged), const FUniqueNetId& /*LocalUserId*/);
	void OnTournamentListDataChanged(const FUniqueNetId& LocalUserId);

	// The subsystem has finished reading the tournament details.  Copy them into our local struct and trigger the delegate to update the UI
	void OnTournamentDetailsReadComplete();

	// The subsystem login details have changed.  We need to update the cached token
	// DECLARE_MULTICAST_DELEGATE_FourParams(FOnLoginStatusChanged, int32 /*LocalUserNum*/, ELoginStatus::Type /*OldStatus*/, ELoginStatus::Type /*NewStatus*/, const FUniqueNetId& /*NewId*/);
	void OnLoginStatusChanged(int32 LocalUserNum, ELoginStatus::Type OldStatus, ELoginStatus::Type NewStatus, const FUniqueNetId& NewId);
	void HandleUserLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);


	TArray<TSharedRef<IOnlinePartyJoinInfo>> PendingInvitesArray;


};
