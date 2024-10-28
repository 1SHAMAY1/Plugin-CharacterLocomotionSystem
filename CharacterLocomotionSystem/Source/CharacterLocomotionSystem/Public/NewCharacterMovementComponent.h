/**
 * Copyright (c) 2024 [SHANKHARAJ DATTA]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software, known as the "Soft Character Locomotion System," and associated
 * documentation files (including user manuals, API documentation, and readme files)
 * (the "Software"), to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * EXCEPTION: The animations included with this Software (if any) are not covered
 * under this license and may not be used, copied, modified, merged, published,
 * distributed, sublicensed, or sold without express permission from [SHANKHARAJ DATTA].
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AdvancedMovementPrimaryDataAsset.h"
#include "NewCharacterMovementComponent.generated.h"

#pragma region ForwardDeclaration

class UAnimMontage;
class UMotionWarpingComponent;
class ANewCharacter;
class UAdvancedPrimaryDataAsset;
class UVaultPrimaryDataAsset;
class UMantlePrimaryDataAsset;
class UClimbUpPrimaryDataAsset;
class FTimermanager;
class UAnimInstance;

#pragma endregion

#pragma region MovementFlags

enum class EFastMovementFlag : uint8
{
	NONE = 0 UMETA(Hidden),
	CFLAG_WantsToSprint = 1 << 0,
	CFLAG_WantsToDash = 1 << 1,
	CFLAG_WantsToFastFly = 1 << 2,
	CFLAG_WantsToFastSwim = 1 << 3,
	CFLAG_WantsToCrouchSprint = 1<<4,
};

enum class EExtendedMovementFlag : uint8
{
	NONE = 0 UMETA(Hidden),
	CFLAG_WantsToFly = 1 << 0,
	CFLAG_WantsToSlide = 1 << 1,
	CFLAG_WantsToProne = 1 << 2,
	CFLAG_WantsToExtendedCustomMove_02 = 1 << 3,
};

enum class EAdvancedMovementFlag : uint8
{
	NONE = 0 UMETA(Hidden),
	CFLAG_WantsToVault = 1 << 0,
	CFLAG_WantsToMantle = 1 << 1,
	CFLAG_WantsToClimbUp = 1 << 2,
	CFLAG_WantsToCustomAdvancedMovement = 1 << 3,
};

enum class ESpecialMovementFlag : uint8
{
	NONE = 0 UMETA(Hidden),
	CFLAG_WantsToWallRun = 1 << 0,
	CFLAG_RightWall = 1 << 1,
	CFLAG_WantsToClimb = 1 << 2,
	CFLAG_WantsToCustomSpecialMovement = 1 << 3,
	CFLAG_WantsToVerticleWallRun= 1 << 3,
};

#pragma endregion

#pragma region MovementModes

UENUM(BlueprintType)
enum ECustomMovementMode
{
	CMOVE_None			UMETA(Hidden),
	CMOVE_Prone			UMETA(DisplayName = "Prone"),
	CMOVE_Slide			UMETA(DisplayName = "Slide"),
	CMOVE_WallRun		UMETA(DisplayName = "Wall Run"),
	CMOVE_Dash			UMETA(DisplayName = "Dash"),
	CMOVE_Climb			UMETA(DisplayName = "Climb"),
	CMOVE_Vault		    UMETA(DisplayName = "Vault"),
	CMOVE_Mantle		UMETA(DisplayName = "Mantle"),
	CMOVE_ClimbUp		UMETA(DisplayName = "ClimbUp"),
	CMOVE_MAX			UMETA(Hidden),
};

#pragma endregion

#pragma region Helpers

UENUM(BlueprintType)
enum class ESlideExitMovementMode : uint8
{
	Crouch UMETA(DisplayName = "Crouch"),
	Prone UMETA(DisplayName = "Prone")
};

UENUM(BlueprintType)
enum class EWallSide : uint8
{
	None UMETA(DisplayName = "None"),
	Front UMETA(DisplayName = "Front"),
	Back UMETA(DisplayName = "Back"),
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right")
};


/**
 * Structure that stores information about the wall the character is currently interacting with.
 * This includes details such as the side of the wall the character is on and the hit result data
 * from the wall collision. This information is crucial for managing special and advanced
 * character movement states, such as wall-running, wall-climbing, or any other interactions
 * with walls that affect character movement and behavior.
 */
USTRUCT(BlueprintType)
struct FCurrentWallInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterMovement")
	EWallSide WallSide; // The side of the wall the character is interacting with.

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterMovement")
	FHitResult WallHit; // Contains the hit result data for the wall collision.

	FCurrentWallInfo()
		: WallSide(EWallSide::None), WallHit(FHitResult())
	{
	}
};

#pragma endregion

#pragma region Delegates
/** Triggered when the character starts sprinting. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSprintStart);

/** Triggered when the character stops sprinting. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSprintStop);

/** Triggered when the character starts crouch sprinting. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCrouchSprintStart);

/** Triggered when the character stops crouch sprinting. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCrouchSprintStop);

/** Triggered when the character enters a prone position. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProneStart);

/** Triggered when the character exits a prone position. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProneStop);

/** Triggered when the character starts sliding. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSlideStart);

/** Triggered when the character stops sliding. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSlideStop);

/**
 * Triggered when the character starts wall running.
 * Provides information about the current wall being run on.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWallRunStart, FCurrentWallInfo, CurrentWall);

/** Triggered when the character stops wall running. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWallRunStop);

/** Triggered when the character starts dashing. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDashStart);

/** Triggered when the character stops dashing. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDashStop);

/**
 * Triggered when the character starts climbing.
 * Provides information about the current wall being climbed.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClimbStart, FCurrentWallInfo, CurrentWall);

/** Triggered when the character stops climbing. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClimbStop);

/**
 * Triggered when the character reaches the top of a ledge while climbing.
 * Provides information about the current wall.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClimbReachedUpLedge, FCurrentWallInfo, CurrentWall);

/**
 * Triggered when the character starts vaulting.
 * Provides information about the current wall being vaulted over.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVaultStart, FCurrentWallInfo, CurrentWall);

/** Triggered when the character stops vaulting. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnVaultStop);

/**
 * Triggered to initialize vaulting with specified vault data.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVaultInitialize, UVaultPrimaryDataAsset*, VaultData);

/**
 * Triggered when the character starts mantling.
 * Provides information about the current wall being mantled over.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMantleStart, FCurrentWallInfo, CurrentWall);

/** Triggered when the character stops mantling. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMantleStop);

/**
 * Triggered to initialize mantling with specified mantle data.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMantleInitialize, UMantlePrimaryDataAsset*, MantleData);

/**
 * Triggered when the character starts climbing up.
 * Provides information about the current wall being climbed up.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClimbUpStart, FCurrentWallInfo, CurrentWall);

/** Triggered when the character stops climbing up. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClimbUpStop);

/**
 * Triggered to initialize climbing up with specified climb-up data.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClimbUpInitialize, UClimbUpPrimaryDataAsset*, ClimbUpData);

/** Triggered when the character starts fast flying. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFastFlyStart);

/** Triggered when the character stops fast flying. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFastFlyStop);

/** Triggered when the character starts flying. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFlyStart);

/** Triggered when the character stops flying. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFlyStop);

/** Triggered when the character starts fast swimming. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFastSwimStart);

/** Triggered when the character stops fast swimming. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFastSwimStop);

#pragma endregion

/**
 * UNewCharacterMovementComponent
 *
 * This component manages advanced character movement mechanics, including:
 * - Special movements: Climbing, Wall Running, Vaulting, Mantling, and Climbing Up
 * - Fast movements: Fast Flying, Fast Swimming, Crouch Sprinting, Sprinting, and Dashing
 * - Extended movements: Prone, Sliding, and Flying
 *
 * This class extends the functionality of UCharacterMovementComponent to provide
 * a more dynamic and flexible movement system tailored for gameplay.
 */

UCLASS()
class CHARACTERLOCOMOTIONSYSTEM_API UNewCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:

	UNewCharacterMovementComponent(const FObjectInitializer& ObjectInitializer);

#pragma region Networking Functions and Parameters

#pragma region SavedMove

	class FSavedMove_New :public FSavedMove_Character
	{
	public:


		typedef FSavedMove_Character Super;
#pragma region SavedFlags
		uint8 Saved_FastMovementFlag = 0;
		uint8 Saved_ExtendedMovementFlag = 0;
		uint8 Saved_AdvancedMovementFlag = 0;
		uint8 Saved_SpecialMovementFlag = 0;
		FVector SavedDashLocation = FVector(0.f, 0.f, 0.f);
#pragma endregion



		virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const override;
		virtual void Clear() override;
		virtual void SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData) override;
		virtual void PrepMoveFor(ACharacter* C) override;


	};

#pragma endregion

#pragma region NetworkPrediction

	class FNetworkPredictionData_Client_New :public FNetworkPredictionData_Client_Character
	{
	public:
		FNetworkPredictionData_Client_New(const UNewCharacterMovementComponent& ClientMovement);
		typedef FNetworkPredictionData_Client_Character Super;
		virtual FSavedMovePtr AllocateNewMove() override;
	};

#pragma endregion

#pragma region NetworkMovedata

	class FNewNetworkMoveData : public FCharacterNetworkMoveData
	{

	public:

		typedef FCharacterNetworkMoveData Super;

		virtual void ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType) override;

		virtual bool Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType) override;
