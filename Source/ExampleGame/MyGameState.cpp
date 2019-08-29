// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameState.h"
#include "ProMMO.h"
#include "Net/UnrealNetwork.h"
//#include "MyServerPortalActor.h"



AMyGameState::AMyGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] CONSTRUCT"));

	ServerShards.Empty();

	KOTHScore.Team1Percentage = 0.0f;
	KOTHScore.Team2Percentage = 0.0f;

	KOTHScore.ClaimPercentageSpeed = 0.005f;
	KOTHScore.CapturePercentageSpeed = 0.001f;

	GameStateHUDType = EGameStateHUDType::None;

	// populate the zone Info - skip if it does not exist
	if (GetWorld())
	{
		UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		if (TheGameInstance)
		{
			ZoneDetail = TheGameInstance->ZoneDetail;
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] Copied ZoneInfo From GameInstance"));
		}
	}


}

void AMyGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyGameState, serverTitle);
	DOREPLIFETIME(AMyGameState, ServerLinks);
	DOREPLIFETIME(AMyGameState, TeamList);
	DOREPLIFETIME(AMyGameState, KOTHScore);
	DOREPLIFETIME(AMyGameState, GameStateHUDType);
	DOREPLIFETIME(AMyGameState, ZoneDetail);
	DOREPLIFETIME(AMyGameState, ServerShards);
	DOREPLIFETIME(AMyGameState, bCombatEnabled);
	//DOREPLIFETIME(AMyGameState, bIsShardedServer);

}

void AMyGameState::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	if (IsRunningDedicatedServer()) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] Dedicated server found."));

		// populate the team names - skip if they don't exist yet.
		UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

		if (TheGameInstance->TeamList.teams.Num() > 1)
		{
			KOTHScore.Team1Title = TheGameInstance->TeamList.teams[0].title;
			KOTHScore.Team2Title = TheGameInstance->TeamList.teams[1].title;
		}

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(
			UnusedHandle, this, &AMyGameState::LoadLevel, 2.0f, false);
	}
}


void AMyGameState::LoadLevel()
{

	if (IsRunningDedicatedServer()) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] LoadLevel - Dedicated server found."));

		// Load our old data
		bool FileIOSuccess;
		TArray<FString> StreamingLevelsStates;
		FString FileName = "serversavedata.dat";

		URamaSaveLibrary::RamaSave_LoadFromFile(GetWorld(), FileIOSuccess, FileName);

		if (FileIOSuccess) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] LoadLevel File IO Success."));
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] LoadLevel File IO FAIL."));
		}
	}
}

void AMyGameState::OnRep_OnSunAngleChange()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] OnRep_OnSunAngleChange."));
}