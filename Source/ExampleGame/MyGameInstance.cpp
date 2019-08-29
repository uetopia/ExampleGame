// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "ProMMO.h"
#include "MyGameState.h"
#include "MyGameMode.h"
#include "MyGameSession.h"
#include "MyPlayerState.h"
#include "MyPlayerController.h"
#include "UEtopiaPersistCharacter.h"
//#include "MyServerPortalActor.h"
#include "MyBaseGameplayAbility.h"
#include "MyTravelApprovedActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "MyRewardItemActor.h"



typedef TSharedPtr<FJsonValue> JsonValPtr;
typedef TArray<JsonValPtr> JsonValPtrArray;


namespace MyGameInstanceState
{
	const FName None = FName(TEXT("None"));
	const FName PendingInvite = FName(TEXT("PendingInvite"));
	const FName WelcomeScreen = FName(TEXT("WelcomeScreen"));
	const FName MainMenu = FName(TEXT("MainMenu"));
	const FName MessageMenu = FName(TEXT("MessageMenu"));
	const FName Playing = FName(TEXT("Playing"));
}

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bIsOnline(true) // Default to online
	, bIsLicensed(true) // Default to licensed (should have been checked by OS on boot)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE CONSTRUCTOR"));
	CurrentState = MyGameInstanceState::None;

	//Trying to see if some kind of init is needed
	// does not seem to make a difference
	//PlayerRecord.ActivePlayers.Init();

	ServerSessionHostAddress = NULL;
	ServerSessionID = NULL;

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE INIT"));

	if (!GConfig) return;

	_configPath = FPaths::SourceConfigDir();
	_configPath += TEXT("UEtopiaConfig.ini");
	// This is deceiving because it looks like we're loading these settings from the UEtopiaConfig.ini config file,
	// but really it's loading from DefaultGame.ini

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] set up path"));


	GConfig->GetString(
		TEXT("UEtopia.Client"),
		TEXT("UEtopiaMode"),
		UEtopiaMode,
		GGameIni
		);

	GConfig->GetString(
		TEXT("UEtopia.Client"),
		TEXT("APIURL"),
		APIURL,
		GGameIni
		);

	GConfig->GetString(
		TEXT("UEtopia.Client"),
		TEXT("ServerSecret"),
		ServerAPISecret,
		GGameIni
		);

	GConfig->GetString(
		TEXT("UEtopia.Client"),
		TEXT("ServerAPIKey"),
		ServerAPIKey,
		GGameIni
		);

	GConfig->GetString(
		TEXT("UEtopia.Client"),
		TEXT("GameKey"),
		GameKey,
		GGameIni
		);

	GConfig->GetBool(
		TEXT("UEtopia.Client"),
		TEXT("CharactersEnabled"),
		UEtopiaCharactersEnabled,
		GGameIni
	);

	bRequestBeginPlayStarted = false;

	// set up our reward spawning values
	bSpawnRewardsEnabled = false;
	SpawnRewardServerMinimumBalanceRequired = 100000;
	SpawnRewardChance = .50f;
	SpawnRewardValue = 250;
	SpawnRewardTimerSeconds = 30.0f;

	SpawnRewardLocationXMin = -1610.0f;
	SpawnRewardLocationXMax = 1000.0f;
	SpawnRewardLocationYMin = -1350.0f;
	SpawnRewardLocationYMax = 1350.0f;
	SpawnRewardLocationZMin = 130.0f;
	SpawnRewardLocationZMax = 1350.0f;

	CubeStoreCost = 100;

	// THis happens in gamemode now.
	//MinimumKillsBeforeResultsSubmit = 3; // When a player has a score of x, submit match results
	//RoundWinsNeededToWinMatch = 3; // when a team wins 3 rounds submit match results

	metaMatchCustom = "";


	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE CONSTRUCTOR - DONE"));
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE INIT"));

	//IgnorePairingChangeForControllerId = -1;
	CurrentConnectionStatus = EOnlineServerConnectionStatus::Connected;

	// game requires the ability to ID users.
	const auto OnlineSub = IOnlineSubsystem::Get();
	check(OnlineSub);
	const auto IdentityInterface = OnlineSub->GetIdentityInterface();
	check(IdentityInterface.IsValid());

	const auto SessionInterface = OnlineSub->GetSessionInterface();
	check(SessionInterface.IsValid());

	const auto FriendsInterface = OnlineSub->GetFriendsInterface();
	check(FriendsInterface.IsValid());

	// bind any OSS delegates we need to handle
	for (int i = 0; i < MAX_LOCAL_PLAYERS; ++i)
	{
		IdentityInterface->AddOnLoginStatusChangedDelegate_Handle(i, FOnLoginStatusChangedDelegate::CreateUObject(this, &UMyGameInstance::HandleUserLoginChanged));
		IdentityInterface->AddOnLoginCompleteDelegate_Handle(i, FOnLoginCompleteDelegate::CreateUObject(this, &UMyGameInstance::HandleUserLoginComplete));
	}

	SessionInterface->AddOnSessionFailureDelegate_Handle(FOnSessionFailureDelegate::CreateUObject(this, &UMyGameInstance::HandleSessionFailure));

	OnEndSessionCompleteDelegate = FOnEndSessionCompleteDelegate::CreateUObject(this, &UMyGameInstance::OnEndSessionComplete);

	GetWorld()->GetTimerManager().SetTimer(ServerLinksTimerHandle, this, &UMyGameInstance::GetServerLinks, 20.0f, true);

	// Set up a timer to submit kills and stats to the backend if this is a continuous server
	// This should be anywhere from a minute to 15 minutes, depending on game load.
	if (UEtopiaMode == "continuous")
	{
		GetWorld()->GetTimerManager().SetTimer(SubmitReportTimerHandle, this, &UMyGameInstance::SubmitReport, 60.0f, true);
	}
	


	MatchStarted = false;

}

AMyGameSession* UMyGameInstance::GetGameSession() const
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::GetGameSession"));
	UWorld* const World = GetWorld();
	if (World)
	{
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] World Found"));
		AGameMode* const Game = Cast<AGameMode>(World->GetAuthGameMode());
		if (Game)
		{
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] Game Found"));
			return Cast<AMyGameSession>(Game->GameSession);
		}
	}

	return nullptr;
}

bool UMyGameInstance::PerformHttpRequest(void(UMyGameInstance::*delegateCallback)(FHttpRequestPtr, FHttpResponsePtr, bool), FString APIURI, FString ArgumentString, FString AccessToken)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] PerformHttpRequest"));

	FHttpModule* Http = &FHttpModule::Get();
	if (!Http) { return false; }
	if (!Http->IsHttpEnabled()) { return false; }

	FString TargetHost = "http://" + APIURL + APIURI;

	//UE_LOG(LogTemp, Log, TEXT("TargetHost: %s"), *TargetHost);
	//UE_LOG(LogTemp, Log, TEXT("ServerAPIKey: %s"), *ServerAPIKey);
	//UE_LOG(LogTemp, Log, TEXT("ServerAPISecret: %s"), *ServerAPISecret);

	TSharedRef < IHttpRequest > Request = Http->CreateRequest();
	Request->SetVerb("POST");
	Request->SetURL(TargetHost);
	Request->SetHeader("User-Agent", "UETOPIA_UE4_API_CLIENT/1.0");
	Request->SetHeader("Content-Type", "application/x-www-form-urlencoded");
	Request->SetHeader("Key", ServerAPIKey);
	Request->SetHeader("Sign", "RealSignatureComingIn411");

	if (!AccessToken.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] PerformHttpRequest AccessToken: %s "), *AccessToken);
		Request->SetHeader(TEXT("x-uetopia-auth"), AccessToken);
	}

	Request->SetContentAsString(ArgumentString);

	Request->OnProcessRequestComplete().BindUObject(this, delegateCallback);
	if (!Request->ProcessRequest()) { return false; }

	return true;
}

bool UMyGameInstance::PerformJsonHttpRequest(void(UMyGameInstance::*delegateCallback)(FHttpRequestPtr, FHttpResponsePtr, bool), FString APIURI, FString ArgumentString, FString AccessToken)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] PerformHttpRequest"));

	FHttpModule* Http = &FHttpModule::Get();
	if (!Http) { return false; }
	if (!Http->IsHttpEnabled()) { return false; }

	FString TargetHost = "http://" + APIURL + APIURI;

	UE_LOG(LogTemp, Log, TEXT("TargetHost: %s"), *TargetHost);
	//UE_LOG(LogTemp, Log, TEXT("ServerAPIKey: %s"), *ServerAPIKey);
	//UE_LOG(LogTemp, Log, TEXT("ServerAPISecret: %s"), *ServerAPISecret);

	TSharedRef < IHttpRequest > Request = Http->CreateRequest();
	Request->SetVerb("POST");
	Request->SetURL(TargetHost);
	Request->SetHeader("User-Agent", "UETOPIA_UE4_API_CLIENT/1.0");
	//Request->SetHeader("Content-Type", "application/x-www-form-urlencoded");
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));
	Request->SetHeader("Key", ServerAPIKey);
	Request->SetHeader("Sign", "RealSignatureComingIn411");

	if (!AccessToken.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] PerformHttpRequest AccessToken: %s "), *AccessToken);
		Request->SetHeader(TEXT("x-uetopia-auth"), AccessToken);
	}

	Request->SetContentAsString(ArgumentString);

	Request->OnProcessRequestComplete().BindUObject(this, delegateCallback);
	if (!Request->ProcessRequest()) { return false; }

	return true;
}

bool UMyGameInstance::GetServerInfo()
{

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] GetServerInfo"));
	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.
	FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;

	if (ServerSessionHostAddress.Len() > 1) {
		//UE_LOG(LogTemp, Log, TEXT("ServerSessionHostAddress: %s"), *ServerSessionHostAddress);
		//UE_LOG(LogTemp, Log, TEXT("ServerSessionID: %s"), *ServerSessionID);
		OutputString = OutputString + "&session_host_address=" + ServerSessionHostAddress + "&session_id=" + ServerSessionID;
	}
	FString APIURI = "/api/v1/server/info";
	bool requestSuccess = PerformHttpRequest(&UMyGameInstance::GetServerInfoComplete, APIURI, OutputString, ""); // No AccessToken
	return requestSuccess;
}

void UMyGameInstance::GetServerInfoComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				// Set up our instance variables

				if (JsonParsed->GetIntegerField("incrementCurrency")) {
					incrementCurrency = JsonParsed->GetIntegerField("incrementCurrency");
				}
				if (JsonParsed->GetIntegerField("minimumCurrencyRequired")) {
					minimumCurrencyRequired = JsonParsed->GetIntegerField("minimumCurrencyRequired");
				}
				if (JsonParsed->GetIntegerField("serverCurrency")) {
					serverCurrency = JsonParsed->GetIntegerField("serverCurrency");
				}

				ServerTitle = JsonParsed->GetStringField("title");

				FString GameLevel = JsonParsed->GetStringField("gameLevel");
				if (GameLevel != "unknown")
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetServerInfoComplete] Travelling to: %s"), *GameLevel);
					GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;
					GetWorld()->ServerTravel(GameLevel);
				}

				FString ServerTime = JsonParsed->GetStringField("serverTime");

				bool convertsuccess = UKismetMathLibrary::DateTimeFromIsoString(ServerTime, ServerStartDateTime);

				float sunRotation = 180.0f;

				if (convertsuccess) {
					UE_LOG(LogTemp, Log, TEXT("serverTime Converted"));

					sunRotation = (ServerStartDateTime.GetHour() * 15.0f) + (ServerStartDateTime.GetMinute() * 0.25f);
				}

				FString ServerLastRunTime = JsonParsed->GetStringField("last_running_timestamp");
				bool convertsuccess2 = UKismetMathLibrary::DateTimeFromIsoString(ServerLastRunTime, ServerLastRunningDateTime);

				// TODO - do things here with your datetime variables.  You now know how much time has elapsed since the server was online last.

				AGameState* gameState = Cast<AGameState>(GetWorld()->GetGameState());
				AMyGameState* uetopiaGameState = Cast<AMyGameState>(gameState);
				//AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);
				uetopiaGameState->serverTitle = ServerTitle;
				uetopiaGameState->sunAngle = sunRotation;

				if (JsonParsed->GetBoolField("sharded")) {
					UE_LOG(LogTemp, Log, TEXT("Found Sharded Server."));
					bIsShardedServer = JsonParsed->GetBoolField("sharded");
				}


				if (JsonParsed->HasField("custom_in_game_texture")) {
					FString custom_in_game_texture = JsonParsed->GetStringField("custom_in_game_texture");
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetServerInfoComplete] custom_in_game_texture: %s"), *custom_in_game_texture);
					// set custom texture
					customTexture = custom_in_game_texture;
				}

				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetServerInfoComplete] ServerTitle: %s"), *ServerTitle);

				// Get our custom configuration field here.  This is just a json formatted text field,
				// so you can do whatever you want here.
				// As an example, we're going to read and write an int which will set the maximum numer of pickup items which can be dropped on this server.
				// This allows private and group instances (my vault, guild hall) to have a low default value, and accept upgrades via in-game events like crafting, or microtransactions
				bool ConfigurationParseSuccess = false;

				if (JsonParsed->HasField("configuration")) {
					FString configuration = JsonParsed->GetStringField("configuration");
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetServerInfoComplete] configuration: %s"), *configuration);

					// If it fails or does not make sense, set it to a default value
					FString ConfigurationJsonRaw = configuration;
					TSharedPtr<FJsonObject> ConfigurationJsonParsed;
					TSharedRef<TJsonReader<TCHAR>> ConfigurationJsonReader = TJsonReaderFactory<TCHAR>::Create(ConfigurationJsonRaw);
					//const JsonValPtrArray *ConfigurationJson;

					if (FJsonSerializer::Deserialize(ConfigurationJsonReader, ConfigurationJsonParsed))
					{
						UE_LOG(LogTemp, Log, TEXT("ConfigurationJsonParsed"));
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetServerInfoComplete] ConfigurationJsonRaw: %s"), *ConfigurationJsonRaw);

						ConfigurationParseSuccess = ConfigurationJsonParsed->TryGetNumberField("maxPickupItemCount", maxPickupItemCount);
						ConfigurationParseSuccess = ConfigurationJsonParsed->TryGetBoolField("combatEnabled", combatEnabled);
					}

				}
				if (!ConfigurationParseSuccess)
				{
					UE_LOG(LogTemp, Log, TEXT("ConfigurationJson NOT Parsed - setting default values"));
					maxPickupItemCount = 25;
					combatEnabled = true;
				}



			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization False"));
			}
		}
	}

	// pull down the list of game data objects if any - just testing
	FString cursor = "";
	QueryGameDataList(cursor);
	QueryGameData(GameKey);

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetServerInfoComplete] Done!"));
}


bool UMyGameInstance::GetMatchInfo()
{

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] GetMatchInfo"));
	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.
	FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;

	if (ServerSessionHostAddress.Len() > 1) {
		//UE_LOG(LogTemp, Log, TEXT("ServerSessionHostAddress: %s"), *ServerSessionHostAddress);
		//UE_LOG(LogTemp, Log, TEXT("ServerSessionID: %s"), *ServerSessionID);
		OutputString = OutputString + "&session_host_address=" + ServerSessionHostAddress + "&session_id=" + ServerSessionID;
	}
	FString APIURI = "/api/v1/matchmaker/info";
	bool requestSuccess = PerformHttpRequest(&UMyGameInstance::GetMatchInfoComplete, APIURI, OutputString, ""); // No AccessToken
	return requestSuccess;
}

void UMyGameInstance::GetMatchInfoComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				// Set up our instance variables

				if (JsonParsed->GetIntegerField("admissionFee")) {
					admissionFee = JsonParsed->GetIntegerField("admissionFee");
				}


				// Put all of our player information in our MatchInfo TArray

				FJsonObjectConverter::JsonObjectStringToUStruct<FMyMatchInfo>(
					JsonRaw,
					&MatchInfo,
					0, 0);

				// Put replicated data in game state
				AGameState* gameState = Cast<AGameState>(GetWorld()->GetGameState());
				AMyGameState* uetopiaGameState = Cast<AMyGameState>(gameState);

				// Also build out the team struct for display purposes
				// Empty anything that might have been there
				uetopiaGameState->TeamList.teams.Empty();
				// First, we need to know how many teams there are

				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] Building Team list"));
				for (int32 b = 0; b < MatchInfo.players.Num(); b++) {
					if (teamCount < MatchInfo.players[b].teamId) {
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] Found team with higher Id"));
						teamCount = MatchInfo.players[b].teamId;
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] teamCount %d"), teamCount);
					}
				}

				// Then, we can start to build the struct, by team.
				// b is our team index
				for (int32 b = 0; b <= teamCount; b++) {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] Found team %d"), b);
					FMyTeamInfo thisTeam;
					// Get the players that are in this team
					// TODO make this a function instead
					for (int32 i = 0; i < MatchInfo.players.Num(); i++) {
						if (b == MatchInfo.players[i].teamId) {
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] Found player in this team"));
							thisTeam.players.Add(MatchInfo.players[i]);
							thisTeam.number = MatchInfo.players[i].teamId;
							thisTeam.title = MatchInfo.players[i].teamTitle;
							thisTeam.roundWinCount = 0;
						}
					}

					// add the team to both game instance and game state
					TeamList.teams.Add(thisTeam);
					uetopiaGameState->TeamList.teams.Add(thisTeam);
				}

				// set the number of kills required to end the game
				// TODO change this to rounds needed to win - this could come out a tie
				// DEPRECATED - This happens in gameMode now
				//MinimumKillsBeforeResultsSubmit = static_cast<int>((float)(MatchInfo.players.Num()) * 1.5);
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] MinimumKillsBeforeResultsSubmit: %d"), MinimumKillsBeforeResultsSubmit);


				MatchTitle = JsonParsed->GetStringField("title");

				uetopiaGameState->MatchTitle = MatchTitle;
				uetopiaGameState->bCombatEnabled = true;
				combatEnabled = true;

				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] MatchTitle: %s"), *MatchTitle);

			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization False"));
			}
		}
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetMatchInfo] Done!"));
}

void  UMyGameInstance::GetServerLinks()
{
	if (IsRunningDedicatedServer()) {
		if (bRequestBeginPlayStarted) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] GetServerLinks"));
			FString nonceString = "10951350917635";
			FString encryption = "off";  // Allowing unencrypted on sandbox for now.
			FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;
			FString APIURI = "/api/v1/server/links";
			bool requestSuccess = PerformHttpRequest(&UMyGameInstance::GetServerLinksComplete, APIURI, OutputString, ""); // No AccessToken
		}
	}
}

void UMyGameInstance::GetServerLinksComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Test failed. NULL response"));
	}
	else
	{
		//UE_LOG(LogTemp, Log, TEXT("Completed test [%s] Url=[%s] Response=[%d] [%s]"),
		//	*HttpRequest->GetVerb(),
		//	*HttpRequest->GetURL(),
		//	HttpResponse->GetResponseCode(),
		//	*HttpResponse->GetContentAsString());

		const FString JsonRaw = *HttpResponse->GetContentAsString();

		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			bool Authorization = JsonParsed->GetBoolField("authorization");
			//UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				//UE_LOG(LogTemp, Log, TEXT("Authorization True"));

				// parse JSON into game instance
				bool jsonConvertSuccess = FJsonObjectConverter::JsonObjectStringToUStruct<FMyServerLinks>(*JsonRaw, &ServerLinks, 0, 0);

				if (jsonConvertSuccess) {
					//UE_LOG(LogTemp, Log, TEXT("jsonConvertSuccess"));
				}
				else {
					//UE_LOG(LogTemp, Log, TEXT("jsonConvertFAIL"));
				}

				/*
				UE_LOG(LogTemp, Log, TEXT("Found %d Server Links"), ServerLinks.links.Num());
				for (int32 b = 0; b < ServerLinks.links.Num(); b++)
				{
				UE_LOG(LogTemp, Log, TEXT("targetServerTitle: %s"), *ServerLinks.links[b].targetServerTitle);
				UE_LOG(LogTemp, Log, TEXT("hostConnectionLink: %s"), *ServerLinks.links[b].hostConnectionLink);

				}
				*/

				// update the game state with the shard list
				AMyGameState* const MyGameState = GetWorld() != NULL ? GetWorld()->GetGameState<AMyGameState>() : NULL;
				MyGameState->ServerShards = ServerLinks.shards;


			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization False"));
			}
		}
	}
	SpawnServerPortals();
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetServerLinksComplete] Done!"));
}

