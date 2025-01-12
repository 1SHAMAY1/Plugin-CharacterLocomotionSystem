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

#include "NewCharacter.h"
#include "NewCharacterMovementComponent.h"
#include "MotionWarpingComponent.h"

 // Sets default values
ANewCharacter::ANewCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UNewCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{

	NewCharacterMovementComponent = Cast<UNewCharacterMovementComponent>(GetCharacterMovement());

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Create and attach the Motion Warping Component
	MotionWarping = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarping"));

	MotionWarping->SetIsReplicated(true);

	ProneEyeHeight = 30.0f;
	SlideEyeHeight = 40.0f;


}


#pragma region Sprint

bool ANewCharacter::Sprint()
{
	if (NewCharacterMovementComponent->CanSprint())
	{
		NewCharacterMovementComponent->StartSprint();
		return true;
	}
	return false;
}

void ANewCharacter::StopSprinting()
{
	NewCharacterMovementComponent->StopSprint();
}


#pragma endregion

#pragma region Crouch

void ANewCharacter::StopCrouchSprinting()
{
	NewCharacterMovementComponent->StopCrouchSprint();
}

bool ANewCharacter::CrouchSprint()
{
	if (NewCharacterMovementComponent->CanCrouchSprint())
	{
		NewCharacterMovementComponent->StartCrouchSprint();
		return true;
	}
	return false;
}

#pragma endregion

#pragma region Prone

bool ANewCharacter::Prone()
{
	if (NewCharacterMovementComponent->CanProne())
	{
		NewCharacterMovementComponent->StartProne();
		return true;
	}
	return false;
}

void ANewCharacter::StopPronning()
{
	NewCharacterMovementComponent->StopProne();
}

#pragma endregion

#pragma region Slide

bool ANewCharacter::Slide()
{
	if (NewCharacterMovementComponent->CanSlide())
	{
		NewCharacterMovementComponent->StartSlide();
		return true;
	}
	return false;

}

void ANewCharacter::StopSliding()
{
	NewCharacterMovementComponent->StopSlide();
}

#pragma endregion

#pragma region WallRun

bool ANewCharacter::WallRun()
{
	if (NewCharacterMovementComponent->CanWallRun())
	{
		NewCharacterMovementComponent->StartWallRun();
		return true;
	}
	return false;
}

void ANewCharacter::StopWallRunning()
{
	if (!NewCharacterMovementComponent->bAutoEndWallRun)
		NewCharacterMovementComponent->StopWallRun();
}

#pragma endregion

#pragma region Dash

bool ANewCharacter::Dash()
{
	if (NewCharacterMovementComponent->CanDashInCurrentState())
	{
		FVector OutTargetLocation;  // Variable to store the target location
		bool bOutSuccess = false;    // Variable to indicate success

		// Call GetDashLocation
		NewCharacterMovementComponent->GetDashLocation(OutTargetLocation, bOutSuccess);

		if (bOutSuccess)  // Check if the dash location was successfully obtained
		{
			NewCharacterMovementComponent->StartDash();  // Pass the location to StartDash
			return true;
		}
	}
	return false;
}


void ANewCharacter::StopDashing()
{
	NewCharacterMovementComponent->StopDash();
}

#pragma endregion

#pragma region Climb

bool ANewCharacter::Climb()
{
	if (NewCharacterMovementComponent->CanClimb())
	{
		NewCharacterMovementComponent->StartClimb();
		return true;
	}
	return false;
}

void ANewCharacter::StopClimb()
{
	NewCharacterMovementComponent->StopClimb();
}

#pragma endregion

#pragma region Advanced Movement

UAdvancedMovementPrimaryDataAsset* ANewCharacter::GetCustomAdvancedMovementData_Implementation() const
{
	return nullptr;
}

bool ANewCharacter::StartCustomAdvancedMovement_Implementation()
{
	if (CanCustomAdvancedMovement())
	{
		NewCharacterMovementComponent->StartCustomAdvancedMovement();
		return true;
	}
	return false;
}

void ANewCharacter::StopCustomAdvancedMovement_Implementation()
{
	NewCharacterMovementComponent->StopCustomAdvancedMovement();
}

void ANewCharacter::EnterCustomAdvancedMovement_Implementation()
{
	NewCharacterMovementComponent->PreInitializeAdvancedMovement();
	if (!GetCustomAdvancedMovementData())
	{
		StopCustomAdvancedMovement();
		return;
	}
	NewCharacterMovementComponent->BroadcastCustomAdvancedMovementInitialized(GetCustomAdvancedMovementData());
	NewCharacterMovementComponent->PlayAdvancedMovementMontage();
	NewCharacterMovementComponent->BroadcastCustomAdvancedMovementStart();
}

void ANewCharacter::ExitCustomAdvancedMovement_Implementation()
{
	NewCharacterMovementComponent->PostInitializeAdvancedMovement();
}

void ANewCharacter::CustomAdvancedMovementPhysics_Implementation(float deltaTime, int32 Iterations)
{
	NewCharacterMovementComponent->FlyingPhysics(deltaTime, Iterations);
}

bool ANewCharacter::CanCustomAdvancedMovement_Implementation()
{
	return false;
}

float ANewCharacter::GetMaxCustomAdvancedSpeed_Implementation()
{
	return 0.0f;
}

