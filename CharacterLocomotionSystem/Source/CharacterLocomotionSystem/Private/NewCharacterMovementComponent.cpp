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


#include "NewCharacterMovementComponent.h"
#include "NewCharacter.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Components/CapsuleComponent.h"
#include "Components/ActorComponent.h"
#include "Components/ActorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PhysicsVolume.h"
#include <Kismet/KismetMathLibrary.h>
#include<VaultPrimaryDataAsset.h>
#include<MantlePrimaryDataAsset.h>
#include<ClimbUpPrimaryDataAsset.h>
#include "MotionWarpingComponent.h"

UNewCharacterMovementComponent::UNewCharacterMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);

	SetNetworkMoveDataContainer(NewMoveDataContainer);

	CharOwner = Cast<ANewCharacter>(GetOwner());

	//Walk
	MaxWalkSpeed = 300.0f;
	//Sprint
	MaxSprintSpeed = 600.0f;
	bCanSprint = true;
	//Crouch
	bCanCrouchSprint = true;
	SetCrouchedHalfHeight(50.0f);
	MaxWalkSpeedCrouched = 150;
	MaxCrouchSprintSpeed = 400.0f;
	NavAgentProps.bCanCrouch = true;
	bCanWalkOffLedgesWhenCrouching = true;
	//Prone
	MaxProneSpeed = 75.0f;
	MaxProneAcceleration = 1000.0f;
	ProneHeight = 35.0f;
	BrakingDecelerationProning = 2500.0f;
	bCanProne = true;
	bShowProneDebugTraces = false;
	//Slide
	MinSlideSpeed = 400.0f;
	MaxSlideSpeed = 600.0f;
	MaxSlideAcceleration = 10000.0f;
	SlideEnterImpulse = 400.0f;
	SlideGravityForce = 4000.0f;
	SlideFrictionFactor = 0.06f;
	BrakingDecelerationSliding = 1000.0f;
	SlideHeight = 60.0f;
	bCanSlide = true;
	bShowSlideDebugTraces = false;
	//WallRun
	MinWallRunSpeed = 400.0f;
	MaxWallRunSpeed = 800.0f;
	MaxVerticalWallRunSpeed = 200.0f;
	MaxWallRunAcceleration = MinWallRunSpeed;
	WallRunPullAwayAngle = 75.0f;
	WallAttractionForce = 200.0f;
	MinWallRunHeight = 50.0f;
	MaxWallRunJumpOffForce = 300.0f;
	MinWallRunGravityScale = 0.1f;
	MaxWallRunGravityScale = 0.5f;
	bCanWallRun = true;
	bApplyVerticleWallRunSpeed = true;
	bAutoEndWallRun = true;
	bShowWallRunDebugTraces = false;
	bApplyVerticle = bApplyVerticleWallRunSpeed;
	//Dash
	DashDistance = 1000.0f;
	MaxDashSpeed = 10000.0f;
	CanDashThroughWall = true;
	CanDashInAir = true;
	bCanDash = true;
	bShowDashDebugTraces = false;

	//Climb
	ClimbDistance = 100.0f;
	MaxClimbSpeed = 150.0f;
	MaxClimbAcceleration = 1000.0f;
	MaxBrakingDecelerationClimb = 1000.0f;
	MinClimbHeight = 300.0f;
	MinClimbAngleUpwards = 30.0f;
	MinClimbAngleSideWays = 45.0f;
	MaxClimbDistance = 100.0f;
	bCanClimb = true;
	bUseSpecificClimbSurface = false;

	//Advanced

	//Vault
	MinVaultSpeed = 0.0f;
	VaultDistance = 100.0f;
	VaultHalfHeight = 50.0f;
	MinVaultHeight = 30.0f;
	MaxVaultHeight = 95.0f;
	MinVaultWidth = 10.0f;
	MaxVaultWidth = 40.0f;
	bCanVault = true;
	bShowVaultDebugTraces = false;

	//Mantle

	MinMantleSpeed = 0.0f;
	MantleDistance = 100.0f;
	MinMantleHeight = 70.0f;
	MaxMantleHeight = 95.0f;
	bCanMantle = true;
	bCanMantleInAir = true;
	bShowMantleDebugTraces = false;

	//ClimbUp
	MinClimbUpSpeed = 0.0f;
	ClimbUpDistance = 100.0f;
	MinClimbUpHeight = 200.0f;
	MaxClimbUpHeight = 250.0f;
	bCanClimbUp = true;
	bShowClimbUpDebugTraces = false;


	// Fly

	MaxFlySpeed = 800.0f;
	MaxFastFlySpeed = 2000.0f;;
	BrakingDecelerationFlying = 600.0f;
	MaxClearanceInUpForStartFlying = 500.0f;
	FlightEnterImpulse = FVector(0.0f, 0.0f, 1000.0f);
	MinHeightToFly = 300.0f;
	bShowFlyingDebugTraces = false;
	NavAgentProps.bCanFly = true;
	bCanFastFly = true;

	// Swim

	bCanFastSwim = true;
	MaxSwimSpeed = 200.0f;
	MaxFastSwimSpeed = 400.0f;
}

#pragma region Sprint

void UNewCharacterMovementComponent::StartSprint()
{
	if (bCanSprint)
	{
		ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToSprint);
		OnSprintStart.Broadcast();
	}
}

void UNewCharacterMovementComponent::StopSprint()
{
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToSprint))
	{
		ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToSprint);
		OnSprintStop.Broadcast();
	}
}

bool UNewCharacterMovementComponent::CanSprint() const
{
	return IsMovingOnGround() && !(IsCrouching() || IsProning() || IsSliding());
}

bool UNewCharacterMovementComponent::IsSprinting() const
{
	return IsMovementMode(MOVE_Walking) && !IsCrouching() && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToSprint);
}

#pragma endregion

#pragma region Crouch


bool UNewCharacterMovementComponent::CanCrouchInCurrentState() const
{
	if (!CanEverCrouch())
	{
		return false;
	}

	return !IsFalling() && IsMovingOnGround() && UpdatedComponent && !UpdatedComponent->IsSimulatingPhysics();
}

void UNewCharacterMovementComponent::Crouch(bool bClientSimulation)
{
	if (IsProning()) StopProne();

	Super::Crouch(bClientSimulation);

}

void UNewCharacterMovementComponent::UnCrouch(bool bClientSimulation)
{
	if (IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToProne))
	{
		if (!HasValidData()) return;
		CharacterOwner->bIsCrouched = false;
		/*const float ComponentScale = CharacterOwner->GetCapsuleComponent()->GetShapeScale();
		float HHAdjust = GetCrouchedHalfHeight() - GetProneHalfHeight();
		CharacterOwner->OnEndCrouch(HHAdjust, HHAdjust * ComponentScale);*/
		return;
	}
	else Super::UnCrouch(bClientSimulation);
}

void UNewCharacterMovementComponent::StartCrouchSprint()
{
	if (bCanCrouchSprint)
	{
		ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToCrouchSprint);
		OnCrouchSprintStart.Broadcast();
	}
}

void UNewCharacterMovementComponent::StopCrouchSprint()
{
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToCrouchSprint) && IsCrouching())
	{
		ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToCrouchSprint);
		OnCrouchSprintStop.Broadcast();
	}
}

bool UNewCharacterMovementComponent::CanCrouchSprint() const
{
	return IsCrouching();
}

bool UNewCharacterMovementComponent::IsCrouchSprinting() const
{
	return IsMovementMode(MOVE_Walking) && IsCrouching() && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToSprint);
}


#pragma endregion

#pragma region Prone

void UNewCharacterMovementComponent::StartProne()
{
	if (bCanProne) ActivateExtendedMovementFlag((uint8)EExtendedMovementFlag::CFLAG_WantsToProne);

}

void UNewCharacterMovementComponent::StopProne()
{
	if (IsProning()) ClearExtendedMovementFlag((uint8)EExtendedMovementFlag::CFLAG_WantsToProne);

}

bool UNewCharacterMovementComponent::CanProne() const
{
	return (IsMovementMode(MOVE_Walking));
}


float UNewCharacterMovementComponent::GetProneHalfHeight() const
{
	return ProneHeight;
}

bool UNewCharacterMovementComponent::IsProning() const
{
	return IsCustomMovementMode(CMOVE_Prone);
}

void UNewCharacterMovementComponent::PhysProne(float DeltaTime, int32 Iterations)
{
	if (DeltaTime < MIN_TICK_TIME)
	{
		return;
	}

	if (!CharacterOwner || (!CharacterOwner->Controller && !bRunPhysicsWithNoController && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && (CharacterOwner->GetLocalRole() != ROLE_SimulatedProxy)))
	{
		Acceleration = FVector::ZeroVector;
		Velocity = FVector::ZeroVector;
		return;
	}

	bJustTeleported = false;
	bool bCheckedFall = false;
	bool bTriedLedgeMove = false;
	float remainingTime = DeltaTime;



	// Perform the move
	while ((remainingTime >= MIN_TICK_TIME) && (Iterations < MaxSimulationIterations) && CharacterOwner && (CharacterOwner->Controller || bRunPhysicsWithNoController || (CharacterOwner->GetLocalRole() == ROLE_SimulatedProxy)))
	{
		Iterations++;
		bJustTeleported = false;
		const float timeTick = GetSimulationTimeStep(remainingTime, Iterations);
		remainingTime -= timeTick;

		// Save current values
		UPrimitiveComponent* const OldBase = GetMovementBase();
		const FVector PreviousBaseLocation = (OldBase != NULL) ? OldBase->GetComponentLocation() : FVector::ZeroVector;
		const FVector OldLocation = UpdatedComponent->GetComponentLocation();
		const FFindFloorResult OldFloor = CurrentFloor;

		// Ensure velocity is horizontal.
		MaintainHorizontalGroundVelocity();
		const FVector OldVelocity = Velocity;
		Acceleration.Z = 0.f;

		// Apply acceleration
		CalcVelocity(timeTick, GroundFriction, false, GetMaxBrakingDeceleration());

		// Compute move parameters
		const FVector MoveVelocity = Velocity;
		const FVector Delta = timeTick * MoveVelocity; // dx = v * dt
		const bool bZeroDelta = Delta.IsNearlyZero();
		FStepDownResult StepDownResult;

		if (bZeroDelta)
		{
			remainingTime = 0.f;
		}
		else
		{
			MoveAlongFloor(MoveVelocity, timeTick, &StepDownResult);

			if (IsFalling())
			{
				// pawn decided to jump up
				const float DesiredDist = Delta.Size();
				if (DesiredDist > KINDA_SMALL_NUMBER)
				{
					const float ActualDist = (UpdatedComponent->GetComponentLocation() - OldLocation).Size2D();
					remainingTime += timeTick * (1.f - FMath::Min(1.f, ActualDist / DesiredDist));
				}
				StartNewPhysics(remainingTime, Iterations);
				return;
			}
			else if (IsSwimming()) //just entered water
			{
				StartSwimming(OldLocation, OldVelocity, timeTick, remainingTime, Iterations);
				StopProne();
				return;
			}
		}

		// Update floor.
		// StepUp might have already done it for us.
		if (StepDownResult.bComputedFloor)
		{
			CurrentFloor = StepDownResult.FloorResult;
		}
		else
		{
			FindFloor(UpdatedComponent->GetComponentLocation(), CurrentFloor, bZeroDelta, NULL);
		}


		// check for ledges here
		const bool bCheckLedges = !CanWalkOffLedges();
		if (bCheckLedges && !CurrentFloor.IsWalkableFloor())
		{
			// calculate possible alternate movement
			const FVector GravDir = FVector(0.f, 0.f, -1.f);
			const FVector NewDelta = bTriedLedgeMove ? FVector::ZeroVector : GetLedgeMove(OldLocation, Delta, GravDir);
			if (!NewDelta.IsZero())
			{
				// first revert this move
				RevertMove(OldLocation, OldBase, PreviousBaseLocation, OldFloor, false);

				// avoid repeated ledge moves if the first one fails
				bTriedLedgeMove = true;

				// Try new movement direction
				Velocity = NewDelta / timeTick; // v = dx/dt
				remainingTime += timeTick;
				continue;
			}
			else
			{

				bool bMustJump = bZeroDelta || (OldBase == NULL || (!OldBase->IsQueryCollisionEnabled() && MovementBaseUtility::IsDynamicBase(OldBase)));
				if ((bMustJump || !bCheckedFall) && CheckFall(OldFloor, CurrentFloor.HitResult, Delta, OldLocation, remainingTime, timeTick, Iterations, bMustJump))
				{
					return;
				}
				bCheckedFall = true;

				RevertMove(OldLocation, OldBase, PreviousBaseLocation, OldFloor, true);
				remainingTime = 0.f;
				break;
			}
		}
		else
		{

			if (CurrentFloor.IsWalkableFloor())
			{
				AdjustFloorHeight();
				SetBase(CurrentFloor.HitResult.Component.Get(), CurrentFloor.HitResult.BoneName);
			}
			else if (CurrentFloor.HitResult.bStartPenetrating && remainingTime <= 0.f)
			{
				FHitResult Hit(CurrentFloor.HitResult);
				Hit.TraceEnd = Hit.TraceStart + FVector(0.f, 0.f, MAX_FLOOR_DIST);
				const FVector RequestedAdjustment = GetPenetrationAdjustment(Hit);
				ResolvePenetration(RequestedAdjustment, Hit, UpdatedComponent->GetComponentQuat());
				bForceNextFloorCheck = true;
			}

			if (IsSwimming())
			{
				StartSwimming(OldLocation, Velocity, timeTick, remainingTime, Iterations);
				StopProne();
				return;
			}

			// See if we need to start falling.
			if (!CurrentFloor.IsWalkableFloor() && !CurrentFloor.HitResult.bStartPenetrating)
			{
				const bool bMustJump = bJustTeleported || bZeroDelta || (OldBase == NULL || (!OldBase->IsQueryCollisionEnabled() && MovementBaseUtility::IsDynamicBase(OldBase)));
				if ((bMustJump || !bCheckedFall) && CheckFall(OldFloor, CurrentFloor.HitResult, Delta, OldLocation, remainingTime, timeTick, Iterations, bMustJump))
				{
					StartNewPhysics(DeltaTime, Iterations);

					StopProne();
					return;
				}
				bCheckedFall = true;
			}
		}

		if (IsMovingOnGround())
		{
			if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && timeTick >= MIN_TICK_TIME)
			{
				Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / timeTick;
				MaintainHorizontalGroundVelocity();
			}
		}

		if (UpdatedComponent->GetComponentLocation() == OldLocation)
		{
			remainingTime = 0.f;
			break;
		}
	}

	if (IsMovingOnGround())
	{
		MaintainHorizontalGroundVelocity();
	}
}


void UNewCharacterMovementComponent::EnterProne()
{
	if (CheckHHUpdateProne())
	{
		if (bWantsToCrouch) bWantsToCrouch = false;
		HHUpdateProne();
		Multicast_UpdateHHEnterProne();
		SetMovementMode(MOVE_Custom, CMOVE_Prone);
		OnProneStart.Broadcast();
	}
}

void UNewCharacterMovementComponent::ExitProne()
{
	if (CheckHHUpdateStopProne(bWantsToCrouch))
	{
		HHUpdateStopProne(bWantsToCrouch);
		Multicast_UpdateHHExitProne(bWantsToCrouch);
		SetMovementMode(MOVE_Walking);
		OnProneStop.Broadcast();
	}
	else if (CheckHHUpdateStopProne(true))
	{
		SetMovementMode(MOVE_Walking);
		OnProneStop.Broadcast();
		Crouch();
	}
}


bool UNewCharacterMovementComponent::CheckHHUpdateProne()
{
	float HHAdjusted = ProneHeight - CapHH();
	FHitResult HitResult;
	FVector Loc = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (HHAdjusted + 1.0f);

	// Perform a capsule sweep to check if the space is clear for prone movement
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		Loc,
		Loc,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeCapsule(CapR(), ProneHeight),
		GetIgnoreCharacterParams()
	);

#if WITH_EDITOR

	if (bShowProneDebugTraces)
	{
		// Draw debug capsule at the location
		DrawDebugCapsule(
			GetWorld(),
			Loc,
			ProneHeight,
			CapR(),
			FQuat::Identity,
			bHit ? FColor::Red : FColor::Green, // Red if hit, green if clear
			false, // Non-persistent (will disappear after duration)
			-1,  // Duration (in seconds)
			0,     // Depth priority (0 is the default)
			2.0f   // Thickness of the line
		);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, 10.0f, FColor::Yellow, false, -1);
		}
	}
#endif

	// Return true if the space is clear (no blocking hit or penetration), allowing the character to be prone
	return !(HitResult.bBlockingHit || HitResult.bStartPenetrating);
}


bool UNewCharacterMovementComponent::CheckHHUpdateStopProne(bool Crouch)
{
	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = Crouch ? GetCrouchedHalfHeight() : DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();

	// Calculate the height adjustment to check space for exiting prone
	float HHAdjusted = DefaultCapsuleHalfHeight - CapHH();
	FHitResult HitResult;

	// Determine the location to perform the sweep
	FVector CheckLocation = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (HHAdjusted + 1.0f);

	// Perform a capsule sweep to check if the space is clear
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		CheckLocation,
		CheckLocation,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeCapsule(CapR(), DefaultCapsuleHalfHeight),
		GetIgnoreCharacterParams()
	);

#if WITH_EDITOR

	if (bShowProneDebugTraces)
	{
		// Draw debug capsule at the CheckLocation
		DrawDebugCapsule(
			GetWorld(),
			CheckLocation,
			DefaultCapsuleHalfHeight,
			CapR(),
			FQuat::Identity,
			bHit ? FColor::Red : FColor::Green,
			false,
			-1,
			0,
			2.0f
		);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, -1, FColor::Yellow, false, 1.0f);
		}

	}
#endif

	// Return true if the space is clear (no blocking hit or penetration), allowing the character to stop prone
	return !(HitResult.bBlockingHit || HitResult.bStartPenetrating);
}


void UNewCharacterMovementComponent::HHUpdateProne()
{
	// Get the default character
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	FVector Updated = CharacterOwner->GetActorLocation() - CharacterOwner->GetActorUpVector() * (CapHH() - GetProneHalfHeight());
	CharacterOwner->CacheInitialMeshOffset(CharacterOwner->GetActorUpVector() * GetProneHalfHeight() * (-1), DefaultCharacter->GetMesh()->GetRelativeRotation());
	CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * GetProneHalfHeight() * (-1));
	CharacterOwner->SetActorLocation(Updated);
	CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(GetProneHalfHeight(), true);
}

void UNewCharacterMovementComponent::HHUpdateStopProne(bool Crouch)
{
	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = Crouch ? GetCrouchedHalfHeight() : DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	if (CapHH() != DefaultCapsuleHalfHeight)
	{
		FVector Updated = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (DefaultCapsuleHalfHeight-CapHH());
		CharacterOwner->CacheInitialMeshOffset(CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight * (-1), DefaultCharacter->GetMesh()->GetRelativeRotation());
		CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight * (-1));
		CharacterOwner->SetActorLocation(Updated);
		CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(DefaultCapsuleHalfHeight, true);
	}
}
#pragma endregion

#pragma region Slide

void UNewCharacterMovementComponent::StartSlide()
{
	if (bCanSlide)
	{
		ActivateExtendedMovementFlag((uint8)EExtendedMovementFlag::CFLAG_WantsToSlide);
	}
}

void UNewCharacterMovementComponent::StopSlide()
{
	ClearExtendedMovementFlag((uint8)EExtendedMovementFlag::CFLAG_WantsToSlide);
}

float UNewCharacterMovementComponent::GetSlideHalfHeight() const
{
	return SlideHeight;
}

bool UNewCharacterMovementComponent::CanSlide() const
{
	bool bEnoughSpeed = Velocity.SizeSquared() > pow(MinSlideSpeed, 2);
	return IsMovingOnGround() && !IsCrouching() && bEnoughSpeed;
}

bool UNewCharacterMovementComponent::IsSliding() const
{
	return IsCustomMovementMode(CMOVE_Slide);
}


void UNewCharacterMovementComponent::SlidingPhysics(float deltaTime, int32 Iterations)
{
	PhysSlide(deltaTime, Iterations);
}

