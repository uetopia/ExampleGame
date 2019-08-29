// Fill out your copyright notice in the Description page of Project Settings.

#include "MyServerPortalActor.h"
#include "ProMMO.h"
#include "Net/UnrealNetwork.h"


// Sets default values
AMyServerPortalActor::AMyServerPortalActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetStaticMesh(SphereVisualAsset.Object);
	GetStaticMeshComponent()->SetRelativeLocation(FVector(1.0f, 1.0f, -3.0f));
	RootComponent = GetStaticMeshComponent();

	// create text render component with some default values
	FString unrealName = "TextIndicator";
	_displayText = CreateDefaultSubobject<UTextRenderComponent>(*unrealName);
	_displayText->SetText(FText::FromString("Text"));
	_displayText->SetTextRenderColor(FColor::Black);
	_displayText->SetXScale(1.0f);
	_displayText->SetYScale(1.0f);
	_displayText->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	_displayText->SetRelativeLocation(FVector(1.0f, 1.0f, 120.0f));
	//_displayText->AttachTo(RootComponent);
	//_displayText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	_displayText->SetupAttachment(RootComponent);

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

	// ParticleSystem'/Game/Portal/p_portal.p_portal'
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PSClass(TEXT("ParticleSystem'/Game/Portal/p_portal.p_portal'"));

	if (PSClass.Object != NULL) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] Got Particle System  "));
		MyParticleSystem = PSClass.Object; // MyParticleSystem is a UParticleSystem pointer
		ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MyPSC"));
		ParticleComp->SetTemplate(PSClass.Object);
		ParticleComp->SetupAttachment(RootComponent);
		R_PortalColor = FLinearColor(0.0, 0.0, 0.9, 1.0);
		ParticleComp->SetColorParameter("Color", R_PortalColor);
		ParticleComp->ActivateSystem(true);
	}


	bReplicates = true;
	bReplicateMovement = true;
}


void AMyServerPortalActor::setServerKeyId(FString serverKeyIdIncoming)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] [serverKeyIdIncoming] %s "), serverKeyIdIncoming);
	serverKeyId = serverKeyIdIncoming;
}

void AMyServerPortalActor::setServerUrl(FString serverUrlIncoming)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] [serverKeyIdIncoming] %s "), serverKeyIdIncoming);
	serverUrl = serverUrlIncoming;
}

void AMyServerPortalActor::setState(FString stateIncoming)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] [stateIncoming] %s "), *stateIncoming);
	state = stateIncoming;

	// also set the material, so we can tell visually what state it's in

	if (stateIncoming == "Creating") {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] Setting State to Creating "));

		R_GlowAmount = 2.0f;
		R_PortalColor = FLinearColor(0.9, 0.6, 0.0, 1.0);
		DoRep_GlowAmount = !DoRep_GlowAmount;
	}

	else if (stateIncoming == "Provisioned") {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] Setting State to Ready "));

		R_GlowAmount = 3.0f;
		R_PortalColor = FLinearColor(0.9, 0.9, 0.0, 1.0);
		DoRep_GlowAmount = !DoRep_GlowAmount;

	}

	else if (stateIncoming == "Ready") {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] Setting State to Ready "));

		R_GlowAmount = 5.0f;
		R_PortalColor = FLinearColor(0.0, 0.9, 0.0, 1.0);
		DoRep_GlowAmount = !DoRep_GlowAmount;

	}

	else if (stateIncoming == "Instanced") {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] Setting State to Instanced "));

		R_GlowAmount = 5.0f;
		R_PortalColor = FLinearColor(1.0, 0.5, 0.0, 1.0);
		DoRep_GlowAmount = !DoRep_GlowAmount;

	}

	else {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] Setting State to Default "));

		R_GlowAmount = 2.0f;
		DoRep_GlowAmount = !DoRep_GlowAmount;
		R_PortalColor = FLinearColor(0.0, 0.0, 0.9, 1.0);

	}



}

void AMyServerPortalActor::setTitle(FString titleIncoming)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] [titleIncoming] %s "), *titleIncoming);
	R_targetServerTitle = titleIncoming;
	DoRep_Title = !DoRep_Title;
}

void AMyServerPortalActor::OnRep_SetTitle()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] On Rep Set Title"));
	_displayText->SetText(FText::FromString(R_targetServerTitle));
}

void AMyServerPortalActor::OnRep_SetGlowAmount()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyServerPortalActor] On Rep Set Glow Amount"));
	MaterialInstance->SetScalarParameterValue(FName("Glow Strength"), R_GlowAmount);
	MaterialInstance->SetVectorParameterValue(FName("Color"), R_PortalColor);
	//GetStaticMeshComponent()->SetMaterial(0, MaterialInstance);
	ParticleComp->SetColorParameter("Color", R_PortalColor);
}

void AMyServerPortalActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMyServerPortalActor, R_GlowAmount);
	DOREPLIFETIME(AMyServerPortalActor, DoRep_GlowAmount);
	DOREPLIFETIME(AMyServerPortalActor, R_PortalColor);
	DOREPLIFETIME(AMyServerPortalActor, state);
	DOREPLIFETIME(AMyServerPortalActor, serverKeyId);
	DOREPLIFETIME(AMyServerPortalActor, serverUrl);
	DOREPLIFETIME(AMyServerPortalActor, R_targetServerTitle);
	DOREPLIFETIME(AMyServerPortalActor, DoRep_Title);
	
}
