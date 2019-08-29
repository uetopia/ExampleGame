// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameSession.h"
#include "Online.h"
#include "Internationalization.h"
#include "MyGameSession.generated.h"


struct FMyGameSessionParams
{
	/** Name of session settings are stored with */
	FName SessionName;
	/** LAN Match */
	bool bIsLAN;
	/** Presence enabled session */
	bool bIsPresence;
	/** Id of player initiating lobby */
	TSharedPtr<const FUniqueNetId> UserId;
	/** Current search result choice to join */
	int32 BestSessionIdx;

	FMyGameSessionParams()
		: SessionName(NAME_None)
		, bIsLAN(false)
		, bIsPresence(false)
		, BestSessionIdx(0)
	{
	}
};

/**
*
*/
UCLASS()
class EXAMPLEGAME_API AMyGameSession : public AGameSession
{
	GENERATED_BODY()


		AMyGameSession(const FObjectInitializer& ObjectInitializer);

	/**
	* Called by GameMode::PostLogin to give session code chance to do work after PostLogin
	*
	* @param NewPlayer player logging in
	*/
	virtual void PostLogin(APlayerController* NewPlayer);

	/**
	* Called from GameMode.PreLogin() and Login().
	* @param	Options	The URL options (e.g. name/spectator) the player has passed
	* @return	Non-empty Error String if player not approved
	*/
	virtual FString ApproveLogin(const FString& Options);

	/**
	* Register a player with the online service session
	* @param NewPlayer player to register
	* @param UniqueId uniqueId they sent over on Login
	* @param bWasFromInvite was this from an invite
	*/
	virtual void RegisterPlayer(APlayerController* NewPlayer, const TSharedPtr<const FUniqueNetId>& UniqueId, bool bWasFromInvite);

private:
	//TSharedPtr<const FUniqueNetId>& LocalPlayerUniqueId;
protected:



	/** Delegate for searching for sessions */
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	/** Delegate after joining a session */
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	/** Delegate for creating a new session */
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	/** Delegate after starting a session */
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	/** Delegate for destroying a session */
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;

	/** Delegate for MATCHMAKER STARTED */
	FOnMatchmakingStartedDelegate OnMatchmakingStartedDelegate;
	/** Delegate for MATCHMAKER COMPLETED */
	FOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate;

	/** Transient properties of a session during game creation/matchmaking */
	FMyGameSessionParams CurrentSessionParams;

	/** Current host settings */
	TSharedPtr<class FShooterOnlineSessionSettings> HostSettings;
	/** Current search settings */
	// Note:  Search Results are also stored inside SearchSettings - which is a little strange.
	// SearchSettings->SearchResults;
	// SearchResults are FOnlineSessionSearchResult
	TSharedPtr<class FMyOnlineSearchSettings> SearchSettings;

	/**
	* Delegate fired when a session create request has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	/**
	* Delegate fired when a session search query has completed
	*
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	void OnFindSessionsComplete(bool bWasSuccessful);
	/**
	* Delegate fired when a session join request has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	/**
	* Delegate fired when a destroying an online session has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

	// Handle incoming Matchmaker Started notifications
	void OnMatchmakingStartedComplete(FName matchType, bool success);


	/**
	* Delegate fired when a destroying an online session has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnMatchmakingComplete(FName SessionName, bool bWasSuccessful);


	/*
	* Event triggered after session search completes
	*/
	//DECLARE_EVENT(AShooterGameSession, FOnFindSessionsComplete);
	DECLARE_EVENT_OneParam(AMyGameSession, FOnFindSessionsComplete, bool /*bWasSuccessful*/);
	FOnFindSessionsComplete FindSessionsCompleteEvent;
	/*
	* Event triggered when a presence session is created
	*
	* @param SessionName name of session that was created
	* @param bWasSuccessful was the create successful
	*/
	DECLARE_EVENT_TwoParams(AMyGameSession, FOnCreatePresenceSessionComplete, FName /*SessionName*/, bool /*bWasSuccessful*/);
	FOnCreatePresenceSessionComplete CreatePresenceSessionCompleteEvent;

