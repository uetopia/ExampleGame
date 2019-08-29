// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameSession.h"
#include "ProMMO.h"
#include "Online.h"
#include "MyGameInstance.h"
#include "MyPlayerState.h"
#include "MyOnlineGameSettings.h"
#include "MyPlayerController.h"

namespace
{
	const FString CustomMatchKeyword("Custom");
}


AMyGameSession::AMyGameSession(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::AMyGameSession"));

	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::AMyGameSession !HasAnyFlags"));
		// TODO some of these should only happen on the client. and never on the server.
		OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &AMyGameSession::OnCreateSessionComplete);
		OnDestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &AMyGameSession::OnDestroySessionComplete);
		OnFindSessionsCompleteDelegate = FOnFindSessionsCompleteDelegate::CreateUObject(this, &AMyGameSession::OnFindSessionsComplete);
		OnJoinSessionCompleteDelegate = FOnJoinSessionCompleteDelegate::CreateUObject(this, &AMyGameSession::OnJoinSessionComplete);
		OnMatchmakingStartedDelegate = FOnMatchmakingStartedDelegate::CreateUObject(this, &AMyGameSession::OnMatchmakingStartedComplete);
		OnMatchmakingCompleteDelegate = FOnMatchmakingCompleteDelegate::CreateUObject(this, &AMyGameSession::OnMatchmakingComplete);
		if (IsRunningDedicatedServer()) {
			//RegisterServer();
		}

		IOnlineSubsystem * OnlineSub = IOnlineSubsystem::Get();
		IOnlineSessionPtr Sessions = (OnlineSub != NULL) ? OnlineSub->GetSessionInterface() : NULL;

		if (Sessions.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::AMyGameSession Session valid"));
			Sessions->AddOnMatchmakingCompleteDelegate_Handle(OnMatchmakingCompleteDelegate);
			Sessions->AddOnMatchmakingStartedDelegate_Handle(OnMatchmakingStartedDelegate);
		}
	}
}

EOnlineAsyncTaskState::Type AMyGameSession::GetSearchResultStatus(int32& SearchResultIdx, int32& NumSearchResults)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION ::GetSearchResultStatus"));
	SearchResultIdx = 0;
	NumSearchResults = 0;

	if (SearchSettings.IsValid())
	{
		if (SearchSettings->SearchState == EOnlineAsyncTaskState::Done)
		{
			SearchResultIdx = CurrentSessionParams.BestSessionIdx;
			NumSearchResults = SearchSettings->SearchResults.Num();
		}
		return SearchSettings->SearchState;
	}

	return EOnlineAsyncTaskState::NotStarted;
}

/**
* Get the search results.
*
* @return Search results
*/
const TArray<FOnlineSessionSearchResult> & AMyGameSession::GetSearchResults() const
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION ::GetSearchResults"));
	return SearchSettings->SearchResults;
};