bool UMyGameInstance::ActivatePlayer(class AMyPlayerController* NewPlayerController, FString playerKeyId, int32 playerID, const FUniqueNetIdRepl& UniqueId)
{

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] ActivatePlayer"));
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DEBUG TEST"));

	// check to see if this player is in the active list already
	bool playerKeyIdFound = false;
	int32 ActivePlayerIndex = 0;

	// Normally, here we have a new player connecting
	// We don't have the unreal engine playerID yet.  Not sure why this is...  TODO investigate
	// So, we're going to store the player's playerKeyId in the player state itself.
	// This way we can iterate over the player controllers at a later stage, and check for the playerKeyID

	// Stick the playerKeyID in the playerState so we can find this player later.
	APlayerState* thisPlayerState = NewPlayerController->PlayerState;
	AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);
	playerS->playerKeyId = playerKeyId;

	// Reset the currency back to zero, in case it's not.
	playerS->Currency = 0;

	// And set combatEnabled
	playerS->bCombatEnabled = combatEnabled;

	// Start the custom texture loading asap.
	// Can't actually do this here because we are still in the lobby level and will travel to map level soon.
	// trying to do it on player state instead
	//playerS->customTextures = customTextures;

	if (UEtopiaMode == "competitive") {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - Mode set to competitive"));

		// on competitive, if a connecting player is not in the matchInfo, just kick them.

		FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(playerKeyId);

		if (ActivePlayer)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - Found ActivePlayer"));

			ActivePlayer->PlayerController = NewPlayerController;
			ActivePlayer->bIsConnected = true;
			ActivePlayer->gamePlayerDataLoaded = false;

			if (UEtopiaCharactersEnabled)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - UEtopiaCharactersEnabled"));

				ActivePlayer->characterCustomized = false;
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - UEtopiaCharacters NOT Enabled "));
				ActivePlayer->characterCustomized = true;
			}

			FString access_token = NewPlayerController->CurrentAccessTokenFromOSS;
			FString nonceString = "10951350917635";
			FString encryption = "off";  // Allowing unencrypted on sandbox for now.
			FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;
			FString APIURI = "/api/v1/match/player/" + playerKeyId + "/activate";;

			bool requestSuccess = PerformHttpRequest(&UMyGameInstance::ActivateMatchPlayerRequestComplete, APIURI, OutputString, access_token);

			return requestSuccess;
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - playerKeyId NOT found in matchInfo- TODO kick"));
		}

		// old way
		/*
		for (int32 b = 0; b < MatchInfo.players.Num(); b++)
		{

			if (MatchInfo.players[b].playerKeyId == playerKeyId) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - FOUND MATCHING playerKeyId"));
				playerKeyIdFound = true;
				ActivePlayerIndex = b;

				MatchInfo.players[b].PlayerController = NewPlayerController;

				if (UEtopiaCharactersEnabled)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - UEtopiaCharactersEnabled"));
					MatchInfo.players[b].characterCustomized = false;
					MatchInfo.players[b].gamePlayerDataLoaded = false;
					MatchInfo.players[b].bIsConnected = true;
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - UEtopiaCharacters NOT Enabled "));
					MatchInfo.players[b].characterCustomized = true;
					MatchInfo.players[b].gamePlayerDataLoaded = false;
					MatchInfo.players[b].bIsConnected = true;
				}
			}
		}

		if (playerKeyIdFound == false) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - playerKeyId NOT found in matchInfo- TODO kick"));
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - playerKeyId found in matchInfo"));
			FString access_token = NewPlayerController->CurrentAccessTokenFromOSS;
			FString nonceString = "10951350917635";
			FString encryption = "off";  // Allowing unencrypted on sandbox for now.
			FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;

			FString APIURI = "/api/v1/match/player/" + playerKeyId + "/activate";;

			bool requestSuccess = PerformHttpRequest(&UMyGameInstance::ActivateMatchPlayerRequestComplete, APIURI, OutputString, access_token);

			return requestSuccess;
		}

		*/

	}
	else {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - Mode set to continuous"));

		// REDOING THIS
		// FOR Continuous, there is no premade player list.
		// we want to allow players, and authorize them.
		// only using active players from now on.  Move the matchPlayers.

		FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(playerKeyId);

		if (ActivePlayer)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - Found ActivePlayer"));

			ActivePlayer->playerID = playerID;
			ActivePlayer->PlayerController = NewPlayerController;
			ActivePlayer->bIsConnected = true;

			// If it is already authorized, Don't resend the http request
			if (ActivePlayer->authorized)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - update existing record - it is already authorized."));
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - update existing record - it is NOT already authorized."));
				FString nonceString = "10951350917635";
				FString encryption = "off";  // Allowing unencrypted on sandbox for now.
				FString access_token = NewPlayerController->CurrentAccessTokenFromOSS;

				FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;

				//UE_LOG(LogTemp, Log, TEXT("ServerSessionHostAddress: %s"), *ServerSessionHostAddress);
				//UE_LOG(LogTemp, Log, TEXT("ServerSessionID: %s"), *ServerSessionID);

				if (ServerSessionHostAddress.Len() > 1) {
					OutputString = OutputString + "&session_host_address=" + ServerSessionHostAddress + "&session_id=" + ServerSessionID;
				}

				FString APIURI = "/api/v1/server/player/" + playerKeyId + "/activate";;

				bool requestSuccess = PerformHttpRequest(&UMyGameInstance::ActivateRequestComplete, APIURI, OutputString, access_token);

				return requestSuccess;
			}
			return true;

		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AuthorizePlayer - Did not find ActiveMatchPlayer"));

			// Add a new one as authorized = false
			FMyActivePlayer activeplayer;

			activeplayer.playerID = playerID; // UE internal player reference
			activeplayer.userKeyId = playerKeyId; // UEtopia player reference
													//activeplayer.playerKeyId = nullptr;
			activeplayer.playerTitle = nullptr;
			activeplayer.authorized = false;
			activeplayer.roundDeaths = 0;
			activeplayer.roundKills = 0;
			//activeplayer.killed = nullptr;
			activeplayer.rank = 1600;
			activeplayer.currencyCurrent = 10;
			activeplayer.gamePlayerKeyId = nullptr;
			activeplayer.UniqueId = UniqueId;
			activeplayer.PlayerController = NewPlayerController;
			activeplayer.bIsConnected = true;

			MatchInfo.players.Add(activeplayer);

			// Run the http request to authorize on the backend
			UE_LOG(LogTemp, Log, TEXT("CurrentAccessTokenFromOSS: %s"), *NewPlayerController->CurrentAccessTokenFromOSS);
			FString access_token = NewPlayerController->CurrentAccessTokenFromOSS;

			FString nonceString = "10951350917635";
			FString encryption = "off";  // Allowing unencrypted on sandbox for now.  

			FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;

			//UE_LOG(LogTemp, Log, TEXT("ServerSessionHostAddress: %s"), *ServerSessionHostAddress);
			//UE_LOG(LogTemp, Log, TEXT("ServerSessionID: %s"), *ServerSessionID);

			if (ServerSessionHostAddress.Len() > 1) {
				OutputString = OutputString + "&session_host_address=" + ServerSessionHostAddress + "&session_id=" + ServerSessionID;
			}

			FString APIURI = "/api/v1/server/player/" + playerKeyId + "/activate";;

			bool requestSuccess = PerformHttpRequest(&UMyGameInstance::ActivateRequestComplete, APIURI, OutputString, access_token);

			return requestSuccess;
		}
	}
	return false;

}

void UMyGameInstance::ActivateRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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

		APlayerController* pc = NULL;
		//int32 playerstateID;

		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));

				// get the player record
				FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(JsonParsed->GetStringField("player_userid"));

				bool PlayerAuthorized = JsonParsed->GetBoolField("player_authorized");
				if (PlayerAuthorized) {
					UE_LOG(LogTemp, Log, TEXT("Player Authorized"));

					int32 activeAuthorizedPlayers = 0;


					if (ActivePlayer)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] ActivateRequestComplete - Found ActiveMatchPlayer"));
						ActivePlayer->authorized = true;
						ActivePlayer->deactivateStarted = false;
						ActivePlayer->playerTitle = JsonParsed->GetStringField("player_name");
						ActivePlayer->userKeyId = JsonParsed->GetStringField("user_key_id");
						ActivePlayer->currencyCurrent = JsonParsed->GetIntegerField("player_currency");
						ActivePlayer->rank = JsonParsed->GetIntegerField("player_rank");
						ActivePlayer->gamePlayerKeyId = JsonParsed->GetStringField("game_player_key_id");

						// We already have the playercontroller.
						APlayerState* thisPlayerState = ActivePlayer->PlayerController->PlayerState;
						AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);

						if (playerS)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] ActivateRequestComplete - Found PlayerState"));

							ActivePlayer->playerID = thisPlayerState->PlayerId;
							playerS->Currency = JsonParsed->GetIntegerField("player_currency");
							ActivePlayer->PlayerController->bIsShardedServer = bIsShardedServer;
							// Also set loginflow completed to false
							// we might need to move this to a different place, in case it's not called in time.
							playerS->playerLoginFlowCompleted = false;
						}

						//get all of the game player data associated with this player.
						// We need a delay on this because on server travel the previous server needs time to update the record

						// Bind the timer delegate
						ActivePlayer->GetPlayerInfoTimerDel.BindUFunction(this, FName("GetGamePlayer"), JsonParsed->GetStringField("player_userid"), true);
						// Set the timer
						GetWorld()->GetTimerManager().SetTimer(ActivePlayer->GetPlayerInfoDelayHandle, ActivePlayer->GetPlayerInfoTimerDel, 5.f, false);


						if (ActivePlayer->authorized) {
							activeAuthorizedPlayers++;
						}
					}

					// There is no lobby so we're going to set true when users successfully activate.
					bRequestBeginPlayStarted = true;

				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("Player NOT Authorized"));
					IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();
					const FString kickReason = TEXT("Not Authorized");
					const FText kickReasonText = FText::FromString(kickReason);
					//AMyGameSession::KickPlayer(pc, kickReasonText);
					this->GetGameSession()->KickPlayer(pc, kickReasonText);
					FString badUrl = "";
					ActivePlayer->PlayerController->ClientTravel(badUrl, ETravelType::TRAVEL_Absolute);
				}
			}
		}
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ActivateRequestComplete] Done!"));
}


void UMyGameInstance::ActivateMatchPlayerRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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

		APlayerController* pc = NULL;
		//int32 playerstateID;

		FString JsonRaw = *HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool PlayerAuthorized = JsonParsed->GetBoolField("player_authorized");
				if (PlayerAuthorized) {
					UE_LOG(LogTemp, Log, TEXT("Player Authorized"));

					int32 activeJoinedPlayers = 0;
					int32 totalExpectedPlayers = 0;
					//int32 activePlayerIndex;

					// refactored using our get_by_id function

					// get the player record
					FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(JsonParsed->GetStringField("player_userid"));
					if (ActivePlayer)
					{
						ActivePlayer->joined = true;
						ActivePlayer->currentRoundAlive = true;
						ActivePlayer->bIsConnected = true;

						APlayerState* thisPlayerState = ActivePlayer->PlayerController->PlayerState;
						AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);

						if (playerS)
						{
							ActivePlayer->playerID = thisPlayerState->PlayerId;
							ActivePlayer->gamePlayerKeyId = JsonParsed->GetStringField("game_player_key_id");
							// Also set the team!
							playerS->TeamId = JsonParsed->GetNumberField("team_id");
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ActivateMatchPlayerRequestComplete] - playerS->TeamId %d"), playerS->TeamId);

							playerS->TeamPlayerIndex = ActivePlayer->teamPlayerIndex;
							playerS->SetPlayerName(ActivePlayer->playerTitle);
							playerS->playerTitle = ActivePlayer->playerTitle;

							// Also set the character customization bool we got from match info
							playerS->CharacterSetup = ActivePlayer->characterCustomized;

							// Bind the timer delegate
							ActivePlayer->GetPlayerInfoTimerDel.BindUFunction(this, FName("GetGamePlayer"), JsonParsed->GetStringField("player_userid"), true);
							// Set the timer
							GetWorld()->GetTimerManager().SetTimer(ActivePlayer->GetPlayerInfoDelayHandle, ActivePlayer->GetPlayerInfoTimerDel, 1.f, false);
						}

						totalExpectedPlayers++;

						if (ActivePlayer->joined) {
							activeJoinedPlayers++;
						}

						// Put replicated data in game state
						AGameState* gameState = Cast<AGameState>(GetWorld()->GetGameState());
						AMyGameState* uetopiaGameState = Cast<AMyGameState>(gameState);

						// b is the team index
						for (int32 b = 0; b < uetopiaGameState->TeamList.teams.Num(); b++)
						{
							// i is the player index for the team
							for (int32 i = 0; i < uetopiaGameState->TeamList.teams[b].players.Num(); i++)
							{
								//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ActivateRequestComplete] playerKeyId: %s"), *PlayerRecord.ActivePlayers[b].playerKeyId);
								if (uetopiaGameState->TeamList.teams[b].players[i].userKeyId == JsonParsed->GetStringField("player_userid")) {
									UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ActivateRequestComplete] - FOUND MATCHING playerKeyId in Game State.TeamList"));

									// set status flags
									uetopiaGameState->TeamList.teams[b].players[i].joined = true;
								}
							}
						}
					}
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("Player NOT Authorized"));

					// TODO - figure out a good way to deal with this.

					// Send to spectator or something?

				}
			}
		}
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ActivateMatchPlayerRequestComplete] Done!"));

}


bool UMyGameInstance::GetGamePlayer(FString playerKeyId, bool bAttemptLock)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] GetGamePlayer"));

	FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(playerKeyId);

	if (ActivePlayer)
	{
		if (!ActivePlayer->gamePlayerDataLoaded)
		{

			FString access_token = ActivePlayer->PlayerController->CurrentAccessTokenFromOSS;

			FString nonceString = "10951350917635";
			FString encryption = "off";  // Allowing unencrypted on sandbox for now.  
			FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption;

			if (bAttemptLock) {
				OutputString = OutputString + "&lock=True";
			}

			FString APIURI = "/api/v1/game/player/" + ActivePlayer->gamePlayerKeyId;
			bool requestSuccess = PerformHttpRequest(&UMyGameInstance::GetGamePlayerRequestComplete, APIURI, OutputString, access_token);
			return requestSuccess;
		}
	}
	return true;
}

