// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UEtopiaPersistCharacter.h"
#include "ProMMO.h"
#include "MySpawnableObject.h"
#include "MyServerPortalActor.h"
#include "MyBaseVendor.h"
#include "MyPlayerState.h"
#include "MyPlayerController.h"
#include "UnrealNetwork.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "GameplayAbilityTypes.h"
#include "MyGameInstance.h"


//////////////////////////////////////////////////////////////////////////
// AUEtopiaPersistCharacter

AUEtopiaPersistCharacter::AUEtopiaPersistCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	bReplicates = true;
	bReplicateMovement = true;

	// mouse showing default true
	bMouseShowing = true;

}


void AUEtopiaPersistCharacter::BeginPlay()
{
	Super::BeginPlay();

	// playerController might not exist yet
	AMyPlayerController* playerC = Cast<AMyPlayerController>(Controller);
	if (playerC)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] Found a valid player controller"));
		playerC->OnFriendsChanged.Broadcast();
		playerC->OnRecentPlayersChanged.Broadcast();
		playerC->OnPartyDataReceivedUETopiaDisplayUI.Broadcast();
	}
}

void AUEtopiaPersistCharacter::PossessedBy(AController* NewController)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [PossessedBy]  "));
	Super::PossessedBy(NewController);
	if (GetAbilitySystemComponent())
	{
		//if (HasAuthority() && Ability)
		//{
		//AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject(), 1, 0));
		//}
		GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
		InitAbilitySystemClient();
	}

	AMyPlayerController* playerC = Cast<AMyPlayerController>(Controller);
	playerC->GrantCachedAbilities();
	RemapAbilities();
}

void AUEtopiaPersistCharacter::InitAbilitySystemClient_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [InitAbilitySystemClient]  "));
	if (GetAbilitySystemComponent())
	{
		//if (HasAuthority() && Ability)
		//{
		//AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject(), 1, 0));
		//}
		GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	}
}

// Called every frame -- Included in 4.7, needs to be added in 4.8
void AUEtopiaPersistCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//  make this run only on client.

	if (!IsRunningDedicatedServer()) {
		AMyBasePickup* itemSeen = GetItemFocus();

		static AMyBasePickup* oldFocus = NULL;

		oldFocus = ApplyPostProcessing(itemSeen, oldFocus);
	}



}




//////////////////////////////////////////////////////////////////////////
// Input

void AUEtopiaPersistCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponentIn)
{
	// Set up gameplay key bindings
	check(InputComponentIn);
	InputComponentIn->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponentIn->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponentIn->BindAction("Fire", IE_Pressed, this, &AUEtopiaPersistCharacter::OnStartFire);
	InputComponentIn->BindAction("Fire", IE_Released, this, &AUEtopiaPersistCharacter::OnStopFire);

	InputComponentIn->BindAction("Pickup", IE_Pressed, this, &AUEtopiaPersistCharacter::OnPickUp);

	InputComponentIn->BindAction("Travel", IE_Pressed, this, &AUEtopiaPersistCharacter::OnTravel);

	InputComponentIn->BindAction("Interact", IE_Pressed, this, &AUEtopiaPersistCharacter::OnInteractWithVendor);

	InputComponentIn->BindAction("ToggleMouse", IE_Pressed, this, &AUEtopiaPersistCharacter::OnToggleMouse);

	InputComponentIn->BindAxis("MoveForward", this, &AUEtopiaPersistCharacter::MoveForward);
	InputComponentIn->BindAxis("MoveRight", this, &AUEtopiaPersistCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponentIn->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponentIn->BindAxis("TurnRate", this, &AUEtopiaPersistCharacter::TurnAtRate);
	InputComponentIn->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponentIn->BindAxis("LookUpRate", this, &AUEtopiaPersistCharacter::LookUpAtRate);

	// handle touch devices
	InputComponentIn->BindTouch(IE_Pressed, this, &AUEtopiaPersistCharacter::TouchStarted);
	InputComponentIn->BindTouch(IE_Released, this, &AUEtopiaPersistCharacter::TouchStopped);

	// Map the "InputIDs" to the ability system
	if (GetAbilitySystemComponent())
	{
		GetAbilitySystemComponent()->BindAbilityActivationToInputComponent(InputComponentIn, FGameplayAbilityInputBinds("ConfirmInput", "CancelInput", "AbilityInput"));
	}
	

}

UAbilitySystemComponent* AUEtopiaPersistCharacter::GetAbilitySystemComponent() const
{
	AMyPlayerState* PlayerS = Cast<AMyPlayerState>(this->GetPlayerState());
	if (PlayerS)
	{
		return PlayerS->GetAbilitySystemComponent();
	}
	return nullptr;

}


void AUEtopiaPersistCharacter::Restart()
{
	Super::Restart();
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaCompetitiveCharacter] [Restart]  "));

	// Server ONLY
	if (IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaCompetitiveCharacter] [Restart] - Server "));

		static UProperty* HealthProperty = FindFieldChecked<UProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, Health));
		static UProperty* MaxHealthProperty = FindFieldChecked<UProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, MaxHealth));
		float maxHealth = GetAbilitySystemComponent()->GetNumericAttributeBase(MaxHealthProperty);
		GetAbilitySystemComponent()->SetNumericAttributeBase(FGameplayAttribute(HealthProperty), maxHealth);


		// TODO - this is a good place to set up any GameplayEffects
		// Like if you have Equipment that grants effects...
		//ServerSetUpEquipmentEffects();

		
	}

}

void AUEtopiaPersistCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void AUEtopiaPersistCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

void AUEtopiaPersistCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AUEtopiaPersistCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AUEtopiaPersistCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AUEtopiaPersistCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AUEtopiaPersistCharacter::OnStartFire()
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnStartFire] "));
	if (CanFire()) {
		FVector ShootDir = GetActorForwardVector();
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnStartFire] GetActorForwardVector"));
		FVector Origin = GetActorLocation();
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnStartFire] GetActorLocation"));
		//  Tell the server to Spawn an actor
		ServerAttemptSpawnActor();
	}

}

bool AUEtopiaPersistCharacter::CanFire()
{
	return true;
}

void AUEtopiaPersistCharacter::OnStopFire()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnStopFire] "));
	//StopWeaponFire();
}

void AUEtopiaPersistCharacter::ServerAttemptSpawnActor_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Implementation]  "));
	if (CanFire()) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Implementation] CanFire "));
		float placementDistance = 200.0f;
		FVector ShootDir = GetActorForwardVector();
		FVector Origin = GetActorLocation();
		FVector spawnlocationstart = ShootDir * placementDistance;
		FVector spawnlocation = spawnlocationstart + Origin;
		// Spawn the actor

		FTransform const SpawnTransform(ShootDir.Rotation(), spawnlocation);
		//int32 playerID = PlayerState->PlayerId;

		UWorld* const World = GetWorld(); // get a reference to the world
		if (World) {
			// if world exists, spawn the blueprint actor
			// note:  take a look at the constructor above which attempts to find the bp object.
			//AMySpawnableObject* YC = World->SpawnActor<AMySpawnableObject>(BlueprintVar, SpawnTransform);

			// get the controller
			
			AMyPlayerController* playerC = Cast<AMyPlayerController>(Controller);

			AMyPlayerState* PlayerS = Cast<AMyPlayerState>(playerC->PlayerState);

			if (PlayerS)
			{
				UClass* LoadedActorOwnerClass;
				LoadedActorOwnerClass = LoadClassFromPath(PlayerS->InventorySlots[0].itemClassPath);
				World->SpawnActor<AMyBasePickup>(LoadedActorOwnerClass, SpawnTransform);
			}
		}
	}

}

bool AUEtopiaPersistCharacter::ServerAttemptSpawnActor_Validate()
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
	return true;
}

