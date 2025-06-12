// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/UI_Subsystem_ContextMenu_Settings.h"
#include "../../Subsystems/Public/UI_Subsystem_ContextMenu.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_Subsystem_ContextMenu_Settings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_NoRegister();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FContextOptionClasses();
// End Cross Module References
	void UUI_Subsystem_ContextMenu_Settings::StaticRegisterNativesUUI_Subsystem_ContextMenu_Settings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_Subsystem_ContextMenu_Settings);
	UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_NoRegister()
	{
		return UUI_Subsystem_ContextMenu_Settings::StaticClass();
	}
	struct Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AdditionalContextOptionsPerClass_ValueProp;
		static const UECodeGen_Private::FClassPropertyParams NewProp_AdditionalContextOptionsPerClass_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalContextOptionsPerClass_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AdditionalContextOptionsPerClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultContextMenuClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultContextMenuClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContextMenuCollisionChannel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_ContextMenuCollisionChannel;
		static const UECodeGen_Private::FClassPropertyParams NewProp_UniqueContextMenuClasses_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UniqueContextMenuClasses_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_UniqueContextMenuClasses;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Subsystems/Public/UI_Subsystem_ContextMenu_Settings.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu_Settings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass_ValueProp = { "AdditionalContextOptionsPerClass", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FContextOptionClasses, METADATA_PARAMS(0, nullptr) }; // 2687691300
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass_Key_KeyProp = { "AdditionalContextOptionsPerClass_Key", nullptr, (EPropertyFlags)0x0004000000004001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu_Settings" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu_Settings.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass = { "AdditionalContextOptionsPerClass", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu_Settings, AdditionalContextOptionsPerClass), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass_MetaData) }; // 2687691300
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_DefaultContextMenuClass_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu_Settings" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu_Settings.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_DefaultContextMenuClass = { "DefaultContextMenuClass", nullptr, (EPropertyFlags)0x0014000000004005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu_Settings, DefaultContextMenuClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_DefaultContextMenuClass_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_DefaultContextMenuClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_ContextMenuCollisionChannel_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu_Settings" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu_Settings.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_ContextMenuCollisionChannel = { "ContextMenuCollisionChannel", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu_Settings, ContextMenuCollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_ContextMenuCollisionChannel_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_ContextMenuCollisionChannel_MetaData) }; // 1822723181
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_UniqueContextMenuClasses_ElementProp = { "UniqueContextMenuClasses", nullptr, (EPropertyFlags)0x0004000000004001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_UniqueContextMenuClasses_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu_Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* only allows one context menu of this class to be open at a time */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu_Settings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "only allows one context menu of this class to be open at a time" },
#endif
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_UniqueContextMenuClasses = { "UniqueContextMenuClasses", nullptr, (EPropertyFlags)0x0014000000004005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu_Settings, UniqueContextMenuClasses), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_UniqueContextMenuClasses_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_UniqueContextMenuClasses_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_AdditionalContextOptionsPerClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_DefaultContextMenuClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_ContextMenuCollisionChannel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_UniqueContextMenuClasses_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::NewProp_UniqueContextMenuClasses,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_Subsystem_ContextMenu_Settings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::ClassParams = {
		&UUI_Subsystem_ContextMenu_Settings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::Class_MetaDataParams), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings()
	{
		if (!Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu_Settings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu_Settings.OuterSingleton, Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu_Settings.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UUI_Subsystem_ContextMenu_Settings>()
	{
		return UUI_Subsystem_ContextMenu_Settings::StaticClass();
	}
	UUI_Subsystem_ContextMenu_Settings::UUI_Subsystem_ContextMenu_Settings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_Subsystem_ContextMenu_Settings);
	UUI_Subsystem_ContextMenu_Settings::~UUI_Subsystem_ContextMenu_Settings() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_Settings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_Settings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings, UUI_Subsystem_ContextMenu_Settings::StaticClass, TEXT("UUI_Subsystem_ContextMenu_Settings"), &Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu_Settings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_Subsystem_ContextMenu_Settings), 2299346990U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_Settings_h_933817158(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_Settings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_Settings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