void ANewCharacter::AddAndUpdateCustomAdvancedWarpTargets_Implementation()
{
}

#pragma region Vault

UVaultPrimaryDataAsset* ANewCharacter::GetVaultData_Implementation() const
{
	return nullptr;
}

bool ANewCharacter::Vault()
{
	if (NewCharacterMovementComponent->CanVault() && NewCharacterMovementComponent->CanVaultInCurrentState())
	{
		NewCharacterMovementComponent->StartVault();
		return true;
	}
	return false;
}

void ANewCharacter::StopVaulting()
{
	NewCharacterMovementComponent->PostInitializeVault();
}

#pragma endregion

#pragma region Mantle

UMantlePrimaryDataAsset* ANewCharacter::GetMantleData_Implementation() const
{
	return nullptr;
}

bool ANewCharacter::Mantle()
{
	if ((NewCharacterMovementComponent->IsFalling() ? NewCharacterMovementComponent->CanMantleInCurrentState() : NewCharacterMovementComponent->CanMantle()) && NewCharacterMovementComponent->CanMantleInCurrentState())
	{
		NewCharacterMovementComponent->StartMantle();
		return true;
	}
	return false;
}

void ANewCharacter::StopMantling()
{
	NewCharacterMovementComponent->StopMantle();
}

#pragma endregion

#pragma region ClimbUp

UClimbUpPrimaryDataAsset* ANewCharacter::GetClimbUpData_Implementation() const
{
	return nullptr;
}

bool ANewCharacter::ClimbUp()
{
	if (NewCharacterMovementComponent->CanClimbUp() && NewCharacterMovementComponent->CanClimbUpInCurrentState())
	{
		NewCharacterMovementComponent->StartClimbUp();
		return true;
	}
	return false;
}

void ANewCharacter::StopClimbingUp()
{
	NewCharacterMovementComponent->StopClimbUp();
}

#pragma endregion

#pragma endregion

#pragma region Flying

bool ANewCharacter::Fly()
{
	if (NewCharacterMovementComponent->CanFly())
	{
		NewCharacterMovementComponent->StartFly();
		return true;
	}
	return false;

}

bool ANewCharacter::FastFly()
{
	if (NewCharacterMovementComponent->CanFastFly())
	{
		NewCharacterMovementComponent->StartFastFly();
		return true;
	}
	return false;
}

void ANewCharacter::StopFlying()
{
	NewCharacterMovementComponent->StopFly();
}

void ANewCharacter::StopFastFlying()
{
	NewCharacterMovementComponent->StopFastFly();
}

#pragma endregion

#pragma region Swimming

bool ANewCharacter::FastSwim()
{
	if (NewCharacterMovementComponent->CanFastSwim())
	{
		NewCharacterMovementComponent->StartFastSwim();
		return true;
	}
	return false;
}

void ANewCharacter::StopFastSwimming()
{
	NewCharacterMovementComponent->StopFastSwim();
}

#pragma endregion

#pragma region Extra

void ANewCharacter::StartFastMovement()
{
	NewCharacterMovementComponent->StartFastMovement();
}

void ANewCharacter::StopFastMovement()
{
	NewCharacterMovementComponent->StopFastMovement();
}

bool ANewCharacter::StartCustomExtendedMovement_Implementation()
{
	if (CanCustomExtendedMovement())
	{
		NewCharacterMovementComponent->StartCustomExtended();
	}
	return false;
}

void ANewCharacter::StopCustomExtendedMovement_Implementation()
{
	NewCharacterMovementComponent->StopCustomExtended();
}

void ANewCharacter::EnterCustomExtendedMovement_Implementation()
{
	NewCharacterMovementComponent->SetMovementMode(MOVE_Custom, CMOVE_CustomExtended);
}

void ANewCharacter::ExitCustomExtendedMovement_Implementation()
{
	NewCharacterMovementComponent->SetMovementMode(MOVE_Walking);
}

void ANewCharacter::CustomExtendedMovementPhysics_Implementation(float deltaTime, int32 Iterations)
{
	NewCharacterMovementComponent->FlyingPhysics(deltaTime, Iterations);
}

bool ANewCharacter::CanCustomExtendedMovement_Implementation()
{
	return false;
}

float ANewCharacter::GetMaxCustomExtendedSpeed_Implementation()
{
	return 0.0f;
}

#pragma endregion

#pragma region Overriden

// Called when the game starts or when spawned
void ANewCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANewCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANewCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}


float ANewCharacter::GetMaxCustomExtendedAcceleration_Implementation()
{
	return 0.0f;
}

float ANewCharacter::GetMaxCustomExtendedDeceleration_Implementation()
{
	return 0.0f;
}

void ANewCharacter::RecalculateBaseEyeHeight()
{
	if (NewCharacterMovementComponent->IsProning()) BaseEyeHeight = ProneEyeHeight;
	else if (NewCharacterMovementComponent->IsSliding()) BaseEyeHeight = SlideEyeHeight;
	else if (NewCharacterMovementComponent->IsVaulting()) BaseEyeHeight = 2 * GetDefault<APawn>(GetClass())->BaseEyeHeight;
	else Super::RecalculateBaseEyeHeight();
}

void ANewCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	if (NewCharacterMovementComponent->WantsToProne())
	{
		RecalculateBaseEyeHeight();
		K2_OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
	}
	else
		Super::OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
}

#pragma endregion














