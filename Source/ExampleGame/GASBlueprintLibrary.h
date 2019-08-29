// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "MyTypes.h"
#include "GASBlueprintLibrary.generated.h"

UCLASS()
class UGASBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category=AbilitySystem)
	static void GenerateEffectSpecs(UPARAM(ref) FMyEffectApplicationContainer& Container, AActor* Source, float LevelOverride=0.f, int32 StackOverride=0);

	UFUNCTION(BlueprintCallable,Category=AbilitySystem)
	static void AddHitResult(UPARAM(ref) FMyEffectApplicationContainer& Container, FHitResult HitResult);

	UFUNCTION(BlueprintCallable, Category=AbilitySystem)
	static TArray<FActiveGameplayEffectHandle> ApplyEffectApplicationContainerToTarget(UPARAM(ref) FMyEffectApplicationContainer& Container, AActor* Target);

};