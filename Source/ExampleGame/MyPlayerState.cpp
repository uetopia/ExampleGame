// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerState.h"
#include "ProMMO.h"
#include "Net/UnrealNetwork.h"
#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"
#include "DDSLoader.h"
#include "DynamicTextureStaticMeshActor.h"
#include "UEtopiaPersistCharacter.h"
#include "MyPlayerController.h"
#include "MyGameInstance.h"

// https://forums.unrealengine.com/community/community-content-tools-and-tutorials/116578-comprehensive-gameplayabilities-analysis-series
FName AMyPlayerState::AbilitySystemName(TEXT("AbilitySystem"));

AMyPlayerState::AMyPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] Init "));

	// https://forums.unrealengine.com/community/community-content-tools-and-tutorials/116578-comprehensive-gameplayabilities-analysis-series
	AbilitySystem = CreateDefaultSubobject<UMyAbilitySystemComponent>(AMyPlayerState::AbilitySystemName);

	// //ActionRPG also says it should be explicitly replicated
	AbilitySystem->SetIsReplicated(true);
	AttributeSet = CreateDefaultSubobject<UMyAttributeSet>(TEXT("AttributeSet"));

	// Prevent pickups on all maps unless specifically authorized
	allowPickup = false;

	AbilitySlotsPerRow = 6;
}

void AMyPlayerState::BeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] BeginPlay"));
	Super::BeginPlay();

	// Bind to delegates inside ability system
	AbilitySystem->OnActiveGameplayEffectAddedDelegateToSelf.AddUObject(this, &AMyPlayerState::OnGameplayEffectAppliedToSelf);

	AActor* thisOwner = GetOwner();

	// Only on the server, grant cached abilities
	if (IsRunningDedicatedServer())
	{
		AMyPlayerController* playerController = Cast<AMyPlayerController>(thisOwner);
		if (playerController)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] BeginPlay got playerController"));
			// This does not work because at this stage, the Character does not have access to the controller
			//playerController->GrantCachedAbilities();
		}
		
	}

	// On the client only - bind the ability system
	// Retry if it fails
	if (!IsRunningDedicatedServer())
	{

		AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(thisOwner);
		if (playerChar)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] BeginPlay - found playerChar"));

			AbilitySystem->BindAbilityActivationToInputComponent(playerChar->InputComponent, FGameplayAbilityInputBinds("ConfirmInput", "CancelInput", "AbilityInput"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] BeginPlay - DID NOT FIND playerChar->InputComponent"));

			AttemptBindInputToASCDel.BindUFunction(this, FName("AttemptBindInputToASC"), true);
			GetWorld()->GetTimerManager().SetTimer(AttemptBindInputToASCHandle, AttemptBindInputToASCDel, 1.f, false);
		}
	}
}


void AMyPlayerState::ClientInitialize(AController* C)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] ClientInitialize"));
	Super::ClientInitialize(C);
	SetOwner(C);
	// Testing putting this is begin play instead
	/*
	AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(C->GetPawn());
	if (playerChar)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] ClientInitialize - found playerChar"));

		AbilitySystem->BindAbilityActivationToInputComponent(playerChar->InputComponent, FGameplayAbilityInputBinds("ConfirmInput", "CancelInput", "AbilityInput"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] ClientInitialize - DID NOT FIND playerChar->InputComponent"));

		AttemptBindInputToASCDel.BindUFunction(this, FName("AttemptBindInputToASC"), true);
		GetWorld()->GetTimerManager().SetTimer(AttemptBindInputToASCHandle, AttemptBindInputToASCDel, 1.f, false);
	}
	*/

	// Abilities are still not working after map travel
	// testing
	AMyPlayerController* playerController = Cast<AMyPlayerController>(C);
	if (playerController)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] ClientInitialize - found playerController"));
		playerController->GrantCachedAbilities();
		
	}

	AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(C->GetPawn());
	if (playerChar)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] ClientInitialize - found playerChar"));
		playerChar->RemapAbilities();
	}
}




