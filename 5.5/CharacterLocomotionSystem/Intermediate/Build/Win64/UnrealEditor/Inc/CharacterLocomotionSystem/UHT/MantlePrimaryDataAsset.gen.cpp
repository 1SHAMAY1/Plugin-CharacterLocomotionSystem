// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/MantlePrimaryDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMantlePrimaryDataAsset() {}

// Begin Cross Module References
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset();
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UMantlePrimaryDataAsset();
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UMantlePrimaryDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References

// Begin Class UMantlePrimaryDataAsset
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
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UMantlePrimaryDataAsset\n *\n * This class is responsible for storing data related to the\n * mantle movement mechanics within the new character movement component.\n * It extends UAdvancedMovementPrimaryDataAsset to provide\n * configuration options and parameters specifically for\n * mantling actions.\n */" },
		{ "IncludePath", "MantlePrimaryDataAsset.h" },
		{ "ModuleRelativePath", "Public/MantlePrimaryDataAsset.h" },
		{ "ToolTip", "UMantlePrimaryDataAsset\n\nThis class is responsible for storing data related to the\nmantle movement mechanics within the new character movement component.\nIt extends UAdvancedMovementPrimaryDataAsset to provide\nconfiguration options and parameters specifically for\nmantling actions." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMantlePrimaryDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMantlePrimaryDataAsset_Statics::DependentSingletons) < 16);
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
// End Class UMantlePrimaryDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_NewPlugin___5_5_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMantlePrimaryDataAsset, UMantlePrimaryDataAsset::StaticClass, TEXT("UMantlePrimaryDataAsset"), &Z_Registration_Info_UClass_UMantlePrimaryDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMantlePrimaryDataAsset), 1272208690U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_5_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_2877052480(TEXT("/Script/CharacterLocomotionSystem"),
	Z_CompiledInDeferFile_FID_NewPlugin___5_5_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_5_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_MantlePrimaryDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