/**
* Delegate fired when a session create request has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void AMyGameSession::OnCreateSessionComplete(FName SessionNameIncoming, bool bWasSuccessful)
{
	//UE_LOG(LogOnlineGame, Verbose, TEXT("OnCreateSessionComplete %s bSuccess: %d"), *SessionName.ToString(), bWasSuccessful);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::OnCreateSessionComplete"));

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::OnCreateSessionComplete OnlineSub"));
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		Sessions->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);
		FNamedOnlineSession *sess = Sessions->GetNamedSession(SessionNameIncoming);
		// TODO - move this off instance, and just fire off the http request from inside here.
		UMyGameInstance *gameInstance = Cast<UMyGameInstance>(this->GetGameInstance());
		//if (GEngine->GetWorld() != nullptr && GEngine->GetWorld()->GetGameInstance() != nullptr)
		//{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::OnCreateSessionComplete Got Instance"));
		//UMyGameInstance *gameInstance = Cast<UMyGameInstance>(GEngine->GetWorld()->GetGameInstance());
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::OnCreateSessionComplete 2"));
		bool result = gameInstance->RegisterNewSession(sess->SessionInfo->ToString(), sess->SessionInfo->ToString());
		//bool result = gameInstance->RegisterNewSession(SessionName.ToString(), SessionName.ToString());
		//bool result = gameInstance->RegisterNewSession("test", "hardcoded");
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::OnCreateSessionComplete 3"));

		// I dont think we want this here.  We are getting duplicate requests.
		// TODO fix it.
		// ServerInfo is for continuous servers.  Since we are using matchmaker, we are not going to use this.
		//gameInstance->GetServerInfo();
		//gameInstance->GetMatchInfo();
		//}
	}
	//OnCreateSessionComplete().Broadcast(SessionName, bWasSuccessful);
	OnCreatePresenceSessionComplete().Broadcast(SessionNameIncoming, bWasSuccessful);
}

void AMyGameSession::OnFindSessionsComplete(bool bWasSuccessful)
{
	//UE_LOG(LogOnlineGame, Verbose, TEXT("OnFindSessionsComplete bSuccess: %d"), bWasSuccessful);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION ::OnFindSessionsComplete"));

	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION ::OnFindSessionsComplete OnlineSub"));
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION ::OnFindSessionsComplete Sessions.IsValid()"));
			Sessions->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);

			UE_LOG(LogTemp, Verbose, TEXT("Num Search Results: %d"), SearchSettings->SearchResults.Num());
			for (int32 SearchIdx = 0; SearchIdx < SearchSettings->SearchResults.Num(); SearchIdx++)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION ::OnFindSessionsComplete looping over results)"));
				const FOnlineSessionSearchResult& SearchResult = SearchSettings->SearchResults[SearchIdx];
				DumpSession(&SearchResult.Session);
			}

			OnFindSessionsComplete().Broadcast(bWasSuccessful);

		}
	}
}


void AMyGameSession::StartMatchmaking(TSharedPtr<const FUniqueNetId> UserId, FName SessionNameInc, FString matchType)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION StartMatchmaking"));
	// set our local player unique id.
	// this should only happen on client
	// this does not work becuase it's a const.
	// LocalPlayerUniqueId = UserId;
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION StartMatchmaking:  OnlineSub"));

		CurrentSessionParams.SessionName = SessionNameInc;
		CurrentSessionParams.bIsLAN = false;
		CurrentSessionParams.bIsPresence = false;
		UE_LOG(LogTemp, Log, TEXT("UserId: %s"), *UserId->ToString());
		CurrentSessionParams.UserId = UserId;

		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{

			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION StartMatchmaking:  Session Valid"));

			if (CurrentSessionParams.UserId.IsValid())
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION StartMatchmaking:  CurrentSessionParams.UserId Valid"));
				/*
				If this is failing, it is possible that you have an incorrect online subsystem loaded.
				Check your game.build.cs and make sure there aren't any stray online susbstems in there.
				*/

				SearchSettings = MakeShareable(new FMyOnlineSearchSettings(false, false));
				SearchSettings->QuerySettings.Set(SEARCH_KEYWORDS, matchType, EOnlineComparisonOp::Equals);
				TSharedRef<FOnlineSessionSearch> SearchSettingsRef = SearchSettings.ToSharedRef();
				FOnlineSessionSettings testSettings;
				//testSettings.Settings.Add("matchType");
				//SearchSettings->QuerySettings.Get("matchType", matchType);
				//testSettings.Set("matchType", matchType, EOnlineDataAdvertisementType::ViaOnlineService);


				// TODO we need to deal with the delegate handle still
				//OnFindSessionsCompleteDelegateHandle = Sessions->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);

				TArray<TSharedRef<const FUniqueNetId>> justASinglePlayer;
				//justASinglePlayer.Init(*CurrentSessionParams.UserId, 1);

				TSharedRef<const FUniqueNetId> UniqueIdRef = CurrentSessionParams.UserId.ToSharedRef();
				justASinglePlayer.Init(UniqueIdRef, 1);

				//const TArray < TSharedRef < const FUniqueNetId > > & LocalPlayers = CurrentSessionParams.UserId;

				Sessions->StartMatchmaking(justASinglePlayer, SessionNameInc, testSettings, SearchSettingsRef);
				// The below was for search


				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  1"));

				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  2"));


				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  3"));

				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  4"));
				//Sessions->FindSessions(*CurrentSessionParams.UserId, SearchSettingsRef);
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION StartMatchmaking:  Done"));
			}

		}

	}
	else
	{
		OnFindSessionsComplete(false);
	}
}