bool AUEtopiaPersistCharacter::CanPickUp()
{
	AMyPlayerController* PlayerC = Cast<AMyPlayerController>(Controller);
	AMyPlayerState* PlayerS = Cast<AMyPlayerState>(PlayerC->PlayerState);

	if (PlayerS->allowPickup)
	{
		AMyBasePickup* ObjectInFocus = GetItemFocus();
		bool doPickup = false;

		if (ObjectInFocus) {
			if (ObjectInFocus->bAnyoneCanPickUp)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [CanPickUp] bAnyoneCanPickUp "));
				doPickup = true;
			}
			else if (ObjectInFocus->OwnerUserKeyId == PlayerS->playerKeyId)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [CanPickUp] OwnerUserKeyId == playerKeyId "));
				if (ObjectInFocus->bOwnerCanPickUp)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [CanPickUp] bOwnerCanPickUp "));
					doPickup = true;
				}

			}

			if (doPickup) {

				if (PlayerC->AddItem(ObjectInFocus, ObjectInFocus->Quantity, true)) // CHECK ONLY!
				{
					return true;
				}
			}
		}
	}
	PlayerC->SendLocalChatMessage("Pickup not permitted.  This could be due to server settings, or group permissions.");
	
	return false;
}

void AUEtopiaPersistCharacter::OnPickUp()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnPickUp] "));
	if (CanPickUp())
	{
		//FVector ShootDir = GetActorForwardVector();
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnPickUp] GetActorForwardVector"));
		//FVector Origin = GetActorLocation();
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnPickUp] GetActorLocation"));
		//  Tell the server to Spawn an actor
		ServerAttemptPickUp();
	}
}


void AUEtopiaPersistCharacter::ServerAttemptPickUp_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptPickUp_Implementation]  "));
	AMyBasePickup* ObjectInFocus = GetItemFocus();
	if (ObjectInFocus) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptPickUp_Implementation] GotItemFocus  "));
		//GetItemFocus()->GetStaticMeshComponent()->DestroyComponent();
		if (CanPickUp())
		{
			

			AMyPlayerController* PlayerC = Cast<AMyPlayerController>(Controller);
			APlayerState* thisPlayerState = PlayerC->PlayerState;
			AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);


			ObjectInFocus->OnItemPickedUp(playerS->playerKeyId);


			

			PlayerC->AddItem(ObjectInFocus, ObjectInFocus->Quantity, false);

			// TODO - rebuild widgets

			//ObjectInFocus->SetActorEnableCollision(false);
			ObjectInFocus->Destroy();
		}

	}
}

bool AUEtopiaPersistCharacter::ServerAttemptPickUp_Validate()
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptPickUp_Validate]  "));
	return true;
}

bool AUEtopiaPersistCharacter::CanTravel()
{
	return true;
}

