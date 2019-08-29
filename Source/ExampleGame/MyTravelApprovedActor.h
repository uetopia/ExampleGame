// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "MyTravelApprovedActor.generated.h"

/**
 *
 */
UCLASS()
class EXAMPLEGAME_API AMyTravelApprovedActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

private:
	UPROPERTY(EditAnywhere)
	class UMaterial* Material;

	UPROPERTY(EditAnywhere)
	class UMaterialInstanceDynamic* MaterialInstance;

public:

	FString playerKeyId;
	void setPlayerKeyId(FString playerKeyIdIncoming);


};
