// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAbilitySystemComponent.h"

void UMyAbilitySystemComponent::BP_ExecuteGameplayCueWithContext(const FGameplayTag GameplayCueTag, FGameplayEffectContextHandle EffectContext)
{
	ExecuteGameplayCue(GameplayCueTag, EffectContext);
}