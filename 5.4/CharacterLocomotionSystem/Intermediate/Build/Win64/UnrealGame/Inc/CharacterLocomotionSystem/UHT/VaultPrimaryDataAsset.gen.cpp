// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/VaultPrimaryDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVaultPrimaryDataAsset() {}

// Begin Cross Module References
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset();
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UVaultPrimaryDataAsset();
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UVaultPrimaryDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References

// Begin Class UVaultPrimaryDataAsset
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
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UVaultPrimaryDataAsset\n *\n * This class is responsible for storing vault-related movement data\n * for the new character movement component. It derives from\n * UAdvancedMovementPrimaryDataAsset and provides access to the\n * necessary parameters and configurations for vaulting mechanics.\n */" },
		{ "IncludePath", "VaultPrimaryDataAsset.h" },
		{ "ModuleRelativePath", "Public/VaultPrimaryDataAsset.h" },
		{ "ToolTip", "UVaultPrimaryDataAsset\n\nThis class is responsible for storing vault-related movement data\nfor the new character movement component. It derives from\nUAdvancedMovementPrimaryDataAsset and provides access to the\nnecessary parameters and configurations for vaulting mechanics." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVaultPrimaryDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVaultPrimaryDataAsset_Statics::DependentSingletons) < 16);
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
// End Class UVaultPrimaryDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVaultPrimaryDataAsset, UVaultPrimaryDataAsset::StaticClass, TEXT("UVaultPrimaryDataAsset"), &Z_Registration_Info_UClass_UVaultPrimaryDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVaultPrimaryDataAsset), 2196529258U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_1673556127(TEXT("/Script/CharacterLocomotionSystem"),
	Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_VaultPrimaryDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
