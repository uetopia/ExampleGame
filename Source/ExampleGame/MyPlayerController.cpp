// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "ProMMO.h"
#include "MyGameInstance.h"
#include "MyBaseGameplayAbility.h"
#include "OnlineSubsystemUtils.h"
#include "ILoginFlowModule.h"
#include "Blueprint/UserWidget.h"
#include "UEtopiaPersistCharacter.h"
#include "Net/UnrealNetwork.h"
#include "MyTravelApprovedActor.h"
#include "MyPlayerState.h"

typedef TSharedPtr<FJsonValue> JsonValPtr;
typedef TArray<JsonValPtr> JsonValPtrArray;

// FOnlinePartyIdUEtopia
const uint8* FOnlinePartyIdUEtopiaDup::GetBytes() const
{
	return 0;
}
int32 FOnlinePartyIdUEtopiaDup::GetSize() const
{
	return 0;
}
bool FOnlinePartyIdUEtopiaDup::IsValid() const
{
	return false;
}
FString FOnlinePartyIdUEtopiaDup::ToString() const
{
	return key_id;
}
FString FOnlinePartyIdUEtopiaDup::ToDebugString() const
{
	return "";
}

//Constructor
AMyPlayerController::AMyPlayerController()
	:
	APlayerController()
{
	//... custom defaults ...
	const auto OnlineSub = IOnlineSubsystem::Get();
	check(OnlineSub);

	const auto IdentityInterface = OnlineSub->GetIdentityInterface();
	check(IdentityInterface.IsValid());

	const auto FriendsInterface = OnlineSub->GetFriendsInterface();
	check(FriendsInterface.IsValid());

	const auto PartyInterface = OnlineSub->GetPartyInterface();
	check(PartyInterface.IsValid());

	const auto ChatInterface = OnlineSub->GetChatInterface();
	check(ChatInterface.IsValid());

	const auto TournamentInterface = OnlineSub->GetTournamentInterface();
	check(TournamentInterface.IsValid());

	IdentityInterface->AddOnLoginStatusChangedDelegate_Handle(0, FOnLoginStatusChangedDelegate::CreateUObject(this, &AMyPlayerController::OnLoginStatusChanged));
	IdentityInterface->AddOnLoginCompleteDelegate_Handle(0, FOnLoginCompleteDelegate::CreateUObject(this, &AMyPlayerController::HandleUserLoginComplete));

	FriendsInterface->AddOnFriendsChangeDelegate_Handle(0, FOnFriendsChangeDelegate::CreateUObject(this, &AMyPlayerController::OnFriendsChange));
	FriendsInterface->AddOnInviteReceivedDelegate_Handle(FOnInviteReceivedDelegate::CreateUObject(this, &AMyPlayerController::OnFriendInviteReceivedComplete));
	FriendsInterface->AddOnQueryRecentPlayersCompleteDelegate_Handle(FOnQueryRecentPlayersCompleteDelegate::CreateUObject(this, &AMyPlayerController::OnReadRecentPlayersComplete));

	PartyInterface->AddOnPartyJoinedDelegate_Handle(FOnPartyJoinedDelegate::CreateUObject(this, &AMyPlayerController::OnPartyJoinedComplete));
	PartyInterface->AddOnPartyInviteReceivedDelegate_Handle(FOnPartyInviteReceivedDelegate::CreateUObject(this, &AMyPlayerController::OnPartyInviteReceivedComplete));
	PartyInterface->AddOnPartyInviteResponseReceivedDelegate_Handle(FOnPartyInviteResponseReceivedDelegate::CreateUObject(this, &AMyPlayerController::OnPartyInviteResponseReceivedComplete));
	PartyInterface->AddOnPartyDataReceivedDelegate_Handle(FOnPartyDataReceivedDelegate::CreateUObject(this, &AMyPlayerController::OnPartyDataReceivedComplete));

	ChatInterface->AddOnChatRoomMessageReceivedDelegate_Handle(FOnChatRoomMessageReceivedDelegate::CreateUObject(this, &AMyPlayerController::OnChatRoomMessageReceivedComplete));
	ChatInterface->AddOnChatPrivateMessageReceivedDelegate_Handle(FOnChatPrivateMessageReceivedDelegate::CreateUObject(this, &AMyPlayerController::OnChatPrivateMessageReceivedComplete));
	ChatInterface->AddOnChatRoomListReadCompleteDelegate_Handle(FOnChatRoomListReadCompleteDelegate::CreateUObject(this, &AMyPlayerController::OnChatRoomListReadComplete));

	TournamentInterface->AddOnTournamentListDataChangedDelegate_Handle(FOnTournamentListDataChangedDelegate::CreateUObject(this, &AMyPlayerController::OnTournamentListDataChanged));
	TournamentInterface->AddOnTournamentDetailsReadDelegate_Handle(FOnTournamentDetailsReadDelegate::CreateUObject(this, &AMyPlayerController::OnTournamentDetailsReadComplete));

	// Bind delegates into the OSS
	OnReadFriendsListCompleteDelegate = FOnReadFriendsListComplete::CreateUObject(this, &AMyPlayerController::OnReadFriendsComplete);
	OnCreatePartyCompleteDelegate = FOnCreatePartyComplete::CreateUObject(this, &AMyPlayerController::OnCreatePartyComplete);

	// Start a player as captain so they can join matchmaker queue without being in a party first
	IAmCaptain = true;

	GConfig->GetString(
		TEXT("UEtopia.Client"),
		TEXT("APIURL"),
		APIURL,
		GGameIni
	);

	GConfig->GetBool(
		TEXT("UEtopia.Client"),
		TEXT("CharactersEnabled"),
		UEtopiaCharactersEnabled,
		GGameIni
	);

	bInteractingWithVendor = false;
	InteractingWithVendorKeyId = "empty";

	AbilitySlotsPerRow = 6;

	PlayerDataLoaded = false;

	CurrentUIState = EConnectUIState::Loading;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (PIE_Bypass)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::BeginPlay PIE_Bypass"));

		return;
	}

	// Only run this on client
	if (!IsRunningDedicatedServer())
	{
		// Check to see if we are on the EntryLevel.
		// If we are, we need to display the mainmenu widget.
		FString mapName = GetWorld()->GetMapName().Mid(GetWorld()->StreamingLevelsPrefix.Len());
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] BeginPlay mapName: %s"), *mapName);

		if (mapName == "EntryLevel")
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] BeginPlay on EntryLevel"));

			if (wMainMenu) // Check if the Asset is assigned in the blueprint.
			{
				// Create the widget and store it.
				MyMainMenu = CreateWidget<UUserWidget>(this, wMainMenu);

				// now you can use the widget directly since you have a referance for it.
				// Extra check to  make sure the pointer holds the widget.
				if (MyMainMenu)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] MainMenu Found"));
					//let add it to the view port
					MyMainMenu->AddToViewport();
				}

				//Show the Cursor.
				bShowMouseCursor = true;
			}
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] BeginPlay on Regular Level"));

			//Hide the Cursor.
			// TODO - you probably want to do something more fancy to allow users access to the mouse in-game.
			bShowMouseCursor = false;


		}
		// IN both cases we want to refresh our UI data
		const auto OnlineSub = IOnlineSubsystem::Get();
		if (OnlineSub)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] Got Online Sub"));
			const auto IdentityInterface = OnlineSub->GetIdentityInterface();
			if (IdentityInterface.IsValid())
			{

				TSharedPtr <const FUniqueNetId> pid = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(0);
				AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(GetPawn());

				// Attempting to set this up to not crash in PIE, and also still work in standalone
				if (GetWorld()->WorldType == EWorldType::PIE)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] Detected PIE - Skipping friends and recent player loading"));

					ClientChangeUIState(EConnectUIState::Play);
				}
				else
				{
					// Creating a local player where we can get the UserID from
					ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
					TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());
					if (UserId.IsValid())
					{
						const auto LoginStatus = IdentityInterface->GetLoginStatus(*UserId);
						if (LoginStatus == ELoginStatus::LoggedIn)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] NOT PIE - Loading friends and recent players"));
							OnlineSub->GetFriendsInterface()->ReadFriendsList(0, "default");
							OnlineSub->GetFriendsInterface()->QueryRecentPlayers(*pid, "default");
						}
					}
				}
			}
		}
	}
}


bool AMyPlayerController::ServerSetCurrentAccessTokenFromOSS_Validate(const FString& CurrentAccessTokenFromOSSIn)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerSetCurrentAccessTokenFromOSS_Implementation(const FString& CurrentAccessTokenFromOSSIn)
{
	// Only run this on the server
	if (IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerSetCurrentAccessTokenFromOSS_Implementation"));

		CurrentAccessTokenFromOSS = CurrentAccessTokenFromOSSIn;

		UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		// Check to see if they have already been activated.  If not, activate.
		FMyActivePlayer* activePlayer = TheGameInstance->getPlayerByPlayerKey(playerKeyId);
		if (activePlayer && activePlayer->gamePlayerDataLoaded)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerSetCurrentAccessTokenFromOSS_Implementation found gamePlayerDataLoaded player - running reconnect"));

			//  reconnect player
			TheGameInstance->ReconnectPlayer(this, playerKeyId, playerIDTemp, UniqueId);

		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerSetCurrentAccessTokenFromOSS_Implementation new player - activating"));
			TheGameInstance->ActivatePlayer(this, playerKeyId, playerIDTemp, UniqueId);
		}
	}
	return;
}

void AMyPlayerController::ClientGetCurrentAccessTokenFromOSS_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ClientGetCurrentAccessTokenFromOSS"));

	if (PIE_Bypass)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ClientGetCurrentAccessTokenFromOSS PIE_Bypass"));
		ServerSetCurrentAccessTokenFromOSS("FAKE_PIE_BYPASS_TOKEN");
		return;
	}

	// Get the access token
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] PerformHttpRequest found OnlineSub"));
		FString CurrentAccessTokenFromOSSCache = OnlineSub->GetIdentityInterface()->GetAuthToken(0);
		ServerSetCurrentAccessTokenFromOSS(CurrentAccessTokenFromOSSCache);
	}

	return;
}


void AMyPlayerController::TravelPlayer(const FString& ServerUrl)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] TransferPlayer - Client Side"));
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] TransferPlayer ServerUrl: %s"), *ServerUrl);
	// Just testing to see if the client can just handle it without the server being involved
	// This does need a serverside check to prevent cheating, but for now this is fine.
	ClientTravel(ServerUrl, ETravelType::TRAVEL_Absolute);
}

void AMyPlayerController::ExecuteClientTravel_Implementation(const FString& ServerUrl)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ExecuteClientTravel_Implementation - Client Side"));
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ExecuteClientTravel_Implementation ServerUrl: %s"), *ServerUrl);
	ClientTravel(ServerUrl, ETravelType::TRAVEL_Absolute);
}

void AMyPlayerController::ClientTravelApprovedSpawnActor_Implementation(FTransform SpawnTransform)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ClientTravelApprovedSpawnActor_Implementation - Client Side"));

	UWorld* const World = GetWorld(); // get a reference to the world
	if (World) {
		AMyTravelApprovedActor* const TravelApprovedActor = World->SpawnActor<AMyTravelApprovedActor>(AMyTravelApprovedActor::StaticClass(), SpawnTransform);
	}
}

void AMyPlayerController::RequestBeginPlay_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] RequestBeginPlay"));
	// We just want to accept the request here from the player and have the game instance do the transfer.
	// TODO implement this however you want
}
bool AMyPlayerController::RequestBeginPlay_Validate()
{
	return true;
}


