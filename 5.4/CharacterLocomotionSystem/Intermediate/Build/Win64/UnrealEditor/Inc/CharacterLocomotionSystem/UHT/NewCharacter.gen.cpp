// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/NewCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNewCharacter() {}

// Begin Cross Module References
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

// Begin Class ANewCharacter Function AddAndUpdateCustomAdvancedWarpTargets
static FName NAME_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets = FName(TEXT("AddAndUpdateCustomAdvancedWarpTargets"));
void ANewCharacter::AddAndUpdateCustomAdvancedWarpTargets()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets),NULL);
}
struct Z_Construct_UFunction_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Updates and adds custom warp targets for advanced movement during root motion.\n\x09 * This function allows dynamic updates to custom warp targets used during root motion-based movement states.\n\x09 * BlueprintNativeEvent enables the ability to adjust these targets through Blueprints at runtime.\n\x09 *\n\x09 * @note: This function is intended to handle warp target updates for root motion and should be extended\n\x09 *        with specific logic in the Implementation.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Updates and adds custom warp targets for advanced movement during root motion.\nThis function allows dynamic updates to custom warp targets used during root motion-based movement states.\nBlueprintNativeEvent enables the ability to adjust these targets through Blueprints at runtime.\n\n@note: This function is intended to handle warp target updates for root motion and should be extended\n       with specific logic in the Implementation." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "AddAndUpdateCustomAdvancedWarpTargets", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execAddAndUpdateCustomAdvancedWarpTargets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddAndUpdateCustomAdvancedWarpTargets_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function AddAndUpdateCustomAdvancedWarpTargets

// Begin Class ANewCharacter Function CanCustomAdvancedMovement
struct NewCharacter_eventCanCustomAdvancedMovement_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventCanCustomAdvancedMovement_Parms()
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
struct Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Determines if the character is permitted to initiate root motion-based custom advanced movement.\n\x09 * This function checks gameplay-related conditions, enforcing rules or restrictions\n\x09 * specific to root motion sequences. BlueprintNativeEvent allows additional condition checks in Blueprints.\n\x09 *\n\x09 * @return True if custom root motion movement is allowed; false otherwise.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Determines if the character is permitted to initiate root motion-based custom advanced movement.\nThis function checks gameplay-related conditions, enforcing rules or restrictions\nspecific to root motion sequences. BlueprintNativeEvent allows additional condition checks in Blueprints.\n\n@return True if custom root motion movement is allowed; false otherwise." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CanCustomAdvancedMovement", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::PropPointers), sizeof(NewCharacter_eventCanCustomAdvancedMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execCanCustomAdvancedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanCustomAdvancedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function CanCustomAdvancedMovement

// Begin Class ANewCharacter Function CanCustomExtendedMovement
struct NewCharacter_eventCanCustomExtendedMovement_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventCanCustomExtendedMovement_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_ANewCharacter_CanCustomExtendedMovement = FName(TEXT("CanCustomExtendedMovement"));
bool ANewCharacter::CanCustomExtendedMovement()
{
	NewCharacter_eventCanCustomExtendedMovement_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_CanCustomExtendedMovement),&Parms);
	return !!Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "Comment", "/**\n\x09 * Determines if the character is permitted to initiate extended custom movement.\n\x09 * Evaluates gameplay conditions to check if custom extended movement is allowed.\n\x09 * Useful for enforcing gameplay rules or restricting movement based on context.\n\x09 * BlueprintNativeEvent enables additional conditional checks within Blueprints.\n\x09 *\n\x09 * @return True if custom extended movement is allowed; false otherwise.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Determines if the character is permitted to initiate extended custom movement.\nEvaluates gameplay conditions to check if custom extended movement is allowed.\nUseful for enforcing gameplay rules or restricting movement based on context.\nBlueprintNativeEvent enables additional conditional checks within Blueprints.\n\n@return True if custom extended movement is allowed; false otherwise." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((NewCharacter_eventCanCustomExtendedMovement_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventCanCustomExtendedMovement_Parms), &Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CanCustomExtendedMovement", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::PropPointers), sizeof(NewCharacter_eventCanCustomExtendedMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::Function_MetaDataParams) };
static_assert(sizeof(NewCharacter_eventCanCustomExtendedMovement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execCanCustomExtendedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanCustomExtendedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function CanCustomExtendedMovement

// Begin Class ANewCharacter Function Climb
struct Z_Construct_UFunction_ANewCharacter_Climb_Statics
{
	struct NewCharacter_eventClimb_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Climb" },
		{ "Comment", "/**\n\x09 * Attempts to initiate the climbing action for the character.\n\x09 * @return True if the character successfully transitions into a climbing state, otherwise false.\n\x09 * Indicates that the character can begin climbing based on current movement\n\x09 * conditions and the presence of a valid climbable surface.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate the climbing action for the character.\n@return True if the character successfully transitions into a climbing state, otherwise false.\nIndicates that the character can begin climbing based on current movement\nconditions and the presence of a valid climbable surface." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Climb_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Climb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Climb", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Climb_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Climb_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Climb_Statics::NewCharacter_eventClimb_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Climb_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Climb_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execClimb)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Climb();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Climb

// Begin Class ANewCharacter Function ClimbUp
struct Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics
{
	struct NewCharacter_eventClimbUp_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|ClimbUp" },
		{ "Comment", "/**\n\x09 * Initiates the climbing-up action for the character.\n\x09 * This function checks the conditions and attempts to start the\n\x09 * climbing-up movement based on the current character state and environment.\n\x09 *\n\x09 * @return True if the climbing-up action was successfully initiated; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates the climbing-up action for the character.\nThis function checks the conditions and attempts to start the\nclimbing-up movement based on the current character state and environment.\n\n@return True if the climbing-up action was successfully initiated; otherwise, false." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "ClimbUp", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::NewCharacter_eventClimbUp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_ClimbUp_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execClimbUp)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ClimbUp();
	P_NATIVE_END;
}
// End Class ANewCharacter Function ClimbUp

// Begin Class ANewCharacter Function CrouchSprint
struct Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics
{
	struct NewCharacter_eventCrouchSprint_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|CrouchSprint" },
		{ "Comment", "/**\n\x09 * Attempts to start crouch sprinting for the character.\n\x09 * This may also affect standard sprint behavior due to interconnected functionality.\n\x09 * @return True if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start crouch sprinting for the character.\nThis may also affect standard sprint behavior due to interconnected functionality.\n@return True if the action is successful." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CrouchSprint", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::NewCharacter_eventCrouchSprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CrouchSprint_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execCrouchSprint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CrouchSprint();
	P_NATIVE_END;
}
// End Class ANewCharacter Function CrouchSprint

// Begin Class ANewCharacter Function CustomAdvancedMovementPhysics
struct NewCharacter_eventCustomAdvancedMovementPhysics_Parms
{
	float deltaTime;
	int32 Iterations;
};
static FName NAME_ANewCharacter_CustomAdvancedMovementPhysics = FName(TEXT("CustomAdvancedMovementPhysics"));
void ANewCharacter::CustomAdvancedMovementPhysics(float deltaTime, int32 Iterations)
{
	NewCharacter_eventCustomAdvancedMovementPhysics_Parms Parms;
	Parms.deltaTime=deltaTime;
	Parms.Iterations=Iterations;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_CustomAdvancedMovementPhysics),&Parms);
}
struct Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Executes custom physics calculations specifically tailored to root motion-based advanced movement.\n\x09 * Called every frame to apply physics logic required by root motion montages. Parameters deltaTime and\n\x09 * Iterations provide granular control over calculations. BlueprintNativeEvent allows for frame-specific\n\x09 * adjustments within Blueprints.\n\x09 *\n\x09 * @param deltaTime The time elapsed since the previous frame.\n\x09 * @param Iterations The number of iterations for physics calculations to apply.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Executes custom physics calculations specifically tailored to root motion-based advanced movement.\nCalled every frame to apply physics logic required by root motion montages. Parameters deltaTime and\nIterations provide granular control over calculations. BlueprintNativeEvent allows for frame-specific\nadjustments within Blueprints.\n\n@param deltaTime The time elapsed since the previous frame.\n@param Iterations The number of iterations for physics calculations to apply." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_deltaTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Iterations;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_deltaTime = { "deltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventCustomAdvancedMovementPhysics_Parms, deltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_Iterations = { "Iterations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventCustomAdvancedMovementPhysics_Parms, Iterations), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_deltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::NewProp_Iterations,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CustomAdvancedMovementPhysics", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::PropPointers), sizeof(NewCharacter_eventCustomAdvancedMovementPhysics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execCustomAdvancedMovementPhysics)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_deltaTime);
	P_GET_PROPERTY(FIntProperty,Z_Param_Iterations);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CustomAdvancedMovementPhysics_Implementation(Z_Param_deltaTime,Z_Param_Iterations);
	P_NATIVE_END;
}
// End Class ANewCharacter Function CustomAdvancedMovementPhysics

// Begin Class ANewCharacter Function CustomExtendedMovementPhysics
struct NewCharacter_eventCustomExtendedMovementPhysics_Parms
{
	float deltaTime;
	int32 Iterations;
};
static FName NAME_ANewCharacter_CustomExtendedMovementPhysics = FName(TEXT("CustomExtendedMovementPhysics"));
void ANewCharacter::CustomExtendedMovementPhysics(float deltaTime, int32 Iterations)
{
	NewCharacter_eventCustomExtendedMovementPhysics_Parms Parms;
	Parms.deltaTime=deltaTime;
	Parms.Iterations=Iterations;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_CustomExtendedMovementPhysics),&Parms);
}
struct Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "Comment", "/**\n\x09 * Executes custom physics calculations specific to extended movement.\n\x09 * Called every frame to apply physics-based logic required for non-root motion montage extended movement mechanics,\n\x09 * allowing fine-tuned adjustments. The deltaTime and Iterations parameters provide detailed control of calculations.\n\x09 * BlueprintNativeEvent allows for experimental frame-specific adjustments within Blueprints.\n\x09 *\n\x09 * @param deltaTime The time elapsed since the previous frame.\n\x09 * @param Iterations The number of iterations for physics calculations.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Executes custom physics calculations specific to extended movement.\nCalled every frame to apply physics-based logic required for non-root motion montage extended movement mechanics,\nallowing fine-tuned adjustments. The deltaTime and Iterations parameters provide detailed control of calculations.\nBlueprintNativeEvent allows for experimental frame-specific adjustments within Blueprints.\n\n@param deltaTime The time elapsed since the previous frame.\n@param Iterations The number of iterations for physics calculations." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_deltaTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Iterations;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::NewProp_deltaTime = { "deltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventCustomExtendedMovementPhysics_Parms, deltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::NewProp_Iterations = { "Iterations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventCustomExtendedMovementPhysics_Parms, Iterations), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::NewProp_deltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::NewProp_Iterations,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "CustomExtendedMovementPhysics", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::PropPointers), sizeof(NewCharacter_eventCustomExtendedMovementPhysics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::Function_MetaDataParams) };
static_assert(sizeof(NewCharacter_eventCustomExtendedMovementPhysics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execCustomExtendedMovementPhysics)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_deltaTime);
	P_GET_PROPERTY(FIntProperty,Z_Param_Iterations);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CustomExtendedMovementPhysics_Implementation(Z_Param_deltaTime,Z_Param_Iterations);
	P_NATIVE_END;
}
// End Class ANewCharacter Function CustomExtendedMovementPhysics

