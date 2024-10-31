// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NewCharacterMovementComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
class UClimbUpPrimaryDataAsset;
class UMantlePrimaryDataAsset;
class UVaultPrimaryDataAsset;
enum class EWallSide : uint8;
struct FCurrentWallInfo;
struct FHitResult;
#ifdef CHARACTERLOCOMOTIONSYSTEM_NewCharacterMovementComponent_generated_h
#error "NewCharacterMovementComponent.generated.h already included, missing '#pragma once' in NewCharacterMovementComponent.h"
#endif
#define CHARACTERLOCOMOTIONSYSTEM_NewCharacterMovementComponent_generated_h

#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_142_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCurrentWallInfo_Statics; \
	CHARACTERLOCOMOTIONSYSTEM_API static class UScriptStruct* StaticStruct();


template<> CHARACTERLOCOMOTIONSYSTEM_API UScriptStruct* StaticStruct<struct FCurrentWallInfo>();

#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_160_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnSprintStart_DelegateWrapper(const FMulticastScriptDelegate& OnSprintStart);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_163_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnSprintStop_DelegateWrapper(const FMulticastScriptDelegate& OnSprintStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_166_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnCrouchSprintStart_DelegateWrapper(const FMulticastScriptDelegate& OnCrouchSprintStart);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_169_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnCrouchSprintStop_DelegateWrapper(const FMulticastScriptDelegate& OnCrouchSprintStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_172_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnProneStart_DelegateWrapper(const FMulticastScriptDelegate& OnProneStart);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_175_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnProneStop_DelegateWrapper(const FMulticastScriptDelegate& OnProneStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_178_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnSlideStart_DelegateWrapper(const FMulticastScriptDelegate& OnSlideStart);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_181_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnSlideStop_DelegateWrapper(const FMulticastScriptDelegate& OnSlideStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_187_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnWallRunStart_DelegateWrapper(const FMulticastScriptDelegate& OnWallRunStart, FCurrentWallInfo CurrentWall);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_190_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnWallRunStop_DelegateWrapper(const FMulticastScriptDelegate& OnWallRunStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_197_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnDashStart_DelegateWrapper(const FMulticastScriptDelegate& OnDashStart, FVector TargetLocation);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_201_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnDashStop_DelegateWrapper(const FMulticastScriptDelegate& OnDashStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_207_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnClimbStart_DelegateWrapper(const FMulticastScriptDelegate& OnClimbStart, FCurrentWallInfo CurrentWall);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_210_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnClimbStop_DelegateWrapper(const FMulticastScriptDelegate& OnClimbStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_216_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnClimbReachedUpLedge_DelegateWrapper(const FMulticastScriptDelegate& OnClimbReachedUpLedge, FCurrentWallInfo CurrentWall);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_222_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnVaultStart_DelegateWrapper(const FMulticastScriptDelegate& OnVaultStart, FCurrentWallInfo CurrentWall);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_225_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnVaultStop_DelegateWrapper(const FMulticastScriptDelegate& OnVaultStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_230_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnVaultInitialize_DelegateWrapper(const FMulticastScriptDelegate& OnVaultInitialize, UVaultPrimaryDataAsset* VaultData);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_236_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnMantleStart_DelegateWrapper(const FMulticastScriptDelegate& OnMantleStart, FCurrentWallInfo CurrentWall);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_239_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnMantleStop_DelegateWrapper(const FMulticastScriptDelegate& OnMantleStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_244_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnMantleInitialize_DelegateWrapper(const FMulticastScriptDelegate& OnMantleInitialize, UMantlePrimaryDataAsset* MantleData);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_250_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnClimbUpStart_DelegateWrapper(const FMulticastScriptDelegate& OnClimbUpStart, FCurrentWallInfo CurrentWall);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_253_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnClimbUpStop_DelegateWrapper(const FMulticastScriptDelegate& OnClimbUpStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_258_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnClimbUpInitialize_DelegateWrapper(const FMulticastScriptDelegate& OnClimbUpInitialize, UClimbUpPrimaryDataAsset* ClimbUpData);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_261_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnFastFlyStart_DelegateWrapper(const FMulticastScriptDelegate& OnFastFlyStart);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_264_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnFastFlyStop_DelegateWrapper(const FMulticastScriptDelegate& OnFastFlyStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_267_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnFlyStart_DelegateWrapper(const FMulticastScriptDelegate& OnFlyStart);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_270_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnFlyStop_DelegateWrapper(const FMulticastScriptDelegate& OnFlyStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_273_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnFastSwimStart_DelegateWrapper(const FMulticastScriptDelegate& OnFastSwimStart);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_276_DELEGATE \
CHARACTERLOCOMOTIONSYSTEM_API void FOnFastSwimStop_DelegateWrapper(const FMulticastScriptDelegate& OnFastSwimStop);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Server_PlayClimbUp_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation); \
	virtual void Multicast_PlayClimbUp_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation); \
	virtual void Server_PlayMantle_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation); \
	virtual void Multicast_PlayMantle_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation); \
	virtual void Server_PlayVault_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation); \
	virtual void Multicast_PlayVault_Implementation(UAnimMontage* InMontage, float PlayRate, float StartingLocation); \
	virtual void Multicast_UpdateHHExitSlide_Implementation(); \
	virtual void Multicast_UpdateHHExitVault_Implementation(); \
	virtual void Multicast_UpdateHHExitProne_Implementation(bool Crouch); \
	virtual void Server_UpdateHHExitSlide_Implementation(); \
	virtual void Server_UpdateHHExitProne_Implementation(bool Crouch); \
	virtual void Multicast_UpdateHHEnterSlide_Implementation(); \
	virtual void Multicast_UpdateHHEnterVault_Implementation(); \
	virtual void Multicast_UpdateHHEnterProne_Implementation(); \
	virtual void Server_UpdateHHEnterSlide_Implementation(); \
	virtual void Server_UpdateHHEnterProne_Implementation(); \
	DECLARE_FUNCTION(execServer_PlayClimbUp); \
	DECLARE_FUNCTION(execMulticast_PlayClimbUp); \
	DECLARE_FUNCTION(execServer_PlayMantle); \
	DECLARE_FUNCTION(execMulticast_PlayMantle); \
	DECLARE_FUNCTION(execServer_PlayVault); \
	DECLARE_FUNCTION(execMulticast_PlayVault); \
	DECLARE_FUNCTION(execMulticast_UpdateHHExitSlide); \
	DECLARE_FUNCTION(execMulticast_UpdateHHExitVault); \
	DECLARE_FUNCTION(execMulticast_UpdateHHExitProne); \
	DECLARE_FUNCTION(execServer_UpdateHHExitSlide); \
	DECLARE_FUNCTION(execServer_UpdateHHExitProne); \
	DECLARE_FUNCTION(execMulticast_UpdateHHEnterSlide); \
	DECLARE_FUNCTION(execMulticast_UpdateHHEnterVault); \
	DECLARE_FUNCTION(execMulticast_UpdateHHEnterProne); \
	DECLARE_FUNCTION(execServer_UpdateHHEnterSlide); \
	DECLARE_FUNCTION(execServer_UpdateHHEnterProne); \
	DECLARE_FUNCTION(execIsClimbingUp); \
	DECLARE_FUNCTION(execCanClimbUp); \
	DECLARE_FUNCTION(execStopClimbUp); \
	DECLARE_FUNCTION(execStartClimbUp); \
	DECLARE_FUNCTION(execIsMantling); \
	DECLARE_FUNCTION(execCanMantle); \
	DECLARE_FUNCTION(execFallingStopMantle); \
	DECLARE_FUNCTION(execStopMantle); \
	DECLARE_FUNCTION(execStartMantle); \
	DECLARE_FUNCTION(execIsVaulting); \
	DECLARE_FUNCTION(execCanVault); \
	DECLARE_FUNCTION(execGetVaultHalfHeight); \
	DECLARE_FUNCTION(execStopVault); \
	DECLARE_FUNCTION(execStartVault); \
	DECLARE_FUNCTION(execPreInitializeAdvancedMovement); \
	DECLARE_FUNCTION(execPhysCustomAdvancedMovement); \
	DECLARE_FUNCTION(execStopCustomAdvancedMovement); \
	DECLARE_FUNCTION(execStartCustomAdvancedMovement); \
	DECLARE_FUNCTION(execIsFastSwimming); \
	DECLARE_FUNCTION(execCanFastSwim); \
	DECLARE_FUNCTION(execStopFastSwim); \
	DECLARE_FUNCTION(execStartFastSwim); \
	DECLARE_FUNCTION(execStopFastFly); \
	DECLARE_FUNCTION(execStartFastFly); \
	DECLARE_FUNCTION(execStopFly); \
	DECLARE_FUNCTION(execStartFly); \
	DECLARE_FUNCTION(execIsFastFlying); \
	DECLARE_FUNCTION(execCanFastFly); \
	DECLARE_FUNCTION(execCanFly); \
	DECLARE_FUNCTION(execCanDashInCurrentState); \
	DECLARE_FUNCTION(execGetDashLocation); \
	DECLARE_FUNCTION(execIsDashing); \
	DECLARE_FUNCTION(execStopDash); \
	DECLARE_FUNCTION(execStartDash); \
	DECLARE_FUNCTION(execCanClimb); \
	DECLARE_FUNCTION(execIsClimbing); \
	DECLARE_FUNCTION(execGetUnrotatedClimbVelocity); \
	DECLARE_FUNCTION(execStopClimb); \
	DECLARE_FUNCTION(execStartClimb); \
	DECLARE_FUNCTION(execIsWallRunOnRightSide); \
	DECLARE_FUNCTION(execIsWallRunning); \
	DECLARE_FUNCTION(execStopWallRun); \
	DECLARE_FUNCTION(execStartWallRun); \
	DECLARE_FUNCTION(execCanWallRun); \
	DECLARE_FUNCTION(execIsSliding); \
	DECLARE_FUNCTION(execCanAutoSlide); \
	DECLARE_FUNCTION(execCanSlide); \
	DECLARE_FUNCTION(execGetSlideHalfHeight); \
	DECLARE_FUNCTION(execStopSlide); \
	DECLARE_FUNCTION(execStartSlide); \
	DECLARE_FUNCTION(execCanProne); \
	DECLARE_FUNCTION(execIsProning); \
	DECLARE_FUNCTION(execGetProneHalfHeight); \
	DECLARE_FUNCTION(execWantsToProne); \
	DECLARE_FUNCTION(execStopProne); \
	DECLARE_FUNCTION(execStartProne); \
	DECLARE_FUNCTION(execIsCrouchSprinting); \
	DECLARE_FUNCTION(execCanCrouchSprint); \
	DECLARE_FUNCTION(execStopCrouchSprint); \
	DECLARE_FUNCTION(execStartCrouchSprint); \
	DECLARE_FUNCTION(execIsSprinting); \
	DECLARE_FUNCTION(execCanSprint); \
	DECLARE_FUNCTION(execStopSprint); \
	DECLARE_FUNCTION(execStartSprint); \
	DECLARE_FUNCTION(execIsInCustomExtended); \
	DECLARE_FUNCTION(execStopCustomExtended); \
	DECLARE_FUNCTION(execStartCustomExtended); \
	DECLARE_FUNCTION(execPhysCustomExtendedMovement); \
	DECLARE_FUNCTION(execStopFastMovement); \
	DECLARE_FUNCTION(execStartFastMovement); \
	DECLARE_FUNCTION(execGetCurrentFloorAngle); \
	DECLARE_FUNCTION(execSetWallInfo); \
	DECLARE_FUNCTION(execClimbingPhysics); \
	DECLARE_FUNCTION(execSlidingPhysics); \
	DECLARE_FUNCTION(execFlyingPhysics); \
	DECLARE_FUNCTION(execIsMovementMode); \
	DECLARE_FUNCTION(execIsCustomMovementMode);


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_CALLBACK_WRAPPERS
#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNewCharacterMovementComponent(); \
	friend struct Z_Construct_UClass_UNewCharacterMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UNewCharacterMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CharacterLocomotionSystem"), NO_API) \
	DECLARE_SERIALIZER(UNewCharacterMovementComponent)


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UNewCharacterMovementComponent(UNewCharacterMovementComponent&&); \
	UNewCharacterMovementComponent(const UNewCharacterMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNewCharacterMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNewCharacterMovementComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNewCharacterMovementComponent) \
	NO_API virtual ~UNewCharacterMovementComponent();