void UNewCharacterMovementComponent::PhysSlide(float DeltaTime, int32 Iterations)
{
	if (DeltaTime < MIN_TICK_TIME)
	{
		StopSlide();
		ExitSlide();
		return;

	}
	if (!CanSlide())
	{
		StopSlide();
		ExitSlide();
		return;
	}
	bJustTeleported = false;
	bool bCheckedFall = false;
	bool bTriedLedgeMove = false;
	float remainingTime = DeltaTime;


	// Perform the move
	while ((remainingTime >= MIN_TICK_TIME) && (Iterations < MaxSimulationIterations) && CharacterOwner && (CharacterOwner->Controller || bRunPhysicsWithNoController || (CharacterOwner->GetLocalRole() == ROLE_SimulatedProxy)))
	{
		Iterations++;
		bJustTeleported = false;
		const float timeTick = GetSimulationTimeStep(remainingTime, Iterations);
		remainingTime -= timeTick;

		// Save current values
		UPrimitiveComponent* const OldBase = GetMovementBase();
		const FVector PreviousBaseLocation = (OldBase != NULL) ? OldBase->GetComponentLocation() : FVector::ZeroVector;
		const FVector OldLocation = UpdatedComponent->GetComponentLocation();
		const FFindFloorResult OldFloor = CurrentFloor;

		// Ensure velocity is horizontal.
		MaintainHorizontalGroundVelocity();
		const FVector OldVelocity = Velocity;

		FVector SlopeForce = CurrentFloor.HitResult.Normal;
		SlopeForce.Z = 0.f;
		Velocity += SlopeForce * SlideGravityForce * DeltaTime;

		Acceleration = Acceleration.ProjectOnTo(UpdatedComponent->GetRightVector().GetSafeNormal2D());

		// Apply acceleration
		CalcVelocity(timeTick, GroundFriction * SlideFrictionFactor, false, GetMaxBrakingDeceleration());

		// Compute move parameters
		const FVector MoveVelocity = Velocity;
		const FVector Delta = timeTick * MoveVelocity;
		const bool bZeroDelta = Delta.IsNearlyZero();
		FStepDownResult StepDownResult;
		bool bFloorWalkable = CurrentFloor.IsWalkableFloor();

		if (bZeroDelta)
		{
			remainingTime = 0.f;
		}
		else
		{
			MoveAlongFloor(MoveVelocity, timeTick, &StepDownResult);

			if (IsFalling())
			{
				// pawn decided to jump up
				const float DesiredDist = Delta.Size();
				if (DesiredDist > KINDA_SMALL_NUMBER)
				{
					const float ActualDist = (UpdatedComponent->GetComponentLocation() - OldLocation).Size2D();
					remainingTime += timeTick * (1.f - FMath::Min(1.f, ActualDist / DesiredDist));
				}
				StopSlide();
				ExitSlide();
				return;
			}
			else if (IsSwimming()) //just entered water
			{
				StopSlide();
				ExitSlide();
				OnSlideStop.Broadcast();
				StartSwimming(OldLocation, OldVelocity, timeTick, remainingTime, Iterations);
				return;
			}
		}
		if (StepDownResult.bComputedFloor)
		{
			CurrentFloor = StepDownResult.FloorResult;
		}
		else
		{
			FindFloor(UpdatedComponent->GetComponentLocation(), CurrentFloor, bZeroDelta, NULL);
		}
		const bool bCheckLedges = !CanWalkOffLedges();
		if (bCheckLedges && !CurrentFloor.IsWalkableFloor())
		{
			const FVector GravDir = FVector(0.f, 0.f, -1.f);
			const FVector NewDelta = bTriedLedgeMove ? FVector::ZeroVector : GetLedgeMove(OldLocation, Delta, GravDir);
			if (!NewDelta.IsZero())
			{
				RevertMove(OldLocation, OldBase, PreviousBaseLocation, OldFloor, false);
				bTriedLedgeMove = true;
				Velocity = NewDelta / timeTick;
				remainingTime += timeTick;
				continue;
			}
			else
			{
				bool bMustJump = bZeroDelta || (OldBase == NULL || (!OldBase->IsQueryCollisionEnabled() && MovementBaseUtility::IsDynamicBase(OldBase)));
				if ((bMustJump || !bCheckedFall) && CheckFall(OldFloor, CurrentFloor.HitResult, Delta, OldLocation, remainingTime, timeTick, Iterations, bMustJump))
				{
					StopSlide();
					ExitSlide();
					return;
				}
				bCheckedFall = true;

				RevertMove(OldLocation, OldBase, PreviousBaseLocation, OldFloor, true);
				remainingTime = 0.f;
				break;
			}
		}
		else
		{
			if (CurrentFloor.IsWalkableFloor())
			{
				if (ShouldCatchAir(OldFloor, CurrentFloor))
				{
					HandleWalkingOffLedge(OldFloor.HitResult.ImpactNormal, OldFloor.HitResult.Normal, OldLocation, timeTick);
					if (IsMovingOnGround())
					{
						StopSlide();
						ExitSlide();
					}
					return;
				}

				AdjustFloorHeight();
				SetBase(CurrentFloor.HitResult.Component.Get(), CurrentFloor.HitResult.BoneName);
			}
			else if (CurrentFloor.HitResult.bStartPenetrating && remainingTime <= 0.f)
			{
				FHitResult Hit(CurrentFloor.HitResult);
				Hit.TraceEnd = Hit.TraceStart + FVector(0.f, 0.f, MAX_FLOOR_DIST);
				const FVector RequestedAdjustment = GetPenetrationAdjustment(Hit);
				ResolvePenetration(RequestedAdjustment, Hit, UpdatedComponent->GetComponentQuat());
				bForceNextFloorCheck = true;
			}
			if (IsSwimming())
			{
				StopSlide();
				ExitSlide();
				OnSlideStop.Broadcast();
				StartSwimming(OldLocation, Velocity, timeTick, remainingTime, Iterations);
				return;
			}
			if (!CurrentFloor.IsWalkableFloor() && !CurrentFloor.HitResult.bStartPenetrating)
			{
				const bool bMustJump = bJustTeleported || bZeroDelta || (OldBase == NULL || (!OldBase->IsQueryCollisionEnabled() && MovementBaseUtility::IsDynamicBase(OldBase)));
				if ((bMustJump || !bCheckedFall) && CheckFall(OldFloor, CurrentFloor.HitResult, Delta, OldLocation, remainingTime, timeTick, Iterations, bMustJump))
				{
					StopSlide();
					ExitSlide();
					return;
				}
				bCheckedFall = true;
			}
		}

		if (IsMovingOnGround() && bFloorWalkable)
		{
			// Make velocity reflect actual move
			if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && timeTick >= MIN_TICK_TIME)
			{
				Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / timeTick;
				MaintainHorizontalGroundVelocity();
			}
		}
		if (UpdatedComponent->GetComponentLocation() == OldLocation)
		{
			remainingTime = 0.f;
			break;
		}
	}

	FHitResult Hit;
	FQuat NewRotation = FRotationMatrix::MakeFromXZ(Velocity.GetSafeNormal2D(), FVector::UpVector).ToQuat();
	SafeMoveUpdatedComponent(FVector::ZeroVector, NewRotation, false, Hit);
}


void UNewCharacterMovementComponent::EnterSlide()
{
	if (CheckHHUpdateSlide())
	{
		Velocity += Velocity.GetSafeNormal2D() * SlideEnterImpulse;
		FindFloor(UpdatedComponent->GetComponentLocation(), CurrentFloor, true, NULL);
		HHUpdateSlide();
		Multicast_UpdateHHEnterSlide();
		SetMovementMode(MOVE_Custom, CMOVE_Slide);
		OnSlideStart.Broadcast();
	}
	else StopSlide();

}

void UNewCharacterMovementComponent::ExitSlide()
{
	if (CheckHHUpdateStopSlide())
	{
		HHUpdateStopSlide();
		Multicast_UpdateHHExitSlide();
		FQuat NewRotation = FRotationMatrix::MakeFromXZ(UpdatedComponent->GetForwardVector().GetSafeNormal2D(), FVector::UpVector).ToQuat();
		FHitResult Hit;
		SafeMoveUpdatedComponent(FVector::ZeroVector, NewRotation, true, Hit);
		SetMovementMode(MOVE_Walking);
	}
	else
	{
		SetMovementMode(MOVE_Walking);
		switch (SlideExitMovementMode)
		{
		case ESlideExitMovementMode::Crouch:
			bWantsToCrouch = true;
			break;
		case ESlideExitMovementMode::Prone:
			StartProne();
			break;
		default:
			StartProne();
			break;
		}
	}
	OnSlideStop.Broadcast();
}


bool UNewCharacterMovementComponent::CheckHHUpdateSlide()
{

	float HHAdjusted = SlideHeight - CapHH();
	FHitResult HitResult;
	FVector Loc = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (HHAdjusted + 1.0f);

	// Perform a capsule sweep to check if the space is clear for prone movement
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		Loc,
		Loc,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeCapsule(CapR(),GetSlideHalfHeight()),
		GetIgnoreCharacterParams()
	);

#if WITH_EDITOR

	if (bShowSlideDebugTraces)
	{
		// Draw debug capsule at the location
		DrawDebugCapsule(
			GetWorld(),
			Loc,
			SlideHeight,
			CapR(),
			FQuat::Identity,
			bHit ? FColor::Red : FColor::Green, // Red if hit, green if clear
			false, // Non-persistent (will disappear after duration)
			5,  // Duration (in seconds)
			0,     // Depth priority (0 is the default)
			2.0f   // Thickness of the line
		);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, 10.0f, FColor::Yellow, false, -1);
		}
	}
#endif

	// Return true if the space is clear (no blocking hit or penetration), allowing the character to be prone
	return !(HitResult.bBlockingHit || HitResult.bStartPenetrating);
}

bool UNewCharacterMovementComponent::CheckHHUpdateStopSlide()
{
	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();

	// Calculate the height adjustment to check space for exiting prone
	float HHAdjusted = DefaultCapsuleHalfHeight - CapHH();
	FHitResult HitResult;

	// Determine the location to perform the sweep
	FVector CheckLocation = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (HHAdjusted + 1.0f);

	// Perform a capsule sweep to check if the space is clear
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		CheckLocation,
		CheckLocation,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeCapsule(CapR(), DefaultCapsuleHalfHeight),
		GetIgnoreCharacterParams()
	);

#if WITH_EDITOR

	if (bShowSlideDebugTraces)
	{
		// Draw debug capsule at the CheckLocation
		DrawDebugCapsule(
			GetWorld(),
			CheckLocation,
			DefaultCapsuleHalfHeight,
			CapR(),
			FQuat::Identity,
			bHit ? FColor::Red : FColor::Green,
			false, // Non-persistent (will disappear after duration)
			5,  // Duration (in seconds)
			0,     // Depth priority (0 is the default)
			2.0f   // Thickness of the line
		);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, -1, FColor::Yellow, false, 1.0f);
		}

	}
#endif

	// Return true if the space is clear (no blocking hit or penetration), allowing the character to stop prone
	return !(HitResult.bBlockingHit || HitResult.bStartPenetrating);
}

void UNewCharacterMovementComponent::HHUpdateSlide()
{
	// Get the default character
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	FVector Updated = CharacterOwner->GetActorLocation() - CharacterOwner->GetActorUpVector() * (CapHH() - GetSlideHalfHeight());
	CharacterOwner->CacheInitialMeshOffset(CharacterOwner->GetActorUpVector() * GetSlideHalfHeight() * (-1), DefaultCharacter->GetMesh()->GetRelativeRotation());
	CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * GetSlideHalfHeight() * (-1));
	CharacterOwner->SetActorLocation(Updated);
	CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(GetSlideHalfHeight(), true);
}

void UNewCharacterMovementComponent::HHUpdateStopSlide()
{
	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	if (CapHH() != DefaultCapsuleHalfHeight)
	{
		FVector Updated = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (DefaultCapsuleHalfHeight - CapHH());
		CharacterOwner->CacheInitialMeshOffset(CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight * (-1), DefaultCharacter->GetMesh()->GetRelativeRotation());
		CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight * (-1));
		CharacterOwner->SetActorLocation(Updated);
		CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(DefaultCapsuleHalfHeight, true);
		return;
	}
}


#pragma endregion

#pragma region Dash

void UNewCharacterMovementComponent::StartDash()
{
	if (bCanDash) ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToDash);
}

void UNewCharacterMovementComponent::StopDash()
{
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToDash)) ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToDash);
}

bool UNewCharacterMovementComponent::IsDashing() const
{
	return IsCustomMovementMode(CMOVE_Dash);
}

void UNewCharacterMovementComponent::PhysDash(float deltaTime, int32 Iterations)
{
	if (deltaTime < MIN_TICK_TIME)
	{
		return;
	}

	RestorePreAdditiveRootMotionVelocity();

	// Ensure we are not using root motion and that we're dashing
	if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
	{
#if WITH_EDITOR
		if (bShowDashDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, FString::Printf(TEXT("Current Location: %s, Target Location: %s, Dash Speed: %f"), *UpdatedComponent->GetComponentLocation().ToString(), *DashLocation.ToString(), GetMaxSpeed()));
#endif
		// Calculate the distance to the target location
		FVector CurrentLocation = UpdatedComponent->GetComponentLocation();
		// Define a small threshold for comparison
		const float Epsilon = 1e-2f; // You can adjust this value as needed

		float DistanceToTarget = FVector::Dist(CurrentLocation, DashLocation);

		// If we've reached or surpassed the target location, handle dash completion
		if (DistanceToTarget <= Epsilon)
		{
			StopMovementImmediately();
			StopDash();
			return; // Exit function
		}


		// Determine how far we can move this frame based on the dash speed and deltaTime
		float MoveDistance = FMath::Min(GetMaxSpeed() * deltaTime, DistanceToTarget);

		// Calculate the direction to the target
		FVector Direction = (DashLocation - CurrentLocation).GetSafeNormal();

		// Move towards the target location
		FVector AdjustedMovement = Direction * MoveDistance;

		// Access the owning actor to set its location
		AActor* OwnerActor = GetOwner();
		if (OwnerActor)
		{
			// Set the new location
			OwnerActor->SetActorLocation(CurrentLocation + AdjustedMovement, false, nullptr, ETeleportType::TeleportPhysics);
		}

		// Optional: Update velocity after movement if you need it for further calculations
		if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
		{
			Velocity = (UpdatedComponent->GetComponentLocation() - CurrentLocation) / deltaTime;
		}
	}

	// Increment iterations and reset teleport flag
	Iterations++;
	bJustTeleported = false;
}

void UNewCharacterMovementComponent::GetDashLocation(FVector& OutTargetLocation, bool& bOutSuccess) const
{
	FVector DistStart = CharacterOwner->GetActorLocation();
	FVector Forward = GetLastInputVector() == FVector::ZeroVector ? CharacterOwner->GetActorForwardVector() : GetLastInputVector();
	FVector Up = CharacterOwner->GetActorUpVector();
	FVector DistEnd = DistStart + (DashDistance * Forward);
	float LineDistance = 50.0f; // Adjust the line trace step size as needed
	float CapsuleRadius = CapR();
	float CapsuleHalfHeight = CapHH();
	FCollisionQueryParams QueryParams = GetIgnoreCharacterParams();

	TArray<FHitResult> HitResults;
	if (bShowDashDebugTraces)
	{
		// Draw debug line for the initial trace
		DrawDebugLine(GetWorld(), DistStart, DistEnd, FColor::Blue, false, 2.0f);
	}
	FHitResult DistHit;
	bool bDistHit = GetWorld()->LineTraceSingleByProfile(
		DistHit,
		DistStart,
		DistEnd,
		TEXT("BlockAll"),
		QueryParams
	);

	if (bDistHit)
	{
		// Initial hit detected
		FVector LastHitLocator = CanDashThroughWall ? DistHit.TraceEnd : DistHit.Location;
		float FloorDist = (LastHitLocator - DistStart).Size();
		int32 FloorDistInt32 = FMath::CeilToInt(FloorDist / LineDistance);

		for (int32 Index = 0; Index < FloorDistInt32; Index++)
		{
			FVector LineStart = DistStart + (Index * LineDistance * Forward);
			FVector LineEnd = LineStart - (Up * (IsFalling() ? CapHH() * 6 : CapHH() * 12)); // Check downward

			FHitResult LineHit;
			bool bLineHit = GetWorld()->LineTraceSingleByProfile(
				LineHit,
				LineStart,
				LineEnd,
				TEXT("BlockAll"),
				QueryParams
			);

			// Draw debug line for each trace
			if (bLineHit && LineHit.bBlockingHit)
			{
				if (bShowDashDebugTraces)
				{
					DrawDebugPoint(GetWorld(), LineHit.ImpactPoint, 10, FColor::Green, false, 2.0f); // Green color for valid hits
				}
				HitResults.Add(LineHit);
			}
			if (bShowDashDebugTraces)
			{
				// Draw debug line for each trace step

				DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Yellow, false, 2.0f); // Yellow for intermediate traces
			}
		}
	}
	else
	{
		// No initial hit detected, perform additional checks
		FVector TempStart = DistStart;
		FVector TempEnd = DistEnd;
		float FloorDist = DashDistance;
		int32 FloorDistInt32 = FMath::CeilToInt(FloorDist / LineDistance);

		for (int32 Index = 0; Index < FloorDistInt32; Index++)
		{
			FVector LineStart = TempStart + (Index * LineDistance * Forward);
			FVector LineEnd = LineStart - (Up * (IsFalling() ? CapHH() * 6 : CapHH() * 12)); // Check downward

			FHitResult LineHit;
			bool bLineHit = GetWorld()->LineTraceSingleByProfile(
				LineHit,
				LineStart,
				LineEnd,
				TEXT("BlockAll"),
				QueryParams
			);

			// Draw debug line for each trace
			if (bLineHit && LineHit.bBlockingHit)
			{
				if (bShowDashDebugTraces)
				{
					DrawDebugPoint(GetWorld(), LineHit.ImpactPoint, 10, FColor::Green, false, 2.0f); // Green color for valid hits
				}
				HitResults.Add(LineHit);
			}
			if (bShowDashDebugTraces)
			{
				// Draw debug line for each trace step
				DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Orange, false, 2.0f); // Orange for additional traces
			}
		}
	}

	// Determine if a valid location was found
	if (FVector::Dist(HitResults[HitResults.Num() - 1].Location, CharacterOwner->GetActorLocation()) > DashDistance / 4)
	{
		FVector CandidateLocation = HitResults[HitResults.Num()-1].Location; // Second last valid hit
		CandidateLocation += Up * CapsuleHalfHeight * 1.7f; // Apply upward offset



		// Perform a capsule sweep at the candidate location to validate it
		FHitResult CapsuleHit;
		bool bCapsuleHit = GetWorld()->SweepSingleByProfile(
			CapsuleHit,
			CandidateLocation, // Start slightly below to account for capsule height
			CandidateLocation, // End slightly above
			FQuat::Identity,
			TEXT("BlockAll"),
			FCollisionShape::MakeCapsule(CapsuleRadius * 1.5f, CapsuleHalfHeight * 1.5f),
			QueryParams
		);

		if (!bCapsuleHit)
		{
			if (bShowDashDebugTraces)
			{
				// Draw debug capsule for the candidate location
				DrawDebugCapsule(GetWorld(),
					CandidateLocation,
					CapsuleHalfHeight * 1.5f,
					CapsuleRadius * 1.5f,
					FQuat::Identity,
					FColor::White,
					false,
					3.0f);
			}
			// If no hit, this is a valid location
			OutTargetLocation = CandidateLocation;
			bOutSuccess = true;
		}
		else
		{
			// Iterate through previous results to find a valid location if needed
			for (int32 i = HitResults.Num() - 1; i >= 0; i--)
			{
				FVector RetryLocation = HitResults[i].Location + Up * CapsuleHalfHeight * 1.7f;
				FHitResult RetryHit;
				bool bRetryCapsuleHit = GetWorld()->SweepSingleByProfile(
					RetryHit,
					RetryLocation,
					RetryLocation,
					FQuat::Identity,
					TEXT("BlockAll"),
					FCollisionShape::MakeCapsule(CapsuleRadius * 1.5f, CapsuleHalfHeight * 1.5f),
					QueryParams
				);

				if (!bRetryCapsuleHit)
				{
					if (bShowDashDebugTraces)
					{
						// Draw debug capsule for the candidate location
						DrawDebugCapsule(GetWorld(),
							RetryLocation,
							CapsuleHalfHeight * 1.5f,
							CapsuleRadius * 1.5f,
							FQuat::Identity,
							FColor::White,
							false,
							3.0f);
					}
					OutTargetLocation = RetryLocation;
					bOutSuccess = true;
					HitResults.Empty(); // Clear the array before returning
					return;
				}
			}

			// No valid location found
			OutTargetLocation = FVector::ZeroVector; // Or some default value
			bOutSuccess = false;
		}
	}
	else
	{
		OutTargetLocation = FVector::ZeroVector; // Or some default value
		bOutSuccess = false;
	}

	HitResults.Empty(); // Clear the array before exiting
}

#pragma endregion

#pragma region WallRun

void UNewCharacterMovementComponent::StartWallRun()
{
	if (bCanWallRun) ActivateSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_WantsToWallRun);

}

void UNewCharacterMovementComponent::StopWallRun()
{
	ClearSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_WantsToWallRun);
}


void UNewCharacterMovementComponent::StopVerticleWallRun()
{
	ClearSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_WantsToVerticleWallRun);
}

bool UNewCharacterMovementComponent::CanWallRun()
{
	if (!CharacterOwner || !IsFalling() || IsMovingOnGround() || IsClimbing()) return false;

	if (Velocity.SizeSquared2D() < FMath::Square(MinWallRunSpeed)) return false;

	FVector ProjectedVelocity;
	FVector Location = CharacterOwner->GetActorLocation();
	FVector Upward = CharacterOwner->GetActorUpVector();
	FVector AdjustedLocation = FVector(Location.X, Location.Y, (Location.Z - CapHH()));
	FVector AdjustedLocationDist = FVector(Location.X, Location.Y, (Location.Z + CapHH()));
	FVector FinalAdjustedLocation = FVector(AdjustedLocation.X, AdjustedLocation.Y, (AdjustedLocation.Z + MaxStepHeight));
	FVector FinalAdjustedLocationDist = FVector(AdjustedLocationDist.X, AdjustedLocationDist.Y, (AdjustedLocationDist.Z - MaxStepHeight));
	FVector Right = CharacterOwner->GetActorRightVector();
	float Dist = FVector::Dist(FinalAdjustedLocation, FinalAdjustedLocationDist);
#if WITH_EDITOR

	if (bShowWallRunDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Required Clearance: %f"), Dist));

#endif
	int32 StepValue = 10;
	int32 Height = FMath::CeilToInt(Dist / StepValue); // Number of steps

	FVector Start = FinalAdjustedLocation;


	auto Params = GetIgnoreCharacterParams();

	FHitResult FloorHit;
	FName CollisionProfileName(TEXT("BlockAll"));

	// Check below the character for ground detection
	if (GetWorld()->SweepSingleByProfile(FloorHit, Start, Start + FVector(0, 0, -1) * MinWallRunHeight, FQuat::Identity, CollisionProfileName, FCollisionShape::MakeSphere(CapR()), Params))
	{
#if WITH_EDITOR
		if (bShowWallRunDebugTraces) DrawDebugLine(GetWorld(), Start, Start + FVector(0, 0, -1) * MinWallRunHeight, FColor::Red, false, 2.0f, 12);
		if (bShowWallRunDebugTraces) if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Not Enough Height")));

#endif
		return false;
	}
#if WITH_EDITOR
	if (bShowWallRunDebugTraces) if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("NotHit,%d"), __LINE__));
#endif
	FHitResult WallHitR;
	FHitResult WallHitL;
	bool bLeftWallDetected = false;
	bool bRightWallDetected = false;


	for (int32 Index = 0; Index < Height; ++Index)
	{
		FVector NewStartR = AdjustedLocation + Upward * Index * StepValue;

		FVector RightEnd = NewStartR + Right * CapR() * 4;
		// Check right side for wall
		if (GetWorld()->SweepSingleByProfile(WallHitR, NewStartR, RightEnd, FQuat::Identity, CollisionProfileName, FCollisionShape::MakeSphere(CapR() / 2.0f), Params))
		{
#if WITH_EDITOR
			if (bShowWallRunDebugTraces) DrawDebugLine(GetWorld(), NewStartR, RightEnd, FColor::Blue, false, 2.0f);
#endif

			if (!(WallHitR.IsValidBlockingHit() /**/ && FVector::DotProduct(Velocity, WallHitR.Normal) < 0))
			{
#if WITH_EDITOR
				if (bShowWallRunDebugTraces) if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Unable To Do Right Side:%d"), __LINE__));
#endif
				break;
			}
		}
		ActivateSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_RightWall);
		SetWallInfo(EWallSide::Right, WallHitR);
		bRightWallDetected = true;
	}


	for (int32 Index = 0; Index < Height; ++Index)
	{
		FVector NewStartL = AdjustedLocation + Upward * Index * StepValue;
		FVector LeftEnd = NewStartL - Right * CapR() * 4;
		// Check left side for wall
		if (GetWorld()->SweepSingleByProfile(WallHitL, NewStartL, LeftEnd, FQuat::Identity, CollisionProfileName, FCollisionShape::MakeSphere(CapR() / 2.0f), Params))
		{
#if WITH_EDITOR
			if (bShowWallRunDebugTraces) DrawDebugLine(GetWorld(), NewStartL, LeftEnd, FColor::Blue, false, 2.0f);
#endif

			if (!(WallHitL.IsValidBlockingHit() /**/ && FVector::DotProduct(Velocity, WallHitL.Normal) < 0))
			{
#if WITH_EDITOR
				if (bShowWallRunDebugTraces) if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Unable To Do Left Side:%d"), __LINE__));
#endif
				break;
			}
		}
		ClearSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_RightWall);
		SetWallInfo(EWallSide::Left, WallHitL);
		bLeftWallDetected = true;
	}


	if (!bLeftWallDetected && !bRightWallDetected)
	{
#if WITH_EDITOR
		if (bShowWallRunDebugTraces) if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Unable To Do Any,%d"), __LINE__));
#endif
		SetWallInfo(EWallSide::None, FHitResult());
		return false;
	}

	ProjectedVelocity = FVector::VectorPlaneProject(Velocity, IsWallRunOnRightSide() ? WallHitR.Normal : WallHitL.Normal);
	if (ProjectedVelocity.SizeSquared2D() < FMath::Square(MinWallRunSpeed))
	{
#if WITH_EDITOR
		if (bShowWallRunDebugTraces) if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Unable To Do Any,%d"), __LINE__));
#endif
		return false;
	}

	Velocity = ProjectedVelocity;
	//Velocity.Z = FMath::Clamp(Velocity.Z, 0.f, MaxVerticalWallRunSpeed);
