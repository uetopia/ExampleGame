// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameMode.h"
#include "ArenaGameMode.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API AArenaGameMode : public AMyGameMode
{
	GENERATED_BODY()

	void RestartPlayer(AController* NewPlayer) override;
	
};