void AUEtopiaPersistCharacter::OnTravel()
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnTravel] "));
	if (CanTravel())
	{
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnTravel] CanTravel  "));

		// We need to examine the server portal and determine the state that it is in.
		AMyPlayerController* myPC = Cast<AMyPlayerController>(Controller);
		AMyServerPortalActor* ObjectInFocus = GetPortalFocus();
		if (ObjectInFocus) {
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] GotItemFocus  "));

			// We keep the array with our server authorizations in the player state.  Go get it.
			APlayerState* thisPlayerState = myPC->PlayerState;
			AMyPlayerState* playerS = Cast<AMyPlayerState>(thisPlayerState);

			bool traveledAndGone = false;

			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] ServerLinksAuthorized.Num() : %d  "), playerS->ServerLinksAuthorized.Num());

			// In the case of instanced servers, the keyId is different.  TODO handle this.

			// Check to see if we are pre-authorized to use this portal.
			for (int32 b = 0; b < playerS->ServerLinksAuthorized.Num(); b++)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] Found Authorization KeyID  "));
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] ObjectInFocus->serverKeyId: %s "), *ObjectInFocus->serverKeyId);
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] playerS->ServerLinksAuthorized[b].targetServerKeyId: %s "), *playerS->ServerLinksAuthorized[b].targetServerKeyId);
				if (playerS->ServerLinksAuthorized[b].targetServerKeyId == ObjectInFocus->serverKeyId) {
					// If the serverKey is in the portals authorized, this player is approved to travel.
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] Server FOUND "));
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] ObjectInFocus->state: %s "), *ObjectInFocus->state);
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] ObjectInFocus->serverUrl: %s "), *ObjectInFocus->serverUrl);
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] playerS->ServerLinksAuthorized[b].hostConnectionLink: %s "), *playerS->ServerLinksAuthorized[b].hostConnectionLink);
					FString readystate = "Ready";
					FString instancedstate = "Instanced";
					if (ObjectInFocus->state == readystate) {
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] State is Ready - travelling "));
						ServerAttemptTravel(false);
						//traveledAndGone = true;
						//myPC->ClientTravel(ObjectInFocus->serverUrl, ETravelType::TRAVEL_Absolute);
					}
					else if (ObjectInFocus->state == instancedstate) {
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] State is Instanced "));
						// it is possible here to not have a travel url yet.
						// If we don't have one yet, Attempt travel again.
						if (playerS->ServerLinksAuthorized[b].hostConnectionLink != "None" )
						{
							UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] Found a hostConnectionLink "));
							ServerAttemptTravel(false);
							//traveledAndGone = true;
							//myPC->ClientTravel(playerS->ServerLinksAuthorized[b].hostConnectionLink, ETravelType::TRAVEL_Absolute);
						}
						
					}
				}
			}
			if (!traveledAndGone) {
				//  Tell the server to run a transfer.  The boolean is for test mode.
				//  True is going to tell us if the user can travel, but not actually perform the transfer request.
				// Ultimately, it will populate our ServerLinksAuthorized if we are allowed to use it!

				ServerAttemptTravel(true);
			}
		}
	}
}

void AUEtopiaPersistCharacter::ServerAttemptTravel_Implementation(bool checkOnly)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation]  "));
	AMyServerPortalActor* ObjectInFocus = GetPortalFocus();
	if (ObjectInFocus) {
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] GotItemFocus  "));
		//GetItemFocus()->GetStaticMeshComponent()->DestroyComponent();
		if (CanTravel())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] CanTravel  "));
			//ObjectInFocus->SetActorEnableCollision(false);
			UWorld* const World = GetWorld();
			if (World) {
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Implementation] Requesting Transfer  "));
				UMyGameInstance* gameInstance = Cast<UMyGameInstance>(World->GetGameInstance());
				gameInstance->TransferPlayer(ObjectInFocus->serverKeyId, GetPlayerState()->PlayerId, checkOnly, false);

			}
		}
	}
}

bool AUEtopiaPersistCharacter::ServerAttemptTravel_Validate(bool checkOnly)
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptTravel_Validate]  "));
	return true;
}

bool AUEtopiaPersistCharacter::CanInteractWithVendor()
{
	AMyBaseVendor* VendorInFocus = GetVendorFocus();
	if (VendorInFocus) {
		if (VendorInFocus->OwnerUserKeyId.IsEmpty())
		{
			return false;
		}
		if (VendorInFocus->bAnyoneCanPickUp)
		{
			return false;
		}
		if (VendorInFocus->bOwnerCanPickUp)
		{
			return false;
		}
	}
	return true;
}

void AUEtopiaPersistCharacter::OnInteractWithVendor()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnInteractWithVendor] "));
	AMyBaseVendor* VendorInFocus = GetVendorFocus();
	if (VendorInFocus) {
		if (CanInteractWithVendor())
		{
			// Fire the delegate to tell BP to display the inventory interface
			AMyPlayerController* myPC = Cast<AMyPlayerController>(Controller);
			//myPC->FOnVendorInteractDisplayUI.Broadcast(VendorInFocus->VendorKeyId);
			//myPC->FOnVendorInteractChanged.Broadcast(VendorInFocus->VendorKeyId, true);
			myPC->AttemptVendorInteract(VendorInFocus);
			myPC->ServerAttemptSetVendorInteract(VendorInFocus);
		}
	}
	
}