	/*
	* Event triggered when a presence session is created
	*
	* @param SessionName name of session that was created
	* @param bWasSuccessful was the create successful
	*/
	//DECLARE_EVENT_TwoParams(AMyGameSession, FOnCreateSessionComplete, FName /*SessionName*/, bool /*bWasSuccessful*/);
	//FOnCreateSessionComplete CreateSessionCompleteEvent;


	/*
	* Event triggered when a session is joined
	*
	* @param SessionName name of session that was joined
	* @param bWasSuccessful was the create successful
	*/
	//DECLARE_DELEGATE_RetVal_TwoParams(bool, FOnJoinSessionComplete, FName /*SessionName*/, bool /*bWasSuccessful*/);
	DECLARE_EVENT_OneParam(AMyGameSession, FOnJoinSessionComplete, EOnJoinSessionCompleteResult::Type /*Result*/);
	FOnJoinSessionComplete JoinSessionCompleteEvent;


public:
	/** Default number of players allowed in a game */
	static const int32 DEFAULT_NUM_PLAYERS = 8;

	/**
	* Start Matchmaking
	*
	* @param UserId user that initiated the request
	* @param SessionName name of session this search will generate
	* @param bIsLAN are we searching LAN matches
	* @param bIsPresence are we searching presence sessions
	*/
	void StartMatchmaking(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, FString matchType);
	void CancelMatchmaking(TSharedPtr<const FUniqueNetId> UserId, FName SessionName);

	/**
	* Find an online session
	*
	* @param UserId user that initiated the request
	* @param SessionName name of session this search will generate
	* @param bIsLAN are we searching LAN matches
	* @param bIsPresence are we searching presence sessions
	*/
	void FindSessions(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence);
	// we need one for serverside too, where we don't care about the user
	// I dont think we're actually using this.  Check and delete.  TODO
	void FindSessions(FName SessionName, bool bIsLAN, bool bIsPresence);
	/**
	* Joins one of the session in search results
	*
	* @param UserId user that initiated the request
	* @param SessionName name of session
	* @param SessionIndexInSearchResults Index of the session in search results
	*
	* @return bool true if successful, false otherwise
	*/
	bool JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, int32 SessionIndexInSearchResults);
	/**
	* Joins a session via a search result
	*
	* @param SessionName name of session
	* @param SearchResult Session to join
	*
	* @return bool true if successful, false otherwise
	*/
	bool JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, const FOnlineSessionSearchResult& SearchResult);

	/**
	* Get the search results found and the current search result being probed
	*
	* @param SearchResultIdx idx of current search result accessed
	* @param NumSearchResults number of total search results found in FindGame()
	*
	* @return State of search result query
	*/
	EOnlineAsyncTaskState::Type GetSearchResultStatus(int32& SearchResultIdx, int32& NumSearchResults);

	/**
	* Get the search results.
	*
	* @return Search results
	*/
	const TArray<FOnlineSessionSearchResult> & GetSearchResults() const;

	/** @return the delegate fired when search of session completes */
	FOnFindSessionsComplete& OnFindSessionsComplete() { return FindSessionsCompleteEvent; }
	/** @return the delegate fired when joining a session */
	FOnJoinSessionComplete& OnJoinSessionComplete() { return JoinSessionCompleteEvent; }

	/** @return the delegate fired when creating a presence session */
	FOnCreatePresenceSessionComplete& OnCreatePresenceSessionComplete() { return CreatePresenceSessionCompleteEvent; }
	/** @return the delegate fired when creating a session */
	//FOnCreateSessionComplete& OnCreateSessionComplete() { return CreateSessionCompleteEvent; }

	//virtual void RegisterServer();

	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	FDelegateHandle OnMatchmakingCompleteDelegateHandle;

	virtual void RegisterServer();


};
