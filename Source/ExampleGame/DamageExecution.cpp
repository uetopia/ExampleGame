// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageExecution.h"
#include "MyAttributeSet.h"
#include "AbilitySystemComponent.h"




struct DamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);

	DamageStatics()
	{
		// Capture the Target's Health attribute. Do not snapshot it, because we want to use the health value at the moment we apply the execution.
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMyAttributeSet, Health, Target, false);

		// Capture the Source's AttackPower. We do want to snapshot this at the moment we create the GameplayEffectSpec that will execute the damage.
		// (imagine we fire a projectile: we create the GE Spec when the projectile is fired. When it hits the target, we want to use the AttackPower at the moment
		// the projectile was launched, not when it hits).
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMyAttributeSet, AttackPower, Source, true);
	}
};

DamageStatics& Damage()
{
	static DamageStatics It;
	return It;
}


// ------------------------------------------------------------------------------------------------------
//		Damage implementation
// ------------------------------------------------------------------------------------------------------


UDamageExecution::UDamageExecution(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RelevantAttributesToCapture.Add(Damage().HealthDef);
	RelevantAttributesToCapture.Add(Damage().AttackPowerDef);
}

void UDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UDamageExecution] [Execute_Implementation]  "));
	UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor* SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->AvatarActor : nullptr;
	AActor* TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->AvatarActor : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	// --------------------------------------------------------------------------------------------

	float Health = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Damage().HealthDef, EvaluationParameters, Health);

	float AttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Damage().AttackPowerDef, EvaluationParameters, AttackPower);

	// --------------------------------------
	//	Damage Done = AttackPower
	//	
	// --------------------------------------

	float DamageDone = FMath::Min<float>(AttackPower, Health);

	if (DamageDone > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Damage().HealthProperty, EGameplayModOp::Additive, -DamageDone));
	}
}