#pragma region SafeFlags

		uint8 Safe_FastMovementFlag = 0;
		uint8 Safe_ExtendedMovementFlag = 0;
		uint8 Safe_AdvancedMovementFlag = 0;
		uint8 Safe_SpecialMovementFlag = 0;
		FVector SafeDashLocation = FVector(0.f, 0.f, 0.f);

#pragma endregion

	};

#pragma endregion

#pragma region DataContainer

	class FNewCharacterNetworkMoveDataContainer : public FCharacterNetworkMoveDataContainer
	{

	public:

		FNewCharacterNetworkMoveDataContainer();

		FNewNetworkMoveData NewDefaultMoveData[3];
	};

	FNewCharacterNetworkMoveDataContainer NewMoveDataContainer;

#pragma endregion


	uint8 FastMovementFlag = 0;
	uint8 ExtendedMovementFlag = 0;
	uint8 AdvancedMovementFlag = 0;
	uint8 SpecialMovementFlag = 0;
	FVector DashLocation;

#pragma endregion

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	virtual bool CanCrouchInCurrentState() const override;
	virtual void Crouch(bool bClientSimulation = false) override;
	virtual void UnCrouch(bool bClientSimulation = false) override;
	virtual FVector ConstrainAnimRootMotionVelocity(const FVector& RootMotionVelocity, const FVector& CurrentVelocity) const override;
	virtual void PhysFlying(float deltaTime, int32 Iterations);
	virtual bool DoJump(bool bReplayingMoves);
	virtual bool CanAttemptJump() const override;
	virtual bool HandlePendingLaunch() override;
	/**
	 * Checks if the character is currently using a specified custom movement mode.
	 *
	 * @param InCustomMovementMode The custom movement mode to check against the current mode.
	 * @return True if the character is using the specified custom movement mode; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement")
	bool IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const;

	/**
	 * Checks if the character is currently in a specified standard movement mode.
	 *
	 * @param InMovementMode The movement mode to check against the current mode.
	 * @return True if the character is in the specified standard movement mode; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement")
	bool IsMovementMode(EMovementMode InMovementMode) const;

	/**
	 * Handles the physics calculations and movement logic while the character is flying.
	 *
	 * This function processes the movement physics for flying, utilizing DeltaTime and Iterations
	 * to control the smoothness and accuracy of the calculations. Typically used during
	 * free-flight movement states.
	 *
	 * **Note:** This function does not use the movement modes; it is a physics function that can
	 * be utilized to replicate flying movement behavior.
	 *
	 * @param DeltaTime The time elapsed since the last frame, used to calculate smooth movement.
	 * @param Iterations The number of iterations to process, allowing for finer control over the movement calculations.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	void FlyingPhysics(float DeltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and movement logic while the character is sliding.
	 *
	 * This function considers variables and conditions that might cause the character to exit
	 * the sliding state. It ensures that sliding behavior is maintained only when specific
	 * conditions are met, like ground slope and player input. It is recommended to use this function
	 * to extend sliding movement only when the conditions allow it. Note that this function mirrors
	 * the sliding physics calculations, but it is not directly invoked during active sliding physics.
	 *
	 * **Note:** This function does not use the movement modes; it is a physics function that can
	 * be utilized to replicate sliding movement behavior.
	 *
	 * @param DeltaTime The time elapsed since the last frame, used to calculate smooth movement.
	 * @param Iterations The number of iterations to process, allowing for finer control over the movement calculations.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	void SlidingPhysics(float DeltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and movement logic while the character is climbing.
	 *
	 * This function takes into account certain variables to determine whether the character should
	 * continue climbing. It is recommended to use this function to extend climbing movement only
	 * when the conditions allow it. Note that this function mirrors the climbing physics calculations,
	 * but it is not directly invoked during active climbing physics.
	 *
	 * **Note:** This function does not use the movement modes; it is a physics function that can
	 * be utilized to replicate climbing movement behavior.
	 *
	 * @param DeltaTime The time elapsed since the last frame, used to calculate smooth movement.
	 * @param Iterations The number of iterations to process, allowing for finer control over the movement calculations.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	void ClimbingPhysics(float DeltaTime, int32 Iterations);

	/**
	 * Holds the current wall interaction information for the character, including which side of
	 * the wall the character is on and the hit result data. This property is used to manage
	 * advanced character movement states such as wall-running and wall-climbing, enabling
	 * smooth and dynamic interactions with walls in the game environment.
	 */
	UPROPERTY(BlueprintReadOnly, Category = "CharacterMovement|Special&Advanced")
	FCurrentWallInfo CurrentWall;

	/**
	 * Sets the current wall information based on the new wall side and hit result.
	 *
	 * This function updates the wall interaction details, allowing the character to
	 * adjust its behavior based on the new wall parameters. Typically used when detecting
	 * a change in wall side or hit result, such as transitioning from one side of a wall
	 * to another during wall running.
	 *
	 * @param NewWallSide The side of the wall that the character is currently interacting with (e.g., left or right).
	 * @param NewWallHit The hit result data providing information about the wall, such as impact point and normal.
	 */
	UFUNCTION(BlueprintCallable, Category = "CharacterMovement|Special&Advanced")
	void SetWallInfo(EWallSide NewWallSide, const FHitResult& NewWallHit);

	UFUNCTION(Category = "CharacterMovement|Fast")
	void StartFastMovement();
	UFUNCTION(Category = "CharacterMovement|Fast")
	void StopFastMovement();

#pragma region Sprint

