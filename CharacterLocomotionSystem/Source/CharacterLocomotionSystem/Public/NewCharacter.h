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
#include "GameFramework/Character.h"
#include "NewCharacter.generated.h"


class UNewCharacterMovementComponent;
class UMotionWarpingComponent;
/**
 * ANewCharacter
 *
 * This class represents a character that provides built-in compatibility
 * with motion warping and utilizes the new character movement component
 * for advanced locomotion mechanics. It extends the base ACharacter class
 * to allow for dynamic and flexible character movement behaviors, including
 * special movements such as climbing, vaulting, and more.
 */
UCLASS()
class CHARACTERLOCOMOTIONSYSTEM_API ANewCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANewCharacter(const FObjectInitializer& ObjectInitializer);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/** Returns NewCharacterMovementComponent subobject **/
	UFUNCTION(Blueprintpure, Category = "Movement", meta = (AllowProtectedAccess = "true"))
	FORCEINLINE  UNewCharacterMovementComponent* GetNewCharacterMovementComponent() const { return NewCharacterMovementComponent; }
	/** Returns MotionWarping Component subobject **/
	UFUNCTION(Blueprintpure, Category = "Movement", meta = (AllowProtectedAccess = "true"))
	FORCEINLINE  UMotionWarpingComponent* GetMotionWarpingComponent() const { return MotionWarping; }

	/**
	 * Initiates fast movement for the character.
	 * When enabled, this function allows for fast movement updates across all movement modes,
	 * enabling the character to move quickly while in states like Walking, flying, swimming, etc.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Fast")
	void StartFastMovement();


	/**
	 * Stops the fast movement for the character.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Fast")
	void StopFastMovement();


#pragma region Overrided

	virtual void RecalculateBaseEyeHeight() override;

#pragma endregion


#pragma region Fly

	/**
	 * Attempts to start flying for the character.
	 * Returns true if the action is successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Fly")
	bool Fly();

	/**
	 * Attempts to start fast flying for the character.
	 * Returns true if the action is successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Fly")
	bool FastFly();

	/**
	 * Stops the flying movement for the character.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Fly")
	void StopFlying();

	/**
	 * Stops the fast flying movement for the character.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Fly")
	void StopFastFlying();

#pragma endregion


#pragma region Swim

	/**
	 * Attempts to start fast swimming for the character.
	 * Returns true if the action is successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Swim")
	bool FastSwim();

	/**
	 * Stops the fast swimming movement for the character.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Swim")
	void StopFastSwimming();


#pragma endregion

#pragma region Sprint

	/**
	 * Attempts to start sprinting for the character.
	 * Sprinting is interconnected with crouch sprinting, and initiating sprint may impact crouch sprint behavior.
	 * @return True if the action is successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Sprint")
	bool Sprint();

	/**
	 * Stops the sprinting movement for the character.
	 * Stopping sprinting may affect crouch sprint behavior due to the interconnected functionality.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Sprint")
	void StopSprinting();



#pragma endregion

#pragma region Crouch
	/**
	 * Attempts to start crouch sprinting for the character.
	 * This may also affect standard sprint behavior due to interconnected functionality.
	 * @return True if the action is successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|CrouchSprint")
	bool CrouchSprint();

	/**
	 * Stops the crouch sprinting movement for the character.
	 * This may also affect standard sprint behavior due to interconnected functionality.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|CrouchSprint")
	void StopCrouchSprinting();


#pragma endregion

#pragma region Dash
	/**
	 * Attempts to start dashing for the character.
	 * @return True if the character successfully starts dashing, otherwise false.
	 * Indicates that the character can dash based on current conditions.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Dash")
	bool Dash();

	/**
	 * Stops the dashing movement for the character.
	 * This function resets the character's state and speed
	 * back to normal after a dash is completed.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Dash")
	void StopDashing();



#pragma endregion

#pragma region Prone
	/**
	 * Attempts to start the proning action for the character.
	 * @return True if the character successfully transitions into a prone position, otherwise false.
	 * Indicates that the character can transition into a prone position based on current conditions.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Prone")
	bool Prone();

	/**
	 * Stops the proning movement for the character.
	 * This function transitions the character out of the prone
	 * position, returning them to a standing or crouched state as appropriate.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Prone")
	void StopPronning();


	/**
	 * The height of the character's eyes when in a prone position.
	 * This value is used to adjust the camera view and ensure
	 * accurate line of sight while the character is proned.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Prone")
	float ProneEyeHeight;


#pragma endregion

#pragma region Slide
	/**
	 * Attempts to initiate the sliding action for the character.
	 * @return True if the character successfully transitions into a sliding state, otherwise false.
	 * Indicates that the character can transition into a sliding state based on
	 * current movement conditions and environment.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Slide")
	bool Slide();

	/**
	 * Stops the sliding movement for the character.
	 * This function transitions the character out of the sliding
	 * state, allowing them to return to regular movement mechanics.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Slide")
	void StopSliding();


	/**
	 * The height of the character's eyes when sliding.
	 * This value is used to adjust the camera view during
	 * sliding to provide a better perspective for aiming
	 * or targeting while maintaining an appropriate field of vision.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Slide")
	float SlideEyeHeight;


#pragma endregion

#pragma region Climb

	/**
	 * Attempts to initiate the climbing action for the character.
	 * @return True if the character successfully transitions into a climbing state, otherwise false.
	 * Indicates that the character can begin climbing based on current movement
	 * conditions and the presence of a valid climbable surface.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Climb")
	bool Climb();

	/**
	 * Stops the climbing movement for the character.
	 * This function transitions the character out of the climbing
	 * state, allowing them to return to regular movement mechanics
	 * or initiate another action.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Climb")
	void StopClimb();


#pragma endregion

#pragma region WallRun
	/**
	 * Attempts to initiate the wall running action for the character.
	 * @return True if the character successfully transitions into a wall running state, otherwise false.
	 * This function checks the conditions for wall running, such as
	 * the character's orientation and proximity to the wall,
	 * returning true if the action is successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|WallRun")
	bool WallRun();

	/**
	 * Stops the wall running movement for the character.
	 * This function transitions the character out of the wall running
	 * state, allowing them to return to regular movement mechanics
	 * or initiate another action.
	 *
	 * Note: This function will not be effective if the auto end wall run feature is active.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|WallRun")
	void StopWallRunning();




#pragma endregion

#pragma region AdvancedMovement

	/**
 * Retrieves the advanced movement data asset associated with this character.
 * This function provides access to custom movement parameters that may affect
 * advanced movement capabilities. Currently, this function does not perform any
 * specific actions and is intended for future implementations.
 *
 * @return Pointer to the UAdvancedMovementPrimaryDataAsset instance.
 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced")
	UAdvancedMovementPrimaryDataAsset* GetCustomAdvancedMovementData() const;
	UAdvancedMovementPrimaryDataAsset* GetCustomAdvancedMovementData_Implementation() const;

	/**
	 * Initiates custom advanced movement for the character.
	 * This function checks the conditions and initiates the necessary changes
	 * in character state to start the custom movement. Currently, it does not
	 * perform any specific actions and is intended for future implementations.
	 *
	 * @return True if the advanced movement was successfully started; otherwise, false.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced")
	bool StartCustomAdvancedMovement();
	bool StartCustomAdvancedMovement_Implementation();

	/**
	 * Stops the custom advanced movement for the character.
	 * This function reverts the character's state back to normal movement mechanics.
	 * Currently, it does not perform any specific actions and is intended for future implementations.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced")
	void StopCustomAdvancedMovement();
	void StopCustomAdvancedMovement_Implementation();

	/**
	 * Performs custom physics calculations for advanced movement.
	 * This function is called every frame to apply any necessary physics logic
	 * related to custom movement mechanics. Currently, it does not perform any
	 * specific actions and is intended for future implementations.
	 *
	 * @param deltaTime The time elapsed since the last frame.
	 * @param Iterations The number of iterations to apply physics calculations.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced")
	void CustomAdvancedMovementPhysics(float deltaTime, int32 Iterations);
	void CustomAdvancedMovementPhysics_Implementation(float deltaTime, int32 Iterations);

	/**
	 * Checks whether the character is currently allowed to perform custom advanced movement.
	 * This function evaluates relevant gameplay conditions to determine if
	 * the movement is permissible. Currently, it does not perform any specific actions
	 * and is intended for future implementations.
	 *
	 * @return True if custom advanced movement can be performed; otherwise, false.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced")
	bool CanCustomAdvancedMovement();
	bool CanCustomAdvancedMovement_Implementation();




#pragma region Vault
	/**
	 * Retrieves the vault data asset associated with this character.
	 * This function provides access to the vaulting parameters that control
	 * the character's vaulting behavior.
	 *
	 * @return Pointer to the UVaultPrimaryDataAsset instance.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced|Vault")
	UVaultPrimaryDataAsset* GetVaultData();
	UVaultPrimaryDataAsset* GetVaultData_Implementation() const;

	/**
	 * Attempts to initiate vaulting for the character.
	 * This function evaluates conditions and triggers the necessary state changes
	 * to perform a vault.
	 *
	 * @return True if the vaulting action was successfully initiated; otherwise, false.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Advanced|Vault")
	bool Vault();

	/**
	 * Stops the vaulting movement for the character.
	 * This function reverts any changes made during the vaulting action,
	 * returning the character to their previous movement state.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Advanced|Vault")
	void StopVaulting();

	/**
	 * Specifies the camera height adjustment during a vaulting action.
	 * This value determines how high the camera view should shift when the character initiates a vault,
	 * providing a smoother visual transition and better perspective for the player.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Vault")
	float VaultEyeHeight;


#pragma endregion

#pragma region Mantle

	/**
	 * Retrieves the mantle data asset associated with this character.
	 * This function provides access to specific parameters and settings
	 * related to mantling mechanics.
	 *
	 * @return Pointer to the UMantlePrimaryDataAsset instance containing mantle data.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced|Mantle")
	UMantlePrimaryDataAsset* GetMantleData();
	UMantlePrimaryDataAsset* GetMantleData_Implementation() const;

	/**
	 * Initiates the mantling action for the character.
	 * This function checks the conditions and attempts to start the
	 * mantling movement based on the current character state and environment.
	 *
	 * @return True if the mantling action was successfully initiated; otherwise, false.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Advanced|Mantle")
	bool Mantle();

	/**
	 * Stops the mantling action for the character.
	 * This function reverts any changes made during the mantling state
	 * and transitions the character back to normal movement.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Advanced|Mantle")
	void StopMantling();


#pragma endregion

#pragma region ClimbUp

	/**
	 * Retrieves the climb-up data asset associated with this character.
	 * This function provides access to specific parameters and settings
	 * related to climbing up mechanics.
	 *
	 * @return Pointer to the UClimbUpPrimaryDataAsset instance containing climb-up data.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Movement|Advanced|ClimbUp")
	UClimbUpPrimaryDataAsset* GetClimbUpData();
	UClimbUpPrimaryDataAsset* GetClimbUpData_Implementation() const;

	/**
	 * Initiates the climbing-up action for the character.
	 * This function checks the conditions and attempts to start the
	 * climbing-up movement based on the current character state and environment.
	 *
	 * @return True if the climbing-up action was successfully initiated; otherwise, false.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Advanced|ClimbUp")
	bool ClimbUp();

	/**
	 * Stops the climbing-up action for the character.
	 * This function reverts any changes made during the climbing-up state
	 * and transitions the character back to normal movement.
	 */
	UFUNCTION(BlueprintCallable, Category = "Movement|Advanced|ClimbUp")
	void StopClimbingUp();

#pragma endregion ClimbUp


#pragma endregion

#pragma endregion


private:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	UNewCharacterMovementComponent* NewCharacterMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	UMotionWarpingComponent* MotionWarping;




};
