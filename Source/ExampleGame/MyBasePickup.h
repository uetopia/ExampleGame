// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RamaSaveComponent.h"
#include "MyObjectLookupTable.h"
#include "MyBasePickup.generated.h"

UCLASS()
class EXAMPLEGAME_API AMyBasePickup : public AActor
{
	GENERATED_BODY()


public:
	//*************************
	//TEMPLATE Load Obj From Path (thanks Rama!)
	//*************************
		static FORCEINLINE UClass* LoadClassFromPath(const FString& Path)
	{
		if (Path == "") return NULL;

		return StaticLoadClass(UObject::StaticClass(), NULL, *Path, NULL, LOAD_None, NULL);
	}

	//Get Path
	static FORCEINLINE FString GetClassPath(UClass* ClassPtr)
	{
		return FStringClassReference(ClassPtr).ToString();
	}


	// Sets default values for this actor's properties
	AMyBasePickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UETOPIA")
		UStaticMeshComponent* myStaticMeshComponent;

	UStaticMesh * myStaticMeshObj;

	//UParticleSystemComponent* OurParticleSystem;

	URamaSaveComponent* OurSaveComponent;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UETOPIA")
	//FDataTableRowHandle  ObjectInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 DataTableId;

	// Variables that exist inside the Data table but we need them for other things
	// Using simple variables for these because they will be persistent objects in the world, and Rama save can't deal with a struct
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	FText Title;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	bool bCanBeUsed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	FText UseText;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	bool bCanBeStacked;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	int32 MaxStackSize;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	FString Category;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
	FString Subcategory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		int32 Quantity;

	// Additional attributes are stored in a TMap
	// You can do whatever you want with these.
	// They get saved in the server save data, as well as converted to JSON when placed on vendors
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UETOPIA")
		TArray<float> Attributes;

	// some items should not be able to be picked up by everyone, and should be restricted to the owner
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadOnly, Category = "UETOPIA")
	FString OwnerUserKeyId;

	// Anyone can pick up this item.  
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadOnly, Category = "UETOPIA")
	bool bAnyoneCanPickUp;

	// the owner can pick up this item.  set to false for items that are IN-use, like vendors with items in the inventory.
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadOnly, Category = "UETOPIA")
		bool bOwnerCanPickUp;



	UFUNCTION(BlueprintCallable, Category = "UETOPIA", meta = (DisplayName = "On Used ~ Player has requested to use this item"))
	 virtual void OnItemUsed(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass);

	//virtual void OnItemUsed_Implementation();

	// This is the function that gets called on the server when an object is used
	UFUNCTION(Server, Reliable, WithValidation)
		virtual void ServerAttemptUse(FTransform SpawnTransform, const FString& UserKeyId, UClass* BPSubClass);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA", meta = (DisplayName = "On Pick up ~ Player has requested to pick up this item"))
		virtual void OnItemPickedUp(const FString& UserKeyId);

	// o-- Lookup table for Game Objects - Loaded from CSV/Excel
	//UDataTable* GameObjectLookupTable;
};
