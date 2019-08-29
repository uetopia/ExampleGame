// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/StaticMeshActor.h"
#include "DynamicTextureStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API ADynamicTextureStaticMeshActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

		// Override BeginPlay()
		virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
		class UMaterial* Material;

	UPROPERTY(EditAnywhere)
		class UMaterialInstanceDynamic* MaterialInstance;
	
	
};
