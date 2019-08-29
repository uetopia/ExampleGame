// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "MyPlayerStart.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API AMyPlayerStart : public APlayerStart
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 teamIndex;

	// this is not the same as the playernumber 
	// this is used to indicate the players on a team 
	// So a 4 man team would have 0 1 2 3
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 playerIndex;
};