#if WITH_EDITOR
	if (bShowWallRunDebugTraces) if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("%s"), IsSpecialFlagActive((uint8)ESpecialMovementFlag::CFLAG_RightWall) ? TEXT("Right Wall") : TEXT("Left Wall")));
#endif

	return true;
}

bool UNewCharacterMovementComponent::IsWallRunning() const
{
	return IsCustomMovementMode(CMOVE_WallRun);
}

bool UNewCharacterMovementComponent::IsWallRunOnRightSide() const
{
	return IsSpecialFlagActive((uint8)ESpecialMovementFlag::CFLAG_RightWall);
}

void UNewCharacterMovementComponent::PhysWallRun(float DeltaTime, int32 Iterations)
{
	if (DeltaTime < MIN_TICK_TIME)
	{
		return;
#if WITH_EDITOR
		if (GEngine && bShowWallRunDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Exiting: %d"), __LINE__));
#endif
	}
	if (!CharacterOwner || (!CharacterOwner->Controller && !bRunPhysicsWithNoController && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && (CharacterOwner->GetLocalRole() != ROLE_SimulatedProxy)))
	{
		Acceleration = FVector::ZeroVector;
		Velocity = FVector::ZeroVector;
#if WITH_EDITOR
		if (GEngine && bShowWallRunDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Exiting: %d"), __LINE__));
#endif
		return;
	}

	bJustTeleported = false;
	float remainingTime = DeltaTime;

	// Main movement logic
	while ((remainingTime >= MIN_TICK_TIME) && (Iterations < MaxSimulationIterations) && CharacterOwner && (CharacterOwner->Controller || bRunPhysicsWithNoController || (CharacterOwner->GetLocalRole() == ROLE_SimulatedProxy)))
	{
		Iterations++;
		bJustTeleported = false;
		const float timeTick = GetSimulationTimeStep(remainingTime, Iterations);
		remainingTime -= timeTick;
		const FVector OldLocation = UpdatedComponent->GetComponentLocation();
		FVector Start = UpdatedComponent->GetComponentLocation();
		FVector CastDelta = UpdatedComponent->GetRightVector() * CapR() * 2;
		FVector EndR = Start + CastDelta;
		FVector EndL = Start - CastDelta;
		auto Params = GetIgnoreCharacterParams();
		float SinPullAwayAngle = FMath::Sin(FMath::DegreesToRadians(WallRunPullAwayAngle));
		FHitResult WallHit;
		FHitResult WallHitRight;
		FHitResult WallHitLeft;

#if WITH_EDITOR
		if (bShowWallRunDebugTraces)
		{
			// Draw debug lines for the traces
			DrawDebugLine(GetWorld(), Start, EndR, FColor::Red, false, -1, 0, 1);
			DrawDebugLine(GetWorld(), Start, EndL, FColor::Blue, false, -1, 0, 1);
		}
#endif
		if (IsWallRunOnRightSide())
		{
			// First, try a line trace to the right.
			GetWorld()->LineTraceSingleByProfile(WallHitRight, Start, EndR, "BlockAll", Params);
			bool bWantsToPullAwayRight = WallHitRight.IsValidBlockingHit() && !Acceleration.IsNearlyZero() && (Acceleration.GetSafeNormal() | WallHitRight.Normal) > SinPullAwayAngle;

			if (WallHitRight.IsValidBlockingHit() && !bWantsToPullAwayRight)
			{
				WallHit = WallHitRight;
				SetWallInfo(EWallSide::Right, WallHitRight);
			}
			else
			{
				// If the right trace doesn't hit or we want to pull away, try a line trace to the left.
				GetWorld()->LineTraceSingleByProfile(WallHitLeft, Start, EndL, "BlockAll", Params);
				bool bWantsToPullAwayLeft = WallHitLeft.IsValidBlockingHit() && !Acceleration.IsNearlyZero() && (Acceleration.GetSafeNormal() | WallHitLeft.Normal) > SinPullAwayAngle;

				if (WallHitLeft.IsValidBlockingHit() && !bWantsToPullAwayLeft)
				{
					WallHit = WallHitLeft;
					SetWallInfo(EWallSide::Left, WallHitLeft);
				}
				else
				{
					// If neither trace hits or we want to pull away, transition to falling mode.
					StopWallRun();
#if WITH_EDITOR
					if (GEngine && bShowWallRunDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Exiting: %d"), __LINE__));
#endif
					SetMovementMode(MOVE_Falling);
					StartNewPhysics(remainingTime, Iterations);
					return;
				}
			}
		}
		else
		{
			// First, try a line trace to the right.
			GetWorld()->LineTraceSingleByProfile(WallHitLeft, Start, EndL, "BlockAll", Params);
			bool bWantsToPullAwayRight = WallHitLeft.IsValidBlockingHit() && !Acceleration.IsNearlyZero() && (Acceleration.GetSafeNormal() | WallHitLeft.Normal) > SinPullAwayAngle;

			if (WallHitLeft.IsValidBlockingHit() && !bWantsToPullAwayRight)
			{
				WallHit = WallHitLeft;
				SetWallInfo(EWallSide::Left, WallHitLeft);
			}
			else
			{
				// If the right trace doesn't hit or we want to pull away, try a line trace to the left.
				GetWorld()->LineTraceSingleByProfile(WallHitRight, Start, EndR, "BlockAll", Params);
				bool bWantsToPullAwayLeft = WallHitRight.IsValidBlockingHit() && !Acceleration.IsNearlyZero() && (Acceleration.GetSafeNormal() | WallHitRight.Normal) > SinPullAwayAngle;

				if (WallHitRight.IsValidBlockingHit() && !bWantsToPullAwayLeft)
				{
					WallHit = WallHitRight;
					SetWallInfo(EWallSide::Right, WallHitRight);
				}
				else
				{
					// If neither trace hits or we want to pull away, transition to falling mode.
					StopWallRun();
#if WITH_EDITOR
					if (GEngine && bShowWallRunDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Exiting: %d"), __LINE__));
#endif
					SetMovementMode(MOVE_Falling);
					StartNewPhysics(remainingTime, Iterations);
					return;
				}
			}
		}
		// Clamp Acceleration
		Acceleration = FVector::VectorPlaneProject(Acceleration, WallHit.Normal);
		Acceleration.Z = 0.f;
		// Apply acceleration
		CalcVelocity(timeTick, 0.f, false, GetMaxBrakingDeceleration());
		Velocity = FVector::VectorPlaneProject(Velocity, WallHit.Normal);
		float TangentAccel = Acceleration.GetSafeNormal() | Velocity.GetSafeNormal2D();
		bool bVelUp = Velocity.Z > 0.f;
		float WallRunGravityScale = FMath::Lerp(MaxWallRunGravityScale, MinWallRunGravityScale, bVelUp ? 0.f : TangentAccel);

		// Apply Vertical Wall Run Speed if bCanVerticalWallRun is true
		if (IsSpecialFlagActive((uint8)ESpecialMovementFlag::CFLAG_WantsToVerticleWallRun))
		{
			// Increase vertical velocity smoothly
			float VerticalSpeed = FMath::Lerp(Velocity.Z, MaxVerticalWallRunSpeed, timeTick * WallRunGravityScale);
			Velocity.Z = FMath::Clamp(VerticalSpeed, 0.f, MaxVerticalWallRunSpeed);
		}
		else  
			Velocity.Z += GetGravityZ() * WallRunGravityScale * timeTick;

		
		if (Velocity.SizeSquared2D() < pow(MinWallRunSpeed, 2) || Velocity.Z < -MaxVerticalWallRunSpeed)
		{
			StopWallRun();
			SetMovementMode(MOVE_Falling);
			StartNewPhysics(remainingTime, Iterations);
			OnWallRunStop.Broadcast();
#if WITH_EDITOR
			if (GEngine && bShowWallRunDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Exiting: %d"), __LINE__));
#endif
			return;
		}
		const FVector Delta = timeTick * Velocity;
		const bool bZeroDelta = Delta.IsNearlyZero();
		if (bZeroDelta)
		{
			remainingTime = 0.f;
		}
		else
		{
			FHitResult Hit;
			SafeMoveUpdatedComponent(Delta, UpdatedComponent->GetComponentQuat(), true, Hit);
			FVector WallAttractionDelta = -WallHit.Normal * WallAttractionForce * timeTick;
			SafeMoveUpdatedComponent(WallAttractionDelta, UpdatedComponent->GetComponentQuat(), true, Hit);
		}
		if (UpdatedComponent->GetComponentLocation() == OldLocation)
		{
			remainingTime = 0.f;
			break;
		}
		Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / timeTick;
	}

	FVector Start = CharacterOwner->GetActorLocation();
	FVector CastDelta = CharacterOwner->GetActorRightVector() * CapR() * 2;
	FVector Forward = CharacterOwner->GetActorForwardVector() * CapR();
	FVector Downward = CharacterOwner->GetActorUpVector() * -1;
	FVector EndR = Start + CastDelta;
	FVector EndL = Start - CastDelta;
	FVector EndF = Start + Forward;
	FVector EndD = Start + Downward * (CapHH() + MinWallRunHeight * 0.5f);
	auto Params = GetIgnoreCharacterParams();
	FHitResult FloorHit, WallHitRight, WallHitLeft, WallHit, ForwardHit;

#if WITH_EDITOR
	if (bShowWallRunDebugTraces)
	{
		// Draw debug lines for the floor and wall traces
		DrawDebugLine(GetWorld(), Start, EndR, FColor::Green, false, -1, 0, 1);
		DrawDebugLine(GetWorld(), Start, EndL, FColor::Yellow, false, -1, 0, 1);
		DrawDebugLine(GetWorld(), Start, EndD, FColor::Cyan, false, -1, 0, 1);
	}
#endif

	FRotator FinalRotator;
	if (IsWallRunOnRightSide())
	{
		// Perform the right line trace.
		GetWorld()->LineTraceSingleByProfile(WallHitRight, Start, EndR, "BlockAll", Params);

		// If the right trace doesn't hit, perform the left line trace.
		if (WallHitRight.IsValidBlockingHit())
		{
			// We hit a wall on the right side, set WallHit to WallHitRight
			WallHit = WallHitRight;

			SetWallInfo(EWallSide::Right, WallHit);

			// Get the impact normal and calculate the desired forward direction
			FVector HitNormal = -WallHitRight.Normal;
			FRotator XRotator = UKismetMathLibrary::MakeRotFromX(HitNormal);
			FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 90.0f, 0.0f));

			// Set the new rotation
			CharacterOwner->SetActorRotation(FinalRotator);
		}
		else
		{
			// Perform the line trace to the left
			GetWorld()->LineTraceSingleByProfile(WallHitLeft, Start, EndL, "BlockAll", Params);

			if (WallHitLeft.IsValidBlockingHit())
			{
				// We hit a wall on the left side, set WallHit to WallHitLeft
				WallHit = WallHitLeft;
				SetWallInfo(EWallSide::Left, WallHit);

				// Get the impact normal and calculate the desired forward direction
				FVector HitNormal = WallHitLeft.Normal;
				FRotator XRotator = UKismetMathLibrary::MakeRotFromX(HitNormal);
				FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 90.0f, 0.0f));

				// Set the new rotation
				CharacterOwner->SetActorRotation(FinalRotator);
				ClearSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_RightWall);
			}
		}
	}
	else
	{
		// Perform the right line trace.
		GetWorld()->LineTraceSingleByProfile(WallHitLeft, Start, EndL, "BlockAll", Params);

		// If the right trace doesn't hit, perform the left line trace.
		if (WallHitLeft.IsValidBlockingHit())
		{
			// We hit a wall on the right side, set WallHit to WallHitRight
			WallHit = WallHitLeft;

			SetWallInfo(EWallSide::Left, WallHit);

			// Get the impact normal and calculate the desired forward direction
			FVector HitNormal = WallHitLeft.Normal;
			FRotator XRotator = UKismetMathLibrary::MakeRotFromX(HitNormal);
			FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 90.0f, 0.0f));

			// Set the new rotation
			CharacterOwner->SetActorRotation(FinalRotator);
		}
		else
		{
			// Perform the line trace to the left
			GetWorld()->LineTraceSingleByProfile(WallHitRight, Start, EndR, "BlockAll", Params);

			if (WallHitRight.IsValidBlockingHit())
			{
				// We hit a wall on the left side, set WallHit to WallHitLeft
				WallHit = WallHitRight;

				SetWallInfo(EWallSide::Right, WallHit);

				// Get the impact normal and calculate the desired forward direction
				FVector HitNormal = -WallHitRight.Normal;
				FRotator XRotator = UKismetMathLibrary::MakeRotFromX(HitNormal);
				FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 90.0f, 0.0f));

				// Set the new rotation
				CharacterOwner->SetActorRotation(FinalRotator);
				ActivateSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_RightWall);

			}
		}
	}



	if (CharacterOwner->GetActorRotation() == FinalRotator)
	{
		GetWorld()->SweepSingleByProfile(ForwardHit, Start, EndF, FQuat::Identity, "BlockAll", FCollisionShape::MakeCapsule(CapR() / 1.1f, CapHH()), Params);
		GetWorld()->LineTraceSingleByProfile(FloorHit, Start, EndD, "BlockAll", Params);


#if WITH_EDITOR
		if (bShowWallRunDebugTraces)
		{
			DrawDebugLine(GetWorld(), Start, EndF, FColor::Purple, false, -1, 0, 1);
			DrawDebugCapsule(GetWorld(), Start, CapHH(), CapR() / 1.1f, FQuat::Identity, FColor::Purple, false, -1, 0, 1);
			DrawDebugCapsule(GetWorld(), EndF, CapHH(), CapR() / 1.1f, FQuat::Identity, FColor::Purple, false, -1, 0, 1);
		}
#endif

		// Check conditions for falling.
		if (FloorHit.IsValidBlockingHit() || ForwardHit.IsValidBlockingHit())
		{
			StopWallRun();
			SetMovementMode(MOVE_Walking);
			StartNewPhysics(remainingTime, Iterations);
#if WITH_EDITOR
			if (GEngine && bShowWallRunDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Exiting: %d"), __LINE__));
#endif
			return;
		}
	}
	if (!WallHit.IsValidBlockingHit() || (Velocity.SizeSquared2D() < FMath::Square(MinWallRunSpeed)))
	{
		StopWallRun();
		SetMovementMode(MOVE_Walking);
		StartNewPhysics(remainingTime, Iterations);
#if WITH_EDITOR
		if (GEngine && bShowWallRunDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Exiting: %d"), __LINE__));
#endif
		return;
	}

}

#pragma endregion

#pragma region Climb

void UNewCharacterMovementComponent::StartClimb()
{
	if (bCanClimb) ActivateSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_WantsToClimb);
}

void UNewCharacterMovementComponent::StopClimb()
{
	ClearSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_WantsToClimb);
}

bool UNewCharacterMovementComponent::IsClimbing() const
{
	return IsCustomMovementMode(CMOVE_Climb);
}

bool UNewCharacterMovementComponent::CanClimb()
{
	return CanStartClimbing();
}

bool UNewCharacterMovementComponent::CanStartClimbing()
{
	if (!SufficientClimbHeight() || !TraceClimbableSurfaces() || IsWallRunning()) return false;
	return true;
}

bool UNewCharacterMovementComponent::CanClimbInCurrentState() const
{
	return IsMovementMode(MOVE_Walking) || IsMovementMode(MOVE_Falling) || IsMovementMode(MOVE_Flying);
}

bool UNewCharacterMovementComponent::SufficientClimbHeight()
{
	FVector Location = CharacterOwner->GetActorLocation();
	float CapsuleHalfHeight = CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	// Adjust the Z component of Location
	FVector AdjustedLocation = FVector(Location.X, Location.Y, Location.Z - CapsuleHalfHeight / 1.1);

	FVector Forward = CharacterOwner->GetActorForwardVector();
	FVector Upward = CharacterOwner->GetActorUpVector();

	// Convert MinClimbHeight to int32 and calculate number of steps
	int32 StepValue = 10;
	int32 Dist = FMath::CeilToInt(MinClimbHeight / StepValue); // Use CeilToInt to ensure enough steps

	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("ClimbTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true; // Can trace complex collisions if needed

	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : ClimbableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	// Loop through each step
	for (int32 Index = 0; Index < Dist; ++Index)
	{
		FVector Start = AdjustedLocation + Upward * StepValue * Index;
		FVector End = Start + Forward * MaxClimbDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams, // Assuming climbing surfaces are static
			TraceParams
		);
#if WITH_EDITOR
		if (bShowClimbDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, -1, 0, 1);
#endif


		// If any trace does not hit or no valid blocking hit, return false
		if (!bHit || !HitResult.IsValidBlockingHit())
		{
			return false;
		}
	}

	// If all traces hit, return true
	return true;
}


bool UNewCharacterMovementComponent::TraceClimbableSurfaces()
{
	const FVector Start = UpdatedComponent->GetComponentLocation() + (CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius() * UpdatedComponent->GetForwardVector());

	FCollisionQueryParams QueryParams = GetIgnoreCharacterParams();

	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : ClimbableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}
	if (bUseSpecificClimbSurface) GetWorld()->SweepMultiByObjectType(
		ClimbSurfaceTracedResult,
		Start,
		Start,
		FQuat::Identity,
		ObjectQueryParams,
		FCollisionShape::MakeCapsule(CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius() * 2, CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight()),
		QueryParams
	);
	else
		GetWorld()->SweepMultiByProfile(
			ClimbSurfaceTracedResult,
			Start,
			Start,
			FQuat::Identity,
			TEXT("BlockAll"), // Use the "BlockAll" collision profile
			FCollisionShape::MakeCapsule(CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius() * 2, CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight()),
			QueryParams
		);

#if WITH_EDITOR
	if (bShowClimbDebugTraces)
	{
		// Draw the capsule for visualization
		DrawDebugCapsule(
			GetWorld(),
			Start,
			CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight(),
			CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius() * 2,
			FQuat::Identity,
			FColor::Blue,
			false,
			-1
		);


		// Iterate through the results and draw the impact points
		for (const FHitResult& Hit : ClimbSurfaceTracedResult)
		{
			// Draw a red point at the impact location
			DrawDebugPoint(
				GetWorld(),
				Hit.ImpactPoint,
				10.0f,
				FColor::Red,
				false,
				-1
			);
		}
	}
#endif

	if (!ClimbSurfaceTracedResult.IsEmpty())SetWallInfo(EWallSide::Front, ClimbSurfaceTracedResult[ClimbSurfaceTracedResult.Num() - 1]);

	return !ClimbSurfaceTracedResult.IsEmpty();
}

void UNewCharacterMovementComponent::ProcessClimbableSurfaceInfo()
{
	CurrentClimbableSurfaceLocation = FVector::ZeroVector;
	CurrentClimbableSurfaceNormal = FVector::ZeroVector;

	if (ClimbSurfaceTracedResult.IsEmpty()) return;

	for (const FHitResult& TracedHitResult : ClimbSurfaceTracedResult)
	{
		// Accumulate the impact points and normals
		CurrentClimbableSurfaceLocation += TracedHitResult.ImpactPoint;
		CurrentClimbableSurfaceNormal += TracedHitResult.ImpactNormal;
#if WITH_EDITOR
		// Show debug traces if enabled
		if (bShowClimbDebugTraces)
		{
			// Draw a point at the impact location
			DrawDebugPoint(GetWorld(), TracedHitResult.ImpactPoint, 10.0f, FColor::Green, false, -1);

			// Draw a line indicating the normal at the impact point
			DrawDebugLine(GetWorld(), TracedHitResult.ImpactPoint, TracedHitResult.ImpactPoint + (TracedHitResult.ImpactNormal * 50.0f), FColor::Blue, false, -1, 0, 2.0f);
		}
#endif
	}


	// Average the surface location and normalize the surface normal
	CurrentClimbableSurfaceLocation /= ClimbSurfaceTracedResult.Num();
	CurrentClimbableSurfaceNormal = CurrentClimbableSurfaceNormal.GetSafeNormal();
#if WITH_EDITOR
	// Optionally, show debug info for the averaged location and normal
	if (bShowClimbDebugTraces)
	{
		// Draw a point for the averaged climbable surface location
		DrawDebugPoint(GetWorld(), CurrentClimbableSurfaceLocation, 0.0f, FColor::Red, false, -1);

		// Draw a line representing the average normal
		DrawDebugLine(GetWorld(), CurrentClimbableSurfaceLocation,
			CurrentClimbableSurfaceLocation + (CurrentClimbableSurfaceNormal * 100.0f),
			FColor::Yellow, false, -1, 0, 3.0f);
	}
#endif
	FHitResult& LastHitResult = ClimbSurfaceTracedResult.Last();

	// Update the Location and Normal with the averaged values
	//LastHitResult.Location = CurrentClimbableSurfaceLocation; // Set the new averaged location
	LastHitResult.Normal = CurrentClimbableSurfaceNormal; // Set the new averaged normal

	// Set the wall info with the modified hit result
	SetWallInfo(EWallSide::Front, LastHitResult);
}

bool UNewCharacterMovementComponent::HasReachedUpLedge()
{

	// Clear previous warp targets
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();

	// Validate if the character is in walking or falling mode and moving upwards
	if (!IsMovementMode(MOVE_Walking) && !IsFalling())
		if (GetUnrotatedClimbVelocity().Z <= 0.0f)
			return false;

	// Define the starting location for the forward trace at the character's eye height
	FVector StartLocation = UpdatedComponent->GetComponentLocation() + (UpdatedComponent->GetUpVector() * CharacterOwner->BaseEyeHeight);

	// Get the character's forward direction
	FVector ForwardDirection = CharacterOwner->GetActorForwardVector();

	// Set the endpoint for the forward trace
	FVector EndLocation = StartLocation + (ForwardDirection * 100.0f); // Adjust distance as needed

	// Perform a forward line trace to detect if there's a surface ahead
	FHitResult ForwardHitResult;
	FCollisionQueryParams TraceParams(FName(TEXT("FallingLedgeTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true; // Enable complex collision tracing if required

	// Define object query parameters for climbing surfaces
	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : MantlableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	bool bForwardHit = GetWorld()->LineTraceSingleByObjectType(
		ForwardHitResult,
		StartLocation,
		EndLocation,
		ObjectQueryParams,
		TraceParams
	);




#if WITH_EDITOR
	// Draw debug lines for visualizing the traces if debug mode is enabled
	if (bShowMantleDebugTraces)
	{
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, false, -1, 0, 1); // Forward trace
	}
#endif

	// If a forward hit is detected, proceed with further checks
	if (bForwardHit)
	{
		// Determine the average position and normal from the forward hit
		const FVector NewLocMant = ForwardHitResult.Location;
		FVector AVG = (NewLocMant + StartLocation) / 2.0f;
		FVector Norm = -ForwardHitResult.Normal;

		// Calculate rotation based on the normal of the hit surface
		FRotator XRotator = UKismetMathLibrary::MakeRotFromX(-Norm);
		FRotator FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 180.0f, 0.0f));
		WarpTargetRotations.Add(FinalRotator);

		// Define the endpoint for a normal check
		FVector EndNorm = AVG + Norm * MantleDistance;
		FHitResult NormForwardHitResult;

		// Perform a trace to check for valid mantle surface
		bool bNormForwardHit = GetWorld()->LineTraceSingleByProfile(
			NormForwardHitResult,
			AVG,
			EndNorm,
			"BlockAll",
			TraceParams
		);

#if WITH_EDITOR
		// Draw debug line for normal check if debug mode is enabled
		if (bShowClimbDebugTraces)
		{
			DrawDebugLine(GetWorld(), AVG, EndNorm, FColor::Green, false, -1, 0, 1); // Forward trace
		}
#endif

		if (bNormForwardHit)
		{
			// Store the valid warp location
			FVector WarpOne = NormForwardHitResult.Location;
			WarpTargetLocations.Add(WarpOne);

#if WITH_EDITOR
			if (bShowClimbDebugTraces)
				DrawDebugSphere(GetWorld(), WarpOne, 10.0f, 12, FColor::White, false, -1, 0, 1);
#endif

			// Setup new start location for a capsule sweep check
			const FVector UpWard = CharacterOwner->GetActorUpVector();
			const FVector NewStartMant = WarpOne + Norm * CapR() * 1.5 + UpWard * CapHH() * 1.1;
			FHitResult CapHitResult;

			// Perform a capsule sweep to ensure no obstructions
			bool bMantleCapsuleHit = GetWorld()->SweepSingleByProfile(
				CapHitResult,
				NewStartMant,
				NewStartMant,
				FQuat::Identity,
				"BlockAll",
				FCollisionShape::MakeCapsule(CapR(), CapHH())
			);

#if WITH_EDITOR
			if (bShowClimbDebugTraces)
			{
				DrawDebugCapsule(GetWorld(), NewStartMant, CapHH(), CapR(), FQuat::Identity, FColor::Magenta, false, -1, 0, 1);
			}
#endif

			// If no hit or not penetrating, proceed to final check
			if (!CapHitResult.bBlockingHit || !CapHitResult.bStartPenetrating)
			{
				const FVector FinalCheck = NewStartMant;
				FVector FinalCheckEnd = NewStartMant - UpWard * CapHH() * 2.0f;
				FHitResult FinalHitResult;

				bool bFinalHit = GetWorld()->LineTraceSingleByProfile(
					FinalHitResult,
					FinalCheck,
					FinalCheckEnd,
					"BlockAll",
					TraceParams
				);

				// If the final trace is valid, add to warp locations and confirm ledge detection
				if (bFinalHit)
				{
#if WITH_EDITOR
					if (bShowMantleDebugTraces)
						DrawDebugSphere(GetWorld(), FinalHitResult.Location, 10.0f, 12, FColor::White, false, -1, 0, 1);
#endif
					WarpTargetLocations.Add(FinalHitResult.Location);
					return true;
				}
			}
		}
	}

	// Clear warp targets if no valid ledge is detected
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();
	return false;
}