void AMyPlayerController::OnReadFriendsComplete(int32 LocalPlayer, bool bWasSuccessful, const FString& ListName, const FString& ErrorStr)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::OnReadFriendsComplete"));
	UE_LOG(LogOnline, Log,
		TEXT("ReadFriendsList() for player (%d) was success=%d error=%s"), LocalPlayer, bWasSuccessful, *ErrorStr);

	if (bWasSuccessful)
	{
		const auto OnlineSub = IOnlineSubsystem::Get();
		TArray< TSharedRef<FOnlineFriend> > Friends;
		// Grab the friends data so we can print it out
		if (OnlineSub->GetFriendsInterface()->GetFriendsList(LocalPlayer, ListName, Friends))
		{
			//UE_LOG(LogOnline, Log,
			//	TEXT("GetFriendsList(%d) returned %d friends"), LocalPlayer, Friends.Num());

			// Clear old entries
			MyCachedFriends.Empty();

			// Log each friend's data out
			for (int32 Index = 0; Index < Friends.Num(); Index++)
			{
				const FOnlineFriend& Friend = *Friends[Index];
				const FOnlineUserPresence& Presence = Friend.GetPresence();
				//UE_LOG(LogOnline, Log, TEXT("\t%s has unique id (%s)"), *Friend.GetDisplayName(), *Friend.GetUserId()->ToString());
				//UE_LOG(LogOnline, Log, TEXT("\t\t Invite status (%s)"), EInviteStatus::ToString(Friend.GetInviteStatus()));
				//UE_LOG(LogOnline, Log, TEXT("\t\t Presence: %s"), *Presence.Status.StatusStr);
				//UE_LOG(LogOnline, Log, TEXT("\t\t State: %s"), EOnlinePresenceState::ToString(Presence.Status.State));
				//UE_LOG(LogOnline, Log, TEXT("\t\t bIsOnline (%s)"), Presence.bIsOnline ? TEXT("true") : TEXT("false"));
				//UE_LOG(LogOnline, Log, TEXT("\t\t bIsPlaying (%s)"), Presence.bIsPlaying ? TEXT("true") : TEXT("false"));
				//UE_LOG(LogOnline, Log, TEXT("\t\t bIsPlayingThisGame (%s)"), Presence.bIsPlayingThisGame ? TEXT("true") : TEXT("false"));
				//UE_LOG(LogOnline, Log, TEXT("\t\t bIsJoinable (%s)"), Presence.bIsJoinable ? TEXT("true") : TEXT("false"));
				//UE_LOG(LogOnline, Log, TEXT("\t\t bHasVoiceSupport (%s)"), Presence.bHasVoiceSupport ? TEXT("true") : TEXT("false"));

				FMyFriend ThisFriend;
				ThisFriend.playerTitle = Friend.GetDisplayName();
				ThisFriend.playerKeyId = Friend.GetUserId()->ToString();
				ThisFriend.bIsOnline = Presence.bIsOnline;
				ThisFriend.bIsPlayingThisGame = Presence.bIsPlayingThisGame;

				MyCachedFriends.Add(ThisFriend);
			}
		}
		else
		{
			UE_LOG(LogOnline, Log,
				TEXT("GetFriendsList(%d) failed"), LocalPlayer);
		}
	}
}

void AMyPlayerController::OnFriendsChange() {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnFriendsChange"));
	OnReadFriendsComplete(0, true, "default", "Success");
	OnFriendsChanged.Broadcast();
}

void AMyPlayerController::OnReadRecentPlayersComplete(const FUniqueNetId& UserId, const FString& ListName, bool bWasSuccessful, const FString& ErrorStr)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::OnReadRecentPlayersComplete"));
	if (bWasSuccessful)
	{
		const auto OnlineSub = IOnlineSubsystem::Get();
		TArray< TSharedRef<FOnlineRecentPlayer> > RecentPlayers;
		// Grab the friends data so we can print it out
		if (OnlineSub->GetFriendsInterface()->GetRecentPlayers(UserId, ListName, RecentPlayers))
		{
			//UE_LOG(LogOnline, Log,TEXT("GetRecentPlayers(%s) returned %d friends"), UserId.ToString(), RecentPlayers.Num());

			// Clear old entries
			MyCachedRecentPlayers.MyRecentPlayers.Empty();

			// Log each friend's data out
			for (int32 Index = 0; Index < RecentPlayers.Num(); Index++)
			{
				const FOnlineRecentPlayer& RecentPlayer = *RecentPlayers[Index];
				//UE_LOG(LogOnline, Log, TEXT("\t%s has unique id (%s)"), *RecentPlayer.GetDisplayName(), *RecentPlayer.GetUserId()->ToString());
				FMyRecentPlayer ThisRecentPlayer;
				ThisRecentPlayer.playerTitle = RecentPlayer.GetDisplayName();
				ThisRecentPlayer.playerKeyId = RecentPlayer.GetUserId()->ToString();
				MyCachedRecentPlayers.MyRecentPlayers.Add(ThisRecentPlayer);
			}
		}
		else
		{
			//UE_LOG(LogOnline, Log,TEXT("GetRecentPlayers failed"));
		}
	}
	OnRecentPlayersChange();
}


void AMyPlayerController::OnRecentPlayersChange() {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerControllere::OnRecentPlayersChange"));
	OnRecentPlayersChanged.Broadcast();
}


void AMyPlayerController::InviteUserToFriends(const FString& UserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::InviteUserToFriends"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	// Fabricate a new FUniqueNetId by the userKeyId
	const TSharedPtr<const FUniqueNetId> UserToInviteId = OnlineSub->GetIdentityInterface()->CreateUniquePlayerId(UserKeyId);

	FString UserToInviteKeyId = UserToInviteId.Get()->ToString();
	UE_LOG_ONLINE(Log, TEXT("UserToInviteKeyId: %s"), *UserToInviteKeyId);

	// Tell the OSS to send the invite
	OnlineSub->GetFriendsInterface()->SendInvite(0, *UserToInviteId, "default");
}

void AMyPlayerController::OnFriendInviteReceivedComplete(const FUniqueNetId& LocalUserId, const FUniqueNetId& SenderId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnFriendInviteReceivedComplete"));

	// Get the Sender Title
	const auto OnlineSub = IOnlineSubsystem::Get();
	TSharedPtr <FOnlineFriend> SenderFriend = OnlineSub->GetFriendsInterface()->GetFriend(0, SenderId, "default");

	if (SenderFriend.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnFriendInviteReceivedComplete Found Sender record in friends list"));
		FString SenderKeyId;
		FString SenderUserTitle;
		SenderFriend->GetUserAttribute("key_id", SenderKeyId);
		UE_LOG_ONLINE(Log, TEXT("SenderKeyId: %s"), *SenderKeyId);
		SenderFriend->GetUserAttribute("title", SenderUserTitle);
		UE_LOG_ONLINE(Log, TEXT("SenderUserTitle: %s"), *SenderUserTitle);
		OnFriendInviteReceivedDisplayUI.Broadcast( SenderUserTitle, SenderKeyId);
	}
	return;
}

void AMyPlayerController::RejectFriendInvite(const FString& senderUserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::RejectFriendInvite"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	// Fabricate a new FUniqueNetId by the userKeyId
	const TSharedPtr<const FUniqueNetId> SenderUserId = OnlineSub->GetIdentityInterface()->CreateUniquePlayerId(senderUserKeyId);

	OnlineSub->GetFriendsInterface()->RejectInvite(0, *SenderUserId, "default");
}

void AMyPlayerController::AcceptFriendInvite(const FString& senderUserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AcceptFriendInvite"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	// Fabricate a new FUniqueNetId by the userKeyId
	const TSharedPtr<const FUniqueNetId> SenderUserId = OnlineSub->GetIdentityInterface()->CreateUniquePlayerId(senderUserKeyId);

	OnlineSub->GetFriendsInterface()->AcceptInvite(0, *SenderUserId, "default");
}

void AMyPlayerController::CreateParty(const FString& PartyTitle, const FString& TournamentKeyId, bool TournamentParty)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::CreateParty"));
	const auto OnlineSub = IOnlineSubsystem::Get();
	FOnlinePartyTypeId PartyTypeId;
	if (TournamentParty) {
		PartyTypeId = FOnlinePartyTypeId(1);
	}
	else {
		PartyTypeId = FOnlinePartyTypeId(0);
	}
	FPartyConfiguration PartyConfiguration = FPartyConfiguration();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());
	OnlineSub->GetPartyInterface()->CreateParty(*UserId, PartyTypeId, PartyConfiguration, OnCreatePartyCompleteDelegate);
}

void AMyPlayerController::RejectPartyInvite(const FString& senderUserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::RejectPartyInvite"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	// Fabricate a new FUniqueNetId by the userKeyId
	const TSharedPtr<const FUniqueNetId> SenderUserId = OnlineSub->GetIdentityInterface()->CreateUniquePlayerId(senderUserKeyId);

	OnlineSub->GetPartyInterface()->RejectInvitation(*UserId, *SenderUserId);
}

void AMyPlayerController::AcceptPartyInvite(const FString& senderUserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AcceptPartyInvite"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	// Fabricate a new FUniqueNetId by the userKeyId
	const TSharedPtr<const FUniqueNetId> SenderUserId = OnlineSub->GetIdentityInterface()->CreateUniquePlayerId(senderUserKeyId);

	OnlineSub->GetPartyInterface()->AcceptInvitation(*UserId, *SenderUserId);
}

void AMyPlayerController::OnCreatePartyComplete(const FUniqueNetId& UserId, const TSharedPtr<const FOnlinePartyId>&, const ECreatePartyCompletionResult)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnCreatePartyComplete"));
}

void AMyPlayerController::OnPartyJoinedComplete(const FUniqueNetId& UserId, const FOnlinePartyId& PartyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyJoinedComplete"));
}

void AMyPlayerController::InviteUserToParty(const FString& PartyKeyId, const FString& UserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::InviteUserToParty"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	// Fabricate a new FUniqueNetId by the userKeyId
	const TSharedPtr<const FUniqueNetId> UserToInviteId = OnlineSub->GetIdentityInterface()->CreateUniquePlayerId(UserKeyId);
	UE_LOG_ONLINE(Log, TEXT("PartyKeyId: %s"), *PartyKeyId);
	FOnlinePartyIdUEtopiaDup PartyId = FOnlinePartyIdUEtopiaDup(PartyKeyId);

	// Create a FPartyInvitationRecipient
	FPartyInvitationRecipient PartyInviteRecipient = FPartyInvitationRecipient(*UserToInviteId);

	FString UserToInviteKeyId = UserToInviteId.Get()->ToString();
	UE_LOG_ONLINE(Log, TEXT("UserToInviteKeyId: %s"), *UserToInviteKeyId);
	PartyInviteRecipient.PlatformData = UserToInviteKeyId;

	FOnlinePartyData PartyData = FOnlinePartyData();
	PartyData.SetAttribute("key_id", PartyKeyId);

	// Tell the OSS to send the invite
	OnlineSub->GetPartyInterface()->SendInvitation(*UserId, PartyId, PartyInviteRecipient, OnSendPartyInvitationComplete);
}

void AMyPlayerController::OnPartyInviteReceivedComplete(const FUniqueNetId& LocalUserId, const FOnlinePartyId& PartyId, const FUniqueNetId& SenderId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyInviteReceivedComplete"));
	// get the array from the OSS party interface

	const auto OnlineSub = IOnlineSubsystem::Get();
	OnlineSub->GetPartyInterface()->GetPendingInvites(LocalUserId, PendingInvitesArray);

	MyCachedPartyInvitations.Empty();

	for (int32 Index = 0; Index < PendingInvitesArray.Num(); Index++)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyInviteReceivedComplete - adding invite to struct"));
		IOnlinePartyJoinInfo& PartyInfo = *PendingInvitesArray[Index];

		FMyPartyInvitation ThisPartyInvitation;

		ThisPartyInvitation.partyKeyId = PartyId.ToString();
		// Is there some other way to get the party title now?
		ThisPartyInvitation.partyTitle = PartyInfo.GetSourceDisplayName();
		ThisPartyInvitation.senderUserKeyId = PartyInfo.GetSourceUserId()->ToString();
		ThisPartyInvitation.senderUserTitle = PartyInfo.GetSourceDisplayName();

		MyCachedPartyInvitations.Add(ThisPartyInvitation);

	}
	OnPartyInviteReceivedDisplayUI.Broadcast();

}

void AMyPlayerController::OnPartyInviteResponseReceivedComplete(const FUniqueNetId& LocalUserId, const FOnlinePartyId& PartyId, const FUniqueNetId& SenderId, const EInvitationResponse Response)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyInviteResponseReceivedComplete"));

	FString senderTitle = "Unknown";

	// Try to find the sender in the friends list so we can get the userTitle
	for (int32 Index = 0; Index < MyCachedFriends.Num(); Index++)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyInviteResponseReceivedComplete - Checking Friend"));
		UE_LOG_ONLINE(Log, TEXT("SenderId.ToString(): %s"), *SenderId.ToString());
		UE_LOG_ONLINE(Log, TEXT("MyCachedFriends[Index].playerKeyId: %s"), *MyCachedFriends[Index].playerKeyId);
		if (MyCachedFriends[Index].playerKeyId == SenderId.ToString())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyInviteResponseReceivedComplete - Found Match"));

			senderTitle = MyCachedFriends[Index].playerTitle;
		}
	}

	FString responseString = "Unknown";
	if (Response == EInvitationResponse::Rejected)
	{
		responseString = "Rejected";
	}
	if (Response == EInvitationResponse::Accepted)
	{
		responseString = "Accepted";
	}

	OnPartyInviteResponseReceivedDisplayUI.Broadcast(senderTitle, responseString);
}

void AMyPlayerController::LeaveParty(const FString& PartyKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::LeaveParty"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	UE_LOG_ONLINE(Log, TEXT("PartyKeyId: %s"), *PartyKeyId);
	FOnlinePartyIdUEtopiaDup PartyId = FOnlinePartyIdUEtopiaDup(PartyKeyId);

	OnlineSub->GetPartyInterface()->LeaveParty(*UserId, PartyId);
}

