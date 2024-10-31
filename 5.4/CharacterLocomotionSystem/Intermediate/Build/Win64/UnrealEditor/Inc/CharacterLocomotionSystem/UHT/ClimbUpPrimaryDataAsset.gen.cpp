// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/ClimbUpPrimaryDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClimbUpPrimaryDataAsset() {}

// Begin Cross Module References
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset();
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UClimbUpPrimaryDataAsset();
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_UClimbUpPrimaryDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References

// Begin Class UClimbUpPrimaryDataAsset
void UClimbUpPrimaryDataAsset::StaticRegisterNativesUClimbUpPrimaryDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UClimbUpPrimaryDataAsset);
UClass* Z_Construct_UClass_UClimbUpPrimaryDataAsset_NoRegister()
{
	return UClimbUpPrimaryDataAsset::StaticClass();
}
struct Z_Construct_UClass_UClimbUpPrimaryDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UClimbUpPrimaryDataAsset\n *\n * This class is responsible for storing data related to the\n * climbing up movement mechanics within the new character movement component.\n * It extends UAdvancedMovementPrimaryDataAsset to provide\n * configuration options and parameters specifically for climbing up actions.\n */" },
		{ "IncludePath", "ClimbUpPrimaryDataAsset.h" },
		{ "ModuleRelativePath", "Public/ClimbUpPrimaryDataAsset.h" },
		{ "ToolTip", "UClimbUpPrimaryDataAsset\n\nThis class is responsible for storing data related to the\nclimbing up movement mechanics within the new character movement component.\nIt extends UAdvancedMovementPrimaryDataAsset to provide\nconfiguration options and parameters specifically for climbing up actions." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClimbUpPrimaryDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UClimbUpPrimaryDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAdvancedMovementPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClimbUpPrimaryDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UClimbUpPrimaryDataAsset_Statics::ClassParams = {
	&UClimbUpPrimaryDataAsset::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClimbUpPrimaryDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UClimbUpPrimaryDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UClimbUpPrimaryDataAsset()
{
	if (!Z_Registration_Info_UClass_UClimbUpPrimaryDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClimbUpPrimaryDataAsset.OuterSingleton, Z_Construct_UClass_UClimbUpPrimaryDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UClimbUpPrimaryDataAsset.OuterSingleton;
}
template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<UClimbUpPrimaryDataAsset>()
{
	return UClimbUpPrimaryDataAsset::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UClimbUpPrimaryDataAsset);
UClimbUpPrimaryDataAsset::~UClimbUpPrimaryDataAsset() {}
// End Class UClimbUpPrimaryDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_ClimbUpPrimaryDataAsset_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UClimbUpPrimaryDataAsset, UClimbUpPrimaryDataAsset::StaticClass, TEXT("UClimbUpPrimaryDataAsset"), &Z_Registration_Info_UClass_UClimbUpPrimaryDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClimbUpPrimaryDataAsset), 1306347954U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_ClimbUpPrimaryDataAsset_h_1958297466(TEXT("/Script/CharacterLocomotionSystem"),
	Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_ClimbUpPrimaryDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_ClimbUpPrimaryDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