// Begin Class ANewCharacter Function Dash
struct Z_Construct_UFunction_ANewCharacter_Dash_Statics
{
	struct NewCharacter_eventDash_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Dash" },
		{ "Comment", "/**\n\x09 * Attempts to start dashing for the character.\n\x09 * @return True if the character successfully starts dashing, otherwise false.\n\x09 * Indicates that the character can dash based on current conditions.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start dashing for the character.\n@return True if the character successfully starts dashing, otherwise false.\nIndicates that the character can dash based on current conditions." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Dash_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Dash_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Dash", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Dash_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Dash_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Dash_Statics::NewCharacter_eventDash_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Dash_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Dash_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execDash)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Dash();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Dash

// Begin Class ANewCharacter Function EnterCustomAdvancedMovement
static FName NAME_ANewCharacter_EnterCustomAdvancedMovement = FName(TEXT("EnterCustomAdvancedMovement"));
void ANewCharacter::EnterCustomAdvancedMovement()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_EnterCustomAdvancedMovement),NULL);
}
struct Z_Construct_UFunction_ANewCharacter_EnterCustomAdvancedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Enters the character into a custom advanced movement state specifically for root motion montages.\n\x09 * Sets the necessary parameters to begin custom movement mechanics based on root motion.\n\x09 * BlueprintNativeEvent enables experimental Blueprint-based overrides to expand functionality.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Enters the character into a custom advanced movement state specifically for root motion montages.\nSets the necessary parameters to begin custom movement mechanics based on root motion.\nBlueprintNativeEvent enables experimental Blueprint-based overrides to expand functionality." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_EnterCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "EnterCustomAdvancedMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_EnterCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_EnterCustomAdvancedMovement_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewCharacter_EnterCustomAdvancedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_EnterCustomAdvancedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execEnterCustomAdvancedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EnterCustomAdvancedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function EnterCustomAdvancedMovement

// Begin Class ANewCharacter Function EnterCustomExtendedMovement
static FName NAME_ANewCharacter_EnterCustomExtendedMovement = FName(TEXT("EnterCustomExtendedMovement"));
void ANewCharacter::EnterCustomExtendedMovement()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_EnterCustomExtendedMovement),NULL);
}
struct Z_Construct_UFunction_ANewCharacter_EnterCustomExtendedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "Comment", "/**\n\x09 * Enters the character into an extended custom movement state, specifically for non-root motion montages.\n\x09 * Primarily intended for specialized movement sequences that require transitioning into unique movement behaviors.\n\x09 * This function sets the necessary parameters to initiate custom extended movement mechanics.\n\x09 * BlueprintNativeEvent allows for experimental overrides within Blueprints.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Enters the character into an extended custom movement state, specifically for non-root motion montages.\nPrimarily intended for specialized movement sequences that require transitioning into unique movement behaviors.\nThis function sets the necessary parameters to initiate custom extended movement mechanics.\nBlueprintNativeEvent allows for experimental overrides within Blueprints." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_EnterCustomExtendedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "EnterCustomExtendedMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_EnterCustomExtendedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_EnterCustomExtendedMovement_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewCharacter_EnterCustomExtendedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_EnterCustomExtendedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execEnterCustomExtendedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EnterCustomExtendedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function EnterCustomExtendedMovement

// Begin Class ANewCharacter Function ExitCustomAdvancedMovement
static FName NAME_ANewCharacter_ExitCustomAdvancedMovement = FName(TEXT("ExitCustomAdvancedMovement"));
void ANewCharacter::ExitCustomAdvancedMovement()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_ExitCustomAdvancedMovement),NULL);
}
struct Z_Construct_UFunction_ANewCharacter_ExitCustomAdvancedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Exits the character from a root motion-based custom advanced movement state.\n\x09 * Used to end advanced movement sequences that rely on root motion and revert back to standard\n\x09 * movement. Ensures smooth transitions and proper state cleanup.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Exits the character from a root motion-based custom advanced movement state.\nUsed to end advanced movement sequences that rely on root motion and revert back to standard\nmovement. Ensures smooth transitions and proper state cleanup." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_ExitCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "ExitCustomAdvancedMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ExitCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_ExitCustomAdvancedMovement_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewCharacter_ExitCustomAdvancedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_ExitCustomAdvancedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execExitCustomAdvancedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExitCustomAdvancedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function ExitCustomAdvancedMovement

