// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBaseVendor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "MyGameInstance.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "ProMMO.h"

// Sets default values
AMyBaseVendor::AMyBaseVendor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Our root component will be a sphere that reacts to physics
	//USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//RootComponent = SphereComponent;
	//SphereComponent->InitSphereRadius(90.0f);
	//SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	/*
	// Create and position a mesh component so we can see where our sphere is
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	RootComponent = SphereVisual;
	//SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	if (SphereVisualAsset.Succeeded())
	{
	SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	SphereVisual->SetWorldScale3D(FVector(0.8f));
	}
	*/

	



	// Rama Save
	/*
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
	*/
	
	OurSaveComponent->RamaSave_OwningActorVarsToSave.Add("VendorKeyId");


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

void AMyBaseVendor::OnItemUsed(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] MyBaseVendor OnItemUsed"));
	// THis is called when a vendor item is in a player's inventory, and they double click or "use"
	// Do all the real work on the server
	ServerAttemptUse(SpawnTransform, UserKeyId, BPSubClass);

	return;
}

void AMyBaseVendor::ServerAttemptUse_Implementation(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBaseVendor] [ServerAttemptUse_Implementation]  "));

	// spawn the vendor in the world
	// skipping this.  it might be possible to item dupe if you drop the vendor then pick it back up again before it has been finalized.

	/*
	UWorld* World = GetWorld(); // get a reference to the world
	if (World)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] [ServerAttemptSpawnActor_Implementation] got world "));
		// if world exists, spawn the blueprint actor

		World->SpawnActor<AMyBaseVendor>(BPSubClass, SpawnTransform);
	}
	*/

	
	// this is not working because when we call this function the actor is not actually spawned in the world.
	//UWorld* const World = GetWorld();
	//if (World) {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBaseVendor] [ServerAttemptUse_Implementation] Got World "));
		//UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(World->GetGameInstance());

	// this might work:  GEngine->GetFirstLocalPlayerController(GEngine->GetWorld())
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(((UGameEngine*)GEngine)->GameInstance);
	if (TheGameInstance)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBaseVendor] [ServerAttemptUse_Implementation] Got Game instance "));
		float coordLocationX = SpawnTransform.GetLocation().X;
		float coordLocationY = SpawnTransform.GetLocation().Y;
		float coordLocationZ = SpawnTransform.GetLocation().Z;
		float forwardVecX = SpawnTransform.GetRotation().GetForwardVector().X;
		float forwardVecY = SpawnTransform.GetRotation().GetForwardVector().Y;
		float forwardVecZ = SpawnTransform.GetRotation().GetForwardVector().Z;
		TheGameInstance->VendorCreate(UserKeyId, VendorTypeKeyId, coordLocationX, coordLocationY, coordLocationZ, forwardVecX, forwardVecY, forwardVecZ);
	}
	// somehow set a temporary key so we can get back to it later
	// Run the http create vendor request
	// deal with all the data coming back on http request complete.
}

bool AMyBaseVendor::ServerAttemptUse_Validate(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBaseVendor] [ServerAttemptPickUp_Validate]  "));
	return true;
}

void AMyBaseVendor::OnItemPickedUp(const FString& UserKeyId)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyBaseVendor] [OnItemPickedUp]  "));
	// this only runs on the server.
	// vendors can only be picked up if there are no items inside.
	// when they are picked up, the backend is notified, and deletes the related database entry
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(((UGameEngine*)GEngine)->GameInstance);
	if (TheGameInstance)
	{
		TheGameInstance->VendorDelete(UserKeyId, VendorKeyId);
	}
	return;
}

void AMyBaseVendor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicates to all players
	DOREPLIFETIME(AMyBaseVendor, VendorKeyId);

}