void UMyGameInstance::GetGamePlayerRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			//UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				//UE_LOG(LogTemp, Log, TEXT("Authorization True"));

				// TODO - this can error out, and crash our server.
				// If the game player was not found, there is no userId to send back.
				// Check it first
				APlayerController* pc = NULL;
				FString playerKeyId = JsonParsed->GetStringField("userKeyId");

				// Keep track of the playerState and playerCharacter that is associated with this player
				APlayerState* thisPlayerState;
				AMyPlayerState* playerS = nullptr;
				AUEtopiaPersistCharacter* playerChar = nullptr;
				AMyPlayerController* PlayerController = nullptr;
				FString playerArrayplayerKeyId;
				
				FMyActivePlayer* activePlayer = getPlayerByPlayerKey(JsonParsed->GetStringField("userKeyId"));

				if (!activePlayer)
				{
					UE_LOG(LogTemp, Error, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - DID NOT FIND activePlayer"));
					return;
				}

				playerArrayplayerKeyId = activePlayer->userKeyId;

				activePlayer->gamePlayerDataLoaded = true;

				PlayerController = Cast<AMyPlayerController>(activePlayer->PlayerController);
				if (PlayerController)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - Found PlayerController"));

					playerChar = Cast<AUEtopiaPersistCharacter>(PlayerController->GetPawn());
					if (playerChar)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - Found playerChar"));
					}
					thisPlayerState = PlayerController->PlayerState;
					playerS = Cast<AMyPlayerState>(thisPlayerState);

				}

					
				
				//APlayerState* thisPlayerState = pc->PlayerState;
					//AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);
					//AMyPlayerController* playerC = Cast<AMyPlayerController>(pc);
					//AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(playerC->GetPawn());

				FString playerstateplayerKeyId = playerS->playerKeyId;

				double scoreTemp;
				FString titleTemp = "None";
				JsonParsed->TryGetNumberField("score", scoreTemp);
				playerS->Score = scoreTemp;
				JsonParsed->TryGetNumberField("coordLocationX", playerS->savedCoordLocationX);
				JsonParsed->TryGetNumberField("coordLocationY", playerS->savedCoordLocationY);
				JsonParsed->TryGetNumberField("coordLocationZ", playerS->savedCoordLocationZ);
				JsonParsed->TryGetStringField("zoneName", playerS->savedZoneName);
				JsonParsed->TryGetStringField("zoneKey", playerS->savedZoneKey);
				JsonParsed->TryGetStringField("inventory", playerS->savedInventory);
				JsonParsed->TryGetStringField("equipment", playerS->savedEquipment);
				JsonParsed->TryGetStringField("abilities", playerS->savedAbilities);
				JsonParsed->TryGetStringField("interface", playerS->savedInterface);

				JsonParsed->TryGetStringField("crafting", playerS->savedCraftingSlots);
				JsonParsed->TryGetStringField("recipes", playerS->savedRecipes);
				JsonParsed->TryGetStringField("character", playerS->savedCharacter);
				JsonParsed->TryGetStringField("characterCustom", playerS->savedCharacterCustom);
				JsonParsed->TryGetStringField("userTitle", titleTemp);
				playerS->playerTitle = titleTemp;
				playerS->serverTitle = ServerTitle;
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] playerS->playerTitle: %s"), *playerS->playerTitle);

				UE_LOG(LogTemp, Log, TEXT("Getting match player specific values"));
				JsonParsed->TryGetNumberField("experience", activePlayer->experience);
				JsonParsed->TryGetNumberField("experienceThisLevel", activePlayer->experienceThisLevel);
				JsonParsed->TryGetNumberField("experience", playerS->Experience);
				JsonParsed->TryGetNumberField("experienceThisLevel", playerS->ExperienceThisLevel);
				JsonParsed->TryGetNumberField("level", activePlayer->level);
				JsonParsed->TryGetNumberField("score", activePlayer->score);
				JsonParsed->TryGetNumberField("rank", activePlayer->rank);

				// Is this player is allowed to pickup and drop items on this server.
				JsonParsed->TryGetBoolField("allowPickup", playerS->allowPickup);
				JsonParsed->TryGetBoolField("allowDrop", playerS->allowDrop);


				// TODO move player to the indicated position.

				// DO Character FIRST.  Equipment and inventory will be modifying these values so they need to be set asap.
				// Character Customization
				bool CharacterParseSuccess = false;
				FString CharacterJsonRaw = playerS->savedCharacter;
				TSharedPtr<FJsonObject> CharacterJsonParsed;
				TSharedRef<TJsonReader<TCHAR>> CharacterJsonReader = TJsonReaderFactory<TCHAR>::Create(CharacterJsonRaw);
				//const JsonValPtrArray *CharacterJson;
				bool CharacterSetup = false;

				if (FJsonSerializer::Deserialize(CharacterJsonReader, CharacterJsonParsed))
				{
					UE_LOG(LogTemp, Log, TEXT("CharacterJsonParsed"));
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] InventoryJsonRaw: %s"), *InventoryJsonRaw);
					CharacterParseSuccess = CharacterJsonParsed->TryGetBoolField("Setup", CharacterSetup);
				}

				if (CharacterParseSuccess)
				{
					UE_LOG(LogTemp, Log, TEXT("CharacterParseSuccess"));

					// check if character customization is complete.
					// then change client UI state

					if (CharacterSetup)
					{
						int32 CharacterClass = 0;
						CharacterJsonParsed->TryGetNumberField("characterClass", CharacterClass);
						playerS->CharacterClass = CharacterClass;
						playerS->CharacterSetup = true;

						// Signal the UI to change to PLAY State
						PlayerController->ClientChangeUIState(EConnectUIState::Play);

						// Also set the playerLoginFlowCompleted so we don't get loading screen on respawn
						playerS->playerLoginFlowCompleted = true;

						// also set the characterCustomized flag in match players
						activePlayer->characterCustomized = true;

					}
					else
					{
						UE_LOG(LogTemp, Log, TEXT("CharacterParsed, but was not set up."));
						PlayerController->ClientChangeUIState(EConnectUIState::CharacterCustomize);
					}
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("CharacterParse FAIL"));

					// On first connection after creating a new character, a player will not have anything inside the character field.
					// We want to check to see if there is anything in the characterCustom field here.
					// If there is, we want to validate it.  Users can easily forge these requests, so it is important to check it first.

					// VALIDATE THE DATA BEFORE USING IT.

					bool CharacterCustomParseSuccess = false;
					FString CharacterCustomJsonRaw = playerS->savedCharacterCustom;
					TSharedPtr<FJsonObject> CharacterCustomJsonParsed;
					TSharedRef<TJsonReader<TCHAR>> CharacterCustomJsonReader = TJsonReaderFactory<TCHAR>::Create(CharacterCustomJsonRaw);

					bool CharacterCustomSetup = false;

					if (FJsonSerializer::Deserialize(CharacterCustomJsonReader, CharacterCustomJsonParsed))
					{
						UE_LOG(LogTemp, Log, TEXT("CharacterCustomJsonParsed"));

						CharacterCustomParseSuccess = CharacterCustomJsonParsed->TryGetBoolField("Setup", CharacterCustomSetup);
					}

					if (CharacterCustomParseSuccess)
					{
						UE_LOG(LogTemp, Log, TEXT("CharacterCustomParseSuccess"));

						// check if character custom data is valid.
						// If so, save it to the player state so it can be saved in character
						// then change client UI state

						// Do validations for all of your data here.
						FString incomingClass = "";

						CharacterCustomJsonParsed->TryGetStringField("Class", incomingClass);

						if (incomingClass == "Tester" || incomingClass == "Developer")
						{
							UE_LOG(LogTemp, Log, TEXT("CharacterCustomParseSuccess - Data is valid."));

							// convert the strings to int32
							if (incomingClass == "Developer")
							{
								playerS->CharacterClass = 0;
							}
							else
							{
								playerS->CharacterClass = 1;
							}

							playerS->CharacterSetup = true;

							// Signal the UI to change to PLAY State
							PlayerController->ClientChangeUIState(EConnectUIState::Play);

							// Also set the playerLoginFlowCompleted so we don't get loading screen on respawn
							playerS->playerLoginFlowCompleted = true;

							// also set the characterCustomized flag in match players
							activePlayer->characterCustomized = true;

						}
						else
						{
							UE_LOG(LogTemp, Log, TEXT("CharacterCustomParseSuccess - Data is NOT valid."));
							PlayerController->ClientChangeUIState(EConnectUIState::CharacterCustomize);
						}
					}

					else
					{
						// Character Custom field did not parse.
						// send the player UI to the character screen
						UE_LOG(LogTemp, Log, TEXT("CharacterCustomParse FAIL"));

						PlayerController->ClientChangeUIState(EConnectUIState::CharacterCustomize);
					}


				}


				////////////////////////////////////////////////////////////////////
				// Abilities
				////////////////////////////////////////////////////////////////////

				// First try to parse abilities as json
				// If it fails or does not make sense, set it to a default value
				bool AbilitiesParseSuccess = false;
				FString AbilitiesJsonRaw = playerS->savedAbilities;
				TSharedPtr<FJsonObject> AbilitiesJsonParsed;
				TSharedRef<TJsonReader<TCHAR>> AbilitiesJsonReader = TJsonReaderFactory<TCHAR>::Create(AbilitiesJsonRaw);
				const JsonValPtrArray* AbilitySlotsJson;

				if (FJsonSerializer::Deserialize(AbilitiesJsonReader, AbilitiesJsonParsed))
				{
					UE_LOG(LogTemp, Log, TEXT("AbilitiesJsonParsed"));
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] AbilitiesJsonRaw: %s"), *AbilitiesJsonRaw);

					AbilitiesParseSuccess = AbilitiesJsonParsed->TryGetArrayField("GrantedAbilities", AbilitySlotsJson);
				}

				// Keep a local copy of the array, so we only perform a single operation on the replicated array
				TArray<FMyGrantedAbility> LocalGrantedAbilities;

				if (AbilitiesParseSuccess)
				{
					UE_LOG(LogTemp, Log, TEXT("AbilitiesParseSuccess"));

					// we already have this
					// AbilitiesJsonParsed->TryGetArrayField("GrantedAbilities", AbilitySlotsJson);

					UMyBaseGameplayAbility* LoadedObjectClass;
					FMyGrantedAbility grantedAbility;
					FGameplayAbilitySpecHandle AbilityHandle;

					// fix for potentially ininitialized pointer.
					AbilitiesJsonParsed->TryGetArrayField("GrantedAbilities", AbilitySlotsJson);

					for (auto grantedAbilityJsonRaw : *AbilitySlotsJson) {
						UE_LOG(LogTemp, Log, TEXT("Found ability "));
						auto grantedAbilityObj = grantedAbilityJsonRaw->AsObject();
						if (grantedAbilityObj.IsValid())
						{
							UClass* LoadedActorOwnerClass;
							LoadedActorOwnerClass = LoadClassFromPath(grantedAbilityObj->GetStringField(FString("AbilityClass")));

							if (LoadedActorOwnerClass)
							{
								UE_LOG(LogTemp, Log, TEXT("Found LoadedActorOwnerClass"));

								LoadedObjectClass = Cast<UMyBaseGameplayAbility>(LoadedActorOwnerClass->GetDefaultObject());

								if (LoadedObjectClass)
								{
									UE_LOG(LogTemp, Log, TEXT("Found LoadedObjectClass"));

									// There is a problem with giving the ability here.
									// It works fine for initial play.
									// but after a death/respawn abilities are missing.
									// moved the give ability call into the refresh call

									//AbilityHandle = playerChar->AttemptGiveAbility(LoadedObjectClass);

									//grantedAbility.AbilityHandle = AbilityHandle;
									grantedAbility.classPath = grantedAbilityObj->GetStringField(FString("AbilityClass"));
									grantedAbility.Icon = LoadedObjectClass->Icon;
									grantedAbility.title = LoadedObjectClass->Title.ToString();
									grantedAbility.description = LoadedObjectClass->Description.ToString();
									//UGameplayAbility* AbilityClassRef = Cast<UGameplayAbility>(LoadedObjectClass);
									grantedAbility.Ability = LoadedObjectClass->GetClass();

									LocalGrantedAbilities.Add(grantedAbility);
									//playerC->MyGrantedAbilities.Add(grantedAbility);
								}
							}

							// trigger the delegate
							// We don't want to do this anymore.
							// The delegate needs to be triggered later, in order to facilitate giving abilities again after respawn
							//playerC->MyGrantedAbilities = LocalGrantedAbilities;
							playerS->CachedAbilities = LocalGrantedAbilities;

							// tell player controller to convert cached to granted
							PlayerController->GrantCachedAbilities();

							//playerS->GrantedAbilities = LocalGrantedAbilities;
							//playerC->DoRep_AbilitiesChanged = !playerC->DoRep_AbilitiesChanged;
						}
					}

				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("AbilitiesParse FAIL - granting base abilities"));

					//"Blueprint'/Game/Abilities/TestAbility.TestAbility'"
					// Blueprint'/Game/Abilities/TestAbility2.TestAbility2'
					//FString ActorClassFullPath = "/Game/Abilities/TestAbility.TestAbility_C";
					//FString ActorClassFullPath = "/Game/Abilities/TestAbility2.TestAbility2_C";
					// Blueprint'/Game/Abilities/TestAbility3.TestAbility3'
					//Blueprint'/Game/Abilities/TestAbility4.TestAbility4'
					TArray <FString> AbilityClassPaths = { "/Game/Abilities/TestAbility2.TestAbility2_C", "/Game/Abilities/TestAbility3.TestAbility3_C", "/Game/Abilities/TestAbility4.TestAbility4_C" };

					UClass* LoadedActorOwnerClass;
					UMyBaseGameplayAbility* LoadedObjectClass;
					FMyGrantedAbility grantedAbility;
					FGameplayAbilitySpecHandle AbilityHandle;

					for (int32 AbilityIndex = 0; AbilityIndex < AbilityClassPaths.Num(); AbilityIndex++)
					{
						UE_LOG(LogTemp, Log, TEXT("Found default ability"));

						LoadedActorOwnerClass = LoadClassFromPath(AbilityClassPaths[AbilityIndex]);
						LoadedObjectClass = Cast<UMyBaseGameplayAbility>(LoadedActorOwnerClass->GetDefaultObject());

						if (LoadedObjectClass)
						{
							UE_LOG(LogTemp, Log, TEXT("Found LoadedObjectClass"));

							//AbilityHandle = playerChar->AttemptGiveAbility(LoadedObjectClass);

							//grantedAbility.AbilityHandle = AbilityHandle;
							grantedAbility.classPath = AbilityClassPaths[AbilityIndex];
							grantedAbility.Icon = LoadedObjectClass->Icon;
							grantedAbility.title = LoadedObjectClass->Title.ToString();
							grantedAbility.description = LoadedObjectClass->Description.ToString();
							//UGameplayAbility* AbilityClassRef = Cast<UGameplayAbility>(LoadedObjectClass);
							grantedAbility.Ability = LoadedObjectClass->GetClass();

							LocalGrantedAbilities.Add(grantedAbility);
						}
					}

					// trigger the delegate
					// We don't want to do this anymore.
					// The delegate needs to be triggered later, in order to facilitate giving abilities again after respawn
					// playerC->MyGrantedAbilities = LocalGrantedAbilities;
					//playerC->DoRep_AbilitiesChanged = !playerC->DoRep_AbilitiesChanged;

					playerS->CachedAbilities = LocalGrantedAbilities;

					// tell player controller to convert cached to granted
					PlayerController->GrantCachedAbilities();

				}

				////////////////////////////////////////////////////////////////////
				// Interface
				////////////////////////////////////////////////////////////////////



				// First try to parse interface ability bar as json
				// If it fails or does not make sense, set it to a default value
				bool InterfaceParseSuccess = false;
				FString InterfaceJsonRaw = playerS->savedInterface;
				TSharedPtr<FJsonObject> InterfaceJsonParsed;
				TSharedRef<TJsonReader<TCHAR>> InterfaceJsonReader = TJsonReaderFactory<TCHAR>::Create(InterfaceJsonRaw);
				const JsonValPtrArray* InterfaceAbilitySlotsJson;

				int32 AbilityCapacity = 4;
				int32 AbilitySlotsPerRow = 6;

				if (FJsonSerializer::Deserialize(InterfaceJsonReader, InterfaceJsonParsed))
				{
					UE_LOG(LogTemp, Log, TEXT("InterfaceJsonParsed"));
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] InterfaceJsonRaw: %s"), *InterfaceJsonRaw);

					InterfaceJsonParsed->TryGetNumberField("AbilityCapacity", AbilityCapacity);
					InterfaceJsonParsed->TryGetNumberField("AbilitySlotsPerRow", AbilitySlotsPerRow);

					InterfaceParseSuccess = InterfaceJsonParsed->TryGetArrayField("AbilitySlots", InterfaceAbilitySlotsJson);
				}

				// get key mappings from config

				const UInputSettings* Settings = GetDefault<UInputSettings>();
				if (!Settings) return;

				const TArray<FInputActionKeyMapping>& KeyBindingsFromConfig = Settings->ActionMappings;

				//TArray<FVictoryInput> KeyBindingsFromConfig; // remapped keybindings are stored in ini files as well.
				//playerC->VictoryGetAllActionKeyBindings(KeyBindingsFromConfig);

				TArray<FInputActionKeyMapping> KeyBindingsForAbilities; // Only keeping bindings that are used for abilities.  They look like:  "UseAbility1"

				FString ActionNameBase = "UseAbility";
				FString ActionNameTarget;
				//int32 ActionBindingIndex = 0;

				// Go through all of the key bindings.  Find the ones that match our naming convention, and put them in order.
				for (int32 ActionBindingIndex = 1; ActionBindingIndex <= AbilityCapacity; ActionBindingIndex++)
				{
					ActionNameTarget = ActionNameBase + FString::FromInt(ActionBindingIndex);
					for (int32 keyBindIndex = 0; keyBindIndex < KeyBindingsFromConfig.Num(); keyBindIndex++)
					{

						if (ActionNameTarget == KeyBindingsFromConfig[keyBindIndex].ActionName.ToString())
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] KeyBindingFromConfig.ActionName: %s"), *KeyBindingsFromConfig[keyBindIndex].ActionName.ToString());
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] KeyBindingFromConfig.KeyAsString: %s"), *KeyBindingsFromConfig[keyBindIndex].Key.ToString());
							KeyBindingsForAbilities.Add(KeyBindingsFromConfig[keyBindIndex]);
						}
					}
				}


				// Make sure there are enough bound keys!
				if (KeyBindingsForAbilities.Num() >= AbilityCapacity)
				{
					UE_LOG(LogTemp, Log, TEXT("KeyBindingsForAbilities.Num() >= AbilityCapacity"));

					// Keep a local copy of the array, so we only perform a single operation on the replicated array
					TArray<FMyAbilitySlot> LocalAbilitySlots;

					if (InterfaceParseSuccess)
					{
						UE_LOG(LogTemp, Log, TEXT("InterfaceParseSuccess"));

						PlayerController->AbilityCapacity = AbilityCapacity;
						PlayerController->AbilitySlotsPerRow = AbilitySlotsPerRow;

						// Keep track of slots that were successfully filled
						int32 abilitySlotsFilledSuccessfully = 0;
						int32 currentSlotIndex = 0;

						// doing this differently...  WE need to fill them in order, and skip any that are not mapped.
						// RIght now, XX-X is saved and relaoaded as XXX-


						// Fill slots from interface json first
						InterfaceJsonParsed->TryGetArrayField("AbilitySlots", InterfaceAbilitySlotsJson);


						for (auto interfaceAbilitySlot : *InterfaceAbilitySlotsJson) {
							UE_LOG(LogTemp, Log, TEXT("Found Interface Ability slot"));
							FMyAbilitySlot interfaceASlot;
							auto interfaceAbilitySlotObj = interfaceAbilitySlot->AsObject();
							if (interfaceAbilitySlotObj.IsValid())
							{
								FString AbilityClassPath = "";
								interfaceAbilitySlotObj->TryGetStringField("AbilityClass", AbilityClassPath);

								int32 matchingGrantedAbilityIndex = -1;

								// go though granted abilities and find by Class
								for (int32 grantedAIndex = 0; grantedAIndex < PlayerController->MyGrantedAbilities.Num(); grantedAIndex++)
								{
									if (AbilityClassPath == PlayerController->MyGrantedAbilities[grantedAIndex].classPath)
									{
										UE_LOG(LogTemp, Log, TEXT("Found matching granted ability"));
										matchingGrantedAbilityIndex = grantedAIndex;
										break;
									}
								}

								// If a match was found, add it.  Otherwise, add empty.
								if (matchingGrantedAbilityIndex >= 0)
								{
									UE_LOG(LogTemp, Log, TEXT("Adding found ability to ability slots"));

									FMyAbilitySlot AbilityTemp;

									AbilityTemp.Key = KeyBindingsForAbilities[currentSlotIndex].Key;
									AbilityTemp.GrantedAbility = PlayerController->MyGrantedAbilities[matchingGrantedAbilityIndex];
									AbilityTemp.bIsValid = true;
									AbilityTemp.title = PlayerController->MyGrantedAbilities[matchingGrantedAbilityIndex].title;
									AbilityTemp.description = PlayerController->MyGrantedAbilities[matchingGrantedAbilityIndex].description;
									AbilityTemp.Icon = PlayerController->MyGrantedAbilities[matchingGrantedAbilityIndex].Icon;
									AbilityTemp.classPath = PlayerController->MyGrantedAbilities[matchingGrantedAbilityIndex].classPath;
									LocalAbilitySlots.Add(AbilityTemp);

									abilitySlotsFilledSuccessfully++;
								}
								else
								{
									UE_LOG(LogTemp, Log, TEXT("No matching Granted ability found - adding empty"));

									FMyAbilitySlot AbilityTemp;

									FMyGrantedAbility grantedAbility;
									grantedAbility.Icon = nullptr;

									AbilityTemp.GrantedAbility = grantedAbility;

									AbilityTemp.Key = KeyBindingsForAbilities[currentSlotIndex].Key;
									AbilityTemp.bIsValid = false;
									AbilityTemp.Icon = nullptr;
									AbilityTemp.classPath = "";
									LocalAbilitySlots.Add(AbilityTemp);

									abilitySlotsFilledSuccessfully++;
								}

							}
							currentSlotIndex++;
						}

						// TODO fill any slots that did not get populated successfully with empty
						if (abilitySlotsFilledSuccessfully < AbilityCapacity)
						{
							UE_LOG(LogTemp, Log, TEXT("found unfilled ability slots - filling with empty"));

							FMyAbilitySlot BlankAbility;
							BlankAbility.Icon = nullptr;
							BlankAbility.title = "Empty";


							for (int32 abilitySlotIndex = 0; abilitySlotIndex < AbilityCapacity - abilitySlotsFilledSuccessfully; abilitySlotIndex++)
							{
								UE_LOG(LogTemp, Log, TEXT("Adding blank ability to ability slots"));
								FMyGrantedAbility grantedAbility;
								grantedAbility.Icon = nullptr;


								BlankAbility.Key = KeyBindingsForAbilities[abilitySlotIndex + abilitySlotsFilledSuccessfully].Key;
								BlankAbility.GrantedAbility = grantedAbility;
								BlankAbility.bIsValid = false;
								//playerC->MyAbilitySlots.Add(BlankAbility);
								LocalAbilitySlots.Add(BlankAbility);
							}

						}

						// trigger the delegate so we can build the UI
						PlayerController->AbilityCapacity = AbilityCapacity;
						PlayerController->AbilitySlotsPerRow = AbilitySlotsPerRow;
						PlayerController->MyAbilitySlots = LocalAbilitySlots;
						//playerC->DoRep_AbilityInterfaceChanged = !playerC->DoRep_AbilityInterfaceChanged;

					}
					else
					{
						UE_LOG(LogTemp, Log, TEXT("InterfaceParse FAIL"));

						// WE don't have Interface json to work with, so we're just going to build up a blank action bar that is empty.
						FMyAbilitySlot BlankAbility;
						BlankAbility.Icon = nullptr;
						BlankAbility.title = "Empty";


						for (int32 abilitySlotIndex = 0; abilitySlotIndex < AbilityCapacity; abilitySlotIndex++)
						{
							UE_LOG(LogTemp, Log, TEXT("Adding blank ability to ability slots"));
							FMyGrantedAbility grantedAbility;
							grantedAbility.Icon = nullptr;

							BlankAbility.Key = KeyBindingsForAbilities[abilitySlotIndex].Key;
							BlankAbility.GrantedAbility = grantedAbility;
							BlankAbility.bIsValid = false;
							LocalAbilitySlots.Add(BlankAbility);

						}

						// trigger the delegate so we can build the UI
						PlayerController->AbilityCapacity = AbilityCapacity;
						PlayerController->AbilitySlotsPerRow = AbilitySlotsPerRow;
						PlayerController->MyAbilitySlots = LocalAbilitySlots;
						//playerC->DoRep_AbilityInterfaceChanged = !playerC->DoRep_AbilityInterfaceChanged;





					}
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("ERROR.  INSUFFICIENT ABILITY BINDINGS.  CANNOT SET UP ACTION BAR.  "));
				}

				////////////////////////////////////////////////////////////////////
				// Inventory
				////////////////////////////////////////////////////////////////////

				// First try to parse the inventory as json.
				// If it fails or does not make sense, set it to a default value.
				bool InventoryParseSuccess = false;
				FString InventoryJsonRaw = playerS->savedInventory;
				TSharedPtr<FJsonObject> InventoryJsonParsed;
				TSharedRef<TJsonReader<TCHAR>> InventoryJsonReader = TJsonReaderFactory<TCHAR>::Create(InventoryJsonRaw);
				const JsonValPtrArray* InventorySlotsJson;
				int32 InventoryCapacity = 16;

				if (FJsonSerializer::Deserialize(InventoryJsonReader, InventoryJsonParsed))
				{
					UE_LOG(LogTemp, Log, TEXT("InventoryJsonParsed"));
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] InventoryJsonRaw: %s"), *InventoryJsonRaw);

					InventoryJsonParsed->TryGetNumberField("InventoryCapacity", InventoryCapacity);
					InventoryParseSuccess = InventoryJsonParsed->TryGetArrayField("InventorySlots", InventorySlotsJson);
				}

				// Keep a local copy of the array, so we only perform a single operation on the replicated array
				TArray<FMyInventorySlot> LocalInventorySlots;

				if (InventoryParseSuccess)
				{
					UE_LOG(LogTemp, Log, TEXT("InventoryParseSuccess"));



					// TODO - set up player controller inventory.
					playerS->InventoryCapacity = InventoryCapacity;

					// Keep track of slots that were successfully filled
					int32 slotsFilledSuccessfully = 0;

					// Fill slots from inventory json first
					InventoryJsonParsed->TryGetArrayField("InventorySlots", InventorySlotsJson);

					for (auto inventorySlot : *InventorySlotsJson) {
						//UE_LOG(LogTemp, Log, TEXT("Found Inventory slot"));
						FMyInventorySlot itemSlot;
						auto inventorySlotObj = inventorySlot->AsObject();
						if (inventorySlotObj.IsValid())
						{
							UClass* LoadedActorOwnerClass;
							LoadedActorOwnerClass = LoadClassFromPath(inventorySlotObj->GetStringField(FString("ItemClass")));

							if (LoadedActorOwnerClass)
							{
								//UE_LOG(LogTemp, Log, TEXT("Found LoadedActorOwnerClass"));

								AMyBasePickup* basePickupBP = Cast<AMyBasePickup>(LoadedActorOwnerClass->GetDefaultObject());
								if (basePickupBP) {
									//UE_LOG(LogTemp, Log, TEXT("Found basePickupBP"));

									itemSlot.itemClassTitle = basePickupBP->GetName();  // FFS - we can't use the name because it's not consistent
									// [2017.11.21-04.31.36:264][655]LogTemp: InventorySlots[i].itemClassTitle: Default__ItemHealthPotion_C
									// [2017.11.21 - 04.31.36:264][655]LogTemp: ClassTypeIn->GetName() : ItemHealthPotion2_2

									FString savedAttributes;

									itemSlot.itemTitle = basePickupBP->Title.ToString();
									itemSlot.itemClassPath = inventorySlotObj->GetStringField(FString("ItemClass"));
									itemSlot.Icon = basePickupBP->Icon;

									inventorySlotObj->TryGetNumberField("Quantity", itemSlot.quantity);
									inventorySlotObj->TryGetStringField("ItemId", itemSlot.itemId);
									inventorySlotObj->TryGetStringField("ItemTitle", itemSlot.itemTitle);

									// For inventory we just use a plain array field, becuase inventory already is a json encoded test string.  We don't need to do it again.

									//bool AttributeParseSuccess;
									//const TArray <TSharedPtr<FJsonValue>> *AttributesJson;
									const JsonValPtrArray* AttributesJson;
									inventorySlotObj->TryGetArrayField("attributes", AttributesJson);

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

											itemSlot.Attributes.Add(JsonValue);
										}
										currentIndex++;
									}


									/*
									//TArray<TSharedPtr<FJsonValue> > JsonFriends = JsonObject->GetArrayField(TEXT("data"));

									inventorySlotObj->TryGetStringField("attributes", savedAttributes);

									TSharedPtr<FJsonObject> AttributesJsonParsed;
									TSharedRef<TJsonReader<TCHAR>> AttributesJsonReader = TJsonReaderFactory<TCHAR>::Create(savedAttributes);



									if (FJsonSerializer::Deserialize(AttributesJsonReader, AttributesJsonParsed))
									{
									UE_LOG(LogTemp, Log, TEXT("AttributesJsonParsed"));
									//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] InventoryJsonRaw: %s"), *InventoryJsonRaw);

									for (auto currObject = AttributesJsonParsed->Values.CreateConstIterator(); currObject; ++currObject)
									{
									UE_LOG(LogTemp, Log, TEXT("Found Attribute: %s"), *currObject->Key);
									currObject->Key;
									if (currObject->Value->AsNumber())
									{
									itemSlot.Attributes.Add(currObject->Value->AsNumber());
									}

									}

									}
									*/



									itemSlot.bCanBeUsed = basePickupBP->bCanBeUsed;
									itemSlot.UseText = basePickupBP->UseText;
									itemSlot.bCanBeStacked = basePickupBP->bCanBeStacked;
									itemSlot.MaxStackSize = basePickupBP->MaxStackSize;

									//playerC->InventorySlots.Add(itemSlot);
									LocalInventorySlots.Add(itemSlot);

									slotsFilledSuccessfully++;
								}

							}
							else {
								UE_LOG(LogTemp, Log, TEXT("Did not find LoadedActorOwnerClass"));
							}
						}
					}

					// Fill remainder slots with empty

					int32 remainingSlotsToFill = InventoryCapacity - slotsFilledSuccessfully;
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

					for (int32 inventoryIndex = 0; inventoryIndex < remainingSlotsToFill; inventoryIndex++)
					{
						//playerC->InventorySlots.Add(emptySlot);
						LocalInventorySlots.Add(emptySlot);
					}

					// Trigger the inventory changed delegate
					playerS->InventorySlots = LocalInventorySlots;
					//playerC->DoRep_InventoryChanged = !playerC->DoRep_InventoryChanged;

				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("InventoryJson Parse FAIL"));

					playerS->InventoryCapacity = InventoryCapacity;

					FMyInventorySlot emptySlot;

					// loop over the InventoryBlueprintClasses array and grab the match
					// Rama to the rescue:  https://answers.unrealengine.com/questions/330309/an-issue-with-runtime-savingloading-of-blueprint-c.html

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
						emptySlot.itemTitle = "Empty";
					}

					emptySlot.itemId = 0;
					emptySlot.quantity = 0;


					for (int32 inventoryIndex = 0; inventoryIndex < 16; inventoryIndex++)
					{
						LocalInventorySlots.Add(emptySlot);
						//playerC->InventorySlots.Add(emptySlot);
					}

					// Trigger the inventory changed delegate
					playerS->InventorySlots = LocalInventorySlots;
				}

				// set loaded state
				PlayerController->PlayerDataLoaded = true;

				// Only do this if competitive
				if (UEtopiaMode == "competitive")
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - competitive"));
					// check to see if all players have connected
					// And if they have completed character customize
					// It is possible that they haven't so we'll need to attempt start match timer from 
					// SaveCharacterCustomization
					bool allPlayersJoined = true;
					bool allPlayersCharCustComplete = true;
					for (int32 b = 0; b < MatchInfo.players.Num(); b++)
					{
						if (!MatchInfo.players[b].joined) {
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - allPlayersJoined = false"));
							allPlayersJoined = false;
						}
						if (!MatchInfo.players[b].characterCustomized) {
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - allPlayersCharCustComplete = false"));
							allPlayersCharCustComplete = false;
						}
					}

					if (MatchStarted == false)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - MatchStarted == false"));
						if (allPlayersJoined && allPlayersCharCustComplete)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - allPlayersJoined && allPlayersCharCustComplete - starting timer"));
							// do it after a timer
							GetWorld()->GetTimerManager().SetTimer(AttemptStartMatchTimerHandle, this, &UMyGameInstance::AttemptStartMatch, 10.0f, false);
						}
					}
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] - continuous"));

					PlayerController->ClientChangeUIState(EConnectUIState::Play);
				}

			}
		}
	}
}