void AMyPlayerController::OnPartyDataReceivedComplete(const FUniqueNetId& LocalUserId, const FOnlinePartyId& PartyId, const TSharedRef<FOnlinePartyData>& PartyData)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyDataReceivedComplete"));

	// Extract our data out of the PartyData.
	// There might be a better way to do this, but I couldn't find any way to strore member data inside PartyData other than this hack-y way.
	// TODO research this.

	// First we need the general data

	FVariantData partyKeyId;
	FVariantData partyTitle;
	FVariantData partySizeMax;
	FVariantData partySizeCurrent;
	FVariantData userIsCaptain;

	PartyData->GetAttribute("title", partyTitle);
	PartyData->GetAttribute("key_id", partyKeyId);
	PartyData->GetAttribute("size_max", partySizeMax);
	PartyData->GetAttribute("size_current", partySizeCurrent);
	PartyData->GetAttribute("userIsCaptain", userIsCaptain);

	FString partySizeMaxTemp = partySizeMax.ToString();
	UE_LOG_ONLINE(Log, TEXT("partySizeMax: %s"), *partySizeMaxTemp);
	MyPartyMaxMemberCount = FCString::Atoi(*partySizeMaxTemp);

	FString partySizeCurrentTemp = partySizeCurrent.ToString();
	UE_LOG_ONLINE(Log, TEXT("partySizeCurrent: %s"), *partySizeCurrentTemp);
	MyPartyCurrentMemberCount = FCString::Atoi(*partySizeCurrentTemp);

	UE_LOG_ONLINE(Log, TEXT("userIsCaptain.ToString(): %s"), *userIsCaptain.ToString());

	IAmCaptain = false;
	if (userIsCaptain.ToString() == "true")
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyDataReceivedComplete I AM CAPTAIN"));
		IAmCaptain = true;
	}

	// Cache the Party data in our local struct, so we can get it easily in BP
	// Clear it first
	MyCachedPartyMembers.Empty();

	FString AttributePrefix = "";

	for (int32 Index = 0; Index < MyPartyCurrentMemberCount; Index++)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyDataReceivedComplete - Adding Member"));

		FString IndexString = FString::FromInt(Index);
		AttributePrefix = "member:" + IndexString + ":";

		FVariantData userTitle;
		FVariantData userKeyId;
		FVariantData captain;
		FMyFriend ThisPartyMember;

		PartyData->GetAttribute(AttributePrefix + "title", userTitle);
		PartyData->GetAttribute(AttributePrefix + "key_id", userKeyId);
		PartyData->GetAttribute(AttributePrefix + "captain", captain);

		ThisPartyMember.playerTitle = userTitle.ToString();
		ThisPartyMember.playerKeyId = userKeyId.ToString();

		UE_LOG_ONLINE(Log, TEXT("captain.ToString(): %s"), *captain.ToString());

		MyCachedPartyMembers.Add(ThisPartyMember);
	}

	// If there is no party, reset this player's captain status to true
	if (MyPartyCurrentMemberCount == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnPartyDataReceivedComplete - No party members - resetting captain status"));
		IAmCaptain = true;
	}

	OnPartyDataReceivedUETopiaDisplayUI.Broadcast();
}


void AMyPlayerController::RefreshChatChannelList(const FUniqueNetId& LocalUserId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::RefreshChatChannelList"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Dump our cached arrays
	MyCachedChatChannels.MyChatChannels.Empty();

	// Creating a local player where we can get the UserID from
	//ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	//TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	TArray<FChatRoomId> CachedRooms;

	OnlineSub->GetChatInterface()->GetJoinedRooms(LocalUserId, CachedRooms);

	// Loop over them and get the room info
	for (int32 Index = 0; Index < CachedRooms.Num(); Index++)
	{
		TSharedPtr<FChatRoomInfo> CachedChatRoomInfo = OnlineSub->GetChatInterface()->GetRoomInfo(LocalUserId, *CachedRooms[Index]);

		FMyChatChannel CachedChatInstance;
		CachedChatInstance.chatChannelKeyId = CachedChatRoomInfo->GetRoomId();
		CachedChatInstance.chatChannelTitle = CachedChatRoomInfo->GetSubject();

		// Populate our USTRUCT
		MyCachedChatChannels.MyChatChannels.Add(CachedChatInstance);

	}

	//DELEGATE
	OnChatChannelsChangedUETopia.Broadcast();

}

void AMyPlayerController::CreateChatChannel(const FString& ChatChannelTitle)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::CreateChatChannel"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	FChatRoomId ChatRoomId;  //unused at this point
	FChatRoomConfig ChatRoomConfig;

	OnlineSub->GetChatInterface()->CreateRoom(*UserId, ChatRoomId, ChatChannelTitle, ChatRoomConfig);
}

void AMyPlayerController::JoinChatChannel(const FString& ChatChannelTitle)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::JoinChatChannel"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	FChatRoomId ChatRoomId;  //unused at this point
	FChatRoomConfig ChatRoomConfig;

	OnlineSub->GetChatInterface()->JoinPublicRoom(*UserId, ChatRoomId, ChatChannelTitle, ChatRoomConfig);
}

void AMyPlayerController::OnChatRoomListReadComplete(const FUniqueNetId& LocalUserId, const FString& ErrorStr)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnChatRoomListChanged"));
	const auto OnlineSub = IOnlineSubsystem::Get();
	RefreshChatChannelList(LocalUserId);
}

void AMyPlayerController::SendChatMessage(int32 CurrentChannelIndex, FString ChatMessage)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SendChatMessage"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// prevent crashing on invalid channel index
	if (!MyCachedChatChannels.MyChatChannels.IsValidIndex(CurrentChannelIndex))
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SendChatMessage Invalid chat channel index"));

		FString Message = "Invalid chat channel.";
		SendLocalChatMessage(Message);

		return;
	}

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	OnlineSub->GetChatInterface()->SendRoomChat(*UserId, MyCachedChatChannels.MyChatChannels[CurrentChannelIndex].chatChannelKeyId, ChatMessage);
	return;
}

void AMyPlayerController::ExitChatChannel(int32 CurrentChannelIndex)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ExitChatChannel"));
	const auto OnlineSub = IOnlineSubsystem::Get();
	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	OnlineSub->GetChatInterface()->ExitRoom(*UserId, MyCachedChatChannels.MyChatChannels[CurrentChannelIndex].chatChannelKeyId);
	return;
}

void AMyPlayerController::OnChatRoomMessageReceivedComplete(const FUniqueNetId& SenderUserId, const FChatRoomId& RoomId, const TSharedRef<FChatMessage>& ChatMessage)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnChatRoomMessageReceivedComplete"));

	FString ChatMessageCombined = ChatMessage->GetNickname() + ": " + ChatMessage->GetBody();
	FString SenderUserKeyId = SenderUserId.ToString();

	OnChatRoomMessageReceivedDisplayUIDelegate.Broadcast(SenderUserKeyId, ChatMessageCombined, RoomId);
}


void AMyPlayerController::OnChatPrivateMessageReceivedComplete(const FUniqueNetId& SenderUserId, const TSharedRef<FChatMessage>& ChatMessage)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnChatRoomMessageReceivedComplete"));

	//FString ChatMessageCombined = ChatMessage->GetNickname() + ": " + ChatMessage->GetBody();
	FString ChatMessageCombined = ChatMessage->GetBody();
	FString SenderUserKeyId = SenderUserId.ToString();

	OnChatPrivateMessageReceivedDisplayUIDelegate.Broadcast(SenderUserKeyId, ChatMessageCombined);
}

void AMyPlayerController::FetchJoinableTournaments()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::FetchJoinableTournaments"));
	const auto OnlineSub = IOnlineSubsystem::Get();
	OnlineSub->GetTournamentInterface()->FetchJoinableTournaments();
}

void AMyPlayerController::CreateTournament(const FString& TournamentTitle, const FString& GameMode, const FString& Region, int32 TeamMin, int32 TeamMax, int32 donationAmount, int32 playerBuyIn)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::CreateTournament"));

	const auto OnlineSub = IOnlineSubsystem::Get();
	FOnlinePartyTypeId PartyTypeId;

	FTournamentConfiguration TournamentConfiguration = FTournamentConfiguration();
	TournamentConfiguration.GameMode = GameMode;
	TournamentConfiguration.MinTeams = TeamMin;
	TournamentConfiguration.MaxTeams = TeamMax;
	TournamentConfiguration.Region = Region;
	TournamentConfiguration.Title = TournamentTitle;
	TournamentConfiguration.donationAmount = donationAmount;
	TournamentConfiguration.playerBuyIn = playerBuyIn;

	// Creating a local player where we can get the UserID from
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(LocalPlayer->GetControllerId());

	// const FUniqueNetId& LocalUserId, const FOnlinePartyTypeId TournamentTypeId, const FTournamentConfiguration& TournamentConfig, const FOnCreateTournamentComplete& Delegate = FOnCreateTournamentComplete()

	OnlineSub->GetTournamentInterface()->CreateTournament(*UserId, PartyTypeId, TournamentConfiguration, OnCreateTournamentCompleteDelegate);
		//OnlineSub->GetPartyInterface()->CreateParty(*UserId, PartyTypeId, PartyConfiguration, OnCreatePartyCompleteDelegate);
}

void AMyPlayerController::OnTournamentListDataChanged(const FUniqueNetId& LocalUserId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnTournamentListDataChanged"));
	const auto OnlineSub = IOnlineSubsystem::Get();


	TArray< TSharedRef<FOnlineTournament> > TournamentListCache;

	if (OnlineSub->GetTournamentInterface()->GetTournamentList(0, TournamentListCache))
	{
		//UE_LOG(LogOnline, Log,TEXT("GetRecentPlayers(%s) returned %d friends"), UserId.ToString(), RecentPlayers.Num());

		// Clear old entries
		MyCachedTournaments.Empty();

		// Log each friend's data out
		for (int32 Index = 0; Index < TournamentListCache.Num(); Index++)
		{
			const FOnlineTournament& ThisTournament = *TournamentListCache[Index];

			UE_LOG(LogOnline, Log, TEXT("\t%s has unique id (%s)"), *ThisTournament.GetTitle(), *ThisTournament.GetTournamentId()->ToString());


			FMyTournament ThisMyTournamentStruct;
			ThisMyTournamentStruct.tournamentKeyId = ThisTournament.GetTournamentId()->ToString();
			ThisMyTournamentStruct.tournamentTitle = ThisTournament.GetTitle();

			MyCachedTournaments.Add(ThisMyTournamentStruct);

		}

	}
	else
	{
		//UE_LOG(LogOnline, Log,TEXT("GetRecentPlayers failed"));

	}

	OnTournamentListChangedUETopiaDisplayUIDelegate.Broadcast();
	return;

}

void AMyPlayerController::ReadTournamentDetails(const FString& TournamentKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::ReadTournamentDetails"));

	// Dump our cached tournament data
	MyCachedTournament.tournamentTitle = "loading...";
	MyCachedTournament.tournamentKeyId = "0";
	MyCachedTournament.RoundList.Empty();
	MyCachedTournament.TeamList.Empty();

	const auto OnlineSub = IOnlineSubsystem::Get();

	FOnlinePartyIdUEtopiaDup TournamentId = FOnlinePartyIdUEtopiaDup(TournamentKeyId);

	OnlineSub->GetTournamentInterface()->ReadTournamentDetails(0, TournamentId);
}

