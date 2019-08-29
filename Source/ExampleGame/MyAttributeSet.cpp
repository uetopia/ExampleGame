// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "UEtopiaPersistCharacter.h"


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
		AController* DamagedController = nullptr;
		if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
		{
			DamagedActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
			DamagedController = Data.Target.AbilityActorInfo->PlayerController.Get();
		}

		// Get the Source actor
		AActor* AttackingActor = nullptr;
		AController* AttackingController = nullptr;
		AController* AttackingPlayerController = nullptr;
		if (Source && Source->AbilityActorInfo.IsValid() && Source->AbilityActorInfo->AvatarActor.IsValid())
		{
			AttackingActor = Source->AbilityActorInfo->AvatarActor.Get();
			AttackingController = Source->AbilityActorInfo->PlayerController.Get();
			AttackingPlayerController = Source->AbilityActorInfo->PlayerController.Get();
			if (AttackingController == nullptr && AttackingActor != nullptr)
			{
				if (APawn* Pawn = Cast<APawn>(AttackingActor))
				{
					AttackingController = Pawn->GetController();
				}
			}
		}

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
			}
		}
	}

}

// ----------------------------------------------------------------------------------

FGameplayAttribute UMyAttributeSet::HealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, Health));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UMyAttributeSet::MaxHealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, MaxHealth));
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