void AMyPlayerState::OnGameplayEffectAppliedToSelf(class UAbilitySystemComponent* FromInstigator, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnGameplayEffectAppliedToSelf"));

	// RPC to client to trigger the delegate
	OnGameplayEffectsChanged();
}

void AMyPlayerState::OnGameplayEffectRemoved(FActiveGameplayEffectHandle Handle)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnGameplayEffectRemoved"));

	// RPC to client to trigger the delegate
	OnGameplayEffectsChanged();
}

void AMyPlayerState::OnGameplayEffectsChanged_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnGameplayEffectsChanged_Implementation"));

	// just trigger the delegate
	OnGameplayEffectChangedDelegate.Broadcast();
}


void AMyPlayerState::TriggerShowMatchResults_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::TriggerShowMatchResults_Implementation"));

	// just trigger the delegate
	FOnShowMatchResultsDelegate.Broadcast();
}

void AMyPlayerState::OnRep_OnAbilityInterfaceChange_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnAbilityInterfaceChange"));
	AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(GetPawn());
	if (playerChar)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnAbilityInterfaceChange got playerChar"));
		playerChar->RemapAbilities();
	}
	

	OnAbilityInterfaceChanged.Broadcast();
}

void AMyPlayerState::AttemptBindInputToASC()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::AttemptBindInputToASC"));

	APawn* thisPawn = GetPawn();
	if (thisPawn)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::AttemptBindInputToASC got pawn"));

		if (thisPawn->IsLocallyControlled())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::AttemptBindInputToASC pawn is locally controlled"));
			AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(thisPawn);

			if (playerChar)
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::AttemptBindInputToASC got player char"));

				if (playerChar->InputComponent)
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] AttemptBindInputToASC - found playerChar->InputComponent"));
					AbilitySystem->BindAbilityActivationToInputComponent(playerChar->InputComponent, FGameplayAbilityInputBinds("ConfirmInput", "CancelInput", "AbilityInput"));
					return;
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] AttemptBindInputToASC - DID NOT FIND playerChar->InputComponent"));

				}

			}
		}
		else
		{
			// not local
			return;
		}
		
	}
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] AttemptBindInputToASC - FAIL - Retrying"));

	AttemptBindInputToASCDel.BindUFunction(this, FName("AttemptBindInputToASC"), true);
	GetWorld()->GetTimerManager().SetTimer(AttemptBindInputToASCHandle, AttemptBindInputToASCDel, 1.f, false);

}

void AMyPlayerState::OnRep_OnCustomTextureChange_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnRep_OnCustomTextureChange_Implementation."));

	// First check to see if they are already loaded.
	// Since we're in player state, this should trigger on travel from lobby to game levels.
	// WE don't need to actually load them again.  We just need to apply them.

	if (customTextures.Num() != LoadedTextures.Num())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnRep_OnCustomTextureChange_Implementation.  customTextures.Num != LoadedTextures.Num"));
		// loop over the custom textures
		// Make sure valid filename was specified
		for (int32 b = 0; b < customTextures.Num(); b++) {
			if (customTextures[b].IsEmpty() || customTextures[b].Contains(TEXT(" ")))
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnRep_OnCustomTextureChange_Implementation.  INVALID FILENAME"));
				customTextures[b] = "https://apitest-dot-ue4topia.appspot.com/img/groups/M_Banners_BaseColor.png";
			}

			// Create the Http request and add to pending request list
			FHttpModule* Http = &FHttpModule::Get();
			if (!Http) { return; }
			if (!Http->IsHttpEnabled()) { return; }

			// this changed in 4.26
			TSharedRef < IHttpRequest, ESPMode::ThreadSafe > Request = Http->CreateRequest();
			Request->SetVerb("GET");
			Request->SetURL(customTextures[b]);
			Request->SetHeader("User-Agent", "UETOPIA_UE4_API_CLIENT/1.0");
			Request->SetHeader("Content-Type", "application/x-www-form-urlencoded");

			//TSharedRef<class IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
			//FileRequests.Add(&HttpRequest.Get(), FPendingFileRequest(FileName));

			//Request->OnProcessRequestComplete().BindUObject(this, delegateCallback);

			Request->OnProcessRequestComplete().BindUObject(this, &AMyPlayerState::ReadCustomTexture_HttpRequestComplete);
			//HttpRequest->SetURL(customTexture);
			//HttpRequest->SetVerb(TEXT("GET"));

			Request->ProcessRequest();

		}
	}

	return;
}