bool UNewCharacterMovementComponent::HasReachedFloor()
{
	const FVector DownVector = UpdatedComponent->GetUpVector() * -1;
	const FVector StartOffset = DownVector * CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	const FVector Start = UpdatedComponent->GetComponentLocation() + StartOffset;
	const FVector End = Start + DownVector * 100.0f; // Trace downwards 100 units

	if (Velocity.Z > -1.0f) return false;

	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : ClimbableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	/*TArray<FHitResult> PossibleFloorHits;
	GetWorld()->SweepMultiByObjectType(
		PossibleFloorHits,
		Start,
		End,
		FQuat::Identity,
		ObjectQueryParams,
		FCollisionShape::MakeCapsule(CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius(), CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight())
	);*/
	TArray<FHitResult> PossibleFloorHits;
	GetWorld()->SweepMultiByProfile(
		PossibleFloorHits,
		Start,
		End,
		FQuat::Identity,
		TEXT("BlockAll"), // Use the "BlockAll" collision profile
		FCollisionShape::MakeCapsule(CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius(), CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight())
	);

#if WITH_EDITOR
	// Debug draw the sweep
	if (bShowClimbDebugTraces)
	{
		DrawDebugCapsule(GetWorld(), Start, CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight(), CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius(), FQuat::Identity, FColor::Green, false, 0.0f);
		DrawDebugCapsule(GetWorld(), End, CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight(), CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius(), FQuat::Identity, FColor::Red, false, 0.0f);
	}
#endif

	if (PossibleFloorHits.IsEmpty()) return false;

	for (const FHitResult& PossibleFloorHit : PossibleFloorHits)
	{
		const bool bFloorReached = FVector::Parallel(-PossibleFloorHit.ImpactNormal, FVector::UpVector);

		if (bFloorReached)
		{
#if WITH_EDITOR
			if (bShowClimbDebugTraces)
			{
				DrawDebugPoint(GetWorld(), PossibleFloorHit.ImpactPoint, 10.0f, FColor::Blue, false, 1.0f);
				DrawDebugLine(GetWorld(), PossibleFloorHit.ImpactPoint, PossibleFloorHit.ImpactPoint + PossibleFloorHit.ImpactNormal * 50.0f, FColor::Cyan, false, 1.0f, 0, 2.0f);
			}
#endif

			return true;
		}
	}
	return false;
}

FVector UNewCharacterMovementComponent::GetUnrotatedClimbVelocity() const
{
	return UKismetMathLibrary::Quat_UnrotateVector(UpdatedComponent->GetComponentQuat(), Velocity);
}

bool UNewCharacterMovementComponent::ShouldStopClimbing()
{

	// If there are no climbable surfaces, stop climbing
	if (ClimbSurfaceTracedResult.IsEmpty()) return true;
	const float DotResultUp = FVector::DotProduct(CurrentClimbableSurfaceNormal, FVector::UpVector);
	const float DotSide = FVector::DotProduct(CurrentClimbableSurfaceNormal, CharacterOwner->GetActorRightVector());
	float DegreeDiffUp = FMath::RadiansToDegrees(FMath::Acos(DotResultUp));
	float DegreeSide = FMath::RadiansToDegrees(FMath::Acos(FMath::Clamp(DotSide, -1.0f, 1.0f)));
	if (DegreeSide > 90.0f) DegreeSide = 180.0f - DegreeSide;
	if (DegreeDiffUp > 90.0f) DegreeDiffUp = 180.0f - DegreeDiffUp;
#if WITH_EDITOR
	// Print both angle differences to the screen
	if (GEngine && bShowClimbDebugTraces)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, FString::Printf(TEXT("DegreeDiffUp: %f"), DegreeDiffUp));
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, FString::Printf(TEXT("DegreeDiffSide: %f"), DegreeSide));

	}
#endif

	// Check angle difference 
	if (DegreeDiffUp < MinClimbAngleUpwards || DegreeSide < MinClimbAngleSideWays) return true;
	//ClimbSurfaceTracedResult.RemoveAt(ClimbSurfaceTracedResult.Num() - 1);
	return false;
}

FQuat UNewCharacterMovementComponent::GetClimbRotation(float deltaTime)
{
	FQuat CurrentQuat = UpdatedComponent->GetComponentQuat();
	if (HasAnimRootMotion() || CurrentRootMotion.HasOverrideVelocity())
	{
		return CurrentQuat;
	}

	FQuat TargetQuat = FRotationMatrix::MakeFromX(-CurrentClimbableSurfaceNormal).ToQuat();

	return FMath::QInterpTo(CurrentQuat, TargetQuat, deltaTime, 5.0f);
}

void UNewCharacterMovementComponent::UpdateClimbSurface(float deltaTime)
{
	const FVector ComponentForward = UpdatedComponent->GetForwardVector();
	const FVector ComponentLocation = UpdatedComponent->GetComponentLocation();

	const FVector ProjectedComponentToSurface = (CurrentClimbableSurfaceLocation - ComponentLocation).ProjectOnTo(ComponentForward);
	const FVector UpdatedVector = -CurrentClimbableSurfaceNormal * ProjectedComponentToSurface.Length();

	UpdatedComponent->MoveComponent(UpdatedVector * deltaTime * MaxClimbSpeed, UpdatedComponent->GetComponentQuat(), true);
}


void UNewCharacterMovementComponent::ClimbingPhysics(float deltaTime, int32 Iterations)
{
	PhysClimb(deltaTime, Iterations);
}


void UNewCharacterMovementComponent::PhysClimb(float deltaTime, int32 Iterations)
{
	if (deltaTime < MIN_TICK_TIME)
	{
		return;
	}
	/*
	*Process all climbable surfaces info.
	*/
	if (TraceClimbableSurfaces()) ProcessClimbableSurfaceInfo();
	else StopClimb();
	/*
	*Check if should stop climbing.
	*/
	if (HasReachedFloor()) StopClimb();

	RestorePreAdditiveRootMotionVelocity();

	if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
	{
		//Define Max Climb Speed and Deceleration .
		CalcVelocity(deltaTime, 0.0f, true, GetMaxBrakingDeceleration());
	}

	ApplyRootMotionToVelocity(deltaTime);

	/**/Iterations++;
	bJustTeleported = false;

	FVector OldLocation = UpdatedComponent->GetComponentLocation();
	const FVector Adjusted = Velocity * deltaTime;
	FHitResult Hit(1.f);

	/*
	* Handle climb rotation.
	*/
	if (ShouldStopClimbing()) StopClimb();

	SafeMoveUpdatedComponent(Adjusted, GetClimbRotation(deltaTime), true, Hit);


	if (Hit.Time < 1.f)
	{
		HandleImpact(Hit, deltaTime, Adjusted);
		SlideAlongSurface(Adjusted, (1.f - Hit.Time), Hit.Normal, Hit, true);
	}

	if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
	{
		Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / deltaTime;
	}
	/*
	* Update movement to climbable surfaces.
	*/
	UpdateClimbSurface(deltaTime);

	if (HasReachedUpLedge())
	{
		OnClimbReachedUpLedge.Broadcast(CurrentWall);
#if WITH_EDITOR
		// Print both angle differences to the screen
		if (GEngine && bShowClimbDebugTraces) GEngine->AddOnScreenDebugMessage(5, 0.0f, FColor::Yellow, FString::Printf(TEXT("ClimbUp:")));
#endif
		//StopClimb();
		StartMantle();
	}
}

#pragma endregion

#pragma region Vault

void UNewCharacterMovementComponent::StartVault()
{
	if (bCanVault && CanVaultInCurrentState()) ActivateAdvancedMovementFlag((uint8)EAdvancedMovementFlag::CFLAG_WantsToVault);

}

void UNewCharacterMovementComponent::StopVault()
{
	ClearAdvancedMovementFlag((uint8)EAdvancedMovementFlag::CFLAG_WantsToVault);
}

float UNewCharacterMovementComponent::GetVaultHalfHeight() const
{
	return VaultHalfHeight;
}

bool UNewCharacterMovementComponent::CanVault()
{
	if (!IsMovementMode(MOVE_Walking)) return false;
	if (Velocity.SizeSquared2D() < FMath::Square(MinVaultSpeed)) return false;

	FVector Location = CharacterOwner->GetActorLocation();
	float CapsuleHalfHeight = CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	// Adjust the Z component of Location
	FVector AdjustedLocationPre = FVector(Location.X, Location.Y, ((Location.Z - CapsuleHalfHeight)));
	// Adjust the Z component of Location
	FVector AdjustedLocation = FVector(Location.X, Location.Y, ((Location.Z - CapsuleHalfHeight) + MaxStepHeight));

	FVector Forward = CharacterOwner->GetActorForwardVector();
	FVector Upward = CharacterOwner->GetActorUpVector();

	int32 StepValue = 10;
	int32 Height = FMath::CeilToInt(MaxVaultHeight / StepValue); // Number of steps
	int32 Width = FMath::CeilToInt(MaxVaultWidth / StepValue); // Number of steps

	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("VaultTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true;


	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : VaultableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	// Local variable to store the last valid hit result
	FHitResult LastHitResult;
	TArray<FVector> FirstHitNorm;
	TArray<FVector> FirstHitLoc;
	TArray<FHitResult> FirstHit;
	TArray<FVector> ForwardFace;
	TArray<FVector> UpperFace;
	FHitResult FirstHitResult;

	// Loop through each step to check forward vaulting traces
	for (int32 Index = 0; Index < Height; ++Index)
	{

		FVector Start = AdjustedLocation + Upward * Index * StepValue;
		FVector End = Start + Forward * VaultDistance;
		// Perform the trace
		FVector FirstEnd = AdjustedLocation + Forward * VaultDistance;
		bool bFisrtHit = GetWorld()->LineTraceSingleByObjectType(
			FirstHitResult,
			AdjustedLocation,
			FirstEnd,
			ObjectQueryParams,
			GetIgnoreCharacterParams()
		);

#if WITH_EDITOR
		if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		if (bFisrtHit && FirstHitResult.IsValidBlockingHit())
		{
			FirstHitLoc.Add(FirstHitResult.Location);
			break;
		}

	}
	if (FirstHitLoc.Num() == 0)
	{
		FirstHitLoc.Empty();
		return false;
	}

	FVector Avg = (AdjustedLocation + FirstHitLoc[FirstHitLoc.Num() - 1]) / 2;
	FVector WarpO = FVector(Avg.X, Avg.Y, AdjustedLocationPre.Z);
	float Dist = FVector::Dist(Avg, WarpO);
	FVector NormDirection = FirstHitResult.Normal * (-1.0f);

#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugSphere(GetWorld(), WarpO, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

#if WITH_EDITOR
	if (GEngine && bShowVaultDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Height diff: %f"), Dist));
#endif

	// Loop through each step to check forward vaulting traces
	for (int32 Index = 0; Index < Height - (Dist / StepValue); ++Index)
	{
		FVector Start = Avg + Upward * StepValue * Index;
		FVector End = Start + NormDirection * VaultDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			GetIgnoreCharacterParams()
		);

#if WITH_EDITOR
		if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		if (bHit && HitResult.IsValidBlockingHit())
		{
			// Store the last valid hit result
			LastHitResult = HitResult;
			ForwardFace.Add(HitResult.Location);
			FirstHit.Add(HitResult);
		}

	}

	if (!(ForwardFace.Num() > 1))
	{
		ForwardFace.Empty();
#if WITH_EDITOR
		if (GEngine && bShowVaultDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Less Hits: %d"), __LINE__));
#endif
		return false;
	}
	FVector LastVector = ForwardFace[ForwardFace.Num() - 1];
	float DiffDistUpper = FVector::Dist(Avg, LastVector);
	if (GEngine)
	{
		if (bShowVaultDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Height value : % f"), DiffDistUpper));
	}
	if (DiffDistUpper > MaxVaultHeight || DiffDistUpper < MinVaultHeight)
	{
		ForwardFace.Empty();
		if (GEngine)
		{
			if (bShowVaultDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("LowHeight!"));
		}
		return false;
	}

	ForwardFace.Empty();

	for (int32 Index = 1; Index < Width; ++Index)
	{
		// Perform a downward trace from the last hit location
		FVector DownwardStart = LastHitResult.Location + NormDirection * Index * StepValue + Upward * VaultHalfHeight;
		FVector DownwardEnd = DownwardStart - Upward * VaultHalfHeight;

		FHitResult DownwardHitResult;
		bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
			DownwardHitResult,
			DownwardStart,
			DownwardEnd,
			"BlockAll",
			GetIgnoreCharacterParams()
		);

#if WITH_EDITOR
		if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), DownwardStart, DownwardEnd, FColor::Blue, false, 5, 0, 1);
#endif

		// If the downward trace does not hit anything, return false
		if (bDownwardHit && DownwardHitResult.IsValidBlockingHit())
		{
			// Perform a capsule trace at the downward hit location to ensure enough space
			FVector CapStart = DownwardHitResult.Location + Upward * VaultHalfHeight + 1;

			FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), VaultHalfHeight);
			bool bCapsuleHit = GetWorld()->SweepTestByProfile(
				CapStart,
				CapStart,
				FQuat::Identity,
				"BlockAll",
				CapsuleShape,
				GetIgnoreCharacterParams()
			);

#if WITH_EDITOR
			if (bShowVaultDebugTraces) DrawDebugCapsule(GetWorld(), CapStart, VaultHalfHeight, CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

			if (!bCapsuleHit)
			{
				UpperFace.Add(DownwardHitResult.Location);
			}

		}
	}


	if (!(UpperFace.Num() > 1))
	{
		UpperFace.Empty();
		if (GEngine)
		{
			if (bShowVaultDebugTraces)
			{
				FString DebugMessage = FString::Printf(TEXT("LowWidth!:%d (Line: %d)"), UpperFace.Num(), __LINE__);
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, DebugMessage);
			}
		}
		return false;
	}
	FVector UpperFaceFirst = UpperFace[0];
	FVector UpperFaceLast = UpperFace[UpperFace.Num() - 1];

	FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), VaultHalfHeight);
	FHitResult ClearanceCapsuleHitResult;
	bool bClearanceCapsuleHit = GetWorld()->SweepSingleByProfile(
		ClearanceCapsuleHitResult,
		UpperFaceFirst + VaultHalfHeight * Upward + 1,
		UpperFaceLast + VaultHalfHeight * Upward + 1,
		FQuat::Identity,
		FName("BlockAll"),
		CapsuleShape,
		TraceParams
	);

	// Draw debug capsules at the start, end, and hit locations
#if WITH_EDITOR

	if (bShowVaultDebugTraces)
	{
		DrawDebugCapsule(GetWorld(), UpperFaceLast + VaultHalfHeight * Upward + 1, VaultHalfHeight, CapR(), FQuat::Identity, FColor::Red, false, 5.0f, 0, 1.0f);
		DrawDebugCapsule(GetWorld(), UpperFaceLast + VaultHalfHeight * Upward + 1, VaultHalfHeight, CapR(), FQuat::Identity, FColor::Red, false, 5.0f, 0, 1.0f);

	}
#endif


	// If there was a hit, draw a hit capsule
	if (bClearanceCapsuleHit)
	{
#if WITH_EDITOR
		if (bShowVaultDebugTraces)
		{
			DrawDebugCapsule(GetWorld(), ClearanceCapsuleHitResult.Location, VaultHalfHeight, CapR(), FQuat::Identity, FColor::Red, false, 5.0f, 0, 1.0f);

			// Display debug message
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Blocked Path!"));

		}
#endif
		// Clear the target locations and rotations
		WarpTargetLocations.Empty();
		WarpTargetRotations.Empty();
		UpperFace.Empty();


		return false;
	}

	float UpperAVG = FVector::Dist(UpperFaceFirst, UpperFaceLast);

#if WITH_EDITOR
	if (bShowVaultDebugTraces && GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Width value: %f"), UpperAVG));
#endif
	if (!(UpperAVG >= MinVaultWidth && UpperAVG <= MaxVaultWidth))
	{
		UpperFace.Empty();
		if (GEngine)
		{
			if (bShowVaultDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("3360! Low Width"));
		}
		return false;
	}
	FVector UpperFaceAVG = (UpperFaceFirst + UpperFaceLast) / 2.0f;


#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugSphere(GetWorld(), UpperFaceAVG, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	UpperFace.Empty();
	FVector LastTraceStart = LastHitResult.Location + NormDirection * CapR();
	FVector LastTraceEnd = LastTraceStart - Upward * CapHH() * 2;
	FHitResult FinalHitResult;
	bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
		FinalHitResult,
		LastTraceStart,
		LastTraceEnd,
		"BlockAll",
		TraceParams
	);
	if (FinalHitResult.IsValidBlockingHit())
	{
		if (FinalHitResult.Distance < MinVaultHeight) {
			return false;
		}
	}
	else
	{
		return false;
	}
	FVector CapLoc = ((FinalHitResult.bBlockingHit || FinalHitResult.bStartPenetrating) ? (FinalHitResult.Location) : (FinalHitResult.TraceEnd)) + (Upward * CapHH() + 1) + NormDirection * CapR();
	bool bFinalCapsuleHit = GetWorld()->SweepTestByProfile(
		CapLoc,
		CapLoc,
		FQuat::Identity,
		"BlockAll",
		FCollisionShape::MakeCapsule(CapR(), CapHH()),
		TraceParams
	);


#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugCapsule(GetWorld(), CapLoc, CapHH(), CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), LastTraceStart, LastTraceEnd, FColor::Blue, false, 5, 0, 1);
#endif

	if ((bFinalCapsuleHit))
	{
		return false;
	}
	else
	{
		FVector FinalWarpLocation = ((FinalHitResult.bBlockingHit || FinalHitResult.bStartPenetrating) ? (FinalHitResult.Location) : (FinalHitResult.TraceEnd)) + NormDirection * CapR();
#if WITH_EDITOR
		if (bShowVaultDebugTraces)
		{
			DrawDebugSphere(GetWorld(), FinalWarpLocation, 10.0f, 12, FColor::White, false, 5, 0, 1);

			if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Vaulting")));

		}
#endif
		SetWallInfo(EWallSide::Front, FirstHit[0]);
		return true;

	}
}

bool UNewCharacterMovementComponent::CanVaultInCurrentState() const
{
	return IsMovementMode(MOVE_Walking) && !IsCrouching();
}

bool UNewCharacterMovementComponent::IsVaulting() const
{
	return IsCustomMovementMode(CMOVE_Vault);
}

void UNewCharacterMovementComponent::EnterVault()
{
	if (UpdateVaultWarpLocations())
	{
		PreInitializeVault();
		if (VaultData) OnVaultInitialize.Broadcast(VaultData);
		PlayVaultMontage();
		HHUpdateVault();
		Multicast_UpdateHHEnterVault();
		SetMovementMode(MOVE_Custom, CMOVE_Vault);
		Multicast_PlayVault(VaultData->AdvancedMovementMontage, VaultData->MontagePlayRate, VaultData->MontageStartDuration);
		OnVaultStart.Broadcast(CurrentWall);
	}
	else StopVault();
}

void UNewCharacterMovementComponent::HHUpdateVault()
{
	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	FVector Start = CharacterOwner->GetActorLocation();
	FVector End = Start - CharacterOwner->GetActorUpVector() * CapHH() + 1;
	FHitResult HitResult;
	// Perform the sphere sweep
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeSphere(CapR()),
		GetIgnoreCharacterParams()
	);

	if (bHit && (HitResult.bBlockingHit || HitResult.bStartPenetrating))
	{
		FVector Updated = CharacterOwner->GetActorLocation() - CharacterOwner->GetActorUpVector() * VaultHalfHeight;
		CharacterOwner->CacheInitialMeshOffset(CharacterOwner->GetActorUpVector() * VaultHalfHeight * (-1), DefaultCharacter->GetMesh()->GetRelativeRotation());
		CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * VaultHalfHeight * (-1));
		CharacterOwner->SetActorLocation(Updated);
		CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(VaultHalfHeight, true);
	}

#if WITH_EDITOR

	if (bShowVaultDebugTraces)
	{
		// Draw debug for the sweep start and end points
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 2.0f);

		// Draw a debug sphere at the start and end positions
		DrawDebugSphere(GetWorld(), Start, CapR(), 12, FColor::Blue, false, 5);
		DrawDebugSphere(GetWorld(), End, CapR(), 12, FColor::Red, false, 5);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, 5, FColor::Yellow, false, 5);
		}
	}
#endif
}