#pragma region Parameters

	/**
	 * Determines whether the character is allowed to sprint.
	 * This boolean value can be toggled to enable or disable
	 * sprinting based on gameplay conditions, such as stamina or
	 * specific game states.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Sprint")
	bool bCanSprint;

	/**
	* The maximum speed the character can achieve while sprinting.
	* This value defines how fast the character can move when
	* the sprint action is triggered.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Sprint", meta = (EditCondition = "bCanSprint"))
	float MaxSprintSpeed;

	/**
	 * Event triggered when the character begins sprinting.
	 * This delegate can be bound to allow other game systems to
	 * respond to the sprint start event, such as playing
	 * animations or sound effects.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Sprint")
	FOnSprintStart OnSprintStart;

	/**
	 * Event triggered when the character stops sprinting.
	 * Similar to OnSprintStart, this delegate allows other systems
	 * to respond when the sprinting action ends, enabling features
	 * like transition animations or sounds.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Sprint")
	FOnSprintStop OnSprintStop;


#pragma endregion

#pragma region Functions

	/**
	 * Initiates the sprinting action for the character.
	 * This function is called to set the character's state
	 * to sprinting, increasing the movement speed according
	 * to MaxSprintSpeed and triggering the OnSprintStart event.
	 */
	UFUNCTION(Category = "Character Movement|Sprint")
	void StartSprint();

	/**
	 * Stops the sprinting action for the character.
	 * This function resets the character's movement speed
	 * back to normal and triggers the OnSprintStop event.
	 */
	UFUNCTION(Category = "Character Movement|Sprint")
	void StopSprint();

	/**
	 * Checks if the character is currently allowed to sprint.
	 *
	 * This function returns true if the character is permitted
	 * to sprint based on flag and any additional
	 * game logic. It is a pure function, meaning it does not
	 * alter any state and can be used safely in other calculations.
	 *
	 * @return True if the character can sprint; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Sprint")
	bool CanSprint() const;

	/**
	 * Determines if the character is currently in a sprinting state.
	 * This function checks if the character is actively sprinting,
	 * providing a way to track high-speed movement during gameplay.
	 *
	 * @return True if the character is sprinting; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Sprint")
	bool IsSprinting() const;


#pragma endregion


#pragma endregion

#pragma region Crouch

#pragma region Parameters

	/**
	 * Determines whether the character is allowed to sprint while crouching.
	 * This boolean value enables or disables the ability to sprint in a
	 * crouched state, allowing for different movement tactics in gameplay.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Walking")
	bool bCanCrouchSprint;


	/**
	 * The maximum speed the character can achieve while crouch sprinting.
	 * This value defines how fast the character can move when sprinting
	 * while in a crouched position, providing a tactical option for
	 * movement in certain gameplay situations.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Walking", meta = (EditCondition = "bCanCrouchSprint"))
	float MaxCrouchSprintSpeed;

	/**
	 * Event triggered when the character starts crouch sprinting.
	 * Can be used to handle gameplay behaviors or animations related to the transition into crouch sprinting mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Sprint")
	FOnCrouchSprintStart OnCrouchSprintStart;

	/**
	 * Event triggered when the character stops crouch sprinting.
	 * Can be used to handle gameplay behaviors or animations related to the transition out of crouch sprinting mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Sprint")
	FOnCrouchSprintStop OnCrouchSprintStop;


#pragma endregion

#pragma region Functions

	/**
	 * Initiates the crouch sprinting action for the character.
	 * This function sets the character's state to crouch sprinting,
	 * adjusting movement speed to MaxCrouchSprintSpeed and
	 * triggering any related events for crouch sprinting.
	 */
	UFUNCTION(Category = "Character Movement|CrouchSprint")
	void StartCrouchSprint();

	/**
	 * Stops the crouch sprinting action for the character.
	 * This function resets the character's movement speed back
	 * to normal and ensures the character returns to a standing
	 * or crouched state as appropriate.
	 */
	UFUNCTION(Category = "Character Movement|CrouchSprint")
	void StopCrouchSprint();

	/**
	 * Checks if the character is currently allowed to crouch sprint.
	 *
	 * This function returns true if the character can sprint while
	 * crouching based on flags and other relevant gameplay conditions.
	 * It is a pure function, meaning it does not modify any state and can be
	 * safely used in other calculations or logic.
	 *
	 * @return True if the character can crouch sprint; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|CrouchSprint")
	bool CanCrouchSprint() const;

	/**
	 * Determines if the character is currently in a crouch sprinting state.
	 *
	 * This function checks if the character is actively sprinting while crouched,
	 * providing an easy way to track the character's movement mode.
	 *
	 * @return True if the character is crouch sprinting; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|CrouchSprint")
	bool IsCrouchSprinting() const;


#pragma endregion
#pragma endregion

#pragma region Prone

#pragma region Parameters
	/**
	 * Indicates whether the character is allowed to go prone.
	 * When set to true, the character can transition into a prone state,
	 * enabling prone-specific movement and abilities.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Prone")
	bool bCanProne;

	/**
	 * The maximum speed at which the character can move while prone.
	 * This value determines how quickly the character can maneuver
	 * in a prone position, affecting gameplay mechanics and strategy.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Prone", meta = (EditCondition = "bCanProne"))
	float MaxProneSpeed;

	/**
	 * The maximum acceleration allowed for the character while in a prone state.
	 * This value influences how quickly the character can reach MaxProneSpeed,
	 * impacting the responsiveness of prone movement.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Prone", meta = (EditCondition = "bCanProne"))
	float MaxProneAcceleration;

	/**
	 * The height of the character when in the prone position.
	 * This value is used to adjust the character's collision capsule
	 * and ensure proper navigation and interaction with the environment.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Prone", meta = (EditCondition = "bCanProne"))
	float ProneHeight;

	/**
	 * The braking deceleration applied when the character is transitioning
	 * into a prone state. This value controls how quickly the character
	 * slows down when attempting to go prone, enhancing realism.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Prone", meta = (EditCondition = "bCanProne"))
	float BrakingDecelerationProning;

	/**
	 * Indicates whether to show debug traces for prone movement.
	 * When enabled, debug visuals can assist in troubleshooting
	 * prone movement mechanics, helping developers optimize functionality.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Prone", meta = (EditCondition = "bCanProne"))
	bool bShowProneDebugTraces;

	// Prone Movement Events
	/**
	 * Event triggered when the character successfully enters the prone state.
	 * This delegate can be used to notify other systems or initiate actions
	 * that should occur upon entering prone.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Prone")
	FOnProneStart OnProneStart;

	/**
	 * Event triggered when the character stops being prone.
	 * This delegate can be used to notify other systems or initiate actions
	 * that should occur upon exiting the prone state.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Prone")
	FOnProneStop OnProneStop;

#pragma endregion

#pragma region Functions
	/**
	 * Initiates the prone movement for the character.
	 * This function handles all necessary logic to transition the character
	 * into a prone state, adjusting movement parameters accordingly.
	 */
	UFUNCTION(Category = "Character Movement:Prone")
	void StartProne();

	/**
	 * Stops the prone movement for the character.
	 * This function handles all necessary logic to transition the character
	 * out of the prone state, restoring previous movement parameters.
	 */
	UFUNCTION(Category = "Character Movement:Prone")
	void StopProne();

	/**
	 * Retrieves the half height of the character when in a prone position.
	 * This value is used for collision detection and navigation adjustments
	 * when the character is prone.
	 *
	 * @return The current half height of the character in the prone state.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Prone")
	float GetProneHalfHeight() const;

	/**
	 * Checks whether the character is currently in the prone state.
	 * This function can be used to determine if prone-specific logic
	 * should be applied.
	 *
	 * @return True if the character is prone, false otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Prone")
	bool IsProning() const;

	/**
	 * Determines if the character is able to enter the prone state.
	 * This function can be used to check whether the conditions
	 * are suitable for transitioning into prone.
	 *
	 * @return True if the character can go prone, false otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Prone")
	bool CanProne() const;


#pragma endregion
#pragma endregion

#pragma region Slide

#pragma region Parameters

	/**
	 * Whether the character is allowed to slide.
	 * This value can be used to enable or disable the sliding capability.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide")
	bool bCanSlide;

	/**
	 * Minimum speed required for the character to enter the sliding state.
	 * This value ensures that the character has enough momentum to initiate a slide.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float MinSlideSpeed;

	/**
	 * Maximum speed the character can achieve while sliding.
	 * This value helps limit the sliding speed for gameplay balance.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float MaxSlideSpeed;

	/**
	 * Maximum acceleration allowed while the character is sliding.
	 * This value controls how quickly the character can gain speed during a slide.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float MaxSlideAcceleration;

	/**
	 * Impulse applied to the character when entering the slide.
	 * This value helps give an initial boost to the sliding motion.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float SlideEnterImpulse;

	/**
	 * Gravity force applied during the sliding motion.
	 * This value controls how quickly the character descends while sliding.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float SlideGravityForce;

	/**
	 * Friction factor affecting the sliding behavior.
	 * This value influences how easily the character can slide on various surfaces.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float SlideFrictionFactor;

	/**
	 * Deceleration applied to the character while sliding.
	 * This value helps control how quickly the character comes to a stop after sliding.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float BrakingDecelerationSliding;

	/**
	 * Height of the character's collision capsule during a slide.
	 * This value is used for collision detection and navigation adjustments when sliding.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	float SlideHeight;

	/**
	 * Whether to show debug traces for sliding actions.
	 * This value can be used for visualization in the editor to aid in debugging slide behavior.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	bool bShowSlideDebugTraces;

	/**
	 * The movement mode to transition into upon exiting the slide if unable to stand up.
	 * This value allows for versatile movement options after the sliding action is completed.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Slide", meta = (EditCondition = "bCanSlide"))
	ESlideExitMovementMode SlideExitMovementMode;


	/**
	 * Event triggered when the character starts sliding.
	 * This can be bound to functions to perform additional logic upon starting the slide.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Slide")
	FOnSlideStart OnSlideStart;

	/**
	 * Event triggered when the character stops sliding.
	 * This can be bound to functions to perform additional logic upon stopping the slide.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Slide")
	FOnSlideStop OnSlideStop;


#pragma endregion

#pragma region Functions

	/**
	 * Initiates the sliding action for the character.
	 * This function applies the necessary logic to transition the character into a sliding state,
	 * setting up any relevant parameters and triggering any associated events.
	 */
	UFUNCTION(Category = "Character Movement:Slide")
	void StartSlide();

	/**
	 * Stops the sliding action for the character.
	 * This function applies the necessary logic to transition the character out of the sliding state,
	 * resetting any relevant parameters and triggering any associated events.
	 */
	UFUNCTION(Category = "Character Movement:Slide")
	void StopSlide();

	/**
	 * Retrieves the half height of the character's collision capsule during a slide.
	 * This value is useful for understanding the character's size during sliding,
	 * particularly for collision detection and interactions with the environment.
	 *
	 * @return The half height of the character's collision capsule while sliding.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Slide")
	float GetSlideHalfHeight() const;

	/**
	 * Checks if the character is allowed to slide.
	 * This function returns a boolean indicating whether the sliding capability is enabled
	 * based on the current character state and any game-specific rules.
	 *
	 * @return True if the character can slide; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Slide")
	bool CanSlide() const;

	/**
	 * Determines whether the character is currently in a sliding state.
	 * This function returns a boolean indicating if the character is actively sliding,
	 * which can be used to trigger animations or control game logic accordingly.
	 *
	 * @return True if the character is sliding; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Slide")
	bool IsSliding() const;


#pragma endregion
#pragma endregion

#pragma region WallRun

#pragma region Parameters

	/**
	 * A boolean indicating whether the character is allowed to perform a wall run.
	 * This flag can be toggled to enable or disable wall running based on the game logic.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun")
	bool bCanWallRun;

	/**
	 * The minimum speed required for the character to initiate a wall run.
	 * This value helps ensure that the character has enough momentum to successfully
	 * perform a wall run without falling off.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MinWallRunSpeed;

	/**
	 * The maximum speed the character can achieve while wall running.
	 * This value limits the character's speed to ensure that wall runs remain controlled
	 * and manageable.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MaxWallRunSpeed;

	/**
	 * The maximum acceleration the character can achieve while wall running.
	 * This value allows for quick adjustments to the character's speed while maintaining
	 * control during the wall run.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MaxWallRunAcceleration;

	/**
	 * The maximum vertical speed the character can maintain while wall running.
	 * This value is used to control how high the character can go when running along a wall.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MaxVerticalWallRunSpeed;

	/**
	 * The angle at which the character can pull away from the wall during a wall run.
	 * This value determines how sharply the character can change direction when leaving the wall.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float WallRunPullAwayAngle;

	/**
	 * The force applied to attract the character towards the wall during a wall run.
	 * This value helps maintain contact with the wall while running along it.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float WallAttractionForce;

	/**
	 * The minimum height required to initiate a wall run.
	 * This value sets a threshold to ensure the character is at the appropriate height
	 * for wall running.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MinWallRunHeight;

	/**
	 * The maximum force applied when the character jumps off a wall.
	 * This value determines how far the character can leap away from the wall after a wall run.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MaxWallRunJumpOffForce;

	/**
	 * The minimum gravity scale applied to the character during a wall run.
	 * This value can be used to reduce the impact of gravity while wall running,
	 * allowing for smoother movement along the wall.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MinWallRunGravityScale;

	/**
	 * The maximum gravity scale applied to the character during a wall run.
	 * This value ensures that the character doesn't become too floaty or lose control
	 * while wall running.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	float MaxWallRunGravityScale;

	/**
	 * Determines whether vertical speed adjustments are applied during wall runs.
	 * When enabled, this allows the character to move vertically (up or down) while wall running,
	 * offering greater control over the character's movement on walls.
	 *
	 * The duration for automatically exiting the wall run is calculated using the formula:
	 * WallRunDuration / 2.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	bool bApplyVerticleWallRunSpeed;



	/**
	 * A boolean indicating whether the wall run should automatically end under certain conditions.
	 * This flag can be used to ensure that the character exits the wall run when necessary, based on game design requirements.
	 *
	 * The duration for automatically exiting the wall run is calculated using the formula:
	 * (MaxWallRunSpeed - MinWallRunSpeed) / MinWallRunHeight.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	bool bAutoEndWallRun;


	/**
	 * A boolean indicating whether to display debug traces for wall running.
	 * This flag can be used during development to visualize wall run mechanics
	 * and troubleshoot issues.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character Movement : WallRun", meta = (EditCondition = "bCanWallRun"))
	bool bShowWallRunDebugTraces;

	/**
	 * Event triggered when the wall run starts.
	 * This event can be bound to gameplay elements to respond to the beginning of a wall run.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|WallRun")
	FOnWallRunStart OnWallRunStart;

	/**
	 * Event triggered when the wall run stops.
	 * This event can be bound to gameplay elements to respond to the ending of a wall run.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|WallRun")
	FOnWallRunStop OnWallRunStop;


#pragma endregion

#pragma region Functions
	// Wall Running Functions

	/**
	 * Checks if the character is currently able to perform a wall run.
	 * This function evaluates the necessary conditions, such as speed
	 * and proximity to a wall, to determine if wall running is possible.
	 *
	 * @return True if the character can initiate a wall run; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|WallRun")
	bool CanWallRun();

	/**
	 * Initiates the wall run for the character.
	 * This function sets the necessary parameters to start wall running,
	 * applying the appropriate physics and animations to the character.
	 */
	UFUNCTION(Category = "Character Movement|WallRun")
	void StartWallRun();

	/**
	 * Stops the wall run for the character.
	 * This function resets the parameters related to wall running,
	 * transitioning the character back to normal movement physics.
	 */
	UFUNCTION(Category = "Character Movement|WallRun")
	void StopWallRun();

	/**
	 * Checks if the character is currently in a wall running state.
	 * This function returns the state of the character to determine if
	 * wall running is active, which can be useful for triggering animations
	 * or other gameplay mechanics.
	 *
	 * @return True if the character is currently wall running; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|WallRun")
	bool IsWallRunning() const;

	/**
	 * Determines if the wall run is occurring on the right side of the character.
	 * This function checks the orientation of the wall relative to the character,
	 * which can affect movement direction and gameplay mechanics.
	 *
	 * @return True if the wall run is on the right side; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|WallRun")
	bool IsWallRunOnRightSide() const;

#pragma endregion
#pragma endregion

#pragma region Climb

#pragma region Parameters


	/**
	 * A boolean flag indicating whether the character can climb.
	 * This value serves as a master switch for climbing functionality,
	 * enabling or disabling the climbing ability.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb")
	bool bCanClimb;

	/**
	 * An array of object types that can be considered climbable surfaces.
	 * When the specific climbing surface condition is enabled, this array is used
	 * to filter which surfaces are detectable for climbing.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb && bUseSpecificClimbSurface"))
	TArray<TEnumAsByte<EObjectTypeQuery>> ClimbableSurfaceTraceTypes;


	/**
	 * The distance the character can reach when attempting to climb.
	 * This value determines how far the character can extend their reach
	 * to initiate climbing on a surface.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float ClimbDistance;

	/**
	 * The maximum speed at which the character can climb.
	 * This value controls the climbing speed, influencing how quickly
	 * the character ascends or descends a climbing surface.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float MaxClimbSpeed;

	/**
	 * The maximum acceleration allowed while climbing.
	 * This value influences how quickly the character can reach their
	 * maximum climbing speed, affecting responsiveness to player input.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float MaxClimbAcceleration;

	/**
	 * The maximum deceleration rate when braking while climbing.
	 * This value affects how quickly the character can stop their climbing motion.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float MaxBrakingDecelerationClimb;

	/**
	 * The minimum height a surface must have for it to be considered climbable.
	 * This value is crucial for ensuring that only surfaces of adequate height
	 * are eligible for climbing.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float MinClimbHeight;

	/**
	 * The maximum distance the character can climb in one motion.
	 * This value sets a limit on how far the character can travel
	 * vertically when climbing.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float MaxClimbDistance;

	/**
	 * The minimum angle for a surface to be considered climbable when moving upwards.
	 * This value ensures that the character can only climb surfaces that meet
	 * specific incline requirements.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float MinClimbAngleUpwards;

	/**
	 * The minimum angle for a surface to be considered climbable when moving sideways.
	 * This value helps determine the feasibility of climbing on angled surfaces.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	float MinClimbAngleSideWays;


	/**
	 * A boolean flag indicating whether to use specific climbable surfaces.
	 * When true, only the surfaces defined in ClimbableSurfaceTraceTypes are considered climbable.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	bool bUseSpecificClimbSurface;

	/**
	 * A boolean flag indicating whether to show debug traces for climbing.
	 * When enabled, this option allows developers to visualize climbing surfaces
	 * and trace results in the editor for debugging purposes.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Character Movement : Climb", meta = (EditCondition = "bCanClimb"))
	bool bShowClimbDebugTraces;

	/**
	 * Event that is triggered when climbing starts.
	 * This delegate can be used to trigger animations, sounds, or any other
	 * logic that should occur when the character begins climbing.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Climb")
	FOnClimbStart OnClimbStart;

	/**
	 * Event that is triggered when climbing stops.
	 * This delegate can be used to trigger animations, sounds, or any other
	 * logic that should occur when the character stops climbing.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Climb")
	FOnClimbStop OnClimbStop;

	/**
	 * Event that is triggered when the character reaches an upward ledge during climbing.
	 * This delegate allows for specific actions or transitions to occur when the character
	 * successfully climbs to a ledge.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Climb")
	FOnClimbReachedUpLedge OnClimbReachedUpLedge;


#pragma endregion

#pragma region Functions

	/**
	 * Initiates the climbing action for the character.
	 * This function is called to start the climbing process, transitioning the
	 * character into a climbing state and applying the necessary movement logic.
	 */
	UFUNCTION(Category = "Character Movement:Climb")
	void StartClimb();

	/**
	 * Stops the climbing action for the character.
	 * This function is called to end the climbing process, transitioning the
	 * character out of the climbing state and applying any necessary logic
	 * for resuming normal movement.
	 */
	UFUNCTION(Category = "Character Movement:Climb")
	void StopClimb();

	/**
	 * Retrieves the unrotated climbing velocity of the character.
	 * This function provides the character's current climbing speed without
	 * any rotations applied. This can be useful for determining the character's
	 * movement direction and speed while climbing.
	 *
	 * @return The unrotated climbing velocity as a FVector.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Climb")
	FVector GetUnrotatedClimbVelocity() const;

	/**
	 * Checks if the character is currently climbing.
	 * This function returns a boolean value indicating whether the character
	 * is in the climbing state. It can be used for conditional logic in
	 * other parts of the character's movement system.
	 *
	 * @return True if the character is climbing, false otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Climb")
	bool IsClimbing() const;

	/**
	 * Determines if the character can initiate climbing.
	 * This function checks various conditions to see if climbing is possible,
	 * such as environmental factors, character state, and ability flags.
	 *
	 * @return True if the character can climb, false otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Climb")
	bool CanClimb();

#pragma endregion
#pragma endregion

#pragma region Dash

#pragma region Parameters


	/**
	 * Determines if the character is allowed to dash at all.
	 * This boolean value acts as a toggle for enabling or disabling the dash ability,
	 * providing control over whether the character can perform dashes.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Dash")
	bool bCanDash;

	/**
	 * The distance the character can dash in a single movement.
	 * This value determines how far the character will move when executing a dash action.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Dash", meta = (EditCondition = "bCanDash"))
	float DashDistance;

	/**
	 * The maximum speed the character can achieve while dashing.
	 * This value sets the upper limit for the character's speed during a dash,
	 * allowing for a fast burst of movement.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Dash", meta = (EditCondition = "bCanDash"))
	float MaxDashSpeed;

	/**
	 * Determines if the character can dash through walls.
	 * If set to true, the character will be able to dash through obstacles
	 * without colliding. This can be useful for gameplay mechanics where
	 * passing through walls is desired.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Dash", meta = (EditCondition = "bCanDash"))
	bool CanDashThroughWall;

	/**
	 * Determines if the character can dash while in the air.
	 * If set to true, the character will be able to initiate a dash even
	 * when not in contact with the ground, adding flexibility to movement options.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Dash", meta = (EditCondition = "bCanDash"))
	bool CanDashInAir;


	/**
	 * Determines whether to show debug traces for dash actions.
	 * If enabled, this will provide visual feedback in the editor or game to help
	 * visualize the dash movement, making it easier to debug or adjust parameters.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Dash", meta = (EditCondition = "bCanDash"))
	bool bShowDashDebugTraces;

	/**
	 * Event triggered when the dash action starts.
	 * This event can be used to implement custom behavior or effects when the
	 * character initiates a dash.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Dash")
	FOnDashStart OnDashStart;

	/**
	 * Event triggered when the dash action stops.
	 * This event can be used to implement custom behavior or effects when the
	 * character ends a dash.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Dash")
	FOnDashStop OnDashStop;


#pragma endregion

#pragma region Functions
	/**
	 * Initiates the dash action for the character.
	 * This function handles the logic for starting a dash, including applying any
	 * necessary speed adjustments and triggering the appropriate events.
	 */
	UFUNCTION(Category = "Character Movement:Dash")
	void StartDash();

	/**
	 * Stops the current dash action for the character.
	 * This function handles the logic for ending a dash, including resetting
	 * any speed adjustments and triggering the appropriate events.
	 */
	UFUNCTION(Category = "Character Movement:Dash")
	void StopDash();

	/**
	 * Checks if the character is currently dashing.
	 *
	 * @return Returns true if the character is in a dashing state, otherwise false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Dash")
	bool IsDashing() const;

	/**
	 * Calculates the target location the character will reach after performing a dash.
	 *
	 * @param OutTargetLocation The location to which the character will dash. This is an output parameter.
	 * @param bOutSuccess Indicates whether the calculation was successful or not. This is an output parameter.
	 */
	UFUNCTION(BlueprintPure, Category = "Locomotion|Dash")
	void GetDashLocation(FVector& OutTargetLocation, bool& bOutSuccess) const;