void AMyPlayerState::ReadCustomTexture_HttpRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete."));
	if (!HttpRequest.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete REQUEST INVALID."));
		return;
	}

	/*

	const FPendingFileRequest* PendingRequest = FileRequests.Find(HttpRequest.Get());

	if (PendingRequest == nullptr)
	{
	return;
	}


	*/
	bool bResult = false;
	FString ResponseStr, ErrorStr;

	/*

	// Cloud file being operated on
	{
	FCloudFile* CloudFile = GetCloudFile(PendingRequest->FileName, true);
	CloudFile->AsyncState = EOnlineAsyncTaskState::Failed;
	CloudFile->Data.Empty();
	}
	*/

	if (bSucceeded &&
		HttpResponse.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete. bSucceeded and IsValid "));
		if (EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
		{
			UE_LOG(LogTemp, Log, TEXT("ReadFile request complete. url=%s code=%d"),
				*HttpRequest->GetURL(), HttpResponse->GetResponseCode());

			// https://answers.unrealengine.com/questions/75929/is-it-possible-to-load-bitmap-or-jpg-files-at-runt.html

			// update the memory copy of the file with data that was just downloaded
			//FCloudFile* CloudFile = GetCloudFile(PendingRequest->FileName, true);

			// only tracking a single file....
			// const FString& InFileName
			const FString& CloudFileTitle = "GroupTexture";
			FCloudFile CloudFile = FCloudFile(CloudFileTitle);
			CloudFile.FileName = CloudFileTitle;

			CloudFile.AsyncState = EOnlineAsyncTaskState::Done;
			CloudFile.Data = HttpResponse->GetContent();

			// cache to disk on successful download
			SaveCloudFileToDisk(CloudFile.FileName, CloudFile.Data);

			IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
			// Note: PNG format.  Other formats are supported
			TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);

			//FString TexturePath = FPaths::GameContentDir() + TEXT("../Saved/Cloud/") + CloudFileTitle;
			FString TexturePath = FPaths::CloudDir() + CloudFileTitle;
			UE_LOG(LogTemp, Warning, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete. TexturePath: %s"), *TexturePath);
			TArray<uint8> FileData;

			if (FFileHelper::LoadFileToArray(FileData, *TexturePath))
			{
				UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete. LoadFileToArray "));
				if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(FileData.GetData(), FileData.Num()))
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete. ImageWrapper->SetCompressed "));
					//changed in 4.25
					// const TArray<uint8>* UncompressedBGRA = NULL;
					TArray<uint8> UncompressedBGRA;
					
					if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
					{
						UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete. ImageWrapper->GetRaw "));
						int32 LoadedTextureIndex;
						LoadedTextureIndex = LoadedTextures.Add(UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8));
						// Changed in 4.24
						//LoadedTextures[LoadedTextureIndex]->PlatformData->NumSlices = 1;
						LoadedTextures[LoadedTextureIndex]->GetPlatformData()->SetNumSlices(1);
						LoadedTextures[LoadedTextureIndex]->NeverStream = true;
						void* TextureData = LoadedTextures[LoadedTextureIndex]->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);

						//changed in 4.25
						//FMemory::Memcpy(TextureData, UncompressedBGRA->GetData(), UncompressedBGRA->Num());
						FMemory::Memcpy(TextureData, UncompressedBGRA.GetData(), UncompressedBGRA.Num());

						LoadedTextures[LoadedTextureIndex]->GetPlatformData()->Mips[0].BulkData.Unlock();
						LoadedTextures[LoadedTextureIndex]->UpdateResource();
					}
				}

				// make sure all of the textures are loaded first.
				if (customTextures.Num() == LoadedTextures.Num())
				{
					UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnRep_OnCustomTextureChange_Implementation.  customTextures.Num == LoadedTextures.Num"));
					LoadTexturesOntoActors();
				}
			}
			bResult = true;
		}
		else
		{
			ErrorStr = FString::Printf(TEXT("Invalid response. code=%d error=%s"),
				HttpResponse->GetResponseCode(), *HttpResponse->GetContentAsString());

			UE_LOG(LogTemp, Log, TEXT("Invalid response. code=%d error=%sd"),
				HttpResponse->GetResponseCode(), *HttpRequest->GetURL());
		}
	}
	else
	{
		ErrorStr = TEXT("No response");
	}

	if (!ErrorStr.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("ReadFile request failed. %s"), *ErrorStr);
	}
}