void UNewCharacterMovementComponent::HHUpdateStopVault()
{
	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	if (CapHH() != DefaultCapsuleHalfHeight)
	{
		FVector Start = CharacterOwner->GetActorLocation();
		FVector End = Start - CharacterOwner->GetActorUpVector() * CapHH() + 1;
		FHitResult HitResult;

		// Perform the sphere sweep
		bool bHit = GetWorld()->SweepSingleByProfile(
			HitResult,
			Start,
			End,
			FQuat::Identity,
			TEXT("BlockAll"),
			FCollisionShape::MakeCapsule(CapR(), CapR()),
			GetIgnoreCharacterParams()
		);

		if (bHit && (HitResult.bBlockingHit || HitResult.bStartPenetrating))
		{
			FVector Updated = HitResult.Location + CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight;
			CharacterOwner->CacheInitialMeshOffset(CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight * (-1), DefaultCharacter->GetMesh()->GetRelativeRotation());
			CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight * (-1));
			CharacterOwner->SetActorLocation(Updated);
			CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(DefaultCapsuleHalfHeight, true);

		}

#if WITH_EDITOR

		if (bShowVaultDebugTraces)
		{
			// Draw debug for the sweep start and end points
			DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 2.0f);

			// Draw a debug sphere at the start and end positions
			DrawDebugSphere(GetWorld(), Start, CapR(), 12, FColor::Blue, false, 5);
			DrawDebugSphere(GetWorld(), End, CapR(), 12, FColor::Red, false, 5);

			// If there was a hit, draw a point at the hit location
			if (bHit)
			{
				DrawDebugPoint(GetWorld(), HitResult.Location, 5, FColor::Yellow, false, 1.0f);
			}
		}
#endif
	}
}


void UNewCharacterMovementComponent::PreInitializeVault()
{
	// Check if the owner is valid
	if (!CharacterOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("PreInitializeVault: CharacterOwner is invalid."));
		return;
	}
	// Get the MotionWarpingComponent from the character owner

	UMotionWarpingComponent* MotionWarpingComp = CharacterOwner->FindComponentByClass<UMotionWarpingComponent>();

	if (!MotionWarpingComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("MotionWarpingComponent is missing on the character."));
		return;
	}

	// Get the vault data from the character owner
	if (!VaultData)	VaultData = CharOwner->GetVaultData();

	if (!VaultData)
	{
		PostInitializeVault();
		return;
	}
	FVector AdjustedWarpLocation;
	FName WarpTargetName;
	FRotator TargetRotator = (WarpTargetRotations.Num() > 0) ? WarpTargetRotations[0] : CharacterOwner->GetActorRotation();

	// Check the number of warp targets
	UE_LOG(LogTemp, Warning, TEXT("Number of Warp Targets: %d"), WarpTargetLocations.Num());
	if (WarpTargetLocations.Num() < 3)
	{
		PostInitializeVault();
		return;
	}
	// Use a range-based for loop to iterate through WarpTargetLocations
	int32 Index = 0;
	StopMovementImmediately();
	for (const FVector& WarpLocation : WarpTargetLocations)
	{
		// Log the index and warp location (optional, for debugging)
		UE_LOG(LogTemp, Warning, TEXT("Index: %d, Warp Location: %s"), Index, *WarpLocation.ToString());
		// Call the function on VaultData with the current warp location or index
		AdjustedWarpLocation = VaultData->AdjustAndUpdateWarpTarget(Index, WarpLocation, CharacterOwner, WarpTargetName);
		MotionWarpingComp->AddOrUpdateWarpTargetFromLocationAndRotation(WarpTargetName, AdjustedWarpLocation, TargetRotator);
		// Increment the index manually
		Index++;
	}
}

void UNewCharacterMovementComponent::PlayVaultMontage()
{
	if (CharacterOwner && CharacterOwner->GetMesh())
	{
		UAnimInstance* OwnerAnimInstance = CharacterOwner->GetMesh()->GetAnimInstance();
		if (OwnerAnimInstance)
		{
			if (!VaultData)
			{
				PostInitializeVault();
				return;
			}

			UAnimMontage* VaultMontage = VaultData->AdvancedMovementMontage;
			if (!VaultMontage)
			{
				PostInitializeVault();
				return;
			}
			float VaultPlayRate = VaultData->MontagePlayRate;
			float VaultStartPosition = VaultData->MontageStartDuration;
			OwnerAnimInstance->Montage_Play(VaultMontage, VaultPlayRate, EMontagePlayReturnType::MontageLength, VaultStartPosition);

			// Bind to the montage blend out delegate
			FOnMontageBlendingOutStarted MontageBlendingOutDelegate;
			MontageBlendingOutDelegate.BindUObject(this, &UNewCharacterMovementComponent::OnVaultMontageEnded);
			OwnerAnimInstance->Montage_SetBlendingOutDelegate(MontageBlendingOutDelegate, VaultMontage);
		}
	}
}

void UNewCharacterMovementComponent::PostInitializeVault()
{
	if (CharacterOwner && CharacterOwner->GetMesh())
	{
		UAnimInstance* OwnerAnimInstance = CharacterOwner->GetMesh()->GetAnimInstance();
		if (OwnerAnimInstance && VaultData && OwnerAnimInstance->Montage_IsPlaying(VaultData->AdvancedMovementMontage)) OwnerAnimInstance->Montage_Stop(VaultData->MontageBlendOutTime, VaultData->AdvancedMovementMontage);
	}
	VaultData = nullptr;
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();
	SetMovementMode(MOVE_Walking);
	SetWallInfo(EWallSide::None, FHitResult());
	HHUpdateStopVault();
	Multicast_UpdateHHExitVault();
	OnVaultStop.Broadcast();

}

bool UNewCharacterMovementComponent::UpdateVaultWarpLocations()
{
	WarpTargetRotations.Empty();
	WarpTargetLocations.Empty();

	if (!IsMovementMode(MOVE_Walking)) return false;
	if (Velocity.SizeSquared2D() < FMath::Square(MinVaultSpeed)) return false;

	FVector Location = CharacterOwner->GetActorLocation();
	float CapsuleHalfHeight = CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	// Adjust the Z component of Location
	FVector AdjustedLocationPre = FVector(Location.X, Location.Y, ((Location.Z - CapsuleHalfHeight)));
	// Adjust the Z component of Location
	FVector AdjustedLocation = FVector(Location.X, Location.Y, ((Location.Z - CapsuleHalfHeight) + MaxStepHeight));

	FVector Forward = CharacterOwner->GetActorForwardVector();
	FVector Upward = CharacterOwner->GetActorUpVector();

	int32 StepValue = 10;
	int32 Height = FMath::CeilToInt(MaxVaultHeight / StepValue); // Number of steps
	int32 Width = FMath::CeilToInt(MaxVaultWidth / StepValue); // Number of steps

	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("VaultTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true;


	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : VaultableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	// Local variable to store the last valid hit result
	FHitResult LastHitResult;
	TArray<FVector> FirstHitNorm;
	TArray<FVector> FirstHitLoc;
	TArray<FHitResult> FirstHit;
	TArray<FVector> ForwardFace;
	TArray<FVector> UpperFace;
	FHitResult FirstHitResult;

	// Loop through each step to check forward vaulting traces
	for (int32 Index = 0; Index < Height; ++Index)
	{

		FVector Start = AdjustedLocation + Upward * Index * StepValue;
		FVector End = Start + Forward * VaultDistance;
		// Perform the trace
		FVector FirstEnd = AdjustedLocation + Forward * VaultDistance;
		bool bFisrtHit = GetWorld()->LineTraceSingleByObjectType(
			FirstHitResult,
			AdjustedLocation,
			FirstEnd,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		if (bFisrtHit && FirstHitResult.IsValidBlockingHit())
		{
			FirstHitLoc.Add(FirstHitResult.Location);
			break;
		}

	}
	if (FirstHitLoc.Num() == 0)
	{
		FirstHitLoc.Empty();
		return false;
	}

	FVector Avg = (AdjustedLocation + FirstHitLoc[FirstHitLoc.Num() - 1]) / 2;
	FVector WarpO = FVector(Avg.X, Avg.Y, AdjustedLocationPre.Z);
	float Dist = FVector::Dist(Avg, WarpO);
	FVector NormDirection = FirstHitResult.Normal * (-1.0f);

	FRotator XRotator = UKismetMathLibrary::MakeRotFromX(FirstHitResult.Normal);
	FRotator FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 180.0f, 0.0f));

	WarpTargetRotations.Add(FinalRotator);
	WarpTargetLocations.Add(WarpO);

#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugSphere(GetWorld(), WarpO, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

#if WITH_EDITOR
	if (GEngine && bShowVaultDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Height diff: %f"), Dist));
#endif

	// Loop through each step to check forward vaulting traces
	for (int32 Index = 0; Index < Height - (Dist / StepValue); ++Index)
	{
		FVector Start = Avg + Upward * StepValue * Index;
		FVector End = Start + NormDirection * VaultDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		if (bHit && HitResult.IsValidBlockingHit())
		{
			// Store the last valid hit result
			LastHitResult = HitResult;
			ForwardFace.Add(HitResult.Location);
			FirstHit.Add(HitResult);
		}

	}

	if (!(ForwardFace.Num() > 1))
	{
		WarpTargetLocations.Empty();
		WarpTargetRotations.Empty();
		ForwardFace.Empty();
#if WITH_EDITOR
		if (GEngine && bShowVaultDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Less Hits: %d"), __LINE__));
#endif
		return false;
	}
	FVector LastVector = ForwardFace[ForwardFace.Num() - 1];
	float DiffDistUpper = FVector::Dist(Avg, LastVector);
#if WITH_EDITOR
	if (GEngine)
	{
		if (bShowVaultDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Height value : % f"), DiffDistUpper));
	}
#endif
	if (DiffDistUpper > MaxVaultHeight || DiffDistUpper < MinVaultHeight)
	{
		WarpTargetLocations.Empty();
		ForwardFace.Empty();
		WarpTargetRotations.Empty();
#if WITH_EDITOR
		if (GEngine)
		{
			if (bShowVaultDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("LowHeight!"));
		}
#endif
		return false;
	}

	ForwardFace.Empty();

	for (int32 Index = 1; Index < Width; ++Index)
	{
		// Perform a downward trace from the last hit location
		FVector DownwardStart = LastHitResult.Location + NormDirection * Index * StepValue + Upward * VaultHalfHeight;
		FVector DownwardEnd = DownwardStart - Upward * VaultHalfHeight;

		FHitResult DownwardHitResult;
		bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
			DownwardHitResult,
			DownwardStart,
			DownwardEnd,
			"BlockAll",
			TraceParams
		);

#if WITH_EDITOR
		if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), DownwardStart, DownwardEnd, FColor::Blue, false, 5, 0, 1);
#endif

		// If the downward trace does not hit anything, return false
		if (bDownwardHit && DownwardHitResult.IsValidBlockingHit())
		{
			// Perform a capsule trace at the downward hit location to ensure enough space
			FVector CapStart = DownwardHitResult.Location + Upward * VaultHalfHeight + 1;

			FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), VaultHalfHeight);
			bool bCapsuleHit = GetWorld()->SweepTestByProfile(
				CapStart,
				CapStart,
				FQuat::Identity,
				"BlockAll",
				CapsuleShape,
				TraceParams
			);

#if WITH_EDITOR
			if (bShowVaultDebugTraces) DrawDebugCapsule(GetWorld(), CapStart, VaultHalfHeight, CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

			if (!bCapsuleHit)
			{
				UpperFace.Add(DownwardHitResult.Location);
			}

		}
	}


	if (!(UpperFace.Num() > 1))
	{
		WarpTargetLocations.Empty();
		UpperFace.Empty();
		WarpTargetRotations.Empty();
#if WITH_EDITOR
		if (GEngine)
		{
			if (bShowVaultDebugTraces)
			{
				FString DebugMessage = FString::Printf(TEXT("LowWidth! (Line: %d)"), __LINE__);
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, DebugMessage);
			}
		}
#endif
		return false;
	}
	FVector UpperFaceFirst = UpperFace[0];
	FVector UpperFaceLast = UpperFace[UpperFace.Num() - 1];

	FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), VaultHalfHeight);
	FHitResult ClearanceCapsuleHitResult;
	bool bClearanceCapsuleHit = GetWorld()->SweepSingleByProfile(
		ClearanceCapsuleHitResult,
		UpperFaceFirst + VaultHalfHeight * Upward + 1,
		UpperFaceLast + VaultHalfHeight * Upward + 1,
		FQuat::Identity,
		FName("BlockAll"),
		CapsuleShape,
		TraceParams
	);
	if (bClearanceCapsuleHit)
	{
		WarpTargetLocations.Empty();
		WarpTargetRotations.Empty();
		UpperFace.Empty();
#if WITH_EDITOR
		if (GEngine)
		{
			if (bShowVaultDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Blocked Path!"));
		}
#endif
		return false;
	}

	float UpperAVG = FVector::Dist(UpperFaceFirst, UpperFaceLast);

#if WITH_EDITOR
	if (bShowVaultDebugTraces && GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Width value: %f"), UpperAVG));
#endif
	if (!(UpperAVG >= MinVaultWidth && UpperAVG <= MaxVaultWidth))
	{
		WarpTargetLocations.Empty();
		UpperFace.Empty();
		WarpTargetRotations.Empty();
#if WITH_EDITOR
		if (GEngine)
		{
			if (bShowVaultDebugTraces)
			{
				FString DebugMessage = FString::Printf(TEXT("LowWidth! (Line: %d)"), __LINE__);
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, DebugMessage);
			}
		}
#endif
		return false;
	}
	FVector UpperFaceAVG = (UpperFaceFirst + UpperFaceLast) / 2.0f;

	WarpTargetLocations.Add(UpperFaceAVG);

#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugSphere(GetWorld(), UpperFaceAVG, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	UpperFace.Empty();
	FVector LastTraceStart = LastHitResult.Location + NormDirection * CapR();
	FVector LastTraceEnd = LastTraceStart - Upward * CapHH() * 2;
	FHitResult FinalHitResult;
	bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
		FinalHitResult,
		LastTraceStart,
		LastTraceEnd,
		"BlockAll",
		TraceParams
	);
	if (FinalHitResult.IsValidBlockingHit())
	{
		if (FinalHitResult.Distance < MinVaultHeight) {
			WarpTargetLocations.Empty();
			WarpTargetRotations.Empty();
			return false;
		}
	}
	else
	{
		WarpTargetLocations.Empty();
		WarpTargetRotations.Empty();
		return false;
	}
	FVector CapLoc = ((FinalHitResult.bBlockingHit || FinalHitResult.bStartPenetrating) ? (FinalHitResult.Location) : (FinalHitResult.TraceEnd)) + (Upward * CapHH() + 1) + NormDirection * CapR();
	bool bFinalCapsuleHit = GetWorld()->SweepTestByProfile(
		CapLoc,
		CapLoc,
		FQuat::Identity,
		"BlockAll",
		FCollisionShape::MakeCapsule(CapR(), CapHH()),
		TraceParams
	);


#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugCapsule(GetWorld(), CapLoc, CapHH(), CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

#if WITH_EDITOR
	if (bShowVaultDebugTraces) DrawDebugLine(GetWorld(), LastTraceStart, LastTraceEnd, FColor::Blue, false, 5, 0, 1);
#endif

	if ((bFinalCapsuleHit))
	{
		WarpTargetLocations.Empty();
		WarpTargetRotations.Empty();
		return false;
	}
	else
	{
		FVector FinalWarpLocation = ((FinalHitResult.bBlockingHit || FinalHitResult.bStartPenetrating) ? (FinalHitResult.Location) : (FinalHitResult.TraceEnd)) + NormDirection * CapR();
		WarpTargetLocations.Add(FinalWarpLocation);
#if WITH_EDITOR
		if (bShowVaultDebugTraces)
		{
			DrawDebugSphere(GetWorld(), FinalWarpLocation, 10.0f, 12, FColor::White, false, 5, 0, 1);

			if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Vaulting")));

		}
#endif
		SetWallInfo(EWallSide::Front, FirstHit[0]);
		return true;

	}
}

void UNewCharacterMovementComponent::OnVaultMontageEnded(UAnimMontage* MontageToPlay, bool bIsInterupted)
{
	if (VaultData)
	{
		if (GEngine && bShowVaultDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Valid!"));
		if (MontageToPlay == VaultData->AdvancedMovementMontage && !bIsInterupted) StopVault();
	}
	else if (GEngine && bShowVaultDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("InValid!"));

}

void UNewCharacterMovementComponent::PhysVault(float deltaTime, int32 Iterations)
{
	PhysFlying(deltaTime, Iterations);
}

#pragma endregion

#pragma region Mantle

void UNewCharacterMovementComponent::StartMantle()
{
	ActivateAdvancedMovementFlag((uint8)EAdvancedMovementFlag::CFLAG_WantsToMantle);
	if (bCanMantleInAir) GetWorld()->GetTimerManager().SetTimer(CheckLedgeDuringFallTimerHandle, this, &UNewCharacterMovementComponent::FallingStopMantle, 1.0f, false);
}

void UNewCharacterMovementComponent::StopMantle()
{
	ClearAdvancedMovementFlag((uint8)EAdvancedMovementFlag::CFLAG_WantsToMantle);
}

bool UNewCharacterMovementComponent::CanMantle()
{
	if (!bCanMantleInAir) if (IsFalling()) return false;

	if (bCanMantleInAir && IsFalling()) return CheckLedgeDuringFall();

	if (Velocity.SizeSquared2D() < FMath::Square(MinMantleSpeed)) return false;

	FVector Location = CharacterOwner->GetActorLocation();
	// Adjust the Z component of Location
	FVector AdjustedLocation = FVector(Location.X, Location.Y, (Location.Z - CapHH()));
	FVector AdjustedLocationFinal = FVector(Location.X, Location.Y, (Location.Z - CapHH() + MaxStepHeight));

	FVector Forward = CharacterOwner->GetActorForwardVector();
	FVector Upward = CharacterOwner->GetActorUpVector();

	int32 StepValue = 10;
	int32 Height = FMath::CeilToInt(MaxMantleHeight / StepValue); // Number of steps
	float CosMinMantleAngle = FMath::Cos(FMath::DegreesToRadians(MinMantleAngle));

	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("MantleTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true;

	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : MantlableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	// Local variable to store the last valid hit result
	FHitResult LastHitResult;
	TArray<FHitResult> InitialcheckFace;
	// Loop through each step to check forward Mantling traces
	for (int32 Index = 0; Index < Height; ++Index)
	{
		FVector Start = AdjustedLocationFinal + Upward * StepValue * Index;
		FVector End = Start + Forward * MantleDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowMantleDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		// If no hit or invalid hit, return false
		if (bHit || HitResult.IsValidBlockingHit())
		{
			// Store the last valid hit result
			LastHitResult = HitResult;
			InitialcheckFace.Add(LastHitResult);
			break;
		}
	}

	if (InitialcheckFace.Num() < 1)
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits")));
#endif
		InitialcheckFace.Empty();
		return false;

	}
	InitialcheckFace.Empty();
	float CurrentWallSteepness = LastHitResult.Normal | FVector::UpVector;
	if ((FMath::Abs(CurrentWallSteepness) > CosMinMantleAngle))
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("CurrentAngle %f"), CurrentWallSteepness));
#endif
		return false;
	}
	FVector AVGOne = LastHitResult.Location;
	FVector AVG = (AVGOne + AdjustedLocationFinal) / 2.0f;
	FVector Norm = -LastHitResult.Normal;
	float AVGZ = FMath::Abs(AVG.Z - AdjustedLocation.Z);

#if WITH_EDITOR
	if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("HeightDiff %f"), AVGZ));
#endif

#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), FVector(AVG.X, AVG.Y, AdjustedLocation.Z), 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif
	TArray<FVector> FrontFace;
	// Loop through each step to check forward Mantling traces
	for (int32 Index = 0; Index < (Height - (AVGZ / StepValue)); ++Index)
	{
		FVector Start = AVG + Upward * StepValue * Index;
		FVector End = Start + Norm * MantleDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowMantleDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif
		CurrentWallSteepness = HitResult.Normal | FVector::UpVector;
		// If no hit or invalid hit, do nothing
		if (bHit || HitResult.IsValidBlockingHit() || (FMath::Abs(CurrentWallSteepness) > CosMinMantleAngle)) FrontFace.Add(HitResult.Location);
	}

	if (FrontFace.Num() < 1)
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits, Line: %d"), __LINE__));
#endif
		FrontFace.Empty();
		return false;
	}

	FVector FrontLast = FrontFace[FrontFace.Num() - 1];
	float DiffUpper = FMath::Abs(FrontLast.Z - AdjustedLocation.Z);

#if WITH_EDITOR
	if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Current Height: %f"), DiffUpper));
#endif

	if (DiffUpper > MaxMantleHeight || DiffUpper < 70)
	{
		FrontFace.Empty();
		return false;
	}
#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), FrontLast, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	// Perform a downward trace from the last hit location
	FVector DownwardStart = FrontLast + Norm * StepValue + Upward * CapR();
	FVector DownwardEnd = DownwardStart - Upward * CapHH();

	FHitResult DownwardHitResult;
	bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
		DownwardHitResult,
		DownwardStart,
		DownwardEnd,
		TEXT("BlockAll"), // Use the "BlockAll" collision profile
		TraceParams
	);


#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugLine(GetWorld(), DownwardStart, DownwardEnd, FColor::Blue, false, 5, 0, 1);
#endif

	// If the downward trace does not hit anything, return false
	if (!bDownwardHit) return false;

	// Perform a capsule trace at the downward hit location to ensure enough space
	FVector CapStart = DownwardHitResult.Location + Upward * CapHH() * 1.1;

	FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), CapHH());
	bool bCapsuleHit = GetWorld()->SweepTestByProfile(
		CapStart,
		CapStart,
		FQuat::Identity,
		TEXT("BlockAll"), // Use the "BlockAll" collision profile
		CapsuleShape,
		TraceParams
	);

#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugCapsule(GetWorld(), CapStart, CapHH(), CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

	// If the capsule trace hits, return false
	if (bCapsuleHit)
	{
		FrontFace.Empty();
		return false;
	}
#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), DownwardHitResult.Location, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	FrontFace.Empty();
	return true;
}

bool UNewCharacterMovementComponent::CanMantleInCurrentState() const
{
	// Return true if not crouching and either:
	// - Walking (if mantling in air is not allowed)
	// - Walking or falling (if mantling in air is allowed)
	//- Return true even if climbing
	return (!IsCrouching() && (bCanMantleInAir ? (IsWalking() || IsFalling()) : IsWalking())) || IsClimbing();
}

bool UNewCharacterMovementComponent::IsMantling() const
{
	return IsCustomMovementMode(CMOVE_Mantle);
}

void UNewCharacterMovementComponent::EnterMantle()
{
	StopClimb();
	if (!IsFalling() && !IsClimbing())
	{
		if (UpdateMantleWarpLocations())
		{
			PreInitializeMantle();
			if (MantleData) OnMantleInitialize.Broadcast(MantleData);
			PlayMantleMontage();
			SetMovementMode(MOVE_Custom, CMOVE_Mantle);
			Server_PlayMantle(MantleData->AdvancedMovementMontage, MantleData->MontagePlayRate, MantleData->MontageStartDuration);
			OnMantleStart.Broadcast(CurrentWall);
		}
		else StopMantle();
	}
	else if (CheckLedgeDuringFall())
	{
		PreInitializeMantle();
		if (MantleData) OnMantleInitialize.Broadcast(MantleData);
		PlayMantleMontage();
		SetMovementMode(MOVE_Custom, CMOVE_Mantle);
		Server_PlayMantle(MantleData->AdvancedMovementMontage, MantleData->MontagePlayRate, MantleData->MontageStartDuration);
		OnMantleStart.Broadcast(CurrentWall);
	}
}

bool UNewCharacterMovementComponent::CheckLedgeDuringFall()
{
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();
	if (!bCanMantleInAir) return false;

#if WITH_EDITOR
	if (bShowMantleDebugTraces && GEngine)GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Green, FString::Printf(TEXT("FallingMantle")));
