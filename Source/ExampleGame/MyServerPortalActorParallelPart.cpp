// Fill out your copyright notice in the Description page of Project Settings.

#include "MyServerPortalActorParallelPart.h"




// Sets default values
AMyServerPortalActorParallelPart::AMyServerPortalActorParallelPart(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetStaticMesh(SphereVisualAsset.Object);
	GetStaticMeshComponent()->SetRelativeLocation(FVector(1.0f, 1.0f, -3.0f));
	//GetStaticMeshComponent()->SetWorldScale3D(FVector(1.0f, 0.5f, 1.0f));
	RootComponent = GetStaticMeshComponent();

	// create text render component with some default values
	//FString unrealName = "TextIndicator";
	//_displayText = CreateDefaultSubobject<UTextRenderComponent>(*unrealName);
	_displayText->SetText(FText::FromString("Text"));
	_displayText->SetTextRenderColor(FColor::Blue);
	_displayText->SetXScale(1.0f);
	_displayText->SetYScale(1.0f);
	_displayText->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	_displayText->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	//_displayText->AttachTo(RootComponent);
	//_displayText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	if (!IsRunningDedicatedServer()) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameState] LoadLevel - Not a Dedicated server."));
		// For some reason the dedicated server can't load the material, but it does not need it.

		static ConstructorHelpers::FObjectFinder<UMaterial> MatFinder(TEXT("Material'/Game/GlowMaterial.GlowMaterial'"));
		// Material'/Game/GlowMaterial.GlowMaterial'
		if (MatFinder.Succeeded())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] [Construct]  "));
			Material = MatFinder.Object;
			MaterialInstance = UMaterialInstanceDynamic::Create(Material, NULL);
			GetStaticMeshComponent()->SetMaterial(0, MaterialInstance);
		}


	}
	bReplicates = true;
	bReplicateMovement = true;
}