void AMyPlayerController::OnTournamentDetailsReadComplete()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::OnTournamentDetailsReadComplete"));

	const auto OnlineSub = IOnlineSubsystem::Get();

	// this is just junk
	TSharedPtr<const FUniqueNetId> UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(0);

	TSharedPtr<FTournament> TournamentDetailsFromOSS = OnlineSub->GetTournamentInterface()->GetTournament(0, *UserId);

	// Empty out local struct arrays
	MyCachedTournament.RoundList.Empty();
	MyCachedTournament.TeamList.Empty();

	// Copy over the OSS data into our local struct
	MyCachedTournament.tournamentKeyId = TournamentDetailsFromOSS->TournamentKeyId;
	MyCachedTournament.tournamentTitle = TournamentDetailsFromOSS->Configuration.Title;
	MyCachedTournament.region = TournamentDetailsFromOSS->Configuration.Region;
	MyCachedTournament.donationAmount = TournamentDetailsFromOSS->Configuration.donationAmount;
	MyCachedTournament.playerBuyIn = TournamentDetailsFromOSS->Configuration.playerBuyIn;
	MyCachedTournament.GameMode = TournamentDetailsFromOSS->Configuration.GameMode;
	MyCachedTournament.PrizeDistributionType = TournamentDetailsFromOSS->Configuration.PrizeDistributionType;

	for (int32 Index = 0; Index < TournamentDetailsFromOSS->TeamList.Num(); Index++)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] Found Team"));
		FMyTournamentTeam TempTeamData;
		TempTeamData.KeyId = TournamentDetailsFromOSS->TeamList[Index].KeyId;
		TempTeamData.title = TournamentDetailsFromOSS->TeamList[Index].Title;

		MyCachedTournament.TeamList.Add(TempTeamData);
	}

	for (int32 RoundIndex = 0; RoundIndex < TournamentDetailsFromOSS->RoundList.Num(); RoundIndex++)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] Found Round"));
		FMyTournamentRound TempRoundData;

		TempRoundData.RoundIndex = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundIndex;

		for (int32 RoundMatchIndex = 0; RoundMatchIndex < TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList.Num(); RoundMatchIndex++)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] Found Round Match"));
			FMyTournamentRoundMatch TempRoundMatchData;
			TempRoundMatchData.Team1KeyId = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team1KeyId;
			TempRoundMatchData.Team1Title = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team1Title;
			TempRoundMatchData.Team1Winner = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team1Winner;
			TempRoundMatchData.Team1Loser = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team1Loser;

			TempRoundMatchData.Team2KeyId = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team2KeyId;
			TempRoundMatchData.Team2Title = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team2Title;
			TempRoundMatchData.Team2Winner = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team2Winner;
			TempRoundMatchData.Team2Loser = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Team2Loser;

			TempRoundMatchData.Status = TournamentDetailsFromOSS->RoundList[RoundIndex].RoundMatchList[RoundMatchIndex].Status;

			TempRoundData.RoundMatchList.Add(TempRoundMatchData);
		}

		MyCachedTournament.RoundList.Add(TempRoundData);

	}

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::OnTournamentDetailsReadComplete - triggering OnTournamentDataReadUETopiaDisplayUIDelegate"));
	OnTournamentDataReadUETopiaDisplayUIDelegate.Broadcast();

	return;
}

void AMyPlayerController::JoinTournament(const FString& TournamentKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::JoinTournament"));
	const auto OnlineSub = IOnlineSubsystem::Get();

	// Fabricate a new FUniqueNetId by the TournamentKeyId
	const TSharedPtr<const FUniqueNetId> TournamentId = OnlineSub->GetIdentityInterface()->CreateUniquePlayerId(TournamentKeyId);

	OnlineSub->GetTournamentInterface()->JoinTournament(0, *TournamentId);

}

// Login status has changed.  We need up update the auth token
void AMyPlayerController::OnLoginStatusChanged(int32 LocalUserNum, ELoginStatus::Type OldStatus, ELoginStatus::Type NewStatus, const FUniqueNetId& NewId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnLoginStatusChanged"));

	if (PIE_Bypass)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnLoginStatusChanged PIE_Bypass"));
		ServerSetCurrentAccessTokenFromOSS("FAKE_PIE_BYPASS_TOKEN");
		return;
	}

	// Get the access token
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] PerformHttpRequest found OnlineSub"));
		FString CurrentAccessTokenFromOSSCache = OnlineSub->GetIdentityInterface()->GetAuthToken(0);
		ServerSetCurrentAccessTokenFromOSS(CurrentAccessTokenFromOSSCache);
	}


}

void AMyPlayerController::HandleUserLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::HandleUserLoginComplete"));

	if (PIE_Bypass)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::HandleUserLoginComplete PIE_Bypass"));
		ServerSetCurrentAccessTokenFromOSS("FAKE_PIE_BYPASS_TOKEN");
		return;
	}

	// Get the access token
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnlineSub"));
		FString CurrentAccessTokenFromOSSCache = OnlineSub->GetIdentityInterface()->GetAuthToken(0);
		ServerSetCurrentAccessTokenFromOSS(CurrentAccessTokenFromOSSCache);
	}
}

// Inventory stuff

bool AMyPlayerController::IsSlotEmpty(const int32 Index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::IsSlotEmpty"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);
	return(myPlayerState->InventorySlots[Index].quantity == 0);
}

int32 AMyPlayerController::SearchEmptySlot()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::SearchEmptySlot"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);
	for (int i = 0; i < myPlayerState->InventorySlots.Num(); i++) {
		if (myPlayerState->InventorySlots[i].quantity == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::SearchEmptySlot Found empty slot"));
			return i;
		}
	}
	return -1;
}

int32 AMyPlayerController::SearchSlotWithAvailableSpace(AMyBasePickup* ClassTypeIn)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::SearchSlotWithAvailableSpace"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);
	for (int i = 0; i < myPlayerState->InventorySlots.Num(); i++) {
		if (myPlayerState->InventorySlots[i].quantity != 0)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::SearchSlotWithAvailableSpace quantity != 0"));
			//UE_LOG(LogTemp, Log, TEXT("InventorySlots[i].itemClassPath: %s"), *myPlayerState->InventorySlots[i].itemClassPath);
			FString ClassClassPath = GetClassPath(ClassTypeIn->GetClass());
			UE_LOG(LogTemp, Log, TEXT("ClassTypeIn->GetClass(): %s"), *ClassClassPath);
			if (myPlayerState->InventorySlots[i].itemClassPath == ClassClassPath)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::SearchSlotWithAvailableSpace itemClass == ClassTypeIn"));
				// Also check to see if the Attributes match.  There could be same classes, with different attributes.
				if (myPlayerState->InventorySlots[i].Attributes == ClassTypeIn->Attributes)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::SearchSlotWithAvailableSpace InventorySlots[i].Attributes == ClassTypeIn->Attributes"));
					if (myPlayerState->InventorySlots[i].quantity < ClassTypeIn->MaxStackSize)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::SearchSlotWithAvailableSpace found slot with space"));
						return i;
					}
				}
			}
		}
	}
	return -1;
}

bool AMyPlayerController::AddItem( AMyBasePickup* ClassTypeIn, int32 quantity, bool checkOnly)
{
	// This should only ever be called from the server.
	// TODO - add dedicated server check
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (IsValid(ClassTypeIn))
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::ClassTypeIn->IsValidLowLevel()"));
		if (ClassTypeIn->bCanBeStacked)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem bCanBeStacked"));
			int32 availableStackableSlot = SearchSlotWithAvailableSpace(ClassTypeIn);
			if (availableStackableSlot >= 0)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem found availableStackableSlot"));
				if (quantity + myPlayerState->InventorySlots[availableStackableSlot].quantity > ClassTypeIn->MaxStackSize)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem quantity will NOT fit inside availableStackableSlot"));
					int32 amountFilled = ClassTypeIn->MaxStackSize - myPlayerState->InventorySlots[availableStackableSlot].quantity;
					if (!checkOnly)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem checkOnly is false - ADDING"));
						myPlayerState->InventorySlots[availableStackableSlot].quantity = ClassTypeIn->MaxStackSize;
					}
					return AddItem(ClassTypeIn, quantity - amountFilled, checkOnly);
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem quantity will fit inside availableStackableSlot"));
					if (!checkOnly)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem checkOnly is false - ADDING"));
						myPlayerState->InventorySlots[availableStackableSlot].quantity = myPlayerState->InventorySlots[availableStackableSlot].quantity + quantity;
					}
					return true;
				}
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem bCanBeStacked but there are no available non full slots"));
				int32 availableEmptySlot = SearchEmptySlot();
				if (availableEmptySlot >= 0)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem found an available empty slot"));
					if (quantity > 1) {
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem quantity is greater than max stack size"));
						if (!checkOnly)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem checkOnly is false - ADDING"));
							//InventorySlots[availableEmptySlot].itemClass = ClassTypeIn;
							myPlayerState->InventorySlots[availableEmptySlot].itemTitle = ClassTypeIn->Title.ToString();
							myPlayerState->InventorySlots[availableEmptySlot].itemDescription = ClassTypeIn->Description.ToString();
							myPlayerState->InventorySlots[availableEmptySlot].itemClassTitle = ClassTypeIn->GetName();
							myPlayerState->InventorySlots[availableEmptySlot].itemClassPath = GetClassPath(ClassTypeIn->GetClass());
							myPlayerState->InventorySlots[availableEmptySlot].quantity = 1;
							myPlayerState->InventorySlots[availableEmptySlot].Icon = ClassTypeIn->Icon;
							myPlayerState->InventorySlots[availableEmptySlot].UseText = ClassTypeIn->UseText;
							myPlayerState->InventorySlots[availableEmptySlot].bCanBeUsed = ClassTypeIn->bCanBeUsed;
							myPlayerState->InventorySlots[availableEmptySlot].bCanBeStacked = ClassTypeIn->bCanBeStacked;
							myPlayerState->InventorySlots[availableEmptySlot].MaxStackSize = ClassTypeIn->MaxStackSize;
							myPlayerState->InventorySlots[availableEmptySlot].Attributes = ClassTypeIn->Attributes;

							// TODO all the other vars
						}
						return AddItem(ClassTypeIn, quantity - 1, checkOnly);
					}
					else
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem quantity is within max stack size"));
						if (!checkOnly)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem checkOnly is false - ADDING"));
							//InventorySlots[availableEmptySlot].itemClass = ClassTypeIn->StaticClass;
							myPlayerState->InventorySlots[availableEmptySlot].itemTitle = ClassTypeIn->Title.ToString();
							myPlayerState->InventorySlots[availableEmptySlot].itemDescription = ClassTypeIn->Description.ToString();
							myPlayerState->InventorySlots[availableEmptySlot].itemClassTitle = ClassTypeIn->GetName();
							myPlayerState->InventorySlots[availableEmptySlot].itemClassPath = GetClassPath(ClassTypeIn->GetClass());
							myPlayerState->InventorySlots[availableEmptySlot].quantity = quantity;
							myPlayerState->InventorySlots[availableEmptySlot].Icon = ClassTypeIn->Icon;
							myPlayerState->InventorySlots[availableEmptySlot].UseText = ClassTypeIn->UseText;
							myPlayerState->InventorySlots[availableEmptySlot].bCanBeUsed = ClassTypeIn->bCanBeUsed;
							myPlayerState->InventorySlots[availableEmptySlot].bCanBeStacked = ClassTypeIn->bCanBeStacked;
							myPlayerState->InventorySlots[availableEmptySlot].MaxStackSize = ClassTypeIn->MaxStackSize;
							myPlayerState->InventorySlots[availableEmptySlot].Attributes = ClassTypeIn->Attributes;

							// TODO all the other vars

						}
						return true;
					}

				}
			}
		}
		else
		{
			int32 availableEmptySlot = SearchEmptySlot();
			if (availableEmptySlot >= 0)
			{
				if (!checkOnly)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::AddItem checkOnly is false - ADDING"));

					//InventorySlots[availableEmptySlot].itemClass = ClassTypeIn->StaticClass;
					myPlayerState->InventorySlots[availableEmptySlot].itemTitle = ClassTypeIn->Title.ToString();
					myPlayerState->InventorySlots[availableEmptySlot].itemDescription = ClassTypeIn->Description.ToString();
					myPlayerState->InventorySlots[availableEmptySlot].itemClassTitle = ClassTypeIn->GetName();
					myPlayerState->InventorySlots[availableEmptySlot].itemClassPath = GetClassPath(ClassTypeIn->GetClass());
					myPlayerState->InventorySlots[availableEmptySlot].quantity = 1;
					myPlayerState->InventorySlots[availableEmptySlot].Icon = ClassTypeIn->Icon;
					myPlayerState->InventorySlots[availableEmptySlot].UseText = ClassTypeIn->UseText;
					myPlayerState->InventorySlots[availableEmptySlot].bCanBeUsed = ClassTypeIn->bCanBeUsed;
					myPlayerState->InventorySlots[availableEmptySlot].bCanBeStacked = ClassTypeIn->bCanBeStacked;
					myPlayerState->InventorySlots[availableEmptySlot].MaxStackSize = ClassTypeIn->MaxStackSize;
					myPlayerState->InventorySlots[availableEmptySlot].Attributes = ClassTypeIn->Attributes;
				}
				if (quantity > 1)
				{
					return AddItem(ClassTypeIn, quantity - 1, checkOnly);
				}
				else {
					return true;
				}
			}
		}
	}
	return false;
}

bool AMyPlayerController::RemoveItemAtIndex(int32 index, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::RemoveItemAtIndex"));
	ServerAttemptRemoveItemAtIndex(index, quantity);
	return true;
}


bool AMyPlayerController::ServerAttemptRemoveItemAtIndex_Validate(int32 index, int32 quantity)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptRemoveItemAtIndex_Implementation(int32 index, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptRemoveItemAtIndex_Implementation"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (!IsSlotEmpty(index) && quantity > 0)
	{
		if (quantity >= myPlayerState->InventorySlots[index].quantity)
		{
			myPlayerState->InventorySlots[index].quantity = 0;
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::RemoveItemAtIndex DoRep_InventoryChanged"));
		}
		else
		{
			myPlayerState->InventorySlots[index].quantity = myPlayerState->InventorySlots[index].quantity - quantity;
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::RemoveItemAtIndex DoRep_InventoryChanged"));
		}
	}
	return;
}

