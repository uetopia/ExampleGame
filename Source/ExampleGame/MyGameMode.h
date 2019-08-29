// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
*
*/
UCLASS()
class EXAMPLEGAME_API AMyGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()



protected:
	/** Returns game session class to use */
	virtual TSubclassOf<AGameSession> GetGameSessionClass() const override;

	/**
	* Customize incoming player based on URL options
	*
	* @param NewPlayerController player logging in
	* @param UniqueId unique id for this player
	* @param Options URL options that came at login
	*
	*/
	virtual FString InitNewPlayer(class APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal = TEXT(""));

	/** The Widget class to use for our HUD screen */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UEtopia", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	/** The instance of the HUD */
	UPROPERTY()
	class UUserWidget* CurrentWidget;


public:

	void Logout(AController* Exiting);

	virtual void BeginPlay() override;

	virtual void RestartPlayer(class AController* NewPlayer) override;

	AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	// This is intended to be overridden by your specific game modes, as each game mode will have specific rules for killing/dying
	virtual void RecordKill(int32 killerPlayerID, int32 victimPlayerID);

	void KilledBy(AController* Killer, AActor* DamageCauser, AController* KilledContoller, AActor* KilledActor, const struct FGameplayEffectSpec& KillingEffectSpec);

	/** Is combat allowed in this game mode?  */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UEtopia")
		bool bCombatEnabled;
};
