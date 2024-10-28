// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/NewCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNewCharacter() {}
// Cross Module References
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_ANewCharacter();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_ANewCharacter_NoRegister();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_NoRegister();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UClimbUpPrimaryDataAsset_NoRegister();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UMantlePrimaryDataAsset_NoRegister();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UNewCharacterMovementComponent_NoRegister();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UVaultPrimaryDataAsset_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	MOTIONWARPING_API UClass* Z_Construct_UClass_UMotionWarpingComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References
	DEFINE_FUNCTION(ANewCharacter::execStopClimbingUp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopClimbingUp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execClimbUp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ClimbUp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execGetClimbUpData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UClimbUpPrimaryDataAsset**)Z_Param__Result=P_THIS->GetClimbUpData_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopMantling)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopMantling();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execMantle)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Mantle();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execGetMantleData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UMantlePrimaryDataAsset**)Z_Param__Result=P_THIS->GetMantleData_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopVaulting)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopVaulting();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execVault)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Vault();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execGetVaultData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVaultPrimaryDataAsset**)Z_Param__Result=P_THIS->GetVaultData_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execCanCustomAdvancedMovement)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanCustomAdvancedMovement_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execCustomAdvancedMovementPhysics)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_deltaTime);
		P_GET_PROPERTY(FIntProperty,Z_Param_Iterations);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CustomAdvancedMovementPhysics_Implementation(Z_Param_deltaTime,Z_Param_Iterations);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopCustomAdvancedMovement)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopCustomAdvancedMovement_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStartCustomAdvancedMovement)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->StartCustomAdvancedMovement_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execGetCustomAdvancedMovementData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAdvancedMovementPrimaryDataAsset**)Z_Param__Result=P_THIS->GetCustomAdvancedMovementData_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopWallRunning)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopWallRunning();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execWallRun)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->WallRun();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopClimb)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopClimb();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execClimb)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Climb();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopSliding)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopSliding();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execSlide)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Slide();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopPronning)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopPronning();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execProne)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Prone();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopDashing)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopDashing();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execDash)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Dash();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopCrouchSprinting)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopCrouchSprinting();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execCrouchSprint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CrouchSprint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopSprinting)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopSprinting();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execSprint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Sprint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopFastSwimming)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopFastSwimming();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execFastSwim)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->FastSwim();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopFastFlying)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopFastFlying();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopFlying)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopFlying();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execFastFly)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->FastFly();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execFly)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Fly();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStopFastMovement)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopFastMovement();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execStartFastMovement)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartFastMovement();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execGetMotionWarpingComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UMotionWarpingComponent**)Z_Param__Result=P_THIS->GetMotionWarpingComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANewCharacter::execGetNewCharacterMovementComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UNewCharacterMovementComponent**)Z_Param__Result=P_THIS->GetNewCharacterMovementComponent();
		P_NATIVE_END;
	}
	struct NewCharacter_eventCanCustomAdvancedMovement_Parms
	{
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		NewCharacter_eventCanCustomAdvancedMovement_Parms()
			: ReturnValue(false)
		{
		}
	};
	struct NewCharacter_eventCustomAdvancedMovementPhysics_Parms
	{
		float deltaTime;
		int32 Iterations;
	};
	struct NewCharacter_eventGetClimbUpData_Parms
	{
		UClimbUpPrimaryDataAsset* ReturnValue;

		/** Constructor, initializes return property only **/
		NewCharacter_eventGetClimbUpData_Parms()
			: ReturnValue(NULL)
		{
		}
	};
	struct NewCharacter_eventGetCustomAdvancedMovementData_Parms
	{
		UAdvancedMovementPrimaryDataAsset* ReturnValue;

		/** Constructor, initializes return property only **/
		NewCharacter_eventGetCustomAdvancedMovementData_Parms()
			: ReturnValue(NULL)
		{
		}
	};
	struct NewCharacter_eventGetMantleData_Parms
	{
		UMantlePrimaryDataAsset* ReturnValue;

		/** Constructor, initializes return property only **/
		NewCharacter_eventGetMantleData_Parms()
			: ReturnValue(NULL)
		{
		}
	};
	struct NewCharacter_eventGetVaultData_Parms
	{
		UVaultPrimaryDataAsset* ReturnValue;

		/** Constructor, initializes return property only **/
		NewCharacter_eventGetVaultData_Parms()
			: ReturnValue(NULL)
		{
		}
	};
	struct NewCharacter_eventStartCustomAdvancedMovement_Parms
	{
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		NewCharacter_eventStartCustomAdvancedMovement_Parms()
			: ReturnValue(false)
		{
		}
	};
	static FName NAME_ANewCharacter_CanCustomAdvancedMovement = FName(TEXT("CanCustomAdvancedMovement"));
	bool ANewCharacter::CanCustomAdvancedMovement()
	{
		NewCharacter_eventCanCustomAdvancedMovement_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_CanCustomAdvancedMovement),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_ANewCharacter_CustomAdvancedMovementPhysics = FName(TEXT("CustomAdvancedMovementPhysics"));
	void ANewCharacter::CustomAdvancedMovementPhysics(float deltaTime, int32 Iterations)
	{
		NewCharacter_eventCustomAdvancedMovementPhysics_Parms Parms;
		Parms.deltaTime=deltaTime;
		Parms.Iterations=Iterations;
		ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_CustomAdvancedMovementPhysics),&Parms);
	}
	static FName NAME_ANewCharacter_GetClimbUpData = FName(TEXT("GetClimbUpData"));
	UClimbUpPrimaryDataAsset* ANewCharacter::GetClimbUpData()
	{
		NewCharacter_eventGetClimbUpData_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetClimbUpData),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_ANewCharacter_GetCustomAdvancedMovementData = FName(TEXT("GetCustomAdvancedMovementData"));
	UAdvancedMovementPrimaryDataAsset* ANewCharacter::GetCustomAdvancedMovementData() const
	{
		NewCharacter_eventGetCustomAdvancedMovementData_Parms Parms;
		const_cast<ANewCharacter*>(this)->ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetCustomAdvancedMovementData),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_ANewCharacter_GetMantleData = FName(TEXT("GetMantleData"));
	UMantlePrimaryDataAsset* ANewCharacter::GetMantleData()
	{
		NewCharacter_eventGetMantleData_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetMantleData),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_ANewCharacter_GetVaultData = FName(TEXT("GetVaultData"));
	UVaultPrimaryDataAsset* ANewCharacter::GetVaultData()
	{
		NewCharacter_eventGetVaultData_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetVaultData),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_ANewCharacter_StartCustomAdvancedMovement = FName(TEXT("StartCustomAdvancedMovement"));
	bool ANewCharacter::StartCustomAdvancedMovement()
	{
		NewCharacter_eventStartCustomAdvancedMovement_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_StartCustomAdvancedMovement),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_ANewCharacter_StopCustomAdvancedMovement = FName(TEXT("StopCustomAdvancedMovement"));
	void ANewCharacter::StopCustomAdvancedMovement()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_StopCustomAdvancedMovement),NULL);
	}
	void ANewCharacter::StaticRegisterNativesANewCharacter()
	{
		UClass* Class = ANewCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanCustomAdvancedMovement", &ANewCharacter::execCanCustomAdvancedMovement },
			{ "Climb", &ANewCharacter::execClimb },
			{ "ClimbUp", &ANewCharacter::execClimbUp },
			{ "CrouchSprint", &ANewCharacter::execCrouchSprint },
			{ "CustomAdvancedMovementPhysics", &ANewCharacter::execCustomAdvancedMovementPhysics },
			{ "Dash", &ANewCharacter::execDash },
			{ "FastFly", &ANewCharacter::execFastFly },
			{ "FastSwim", &ANewCharacter::execFastSwim },
			{ "Fly", &ANewCharacter::execFly },
			{ "GetClimbUpData", &ANewCharacter::execGetClimbUpData },
			{ "GetCustomAdvancedMovementData", &ANewCharacter::execGetCustomAdvancedMovementData },
			{ "GetMantleData", &ANewCharacter::execGetMantleData },
			{ "GetMotionWarpingComponent", &ANewCharacter::execGetMotionWarpingComponent },
			{ "GetNewCharacterMovementComponent", &ANewCharacter::execGetNewCharacterMovementComponent },
			{ "GetVaultData", &ANewCharacter::execGetVaultData },
			{ "Mantle", &ANewCharacter::execMantle },
			{ "Prone", &ANewCharacter::execProne },
			{ "Slide", &ANewCharacter::execSlide },
			{ "Sprint", &ANewCharacter::execSprint },
			{ "StartCustomAdvancedMovement", &ANewCharacter::execStartCustomAdvancedMovement },
			{ "StartFastMovement", &ANewCharacter::execStartFastMovement },
			{ "StopClimb", &ANewCharacter::execStopClimb },
			{ "StopClimbingUp", &ANewCharacter::execStopClimbingUp },
			{ "StopCrouchSprinting", &ANewCharacter::execStopCrouchSprinting },
			{ "StopCustomAdvancedMovement", &ANewCharacter::execStopCustomAdvancedMovement },
			{ "StopDashing", &ANewCharacter::execStopDashing },
			{ "StopFastFlying", &ANewCharacter::execStopFastFlying },
			{ "StopFastMovement", &ANewCharacter::execStopFastMovement },
			{ "StopFastSwimming", &ANewCharacter::execStopFastSwimming },
			{ "StopFlying", &ANewCharacter::execStopFlying },
			{ "StopMantling", &ANewCharacter::execStopMantling },
			{ "StopPronning", &ANewCharacter::execStopPronning },
			{ "StopSliding", &ANewCharacter::execStopSliding },
			{ "StopSprinting", &ANewCharacter::execStopSprinting },
			{ "StopVaulting", &ANewCharacter::execStopVaulting },
			{ "StopWallRunning", &ANewCharacter::execStopWallRunning },
			{ "Vault", &ANewCharacter::execVault },
			{ "WallRun", &ANewCharacter::execWallRun },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventCanCustomAdvancedMovement_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventCanCustomAdvancedMovement_Parms), &Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Checks whether the character is currently allowed to perform custom advanced movement.\n\x09 * This function evaluates relevant gameplay conditions to determine if\n\x09 * the movement is permissible. Currently, it does not perform any specific actions\n\x09 * and is intended for future implementations.\n\x09 *\n\x09 * @return True if custom advanced movement can be performed; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Checks whether the character is currently allowed to perform custom advanced movement.\nThis function evaluates relevant gameplay conditions to determine if\nthe movement is permissible. Currently, it does not perform any specific actions\nand is intended for future implementations.\n\n@return True if custom advanced movement can be performed; otherwise, false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CanCustomAdvancedMovement", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::PropPointers), sizeof(NewCharacter_eventCanCustomAdvancedMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::PropPointers) < 2048);
	static_assert(sizeof(NewCharacter_eventCanCustomAdvancedMovement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Climb_Statics
	{
		struct NewCharacter_eventClimb_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Climb_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventClimb_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Climb_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventClimb_Parms), &Z_Construct_UFunction_ANewCharacter_Climb_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Climb_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Climb_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Climb_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Climb" },
		{ "Comment", "/**\n\x09 * Attempts to initiate the climbing action for the character.\n\x09 * @return True if the character successfully transitions into a climbing state, otherwise false.\n\x09 * Indicates that the character can begin climbing based on current movement\n\x09 * conditions and the presence of a valid climbable surface.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate the climbing action for the character.\n@return True if the character successfully transitions into a climbing state, otherwise false.\nIndicates that the character can begin climbing based on current movement\nconditions and the presence of a valid climbable surface." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Climb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Climb", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Climb_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Climb_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Climb_Statics::NewCharacter_eventClimb_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Climb_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Climb_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Climb_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Climb_Statics::NewCharacter_eventClimb_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Climb()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Climb_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics
	{
		struct NewCharacter_eventClimbUp_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventClimbUp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventClimbUp_Parms), &Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|ClimbUp" },
		{ "Comment", "/**\n\x09 * Initiates the climbing-up action for the character.\n\x09 * This function checks the conditions and attempts to start the\n\x09 * climbing-up movement based on the current character state and environment.\n\x09 *\n\x09 * @return True if the climbing-up action was successfully initiated; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates the climbing-up action for the character.\nThis function checks the conditions and attempts to start the\nclimbing-up movement based on the current character state and environment.\n\n@return True if the climbing-up action was successfully initiated; otherwise, false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "ClimbUp", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::NewCharacter_eventClimbUp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::NewCharacter_eventClimbUp_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_ClimbUp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics
	{
		struct NewCharacter_eventCrouchSprint_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventCrouchSprint_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventCrouchSprint_Parms), &Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|CrouchSprint" },
		{ "Comment", "/**\n\x09 * Attempts to start crouch sprinting for the character.\n\x09 * This may also affect standard sprint behavior due to interconnected functionality.\n\x09 * @return True if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start crouch sprinting for the character.\nThis may also affect standard sprint behavior due to interconnected functionality.\n@return True if the action is successful." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CrouchSprint", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::NewCharacter_eventCrouchSprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::NewCharacter_eventCrouchSprint_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_CrouchSprint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_deltaTime;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Iterations;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_deltaTime = { "deltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventCustomAdvancedMovementPhysics_Parms, deltaTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_Iterations = { "Iterations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventCustomAdvancedMovementPhysics_Parms, Iterations), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_deltaTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_Iterations,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Performs custom physics calculations for advanced movement.\n\x09 * This function is called every frame to apply any necessary physics logic\n\x09 * related to custom movement mechanics. Currently, it does not perform any\n\x09 * specific actions and is intended for future implementations.\n\x09 *\n\x09 * @param deltaTime The time elapsed since the last frame.\n\x09 * @param Iterations The number of iterations to apply physics calculations.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Performs custom physics calculations for advanced movement.\nThis function is called every frame to apply any necessary physics logic\nrelated to custom movement mechanics. Currently, it does not perform any\nspecific actions and is intended for future implementations.\n\n@param deltaTime The time elapsed since the last frame.\n@param Iterations The number of iterations to apply physics calculations." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CustomAdvancedMovementPhysics", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers), sizeof(NewCharacter_eventCustomAdvancedMovementPhysics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers) < 2048);
	static_assert(sizeof(NewCharacter_eventCustomAdvancedMovementPhysics_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Dash_Statics
	{
		struct NewCharacter_eventDash_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Dash_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventDash_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Dash_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventDash_Parms), &Z_Construct_UFunction_ANewCharacter_Dash_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Dash_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Dash_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Dash_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Dash" },
		{ "Comment", "/**\n\x09 * Attempts to start dashing for the character.\n\x09 * @return True if the character successfully starts dashing, otherwise false.\n\x09 * Indicates that the character can dash based on current conditions.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start dashing for the character.\n@return True if the character successfully starts dashing, otherwise false.\nIndicates that the character can dash based on current conditions." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Dash_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Dash", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Dash_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Dash_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Dash_Statics::NewCharacter_eventDash_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Dash_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Dash_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Dash_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Dash_Statics::NewCharacter_eventDash_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Dash()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Dash_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_FastFly_Statics
	{
		struct NewCharacter_eventFastFly_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_FastFly_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventFastFly_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_FastFly_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventFastFly_Parms), &Z_Construct_UFunction_ANewCharacter_FastFly_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_FastFly_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_FastFly_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_FastFly_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Attempts to start fast flying for the character.\n\x09 * Returns true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start fast flying for the character.\nReturns true if the action is successful." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_FastFly_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "FastFly", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_FastFly_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::NewCharacter_eventFastFly_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_FastFly_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::NewCharacter_eventFastFly_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_FastFly()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_FastFly_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_FastSwim_Statics
	{
		struct NewCharacter_eventFastSwim_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventFastSwim_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventFastSwim_Parms), &Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Swim" },
		{ "Comment", "/**\n\x09 * Attempts to start fast swimming for the character.\n\x09 * Returns true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start fast swimming for the character.\nReturns true if the action is successful." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "FastSwim", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::NewCharacter_eventFastSwim_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::NewCharacter_eventFastSwim_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_FastSwim()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Fly_Statics
	{
		struct NewCharacter_eventFly_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Fly_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventFly_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Fly_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventFly_Parms), &Z_Construct_UFunction_ANewCharacter_Fly_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Fly_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Fly_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Fly_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Attempts to start flying for the character.\n\x09 * Returns true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start flying for the character.\nReturns true if the action is successful." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Fly_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Fly", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Fly_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Fly_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Fly_Statics::NewCharacter_eventFly_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Fly_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Fly_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Fly_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Fly_Statics::NewCharacter_eventFly_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Fly()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Fly_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetClimbUpData_Parms, ReturnValue), Z_Construct_UClass_UClimbUpPrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|ClimbUp" },
		{ "Comment", "/**\n\x09 * Retrieves the climb-up data asset associated with this character.\n\x09 * This function provides access to specific parameters and settings\n\x09 * related to climbing up mechanics.\n\x09 *\n\x09 * @return Pointer to the UClimbUpPrimaryDataAsset instance containing climb-up data.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the climb-up data asset associated with this character.\nThis function provides access to specific parameters and settings\nrelated to climbing up mechanics.\n\n@return Pointer to the UClimbUpPrimaryDataAsset instance containing climb-up data." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetClimbUpData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers), sizeof(NewCharacter_eventGetClimbUpData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers) < 2048);
	static_assert(sizeof(NewCharacter_eventGetClimbUpData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_GetClimbUpData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetCustomAdvancedMovementData_Parms, ReturnValue), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n * Retrieves the advanced movement data asset associated with this character.\n * This function provides access to custom movement parameters that may affect\n * advanced movement capabilities. Currently, this function does not perform any\n * specific actions and is intended for future implementations.\n *\n * @return Pointer to the UAdvancedMovementPrimaryDataAsset instance.\n */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the advanced movement data asset associated with this character.\nThis function provides access to custom movement parameters that may affect\nadvanced movement capabilities. Currently, this function does not perform any\nspecific actions and is intended for future implementations.\n\n@return Pointer to the UAdvancedMovementPrimaryDataAsset instance." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetCustomAdvancedMovementData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers), sizeof(NewCharacter_eventGetCustomAdvancedMovementData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers) < 2048);
	static_assert(sizeof(NewCharacter_eventGetCustomAdvancedMovementData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMantleData_Parms, ReturnValue), Z_Construct_UClass_UMantlePrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Mantle" },
		{ "Comment", "/**\n\x09 * Retrieves the mantle data asset associated with this character.\n\x09 * This function provides access to specific parameters and settings\n\x09 * related to mantling mechanics.\n\x09 *\n\x09 * @return Pointer to the UMantlePrimaryDataAsset instance containing mantle data.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the mantle data asset associated with this character.\nThis function provides access to specific parameters and settings\nrelated to mantling mechanics.\n\n@return Pointer to the UMantlePrimaryDataAsset instance containing mantle data." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMantleData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers), sizeof(NewCharacter_eventGetMantleData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers) < 2048);
	static_assert(sizeof(NewCharacter_eventGetMantleData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_GetMantleData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics
	{
		struct NewCharacter_eventGetMotionWarpingComponent_Parms
		{
			UMotionWarpingComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMotionWarpingComponent_Parms, ReturnValue), Z_Construct_UClass_UMotionWarpingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::Function_MetaDataParams[] = {
		{ "AllowProtectedAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "/** Returns MotionWarping Component subobject **/" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Returns MotionWarping Component subobject *" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMotionWarpingComponent", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewCharacter_eventGetMotionWarpingComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewCharacter_eventGetMotionWarpingComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics
	{
		struct NewCharacter_eventGetNewCharacterMovementComponent_Parms
		{
			UNewCharacterMovementComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetNewCharacterMovementComponent_Parms, ReturnValue), Z_Construct_UClass_UNewCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::Function_MetaDataParams[] = {
		{ "AllowProtectedAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "/** Returns NewCharacterMovementComponent subobject **/" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Returns NewCharacterMovementComponent subobject *" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetNewCharacterMovementComponent", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewCharacter_eventGetNewCharacterMovementComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewCharacter_eventGetNewCharacterMovementComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetVaultData_Parms, ReturnValue), Z_Construct_UClass_UVaultPrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Vault" },
		{ "Comment", "/**\n\x09 * Retrieves the vault data asset associated with this character.\n\x09 * This function provides access to the vaulting parameters that control\n\x09 * the character's vaulting behavior.\n\x09 *\n\x09 * @return Pointer to the UVaultPrimaryDataAsset instance.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the vault data asset associated with this character.\nThis function provides access to the vaulting parameters that control\nthe character's vaulting behavior.\n\n@return Pointer to the UVaultPrimaryDataAsset instance." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetVaultData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers), sizeof(NewCharacter_eventGetVaultData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers) < 2048);
	static_assert(sizeof(NewCharacter_eventGetVaultData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_GetVaultData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Mantle_Statics
	{
		struct NewCharacter_eventMantle_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Mantle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventMantle_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Mantle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventMantle_Parms), &Z_Construct_UFunction_ANewCharacter_Mantle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Mantle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Mantle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Mantle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Mantle" },
		{ "Comment", "/**\n\x09 * Initiates the mantling action for the character.\n\x09 * This function checks the conditions and attempts to start the\n\x09 * mantling movement based on the current character state and environment.\n\x09 *\n\x09 * @return True if the mantling action was successfully initiated; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates the mantling action for the character.\nThis function checks the conditions and attempts to start the\nmantling movement based on the current character state and environment.\n\n@return True if the mantling action was successfully initiated; otherwise, false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Mantle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Mantle", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Mantle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::NewCharacter_eventMantle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Mantle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::NewCharacter_eventMantle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Mantle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Mantle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Prone_Statics
	{
		struct NewCharacter_eventProne_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Prone_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventProne_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Prone_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventProne_Parms), &Z_Construct_UFunction_ANewCharacter_Prone_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Prone_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Prone_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Prone_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Prone" },
		{ "Comment", "/**\n\x09 * Attempts to start the proning action for the character.\n\x09 * @return True if the character successfully transitions into a prone position, otherwise false.\n\x09 * Indicates that the character can transition into a prone position based on current conditions.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start the proning action for the character.\n@return True if the character successfully transitions into a prone position, otherwise false.\nIndicates that the character can transition into a prone position based on current conditions." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Prone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Prone", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Prone_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Prone_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Prone_Statics::NewCharacter_eventProne_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Prone_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Prone_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Prone_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Prone_Statics::NewCharacter_eventProne_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Prone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Prone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Slide_Statics
	{
		struct NewCharacter_eventSlide_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Slide_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventSlide_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Slide_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventSlide_Parms), &Z_Construct_UFunction_ANewCharacter_Slide_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Slide_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Slide_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Slide_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Slide" },
		{ "Comment", "/**\n\x09 * Attempts to initiate the sliding action for the character.\n\x09 * @return True if the character successfully transitions into a sliding state, otherwise false.\n\x09 * Indicates that the character can transition into a sliding state based on\n\x09 * current movement conditions and environment.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate the sliding action for the character.\n@return True if the character successfully transitions into a sliding state, otherwise false.\nIndicates that the character can transition into a sliding state based on\ncurrent movement conditions and environment." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Slide_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Slide", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Slide_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Slide_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Slide_Statics::NewCharacter_eventSlide_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Slide_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Slide_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Slide_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Slide_Statics::NewCharacter_eventSlide_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Slide()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Slide_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Sprint_Statics
	{
		struct NewCharacter_eventSprint_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Sprint_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventSprint_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Sprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventSprint_Parms), &Z_Construct_UFunction_ANewCharacter_Sprint_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Sprint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Sprint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Sprint_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Sprint" },
		{ "Comment", "/**\n\x09 * Attempts to start sprinting for the character.\n\x09 * Sprinting is interconnected with crouch sprinting, and initiating sprint may impact crouch sprint behavior.\n\x09 * @return True if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start sprinting for the character.\nSprinting is interconnected with crouch sprinting, and initiating sprint may impact crouch sprint behavior.\n@return True if the action is successful." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Sprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Sprint", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Sprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::NewCharacter_eventSprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Sprint_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::NewCharacter_eventSprint_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Sprint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Sprint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventStartCustomAdvancedMovement_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventStartCustomAdvancedMovement_Parms), &Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Initiates custom advanced movement for the character.\n\x09 * This function checks the conditions and initiates the necessary changes\n\x09 * in character state to start the custom movement. Currently, it does not\n\x09 * perform any specific actions and is intended for future implementations.\n\x09 *\n\x09 * @return True if the advanced movement was successfully started; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates custom advanced movement for the character.\nThis function checks the conditions and initiates the necessary changes\nin character state to start the custom movement. Currently, it does not\nperform any specific actions and is intended for future implementations.\n\n@return True if the advanced movement was successfully started; otherwise, false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StartCustomAdvancedMovement", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::PropPointers), sizeof(NewCharacter_eventStartCustomAdvancedMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::PropPointers) < 2048);
	static_assert(sizeof(NewCharacter_eventStartCustomAdvancedMovement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StartFastMovement_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StartFastMovement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Fast" },
		{ "Comment", "/**\n\x09 * Initiates fast movement for the character.\n\x09 * When enabled, this function allows for fast movement updates across all movement modes,\n\x09 * enabling the character to move quickly while in states like Walking, flying, swimming, etc.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates fast movement for the character.\nWhen enabled, this function allows for fast movement updates across all movement modes,\nenabling the character to move quickly while in states like Walking, flying, swimming, etc." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StartFastMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StartFastMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartFastMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StartFastMovement_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StartFastMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StartFastMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopClimb_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopClimb_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Climb" },
		{ "Comment", "/**\n\x09 * Stops the climbing movement for the character.\n\x09 * This function transitions the character out of the climbing\n\x09 * state, allowing them to return to regular movement mechanics\n\x09 * or initiate another action.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the climbing movement for the character.\nThis function transitions the character out of the climbing\nstate, allowing them to return to regular movement mechanics\nor initiate another action." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopClimb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopClimb", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopClimb_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopClimb_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopClimb()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopClimb_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopClimbingUp_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopClimbingUp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|ClimbUp" },
		{ "Comment", "/**\n\x09 * Stops the climbing-up action for the character.\n\x09 * This function reverts any changes made during the climbing-up state\n\x09 * and transitions the character back to normal movement.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the climbing-up action for the character.\nThis function reverts any changes made during the climbing-up state\nand transitions the character back to normal movement." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopClimbingUp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopClimbingUp", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopClimbingUp_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopClimbingUp_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopClimbingUp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopClimbingUp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|CrouchSprint" },
		{ "Comment", "/**\n\x09 * Stops the crouch sprinting movement for the character.\n\x09 * This may also affect standard sprint behavior due to interconnected functionality.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the crouch sprinting movement for the character.\nThis may also affect standard sprint behavior due to interconnected functionality." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopCrouchSprinting", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Stops the custom advanced movement for the character.\n\x09 * This function reverts the character's state back to normal movement mechanics.\n\x09 * Currently, it does not perform any specific actions and is intended for future implementations.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the custom advanced movement for the character.\nThis function reverts the character's state back to normal movement mechanics.\nCurrently, it does not perform any specific actions and is intended for future implementations." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopCustomAdvancedMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopDashing_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopDashing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Dash" },
		{ "Comment", "/**\n\x09 * Stops the dashing movement for the character.\n\x09 * This function resets the character's state and speed\n\x09 * back to normal after a dash is completed.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the dashing movement for the character.\nThis function resets the character's state and speed\nback to normal after a dash is completed." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopDashing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopDashing", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopDashing_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopDashing_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopDashing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopDashing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopFastFlying_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopFastFlying_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Stops the fast flying movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the fast flying movement for the character." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopFastFlying_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopFastFlying", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopFastFlying_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopFastFlying_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopFastFlying()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopFastFlying_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopFastMovement_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopFastMovement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Fast" },
		{ "Comment", "/**\n\x09 * Stops the fast movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the fast movement for the character." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopFastMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopFastMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopFastMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopFastMovement_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopFastMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopFastMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopFastSwimming_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopFastSwimming_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Swim" },
		{ "Comment", "/**\n\x09 * Stops the fast swimming movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the fast swimming movement for the character." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopFastSwimming_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopFastSwimming", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopFastSwimming_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopFastSwimming_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopFastSwimming()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopFastSwimming_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopFlying_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopFlying_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Stops the flying movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the flying movement for the character." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopFlying_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopFlying", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopFlying_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopFlying_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopFlying()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopFlying_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopMantling_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopMantling_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Mantle" },
		{ "Comment", "/**\n\x09 * Stops the mantling action for the character.\n\x09 * This function reverts any changes made during the mantling state\n\x09 * and transitions the character back to normal movement.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the mantling action for the character.\nThis function reverts any changes made during the mantling state\nand transitions the character back to normal movement." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopMantling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopMantling", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopMantling_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopMantling_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopMantling()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopMantling_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopPronning_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopPronning_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Prone" },
		{ "Comment", "/**\n\x09 * Stops the proning movement for the character.\n\x09 * This function transitions the character out of the prone\n\x09 * position, returning them to a standing or crouched state as appropriate.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the proning movement for the character.\nThis function transitions the character out of the prone\nposition, returning them to a standing or crouched state as appropriate." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopPronning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopPronning", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopPronning_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopPronning_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopPronning()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopPronning_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopSliding_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopSliding_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Slide" },
		{ "Comment", "/**\n\x09 * Stops the sliding movement for the character.\n\x09 * This function transitions the character out of the sliding\n\x09 * state, allowing them to return to regular movement mechanics.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the sliding movement for the character.\nThis function transitions the character out of the sliding\nstate, allowing them to return to regular movement mechanics." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopSliding_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopSliding", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopSliding_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopSliding_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopSliding()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopSliding_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopSprinting_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopSprinting_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Sprint" },
		{ "Comment", "/**\n\x09 * Stops the sprinting movement for the character.\n\x09 * Stopping sprinting may affect crouch sprint behavior due to the interconnected functionality.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the sprinting movement for the character.\nStopping sprinting may affect crouch sprint behavior due to the interconnected functionality." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopSprinting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopSprinting", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopSprinting_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopSprinting_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopSprinting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopSprinting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopVaulting_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopVaulting_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Vault" },
		{ "Comment", "/**\n\x09 * Stops the vaulting movement for the character.\n\x09 * This function reverts any changes made during the vaulting action,\n\x09 * returning the character to their previous movement state.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the vaulting movement for the character.\nThis function reverts any changes made during the vaulting action,\nreturning the character to their previous movement state." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopVaulting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopVaulting", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopVaulting_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopVaulting_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopVaulting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopVaulting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_StopWallRunning_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_StopWallRunning_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|WallRun" },
		{ "Comment", "/**\n\x09 * Stops the wall running movement for the character.\n\x09 * This function transitions the character out of the wall running\n\x09 * state, allowing them to return to regular movement mechanics\n\x09 * or initiate another action.\n\x09 *\n\x09 * Note: This function will not be effective if the auto end wall run feature is active.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the wall running movement for the character.\nThis function transitions the character out of the wall running\nstate, allowing them to return to regular movement mechanics\nor initiate another action.\n\nNote: This function will not be effective if the auto end wall run feature is active." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopWallRunning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopWallRunning", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopWallRunning_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopWallRunning_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANewCharacter_StopWallRunning()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopWallRunning_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_Vault_Statics
	{
		struct NewCharacter_eventVault_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_Vault_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventVault_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_Vault_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventVault_Parms), &Z_Construct_UFunction_ANewCharacter_Vault_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_Vault_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_Vault_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_Vault_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Vault" },
		{ "Comment", "/**\n\x09 * Attempts to initiate vaulting for the character.\n\x09 * This function evaluates conditions and triggers the necessary state changes\n\x09 * to perform a vault.\n\x09 *\n\x09 * @return True if the vaulting action was successfully initiated; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate vaulting for the character.\nThis function evaluates conditions and triggers the necessary state changes\nto perform a vault.\n\n@return True if the vaulting action was successfully initiated; otherwise, false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Vault_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Vault", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Vault_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Vault_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Vault_Statics::NewCharacter_eventVault_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Vault_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Vault_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Vault_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_Vault_Statics::NewCharacter_eventVault_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_Vault()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_Vault_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANewCharacter_WallRun_Statics
	{
		struct NewCharacter_eventWallRun_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANewCharacter_WallRun_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NewCharacter_eventWallRun_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_WallRun_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventWallRun_Parms), &Z_Construct_UFunction_ANewCharacter_WallRun_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_WallRun_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_WallRun_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANewCharacter_WallRun_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement|WallRun" },
		{ "Comment", "/**\n\x09 * Attempts to initiate the wall running action for the character.\n\x09 * @return True if the character successfully transitions into a wall running state, otherwise false.\n\x09 * This function checks the conditions for wall running, such as\n\x09 * the character's orientation and proximity to the wall,\n\x09 * returning true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate the wall running action for the character.\n@return True if the character successfully transitions into a wall running state, otherwise false.\nThis function checks the conditions for wall running, such as\nthe character's orientation and proximity to the wall,\nreturning true if the action is successful." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_WallRun_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "WallRun", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_WallRun_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::NewCharacter_eventWallRun_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_WallRun_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::NewCharacter_eventWallRun_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANewCharacter_WallRun()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_WallRun_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANewCharacter);
	UClass* Z_Construct_UClass_ANewCharacter_NoRegister()
	{
		return ANewCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ANewCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProneEyeHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProneEyeHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlideEyeHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SlideEyeHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VaultEyeHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VaultEyeHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewCharacterMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NewCharacterMovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MotionWarping_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MotionWarping;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANewCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ANewCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement, "CanCustomAdvancedMovement" }, // 23849012
		{ &Z_Construct_UFunction_ANewCharacter_Climb, "Climb" }, // 508110465
		{ &Z_Construct_UFunction_ANewCharacter_ClimbUp, "ClimbUp" }, // 685623370
		{ &Z_Construct_UFunction_ANewCharacter_CrouchSprint, "CrouchSprint" }, // 3954996373
		{ &Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics, "CustomAdvancedMovementPhysics" }, // 2940112524
		{ &Z_Construct_UFunction_ANewCharacter_Dash, "Dash" }, // 3856176094
		{ &Z_Construct_UFunction_ANewCharacter_FastFly, "FastFly" }, // 3407681376
		{ &Z_Construct_UFunction_ANewCharacter_FastSwim, "FastSwim" }, // 2757514799
		{ &Z_Construct_UFunction_ANewCharacter_Fly, "Fly" }, // 681585408
		{ &Z_Construct_UFunction_ANewCharacter_GetClimbUpData, "GetClimbUpData" }, // 111445489
		{ &Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData, "GetCustomAdvancedMovementData" }, // 2441346499
		{ &Z_Construct_UFunction_ANewCharacter_GetMantleData, "GetMantleData" }, // 4126256666
		{ &Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent, "GetMotionWarpingComponent" }, // 2725150200
		{ &Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent, "GetNewCharacterMovementComponent" }, // 3468633205
		{ &Z_Construct_UFunction_ANewCharacter_GetVaultData, "GetVaultData" }, // 4130312248
		{ &Z_Construct_UFunction_ANewCharacter_Mantle, "Mantle" }, // 464709597
		{ &Z_Construct_UFunction_ANewCharacter_Prone, "Prone" }, // 3444037703
		{ &Z_Construct_UFunction_ANewCharacter_Slide, "Slide" }, // 2825895138
		{ &Z_Construct_UFunction_ANewCharacter_Sprint, "Sprint" }, // 453974724
		{ &Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement, "StartCustomAdvancedMovement" }, // 350441478
		{ &Z_Construct_UFunction_ANewCharacter_StartFastMovement, "StartFastMovement" }, // 1728798419
		{ &Z_Construct_UFunction_ANewCharacter_StopClimb, "StopClimb" }, // 1351102994
		{ &Z_Construct_UFunction_ANewCharacter_StopClimbingUp, "StopClimbingUp" }, // 3576529907
		{ &Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting, "StopCrouchSprinting" }, // 823662212
		{ &Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement, "StopCustomAdvancedMovement" }, // 760967334
		{ &Z_Construct_UFunction_ANewCharacter_StopDashing, "StopDashing" }, // 742551542
		{ &Z_Construct_UFunction_ANewCharacter_StopFastFlying, "StopFastFlying" }, // 3231344612
		{ &Z_Construct_UFunction_ANewCharacter_StopFastMovement, "StopFastMovement" }, // 2367474070
		{ &Z_Construct_UFunction_ANewCharacter_StopFastSwimming, "StopFastSwimming" }, // 2825059893
		{ &Z_Construct_UFunction_ANewCharacter_StopFlying, "StopFlying" }, // 1749021663
		{ &Z_Construct_UFunction_ANewCharacter_StopMantling, "StopMantling" }, // 1940728425
		{ &Z_Construct_UFunction_ANewCharacter_StopPronning, "StopPronning" }, // 811478009
		{ &Z_Construct_UFunction_ANewCharacter_StopSliding, "StopSliding" }, // 2117515542
		{ &Z_Construct_UFunction_ANewCharacter_StopSprinting, "StopSprinting" }, // 50771186
		{ &Z_Construct_UFunction_ANewCharacter_StopVaulting, "StopVaulting" }, // 3423491923
		{ &Z_Construct_UFunction_ANewCharacter_StopWallRunning, "StopWallRunning" }, // 1920157023
		{ &Z_Construct_UFunction_ANewCharacter_Vault, "Vault" }, // 169008872
		{ &Z_Construct_UFunction_ANewCharacter_WallRun, "WallRun" }, // 2307473273
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * ANewCharacter\n *\n * This class represents a character that provides built-in compatibility\n * with motion warping and utilizes the new character movement component\n * for advanced locomotion mechanics. It extends the base ACharacter class\n * to allow for dynamic and flexible character movement behaviors, including\n * special movements such as climbing, vaulting, and more.\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "NewCharacter.h" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "ANewCharacter\n\nThis class represents a character that provides built-in compatibility\nwith motion warping and utilizes the new character movement component\nfor advanced locomotion mechanics. It extends the base ACharacter class\nto allow for dynamic and flexible character movement behaviors, including\nspecial movements such as climbing, vaulting, and more." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCharacter_Statics::NewProp_ProneEyeHeight_MetaData[] = {
		{ "Category", "Camera|Prone" },
		{ "Comment", "/**\n\x09 * The height of the character's eyes when in a prone position.\n\x09 * This value is used to adjust the camera view and ensure\n\x09 * accurate line of sight while the character is proned.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "The height of the character's eyes when in a prone position.\nThis value is used to adjust the camera view and ensure\naccurate line of sight while the character is proned." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_ProneEyeHeight = { "ProneEyeHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, ProneEyeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::NewProp_ProneEyeHeight_MetaData), Z_Construct_UClass_ANewCharacter_Statics::NewProp_ProneEyeHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCharacter_Statics::NewProp_SlideEyeHeight_MetaData[] = {
		{ "Category", "Camera|Slide" },
		{ "Comment", "/**\n\x09 * The height of the character's eyes when sliding.\n\x09 * This value is used to adjust the camera view during\n\x09 * sliding to provide a better perspective for aiming\n\x09 * or targeting while maintaining an appropriate field of vision.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "The height of the character's eyes when sliding.\nThis value is used to adjust the camera view during\nsliding to provide a better perspective for aiming\nor targeting while maintaining an appropriate field of vision." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_SlideEyeHeight = { "SlideEyeHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, SlideEyeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::NewProp_SlideEyeHeight_MetaData), Z_Construct_UClass_ANewCharacter_Statics::NewProp_SlideEyeHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCharacter_Statics::NewProp_VaultEyeHeight_MetaData[] = {
		{ "Category", "Camera|Vault" },
		{ "Comment", "/**\n\x09 * Specifies the camera height adjustment during a vaulting action.\n\x09 * This value determines how high the camera view should shift when the character initiates a vault,\n\x09 * providing a smoother visual transition and better perspective for the player.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Specifies the camera height adjustment during a vaulting action.\nThis value determines how high the camera view should shift when the character initiates a vault,\nproviding a smoother visual transition and better perspective for the player." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_VaultEyeHeight = { "VaultEyeHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, VaultEyeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::NewProp_VaultEyeHeight_MetaData), Z_Construct_UClass_ANewCharacter_Statics::NewProp_VaultEyeHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCharacter_Statics::NewProp_NewCharacterMovementComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_NewCharacterMovementComponent = { "NewCharacterMovementComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, NewCharacterMovementComponent), Z_Construct_UClass_UNewCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::NewProp_NewCharacterMovementComponent_MetaData), Z_Construct_UClass_ANewCharacter_Statics::NewProp_NewCharacterMovementComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCharacter_Statics::NewProp_MotionWarping_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_MotionWarping = { "MotionWarping", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, MotionWarping), Z_Construct_UClass_UMotionWarpingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::NewProp_MotionWarping_MetaData), Z_Construct_UClass_ANewCharacter_Statics::NewProp_MotionWarping_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANewCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_ProneEyeHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_SlideEyeHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_VaultEyeHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_NewCharacterMovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_MotionWarping,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANewCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANewCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANewCharacter_Statics::ClassParams = {
		&ANewCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ANewCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ANewCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANewCharacter()
	{
		if (!Z_Registration_Info_UClass_ANewCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANewCharacter.OuterSingleton, Z_Construct_UClass_ANewCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANewCharacter.OuterSingleton;
	}
	template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<ANewCharacter>()
	{
		return ANewCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANewCharacter);
	ANewCharacter::~ANewCharacter() {}
	struct Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANewCharacter, ANewCharacter::StaticClass, TEXT("ANewCharacter"), &Z_Registration_Info_UClass_ANewCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANewCharacter), 934233374U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_3628362243(TEXT("/Script/CharacterLocomotionSystem"),
		Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