bool AMyPlayerController::SwapSlots(int32 index1, int32 index2)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SwapSlots"));
	ServerAttemptSwapSlots(index1, index2);
	return true;
}

bool AMyPlayerController::ServerAttemptSwapSlots_Validate(int32 index, int32 quantity)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptSwapSlots_Implementation(int32 index1, int32 index2)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SwapSlots"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (index1 > myPlayerState->InventorySlots.Num() || index2 > myPlayerState->InventorySlots.Num())
	{
		return;
	}
	FMyInventorySlot localslot2 = myPlayerState->InventorySlots[index2];
	myPlayerState->InventorySlots[index2] = myPlayerState->InventorySlots[index1];
	myPlayerState->InventorySlots[index1] = localslot2;
	return;
}

bool AMyPlayerController::SplitStack(int32 index, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStack"));
	ServerAttemptSplitStack(index, quantity);
	return true;
}

bool AMyPlayerController::ServerAttemptSplitStack_Validate(int32 index, int32 quantity)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptSplitStack_Implementation(int32 index, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStack"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (myPlayerState->InventorySlots[index].quantity <= 0)
	{
		return;
	}
	if (myPlayerState->InventorySlots[index].bCanBeStacked && myPlayerState->InventorySlots[index].quantity > quantity)
	{
		int32 newIndex = SearchEmptySlot();
		if (newIndex >= 0) {
			myPlayerState->InventorySlots[newIndex] = myPlayerState->InventorySlots[index];
			myPlayerState->InventorySlots[newIndex].quantity = myPlayerState->InventorySlots[index].quantity - quantity;
			myPlayerState->InventorySlots[index].quantity = quantity;
			return;
		}
		else
		{
			return;
		}
	}
	return;

}


bool AMyPlayerController::SplitStackToIndex(int32 indexFrom, int32 indexTo, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (myPlayerState->InventorySlots[indexTo].quantity == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexTo is empty"));
		if (myPlayerState->InventorySlots[indexFrom].quantity > 1)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexFrom is not empty"));
			if (myPlayerState->InventorySlots[indexFrom].bCanBeStacked)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexFrom can be stacked"));
				if (myPlayerState->InventorySlots[indexFrom].quantity > quantity)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexFrom amount is greater than split amount"));
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex Requesting SplitStackToIndex on server"));

					ServerAttemptSplitStackToIndex(indexFrom, indexTo, quantity);
					return true;
				}
			}
		}
	}
	return false;
}

bool AMyPlayerController::ServerAttemptSplitStackToIndex_Validate(int32 indexFrom, int32 indexTo, int32 quantity)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptSplitStackToIndex_Implementation(int32 indexFrom, int32 indexTo, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptSplitStackToIndex_Implementation"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (myPlayerState->InventorySlots[indexTo].quantity == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexTo is empty"));
		if (myPlayerState->InventorySlots[indexFrom].quantity > 1)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexFrom is not empty"));
			if (myPlayerState->InventorySlots[indexFrom].bCanBeStacked)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexFrom can be stacked"));
				if (myPlayerState->InventorySlots[indexFrom].quantity > quantity)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SplitStackToIndex indexFrom amount is greater than split amount"));

					myPlayerState->InventorySlots[indexTo] = myPlayerState->InventorySlots[indexFrom];
					myPlayerState->InventorySlots[indexTo].quantity = quantity;
					myPlayerState->InventorySlots[indexFrom].quantity = myPlayerState->InventorySlots[indexFrom].quantity - quantity;

				}
			}
		}
	}
	return;

}

bool AMyPlayerController::DropItem(int32 index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::DropItem"));
	// this is executing on the client, not server.
	// check to see if this player is even allowed to drop
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (myPlayerState->allowDrop)
	{
		if (myPlayerState->InventorySlots[index].quantity > 0)
		{
			ServerAttemptDropItem(index);
			return true;
		}
		return false;
	}
	SendLocalChatMessage("Drop not permitted.  This could be due to server settings, or group permissions.");
	return false;
}

bool AMyPlayerController::ServerAttemptDropItem_Validate(int32 index)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}


void AMyPlayerController::ServerAttemptDropItem_Implementation(int32 index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptDropItem_Implementation]  "));

	// check to see if this player is even allowed to drop
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (myPlayerState->allowDrop)
	{
		// check to see if the maximum count has been reached yet.
		BasePickupsInLevel.Empty();
		FindAllActors(GetWorld(), BasePickupsInLevel);
		UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

		if (BasePickupsInLevel.Num() < TheGameInstance->maxPickupItemCount)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptDropItem_Implementation] BasePickupsInLevel < TheGameInstance->maxPickupItemCount "));
			if (myPlayerState->InventorySlots[index].quantity > 0) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptDropItem_Implementation] InventorySlots[index].quantity > 0 "));

				float placementDistance = 200.0f;
				FVector ShootDir = GetPawn()->GetActorForwardVector();
				FVector Origin = GetPawn()->GetActorLocation();
				FVector spawnlocationstart = ShootDir * placementDistance;
				FVector spawnlocation = spawnlocationstart + Origin;
				FTransform const SpawnTransform(ShootDir.Rotation(), spawnlocation);

				UWorld* World = GetWorld(); // get a reference to the world
				if (World)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptDropItem_Implementation] got world "));
					// if world exists, spawn the blueprint actor

					UClass* LoadedActorOwnerClass;
					LoadedActorOwnerClass = LoadClassFromPath(myPlayerState->InventorySlots[index].itemClassPath);

					//////  Instead of a stright spawn actor we need to use Deferred so we can set the attributes to something to what they are in the inventory.

					AMyBasePickup* pActor = World->SpawnActorDeferred<AMyBasePickup>(LoadedActorOwnerClass, SpawnTransform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
					if (pActor)
					{
						pActor->Attributes = myPlayerState->InventorySlots[index].Attributes;
						pActor->bCanBeStacked = myPlayerState->InventorySlots[index].bCanBeStacked;
						pActor->Quantity = myPlayerState->InventorySlots[index].quantity;
						UGameplayStatics::FinishSpawningActor(pActor, SpawnTransform);
					}
				}
				myPlayerState->InventorySlots[index].quantity = 0;
			}
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptDropItem_Implementation] maxPickupItemCount exceeded. "));

			// Send a local chat to the player in this case
			SendLocalChatMessage("The level cannot accept any more dropped items.");
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptDropItem_Implementation] Drop not permitted. "));

		// Send a local chat to the player in this case
		SendLocalChatMessage("Drop not permitted.  This could be due to server settings, or group permissions.");
	}
}

bool AMyPlayerController::UseItem(int32 index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::UseItem"));
	// this is executing on the client, not server.
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);
	if (myPlayerState->InventorySlots[index].quantity > 0)
	{
		ServerAttemptUseItem(index);
		return true;
	}
	return false;
}

bool AMyPlayerController::ServerAttemptUseItem_Validate(int32 index)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}


void AMyPlayerController::ServerAttemptUseItem_Implementation(int32 index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptUseItem_Implementation"));

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	UClass* LoadedActorOwnerClass;
	LoadedActorOwnerClass = LoadClassFromPath(myPlayerState->InventorySlots[index].itemClassPath);

	float placementDistance = 200.0f;
	FVector ShootDir = GetPawn()->GetActorForwardVector();
	FVector Origin = GetPawn()->GetActorLocation();
	FVector spawnlocationstart = ShootDir * placementDistance;
	FVector spawnlocation = spawnlocationstart + Origin;
	FTransform const SpawnTransform(ShootDir.Rotation(), spawnlocation);

	AMyBasePickup* myBasePickup = Cast<AMyBasePickup>(LoadedActorOwnerClass->GetDefaultObject());
	if (myBasePickup)
	{
		myBasePickup->OnItemUsed(SpawnTransform, myPlayerState->playerKeyId, LoadedActorOwnerClass);
	}

	myPlayerState->InventorySlots[index].quantity = myPlayerState->InventorySlots[index].quantity - 1;

}

bool AMyPlayerController::AddToIndex(int32 indexFrom, int32 indexTo)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex"));
	// this is executing on the client, not server.

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	UClass* IndexFromClass;
	IndexFromClass = LoadClassFromPath(myPlayerState->InventorySlots[indexFrom].itemClassPath);
	UClass* IndexToClass;
	IndexToClass = LoadClassFromPath(myPlayerState->InventorySlots[indexTo].itemClassPath);

	if (myPlayerState->InventorySlots[indexFrom].itemClassPath == myPlayerState->InventorySlots[indexTo].itemClassPath)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex Items match"));
		if (myPlayerState->InventorySlots[indexTo].quantity < myPlayerState->InventorySlots[indexTo].MaxStackSize)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex there is space available"));
			if (myPlayerState->InventorySlots[indexTo].bCanBeStacked)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex Can be stacked"));
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex Requesting Add to index on the server"));

				ServerAttemptAddToIndex(indexFrom, indexTo);
				return true;
			}
		}
	}
	return false;
}

bool AMyPlayerController::ServerAttemptAddToIndex_Validate(int32 indexFrom, int32 indexTo)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}


void AMyPlayerController::ServerAttemptAddToIndex_Implementation(int32 indexFrom, int32 indexTo)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptAddToIndex_Implementation"));

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (myPlayerState->InventorySlots[indexFrom].itemClassPath == myPlayerState->InventorySlots[indexTo].itemClassPath)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex Items match"));
		if (myPlayerState->InventorySlots[indexTo].quantity < myPlayerState->InventorySlots[indexTo].MaxStackSize)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex there is space available"));
			if (myPlayerState->InventorySlots[indexTo].bCanBeStacked)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex Can be stacked"));
				int32 availableStackQuantity = myPlayerState->InventorySlots[indexTo].MaxStackSize - myPlayerState->InventorySlots[indexTo].quantity;
				if (availableStackQuantity >= myPlayerState->InventorySlots[indexFrom].quantity)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex All Items can fit"));
					myPlayerState->InventorySlots[indexTo].quantity = myPlayerState->InventorySlots[indexTo].quantity + myPlayerState->InventorySlots[indexFrom].quantity;
					// clear out the from slot
					myPlayerState->InventorySlots[indexFrom].quantity = 0;
					myPlayerState->InventorySlots[indexFrom].itemClassTitle = "empty";
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddToIndex There are leftover items that cannot fit"));
					int32 amountRemaining = myPlayerState->InventorySlots[indexFrom].quantity - availableStackQuantity;

					myPlayerState->InventorySlots[indexTo].quantity = myPlayerState->InventorySlots[indexTo].MaxStackSize;
					myPlayerState->InventorySlots[indexFrom].quantity = amountRemaining;
				}
			}
		}
	}
	return;
}


void AMyPlayerController::InventoryItemSellStart(int32 index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::InventoryItemSellStart"));
	if (bInteractingWithVendor)
	{
		// TODO other checks like...  Is the vendor in range?
		FOnInventoryItemSellStarted.Broadcast(index);

	}
	return;
}

void AMyPlayerController::InventoryItemSellConfirm(int32 index, int32 pricePerUnit)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::InventoryItemSellConfirm"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (pricePerUnit >= 0)
	{
		if (myPlayerState->InventorySlots[index].quantity > 0)
		{
			ServerAttemptInventoryItemSellConfirm(index, pricePerUnit);
		}
	}
}

bool AMyPlayerController::ServerAttemptInventoryItemSellConfirm_Validate(int32 index, int32 pricePerUnit)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptInventoryItemSellConfirm_Implementation(int32 index, int32 pricePerUnit)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptInventoryItemSellConfirm_Implementation"));
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (pricePerUnit >= 0)
	{
		if (myPlayerState->InventorySlots[index].quantity > 0)
		{
			UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
			TheGameInstance->VendorItemCreate(this, InteractingWithVendorKeyId, index, pricePerUnit);
		}
	}
}

bool AMyPlayerController::PerformJsonHttpRequest(void(AMyPlayerController::*delegateCallback)(FHttpRequestPtr, FHttpResponsePtr, bool), FString APIURI, FString ArgumentString)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] PerformHttpRequest"));

	FHttpModule* Http = &FHttpModule::Get();
	if (!Http) { return false; }
	if (!Http->IsHttpEnabled()) { return false; }

	FString TargetHost = "https://" + APIURL + APIURI;

	UE_LOG(LogTemp, Log, TEXT("TargetHost: %s"), *TargetHost);

	TSharedRef < IHttpRequest > Request = Http->CreateRequest();


	// Get the access token
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] PerformHttpRequest found OnlineSub"));
		FString AccessToken = OnlineSub->GetIdentityInterface()->GetAuthToken(0);
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] PerformHttpRequest AccessToken: %s "), *AccessToken);
		Request->SetHeader(TEXT("x-uetopia-auth"), AccessToken);
	}


	Request->SetVerb("POST");
	Request->SetURL(TargetHost);
	Request->SetHeader("User-Agent", "UETOPIA_UE4_API_CLIENT/1.0");
	//Request->SetHeader("Content-Type", "application/x-www-form-urlencoded");
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));
	//Request->SetHeader("Key", ServerAPIKey);
	//Request->SetHeader("Sign", "RealSignatureComingIn411");
	Request->SetContentAsString(ArgumentString);

	Request->OnProcessRequestComplete().BindUObject(this, delegateCallback);
	if (!Request->ProcessRequest()) { return false; }

	return true;
}





