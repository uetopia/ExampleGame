// Fill out your copyright notice in the Description page of Project Settings.

#include "MySpawnableObject.h"
#include "ProMMO.h"
#include "Engine.h"

// Sets default values
AMySpawnableObject::AMySpawnableObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);
	CollisionComp->AlwaysLoadOnClient = true;
	CollisionComp->AlwaysLoadOnServer = true;
	CollisionComp->bTraceComplexOnMove = true;
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//CollisionComp->SetCollisionObjectType(COLLISION_PROJECTILE);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	//CollisionComp->OnComponentHit.AddDynamic(this, &AMyBomb::OnHit);
	*/

	//RootComponent = CollisionComp;

	//MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	//MovementComp->UpdatedComponent = CollisionComp;
	//MovementComp->InitialSpeed = 0.0f;
	//MovementComp->MaxSpeed = 50.0f;
	//MovementComp->bRotationFollowsVelocity = true;
	// //MovementComp->ProjectileGravityScale = 0.f;
	//MovementComp->bShouldBounce = true;
	//MovementComp->Bounciness = 10.f;
	//MovementComp->Friction = 0.f;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	/*

	// Create and position a mesh component so we can see where our sphere is
	SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));


	if (SphereVisualAsset.Succeeded())
	{
	SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	//SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	//SphereVisual->SetWorldScale3D(FVector(0.5f));
	}

	//SphereVisual->SetupAttachment(RootComponent);

	*/
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetStaticMesh(SphereVisualAsset.Object);
	GetStaticMeshComponent()->SetRelativeLocation(FVector(1.0f, 1.0f, -3.0f));


	// Create dummy root scene component
	//DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = GetStaticMeshComponent();

	//RootComponent = SphereVisual;

	//CollisionComp->SetupAttachment(RootComponent);
	//SphereVisual->SetupAttachment(RootComponent);


	//Cube1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box1"));
	//Cube1->InitBoxExtent(FVector(0.0f)); //->InitSphereRadius(20.0f);
	//Cube1->SetupAttachment(RootComponent);

	bReplicates = true;
	bReplicateMovement = true;

	// Rama Save
	OurSaveComponent = CreateDefaultSubobject<URamaSaveComponent>(TEXT("Save System"));

}

// Called when the game starts or when spawned
void AMySpawnableObject::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMySpawnableObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
