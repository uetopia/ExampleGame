// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MyTypes.h"
#include "MyGameStore.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API AMyGameStore : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString storeTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		FString storeDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UETOPIA")
	TArray <FStoreItem> StoreItems;
	
};