#pragma endregion
#pragma endregion

#pragma region Fly

#pragma region Parameters
	/**
	 * Indicates whether the character is allowed to perform fast flying.
	 * This property determines if the fast fly mechanics are enabled for this character.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character Movement:Flying")
	bool bCanFastFly;

	/**
	 * The maximum speed the character can achieve while fast flying.
	 * This speed setting allows for faster movement during flight.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement:Flying", meta = (EditCondition = "bCanFastFly"))
	float MaxFastFlySpeed;

	/**
	 * The minimum clearance height required to initiate flying.
	 * This value ensures the character has sufficient space above them to start flying.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement:Flying")
	float MaxClearanceInUpForStartFlying;

	/**
	 * The minimum height required for the character to be able to start flying.
	 * This property is useful for preventing flight initiation from too low to the ground.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement:Flying")
	float MinHeightToFly;

	/**
	 * The impulse applied when the character begins to fly.
	 * This vector value controls the initial force exerted to launch the character into the air.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement:Flying")
	FVector FlightEnterImpulse;

	/**
	 * Indicates whether to display debug traces during flying.
	 * This property allows for visual debugging of flying mechanics in the editor.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Character Movement:Flying")
	bool bShowFlyingDebugTraces;

	/**
	 * Event triggered when the character starts flying.
	 * Can be used to handle gameplay behaviors or animations related to the transition into flying mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Flying")
	FOnFlyStart OnFlyStart;

	/**
	 * Event triggered when the character stops flying.
	 * Can be used to handle gameplay behaviors or animations related to the transition out of flying mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Flying")
	FOnFlyStop OnFlyStop;


	/**
	 * Event triggered when the character starts fast flying.
	 * Can be used to handle gameplay behaviors or animations related to the transition into fast flying mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Flying")
	FOnFastFlyStart OnFastFlyStart;

	/**
	 * Event triggered when the character stops fast flying.
	 * Can be used to handle gameplay behaviors or animations related to the transition out of fast flying mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Flying")
	FOnFastFlyStop OnFastFlyStop;


#pragma endregion

#pragma region Functions
	/**
	 * Checks if the character is currently able to fly.
	 * This function evaluates conditions such as character state and environment
	 * to determine if flying is permitted.
	 *
	 * @return True if the character can fly; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Flying")
	bool CanFly() const;

	/**
	 * Checks if the character is currently able to perform fast flying.
	 * This function evaluates conditions to see if fast flying is enabled for the character.
	 *
	 * @return True if the character can fast fly; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Flying")
	bool CanFastFly() const;

	/**
	 * Determines if the character is actively in a fast flying state.
	 * This function checks if the character is currently flying at an accelerated speed.
	 *
	 * @return True if the character is fast flying; otherwise, false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Flying")
	bool IsFastFlying() const;

	/**
	 * Initiates the flying state for the character.
	 * This function applies necessary changes to the character movement state
	 * and physics to transition into flying.
	 */
	UFUNCTION(Category = "Character Movement|Flying")
	void StartFly();

	/**
	 * Stops the flying state for the character.
	 * This function reverts the necessary changes to the character's movement state
	 * and physics to return to ground movement.
	 */
	UFUNCTION(Category = "Character Movement|Flying")
	void StopFly();

	/**
	 * Initiates the fast flying state for the character.
	 * This function applies necessary changes to the character's movement state
	 * and physics to transition into fast flying.
	 */
	UFUNCTION(Category = "Character Movement|Flying")
	void StartFastFly();

	/**
	 * Stops the fast flying state for the character.
	 * This function reverts the necessary changes to the character's movement state
	 * and physics to return to normal flying or ground movement.
	 */
	UFUNCTION(Category = "Character Movement|Flying")
	void StopFastFly();



