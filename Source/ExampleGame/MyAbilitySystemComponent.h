// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MyAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API UMyAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

		// Execute a gameplaycue
		UFUNCTION(BlueprintCallable, Category = "GameplayCue", Meta = (DisplayName = "ExecuteGameplayCueWithContext", ScriptName = "ExecuteGameplayCueWithContext"))
		void BP_ExecuteGameplayCueWithContext(const FGameplayTag GameplayCueTag, FGameplayEffectContextHandle EffectContext);
};
