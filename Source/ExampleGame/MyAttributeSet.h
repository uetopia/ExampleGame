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
		void OnRep_Health()
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Health);
	}

	//UPROPERTY(Replicated)
	//	float	MaxHealth;

	UPROPERTY(Category = "Attribute", EditAnywhere, ReplicatedUsing = OnRep_MaxHealth, BlueprintReadWrite)
		float MaxHealth;
	UFUNCTION()
		void OnRep_MaxHealth()
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MaxHealth);
	}

	//UPROPERTY(Replicated)
	//	float	AttackPower;

	UPROPERTY(Category = "Attribute", EditAnywhere, ReplicatedUsing = OnRep_AttackPower, BlueprintReadWrite)
		float AttackPower;
	UFUNCTION()
		void OnRep_AttackPower()
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, AttackPower);
	}

	void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;
	
	static FGameplayAttribute HealthAttribute();
	static FGameplayAttribute MaxHealthAttribute();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

};
