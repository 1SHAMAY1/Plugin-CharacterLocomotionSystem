// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NewCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAdvancedMovementPrimaryDataAsset;
class UClimbUpPrimaryDataAsset;
class UMantlePrimaryDataAsset;
class UMotionWarpingComponent;
class UNewCharacterMovementComponent;
class UVaultPrimaryDataAsset;
#ifdef CHARACTERLOCOMOTIONSYSTEM_NewCharacter_generated_h
#error "NewCharacter.generated.h already included, missing '#pragma once' in NewCharacter.h"
#endif
#define CHARACTERLOCOMOTIONSYSTEM_NewCharacter_generated_h

#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_SPARSE_DATA
#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopClimbingUp); \
	DECLARE_FUNCTION(execClimbUp); \
	DECLARE_FUNCTION(execGetClimbUpData); \
	DECLARE_FUNCTION(execStopMantling); \
	DECLARE_FUNCTION(execMantle); \
	DECLARE_FUNCTION(execGetMantleData); \
	DECLARE_FUNCTION(execStopVaulting); \
	DECLARE_FUNCTION(execVault); \
	DECLARE_FUNCTION(execGetVaultData); \
	DECLARE_FUNCTION(execAddAndUpdateCustomAdvancedWarpTargets); \
	DECLARE_FUNCTION(execGetMaxCustomAdvancedSpeed); \
	DECLARE_FUNCTION(execCanCustomAdvancedMovement); \
	DECLARE_FUNCTION(execCustomAdvancedMovementPhysics); \
	DECLARE_FUNCTION(execExitCustomAdvancedMovement); \
	DECLARE_FUNCTION(execEnterCustomAdvancedMovement); \
	DECLARE_FUNCTION(execStopCustomAdvancedMovement); \
	DECLARE_FUNCTION(execStartCustomAdvancedMovement); \
	DECLARE_FUNCTION(execGetCustomAdvancedMovementData); \
	DECLARE_FUNCTION(execStopWallRunning); \
	DECLARE_FUNCTION(execWallRun); \
	DECLARE_FUNCTION(execStopClimb); \
	DECLARE_FUNCTION(execClimb); \
	DECLARE_FUNCTION(execStopSliding); \
	DECLARE_FUNCTION(execSlide); \
	DECLARE_FUNCTION(execStopPronning); \
	DECLARE_FUNCTION(execProne); \
	DECLARE_FUNCTION(execStopDashing); \
	DECLARE_FUNCTION(execDash); \
	DECLARE_FUNCTION(execStopCrouchSprinting); \
	DECLARE_FUNCTION(execCrouchSprint); \
	DECLARE_FUNCTION(execStopSprinting); \
	DECLARE_FUNCTION(execSprint); \
	DECLARE_FUNCTION(execStopFastSwimming); \
	DECLARE_FUNCTION(execFastSwim); \
	DECLARE_FUNCTION(execStopFastFlying); \
	DECLARE_FUNCTION(execStopFlying); \
	DECLARE_FUNCTION(execFastFly); \
	DECLARE_FUNCTION(execFly); \
	DECLARE_FUNCTION(execGetMaxCustomExtendedDeceleration); \
	DECLARE_FUNCTION(execGetMaxCustomExtendedAcceleration); \
	DECLARE_FUNCTION(execGetMaxCustomExtendedSpeed); \
	DECLARE_FUNCTION(execCanCustomExtendedMovement); \
	DECLARE_FUNCTION(execCustomExtendedMovementPhysics); \
	DECLARE_FUNCTION(execExitCustomExtendedMovement); \
	DECLARE_FUNCTION(execEnterCustomExtendedMovement); \
	DECLARE_FUNCTION(execStopCustomExtendedMovement); \
	DECLARE_FUNCTION(execStartCustomExtendedMovement); \
	DECLARE_FUNCTION(execStopFastMovement); \
	DECLARE_FUNCTION(execStartFastMovement); \
	DECLARE_FUNCTION(execGetMotionWarpingComponent); \
	DECLARE_FUNCTION(execGetNewCharacterMovementComponent);


#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_ACCESSORS
#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_CALLBACK_WRAPPERS
#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANewCharacter(); \
	friend struct Z_Construct_UClass_ANewCharacter_Statics; \
public: \
	DECLARE_CLASS(ANewCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CharacterLocomotionSystem"), NO_API) \
	DECLARE_SERIALIZER(ANewCharacter)


#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANewCharacter(ANewCharacter&&); \
	NO_API ANewCharacter(const ANewCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANewCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANewCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANewCharacter) \
	NO_API virtual ~ANewCharacter();


#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_46_PROLOG
#define FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_SPARSE_DATA \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_ACCESSORS \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_CALLBACK_WRAPPERS \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_INCLASS_NO_PURE_DECLS \
	FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_49_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<class ANewCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