void AUEtopiaPersistCharacter::OnToggleMouse()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnToggleMouse] "));

	// Not working - prevents gameplay

	/*
	APlayerController* PC = Cast<APlayerController>(GetController());

	if (PC)
	{
		if (bMouseShowing) {
			PC->bShowMouseCursor = false;
			PC->SetInputMode(FInputModeGameOnly());
		}
		else {
			PC->bShowMouseCursor = true;
			PC->SetInputMode(FInputModeUIOnly());
		}
		
	}

	bMouseShowing = !bMouseShowing;
	
	*/
	
	
	
	
	
}

void AUEtopiaPersistCharacter::ServerAttemptBuy_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptBuy_Implementation]  "));
	/*
	AMyStoreActor* ObjectInFocus = GetStoreFocus();
	if (ObjectInFocus) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptBuy_Implementation] GotStoreFocus  "));
	//GetItemFocus()->GetStaticMeshComponent()->DestroyComponent();
	if (CanBuy())
	{
	UWorld* const World = GetWorld();
	if (World) {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptBuy_Implementation] Requesting Buy "));
	UMyGameInstance* gameInstance = Cast<UMyGameInstance>(World->GetGameInstance());
	FString itemName = "Cube";
	FString description = "You bought an in-game item:  Cube";
	FMyActivePlayer* thisPlayer = gameInstance->getPlayerByPlayerId(PlayerState->PlayerId);
	gameInstance->Purchase(thisPlayer->playerKeyId, itemName, description, 100);
	}
	}

	}
	*/
	
}

bool AUEtopiaPersistCharacter::ServerAttemptBuy_Validate()
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptPickUp_Validate]  "));
	return true;
}


class AMyBasePickup* AUEtopiaPersistCharacter::GetItemFocus() {
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [GetItemFocus]  "));
	// Attempt to use Raycasts to view an object and echo it back

	FVector Direction = this->FollowCamera->GetForwardVector();
	FVector StartTrace = GetActorLocation();
	const FVector EndTrace = StartTrace + Direction * 150.0f; //where 300 is the distance it checks

	/*
	DrawDebugLine(
		GetWorld(),
		StartTrace,
		EndTrace,
		FColor(255, 0, 0),
		false, -1, 0,
		12.333
		);
	*/

	FCollisionQueryParams TraceParams(FName(TEXT("")), true, this);

	// removed in 4.22
	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_VIEW, TraceParams);

	AMyBasePickup* BasePickupClass = Cast<AMyBasePickup>(Hit.GetActor());

	//if (BasePickupClass->IsValidLowLevel())
	//{
	//	return BasePickupClass->GetClass();
	//}

	//return nullptr;
	return BasePickupClass;
}

