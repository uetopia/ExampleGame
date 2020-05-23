// Fill out your copyright notice in the Description page of Project Settings.


#include "ArenaGameMode.h"
#include "MyAttributeSet.h"
#include "MyPlayerController.h"
#include "MyPlayerState.h"
#include "MyGameInstance.h"
#include "MyGameState.h"


void AArenaGameMode::RestartPlayer(AController* NewPlayer)
{
	if (NewPlayer == nullptr || NewPlayer->IsPendingKillPending())
	{
		return;
	}

	AActor* StartSpot = FindPlayerStart(NewPlayer);

	// If a start spot wasn't found,
	if (StartSpot == nullptr)
	{
		// Check for a previously assigned spot
		if (NewPlayer->StartSpot != nullptr)
		{
			StartSpot = NewPlayer->StartSpot.Get();
			UE_LOG(LogGameMode, Warning, TEXT("RestartPlayer: Player start not found, using last start spot"));
		}
	}

	RestartPlayerAtPlayerStart(NewPlayer, StartSpot);

	// Set health back to full

	AMyPlayerController* playerController = Cast<AMyPlayerController>(NewPlayer);

	if (playerController)
	{
		AMyPlayerState* myPlayerState = Cast<AMyPlayerState>(playerController->PlayerState);
		if (myPlayerState)
		{

			static FProperty* MaxHealthProperty = FindFieldChecked<FProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, MaxHealth));
			float maxHealthValue = myPlayerState->GetAbilitySystemComponent()->GetNumericAttributeBase(FGameplayAttribute(MaxHealthProperty));

			static FProperty* HealthProperty = FindFieldChecked<FProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, Health));
			myPlayerState->GetAbilitySystemComponent()->SetNumericAttributeBase(FGameplayAttribute(HealthProperty), maxHealthValue);
		}

		// Set the UI state

		playerController->ClientChangeUIState(EConnectUIState::Play);

	}


}