bool AMyPlayerController::ServerAttemptSetVendorInteract_Validate(AMyBaseVendor* VendorRef)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptSetVendorInteract_Implementation(AMyBaseVendor* VendorRef)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptSetVendorInteract_Implementation"));

	bInteractingWithVendor = true;
	InteractingWithVendorKeyId = VendorRef->VendorKeyId;
	MyCurrentVendorRef = VendorRef;

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptSetVendorInteract_Implementation] VendorKeyId: %s "), *VendorRef->VendorKeyId);
}

void AMyPlayerController::AttemptVendorInteract(AMyBaseVendor* VendorRef)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AttemptVendorInteract"));

	// TODO check to see if in range
	FOnVendorInteractDisplayUI.Broadcast(VendorRef);
}

bool AMyPlayerController::ServerAttemptVendorUpdate_Validate(const FString& Title, const FString& Description, const FString& DiscordWebhook, bool bIsSelling, bool bIsBuying, bool bDisableForPickup)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptVendorUpdate_Implementation(const FString& Title, const FString& Description, const FString& DiscordWebhook, bool bIsSelling, bool bIsBuying, bool bDisableForPickup)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptVendorUpdate_Implementation"));

	// we could possibly get away with running the http call here, but it's better if it happens in game instance with server apikey/secret instead.

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);
	if (MyCurrentVendorRef == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptVendorUpdate_Implementation MyCurrentVendorRef Was nullptr!"));
	}
	else
	{
		TheGameInstance->VendorUpdate(myPlayerState->playerKeyId, MyCurrentVendorRef->VendorKeyId, Title, Description, DiscordWebhook, bIsSelling, bIsBuying, bDisableForPickup);
	}
}

void AMyPlayerController::AttemptVendorUpdate(const FString& Title, const FString& Description, const FString& DiscordWebhook, bool bIsSelling, bool bIsBuying, bool bDisableForPickup)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AttemptVendorUpdate"));

	ServerAttemptVendorUpdate(Title, Description, DiscordWebhook, bIsSelling, bIsBuying, bDisableForPickup);

}

bool AMyPlayerController::FindServerClusters()
{
	// Running on Client
	if (!IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] FindServerClusters"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);

		UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		FString GameKey = TheGameInstance->GameKey;

		FString JsonOutputString;
		PlayerJsonObj->SetStringField("gameKeyIdStr", GameKey);
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/_ah/api/servers/v1/serverClusterCollectionGetPage";

		//bool requestSuccess = PerformHttpRequest(&UMyGameInstance::FindServerClustersComplete, APIURI, OutputString, access_token);

		bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::FindServerClustersComplete, APIURI, JsonOutputString);

		// Clean out the server cluster list
		MyServerClusterResults.server_clusters.Empty();

		return requestSuccess;
	}
	return false;

}

void AMyPlayerController::FindServerClustersComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());

		//FString JsonRaw = *HttpResponse->GetContentAsString();
		const FString JsonRaw = *HttpResponse->GetContentAsString();

		bool jsonConvertSuccess = FJsonObjectConverter::JsonObjectStringToUStruct<FMyServerClusterSearchResults>(*JsonRaw, &MyServerClusterResults, 0, 0);

	}
	// Trigger the delegate
	OnGetServerClustersCompleteDelegate.Broadcast();

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [FindServerClustersComplete] Done!"));
}



bool AMyPlayerController::SelectServerCluster(const FString& serverClusterKeyId)
{
	// Running on Client
	if (!IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] SelectServerCluster"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);

		UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		FString GameKey = TheGameInstance->GameKey;

		FString JsonOutputString;
		PlayerJsonObj->SetStringField("key_id", GameKey);
		PlayerJsonObj->SetStringField("lastServerClusterKeyId", serverClusterKeyId);
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/_ah/api/games/v1/gamePlayerUpdate";

		//bool requestSuccess = PerformHttpRequest(&UMyGameInstance::FindServerClustersComplete, APIURI, OutputString, access_token);

		bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::SelectServerClusterComplete, APIURI, JsonOutputString);

		return requestSuccess;;

	}
	return false;

}

void AMyPlayerController::SelectServerClusterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());

		//We don't care too much about the results from this.  Maybe trigger a different delegate on failure or something?

	}
	// Trigger the delegate
	OnSelectServerClusterCompleteDelegate.Broadcast();

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [SelectServerClusterComplete] Done!"));
}


bool AMyPlayerController::FindServers(const FString& serverClusterKeyId)
{
	// Running on Client
	if (!IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] FindServers"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);


		FString JsonOutputString;
		PlayerJsonObj->SetStringField("serverClusterKeyIdStr", serverClusterKeyId);
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/_ah/api/servers/v1/serversCollectionGetPage";

		//bool requestSuccess = PerformHttpRequest(&UMyGameInstance::FindServerClustersComplete, APIURI, OutputString, access_token);

		bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::FindServersComplete, APIURI, JsonOutputString);

		// Clean out the server list
		MyServerResults.servers.Empty();

		return requestSuccess;;

	}
	return false;

}

void AMyPlayerController::FindServersComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());

		//FString JsonRaw = *HttpResponse->GetContentAsString();
		const FString JsonRaw = *HttpResponse->GetContentAsString();

		bool jsonConvertSuccess = FJsonObjectConverter::JsonObjectStringToUStruct<FMyServerSearchResults>(*JsonRaw, &MyServerResults, 0, 0);

	}
	// Trigger the delegate
	OnGetServersCompleteDelegate.Broadcast();

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [FindServersComplete] Done!"));
}


bool AMyPlayerController::ServerAllocate()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ServerAllocate"));


	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	FString GameKey = TheGameInstance->GameKey;

	FString JsonOutputString;
	PlayerJsonObj->SetStringField("key_id", GameKey);
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);


	FString APIURI = "/_ah/api/games/v1/attemptServerAllocate";

	bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::ServerAllocateComplete, APIURI, JsonOutputString);

	return requestSuccess;

}

bool AMyPlayerController::ServerAllocateByKey(const FString& serverKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ServerAllocate by serverKeyId"));


	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	FString GameKey = TheGameInstance->GameKey;

	FString JsonOutputString;
	PlayerJsonObj->SetStringField("key_id", GameKey);
	PlayerJsonObj->SetStringField("serverKeyIdStr", serverKeyId);
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/_ah/api/games/v1/attemptServerAllocate";

	bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::ServerAllocateComplete, APIURI, JsonOutputString);

	return requestSuccess;

}

void AMyPlayerController::ServerAllocateComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());
		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			UE_LOG(LogTemp, Log, TEXT("Parsed JSON response successfully."));

			// we don't care about this response.

		}
	}
}



bool AMyPlayerController::GetVendorInfo(FString vendorKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] GetVendorInfo"));

	// clear out the cache
	MyCurrentVendorInventory.Empty();

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);

	PlayerJsonObj->SetStringField("key_id", vendorKeyId);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	// _ah/api/vendors/v1/get

	FString APIURI = "/_ah/api/vendors/v1/get";

	bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::GetVendorInfoComplete, APIURI, JsonOutputString);

	return requestSuccess;

}

void AMyPlayerController::GetVendorInfoComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());
		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			UE_LOG(LogTemp, Log, TEXT("Parsed JSON response successfully."));

			JsonParsed->TryGetStringField("title", MyCurrentVendorTitle);
			JsonParsed->TryGetStringField("description", MyCurrentVendorDescription);
			JsonParsed->TryGetStringField("discordWebhook", MyCurrentVendorDiscordWebhook);

			JsonParsed->TryGetBoolField("bMyVendor", MyCurrentVendorIsOwnedByMe);
			JsonParsed->TryGetNumberField("vendorCurrency", MyCurrentVendorCurrency);


			const JsonValPtrArray *VendorItemsJson = nullptr;
			JsonParsed->TryGetArrayField("items", VendorItemsJson);
			if (VendorItemsJson != nullptr)
			{
				UE_LOG(LogTemp, Log, TEXT("Found Vendor Items in JSON "));
				// sometimes crashing here...  adding an extra check
				if (VendorItemsJson->Num() > 0)
				{
					for (auto vendorItem : *VendorItemsJson) {
						UE_LOG(LogTemp, Log, TEXT("Found Vendor Item "));
						auto VendorItemObj = vendorItem->AsObject();
						if (VendorItemObj.IsValid())
						{
							UE_LOG(LogTemp, Log, TEXT("Found Vendor Item - it is valid "));
							FMyVendorItem NewVendorItem;
							FString savedAttributes;
							//tempItem->TryGetStringField("key_id_str", NewVendorItem.ItemKeyId);
							VendorItemObj->TryGetStringField("title", NewVendorItem.itemTitle);
							VendorItemObj->TryGetStringField("description", NewVendorItem.itemDescription);
							VendorItemObj->TryGetNumberField("quantityAvailable", NewVendorItem.quantity);
							VendorItemObj->TryGetNumberField("pricePerUnit", NewVendorItem.PricePerUnit);
							VendorItemObj->TryGetStringField("blueprintPath", NewVendorItem.itemClassPath);
							VendorItemObj->TryGetStringField("key_id_str", NewVendorItem.itemKeyId);
							VendorItemObj->TryGetBoolField("selling", NewVendorItem.selling);
							VendorItemObj->TryGetBoolField("buyingOffer", NewVendorItem.buyingOffer);
							VendorItemObj->TryGetStringField("buyingOfferExpires", NewVendorItem.buyingOfferExpires);
							VendorItemObj->TryGetBoolField("claimable", NewVendorItem.claimable);
							VendorItemObj->TryGetStringField("attributes", savedAttributes);

							// parse Attributes from JSON
							// at this point we have a JSON encoded string:  savedAttributes

							bool AttributeParseSuccess = false;
							//FString AttributeJsonRaw = savedAttributes;
							TSharedPtr<FJsonObject> AttributesJsonParsed;
							TSharedRef<TJsonReader<TCHAR>> AttributesJsonReader = TJsonReaderFactory<TCHAR>::Create(savedAttributes);

							//const JsonValPtrArray *AttributesJson;

							if (FJsonSerializer::Deserialize(AttributesJsonReader, AttributesJsonParsed))
							{
								UE_LOG(LogTemp, Log, TEXT("AttributesJsonParsed"));
								//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] InventoryJsonRaw: %s"), *InventoryJsonRaw);

								// Now that the String has been converted into a json object we can get the array of values.

								const JsonValPtrArray *AttributesJson;
								AttributesJsonParsed->TryGetArrayField("attributes", AttributesJson);

								int32 currentIndex = 0;
								int32 referenceIndex = 0;
								FString JsonIndexName = "0";
								double JsonValue = 0.0f;

								// TODO rework this - it's possible that somewhow the attributes get messed up and out of sequence
								// like if it is saved, and an index is skipped.
								for (auto attributeJsonRaw : *AttributesJson) {
									UE_LOG(LogTemp, Log, TEXT("Found attribute "));
									JsonValue = 0.0f;
									auto attributeObj = attributeJsonRaw->AsObject();
									if (attributeObj.IsValid())
									{
										JsonIndexName = FString::FromInt(currentIndex);

										attributeObj->TryGetNumberField(JsonIndexName, JsonValue);

										NewVendorItem.Attributes.Add(JsonValue);
									}
									currentIndex++;
								}

								/*
								for (auto currObject = AttributesJsonParsed->Values.CreateConstIterator(); currObject; ++currObject)
								{
									UE_LOG(LogTemp, Log, TEXT("Found Attribute: %s"), *currObject->Key);
									currObject->Key;
									if (currObject->Value->AsNumber())
									{
										NewVendorItem.Attributes.Add(currObject->Value->AsNumber());
									}

								}
								*/



								//AttributeParseSuccess = AttributesJsonParsed->TryGetArrayField("data", AttributesJson);
								//TArray<TSharedPtr<FJsonValue> > JsonFriends = JsonObject->GetArrayField(TEXT("data"));
							}

							if (!NewVendorItem.itemClassPath.IsEmpty())
							{
								UE_LOG(LogTemp, Log, TEXT("!NewVendorItem.itemClassPath.IsEmpty()"));
								UClass* LoadedActorOwnerClass;
								LoadedActorOwnerClass = LoadClassFromPath(VendorItemObj->GetStringField(FString("blueprintPath")));

								if (LoadedActorOwnerClass)
								{
									UE_LOG(LogTemp, Log, TEXT("Found LoadedActorOwnerClass"));

									AMyBasePickup* basePickupBP = Cast<AMyBasePickup>(LoadedActorOwnerClass->GetDefaultObject());

									NewVendorItem.Icon = basePickupBP->Icon;
								}
								else
								{
									NewVendorItem.Icon = nullptr;
								}
							}
							else
							{
								NewVendorItem.Icon = nullptr;
							}

							MyCurrentVendorInventory.Add(NewVendorItem);
						}
					}
				}

			}

			FOnVendorInfoComplete.Broadcast();

		}
	}
}