void AMyGameSession::CancelMatchmaking(TSharedPtr<const FUniqueNetId> UserId, FName SessionNameInc)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION CancelMatchmaking"));
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION CancelMatchmaking:  OnlineSub"));

		CurrentSessionParams.SessionName = SessionNameInc;
		CurrentSessionParams.bIsLAN = false;
		CurrentSessionParams.bIsPresence = false;
		UE_LOG(LogTemp, Log, TEXT("UserId: %s"), *UserId->ToString());
		CurrentSessionParams.UserId = UserId;

		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{

			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION CancelMatchmaking:  Session Valid"));

			if (CurrentSessionParams.UserId.IsValid())
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION CancelMatchmaking:  CurrentSessionParams.UserId Valid"));
				/*
				If this is failing, it is possible that you have an incorrect online subsystem loaded.
				Check your game.build.cs and make sure there aren't any stray online susbstems in there.
				*/

				// TODO we need to deal with the delegate handle still
				//OnFindSessionsCompleteDelegateHandle = Sessions->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);


				//const TArray < TSharedRef < const FUniqueNetId > > & LocalPlayers = CurrentSessionParams.UserId;
				Sessions->CancelMatchmaking(*UserId, SessionNameInc);

				//Sessions->FindSessions(*CurrentSessionParams.UserId, SearchSettingsRef);
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION CancelMatchmaking:  Done"));
			}

		}

	}
	else
	{
		//OnFindSessionsComplete(false);
	}
}

/**
* Delegate fired when a session create request has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void AMyGameSession::OnMatchmakingComplete(FName SessionNameIncoming, bool bWasSuccessful)
{
	//UE_LOG(LogOnlineGame, Verbose, TEXT("OnCreateSessionComplete %s bSuccess: %d"), *SessionName.ToString(), bWasSuccessful);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::OnMatchmakingComplete"));
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION OnMatchmakingComplete:  OnlineSub"));
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION OnMatchmakingComplete:  Sessions"));
			//IOnlineSession* MMSession = Sessions->GetNamedSession(SessionNameIncoming.ToString());
			//FOnlineSessionSettings* MMSessionSettings = Sessions->GetSessionSettings(SessionNameIncoming);

			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION OnMatchmakingComplete:  MMSessionSettings"));

			// Join
			// We're artificially inserting the search results.
			// Since there will only be one, just use index 0
			//get the playeruniqueid

			// Creating a local player where we can get the UserID from
			UMyGameInstance *gameInstance = Cast<UMyGameInstance>(this->GetGameInstance());
			ULocalPlayer* const Player = gameInstance->GetFirstGamePlayer();
			int32 sessionIndexinSearchResults = 0;

			// this changed in 4.20  - not returning the same type anymore
			//JoinSession(Player->GetPreferredUniqueNetId(), SessionNameIncoming, sessionIndexinSearchResults);
			FUniqueNetIdRepl playerNetId = Player->GetPreferredUniqueNetId();
			JoinSession(playerNetId.GetUniqueNetId(), SessionNameIncoming, sessionIndexinSearchResults);

			gameInstance->TravelToSession(0, SessionNameIncoming);

		}
	}
}

void AMyGameSession::FindSessions(TSharedPtr<const FUniqueNetId> UserId, FName SessionNameInc, bool bIsLAN, bool bIsPresence)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions"));
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  OnlineSub"));

		CurrentSessionParams.SessionName = SessionNameInc;
		CurrentSessionParams.bIsLAN = bIsLAN;
		CurrentSessionParams.bIsPresence = bIsPresence;
		CurrentSessionParams.UserId = UserId;

		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{

			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  Session Valid"));
			if (CurrentSessionParams.UserId.IsValid())
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  CurrentSessionParams.UserId Valid"));
				/*
				If this is failing, it is possible that you have an incorrect online subsystem loaded.
				Check your game.build.cs and make sure there aren't any stray online susbstems in there.
				*/


				SearchSettings = MakeShareable(new FMyOnlineSearchSettings(bIsLAN, bIsPresence));
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  1"));
				SearchSettings->QuerySettings.Set(SEARCH_KEYWORDS, CustomMatchKeyword, EOnlineComparisonOp::Equals);
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  2"));

				// Set userKeyId in SearchSettings so we can pass it through on FindSessions
				FName KeyUserKeyId = FName(TEXT("UserKeyId"));
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions UserId :%s"), *UserId->ToString());
				SearchSettings->QuerySettings.Set(KeyUserKeyId, UserId->ToString(), EOnlineComparisonOp::Equals);

				TSharedRef<FOnlineSessionSearch> SearchSettingsRef = SearchSettings.ToSharedRef();
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  3"));

				OnFindSessionsCompleteDelegateHandle = Sessions->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  4"));
				Sessions->FindSessions(*CurrentSessionParams.UserId, SearchSettingsRef);
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  Done"));
			}

		}

	}
	else
	{
		OnFindSessionsComplete(false);
	}
}