#endif
	if (!IsFalling())
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces && GEngine)GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Green, FString::Printf(TEXT("Exiting")));
#endif
		return false;
	}
	// Get the character's eye height location
	FVector StartLocation = UpdatedComponent->GetComponentLocation() + (UpdatedComponent->GetUpVector() * CharacterOwner->BaseEyeHeight);

	// Get the forward direction of the character
	FVector ForwardDirection = CharacterOwner->GetActorForwardVector();

	// Set the end location for the forward trace
	FVector EndLocation = StartLocation + (ForwardDirection * 100.0f); // Adjust distance as needed

	// Perform a forward line trace
	FHitResult ForwardHitResult;
	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("FallingLedgeTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true; // Trace complex collisions if needed



	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : MantlableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	bool bForwardHit = GetWorld()->LineTraceSingleByObjectType(
		ForwardHitResult,
		StartLocation,
		EndLocation,
		ObjectQueryParams, // Assuming climbing surfaces are static
		TraceParams
	);

	// Perform a downward line trace to check if the character is close to a ledge or the ground
	FVector DownwardStartLocation = UpdatedComponent->GetComponentLocation();
	FVector DownwardEndLocation = DownwardStartLocation + UpdatedComponent->GetUpVector() * (-1) * (CapHH() /*+ CapR()*/); // Adjust the distance as needed

	FHitResult DownwardHitResult;
	bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
		DownwardHitResult,
		DownwardStartLocation,
		DownwardEndLocation,
		FName("BlockAll"),
		TraceParams
	);

	FHitResult DownwardNewHitResult;
	bool bNewDownwardHit = GetWorld()->LineTraceSingleByProfile(
		DownwardNewHitResult,
		DownwardStartLocation,
		DownwardEndLocation,
		FName("BlockAll"),
		TraceParams
	);

#if WITH_EDITOR
	// Debug traces
	if (bShowMantleDebugTraces)
	{
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, false, -1, 0, 1); // Forward trace
		DrawDebugLine(GetWorld(), DownwardStartLocation, DownwardEndLocation, FColor::Red, false, -1, 0, 1); // Downward trace
	}
#endif
	if (bNewDownwardHit)
	{
		return false;
	}


	if (bForwardHit)
	{

		const FVector NewLocMant = ForwardHitResult.Location;
		FVector AVG = (NewLocMant + StartLocation) / 2.0f;
		FVector Norm = -ForwardHitResult.Normal;
		FRotator XRotator = UKismetMathLibrary::MakeRotFromX(-Norm);
		FRotator FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 180.0f, 0.0f));
		WarpTargetRotations.Add(FinalRotator);
		FVector EndNorm = AVG + Norm * MantleDistance;
		FHitResult NormForwardHitResult;
		bool bNormForwardHit = GetWorld()->LineTraceSingleByObjectType(
			NormForwardHitResult,
			AVG,
			EndNorm,
			ObjectQueryParams, // Assuming climbing surfaces are static
			TraceParams
		);

#if WITH_EDITOR
		// Debug traces
		if (bShowMantleDebugTraces)
		{
			DrawDebugLine(GetWorld(), AVG, EndNorm, FColor::Green, false, -1, 0, 1); // Forward trace
		}
#endif

		if (bNormForwardHit)
		{
			FVector WarpOne = NormForwardHitResult.Location;
			WarpTargetLocations.Add(WarpOne);
#if WITH_EDITOR
			if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), WarpOne, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif
			const FVector UpWard = CharacterOwner->GetActorUpVector();
			const FVector NewStartMant = WarpOne + Norm * CapR() * 1.5 + UpWard * CapHH() * 1.1;
			FHitResult CapHitResult;

			bool bMantleCapsuleHit = GetWorld()->SweepSingleByObjectType(
				CapHitResult,
				NewStartMant,
				NewStartMant,
				FQuat::Identity,
				ObjectQueryParams,
				FCollisionShape::MakeCapsule(CapR(), CapHH())
			);
#if WITH_EDITOR
			if (bShowMantleDebugTraces)
			{
				DrawDebugCapsule(GetWorld(), NewStartMant, CapHH(), CapR(), FQuat::Identity, FColor::Magenta, false, 1, 0, 1);
			}
#endif


			/*if capsule hit then return*/
			if (!CapHitResult.bBlockingHit || !CapHitResult.bStartPenetrating)
			{
				const FVector FinalCheck = NewStartMant;
				FVector FinalCheckEnd = NewStartMant - UpWard * CapHH() * 2.0f;
				FHitResult FinalHitResult;
				bool bFinalHit = GetWorld()->LineTraceSingleByObjectType(
					FinalHitResult,
					FinalCheck,
					FinalCheckEnd,
					ObjectQueryParams, // Assuming climbing surfaces are static
					TraceParams
				);


				if (bFinalHit)
				{
#if WITH_EDITOR
					if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), FinalHitResult.Location, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif
					WarpTargetLocations.Add(FinalHitResult.Location);
					SetWallInfo(EWallSide::Front, ForwardHitResult);
					return true;
				}
			}
		}
	}

	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();
	return false;
}

void UNewCharacterMovementComponent::FallingStopMantle()
{
	if (!IsMantling())	ClearAdvancedMovementFlag((uint8)EAdvancedMovementFlag::CFLAG_WantsToMantle);
}

bool UNewCharacterMovementComponent::UpdateMantleWarpLocations()
{
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();

	if (!bCanMantleInAir) if (IsFalling()) return false;

	if (bCanMantleInAir && IsFalling()) return true;

	if (Velocity.SizeSquared2D() < FMath::Square(MinMantleSpeed)) return false;

	FVector Location = CharacterOwner->GetActorLocation();
	// Adjust the Z component of Location
	FVector AdjustedLocation = FVector(Location.X, Location.Y, (Location.Z - CapHH()));
	FVector AdjustedLocationFinal = FVector(Location.X, Location.Y, (Location.Z - CapHH() + MaxStepHeight));

	FVector Forward = CharacterOwner->GetActorForwardVector();
	FVector Upward = CharacterOwner->GetActorUpVector();

	int32 StepValue = 10;
	int32 Height = FMath::CeilToInt(MaxMantleHeight / StepValue); // Number of steps
	float CosMinMantleAngle = FMath::Cos(FMath::DegreesToRadians(MinMantleAngle));

	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("MantleTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true;

	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : MantlableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	// Local variable to store the last valid hit result
	FHitResult LastHitResult;
	TArray<FHitResult> InitialcheckFace;
	// Loop through each step to check forward Mantling traces
	for (int32 Index = 0; Index < Height; ++Index)
	{
		FVector Start = AdjustedLocationFinal + Upward * StepValue * Index;
		FVector End = Start + Forward * MantleDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowMantleDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		// If no hit or invalid hit, return false
		if (bHit || HitResult.IsValidBlockingHit())
		{
			// Store the last valid hit result
			LastHitResult = HitResult;
			InitialcheckFace.Add(LastHitResult);
			break;
		}
	}

	if (InitialcheckFace.Num() < 1)
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits")));
#endif
		InitialcheckFace.Empty();
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;

	}
	InitialcheckFace.Empty();
	float CurrentWallSteepness = LastHitResult.Normal | FVector::UpVector;
	if ((FMath::Abs(CurrentWallSteepness) > CosMinMantleAngle))
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("CurrentAngle %f"), CurrentWallSteepness));
#endif
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}
	FVector AVGOne = LastHitResult.Location;
	FVector AVG = (AVGOne + AdjustedLocationFinal) / 2.0f;
	FVector Norm = -LastHitResult.Normal;
	float AVGZ = FMath::Abs(AVG.Z - AdjustedLocation.Z);
	FRotator XRotator = UKismetMathLibrary::MakeRotFromX(LastHitResult.Normal);
	FRotator FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 180.0f, 0.0f));

#if WITH_EDITOR
	if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("HeightDiff %f"), AVGZ));
#endif

	WarpTargetRotations.Add(FinalRotator);
	WarpTargetLocations.Add(FVector(AVG.X, AVG.Y, AdjustedLocation.Z));

#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), FVector(AVG.X, AVG.Y, AdjustedLocation.Z), 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif


	TArray<FVector> FrontFace;
	TArray<FHitResult> FrontFaceHit;

	// Loop through each step to check forward Mantling traces
	for (int32 Index = 0; Index < (Height - (AVGZ / StepValue)); ++Index)
	{
		FVector Start = AVG + Upward * StepValue * Index;
		FVector End = Start + Norm * MantleDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowMantleDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif
		CurrentWallSteepness = HitResult.Normal | FVector::UpVector;
		// If no hit or invalid hit, do nothing
		if (bHit || HitResult.IsValidBlockingHit() || (FMath::Abs(CurrentWallSteepness) > CosMinMantleAngle))
		{
			FrontFace.Add(HitResult.Location);
			FrontFaceHit.Add(HitResult);
		}
	}

	if (FrontFace.Num() < 1)
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits, Line: %d"), __LINE__));
#endif
		FrontFace.Empty();
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}

	FVector FrontLast = FrontFace[FrontFace.Num() - 1];
	float DiffUpper = FMath::Abs(FrontLast.Z - AdjustedLocation.Z);

#if WITH_EDITOR
	if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Current Height: %f"), DiffUpper));
#endif

	if (DiffUpper > MaxMantleHeight || DiffUpper < MinMantleHeight)
	{
		FrontFace.Empty();
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}

	WarpTargetLocations.Add(FrontLast);

#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), FrontLast, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	// Perform a downward trace from the last hit location
	FVector DownwardStart = FrontLast + Norm * StepValue + Upward * CapR();
	FVector DownwardEnd = DownwardStart - Upward * CapHH();

	FHitResult DownwardHitResult;
	bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
		DownwardHitResult,
		DownwardStart,
		DownwardEnd,
		TEXT("BlockAll"), // Use the "BlockAll" collision profile
		TraceParams
	);


#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugLine(GetWorld(), DownwardStart, DownwardEnd, FColor::Blue, false, 5, 0, 1);
#endif

	// If the downward trace does not hit anything, return false
	if (!bDownwardHit) return false;

	// Perform a capsule trace at the downward hit location to ensure enough space
	FVector CapStart = DownwardHitResult.Location + Upward * CapHH() * 1.1;

	FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), CapHH());
	bool bCapsuleHit = GetWorld()->SweepTestByProfile(
		CapStart,
		CapStart,
		FQuat::Identity,
		TEXT("BlockAll"), // Use the "BlockAll" collision profile
		CapsuleShape,
		TraceParams
	);

#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugCapsule(GetWorld(), CapStart, CapHH(), CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

	// If the capsule trace hits, return false
	if (bCapsuleHit)
	{
		FrontFace.Empty();
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}
	WarpTargetLocations.Add(DownwardHitResult.Location);

#if WITH_EDITOR
	if (bShowMantleDebugTraces) DrawDebugSphere(GetWorld(), DownwardHitResult.Location, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif
	SetWallInfo(EWallSide::Front, FrontFaceHit[0]);

	FrontFace.Empty();
	return true;
}

void UNewCharacterMovementComponent::PreInitializeMantle()
{

	//CharOwner = Cast<ANewCharacter>(GetOwner());
	// Check if the owner is valid
	if (!CharacterOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("PreInitializeMantle: CharacterOwner is invalid."));
		PostInitializeMantle();
		return;
	}
	// Get the MotionWarpingComponent from the character owner

	UMotionWarpingComponent* MotionWarpingComp = CharacterOwner->FindComponentByClass<UMotionWarpingComponent>();

	if (!MotionWarpingComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("MotionWarpingComponent is missing on the character."));
		PostInitializeMantle();
		return;
	}
	// Get the vault data from the character owner

	if (!MantleData)MantleData = CharOwner->GetMantleData();


	if (!MantleData)
	{
		PostInitializeMantle();
		return;
	}
	FVector AdjustedWarpLocation;
	FName WarpTargetName;
	FRotator TargetRotator = (WarpTargetRotations.Num() > 0)/*false */ ? WarpTargetRotations[0] : CharacterOwner->GetActorRotation();

	// Check the number of warp targets
	UE_LOG(LogTemp, Warning, TEXT("Number of Warp Targets: %d"), WarpTargetLocations.Num());
	if (WarpTargetLocations.Num() < 1)
	{
		PostInitializeMantle();
		return;
	}
	// Use a range-based for loop to iterate through WarpTargetLocations
	int32 Index = 0;
	StopMovementImmediately();
	for (const FVector& WarpLocation : WarpTargetLocations)
	{
		// Log the index and warp location (optional, for debugging)
		UE_LOG(LogTemp, Warning, TEXT("Index: %d, Warp Location: %s"), Index, *WarpLocation.ToString());
		// Call the function on VaultData with the current warp location or index
		AdjustedWarpLocation = MantleData->AdjustAndUpdateWarpTarget(Index, WarpLocation, CharacterOwner, WarpTargetName);
		MotionWarpingComp->AddOrUpdateWarpTargetFromLocationAndRotation(WarpTargetName, AdjustedWarpLocation, TargetRotator);
		// Increment the index manually
		Index++;
	}
}

void UNewCharacterMovementComponent::PlayMantleMontage()
{
	if (CharacterOwner && CharacterOwner->GetMesh())
	{
		UAnimInstance* OwnerAnimInstance = CharacterOwner->GetMesh()->GetAnimInstance();
		if (OwnerAnimInstance)
		{
			if (!MantleData)
			{
				PostInitializeMantle();
				return;
			}

			UAnimMontage* MantleMontage = MantleData->AdvancedMovementMontage;
			if (!MantleMontage)
			{
				PostInitializeMantle();
				return;
			}
			float MantlePlayRate = MantleData->MontagePlayRate;
			float MantleStartPosition = MantleData->MontageStartDuration;

			OwnerAnimInstance->Montage_Play(MantleMontage, MantlePlayRate, EMontagePlayReturnType::MontageLength, MantleStartPosition);
			// Bind to the montage blend out delegate
			FOnMontageBlendingOutStarted MontageBlendingOutDelegate;
			MontageBlendingOutDelegate.BindUObject(this, &UNewCharacterMovementComponent::OnMantleMontageEnded);
			OwnerAnimInstance->Montage_SetBlendingOutDelegate(MontageBlendingOutDelegate, MantleMontage);

		}
	}
}

void UNewCharacterMovementComponent::PostInitializeMantle()
{
	if (CharacterOwner && CharacterOwner->GetMesh())
	{
		UAnimInstance* OwnerAnimInstance = CharacterOwner->GetMesh()->GetAnimInstance();
		if (OwnerAnimInstance && MantleData && OwnerAnimInstance->Montage_IsPlaying(MantleData->AdvancedMovementMontage)) OwnerAnimInstance->Montage_Stop(MantleData->MontageBlendOutTime, MantleData->AdvancedMovementMontage);
	}
	MantleData = nullptr;
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();
	SetMovementMode(MOVE_Walking);
	SetWallInfo(EWallSide::None, FHitResult());
	OnMantleStop.Broadcast();
}

void UNewCharacterMovementComponent::OnMantleMontageEnded(UAnimMontage* MontageToPlay, bool bIsInterupted)
{
	if (MantleData)
	{
		if (GEngine && bShowMantleDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Valid!"));
		if (MontageToPlay == MantleData->AdvancedMovementMontage && !bIsInterupted) StopMantle();
	}
	if (GEngine && bShowMantleDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("InValid!"));

}

void UNewCharacterMovementComponent::PhysMantle(float deltaTime, int32 Iterations)
{
	PhysFlying(deltaTime, Iterations);
}

#pragma endregion

#pragma region ClimbUp

void UNewCharacterMovementComponent::StartClimbUp()
{
	ActivateAdvancedMovementFlag((uint8)EAdvancedMovementFlag::CFLAG_WantsToClimbUp);
}

void UNewCharacterMovementComponent::EnterClimbUp()
{
	if (UpdateClimbUpWarpLocations())
	{
		PreInitializeClimbUp();
		if (ClimbUpData)OnClimbUpInitialize.Broadcast(ClimbUpData);
		PlayClimbUpMontage();
		SetMovementMode(MOVE_Custom, CMOVE_ClimbUp);
		Server_PlayClimbUp(ClimbUpData->AdvancedMovementMontage, ClimbUpData->MontagePlayRate, ClimbUpData->MontageStartDuration);
		OnClimbUpStart.Broadcast(CurrentWall);
	}
}

void UNewCharacterMovementComponent::StopClimbUp()
{
	ClearAdvancedMovementFlag((uint8)EAdvancedMovementFlag::CFLAG_WantsToClimbUp);
}

bool UNewCharacterMovementComponent::CanClimbUp()
{
	if (IsFalling()) return false;

	if (Velocity.SizeSquared2D() < FMath::Square(MinClimbUpSpeed)) return false;

	FVector Location = CharacterOwner->GetActorLocation();

	// Adjust the Z component of Location
	FVector AdjustedLocation = FVector(Location.X, Location.Y, (Location.Z - CapHH()));
	FVector AdjustedLocationFinal = FVector(Location.X, Location.Y, (Location.Z - (CapHH() - MaxStepHeight)));

	FVector Forward = CharacterOwner->GetActorForwardVector();
	FVector Upward = CharacterOwner->GetActorUpVector();

	int32 StepValue = 10;
	int32 Height = FMath::CeilToInt(MaxClimbUpHeight / StepValue); // Number of steps
	float CosMinMantleAngle = FMath::Cos(FMath::DegreesToRadians(MinMantleAngle));

	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("ClimbUpTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true;

	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : ClimbUpableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	// Local variable to store the last valid hit result
	FHitResult LastHitResult;

	TArray<FVector> Primary;

	// Loop through each step to check forward climb-up traces
	for (int32 Index = 0; Index < Height; ++Index)
	{
		FVector Start = AdjustedLocationFinal + Upward * StepValue * Index;
		FVector End = Start + Forward * ClimbUpDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		// If no hit or invalid hit, return false
		if (bHit || HitResult.IsValidBlockingHit())
		{
			// Store the last valid hit result
			LastHitResult = HitResult;
			Primary.Add(LastHitResult.Location);
			break;
		}
	}



	if (Primary.Num() == 0)
	{
#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits,Line: %d"), __LINE__));
#endif
		return false;
	}

	float CurrentWallSteepness = LastHitResult.Normal | FVector::UpVector;
	if ((FMath::Abs(CurrentWallSteepness) > CosMinMantleAngle))
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("CurrentAngle %f"), CurrentWallSteepness));
#endif
		return false;
	}


	FVector AVGOne = LastHitResult.Location;
	FVector AVG = (AVGOne + AdjustedLocationFinal) / 2.0f;
	FVector Norm = -LastHitResult.Normal;
	float AVGZ = FMath::Abs(AVG.Z - AdjustedLocation.Z);

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Height Diff:%f"), AVGZ));
#endif

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugSphere(GetWorld(), FVector(AVG.X, AVG.Y, AdjustedLocation.Z), 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif


	TArray<FVector> FrontFace;
	TArray<FHitResult> FrontFaceHit;

	// Loop through each step to check forward ClimbUp traces
	for (int32 Index = 0; Index < (Height - (AVGZ / StepValue)/**/); ++Index)
	{
		FVector Start = AVG + Upward * StepValue * Index;
		FVector End = Start + Norm * ClimbUpDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		CurrentWallSteepness = HitResult.Normal | FVector::UpVector;
		// If no hit or invalid hit, do nothing
		if (bHit || HitResult.IsValidBlockingHit() || (FMath::Abs(CurrentWallSteepness) > CosMinMantleAngle))
		{
			FrontFace.Add(HitResult.Location);
			FrontFaceHit.Add(HitResult);
		}

	}

	if (FrontFace.Num() < 2)
	{
#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits,Line: %d"), __LINE__));
#endif
		FrontFace.Empty();
		return false;
	}

	FVector FrontOne = FrontFace[0];
	FVector FrontLast = FrontFace[FrontFace.Num() - 1];

	float DiffLower = FMath::Abs(FrontOne.Z - AdjustedLocationFinal.Z);
	float DiffUpper = FMath::Abs(FrontLast.Z - AdjustedLocationFinal.Z);


#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Current Height: %f"), DiffUpper));
#endif


	if (DiffUpper > MaxClimbUpHeight || DiffUpper < MinClimbUpHeight)
	{
		FrontFace.Empty();
		return false;
	}

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugSphere(GetWorld(), FrontLast, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	// Perform a downward trace from the last hit location
	FVector DownwardStart = FrontLast + Norm * StepValue + Upward * CapR();
	FVector DownwardEnd = DownwardStart - Upward * CapHH();

	FHitResult DownwardHitResult;
	bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
		DownwardHitResult,
		DownwardStart,
		DownwardEnd,
		TEXT("BlockAll"),
		TraceParams
	);

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugLine(GetWorld(), DownwardStart, DownwardEnd, FColor::Blue, false, 5, 0, 1);
#endif

	// If the downward trace does not hit anything, return false
	if (!bDownwardHit || !DownwardHitResult.IsValidBlockingHit()) return false;

	// Perform a capsule trace at the downward hit location to ensure enough space
	FVector CapStart = DownwardHitResult.Location + Upward * CapHH() * 1.1;

	FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), CapHH());
	bool bCapsuleHit = GetWorld()->SweepTestByProfile(
		CapStart,
		CapStart,
		FQuat::Identity,
		TEXT("BlockAll"),
		CapsuleShape,
		TraceParams
	);

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugCapsule(GetWorld(), CapStart, CapHH(), CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

	// If the capsule trace fails, return false
	if (bCapsuleHit)
	{
		FrontFace.Empty();
		return false;
	}
#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugSphere(GetWorld(), DownwardHitResult.Location, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	FrontFace.Empty();
	return true;
}

bool UNewCharacterMovementComponent::CanClimbUpInCurrentState() const
{
	return IsMovementMode(MOVE_Walking) && !IsCrouching();
}

bool UNewCharacterMovementComponent::IsClimbingUp() const
{
	return IsCustomMovementMode(CMOVE_ClimbUp);
}

