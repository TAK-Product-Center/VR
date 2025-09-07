// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_UnitConverter_Settings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_UnitConverter_Settings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_NoRegister();
// End Cross Module References
	void UDeveloper_Subsystem_UnitConverter_Settings::StaticRegisterNativesUDeveloper_Subsystem_UnitConverter_Settings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_UnitConverter_Settings);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_NoRegister()
	{
		return UDeveloper_Subsystem_UnitConverter_Settings::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultConverters_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultConverters_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_DefaultConverters;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_UnitConverter_Settings.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter_Settings.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::NewProp_DefaultConverters_ElementProp = { "DefaultConverters", nullptr, (EPropertyFlags)0x0004000000004001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::NewProp_DefaultConverters_MetaData[] = {
		{ "Category", "Developer_Subsystem_UnitConverter_Settings" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter_Settings.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::NewProp_DefaultConverters = { "DefaultConverters", nullptr, (EPropertyFlags)0x0014000000004005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_UnitConverter_Settings, DefaultConverters), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::NewProp_DefaultConverters_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::NewProp_DefaultConverters_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::NewProp_DefaultConverters_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::NewProp_DefaultConverters,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_UnitConverter_Settings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::ClassParams = {
		&UDeveloper_Subsystem_UnitConverter_Settings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter_Settings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter_Settings.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter_Settings.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_UnitConverter_Settings>()
	{
		return UDeveloper_Subsystem_UnitConverter_Settings::StaticClass();
	}
	UDeveloper_Subsystem_UnitConverter_Settings::UDeveloper_Subsystem_UnitConverter_Settings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_UnitConverter_Settings);
	UDeveloper_Subsystem_UnitConverter_Settings::~UDeveloper_Subsystem_UnitConverter_Settings() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_Settings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_Settings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings, UDeveloper_Subsystem_UnitConverter_Settings::StaticClass, TEXT("UDeveloper_Subsystem_UnitConverter_Settings"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter_Settings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_UnitConverter_Settings), 2735329441U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_Settings_h_2884535816(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_Settings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_Settings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