bool UMyGameInstance::SaveGamePlayer(FString playerKeyId, bool bAttemptUnLock)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SaveGamePlayer"));

	// get our player state so we can access all of the saved data

	APlayerController* pc = NULL;

	// Keep track of the playerState and playerCharacter that is associated with this player
	APlayerState* thisPlayerState = nullptr;
	AMyPlayerState* playerS = nullptr;
	AUEtopiaPersistCharacter* playerChar = nullptr;
	AMyPlayerController* PlayerController = nullptr;
	FString gamePlayerKeyId;

	// And grab our scores out of the array while we're at it.
	int32 Rank = 1600;
	int32 Score = 0;
	int32 Level = 0;
	int32 Experience = 0;
	int32 ExperienceThisLevel = 0;

	FString InventoryOutputString;
	FString AbilitiesOutputString;
	FString InterfaceOutputString;
	FString CharacterOutputString;
	FString EquipmentOutputString;

	FMyActivePlayer* activePlayer = getPlayerByPlayerKey(playerKeyId);
	if (activePlayer)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - Found activePlayer"));

		gamePlayerKeyId = activePlayer->gamePlayerKeyId;
		Rank = activePlayer->rank;
		Score = activePlayer->score;
		Level = activePlayer->level;
		Experience = activePlayer->experience;
		ExperienceThisLevel = activePlayer->experienceThisLevel;

		if (activePlayer->bIsConnected)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - activePlayer->bIsConnected "));

			// Setting bisconnected to false so that the active player count will not find this record
			activePlayer->bIsConnected = false;

			// get our player state so we can access all of the saved data
			pc = activePlayer->PlayerController;
			PlayerController = Cast<AMyPlayerController>(pc);

			if (PlayerController)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - found PlayerController"));
				// Only continue if player data has been loaded.  If a player disconnects before getGamePlayer can finish,
				// this could be empty.
				if (PlayerController->PlayerDataLoaded)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - PlayerController->PlayerDataLoaded"));

					playerChar = Cast<AUEtopiaPersistCharacter>(pc->GetPawn());
					thisPlayerState = pc->PlayerState;
					playerS = Cast<AMyPlayerState>(thisPlayerState);

					if (playerS)
					{

						//////////////////////////////////////////////////////////////
						// Convert player granted ability slots to json friendly array
						TSharedPtr<FJsonObject> AbilitiesJsonObject = MakeShareable(new FJsonObject);
						TArray< TSharedPtr<FJsonValue> > GrantedAbilityArray;
						for (int32 GrantedAbilityIndex = 0; GrantedAbilityIndex < PlayerController->MyGrantedAbilities.Num(); GrantedAbilityIndex++)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - Found GrantedAbilityIndex"));
							// all of them should be valid.
							TSharedPtr< FJsonObject > AbilityObj = MakeShareable(new FJsonObject);
							AbilityObj->SetStringField("AbilityClass", PlayerController->MyGrantedAbilities[GrantedAbilityIndex].classPath);
							TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(AbilityObj));
							GrantedAbilityArray.Add(JsonValue);
						}
						AbilitiesJsonObject->SetArrayField("GrantedAbilities", GrantedAbilityArray);
						TSharedRef< TJsonWriter<> > AbilityWriter = TJsonWriterFactory<>::Create(&AbilitiesOutputString);
						FJsonSerializer::Serialize(AbilitiesJsonObject.ToSharedRef(), AbilityWriter);
						UE_LOG(LogTemp, Log, TEXT("[UMyGameInstance] AbilitiesOutputString: %s"), *AbilitiesOutputString);

						///////////////////////////////////////////////////////////
						// Convert player Interface settings to json friendly array
						TSharedPtr<FJsonObject> InterfaceJsonObject = MakeShareable(new FJsonObject);
						InterfaceJsonObject->SetNumberField("AbilityCapacity", PlayerController->AbilityCapacity);
						InterfaceJsonObject->SetNumberField("AbilitySlotsPerRow", PlayerController->AbilitySlotsPerRow);
						TArray< TSharedPtr<FJsonValue> > AbilitySlotsArray;
						for (int32 AbilitySlotIndex = 0; AbilitySlotIndex < PlayerController->MyAbilitySlots.Num(); AbilitySlotIndex++)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - Found AbilitySlotIndex"));
							// just adding them all for now.  TODO - maybe optimize this?
							TSharedPtr< FJsonObject > AbilitySlotObj = MakeShareable(new FJsonObject);
							AbilitySlotObj->SetStringField("AbilityClass", PlayerController->MyAbilitySlots[AbilitySlotIndex].classPath);
							TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(AbilitySlotObj));
							AbilitySlotsArray.Add(JsonValue);
						}
						InterfaceJsonObject->SetArrayField("AbilitySlots", AbilitySlotsArray);
						TSharedRef< TJsonWriter<> > InterfaceWriter = TJsonWriterFactory<>::Create(&InterfaceOutputString);
						FJsonSerializer::Serialize(InterfaceJsonObject.ToSharedRef(), InterfaceWriter);
						UE_LOG(LogTemp, Log, TEXT("[UMyGameInstance] InterfaceOutputString: %s"), *InterfaceOutputString);

						///////////////////////////////////////////////////////
						// Convert player inventory slots to json friendly array
						TSharedPtr<FJsonObject> InventoryJsonObject = MakeShareable(new FJsonObject);
						InventoryJsonObject->SetNumberField("InventoryCapacity", playerS->InventoryCapacity);
						TArray< TSharedPtr<FJsonValue> > InventorySlotArray;

						for (int32 InventorySlotIndex = 0; InventorySlotIndex < playerS->InventorySlots.Num(); InventorySlotIndex++)
						{
							//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - Found InventorySlotIndex"));
							// only add valid slots
							if (playerS->InventorySlots[InventorySlotIndex].itemClassTitle != "empty")
							{
								//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - InventorySlots[InventorySlotIndex].itemClass IsValid "));
								TSharedPtr< FJsonObject > SlotObj = MakeShareable(new FJsonObject);
								SlotObj->SetStringField("ItemId", playerS->InventorySlots[InventorySlotIndex].itemId);
								SlotObj->SetStringField("ItemTitle", playerS->InventorySlots[InventorySlotIndex].itemTitle);
								SlotObj->SetStringField("ItemDescription", playerS->InventorySlots[InventorySlotIndex].itemDescription);
								SlotObj->SetNumberField("Quantity", playerS->InventorySlots[InventorySlotIndex].quantity);
								SlotObj->SetStringField("ItemClass", playerS->InventorySlots[InventorySlotIndex].itemClassPath);

								// Deal with attributes
								FString AttributesOutputString;
								// Convert to json friendly array
								TSharedPtr<FJsonObject> AttributesJsonObject = MakeShareable(new FJsonObject);
								TArray< TSharedPtr<FJsonValue> > AttributesArray;

								for (int attributeIndex = 0; attributeIndex < playerS->InventorySlots[InventorySlotIndex].Attributes.Num(); attributeIndex++)
								{
									//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] Found attribute"));

									TSharedPtr< FJsonObject > AttributeObj = MakeShareable(new FJsonObject);
									AttributeObj->SetNumberField(FString::FromInt(attributeIndex), playerS->InventorySlots[InventorySlotIndex].Attributes[attributeIndex]);
									TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(AttributeObj));
									AttributesArray.Add(JsonValue);
								}

								// For Inventory, we already have a json serialized text area, so we don't need to do it again.
								// Just create a plain array field
								SlotObj->SetArrayField("attributes", AttributesArray);
								TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(SlotObj));
								InventorySlotArray.Add(JsonValue);
							}

						}

						InventoryJsonObject->SetArrayField("InventorySlots", InventorySlotArray);

						TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&InventoryOutputString);
						FJsonSerializer::Serialize(InventoryJsonObject.ToSharedRef(), Writer);
						//UE_LOG(LogTemp, Log, TEXT("[UMyGameInstance] InventoryOutputString: %s"), *InventoryOutputString);

						// Convert Character Customization data into json friendly 
						// At this stage our character class data has been validated by the server and is safe to store on the backend.
						TSharedPtr<FJsonObject> CharacterJsonObject = MakeShareable(new FJsonObject);
						CharacterJsonObject->SetBoolField("Setup", playerS->CharacterSetup);
						CharacterJsonObject->SetNumberField("characterClass", playerS->CharacterClass);

						TSharedRef< TJsonWriter<> > CharactertWriter = TJsonWriterFactory<>::Create(&CharacterOutputString);
						FJsonSerializer::Serialize(CharacterJsonObject.ToSharedRef(), CharactertWriter);

						activePlayer->currencyCurrent = 0;
						FString nonceString = "10951350917635";
						FString encryption = "off";  // Allowing unencrypted on sandbox for now.

						TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
						PlayerJsonObj->SetStringField("nonce", "nonceString");
						PlayerJsonObj->SetStringField("encryption", encryption);
						PlayerJsonObj->SetStringField("inventory", InventoryOutputString);
						PlayerJsonObj->SetStringField("equipment", "hardcoded test");
						PlayerJsonObj->SetStringField("abilities", AbilitiesOutputString);
						PlayerJsonObj->SetStringField("interface", InterfaceOutputString);
						PlayerJsonObj->SetStringField("character", CharacterOutputString);
						PlayerJsonObj->SetNumberField("rank", activePlayer->rank);
						PlayerJsonObj->SetNumberField("score", activePlayer->score);
						PlayerJsonObj->SetNumberField("level", 1);  // TODO set this up in the struct
						PlayerJsonObj->SetNumberField("experience", activePlayer->experience);
						PlayerJsonObj->SetNumberField("experienceThisLevel", 1);
						PlayerJsonObj->SetNumberField("coordLocationX", 1);
						PlayerJsonObj->SetNumberField("coordLocationY", 1);
						PlayerJsonObj->SetNumberField("coordLocationZ", 1);
						PlayerJsonObj->SetStringField("zoneName", "hardcoded test");
						PlayerJsonObj->SetStringField("zoneKey", "hardcoded test");

						FString JsonOutputString;
						TSharedRef< TJsonWriter<> > FinalWriter = TJsonWriterFactory<>::Create(&JsonOutputString);
						FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), FinalWriter);

						//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SaveGamePlayer - setup output string"));

						if (bAttemptUnLock) {
							PlayerJsonObj->SetBoolField("unlock", true);
						}

						// Only do this if we actually have a gamePlayerKeyId
						// We might not...  If a user was not authorized for example.

						// Check to see if there are any more players, if not...  Save and prepare for server shutdown
						// Only if continuous
						if (UEtopiaMode == "continuous")
						{
							int32 authorizedPlayerCount = getActivePlayerCount();
							if (authorizedPlayerCount > 0)
							{
								UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeActivatePlayer - There are still players authorized on this server."));
							}
							else {
								UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeActivatePlayer - No Authorized players found - moving to save."));

								/*
								bool FileIOSuccess;
								bool allComponentsSaved;
								FString FileName = "serversavedata.dat";
								URamaSaveLibrary::RamaSave_SaveToFile(GetWorld(), FileName, FileIOSuccess, allComponentsSaved);
								if (FileIOSuccess) {
								UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] File IO Success."));
								}
								else {
								UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] File IO FAIL."));
								}
								*/

								// Reset our playstarted flag
								bRequestBeginPlayStarted = false;

								// Tell the backend that it's safe to bring this server down.
								NotifyDownReady();
							}
						}

						

						if (activePlayer->gamePlayerKeyId.Len() > 1) {
							FString access_token = activePlayer->PlayerController->CurrentAccessTokenFromOSS;

							FString APIURI = "/api/v1/game/player/" + activePlayer->gamePlayerKeyId + "/update";

							bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::SaveGamePlayerRequestComplete, APIURI, JsonOutputString, access_token);
							return requestSuccess;
						}
						else {
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - No gamePlayerKeyId found - skipping game player update"));
							return false;

						}
					}
				}
			}
		}
		//  if no playercontroller, use the backed-up data instead

		// Setup variables to hold encoded json data
		//FString CharacterOutputString;

		// Convert Character Customization data into json friendly 
		TSharedPtr<FJsonObject> CharacterJsonObject = MakeShareable(new FJsonObject);
		CharacterJsonObject->SetBoolField("Setup", activePlayer->PSBackupCharacterSetup);
		CharacterJsonObject->SetNumberField("Mesh", activePlayer->PSBackupCharacterMesh);
		CharacterJsonObject->SetNumberField("Gender", activePlayer->PSBackupCharacterGender);

		TSharedRef< TJsonWriter<> > CharactertWriter = TJsonWriterFactory<>::Create(&CharacterOutputString);
		FJsonSerializer::Serialize(CharacterJsonObject.ToSharedRef(), CharactertWriter);


		///////////////////////////////////////////////////////
		// Convert player inventory slots to json friendly array
		TSharedPtr<FJsonObject> InventoryJsonObject = MakeShareable(new FJsonObject);
		InventoryJsonObject->SetNumberField("InventoryCapacity", activePlayer->PSBackupInventoryCapacity);
		TArray< TSharedPtr<FJsonValue> > InventorySlotArray;

		for (int32 InventorySlotIndex = 0; InventorySlotIndex < activePlayer->PSBackupInventorySlots.Num(); InventorySlotIndex++)
		{
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - Found InventorySlotIndex"));
			// only add valid slots
			if (activePlayer->PSBackupInventorySlots[InventorySlotIndex].itemClassTitle != "empty")
			{
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - InventorySlots[InventorySlotIndex].itemClass IsValid "));
				TSharedPtr< FJsonObject > SlotObj = MakeShareable(new FJsonObject);
				SlotObj->SetStringField("ItemId", activePlayer->PSBackupInventorySlots[InventorySlotIndex].itemId);
				SlotObj->SetStringField("ItemTitle", activePlayer->PSBackupInventorySlots[InventorySlotIndex].itemTitle);
				SlotObj->SetStringField("ItemDescription", activePlayer->PSBackupInventorySlots[InventorySlotIndex].itemDescription);
				SlotObj->SetNumberField("Quantity", activePlayer->PSBackupInventorySlots[InventorySlotIndex].quantity);
				SlotObj->SetNumberField("DTID", activePlayer->PSBackupInventorySlots[InventorySlotIndex].DataTableId);

				// Deal with attributes
				FString AttributesOutputString;
				// Convert to json friendly array
				TSharedPtr<FJsonObject> AttributesJsonObject = MakeShareable(new FJsonObject);
				TArray< TSharedPtr<FJsonValue> > AttributesArray;

				for (int attributeIndex = 0; attributeIndex < activePlayer->PSBackupInventorySlots[InventorySlotIndex].Attributes.Num(); attributeIndex++)
				{
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] Found attribute"));

					TSharedPtr< FJsonObject > AttributeObj = MakeShareable(new FJsonObject);
					AttributeObj->SetNumberField(FString::FromInt(attributeIndex), activePlayer->PSBackupInventorySlots[InventorySlotIndex].Attributes[attributeIndex]);
					TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(AttributeObj));
					AttributesArray.Add(JsonValue);
				}

				// For Inventory, we already have a json serialized text area, so we don't need to do it again.
				// Just create a plain array field
				SlotObj->SetArrayField("attributes", AttributesArray);

				TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(SlotObj));
				InventorySlotArray.Add(JsonValue);
			}

		}

		InventoryJsonObject->SetArrayField("InventorySlots", InventorySlotArray);

		TSharedRef< TJsonWriter<> > InventoryWriter = TJsonWriterFactory<>::Create(&InventoryOutputString);
		FJsonSerializer::Serialize(InventoryJsonObject.ToSharedRef(), InventoryWriter);


		///////////////////////////////////////////////////////
		// Convert player equipment slots to json friendly array

		TSharedPtr<FJsonObject> EquipmentJsonObject = MakeShareable(new FJsonObject);
		EquipmentJsonObject->SetNumberField("EquipmentCapacity", 10);
		TArray< TSharedPtr<FJsonValue> > EquipmentSlotArray;

		for (int32 EquipmentSlotIndex = 0; EquipmentSlotIndex < activePlayer->PSBackupMyEquipment.Num(); EquipmentSlotIndex++)
		{
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - Found InventorySlotIndex"));
			// only add valid slots
			if (activePlayer->PSBackupMyEquipment[EquipmentSlotIndex].itemClassTitle != "empty")
			{
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] - InventorySlots[InventorySlotIndex].itemClass IsValid "));
				TSharedPtr< FJsonObject > SlotObj = MakeShareable(new FJsonObject);
				SlotObj->SetStringField("ItemTitle", activePlayer->PSBackupMyEquipment[EquipmentSlotIndex].itemTitle);
				SlotObj->SetNumberField("DTID", activePlayer->PSBackupMyEquipment[EquipmentSlotIndex].DataTableId);

				// Deal with attributes
				FString AttributesOutputString;
				// Convert to json friendly array
				TSharedPtr<FJsonObject> AttributesJsonObject = MakeShareable(new FJsonObject);
				TArray< TSharedPtr<FJsonValue> > AttributesArray;

				for (int attributeIndex = 0; attributeIndex < activePlayer->PSBackupMyEquipment[EquipmentSlotIndex].Attributes.Num(); attributeIndex++)
				{
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SaveGamePlayer] Found attribute"));

					TSharedPtr< FJsonObject > AttributeObj = MakeShareable(new FJsonObject);
					AttributeObj->SetNumberField(FString::FromInt(attributeIndex), activePlayer->PSBackupMyEquipment[EquipmentSlotIndex].Attributes[attributeIndex]);
					TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(AttributeObj));
					AttributesArray.Add(JsonValue);
				}

				// For Inventory, we already have a json serialized text area, so we don't need to do it again.
				// Just create a plain array field
				SlotObj->SetArrayField("attributes", AttributesArray);

				TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(SlotObj));
				EquipmentSlotArray.Add(JsonValue);
			}

		}

		EquipmentJsonObject->SetArrayField("EquipmentSlots", EquipmentSlotArray);

		TSharedRef< TJsonWriter<> > EquipmentWriter = TJsonWriterFactory<>::Create(&EquipmentOutputString);
		FJsonSerializer::Serialize(EquipmentJsonObject.ToSharedRef(), EquipmentWriter);


		FString nonceString = "10951350917635";
		FString encryption = "off";  // Allowing unencrypted on sandbox for now.  

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("inventory", InventoryOutputString);
		PlayerJsonObj->SetStringField("equipment", EquipmentOutputString);
		PlayerJsonObj->SetStringField("abilities", "hardcoded test");
		PlayerJsonObj->SetStringField("interface", "hardcoded test");
		PlayerJsonObj->SetStringField("crafting", "hardcoded test");
		PlayerJsonObj->SetStringField("recipes", "hardcoded test");
		PlayerJsonObj->SetStringField("character", CharacterOutputString);
		PlayerJsonObj->SetNumberField("rank", Rank);
		PlayerJsonObj->SetNumberField("score", Score);

		PlayerJsonObj->SetNumberField("experience", Experience);
		PlayerJsonObj->SetNumberField("experienceThisLevel", ExperienceThisLevel);
		PlayerJsonObj->SetNumberField("level", Level);

		if (bAttemptUnLock) {
			PlayerJsonObj->SetBoolField("unlock", true);
		}

		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		//FString access_token = PlayerController->CurrentAccessTokenFromOSS;
		FString access_token = "";

		FString APIURI = "/api/v1/game/player/" + gamePlayerKeyId + "/update";

		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::SaveGamePlayerRequestComplete, APIURI, JsonOutputString, access_token);

		//return requestSuccess;


	}

	// Check to see if there are any more players, if not...  Save and prepare for server shutdown
	// Only if continuous
	if (UEtopiaMode == "continuous")
	{
		int32 authorizedPlayerCount = getActivePlayerCount();
		if (authorizedPlayerCount > 0)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeActivatePlayer - There are still players authorized on this server."));
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeActivatePlayer - No Authorized players found - moving to save."));

			/*
			bool FileIOSuccess;
			bool allComponentsSaved;
			FString FileName = "serversavedata.dat";
			URamaSaveLibrary::RamaSave_SaveToFile(GetWorld(), FileName, FileIOSuccess, allComponentsSaved);
			if (FileIOSuccess) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] File IO Success."));
			}
			else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] File IO FAIL."));
			}
			*/

			// Reset our playstarted flag
			bRequestBeginPlayStarted = false;

			// Tell the backend that it's safe to bring this server down.
			NotifyDownReady();
		}
	}
	return false;
}

void UMyGameInstance::SaveGamePlayerRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			//UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
			}
		}
	}
}



bool UMyGameInstance::DeActivatePlayer(int32 playerID)
{
	if (IsRunningDedicatedServer()) {

		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeActivatePlayer"));

		if (UEtopiaMode == "competitive") {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer - Mode set to competitive"));

			FMyActivePlayer* CurrentActivePlayer = getPlayerByPlayerId(playerID);
			if (CurrentActivePlayer) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer - existing playerID found"));
				// TODO match player deactivate
			}

		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer - Mode set to continuous"));

			FMyActivePlayer* CurrentActivePlayer = getPlayerByPlayerId(playerID);

			if (CurrentActivePlayer) {
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer - existing playerID found"));

				// make sure they were not deactivated through transfer first!
				if (CurrentActivePlayer->deactivateStarted)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer - deactivate already started."));
					return false;
				}

				FString GamePlayerKeyIdString = CurrentActivePlayer->gamePlayerKeyId;
				FString playerKeyId = CurrentActivePlayer->userKeyId;

				CurrentActivePlayer->authorized = false;
				CurrentActivePlayer->deactivateStarted = true;

				FString access_token = CurrentActivePlayer->PlayerController->CurrentAccessTokenFromOSS;
				FString nonceString = "10951350917635";
				FString encryption = "off";  // Allowing unencrypted on sandbox for now.
				FString OutputString;

				// Build Params as text string
				OutputString = "nonce=" + nonceString + "&encryption=" + encryption;
				// urlencode the params

				FString APIURI = "/api/v1/server/player/" + playerKeyId + "/deactivate";
				bool requestSuccess = PerformHttpRequest(&UMyGameInstance::DeActivateRequestComplete, APIURI, OutputString, access_token);
				SaveGamePlayer(CurrentActivePlayer->userKeyId, true);

				//  cleanup any TravelAuthorizedActors that this player owns.
				APlayerState* thisPlayerState = CurrentActivePlayer->PlayerController->PlayerState;
				AMyPlayerState* playerS = nullptr;
				playerS = Cast<AMyPlayerState>(thisPlayerState);

				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer - Found a playerState"));
				// delete the travel approved actors from the world
				for (int i = 0; i < playerS->ServerTravelApprovedActors.Num(); i++)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer Found playerS->ServerTravelApprovedActors"));
					playerS->ServerTravelApprovedActors[i]->Destroy();
				}
				playerS->ServerLinksAuthorized.Empty();
				playerS->ServerTravelApprovedActors.Empty();
			}
			else {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeAuthorizePlayer - Not found - Ignoring"));
			}
		}
	}
	return true;
}

void UMyGameInstance::DeActivateRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			//  We don't care too much about the results from this call.
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization False"));
			}
		}
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [DeActivateRequestComplete] Done!"));
}


bool UMyGameInstance::BackupExitingPlayerState(int32 playerID, AMyPlayerState* playerState)
{
	// this only runs serverside
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] BackupExitingPlayerState"));

	if (UEtopiaMode == "competitive") {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] BackupExitingPlayerState - Mode set to competitive"));

		FMyActivePlayer* CurrentActivePlayer = getPlayerByPlayerId(playerID);
		if (CurrentActivePlayer) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] BackupExitingPlayerState - existing playerID found"));

			CurrentActivePlayer->PSBackupCharacterSetup = playerState->CharacterSetup;
			CurrentActivePlayer->PSBackupInventorySlots = playerState->InventorySlots;
			CurrentActivePlayer->PSBackupMyEquipment = playerState->MyEquipment;
			CurrentActivePlayer->PSBackupInventoryCapacity = playerState->InventoryCapacity;

			// Trying putting this here instead of deactivate.
			CurrentActivePlayer->bIsConnected = false;

			// Also set a flag so we know that this player has a playerstate backup
			CurrentActivePlayer->bWasConnected = true;

			return true;

		}

	}
	else {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] BackupExitingPlayerState - Mode set to continuous"));

		FMyActivePlayer* CurrentActivePlayer = getPlayerByPlayerId(playerID);
		if (CurrentActivePlayer) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] BackupExitingPlayerState - existing playerID found"));

			return true;
		}
	}
	return false;
}

