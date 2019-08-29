// Fill out your copyright notice in the Description page of Project Settings.

#include "MyRewardItemActor.h"
#include "ProMMO.h"
#include "MyGameInstance.h"
#include "UEtopiaPersistCharacter.h"
#include "MyPlayerController.h"
#include "MyPlayerState.h"




// Sets default values
AMyRewardItemActor::AMyRewardItemActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	// StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetStaticMesh(SphereVisualAsset.Object);
	GetStaticMeshComponent()->SetRelativeLocation(FVector(1.0f, 1.0f, -3.0f));
	FRotator rotation;
	rotation.Roll = 90.0f;
	GetStaticMeshComponent()->SetRelativeRotation(rotation);
	FVector relativeScale = FVector(1.0f, 1.0f, 0.1f);
	GetStaticMeshComponent()->SetRelativeScale3D(relativeScale);

	RootComponent = GetStaticMeshComponent();

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(450.0f);
	Sphere1->SetupAttachment(RootComponent);
	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &AMyRewardItemActor::OnOverlapBegin);       // set up a notification for when this component overlaps something


	if (!IsRunningDedicatedServer()) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyRewardItemActor] construct - Not a Dedicated server."));
		// For some reason the dedicated server can't load the material, but it does not need it.

		static ConstructorHelpers::FObjectFinder<UMaterial> MatFinder(TEXT("Material'/Game/CoinMaterial.CoinMaterial'"));
		// Material'/Game/GlowMaterial.GlowMaterial'
		if (MatFinder.Succeeded())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyRewardItemActor] [Construct]  "));
			Material = MatFinder.Object;
			GetStaticMeshComponent()->SetMaterial(0, Material);
		}


	}
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;

	bReplicateMovement = true;
	RotationSpeed = 115.0f;
}

// Called every frame
void AMyRewardItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Call your functions
	FRotator rotation = FRotator(RotationSpeed, 0.0f, 0.0f);
	this->AddActorLocalRotation(rotation * DeltaTime, false);

}

void AMyRewardItemActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority())
	{
		if (OtherActor && (OtherActor != this) && OtherComp)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyRewardItemActor] OnOverlapBegin"));
			//ToggleLight();
			// TODO tell the server via gameinstance to attempt the pickup.
			ServerAttemptClaimReward(OtherActor);
		}
	}
}

void AMyRewardItemActor::ServerAttemptClaimReward_Implementation(class AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyRewardItemActor] [ServerAttemptPickUp_Implementation]  "));

	// hopefully this is a player actor.
	// we could cast here, but let's just do that in the game instance

	AUEtopiaPersistCharacter* MyPC = Cast<AUEtopiaPersistCharacter>(OtherActor);
	if (MyPC) {
		UWorld* const World = GetWorld();
		if (World) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyRewardItemActor] [ServerAttemptClaimReward_Implementation] Requesting Reward  "));
			FString itemname = "coin";
			FString description = "You collected a coin";
			UMyGameInstance* gameInstance = Cast<UMyGameInstance>(World->GetGameInstance());
			// cast our playerstate
			AMyPlayerState* playerS = Cast<AMyPlayerState>(MyPC->GetPlayerState());
			if (playerS) {
				gameInstance->Reward(playerS->playerKeyId, itemname, description, gameInstance->getSpawnRewardValue());
			}


		}
	}

	this->Destroy();


}

bool AMyRewardItemActor::ServerAttemptClaimReward_Validate(class AActor* OtherActor)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptPickUp_Validate]  "));
	return true;
}
