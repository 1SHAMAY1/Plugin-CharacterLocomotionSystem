// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/MantlePrimaryDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMantlePrimaryDataAsset() {}
// Cross Module References
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UMantlePrimaryDataAsset();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UMantlePrimaryDataAsset_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References
	void UMantlePrimaryDataAsset::StaticRegisterNativesUMantlePrimaryDataAsset()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMantlePrimaryDataAsset);
	UClass* Z_Construct_UClass_UMantlePrimaryDataAsset_NoRegister()
	{
		return UMantlePrimaryDataAsset::StaticClass();
	}
	struct Z_Construct_UClass_UMantlePrimaryDataAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UMantlePrimaryDataAsset\n *\n * This class is responsible for storing data related to the\n * mantle movement mechanics within the new character movement component.\n * It extends UAdvancedMovementPrimaryDataAsset to provide\n * configuration options and parameters specifically for\n * mantling actions.\n */" },
		{ "IncludePath", "MantlePrimaryDataAsset.h" },
		{ "ModuleRelativePath", "Public/MantlePrimaryDataAsset.h" },
		{ "ToolTip", "UMantlePrimaryDataAsset\n\nThis class is responsible for storing data related to the\nmantle movement mechanics within the new character movement component.\nIt extends UAdvancedMovementPrimaryDataAsset to provide\nconfiguration options and parameters specifically for\nmantling actions." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMantlePrimaryDataAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::ClassParams = {
		&UMantlePrimaryDataAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMantlePrimaryDataAsset()
	{
		if (!Z_Registration_Info_UClass_UMantlePrimaryDataAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMantlePrimaryDataAsset.OuterSingleton, Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMantlePrimaryDataAsset.OuterSingleton;
	}
	template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<UMantlePrimaryDataAsset>()
	{
		return UMantlePrimaryDataAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMantlePrimaryDataAsset);
	UMantlePrimaryDataAsset::~UMantlePrimaryDataAsset() {}
	struct Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMantlePrimaryDataAsset, UMantlePrimaryDataAsset::StaticClass, TEXT("UMantlePrimaryDataAsset"), &Z_Registration_Info_UClass_UMantlePrimaryDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMantlePrimaryDataAsset), 3911265813U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_394139544(TEXT("/Script/CharacterLocomotionSystem"),
		Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