bool AMyPlayerController::AddItemToVendor(int32 indexFrom, int32 quantity, int32 pricePerUnit, const FString& vendorKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddItemToVendor"));
	// this is executing on the client, not server.

	ServerAttemptAddItemToVendor(indexFrom, quantity, pricePerUnit, vendorKeyId);
	return true;

}

bool AMyPlayerController::ServerAttemptAddItemToVendor_Validate(int32 indexFrom, int32 quantity, int32 pricePerUnit, const FString& vendorKeyId)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}


void AMyPlayerController::ServerAttemptAddItemToVendor_Implementation(int32 indexFrom, int32 quantity, int32 pricePerUnit, const FString& vendorKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptAddItemToVendor_Implementation"));

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (quantity > 0)
	{
		if (myPlayerState->InventorySlots[indexFrom].quantity >= quantity)
		{
			if (pricePerUnit >= 0)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptAddItemToVendor_Implementation checks passed - calling instance"));
			}
		}
	}
	return;
}


bool AMyPlayerController::RemoveItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::RemoveItemFromVendor"));
	// this is executing on the client, not server.
	// TODO Make sure that the user has space in inventory
	ServerRemoveItemFromVendor( vendorKeyId, vendorItemKeyId);
	return true;
}

bool AMyPlayerController::ServerRemoveItemFromVendor_Validate(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}


void AMyPlayerController::ServerRemoveItemFromVendor_Implementation(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerRemoveItemFromVendor_Implementation"));
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	TheGameInstance->VendorItemDelete(this, vendorKeyId, vendorItemKeyId);
	return;
}


bool AMyPlayerController::BuyItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::RemoveItemFromVendor"));
	// this is executing on the client, not server.
	// TODO Make sure that the user has space in inventory
	ServerBuyItemFromVendor(vendorKeyId, vendorItemKeyId, quantity);
	return true;
}

bool AMyPlayerController::ServerBuyItemFromVendor_Validate(const FString& vendorKeyId, const FString& vendorItemKeyId, int32 quantity)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerBuyItemFromVendor_Implementation(const FString& vendorKeyId, const FString& vendorItemKeyId, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerBuyItemFromVendor_Implementation"));
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	TheGameInstance->VendorItemBuy(this, vendorKeyId, vendorItemKeyId, quantity);
	return;
}

bool AMyPlayerController::WithdrawFromVendor(const FString& vendorKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::WithdrawFromVendor"));
	// this is executing on the client, not server.
	// TODO Make sure that the user has space in inventory
	ServerWithdrawFromVendor(vendorKeyId);
	return true;
}

bool AMyPlayerController::ServerWithdrawFromVendor_Validate(const FString& vendorKeyId)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}


void AMyPlayerController::ServerWithdrawFromVendor_Implementation(const FString& vendorKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerWithdrawFromVendor_Implementation"));
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	TheGameInstance->VendorWithdraw(this, vendorKeyId);
	return;
}

bool AMyPlayerController::DeclineOfferFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::DeclineOfferFromVendor"));
	// this is executing on the client, not server.
	// TODO Make sure that the user has space in inventory
	ServerDeclineOfferFromVendor(vendorKeyId, vendorItemKeyId);
	return true;
}

bool AMyPlayerController::ServerDeclineOfferFromVendor_Validate(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerDeclineOfferFromVendor_Implementation(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerDeclineOfferFromVendor_Implementation"));
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	TheGameInstance->VendorOfferDecline(this, vendorKeyId, vendorItemKeyId);
	return;
}


bool AMyPlayerController::ClaimItemFromVendor(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ClaimItemFromVendor"));
	// this is executing on the client, not server.
	// TODO Make sure that the user has space in inventory
	ServerClaimItemFromVendor(vendorKeyId, vendorItemKeyId);
	return true;
}

bool AMyPlayerController::ServerClaimItemFromVendor_Validate(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerClaimItemFromVendor_Implementation(const FString& vendorKeyId, const FString& vendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerBuyItemFromVendor_Implementation"));
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	TheGameInstance->VendorItemClaim(this, vendorKeyId, vendorItemKeyId);
	return;
}

/////////////
// CHARACTERS
/////////////


bool AMyPlayerController::GetCharacterList()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] GetCharacterList"));

	// clear out the struct
	MyCachedCharacters.Empty();

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	FString GameKey = TheGameInstance->GameKey;

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("gameKeyIdStr", GameKey);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);
	FString APIURI = "/_ah/api/characters/v1/collectionGetPage";
	bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::GetCharacterListComplete, APIURI, JsonOutputString);
	return requestSuccess;

}

void AMyPlayerController::GetCharacterListComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());
		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			UE_LOG(LogTemp, Log, TEXT("Parsed JSON response successfully."));

			const JsonValPtrArray *CharactersJson = nullptr;
			JsonParsed->TryGetArrayField("characters", CharactersJson);
			if (CharactersJson != nullptr)
			{
				UE_LOG(LogTemp, Log, TEXT("Found Characters in JSON "));
				// sometimes crashing here...  adding an extra check
				if (CharactersJson->Num() > 0)
				{
					for (auto characterJson : *CharactersJson) {
						UE_LOG(LogTemp, Log, TEXT("Found Vendor Item "));
						auto CharacterObj = characterJson->AsObject();
						if (CharacterObj.IsValid())
						{
							UE_LOG(LogTemp, Log, TEXT("Found Character - it is valid "));
							FMyCharacterRecord NewCharacter;

							CharacterObj->TryGetStringField("key_id", NewCharacter.key_id);
							CharacterObj->TryGetStringField("title", NewCharacter.title);
							CharacterObj->TryGetStringField("description", NewCharacter.description);
							CharacterObj->TryGetStringField("characterType", NewCharacter.characterType);
							CharacterObj->TryGetStringField("characterState", NewCharacter.characterState);
							CharacterObj->TryGetBoolField("characterAlive", NewCharacter.characterAlive);
							CharacterObj->TryGetBoolField("currentlySelectedActive", NewCharacter.currentlySelectedActive);

							CharacterObj->TryGetNumberField("rank", NewCharacter.rank);
							CharacterObj->TryGetNumberField("score", NewCharacter.score);
							CharacterObj->TryGetNumberField("level", NewCharacter.level);

							// TODO - use the "character" string to parse out any of your custom values
							// If it does not exist, fall back to characterCustom

							// TODO - run some logic to assign an icon
							NewCharacter.Icon = nullptr;

							MyCachedCharacters.Add(NewCharacter);
						}
					}
				}
			}
			OnGetCharacterListCompleteDelegate.Broadcast();
		}
	}
}

bool AMyPlayerController::CreateCharacter(FString title, FString description, FString characterType, FString characterState, FString characterClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] CreateCharacter"));

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	FString GameKey = TheGameInstance->GameKey;
	PlayerJsonObj->SetStringField("gameKeyIdStr", GameKey);

	PlayerJsonObj->SetStringField("title", title);
	PlayerJsonObj->SetStringField("description", description);
	PlayerJsonObj->SetStringField("characterType", characterType);
	PlayerJsonObj->SetStringField("characterState", characterState);

	// Combine all of your custom character information, and serialize to JSON for storage in characterCustom.
	// At this stage, it has been submitted by the player, and might contain invalid data - if the player were to forge this request
	// The data will be verified later by the server.  

	// Convert Character Customization data into json friendly 
	TSharedPtr<FJsonObject> CharacterCustomJsonObject = MakeShareable(new FJsonObject);
	CharacterCustomJsonObject->SetBoolField("Setup", true);
	CharacterCustomJsonObject->SetStringField("Class", characterClass);
	FString CharacterCustomOutputString;

	TSharedRef< TJsonWriter<> > CharacterCustomWriter = TJsonWriterFactory<>::Create(&CharacterCustomOutputString);
	FJsonSerializer::Serialize(CharacterCustomJsonObject.ToSharedRef(), CharacterCustomWriter);

	PlayerJsonObj->SetStringField("characterCustom", CharacterCustomOutputString);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);
	FString APIURI = "/_ah/api/characters/v1/create";
	bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::CreateCharacterComplete, APIURI, JsonOutputString);
	return requestSuccess;
}

void AMyPlayerController::CreateCharacterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());
		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			UE_LOG(LogTemp, Log, TEXT("Parsed JSON response successfully."));
			// WE don't need to do anything in here...  Maybe trigger a delegate to start a refresh?
		}
	}
}

bool AMyPlayerController::DeleteCharacter(FString characterKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] DeleteCharacter"));
	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	FString GameKey = TheGameInstance->GameKey;
	PlayerJsonObj->SetStringField("gameKeyId", GameKey);
	PlayerJsonObj->SetStringField("key_id", characterKeyId);
	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);
	FString APIURI = "/_ah/api/characters/v1/delete";
	bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::DeleteCharacterComplete, APIURI, JsonOutputString);
	return requestSuccess;
}

void AMyPlayerController::DeleteCharacterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());
		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			UE_LOG(LogTemp, Log, TEXT("Parsed JSON response successfully."));
			// WE don't need to do anything in here...  Maybe trigger a delegate to start a refresh?
		}
	}
}


bool AMyPlayerController::SelectCharacter(FString characterKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] SelectCharacter"));
	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	FString GameKey = TheGameInstance->GameKey;
	PlayerJsonObj->SetStringField("gameKeyId", GameKey);
	PlayerJsonObj->SetStringField("key_id", characterKeyId);
	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);
	FString APIURI = "/_ah/api/characters/v1/select";
	bool requestSuccess = PerformJsonHttpRequest(&AMyPlayerController::SelectCharacterComplete, APIURI, JsonOutputString);
	return requestSuccess;
}

void AMyPlayerController::SelectCharacterComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
			*HttpRequest->GetVerb(),
			*HttpRequest->GetURL(),
			HttpResponse->GetResponseCode(),
			*HttpResponse->GetContentAsString());
		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			UE_LOG(LogTemp, Log, TEXT("Parsed JSON response successfully."));
			// WE don't need to do anything in here...  Maybe trigger a delegate to start a refresh?
		}
	}
}


void AMyPlayerController::SaveCharacterCustomization(FString characterClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SaveCharacterCustomization"));

	int32 ClassIndex;

	// convert the strings to int32
	if (characterClass == "Developer")
	{
		ClassIndex = 0;
	}
	else
	{
		ClassIndex = 1;
	}

	// Run RPC on server
	SaveCharacterCustomizationServer(ClassIndex);
}

bool AMyPlayerController::SaveCharacterCustomizationServer_Validate(int32 characterClass)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::SaveCharacterCustomizationServer_Implementation(int32 characterClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SaveCharacterCustomization -running on server"));

	// Set vars in playerState
	AMyPlayerState* playerS = Cast<AMyPlayerState>(this->PlayerState);
	AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(GetPawn());

	// If you are doing anything complicated, maybe put all of these character custom fields in a struct for easier passing?
	// because we're going to want a repnotify for it in the character.
	playerS->CharacterSetup = true;
	playerS->CharacterClass = characterClass;

	if (playerChar)
	{
		// Tell this client to change UI state to play
		ClientChangeUIState(EConnectUIState::Play);
	}
}


////////////
// ABILITIES
////////////

bool AMyPlayerController::RemoveAbilityFromBar(int32 index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::RemoveAbilityFromBar"));
	// this is executing on the client, not server.
	ServerAttemptRemoveAbilityFromBar(index);
	return false;
}

bool AMyPlayerController::ServerAttemptRemoveAbilityFromBar_Validate(int32 index)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptRemoveAbilityFromBar_Implementation(int32 index)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptRemoveAbilityFromBar_Implementation"));

	MyAbilitySlots[index].bIsValid = false;

	// Trigger the delegate.
	// Note: this function should only be used as a "throw away a skill" function, and not used in combination with AddAbility
	// TODO - consider adding a bool to determine if the delegate should be triggered or not.

	//DoRep_AbilityInterfaceChanged = !DoRep_AbilityInterfaceChanged;

	return;
}

bool AMyPlayerController::AddAbilityToBar(int32 index, FMyGrantedAbility GrantedAbility)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AddAbilityToBar"));
	// this is executing on the client, not server.


	ServerAttemptAddAbilityToBar(index, GrantedAbility);
	return false;
}