AMyBasePickup* AUEtopiaPersistCharacter::ApplyPostProcessing(AMyBasePickup* itemSeen, AMyBasePickup* oldFocus) {
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ApplyPostProcessing]  "));
	if (itemSeen) {
		//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ApplyPostProcessing] itemSeen "));
		// An item is currently being looked at
		if (itemSeen == oldFocus || oldFocus == NULL) {
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ApplyPostProcessing] itemSeen == oldFocus || oldFocus == NULL "));
			//The item being looked at is the same as the one on the last tick

			TArray<UStaticMeshComponent*> Comps;

			itemSeen->GetComponents(Comps);
			if (Comps.Num() > 0)
			{
				UStaticMeshComponent* FoundComp = Comps[0];
				//do stuff with FoundComp
				FoundComp->SetRenderCustomDepth(true);
			}


		}
		else if (oldFocus != NULL) {
			// An item is being looked at and the old focus was not null (and not the same as the one on the last tick)
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ApplyPostProcessing]  oldFocus != NULL "));

			TArray<UStaticMeshComponent*> Comps;

			itemSeen->GetComponents(Comps);
			if (Comps.Num() > 0)
			{
				UStaticMeshComponent* FoundComp = Comps[0];
				//do stuff with FoundComp
				FoundComp->SetRenderCustomDepth(true);
			}

			TArray<UStaticMeshComponent*> oldComps;

			oldFocus->GetComponents(oldComps);
			if (oldComps.Num() > 0)
			{
				UStaticMeshComponent* FoundComp = oldComps[0];
				//do stuff with FoundComp
				FoundComp->SetRenderCustomDepth(false);
			}

			//UStaticMeshComponent* mesh = itemSeen->GetStaticMeshComponent();
			//itemSeen->StaticMeshComponent->SetRenderCustomDepth(true);
			//mesh->SetRenderCustomDepth(true);

			//UStaticMeshComponent* oldMesh = oldFocus->GetStaticMeshComponent();
			//oldMesh->SetRenderCustomDepth(false);
		}

		return oldFocus = itemSeen;
	}
	else {
		// No item currectly being looked at
		if (oldFocus != NULL) {
			//An item was looked at last tick but isn't being looked at anymore

			TArray<UStaticMeshComponent*> oldComps;

			oldFocus->GetComponents(oldComps);
			if (oldComps.Num() > 0)
			{
				UStaticMeshComponent* FoundComp = oldComps[0];
				//do stuff with FoundComp
				FoundComp->SetRenderCustomDepth(false);
			}


			//UStaticMeshComponent* mesh = oldFocus->GetStaticMeshComponent();
			//mesh->SetRenderCustomDepth(false);
		}

		return oldFocus = NULL;
	}

}

AMyServerPortalActor* AUEtopiaPersistCharacter::GetPortalFocus() {
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [GetPortalFocus]  "));
	// Attempt to use Raycasts to view an object and echo it back

	FVector Direction = this->FollowCamera->GetForwardVector();
	FVector StartTrace = GetActorLocation();
	const FVector EndTrace = StartTrace + Direction * 3000.0f; //where 300 is the distance it checks

															   /*
															   DrawDebugLine(
															   GetWorld(),
															   StartTrace,
															   EndTrace,
															   FColor(255, 0, 0),
															   false, -1, 0,
															   12.333
															   );
															   */

	FCollisionQueryParams TraceParams(FName(TEXT("")), true, this);

	// Removed in 4.22
	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_VIEW, TraceParams);

	// We only want portal type actors
	//GetWorld()->LineTraceSingleByObjectType(Hit, StartTrace, EndTrace, COLLISION_VIEW, TraceParams)

	return Cast<AMyServerPortalActor>(Hit.GetActor());
}


AMyBaseVendor* AUEtopiaPersistCharacter::GetVendorFocus() {
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [GetVendorFocus]  "));
	// Attempt to use Raycasts to view an object and echo it back

	FVector Direction = this->FollowCamera->GetForwardVector();
	FVector StartTrace = GetActorLocation();
	const FVector EndTrace = StartTrace + Direction * 3000.0f; //where 300 is the distance it checks

	FCollisionQueryParams TraceParams(FName(TEXT("")), true, this);

	// Removed in 4.22
	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_VIEW, TraceParams);

	// We only want portal type actors
	//GetWorld()->LineTraceSingleByObjectType(Hit, StartTrace, EndTrace, COLLISION_VIEW, TraceParams)

	return Cast<AMyBaseVendor>(Hit.GetActor());
}


