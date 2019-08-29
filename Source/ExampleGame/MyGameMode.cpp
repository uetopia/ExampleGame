// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "ProMMO.h"
#include "MyPlayerState.h"
#include "MyGameState.h"
#include "MyGameSession.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "UEtopiaPersistCharacter.h"
#include "MyPlayerStart.h"
#include "Blueprint/UserWidget.h"



AMyGameMode::AMyGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// set default pawn class to our flying pawn

	static ConstructorHelpers::FClassFinder<ACharacter> PlayerPawnBPClass(TEXT("/Game/MyUEtopiaPersistCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] PlayerPawnBPClass.Class = NUL"));
	}

	PlayerStateClass = AMyPlayerState::StaticClass();
	GameStateClass = AMyGameState::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();

	bUseSeamlessTravel = true;

	/** Time a playerstate will stick around in an inactive state after a player logout.  seconds?
	// We don't want a player state to exist after a player has disconnected.
	// It causes duplicate results and makes it impossible to find the correct/active state */
	InactivePlayerStateLifeSpan = 0.5f;
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
}

/** Returns game session class to use */
TSubclassOf<AGameSession> AMyGameMode::GetGameSessionClass() const
{
	return AMyGameSession::StaticClass();
}


FString AMyGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] InitNewPlayer"));

	FString ErrorMessage;

	check(NewPlayerController);

	//  we need to set the platformID in the player state so we can find this player again.
	AMyPlayerState* PlayerS = Cast<AMyPlayerState>(NewPlayerController->PlayerState);
	FString Name = UGameplayStatics::ParseOption(Options, TEXT("Name"));

	if (PlayerS)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] InitNewPlayer Param1: %s"), *Name);

		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [InitNewPlayer] - Found My player state"));
		PlayerS->playerKeyId = Name;
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [InitNewPlayer] - Set platformID"));
	}

	// TODO: this should only run on dedicated server
	if (IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] AMyGameMode::InitNewPlayer RUNNING ON DEDICATED SERVER!"));
		int32 playerId = PlayerS->PlayerId; // NewPlayerController->PlayerState->PlayerId;

		// This number is always 0 even with multiple players logged in...  

		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] InitNewPlayer playerId: %d"), playerId);
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] InitNewPlayer Options: %s"), *Options);

		/* At this point we want to be able to deny the Login, but we need to do it over http, which requires a delegate.
		// So we're just going to allow login, then kick them if the http request comes up negative
		// TODO find a better way to do this - it should probably be part of onlineSubsystem.
		*/
		UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		AMyPlayerController* playerC = Cast<AMyPlayerController>(NewPlayerController);

		// Register the player with the session
		const TSharedPtr<const FUniqueNetId> UniqueIdTemp = UniqueId.GetUniqueNetId();
		GameSession->RegisterPlayer(NewPlayerController, UniqueIdTemp, UGameplayStatics::HasOption(Options, TEXT("bIsFromInvite")));

		// Moving the activate routine below register allows us to use the actual UE playerID instead of 0

		playerId = PlayerS->PlayerId; // NewPlayerController->PlayerState->PlayerId;
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] InitNewPlayer playerId: %d"), playerId);

		// WE need to move this...  We don't have the player access token yet.
		// TheGameInstance->ActivatePlayer(playerC, Name, playerId, UniqueId);

		// save the vars in the controller so we can run this later.
		playerC->UniqueId = UniqueId;
		playerC->playerKeyId = Name;
		playerC->playerIDTemp = playerId;

		// Init player's name
		FString InName = UGameplayStatics::ParseOption(Options, TEXT("Name")).Left(20);
		if (InName.IsEmpty())
		{
			InName = FString::Printf(TEXT("%s%i"), *DefaultPlayerName.ToString(), NewPlayerController->PlayerState->PlayerId);
		}

		ChangeName(NewPlayerController, InName, false);

		// Find a starting spot
		AActor* const StartSpot = FindPlayerStart(NewPlayerController, Portal);
		if (StartSpot != NULL)
		{
			// Set the player controller / camera in this new location
			FRotator InitialControllerRot = StartSpot->GetActorRotation();
			InitialControllerRot.Roll = 0.f;
			NewPlayerController->SetInitialLocationAndRotation(StartSpot->GetActorLocation(), InitialControllerRot);
			NewPlayerController->StartSpot = StartSpot;
		}
		else
		{
			ErrorMessage = FString::Printf(TEXT("Failed to find PlayerStart"));
		}
	}

	return ErrorMessage;
}


