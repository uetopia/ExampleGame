// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "Core.h"
#include "MySpawnableObject.h"
#include "MyBasePickup.h"
#include "MyBaseVendor.h"
#include "AbilitySystemInterface.h" 
#include "GameplayAbility.h"
#include "MyAttributeSet.h"
#include "UEtopiaPersistCharacter.generated.h"


//class UGameplayAbility;

//Example for an enum the FGameplayAbiliyInputBinds may use to map input to ability slots.
// WE're not using a direct mapping from keypress to ability activation
// Instead keypress will trigger action bar, which is mapped to abilities by the player.

//It's very important that this enum is UENUM, because the code will look for UENUM by the given name and crash if the UENUM can't be found. BlueprintType is there so we can use these in blueprints, too. Just in case. Can be neat to define ability packages.

UENUM(BlueprintType)
enum class AbilityInput : uint8
{
	UseAbility1 UMETA(DisplayName = "Use Ability 1"), //This maps the first ability(input ID should be 0 in int) to the action mapping(which you define in the project settings) by the name of "UseAbility1". "Use Spell 1" is the blueprint name of the element.
	UseAbility2 UMETA(DisplayName = "Use Ability 2"), //Maps ability 2(input ID 1) to action mapping UseAbility2. "Use Spell 2" is mostly used for when the enum is a blueprint variable.
	UseAbility3 UMETA(DisplayName = "Use Ability 3"),
	UseAbility4 UMETA(DisplayName = "Use Ability 4"),
	UseAbility5 UMETA(DisplayName = "Use Ability 5"),
	UseAbility6 UMETA(DisplayName = "Use Ability 6"),
	//WeaponAbility UMETA(DisplayName = "Use Weapon"), //This finally maps the fifth ability(here designated to be your weaponability, or auto-attack, or whatever) to action mapping "WeaponAbility".

	// This is super confusing.
	// These "Input IDs" are referenced by the GiveAbility function, which maps an ability to an input.

													 //You may also do something like define an enum element name that is not actually mapped to an input, for example if you have a passive ability that isn't supposed to have an input. This isn't usually necessary though as you usually grant abilities via input ID,
													 //which can be negative while enums cannot. In fact, a constant called "INDEX_NONE" exists for the exact purpose of rendering an input as unavailable, and it's simply defined as -1.
													 //Because abilities are granted by input ID, which is an int, you may use enum elements to describe the ID anyway however, because enums are fancily dressed up ints.
};


UCLASS()
class EXAMPLEGAME_API AUEtopiaPersistCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

	// via Zlo on discord
	virtual void OnRep_PlayerState() override;

	UFUNCTION(Client, Reliable)
	void InitAbilitySystemClient();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// get this from player state
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	// This is just a way to assign an ability without the full auth flow involved.  Unmute if you need it.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	//	TSubclassOf<class UGameplayAbility> Ability;

	/** Called when the Pawn is being restarted (usually by being possessed by a Controller). */
	void Restart() override;

	/** player pressed start fire action */
	void OnStartFire();

	/* returns true if player has cubes in inventory */
	bool CanFire();

	/** player released start fire action */
	void OnStopFire();

	/* returns true if player can pickup items - controlled by server settings and group permissions */
	bool CanPickUp();

	/** player pressed pickup action */
	void OnPickUp();

	/** player pressed travel action */
	void OnTravel();

	/* true if a player is looking at a portal */
	bool CanTravel();

	/* returns true if player can interact with a vendor */
	bool CanInteractWithVendor();

	/* returns true if player can interact with a vendor */
	bool CanInteractWithGameStore();

	/** player pressed Interact button */
	void OnInteractWithVendor();

	/** player pressed buy action */
	bool bMouseShowing;
	void OnToggleMouse();

	/** spawnable blueprint object reference */
	TSubclassOf<AMySpawnableObject> BlueprintVar; // the base class that the blueprint uses

	/* editor selectable blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = BPClasses)
	UClass* MyBP;

	// Load from path
	static FORCEINLINE UClass* LoadClassFromPath(const FString& Path)
	{
		if (Path == "") return NULL;

		return StaticLoadClass(UObject::StaticClass(), NULL, *Path, NULL, LOAD_None, NULL);
	}

public:
	//AUEtopiaPlugCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptSpawnActor();

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptPickUp();

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptTravel(bool checkOnly);

	// This is the function that gets called on the server
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerAttemptBuy();

	FGameplayAbilitySpecHandle AttemptGiveAbility( UGameplayAbility* Ability);

	UFUNCTION(Server, Reliable, WithValidation)
	void RemapAbilities();

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		float GetCooldownTimeRemaining(FGameplayAbilitySpecHandle CallingAbilityHandle, float& TotalDuration);

	//UFUNCTION(Server, Reliable, WithValidation)
	void Die(AController* Killer, AActor* DamageCauser, const FGameplayEffectSpec& KillingEffectSpec, float KillingDamageMagnitude, FVector KillingDamageNormal);

	UFUNCTION(NetMulticast, Unreliable)
	void PlayDying();

	bool bIsDying;

	FTimerHandle PlayDyingTimerHandle;

	UFUNCTION(BlueprintNativeEvent)
		void OnDropsChangedBP();


private:
	/** pawn mesh: 1st person view */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;
protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponentIn) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/* check to see if there is an item within our trace */
	//TSubclassOf<class AMyBasePickup> GetItemFocus();
	class AMyBasePickup* GetItemFocus();
	class AMyBasePickup* ApplyPostProcessing(AMyBasePickup* itemSeen, AMyBasePickup* oldFocus);

	class AMyServerPortalActor* GetPortalFocus();
	class AMyBaseVendor* GetVendorFocus();
	class AMyGameStore* GetGameStoreFocus();

};