FGameplayAbilitySpecHandle AUEtopiaPersistCharacter::AttemptGiveAbility( UGameplayAbility* Ability)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [AttemptGiveAbility]  "));

	FGameplayAbilitySpecHandle AbilityHandle = GetAbilitySystemComponent()->GiveAbility(FGameplayAbilitySpec(Ability, 1, INDEX_NONE)); // assigning abilities to -1 by default makes them not triggerable
	// For abilities to be triggerable, RemapAbilities must be run first, which looks at the ability bar setup
	return AbilityHandle;
}

bool AUEtopiaPersistCharacter::RemapAbilities_Validate()
{
	//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptPickUp_Validate]  "));
	return true;
}


void AUEtopiaPersistCharacter::RemapAbilities_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [RemapAbilities]  "));

	if (IsRunningDedicatedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [RemapAbilities] - Server "));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [RemapAbilities] - Client "));
	}
	AMyPlayerController* playerC = Cast<AMyPlayerController>(Controller);
	AMyPlayerState* playerS = Cast<AMyPlayerState>(playerC->PlayerState);

	FGameplayAbilitySpec* Spec;


	for (int32 abilitySlotIndex = 0; abilitySlotIndex < playerC->MyAbilitySlots.Num(); abilitySlotIndex++)
	{
		Spec = GetAbilitySystemComponent()->FindAbilitySpecFromHandle(playerC->MyAbilitySlots[abilitySlotIndex].GrantedAbility.AbilityHandle);
		if (Spec)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [RemapAbilities] classPath: %s "), *playerC->MyAbilitySlots[abilitySlotIndex].GrantedAbility.classPath);
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [RemapAbilities] Spec->InputID: %d "), Spec->InputID);
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [RemapAbilities] abilitySlotIndex: %d "), abilitySlotIndex);
			Spec->InputID = abilitySlotIndex;
			GetAbilitySystemComponent()->MarkAbilitySpecDirty(*Spec);
		}
		
	}
	// testing - no effect
	//AbilitySystem->InitAbilityActorInfo(this, this);

}

/*
bool AUEtopiaPersistCharacter::Die_Validate(AController* Killer, AActor* DamageCauser, const FGameplayEffectSpec& KillingEffectSpec, float KillingDamageMagnitude, FVector KillingDamageNormal)
{
//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [ServerAttemptSpawnActor_Validate]  "));
return true;
}
*/

void AUEtopiaPersistCharacter::OnRep_PlayerState()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnRep_PlayerState]  "));

	Super::OnRep_PlayerState();

	// This should be running client side...  ???

	AMyPlayerState* PlayerS = Cast<AMyPlayerState>(GetPlayerState());
	if (PlayerS)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [OnRep_PlayerState] Found a valid player state"));

		AMyPlayerController* playerC = Cast<AMyPlayerController>(Controller);
		if (playerC)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] OnRep_PlayerState Found a valid player controller"));
			playerC->OntitleChangedBP();
		}
	}
}

float AUEtopiaPersistCharacter::GetCooldownTimeRemaining(FGameplayAbilitySpecHandle CallingAbilityHandle, float& TotalDuration)
{
	if (CallingAbilityHandle.IsValid())
	{
		if (GetAbilitySystemComponent())
		{
			//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [GetCooldownTimeRemaining]"));
			FGameplayAbilitySpec* Spec = GetAbilitySystemComponent()->FindAbilitySpecFromHandle(CallingAbilityHandle);
			if (Spec)
			{
				//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [GetCooldownTimeRemaining] found spec"));
				UGameplayAbility* AbilityToCheck = Spec->Ability;
				UAbilitySystemComponent* AbilityComp = Cast<IAbilitySystemInterface>(this) ? Cast<IAbilitySystemInterface>(this)->GetAbilitySystemComponent() : nullptr;

				if (AbilityToCheck && AbilityComp)
				{
					//UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [GetCooldownTimeRemaining] AbilityToCheck && AbilityComp"));
					float CurrentDuration;
					AbilityToCheck->GetCooldownTimeRemainingAndDuration(CallingAbilityHandle, AbilityComp->AbilityActorInfo.Get(), CurrentDuration, TotalDuration);
					return CurrentDuration;
				}
			}
		}
	}
	return 0.f;

}

