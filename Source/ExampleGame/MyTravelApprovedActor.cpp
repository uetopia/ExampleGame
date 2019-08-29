// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTravelApprovedActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "ProMMO.h"





// Sets default values
AMyTravelApprovedActor::AMyTravelApprovedActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Portal/shape_portal_active.shape_portal_active"));
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetStaticMesh(SphereVisualAsset.Object);
	GetStaticMeshComponent()->SetRelativeLocation(FVector(1.0f, 1.0f, -3.0f));
	GetStaticMeshComponent()->SetRelativeScale3D(FVector(1.1f, 1.1f, 1.1f));
	RootComponent = GetStaticMeshComponent();

	if (!IsRunningDedicatedServer()) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyTravelApprovedActor]  Not a Dedicated server."));
		// For some reason the dedicated server can't load the material, but it does not need it.

		static ConstructorHelpers::FObjectFinder<UMaterial> MatFinder(TEXT("Material'/Game/TravelApprovedMaterial.TravelApprovedMaterial'"));
		// Material'/Game/TravelApprovedMaterial.TravelApprovedMaterial'
		if (MatFinder.Succeeded())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyTravelApprovedActor] [Construct]  "));
			Material = MatFinder.Object;
			MaterialInstance = UMaterialInstanceDynamic::Create(Material, NULL);
			GetStaticMeshComponent()->SetMaterial(0, MaterialInstance);
		}


	}
	bReplicates = true;
	SetActorEnableCollision(false);
}

void AMyTravelApprovedActor::setPlayerKeyId(FString playerKeyIdIncoming)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] [serverKeyIdIncoming] %s "), serverKeyIdIncoming);
	playerKeyId = playerKeyIdIncoming;
}
