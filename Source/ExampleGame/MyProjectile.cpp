// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

//#include "GAS.h"
#include "MyProjectile.h"
#include "UnrealNetwork.h"
#include "GameFramework/ProjectileMovementComponent.h"

//////////////////////////////////////////////////////////////////////////
// AGASCharacter

AMyProjectile::AMyProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionBlockComp0"));
	CollisionComponent->InitSphereRadius(0.0f);
	CollisionComponent->bAbsoluteScale = true;
	CollisionComponent->SetCanEverAffectNavigation(false);
	//CollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	RootComponent = CollisionComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp0"));
	MeshComponent->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetCanEverAffectNavigation(false);
	MeshComponent->CastShadow = false;

	// moved to private in 4.20?
	//MeshComponent->bGenerateOverlapEvents = false;

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp0"));
	MovementComponent->UpdatedComponent = RootComponent;

	bReplicates = true;
}

void AMyProjectile::BeginPlay()
{
	Super::BeginPlay();

	if (Role == ROLE_Authority)
	{
		if (Instigator)
		{
			SetActorTransform( Instigator->GetActorTransform(), false);
		}

		SpawnOrigin = GetActorLocation();
		SpawnRotation = GetActorRotation().GetNormalized();
	}

	const FVector Direction = SpawnRotation.Vector();
	const float Speed = GetLaunchSpeed();

	Launch(Direction, Speed);
}

void AMyProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AMyProjectile, SpawnOrigin, COND_InitialOnly);
	DOREPLIFETIME_CONDITION(AMyProjectile, SpawnRotation, COND_InitialOnly);
	DOREPLIFETIME_CONDITION(AMyProjectile, LaunchSpeed, COND_InitialOnly);
}

float AMyProjectile::GetLaunchSpeed() const
{
	return LaunchSpeed;
}

void AMyProjectile::Launch(const FVector& Dir, float Speed)
{
	FVector const DirNorm = Dir.GetSafeNormal();

	MovementComponent->Velocity = Speed * DirNorm;
}
