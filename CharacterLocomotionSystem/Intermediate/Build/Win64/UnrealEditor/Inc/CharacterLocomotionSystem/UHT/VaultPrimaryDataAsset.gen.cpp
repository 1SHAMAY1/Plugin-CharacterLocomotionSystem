// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/VaultPrimaryDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVaultPrimaryDataAsset() {}
// Cross Module References
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UVaultPrimaryDataAsset();
	CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UVaultPrimaryDataAsset_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References
	void UVaultPrimaryDataAsset::StaticRegisterNativesUVaultPrimaryDataAsset()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVaultPrimaryDataAsset);
	UClass* Z_Construct_UClass_UVaultPrimaryDataAsset_NoRegister()
	{
		return UVaultPrimaryDataAsset::StaticClass();
	}
	struct Z_Construct_UClass_UVaultPrimaryDataAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UVaultPrimaryDataAsset\n *\n * This class is responsible for storing vault-related movement data\n * for the new character movement component. It derives from\n * UAdvancedMovementPrimaryDataAsset and provides access to the\n * necessary parameters and configurations for vaulting mechanics.\n */" },
		{ "IncludePath", "VaultPrimaryDataAsset.h" },
		{ "ModuleRelativePath", "Public/VaultPrimaryDataAsset.h" },
		{ "ToolTip", "UVaultPrimaryDataAsset\n\nThis class is responsible for storing vault-related movement data\nfor the new character movement component. It derives from\nUAdvancedMovementPrimaryDataAsset and provides access to the\nnecessary parameters and configurations for vaulting mechanics." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVaultPrimaryDataAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::ClassParams = {
		&UVaultPrimaryDataAsset::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVaultPrimaryDataAsset()
	{
		if (!Z_Registration_Info_UClass_UVaultPrimaryDataAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVaultPrimaryDataAsset.OuterSingleton, Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVaultPrimaryDataAsset.OuterSingleton;
	}
	template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<UVaultPrimaryDataAsset>()
	{
		return UVaultPrimaryDataAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVaultPrimaryDataAsset);
	UVaultPrimaryDataAsset::~UVaultPrimaryDataAsset() {}
	struct Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVaultPrimaryDataAsset, UVaultPrimaryDataAsset::StaticClass, TEXT("UVaultPrimaryDataAsset"), &Z_Registration_Info_UClass_UVaultPrimaryDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVaultPrimaryDataAsset), 2961023282U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_2713588263(TEXT("/Script/CharacterLocomotionSystem"),
		Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_3_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
