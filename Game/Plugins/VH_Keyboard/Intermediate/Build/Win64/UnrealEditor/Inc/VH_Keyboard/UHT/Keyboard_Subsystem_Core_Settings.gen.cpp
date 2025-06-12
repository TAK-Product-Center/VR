// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Keyboard_Subsystem_Core_Settings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKeyboard_Subsystem_Core_Settings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	UPackage* Z_Construct_UPackage__Script_VH_Keyboard();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_NoRegister();
// End Cross Module References
	void UKeyboard_Subsystem_Core_Settings::StaticRegisterNativesUKeyboard_Subsystem_Core_Settings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UKeyboard_Subsystem_Core_Settings);
	UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_NoRegister()
	{
		return UKeyboard_Subsystem_Core_Settings::StaticClass();
	}
	struct Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultKeyboardClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultKeyboardClass;
		static const UECodeGen_Private::FClassPropertyParams NewProp_KeyboardClassMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_KeyboardClassMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyboardClassMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_KeyboardClassMap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyboardCollisionChannel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_KeyboardCollisionChannel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Keyboard,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Subsystems/Public/Keyboard_Subsystem_Core_Settings.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core_Settings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_DefaultKeyboardClass_MetaData[] = {
		{ "Category", "Keyboard_Subsystem_Core_Settings" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core_Settings.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_DefaultKeyboardClass = { "DefaultKeyboardClass", nullptr, (EPropertyFlags)0x0014000000004005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core_Settings, DefaultKeyboardClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_DefaultKeyboardClass_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_DefaultKeyboardClass_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap_ValueProp = { "KeyboardClassMap", nullptr, (EPropertyFlags)0x0004000000004001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap_Key_KeyProp = { "KeyboardClassMap_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap_MetaData[] = {
		{ "Category", "Keyboard_Subsystem_Core_Settings" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core_Settings.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap = { "KeyboardClassMap", nullptr, (EPropertyFlags)0x0014000000004005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core_Settings, KeyboardClassMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardCollisionChannel_MetaData[] = {
		{ "Category", "Keyboard_Subsystem_Core_Settings" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core_Settings.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardCollisionChannel = { "KeyboardCollisionChannel", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core_Settings, KeyboardCollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardCollisionChannel_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardCollisionChannel_MetaData) }; // 1822723181
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_DefaultKeyboardClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardClassMap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::NewProp_KeyboardCollisionChannel,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKeyboard_Subsystem_Core_Settings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::ClassParams = {
		&UKeyboard_Subsystem_Core_Settings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::Class_MetaDataParams), Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings()
	{
		if (!Z_Registration_Info_UClass_UKeyboard_Subsystem_Core_Settings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UKeyboard_Subsystem_Core_Settings.OuterSingleton, Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UKeyboard_Subsystem_Core_Settings.OuterSingleton;
	}
	template<> VH_KEYBOARD_API UClass* StaticClass<UKeyboard_Subsystem_Core_Settings>()
	{
		return UKeyboard_Subsystem_Core_Settings::StaticClass();
	}
	UKeyboard_Subsystem_Core_Settings::UKeyboard_Subsystem_Core_Settings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKeyboard_Subsystem_Core_Settings);
	UKeyboard_Subsystem_Core_Settings::~UKeyboard_Subsystem_Core_Settings() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_Settings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_Settings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings, UKeyboard_Subsystem_Core_Settings::StaticClass, TEXT("UKeyboard_Subsystem_Core_Settings"), &Z_Registration_Info_UClass_UKeyboard_Subsystem_Core_Settings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UKeyboard_Subsystem_Core_Settings), 430354599U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_Settings_h_1246725478(TEXT("/Script/VH_Keyboard"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_Settings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_Settings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