//void AUEtopiaPersistCharacter::Die_Implementation(AController* Killer, AActor* DamageCauser, const FGameplayEffectSpec& KillingEffectSpec, float KillingDamageMagnitude, FVector KillingDamageNormal)
void AUEtopiaPersistCharacter::Die(AController* Killer, AActor* DamageCauser, const FGameplayEffectSpec& KillingEffectSpec, float KillingDamageMagnitude, FVector KillingDamageNormal)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AUEtopiaPersistCharacter] [Die]  "));
	// start the ragdoll and cancel abilities after a very brief delay.
	GetWorldTimerManager().SetTimer(PlayDyingTimerHandle, this, &AUEtopiaPersistCharacter::PlayDying, 0.1f, false);

	AController* const DyingController = (Controller != NULL) ? Controller : Cast<AController>(GetOwner());

	TearOff();
	//bTearOff = true;
	bIsDying = true;
	
	// clear all widgets 
	AMyPlayerController* playerC = Cast<AMyPlayerController>(Controller);
	playerC->ClearHUDWidgets();

	UWorld* const World = GetWorld();
	if (World) {
		UMyGameInstance* gameInstance = Cast<UMyGameInstance>(World->GetGameInstance());
		if (gameInstance)
		{
			// report the kill
			AMyPlayerState* PlayerS = Cast<AMyPlayerState>(this->GetPlayerState());
			AMyPlayerState* KillerPlayerS = Cast<AMyPlayerState>(Killer->PlayerState);

			gameInstance->RecordKill(KillerPlayerS->PlayerId, PlayerS->PlayerId);
		}
	}

	DetachFromControllerPendingDestroy();

	// set it up to remove this body
	SetLifeSpan(5.0f);
}




void AUEtopiaPersistCharacter::PlayDying_Implementation()
{
	if (bIsDying)
	{
		return;
	}

	// CleanUpAbilitySystem();
	// UAbilitySystemGlobals::Get().GetGameplayCueManager()->EndGameplayCuesFor(this);

	TearOff();
	bIsDying = true;
	//bTearOff = true;
	bReplicateMovement = false;

	SetLifeSpan(5.0f);

	//DetachFromControllerPendingDestroy();

	// set it up to remove this body
	//SetLifeSpan(5.0f);

	// disable collision on the collision capsule
	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	}

	// Disable character movement
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->StopMovementImmediately();
		GetCharacterMovement()->DisableMovement();
		GetCharacterMovement()->SetComponentTickEnabled(false);
	}

	// just go full ragdoll for now
	if (USkeletalMeshComponent* SkelMesh = GetMesh())
	{
		//static FName CollisionProfileName(TEXT("Ragdoll"));
		//PrimaryMesh->SetCollisionProfileName(CollisionProfileName);
		SkelMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		SkelMesh->SetSimulatePhysics(true);

		SkelMesh->SetAllBodiesSimulatePhysics(true);
		SkelMesh->bBlendPhysics = true;
		SkelMesh->SetAnimInstanceClass(nullptr);

		// give it the impulse
		/*
		FDamageEvent& DamageEvent = LastTakeHitInfo.GetDamageEvent();
		FVector ImpulseDir;
		FHitResult Hit;
		DamageEvent.GetBestHitInfo(this, LastTakeHitInfo.PawnInstigator.Get(), Hit, ImpulseDir);
		if (DamageEvent.DamageTypeClass)
		{
		FVector const Impulse = ImpulseDir * DamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>()->DamageImpulse;
		PrimaryMesh->AddImpulseAtLocation(Impulse, Hit.ImpactPoint);
		}
		// Ignore projectiles
		PrimaryMesh->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Ignore);
		*/
	}
}


void AUEtopiaPersistCharacter::OnDropsChangedBP_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AUEtopiaCompetitiveCharacter::OnDropsChangedBP_Implementation"));
}