#pragma endregion
#pragma endregion

#pragma region Swim

#pragma region Parameters


	/**
	 * Indicates whether the character is capable of fast swimming.
	 * This boolean flag is used to determine if the character can swim faster than
	 * the standard swimming speed, depending on conditions like character state or abilities.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character Movement:Swimming")
	bool bCanFastSwim;

	/**
	 * Maximum speed the character can achieve while swimming fast.
	 * This value determines how quickly the character can move through water
	 * when utilizing fast swimming techniques.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement:Swimming", meta = (EditCondition = "bCanFastSwim"))
	float MaxFastSwimSpeed;


	/**
	 * Event triggered when the character starts fast swimming.
	 * Can be used to handle gameplay behaviors or animations related to the transition into fast swimming mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Swimming")
	FOnFastSwimStart OnFastSwimStart;

	/**
	 * Event triggered when the character stops fast swimming.
	 * Can be used to handle gameplay behaviors or animations related to the transition out of fast swimming mode.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Swimming")
	FOnFastSwimStop OnFastSwimStop;



#pragma endregion

#pragma region Functions

	/**
	 * Initiates fast swimming mode for the character.
	 * This function activates any logic or animations needed to switch to fast swimming.
	 */
	UFUNCTION(Category = "Character Movement|Swimming")
	void StartFastSwim();

	/**
	 * Stops fast swimming mode for the character.
	 * This function deactivates any logic or animations related to fast swimming.
	 */
	UFUNCTION(Category = "Character Movement|Swimming")
	void StopFastSwim();

	/**
	 * Checks if the character is capable of fast swimming.
	 * @return True if the character can swim faster than the standard speed, based on conditions like character state or abilities.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Swimming")
	bool CanFastSwim() const;

	/**
	 * Determines if the character is currently in fast swimming mode.
	 * @return True if the character is actively swimming faster than the normal swimming speed.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Swimming")
	bool IsFastSwimming() const;



#pragma endregion
#pragma endregion

#pragma region Advanced Movement

#pragma region Parameters

	/**
	 * Reference to a data asset containing advanced movement configuration.
	 * This asset holds various settings and parameters that influence the
	 * character's advanced movement capabilities, allowing for easier
	 * adjustments and customization.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "CharacterMovement|Advanced")
	UAdvancedMovementPrimaryDataAsset* AdvancedMovementData;

	/**
	 * Array of target locations for warp functionality.
	 * This array stores the locations to which the character can warp
	 * during advanced movement actions. It is used to facilitate quick
	 * positional changes in the game world.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "CharacterMovement|Advanced")
	TArray<FVector> WarpTargetLocations;

	/**
	 * Array of target rotations for warp functionality.
	 * This array holds the rotations corresponding to each warp target location,
	 * allowing the character to smoothly transition to the desired orientation
	 * when warping to a new position.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "CharacterMovement|Advanced")
	TArray<FRotator> WarpTargetRotations;

#pragma endregion

#pragma region Functions
#pragma endregion
#pragma region Vault

#pragma region Parameters

	/**
	 * Determines whether the character can vault.
	 * Can be toggled off to disable vaulting functionality without altering other properties.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement : Advanced : Vault")
	bool bCanVault;

	/**
	 * Types of object queries used to detect vaultable surfaces.
	 * This array holds specific object types that the vault trace will consider valid for vaulting.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	TArray<TEnumAsByte<EObjectTypeQuery>> VaultableSurfaceTraceTypes;


	/**
	 * The half-height of the vaulting area for the character.
	 * This value determines the vertical clearance required for the character
	 * to successfully vault over obstacles, ensuring smooth transitions during movement.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	float VaultHalfHeight;

	/**
	 * The minimum speed required to initiate a vault.
	 * Characters moving slower than this speed will not be able to vault.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	float MinVaultSpeed;

	/**
	 * The maximum distance the character can chack for valid vaultable surface forward.
	 * This defines how far the character can check for vault action.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	float VaultDistance;

	/**
	 * The minimum height required for a surface to be considered vaultable.
	 * Surfaces lower than this height will not trigger a vault.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	float MinVaultHeight;

	/**
	 * The maximum height that the character can vault over.
	 * Surfaces higher than this value will not be considered vaultable.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	float MaxVaultHeight;



	/**
	 * The minimum width of the vault path.
	 * Ensures that vaults are not attempted over narrow surfaces.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	float MinVaultWidth;

	/**
	 * The maximum width allowed for a vault action.
	 * Prevents vaulting across excessively wide gaps or surfaces.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	float MaxVaultWidth;


	/**
	 * If true, enables debug visuals for vault traces.
	 * Helps in visualizing vault detection and troubleshooting vault behavior.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement : Advanced : Vault", meta = (EditCondition = "bCanVault"))
	bool bShowVaultDebugTraces;

	/**
	 * Event triggered when the vault action starts.
	 * Can be used to execute custom logic or animations at the beginning of a vault.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|Vault")
	FOnVaultStart OnVaultStart;

	/**
	 * Event triggered when the vault action stops.
	 * Useful for handling cleanup or additional effects when the character finishes vaulting.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|Vault")
	FOnVaultStop OnVaultStop;

	/**
	 * Event triggered when vault initialization begins.
	 * Can be used to prepare necessary data or animations before the vault starts.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|Vault")
	FOnVaultInitialize OnVaultInitialize;

	/**
	 * Data asset containing configuration and animation data for vaulting.
	 * Provides additional customization for vault behavior and visuals.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "Character Movement|Advanced|Vault")
	UVaultPrimaryDataAsset* VaultData;

#pragma endregion

#pragma region Functions

	/**
	 * Initiates the vault action for the character.
	 * Handles the logic required to start vaulting, such as setting animations, adjusting movement, and triggering events.
	 */
	UFUNCTION(Category = "Character Movement|Advanced|Vault")
	void StartVault();

	/**
	 * Stops the vault action and resets any vault-related states.
	 * Used to end the vaulting process, typically when the character completes or cancels the vault.
	 */
	UFUNCTION(Category = "Character Movement|Advanced|Vault")
	void StopVault();

	/**
	 * Retrieves the half-height of the capsule during a vaulting action.
	 * This value reflects the adjusted capsule size while the character is vaulting,
	 * which helps in determining collision and clearance requirements.
	 * Useful for assessing vault feasibility based on environmental obstacles.
	 * Designed for use within Blueprints to provide access to vaulting parameters.
	 *
	 * @return The capsule's half-height during a vault action.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Advanced|Vault")
	float GetVaultHalfHeight() const;


	/**
	 * Checks if the character is capable of initiating a vault.
	 * Returns true if the conditions for vaulting are met, such as speed, distance, and surface suitability.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Advanced|Vault")
	bool CanVault();

	/**
	 * Checks if the character is currently performing a vault action.
	 * Returns true if the character is in the middle of a vault, allowing for condition checks in gameplay or animations.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Advanced|Vault")
	bool IsVaulting() const;


#pragma endregion
#pragma endregion

#pragma region Mantle

#pragma region Parameters

	/**
	 * Indicates if the character is capable of performing mantle actions.
	 * Set to true if the character can mantle onto surfaces.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement : Advanced : Mantle")
	bool bCanMantle;


	/**
	  * Types of surfaces that the character can mantle onto, defined by object type queries.
	 * Determines which objects will be considered valid for mantle traces.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	TArray<TEnumAsByte<EObjectTypeQuery>> MantlableSurfaceTraceTypes;

	/**
	 * The minimum speed required for the character to initiate a mantle action.
	 * If the character's speed is below this value, mantle attempts will not be triggered.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	float MinMantleSpeed;

	/**
	 * The distance the character will check for mantle surfaces when initiating a mantle action.
	 * Affects how far in front of the character the system will search for mantleable objects.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	float MantleDistance;

	/**
	 * The minimum height of an obstacle that the character can mantle over.
	 * Surfaces below this height will not be considered for mantling.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	float MinMantleHeight;

	/**
	 * The maximum height of an obstacle that the character can mantle over.
	 * Surfaces above this height will not be considered for mantling.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	float MaxMantleHeight;

	/**
	 * The minimum angle required for a surface to be considered suitable for mantling.
	 * This value determines the steepness of the surface that the character can mantle onto.
	 * Surfaces with angles above this threshold will be deemed too steep for the character to
	 * successfully perform a mantle action. This angle is measured relative to the surface normal.
	 * Adjusting this property in the editor allows for fine-tuning of the mantling mechanics.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	float MinMantleAngle;




	/**
	 * Allows the character to perform mantle actions while in the air.
	 * Set to true if mantling can be initiated while falling or jumping.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	bool bCanMantleInAir;

	/**
	 * Enables or disables the display of debug traces for mantle actions.
	 * Useful for visualizing mantle traces during development and troubleshooting.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement : Advanced : Mantle", meta = (EditCondition = "bCanMantle"))
	bool bShowMantleDebugTraces;

	/**
	 * Delegate called when the character starts a mantle action.
	 * Can be used to trigger events or effects when mantling begins.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|Mantle")
	FOnMantleStart OnMantleStart;

	/**
	 * Delegate called when the character stops a mantle action.
	 * Can be used to trigger events or effects when mantling ends.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|Mantle")
	FOnMantleStop OnMantleStop;

	/**
	 * Delegate called when the character initializes a mantle action.
	 * Can be used to prepare or configure settings needed before the mantle begins.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|Mantle")
	FOnMantleInitialize OnMantleInitialize;

	/**
	 * Data asset that holds configuration and settings related to mantling actions.
	 * Allows for centralized management of mantle properties, making it easier to adjust parameters.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "Character Movement|Advanced|Mantle")
	UMantlePrimaryDataAsset* MantleData;

#pragma endregion

#pragma region Functions

	/**
	 * Initiates the mantle action for the character.
	 * This function should be called when the character begins to mantle onto a surface, triggering the mantle process.
	 */
	UFUNCTION(Category = "Character Movement|Advanced|Mantle")
	void StartMantle();

	/**
	 * Stops the mantle action for the character.
	 * This function should be called when the character completes or cancels a mantle action, ending the mantling process.
	 */
	UFUNCTION(Category = "Character Movement|Advanced|Mantle")
	void StopMantle();

	/**
	 * Ends the mantle action when the character starts falling.
	 * This function is useful for situations where the character loses footing or slips off during a mantle attempt, requiring the action to be aborted.
	 */
	UFUNCTION(Category = "Character Movement|Advanced|Mantle")
	void FallingStopMantle();

	/**
	 * Checks if the character can initiate a mantle action.
	 * This function evaluates conditions to determine if mantling is possible, such as speed, surface properties, and angle.
	 * @return true if the character can mantle, otherwise false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Advanced|Mantle")
	bool CanMantle();

	/**
	 * Determines whether the character is currently performing a mantle action.
	 * This function allows other systems to check if the character is mid-mantle.
	 * @return true if the character is in the process of mantling, otherwise false.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Advanced|Mantle")
	bool IsMantling() const;



#pragma endregion
#pragma endregion
#pragma region ClimbUp

#pragma region Parameters


	/**
	 * Indicates whether the character is allowed to perform climb-up actions.
	 * Disabling this will prevent the character from climbing up surfaces.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement : Advanced : ClimbUp")
	bool bCanClimbUp;

	/**
	 * Specifies the object types that are considered valid for climb-up surface detection.
	 * The character will be able to initiate a climb-up action when interacting with surfaces of these types.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : ClimbUp", meta = (EditCondition = "bCanClimbUp"))
	TArray<TEnumAsByte<EObjectTypeQuery>> ClimbUpableSurfaceTraceTypes;

	/**
	 * The minimum speed required for the character to initiate a climb-up action.
	 * If the character's speed is below this value, a climb-up action cannot be started.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : ClimbUp", meta = (EditCondition = "bCanClimbUp"))
	float MinClimbUpSpeed;

	/**
	 * The maximum distance from the character to a surface where a climb-up can be initiated.
	 * This distance determines how close the character needs to be to start climbing up.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : ClimbUp", meta = (EditCondition = "bCanClimbUp"))
	float ClimbUpDistance;

	/**
	 * The minimum angle required for a surface to be considered climbable.
	 * This value determines the steepness of the surface that the character can ascend.
	 * Surfaces with angles below this threshold will not trigger climb-up actions.
	 * A higher value allows for steeper climbs, while a lower value may enable
	 * the character to climb up less steep surfaces.
	 * This property can be adjusted in the editor to fine-tune the climbing mechanics.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : ClimbUp", meta = (EditCondition = "bCanClimbUp"))
	float MinClimbUpAngle;

	/**
	 * The minimum height of the surface for a climb-up action to be possible.
	 * Surfaces below this height will not be considered climbable.
	 * @note The minimum value is clamped to 10.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : ClimbUp", meta = (ClampMin = "10"), meta = (EditCondition = "bCanClimbUp"))
	float MinClimbUpHeight;

	/**
	 * The maximum height of the surface that can be climbed up by the character.
	 * Surfaces taller than this height will be ignored for climb-up actions.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement : Advanced : ClimbUp", meta = (EditCondition = "bCanClimbUp"))
	float MaxClimbUpHeight;


	/**
	 * Toggles the display of debug traces for climb-up actions.
	 * Useful for visualizing climb-up traces during development and testing.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement : Advanced : ClimbUp", meta = (EditCondition = "bCanClimbUp"))
	bool bShowClimbUpDebugTraces;

	/**
	 * Delegate triggered when a climb-up action begins.
	 * Can be used to handle additional logic or effects when the character starts climbing up.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|ClimbUp")
	FOnClimbUpStart OnClimbUpStart;

	/**
	 * Delegate triggered when a climb-up action ends.
	 * Can be used to handle additional logic or effects when the character finishes climbing up.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|ClimbUp")
	FOnClimbUpStop OnClimbUpStop;

	/**
	 * Delegate triggered to initialize a climb-up action.
	 * Can be used to set up necessary parameters or conditions before the climb-up starts.
	 */
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Character Movement|Advanced|ClimbUp")
	FOnClimbUpInitialize OnClimbUpInitialize;

	/**
	 * Reference to a data asset that contains settings and parameters specific to the climb-up action.
	 * This can be used to store configurable data for various climb-up behaviors.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "Character Movement|Advanced|ClimbUp")
	UClimbUpPrimaryDataAsset* ClimbUpData;


#pragma endregion

#pragma region Functions

	/**
	 * Initiates a climb-up action for the character.
	 * This function checks if the conditions are met and triggers the climb-up process, moving the character upward.
	 */
	UFUNCTION(Category = "Character Movement|Advanced|ClimbUp")
	void StartClimbUp();

	/**
	 * Stops the climb-up action for the character.
	 * This can be used to interrupt or end the climb-up movement when certain conditions are met or events occur.
	 */
	UFUNCTION(Category = "Character Movement|Advanced|ClimbUp")
	void StopClimbUp();

	/**
	 * Checks if the character is currently able to perform a climb-up action.
	 * Returns true if the conditions for climbing up are satisfied, false otherwise.
	 * This function is useful for determining if a climb-up can be initiated at the current moment.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Advanced|ClimbUp")
	bool CanClimbUp();

	/**
	 * Checks if the character is currently in the process of climbing up.
	 * Returns true if the character is actively performing a climb-up action, false otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Movement|Advanced|ClimbUp")
	bool IsClimbingUp() const;


#pragma endregion
#pragma endregion
#pragma endregion

#pragma region public Helper Functions
	/**
	 * Updates the target warp locations for the vaulting action.
	 * Calculates and sets positions where the character should move during a vault. Returns true if successful, false otherwise.
	 */
	bool UpdateVaultWarpLocations();

	/**
	 * Updates the target warp locations for the mantling action.
	 * Calculates and sets positions where the character should move during a mantle. Returns true if successful, false otherwise.
	 */
	bool UpdateMantleWarpLocations();

	/**
	 * Updates the target warp locations for the climb-up action.
	 * Calculates and sets positions where the character should move during a climb-up. Returns true if successful, false otherwise.
	 */
	bool UpdateClimbUpWarpLocations();

	/**
	 * Checks if there is a ledge nearby when the character is falling.
	 * Helps determine if a ledge can be grabbed to initiate a mantling or climb-up action. Returns true if a ledge is detected.
	 */
	bool CheckLedgeDuringFall();

	/**
	 * Checks if the character can perform a vault in its current state.
	 * Evaluates conditions to see if vaulting can be initiated, considering movement mode, speed, and other factors.
	 */
	bool CanVaultInCurrentState() const;

	/**
	 * Checks if the character can perform a mantle in its current state.
	 * Evaluates conditions to see if mantling can be initiated, considering movement mode, speed, and other factors.
	 */
	bool CanMantleInCurrentState() const;

	/**
	 * Checks if the character can perform a climb-up in its current state.
	 * Evaluates conditions to see if climbing up can be initiated, considering movement mode, speed, and other factors.
	 */
	bool CanClimbUpInCurrentState() const;

	/**
	 * Prepares and initializes the vaulting process.
	 * This function sets up parameters and ensures all necessary conditions are met before starting a vault.
	 */
	void PreInitializeVault();

	/**
	 * Prepares and initializes the mantling process.
	 * This function sets up parameters and ensures all necessary conditions are met before starting a mantle.
	 */
	void PreInitializeMantle();

	/**
	 * Prepares and initializes the climb-up process.
	 * This function sets up parameters and ensures all necessary conditions are met before starting a climb-up.
	 */
	void PreInitializeClimbUp();

	/**
	 * Finalizes the vaulting process after it has been successfully initiated.
	 * Can be used to handle any cleanup or further setup needed once the vault starts.
	 */
	void PostInitializeVault();

	/**
	 * Finalizes the mantling process after it has been successfully initiated.
	 * Can be used to handle any cleanup or further setup needed once the mantle starts.
	 */
	void PostInitializeMantle();

	/**
	 * Finalizes the climb-up process after it has been successfully initiated.
	 * Can be used to handle any cleanup or further setup needed once the climb-up starts.
	 */
	void PostInitializeClimbUp();

	/**
	 * Plays the animation montage associated with vaulting.
	 * This function handles triggering the vaulting animation at the appropriate time.
	 */
	void PlayVaultMontage();

	/**
	 * Plays the animation montage associated with mantling.
	 * This function handles triggering the mantling animation at the appropriate time.
	 */
	void PlayMantleMontage();

	/**
	 * Plays the animation montage associated with climbing up.
	 * This function handles triggering the climb-up animation at the appropriate time.
	 */
	void PlayClimbUpMontage();

	/**
	 * Determines if the character is currently moving on the ground.
	 * Overrides the default Unreal Engine implementation to add custom behavior to include prone and slide as ground movement mode.
	 */
	virtual bool IsMovingOnGround() const override;

	/**
	 * Plays a specified animation montage.
	 * Triggers the given animation montage, allowing for control over play rate and starting position.
	 * @param InMontage - The montage to play.
	 * @param PlayRate - The rate at which the montage will play.
	 * @param StartingLocation - The starting point within the montage to begin playback.
	 */
	void PlayMonatage(UAnimMontage* InMontage, float PlayRate, float StartingLocation);