void AMyGameSession::FindSessions(FName SessionNameInc, bool bIsLAN, bool bIsPresence)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions"));
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  OnlineSub"));

		CurrentSessionParams.SessionName = SessionNameInc;
		CurrentSessionParams.bIsLAN = bIsLAN;
		CurrentSessionParams.bIsPresence = bIsPresence;
		//CurrentSessionParams.UserId = UserId;

		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			/*
			If this is failing, it is possible that you have an incorrect online subsystem loaded.
			Check your game.build.cs and make sure there aren't any stray online susbstems in there.
			*/

			SearchSettings = MakeShareable(new FMyOnlineSearchSettings(bIsLAN, bIsPresence));
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  1"));
			SearchSettings->QuerySettings.Set(SEARCH_KEYWORDS, CustomMatchKeyword, EOnlineComparisonOp::Equals);
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  2"));

			TSharedRef<FOnlineSessionSearch> SearchSettingsRef = SearchSettings.ToSharedRef();
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  3"));

			OnFindSessionsCompleteDelegateHandle = Sessions->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  4"));
			// testing passing 0 for userid.  Sessions comments says it's fine.
			Sessions->FindSessions(0, SearchSettingsRef);
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION FindSessions:  Done"));

		}

	}
	else
	{
		OnFindSessionsComplete(false);
	}
}

/**
* Delegate fired when a destroying an online session has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void AMyGameSession::OnDestroySessionComplete(FName SessionNameInc, bool bWasSuccessful)
{
	UE_LOG(LogOnlineGame, Verbose, TEXT("OnDestroySessionComplete %s bSuccess: %d"), *SessionNameInc.ToString(), bWasSuccessful);

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		Sessions->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegateHandle);
		HostSettings = NULL;
	}
}

/**
* Delegate fired when the joining process for an online session has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void AMyGameSession::OnJoinSessionComplete(FName SessionNameInc, EOnJoinSessionCompleteResult::Type Result)
{
	bool bWillTravel = false;

	UE_LOG(LogOnlineGame, Verbose, TEXT("OnJoinSessionComplete %s bSuccess: %d"), *SessionNameInc.ToString(), static_cast<int32>(Result));

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	IOnlineSessionPtr Sessions = NULL;
	if (OnlineSub)
	{
		Sessions = OnlineSub->GetSessionInterface();
		Sessions->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
	}

	OnJoinSessionComplete().Broadcast(Result);
}

bool AMyGameSession::JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionNameInc, int32 SessionIndexInSearchResults)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession 1"));
	bool bResult = false;
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession SessionIndexInSearchResults :%d"), SessionIndexInSearchResults);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession UserId :%s"), *UserId->ToString());
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession SearchSettings->SearchResults.Num() :%d"), SearchSettings->SearchResults.Num());

	if (SessionIndexInSearchResults >= 0 && SessionIndexInSearchResults < SearchSettings->SearchResults.Num())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession 1-2"));
		bResult = JoinSession(UserId, SessionNameInc, SearchSettings->SearchResults[SessionIndexInSearchResults]);
	}

	return bResult;
}

bool AMyGameSession::JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionNameInc, const FOnlineSessionSearchResult& SearchResult)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession 2"));
	bool bResult = false;

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession : OnelineSub"));
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession : Session valid"));
			if (UserId.IsValid())
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION JoinSession : UserId valid"));
				OnJoinSessionCompleteDelegateHandle = Sessions->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);
				bResult = Sessions->JoinSession(*UserId, SessionNameInc, SearchResult);
			}
		}
	}

	return bResult;
}

void AMyGameSession::RegisterServer() {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::RegisterServer"));
	UWorld* World = GetWorld();
	IOnlineSessionPtr SessionInt = Online::GetSessionInterface();

	FOnlineSessionSettings Settings;
	Settings.NumPublicConnections = 3;
	Settings.bShouldAdvertise = true;
	Settings.bAllowJoinInProgress = true;
	Settings.bIsLANMatch = true;
	Settings.bUsesPresence = true;
	Settings.bAllowJoinViaPresence = true;
	Settings.bIsDedicated = true;

	OnCreateSessionCompleteDelegateHandle = SessionInt->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);
	SessionInt->CreateSession(0, GameSessionName, Settings);

	// We want to get a session list built for server links.
	// Doing it here for now until a better place is found.

	/*

	MUTING THIS STUFF FOR NOW


	TSharedRef<FOnlineSessionSearch> SearchSettingsRef = SearchSettings.ToSharedRef();

	SessionInt->FindSessions(0, SearchSettingsRef);
	*/


	//OnCreateSessionCompleteDelegateHandle = Sessions->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);


	return;
}