void AMyPlayerState::LoadTexturesOntoActors_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] LoadTexturesOntoActors_Implementation."));

	// now assign the textures to all of the banners
	// we want to loop over the actors first, 
	// and loop over the textures inside.
	// Actor1 - Texture1
	// Actor2 - Texture2
	// Actor3 - Texture1
	// Actor4 - Texture2
	// ActorIndex % len(textures) = TextureIndex  // I think...
	int32 ActorIndex = 0;
	int32 TextureIndex = 0;
	TActorIterator< ADynamicTextureStaticMeshActor > AllActorsItr = TActorIterator< ADynamicTextureStaticMeshActor >(GetWorld());

	//While not reached end (overloaded bool operator)
	while (AllActorsItr)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete. Found ADynamicTextureStaticMeshActor "));

		if (AllActorsItr->MaterialInstance->IsValidLowLevel())
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] ReadCustomTexture_HttpRequestComplete. Material Instance IsValid "));

			if (LoadedTextures.Num())
			{
				TextureIndex = ActorIndex % LoadedTextures.Num();
				UE_LOG(LogTemp, Warning, TEXT("[UETOPIA] [AMyPlayerState] LoadTexturesOntoActors_Implementation. TextureIndex: %d"), TextureIndex);

				AllActorsItr->MaterialInstance->SetTextureParameterValue(FName("BaseColor"), LoadedTextures[TextureIndex]);
			}
		}

		//next actor
		++AllActorsItr;
		++ActorIndex;
	}
}

void AMyPlayerState::SaveCloudFileToDisk(const FString& Filename, const TArray<uint8>& Data)
{
	// save local disk copy as well
	FString LocalFilePath = GetLocalFilePath(Filename);
	bool bSavedLocal = FFileHelper::SaveArrayToFile(Data, *LocalFilePath);
	if (bSavedLocal)
	{
		UE_LOG(LogTemp, Verbose, TEXT("WriteUserFile request complete. Local file cache updated =%s"),
			*LocalFilePath);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("WriteUserFile request complete. Local file cache failed to update =%s"),
			*LocalFilePath);
	}
}

void AMyPlayerState::OnRep_OnDropsChange()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnRep_OnDropsChange."));

	AActor* ActorOwner = GetOwner();

	AMyPlayerController* playerController = Cast<AMyPlayerController>(ActorOwner);
	if (playerController)
	{
		playerController->OnDropsChangedBP();
	}

}

FString AMyPlayerState::GetLocalFilePath(const FString& FileName)
{
	return FPaths::CloudDir() + FPaths::GetCleanFilename(FileName);
}

void AMyPlayerState::OnRep_OnInventoryChange()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnInventoryChange"));
	// MOved to Controller instead.  Skipping the delegate for a direct call.
	AActor* ActorOwner = GetOwner();
	AMyPlayerController* playerController = Cast<AMyPlayerController>(ActorOwner);
	if (playerController)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnInventoryChange Got Controller"));
		playerController->OnInventoryChangedBP();
	}

	//FOnPlayerInventoryChangeDelegate.Broadcast();
}

