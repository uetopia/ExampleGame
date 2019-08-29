// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameplayAbilitySpec.h"
#include "Abilities/GameplayAbility.h"
#include "MyBaseGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API UMyBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

	/** Get default priority for running a task */
	virtual uint8 GetGameplayTaskDefaultPriority() const { return FGameplayTasks::DefaultPriority; }
	
public:

	UMyBaseGameplayAbility(const FObjectInitializer& ObjectInitializer);


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString DataTableRowName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FText Title;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeUsed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FText UseText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Category;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString Subcategory;

	//virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* OwnerInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	/*
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

	

	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;

	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;
	*/
	
	
	
};