bool UMyGameInstance::RestoreJoiningPlayerState(FString playerKeyId)
{
	// this only runs serverside
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] RestoreJoiningPlayerState"));

	// Keep track of the playerState and playerCharacter that is associated with this player
	APlayerState* thisPlayerState;
	AMyPlayerState* playerS = nullptr;

	AMyPlayerController* PlayerController = nullptr;
	FString playerArrayplayerKeyId;
	FMyActivePlayer* activePlayer = nullptr;

	//playerC = PlayerController

	// For very simple match based games, gamePlayer data is not required.
	// But for more advanced match games, with persistent user data, the getGamePlayer call is required.
	// So we'll need to distinguish here if we are running in competitive or continuous mode.
	// TODO - revisit this.  Merging "ActivePlayers" and "MatchPlayers" into a single array seems like a possible solution.

	if (UEtopiaMode == "competitive")
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RestoreJoiningPlayerState] - Mode set to competitive"));

		activePlayer = getPlayerByPlayerKey(playerKeyId);
		playerArrayplayerKeyId = activePlayer->userKeyId;

		if (activePlayer)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RestoreJoiningPlayerState] - Found activePlayer"));

			activePlayer->gamePlayerDataLoaded = true;

			PlayerController = Cast<AMyPlayerController>(activePlayer->PlayerController);
			if (PlayerController)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RestoreJoiningPlayerState] - Found PlayerController"));

				thisPlayerState = PlayerController->PlayerState;
				playerS = Cast<AMyPlayerState>(thisPlayerState);

				if (playerS)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RestoreJoiningPlayerState] - Found playerState"));

					playerS->CharacterSetup = activePlayer->PSBackupCharacterSetup;
					playerS->InventorySlots = activePlayer->PSBackupInventorySlots;
					playerS->MyEquipment = activePlayer->PSBackupMyEquipment;
					playerS->InventoryCapacity = activePlayer->PSBackupInventoryCapacity;

					return true;
				}
			}
		}
	}


	return false;
}


bool UMyGameInstance::ReconnectPlayer(class AMyPlayerController* NewPlayerController, FString playerKeyId, int32 playerID, const FUniqueNetIdRepl& UniqueId)
{

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] ReconnectPlayer"));

	// Stick the playerKeyID in the playerState so we can find this player later.
	FMyActivePlayer* activePlayer = nullptr;
	APlayerState* thisPlayerState = NewPlayerController->PlayerState;
	AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);
	playerS->playerKeyId = playerKeyId;

	// it's always competitive now
	activePlayer = getPlayerByPlayerKey(playerKeyId);

	if (activePlayer)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ReconnectPlayer] - Found activePlayer"));

		activePlayer->PlayerController = NewPlayerController;
		activePlayer->bIsConnected = true;

		// TODO - missing some things in here.  Player lost all inventory and such
		activePlayer->joined = true;
		activePlayer->currentRoundAlive = true;

		// And set combatEnabled
		playerS->bCombatEnabled = combatEnabled;

		// Bind the timer delegate
		activePlayer->GetPlayerInfoTimerDel.BindUFunction(this, FName("GetGamePlayer"), playerKeyId, true);
		// Set the timer
		GetWorld()->GetTimerManager().SetTimer(activePlayer->GetPlayerInfoDelayHandle, activePlayer->GetPlayerInfoTimerDel, 1.f, false);

		return true;

	}

	return false;

}

void UMyGameInstance::TransferPlayer(const FString& ServerKey, int32 playerID, bool checkOnly, bool toShard)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] TransferPlayer"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.
	FString checkOnlyStr = "";
	if (checkOnly) {
		checkOnlyStr = "true";
	}
	else {
		checkOnlyStr = "false";
	}
	FString OutputString = "nonce=" + nonceString + "&encryption=" + encryption + "&checkOnly=" + checkOnlyStr;

	FMyActivePlayer* playerRecord = getPlayerByPlayerId(playerID);
	if (playerRecord == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] TransferPlayer - Player NOT found by Id"));
		return;
	}

	FString playerplayerKeyId = playerRecord->userKeyId;
	bool permissionCanUserTravel = false;

	if (toShard)
	{
		permissionCanUserTravel = true;
	}
	else
	{
		FMyServerLink* serverRecord = getServerByKey(ServerKey);
		if (serverRecord->permissionCanUserTravel)
		{
			permissionCanUserTravel = true;
		}
	}

	if (permissionCanUserTravel)
	{
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] TransferPlayer - Permission Granted"));
		FString access_token = playerRecord->PlayerController->CurrentAccessTokenFromOSS;

		FString APIURI = "/api/v1/server/" + ServerKey + "/player/" + playerplayerKeyId + "/transfer";
		bool requestSuccess = PerformHttpRequest(&UMyGameInstance::TransferPlayerRequestComplete, APIURI, OutputString, access_token);

		if (!checkOnly)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] TransferPlayer - Checkonly is false"));
		}
		return;
	}
	else {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] TransferPlayer - Permission NOT Granted"));
		return;
	}

}


void UMyGameInstance::TransferPlayerRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));

				// Starting over with this

				// First check to see if this was a checkOnly request
				// checkOnly performs the tests, but does not initiate the transfer.  This allows us to populate the user's portal list:  ServerPortalKeyIdsAuthorized

				// If it was a full transfer request, we can do any cleanups of old stuff.
				// TODO - cleanups?

				// Print out our incoming information
				FString targetServerKeyId = JsonParsed->GetStringField("targetServerKeyId");
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] targetServerKeyId: %s"), *targetServerKeyId);
				FString userKeyId = JsonParsed->GetStringField("userKeyId");
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] userKeyId: %s"), *userKeyId);
				FString checkOnly = JsonParsed->GetStringField("checkOnly");
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] checkOnly: %s"), *checkOnly);
				bool allowedToTravel = JsonParsed->GetBoolField("success");
				if (allowedToTravel) {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] allowedToTravel: TRUE"));
				}
				else {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] allowedToTravel: FALSE"));
				}

				bool toShard = JsonParsed->GetBoolField("toShard");
				if (toShard) {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] toShard: TRUE"));
				}
				else {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] toShard: FALSE"));
				}

				// Get the additional fields to support instanced servers
				bool instanceServerTemplate = JsonParsed->GetBoolField("instanceServerTemplate");
				FString instanceServerKeyId = JsonParsed->GetStringField("instanceServerKeyId");
				bool instanceCreating = JsonParsed->GetBoolField("instanceCreating");
				bool instanceProvisioned = JsonParsed->GetBoolField("instanceProvisioned");
				bool instanceOnline = JsonParsed->GetBoolField("instanceOnline");
				FString instanceHostConnectionLink = JsonParsed->GetStringField("instanceHostConnectionLink");
				FString instanceSessionHostAddress = JsonParsed->GetStringField("instanceSessionHostAddress");
				FString instanceSessionId = JsonParsed->GetStringField("instanceSessionId");


				for (int i = 0; i < ServerLinks.links.Num(); i++)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] Found serverlink"));
				}

				// get the player
				FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(userKeyId);

				// Deal with shard to shard travel
				if (toShard)
				{
					if (allowedToTravel)
					{
						
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] ActivePlayer->UniqueId: %s"), *ActivePlayer->UniqueId->ToString());
						AMyPlayerController* pc = ActivePlayer->PlayerController;

						DeActivatePlayer(ActivePlayer->playerID);
						pc->ExecuteClientTravel(instanceHostConnectionLink);
					}

				}
				else
				{
					if (checkOnly == "true") {
						
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] ActivePlayer->UniqueId: %s"), *ActivePlayer->UniqueId->ToString());

						//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] - looking for a playerKeyId match"));
						AMyPlayerController* pc = ActivePlayer->PlayerController;

						APlayerState* thisPlayerState = pc->PlayerState;
						AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);


						if (playerS)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] - Found a playerState with matching playerKeyID"));
							UE_LOG(LogTemp, Log, TEXT("playerS->PlayerId: %d"), thisPlayerState->PlayerId);

							// Instanced servers have different keys and need to be handled differently.
							// Since we can't poll for these server links on a global basis, we'll get the status on a transfer request.
							// We need to update all of the server link information after every transfer request like this one.

							if (allowedToTravel) {

								// check to see if this key is already in the array
								bool foundServerLinkAuthorized = false;
								for (int sla = 0; sla < playerS->ServerLinksAuthorized.Num(); sla++)
								{
									UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] Found ServerLinkAuthorized"));
									if (playerS->ServerLinksAuthorized[sla].targetServerKeyId == targetServerKeyId)
									{
										UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] Found Matching ServerLinkAuthorized"));

										// update the record
										playerS->ServerLinksAuthorized[sla].hostConnectionLink = instanceHostConnectionLink;
										foundServerLinkAuthorized = true;
									}
								}

								if (!foundServerLinkAuthorized)
								{
									FMyApprovedServerLink newApprovedLink;
									newApprovedLink.hostConnectionLink = instanceHostConnectionLink;
									newApprovedLink.targetServerKeyId = targetServerKeyId;
									playerS->ServerLinksAuthorized.Add(newApprovedLink);
								}

								// Spawn and setup the travelapproved actor visible only to the owner
								FMyServerLink thisServerLink = GetServerLinkByTargetServerKeyId(targetServerKeyId);

								// check in case the server link is not found or does not exist.
								if (thisServerLink.targetServerKeyId.IsEmpty()) {
									UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] - thisServerLink.targetServerKeyId.IsEmpty - aborting TravelApproval"));
									return;
								}


								UWorld* const World = GetWorld(); // get a reference to the world
								if (World) {
									//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] - Spawning a TravelApprovedActor"));

									FVector spawnlocation = FVector(thisServerLink.coordLocationX, thisServerLink.coordLocationY, thisServerLink.coordLocationZ);
									FTransform SpawnTransform = FTransform(spawnlocation);
									SpawnTransform.SetScale3D(FVector(2.5f, 2.5f, 2.5f));
									SpawnTransform.SetRotation(FRotator(thisServerLink.rotationX, thisServerLink.rotationY, thisServerLink.rotationZ).Quaternion());

									// Send RPC to the client to spawn it.
									pc->ClientTravelApprovedSpawnActor(SpawnTransform);

								}
							}
						}

					}
					else
					{
						if (allowedToTravel) {
							
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [TransferPlayerRequestComplete] ActivePlayer->UniqueId: %s"), *ActivePlayer->UniqueId->ToString());
							AMyPlayerController* pc = ActivePlayer->PlayerController;

							pc->ExecuteClientTravel(instanceHostConnectionLink);
							DeActivatePlayer(ActivePlayer->playerID);
						}
					}
				}
			}
		}
	}
}




bool UMyGameInstance::Purchase(FString playerKeyId, FString itemName, FString description, int32 amount)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] Purchase"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);
	PlayerJsonObj->SetStringField("itemName", itemName);
	PlayerJsonObj->SetStringField("description", description);
	PlayerJsonObj->SetNumberField("amount", amount);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/server/player/" + playerKeyId + "/purchase";

	FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(playerKeyId);
	if (ActivePlayer)
	{
		FString access_token = ActivePlayer->PlayerController->CurrentAccessTokenFromOSS;
		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::PurchaseRequestComplete, APIURI, JsonOutputString, access_token);
		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::PurchaseRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					FString userKeyId = JsonParsed->GetStringField("userKeyId");
					FString itemName = JsonParsed->GetStringField("itemName");
					int32 purchaseAmount = JsonParsed->GetNumberField("amount");

					FMyActivePlayer* playerRecord = getPlayerByPlayerKey(userKeyId);
					if (playerRecord == nullptr)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] TransferPlayer - Player NOT found by Key"));
						return;
					}

					APlayerController* pc = Cast<AMyPlayerController>(playerRecord->PlayerController);
					APlayerState* thisPlayerState = pc->PlayerState;
					AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);

					if (playerS)
					{
						// Do whatever you want with your result here.
						// Data Tables most likely.

						if (itemName == "Cube") {
							UE_LOG(LogTemp, Log, TEXT("Purchase was a cube"));
							// put the item in the player inventory 


						}
						// update player currency balance
						playerRecord->currencyCurrent = playerRecord->currencyCurrent - purchaseAmount;
						playerS->Currency = playerS->Currency - purchaseAmount;
					}
				}
			}
		}
	}
}


bool UMyGameInstance::VendorCreate(FString userKeyId, FString VendorTypeKeyId, float coordLocationX, float coordLocationY, float coordLocationZ, float forwardVecX, float forwardVecY, float forwardVecZ)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorCreate"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);
	PlayerJsonObj->SetStringField("userKeyId", userKeyId);
	PlayerJsonObj->SetStringField("vendorTypeKeyId", VendorTypeKeyId);
	//PlayerJsonObj->SetStringField("VendorTemporaryKeyId", VendorTemporaryKeyId);
	PlayerJsonObj->SetNumberField("coordLocationX", coordLocationX);
	PlayerJsonObj->SetNumberField("coordLocationY", coordLocationY);
	PlayerJsonObj->SetNumberField("coordLocationZ", coordLocationZ);
	PlayerJsonObj->SetNumberField("forwardVecX", forwardVecX);
	PlayerJsonObj->SetNumberField("forwardVecY", forwardVecY);
	PlayerJsonObj->SetNumberField("forwardVecZ", forwardVecZ);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/server/vendor/create";

	FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(userKeyId);
	if (ActivePlayer)
	{
		FString access_token = ActivePlayer->PlayerController->CurrentAccessTokenFromOSS;
		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorCreateRequestComplete, APIURI, JsonOutputString, access_token);
		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorCreateRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					FString createdByUserKeyId = JsonParsed->GetStringField("createdByUserKeyId");
					FString vendorKeyId = JsonParsed->GetStringField("vendorKeyId");
					FString VendorTypeKeyId = JsonParsed->GetStringField("VendorTypeKeyId");

					float coordLocationX = JsonParsed->GetNumberField("coordLocationX");
					float coordLocationY = JsonParsed->GetNumberField("coordLocationY");
					float coordLocationZ = JsonParsed->GetNumberField("coordLocationZ");
					float forwardVecX = JsonParsed->GetNumberField("forwardVecX");
					float forwardVecY = JsonParsed->GetNumberField("forwardVecY");
					float forwardVecZ = JsonParsed->GetNumberField("forwardVecZ");

					FString title = JsonParsed->GetStringField("title");
					FString description = JsonParsed->GetStringField("description");

					int32 buyingMax = JsonParsed->GetNumberField("buyingMax");
					int32 sellingMax = JsonParsed->GetNumberField("sellingMax");

					float transactionTaxPercentageToServer = JsonParsed->GetNumberField("transactionTaxPercentageToServer");

					FString engineActorAsset = JsonParsed->GetStringField("engineActorAsset");

					FMyActivePlayer* playerRecord = getPlayerByPlayerKey(createdByUserKeyId);
					if (playerRecord == nullptr)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorCreateRequestComplete - Player NOT found by Key"));
						return;
					}

					// reconstruct the FTransform
					// reconstruct the Forward Vector
					FVector VendorForwardVector = FVector(forwardVecX, forwardVecY, forwardVecZ);
					FVector VendorLocation = FVector(coordLocationX, coordLocationY, coordLocationZ);
					FTransform VendorTransform = FTransform(VendorForwardVector.Rotation(), VendorLocation);

					UWorld* World = GetWorld(); // get a reference to the world
					if (World)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptSpawnActor_Implementation] got world "));
						// if world exists, spawn the blueprint actor

						UClass* LoadedActorOwnerClass;
						LoadedActorOwnerClass = LoadClassFromPath(engineActorAsset);

						AMyBaseVendor* thisActor = World->SpawnActor<AMyBaseVendor>(LoadedActorOwnerClass, VendorTransform);

						// setup values for an owned vendor
						thisActor->VendorKeyId = vendorKeyId;
						thisActor->OwnerUserKeyId = createdByUserKeyId;
						thisActor->bAnyoneCanPickUp = false;
						thisActor->bOwnerCanPickUp = false;  // have to switch this off in edit vendor if it should be able to be picked up again.
						thisActor->VendorTypeKeyId = VendorTypeKeyId;
					}
				}
			}
		}
	}
}



bool UMyGameInstance::VendorUpdate(FString userKeyId, FString VendorKeyId, FString Title, FString Description, FString DiscordWebhook, bool bIsSelling, bool bIsBuying, bool bDisable)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorUpdate"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);
	PlayerJsonObj->SetStringField("userKeyId", userKeyId);
	//PlayerJsonObj->SetStringField("vendorKeyId", VendorKeyId);
	//PlayerJsonObj->SetStringField("VendorTemporaryKeyId", VendorTemporaryKeyId);
	PlayerJsonObj->SetStringField("title", Title);
	PlayerJsonObj->SetStringField("description", Description);
	PlayerJsonObj->SetStringField("discordWebhook", DiscordWebhook);
	PlayerJsonObj->SetBoolField("selling", bIsSelling);
	PlayerJsonObj->SetBoolField("buying", bIsBuying);
	PlayerJsonObj->SetBoolField("disable", bDisable);


	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/update";

	FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(userKeyId);
	if (ActivePlayer)
	{
		FString access_token = ActivePlayer->PlayerController->CurrentAccessTokenFromOSS;
		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorUpdateRequestComplete, APIURI, JsonOutputString, access_token);
		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorUpdateRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success)
				{
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// TODO maybe trigger a refresh for the player that initiated the update.
					bool CanDisable = JsonParsed->GetBoolField("can_disable");
					if (CanDisable)
					{
						UE_LOG(LogTemp, Log, TEXT("CanDisable True")); // the user wants to pack this vendor up.
						FString VendorKeyId = JsonParsed->GetStringField("key_id");
						// Find the vendor, and mark it bOwnerCanPickUp = true
						for (TActorIterator<AMyBaseVendor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
						{
							// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
							AMyBaseVendor *Vendor = *ActorItr;
							if (Vendor->VendorKeyId == VendorKeyId)
							{
								UE_LOG(LogTemp, Log, TEXT("Found the vendor in the world.  Marking as bOwnerCanPickUp"));
								Vendor->bOwnerCanPickUp = true;
							}

						}

					}
				}
			}
		}
	}
}


bool UMyGameInstance::VendorDelete(FString userKeyId, FString VendorKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorDelete"));

	// Vendors that are not owned by any player will not have a KeyId, and they will not be "real" they are just inventory objects at this point.
	// So if we don't have a KeyId, don't try to delete it.

	if (!VendorKeyId.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorDelete found VendorKeyId"));

		FString nonceString = "10951350917635";
		FString encryption = "off";  // Allowing unencrypted on sandbox for now.

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("userKeyId", userKeyId);
		//PlayerJsonObj->SetStringField("VendorKeyId", VendorKeyId);


		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/delete";

		FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(userKeyId);
		if (ActivePlayer)
		{
			FString access_token = ActivePlayer->PlayerController->CurrentAccessTokenFromOSS;
			bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorDeleteRequestComplete, APIURI, JsonOutputString, access_token);
			return requestSuccess;
		}

		return false;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorDelete did not find VendorKeyId - skipping"));
	}

	return false;
}

void UMyGameInstance::VendorDeleteRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// we don't care too much about this data other than it worked.
				}
			}
		}
	}
}


bool UMyGameInstance::VendorItemCreate(AMyPlayerController* playerController, FString VendorKeyId, int32 index, int32 pricePerUnit)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemCreate"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(playerController->PlayerState);

	if (myPlayerState)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemCreate got myPlayerState"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("userKeyId", myPlayerState->playerKeyId);
		//PlayerJsonObj->SetStringField("vendorTypeKeyId", VendorTypeKeyId);
		//PlayerJsonObj->SetStringField("VendorTemporaryKeyId", VendorTemporaryKeyId);
		PlayerJsonObj->SetNumberField("quantity", myPlayerState->InventorySlots[index].quantity);
		PlayerJsonObj->SetNumberField("pricePerUnit", pricePerUnit);
		PlayerJsonObj->SetStringField("title", myPlayerState->InventorySlots[index].itemTitle);
		PlayerJsonObj->SetStringField("description", myPlayerState->InventorySlots[index].itemDescription);
		PlayerJsonObj->SetStringField("blueprintPath", myPlayerState->InventorySlots[index].itemClassPath);

		// Deal with attributes
		//////////////////////////////////////////////////////////////
		FString AttributesOutputString;
		// Convert to json friendly array
		TSharedPtr<FJsonObject> AttributesJsonObject = MakeShareable(new FJsonObject);
		TArray< TSharedPtr<FJsonValue> > AttributesArray;

		for (int attributeIndex = 0; attributeIndex < myPlayerState->InventorySlots[index].Attributes.Num(); attributeIndex++)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [VendorItemCreate] Found attribute"));

			TSharedPtr< FJsonObject > AttributeObj = MakeShareable(new FJsonObject);
			AttributeObj->SetNumberField(FString::FromInt(attributeIndex), myPlayerState->InventorySlots[index].Attributes[attributeIndex]);
			TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(AttributeObj));
			AttributesArray.Add(JsonValue);
		}

		AttributesJsonObject->SetArrayField("attributes", AttributesArray);
		TSharedRef< TJsonWriter<> > AttrbutesWriter = TJsonWriterFactory<>::Create(&AttributesOutputString);
		FJsonSerializer::Serialize(AttributesJsonObject.ToSharedRef(), AttrbutesWriter);
		UE_LOG(LogTemp, Log, TEXT("[UMyGameInstance] AttributesOutputString: %s"), *AttributesOutputString);

		PlayerJsonObj->SetStringField("attributes", AttributesOutputString);

		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/item/create";

		FString access_token = playerController->CurrentAccessTokenFromOSS;

		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorItemCreateRequestComplete, APIURI, JsonOutputString, access_token);

		// TODO thnk this through - we might want to just lock the inventory item so that the user can't do anything with it until the request completes.

		// For now, just deleting it.
		playerController->ServerAttemptRemoveItemAtIndex_Implementation(index, myPlayerState->InventorySlots[index].quantity);

		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorItemCreateRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// TODO - refresh the vendor item list.
				}
			}
		}
	}
}


