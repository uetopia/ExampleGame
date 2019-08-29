// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MyObjectLookupTable.generated.h"

/** Structure to store the lookup of GameObjects for use in a UDataTable */
USTRUCT(BlueprintType)
struct FMyObjectLookupTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	/** Extra Note field */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	FString Note;

	/** Object Title */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	FString Title;

	/** Object Description */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString Description;

	/** Full Path of Blueprint */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	FString BlueprintClass;

	/** UI ICon */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString Icon;

	/** Category of GamePlay Object */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString Category;

	/** Subcategory of GamePlay Object */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString Subcategory;

	/** Subcategory of GamePlay Object */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeUsed;

	/** Text to show in UI hover before use */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		FString UseText;

	/** Can these objects stack in the inventory */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
		bool bCanBeStacked;

	/** Scriptable Use Code */
	UPROPERTY(BlueprintReadOnly, Category = "UETOPIA")
	int32 StackSize;
};
