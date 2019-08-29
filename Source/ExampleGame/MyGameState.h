// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "MyGameInstance.h"
//#include "MyServerPortalActor.h"
#include "MyGameState.generated.h"

/**
*
*/
UCLASS()
class EXAMPLEGAME_API AMyGameState : public AGameState
{
	GENERATED_UCLASS_BODY()

		virtual void BeginPlay();

	void LoadLevel();

	/* Handle to manage the timer */
	FTimerHandle ServerPortalsTimerHandle;


public:

	UPROPERTY(Replicated, BlueprintReadOnly)
		FMyServerLinks ServerLinks;

	UPROPERTY(Replicated, BlueprintReadOnly)
		FString serverTitle;

	UPROPERTY(Replicated, BlueprintReadOnly)
		FString MatchTitle;

	UPROPERTY(Replicated, BlueprintReadOnly)
		FMyTeamList TeamList;
	
	// ZoneDetail comes from metagame, put any json there to pass through to the game
	UPROPERTY(Replicated, BlueprintReadOnly)
		FZoneDetails ZoneDetail;

	// Most games need a bunch of values to handle score, progress etc.
	// Each game mode will have different requirements, and we may want to have game states specifically for each of the game modes.

	UPROPERTY(Replicated, BlueprintReadOnly)
		EGameStateHUDType GameStateHUDType;

	UPROPERTY(Replicated, BlueprintReadOnly)
		FScoreboardKOTH KOTHScore;


	// Day/Night Cycle 
	// Rep notify to tell the client to load the new inventory
	UPROPERTY(ReplicatedUsing = OnRep_OnSunAngleChange)
		float sunAngle;

	// this function just calls the delegate.
	UFUNCTION()
		virtual void OnRep_OnSunAngleChange();

	float deltaSecondsElapsed = 0.0f;

	UPROPERTY(BlueprintReadWrite)
		float sunAngleMultiplier = 1.0f;

	// Control for servers that do not allow conbat.
	UPROPERTY(Replicated, BlueprintReadOnly)
		bool bCombatEnabled = true;

	// prevent duplicate results.
	UPROPERTY(VisibleAnywhere, Category = "UETOPIA")
		bool bRoundWinProcessing = false;


	// Server shards

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "UETOPIA")
	TArray<FMyServerShard> ServerShards;

	

};