#pragma endregion

private:

#pragma region Private Helper Functions and Parameters

	bool bCorrectionHHProne;
	/**
	 * Generates collision query parameters to ignore the character itself during traces.
	 * This is useful for avoiding self-collisions when performing movement checks.
	 */
	FCollisionQueryParams GetIgnoreCharacterParams() const;

	/**
	 * Timer handle used for managing wall run behavior.
	 */
	UPROPERTY()
	FTimerHandle WallRunTimerHandle;

	/**
	 * Timer handle used to manage vertical speed adjustments.
	 */
	FTimerHandle VerticleSpeedTimerHandle;

	/**
	 * Timer handle for checking ledge availability during a fall.
	 */
	FTimerHandle CheckLedgeDuringFallTimerHandle;

	/**
	 * Stores results from traces to detect climbable surfaces.
	 */
	TArray<FHitResult> ClimbSurfaceTracedResult;

	/**
	 * Location of the currently detected climbable surface.
	 */
	FVector CurrentClimbableSurfaceLocation;

	/**
	 * Normal vector of the currently detected climbable surface.
	 */
	FVector CurrentClimbableSurfaceNormal;

	/**
	 * Indicates whether vertical adjustments should be applied during certain movement modes.
	 */
	bool bApplyVerticle;

	/**
	 * Returns the capsule radius of the character.
	 */
	float CapR() const;

	/**
	 * Returns the capsule half-height of the character.
	 */
	float CapHH() const;

	/**
	 * Initiates sliding movement mode.
	 */
	void EnterSlide();

	/**
	 * Exits sliding movement mode and returns to the previous state.
	 */
	void ExitSlide();

	/**
	 * Returns the maximum speed allowed for the character, based on the current movement mode.
	 */
	virtual float GetMaxSpeed() const override;

	/**
	 * Returns the maximum acceleration allowed for the character, based on the current movement mode.
	 */
	virtual float GetMaxAcceleration() const override;

	/**
	 * Returns the maximum braking deceleration for the character, based on the current movement mode.
	 */
	virtual float GetMaxBrakingDeceleration() const override;

	/**
	 * Handles the physics calculations and behavior for sliding movement.
	 */
	void PhysSlide(float DeltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and behavior for prone movement.
	 */
	void PhysProne(float DeltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and behavior for wall running.
	 */
	void PhysWallRun(float DeltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and behavior for climbing.
	 */
	void PhysClimb(float deltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and behavior for dashing.
	 */
	void PhysDash(float deltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and behavior for vaulting.
	 */
	void PhysVault(float deltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and behavior for mantling.
	 */
	void PhysMantle(float deltaTime, int32 Iterations);

	/**
	 * Handles the physics calculations and behavior for climbing up ledges.
	 */
	void PhysClimbUp(float deltaTime, int32 Iterations);


	/**
	 * Performs traces to detect climbable surfaces and stores the results.
	 * Returns true if a climbable surface is detected.
	 */
	bool TraceClimbableSurfaces();

	/**
	 * Processes information about the currently detected climbable surface.
	 * This may include calculating angles, distances, and other metrics.
	 */
	void ProcessClimbableSurfaceInfo();

	/**
	 * Determines if the character has reached an upward ledge that can be climbed.
	 * Uses collision checks to validate the presence of a ledge.
	 */
	bool HasReachedUpLedge();

	/**
	 * Checks if the character is on a solid floor.
	 * Useful for determining when to stop certain movement behaviors like climbing.
	 */
	bool HasReachedFloor();

	/**
	 * Evaluates conditions to determine if climbing should be stopped.
	 */
	bool ShouldStopClimbing();

	/**
	 * Returns the appropriate rotation for climbing, based on delta time.
	 */
	FQuat GetClimbRotation(float deltaTime);

	/**
	 * Updates the position of the climbable surface while the character is climbing.
	 */
	void UpdateClimbSurface(float deltaTime);

	/**
	 * Checks if climbing can be initiated based on the character's current state and movement mode.
	 */
	bool CanStartClimbing();

	/**
	 * Ensures the climb height is sufficient to proceed with the climbing motion.
	 */
	bool SufficientClimbHeight();

	/**
	 * Checks if climbing is allowed in the current movement state.
	 */
	bool CanClimbInCurrentState() const;

	/**
	 * Handles the end of the climb-up montage, providing functionality when the animation finishes or is interrupted.
	 */
	void OnClimbUpTheLedgeMontageEnded(UAnimMontage* MontageToPlay, bool bIsInterupted);

	/**
	 * Handles the end of the vault montage, providing functionality when the animation finishes or is interrupted.
	 */
	void OnVaultMontageEnded(UAnimMontage* MontageToPlay, bool bIsInterupted);

	/**
	 * Handles the end of the mantle montage, providing functionality when the animation finishes or is interrupted.
	 */
	void OnMantleMontageEnded(UAnimMontage* MontageToPlay, bool bIsInterupted);

	/**
	 * Handles the end of the climb-up montage, providing functionality when the animation finishes or is interrupted.
	 */
	void OnClimbUpMontageEnded(UAnimMontage* MontageToPlay, bool bIsInterupted);

	/**
	 * Initiates the vaulting sequence.
	 */
	void EnterVault();

	/**
	 * Initiates the mantling sequence.
	 */
	void EnterMantle();

	/**
	 * Initiates the climb-up sequence.
	 */
	void EnterClimbUp();

	/**
	 * Checks conditions for height adjustments when entering or exiting prone mode.
	 */
	bool CheckHHUpdateProne();

	/**
	 * Checks conditions for stopping height adjustments when exiting prone mode.
	 */
	bool CheckHHUpdateStopProne(bool Crouch);


	/**
	 * Updates the height when entering prone mode.
	 */
	void HHUpdateProne();

	/**
	 * Stops height adjustment updates when exiting prone mode.
	 */
	void HHUpdateStopProne(bool Crouch);

	/**
	 * Updates the height of the character when entering prone mode.
	 * This function handles the necessary adjustments to the character's
	 * height to accommodate the prone position.
	 */
	void HHUpdateVault();

	/**
	 * Stops the height adjustment updates when exiting prone mode.
	 * This function ensures that the character's height returns to its
	 * default state after leaving the prone position.
	 */
	void HHUpdateStopVault();

	/**
	 * Checks conditions for height adjustments when entering or exiting slide mode.
	 */
	bool CheckHHUpdateSlide();

	/**
	 * Checks conditions for stopping height adjustments when exiting slide mode.
	 */
	bool CheckHHUpdateStopSlide();

	/**
	 * Updates the height when entering slide mode.
	 */
	void HHUpdateSlide();

	/**
	 * Stops height adjustment updates when exiting slide mode.
	 */
	void HHUpdateStopSlide();

	/**
	 * Initiates prone movement mode.
	 */
	void EnterProne();

	/**
	 * Exits prone movement mode and returns to the previous state.
	 */
	void ExitProne();


	/**
	 * Reserved for future height adjustment updates for large height changes.
	 */
	bool CheckHHUpdateBig(float InHH, bool UseDefault);

	/**
	 * Reserved for future height adjustment updates for small height changes.
	 */
	bool CheckHHUpdateSmall(float InHH);

	/**
	 * Updates height adjustments for large height changes.
	 */
	void HHUpdateBig(float InHH, bool UseDefault);

	/**
	 * Updates height adjustments for small height changes.
	 */
	void HHUpdateSmall(float InHH);

#pragma region Server RPC

	/**
	 * Server RPC to update height and handle entering prone mode.
	 */
	UFUNCTION(Server, Reliable)
	void Server_UpdateHHEnterProne();

	/**
	 * Server RPC to update height and handle entering slide mode.
	 */
	UFUNCTION(Server, Reliable)
	void Server_UpdateHHEnterSlide();

	/**
	 * Multicast RPC to broadcast height updates for entering prone mode to all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_UpdateHHEnterProne();

	/**
	 * Multicast RPC to broadcast height updates for entering vault mode to all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_UpdateHHEnterVault();

	/**
	 * Multicast RPC to broadcast height updates for entering slide mode to all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_UpdateHHEnterSlide();

	/**
	 * Server RPC to update height and handle exiting prone mode.
	 */
	UFUNCTION(Server, Reliable)
	void Server_UpdateHHExitProne(bool Crouch);

	/**
	 * Server RPC to update height and handle exiting slide mode.
	 */
	UFUNCTION(Server, Reliable)
	void Server_UpdateHHExitSlide();

	/**
	 * Multicast RPC to broadcast height updates for exiting prone mode to all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_UpdateHHExitProne(bool Crouch);

	/**
	 * Multicast RPC to broadcast height updates for exiting vault mode to all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_UpdateHHExitVault();

	/**
	 * Multicast RPC to broadcast height updates for exiting slide mode to all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_UpdateHHExitSlide();


	/**
	 * Multicast RPC to play the vault montage across all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayVault(UAnimMontage* InMontage, float PlayRate, float StartingLocation);

	/**
	 * Server RPC to request playing the vault montage.
	 */
	UFUNCTION(Server, Reliable)
	void Server_PlayVault(UAnimMontage* InMontage, float PlayRate, float StartingLocation);

	/**
	 * Multicast RPC to play the mantle montage across all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayMantle(UAnimMontage* InMontage, float PlayRate, float StartingLocation);

	/**
	 * Server RPC to request playing the mantle montage.
	 */
	UFUNCTION(Server, Reliable)
	void Server_PlayMantle(UAnimMontage* InMontage, float PlayRate, float StartingLocation);

	/**
	 * Multicast RPC to play the climb-up montage across all clients.
	 */
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayClimbUp(UAnimMontage* InMontage, float PlayRate, float StartingLocation);

	/**
	 * Server RPC to request playing the climb-up montage.
	 */
	UFUNCTION(Server, Reliable)
	void Server_PlayClimbUp(UAnimMontage* InMontage, float PlayRate, float StartingLocation);

	void StopVerticleWallRun();


#pragma endregion

#pragma endregion

protected:
	ANewCharacter* CharOwner;
#pragma region Overrided
	virtual void PhysCustom(float DeltaTime, int32 Iterations) override;
	virtual void UpdateCharacterStateBeforeMovement(float DeltaSeconds) override;
	virtual void UpdateCharacterStateAfterMovement(float DeltaSeconds) override;
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;
	virtual void MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel) override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
#pragma endregion

#pragma region New Overridable
	// Activates a flag in the FastMovementFlag bitmask.
	// @param FlagToActivate - The flag to be activated.
	virtual void ActivateExtendedMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = EFastMovementFlag)) uint8 FlagToActivate);

	// Clears a flag in the FastMovementFlag bitmask.
	// @param FlagToClear - The flag to be cleared.
	virtual void ClearFastMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = EFastMovementFlag)) uint8 FlagToClear);

	// Checks if a specific flag is active in the FastMovementFlag bitmask.
	// @param Flag - The flag to check.
	// @return True if the flag is active, otherwise false.
	bool IsFastFlagActive(UPARAM(meta = (Bitmask, BitmaskEnum = EFastMovementFlag)) uint8 Flag) const { return (FastMovementFlag & Flag); }

	// Activates a flag in the ExtendedMovementFlag bitmask.
	// @param FlagToActivate - The flag to be activated.
	virtual void ActivateFastMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = EExtendedMovementFlag)) uint8 FlagToActivate);

	// Clears a flag in the ExtendedMovementFlag bitmask.
	// @param FlagToClear - The flag to be cleared.
	virtual void ClearExtendedMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = EExtendedMovementFlag)) uint8 FlagToClear);

	// Checks if a specific flag is active in the ExtendedMovementFlag bitmask.
	// @param Flag - The flag to check.
	// @return True if the flag is active, otherwise false.
	bool IsExtendedFlagActive(UPARAM(meta = (Bitmask, BitmaskEnum = EExtendedMovementFlag)) uint8 Flag) const { return (ExtendedMovementFlag & Flag); }

	// Activates a flag in the AdvancedMovementFlag bitmask.
	// @param FlagToActivate - The flag to be activated.
	virtual void ActivateAdvancedMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = EAdvancedMovementFlag)) uint8 FlagToActivate);

	// Clears a flag in the AdvancedMovementFlag bitmask.
	// @param FlagToClear - The flag to be cleared.
	virtual void ClearAdvancedMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = EAdvancedMovementFlag)) uint8 FlagToClear);

	// Checks if a specific flag is active in the AdvancedMovementFlag bitmask.
	// @param Flag - The flag to check.
	// @return True if the flag is active, otherwise false.
	bool IsAdvancedFlagActive(UPARAM(meta = (Bitmask, BitmaskEnum = EAdvancedMovementFlag)) uint8 Flag) const { return (AdvancedMovementFlag & Flag); }

	// Activates a flag in the SpecialMovementFlag bitmask.
	// @param FlagToActivate - The flag to be activated.
	virtual void ActivateSpecialMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = ESpecialMovementFlag)) uint8 FlagToActivate);

	// Clears a flag in the SpecialMovementFlag bitmask.
	// @param FlagToClear - The flag to be cleared.
	virtual void ClearSpecialMovementFlag(UPARAM(meta = (Bitmask, BitmaskEnum = ESpecialMovementFlag)) uint8 FlagToClear);

	// Checks if a specific flag is active in the SpecialMovementFlag bitmask.
	// @param Flag - The flag to check.
	// @return True if the flag is active, otherwise false.
	bool IsSpecialFlagActive(UPARAM(meta = (Bitmask, BitmaskEnum = ESpecialMovementFlag)) uint8 Flag) const { return (SpecialMovementFlag & Flag); }


#pragma endregion

};