// Begin Class ANewCharacter Function ExitCustomExtendedMovement
static FName NAME_ANewCharacter_ExitCustomExtendedMovement = FName(TEXT("ExitCustomExtendedMovement"));
void ANewCharacter::ExitCustomExtendedMovement()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_ExitCustomExtendedMovement),NULL);
}
struct Z_Construct_UFunction_ANewCharacter_ExitCustomExtendedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "Comment", "/**\n\x09 * Exits the character from an extended custom movement state for non-root motion montages.\n\x09 * Transitions the character out of extended movement and back to standard movement settings.\n\x09 * Ensures smooth transitions and proper state cleanup, making it ideal for adding experimental custom exit logic.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Exits the character from an extended custom movement state for non-root motion montages.\nTransitions the character out of extended movement and back to standard movement settings.\nEnsures smooth transitions and proper state cleanup, making it ideal for adding experimental custom exit logic." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_ExitCustomExtendedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "ExitCustomExtendedMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_ExitCustomExtendedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_ExitCustomExtendedMovement_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewCharacter_ExitCustomExtendedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_ExitCustomExtendedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execExitCustomExtendedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExitCustomExtendedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function ExitCustomExtendedMovement

// Begin Class ANewCharacter Function FastFly
struct Z_Construct_UFunction_ANewCharacter_FastFly_Statics
{
	struct NewCharacter_eventFastFly_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Attempts to start fast flying for the character.\n\x09 * Returns true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start fast flying for the character.\nReturns true if the action is successful." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_FastFly_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "FastFly", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_FastFly_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::NewCharacter_eventFastFly_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastFly_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_FastFly_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execFastFly)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->FastFly();
	P_NATIVE_END;
}
// End Class ANewCharacter Function FastFly

// Begin Class ANewCharacter Function FastSwim
struct Z_Construct_UFunction_ANewCharacter_FastSwim_Statics
{
	struct NewCharacter_eventFastSwim_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Swim" },
		{ "Comment", "/**\n\x09 * Attempts to start fast swimming for the character.\n\x09 * Returns true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start fast swimming for the character.\nReturns true if the action is successful." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "FastSwim", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::NewCharacter_eventFastSwim_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_FastSwim_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execFastSwim)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->FastSwim();
	P_NATIVE_END;
}
// End Class ANewCharacter Function FastSwim

// Begin Class ANewCharacter Function Fly
struct Z_Construct_UFunction_ANewCharacter_Fly_Statics
{
	struct NewCharacter_eventFly_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Attempts to start flying for the character.\n\x09 * Returns true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start flying for the character.\nReturns true if the action is successful." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Fly_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Fly_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Fly", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Fly_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Fly_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Fly_Statics::NewCharacter_eventFly_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Fly_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Fly_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execFly)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Fly();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Fly

// Begin Class ANewCharacter Function GetClimbUpData
struct NewCharacter_eventGetClimbUpData_Parms
{
	UClimbUpPrimaryDataAsset* ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetClimbUpData_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_ANewCharacter_GetClimbUpData = FName(TEXT("GetClimbUpData"));
UClimbUpPrimaryDataAsset* ANewCharacter::GetClimbUpData()
{
	NewCharacter_eventGetClimbUpData_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetClimbUpData),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|ClimbUp" },
		{ "Comment", "/**\n\x09 * Retrieves the climb-up data asset associated with this character.\n\x09 * This function provides access to specific parameters and settings\n\x09 * related to climbing up mechanics.\n\x09 *\n\x09 * @return Pointer to the UClimbUpPrimaryDataAsset instance containing climb-up data.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the climb-up data asset associated with this character.\nThis function provides access to specific parameters and settings\nrelated to climbing up mechanics.\n\n@return Pointer to the UClimbUpPrimaryDataAsset instance containing climb-up data." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetClimbUpData_Parms, ReturnValue), Z_Construct_UClass_UClimbUpPrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetClimbUpData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::PropPointers), sizeof(NewCharacter_eventGetClimbUpData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetClimbUpData_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execGetClimbUpData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UClimbUpPrimaryDataAsset**)Z_Param__Result=P_THIS->GetClimbUpData_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetClimbUpData

// Begin Class ANewCharacter Function GetCustomAdvancedMovementData
struct NewCharacter_eventGetCustomAdvancedMovementData_Parms
{
	UAdvancedMovementPrimaryDataAsset* ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetCustomAdvancedMovementData_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_ANewCharacter_GetCustomAdvancedMovementData = FName(TEXT("GetCustomAdvancedMovementData"));
UAdvancedMovementPrimaryDataAsset* ANewCharacter::GetCustomAdvancedMovementData() const
{
	NewCharacter_eventGetCustomAdvancedMovementData_Parms Parms;
	const_cast<ANewCharacter*>(this)->ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetCustomAdvancedMovementData),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Retrieves the custom advanced movement data asset associated with this character.\n\x09 * Provides access to configurable parameters that influence advanced movement\n\x09 * capabilities, allowing flexibility in custom movement behaviors.\n\x09 * This function is a BlueprintNativeEvent, meaning it can be overridden in\n\x09 * Blueprints for further customization.\n\x09 *\n\x09 * @return Pointer to a UAdvancedMovementPrimaryDataAsset instance if available;\n\x09 *         nullptr otherwise.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the custom advanced movement data asset associated with this character.\nProvides access to configurable parameters that influence advanced movement\ncapabilities, allowing flexibility in custom movement behaviors.\nThis function is a BlueprintNativeEvent, meaning it can be overridden in\nBlueprints for further customization.\n\n@return Pointer to a UAdvancedMovementPrimaryDataAsset instance if available;\n        nullptr otherwise." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetCustomAdvancedMovementData_Parms, ReturnValue), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetCustomAdvancedMovementData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::PropPointers), sizeof(NewCharacter_eventGetCustomAdvancedMovementData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execGetCustomAdvancedMovementData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAdvancedMovementPrimaryDataAsset**)Z_Param__Result=P_THIS->GetCustomAdvancedMovementData_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetCustomAdvancedMovementData

// Begin Class ANewCharacter Function GetMantleData
struct NewCharacter_eventGetMantleData_Parms
{
	UMantlePrimaryDataAsset* ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetMantleData_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_ANewCharacter_GetMantleData = FName(TEXT("GetMantleData"));
UMantlePrimaryDataAsset* ANewCharacter::GetMantleData()
{
	NewCharacter_eventGetMantleData_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetMantleData),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Mantle" },
		{ "Comment", "/**\n\x09 * Retrieves the mantle data asset associated with this character.\n\x09 * This function provides access to specific parameters and settings\n\x09 * related to mantling mechanics.\n\x09 *\n\x09 * @return Pointer to the UMantlePrimaryDataAsset instance containing mantle data.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the mantle data asset associated with this character.\nThis function provides access to specific parameters and settings\nrelated to mantling mechanics.\n\n@return Pointer to the UMantlePrimaryDataAsset instance containing mantle data." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMantleData_Parms, ReturnValue), Z_Construct_UClass_UMantlePrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMantleData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::PropPointers), sizeof(NewCharacter_eventGetMantleData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMantleData_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execGetMantleData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMantlePrimaryDataAsset**)Z_Param__Result=P_THIS->GetMantleData_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetMantleData

// Begin Class ANewCharacter Function GetMaxCustomAdvancedSpeed
struct NewCharacter_eventGetMaxCustomAdvancedSpeed_Parms
{
	float ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetMaxCustomAdvancedSpeed_Parms()
		: ReturnValue(0)
	{
	}
};
static FName NAME_ANewCharacter_GetMaxCustomAdvancedSpeed = FName(TEXT("GetMaxCustomAdvancedSpeed"));
float ANewCharacter::GetMaxCustomAdvancedSpeed()
{
	NewCharacter_eventGetMaxCustomAdvancedSpeed_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetMaxCustomAdvancedSpeed),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Retrieves the maximum speed allowed during root motion-based custom advanced movement.\n\x09 * Allows setting custom maximum speeds specifically for root motion-based movement states.\n\x09 * BlueprintNativeEvent enables dynamic speed adjustments in Blueprints.\n\x09 *\n\x09 * @return The maximum speed permitted during custom root motion movement.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the maximum speed allowed during root motion-based custom advanced movement.\nAllows setting custom maximum speeds specifically for root motion-based movement states.\nBlueprintNativeEvent enables dynamic speed adjustments in Blueprints.\n\n@return The maximum speed permitted during custom root motion movement." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMaxCustomAdvancedSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMaxCustomAdvancedSpeed", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::PropPointers), sizeof(NewCharacter_eventGetMaxCustomAdvancedSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::Function_MetaDataParams) };
