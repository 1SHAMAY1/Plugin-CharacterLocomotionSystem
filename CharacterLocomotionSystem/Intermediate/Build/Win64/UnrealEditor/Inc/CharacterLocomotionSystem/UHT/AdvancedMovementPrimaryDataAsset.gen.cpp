// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/AdvancedMovementPrimaryDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvancedMovementPrimaryDataAsset() {}
// Cross Module References
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
	UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References
	DEFINE_FUNCTION(UAdvancedMovementPrimaryDataAsset::execAdjustAndUpdateWarpTarget)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_STRUCT(FVector,Z_Param_CurrentWarpLocation);
		P_GET_OBJECT(ACharacter,Z_Param_Character);
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_OutWarpTargetName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->AdjustAndUpdateWarpTarget(Z_Param_Index,Z_Param_CurrentWarpLocation,Z_Param_Character,Z_Param_Out_OutWarpTargetName);
		P_NATIVE_END;
	}
	void UAdvancedMovementPrimaryDataAsset::StaticRegisterNativesUAdvancedMovementPrimaryDataAsset()
	{
		UClass* Class = UAdvancedMovementPrimaryDataAsset::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AdjustAndUpdateWarpTarget", &UAdvancedMovementPrimaryDataAsset::execAdjustAndUpdateWarpTarget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics
	{
		struct AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms
		{
			int32 Index;
			FVector CurrentWarpLocation;
			ACharacter* Character;
			FName OutWarpTargetName;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentWarpLocation;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
		static const UECodeGen_Private::FNamePropertyParams NewProp_OutWarpTargetName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_CurrentWarpLocation = { "CurrentWarpLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms, CurrentWarpLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms, Character), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_OutWarpTargetName = { "OutWarpTargetName", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms, OutWarpTargetName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_CurrentWarpLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_Character,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_OutWarpTargetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Movement:Advanced" },
		{ "Comment", "/**\n\x09 * Adjusts and updates the warp target location based on the specified index.\n\x09 * This function returns a modified location for the warp target and also\n\x09 * provides the corresponding warp target name via the output parameter.\n\x09 * It can be used to fine-tune movement during gameplay, such as adjusting the\n\x09 * final landing spot of a dash or vault.\n\x09 *\n\x09 * @param Index - The index of the warp target to adjust.\n\x09 * @param CurrentWarpLocation - The current location to be adjusted.\n\x09 * @param Character - The character performing the movement.\n\x09 * @param OutWarpTargetName - The output parameter that returns the name of the warp target.\n\x09 * @return The modified warp target location.\n\x09 */" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "Adjusts and updates the warp target location based on the specified index.\nThis function returns a modified location for the warp target and also\nprovides the corresponding warp target name via the output parameter.\nIt can be used to fine-tune movement during gameplay, such as adjusting the\nfinal landing spot of a dash or vault.\n\n@param Index - The index of the warp target to adjust.\n@param CurrentWarpLocation - The current location to be adjusted.\n@param Character - The character performing the movement.\n@param OutWarpTargetName - The output parameter that returns the name of the warp target.\n@return The modified warp target location." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset, nullptr, "AdjustAndUpdateWarpTarget", nullptr, nullptr, Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::AdvancedMovementPrimaryDataAsset_eventAdjustAndUpdateWarpTarget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAdvancedMovementPrimaryDataAsset);
	UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_NoRegister()
	{
		return UAdvancedMovementPrimaryDataAsset::StaticClass();
	}
	struct Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WarpTargetLocationOffsets_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WarpTargetLocationOffsets_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_WarpTargetLocationOffsets;
		static const UECodeGen_Private::FNamePropertyParams NewProp_WarpTargetNames_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WarpTargetNames_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_WarpTargetNames;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AdvancedMovementMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AdvancedMovementMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MontageStartDuration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MontageStartDuration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MontagePlayRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MontagePlayRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MontageBlendOutTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MontageBlendOutTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedMovementPrimaryDataAsset_AdjustAndUpdateWarpTarget, "AdjustAndUpdateWarpTarget" }, // 239567494
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * UAdvancedMovementPrimaryDataAsset\n * \n * This class serves as a base data asset for advanced movement mechanics \n * within the new character movement component. It is intended to be extended \n * by child classes such as vaulting, mantling, and climbing up, \n * allowing for a modular approach to managing movement-related data.\n */" },
		{ "IncludePath", "AdvancedMovementPrimaryDataAsset.h" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "UAdvancedMovementPrimaryDataAsset\n\nThis class serves as a base data asset for advanced movement mechanics\nwithin the new character movement component. It is intended to be extended\nby child classes such as vaulting, mantling, and climbing up,\nallowing for a modular approach to managing movement-related data." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetLocationOffsets_Inner = { "WarpTargetLocationOffsets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetLocationOffsets_MetaData[] = {
		{ "Category", "Movement:Advanced" },
		{ "Comment", "// Array of location offsets for warp targets, which represent relative positions to adjust the character's movement destination during advanced actions.\n" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "Array of location offsets for warp targets, which represent relative positions to adjust the character's movement destination during advanced actions." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetLocationOffsets = { "WarpTargetLocationOffsets", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdvancedMovementPrimaryDataAsset, WarpTargetLocationOffsets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetLocationOffsets_MetaData), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetLocationOffsets_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetNames_Inner = { "WarpTargetNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetNames_MetaData[] = {
		{ "Category", "Movement:Advanced" },
		{ "Comment", "// Array containing the names of warp targets, used to identify specific warp locations during advanced movement sequences.\n" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "Array containing the names of warp targets, used to identify specific warp locations during advanced movement sequences." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetNames = { "WarpTargetNames", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdvancedMovementPrimaryDataAsset, WarpTargetNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetNames_MetaData), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetNames_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_AdvancedMovementMontage_MetaData[] = {
		{ "Category", "Movement:Advanced" },
		{ "Comment", "// Reference to an animation montage that will be played during advanced movement actions, such as dashing or vaulting.\n" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "Reference to an animation montage that will be played during advanced movement actions, such as dashing or vaulting." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_AdvancedMovementMontage = { "AdvancedMovementMontage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdvancedMovementPrimaryDataAsset, AdvancedMovementMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_AdvancedMovementMontage_MetaData), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_AdvancedMovementMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageStartDuration_MetaData[] = {
		{ "Category", "Movement:Advanced" },
		{ "Comment", "// Duration of the blend-in time when starting the advanced movement montage, defining how smoothly the montage starts.\n" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "Duration of the blend-in time when starting the advanced movement montage, defining how smoothly the montage starts." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageStartDuration = { "MontageStartDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdvancedMovementPrimaryDataAsset, MontageStartDuration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageStartDuration_MetaData), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageStartDuration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontagePlayRate_MetaData[] = {
		{ "Category", "Movement:Advanced" },
		{ "Comment", "// Playback speed for the advanced movement montage, controlling the rate at which the animation plays. A higher value means a faster playback.\n" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "Playback speed for the advanced movement montage, controlling the rate at which the animation plays. A higher value means a faster playback." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontagePlayRate = { "MontagePlayRate", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdvancedMovementPrimaryDataAsset, MontagePlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontagePlayRate_MetaData), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontagePlayRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageBlendOutTime_MetaData[] = {
		{ "Category", "Movement:Advanced" },
		{ "Comment", "// Duration for blending out of the advanced movement montage when it finishes, ensuring a smooth transition back to normal movement.\n" },
		{ "ModuleRelativePath", "Public/AdvancedMovementPrimaryDataAsset.h" },
		{ "ToolTip", "Duration for blending out of the advanced movement montage when it finishes, ensuring a smooth transition back to normal movement." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageBlendOutTime = { "MontageBlendOutTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAdvancedMovementPrimaryDataAsset, MontageBlendOutTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageBlendOutTime_MetaData), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageBlendOutTime_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetLocationOffsets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetLocationOffsets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetNames_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_WarpTargetNames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_AdvancedMovementMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageStartDuration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontagePlayRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::NewProp_MontageBlendOutTime,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAdvancedMovementPrimaryDataAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::ClassParams = {
		&UAdvancedMovementPrimaryDataAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset()
	{
		if (!Z_Registration_Info_UClass_UAdvancedMovementPrimaryDataAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAdvancedMovementPrimaryDataAsset.OuterSingleton, Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAdvancedMovementPrimaryDataAsset.OuterSingleton;
	}
	template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<UAdvancedMovementPrimaryDataAsset>()
	{
		return UAdvancedMovementPrimaryDataAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedMovementPrimaryDataAsset);
	UAdvancedMovementPrimaryDataAsset::~UAdvancedMovementPrimaryDataAsset() {}
	struct Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_AdvancedMovementPrimaryDataAsset_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_AdvancedMovementPrimaryDataAsset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset, UAdvancedMovementPrimaryDataAsset::StaticClass, TEXT("UAdvancedMovementPrimaryDataAsset"), &Z_Registration_Info_UClass_UAdvancedMovementPrimaryDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAdvancedMovementPrimaryDataAsset), 3951170074U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_AdvancedMovementPrimaryDataAsset_h_1388801677(TEXT("/Script/CharacterLocomotionSystem"),
		Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_AdvancedMovementPrimaryDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_AdvancedMovementPrimaryDataAsset_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
