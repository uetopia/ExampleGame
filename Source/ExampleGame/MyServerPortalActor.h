// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine.h"
#include "MyServerPortalActor.generated.h"

/**
 *
 */
UCLASS()
class EXAMPLEGAME_API AMyServerPortalActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

private:

	

	//class UMaterialInstanceDynamic* MaterialInstanceCreating;
	//class UMaterialInstanceDynamic* MaterialInstanceReady;

	UPROPERTY(ReplicatedUsing = OnRep_SetGlowAmount)
		bool DoRep_GlowAmount;

	UPROPERTY(Replicated)
		float R_GlowAmount;

	UFUNCTION()
		virtual void OnRep_SetGlowAmount();

	UPROPERTY(Replicated)
	FLinearColor R_PortalColor;



	UPROPERTY(ReplicatedUsing = OnRep_SetTitle)
		bool DoRep_Title;

	UPROPERTY(Replicated)
		FString R_targetServerTitle;

	UFUNCTION()
		virtual void OnRep_SetTitle();


public:
	// We want to keep track of the server reference so it can be used.
	UPROPERTY(Replicated)
	FString serverKeyId;
	void setServerKeyId(FString serverKeyIdIncoming);

	UPROPERTY(Replicated)
	FString serverUrl;
	void setServerUrl(FString serverUrlIncoming);

	// We want to keep track of the state too
	//  Doing this as a string instead of various bools since there it should be a finite state machine.
	UPROPERTY(Replicated)
	FString state;
	void setState(FString stateIncoming);

	// display text render component
	UPROPERTY(Replicated)
		UTextRenderComponent* _displayText;

	
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		UParticleSystemComponent* ParticleComp;
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		UParticleSystem* MyParticleSystem;


	void setTitle(FString titleIncoming);

protected:

	UPROPERTY(EditAnywhere)
		class UMaterial* Material;

	UPROPERTY(EditAnywhere)
		class UMaterialInstanceDynamic* MaterialInstance;

	
};
