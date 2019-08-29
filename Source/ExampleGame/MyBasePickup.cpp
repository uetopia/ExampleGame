// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBasePickup.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "ProMMO.h"



// Sets default values
AMyBasePickup::AMyBasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Our root component will be a sphere collision
	//USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//RootComponent = SphereComponent;
	//SphereComponent->InitSphereRadius(90.0f);
	//SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// Create and position a mesh component so we can see where our sphere is
	myStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	RootComponent = myStaticMeshComponent;
	//myStaticMeshComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	if (SphereVisualAsset.Succeeded())
	{
		myStaticMeshComponent->SetStaticMesh(SphereVisualAsset.Object);
		myStaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		myStaticMeshComponent->SetWorldScale3D(FVector(0.8f));
	}



	// Rama Save
	OurSaveComponent = CreateDefaultSubobject<URamaSaveComponent>(TEXT("Save System"));
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("DataTableRowName");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("Icon");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("Title");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("Description");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("bCanBeUsed");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("UseText");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("bCanBeStacked");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("MaxStackSize");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("Category");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("Subcategory");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("Quantity");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("OwnerUserKeyId");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("bAnyoneCanPickUp");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("bOwnerCanPickUp");
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("Attributes");
	
	
	


	// data table setup
	// we're just using a string refrencing the row name now.


	// DataTable'/Game/Data/Resources_and_materials.Resources_and_materials'
	//static ConstructorHelpers::FObjectFinder<UDataTable>
	//	GameObjectLookupDataTable_BP(TEXT("DataTable'/Game/Data/Resources_and_materials.Resources_and_materials'"));
	//GameObjectLookupTable = GameObjectLookupDataTable_BP.Object;

	//ObjectInfo.DataTable = GameObjectLookupTable;

	bReplicates = true;
	bReplicateMovement = true;

}

// Called when the game starts or when spawned
void AMyBasePickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyBasePickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMyBasePickup::OnItemUsed(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] MyBasePickup OnItemUsed"));
	// your code here to run on client.  
	// do all the real work on the server
	ServerAttemptUse(SpawnTransform, UserKeyId, BPSubClass);
	return;
}


void AMyBasePickup::ServerAttemptUse_Implementation(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBasePickup] [ServerAttemptUse_Implementation]  "));
	
	// custom OnUse Implementation here.
}

bool AMyBasePickup::ServerAttemptUse_Validate(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBasePickup] [ServerAttemptPickUp_Validate]  "));
	return true;
}

void AMyBasePickup::OnItemPickedUp(const FString& UserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] MyBasePickup OnItemPickedUp"));
	// your code here
	// this should only run on server.
	return;
}

void AMyBasePickup::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	DOREPLIFETIME(AMyBasePickup, bAnyoneCanPickUp);
	DOREPLIFETIME(AMyBasePickup, bOwnerCanPickUp);
	DOREPLIFETIME(AMyBasePickup, OwnerUserKeyId);
	

}