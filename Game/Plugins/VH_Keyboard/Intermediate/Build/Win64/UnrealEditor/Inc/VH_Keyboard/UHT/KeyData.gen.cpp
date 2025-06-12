// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Examples/Public/KeyData.h"
#include "InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKeyData() {}
// Cross Module References
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	UPackage* Z_Construct_UPackage__Script_VH_Keyboard();
	VH_KEYBOARD_API UScriptStruct* Z_Construct_UScriptStruct_FKeyData();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_KeyData;
class UScriptStruct* FKeyData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_KeyData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_KeyData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FKeyData, (UObject*)Z_Construct_UPackage__Script_VH_Keyboard(), TEXT("KeyData"));
	}
	return Z_Registration_Info_UScriptStruct_KeyData.OuterSingleton;
}
template<> VH_KEYBOARD_API UScriptStruct* StaticStruct<FKeyData>()
{
	return FKeyData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FKeyData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Key;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSendAsString_MetaData[];
#endif
		static void NewProp_bSendAsString_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSendAsString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_KeyString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShiftKeyString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ShiftKeyString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Examples/Public/KeyData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FKeyData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FKeyData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_Key_MetaData[] = {
		{ "Category", "KeyData" },
		{ "ModuleRelativePath", "Examples/Public/KeyData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKeyData, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_Key_MetaData), Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_Key_MetaData) }; // 46000949
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_bSendAsString_MetaData[] = {
		{ "Category", "KeyData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if true, key sent as characters (e.g. 'p'); if false, key sent as command (e.g. [enter] or [leftArrow] */" },
#endif
		{ "ModuleRelativePath", "Examples/Public/KeyData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if true, key sent as characters (e.g. 'p'); if false, key sent as command (e.g. [enter] or [leftArrow]" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_bSendAsString_SetBit(void* Obj)
	{
		((FKeyData*)Obj)->bSendAsString = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_bSendAsString = { "bSendAsString", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FKeyData), &Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_bSendAsString_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_bSendAsString_MetaData), Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_bSendAsString_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_KeyString_MetaData[] = {
		{ "Category", "KeyData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* string to send when key is pressed without shift; if empty, defaults to Key.GetDisplayName().ToString().ToLower() */" },
#endif
		{ "ModuleRelativePath", "Examples/Public/KeyData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "string to send when key is pressed without shift; if empty, defaults to Key.GetDisplayName().ToString().ToLower()" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_KeyString = { "KeyString", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKeyData, KeyString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_KeyString_MetaData), Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_KeyString_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_ShiftKeyString_MetaData[] = {
		{ "Category", "KeyData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* string to send when key is pressed with shift; if empty, defaults to Key.GetDisplayName() */" },
#endif
		{ "ModuleRelativePath", "Examples/Public/KeyData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "string to send when key is pressed with shift; if empty, defaults to Key.GetDisplayName()" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_ShiftKeyString = { "ShiftKeyString", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKeyData, ShiftKeyString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_ShiftKeyString_MetaData), Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_ShiftKeyString_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FKeyData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_bSendAsString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_KeyString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKeyData_Statics::NewProp_ShiftKeyString,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FKeyData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Keyboard,
		nullptr,
		&NewStructOps,
		"KeyData",
		Z_Construct_UScriptStruct_FKeyData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyData_Statics::PropPointers),
		sizeof(FKeyData),
		alignof(FKeyData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FKeyData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKeyData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FKeyData()
	{
		if (!Z_Registration_Info_UScriptStruct_KeyData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_KeyData.InnerSingleton, Z_Construct_UScriptStruct_FKeyData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_KeyData.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_KeyData_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_KeyData_h_Statics::ScriptStructInfo[] = {
		{ FKeyData::StaticStruct, Z_Construct_UScriptStruct_FKeyData_Statics::NewStructOps, TEXT("KeyData"), &Z_Registration_Info_UScriptStruct_KeyData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FKeyData), 941138177U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_KeyData_h_1705188621(TEXT("/Script/VH_Keyboard"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_KeyData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_KeyData_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
