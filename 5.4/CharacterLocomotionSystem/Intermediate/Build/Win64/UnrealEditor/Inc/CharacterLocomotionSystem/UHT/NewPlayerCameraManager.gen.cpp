// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterLocomotionSystem/Public/NewPlayerCameraManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNewPlayerCameraManager() {}

// Begin Cross Module References
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_ANewPlayerCameraManager();
CHARACTERLOCOMOTIONSYSTEM_API UClass* Z_Construct_UClass_ANewPlayerCameraManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
UPackage* Z_Construct_UPackage__Script_CharacterLocomotionSystem();
// End Cross Module References

// Begin Class ANewPlayerCameraManager
void ANewPlayerCameraManager::StaticRegisterNativesANewPlayerCameraManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANewPlayerCameraManager);
UClass* Z_Construct_UClass_ANewPlayerCameraManager_NoRegister()
{
	return ANewPlayerCameraManager::StaticClass();
}
struct Z_Construct_UClass_ANewPlayerCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Player Camera Manager with support for smooth transitions during crouch, slide, prone and vault  states.\n */" },
		{ "IncludePath", "NewPlayerCameraManager.h" },
		{ "ModuleRelativePath", "Public/NewPlayerCameraManager.h" },
		{ "ToolTip", "Player Camera Manager with support for smooth transitions during crouch, slide, prone and vault  states." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmoothBlendDuration_MetaData[] = {
		{ "Category", "Blend Durations" },
		{ "Comment", "/*\n\x09 * Duration for smooth transitions of the camera when the character changes\n\x09 * between crouching, proning, and sliding states. This value determines how\n\x09 * long it takes for the camera to smoothly blend to the new position, enhancing\n\x09 * the player's visual experience by avoiding abrupt changes in view.\n\x09 * Measured in seconds.\n\x09 */" },
		{ "ModuleRelativePath", "Public/NewPlayerCameraManager.h" },
		{ "ToolTip", "* Duration for smooth transitions of the camera when the character changes\n* between crouching, proning, and sliding states. This value determines how\n* long it takes for the camera to smoothly blend to the new position, enhancing\n* the player's visual experience by avoiding abrupt changes in view.\n* Measured in seconds." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SmoothBlendDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANewPlayerCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANewPlayerCameraManager_Statics::NewProp_SmoothBlendDuration = { "SmoothBlendDuration", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewPlayerCameraManager, SmoothBlendDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmoothBlendDuration_MetaData), NewProp_SmoothBlendDuration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANewPlayerCameraManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewPlayerCameraManager_Statics::NewProp_SmoothBlendDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewPlayerCameraManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ANewPlayerCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_CharacterLocomotionSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewPlayerCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANewPlayerCameraManager_Statics::ClassParams = {
	&ANewPlayerCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ANewPlayerCameraManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ANewPlayerCameraManager_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewPlayerCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ANewPlayerCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANewPlayerCameraManager()
{
	if (!Z_Registration_Info_UClass_ANewPlayerCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANewPlayerCameraManager.OuterSingleton, Z_Construct_UClass_ANewPlayerCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANewPlayerCameraManager.OuterSingleton;
}
template<> CHARACTERLOCOMOTIONSYSTEM_API UClass* StaticClass<ANewPlayerCameraManager>()
{
	return ANewPlayerCameraManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANewPlayerCameraManager);
ANewPlayerCameraManager::~ANewPlayerCameraManager() {}
// End Class ANewPlayerCameraManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewPlayerCameraManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANewPlayerCameraManager, ANewPlayerCameraManager::StaticClass, TEXT("ANewPlayerCameraManager"), &Z_Registration_Info_UClass_ANewPlayerCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANewPlayerCameraManager), 2260545258U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewPlayerCameraManager_h_422148147(TEXT("/Script/CharacterLocomotionSystem"),
	Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewPlayerCameraManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewPlugin___5_4_CharacterLocomotionSystem_HostProject_Plugins_CharacterLocomotionSystem_Source_CharacterLocomotionSystem_Public_NewPlayerCameraManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