void AMyGameSession::PostLogin(APlayerController* NewPlayer)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::PostLogin"));

	// Ask the client to provide the CurrentAccessTokenFromOSS
	// This does not work.
	AMyPlayerController* myPC = Cast<AMyPlayerController>(NewPlayer);
	myPC->ClientGetCurrentAccessTokenFromOSS();
}

FString AMyGameSession::ApproveLogin(const FString& Options)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameSession] ApproveLogin Options: %s"), *Options);
	UWorld* const World = GetWorld();
	check(World);

	AGameMode* const GameMode = Cast<AGameMode>(World->GetAuthGameMode());
	check(GameMode);

	int32 SpectatorOnly = 0;
	SpectatorOnly = UGameplayStatics::GetIntOption(Options, TEXT("SpectatorOnly"), SpectatorOnly);

	if (AtCapacity(SpectatorOnly == 1))
	{
		return TEXT("Server full.");
	}

	int32 SplitscreenCount = 0;
	SplitscreenCount = UGameplayStatics::GetIntOption(Options, TEXT("SplitscreenCount"), SplitscreenCount);

	if (SplitscreenCount > MaxSplitscreensPerConnection)
	{
		//UE_LOG(LogGameSession, Warning, TEXT("ApproveLogin: A maximum of %i splitscreen players are allowed"), MaxSplitscreensPerConnection);
		return TEXT("Maximum splitscreen players");
	}

	return TEXT("");
}

void AMyGameSession::RegisterPlayer(APlayerController* NewPlayer, const TSharedPtr<const FUniqueNetId>& UniqueId, bool bWasFromInvite)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::RegisterPlayer"));
	if (NewPlayer != NULL)
	{
		// Set the player's ID.
		check(NewPlayer->PlayerState);
		NewPlayer->PlayerState->PlayerId = GetNextPlayerID();
		NewPlayer->PlayerState->SetUniqueId(UniqueId);
		NewPlayer->PlayerState->RegisterPlayerWithSession(bWasFromInvite);

		int32 playerId = NewPlayer->PlayerState->PlayerId;
		//FString playerUniqueId = UniqueId->ToString(); // assertion fail

		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameSession] RegisterPlayer playerId: %d"), playerId);
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameSession] RegisterPlayer UniqueId: %s"), *UniqueId->ToString()); //assertionFail
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameSession] RegisterPlayer playerUniqueId: %s"), *playerUniqueId);  // assertion fail

		// Deprecated/Unused
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameSession] RegisterPlayer NewPlayer->PlayerState->PlayerName: %s"), *NewPlayer->PlayerState->PlayerName);




	}
}

void AMyGameSession::OnMatchmakingStartedComplete(FName matchType, bool success)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameSession::OnMatchmakingStartedComplete"));

	// Setting up a SearchSettings, because we need it later

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION OnMatchmakingStartedComplete:  OnlineSub"));

		CurrentSessionParams.SessionName = "matchmaker-tounament";
		CurrentSessionParams.bIsLAN = false;
		CurrentSessionParams.bIsPresence = false;
		OnlineSub->GetIdentityInterface()->GetUniquePlayerId(0);
		//UE_LOG(LogTemp, Log, TEXT("UserId: %s"), *UserId->ToString());
		CurrentSessionParams.UserId = OnlineSub->GetIdentityInterface()->GetUniquePlayerId(0);

		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{

			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION OnMatchmakingStartedComplete:  Session Valid"));

			if (CurrentSessionParams.UserId.IsValid())
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME SESSION OnMatchmakingStartedComplete:  CurrentSessionParams.UserId Valid"));
				/*
				If this is failing, it is possible that you have an incorrect online subsystem loaded.
				Check your game.build.cs and make sure there aren't any stray online susbstems in there.
				*/

				SearchSettings = MakeShareable(new FMyOnlineSearchSettings(false, false));
				//SearchSettings->QuerySettings.Set(SEARCH_KEYWORDS, matchType, EOnlineComparisonOp::Equals);
			}
		}
	}
}
