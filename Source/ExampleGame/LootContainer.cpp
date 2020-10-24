// Fill out your copyright notice in the Description page of Project Settings.


#include "LootContainer.h"
#include "Engine.h"
#include "MyGameInstance.h"
#include "UObject/ConstructorHelpers.h"

ALootContainer::ALootContainer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// SkeletalMesh'/Game/Blueprints/LootCrate/LootCrate.LootCrate'
	// SkeletalMesh'/Game/Objects/meshes/SM_cube_loot_crate.SM_cube_loot_crate'
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> LootContainerSMAsset(TEXT("/Game/Objects/meshes/SM_cube_loot_crate.SM_cube_loot_crate"));
	
	//MySkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("My Skeletal Mesh Component"));
	//MyParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("My Particle System Component"));

	GetSkeletalMeshComponent()->SetSkeletalMesh(LootContainerSMAsset.Object, true);

	//MySkeletalMesh->
	//GetSkeletalMeshComponent()
	RootComponent = GetSkeletalMeshComponent();

	//MyParticleSystemComponent->AttachTo(GetSkeletalMeshComponent(), "SocketName", EAttachLocation::SnapToTarget);
	//MyParticleSystemComponent->SetupAttachment(RootComponent);

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(150.0f);
	Sphere1->SetupAttachment(RootComponent);
	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALootContainer::OnOverlapBegin);
}

void ALootContainer::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority())
	{
		if (OtherActor && (OtherActor != this) && OtherComp)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [ALootContainer] OnOverlapBegin"));
			ServerAttemptOverlapBegin(OtherActor);
		}
	}
}

void ALootContainer::ServerAttemptOverlapBegin_Implementation(class AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [ALootContainer] [ServerAttemptOverlapBegin_Implementation]  "));

	// Check to see if this is a player character or something else.
	// Overlap is set to pawn, so it should only be the player...  test this and adjust in the collision settings itself.

	// Check to see if it is unlocked - has the boss died or some other condition which allows it to open
	// Instead of this, I'm putting it behind a barrier which will drop when the boss or miniboss dies.

	// Play the opening animation and activate the particle on the clients

	// Initiate the loot process based on the party settings.
	// This should happen in gameInstance probably.  We're going to need all kinds of stuff.

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	if (TheGameInstance)
	{

		if (!lootStarted)
		{
			lootStarted = true;
			TheGameInstance->BackendRequestPartyMembers(OtherActor, Contents);
		}
		
	}

	// TODO - prevent duplicate overlaps
	// give this a lifespan too so it can play the animation and look sparkly
	SetLifeSpan(2.0f);

}

bool ALootContainer::ServerAttemptOverlapBegin_Validate(class AActor* OtherActor)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptPickUp_Validate]  "));
	return true;
}

void ALootContainer::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	DOREPLIFETIME(ALootContainer, Contents);
}


void ALootContainer::GenerateContents(int32 contentsCount)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [ALootContainer] [GenerateContents]  "));

	// dump contents first just in case
	Contents.Empty();

	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	if (TheGameInstance)
	{
		// Setup the vars we need

		TArray<int32> LootDTIDs;
		TArray<int32> LootWeights;
		float AttributeSumMaximum = 5.0f;
		float AttributeSumMinimum = 5.0f;
		float ComponentStrengthMaximum = 0.25f;

		// ExampleGame only has 2 items...  You can add your own from your data table here
		// Do something with attributes and Tier...

		LootDTIDs.Add(1002);
		LootWeights.Add(1);

		LootDTIDs.Add(1003);
		LootWeights.Add(1);

		// Containers can hold more than one item, so make rolls for each one.

		for (int32 i = 0; i < contentsCount; i++)
		{
			// roll for the item by weight
			int32 ChosenDTID = ChooseDTIDByWeight(LootDTIDs, LootWeights);

			// Load the DTID - populate all of the fields from data table and or BP object
			FMyInventorySlot Loot = TheGameInstance->GetInventorySlotByDTID(ChosenDTID);

			Loot.quantity = 1;
			Loot.Tier = Tier; // LootTierLevel is already adjusted correctly.

			// Do something with the loot attributes.  Here I just randomize them

			float randomSumTarget = FMath::RandRange(AttributeSumMinimum, AttributeSumMaximum);

			// https://stackoverflow.com/questions/8064629/random-numbers-that-add-to-100-matlab

			TArray<float> TempAttributes;
			float AttributesTotal = 0.0f;

			// Adding 0 and Max to the Array so we can find the differences

			TempAttributes.Add(0.0f);
			TempAttributes.Add(AttributeSumMaximum);

			for (int i = 0; i < 2; i++) {
				float atributeRandom = FMath::RandRange(0.0f, AttributeSumMaximum);
				TempAttributes.Add(atributeRandom);
				AttributesTotal = AttributesTotal + atributeRandom;
			}

			TempAttributes.Sort();

			TArray<float> AttributeDiffs;

			for (int i = 1; i < 3; i++) {
				// Subtract the current from the previous
				AttributeDiffs.Add(TempAttributes[i] - TempAttributes[i - 1]);
			}

			// assign them
			Loot.Attributes = AttributeDiffs;

			// Add it to our contents array
			Contents.Add(Loot);
		}
	}

}

int32 ALootContainer::ChooseDTIDByWeight(TArray<int32> LootDTIDs, TArray<int32> LootWeights)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChooseDTIDByWeight]"));
	int32 sum_of_weight = 0;
	for (int i = 0; i < LootWeights.Num(); i++) {
		sum_of_weight += LootWeights[i];
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChooseDTIDByWeight] sum_of_weight: %d"), sum_of_weight);
	int32 rnd = FMath::RandRange(0, sum_of_weight);
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChooseDTIDByWeight] rnd: %d"), rnd);
	for (int i = 0; i < LootWeights.Num(); i++) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChooseDTIDByWeight] checking LootWeights[i]: %d"), LootWeights[i]);
		if (rnd < LootWeights[i])
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChooseDTIDByWeight] Found Loot"));
			return LootDTIDs[i];
		}
		rnd = rnd - LootWeights[i];
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChooseDTIDByWeight] Setting new rnd: %d"), rnd);
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyGameMode] [ChooseDTIDByWeight] Should not end up here.  Returning index 0"));
	return LootDTIDs[0];
}