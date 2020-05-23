// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UnrealNetwork.h"
#include "MyAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API UMyAttributeSet : public UAttributeSet
{
	GENERATED_UCLASS_BODY()
	
	//UPROPERTY(Replicated)
	//	float	Health;

	UPROPERTY(Category = "Attribute", EditAnywhere, ReplicatedUsing = OnRep_Health, BlueprintReadWrite)
		float Health;
	UFUNCTION()
		void OnRep_Health(float OldHealth)
	{
		// changed in 4.25 takes 3 args now with the "old" value
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Health, OldHealth);
	}

	//UPROPERTY(Replicated)
	//	float	MaxHealth;

	UPROPERTY(Category = "Attribute", EditAnywhere, ReplicatedUsing = OnRep_MaxHealth, BlueprintReadWrite)
		float MaxHealth;
	UFUNCTION()
		void OnRep_MaxHealth(float OldMaxHealth)
	{
		// changed in 4.25 takes 3 args now with the "old" value
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MaxHealth, OldMaxHealth);
	}

	//UPROPERTY(Replicated)
	//	float	AttackPower;

	UPROPERTY(Category = "Attribute", EditAnywhere, ReplicatedUsing = OnRep_AttackPower, BlueprintReadWrite)
		float AttackPower;
	UFUNCTION()
		void OnRep_AttackPower(float OldAttackPower)
	{
		// changed in 4.25 takes 3 args now with the "old" value
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, AttackPower, OldAttackPower);
	}

	void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;
	
	static FGameplayAttribute HealthAttribute();
	static FGameplayAttribute MaxHealthAttribute();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

};