#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_292_PROLOG
#define FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_CALLBACK_WRAPPERS \
	FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_INCLASS_NO_PURE_DECLS \
	FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h_295_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<class UNewCharacterMovementComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacterMovementComponent_h


#define FOREACH_ENUM_ECUSTOMMOVEMENTMODE(op) \
	op(CMOVE_None) \
	op(CMOVE_Prone) \
	op(CMOVE_Slide) \
	op(CMOVE_WallRun) \
	op(CMOVE_Dash) \
	op(CMOVE_Climb) \
	op(CMOVE_CustomExtended) \
	op(CMOVE_CustomAdvancedMovement) \
	op(CMOVE_Vault) \
	op(CMOVE_Mantle) \
	op(CMOVE_ClimbUp) 
#define FOREACH_ENUM_ESLIDEEXITMOVEMENTMODE(op) \
	op(ESlideExitMovementMode::Crouch) \
	op(ESlideExitMovementMode::Prone) 

enum class ESlideExitMovementMode : uint8;
template<> struct TIsUEnumClass<ESlideExitMovementMode> { enum { Value = true }; };
template<> CHARACTERLOCOMOTIONSYSTEM_API UEnum* StaticEnum<ESlideExitMovementMode>();

#define FOREACH_ENUM_EWALLSIDE(op) \
	op(EWallSide::None) \
	op(EWallSide::Front) \
	op(EWallSide::Back) \
	op(EWallSide::Left) \
	op(EWallSide::Right) 

enum class EWallSide : uint8;
template<> struct TIsUEnumClass<EWallSide> { enum { Value = true }; };
template<> CHARACTERLOCOMOTIONSYSTEM_API UEnum* StaticEnum<EWallSide>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