bool UMyGameInstance::VendorItemDelete(AMyPlayerController* playerController, FString VendorKeyId, FString VendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemDelete"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(playerController->PlayerState);

	if (myPlayerState)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemDelete got myPlayerState"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("userKeyId", myPlayerState->playerKeyId);
		//PlayerJsonObj->SetStringField("vendorTypeKeyId", VendorTypeKeyId);
		//PlayerJsonObj->SetStringField("VendorTemporaryKeyId", VendorTemporaryKeyId);

		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/item/" + VendorItemKeyId + "/delete";

		FString access_token = playerController->CurrentAccessTokenFromOSS;

		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorItemDeleteRequestComplete, APIURI, JsonOutputString, access_token);

		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorItemDeleteRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// put the item in inventory

					FString bpItemClassStr;
					JsonParsed->TryGetStringField("blueprintPath", bpItemClassStr);

					UClass* LoadedActorOwnerClass;
					LoadedActorOwnerClass = LoadClassFromPath(bpItemClassStr);

					if (LoadedActorOwnerClass)
					{
						UE_LOG(LogTemp, Log, TEXT("Found LoadedActorOwnerClass"));

						AMyBasePickup* basePickupBP = Cast<AMyBasePickup>(LoadedActorOwnerClass->GetDefaultObject());
						if (basePickupBP) {
							UE_LOG(LogTemp, Log, TEXT("Found basePickupBP"));

							// set up vars
							FString userKeyId;
							JsonParsed->TryGetStringField("userKeyId", userKeyId);
							int32 quantity;
							JsonParsed->TryGetNumberField("quantityAvailable", quantity);
							FString savedAttributes;
							JsonParsed->TryGetStringField("attributes", savedAttributes);

							// Clear default attributes
							basePickupBP->Attributes.Empty();

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

										basePickupBP->Attributes.Add(JsonValue);
									}
									currentIndex++;
								}
							}

							// get the character controller that matches our userKeyId
							FMyActivePlayer* thisPlayer = getPlayerByPlayerKey(userKeyId);
							thisPlayer->PlayerController->AddItem(basePickupBP, quantity, false);

						}
					}
				}
			}
		}
	}
}


bool UMyGameInstance::VendorItemBuy(AMyPlayerController* playerController, FString VendorKeyId, FString VendorItemKeyId, int32 quantity)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemDelete"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(playerController->PlayerState);

	if (myPlayerState)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemDelete got myPlayerState"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("userKeyId", myPlayerState->playerKeyId);
		PlayerJsonObj->SetNumberField("quantity", quantity);

		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/item/" + VendorItemKeyId + "/buy";
		FString access_token = playerController->CurrentAccessTokenFromOSS;

		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorItemBuyRequestComplete, APIURI, JsonOutputString, access_token);

		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorItemBuyRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// TODO - put the item in inventory

					FString bpItemClassStr;
					JsonParsed->TryGetStringField("blueprintPath", bpItemClassStr);

					UClass* LoadedActorOwnerClass;
					LoadedActorOwnerClass = LoadClassFromPath(bpItemClassStr);

					if (LoadedActorOwnerClass)
					{
						UE_LOG(LogTemp, Log, TEXT("Found LoadedActorOwnerClass"));

						AMyBasePickup* basePickupBP = Cast<AMyBasePickup>(LoadedActorOwnerClass->GetDefaultObject());
						if (basePickupBP) {
							UE_LOG(LogTemp, Log, TEXT("Found basePickupBP"));

							// get the character controller that matches our userKeyId
							FString userKeyId;
							JsonParsed->TryGetStringField("userKeyId", userKeyId);
							int32 quantity;
							JsonParsed->TryGetNumberField("quantityBought", quantity);
							int32 pricePerUnit;
							JsonParsed->TryGetNumberField("pricePerUnit", pricePerUnit);

							UE_LOG(LogTemp, Log, TEXT("Quantity: %d Price Per Unit: %d"),
								quantity,
								pricePerUnit);

							int32 currencySpent = quantity * pricePerUnit;

							FString savedAttributes;
							JsonParsed->TryGetStringField("attributes", savedAttributes);

							// Clear default attributes
							basePickupBP->Attributes.Empty();

							// parse Attributes from JSON
							// at this point we have a JSON encoded string:  savedAttributes

							bool AttributeParseSuccess = false;
							TSharedPtr<FJsonObject> AttributesJsonParsed;
							TSharedRef<TJsonReader<TCHAR>> AttributesJsonReader = TJsonReaderFactory<TCHAR>::Create(savedAttributes);

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

										basePickupBP->Attributes.Add(JsonValue);
									}
									currentIndex++;
								}
							}
							FMyActivePlayer* thisPlayer = getPlayerByPlayerKey(userKeyId);

							
							thisPlayer->PlayerController->AddItem(basePickupBP, quantity, false);

							AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(thisPlayer->PlayerController->PlayerState);
							if (myPlayerState)
							{
								myPlayerState->Currency = myPlayerState->Currency - currencySpent;
							}
							

						}
					}
				}
			}
		}
	}
}


bool UMyGameInstance::VendorWithdraw(AMyPlayerController* playerController, FString VendorKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorWithdraw"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(playerController->PlayerState);

	if (myPlayerState)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemDelete got myPlayerState"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("userKeyId", myPlayerState->playerKeyId);

		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/withdraw";
		FString access_token = playerController->CurrentAccessTokenFromOSS;

		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorWithdrawRequestComplete, APIURI, JsonOutputString, access_token);

		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorWithdrawRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success)
				{
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// TODO - add the currency to the player

					FString userKeyId;
					JsonParsed->TryGetStringField("userKeyId", userKeyId);

					int32 transaction_amount;
					JsonParsed->TryGetNumberField("transaction_amount", transaction_amount);

					FMyActivePlayer* thisPlayer = getPlayerByPlayerKey(userKeyId);

					AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayer->PlayerController->PlayerState);
					if (playerS)
					{
						playerS->Currency = playerS->Currency + transaction_amount;

					}
				}
			}
		}
	}
}


bool UMyGameInstance::VendorOfferDecline(AMyPlayerController* playerController, FString VendorKeyId, FString VendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorOfferDecline"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(playerController->PlayerState);

	if (myPlayerState)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemDelete got myPlayerState"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("userKeyId", myPlayerState->playerKeyId);

		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/item/" + VendorItemKeyId + "/decline";
		FString access_token = playerController->CurrentAccessTokenFromOSS;

		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorOfferDeclineRequestComplete, APIURI, JsonOutputString, access_token);

		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorOfferDeclineRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// WE don't have to do anything with this.
					// Maybe display a success or something.
				}
			}
		}
	}
}


bool UMyGameInstance::VendorItemClaim(AMyPlayerController* playerController, FString VendorKeyId, FString VendorItemKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemClaim"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(playerController->PlayerState);

	if (myPlayerState)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] VendorItemClaim got myPlayerState"));

		TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
		PlayerJsonObj->SetStringField("nonce", "nonceString");
		PlayerJsonObj->SetStringField("encryption", encryption);
		PlayerJsonObj->SetStringField("userKeyId", myPlayerState->playerKeyId);
		//PlayerJsonObj->SetNumberField("quantity", quantity);

		FString JsonOutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
		FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

		FString APIURI = "/api/v1/server/vendor/" + VendorKeyId + "/item/" + VendorItemKeyId + "/claim";
		FString access_token = playerController->CurrentAccessTokenFromOSS;

		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::VendorItemClaimRequestComplete, APIURI, JsonOutputString, access_token);

		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::VendorItemClaimRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					// TODO - put the item in inventory

					FString bpItemClassStr;
					JsonParsed->TryGetStringField("blueprintPath", bpItemClassStr);

					UClass* LoadedActorOwnerClass;
					LoadedActorOwnerClass = LoadClassFromPath(bpItemClassStr);

					if (LoadedActorOwnerClass)
					{
						UE_LOG(LogTemp, Log, TEXT("Found LoadedActorOwnerClass"));

						AMyBasePickup* basePickupBP = Cast<AMyBasePickup>(LoadedActorOwnerClass->GetDefaultObject());
						if (basePickupBP) {
							UE_LOG(LogTemp, Log, TEXT("Found basePickupBP"));

							// set up vars
							FString userKeyId;
							JsonParsed->TryGetStringField("userKeyId", userKeyId);
							int32 quantity;
							JsonParsed->TryGetNumberField("quantityAvailable", quantity);

							FString savedAttributes;
							JsonParsed->TryGetStringField("attributes", savedAttributes);

							// Clear default attributes
							basePickupBP->Attributes.Empty();

							// parse Attributes from JSON
							// at this point we have a JSON encoded string:  savedAttributes

							bool AttributeParseSuccess = false;
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

										basePickupBP->Attributes.Add(JsonValue);
									}
									currentIndex++;
								}
							}

							// get the character controller that matches our userKeyId
							FMyActivePlayer* thisPlayer = getPlayerByPlayerKey(userKeyId);

							thisPlayer->PlayerController->AddItem(basePickupBP, quantity, false);

						}
					}
				}
			}
		}
	}
}



int32 UMyGameInstance::getSpawnRewardValue() {
	return SpawnRewardValue;
}

bool UMyGameInstance::Reward(FString playerKeyId, FString itemName, FString description, int32 amount)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] Reward"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);
	PlayerJsonObj->SetStringField("itemName", itemName);
	PlayerJsonObj->SetStringField("description", description);
	PlayerJsonObj->SetNumberField("amount", amount);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/server/player/" + playerKeyId + "/reward";

	FMyActivePlayer* ActivePlayer = getPlayerByPlayerKey(playerKeyId);
	if (ActivePlayer)
	{
		FString access_token = ActivePlayer->PlayerController->CurrentAccessTokenFromOSS;
		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::RewardRequestComplete, APIURI, JsonOutputString, access_token);
		return requestSuccess;
	}
	return false;
}

void UMyGameInstance::RewardRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					FString userKeyId = JsonParsed->GetStringField("userKeyId");
					FString itemName = JsonParsed->GetStringField("itemName");
					int32 purchaseAmount = JsonParsed->GetNumberField("amount");

					FMyActivePlayer* playerRecord = getPlayerByPlayerKey(userKeyId);
					if (playerRecord == nullptr)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] Reward - Player NOT found by Key"));
						return;
					}

					APlayerState* thisPlayerState = playerRecord->PlayerController->PlayerState;
					AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);

					playerRecord->currencyCurrent = playerRecord->currencyCurrent + purchaseAmount;
					playerS->Currency = playerRecord->currencyCurrent;
					//playerRecord->PlayerController->CurrencyAvailable = playerRecord->currencyCurrent;

				}
			}
		}
	}
}


bool UMyGameInstance::GetPlayerDrops(FString playerKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] Purchase"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.  

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);
	PlayerJsonObj->SetStringField("userKeyId", playerKeyId);


	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/game/drops/";

	FMyActivePlayer* CurrentActivePlayer = getPlayerByPlayerKey(playerKeyId);
	if (CurrentActivePlayer)
	{
		FString access_token = CurrentActivePlayer->PlayerController->CurrentAccessTokenFromOSS;
		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::GetPlayerDropsRequestComplete, APIURI, JsonOutputString, access_token);
		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::GetPlayerDropsRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					FString userKeyId = JsonParsed->GetStringField("userKeyId");

					FMyActivePlayer* playerRecord = getPlayerByPlayerKey(userKeyId);
					if (playerRecord)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] GetPlayerDropsRequestComplete Player found by Key"));

						APlayerState* thisPlayerState = playerRecord->PlayerController->PlayerState;
						AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);

						if (playerS)
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] GetPlayerDropsRequestComplete Got player state"));

							// Clear out the old Drops if any
							playerS->MyDrops.Empty();

							// Parse out the Array of returned Drops and add them to the state.
							TArray<TSharedPtr<FJsonValue>> dropsArray = JsonParsed->GetArrayField("drops");

							for (int32 i = 0; i < dropsArray.Num(); i++)
							{
								TSharedPtr<FJsonValue> value = dropsArray[i];
								TSharedPtr<FJsonObject> json = value->AsObject();

								FLootDrop NewDrop;
								NewDrop.key_id = json->GetStringField("key_id");
								NewDrop.title = json->GetStringField("title");
								NewDrop.uiIcon = json->GetStringField("uiIcon");
								NewDrop.expires = json->GetStringField("expires");

								playerS->MyDrops.Add(NewDrop);
							}
						}
					}
				}
			}
		}
	}
}


bool UMyGameInstance::ClaimPlayerDrop(FString playerKeyId, FString dropKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] ClaimPlayerDrop"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.  

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);


	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/game/drops/" + dropKeyId;

	//FMyMatchPlayer* MatchPlayer = getMatchPlayerByPlayerKey(playerKeyId);
	FMyActivePlayer* playerRecord = getPlayerByPlayerKey(playerKeyId);
	if (playerRecord)
	{
		FString access_token = playerRecord->PlayerController->CurrentAccessTokenFromOSS;
		bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::ClaimPlayerDropRequestComplete, APIURI, JsonOutputString, access_token);
		return requestSuccess;
	}

	return false;
}

void UMyGameInstance::ClaimPlayerDropRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					FString userKeyId = JsonParsed->GetStringField("userKeyId");

					FMyActivePlayer* playerRecord = getPlayerByPlayerKey(userKeyId);
					if (playerRecord)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] ClaimPlayerDropRequestComplete Player found by Key"));

						// Add the item to the inventory.
						// Parse out the data field


						FString DropDataJsonRaw = JsonParsed->GetStringField("data");
						TSharedPtr<FJsonObject> DropDataJsonParsed;
						TSharedRef<TJsonReader<TCHAR>> DropDataJsonReader = TJsonReaderFactory<TCHAR>::Create(DropDataJsonRaw);
						//const JsonValPtrArray *DropDataJson;

						if (FJsonSerializer::Deserialize(DropDataJsonReader, DropDataJsonParsed))
						{
							UE_LOG(LogTemp, Log, TEXT("DropDataJsonParsed"));
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [GetGamePlayerRequestComplete] DropDataJsonRaw: %s"), *DropDataJsonRaw);

							// TODO  - add the drop to your inventory.  I use data tables for this.  Ping me if you want to see my code.

							// refresh the drop list
							GetPlayerDrops(JsonParsed->GetStringField("userKeyId"));

						}
					}
				}
			}
		}
	}
}


bool UMyGameInstance::QueryGameDataList(FString cursor)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] QueryGameDataList"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);
	if (cursor.Len() > 5)
	{
		PlayerJsonObj->SetStringField("cursor", cursor);
	}


	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/game/data/";

	bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::QueryGameDataListRequestComplete, APIURI, JsonOutputString, ""); // No AccessToken

	return requestSuccess;
}

void UMyGameInstance::QueryGameDataListRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));

					// TODO - do something with the returned array of keys
				}
			}
		}
	}
}


bool UMyGameInstance::QueryGameData(FString gameDataKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] QueryGameData"));

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	TSharedPtr<FJsonObject> PlayerJsonObj = MakeShareable(new FJsonObject);
	PlayerJsonObj->SetStringField("nonce", "nonceString");
	PlayerJsonObj->SetStringField("encryption", encryption);
	PlayerJsonObj->SetStringField("key_id", gameDataKeyId);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(PlayerJsonObj.ToSharedRef(), Writer);

	FString APIURI = "/api/v1/game/data/" + gameDataKeyId;

	bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::QueryGameDataRequestComplete, APIURI, JsonOutputString, ""); // No AccessToken

	return requestSuccess;
}

void UMyGameInstance::QueryGameDataRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				bool Success = JsonParsed->GetBoolField("success");
				if (Success) {
					UE_LOG(LogTemp, Log, TEXT("Success True"));
					FString game_data_json_string = JsonParsed->GetStringField("data");

					// TODO - do something with the returned string
				}
			}
		}
	}
}



void UMyGameInstance::RequestBeginPlay()
{
	// This is not used here because we're skipping the lobby and going straight into the world.
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] RequestBeginPlay"));
	// travel to the third person map
	FString UrlString = TEXT("/Game/Maps/ThirdPersonExampleMap?listen");
	GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;
	GetWorld()->ServerTravel(UrlString);
	bRequestBeginPlayStarted = true;
}


bool UMyGameInstance::SubmitMatchMakerResults()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SubmitMatchMakerResults"));
	MatchInfo.encryption = "off";
	MatchInfo.nonce = "10951350917635";
	FString json_string;
	FJsonObjectConverter::UStructToJsonObjectString(MatchInfo.StaticStruct(), &MatchInfo, json_string, 0, 0);
	UE_LOG(LogTemp, Log, TEXT("json_string: %s"), *json_string);
	FString APIURI = "/api/v1/matchmaker/results";
	bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::SubmitMatchMakerResultsComplete, APIURI, json_string, "");  // NO AccessToken
	return requestSuccess;
}


void UMyGameInstance::SubmitMatchMakerResultsComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			//  We don't care too much about the results from this call.
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization False"));
			}
		}
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SubmitMatchMakerResultsComplete] Done!"));
}


void UMyGameInstance::SubmitReport()
{
	if (IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SubmitReport"));

		bool FoundKills = false;
		bool FoundEvents = false;

		for (int32 b = 0; b < PlayerRecord.ActivePlayers.Num(); b++)
		{
			if (PlayerRecord.ActivePlayers[b].roundKills > 0)
			{
				FoundKills = true;
				break;
			}
			if (PlayerRecord.ActivePlayers[b].events.Num() > 0)
			{
				FoundEvents = true;
				break;
			}
		}

		PlayerRecord.encryption = "off";
		PlayerRecord.nonce = "10951350917635";
		FString json_string;
		FJsonObjectConverter::UStructToJsonObjectString(FMyActivePlayers::StaticStruct(), &PlayerRecord, json_string, 0, 0);

		//UE_LOG(LogTemp, Log, TEXT("json_string: %s"), *json_string);

		if (FoundKills || FoundEvents) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SubmitReport - found kills or events"));

			FHttpModule* Http = &FHttpModule::Get();
			if (!Http) { return; }
			if (!Http->IsHttpEnabled()) { return; }

			UE_LOG(LogTemp, Log, TEXT("Object is: %s"), *GetName());

			FString APIURI = "/api/v1/server/report";;

			bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::SubmitReportComplete, APIURI, json_string, "");  // NO AccessToken

			// Clean out the active players list

			for (int32 b = 0; b < PlayerRecord.ActivePlayers.Num(); b++)
			{
				PlayerRecord.ActivePlayers[b].killed.Empty();
				PlayerRecord.ActivePlayers[b].roundDeaths = 0;
				PlayerRecord.ActivePlayers[b].roundKills = 0;
				PlayerRecord.ActivePlayers[b].events.Empty();
			}

			return;
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SubmitReport - No kills or events - Ignoring"));
		}
	}
	return;

}

void UMyGameInstance::SubmitReportComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			//  We don't care too much about the results from this call.
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization False"));
			}
		}
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [SubmitReport] Done!"));
}

/**
* Delegate fired when a session create request has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void UMyGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	//UE_LOG(LogOnlineGame, Verbose, TEXT("OnCreateSessionComplete %s bSuccess: %d"), *SessionName.ToString(), bWasSuccessful);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] UMyGameInstance::OnCreateSessionComplete"));
}

/** Initiates matchmaker */
bool UMyGameInstance::StartMatchmaking(ULocalPlayer* PlayerOwner, FString MatchType)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::StartMatchmaking"));
	bool bResult = false;

	/*
	// THIS stuff came from shooter game
	// It requires a function inside gameMode for the cast to succeed:  GetGameSessionClass
	*/
	check(PlayerOwner != nullptr);
	if (PlayerOwner)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Player Owner found"));
		AMyGameSession* const GameSession = GetGameSession();
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE got game session"));
		if (GameSession)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Game session found"));
			GameSession->OnFindSessionsComplete().RemoveAll(this);
			OnSearchSessionsCompleteDelegateHandle = GameSession->OnFindSessionsComplete().AddUObject(this, &UMyGameInstance::OnSearchSessionsComplete);

			//UE_LOG(LogTemp, Verbose, TEXT("FindSessions PlayerOwner->GetPreferredUniqueNetId(): %d"), PlayerOwner->GetPreferredUniqueNetId());

			// this chenged in 4.20 - it is not returning the same type anymore
			FUniqueNetIdRepl playerNetId = PlayerOwner->GetPreferredUniqueNetId();
			GameSession->StartMatchmaking(playerNetId.GetUniqueNetId(), GameSessionName, MatchType);

			bResult = true;
		}
	}
	return bResult;
}


/** Stops matchmaker */
bool UMyGameInstance::CancelMatchmaking(ULocalPlayer* PlayerOwner)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::CancelMatchmaking"));
	bool bResult = false;

	/*
	// THIS stuff came from shooter game
	// It requires a function inside gameMode for the cast to succeed:  GetGameSessionClass
	*/
	check(PlayerOwner != nullptr);
	if (PlayerOwner)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Player Owner found"));
		AMyGameSession* const GameSession = GetGameSession();
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE got game session"));
		if (GameSession)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Game session found"));
			GameSession->OnFindSessionsComplete().RemoveAll(this);

			//UE_LOG(LogTemp, Verbose, TEXT("FindSessions PlayerOwner->GetPreferredUniqueNetId(): %d"), PlayerOwner->GetPreferredUniqueNetId());

			// this chenged in 4.20 - it is not returning the same type anymore
			FUniqueNetIdRepl playerNetId = PlayerOwner->GetPreferredUniqueNetId();
			GameSession->CancelMatchmaking(playerNetId.GetUniqueNetId(), GameSessionName);

			bResult = true;
		}
	}
	return bResult;
}

/** Initiates the session searching */
bool UMyGameInstance::FindSessions(ULocalPlayer* PlayerOwner, bool bFindLAN)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::FindSessions"));
	bool bResult = false;

	/*
	// THIS stuff came from shooter game
	// It requires a function inside gameMode for the cast to succeed:  GetGameSessionClass
	*/
	check(PlayerOwner != nullptr);
	if (PlayerOwner)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Player Owner found"));
		AMyGameSession* const GameSession = GetGameSession();
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE got game session"));
		if (GameSession)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Game session found"));
			GameSession->OnFindSessionsComplete().RemoveAll(this);
			OnSearchSessionsCompleteDelegateHandle = GameSession->OnFindSessionsComplete().AddUObject(this, &UMyGameInstance::OnSearchSessionsComplete);

			//UE_LOG(LogTemp, Verbose, TEXT("FindSessions PlayerOwner->GetPreferredUniqueNetId(): %d"), PlayerOwner->GetPreferredUniqueNetId());

			// this chenged in 4.20 - it is not returning the same type anymore
			FUniqueNetIdRepl playerNetId = PlayerOwner->GetPreferredUniqueNetId();
			GameSession->FindSessions(playerNetId.GetUniqueNetId(), GameSessionName, bFindLAN, true);

			bResult = true;
		}
	}
	return bResult;
}

/** Initiates the session searching on a server*/
bool UMyGameInstance::FindSessions(bool bFindLAN)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::FindSessions"));
	bool bResult = false;

	/*
	// THIS stuff came from shooter game
	// It requires a function inside gameMode for the cast to succeed:  GetGameSessionClass
	*/

	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Player Owner found"));
	AMyGameSession* const GameSession = GetGameSession();
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE got game session"));
	if (GameSession)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE Game session found"));
		GameSession->OnFindSessionsComplete().RemoveAll(this);
		OnSearchSessionsCompleteDelegateHandle = GameSession->OnFindSessionsComplete().AddUObject(this, &UMyGameInstance::OnSearchSessionsComplete);

		//UE_LOG(LogTemp, Verbose, TEXT("FindSessions PlayerOwner->GetPreferredUniqueNetId(): %d"), PlayerOwner->GetPreferredUniqueNetId());

		GameSession->FindSessions(GameSessionName, bFindLAN, true);

		bResult = true;
	}

	return bResult;
}

