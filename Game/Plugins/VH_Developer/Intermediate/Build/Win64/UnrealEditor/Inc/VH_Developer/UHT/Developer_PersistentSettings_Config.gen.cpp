// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Developer_PersistentSettings_Config.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_PersistentSettings_Config() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_PersistentSettings();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_Config();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_Config_NoRegister();
// End Cross Module References
	void UDeveloper_PersistentSettings_Config::StaticRegisterNativesUDeveloper_PersistentSettings_Config()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_PersistentSettings_Config);
	UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_Config_NoRegister()
	{
		return UDeveloper_PersistentSettings_Config::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SettingsMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_SettingsMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SettingsMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_SettingsMap;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloper_PersistentSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/Developer_PersistentSettings_Config.h" },
		{ "ModuleRelativePath", "Core/Public/Developer_PersistentSettings_Config.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap_ValueProp = { "SettingsMap", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap_Key_KeyProp = { "SettingsMap_Key", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap_MetaData[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_PersistentSettings_Config.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap = { "SettingsMap", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_PersistentSettings_Config, SettingsMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap_MetaData), Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::NewProp_SettingsMap,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_PersistentSettings_Config>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::ClassParams = {
		&UDeveloper_PersistentSettings_Config::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_Config()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_PersistentSettings_Config.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_PersistentSettings_Config.OuterSingleton, Z_Construct_UClass_UDeveloper_PersistentSettings_Config_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_PersistentSettings_Config.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_PersistentSettings_Config>()
	{
		return UDeveloper_PersistentSettings_Config::StaticClass();
	}
	UDeveloper_PersistentSettings_Config::UDeveloper_PersistentSettings_Config(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_PersistentSettings_Config);
	UDeveloper_PersistentSettings_Config::~UDeveloper_PersistentSettings_Config() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_Config_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_Config_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_PersistentSettings_Config, UDeveloper_PersistentSettings_Config::StaticClass, TEXT("UDeveloper_PersistentSettings_Config"), &Z_Registration_Info_UClass_UDeveloper_PersistentSettings_Config, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_PersistentSettings_Config), 136420893U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_Config_h_1649566692(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_Config_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_Config_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