bool UNewCharacterMovementComponent::UpdateClimbUpWarpLocations()
{
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();

	if (IsFalling()) return false;

	if (Velocity.SizeSquared2D() < FMath::Square(MinClimbUpSpeed)) return false;

	FVector Location = CharacterOwner->GetActorLocation();

	// Adjust the Z component of Location
	FVector AdjustedLocation = FVector(Location.X, Location.Y, (Location.Z - CapHH()));
	FVector AdjustedLocationFinal = FVector(Location.X, Location.Y, (Location.Z - (CapHH() - MaxStepHeight)));

	FVector Forward = CharacterOwner->GetActorForwardVector();
	FVector Upward = CharacterOwner->GetActorUpVector();

	int32 StepValue = 10;
	int32 Height = FMath::CeilToInt(MaxClimbUpHeight / StepValue); // Number of steps
	float CosMinClimbUpAngle = FMath::Cos(FMath::DegreesToRadians(MinClimbUpAngle));

	// Setup trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("ClimbUpTrace")), false, CharacterOwner);
	TraceParams.bTraceComplex = true;

	FCollisionObjectQueryParams ObjectQueryParams;
	for (TEnumAsByte<EObjectTypeQuery> ObjectType : ClimbUpableSurfaceTraceTypes)
	{
		ObjectQueryParams.AddObjectTypesToQuery(UEngineTypes::ConvertToCollisionChannel(ObjectType));
	}

	// Local variable to store the last valid hit result
	FHitResult LastHitResult;

	TArray<FVector> Primary;

	// Loop through each step to check forward climb-up traces
	for (int32 Index = 0; Index < Height; ++Index)
	{
		FVector Start = AdjustedLocationFinal + Upward * StepValue * Index;
		FVector End = Start + Forward * ClimbUpDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		// If no hit or invalid hit, return false
		if (bHit || HitResult.IsValidBlockingHit())
		{
			// Store the last valid hit result
			LastHitResult = HitResult;
			Primary.Add(LastHitResult.Location);
			break;
		}
	}



	if (Primary.Num() == 0)
	{
#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits,Line: %d"), __LINE__));
#endif
		return false;
	}

	float CurrentWallSteepness = LastHitResult.Normal | FVector::UpVector;
	if ((FMath::Abs(CurrentWallSteepness) > CosMinClimbUpAngle))
	{
#if WITH_EDITOR
		if (bShowMantleDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("CurrentAngle %f"), CurrentWallSteepness));
#endif
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}


	FVector AVGOne = LastHitResult.Location;
	FVector AVG = (AVGOne + AdjustedLocationFinal) / 2.0f;
	FVector Norm = -LastHitResult.Normal;
	float AVGZ = FMath::Abs(AVG.Z - AdjustedLocation.Z);

	FRotator XRotator = UKismetMathLibrary::MakeRotFromX(LastHitResult.Normal);
	FRotator FinalRotator = UKismetMathLibrary::NormalizedDeltaRotator(XRotator, FRotator(0.0f, 180.0f, 0.0f));

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Height Diff:%f"), AVGZ));
#endif

	WarpTargetRotations.Add(FinalRotator);
	WarpTargetLocations.Add(FVector(AVG.X, AVG.Y, AdjustedLocation.Z));

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugSphere(GetWorld(), FVector(AVG.X, AVG.Y, AdjustedLocation.Z), 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif


	TArray<FVector> FrontFace;
	TArray<FHitResult> FrontFaceHit;

	// Loop through each step to check forward ClimbUp traces
	for (int32 Index = 0; Index < (Height - (AVGZ / StepValue)/**/); ++Index)
	{
		FVector Start = AVG + Upward * StepValue * Index;
		FVector End = Start + Norm * ClimbUpDistance;

		// Perform the trace
		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByObjectType(
			HitResult,
			Start,
			End,
			ObjectQueryParams,
			TraceParams
		);

#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 5, 0, 1);
#endif

		CurrentWallSteepness = HitResult.Normal | FVector::UpVector;
		// If no hit or invalid hit, do nothing
		if (bHit || HitResult.IsValidBlockingHit() || (FMath::Abs(CurrentWallSteepness) > CosMinClimbUpAngle))
		{
			FrontFace.Add(HitResult.Location);
			FrontFaceHit.Add(HitResult);
		}

	}

	if (FrontFace.Num() < 2)
	{
#if WITH_EDITOR
		if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Low Hits,Line: %d"), __LINE__));
#endif
		FrontFace.Empty();
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}

	FVector FrontOne = FrontFace[0];
	FVector FrontLast = FrontFace[FrontFace.Num() - 1];

	float DiffLower = FMath::Abs(FrontOne.Z - AdjustedLocationFinal.Z);
	float DiffUpper = FMath::Abs(FrontLast.Z - AdjustedLocationFinal.Z);


#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Current Height: %f"), DiffUpper));
#endif


	if (DiffUpper > MaxClimbUpHeight || DiffUpper < MinClimbUpHeight)
	{
		FrontFace.Empty();
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}

	WarpTargetLocations.Add(FrontLast);

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugSphere(GetWorld(), FrontLast, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	// Perform a downward trace from the last hit location
	FVector DownwardStart = FrontLast + Norm * StepValue + Upward * CapR();
	FVector DownwardEnd = DownwardStart - Upward * CapHH();

	FHitResult DownwardHitResult;
	bool bDownwardHit = GetWorld()->LineTraceSingleByProfile(
		DownwardHitResult,
		DownwardStart,
		DownwardEnd,
		TEXT("BlockAll"),
		TraceParams
	);

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugLine(GetWorld(), DownwardStart, DownwardEnd, FColor::Blue, false, 5, 0, 1);
#endif

	// If the downward trace does not hit anything, return false
	if (!bDownwardHit || !DownwardHitResult.IsValidBlockingHit()) return false;

	// Perform a capsule trace at the downward hit location to ensure enough space
	FVector CapStart = DownwardHitResult.Location + Upward * CapHH() * 1.1;

	FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(CapR(), CapHH());
	bool bCapsuleHit = GetWorld()->SweepTestByProfile(
		CapStart,
		CapStart,
		FQuat::Identity,
		TEXT("BlockAll"),
		CapsuleShape,
		TraceParams
	);

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugCapsule(GetWorld(), CapStart, CapHH(), CapR(), FQuat::Identity, FColor::Red, false, 5, 0, 1);
#endif

	// If the capsule trace fails, return false
	if (bCapsuleHit)
	{
		FrontFace.Empty();
		WarpTargetRotations.Empty();
		WarpTargetLocations.Empty();
		return false;
	}
	WarpTargetLocations.Add(DownwardHitResult.Location);

#if WITH_EDITOR
	if (bShowClimbUpDebugTraces) DrawDebugSphere(GetWorld(), DownwardHitResult.Location, 10.0f, 12, FColor::White, false, 5, 0, 1);
#endif

	FrontFace.Empty();
	SetWallInfo(EWallSide::Front, FrontFaceHit[0]);
	return true;
}

void UNewCharacterMovementComponent::PreInitializeClimbUp()
{

	//CharOwner = Cast<ANewCharacter>(GetOwner());
	// Check if the owner is valid
	if (!CharacterOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("PreInitializeClimbUp: CharacterOwner is invalid."));
		PostInitializeClimbUp();
		return;
	}
	// Get the MotionWarpingComponent from the character owner

	UMotionWarpingComponent* MotionWarpingComp = CharacterOwner->FindComponentByClass<UMotionWarpingComponent>();

	if (!MotionWarpingComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("MotionWarpingComponent is missing on the character."));
		PostInitializeClimbUp();
		return;
	}
	// Get the climb-up data from the character owner

	if (!ClimbUpData)ClimbUpData = CharOwner->GetClimbUpData();

	if (!ClimbUpData)
	{
		PostInitializeClimbUp();
		return;
	}
	FVector AdjustedWarpLocation;
	FName WarpTargetName;
	FRotator TargetRotator = (WarpTargetRotations.Num() > 0)/*false */ ? WarpTargetRotations[0] : CharacterOwner->GetActorRotation();

	// Check the number of warp targets
	UE_LOG(LogTemp, Warning, TEXT("Number of Warp Targets: %d"), WarpTargetLocations.Num());
	if (WarpTargetLocations.Num() < 2)
	{
		PostInitializeClimbUp();
		return;
	}
	// Use a range-based for loop to iterate through WarpTargetLocations
	int32 Index = 0;
	StopMovementImmediately();
	for (const FVector& WarpLocation : WarpTargetLocations)
	{
		// Log the index and warp location (optional, for debugging)
		UE_LOG(LogTemp, Warning, TEXT("Index: %d, Warp Location: %s"), Index, *WarpLocation.ToString());
		// Call the function on ClimbUpData with the current warp location or index
		AdjustedWarpLocation = ClimbUpData->AdjustAndUpdateWarpTarget(Index, WarpLocation, CharacterOwner, WarpTargetName);
		MotionWarpingComp->AddOrUpdateWarpTargetFromLocationAndRotation(WarpTargetName, AdjustedWarpLocation, TargetRotator);
		// Increment the index manually
		Index++;
	}
}

void UNewCharacterMovementComponent::PlayClimbUpMontage()
{
	if (CharacterOwner && CharacterOwner->GetMesh())
	{
		UAnimInstance* OwnerAnimInstance = CharacterOwner->GetMesh()->GetAnimInstance();
		if (OwnerAnimInstance)
		{
			if (!ClimbUpData)
			{
				PostInitializeClimbUp();
				return;
			}

			UAnimMontage* ClimbUpMontage = ClimbUpData->AdvancedMovementMontage;
			if (!ClimbUpMontage)
			{
				PostInitializeClimbUp();
				return;
			}
			float ClimbUpPlayRate = ClimbUpData->MontagePlayRate;
			float ClimbUpStartPosition = ClimbUpData->MontageStartDuration;

			OwnerAnimInstance->Montage_Play(ClimbUpMontage, ClimbUpPlayRate, EMontagePlayReturnType::MontageLength, ClimbUpStartPosition);
			// Bind to the montage blend out delegate
			FOnMontageBlendingOutStarted MontageBlendingOutDelegate;
			MontageBlendingOutDelegate.BindUObject(this, &UNewCharacterMovementComponent::OnClimbUpMontageEnded);
			OwnerAnimInstance->Montage_SetBlendingOutDelegate(MontageBlendingOutDelegate, ClimbUpMontage);

		}
	}
}

void UNewCharacterMovementComponent::PostInitializeClimbUp()
{
	if (CharacterOwner && CharacterOwner->GetMesh())
	{
		UAnimInstance* OwnerAnimInstance = CharacterOwner->GetMesh()->GetAnimInstance();
		if (OwnerAnimInstance && ClimbUpData && OwnerAnimInstance->Montage_IsPlaying(ClimbUpData->AdvancedMovementMontage)) OwnerAnimInstance->Montage_Stop(ClimbUpData->MontageBlendOutTime, ClimbUpData->AdvancedMovementMontage);
	}
	ClimbUpData = nullptr;
	WarpTargetLocations.Empty();
	WarpTargetRotations.Empty();
	SetMovementMode(MOVE_Walking);
	SetWallInfo(EWallSide::None, FHitResult());
	OnClimbUpStop.Broadcast();

}

void UNewCharacterMovementComponent::OnClimbUpMontageEnded(UAnimMontage* MontageToPlay, bool bIsInterupted)
{
	if (ClimbUpData)
	{
		if (GEngine && bShowClimbUpDebugTraces) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Valid!"));
		if (MontageToPlay == ClimbUpData->AdvancedMovementMontage && !bIsInterupted) StopClimbUp();
	}
	if (GEngine && bShowClimbUpDebugTraces)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("InValid!"));

}

void UNewCharacterMovementComponent::PhysClimbUp(float deltaTime, int32 Iterations)
{
	PhysFlying(deltaTime, Iterations);
}


#pragma endregion

#pragma region Flying

void UNewCharacterMovementComponent::StartFly()
{
	ActivateExtendedMovementFlag((uint8)EExtendedMovementFlag::CFLAG_WantsToFly);
}

void UNewCharacterMovementComponent::StopFly()
{
	ClearExtendedMovementFlag((uint8)EExtendedMovementFlag::CFLAG_WantsToFly);
}

bool UNewCharacterMovementComponent::CanFly() const
{
	if (!NavAgentProps.bCanFly) return false;
	if (!(IsFalling() || IsMovementMode(MOVE_Walking) || IsSliding() || IsCrouching())) return false;

	FVector Location = CharacterOwner->GetActorLocation();
	FVector Upward = CharacterOwner->GetActorUpVector();
	FVector AdjustedLocation = Location + Upward * CharacterOwner->BaseEyeHeight;
	FVector EndLocation = AdjustedLocation + Upward * MaxClearanceInUpForStartFlying;


	// Perform the sphere trace (raycast with a radius)
	FHitResult HitResult;
	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		AdjustedLocation,
		EndLocation,
		FQuat::Identity, // No rotation needed for this case
		ECC_Visibility,  // Use visibility channel, adjust if necessary
		FCollisionShape::MakeSphere(CapHH() / 2),
		GetIgnoreCharacterParams()
	);

#if WITH_EDITOR
	// Debug trace to visualize the flying check in the editor
	if (bShowFlyingDebugTraces)
	{
		FColor LineColor = bHit ? FColor::Red : FColor::Green;
		DrawDebugLine(
			GetWorld(),
			AdjustedLocation,  // Starting point of the trace
			EndLocation,       // End point of the trace
			LineColor,         // Red for hit, green for no hit
			false,             // Don't persist after the frame
			1.0f,              // Display for 1 second
			0,                 // No depth priority
			2.0f               // Line thickness
		);
	}
#endif

#if WITH_EDITOR
	if (bShowFlyingDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Flying check: %s"), HitResult.IsValidBlockingHit() ? TEXT("Hit") : TEXT("No Hit")));

#endif
	// If we hit something, we can't fly
	return !HitResult.IsValidBlockingHit();
}

void UNewCharacterMovementComponent::StartFastFly()
{
	if (bCanFastFly)
	{
		ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastFly);
		OnFastFlyStart.Broadcast();
	}
}

void UNewCharacterMovementComponent::StopFastFly()
{
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastFly) && IsFlying())
	{
		ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastFly);
		OnFastFlyStop.Broadcast();
	}
}

bool UNewCharacterMovementComponent::CanFastFly() const
{
	return IsFlying() && bCanFastFly;
}

bool UNewCharacterMovementComponent::IsFastFlying() const
{
	return IsFlying() && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastFly);
}

void UNewCharacterMovementComponent::FlyingPhysics(float deltaTime, int32 Iterations)
{
	PhysFlying(deltaTime, Iterations);
}

void UNewCharacterMovementComponent::PhysFlying(float deltaTime, int32 Iterations)
{
	if (IsMovementMode(MOVE_Flying) && !(Velocity.Z > 0.0f)) {
		// Perform the downward sphere trace to check if we should start falling
		FVector Location = CharacterOwner->GetActorLocation();
		FVector Downward = -CharacterOwner->GetActorUpVector();  // Downward direction
		FVector AdjustedLocation = Location + Downward * CapHH();
		float LerpFactor = FMath::Clamp((Velocity.Z / (-MaxFastFlySpeed)), 0.0f, 1.0f);
		float SmoothFactor = FMath::Lerp(4.0f, 1.0f, LerpFactor);
		FVector EndLocation = AdjustedLocation + Downward * MinHeightToFly / SmoothFactor;

		//FVector EndLocation = AdjustedLocation + Downward * MinHeightToFly / ((Velocity.Z < 0.0f) ? 1 : 4);

		// Perform the sphere trace using a collision profile
		FHitResult HitResult;
		bool bHit = GetWorld()->SweepSingleByProfile(
			HitResult,
			AdjustedLocation,
			EndLocation,
			FQuat::Identity, // No rotation needed for this case
			TEXT("BlockAll"), // Use the "BlockAll" collision profile or your custom profile name
			FCollisionShape::MakeSphere(CapR()), // Adjust for the character's capsule radius divided by 2
			GetIgnoreCharacterParams() // Custom collision query params to ignore the character
		);

#if WITH_EDITOR
		// Debug trace visualization
		if (bShowFlyingDebugTraces)
		{
			FColor LineColor = bHit ? FColor::Red : FColor::Green;
			DrawDebugLine(GetWorld(), AdjustedLocation, EndLocation, LineColor, false, -1, 0, 2.0);
			// Draw a debug sphere at the starting location
			DrawDebugSphere(GetWorld(), AdjustedLocation, CapR(), 12, FColor::Blue, false, -1); // Sphere with radius 10 and 12 segments

			if (bHit) DrawDebugPoint(GetWorld(), HitResult.Location, 10.0f, FColor::Red, false, -1);

		}
#endif

		// If something is hit, transition to falling
		if (HitResult.IsValidBlockingHit())
		{
#if WITH_EDITOR
			if (bShowFlyingDebugTraces) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Unable to fly"));
			// Start falling if the trace hits something below
#endif

			StopFly();
		}

	}
	/**/
	// Start falling if the trace hits something below
	Super::PhysFlying(deltaTime, Iterations);
}

#pragma endregion

#pragma region Swiming

void UNewCharacterMovementComponent::StartFastSwim()
{
	if (bCanFastSwim)
	{
		ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim);
		OnFastSwimStart.Broadcast();
	}
}

void UNewCharacterMovementComponent::StopFastSwim()
{

	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim) && IsSwimming())
	{
		ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim);
		OnFastSwimStop.Broadcast();
	}
}

bool UNewCharacterMovementComponent::CanFastSwim() const
{
	return IsMovementMode(MOVE_Swimming) && bCanFastSwim;
}

bool UNewCharacterMovementComponent::IsFastSwimming() const
{
	return  IsMovementMode(MOVE_Swimming) && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim);
}

#pragma endregion

#pragma region Helper

FCollisionQueryParams UNewCharacterMovementComponent::GetIgnoreCharacterParams() const
{
	// Create a FCollisionQueryParams instance and set it to ignore the CharacterOwner
	FCollisionQueryParams QueryParams;
	if (CharacterOwner)
	{
		// Make sure the query ignores the owning character
		QueryParams.AddIgnoredActor(CharacterOwner);
	}
	return QueryParams;
}

float UNewCharacterMovementComponent::CapR() const
{
	return CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius();
}

float UNewCharacterMovementComponent::CapHH() const
{
	return CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
}

bool UNewCharacterMovementComponent::IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const
{
	return MovementMode == MOVE_Custom && CustomMovementMode == InCustomMovementMode;
}

bool UNewCharacterMovementComponent::IsMovementMode(EMovementMode InMovementMode) const
{
	return InMovementMode == MovementMode;
}

void UNewCharacterMovementComponent::SetWallInfo(EWallSide NewWallSide, const FHitResult& NewWallHit)
{
	// Update CurrentWallInfo with the new values
	CurrentWall.WallSide = NewWallSide;
	CurrentWall.WallHit = NewWallHit;
}

bool UNewCharacterMovementComponent::HandlePendingLaunch()
{
	if (IsMovementMode(MOVE_Flying) && !PendingLaunchVelocity.IsZero() && HasValidData())
	{
		Velocity = PendingLaunchVelocity;
		PendingLaunchVelocity = FVector::ZeroVector;
		bForceNextFloorCheck = true;
		return true;
	}
	else
	{
		return Super::HandlePendingLaunch();
	}
}

bool UNewCharacterMovementComponent::IsMovingOnGround() const
{
	return IsProning() || IsSliding() || Super::IsMovingOnGround();
}

void UNewCharacterMovementComponent::PlayMonatage(UAnimMontage* InMontage, float PlayRate, float StartingLocation)
{
	CharacterOwner->GetMesh()->GetAnimInstance()->Montage_Play(InMontage, PlayRate, EMontagePlayReturnType::MontageLength, StartingLocation);
}

bool UNewCharacterMovementComponent::CheckHHUpdateBig(float InHH, bool UseDefault)
{
	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	if (!UseDefault) DefaultCapsuleHalfHeight = InHH;

	// Calculate the height adjustment to check space for exiting prone
	float HHAdjusted = DefaultCapsuleHalfHeight - CapHH();
	FHitResult HitResult;

	// Determine the location to perform the sweep
	FVector CheckLocation = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (HHAdjusted + 1.0f);

	// Perform a capsule sweep to check if the space is clear
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		CheckLocation,
		CheckLocation,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeCapsule(CapR(), DefaultCapsuleHalfHeight),
		GetIgnoreCharacterParams()
	);

#if WITH_EDITOR

	if (bShowProneDebugTraces)
	{
		// Draw debug capsule at the CheckLocation
		DrawDebugCapsule(
			GetWorld(),
			CheckLocation,
			DefaultCapsuleHalfHeight,
			CapR(),
			FQuat::Identity,
			bHit ? FColor::Red : FColor::Green,
			false,
			-1,
			0,
			2.0f
		);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, -1, FColor::Yellow, false, 1.0f);
		}

	}
#endif

	// Return true if the space is clear (no blocking hit or penetration), allowing the character to stop prone
	return !(HitResult.bBlockingHit || HitResult.bStartPenetrating);
}

bool UNewCharacterMovementComponent::CheckHHUpdateSmall(float InHH)
{
	float HHAdjusted = InHH - CapHH();
	FHitResult HitResult;
	FVector Loc = CharacterOwner->GetActorLocation() + CharacterOwner->GetActorUpVector() * (HHAdjusted + 1.0f);

	// Perform a capsule sweep to check if the space is clear for prone movement
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		Loc,
		Loc,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeCapsule(CapR(), InHH),
		GetIgnoreCharacterParams()
	);

#if WITH_EDITOR

	if (bShowProneDebugTraces)
	{
		// Draw debug capsule at the location
		DrawDebugCapsule(
			GetWorld(),
			Loc,
			InHH,
			CapR(),
			FQuat::Identity,
			bHit ? FColor::Red : FColor::Green, // Red if hit, green if clear
			false, // Non-persistent (will disappear after duration)
			-1,  // Duration (in seconds)
			0,     // Depth priority (0 is the default)
			2.0f   // Thickness of the line
		);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, 10.0f, FColor::Yellow, false, -1);
		}
	}
#endif

	// Return true if the space is clear (no blocking hit or penetration), allowing the character to be prone
	return !(HitResult.bBlockingHit || HitResult.bStartPenetrating);

}

void UNewCharacterMovementComponent::HHUpdateBig(float InHH, bool UseDefault)
{

	// Get the default character's capsule half-height
	ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
	float DefaultCapsuleHalfHeight = DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	if (!UseDefault)DefaultCapsuleHalfHeight = InHH;
	if (CapHH() != DefaultCapsuleHalfHeight)
	{
		FVector Start = CharacterOwner->GetActorLocation();
		FVector End = Start + CharacterOwner->GetActorUpVector() * CapHH() * (-2);
		FHitResult HitResult;

		// Perform the sphere sweep
		bool bHit = GetWorld()->SweepSingleByProfile(
			HitResult,
			Start,
			End,
			FQuat::Identity,
			TEXT("BlockAll"),
			FCollisionShape::MakeSphere(CapR()),
			GetIgnoreCharacterParams()
		);

		if (bHit && (HitResult.bBlockingHit || HitResult.bStartPenetrating))
		{
			FVector Updated = HitResult.Location + CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight;
			CharacterOwner->SetActorLocation(Updated);
			CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(DefaultCapsuleHalfHeight, true);
			CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * DefaultCapsuleHalfHeight * (-1));
		}

#if WITH_EDITOR

		if (bShowProneDebugTraces)
		{
			// Draw debug for the sweep start and end points
			DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, -1, 0, 2.0f);

			// Draw a debug sphere at the start and end positions
			DrawDebugSphere(GetWorld(), Start, CapR(), 12, FColor::Blue, false, -1);
			DrawDebugSphere(GetWorld(), End, CapR(), 12, FColor::Red, false, -1);

			// If there was a hit, draw a point at the hit location
			if (bHit)
			{
				DrawDebugPoint(GetWorld(), HitResult.Location, -1, FColor::Yellow, false, 1.0f);
			}
		}
#endif
	}
}

void UNewCharacterMovementComponent::HHUpdateSmall(float InHH)
{
	FVector Start = CharacterOwner->GetActorLocation();
	FVector End = Start + CharacterOwner->GetActorUpVector() * CapHH() * (-2);
	FHitResult HitResult;

	// Perform the sphere sweep
	bool bHit = GetWorld()->SweepSingleByProfile(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		TEXT("BlockAll"),
		FCollisionShape::MakeSphere(CapR()),
		GetIgnoreCharacterParams()
	);

	if (bHit && (HitResult.bBlockingHit || HitResult.bStartPenetrating))
	{
		FVector Updated = HitResult.Location + CharacterOwner->GetActorUpVector() * InHH;
		CharacterOwner->SetActorLocation(Updated);
		CharacterOwner->GetCapsuleComponent()->SetCapsuleHalfHeight(InHH, true);
		CharacterOwner->GetMesh()->SetRelativeLocation(CharacterOwner->GetActorUpVector() * InHH * (-1));
	}

#if WITH_EDITOR

	if (bShowProneDebugTraces)
	{
		// Draw debug for the sweep start and end points
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, -1, 0, 2.0f);

		// Draw a debug sphere at the start and end positions
		DrawDebugSphere(GetWorld(), Start, CapR(), 12, FColor::Blue, false, -1);
		DrawDebugSphere(GetWorld(), End, CapR(), 12, FColor::Red, false, -1);

		// If there was a hit, draw a point at the hit location
		if (bHit)
		{
			DrawDebugPoint(GetWorld(), HitResult.Location, -1, FColor::Yellow, false, 1.0f);
		}
	}