void AMyPlayerState::OnRep_OnEquipmentChange()
{
	// This is running client side.
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnEquipmentChange"));

	// Attempting to do this without the MyEquipment copy inside of character.  It's not getting found in gameInstance GetPlayerDataComplete for some reason

	// Another problem with this is that other players do not have access to the playerController, so they won't be able to respond to OnEquipmentChangedBP
	AActor* ActorOwner = GetOwner();

	AMyPlayerController* playerController = Cast<AMyPlayerController>(ActorOwner);
	if (playerController)
	{
		// Trigger the bp native call.
		playerController->OnEquipmentChangedBP();

		AUEtopiaPersistCharacter* playerChar = Cast<AUEtopiaPersistCharacter>(playerController->GetPawn());
		if (playerChar)
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] OnRep_OnEquipmentChange - found playerChar"));

			// TODO - Run the function to equip your items.
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] OnRep_OnEquipmentChange - DID NOT FIND playerChar"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] OnRep_OnEquipmentChange - DID NOT FIND playerController"));
	}
	// Equipment can change the attributes too, so fire the delegate to refresh the UI
	// NOt sure why but inventory change effects are not getting caught by OnGameplayEffectAppliedToSelf
	OnGameplayEffectChangedDelegate.Broadcast();

	// WE NEED THIS because of other players and non-local pawns.
	FOnPlayerEquipmentChangeDelegate.Broadcast();

}


FMyGrantedAbility AMyPlayerState::GetGrantedAbilityByClassPath(FString classPathIn)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] GetGrantedAbilityByClassPath "));
	// loop over GrantedAbilities
	for (int32 AIndex = 0; AIndex < GrantedAbilities.Num(); AIndex++)
	{
		if (classPathIn == GrantedAbilities[AIndex].classPath)
		{
			return GrantedAbilities[AIndex];
		}
	}

	FMyGrantedAbility NotFoundAbility;
	return NotFoundAbility;
}

FMyGrantedAbility AMyPlayerState::RemoveGrantedAbilityByClassPath(FString classPathIn)
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerState] GetGrantedAbilityByClassPath "));
	// loop over GrantedAbilities
	for (int32 AIndex = 0; AIndex < GrantedAbilities.Num(); AIndex++)
	{
		if (classPathIn == GrantedAbilities[AIndex].classPath)
		{
			FMyGrantedAbility tempAbilityCopy = GrantedAbilities[AIndex];
			GrantedAbilities.RemoveAt(AIndex);
			return tempAbilityCopy;
		}
	}

	FMyGrantedAbility NotFoundAbility;
	return NotFoundAbility;
}

void AMyPlayerState::OnRep_OnAbilitiesChange_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnAbilitiesChange"));
	AActor* ActorOwner = GetOwner();
	AMyPlayerController* playerController = Cast<AMyPlayerController>(ActorOwner);
	if (playerController)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnAbilitiesChange_Implementation Got Controller"));

		playerController->OnAbilitiesChanged.Broadcast();
	}
}

void AMyPlayerState::OnRep_OnLootSettingsChange()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnLootSettingsChange"));

	AActor* ActorOwner = GetOwner();
	AMyPlayerController* playerController = Cast<AMyPlayerController>(ActorOwner);
	if (playerController)
	{
		UE_LOG(LogTemp, Log, TEXT("[UETOPIA]AMyPlayerState::OnRep_OnLootSettingsChange Got Controller"));
		playerController->OnLootSettingsChangedBP();
	}
}

void AMyPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMyPlayerState, playerTitle);
	DOREPLIFETIME_CONDITION(AMyPlayerState, serverTitle, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, playerKeyId, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, Currency, COND_OwnerOnly);
	//DOREPLIFETIME(AMyPlayerState, ServerPortalKeyIdsAuthorized);
	DOREPLIFETIME_CONDITION(AMyPlayerState, TeamId, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, TeamPlayerIndex, COND_OwnerOnly);
	DOREPLIFETIME(AMyPlayerState, teamTitle);

	DOREPLIFETIME_CONDITION(AMyPlayerState, customTextures, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, playerLoginFlowCompleted, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, winningTeamTitle, COND_OwnerOnly);

	DOREPLIFETIME_CONDITION(AMyPlayerState, InventorySlots, COND_OwnerOnly);

	DOREPLIFETIME(AMyPlayerState, MyEquipment);
	DOREPLIFETIME(AMyPlayerState, Level);
	DOREPLIFETIME(AMyPlayerState, Experience);
	DOREPLIFETIME(AMyPlayerState, ExperienceThisLevel);
	DOREPLIFETIME(AMyPlayerState, MyAbilitySlots);
	DOREPLIFETIME(AMyPlayerState, AbilitySlotsPerRow);

	DOREPLIFETIME_CONDITION(AMyPlayerState, ServerLinksAuthorized, COND_OwnerOnly);
	
	DOREPLIFETIME_CONDITION(AMyPlayerState, allowPickup, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, allowDrop, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, MyDrops, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, bCombatEnabled, COND_OwnerOnly);
	DOREPLIFETIME(AMyPlayerState, GrantedAbilities);
	
	DOREPLIFETIME_CONDITION(AMyPlayerState, bLootDropsEnabled, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, bPartyLeaderCanChangeLootSettings, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, LootThreshold, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, LootSetting, COND_OwnerOnly);

	DOREPLIFETIME_CONDITION(AMyPlayerState, bCanBidOnLoot, COND_OwnerOnly); // replicate only to the owner
	DOREPLIFETIME_CONDITION(AMyPlayerState, gkpAmount, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, gkpVettingThisRaid, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, gkpVettingRemaining, COND_OwnerOnly);

	DOREPLIFETIME_CONDITION(AMyPlayerState, LootData, COND_OwnerOnly);

	DOREPLIFETIME_CONDITION(AMyPlayerState, PlayerTitles, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(AMyPlayerState, PlayerKeyIds, COND_OwnerOnly);
}

/* handles copying properties when we do seamless travel */
void AMyPlayerState::CopyProperties(class APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);

	AMyPlayerState* MyPlayerState = Cast<AMyPlayerState>(PlayerState);

	if (MyPlayerState)
	{
		MyPlayerState->playerTitle = playerTitle;
		MyPlayerState->playerKeyId = playerKeyId;
		MyPlayerState->Currency = Currency;
		MyPlayerState->TeamId = TeamId;
		MyPlayerState->TeamPlayerIndex = TeamPlayerIndex;
		MyPlayerState->customTextures = customTextures;
		MyPlayerState->playerLoginFlowCompleted = playerLoginFlowCompleted;
		MyPlayerState->CharacterSetup = CharacterSetup;
		MyPlayerState->Level = Level;
		MyPlayerState->Experience = Experience;
		MyPlayerState->ExperienceThisLevel = ExperienceThisLevel;
		MyPlayerState->winningTeamTitle = winningTeamTitle;
		MyPlayerState->InventorySlots = InventorySlots;
		MyPlayerState->MyEquipment = MyEquipment;
		MyPlayerState->MyAbilitySlots = MyAbilitySlots;
		MyPlayerState->AbilityCapacity = AbilityCapacity;
		MyPlayerState->AbilitySlotsPerRow = AbilitySlotsPerRow;

		MyPlayerState->allowPickup = allowPickup;
		MyPlayerState->allowDrop = allowDrop;
		MyPlayerState->MyDrops = MyDrops;
		MyPlayerState->bCombatEnabled = bCombatEnabled;
		MyPlayerState->GrantedAbilities = GrantedAbilities;
		MyPlayerState->CachedAbilities = CachedAbilities;

		MyPlayerState->bLootDropsEnabled = bLootDropsEnabled;
		MyPlayerState->bPartyLeaderCanChangeLootSettings = bPartyLeaderCanChangeLootSettings;
		MyPlayerState->LootThreshold = LootThreshold;
		MyPlayerState->LootSetting = LootSetting;

		MyPlayerState->bCanBidOnLoot = bCanBidOnLoot;
		MyPlayerState->gkpAmount = gkpAmount;
		MyPlayerState->gkpVettingThisRaid = gkpVettingThisRaid;
		MyPlayerState->gkpVettingRemaining = gkpVettingRemaining;
	}

}