AActor* AMyGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChoosePlayerStart] "));

	TArray<AMyPlayerStart*> Starts;

	// First try for team slots - team info is in playerstate.
	if (Player)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChoosePlayerStart] Found Player "));
		AMyPlayerState* PS = Cast<AMyPlayerState>(Player->PlayerState);
		if (PS)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChoosePlayerStart] Found PlayerState "));

			for (TActorIterator<AMyPlayerStart> StartItr(GetWorld()); StartItr; ++StartItr)
			{
				if (StartItr->teamIndex == PS->TeamId)
				{
					// Also check teamplayerIndex
					if (StartItr->playerIndex == PS->TeamPlayerIndex)
					{
						Starts.Add(*StartItr);
					}
				}
			}
			if (Starts.Num())
			{
				return Starts[FMath::RandRange(0, Starts.Num() - 1)];
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChoosePlayerStart] Could not find a start by team "));

	// Try for any start if we can't get playerstate 
	for (TActorIterator<AMyPlayerStart> StartItr(GetWorld()); StartItr; ++StartItr)
	{
		Starts.Add(*StartItr);
	}

	if (Starts.Num())
	{
		return Starts[FMath::RandRange(0, Starts.Num() - 1)];
	}
	return NULL;
}

void AMyGameMode::RecordKill(int32 killerPlayerID, int32 victimPlayerID)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] "));

	FTimerDelegate TimerDel;

	FTimerHandle TimerHandle;

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	if (TheGameInstance)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] Got game instance"));

		// TODO EXAMPLE GAME - move this all to GameMode
		if (TheGameInstance->UEtopiaMode == "competitive") {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] RecordKill - Mode set to competitive"));
			/*
			// If we are here, this server is running in competitive/matchmaker mode.
			//
			*/
			// get attacker activeplayer
			bool attackerPlayerIDFound = false;
			int32 killerPlayerIndex = 0;
			// sum all the round kills while we're looping
			int32 roundKillsTotal = 0;

			// NOT refactoring to use get by function becaseu we do want to loop through them in this case to count round kills.
			//FMyActivePlayer* KillerPlayer = TheGameInstance->getPlayerByPlayerId(killerPlayerID);

			for (int32 b = 0; b < TheGameInstance->MatchInfo.players.Num(); b++)
			{
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [DeAuthorizePlayer] playerID: %s"), ActivePlayers[b].playerID);
				if (TheGameInstance->MatchInfo.players[b].playerID == killerPlayerID) {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - FOUND MATCHING killer playerID"));
					attackerPlayerIDFound = true;
					killerPlayerIndex = b;
				}
				roundKillsTotal = roundKillsTotal + TheGameInstance->MatchInfo.players[b].roundKills;
			}
			// we need one more since this kill has not been added to the list yet
			roundKillsTotal = roundKillsTotal + 1;

			if (killerPlayerID == victimPlayerID) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] suicide"));
			}
			else {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] Not a suicide"));

				// get victim
				// not refactoring here becasue we need the index later for calculate ranks
				bool victimPlayerIDFound = false;
				int32 victimPlayerIndex = 0;

				for (int32 b = 0; b < TheGameInstance->MatchInfo.players.Num(); b++)
				{
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [DeAuthorizePlayer] playerID: %s"), ActivePlayers[b].playerID);
					if (TheGameInstance->MatchInfo.players[b].playerID == victimPlayerID) {
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - FOUND MATCHING victim playerID"));
						victimPlayerIDFound = true;
						victimPlayerIndex = b;
						// set currentRoundAlive
						TheGameInstance->MatchInfo.players[b].currentRoundAlive = false;
					}
				}

				// check to see if this victim is already in the kill list

				bool victimIDFoundInKillList = false;

				for (int32 b = 0; b < TheGameInstance->MatchInfo.players[killerPlayerIndex].killed.Num(); b++)
				{
					if (TheGameInstance->MatchInfo.players[killerPlayerIndex].killed[b] == TheGameInstance->MatchInfo.players[victimPlayerIndex].userKeyId)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Victim already in kill list"));
						victimIDFoundInKillList = true;
					}
				}

				if (victimIDFoundInKillList == false) {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Adding victim to kill list"));
					TheGameInstance->MatchInfo.players[killerPlayerIndex].killed.Add(TheGameInstance->MatchInfo.players[victimPlayerIndex].userKeyId);
				}

				// Increase the killer's kill count
				TheGameInstance->MatchInfo.players[killerPlayerIndex].roundKills = TheGameInstance->MatchInfo.players[killerPlayerIndex].roundKills + 1;
				// And increase the victim's deaths
				TheGameInstance->MatchInfo.players[victimPlayerIndex].roundDeaths = TheGameInstance->MatchInfo.players[victimPlayerIndex].roundDeaths + 1;

				// Give the killer some xp and score
				TheGameInstance->MatchInfo.players[killerPlayerIndex].score = TheGameInstance->MatchInfo.players[killerPlayerIndex].score + 100;
				TheGameInstance->MatchInfo.players[killerPlayerIndex].experience = TheGameInstance->MatchInfo.players[killerPlayerIndex].experience + 10;

				//calculate new ranks;
				TheGameInstance->CalculateNewRank(killerPlayerIndex, victimPlayerIndex, true);

				//Calculate winning team


			}

			AGameState* gameState = Cast<AGameState>(GetWorld()->GetGameState());
			AMyGameState* uetopiaGameState = Cast<AMyGameState>(gameState);


			// Check to see if the round is over
			// reset the level if one team is all dead
			// If you have a game that has more than two teams you should rewrite this for your end round logic
			bool anyTeamDead = false;
			int32 stillAliveTeamId = 0;
			for (int32 b = 0; b <= TheGameInstance->teamCount; b++) // b is the team ID we're checking
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] Checking team %d"), b);
				bool thisTeamAlive = false;

				for (int32 ip = 0; ip < TheGameInstance->MatchInfo.players.Num(); ip++) // ip is player index
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [CalculateNewRank] Checking player %d"), ip);
					if (TheGameInstance->MatchInfo.players[ip].teamId == b) {
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Player is a member of this team"));
						// current round alive boolean check
						if (TheGameInstance->MatchInfo.players[ip].currentRoundAlive) {
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Player is alive"));
							thisTeamAlive = true;
							stillAliveTeamId = b;
						}
						else {
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Player is dead"));
						}
					}
				}

				if (thisTeamAlive == false) {
					anyTeamDead = true;
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - A team is dead"));
				}


			}

			// Get the index from our TeamList struct - it might not be the same index!
			int32 TeamStillAliveTeamListIndex = 0;
			for (int32 b = 0; b < TheGameInstance->TeamList.teams.Num(); b++)
			{
				if (TheGameInstance->TeamList.teams[b].number == stillAliveTeamId)
				{
					TeamStillAliveTeamListIndex = b;
				}
			}

			if (anyTeamDead) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Detected dead team"));
				// flag and count the team win
				// this is only for two teams - if you have more, change this.
				for (int32 b = 0; b < TheGameInstance->MatchInfo.players.Num(); b++)
				{
					if (TheGameInstance->MatchInfo.players[b].teamId == stillAliveTeamId) {
						TheGameInstance->MatchInfo.players[b].score = TheGameInstance->MatchInfo.players[b].score + 200;
						TheGameInstance->MatchInfo.players[b].experience = TheGameInstance->MatchInfo.players[b].experience + 75;
					}
				}

				TheGameInstance->TeamList.teams[TeamStillAliveTeamListIndex].roundWinCount = TheGameInstance->TeamList.teams[TeamStillAliveTeamListIndex].roundWinCount + 1;

			}
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] RecordKill - Mode set to continuous"));
			// get attacker activeplayer
			bool attackerPlayerIDFound = false;
			int32 killerPlayerIndex = 0;
			// sum all the round kills while we're looping
			int32 roundKillsTotal = 0;

			// TODO refactor this to use our get player function instead

			for (int32 b = 0; b < TheGameInstance->MatchInfo.players.Num(); b++)
			{
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [DeAuthorizePlayer] playerID: %s"), ActivePlayers[b].playerID);
				if (TheGameInstance->MatchInfo.players[b].playerID == killerPlayerID) {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - FOUND MATCHING killer playerID"));
					attackerPlayerIDFound = true;
					killerPlayerIndex = b;
				}
				roundKillsTotal = roundKillsTotal + TheGameInstance->MatchInfo.players[b].roundKills;
			}
			// we need one more since this kill has not been added to the list yet
			roundKillsTotal = roundKillsTotal + 1;

			if (killerPlayerID == victimPlayerID) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] suicide"));
			}
			else {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] Not a suicide"));

				// get victim activeplayer
				bool victimPlayerIDFound = false;
				int32 victimPlayerIndex = 0;

				for (int32 b = 0; b < TheGameInstance->MatchInfo.players.Num(); b++)
				{
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyGameInstance] [DeAuthorizePlayer] playerID: %s"), ActivePlayers[b].playerID);
					if (TheGameInstance->MatchInfo.players[b].playerID == victimPlayerID) {
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - FOUND MATCHING victim playerID"));
						victimPlayerIDFound = true;
						victimPlayerIndex = b;
						break;
					}
				}

				// check to see if this victim is already in the kill list

				bool victimIDFoundInKillList = false;

				for (int32 b = 0; b < TheGameInstance->MatchInfo.players[killerPlayerIndex].killed.Num(); b++)
				{
					if (TheGameInstance->MatchInfo.players[killerPlayerIndex].killed[b] == TheGameInstance->MatchInfo.players[victimPlayerIndex].userKeyId)
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Victim already in kill list"));
						victimIDFoundInKillList = true;
					}
				}

				if (victimIDFoundInKillList == false) {
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [RecordKill] - Adding victim to kill list"));
					TheGameInstance->MatchInfo.players[killerPlayerIndex].killed.Add(TheGameInstance->MatchInfo.players[victimPlayerIndex].userKeyId);
				}

				// create an event also
				FString eventSummary = "killed " + TheGameInstance->MatchInfo.players[victimPlayerIndex].playerTitle;
				TheGameInstance->RecordEvent(killerPlayerID, eventSummary, "location_searching", "Kill");  // look at https://material.io/icons/ for other icons

				// Increase the killer's kill count
				TheGameInstance->MatchInfo.players[killerPlayerIndex].roundKills = TheGameInstance->MatchInfo.players[killerPlayerIndex].roundKills + 1;
				// And increase the victim's deaths
				TheGameInstance->MatchInfo.players[victimPlayerIndex].roundDeaths = TheGameInstance->MatchInfo.players[victimPlayerIndex].roundDeaths + 1;

				// Give the killer some xp and score
				TheGameInstance->MatchInfo.players[killerPlayerIndex].score = TheGameInstance->MatchInfo.players[killerPlayerIndex].score + 100;
				TheGameInstance->MatchInfo.players[killerPlayerIndex].experience = TheGameInstance->MatchInfo.players[killerPlayerIndex].experience + 10;

				//Change rank
				TheGameInstance->CalculateNewRank(killerPlayerIndex, victimPlayerIndex, true);

				// Optionally, you can also have a CRED cost associated with killing/dying.
				// Leaving it muted here, since it's not a standard MMO feature.

				// Increase the killer's balance
				//PlayerRecord.ActivePlayers[killerPlayerIndex].currencyCurrent = PlayerRecord.ActivePlayers[killerPlayerIndex].currencyCurrent + killRewardBTC;

				// Decrease the victim's balance
				//PlayerRecord.ActivePlayers[victimPlayerIndex].currencyCurrent = PlayerRecord.ActivePlayers[victimPlayerIndex].currencyCurrent - incrementCurrency;

				// TODO kick the victim if it falls below the minimum?

			}

		}


		/*

		//FMyMatchPlayer* killerMatchPlayer = TheGameInstance->getMatchPlayerByPlayerId(killerPlayerID);
		FMyActivePlayer* victimPlayer = TheGameInstance->getMatchPlayerByPlayerId(victimPlayerID);

		// It could have been an AI kill which would not have a killerMatchPlayer - but we still want the player to respawn.
		if (victimPlayer)
		{
			TimerDel.BindUFunction(this, FName("RestartPlayer"), victimPlayer->PlayerController);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 5.0f, false);
		}
		*/
	}
}

void AMyGameMode::Logout(AController* Exiting)
{
	// Handle users that disconnect from the server.
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [Logout] "));
	Super::Logout(Exiting);

	AMyPlayerState* ExitingPlayerState = Cast<AMyPlayerState>(Exiting->PlayerState);
	int ExitingPlayerId = ExitingPlayerState->PlayerId;

	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [Logout] ExitingPlayerId: %i"), ExitingPlayerId);

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	//Save off PlayerState vars that we need
	TheGameInstance->BackupExitingPlayerState(ExitingPlayerId, ExitingPlayerState);

	TheGameInstance->DeActivatePlayer(ExitingPlayerId);

}

void AMyGameMode::RestartPlayer(class AController* NewPlayer)
{
	Super::RestartPlayer(NewPlayer);
}

void AMyGameMode::KilledBy(AController* Killer, AActor* DamageCauser, AController* KilledController, AActor* KilledActor, const struct FGameplayEffectSpec& KillingEffectSpec)
{
	if (KilledController)
	{
		KilledController->ChangeState(NAME_Spectating);
		RestartPlayer(KilledController);
	}
}