#endif

}

void UNewCharacterMovementComponent::ActivateAdvancedMovementFlag(uint8 FlagToActivate)
{
	AdvancedMovementFlag |= FlagToActivate;

}

void UNewCharacterMovementComponent::ClearAdvancedMovementFlag(uint8 FlagToClear)
{
	AdvancedMovementFlag &= ~FlagToClear;
}

void UNewCharacterMovementComponent::ActivateSpecialMovementFlag(uint8 FlagToActivate)
{
	SpecialMovementFlag |= FlagToActivate;

}

void UNewCharacterMovementComponent::ClearSpecialMovementFlag(uint8 FlagToClear)
{
	SpecialMovementFlag &= ~FlagToClear;
}

void UNewCharacterMovementComponent::ActivateFastMovementFlag(uint8 FlagToActivate)
{
	FastMovementFlag |= FlagToActivate;

}

void UNewCharacterMovementComponent::ClearFastMovementFlag(uint8 FlagToClear)
{
	FastMovementFlag &= ~FlagToClear;
}

void UNewCharacterMovementComponent::ActivateExtendedMovementFlag(uint8 FlagToActivate)
{
	ExtendedMovementFlag |= FlagToActivate;
}

void UNewCharacterMovementComponent::ClearExtendedMovementFlag(uint8 FlagToClear)
{
	ExtendedMovementFlag &= ~FlagToClear;
}

#pragma endregion

#pragma region Networking

bool UNewCharacterMovementComponent::FSavedMove_New::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const
{
	FSavedMove_New* NewMovementMove = static_cast<FSavedMove_New*>(NewMove.Get());
	if (SavedDashLocation != NewMovementMove->SavedDashLocation)return false;
	if (Saved_FastMovementFlag != NewMovementMove->Saved_FastMovementFlag)return false;
	if (Saved_ExtendedMovementFlag != NewMovementMove->Saved_ExtendedMovementFlag)return false;
	if (Saved_AdvancedMovementFlag != NewMovementMove->Saved_AdvancedMovementFlag)return false;
	if (Saved_SpecialMovementFlag != NewMovementMove->Saved_SpecialMovementFlag) return false;
	return FSavedMove_Character::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

void UNewCharacterMovementComponent::FSavedMove_New::Clear()
{
	FSavedMove_Character::Clear();
	Saved_FastMovementFlag = 0;
	Saved_ExtendedMovementFlag = 0;
	Saved_AdvancedMovementFlag = 0;
	Saved_SpecialMovementFlag = 0;
	SavedDashLocation = FVector(0.0f, 0.0f, 0.0f);
}

void UNewCharacterMovementComponent::FSavedMove_New::SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
	FSavedMove_Character::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);
	UNewCharacterMovementComponent* CharacterMovement = Cast<UNewCharacterMovementComponent>(C->GetCharacterMovement());

	Saved_FastMovementFlag = CharacterMovement->FastMovementFlag;
	Saved_ExtendedMovementFlag = CharacterMovement->ExtendedMovementFlag;
	Saved_AdvancedMovementFlag = CharacterMovement->AdvancedMovementFlag;
	Saved_SpecialMovementFlag = CharacterMovement->SpecialMovementFlag;
	SavedDashLocation = CharacterMovement->DashLocation;
}

void UNewCharacterMovementComponent::FSavedMove_New::PrepMoveFor(ACharacter* C)
{
	Super::PrepMoveFor(C);
	UNewCharacterMovementComponent* CharacterMovement = Cast<UNewCharacterMovementComponent>(C->GetCharacterMovement());
	CharacterMovement->FastMovementFlag = Saved_FastMovementFlag;
	CharacterMovement->ExtendedMovementFlag = Saved_ExtendedMovementFlag;
	CharacterMovement->AdvancedMovementFlag = Saved_AdvancedMovementFlag;
	CharacterMovement->SpecialMovementFlag = Saved_SpecialMovementFlag;
	CharacterMovement->DashLocation = SavedDashLocation;
}

UNewCharacterMovementComponent::FNetworkPredictionData_Client_New::FNetworkPredictionData_Client_New(const UNewCharacterMovementComponent& ClientMovement) :Super(ClientMovement)
{
}

FSavedMovePtr UNewCharacterMovementComponent::FNetworkPredictionData_Client_New::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_New());
}

FNetworkPredictionData_Client* UNewCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner != nullptr)

		if (ClientPredictionData == nullptr)
		{
			UNewCharacterMovementComponent* MutableThis = const_cast<UNewCharacterMovementComponent*>(this);

			MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_New(*this);
			MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.f;
			MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.f;
		}
	return ClientPredictionData;
}

void UNewCharacterMovementComponent::MoveAutonomous(float ClientTimeStamp, float DeltaTime, uint8 CompressedFlags, const FVector& NewAccel)
{
	FNewNetworkMoveData* NewMoveData = static_cast<FNewNetworkMoveData*>(GetCurrentNetworkMoveData());
	if (NewMoveData != nullptr)
	{
		DashLocation = NewMoveData->SafeDashLocation;
		FastMovementFlag = NewMoveData->Safe_FastMovementFlag;
		ExtendedMovementFlag = NewMoveData->Safe_ExtendedMovementFlag;
		AdvancedMovementFlag = NewMoveData->Safe_AdvancedMovementFlag;
		SpecialMovementFlag = NewMoveData->Safe_SpecialMovementFlag;
	}
	Super::MoveAutonomous(ClientTimeStamp, DeltaTime, CompressedFlags, NewAccel);
}

void UNewCharacterMovementComponent::FNewNetworkMoveData::ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType)
{
	Super::ClientFillNetworkMoveData(ClientMove, MoveType);

	const FSavedMove_New& NewSavedMove = static_cast<const FSavedMove_New&>(ClientMove);
	SafeDashLocation = NewSavedMove.SavedDashLocation;
	Safe_FastMovementFlag = NewSavedMove.Saved_FastMovementFlag;
	Safe_ExtendedMovementFlag = NewSavedMove.Saved_ExtendedMovementFlag;
	Safe_AdvancedMovementFlag = NewSavedMove.Saved_AdvancedMovementFlag;
	Safe_SpecialMovementFlag = NewSavedMove.Saved_SpecialMovementFlag;
}

bool UNewCharacterMovementComponent::FNewNetworkMoveData::Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType)
{
	Super::Serialize(CharacterMovement, Ar, PackageMap, MoveType);
	SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, Safe_FastMovementFlag, 0);
	SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, Safe_ExtendedMovementFlag, 0);
	SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, Safe_SpecialMovementFlag, 0);
	SerializeOptionalValue<FVector>(Ar.IsSaving(), Ar, SafeDashLocation, FVector(0.f, 0.f, 0.f));
	SerializeOptionalValue<uint8>(Ar.IsSaving(), Ar, Safe_AdvancedMovementFlag, 0);
	return !Ar.IsError();
}

UNewCharacterMovementComponent::FNewCharacterNetworkMoveDataContainer::FNewCharacterNetworkMoveDataContainer()
{
	NewMoveData = &NewDefaultMoveData[0];
	PendingMoveData = &NewDefaultMoveData[1];
	OldMoveData = &NewDefaultMoveData[2];
}

#pragma endregion

#pragma region Overrided

void UNewCharacterMovementComponent::PhysCustom(float DeltaTime, int32 Iterations)
{
	Super::PhysCustom(DeltaTime, Iterations);
	switch (CustomMovementMode)
	{
	case CMOVE_Slide:
		PhysSlide(DeltaTime, Iterations);
		break;
	case CMOVE_Prone:
		PhysProne(DeltaTime, Iterations);
		break;
	case CMOVE_WallRun:
		PhysWallRun(DeltaTime, Iterations);
		break;
	case CMOVE_Climb:
		PhysClimb(DeltaTime, Iterations);
		break;
	case CMOVE_Dash:
		PhysDash(DeltaTime, Iterations);
		break;
	case CMOVE_Vault:
		PhysVault(DeltaTime, Iterations);
		break;
	case CMOVE_Mantle:
		PhysMantle(DeltaTime, Iterations);
		break;
	case CMOVE_ClimbUp:
		PhysClimbUp(DeltaTime, Iterations);
		break;
	default:
		break;
	}
}

void UNewCharacterMovementComponent::UpdateCharacterStateBeforeMovement(float DeltaSeconds)
{
	if (CharacterOwner->GetLocalRole() != ROLE_SimulatedProxy)
	{
		if (IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToFly) && !IsMovementMode(MOVE_Flying))
		{
			if (CanFly())
			{
				UnCrouch();
				SetMovementMode(MOVE_Flying);
				CharacterOwner->LaunchCharacter(FlightEnterImpulse, false, true);
				OnFlyStart.Broadcast();
			}
		}
		else if ((!IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToFly) && MovementMode == MOVE_Flying))
		{
			SetMovementMode(MOVE_Falling);
			CharacterOwner->LaunchCharacter(-2 * FlightEnterImpulse, false, true);
			OnFlyStop.Broadcast();
		}
		if (MovementMode == MOVE_Walking && IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToSlide) && !IsSliding())
		{
			if (CanSlide()) EnterSlide();
		}
		else if (IsSliding() && !IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToSlide)) ExitSlide();

		if (MovementMode == MOVE_Walking && IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToProne) &&
			!IsProning() && CanProne()) EnterProne();
		else if ((!IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToProne) && IsProning()))ExitProne();
		if (IsFalling() && IsProning()) StopProne();

		if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToDash) && !IsDashing())
		{
			bool ShouldDash = false;;
			GetDashLocation(DashLocation, ShouldDash);
			if (ShouldDash) SetMovementMode(MOVE_Custom, CMOVE_Dash);
			OnDashStart.Broadcast();

		}
		else if (!IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToDash) && IsDashing())
		{
			SetMovementMode(MOVE_Walking);
			StopMovementImmediately();
			OnDashStop.Broadcast();
		}

		if (IsAdvancedFlagActive((uint8)EAdvancedMovementFlag::CFLAG_WantsToVault) && !IsVaulting()) EnterVault();
		else if (!IsAdvancedFlagActive((uint8)EAdvancedMovementFlag::CFLAG_WantsToVault) && IsVaulting()) PostInitializeVault();
		if (IsAdvancedFlagActive((uint8)EAdvancedMovementFlag::CFLAG_WantsToMantle) && !IsMantling()) EnterMantle();
		else if (!IsAdvancedFlagActive((uint8)EAdvancedMovementFlag::CFLAG_WantsToMantle) && IsMantling()) PostInitializeMantle();
		if (IsAdvancedFlagActive((uint8)EAdvancedMovementFlag::CFLAG_WantsToClimbUp) && !IsClimbingUp()) EnterClimbUp();
		else if (!IsAdvancedFlagActive((uint8)EAdvancedMovementFlag::CFLAG_WantsToClimbUp) && IsClimbingUp()) PostInitializeClimbUp();

		if (IsSpecialFlagActive((uint8)ESpecialMovementFlag::CFLAG_WantsToWallRun) && !IsWallRunning())
		{
			if (CanWallRun())
			{
				SetMovementMode(MOVE_Custom, CMOVE_WallRun);
				OnWallRunStart.Broadcast(CurrentWall);
				float WallRunDuration = (MaxWallRunSpeed - MinWallRunSpeed) / MinWallRunHeight;
				float VerticleSpeedDuration = WallRunDuration / 2.0f;
				if (bAutoEndWallRun) GetWorld()->GetTimerManager().SetTimer(WallRunTimerHandle, this, &UNewCharacterMovementComponent::StopWallRun, WallRunDuration, false);
				if (bApplyVerticleWallRunSpeed)
				{
					ActivateSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_WantsToVerticleWallRun);
					GetWorld()->GetTimerManager().SetTimer(VerticleSpeedTimerHandle, this, &UNewCharacterMovementComponent::StopVerticleWallRun, VerticleSpeedDuration, false);
				}
			}
		}
		else if (!IsSpecialFlagActive((uint8)ESpecialMovementFlag::CFLAG_WantsToWallRun) && IsWallRunning())
		{
			GetWorld()->GetTimerManager().ClearTimer(WallRunTimerHandle);
			GetWorld()->GetTimerManager().ClearTimer(VerticleSpeedTimerHandle);
			if (bApplyVerticle) ActivateSpecialMovementFlag((uint8)ESpecialMovementFlag::CFLAG_WantsToVerticleWallRun);
			SetMovementMode(MOVE_Walking);
			SetWallInfo(EWallSide::None, FHitResult());
			OnWallRunStop.Broadcast();
		}
		if (IsSpecialFlagActive((uint8)ESpecialMovementFlag::CFLAG_WantsToClimb) && !IsClimbing())
		{
			if (CanClimb())
			{
				if (IsFlying())
					StopFly();
				bOrientRotationToMovement = false;
				SetMovementMode(MOVE_Custom, CMOVE_Climb);
				OnClimbStart.Broadcast(CurrentWall);
			}
		}
		else if (!IsSpecialFlagActive((uint8)ESpecialMovementFlag::CFLAG_WantsToClimb) && IsClimbing())
		{
			bOrientRotationToMovement = true;
			SetMovementMode(MOVE_Walking);
			SetWallInfo(EWallSide::None, FHitResult());
			OnClimbStop.Broadcast();
		}
	}

	Super::UpdateCharacterStateBeforeMovement(DeltaSeconds);

}

void UNewCharacterMovementComponent::UpdateCharacterStateAfterMovement(float DeltaSeconds)
{
	if ((!IsExtendedFlagActive((uint8)EExtendedMovementFlag::CFLAG_WantsToProne)
		&& IsProning()) && CharacterOwner->GetLocalRole() != ROLE_SimulatedProxy) ExitProne();
	Super::UpdateCharacterStateAfterMovement(DeltaSeconds);
}

void UNewCharacterMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	if (PreviousMovementMode == MOVE_Custom && PreviousCustomMode == CMOVE_Slide)		StopSlide();
	if (PreviousMovementMode == MOVE_Custom && PreviousCustomMode == CMOVE_Prone)		StopProne();
	if (PreviousMovementMode == MOVE_Custom && PreviousCustomMode == CMOVE_WallRun)		StopWallRun();
	if ((PreviousMovementMode == MOVE_Custom) && PreviousCustomMode == CMOVE_Climb)		StopClimb();
	if ((PreviousMovementMode == MOVE_Custom) && PreviousCustomMode == CMOVE_Vault)		StopVault();
	if ((PreviousMovementMode == MOVE_Custom) && PreviousCustomMode == CMOVE_Mantle)	StopMantle();
	if ((PreviousMovementMode == MOVE_Custom) && PreviousCustomMode == CMOVE_ClimbUp)	StopClimbUp();

	if (IsCustomMovementMode(CMOVE_Slide))		StartSlide();
	if (IsCustomMovementMode(CMOVE_Prone))		StartProne();
	if (IsCustomMovementMode(CMOVE_WallRun))	StartWallRun();
	if (IsCustomMovementMode(CMOVE_Climb))		StartClimb();
	if (IsCustomMovementMode(CMOVE_Vault))		StartVault();
	if (IsCustomMovementMode(CMOVE_Mantle))		StartMantle();
	if (IsCustomMovementMode(CMOVE_ClimbUp))	StartClimbUp();

	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
}

float UNewCharacterMovementComponent::GetMaxSpeed() const
{
	if (IsMovementMode(MOVE_Walking) && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToSprint) && !IsCrouching()) return MaxSprintSpeed;
	if (IsMovementMode(MOVE_Walking) && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToCrouchSprint) && IsCrouching()) return MaxCrouchSprintSpeed;
	if (IsMovementMode(MOVE_Flying) && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastFly)) return MaxFastFlySpeed;
	if (IsMovementMode(MOVE_Swimming) && IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim)) return MaxFastSwimSpeed;
	if (MovementMode != MOVE_Custom) return Super::GetMaxSpeed();
	switch (CustomMovementMode)
	{
	case CMOVE_Slide:
		return MaxSlideSpeed;
	case CMOVE_Prone:
		return MaxProneSpeed;
	case CMOVE_WallRun:
		return MaxWallRunSpeed;
	case CMOVE_Climb:
		return MaxClimbSpeed;
	case CMOVE_Dash:
		return MaxDashSpeed;
	case CMOVE_Vault:
		return 0.0f;
	case CMOVE_Mantle:
		return 0.0f;
	case CMOVE_ClimbUp:
		return 0.0f;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("Invalid Movement Mode"))
			return -1.f;
	}
}

float UNewCharacterMovementComponent::GetMaxAcceleration() const
{

	if (MovementMode != MOVE_Custom) return Super::GetMaxAcceleration();

	switch (CustomMovementMode)
	{
	case CMOVE_Slide:
		return MaxSlideAcceleration;
	case CMOVE_Prone:
		return MaxProneAcceleration;
	case CMOVE_WallRun:
		return MaxWallRunAcceleration;
	case CMOVE_Climb:
		return MaxClimbAcceleration;
	case CMOVE_Dash:
		return 1000.0f;
	case CMOVE_Vault:
		return 0.0f;
	case CMOVE_Mantle:
		return 0.0f;
	case CMOVE_ClimbUp:
		return 0.0f;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("Invalid Movement Mode"))
			return -1.f;
	}
}

float UNewCharacterMovementComponent::GetMaxBrakingDeceleration() const
{
	if (MovementMode != MOVE_Custom) return Super::GetMaxBrakingDeceleration();

	switch (CustomMovementMode)
	{
	case CMOVE_Slide:
		return BrakingDecelerationSliding;
	case CMOVE_Prone:
		return BrakingDecelerationProning;
	case CMOVE_WallRun:
		return 0.0f;
	case CMOVE_Climb:
		return MaxBrakingDecelerationClimb;
	case CMOVE_Dash:
		return 1000.0f;
	case CMOVE_Vault:
		return 10000.0f;
	case CMOVE_Mantle:
		return 10000.0f;
	case CMOVE_ClimbUp:
		return 10000.0f;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("Invalid Movement Mode"))
			return -1.f;
	}
}

FVector UNewCharacterMovementComponent::ConstrainAnimRootMotionVelocity(const FVector& RootMotionVelocity, const FVector& CurrentVelocity) const
{
	return IsCustomMovementMode(CMOVE_Vault) || IsCustomMovementMode(CMOVE_Mantle) || IsCustomMovementMode(CMOVE_ClimbUp) ? RootMotionVelocity : Super::ConstrainAnimRootMotionVelocity(RootMotionVelocity, CurrentVelocity);
}

bool UNewCharacterMovementComponent::DoJump(bool bReplayingMoves)
{

	if (IsSliding())
	{
		StopSlide();
		ExitSlide();
	}
	if (Super::DoJump(bReplayingMoves))
	{
		if (IsWallRunning())
		{
			FVector Start = UpdatedComponent->GetComponentLocation();
			FVector CastDelta = UpdatedComponent->GetRightVector() * CapR() * 2;
			FVector End = IsWallRunOnRightSide() ? Start + CastDelta : Start - CastDelta;
			auto Params = GetIgnoreCharacterParams();
			FHitResult WallHit;
			GetWorld()->LineTraceSingleByProfile(WallHit, Start, End, "BlockAll", Params);
#if WITH_EDITOR
			if (bShowWallRunDebugTraces) DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 5.0f, 0, 1);
#endif
			Velocity += WallHit.Normal * MaxWallRunJumpOffForce;
		}
		return true;
	}
	return false;

}

bool UNewCharacterMovementComponent::CanAttemptJump() const
{
	return (Super::CanAttemptJump() || IsWallRunning()) && !IsProning();
}

void UNewCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UNewCharacterMovementComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UNewCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

#pragma endregion

#pragma region RPC

void UNewCharacterMovementComponent::Server_UpdateHHEnterProne_Implementation()
{
	Multicast_UpdateHHEnterProne();
}

void UNewCharacterMovementComponent::Server_UpdateHHEnterSlide_Implementation()
{
	Multicast_UpdateHHEnterSlide();
}

void UNewCharacterMovementComponent::Multicast_UpdateHHEnterProne_Implementation()
{
	if (!CharacterOwner->IsLocallyControlled()) HHUpdateProne();
}

void UNewCharacterMovementComponent::Multicast_UpdateHHEnterSlide_Implementation()
{
	if (!CharacterOwner->IsLocallyControlled()) HHUpdateSlide();
}

void UNewCharacterMovementComponent::Server_UpdateHHExitProne_Implementation(bool Crouch)
{
	Multicast_UpdateHHExitProne(Crouch);
}

void UNewCharacterMovementComponent::Server_UpdateHHExitSlide_Implementation()
{
	Multicast_UpdateHHExitSlide();
}

void UNewCharacterMovementComponent::Multicast_UpdateHHExitProne_Implementation(bool Crouch)
{
	if (!CharacterOwner->IsLocallyControlled()) HHUpdateStopProne(Crouch);
}

void UNewCharacterMovementComponent::Multicast_UpdateHHExitSlide_Implementation()
{
	if (!CharacterOwner->IsLocallyControlled()) HHUpdateStopSlide();

}

void UNewCharacterMovementComponent::Multicast_PlayVault_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation)
{
	if (!CharacterOwner->IsLocallyControlled()) PlayMonatage(InMontage, PlayRate, StartingLocation);

}

void UNewCharacterMovementComponent::Server_PlayVault_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation)
{
	Multicast_PlayVault(InMontage, PlayRate, StartingLocation);
}

void UNewCharacterMovementComponent::Multicast_PlayMantle_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation)
{
	if (!CharacterOwner->IsLocallyControlled()) PlayMonatage(InMontage, PlayRate, StartingLocation);
}

void UNewCharacterMovementComponent::Server_PlayMantle_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation)
{
	Multicast_PlayMantle(InMontage, PlayRate, StartingLocation);
}

void UNewCharacterMovementComponent::Multicast_PlayClimbUp_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation)
{
	if (!CharacterOwner->IsLocallyControlled()) PlayMonatage(InMontage, PlayRate, StartingLocation);
}

void UNewCharacterMovementComponent::Server_PlayClimbUp_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation)
{
	Multicast_PlayClimbUp(InMontage, PlayRate, StartingLocation);
}

void UNewCharacterMovementComponent::Multicast_UpdateHHExitVault_Implementation()
{
	if (!CharacterOwner->IsLocallyControlled()) HHUpdateStopVault();
}

void UNewCharacterMovementComponent::Multicast_UpdateHHEnterVault_Implementation()
{
	if (!CharacterOwner->IsLocallyControlled()) HHUpdateVault();
}

#pragma endregion

#pragma region Extra

void UNewCharacterMovementComponent::StartFastMovement()
{
	if (bCanSprint ) ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToSprint);
	if (bCanCrouchSprint) ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToCrouchSprint);
	if (bCanFastFly) ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastFly);
	if (bCanFastSwim) ActivateFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim);
}

void UNewCharacterMovementComponent::StopFastMovement()
{
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToSprint)) ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToSprint);
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToCrouchSprint)) ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToCrouchSprint);
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastFly)) ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastFly);
	if (IsFastFlagActive((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim)) ClearFastMovementFlag((uint8)EFastMovementFlag::CFLAG_WantsToFastSwim);
}

#pragma endregion

