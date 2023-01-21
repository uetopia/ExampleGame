// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "UEtopiaPersistCharacter.h"

class UMyGameInstance;

UMyAttributeSet::UMyAttributeSet(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	Health = 100.f;
	MaxHealth = 100.f;
}


void UMyAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == HealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxHealth);
	}
}

void UMyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{

}

void UMyAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)
{
	UAbilitySystemComponent* Source = Data.EffectSpec.GetContext().GetOriginalInstigatorAbilitySystemComponent();

	if (HealthAttribute() == Data.EvaluatedData.Attribute)
	{

		// Get the Target actor
		AActor* DamagedActor = nullptr;
		AUEtopiaPersistCharacter* DamagedUEtopiaCompChar = nullptr;
		AController* DamagedController = nullptr;
		APlayerState* DamagedPlayerS = nullptr;
		int32 DamagedPlayerId = 0;

		if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
		{
			DamagedActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
			DamagedUEtopiaCompChar = Cast<AUEtopiaPersistCharacter>(DamagedActor);
			DamagedController = Data.Target.AbilityActorInfo->PlayerController.Get();

			if (DamagedUEtopiaCompChar)
			{
				DamagedPlayerS = DamagedUEtopiaCompChar->GetPlayerState();
				DamagedPlayerId = DamagedPlayerS->PlayerId;
			}


		}

		// Get the Source actor
		AActor* AttackingActor = nullptr;
		AUEtopiaPersistCharacter* AttackingUEtopiaCompChar = nullptr;
		AController* AttackingController = nullptr;
		APlayerState* AttackingdPlayerS = nullptr;
		int32 AttackingPlayerId = 0;


		if (Source && Source->AbilityActorInfo.IsValid() && Source->AbilityActorInfo->AvatarActor.IsValid())
		{
			AttackingActor = Source->AbilityActorInfo->AvatarActor.Get();
			AttackingUEtopiaCompChar = Cast<AUEtopiaPersistCharacter>(AttackingActor);
			AttackingController = Source->AbilityActorInfo->PlayerController.Get();
			//AttackingPlayerController = Source->AbilityActorInfo->PlayerController.Get();
			if (AttackingUEtopiaCompChar)
			{
				AttackingdPlayerS = AttackingUEtopiaCompChar->GetPlayerState();
				AttackingPlayerId = AttackingdPlayerS->PlayerId;
			}
		}
		// keep track of kill status
		bool thisWasAKill = false;

		// Clamp health
		Health = FMath::Clamp(Health, 0.0f, MaxHealth);
		if (Health <= 0)
		{

			// Handle death with GASCharacter. Note this is just one example of how this could be done.
			if (AUEtopiaPersistCharacter* GASChar = Cast<AUEtopiaPersistCharacter>(DamagedActor))
			{
				// Construct a gameplay cue event for this death
				FGameplayCueParameters Params(Data.EffectSpec.GetContext());
				Params.RawMagnitude = Data.EvaluatedData.Magnitude;;
				Params.NormalizedMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude / MaxHealth);
				Params.AggregatedSourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
				Params.AggregatedTargetTags = *Data.EffectSpec.CapturedTargetTags.GetAggregatedTags();

				GASChar->Die(AttackingController, AttackingActor, Data.EffectSpec, Params.RawMagnitude, Params.Normal);

				thisWasAKill = true;
			}
		}

		// save the damage to the instance gamestory struct for GameData submission
		// only do this on server
		// only do this if it was a hit (keep within the heath block



		if (IsRunningDedicatedServer()) {
			UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

			if (TheGameInstance)
			{
				// only do this if we are in a matchmaker or metagame mode - skip if FFA 
				if (TheGameInstance->UEtopiaMode == "competitive")
				{
					FMatchStoryEvent MatchStoryEvent;

					// calculate importance
					float importance = 0.01;

					MatchStoryEvent.targetKilled = thisWasAKill;

					// get it from the setbycallermagnitude, which we set within the calculation execution
					MatchStoryEvent.eventSummary = "GameplayEffectExecution";
					MatchStoryEvent.eventImportance = importance;

					// Get the playerKeys here.  This is our last chance
					// these are actually Unreal Engine playerID's  Like 256, 257
					// Which is OK, we just need to get the correct Keys later.
					// do this in gameInstance.processMatchStory
					MatchStoryEvent.targetPlayerId = DamagedPlayerId;
					MatchStoryEvent.sourcePlayerId = AttackingPlayerId;

					MatchStoryEvent.hitCount = 1;

					UE_LOG(LogTemp, Log, TEXT("PostGameplayEffectExecute DamageDone: %f"), Data.EffectSpec.GetSetByCallerMagnitude(FName(TEXT("DamageDone"))));

					MatchStoryEvent.damageDone = Data.EffectSpec.GetSetByCallerMagnitude(FName(TEXT("DamageDone")));

					// TODO Add all of your other variables here.

					TheGameInstance->AddMatchStoryEvent(MatchStoryEvent);
				}
			}
		}
	}

}

// ----------------------------------------------------------------------------------

FGameplayAttribute UMyAttributeSet::HealthAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, Health));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UMyAttributeSet::MaxHealthAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, MaxHealth));
	return FGameplayAttribute(Property);
}

void UMyAttributeSet::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME( UMyAttributeSet, MyAttribute); Chances are this is how you would ordinarily do it, however in the case of attributes this'll lead to confusing and annoying replication errors, usually involving clientside ability prediction.
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Health, COND_None, REPNOTIFY_Always); //This is how it is done properly for attributes. 
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always); //This is how it is done properly for attributes. 
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, AttackPower, COND_None, REPNOTIFY_Always); //This is how it is done properly for attributes. 
}