/** Callback which is intended to be called upon finding sessions */
void UMyGameInstance::OnSearchSessionsComplete(bool bWasSuccessful)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::OnSearchSessionsComplete"));
	AMyGameSession* const Session = GetGameSession();
	if (Session)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::OnSearchSessionsComplete: Session found"));
		Session->OnFindSessionsComplete().Remove(OnSearchSessionsCompleteDelegateHandle);

		//Session->GetSearchResults();

		// clear out the Array before adding in new results
		MySessionSearchResults.Empty();

		const TArray<FOnlineSessionSearchResult> & SearchResults = Session->GetSearchResults();

		for (int32 IdxResult = 0; IdxResult < SearchResults.Num(); ++IdxResult)
		{
			//TSharedPtr<FServerEntry> NewServerEntry = MakeShareable(new FServerEntry());

			const FOnlineSessionSearchResult& Result = SearchResults[IdxResult];

			// setup a ustruct for bp
			// add the results to the TArray
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] UMyGameInstance::OnSearchSessionsComplete: Adding to MySessionSearchResults"));
			FMySessionSearchResult searchresult;
			searchresult.OwningUserName = Result.Session.OwningUserName;
			searchresult.SearchIdx = IdxResult;
			FName key = "serverTitle";
			FString serverTitle;
			bool settingsSuccess = Result.Session.SessionSettings.Get(key, serverTitle);
			searchresult.ServerTitle = serverTitle;

			key = "serverKey";
			FString serverKey;
			Result.Session.SessionSettings.Get(key, serverKey);

			searchresult.ServerKey = serverKey;

			MySessionSearchResults.Add(searchresult);
			if (MySessionSearchResults.Num() > 0)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] UMyGameInstance::OnSearchSessionsComplete: MySessionSearchResults.Num() > 0"));  // just checking
			}
		}
	}
}


void UMyGameInstance::BeginWelcomeScreenState()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::BeginWelcomeScreenState"));
	//this must come before split screen player removal so that the OSS sets all players to not using online features.
	SetIsOnline(false);

	// Remove any possible splitscren players
	RemoveSplitScreenPlayers();

	ULocalPlayer* const LocalPlayer = GetFirstGamePlayer();

	// Disallow splitscreen
	GetGameViewportClient()->SetDisableSplitscreenOverride(true);
}

void UMyGameInstance::SetIsOnline(bool bInIsOnline)
{
	bIsOnline = bInIsOnline;
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		for (int32 i = 0; i < LocalPlayers.Num(); ++i)
		{
			ULocalPlayer* LocalPlayer = LocalPlayers[i];

			// this changed in 4.20  - not returning the same type anymore
			FUniqueNetIdRepl playerNetId = LocalPlayer->GetPreferredUniqueNetId();
			TSharedPtr<const FUniqueNetId> PlayerId = playerNetId.GetUniqueNetId();

			if (PlayerId.IsValid())
			{
				OnlineSub->SetUsingMultiplayerFeatures(*PlayerId, bIsOnline);
			}
		}
	}
}

void UMyGameInstance::RemoveSplitScreenPlayers()
{
	// if we had been split screen, toss the extra players now
	// remove every player, back to front, except the first one
	while (LocalPlayers.Num() > 1)
	{
		ULocalPlayer* const PlayerToRemove = LocalPlayers.Last();
		RemoveExistingLocalPlayer(PlayerToRemove);
	}
}

void UMyGameInstance::RemoveExistingLocalPlayer(ULocalPlayer* ExistingPlayer)
{
	check(ExistingPlayer);
	if (ExistingPlayer->PlayerController != NULL)
		// Remove local split-screen players from the list
		RemoveLocalPlayer(ExistingPlayer);
}



bool UMyGameInstance::JoinSession(ULocalPlayer* LocalPlayer, int32 SessionIndexInSearchResults)
{
	// needs to tear anything down based on current state?

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::JoinSession 1"));


	AMyGameSession* const GameSession = GetGameSession();
	if (GameSession)
	{
		AddNetworkFailureHandlers();

		OnJoinSessionCompleteDelegateHandle = GameSession->OnJoinSessionComplete().AddUObject(this, &UMyGameInstance::OnJoinSessionComplete);

		// this chenged in 4.20 - it is not returning the same type anymore
		FUniqueNetIdRepl playerNetId = LocalPlayer->GetPreferredUniqueNetId();
		if (GameSession->JoinSession(playerNetId.GetUniqueNetId(), GameSessionName, SessionIndexInSearchResults))
		{
			// If any error occured in the above, pending state would be set
			//if ((PendingState == CurrentState) || (PendingState == MyGameInstanceState::None))
			//{
			// Go ahead and go into loading state now
			// If we fail, the delegate will handle showing the proper messaging and move to the correct state
			//ShowLoadingScreen();
			//	GotoState(MyGameInstanceState::Playing);
			//	return true;
			//}
		}
	}


	return false;
}

bool UMyGameInstance::JoinSession(ULocalPlayer* LocalPlayer, const FOnlineSessionSearchResult& SearchResult)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::JoinSession 2"));
	// needs to tear anything down based on current state?
	AMyGameSession* const GameSession = GetGameSession();
	if (GameSession)
	{
		AddNetworkFailureHandlers();

		OnJoinSessionCompleteDelegateHandle = GameSession->OnJoinSessionComplete().AddUObject(this, &UMyGameInstance::OnJoinSessionComplete);

		// this chenged in 4.20 - it is not returning the same type anymore
		FUniqueNetIdRepl playerNetId = LocalPlayer->GetPreferredUniqueNetId();
		if (GameSession->JoinSession(playerNetId.GetUniqueNetId(), GameSessionName, SearchResult))
		{
			// If any error occured in the above, pending state would be set
			if ((PendingState == CurrentState) || (PendingState == MyGameInstanceState::None))
			{
				// Go ahead and go into loading state now
				// If we fail, the delegate will handle showing the proper messaging and move to the correct state
				//ShowLoadingScreen();
				GotoState(MyGameInstanceState::Playing);
				return true;
			}
		}
	}
	return false;
}


/**
* Delegate fired when the joining process for an online session has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void UMyGameInstance::OnJoinSessionComplete(EOnJoinSessionCompleteResult::Type Result)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::OnJoinSessionComplete"));
	// unhook the delegate
	AMyGameSession* const GameSession = GetGameSession();
	if (GameSession)
	{
		GameSession->OnJoinSessionComplete().Remove(OnJoinSessionCompleteDelegateHandle);
	}
	FinishJoinSession(Result);

}

void UMyGameInstance::FinishJoinSession(EOnJoinSessionCompleteResult::Type Result)
{
	if (Result != EOnJoinSessionCompleteResult::Success)
	{
		FText ReturnReason;
		switch (Result)
		{
		case EOnJoinSessionCompleteResult::SessionIsFull:
			ReturnReason = NSLOCTEXT("NetworkErrors", "JoinSessionFailed", "Game is full.");
			break;
		case EOnJoinSessionCompleteResult::SessionDoesNotExist:
			ReturnReason = NSLOCTEXT("NetworkErrors", "JoinSessionFailed", "Game no longer exists.");
			break;
		default:
			ReturnReason = NSLOCTEXT("NetworkErrors", "JoinSessionFailed", "Join failed.");
			break;
		}

		FText OKButton = NSLOCTEXT("DialogButtons", "OKAY", "OK");
		RemoveNetworkFailureHandlers();
		return;
	}

	InternalTravelToSession(GameSessionName);
}

void UMyGameInstance::InternalTravelToSession(const FName& SessionName)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::InternalTravelToSession"));
	APlayerController * const PlayerController = GetFirstLocalPlayerController();

	if (PlayerController == nullptr)
	{
		FText ReturnReason = NSLOCTEXT("NetworkErrors", "InvalidPlayerController", "Invalid Player Controller");
		FText OKButton = NSLOCTEXT("DialogButtons", "OKAY", "OK");
		RemoveNetworkFailureHandlers();
		//ShowMessageThenGoMain(ReturnReason, OKButton, FText::GetEmpty());
		return;
	}

	// travel to session
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub == nullptr)
	{
		FText ReturnReason = NSLOCTEXT("NetworkErrors", "OSSMissing", "OSS missing");
		FText OKButton = NSLOCTEXT("DialogButtons", "OKAY", "OK");
		RemoveNetworkFailureHandlers();
		//ShowMessageThenGoMain(ReturnReason, OKButton, FText::GetEmpty());
		return;
	}

	FString URL;
	IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

	if (!Sessions.IsValid() || !Sessions->GetResolvedConnectString(SessionName, URL))
	{
		FText FailReason = NSLOCTEXT("NetworkErrors", "TravelSessionFailed", "Travel to Session failed.");
		FText OKButton = NSLOCTEXT("DialogButtons", "OKAY", "OK");
		UE_LOG(LogOnlineGame, Warning, TEXT("Failed to travel to session upon joining it"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::InternalTravelToSession Traveling..."));
	PlayerController->ClientTravel(URL, TRAVEL_Absolute);
}

bool UMyGameInstance::TravelToSession(int32 ControllerId, FName SessionName)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::TravelToSession"));
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		FString URL;
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid() && Sessions->GetResolvedConnectString(SessionName, URL))
		{
			APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), ControllerId);
			if (PC)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::TravelToSession Travelling..."));
				PC->ClientTravel(URL, TRAVEL_Absolute);
				return true;
			}
		}
		else
		{
			UE_LOG(LogOnlineGame, Warning, TEXT("Failed to join session %s"), *SessionName.ToString());
		}
	}
#if !UE_BUILD_SHIPPING
	else
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), ControllerId);
		if (PC)
		{
			FString LocalURL(TEXT("127.0.0.1"));
			PC->ClientTravel(LocalURL, TRAVEL_Absolute);
			return true;
		}
	}
#endif //!UE_BUILD_SHIPPING

	return false;
}

void UMyGameInstance::RemoveNetworkFailureHandlers()
{
	// Remove the local session/travel failure bindings if they exist
	if (GEngine->OnTravelFailure().IsBoundToObject(this) == true)
	{
		GEngine->OnTravelFailure().Remove(TravelLocalSessionFailureDelegateHandle);
	}
}

void UMyGameInstance::AddNetworkFailureHandlers()
{
	// Add network/travel error handlers (if they are not already there)
	if (GEngine->OnTravelFailure().IsBoundToObject(this) == false)
	{
		TravelLocalSessionFailureDelegateHandle = GEngine->OnTravelFailure().AddUObject(this, &UMyGameInstance::TravelLocalSessionFailure);
	}
}

void UMyGameInstance::TravelLocalSessionFailure(UWorld *World, ETravelFailure::Type FailureType, const FString& ReasonString)
{
	/*
	AShooterPlayerController_Menu* const FirstPC = Cast<AShooterPlayerController_Menu>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FirstPC != nullptr)
	{
	FText ReturnReason = NSLOCTEXT("NetworkErrors", "JoinSessionFailed", "Join Session failed.");
	if (ReasonString.IsEmpty() == false)
	{
	ReturnReason = FText::Format(NSLOCTEXT("NetworkErrors", "JoinSessionFailedReasonFmt", "Join Session failed. {0}"), FText::FromString(ReasonString));
	}

	FText OKButton = NSLOCTEXT("DialogButtons", "OKAY", "OK");
	ShowMessageThenGoMain(ReturnReason, OKButton, FText::GetEmpty());
	}
	*/
}


FName UMyGameInstance::GetInitialState()
{
	// On PC, go directly to the main menu
	return MyGameInstanceState::MainMenu;
}

void UMyGameInstance::GotoInitialState()
{
	GotoState(GetInitialState());
}

void UMyGameInstance::GotoState(FName NewState)
{
	UE_LOG(LogOnline, Log, TEXT("GotoState: NewState: %s"), *NewState.ToString());

	PendingState = NewState;
}

void UMyGameInstance::HandleSessionFailure(const FUniqueNetId& NetId, ESessionFailure::Type FailureType)
{
	UE_LOG(LogOnlineGame, Warning, TEXT("UMyGameInstance::HandleSessionFailure: %u"), (uint32)FailureType);
}

void UMyGameInstance::OnEndSessionComplete(FName SessionName, bool bWasSuccessful)
{
	UE_LOG(LogOnline, Log, TEXT("UMyGameInstance::OnEndSessionComplete: Session=%s bWasSuccessful=%s"), *SessionName.ToString(), bWasSuccessful ? TEXT("true") : TEXT("false"));

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			Sessions->ClearOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegateHandle);
			Sessions->ClearOnEndSessionCompleteDelegate_Handle(OnEndSessionCompleteDelegateHandle);
			Sessions->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegateHandle);
		}
	}

	// continue
	CleanupSessionOnReturnToMenu();
}

void UMyGameInstance::CleanupSessionOnReturnToMenu()
{
	bool bPendingOnlineOp = false;

	// end online game and then destroy it
	IOnlineSubsystem * OnlineSub = IOnlineSubsystem::Get();
	IOnlineSessionPtr Sessions = (OnlineSub != NULL) ? OnlineSub->GetSessionInterface() : NULL;

	if (Sessions.IsValid())
	{
		EOnlineSessionState::Type SessionState = Sessions->GetSessionState(GameSessionName);
		//UE_LOG(LogOnline, Log, TEXT("Session %s is '%s'"), *GameSessionName.ToString(), EOnlineSessionState::ToString(SessionState));

		if (EOnlineSessionState::InProgress == SessionState)
		{
			//UE_LOG(LogOnline, Log, TEXT("Ending session %s on return to main menu"), *GameSessionName.ToString());
			OnEndSessionCompleteDelegateHandle = Sessions->AddOnEndSessionCompleteDelegate_Handle(OnEndSessionCompleteDelegate);
			Sessions->EndSession(GameSessionName);
			bPendingOnlineOp = true;
		}
		else if (EOnlineSessionState::Ending == SessionState)
		{
			//UE_LOG(LogOnline, Log, TEXT("Waiting for session %s to end on return to main menu"), *GameSessionName.ToString());
			OnEndSessionCompleteDelegateHandle = Sessions->AddOnEndSessionCompleteDelegate_Handle(OnEndSessionCompleteDelegate);
			bPendingOnlineOp = true;
		}
		else if (EOnlineSessionState::Ended == SessionState || EOnlineSessionState::Pending == SessionState)
		{
			//UE_LOG(LogOnline, Log, TEXT("Destroying session %s on return to main menu"), *GameSessionName.ToString());
			OnDestroySessionCompleteDelegateHandle = Sessions->AddOnDestroySessionCompleteDelegate_Handle(OnEndSessionCompleteDelegate);
			Sessions->DestroySession(GameSessionName);
			bPendingOnlineOp = true;
		}
		else if (EOnlineSessionState::Starting == SessionState)
		{
			//UE_LOG(LogOnline, Log, TEXT("Waiting for session %s to start, and then we will end it to return to main menu"), *GameSessionName.ToString());
			OnStartSessionCompleteDelegateHandle = Sessions->AddOnStartSessionCompleteDelegate_Handle(OnEndSessionCompleteDelegate);
			bPendingOnlineOp = true;
		}
	}

	if (!bPendingOnlineOp)
	{
		//GEngine->HandleDisconnect( GetWorld(), GetWorld()->GetNetDriver() );
	}
}

bool UMyGameInstance::RegisterNewSession(FString IncServerSessionHostAddress, FString IncServerSessionID)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::RegisterNewSession"));

	ServerSessionHostAddress = IncServerSessionHostAddress;
	ServerSessionID = IncServerSessionID;

	if (UEtopiaMode == "competitive") {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::RegisterNewSession competitive"));
		// We're matchmaker, so get match info
		GetMatchInfo();
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::RegisterNewSession persistent"));
		// UEtopia persistent server.
		GetServerInfo();
		GetServerLinks();
	}
	return true;
}

bool UMyGameInstance::IsLocalPlayerOnline(ULocalPlayer* LocalPlayer)
{
	if (LocalPlayer == NULL)
	{
		return false;
	}
	const auto OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		const auto IdentityInterface = OnlineSub->GetIdentityInterface();
		if (IdentityInterface.IsValid())
		{
			auto UniqueId = LocalPlayer->GetCachedUniqueNetId();
			if (UniqueId.IsValid())
			{
				const auto LoginStatus = IdentityInterface->GetLoginStatus(*UniqueId);
				if (LoginStatus == ELoginStatus::LoggedIn)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool UMyGameInstance::ValidatePlayerForOnlinePlay(ULocalPlayer* LocalPlayer)
{
	return true;
}

void UMyGameInstance::HandleUserLoginChanged(int32 GameUserIndex, ELoginStatus::Type PreviousLoginStatus, ELoginStatus::Type LoginStatus, const FUniqueNetId& UserId)
{
	
}

void UMyGameInstance::HandleUserLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::HandleUserLoginComplete"));
	if (PIE_Bypass)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::HandleUserLoginComplete PIE_Bypass"));
		return;
	}
	if (bWasSuccessful == false)
	{
		return;
	}
	//const auto OnlineSub = IOnlineSubsystem::Get();
	//if (OnlineSub)
	//{
	//	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::HandleUserLoginComplete OnlineSub"));
	//	const auto FriendsInterface = OnlineSub->GetFriendsInterface();
	//	if (FriendsInterface.IsValid())
	//	{
	//		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::HandleUserLoginComplete FriendsInterface.IsValid()"));
	//
	//	}
	//}
}

void UMyGameInstance::HandleSignInChangeMessaging()
{
	// Master user signed out, go to initial state (if we aren't there already)
	if (CurrentState != GetInitialState())
	{
		GotoInitialState();
	}
}

void UMyGameInstance::BeginLogin(FString InType, FString InId, FString InToken)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] GAME INSTANCE UMyGameInstance::BeginLogin"));

	const auto OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		const auto IdentityInterface = OnlineSub->GetIdentityInterface();
		if (IdentityInterface.IsValid())
		{
			FOnlineAccountCredentials* Credentials = new FOnlineAccountCredentials(InType, InId, InToken);
			IdentityInterface->Login(0, *Credentials);
		}
	}
}



FMyActivePlayer* UMyGameInstance::getPlayerByPlayerId(int32 playerID)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getPlayerByPlayerID"));
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		if (MatchInfo.players[b].playerID) {
			UE_LOG(LogTemp, Log, TEXT("Comparing playerID: %d PlayerRecord.ActivePlayers[b].playerID:%d"),
				playerID,
				MatchInfo.players[b].playerID);

			if (MatchInfo.players[b].playerID == playerID) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getPlayerByPlayerID - FOUND MATCHING playerID"));
				FMyActivePlayer* playerPointer = &MatchInfo.players[b];
				return playerPointer;
			}
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] DeActivatePlayer - PlayerRecord.ActivePlayers[b].playerID DOES NOT EXIST"));
		}
	}
	return nullptr;
}

FMyActivePlayer* UMyGameInstance::getPlayerByPlayerKey(FString playerKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getPlayerByPlayerKey"));
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		if (MatchInfo.players[b].userKeyId == playerKeyId) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getPlayerByPlayerKey - FOUND MATCHING playerID"));
			FMyActivePlayer* playerPointer = &MatchInfo.players[b];
			return playerPointer;
		}
	}
	return nullptr;
}

void UMyGameInstance::deletePlayerByPlayerKey(FString playerKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] deletePlayerByPlayerKey"));
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		if (MatchInfo.players[b].userKeyId == playerKeyId) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] deletePlayerByPlayerKey - FOUND MATCHING playerID"));
			MatchInfo.players.RemoveAt(b);
			return ;
		}
	}
	return ;
}

FMyActivePlayer* UMyGameInstance::getMatchPlayerByPlayerId(int32 playerID)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getMatchPlayerByPlayerID"));
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		if (MatchInfo.players[b].playerID) {
			UE_LOG(LogTemp, Log, TEXT("Comparing playerID: %d MatchInfo.players[b].playerID:%d"),
			playerID,
			MatchInfo.players[b].playerID);

			if (MatchInfo.players[b].playerID == playerID) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getMatchPlayerByPlayerID - FOUND MATCHING playerID"));
				FMyActivePlayer* playerPointer = &MatchInfo.players[b];
				return playerPointer;
			}
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getMatchPlayerByPlayerId - MatchInfo.players[b].playerID DOES NOT EXIST"));
		}
	}
	return nullptr;
}


int32 UMyGameInstance::getActivePlayerCount()
{
	int32 count = 0;
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getActivePlayerCount"));
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		if (MatchInfo.players[b].authorized) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getActivePlayerCount - FOUND authorized"));
			count++;
		}
	}
	return count;
}

FMyServerLink* UMyGameInstance::getServerByKey(FString serverKey)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getServerByKey"));
	for (int32 b = 0; b < ServerLinks.links.Num(); b++)
	{
		if (ServerLinks.links[b].targetServerKeyId == serverKey) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] getServerByKey - FOUND MATCHING server"));
			FMyServerLink* serverPointer = &ServerLinks.links[b];
			return serverPointer;
		}
	}
	return nullptr;
}


bool UMyGameInstance::RecordKill(int32 killerPlayerID, int32 victimPlayerID)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RecordKill] "));
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RecordKill] killerPlayerID: %i"), killerPlayerID);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RecordKill] victimPlayerID: %i "), victimPlayerID);

	


	return true;
}

bool UMyGameInstance::RecordEvent(int32 playerID, FString eventSummary, FString eventIcon, FString eventType)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RecordKill] "));
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RecordKill] killerPlayerID: %s"), *eventSummary);

	FMyActivePlayer* CurrentActivePlayer = getPlayerByPlayerId(playerID);

	bool eventAlreadyExists = false;

	if (CurrentActivePlayer)
	{
		for (int32 b = 0; b < CurrentActivePlayer->events.Num(); b++)
		{
			if (CurrentActivePlayer->events[b].EventSummary == eventSummary)
			{
				eventAlreadyExists = true;
				break;
			}
		}

		if (!eventAlreadyExists)
		{
			FUserEvent tempEvent;
			tempEvent.EventSummary = eventSummary;
			tempEvent.EventIcon = eventIcon;
			tempEvent.EventType = eventType;
			CurrentActivePlayer->events.Add(tempEvent);
		}
	}
	return true;
}


