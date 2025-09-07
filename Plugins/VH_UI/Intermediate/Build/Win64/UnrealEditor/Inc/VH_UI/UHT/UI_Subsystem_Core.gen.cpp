// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/UI_Subsystem_Core.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Layout/Margin.h"
#include "Widgets/Layout/Anchors.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_Subsystem_Core() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	SLATE_API UScriptStruct* Z_Construct_UScriptStruct_FAnchors();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_Core();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_Core_NoRegister();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_Core_Settings_NoRegister();
	VH_UI_API UEnum* Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy();
	VH_UI_API UEnum* Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule();
	VH_UI_API UEnum* Z_Construct_UEnum_VH_UI_ETabContainerType();
	VH_UI_API UEnum* Z_Construct_UEnum_VH_UI_EUIType();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FOpenBehavior();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FTabContainerSettings();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EUIType;
	static UEnum* EUIType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EUIType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EUIType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_UI_EUIType, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("EUIType"));
		}
		return Z_Registration_Info_UEnum_EUIType.OuterSingleton;
	}
	template<> VH_UI_API UEnum* StaticEnum<EUIType>()
	{
		return EUIType_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_UI_EUIType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_UI_EUIType_Statics::Enumerators[] = {
		{ "EUIType::Viewport", (int64)EUIType::Viewport },
		{ "EUIType::World", (int64)EUIType::World },
		{ "EUIType::PopoutWindow", (int64)EUIType::PopoutWindow },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_UI_EUIType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enums\n// ---------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
		{ "PopoutWindow.Name", "EUIType::PopoutWindow" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enums" },
#endif
		{ "Viewport.Name", "EUIType::Viewport" },
		{ "World.Name", "EUIType::World" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_UI_EUIType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		"EUIType",
		"EUIType",
		Z_Construct_UEnum_VH_UI_EUIType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EUIType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EUIType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_UI_EUIType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_UI_EUIType()
	{
		if (!Z_Registration_Info_UEnum_EUIType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EUIType.InnerSingleton, Z_Construct_UEnum_VH_UI_EUIType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EUIType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ETabContainerType;
	static UEnum* ETabContainerType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ETabContainerType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ETabContainerType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_UI_ETabContainerType, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("ETabContainerType"));
		}
		return Z_Registration_Info_UEnum_ETabContainerType.OuterSingleton;
	}
	template<> VH_UI_API UEnum* StaticEnum<ETabContainerType>()
	{
		return ETabContainerType_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_UI_ETabContainerType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::Enumerators[] = {
		{ "ETabContainerType::None", (int64)ETabContainerType::None },
		{ "ETabContainerType::Existing", (int64)ETabContainerType::Existing },
		{ "ETabContainerType::New", (int64)ETabContainerType::New },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Existing.Comment", "/* use an existing tab container if any exist; otherwise create new tab container */" },
		{ "Existing.Name", "ETabContainerType::Existing" },
		{ "Existing.ToolTip", "use an existing tab container if any exist; otherwise create new tab container" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
		{ "New.Comment", "/* create a new tab container */" },
		{ "New.Name", "ETabContainerType::New" },
		{ "New.ToolTip", "create a new tab container" },
		{ "None.Comment", "/* does not use tab containers */" },
		{ "None.Name", "ETabContainerType::None" },
		{ "None.ToolTip", "does not use tab containers" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		"ETabContainerType",
		"ETabContainerType",
		Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_UI_ETabContainerType()
	{
		if (!Z_Registration_Info_UEnum_ETabContainerType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ETabContainerType.InnerSingleton, Z_Construct_UEnum_VH_UI_ETabContainerType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ETabContainerType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBlueprintWindowSizingRule;
	static UEnum* EBlueprintWindowSizingRule_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EBlueprintWindowSizingRule.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EBlueprintWindowSizingRule.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("EBlueprintWindowSizingRule"));
		}
		return Z_Registration_Info_UEnum_EBlueprintWindowSizingRule.OuterSingleton;
	}
	template<> VH_UI_API UEnum* StaticEnum<EBlueprintWindowSizingRule>()
	{
		return EBlueprintWindowSizingRule_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::Enumerators[] = {
		{ "EBlueprintWindowSizingRule::FixedSize", (int64)EBlueprintWindowSizingRule::FixedSize },
		{ "EBlueprintWindowSizingRule::Autosized", (int64)EBlueprintWindowSizingRule::Autosized },
		{ "EBlueprintWindowSizingRule::UserSized", (int64)EBlueprintWindowSizingRule::UserSized },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::Enum_MetaDataParams[] = {
		{ "Autosized.Comment", "/* The window size is computed from its content and cannot be resized by users */" },
		{ "Autosized.Name", "EBlueprintWindowSizingRule::Autosized" },
		{ "Autosized.ToolTip", "The window size is computed from its content and cannot be resized by users" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// copied from SWindow.h to expose to blueprint; should be updated each Engine integration\n" },
#endif
		{ "FixedSize.Comment", "/* The windows size fixed and cannot be resized */" },
		{ "FixedSize.Name", "EBlueprintWindowSizingRule::FixedSize" },
		{ "FixedSize.ToolTip", "The windows size fixed and cannot be resized" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "copied from SWindow.h to expose to blueprint; should be updated each Engine integration" },
#endif
		{ "UserSized.Comment", "/* The window can be resized by users */" },
		{ "UserSized.Name", "EBlueprintWindowSizingRule::UserSized" },
		{ "UserSized.ToolTip", "The window can be resized by users" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		"EBlueprintWindowSizingRule",
		"EBlueprintWindowSizingRule",
		Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule()
	{
		if (!Z_Registration_Info_UEnum_EBlueprintWindowSizingRule.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBlueprintWindowSizingRule.InnerSingleton, Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EBlueprintWindowSizingRule.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy;
	static UEnum* EBlueprintWindowActivationPolicy_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("EBlueprintWindowActivationPolicy"));
		}
		return Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy.OuterSingleton;
	}
	template<> VH_UI_API UEnum* StaticEnum<EBlueprintWindowActivationPolicy>()
	{
		return EBlueprintWindowActivationPolicy_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::Enumerators[] = {
		{ "EBlueprintWindowActivationPolicy::Never", (int64)EBlueprintWindowActivationPolicy::Never },
		{ "EBlueprintWindowActivationPolicy::Always", (int64)EBlueprintWindowActivationPolicy::Always },
		{ "EBlueprintWindowActivationPolicy::FirstShown", (int64)EBlueprintWindowActivationPolicy::FirstShown },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::Enum_MetaDataParams[] = {
		{ "Always.Comment", "/* Value indicating that a window always activates when it is shown */" },
		{ "Always.Name", "EBlueprintWindowActivationPolicy::Always" },
		{ "Always.ToolTip", "Value indicating that a window always activates when it is shown" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// copied from SWindow.h to expose to blueprint; should be updated each Engine integration\n" },
#endif
		{ "FirstShown.Comment", "/* Value indicating that a window only activates when it is first shown */" },
		{ "FirstShown.Name", "EBlueprintWindowActivationPolicy::FirstShown" },
		{ "FirstShown.ToolTip", "Value indicating that a window only activates when it is first shown" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
		{ "Never.Comment", "/* Value indicating that a window never activates when it is shown */" },
		{ "Never.Name", "EBlueprintWindowActivationPolicy::Never" },
		{ "Never.ToolTip", "Value indicating that a window never activates when it is shown" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "copied from SWindow.h to expose to blueprint; should be updated each Engine integration" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		"EBlueprintWindowActivationPolicy",
		"EBlueprintWindowActivationPolicy",
		Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy()
	{
		if (!Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy.InnerSingleton, Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OpenBehavior;
class UScriptStruct* FOpenBehavior::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OpenBehavior.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OpenBehavior.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOpenBehavior, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("OpenBehavior"));
	}
	return Z_Registration_Info_UScriptStruct_OpenBehavior.OuterSingleton;
}
template<> VH_UI_API UScriptStruct* StaticStruct<FOpenBehavior>()
{
	return FOpenBehavior::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOpenBehavior_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_OpenBehavior_ValueProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OpenBehavior_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OpenBehavior_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OpenBehavior_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OpenBehavior_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_OpenBehavior;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAllowMultipleInstances_MetaData[];
#endif
		static void NewProp_bAllowMultipleInstances_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowMultipleInstances;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenBehavior_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Structs\n// ---------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Structs" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOpenBehavior>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_ValueProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_ValueProp = { "OpenBehavior", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UEnum_VH_UI_EUIType, METADATA_PARAMS(0, nullptr) }; // 3765397352
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_Key_KeyProp = { "OpenBehavior_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_MetaData[] = {
		{ "Category", "OpenBehavior" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior = { "OpenBehavior", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenBehavior, OpenBehavior), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_MetaData), Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_MetaData) }; // 2688149405 3765397352
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_bAllowMultipleInstances_MetaData[] = {
		{ "Category", "OpenBehavior" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_bAllowMultipleInstances_SetBit(void* Obj)
	{
		((FOpenBehavior*)Obj)->bAllowMultipleInstances = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_bAllowMultipleInstances = { "bAllowMultipleInstances", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenBehavior), &Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_bAllowMultipleInstances_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_bAllowMultipleInstances_MetaData), Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_bAllowMultipleInstances_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOpenBehavior_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_ValueProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_OpenBehavior,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewProp_bAllowMultipleInstances,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOpenBehavior_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		&NewStructOps,
		"OpenBehavior",
		Z_Construct_UScriptStruct_FOpenBehavior_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenBehavior_Statics::PropPointers),
		sizeof(FOpenBehavior),
		alignof(FOpenBehavior),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenBehavior_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOpenBehavior_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenBehavior_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOpenBehavior()
	{
		if (!Z_Registration_Info_UScriptStruct_OpenBehavior.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OpenBehavior.InnerSingleton, Z_Construct_UScriptStruct_FOpenBehavior_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OpenBehavior.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings;
class UScriptStruct* FOpenUserWidgetViewportSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("OpenUserWidgetViewportSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings.OuterSingleton;
}
template<> VH_UI_API UScriptStruct* StaticStruct<FOpenUserWidgetViewportSettings>()
{
	return FOpenUserWidgetViewportSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Anchors_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Anchors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Alignment_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Alignment;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOpenUserWidgetViewportSettings>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "OpenUserWidgetViewportSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* position in viewport; 0, 0 is top left */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "position in viewport; 0, 0 is top left" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetViewportSettings, Position), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Position_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Position_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Size_MetaData[] = {
		{ "Category", "OpenUserWidgetViewportSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* pixel size */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "pixel size" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetViewportSettings, Size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Size_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Size_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Anchors_MetaData[] = {
		{ "Category", "OpenUserWidgetViewportSettings" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Anchors = { "Anchors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetViewportSettings, Anchors), Z_Construct_UScriptStruct_FAnchors, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Anchors_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Anchors_MetaData) }; // 983886659
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Alignment_MetaData[] = {
		{ "Category", "OpenUserWidgetViewportSettings" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Alignment = { "Alignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetViewportSettings, Alignment), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Alignment_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Alignment_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Anchors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewProp_Alignment,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		&NewStructOps,
		"OpenUserWidgetViewportSettings",
		Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::PropPointers),
		sizeof(FOpenUserWidgetViewportSettings),
		alignof(FOpenUserWidgetViewportSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings.InnerSingleton, Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings;
class UScriptStruct* FOpenUserWidgetWorldSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("OpenUserWidgetWorldSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings.OuterSingleton;
}
template<> VH_UI_API UScriptStruct* StaticStruct<FOpenUserWidgetWorldSettings>()
{
	return FOpenUserWidgetWorldSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldUIActorClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_WorldUIActorClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldUIActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldUIActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalSpawnOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LocalSpawnOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOpenUserWidgetWorldSettings>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActorClass_MetaData[] = {
		{ "Category", "OpenUserWidgetWorldSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if WorldUIActor and WorldUIActorClass are nullptr, uses subsystem's DefaultWorldSettings */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if WorldUIActor and WorldUIActorClass are nullptr, uses subsystem's DefaultWorldSettings" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActorClass = { "WorldUIActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWorldSettings, WorldUIActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActorClass_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActorClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActor_MetaData[] = {
		{ "Category", "OpenUserWidgetWorldSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if WorldUIActor is nullptr, spawns actor using WorldUIActoClass */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if WorldUIActor is nullptr, spawns actor using WorldUIActoClass" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActor = { "WorldUIActor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWorldSettings, WorldUIActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActor_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_LocalSpawnOffset_MetaData[] = {
		{ "Category", "OpenUserWidgetWorldSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* local offset from player camera to use if spawning WorldUIActor */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "local offset from player camera to use if spawning WorldUIActor" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_LocalSpawnOffset = { "LocalSpawnOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWorldSettings, LocalSpawnOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_LocalSpawnOffset_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_LocalSpawnOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_Size_MetaData[] = {
		{ "Category", "OpenUserWidgetWorldSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* size of widget in WidgetComponent of WorldUIActor */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "size of widget in WidgetComponent of WorldUIActor" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWorldSettings, Size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_Size_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_Size_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActorClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_WorldUIActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_LocalSpawnOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewProp_Size,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		&NewStructOps,
		"OpenUserWidgetWorldSettings",
		Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::PropPointers),
		sizeof(FOpenUserWidgetWorldSettings),
		alignof(FOpenUserWidgetWorldSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings.InnerSingleton, Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings;
class UScriptStruct* FOpenUserWidgetWindowSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("OpenUserWidgetWindowSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings.OuterSingleton;
}
template<> VH_UI_API UScriptStruct* StaticStruct<FOpenUserWidgetWindowSettings>()
{
	return FOpenUserWidgetWindowSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoCenter_MetaData[];
#endif
		static void NewProp_AutoCenter_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_AutoCenter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ClientSize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ClientSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SupportsTransparency_MetaData[];
#endif
		static void NewProp_SupportsTransparency_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SupportsTransparency;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitialOpacity_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_InitialOpacity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsInitiallyMaximized_MetaData[];
#endif
		static void NewProp_IsInitiallyMaximized_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsInitiallyMaximized;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsInitiallyMinimized_MetaData[];
#endif
		static void NewProp_IsInitiallyMinimized_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsInitiallyMinimized;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SizingRule_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SizingRule_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SizingRule;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsTopmostWindow_MetaData[];
#endif
		static void NewProp_IsTopmostWindow_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTopmostWindow;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FocusWhenFirstShown_MetaData[];
#endif
		static void NewProp_FocusWhenFirstShown_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_FocusWhenFirstShown;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ActivationPolicy_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActivationPolicy_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ActivationPolicy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UseOSWindowBorder_MetaData[];
#endif
		static void NewProp_UseOSWindowBorder_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_UseOSWindowBorder;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HasCloseButton_MetaData[];
#endif
		static void NewProp_HasCloseButton_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_HasCloseButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SupportsMaximize_MetaData[];
#endif
		static void NewProp_SupportsMaximize_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SupportsMaximize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SupportsMinimize_MetaData[];
#endif
		static void NewProp_SupportsMinimize_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SupportsMinimize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShouldPreserveAspectRatio_MetaData[];
#endif
		static void NewProp_ShouldPreserveAspectRatio_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ShouldPreserveAspectRatio;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinWidth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxWidth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CreateTitleBar_MetaData[];
#endif
		static void NewProp_CreateTitleBar_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CreateTitleBar;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SaneWindowPlacement_MetaData[];
#endif
		static void NewProp_SaneWindowPlacement_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SaneWindowPlacement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LayoutBorder_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LayoutBorder;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserResizeBorder_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UserResizeBorder;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bManualManageDPI_MetaData[];
#endif
		static void NewProp_bManualManageDPI_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bManualManageDPI;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// copied from SWindow.h to expose to blueprint; should be updated each Engine integration\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "copied from SWindow.h to expose to blueprint; should be updated each Engine integration" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOpenUserWidgetWindowSettings>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_Title_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Title of the window */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Title of the window" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, Title), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_Title_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_Title_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_AutoCenter_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Does this window auto-center? If set to true, then the\n\x09\x09ScreenPosition value will be ignored */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Does this window auto-center? If set to true, then the\n              ScreenPosition value will be ignored" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_AutoCenter_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->AutoCenter = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_AutoCenter = { "AutoCenter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_AutoCenter_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_AutoCenter_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_AutoCenter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Screen-space position where the window should be initially located. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Screen-space position where the window should be initially located." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ScreenPosition_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ScreenPosition_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ClientSize_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* What the initial size of the window should be. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What the initial size of the window should be." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ClientSize = { "ClientSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, ClientSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ClientSize_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ClientSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsTransparency_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Should this window support transparency */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should this window support transparency" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsTransparency_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->SupportsTransparency = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsTransparency = { "SupportsTransparency", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsTransparency_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsTransparency_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsTransparency_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_InitialOpacity_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The initial opacity of the window */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The initial opacity of the window" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_InitialOpacity = { "InitialOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, InitialOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_InitialOpacity_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_InitialOpacity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMaximized_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Is the window initially maximized */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Is the window initially maximized" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMaximized_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->IsInitiallyMaximized = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMaximized = { "IsInitiallyMaximized", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMaximized_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMaximized_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMaximized_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMinimized_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Is the window initially minimized */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Is the window initially minimized" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMinimized_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->IsInitiallyMinimized = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMinimized = { "IsInitiallyMinimized", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMinimized_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMinimized_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMinimized_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SizingRule_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SizingRule_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* How the window should be sized */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How the window should be sized" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SizingRule = { "SizingRule", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, SizingRule), Z_Construct_UEnum_VH_UI_EBlueprintWindowSizingRule, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SizingRule_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SizingRule_MetaData) }; // 2700173059
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsTopmostWindow_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* True if this window should always be on top of all other windows */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True if this window should always be on top of all other windows" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsTopmostWindow_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->IsTopmostWindow = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsTopmostWindow = { "IsTopmostWindow", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsTopmostWindow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsTopmostWindow_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsTopmostWindow_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_FocusWhenFirstShown_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Should this window be focused immediately after it is shown? */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should this window be focused immediately after it is shown?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_FocusWhenFirstShown_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->FocusWhenFirstShown = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_FocusWhenFirstShown = { "FocusWhenFirstShown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_FocusWhenFirstShown_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_FocusWhenFirstShown_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_FocusWhenFirstShown_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ActivationPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ActivationPolicy_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* When should this window be activated upon being shown? */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When should this window be activated upon being shown?" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ActivationPolicy = { "ActivationPolicy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, ActivationPolicy), Z_Construct_UEnum_VH_UI_EBlueprintWindowActivationPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ActivationPolicy_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ActivationPolicy_MetaData) }; // 3288275011
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UseOSWindowBorder_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Use the default os look for the border of the window */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use the default os look for the border of the window" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UseOSWindowBorder_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->UseOSWindowBorder = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UseOSWindowBorder = { "UseOSWindowBorder", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UseOSWindowBorder_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UseOSWindowBorder_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UseOSWindowBorder_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_HasCloseButton_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Does this window have a close button? */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Does this window have a close button?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_HasCloseButton_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->HasCloseButton = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_HasCloseButton = { "HasCloseButton", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_HasCloseButton_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_HasCloseButton_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_HasCloseButton_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMaximize_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Can this window be maximized? */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can this window be maximized?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMaximize_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->SupportsMaximize = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMaximize = { "SupportsMaximize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMaximize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMaximize_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMaximize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMinimize_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Can this window be minimized? */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can this window be minimized?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMinimize_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->SupportsMinimize = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMinimize = { "SupportsMinimize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMinimize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMinimize_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMinimize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ShouldPreserveAspectRatio_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Should this window preserve its aspect ratio when resized by user? */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should this window preserve its aspect ratio when resized by user?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ShouldPreserveAspectRatio_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->ShouldPreserveAspectRatio = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ShouldPreserveAspectRatio = { "ShouldPreserveAspectRatio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ShouldPreserveAspectRatio_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ShouldPreserveAspectRatio_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ShouldPreserveAspectRatio_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinWidth_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The smallest width this window can be in Desktop Pixel Units. 0 means to ignore. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The smallest width this window can be in Desktop Pixel Units. 0 means to ignore." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinWidth = { "MinWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, MinWidth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinWidth_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinWidth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinHeight_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The smallest height this window can be in Desktop Pixel Units. 0 means to ignore. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The smallest height this window can be in Desktop Pixel Units. 0 means to ignore." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinHeight = { "MinHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, MinHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinHeight_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxWidth_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The biggest width this window can be in Desktop Pixel Units. 0 means to ignore. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The biggest width this window can be in Desktop Pixel Units. 0 means to ignore." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxWidth = { "MaxWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, MaxWidth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxWidth_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxWidth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxHeight_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The biggest height this window can be in Desktop Pixel Units. 0 means to ignore. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The biggest height this window can be in Desktop Pixel Units. 0 means to ignore." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxHeight = { "MaxHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, MaxHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxHeight_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_CreateTitleBar_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* True if we should initially create a traditional title bar area.  If false, the user must embed the title\n\x09\x09""area content into the window manually, taking into account platform-specific considerations!  Has no\n\x09\x09""effect for certain types of windows (popups, tool-tips, etc.) */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True if we should initially create a traditional title bar area.  If false, the user must embed the title\n              area content into the window manually, taking into account platform-specific considerations!  Has no\n              effect for certain types of windows (popups, tool-tips, etc.)" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_CreateTitleBar_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->CreateTitleBar = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_CreateTitleBar = { "CreateTitleBar", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_CreateTitleBar_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_CreateTitleBar_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_CreateTitleBar_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SaneWindowPlacement_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* If the window appears off screen or is too large to safely fit this flag will force realistic\n\x09\x09""constraints on the window and bring it back into view. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the window appears off screen or is too large to safely fit this flag will force realistic\n              constraints on the window and bring it back into view." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SaneWindowPlacement_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->SaneWindowPlacement = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SaneWindowPlacement = { "SaneWindowPlacement", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SaneWindowPlacement_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SaneWindowPlacement_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SaneWindowPlacement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_LayoutBorder_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The padding around the edges of the window applied to it's content. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The padding around the edges of the window applied to it's content." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_LayoutBorder = { "LayoutBorder", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, LayoutBorder), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_LayoutBorder_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_LayoutBorder_MetaData) }; // 2235102396
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UserResizeBorder_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The margin around the edges of the window that will be detected as places the user can grab to resize the window. */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The margin around the edges of the window that will be detected as places the user can grab to resize the window." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UserResizeBorder = { "UserResizeBorder", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOpenUserWidgetWindowSettings, UserResizeBorder), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UserResizeBorder_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UserResizeBorder_MetaData) }; // 2235102396
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_bManualManageDPI_MetaData[] = {
		{ "Category", "OpenUserWidgetWindowSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* true if this window will self handle any eventual DPI adjustments */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "true if this window will self handle any eventual DPI adjustments" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_bManualManageDPI_SetBit(void* Obj)
	{
		((FOpenUserWidgetWindowSettings*)Obj)->bManualManageDPI = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_bManualManageDPI = { "bManualManageDPI", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOpenUserWidgetWindowSettings), &Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_bManualManageDPI_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_bManualManageDPI_MetaData), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_bManualManageDPI_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_Title,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_AutoCenter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ClientSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsTransparency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_InitialOpacity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMaximized,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsInitiallyMinimized,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SizingRule_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SizingRule,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_IsTopmostWindow,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_FocusWhenFirstShown,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ActivationPolicy_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ActivationPolicy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UseOSWindowBorder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_HasCloseButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMaximize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SupportsMinimize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_ShouldPreserveAspectRatio,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MinHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_MaxHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_CreateTitleBar,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_SaneWindowPlacement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_LayoutBorder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_UserResizeBorder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewProp_bManualManageDPI,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		&NewStructOps,
		"OpenUserWidgetWindowSettings",
		Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::PropPointers),
		sizeof(FOpenUserWidgetWindowSettings),
		alignof(FOpenUserWidgetWindowSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings.InnerSingleton, Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TabContainerSettings;
class UScriptStruct* FTabContainerSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TabContainerSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TabContainerSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTabContainerSettings, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("TabContainerSettings"));
	}
	return Z_Registration_Info_UScriptStruct_TabContainerSettings.OuterSingleton;
}
template<> VH_UI_API UScriptStruct* StaticStruct<FTabContainerSettings>()
{
	return FTabContainerSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTabContainerSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_TabContainerType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TabContainerType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TabContainerType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TabContainerClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_TabContainerClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TabContainer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TabContainer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTabContainerSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTabContainerSettings>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerType_MetaData[] = {
		{ "Category", "TabContainerSettings" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerType = { "TabContainerType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTabContainerSettings, TabContainerType), Z_Construct_UEnum_VH_UI_ETabContainerType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerType_MetaData), Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerType_MetaData) }; // 2853082499
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerClass_MetaData[] = {
		{ "Category", "TabContainerSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if needs TabContainer and TabContainer and TabContainerClass are nullptr, uses subsystem's default TabContainerSettings */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if needs TabContainer and TabContainer and TabContainerClass are nullptr, uses subsystem's default TabContainerSettings" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerClass = { "TabContainerClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTabContainerSettings, TabContainerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerClass_MetaData), Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainer_MetaData[] = {
		{ "Category", "TabContainerSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if needs TabContainer and TabContainer is nullptr, spawns tab container using TabContainerClass */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if needs TabContainer and TabContainer is nullptr, spawns tab container using TabContainerClass" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainer = { "TabContainer", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTabContainerSettings, TabContainer), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainer_MetaData), Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTabContainerSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainerClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewProp_TabContainer,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTabContainerSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		&NewStructOps,
		"TabContainerSettings",
		Z_Construct_UScriptStruct_FTabContainerSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabContainerSettings_Statics::PropPointers),
		sizeof(FTabContainerSettings),
		alignof(FTabContainerSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000005),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabContainerSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTabContainerSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabContainerSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FTabContainerSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_TabContainerSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TabContainerSettings.InnerSingleton, Z_Construct_UScriptStruct_FTabContainerSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TabContainerSettings.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics
	{
		struct UI_Subsystem_Core_eventOnUserWidgetClosed_Parms
		{
			UUserWidget* userWidget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOnUserWidgetClosed_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::NewProp_userWidget_MetaData), Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::NewProp_userWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OnUserWidgetClosed__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::UI_Subsystem_Core_eventOnUserWidgetClosed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::UI_Subsystem_Core_eventOnUserWidgetClosed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UUI_Subsystem_Core::FOnUserWidgetClosed_DelegateWrapper(const FMulticastScriptDelegate& OnUserWidgetClosed, UUserWidget* userWidget)
{
	struct UI_Subsystem_Core_eventOnUserWidgetClosed_Parms
	{
		UUserWidget* userWidget;
	};
	UI_Subsystem_Core_eventOnUserWidgetClosed_Parms Parms;
	Parms.userWidget=userWidget;
	OnUserWidgetClosed.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics
	{
		struct UI_Subsystem_Core_eventOnUserWidgetOpened_Parms
		{
			UUserWidget* userWidget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOnUserWidgetOpened_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::NewProp_userWidget_MetaData), Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::NewProp_userWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OnUserWidgetOpened__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::UI_Subsystem_Core_eventOnUserWidgetOpened_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::UI_Subsystem_Core_eventOnUserWidgetOpened_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UUI_Subsystem_Core::FOnUserWidgetOpened_DelegateWrapper(const FMulticastScriptDelegate& OnUserWidgetOpened, UUserWidget* userWidget)
{
	struct UI_Subsystem_Core_eventOnUserWidgetOpened_Parms
	{
		UUserWidget* userWidget;
	};
	UI_Subsystem_Core_eventOnUserWidgetOpened_Parms Parms;
	Parms.userWidget=userWidget;
	OnUserWidgetOpened.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execHandleHardwareInterfaceModeChanged)
	{
		P_GET_ENUM(EHardwareInterfaceMode,Z_Param_newMode);
		P_GET_ENUM(EHardwareInterfaceMode,Z_Param_previousMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode(Z_Param_newMode),EHardwareInterfaceMode(Z_Param_previousMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execMoveWindowToMonitor)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_PROPERTY(FIntProperty,Z_Param_monitorIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->MoveWindowToMonitor(Z_Param_userWidget,Z_Param_monitorIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetWindowMonitorIndex)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_monitorIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetWindowMonitorIndex(Z_Param_userWidget,Z_Param_Out_monitorIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetViewportSize)
	{
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_size);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetViewportSize(Z_Param_Out_size);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetViewportPosition)
	{
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_position);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetViewportPosition(Z_Param_Out_position);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetViewportMonitorIndex)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_monitorIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetViewportMonitorIndex(Z_Param_Out_monitorIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execSetUserWidgetClassWorldSettings)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_GET_STRUCT_REF(FOpenUserWidgetWorldSettings,Z_Param_Out_settings);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUserWidgetClassWorldSettings(Z_Param_userWidgetClass,Z_Param_Out_settings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetClassWorldSettings)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FOpenUserWidgetWorldSettings*)Z_Param__Result=P_THIS->GetUserWidgetClassWorldSettings(Z_Param_userWidgetClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execSetUserWidgetDefaultWorldUIActor)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_OBJECT(AActor,Z_Param_worldUIActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUserWidgetDefaultWorldUIActor(Z_Param_userWidget,Z_Param_worldUIActor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetWorldUIActor)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->GetUserWidgetWorldUIActor(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetsByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_GET_UBOOL(Z_Param_bIncludeSubclasses);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<UUserWidget*>*)Z_Param__Result=P_THIS->GetUserWidgetsByClass(Z_Param_userWidgetClass,Z_Param_bIncludeSubclasses);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execSetUserWidgetTabContainer)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_OBJECT(UUserWidget,Z_Param_tabContainer);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUserWidgetTabContainer(Z_Param_userWidget,Z_Param_tabContainer);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execMoveWidgetToNewTabContainer)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveWidgetToNewTabContainer(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execRemoveUserWidgetFromTabContainer)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveUserWidgetFromTabContainer(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetTabsInTabContainer)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_tabContainer);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<UUserWidget*>*)Z_Param__Result=P_THIS->GetTabsInTabContainer(Z_Param_tabContainer);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetTabContainer)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UUserWidget**)Z_Param__Result=P_THIS->GetUserWidgetTabContainer(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetScale)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=P_THIS->GetUserWidgetScale(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execSetUserWidgetScale)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_scale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUserWidgetScale(Z_Param_userWidget,Z_Param_Out_scale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execMoveUserWidgetToWorldLocation)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_worldLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveUserWidgetToWorldLocation(Z_Param_userWidget,Z_Param_Out_worldLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetPosition)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=P_THIS->GetUserWidgetPosition(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execSetUserWidgetPosition)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_position);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUserWidgetPosition(Z_Param_userWidget,Z_Param_Out_position);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetSize)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=P_THIS->GetUserWidgetSize(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execSetUserWidgetSize)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_size);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUserWidgetSize(Z_Param_userWidget,Z_Param_Out_size);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execCloseAllWidgetsByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_GET_UBOOL(Z_Param_bIncludeSubclasses);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseAllWidgetsByClass(Z_Param_userWidgetClass,Z_Param_bIncludeSubclasses);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execCloseUserWidget)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseUserWidget(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execCloseTabContainer)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_tabContainer);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseTabContainer(Z_Param_tabContainer);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execGetUserWidgetUIType)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EUIType*)Z_Param__Result=P_THIS->GetUserWidgetUIType(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenInPopoutWindow)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_STRUCT_REF(FTabContainerSettings,Z_Param_Out_tabContainerSettings);
		P_GET_STRUCT_REF(FOpenUserWidgetWindowSettings,Z_Param_Out_windowSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OpenInPopoutWindow(Z_Param_userWidget,Z_Param_Out_tabContainerSettings,Z_Param_Out_windowSettings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenInPopoutWindowByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_GET_STRUCT_REF(FTabContainerSettings,Z_Param_Out_tabContainerSettings);
		P_GET_STRUCT_REF(FOpenUserWidgetWindowSettings,Z_Param_Out_windowSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UUserWidget**)Z_Param__Result=P_THIS->OpenInPopoutWindowByClass(Z_Param_userWidgetClass,Z_Param_Out_tabContainerSettings,Z_Param_Out_windowSettings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenInWorld)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_STRUCT_REF(FTabContainerSettings,Z_Param_Out_tabContainerSettings);
		P_GET_STRUCT_REF(FOpenUserWidgetWorldSettings,Z_Param_Out_worldSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OpenInWorld(Z_Param_userWidget,Z_Param_Out_tabContainerSettings,Z_Param_Out_worldSettings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenInWorldByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_GET_STRUCT_REF(FTabContainerSettings,Z_Param_Out_tabContainerSettings);
		P_GET_STRUCT_REF(FOpenUserWidgetWorldSettings,Z_Param_Out_worldSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UUserWidget**)Z_Param__Result=P_THIS->OpenInWorldByClass(Z_Param_userWidgetClass,Z_Param_Out_tabContainerSettings,Z_Param_Out_worldSettings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenInViewport)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_GET_STRUCT_REF(FTabContainerSettings,Z_Param_Out_tabContainerSettings);
		P_GET_STRUCT_REF(FOpenUserWidgetViewportSettings,Z_Param_Out_viewportSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OpenInViewport(Z_Param_userWidget,Z_Param_Out_tabContainerSettings,Z_Param_Out_viewportSettings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenInViewportByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_GET_STRUCT_REF(FTabContainerSettings,Z_Param_Out_tabContainerSettings);
		P_GET_STRUCT_REF(FOpenUserWidgetViewportSettings,Z_Param_Out_viewportSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UUserWidget**)Z_Param__Result=P_THIS->OpenInViewportByClass(Z_Param_userWidgetClass,Z_Param_Out_tabContainerSettings,Z_Param_Out_viewportSettings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenWithDefaults)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OpenWithDefaults(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execOpenWithDefaultsByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_userWidgetClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UUserWidget**)Z_Param__Result=P_THIS->OpenWithDefaultsByClass(Z_Param_userWidgetClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_Core::execUpdateSettings)
	{
		P_GET_OBJECT(UClass,Z_Param_settingsClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSettings(Z_Param_settingsClass);
		P_NATIVE_END;
	}
	void UUI_Subsystem_Core::StaticRegisterNativesUUI_Subsystem_Core()
	{
		UClass* Class = UUI_Subsystem_Core::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseAllWidgetsByClass", &UUI_Subsystem_Core::execCloseAllWidgetsByClass },
			{ "CloseTabContainer", &UUI_Subsystem_Core::execCloseTabContainer },
			{ "CloseUserWidget", &UUI_Subsystem_Core::execCloseUserWidget },
			{ "GetTabsInTabContainer", &UUI_Subsystem_Core::execGetTabsInTabContainer },
			{ "GetUserWidgetClassWorldSettings", &UUI_Subsystem_Core::execGetUserWidgetClassWorldSettings },
			{ "GetUserWidgetPosition", &UUI_Subsystem_Core::execGetUserWidgetPosition },
			{ "GetUserWidgetsByClass", &UUI_Subsystem_Core::execGetUserWidgetsByClass },
			{ "GetUserWidgetScale", &UUI_Subsystem_Core::execGetUserWidgetScale },
			{ "GetUserWidgetSize", &UUI_Subsystem_Core::execGetUserWidgetSize },
			{ "GetUserWidgetTabContainer", &UUI_Subsystem_Core::execGetUserWidgetTabContainer },
			{ "GetUserWidgetUIType", &UUI_Subsystem_Core::execGetUserWidgetUIType },
			{ "GetUserWidgetWorldUIActor", &UUI_Subsystem_Core::execGetUserWidgetWorldUIActor },
			{ "GetViewportMonitorIndex", &UUI_Subsystem_Core::execGetViewportMonitorIndex },
			{ "GetViewportPosition", &UUI_Subsystem_Core::execGetViewportPosition },
			{ "GetViewportSize", &UUI_Subsystem_Core::execGetViewportSize },
			{ "GetWindowMonitorIndex", &UUI_Subsystem_Core::execGetWindowMonitorIndex },
			{ "HandleHardwareInterfaceModeChanged", &UUI_Subsystem_Core::execHandleHardwareInterfaceModeChanged },
			{ "MoveUserWidgetToWorldLocation", &UUI_Subsystem_Core::execMoveUserWidgetToWorldLocation },
			{ "MoveWidgetToNewTabContainer", &UUI_Subsystem_Core::execMoveWidgetToNewTabContainer },
			{ "MoveWindowToMonitor", &UUI_Subsystem_Core::execMoveWindowToMonitor },
			{ "OpenInPopoutWindow", &UUI_Subsystem_Core::execOpenInPopoutWindow },
			{ "OpenInPopoutWindowByClass", &UUI_Subsystem_Core::execOpenInPopoutWindowByClass },
			{ "OpenInViewport", &UUI_Subsystem_Core::execOpenInViewport },
			{ "OpenInViewportByClass", &UUI_Subsystem_Core::execOpenInViewportByClass },
			{ "OpenInWorld", &UUI_Subsystem_Core::execOpenInWorld },
			{ "OpenInWorldByClass", &UUI_Subsystem_Core::execOpenInWorldByClass },
			{ "OpenWithDefaults", &UUI_Subsystem_Core::execOpenWithDefaults },
			{ "OpenWithDefaultsByClass", &UUI_Subsystem_Core::execOpenWithDefaultsByClass },
			{ "RemoveUserWidgetFromTabContainer", &UUI_Subsystem_Core::execRemoveUserWidgetFromTabContainer },
			{ "SetUserWidgetClassWorldSettings", &UUI_Subsystem_Core::execSetUserWidgetClassWorldSettings },
			{ "SetUserWidgetDefaultWorldUIActor", &UUI_Subsystem_Core::execSetUserWidgetDefaultWorldUIActor },
			{ "SetUserWidgetPosition", &UUI_Subsystem_Core::execSetUserWidgetPosition },
			{ "SetUserWidgetScale", &UUI_Subsystem_Core::execSetUserWidgetScale },
			{ "SetUserWidgetSize", &UUI_Subsystem_Core::execSetUserWidgetSize },
			{ "SetUserWidgetTabContainer", &UUI_Subsystem_Core::execSetUserWidgetTabContainer },
			{ "UpdateSettings", &UUI_Subsystem_Core::execUpdateSettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics
	{
		struct UI_Subsystem_Core_eventCloseAllWidgetsByClass_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			bool bIncludeSubclasses;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
		static void NewProp_bIncludeSubclasses_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeSubclasses;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventCloseAllWidgetsByClass_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::NewProp_bIncludeSubclasses_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventCloseAllWidgetsByClass_Parms*)Obj)->bIncludeSubclasses = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::NewProp_bIncludeSubclasses = { "bIncludeSubclasses", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventCloseAllWidgetsByClass_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::NewProp_bIncludeSubclasses_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::NewProp_bIncludeSubclasses,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "CloseAllWidgetsByClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::UI_Subsystem_Core_eventCloseAllWidgetsByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::UI_Subsystem_Core_eventCloseAllWidgetsByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics
	{
		struct UI_Subsystem_Core_eventCloseTabContainer_Parms
		{
			UUserWidget* tabContainer;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tabContainer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::NewProp_tabContainer_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::NewProp_tabContainer = { "tabContainer", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventCloseTabContainer_Parms, tabContainer), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::NewProp_tabContainer_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::NewProp_tabContainer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::NewProp_tabContainer,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "CloseTabContainer", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::UI_Subsystem_Core_eventCloseTabContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::UI_Subsystem_Core_eventCloseTabContainer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics
	{
		struct UI_Subsystem_Core_eventCloseUserWidget_Parms
		{
			UUserWidget* userWidget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventCloseUserWidget_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::NewProp_userWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "CloseUserWidget", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::UI_Subsystem_Core_eventCloseUserWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::UI_Subsystem_Core_eventCloseUserWidget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics
	{
		struct UI_Subsystem_Core_eventGetTabsInTabContainer_Parms
		{
			UUserWidget* tabContainer;
			TSet<UUserWidget*> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tabContainer;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_tabContainer_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_tabContainer = { "tabContainer", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetTabsInTabContainer_Parms, tabContainer), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_tabContainer_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_tabContainer_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetTabsInTabContainer_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_tabContainer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetTabsInTabContainer", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::UI_Subsystem_Core_eventGetTabsInTabContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::UI_Subsystem_Core_eventGetTabsInTabContainer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetClassWorldSettings_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			FOpenUserWidgetWorldSettings ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetClassWorldSettings_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetClassWorldSettings_Parms, ReturnValue), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings, METADATA_PARAMS(0, nullptr) }; // 3485812593
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief returns DefaultWorldSettings if DefaultClassWorldSettings does not contain userWidgetClass\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief returns DefaultWorldSettings if DefaultClassWorldSettings does not contain userWidgetClass" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetClassWorldSettings", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::UI_Subsystem_Core_eventGetUserWidgetClassWorldSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::UI_Subsystem_Core_eventGetUserWidgetClassWorldSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetPosition_Parms
		{
			UUserWidget* userWidget;
			FVector2D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetPosition_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetPosition", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::UI_Subsystem_Core_eventGetUserWidgetPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::UI_Subsystem_Core_eventGetUserWidgetPosition_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetsByClass_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			bool bIncludeSubclasses;
			TSet<UUserWidget*> ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
		static void NewProp_bIncludeSubclasses_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeSubclasses;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetsByClass_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_bIncludeSubclasses_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventGetUserWidgetsByClass_Parms*)Obj)->bIncludeSubclasses = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_bIncludeSubclasses = { "bIncludeSubclasses", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventGetUserWidgetsByClass_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_bIncludeSubclasses_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetsByClass_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_bIncludeSubclasses,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetsByClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::UI_Subsystem_Core_eventGetUserWidgetsByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::UI_Subsystem_Core_eventGetUserWidgetsByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetScale_Parms
		{
			UUserWidget* userWidget;
			FVector2D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetScale_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetScale_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetScale", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::UI_Subsystem_Core_eventGetUserWidgetScale_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::UI_Subsystem_Core_eventGetUserWidgetScale_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetSize_Parms
		{
			UUserWidget* userWidget;
			FVector2D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetSize_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetSize_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetSize", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::UI_Subsystem_Core_eventGetUserWidgetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::UI_Subsystem_Core_eventGetUserWidgetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetTabContainer_Parms
		{
			UUserWidget* userWidget;
			UUserWidget* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetTabContainer_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetTabContainer_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetTabContainer", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::UI_Subsystem_Core_eventGetUserWidgetTabContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::UI_Subsystem_Core_eventGetUserWidgetTabContainer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetUIType_Parms
		{
			UUserWidget* userWidget;
			EUIType ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetUIType_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetUIType_Parms, ReturnValue), Z_Construct_UEnum_VH_UI_EUIType, METADATA_PARAMS(0, nullptr) }; // 3765397352
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetUIType", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::UI_Subsystem_Core_eventGetUserWidgetUIType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::UI_Subsystem_Core_eventGetUserWidgetUIType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics
	{
		struct UI_Subsystem_Core_eventGetUserWidgetWorldUIActor_Parms
		{
			const UUserWidget* userWidget;
			AActor* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetWorldUIActor_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetUserWidgetWorldUIActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns worldUIActor currently displaying userWidget (if any)\n\x09* \\param userWidget UserWidget to find\n\x09* \\return WorldUIActor currently displaying userWidget\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns worldUIActor currently displaying userWidget (if any)\n* \\param userWidget UserWidget to find\n* \\return WorldUIActor currently displaying userWidget" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetUserWidgetWorldUIActor", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::UI_Subsystem_Core_eventGetUserWidgetWorldUIActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::UI_Subsystem_Core_eventGetUserWidgetWorldUIActor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics
	{
		struct UI_Subsystem_Core_eventGetViewportMonitorIndex_Parms
		{
			int32 monitorIndex;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_monitorIndex;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::NewProp_monitorIndex = { "monitorIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetViewportMonitorIndex_Parms, monitorIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventGetViewportMonitorIndex_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventGetViewportMonitorIndex_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::NewProp_monitorIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetViewportMonitorIndex", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::UI_Subsystem_Core_eventGetViewportMonitorIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::UI_Subsystem_Core_eventGetViewportMonitorIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics
	{
		struct UI_Subsystem_Core_eventGetViewportPosition_Parms
		{
			FVector2D position;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_position;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::NewProp_position = { "position", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetViewportPosition_Parms, position), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventGetViewportPosition_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventGetViewportPosition_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::NewProp_position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetViewportPosition", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::UI_Subsystem_Core_eventGetViewportPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::UI_Subsystem_Core_eventGetViewportPosition_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics
	{
		struct UI_Subsystem_Core_eventGetViewportSize_Parms
		{
			FVector2D size;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_size;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::NewProp_size = { "size", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetViewportSize_Parms, size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventGetViewportSize_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventGetViewportSize_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::NewProp_size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetViewportSize", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::UI_Subsystem_Core_eventGetViewportSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::UI_Subsystem_Core_eventGetViewportSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics
	{
		struct UI_Subsystem_Core_eventGetWindowMonitorIndex_Parms
		{
			UUserWidget* userWidget;
			int32 monitorIndex;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FIntPropertyParams NewProp_monitorIndex;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetWindowMonitorIndex_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_monitorIndex = { "monitorIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventGetWindowMonitorIndex_Parms, monitorIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventGetWindowMonitorIndex_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventGetWindowMonitorIndex_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_monitorIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Gets monitor index of window showing userWidget\n\x09*  \\param userWidget UserWidget to find monitor index\n\x09*  \\param monitorIndex Populated with monitorIndex if function returns true\n\x09*  \\return True if userWidget is shown in a window and no errors getting the monitor index\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Gets monitor index of window showing userWidget\n      *  \\param userWidget UserWidget to find monitor index\n      *  \\param monitorIndex Populated with monitorIndex if function returns true\n      *  \\return True if userWidget is shown in a window and no errors getting the monitor index" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "GetWindowMonitorIndex", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::UI_Subsystem_Core_eventGetWindowMonitorIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::UI_Subsystem_Core_eventGetWindowMonitorIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics
	{
		struct UI_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms
		{
			EHardwareInterfaceMode newMode;
			EHardwareInterfaceMode previousMode;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_newMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newMode;
		static const UECodeGen_Private::FBytePropertyParams NewProp_previousMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_previousMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode = { "newMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms, newMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode = { "previousMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms, previousMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "HandleHardwareInterfaceModeChanged", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::UI_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::UI_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics
	{
		struct UI_Subsystem_Core_eventMoveUserWidgetToWorldLocation_Parms
		{
			UUserWidget* userWidget;
			FVector worldLocation;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventMoveUserWidgetToWorldLocation_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_worldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_worldLocation = { "worldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventMoveUserWidgetToWorldLocation_Parms, worldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_worldLocation_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_worldLocation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::NewProp_worldLocation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "MoveUserWidgetToWorldLocation", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::UI_Subsystem_Core_eventMoveUserWidgetToWorldLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::UI_Subsystem_Core_eventMoveUserWidgetToWorldLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics
	{
		struct UI_Subsystem_Core_eventMoveWidgetToNewTabContainer_Parms
		{
			UUserWidget* userWidget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventMoveWidgetToNewTabContainer_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::NewProp_userWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "MoveWidgetToNewTabContainer", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::UI_Subsystem_Core_eventMoveWidgetToNewTabContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::UI_Subsystem_Core_eventMoveWidgetToNewTabContainer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics
	{
		struct UI_Subsystem_Core_eventMoveWindowToMonitor_Parms
		{
			UUserWidget* userWidget;
			int32 monitorIndex;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FIntPropertyParams NewProp_monitorIndex;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventMoveWindowToMonitor_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_monitorIndex = { "monitorIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventMoveWindowToMonitor_Parms, monitorIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventMoveWindowToMonitor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventMoveWindowToMonitor_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_monitorIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Moves window showing userWidget to monitor with specified monitorIndex\n\x09*  \\param userWidget UserWidget to move\n\x09*  \\param monitorIndex Index of monitor to move window showing userWidget\n\x09*  \\return True if userWidget is shown in a window and no errors moving window to monitor\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Moves window showing userWidget to monitor with specified monitorIndex\n      *  \\param userWidget UserWidget to move\n      *  \\param monitorIndex Index of monitor to move window showing userWidget\n      *  \\return True if userWidget is shown in a window and no errors moving window to monitor" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "MoveWindowToMonitor", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::UI_Subsystem_Core_eventMoveWindowToMonitor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::UI_Subsystem_Core_eventMoveWindowToMonitor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics
	{
		struct UI_Subsystem_Core_eventOpenInPopoutWindow_Parms
		{
			UUserWidget* userWidget;
			FTabContainerSettings tabContainerSettings;
			FOpenUserWidgetWindowSettings windowSettings;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_tabContainerSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_windowSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_windowSettings;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInPopoutWindow_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_tabContainerSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_tabContainerSettings = { "tabContainerSettings", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInPopoutWindow_Parms, tabContainerSettings), Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_tabContainerSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_tabContainerSettings_MetaData) }; // 2140638768
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_windowSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_windowSettings = { "windowSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInPopoutWindow_Parms, windowSettings), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_windowSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_windowSettings_MetaData) }; // 147903675
	void Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventOpenInPopoutWindow_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventOpenInPopoutWindow_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_tabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_windowSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenInPopoutWindow", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::UI_Subsystem_Core_eventOpenInPopoutWindow_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::UI_Subsystem_Core_eventOpenInPopoutWindow_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics
	{
		struct UI_Subsystem_Core_eventOpenInPopoutWindowByClass_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			FTabContainerSettings tabContainerSettings;
			FOpenUserWidgetWindowSettings windowSettings;
			UUserWidget* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_tabContainerSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_windowSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_windowSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInPopoutWindowByClass_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_tabContainerSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_tabContainerSettings = { "tabContainerSettings", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInPopoutWindowByClass_Parms, tabContainerSettings), Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_tabContainerSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_tabContainerSettings_MetaData) }; // 2140638768
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_windowSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_windowSettings = { "windowSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInPopoutWindowByClass_Parms, windowSettings), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_windowSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_windowSettings_MetaData) }; // 147903675
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInPopoutWindowByClass_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_tabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_windowSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::Function_MetaDataParams[] = {
		{ "DeterminesOutputType", "userWidgetClass" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenInPopoutWindowByClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::UI_Subsystem_Core_eventOpenInPopoutWindowByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::UI_Subsystem_Core_eventOpenInPopoutWindowByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics
	{
		struct UI_Subsystem_Core_eventOpenInViewport_Parms
		{
			UUserWidget* userWidget;
			FTabContainerSettings tabContainerSettings;
			FOpenUserWidgetViewportSettings viewportSettings;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_tabContainerSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_viewportSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_viewportSettings;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInViewport_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_tabContainerSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_tabContainerSettings = { "tabContainerSettings", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInViewport_Parms, tabContainerSettings), Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_tabContainerSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_tabContainerSettings_MetaData) }; // 2140638768
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_viewportSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_viewportSettings = { "viewportSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInViewport_Parms, viewportSettings), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_viewportSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_viewportSettings_MetaData) }; // 990075112
	void Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventOpenInViewport_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventOpenInViewport_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_tabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_viewportSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenInViewport", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::UI_Subsystem_Core_eventOpenInViewport_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::UI_Subsystem_Core_eventOpenInViewport_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics
	{
		struct UI_Subsystem_Core_eventOpenInViewportByClass_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			FTabContainerSettings tabContainerSettings;
			FOpenUserWidgetViewportSettings viewportSettings;
			UUserWidget* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_tabContainerSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_viewportSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_viewportSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInViewportByClass_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_tabContainerSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_tabContainerSettings = { "tabContainerSettings", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInViewportByClass_Parms, tabContainerSettings), Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_tabContainerSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_tabContainerSettings_MetaData) }; // 2140638768
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_viewportSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_viewportSettings = { "viewportSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInViewportByClass_Parms, viewportSettings), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_viewportSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_viewportSettings_MetaData) }; // 990075112
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInViewportByClass_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_tabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_viewportSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::Function_MetaDataParams[] = {
		{ "DeterminesOutputType", "userWidgetClass" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenInViewportByClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::UI_Subsystem_Core_eventOpenInViewportByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::UI_Subsystem_Core_eventOpenInViewportByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics
	{
		struct UI_Subsystem_Core_eventOpenInWorld_Parms
		{
			UUserWidget* userWidget;
			FTabContainerSettings tabContainerSettings;
			FOpenUserWidgetWorldSettings worldSettings;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_tabContainerSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldSettings;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInWorld_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_tabContainerSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_tabContainerSettings = { "tabContainerSettings", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInWorld_Parms, tabContainerSettings), Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_tabContainerSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_tabContainerSettings_MetaData) }; // 2140638768
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_worldSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_worldSettings = { "worldSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInWorld_Parms, worldSettings), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_worldSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_worldSettings_MetaData) }; // 3485812593
	void Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventOpenInWorld_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventOpenInWorld_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_tabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_worldSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenInWorld", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::UI_Subsystem_Core_eventOpenInWorld_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::UI_Subsystem_Core_eventOpenInWorld_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics
	{
		struct UI_Subsystem_Core_eventOpenInWorldByClass_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			FTabContainerSettings tabContainerSettings;
			FOpenUserWidgetWorldSettings worldSettings;
			UUserWidget* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_tabContainerSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInWorldByClass_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_tabContainerSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_tabContainerSettings = { "tabContainerSettings", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInWorldByClass_Parms, tabContainerSettings), Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_tabContainerSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_tabContainerSettings_MetaData) }; // 2140638768
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_worldSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_worldSettings = { "worldSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInWorldByClass_Parms, worldSettings), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_worldSettings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_worldSettings_MetaData) }; // 3485812593
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenInWorldByClass_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_tabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_worldSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::Function_MetaDataParams[] = {
		{ "DeterminesOutputType", "userWidgetClass" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenInWorldByClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::UI_Subsystem_Core_eventOpenInWorldByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::UI_Subsystem_Core_eventOpenInWorldByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics
	{
		struct UI_Subsystem_Core_eventOpenWithDefaults_Parms
		{
			UUserWidget* userWidget;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenWithDefaults_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_userWidget_MetaData) };
	void Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_Core_eventOpenWithDefaults_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_Core_eventOpenWithDefaults_Parms), &Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenWithDefaults", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::UI_Subsystem_Core_eventOpenWithDefaults_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::UI_Subsystem_Core_eventOpenWithDefaults_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics
	{
		struct UI_Subsystem_Core_eventOpenWithDefaultsByClass_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			UUserWidget* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenWithDefaultsByClass_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventOpenWithDefaultsByClass_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Opens user widget using subsystem defaults\n\x09*/" },
#endif
		{ "DeterminesOutputType", "userWidgetClass" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Opens user widget using subsystem defaults" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "OpenWithDefaultsByClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::UI_Subsystem_Core_eventOpenWithDefaultsByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::UI_Subsystem_Core_eventOpenWithDefaultsByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics
	{
		struct UI_Subsystem_Core_eventRemoveUserWidgetFromTabContainer_Parms
		{
			UUserWidget* userWidget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventRemoveUserWidgetFromTabContainer_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::NewProp_userWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Removes userWidget from it's tab container (if it's in a tab container)\n\x09*  \\param userWidget UserWidget to remove from it's tab container\n\x09*  \\note This calls userWidget->RemoveFromParent(), so keep a reference to it if you want to open later.  Otherwise it will be cleaned up by garbage collection.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Removes userWidget from it's tab container (if it's in a tab container)\n      *  \\param userWidget UserWidget to remove from it's tab container\n      *  \\note This calls userWidget->RemoveFromParent(), so keep a reference to it if you want to open later.  Otherwise it will be cleaned up by garbage collection." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "RemoveUserWidgetFromTabContainer", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::UI_Subsystem_Core_eventRemoveUserWidgetFromTabContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::UI_Subsystem_Core_eventRemoveUserWidgetFromTabContainer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics
	{
		struct UI_Subsystem_Core_eventSetUserWidgetClassWorldSettings_Parms
		{
			TSubclassOf<UUserWidget>  userWidgetClass;
			FOpenUserWidgetWorldSettings settings;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_userWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_settings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_settings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::NewProp_userWidgetClass = { "userWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetClassWorldSettings_Parms, userWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::NewProp_settings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::NewProp_settings = { "settings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetClassWorldSettings_Parms, settings), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::NewProp_settings_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::NewProp_settings_MetaData) }; // 3485812593
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::NewProp_userWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::NewProp_settings,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief null userWidgetClass sets DefaultWorldSetttings to settings\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief null userWidgetClass sets DefaultWorldSetttings to settings" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "SetUserWidgetClassWorldSettings", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::UI_Subsystem_Core_eventSetUserWidgetClassWorldSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::UI_Subsystem_Core_eventSetUserWidgetClassWorldSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics
	{
		struct UI_Subsystem_Core_eventSetUserWidgetDefaultWorldUIActor_Parms
		{
			UUserWidget* userWidget;
			AActor* worldUIActor;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_worldUIActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetDefaultWorldUIActor_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::NewProp_worldUIActor = { "worldUIActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetDefaultWorldUIActor_Parms, worldUIActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::NewProp_worldUIActor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "SetUserWidgetDefaultWorldUIActor", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::UI_Subsystem_Core_eventSetUserWidgetDefaultWorldUIActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::UI_Subsystem_Core_eventSetUserWidgetDefaultWorldUIActor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics
	{
		struct UI_Subsystem_Core_eventSetUserWidgetPosition_Parms
		{
			UUserWidget* userWidget;
			FVector2D position;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_position_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_position;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetPosition_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_position = { "position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetPosition_Parms, position), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_position_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_position_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::NewProp_position,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "SetUserWidgetPosition", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::UI_Subsystem_Core_eventSetUserWidgetPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::UI_Subsystem_Core_eventSetUserWidgetPosition_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics
	{
		struct UI_Subsystem_Core_eventSetUserWidgetScale_Parms
		{
			UUserWidget* userWidget;
			FVector2D scale;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_scale_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_scale;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetScale_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_scale = { "scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetScale_Parms, scale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_scale_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_scale_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::NewProp_scale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "SetUserWidgetScale", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::UI_Subsystem_Core_eventSetUserWidgetScale_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::UI_Subsystem_Core_eventSetUserWidgetScale_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics
	{
		struct UI_Subsystem_Core_eventSetUserWidgetSize_Parms
		{
			UUserWidget* userWidget;
			FVector2D size;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_size_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_size;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetSize_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_size_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_size = { "size", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetSize_Parms, size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_size_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_size_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::NewProp_size,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "SetUserWidgetSize", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::UI_Subsystem_Core_eventSetUserWidgetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::UI_Subsystem_Core_eventSetUserWidgetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics
	{
		struct UI_Subsystem_Core_eventSetUserWidgetTabContainer_Parms
		{
			UUserWidget* userWidget;
			UUserWidget* tabContainer;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tabContainer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tabContainer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetTabContainer_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_userWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_tabContainer_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_tabContainer = { "tabContainer", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventSetUserWidgetTabContainer_Parms, tabContainer), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_tabContainer_MetaData), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_tabContainer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_userWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::NewProp_tabContainer,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "SetUserWidgetTabContainer", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::UI_Subsystem_Core_eventSetUserWidgetTabContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::UI_Subsystem_Core_eventSetUserWidgetTabContainer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics
	{
		struct UI_Subsystem_Core_eventUpdateSettings_Parms
		{
			TSubclassOf<UUI_Subsystem_Core_Settings>  settingsClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_settingsClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::NewProp_settingsClass = { "settingsClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_Core_eventUpdateSettings_Parms, settingsClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUI_Subsystem_Core_Settings_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::NewProp_settingsClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Convenience function to set class variables\n\x09* \\param settings Settings object to use to set class variables\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Convenience function to set class variables\n* \\param settings Settings object to use to set class variables" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_Core, nullptr, "UpdateSettings", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::UI_Subsystem_Core_eventUpdateSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::UI_Subsystem_Core_eventUpdateSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_Subsystem_Core);
	UClass* Z_Construct_UClass_UUI_Subsystem_Core_NoRegister()
	{
		return UUI_Subsystem_Core::StaticClass();
	}
	struct Z_Construct_UClass_UUI_Subsystem_Core_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnUserWidgetClosed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUserWidgetClosed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnUserWidgetOpened_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUserWidgetOpened;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultViewportSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultViewportSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWorldSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultWorldSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWindowSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultWindowSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultTabContainerSettings;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultOpenBehavior_ValueProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultOpenBehavior_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultOpenBehavior_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultOpenBehavior_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultOpenBehavior_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DefaultOpenBehavior;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDefaultAllowMultipleInstances_MetaData[];
#endif
		static void NewProp_bDefaultAllowMultipleInstances_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefaultAllowMultipleInstances;
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultClassViewportSettings_ValueProp;
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultClassViewportSettings_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultClassViewportSettings_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DefaultClassViewportSettings;
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultClassWorldSettings_ValueProp;
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultClassWorldSettings_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultClassWorldSettings_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DefaultClassWorldSettings;
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultClassWindowSettings_ValueProp;
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultClassWindowSettings_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultClassWindowSettings_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DefaultClassWindowSettings;
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultClassTabContainerSettings_ValueProp;
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultClassTabContainerSettings_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultClassTabContainerSettings_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DefaultClassTabContainerSettings;
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultClassOpenBehavior_ValueProp;
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultClassOpenBehavior_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultClassOpenBehavior_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DefaultClassOpenBehavior;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_Subsystem_Core_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_Subsystem_Core_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_CloseAllWidgetsByClass, "CloseAllWidgetsByClass" }, // 949577112
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_CloseTabContainer, "CloseTabContainer" }, // 994285050
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_CloseUserWidget, "CloseUserWidget" }, // 2430509139
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetTabsInTabContainer, "GetTabsInTabContainer" }, // 2237254531
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetClassWorldSettings, "GetUserWidgetClassWorldSettings" }, // 2695855376
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetPosition, "GetUserWidgetPosition" }, // 3354433780
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetsByClass, "GetUserWidgetsByClass" }, // 2745111380
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetScale, "GetUserWidgetScale" }, // 3752909737
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetSize, "GetUserWidgetSize" }, // 3770314505
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetTabContainer, "GetUserWidgetTabContainer" }, // 492796350
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetUIType, "GetUserWidgetUIType" }, // 74505126
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetUserWidgetWorldUIActor, "GetUserWidgetWorldUIActor" }, // 2565264606
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportMonitorIndex, "GetViewportMonitorIndex" }, // 4229960463
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportPosition, "GetViewportPosition" }, // 215465363
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetViewportSize, "GetViewportSize" }, // 322753253
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_GetWindowMonitorIndex, "GetWindowMonitorIndex" }, // 3145637723
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_HandleHardwareInterfaceModeChanged, "HandleHardwareInterfaceModeChanged" }, // 3771326299
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_MoveUserWidgetToWorldLocation, "MoveUserWidgetToWorldLocation" }, // 473329986
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_MoveWidgetToNewTabContainer, "MoveWidgetToNewTabContainer" }, // 1656587167
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_MoveWindowToMonitor, "MoveWindowToMonitor" }, // 3400670131
		{ &Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature, "OnUserWidgetClosed__DelegateSignature" }, // 1755769624
		{ &Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature, "OnUserWidgetOpened__DelegateSignature" }, // 2784494268
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindow, "OpenInPopoutWindow" }, // 1129363656
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInPopoutWindowByClass, "OpenInPopoutWindowByClass" }, // 2620462798
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewport, "OpenInViewport" }, // 3371031669
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInViewportByClass, "OpenInViewportByClass" }, // 1822595016
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorld, "OpenInWorld" }, // 4058530196
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenInWorldByClass, "OpenInWorldByClass" }, // 1345032465
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaults, "OpenWithDefaults" }, // 952585607
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_OpenWithDefaultsByClass, "OpenWithDefaultsByClass" }, // 505281065
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_RemoveUserWidgetFromTabContainer, "RemoveUserWidgetFromTabContainer" }, // 715702968
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetClassWorldSettings, "SetUserWidgetClassWorldSettings" }, // 4008848343
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetDefaultWorldUIActor, "SetUserWidgetDefaultWorldUIActor" }, // 2499938568
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetPosition, "SetUserWidgetPosition" }, // 1395666309
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetScale, "SetUserWidgetScale" }, // 2570740702
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetSize, "SetUserWidgetSize" }, // 2078082275
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_SetUserWidgetTabContainer, "SetUserWidgetTabContainer" }, // 3465711322
		{ &Z_Construct_UFunction_UUI_Subsystem_Core_UpdateSettings, "UpdateSettings" }, // 3721008339
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/UI_Subsystem_Core.h" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetClosed_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetClosed = { "OnUserWidgetClosed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, OnUserWidgetClosed), Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetClosed_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetClosed_MetaData) }; // 1755769624
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetOpened_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetOpened = { "OnUserWidgetOpened", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, OnUserWidgetOpened), Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetOpened__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetOpened_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetOpened_MetaData) }; // 2784494268
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultViewportSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* default viewport settings; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "default viewport settings; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultViewportSettings = { "DefaultViewportSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultViewportSettings), Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultViewportSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultViewportSettings_MetaData) }; // 990075112
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWorldSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* default world settings; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "default world settings; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWorldSettings = { "DefaultWorldSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultWorldSettings), Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWorldSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWorldSettings_MetaData) }; // 3485812593
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWindowSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* default window settings; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "default window settings; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWindowSettings = { "DefaultWindowSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultWindowSettings), Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWindowSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWindowSettings_MetaData) }; // 147903675
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultTabContainerSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* default tab settings; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "default tab settings; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultTabContainerSettings = { "DefaultTabContainerSettings", nullptr, (EPropertyFlags)0x0010008000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultTabContainerSettings), Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultTabContainerSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultTabContainerSettings_MetaData) }; // 2140638768
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_ValueProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_ValueProp = { "DefaultOpenBehavior", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UEnum_VH_UI_EUIType, METADATA_PARAMS(0, nullptr) }; // 3765397352
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_Key_KeyProp = { "DefaultOpenBehavior_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* holds default opening behavior based on hardware interface mode; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "holds default opening behavior based on hardware interface mode; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior = { "DefaultOpenBehavior", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultOpenBehavior), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_MetaData) }; // 2688149405 3765397352
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_bDefaultAllowMultipleInstances_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if true, allows multiple instances of a widget from a particular class */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if true, allows multiple instances of a widget from a particular class" },
#endif
	};
#endif
	void Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_bDefaultAllowMultipleInstances_SetBit(void* Obj)
	{
		((UUI_Subsystem_Core*)Obj)->bDefaultAllowMultipleInstances = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_bDefaultAllowMultipleInstances = { "bDefaultAllowMultipleInstances", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UUI_Subsystem_Core), &Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_bDefaultAllowMultipleInstances_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_bDefaultAllowMultipleInstances_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_bDefaultAllowMultipleInstances_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings_ValueProp = { "DefaultClassViewportSettings", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings, METADATA_PARAMS(0, nullptr) }; // 990075112
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings_Key_KeyProp = { "DefaultClassViewportSettings_Key", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* overrides DefaultViewportSettings for specific classes; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "overrides DefaultViewportSettings for specific classes; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings = { "DefaultClassViewportSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultClassViewportSettings), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings_MetaData) }; // 990075112
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings_ValueProp = { "DefaultClassWorldSettings", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings, METADATA_PARAMS(0, nullptr) }; // 3485812593
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings_Key_KeyProp = { "DefaultClassWorldSettings_Key", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* overrides DefaultWorldSettings for specific classes; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "overrides DefaultWorldSettings for specific classes; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings = { "DefaultClassWorldSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultClassWorldSettings), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings_MetaData) }; // 3485812593
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings_ValueProp = { "DefaultClassWindowSettings", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings, METADATA_PARAMS(0, nullptr) }; // 147903675
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings_Key_KeyProp = { "DefaultClassWindowSettings_Key", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* overrides DefaultWindowSettings for specific classes; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "overrides DefaultWindowSettings for specific classes; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings = { "DefaultClassWindowSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultClassWindowSettings), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings_MetaData) }; // 147903675
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings_ValueProp = { "DefaultClassTabContainerSettings", nullptr, (EPropertyFlags)0x0000008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FTabContainerSettings, METADATA_PARAMS(0, nullptr) }; // 2140638768
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings_Key_KeyProp = { "DefaultClassTabContainerSettings_Key", nullptr, (EPropertyFlags)0x0004008000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* overrides DefaultTabContainerSettings for specific classes; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "overrides DefaultTabContainerSettings for specific classes; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings = { "DefaultClassTabContainerSettings", nullptr, (EPropertyFlags)0x0010008000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultClassTabContainerSettings), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings_MetaData) }; // 2140638768
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior_ValueProp = { "DefaultClassOpenBehavior", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOpenBehavior, METADATA_PARAMS(0, nullptr) }; // 3824658793
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior_Key_KeyProp = { "DefaultClassOpenBehavior_Key", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior_MetaData[] = {
		{ "Category", "UI_Subsystem_Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* overrides DefaultOpenBehavior for specific classes; used by the OpenWithDefaults functions */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "overrides DefaultOpenBehavior for specific classes; used by the OpenWithDefaults functions" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior = { "DefaultClassOpenBehavior", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_Core, DefaultClassOpenBehavior), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior_MetaData), Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior_MetaData) }; // 3824658793
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUI_Subsystem_Core_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetClosed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_OnUserWidgetOpened,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultViewportSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWorldSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultWindowSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultTabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_ValueProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultOpenBehavior,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_bDefaultAllowMultipleInstances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassViewportSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWorldSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassWindowSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassTabContainerSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_Core_Statics::NewProp_DefaultClassOpenBehavior,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_Subsystem_Core_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_Subsystem_Core>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_Subsystem_Core_Statics::ClassParams = {
		&UUI_Subsystem_Core::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UUI_Subsystem_Core_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::Class_MetaDataParams), Z_Construct_UClass_UUI_Subsystem_Core_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_Core_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UUI_Subsystem_Core()
	{
		if (!Z_Registration_Info_UClass_UUI_Subsystem_Core.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_Subsystem_Core.OuterSingleton, Z_Construct_UClass_UUI_Subsystem_Core_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_Subsystem_Core.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UUI_Subsystem_Core>()
	{
		return UUI_Subsystem_Core::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_Subsystem_Core);
	UUI_Subsystem_Core::~UUI_Subsystem_Core() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::EnumInfo[] = {
		{ EUIType_StaticEnum, TEXT("EUIType"), &Z_Registration_Info_UEnum_EUIType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3765397352U) },
		{ ETabContainerType_StaticEnum, TEXT("ETabContainerType"), &Z_Registration_Info_UEnum_ETabContainerType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2853082499U) },
		{ EBlueprintWindowSizingRule_StaticEnum, TEXT("EBlueprintWindowSizingRule"), &Z_Registration_Info_UEnum_EBlueprintWindowSizingRule, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2700173059U) },
		{ EBlueprintWindowActivationPolicy_StaticEnum, TEXT("EBlueprintWindowActivationPolicy"), &Z_Registration_Info_UEnum_EBlueprintWindowActivationPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3288275011U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::ScriptStructInfo[] = {
		{ FOpenBehavior::StaticStruct, Z_Construct_UScriptStruct_FOpenBehavior_Statics::NewStructOps, TEXT("OpenBehavior"), &Z_Registration_Info_UScriptStruct_OpenBehavior, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOpenBehavior), 3824658793U) },
		{ FOpenUserWidgetViewportSettings::StaticStruct, Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics::NewStructOps, TEXT("OpenUserWidgetViewportSettings"), &Z_Registration_Info_UScriptStruct_OpenUserWidgetViewportSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOpenUserWidgetViewportSettings), 990075112U) },
		{ FOpenUserWidgetWorldSettings::StaticStruct, Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics::NewStructOps, TEXT("OpenUserWidgetWorldSettings"), &Z_Registration_Info_UScriptStruct_OpenUserWidgetWorldSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOpenUserWidgetWorldSettings), 3485812593U) },
		{ FOpenUserWidgetWindowSettings::StaticStruct, Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics::NewStructOps, TEXT("OpenUserWidgetWindowSettings"), &Z_Registration_Info_UScriptStruct_OpenUserWidgetWindowSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOpenUserWidgetWindowSettings), 147903675U) },
		{ FTabContainerSettings::StaticStruct, Z_Construct_UScriptStruct_FTabContainerSettings_Statics::NewStructOps, TEXT("TabContainerSettings"), &Z_Registration_Info_UScriptStruct_TabContainerSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTabContainerSettings), 2140638768U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_Subsystem_Core, UUI_Subsystem_Core::StaticClass, TEXT("UUI_Subsystem_Core"), &Z_Registration_Info_UClass_UUI_Subsystem_Core, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_Subsystem_Core), 3427727275U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_1833821852(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