bool AMyPlayerController::ServerAttemptAddAbilityToBar_Validate(int32 index, FMyGrantedAbility GrantedAbility)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptAddAbilityToBar_Implementation(int32 index, FMyGrantedAbility GrantedAbility)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptAddAbilityToBar_Implementation"));

	// check to see if GrantedAbility is real.

	// TODO Make sure that this ability is not already in the bar.
	// Can't have an ability assigned to more than one hotkey

	for (int32 abilitySlotIndex = 0; abilitySlotIndex < MyAbilitySlots.Num(); abilitySlotIndex++)
	{
		if (MyAbilitySlots[abilitySlotIndex].bIsValid)
		{
			if (MyAbilitySlots[abilitySlotIndex].GrantedAbility.AbilityHandle == GrantedAbility.AbilityHandle)
			{
				if (index == abilitySlotIndex)
				{
					// same slot - we don't need to do anything.
					return;
				}
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptAddAbilityToBar_Implementation - found duplicate handle in ability bar - removing it"));
				MyAbilitySlots[abilitySlotIndex].bIsValid = false;
			}
		}
	}

	MyAbilitySlots[index].bIsValid = true;
		//MyAbilitySlots[index].bCanBeUsed = GrantedAbility.
	MyAbilitySlots[index].classPath = GrantedAbility.classPath;
		//MyAbilitySlots[index].classTitle = GrantedAbility.
	MyAbilitySlots[index].description = GrantedAbility.description;
	MyAbilitySlots[index].Icon = GrantedAbility.Icon;
		//MyAbilitySlots[index].Key = GrantedAbility.
	MyAbilitySlots[index].title = GrantedAbility.title;
		//MyAbilitySlots[index].UseText = GrantedAbility.
	MyAbilitySlots[index].GrantedAbility = GrantedAbility;

	return;
}

bool AMyPlayerController::SwapAbilityBarLocations(int32 indexFrom, int32 indexTo)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SwapAbilityBarLocations"));
	// this is executing on the client, not server.
	ServerAttemptSwapAbilityBarLocations(indexFrom, indexTo);
	return false;
}

bool AMyPlayerController::ServerAttemptSwapAbilityBarLocations_Validate(int32 indexFrom, int32 indexTo)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

void AMyPlayerController::ServerAttemptSwapAbilityBarLocations_Implementation(int32 indexFrom, int32 indexTo)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptSwapAbilityBarLocations_Implementation"));

	// we can't just copy the entire struct becuase the key binding is in there too!

	// We need to do something with the array in player state in order to get the keybindings to stick

	FMyAbilitySlot TempSlotData = MyAbilitySlots[indexFrom];

	MyAbilitySlots[indexFrom].bCanBeUsed = MyAbilitySlots[indexTo].bCanBeUsed;
	MyAbilitySlots[indexFrom].bIsValid = MyAbilitySlots[indexTo].bIsValid;
	MyAbilitySlots[indexFrom].classPath = MyAbilitySlots[indexTo].classPath;
	MyAbilitySlots[indexFrom].classTitle = MyAbilitySlots[indexTo].classTitle;
	MyAbilitySlots[indexFrom].description = MyAbilitySlots[indexTo].description;
	MyAbilitySlots[indexFrom].GrantedAbility = MyAbilitySlots[indexTo].GrantedAbility;
	MyAbilitySlots[indexFrom].Icon = MyAbilitySlots[indexTo].Icon;
	MyAbilitySlots[indexFrom].title = MyAbilitySlots[indexTo].title;
	MyAbilitySlots[indexFrom].UseText = MyAbilitySlots[indexTo].UseText;

	MyAbilitySlots[indexTo].bCanBeUsed = TempSlotData.bCanBeUsed;
	MyAbilitySlots[indexTo].bIsValid = TempSlotData.bIsValid;
	MyAbilitySlots[indexTo].classPath = TempSlotData.classPath;
	MyAbilitySlots[indexTo].classTitle = TempSlotData.classTitle;
	MyAbilitySlots[indexTo].description = TempSlotData.description;
	MyAbilitySlots[indexTo].GrantedAbility = TempSlotData.GrantedAbility;
	MyAbilitySlots[indexTo].Icon = TempSlotData.Icon;
	MyAbilitySlots[indexTo].title = TempSlotData.title;
	MyAbilitySlots[indexTo].UseText = TempSlotData.UseText;

	//MyAbilitySlots[indexTo] = TempSlotData;

	//DoRep_AbilityInterfaceChanged = !DoRep_AbilityInterfaceChanged;

	return;
}

bool AMyPlayerController::GrantCachedAbilities_Validate()
{
	return true;
}
void AMyPlayerController::GrantCachedAbilities_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::GrantCachedAbilities_Implementation"));

	AMyPlayerState* playerS = Cast<AMyPlayerState>(this->PlayerState);
	AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(GetPawn());
	FGameplayAbilitySpecHandle AbilityHandle;
	UClass* LoadedActorOwnerClass;
	UMyBaseGameplayAbility* LoadedObjectClass;

	// empty the granted abilities array in player state and here
	MyGrantedAbilities.Empty();
	playerS->GrantedAbilities.Empty();

	// Create a local copy of the array
	TArray<FMyGrantedAbility> LocalGrantedAbilities;
	FMyGrantedAbility grantedAbility;

	for (int32 Index = 0; Index < playerS->CachedAbilities.Num(); Index++)
	{

		LoadedActorOwnerClass = LoadClassFromPath(playerS->CachedAbilities[Index].classPath);

		if (LoadedActorOwnerClass)
		{
			LoadedObjectClass = Cast<UMyBaseGameplayAbility>(LoadedActorOwnerClass->GetDefaultObject());
			AbilityHandle = playerChar->AttemptGiveAbility(LoadedObjectClass);

			grantedAbility.AbilityHandle = AbilityHandle;
			grantedAbility.classPath = playerS->CachedAbilities[Index].classPath;
			grantedAbility.Icon = LoadedObjectClass->Icon;
			grantedAbility.title = LoadedObjectClass->Title.ToString();
			grantedAbility.description = LoadedObjectClass->Description.ToString();
			//UGameplayAbility* AbilityClassRef = Cast<UGameplayAbility>(LoadedObjectClass);
			grantedAbility.Ability = LoadedObjectClass->GetClass();

			LocalGrantedAbilities.Add(grantedAbility);
		}


	}
	playerS->GrantedAbilities = LocalGrantedAbilities;
	MyGrantedAbilities = LocalGrantedAbilities;

	// WE need to update MyAbilitySlots as well with the new ability
	for (int32 Index = 0; Index < MyAbilitySlots.Num(); Index++)
	{
		int32 matchingGrantedAbilityIndex = -1;
		// go though granted abilities and find by Class
		for (int32 grantedAIndex = 0; grantedAIndex < MyGrantedAbilities.Num(); grantedAIndex++)
		{
			if (MyAbilitySlots[Index].classPath == MyGrantedAbilities[grantedAIndex].classPath)
			{
				UE_LOG(LogTemp, Log, TEXT("Found matching granted ability"));
				matchingGrantedAbilityIndex = grantedAIndex;
				break;
			}
		}
		// If a match was found, replace the link to the granted ability.
		if (matchingGrantedAbilityIndex >= 0)
		{
			UE_LOG(LogTemp, Log, TEXT("Adding found ability to ability slots"));
			MyAbilitySlots[Index].GrantedAbility = MyGrantedAbilities[matchingGrantedAbilityIndex];
		}

	}
	return;
}

void AMyPlayerController::OnRep_OnAbilitiesChange_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnRep_OnAbilitiesChange"));
	//AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(GetPawn());
	//playerChar->RemapAbilities();
	OnAbilitiesChanged.Broadcast();
}

void AMyPlayerController::OnRep_OnAbilityInterfaceChange_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnRep_OnAbilityInterfaceChange"));
	AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(GetPawn());
	playerChar->RemapAbilities();
	OnAbilityInterfaceChanged.Broadcast();
}

void AMyPlayerController::UnFreeze()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::UnFreeze"));
	ServerRestartPlayer();

	// Tell the UI to refresh
	OnAbilitiesChanged.Broadcast();
	OnAbilityInterfaceChanged.Broadcast();
	OnChatChannelsChangedUETopia.Broadcast();
	OnFriendsChanged.Broadcast();
	//OnInventoryChanged.Broadcast();
	OnPartyDataReceivedUETopiaDisplayUI.Broadcast();
	OnRecentPlayersChanged.Broadcast();
}

void AMyPlayerController::ClearHUDWidgets_Implementation()
{
	/* Object Iterator for All User Widgets! */
	for (TObjectIterator<UUserWidget> Itr; Itr; ++Itr)
	{
		UUserWidget* LiveWidget = *Itr;

		/* If the Widget has no World, Ignore it (It's probably in the Content Browser!) */
		if (!LiveWidget->GetWorld())
		{
			continue;
		}
		else
		{
			LiveWidget->RemoveFromParent();
		}
	}
}

void AMyPlayerController::AttemptShardSwitch(const FString& ShardKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::AttemptShardSwitch"));
	ServerAttemptShardSwitch(ShardKeyId);
}

void AMyPlayerController::ServerAttemptShardSwitch_Implementation(const FString& ShardKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptShardSwitch_Implementation]  "));
	UWorld* const World = GetWorld();
	if (World) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptTravel_Implementation] Requesting Transfer  "));
		UMyGameInstance* gameInstance = Cast<UMyGameInstance>(World->GetGameInstance());
		AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);
		gameInstance->TransferPlayer(ShardKeyId, PlayerState->PlayerId, false, true);
	}
}

bool AMyPlayerController::ServerAttemptShardSwitch_Validate(const FString& ShardKeyId)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Validate]  "));
	return true;
}


bool AMyPlayerController::ServerAttemptClaimDrop_Validate(const FString& dropKeyId)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}


void AMyPlayerController::ServerAttemptClaimDrop_Implementation(const FString& dropKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::ServerAttemptClaimDrop_Implementation"));

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(PlayerState);

	// find an empty slot
	int32 emptyInventorySlotIndex = SearchEmptySlot();

	if (emptyInventorySlotIndex == -1)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SaveLootItemToInventory NO Space in inventory"));
		return;
	}

	// tell game instance to run the request
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	if (TheGameInstance)
	{
		TheGameInstance->ClaimPlayerDrop(myPlayerState->playerKeyId, dropKeyId);
	}
}


void AMyPlayerController::SendLocalChatMessage_Implementation(const FString& ChatMessageIn)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::SendLocalChatMessage"));
	OnChatPrivateMessageReceivedDisplayUIDelegate.Broadcast("SYSTEM", ChatMessageIn);
}


///////////////////////////////////////////////////////////
// These all get overridden in BP and should never actually trigger
///////////////////////////////////////////////////////////

void AMyPlayerController::OnInventoryChangedBP_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyPlayerController::OnInventoryChangedBP_Implementation"));
}

void AMyPlayerController::OnEquipmentChangedBP_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnEquipmentChangedBP_Implementation"));
}

void AMyPlayerController::OnUIStateChange_Implementation(EConnectUIState UIState)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AUEtopiaCompetitiveCharacter::OnUIStateChange_Implementation"));
}

void AMyPlayerController::OnChatChannelsChangedChangedBP_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnChatChannelsChangedChangedBP_Implementation"));
}

void AMyPlayerController::OnAttributesChangedBP_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnAttributesChangedBP_Implementation"));
}

void AMyPlayerController::OnDropsChangedBP_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OnDropsChangedBP_Implementation"));
}

void AMyPlayerController::OntitleChangedBP_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerController::OntitleChangedBP_Implementation"));
}

void AMyPlayerController::ClientChangeUIState_Implementation(EConnectUIState NewState)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ClientChangeUIState_Implementation"));
	//OnUIStateChange.Broadcast(NewState);
	CurrentUIState = NewState;
	OnUIStateChange(NewState);
	return;
}



void AMyPlayerController::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicates to this player only
	//DOREPLIFETIME(AMyPlayerController, DoRep_InventoryChanged);
	//DOREPLIFETIME(AMyPlayerController, DoRep_AbilitiesChanged);
	//DOREPLIFETIME(AMyPlayerController, DoRep_AbilityInterfaceChanged);
	//DOREPLIFETIME(AMyPlayerController, InventorySlots);
	DOREPLIFETIME(AMyPlayerController, MyAbilitySlots);
	DOREPLIFETIME(AMyPlayerController, MyGrantedAbilities);
	DOREPLIFETIME(AMyPlayerController, AbilitySlotsPerRow);
	//DOREPLIFETIME(AMyPlayerController, CurrencyAvailable);
	DOREPLIFETIME(AMyPlayerController, bInteractingWithVendor);
	DOREPLIFETIME(AMyPlayerController, InteractingWithVendorKeyId);
	//DOREPLIFETIME(AMyPlayerController, Experience);
	//DOREPLIFETIME(AMyPlayerController, ExperienceThisLevel);
	DOREPLIFETIME(AMyPlayerController, bIsShardedServer);
	//DOREPLIFETIME(AMyPlayerController, customTexture);

}