void UMyGameInstance::SpawnServerPortals()
{
	if (IsRunningDedicatedServer()) {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SpawnServerPortals - Dedicated server found."));
		// Check gamestate HasBegunPlay
		//AGameState* gameState = GetWorld()->GameState;
		if (bRequestBeginPlayStarted) {
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] SpawnServerPortals - bRequestBeginPlayStarted."));
			// Place the server portals

			UWorld* const World = GetWorld(); // get a reference to the world


			//UE_LOG(LogTemp, Log, TEXT("Found %d Server Links"), ServerLinks.links.Num());

			bool thisPortalAlreadySpawned = false;

			for (int32 b = 0; b < ServerLinks.links.Num(); b++)
			{
				//UE_LOG(LogTemp, Log, TEXT("targetServerTitle: %s"), *ServerLinks.links[b].targetServerTitle);
				thisPortalAlreadySpawned = false;

				// check to see if we have already spawned this actor
				for (int i = 0; i < ServerPortalActorReference.Num(); i++) {
					if (ServerPortalActorReference[i]->serverKeyId == *ServerLinks.links[b].targetServerKeyId) {
						thisPortalAlreadySpawned = true;
						// set the portal state to our new state
						// usually shows server state, defaults to instanced if instanced, and default if not.
						if (ServerLinks.links[b].targetStatusOnline) {
							ServerPortalActorReference[i]->setState("Ready");
						}
						else if (ServerLinks.links[b].targetStatusProvisioned) {
							ServerPortalActorReference[i]->setState("Provisioned");
						}
						else if (ServerLinks.links[b].targetStatusCreating) {
							ServerPortalActorReference[i]->setState("Creating");
						}
						else if (ServerLinks.links[b].targetInstanced) {
							ServerPortalActorReference[i]->setState("Instanced");
						}
						else {
							ServerPortalActorReference[i]->setState("Default");
						}
						// re-set the serverURL - it may not have existed before
						ServerPortalActorReference[i]->setServerUrl(*ServerLinks.links[b].hostConnectionLink);
					}
				}

				if (World) {
					// if world exists,
					if (thisPortalAlreadySpawned == false) {
						// spawn the actor
						UE_LOG(LogTemp, Log, TEXT("Spawn The Server Portal"));
						UE_LOG(LogTemp, Log, TEXT("coordLocationX: %f"), ServerLinks.links[b].coordLocationX);
						UE_LOG(LogTemp, Log, TEXT("coordLocationY: %f"), ServerLinks.links[b].coordLocationY);
						UE_LOG(LogTemp, Log, TEXT("coordLocationZ: %f"), ServerLinks.links[b].coordLocationZ);
						UE_LOG(LogTemp, Log, TEXT("rotationX: %f"), ServerLinks.links[b].rotationX);
						UE_LOG(LogTemp, Log, TEXT("rotationY: %f"), ServerLinks.links[b].rotationY);
						UE_LOG(LogTemp, Log, TEXT("rotationZ: %f"), ServerLinks.links[b].rotationZ);
						UE_LOG(LogTemp, Log, TEXT("hostConnectionLink: %s"), *ServerLinks.links[b].hostConnectionLink);

						const FVector spawnlocation = FVector(ServerLinks.links[b].coordLocationX, ServerLinks.links[b].coordLocationY, ServerLinks.links[b].coordLocationZ);
						const FRotator spawnRotation = FRotator(ServerLinks.links[b].rotationX, ServerLinks.links[b].rotationY, ServerLinks.links[b].rotationZ);

						// Parallel/Instanced servers have a different class, with probably a different model.
						// switch based on the instance type

						if (ServerLinks.links[b].targetInstanced) {
							UE_LOG(LogTemp, Log, TEXT("Parallel/Instanced"));
							if (ServerLinks.links[b].targetInstanceConfiguration == "user") {
								UE_LOG(LogTemp, Log, TEXT("Parallel/Instanced - user"));
								AMyServerPortalActorParallelPriv* const PortalActor = World->SpawnActor<AMyServerPortalActorParallelPriv>(AMyServerPortalActorParallelPriv::StaticClass(), spawnlocation, spawnRotation);
								PortalActor->setServerKeyId(*ServerLinks.links[b].targetServerKeyId);
								PortalActor->setServerUrl(*ServerLinks.links[b].hostConnectionLink);
								PortalActor->setTitle(ServerLinks.links[b].targetServerTitle);
								// add the actor to our TArray
								ServerPortalActorReference.Add(PortalActor);
							}
							else if (ServerLinks.links[b].targetInstanceConfiguration == "party") {
								UE_LOG(LogTemp, Log, TEXT("Parallel/Instanced - party"));
								AMyServerPortalActorParallelPart* const PortalActor = World->SpawnActor<AMyServerPortalActorParallelPart>(AMyServerPortalActorParallelPart::StaticClass(), spawnlocation, spawnRotation);
								PortalActor->setServerKeyId(*ServerLinks.links[b].targetServerKeyId);
								PortalActor->setServerUrl(*ServerLinks.links[b].hostConnectionLink);
								PortalActor->setTitle(ServerLinks.links[b].targetServerTitle);
								// add the actor to our TArray
								ServerPortalActorReference.Add(PortalActor);
							}
							else if (ServerLinks.links[b].targetInstanceConfiguration == "group") {
								UE_LOG(LogTemp, Log, TEXT("Parallel/Instanced - group"));
								AMyServerPortalActorParallelGrou* const PortalActor = World->SpawnActor<AMyServerPortalActorParallelGrou>(AMyServerPortalActorParallelGrou::StaticClass(), spawnlocation, spawnRotation);
								PortalActor->setServerKeyId(*ServerLinks.links[b].targetServerKeyId);
								PortalActor->setServerUrl(*ServerLinks.links[b].hostConnectionLink);
								PortalActor->setTitle(ServerLinks.links[b].targetServerTitle);
								// add the actor to our TArray
								ServerPortalActorReference.Add(PortalActor);
							}
							else {
								UE_LOG(LogTemp, Log, TEXT("Parallel/Instanced - not found"));
								AMyServerPortalActorParallelPriv* const PortalActor = World->SpawnActor<AMyServerPortalActorParallelPriv>(AMyServerPortalActorParallelPriv::StaticClass(), spawnlocation, spawnRotation);
								PortalActor->setServerKeyId(*ServerLinks.links[b].targetServerKeyId);
								PortalActor->setServerUrl(*ServerLinks.links[b].hostConnectionLink);
								PortalActor->setTitle(ServerLinks.links[b].targetServerTitle);
								// add the actor to our TArray
								ServerPortalActorReference.Add(PortalActor);
							}
						}
						else {
							AMyServerPortalActor* const PortalActor = World->SpawnActor<AMyServerPortalActor>(AMyServerPortalActor::StaticClass(), spawnlocation, spawnRotation);
							PortalActor->setServerKeyId(*ServerLinks.links[b].targetServerKeyId);
							PortalActor->setServerUrl(*ServerLinks.links[b].hostConnectionLink);
							PortalActor->setTitle(ServerLinks.links[b].targetServerTitle);

							// determine the portal state, and set it
							if (ServerLinks.links[b].targetStatusOnline) {
								PortalActor->setState("Ready");
							}
							else if (ServerLinks.links[b].targetStatusProvisioned) {
								PortalActor->setState("Provisioned");
							}
							else if (ServerLinks.links[b].targetStatusCreating) {
								PortalActor->setState("Creating");
							}
							else {
								PortalActor->setState("Default");
							}

							// add the actor to our TArray
							ServerPortalActorReference.Add(PortalActor);

						}
					}
				}
				// TODO deal with portals that disappear and need deletion
			}
		}
	}
}


bool UMyGameInstance::KickPlayersFromServer()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] KickPlayersFromServer."));

	// Run deactivate and Save Game players
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		DeActivatePlayer(MatchInfo.players[b].playerID);
		SaveGamePlayer(MatchInfo.players[b].userKeyId, true);

	}

	// Kick everyone back to login
	// travel all clinets back to login
	APlayerController* pc = NULL;
	FString UrlString = TEXT("/Game/LoginLevel");

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		pc = Iterator->Get();
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [KickPlayersFromServer] - kicking back to login"));
		pc->ClientTravel(UrlString, ETravelType::TRAVEL_Absolute);
	}
	return true;
}


bool UMyGameInstance::RecordRoundWin(int32 winnerTeamID) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] RecordRoundWin."));

	// Just record it.  Handle all of the other logic in game mode
	int32 roundWinnerIndex = 0;
	int32 roundLoserIndex = 0;
	for (int32 b = 0; b < TeamList.teams.Num(); b++)
	{
		if (TeamList.teams[b].number == winnerTeamID) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] Found Winning team."));

			roundWinnerIndex = b;
		}
		else {
			roundLoserIndex = b;
		}
	}
	TeamList.teams[roundWinnerIndex].roundWinCount = TeamList.teams[roundWinnerIndex].roundWinCount + 1;

	return true;
}

bool UMyGameInstance::RecordMatchWin(int32 winnerTeamID) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] RecordMatchWin."));

	// Just record it.  Handle all of the other logic in game mode
	int32 roundWinnerIndex = 0;
	int32 roundLoserIndex = 0;
	for (int32 b = 0; b < TeamList.teams.Num(); b++)
	{
		if (TeamList.teams[b].number == winnerTeamID) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] Found Winning team."));
			roundWinnerIndex = b;
		}
		else {
			roundLoserIndex = b;
		}
	}
	TeamList.teams[roundWinnerIndex].roundWinCount = TeamList.teams[roundWinnerIndex].roundWinCount + 1;

	//  the match is over.

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RecordMatchWin] - Ending the Game"));

	// calculate new ranks for all of the players
	CalculateNewTeamRank(roundWinnerIndex, roundLoserIndex);

	//set winner for the winning team
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		if (MatchInfo.players[b].teamId == winnerTeamID) {
			MatchInfo.players[b].win = true;
			MatchInfo.players[b].score = MatchInfo.players[b].score + 1;
			MatchInfo.players[b].experience = MatchInfo.players[b].experience + 1;
			MatchInfo.players[b].experienceThisLevel = MatchInfo.players[b].experienceThisLevel + 1;

			// DO level up - TODO move this to a function
			//  level / 3 = exp required to level

			if (MatchInfo.players[b].level / 3.0f < MatchInfo.players[b].experienceThisLevel)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [RecordMatchWin] - Level Up"));

				MatchInfo.players[b].experienceThisLevel = MatchInfo.players[b].experienceThisLevel - (MatchInfo.players[b].level / 3.0f);
				MatchInfo.players[b].level = MatchInfo.players[b].level + 1;
			}
		}
	}

	bool gamesubmitted = SubmitMatchMakerResults();

	//Deauthorize everyone later.  first show results and loot screen.

	ShowMatchResults();
	return true;
}

FMyServerLink UMyGameInstance::GetServerLinkByTargetServerKeyId(FString incomingTargetServerKeyId) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] GetServerLinkByTargetServerKeyId."));
	for (int32 b = 0; b < ServerLinks.links.Num(); b++)
	{
		if (ServerLinks.links[b].targetServerKeyId == incomingTargetServerKeyId) {
			return ServerLinks.links[b];
		}
	}
	// just make an empty one
	FMyServerLink emptylink;
	return emptylink;
}


void UMyGameInstance::AttemptSpawnReward()
{
	if (IsRunningDedicatedServer())
	{
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AttemptSpawnReward - Dedicated server found."));
		if (bSpawnRewardsEnabled) {
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AttemptSpawnReward - Spawn rewards enabled."));

			if (bRequestBeginPlayStarted) {
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AttemptSpawnReward - bRequestBeginPlayStarted."));
				if (SpawnRewardServerMinimumBalanceRequired < serverCurrency) {
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AttemptSpawnReward - Server has enough currency."));
					float randomchance = FMath::RandRange(0.0f, 1.0f);
					if (randomchance < SpawnRewardChance) {
						//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AttemptSpawnReward - Random success."));
						UWorld* const World = GetWorld(); // get a reference to the world
						if (World) {
							// if world exists, spawn the actor
							float randomXlocation = FMath::RandRange(SpawnRewardLocationXMin, SpawnRewardLocationXMax);
							float randomYlocation = FMath::RandRange(SpawnRewardLocationYMin, SpawnRewardLocationYMax);
							float randomZlocation = FMath::RandRange(SpawnRewardLocationZMin, SpawnRewardLocationZMax);

							FVector spawnlocation = FVector(randomXlocation, randomYlocation, randomZlocation);
							FTransform SpawnTransform = FTransform(spawnlocation);
							AMyRewardItemActor* const RewardActor = World->SpawnActor<AMyRewardItemActor>(AMyRewardItemActor::StaticClass(), SpawnTransform);

							// reduce the server's balance by the reward amount
							serverCurrency = serverCurrency - SpawnRewardValue;
						}
					}
				}
			}
		}
	}
}

void UMyGameInstance::AttemptStartMatch()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AttemptStartMatch."));
	if (IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] AttemptStartMatch - Dedicated server found."));
		// travel to the third person map
		// This is just a simple example.  

		// calculate the average rank of the teams
		int32 team0RankTotal = 0;
		for (int32 b = 0; b < TeamList.teams[0].players.Num(); b++)
		{
			team0RankTotal = team0RankTotal + TeamList.teams[0].players[b].rank;
		}
		TeamList.teams[0].averageRank = team0RankTotal / TeamList.teams[0].players.Num();

		int32 team1RankTotal = 0;
		for (int32 b = 0; b < TeamList.teams[1].players.Num(); b++)
		{
			team1RankTotal = team1RankTotal + TeamList.teams[1].players[b].rank;
		}
		TeamList.teams[1].averageRank = team1RankTotal / TeamList.teams[1].players.Num();

		MatchStarted = true;

		// Default map in case we don't get a match.
		FString UrlString = TEXT("/Game/Maps/Arena?listen");

		// You can also switch maps depending on the gameMode
		if (MatchInfo.gameModeTitle == "1v1")
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [AttemptStartMatch] gameModeTitle = 1v1"));

		}

		// Or do some kind of map randomization

		GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;
		GetWorld()->ServerTravel(UrlString);
	}
}

void UMyGameInstance::CalculateNewRank(int32 WinnerPlayerIndex, int32 LoserPlayerIndex, bool penalizeLoser) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] "));

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] WinnerRank %d"), MatchInfo.players[WinnerPlayerIndex].rank);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] LoserRank %d"), MatchInfo.players[LoserPlayerIndex].rank);
	// redoing this according to:
	// https://metinmediamath.wordpress.com/2013/11/27/how-to-calculate-the-elo-rating-including-example/
	float winnerTransformedRankExp = MatchInfo.players[WinnerPlayerIndex].rank / 400.0f;
	float winnerTransformedRank = pow(10.0f, winnerTransformedRankExp);
	float loserTransformedRankExp = MatchInfo.players[LoserPlayerIndex].rank / 400.0f;
	float loserTransformedRank = pow(10.0f, loserTransformedRankExp);

	float winnerExpected = winnerTransformedRank / (winnerTransformedRank + loserTransformedRank);
	float loserExpected = loserTransformedRank / (winnerTransformedRank + loserTransformedRank);

	float k = 32.0f;

	int32 newWinnerRank = round(MatchInfo.players[WinnerPlayerIndex].rank + k * (1.0f - winnerExpected));
	int32 newLoserRank = round(MatchInfo.players[LoserPlayerIndex].rank + k * (0.0f - loserExpected));



	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] newWinnerRank %d"), newWinnerRank);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] NewLoserRank %d"), newLoserRank);

	MatchInfo.players[WinnerPlayerIndex].rank = newWinnerRank;
	MatchInfo.players[LoserPlayerIndex].rank = newLoserRank;
}

void UMyGameInstance::CalculateNewRankContinuous(int32 WinnerPlayerIndex, int32 LoserPlayerIndex, bool penalizeLoser) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRankContinuous] "));

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRankContinuous] WinnerRank %d"), PlayerRecord.ActivePlayers[WinnerPlayerIndex].rank);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRankContinuous] LoserRank %d"), PlayerRecord.ActivePlayers[LoserPlayerIndex].rank);
	// redoing this according to:
	// https://metinmediamath.wordpress.com/2013/11/27/how-to-calculate-the-elo-rating-including-example/
	float winnerTransformedRankExp = PlayerRecord.ActivePlayers[WinnerPlayerIndex].rank / 400.0f;
	float winnerTransformedRank = pow(10.0f, winnerTransformedRankExp);
	float loserTransformedRankExp = PlayerRecord.ActivePlayers[LoserPlayerIndex].rank / 400.0f;
	float loserTransformedRank = pow(10.0f, loserTransformedRankExp);

	float winnerExpected = winnerTransformedRank / (winnerTransformedRank + loserTransformedRank);
	float loserExpected = loserTransformedRank / (winnerTransformedRank + loserTransformedRank);

	float k = 32.0f;

	int32 newWinnerRank = round(PlayerRecord.ActivePlayers[WinnerPlayerIndex].rank + k * (1.0f - winnerExpected));
	int32 newLoserRank = round(PlayerRecord.ActivePlayers[LoserPlayerIndex].rank + k * (0.0f - loserExpected));



	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRankContinuous] newWinnerRank %d"), newWinnerRank);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRankContinuous] NewLoserRank %d"), newLoserRank);

	PlayerRecord.ActivePlayers[WinnerPlayerIndex].rank = newWinnerRank;
	PlayerRecord.ActivePlayers[LoserPlayerIndex].rank = newLoserRank;
}


void UMyGameInstance::CalculateNewTeamRank(int32 WinnerTeamIndex, int32 LoserTeamIndex) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] "));

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] WinnerTeamIndex %d"), WinnerTeamIndex);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] LoserTeamIndex %d"), LoserTeamIndex);

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] WinnerRank %d"), TeamList.teams[WinnerTeamIndex].averageRank);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] LoserRank %d"), TeamList.teams[LoserTeamIndex].averageRank);
	// redoing this according to:
	// https://metinmediamath.wordpress.com/2013/11/27/how-to-calculate-the-elo-rating-including-example/
	float winnerTransformedRankExp = TeamList.teams[WinnerTeamIndex].averageRank / 400.0f;
	float winnerTransformedRank = pow(10.0f, winnerTransformedRankExp);
	float loserTransformedRankExp = TeamList.teams[LoserTeamIndex].averageRank / 400.0f;
	float loserTransformedRank = pow(10.0f, loserTransformedRankExp);

	float winnerExpected = winnerTransformedRank / (winnerTransformedRank + loserTransformedRank);
	float loserExpected = loserTransformedRank / (winnerTransformedRank + loserTransformedRank);

	float k = 32.0f;

	int32 newWinnerRank = round(TeamList.teams[WinnerTeamIndex].averageRank + k * (1.0f - winnerExpected));
	int32 newLoserRank = round(TeamList.teams[LoserTeamIndex].averageRank + k * (0.0f - loserExpected));



	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] newWinnerRank %d"), newWinnerRank);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] NewLoserRank %d"), newLoserRank);

	// Now figure out the differences for each team, and apply it to the individual players.

	int32 winnerRankDifference = newWinnerRank - TeamList.teams[WinnerTeamIndex].averageRank;
	int32 loserRankDifference = newLoserRank - TeamList.teams[LoserTeamIndex].averageRank;

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] winnerRankDifference %d"), winnerRankDifference);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [CalculateNewRank] loserRankDifference %d"), loserRankDifference);

	for (int32 b = 0; b < TeamList.teams[WinnerTeamIndex].players.Num(); b++)
	{
		TeamList.teams[WinnerTeamIndex].players[b].rank = TeamList.teams[WinnerTeamIndex].players[b].rank + winnerRankDifference;
		FMyActivePlayer* thisMatchPlayer = getPlayerByPlayerKey(TeamList.teams[WinnerTeamIndex].players[b].userKeyId);
		thisMatchPlayer->rank = thisMatchPlayer->rank + winnerRankDifference;
	}

	for (int32 b = 0; b < TeamList.teams[LoserTeamIndex].players.Num(); b++)
	{
		TeamList.teams[LoserTeamIndex].players[b].rank = TeamList.teams[LoserTeamIndex].players[b].rank + loserRankDifference;
		FMyActivePlayer* thisMatchPlayer = getPlayerByPlayerKey(TeamList.teams[LoserTeamIndex].players[b].userKeyId);
		thisMatchPlayer->rank = thisMatchPlayer->rank + loserRankDifference;
	}

}


bool UMyGameInstance::ShowMatchResults()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ShowMatchResults] "));
	for (int32 b = 0; b < MatchInfo.players.Num(); b++)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [ShowMatchResults] telling player to change state"));

		if (MatchInfo.players[b].bIsConnected)
		{
			if (MatchInfo.players[b].PlayerController->PlayerState)
			{
				AMyPlayerState* thisMyPlayerState = Cast<AMyPlayerState>(MatchInfo.players[b].PlayerController->PlayerState);
				if (thisMyPlayerState)
				{
					// Tell the client to trigger the delegate.
					thisMyPlayerState->TriggerShowMatchResults();
				}
			}

			// Tell HUD to change UI state
			MatchInfo.players[b].PlayerController->ClientChangeUIState(EConnectUIState::MatchResults);
		}
	}
	return true;
}

bool UMyGameInstance::NotifyDownReady()
{

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] NotifyDownReady"));

	
	//////////////////////////////////////////////////////////////
	// Convert server configuration to JSON

	FString ConfigurationOutputString;
	TSharedPtr<FJsonObject> ConfigurationJsonObject = MakeShareable(new FJsonObject);
	ConfigurationJsonObject->SetNumberField("maxPickupItemCount", maxPickupItemCount);


	TSharedRef< TJsonWriter<> > ConfigurationWriter = TJsonWriterFactory<>::Create(&ConfigurationOutputString);
	FJsonSerializer::Serialize(ConfigurationJsonObject.ToSharedRef(), ConfigurationWriter);
	UE_LOG(LogTemp, Log, TEXT("[UMyGameInstance] ConfigurationOutputString: %s"), *ConfigurationOutputString);

	FString nonceString = "10951350917635";
	FString encryption = "off";  // Allowing unencrypted on sandbox for now.

	TSharedPtr<FJsonObject> ServerJsonObj = MakeShareable(new FJsonObject);

	if (ServerSessionHostAddress.Len() > 1) {
		//UE_LOG(LogTemp, Log, TEXT("ServerSessionHostAddress: %s"), *ServerSessionHostAddress);
		//UE_LOG(LogTemp, Log, TEXT("ServerSessionID: %s"), *ServerSessionID);
		ServerJsonObj->SetStringField("session_host_address", ServerSessionHostAddress);
	}

	ServerJsonObj->SetStringField("nonce", "nonceString");
	ServerJsonObj->SetStringField("encryption", encryption);
	ServerJsonObj->SetStringField("configuration", ConfigurationOutputString);

	FString JsonOutputString;
	TSharedRef< TJsonWriter<> > FinalWriter = TJsonWriterFactory<>::Create(&JsonOutputString);
	FJsonSerializer::Serialize(ServerJsonObj.ToSharedRef(), FinalWriter);

	FString APIURI = "/api/v1/server/down_ready";
	bool requestSuccess = PerformJsonHttpRequest(&UMyGameInstance::NotifyDownReadyComplete, APIURI, JsonOutputString, ""); // NO AccessToken

	return requestSuccess;
}

void UMyGameInstance::NotifyDownReadyComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
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
			bool Authorization = JsonParsed->GetBoolField("authorization");
			UE_LOG(LogTemp, Log, TEXT("Authorization"));
			if (Authorization)
			{
				UE_LOG(LogTemp, Log, TEXT("Authorization True"));
				// we don't care about the results
			}
		}
	}
}