static_assert(sizeof(NewCharacter_eventGetMaxCustomAdvancedSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execGetMaxCustomAdvancedSpeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMaxCustomAdvancedSpeed_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetMaxCustomAdvancedSpeed

// Begin Class ANewCharacter Function GetMaxCustomExtendedAcceleration
struct NewCharacter_eventGetMaxCustomExtendedAcceleration_Parms
{
	float ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetMaxCustomExtendedAcceleration_Parms()
		: ReturnValue(0)
	{
	}
};
static FName NAME_ANewCharacter_GetMaxCustomExtendedAcceleration = FName(TEXT("GetMaxCustomExtendedAcceleration"));
float ANewCharacter::GetMaxCustomExtendedAcceleration()
{
	NewCharacter_eventGetMaxCustomExtendedAcceleration_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetMaxCustomExtendedAcceleration),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMaxCustomExtendedAcceleration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMaxCustomExtendedAcceleration", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::PropPointers), sizeof(NewCharacter_eventGetMaxCustomExtendedAcceleration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::Function_MetaDataParams) };
static_assert(sizeof(NewCharacter_eventGetMaxCustomExtendedAcceleration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execGetMaxCustomExtendedAcceleration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMaxCustomExtendedAcceleration_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetMaxCustomExtendedAcceleration

// Begin Class ANewCharacter Function GetMaxCustomExtendedDeceleration
struct NewCharacter_eventGetMaxCustomExtendedDeceleration_Parms
{
	float ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetMaxCustomExtendedDeceleration_Parms()
		: ReturnValue(0)
	{
	}
};
static FName NAME_ANewCharacter_GetMaxCustomExtendedDeceleration = FName(TEXT("GetMaxCustomExtendedDeceleration"));
float ANewCharacter::GetMaxCustomExtendedDeceleration()
{
	NewCharacter_eventGetMaxCustomExtendedDeceleration_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetMaxCustomExtendedDeceleration),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMaxCustomExtendedDeceleration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMaxCustomExtendedDeceleration", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::PropPointers), sizeof(NewCharacter_eventGetMaxCustomExtendedDeceleration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::Function_MetaDataParams) };
static_assert(sizeof(NewCharacter_eventGetMaxCustomExtendedDeceleration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execGetMaxCustomExtendedDeceleration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMaxCustomExtendedDeceleration_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetMaxCustomExtendedDeceleration

// Begin Class ANewCharacter Function GetMaxCustomExtendedSpeed
struct NewCharacter_eventGetMaxCustomExtendedSpeed_Parms
{
	float ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetMaxCustomExtendedSpeed_Parms()
		: ReturnValue(0)
	{
	}
};
static FName NAME_ANewCharacter_GetMaxCustomExtendedSpeed = FName(TEXT("GetMaxCustomExtendedSpeed"));
float ANewCharacter::GetMaxCustomExtendedSpeed()
{
	NewCharacter_eventGetMaxCustomExtendedSpeed_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetMaxCustomExtendedSpeed),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "Comment", "/**\n\x09 * Retrieves the maximum speed permitted during extended custom movement.\n\x09 * Supports varying maximum speeds for extended movement states, providing control\n\x09 * over movement capabilities based on the current state. BlueprintNativeEvent allows for experimental\n\x09 * Blueprint-based overrides to dynamically adjust speed, specifically for non-root motion montages.\n\x09 *\n\x09 * @return The maximum speed allowed during extended custom movement.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the maximum speed permitted during extended custom movement.\nSupports varying maximum speeds for extended movement states, providing control\nover movement capabilities based on the current state. BlueprintNativeEvent allows for experimental\nBlueprint-based overrides to dynamically adjust speed, specifically for non-root motion montages.\n\n@return The maximum speed allowed during extended custom movement." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMaxCustomExtendedSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMaxCustomExtendedSpeed", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::PropPointers), sizeof(NewCharacter_eventGetMaxCustomExtendedSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::Function_MetaDataParams) };
static_assert(sizeof(NewCharacter_eventGetMaxCustomExtendedSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execGetMaxCustomExtendedSpeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMaxCustomExtendedSpeed_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetMaxCustomExtendedSpeed

// Begin Class ANewCharacter Function GetMotionWarpingComponent
struct Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics
{
	struct NewCharacter_eventGetMotionWarpingComponent_Parms
	{
		UMotionWarpingComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AllowProtectedAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "/** Returns MotionWarping Component subobject **/" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Returns MotionWarping Component subobject *" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetMotionWarpingComponent_Parms, ReturnValue), Z_Construct_UClass_UMotionWarpingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetMotionWarpingComponent", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::NewCharacter_eventGetMotionWarpingComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execGetMotionWarpingComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMotionWarpingComponent**)Z_Param__Result=P_THIS->GetMotionWarpingComponent();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetMotionWarpingComponent

// Begin Class ANewCharacter Function GetNewCharacterMovementComponent
struct Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics
{
	struct NewCharacter_eventGetNewCharacterMovementComponent_Parms
	{
		UNewCharacterMovementComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AllowProtectedAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "/** Returns NewCharacterMovementComponent subobject **/" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Returns NewCharacterMovementComponent subobject *" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetNewCharacterMovementComponent_Parms, ReturnValue), Z_Construct_UClass_UNewCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetNewCharacterMovementComponent", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::NewCharacter_eventGetNewCharacterMovementComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execGetNewCharacterMovementComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UNewCharacterMovementComponent**)Z_Param__Result=P_THIS->GetNewCharacterMovementComponent();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetNewCharacterMovementComponent

// Begin Class ANewCharacter Function GetVaultData
struct NewCharacter_eventGetVaultData_Parms
{
	UVaultPrimaryDataAsset* ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventGetVaultData_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_ANewCharacter_GetVaultData = FName(TEXT("GetVaultData"));
UVaultPrimaryDataAsset* ANewCharacter::GetVaultData()
{
	NewCharacter_eventGetVaultData_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_GetVaultData),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Vault" },
		{ "Comment", "/**\n\x09 * Retrieves the vault data asset associated with this character.\n\x09 * This function provides access to the vaulting parameters that control\n\x09 * the character's vaulting behavior.\n\x09 *\n\x09 * @return Pointer to the UVaultPrimaryDataAsset instance.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Retrieves the vault data asset associated with this character.\nThis function provides access to the vaulting parameters that control\nthe character's vaulting behavior.\n\n@return Pointer to the UVaultPrimaryDataAsset instance." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewCharacter_eventGetVaultData_Parms, ReturnValue), Z_Construct_UClass_UVaultPrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "GetVaultData", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::PropPointers), sizeof(NewCharacter_eventGetVaultData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_GetVaultData_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execGetVaultData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UVaultPrimaryDataAsset**)Z_Param__Result=P_THIS->GetVaultData_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function GetVaultData

// Begin Class ANewCharacter Function Mantle
struct Z_Construct_UFunction_ANewCharacter_Mantle_Statics
{
	struct NewCharacter_eventMantle_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Mantle" },
		{ "Comment", "/**\n\x09 * Initiates the mantling action for the character.\n\x09 * This function checks the conditions and attempts to start the\n\x09 * mantling movement based on the current character state and environment.\n\x09 *\n\x09 * @return True if the mantling action was successfully initiated; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates the mantling action for the character.\nThis function checks the conditions and attempts to start the\nmantling movement based on the current character state and environment.\n\n@return True if the mantling action was successfully initiated; otherwise, false." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Mantle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Mantle", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Mantle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::NewCharacter_eventMantle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Mantle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Mantle_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execMantle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Mantle();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Mantle

// Begin Class ANewCharacter Function Prone
struct Z_Construct_UFunction_ANewCharacter_Prone_Statics
{
	struct NewCharacter_eventProne_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Prone" },
		{ "Comment", "/**\n\x09 * Attempts to start the proning action for the character.\n\x09 * @return True if the character successfully transitions into a prone position, otherwise false.\n\x09 * Indicates that the character can transition into a prone position based on current conditions.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start the proning action for the character.\n@return True if the character successfully transitions into a prone position, otherwise false.\nIndicates that the character can transition into a prone position based on current conditions." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Prone_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Prone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Prone", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Prone_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Prone_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Prone_Statics::NewCharacter_eventProne_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Prone_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Prone_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execProne)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Prone();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Prone

// Begin Class ANewCharacter Function Slide
struct Z_Construct_UFunction_ANewCharacter_Slide_Statics
{
	struct NewCharacter_eventSlide_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Slide" },
		{ "Comment", "/**\n\x09 * Attempts to initiate the sliding action for the character.\n\x09 * @return True if the character successfully transitions into a sliding state, otherwise false.\n\x09 * Indicates that the character can transition into a sliding state based on\n\x09 * current movement conditions and environment.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate the sliding action for the character.\n@return True if the character successfully transitions into a sliding state, otherwise false.\nIndicates that the character can transition into a sliding state based on\ncurrent movement conditions and environment." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Slide_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Slide_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Slide", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Slide_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Slide_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Slide_Statics::NewCharacter_eventSlide_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Slide_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Slide_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execSlide)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Slide();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Slide

// Begin Class ANewCharacter Function Sprint
struct Z_Construct_UFunction_ANewCharacter_Sprint_Statics
{
	struct NewCharacter_eventSprint_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Sprint" },
		{ "Comment", "/**\n\x09 * Attempts to start sprinting for the character.\n\x09 * Sprinting is interconnected with crouch sprinting, and initiating sprint may impact crouch sprint behavior.\n\x09 * @return True if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to start sprinting for the character.\nSprinting is interconnected with crouch sprinting, and initiating sprint may impact crouch sprint behavior.\n@return True if the action is successful." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Sprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Sprint", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Sprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::NewCharacter_eventSprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Sprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Sprint_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execSprint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Sprint();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Sprint

// Begin Class ANewCharacter Function StartCustomAdvancedMovement
struct NewCharacter_eventStartCustomAdvancedMovement_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventStartCustomAdvancedMovement_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_ANewCharacter_StartCustomAdvancedMovement = FName(TEXT("StartCustomAdvancedMovement"));
bool ANewCharacter::StartCustomAdvancedMovement()
{
	NewCharacter_eventStartCustomAdvancedMovement_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_StartCustomAdvancedMovement),&Parms);
	return !!Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Initiates custom advanced movement for the character using root motion montages.\n\x09 * This function assesses conditions and triggers necessary state changes to\n\x09 * activate custom movement logic that relies on root motion. Intended as an entry\n\x09 * point for root motion-based advanced movement, enabling experimental gameplay mechanics.\n\x09 * BlueprintNativeEvent allows this function to be customized in Blueprints.\n\x09 *\n\x09 * @return True if the custom movement initiation is successful, false otherwise.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates custom advanced movement for the character using root motion montages.\nThis function assesses conditions and triggers necessary state changes to\nactivate custom movement logic that relies on root motion. Intended as an entry\npoint for root motion-based advanced movement, enabling experimental gameplay mechanics.\nBlueprintNativeEvent allows this function to be customized in Blueprints.\n\n@return True if the custom movement initiation is successful, false otherwise." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StartCustomAdvancedMovement", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::PropPointers), sizeof(NewCharacter_eventStartCustomAdvancedMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execStartCustomAdvancedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartCustomAdvancedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StartCustomAdvancedMovement

// Begin Class ANewCharacter Function StartCustomExtendedMovement
struct NewCharacter_eventStartCustomExtendedMovement_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	NewCharacter_eventStartCustomExtendedMovement_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_ANewCharacter_StartCustomExtendedMovement = FName(TEXT("StartCustomExtendedMovement"));
bool ANewCharacter::StartCustomExtendedMovement()
{
	NewCharacter_eventStartCustomExtendedMovement_Parms Parms;
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_StartCustomExtendedMovement),&Parms);
	return !!Parms.ReturnValue;
}
struct Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "Comment", "/**\n\x09 * Initiates extended custom movement for the character, specifically for non-root motion montages.\n\x09 * This function evaluates necessary conditions and triggers state changes to activate extended movement logic.\n\x09 * Serves as an entry point for advanced extended movement, enabling specialized gameplay mechanics for non root motion\n\x09 * montage movements only.\n\x09 * BlueprintNativeEvent allows this function to be customized in Blueprints.\n\x09 *\n\x09 * @return True if the custom movement initiation is successful; false otherwise.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates extended custom movement for the character, specifically for non-root motion montages.\nThis function evaluates necessary conditions and triggers state changes to activate extended movement logic.\nServes as an entry point for advanced extended movement, enabling specialized gameplay mechanics for non root motion\nmontage movements only.\nBlueprintNativeEvent allows this function to be customized in Blueprints.\n\n@return True if the custom movement initiation is successful; false otherwise." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((NewCharacter_eventStartCustomExtendedMovement_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NewCharacter_eventStartCustomExtendedMovement_Parms), &Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StartCustomExtendedMovement", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::PropPointers), sizeof(NewCharacter_eventStartCustomExtendedMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::Function_MetaDataParams) };
static_assert(sizeof(NewCharacter_eventStartCustomExtendedMovement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execStartCustomExtendedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartCustomExtendedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StartCustomExtendedMovement

// Begin Class ANewCharacter Function StartFastMovement
struct Z_Construct_UFunction_ANewCharacter_StartFastMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Fast" },
		{ "Comment", "/**\n\x09 * Initiates fast movement for the character.\n\x09 * When enabled, this function allows for fast movement updates across all movement modes,\n\x09 * enabling the character to move quickly while in states like Walking, flying, swimming, etc.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Initiates fast movement for the character.\nWhen enabled, this function allows for fast movement updates across all movement modes,\nenabling the character to move quickly while in states like Walking, flying, swimming, etc." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStartFastMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartFastMovement();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StartFastMovement

// Begin Class ANewCharacter Function StopClimb
struct Z_Construct_UFunction_ANewCharacter_StopClimb_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Climb" },
		{ "Comment", "/**\n\x09 * Stops the climbing movement for the character.\n\x09 * This function transitions the character out of the climbing\n\x09 * state, allowing them to return to regular movement mechanics\n\x09 * or initiate another action.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the climbing movement for the character.\nThis function transitions the character out of the climbing\nstate, allowing them to return to regular movement mechanics\nor initiate another action." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopClimb)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopClimb();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopClimb

// Begin Class ANewCharacter Function StopClimbingUp
struct Z_Construct_UFunction_ANewCharacter_StopClimbingUp_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|ClimbUp" },
		{ "Comment", "/**\n\x09 * Stops the climbing-up action for the character.\n\x09 * This function reverts any changes made during the climbing-up state\n\x09 * and transitions the character back to normal movement.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the climbing-up action for the character.\nThis function reverts any changes made during the climbing-up state\nand transitions the character back to normal movement." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopClimbingUp)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopClimbingUp();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopClimbingUp

// Begin Class ANewCharacter Function StopCrouchSprinting
struct Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|CrouchSprint" },
		{ "Comment", "/**\n\x09 * Stops the crouch sprinting movement for the character.\n\x09 * This may also affect standard sprint behavior due to interconnected functionality.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the crouch sprinting movement for the character.\nThis may also affect standard sprint behavior due to interconnected functionality." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopCrouchSprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopCrouchSprinting();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopCrouchSprinting

// Begin Class ANewCharacter Function StopCustomAdvancedMovement
static FName NAME_ANewCharacter_StopCustomAdvancedMovement = FName(TEXT("StopCustomAdvancedMovement"));
void ANewCharacter::StopCustomAdvancedMovement()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_StopCustomAdvancedMovement),NULL);
}
struct Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced" },
		{ "Comment", "/**\n\x09 * Terminates the character's root motion-based custom advanced movement state.\n\x09 * This function restores the character's default movement behavior, ending\n\x09 * root motion sequences cleanly and ensuring smooth transition back to standard movement.\n\x09 * Designed for experimental use as the custom root motion system evolves.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Terminates the character's root motion-based custom advanced movement state.\nThis function restores the character's default movement behavior, ending\nroot motion sequences cleanly and ensuring smooth transition back to standard movement.\nDesigned for experimental use as the custom root motion system evolves." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopCustomAdvancedMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execStopCustomAdvancedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopCustomAdvancedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopCustomAdvancedMovement

// Begin Class ANewCharacter Function StopCustomExtendedMovement
static FName NAME_ANewCharacter_StopCustomExtendedMovement = FName(TEXT("StopCustomExtendedMovement"));
void ANewCharacter::StopCustomExtendedMovement()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewCharacter_StopCustomExtendedMovement),NULL);
}
struct Z_Construct_UFunction_ANewCharacter_StopCustomExtendedMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Extended" },
		{ "Comment", "/**\n\x09 * Terminates the character's extended custom movement state for non-root motion montages.\n\x09 * Restores the character's default movement behavior, effectively ending any extended movement logic.\n\x09 * Ensures a clean transition back to standard movement. Designed for experimental use as the extended movement\n\x09 * system evolves.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Terminates the character's extended custom movement state for non-root motion montages.\nRestores the character's default movement behavior, effectively ending any extended movement logic.\nEnsures a clean transition back to standard movement. Designed for experimental use as the extended movement\nsystem evolves." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_StopCustomExtendedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "StopCustomExtendedMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_StopCustomExtendedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_StopCustomExtendedMovement_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewCharacter_StopCustomExtendedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewCharacter_StopCustomExtendedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewCharacter::execStopCustomExtendedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopCustomExtendedMovement_Implementation();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopCustomExtendedMovement

// Begin Class ANewCharacter Function StopDashing
struct Z_Construct_UFunction_ANewCharacter_StopDashing_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Dash" },
		{ "Comment", "/**\n\x09 * Stops the dashing movement for the character.\n\x09 * This function resets the character's state and speed\n\x09 * back to normal after a dash is completed.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the dashing movement for the character.\nThis function resets the character's state and speed\nback to normal after a dash is completed." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopDashing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopDashing();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopDashing

// Begin Class ANewCharacter Function StopFastFlying
struct Z_Construct_UFunction_ANewCharacter_StopFastFlying_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Stops the fast flying movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the fast flying movement for the character." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopFastFlying)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopFastFlying();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopFastFlying

// Begin Class ANewCharacter Function StopFastMovement
struct Z_Construct_UFunction_ANewCharacter_StopFastMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Fast" },
		{ "Comment", "/**\n\x09 * Stops the fast movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the fast movement for the character." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopFastMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopFastMovement();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopFastMovement

// Begin Class ANewCharacter Function StopFastSwimming
struct Z_Construct_UFunction_ANewCharacter_StopFastSwimming_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Swim" },
		{ "Comment", "/**\n\x09 * Stops the fast swimming movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the fast swimming movement for the character." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopFastSwimming)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopFastSwimming();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopFastSwimming

// Begin Class ANewCharacter Function StopFlying
struct Z_Construct_UFunction_ANewCharacter_StopFlying_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Fly" },
		{ "Comment", "/**\n\x09 * Stops the flying movement for the character.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the flying movement for the character." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopFlying)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopFlying();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopFlying

// Begin Class ANewCharacter Function StopMantling
struct Z_Construct_UFunction_ANewCharacter_StopMantling_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Mantle" },
		{ "Comment", "/**\n\x09 * Stops the mantling action for the character.\n\x09 * This function reverts any changes made during the mantling state\n\x09 * and transitions the character back to normal movement.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the mantling action for the character.\nThis function reverts any changes made during the mantling state\nand transitions the character back to normal movement." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopMantling)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopMantling();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopMantling

// Begin Class ANewCharacter Function StopPronning
struct Z_Construct_UFunction_ANewCharacter_StopPronning_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Prone" },
		{ "Comment", "/**\n\x09 * Stops the proning movement for the character.\n\x09 * This function transitions the character out of the prone\n\x09 * position, returning them to a standing or crouched state as appropriate.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the proning movement for the character.\nThis function transitions the character out of the prone\nposition, returning them to a standing or crouched state as appropriate." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopPronning)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopPronning();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopPronning

// Begin Class ANewCharacter Function StopSliding
struct Z_Construct_UFunction_ANewCharacter_StopSliding_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Slide" },
		{ "Comment", "/**\n\x09 * Stops the sliding movement for the character.\n\x09 * This function transitions the character out of the sliding\n\x09 * state, allowing them to return to regular movement mechanics.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the sliding movement for the character.\nThis function transitions the character out of the sliding\nstate, allowing them to return to regular movement mechanics." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopSliding)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopSliding();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopSliding

// Begin Class ANewCharacter Function StopSprinting
struct Z_Construct_UFunction_ANewCharacter_StopSprinting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Sprint" },
		{ "Comment", "/**\n\x09 * Stops the sprinting movement for the character.\n\x09 * Stopping sprinting may affect crouch sprint behavior due to the interconnected functionality.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the sprinting movement for the character.\nStopping sprinting may affect crouch sprint behavior due to the interconnected functionality." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopSprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopSprinting();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopSprinting

// Begin Class ANewCharacter Function StopVaulting
struct Z_Construct_UFunction_ANewCharacter_StopVaulting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Vault" },
		{ "Comment", "/**\n\x09 * Stops the vaulting movement for the character.\n\x09 * This function reverts any changes made during the vaulting action,\n\x09 * returning the character to their previous movement state.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the vaulting movement for the character.\nThis function reverts any changes made during the vaulting action,\nreturning the character to their previous movement state." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopVaulting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopVaulting();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopVaulting

// Begin Class ANewCharacter Function StopWallRunning
struct Z_Construct_UFunction_ANewCharacter_StopWallRunning_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|WallRun" },
		{ "Comment", "/**\n\x09 * Stops the wall running movement for the character.\n\x09 * This function transitions the character out of the wall running\n\x09 * state, allowing them to return to regular movement mechanics\n\x09 * or initiate another action.\n\x09 *\n\x09 * Note: This function will not be effective if the auto end wall run feature is active.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Stops the wall running movement for the character.\nThis function transitions the character out of the wall running\nstate, allowing them to return to regular movement mechanics\nor initiate another action.\n\nNote: This function will not be effective if the auto end wall run feature is active." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
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
DEFINE_FUNCTION(ANewCharacter::execStopWallRunning)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopWallRunning();
	P_NATIVE_END;
}
// End Class ANewCharacter Function StopWallRunning

// Begin Class ANewCharacter Function Vault
struct Z_Construct_UFunction_ANewCharacter_Vault_Statics
{
	struct NewCharacter_eventVault_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Advanced|Vault" },
		{ "Comment", "/**\n\x09 * Attempts to initiate vaulting for the character.\n\x09 * This function evaluates conditions and triggers the necessary state changes\n\x09 * to perform a vault.\n\x09 *\n\x09 * @return True if the vaulting action was successfully initiated; otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate vaulting for the character.\nThis function evaluates conditions and triggers the necessary state changes\nto perform a vault.\n\n@return True if the vaulting action was successfully initiated; otherwise, false." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Vault_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_Vault_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "Vault", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_Vault_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Vault_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_Vault_Statics::NewCharacter_eventVault_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_Vault_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_Vault_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execVault)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Vault();
	P_NATIVE_END;
}
// End Class ANewCharacter Function Vault

// Begin Class ANewCharacter Function WallRun
struct Z_Construct_UFunction_ANewCharacter_WallRun_Statics
{
	struct NewCharacter_eventWallRun_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|WallRun" },
		{ "Comment", "/**\n\x09 * Attempts to initiate the wall running action for the character.\n\x09 * @return True if the character successfully transitions into a wall running state, otherwise false.\n\x09 * This function checks the conditions for wall running, such as\n\x09 * the character's orientation and proximity to the wall,\n\x09 * returning true if the action is successful.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Attempts to initiate the wall running action for the character.\n@return True if the character successfully transitions into a wall running state, otherwise false.\nThis function checks the conditions for wall running, such as\nthe character's orientation and proximity to the wall,\nreturning true if the action is successful." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewCharacter_WallRun_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewCharacter, nullptr, "WallRun", nullptr, nullptr, Z_Construct_UFunction_ANewCharacter_WallRun_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::NewCharacter_eventWallRun_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewCharacter_WallRun_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewCharacter_WallRun_Statics::Function_MetaDataParams) };
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
DEFINE_FUNCTION(ANewCharacter::execWallRun)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->WallRun();
	P_NATIVE_END;
}
// End Class ANewCharacter Function WallRun

// Begin Class ANewCharacter
void ANewCharacter::StaticRegisterNativesANewCharacter()
{
	UClass* Class = ANewCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddAndUpdateCustomAdvancedWarpTargets", &ANewCharacter::execAddAndUpdateCustomAdvancedWarpTargets },
		{ "CanCustomAdvancedMovement", &ANewCharacter::execCanCustomAdvancedMovement },
		{ "CanCustomExtendedMovement", &ANewCharacter::execCanCustomExtendedMovement },
		{ "Climb", &ANewCharacter::execClimb },
		{ "ClimbUp", &ANewCharacter::execClimbUp },
		{ "CrouchSprint", &ANewCharacter::execCrouchSprint },
		{ "CustomAdvancedMovementPhysics", &ANewCharacter::execCustomAdvancedMovementPhysics },
		{ "CustomExtendedMovementPhysics", &ANewCharacter::execCustomExtendedMovementPhysics },
		{ "Dash", &ANewCharacter::execDash },
		{ "EnterCustomAdvancedMovement", &ANewCharacter::execEnterCustomAdvancedMovement },
		{ "EnterCustomExtendedMovement", &ANewCharacter::execEnterCustomExtendedMovement },
		{ "ExitCustomAdvancedMovement", &ANewCharacter::execExitCustomAdvancedMovement },
		{ "ExitCustomExtendedMovement", &ANewCharacter::execExitCustomExtendedMovement },
		{ "FastFly", &ANewCharacter::execFastFly },
		{ "FastSwim", &ANewCharacter::execFastSwim },
		{ "Fly", &ANewCharacter::execFly },
		{ "GetClimbUpData", &ANewCharacter::execGetClimbUpData },
		{ "GetCustomAdvancedMovementData", &ANewCharacter::execGetCustomAdvancedMovementData },
		{ "GetMantleData", &ANewCharacter::execGetMantleData },
		{ "GetMaxCustomAdvancedSpeed", &ANewCharacter::execGetMaxCustomAdvancedSpeed },
		{ "GetMaxCustomExtendedAcceleration", &ANewCharacter::execGetMaxCustomExtendedAcceleration },
		{ "GetMaxCustomExtendedDeceleration", &ANewCharacter::execGetMaxCustomExtendedDeceleration },
		{ "GetMaxCustomExtendedSpeed", &ANewCharacter::execGetMaxCustomExtendedSpeed },
		{ "GetMotionWarpingComponent", &ANewCharacter::execGetMotionWarpingComponent },
		{ "GetNewCharacterMovementComponent", &ANewCharacter::execGetNewCharacterMovementComponent },
		{ "GetVaultData", &ANewCharacter::execGetVaultData },
		{ "Mantle", &ANewCharacter::execMantle },
		{ "Prone", &ANewCharacter::execProne },
		{ "Slide", &ANewCharacter::execSlide },
		{ "Sprint", &ANewCharacter::execSprint },
		{ "StartCustomAdvancedMovement", &ANewCharacter::execStartCustomAdvancedMovement },
		{ "StartCustomExtendedMovement", &ANewCharacter::execStartCustomExtendedMovement },
		{ "StartFastMovement", &ANewCharacter::execStartFastMovement },
		{ "StopClimb", &ANewCharacter::execStopClimb },
		{ "StopClimbingUp", &ANewCharacter::execStopClimbingUp },
		{ "StopCrouchSprinting", &ANewCharacter::execStopCrouchSprinting },
		{ "StopCustomAdvancedMovement", &ANewCharacter::execStopCustomAdvancedMovement },
		{ "StopCustomExtendedMovement", &ANewCharacter::execStopCustomExtendedMovement },
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
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANewCharacter);
UClass* Z_Construct_UClass_ANewCharacter_NoRegister()
{
	return ANewCharacter::StaticClass();
}
struct Z_Construct_UClass_ANewCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * ANewCharacter\n *\n * This class represents a character that provides built-in compatibility\n * with motion warping and utilizes the new character movement component\n * for advanced locomotion mechanics. It extends the base ACharacter class\n * to allow for dynamic and flexible character movement behaviors, including\n * special movements such as climbing, vaulting, and more.\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "NewCharacter.h" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "ANewCharacter\n\nThis class represents a character that provides built-in compatibility\nwith motion warping and utilizes the new character movement component\nfor advanced locomotion mechanics. It extends the base ACharacter class\nto allow for dynamic and flexible character movement behaviors, including\nspecial movements such as climbing, vaulting, and more." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProneEyeHeight_MetaData[] = {
		{ "Category", "Camera|Prone" },
		{ "Comment", "/**\n\x09 * The height of the character's eyes when in a prone position.\n\x09 * This value is used to adjust the camera view and ensure\n\x09 * accurate line of sight while the character is proned.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "The height of the character's eyes when in a prone position.\nThis value is used to adjust the camera view and ensure\naccurate line of sight while the character is proned." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideEyeHeight_MetaData[] = {
		{ "Category", "Camera|Slide" },
		{ "Comment", "/**\n\x09 * The height of the character's eyes when sliding.\n\x09 * This value is used to adjust the camera view during\n\x09 * sliding to provide a better perspective for aiming\n\x09 * or targeting while maintaining an appropriate field of vision.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "The height of the character's eyes when sliding.\nThis value is used to adjust the camera view during\nsliding to provide a better perspective for aiming\nor targeting while maintaining an appropriate field of vision." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VaultEyeHeight_MetaData[] = {
		{ "Category", "Camera|Vault" },
		{ "Comment", "/**\n\x09 * Specifies the camera height adjustment during a vaulting action.\n\x09 * This value determines how high the camera view should shift when the character initiates a vault,\n\x09 * providing a smoother visual transition and better perspective for the player.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
		{ "ToolTip", "Specifies the camera height adjustment during a vaulting action.\nThis value determines how high the camera view should shift when the character initiates a vault,\nproviding a smoother visual transition and better perspective for the player." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewCharacterMovementComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionWarping_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NewCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProneEyeHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlideEyeHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VaultEyeHeight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewCharacterMovementComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MotionWarping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ANewCharacter_AddAndUpdateCustomAdvancedWarpTargets, "AddAndUpdateCustomAdvancedWarpTargets" }, // 1860325428
		{ &Z_Construct_UFunction_ANewCharacter_CanCustomAdvancedMovement, "CanCustomAdvancedMovement" }, // 3073121520
		{ &Z_Construct_UFunction_ANewCharacter_CanCustomExtendedMovement, "CanCustomExtendedMovement" }, // 3858637509
		{ &Z_Construct_UFunction_ANewCharacter_Climb, "Climb" }, // 152669956
		{ &Z_Construct_UFunction_ANewCharacter_ClimbUp, "ClimbUp" }, // 651429093
		{ &Z_Construct_UFunction_ANewCharacter_CrouchSprint, "CrouchSprint" }, // 2610399135
		{ &Z_Construct_UFunction_ANewCharacter_CustomAdvancedMovementPhysics, "CustomAdvancedMovementPhysics" }, // 1391318165
		{ &Z_Construct_UFunction_ANewCharacter_CustomExtendedMovementPhysics, "CustomExtendedMovementPhysics" }, // 4116718220
		{ &Z_Construct_UFunction_ANewCharacter_Dash, "Dash" }, // 177089939
		{ &Z_Construct_UFunction_ANewCharacter_EnterCustomAdvancedMovement, "EnterCustomAdvancedMovement" }, // 951643653
		{ &Z_Construct_UFunction_ANewCharacter_EnterCustomExtendedMovement, "EnterCustomExtendedMovement" }, // 3712425832
		{ &Z_Construct_UFunction_ANewCharacter_ExitCustomAdvancedMovement, "ExitCustomAdvancedMovement" }, // 266771977
		{ &Z_Construct_UFunction_ANewCharacter_ExitCustomExtendedMovement, "ExitCustomExtendedMovement" }, // 1782007352
		{ &Z_Construct_UFunction_ANewCharacter_FastFly, "FastFly" }, // 190424329
		{ &Z_Construct_UFunction_ANewCharacter_FastSwim, "FastSwim" }, // 2212101439
		{ &Z_Construct_UFunction_ANewCharacter_Fly, "Fly" }, // 2770998362
		{ &Z_Construct_UFunction_ANewCharacter_GetClimbUpData, "GetClimbUpData" }, // 2984809311
		{ &Z_Construct_UFunction_ANewCharacter_GetCustomAdvancedMovementData, "GetCustomAdvancedMovementData" }, // 2497338425
		{ &Z_Construct_UFunction_ANewCharacter_GetMantleData, "GetMantleData" }, // 744853134
		{ &Z_Construct_UFunction_ANewCharacter_GetMaxCustomAdvancedSpeed, "GetMaxCustomAdvancedSpeed" }, // 511074019
		{ &Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedAcceleration, "GetMaxCustomExtendedAcceleration" }, // 758799371
		{ &Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedDeceleration, "GetMaxCustomExtendedDeceleration" }, // 1385276117
		{ &Z_Construct_UFunction_ANewCharacter_GetMaxCustomExtendedSpeed, "GetMaxCustomExtendedSpeed" }, // 489142939
		{ &Z_Construct_UFunction_ANewCharacter_GetMotionWarpingComponent, "GetMotionWarpingComponent" }, // 2205646347
		{ &Z_Construct_UFunction_ANewCharacter_GetNewCharacterMovementComponent, "GetNewCharacterMovementComponent" }, // 21749392
		{ &Z_Construct_UFunction_ANewCharacter_GetVaultData, "GetVaultData" }, // 2860644234
		{ &Z_Construct_UFunction_ANewCharacter_Mantle, "Mantle" }, // 358790069
		{ &Z_Construct_UFunction_ANewCharacter_Prone, "Prone" }, // 1049751689
		{ &Z_Construct_UFunction_ANewCharacter_Slide, "Slide" }, // 1901785753
		{ &Z_Construct_UFunction_ANewCharacter_Sprint, "Sprint" }, // 4242822710
		{ &Z_Construct_UFunction_ANewCharacter_StartCustomAdvancedMovement, "StartCustomAdvancedMovement" }, // 1862056789
		{ &Z_Construct_UFunction_ANewCharacter_StartCustomExtendedMovement, "StartCustomExtendedMovement" }, // 879924751
		{ &Z_Construct_UFunction_ANewCharacter_StartFastMovement, "StartFastMovement" }, // 3860306801
		{ &Z_Construct_UFunction_ANewCharacter_StopClimb, "StopClimb" }, // 1167239943
		{ &Z_Construct_UFunction_ANewCharacter_StopClimbingUp, "StopClimbingUp" }, // 1155701939
		{ &Z_Construct_UFunction_ANewCharacter_StopCrouchSprinting, "StopCrouchSprinting" }, // 3141043063
		{ &Z_Construct_UFunction_ANewCharacter_StopCustomAdvancedMovement, "StopCustomAdvancedMovement" }, // 930629387
		{ &Z_Construct_UFunction_ANewCharacter_StopCustomExtendedMovement, "StopCustomExtendedMovement" }, // 327154933
		{ &Z_Construct_UFunction_ANewCharacter_StopDashing, "StopDashing" }, // 1655986063
		{ &Z_Construct_UFunction_ANewCharacter_StopFastFlying, "StopFastFlying" }, // 763088813
		{ &Z_Construct_UFunction_ANewCharacter_StopFastMovement, "StopFastMovement" }, // 297959158
		{ &Z_Construct_UFunction_ANewCharacter_StopFastSwimming, "StopFastSwimming" }, // 3852017683
		{ &Z_Construct_UFunction_ANewCharacter_StopFlying, "StopFlying" }, // 2733092485
		{ &Z_Construct_UFunction_ANewCharacter_StopMantling, "StopMantling" }, // 974117930
		{ &Z_Construct_UFunction_ANewCharacter_StopPronning, "StopPronning" }, // 3274728981
		{ &Z_Construct_UFunction_ANewCharacter_StopSliding, "StopSliding" }, // 1502011509
		{ &Z_Construct_UFunction_ANewCharacter_StopSprinting, "StopSprinting" }, // 1725139072
		{ &Z_Construct_UFunction_ANewCharacter_StopVaulting, "StopVaulting" }, // 147645146
		{ &Z_Construct_UFunction_ANewCharacter_StopWallRunning, "StopWallRunning" }, // 550937993
		{ &Z_Construct_UFunction_ANewCharacter_Vault, "Vault" }, // 4219765606
		{ &Z_Construct_UFunction_ANewCharacter_WallRun, "WallRun" }, // 2002824124
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANewCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_ProneEyeHeight = { "ProneEyeHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, ProneEyeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProneEyeHeight_MetaData), NewProp_ProneEyeHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_SlideEyeHeight = { "SlideEyeHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, SlideEyeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideEyeHeight_MetaData), NewProp_SlideEyeHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_VaultEyeHeight = { "VaultEyeHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, VaultEyeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VaultEyeHeight_MetaData), NewProp_VaultEyeHeight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_NewCharacterMovementComponent = { "NewCharacterMovementComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, NewCharacterMovementComponent), Z_Construct_UClass_UNewCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewCharacterMovementComponent_MetaData), NewProp_NewCharacterMovementComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANewCharacter_Statics::NewProp_MotionWarping = { "MotionWarping", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCharacter, MotionWarping), Z_Construct_UClass_UMotionWarpingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionWarping_MetaData), NewProp_MotionWarping_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANewCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_ProneEyeHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_SlideEyeHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_VaultEyeHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_NewCharacterMovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCharacter_Statics::NewProp_MotionWarping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ANewCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCharacter_Statics::DependentSingletons) < 16);
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
// End Class ANewCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANewCharacter, ANewCharacter::StaticClass, TEXT("ANewCharacter"), &Z_Registration_Info_UClass_ANewCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANewCharacter), 3702049181U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_1830023597(TEXT("/Script/CharacterLocomotionSystem"),
	Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
