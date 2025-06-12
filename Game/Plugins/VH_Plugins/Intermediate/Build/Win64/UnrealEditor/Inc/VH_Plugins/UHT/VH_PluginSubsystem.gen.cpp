// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_Plugins/Public/VH_PluginSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Styling/SlateBrush.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_PluginSubsystem() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
	UPackage* Z_Construct_UPackage__Script_VH_Plugins();
	VH_PLUGINS_API UClass* Z_Construct_UClass_UVH_PluginSubsystem();
	VH_PLUGINS_API UClass* Z_Construct_UClass_UVH_PluginSubsystem_NoRegister();
	VH_PLUGINS_API UEnum* Z_Construct_UEnum_VH_Plugins_EPluginLoadError();
	VH_PLUGINS_API UScriptStruct* Z_Construct_UScriptStruct_FPluginInfo();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPluginLoadError;
	static UEnum* EPluginLoadError_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPluginLoadError.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPluginLoadError.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Plugins_EPluginLoadError, (UObject*)Z_Construct_UPackage__Script_VH_Plugins(), TEXT("EPluginLoadError"));
		}
		return Z_Registration_Info_UEnum_EPluginLoadError.OuterSingleton;
	}
	template<> VH_PLUGINS_API UEnum* StaticEnum<EPluginLoadError>()
	{
		return EPluginLoadError_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::Enumerators[] = {
		{ "EPluginLoadError::NoError", (int64)EPluginLoadError::NoError },
		{ "EPluginLoadError::VersionMismatch", (int64)EPluginLoadError::VersionMismatch },
		{ "EPluginLoadError::UnknownError", (int64)EPluginLoadError::UnknownError },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Holds basic information for each plugin\n */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
		{ "NoError.Name", "EPluginLoadError::NoError" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Holds basic information for each plugin" },
#endif
		{ "UnknownError.Name", "EPluginLoadError::UnknownError" },
		{ "VersionMismatch.Name", "EPluginLoadError::VersionMismatch" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Plugins,
		nullptr,
		"EPluginLoadError",
		"EPluginLoadError",
		Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Plugins_EPluginLoadError()
	{
		if (!Z_Registration_Info_UEnum_EPluginLoadError.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPluginLoadError.InnerSingleton, Z_Construct_UEnum_VH_Plugins_EPluginLoadError_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPluginLoadError.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PluginInfo;
class UScriptStruct* FPluginInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PluginInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PluginInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPluginInfo, (UObject*)Z_Construct_UPackage__Script_VH_Plugins(), TEXT("PluginInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PluginInfo.OuterSingleton;
}
template<> VH_PLUGINS_API UScriptStruct* StaticStruct<FPluginInfo>()
{
	return FPluginInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPluginInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_PluginName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PluginPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_PluginPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DescriptorPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DescriptorPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FriendlyName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FriendlyName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Icon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VersionNum_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_VersionNum;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VersionName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_VersionName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Author_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Author;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[];
#endif
		static void NewProp_bEnabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
		static const UECodeGen_Private::FBytePropertyParams NewProp_PluginError_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PluginError_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_PluginError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSlatedForDeletion_MetaData[];
#endif
		static void NewProp_bSlatedForDeletion_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSlatedForDeletion;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDirty_MetaData[];
#endif
		static void NewProp_bDirty_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDirty;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPluginInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPluginInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginName_MetaData[] = {
		{ "Category", "PluginInfo" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginName = { "PluginName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, PluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginName_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginPath_MetaData[] = {
		{ "Category", "PluginInfo" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginPath = { "PluginPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, PluginPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginPath_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_DescriptorPath_MetaData[] = {
		{ "Category", "PluginInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// path to plugin's root dir; we don't want the user changing this.\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "path to plugin's root dir; we don't want the user changing this." },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_DescriptorPath = { "DescriptorPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, DescriptorPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_DescriptorPath_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_DescriptorPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_FriendlyName_MetaData[] = {
		{ "Category", "PluginInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Longer form of the name, does not need to match class name of the plugin\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Longer form of the name, does not need to match class name of the plugin" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_FriendlyName = { "FriendlyName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, FriendlyName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_FriendlyName_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_FriendlyName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "PluginInfo" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, Description), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Description_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Description_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "PluginInfo" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, Icon), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Icon_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Icon_MetaData) }; // 899956612
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionNum_MetaData[] = {
		{ "Category", "PluginInfo" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionNum = { "VersionNum", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, VersionNum), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionNum_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionNum_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionName_MetaData[] = {
		{ "Category", "PluginInfo" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionName = { "VersionName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, VersionName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionName_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Author_MetaData[] = {
		{ "Category", "PluginInfo" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Author = { "Author", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, Author), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Author_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Author_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bEnabled_MetaData[] = {
		{ "Category", "PluginInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether this plugin is currently enabled\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this plugin is currently enabled" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bEnabled_SetBit(void* Obj)
	{
		((FPluginInfo*)Obj)->bEnabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginInfo), &Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bEnabled_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bEnabled_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginError_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginError_MetaData[] = {
		{ "Category", "PluginInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Reason why plugin was not loaded correctly.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reason why plugin was not loaded correctly." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginError = { "PluginError", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPluginInfo, PluginError), Z_Construct_UEnum_VH_Plugins_EPluginLoadError, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginError_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginError_MetaData) }; // 615494349
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bSlatedForDeletion_MetaData[] = {
		{ "Category", "PluginInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether this plugin should be deleted.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this plugin should be deleted." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bSlatedForDeletion_SetBit(void* Obj)
	{
		((FPluginInfo*)Obj)->bSlatedForDeletion = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bSlatedForDeletion = { "bSlatedForDeletion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginInfo), &Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bSlatedForDeletion_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bSlatedForDeletion_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bSlatedForDeletion_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bDirty_MetaData[] = {
		{ "Category", "PluginInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * if true, then we'll want to propagate the changes to the plugin descriptor (.uplugin) file.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if true, then we'll want to propagate the changes to the plugin descriptor (.uplugin) file." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bDirty_SetBit(void* Obj)
	{
		((FPluginInfo*)Obj)->bDirty = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bDirty = { "bDirty", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPluginInfo), &Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bDirty_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bDirty_MetaData), Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bDirty_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPluginInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_DescriptorPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_FriendlyName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Description,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Icon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionNum,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_VersionName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_Author,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bEnabled,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginError_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_PluginError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bSlatedForDeletion,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPluginInfo_Statics::NewProp_bDirty,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPluginInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Plugins,
		nullptr,
		&NewStructOps,
		"PluginInfo",
		Z_Construct_UScriptStruct_FPluginInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::PropPointers),
		sizeof(FPluginInfo),
		alignof(FPluginInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPluginInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPluginInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPluginInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PluginInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PluginInfo.InnerSingleton, Z_Construct_UScriptStruct_FPluginInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PluginInfo.InnerSingleton;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execHandleGenerateCrashLog)
	{
		P_GET_TARRAY_REF(FString,Z_Param_Out_logLines);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleGenerateCrashLog(Z_Param_Out_logLines);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execImportPlugin)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_importFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ImportPlugin(Z_Param_importFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execUpdateAllPlugins)
	{
		P_GET_UBOOL(Z_Param_bWithRestart);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAllPlugins(Z_Param_bWithRestart);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execUpdatePlugin)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->UpdatePlugin(Z_Param_Out_pluginName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execSetPluginAuthor)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_GET_PROPERTY(FStrProperty,Z_Param_pluginAuthor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPluginAuthor(Z_Param_Out_pluginName,Z_Param_pluginAuthor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execSetPluginVersion)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_GET_PROPERTY(FIntProperty,Z_Param_versionNum);
		P_GET_PROPERTY(FStrProperty,Z_Param_versionName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPluginVersion(Z_Param_Out_pluginName,Z_Param_versionNum,Z_Param_versionName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execSetPluginDescription)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_GET_PROPERTY(FStrProperty,Z_Param_pluginDescription);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPluginDescription(Z_Param_Out_pluginName,Z_Param_pluginDescription);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execSetPluginFriendlyName)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_GET_PROPERTY(FStrProperty,Z_Param_friendlyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPluginFriendlyName(Z_Param_Out_pluginName,Z_Param_friendlyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execSetPluginDeletion)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_GET_UBOOL(Z_Param_bShouldDelete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPluginDeletion(Z_Param_Out_pluginName,Z_Param_bShouldDelete);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execSetPluginEnabled)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_GET_UBOOL(Z_Param_bIsEnabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPluginEnabled(Z_Param_Out_pluginName,Z_Param_bIsEnabled);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execSetPluginLoaded)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_GET_UBOOL(Z_Param_bIsLoaded);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetPluginLoaded(Z_Param_Out_pluginName,Z_Param_bIsLoaded);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execGetMapsInPlugin)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_packagePath);
		P_GET_TARRAY_REF(FName,Z_Param_Out_maps);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetMapsInPlugin(Z_Param_packagePath,Z_Param_Out_maps);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execGetClassesInPlugin)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_packageName);
		P_GET_TARRAY_REF(UClass*,Z_Param_Out_classes);
		P_GET_OBJECT(UClass,Z_Param_classFilter);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetClassesInPlugin(Z_Param_packageName,Z_Param_Out_classes,Z_Param_classFilter);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execGetRegisteredPlugins)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FName,FPluginInfo>*)Z_Param__Result=P_THIS->GetRegisteredPlugins();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execUnregisterPlugin)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->UnregisterPlugin(Z_Param_Out_pluginName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_PluginSubsystem::execRegisterPlugin)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_pluginName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RegisterPlugin(Z_Param_Out_pluginName);
		P_NATIVE_END;
	}
	void UVH_PluginSubsystem::StaticRegisterNativesUVH_PluginSubsystem()
	{
		UClass* Class = UVH_PluginSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetClassesInPlugin", &UVH_PluginSubsystem::execGetClassesInPlugin },
			{ "GetMapsInPlugin", &UVH_PluginSubsystem::execGetMapsInPlugin },
			{ "GetRegisteredPlugins", &UVH_PluginSubsystem::execGetRegisteredPlugins },
			{ "HandleGenerateCrashLog", &UVH_PluginSubsystem::execHandleGenerateCrashLog },
			{ "ImportPlugin", &UVH_PluginSubsystem::execImportPlugin },
			{ "RegisterPlugin", &UVH_PluginSubsystem::execRegisterPlugin },
			{ "SetPluginAuthor", &UVH_PluginSubsystem::execSetPluginAuthor },
			{ "SetPluginDeletion", &UVH_PluginSubsystem::execSetPluginDeletion },
			{ "SetPluginDescription", &UVH_PluginSubsystem::execSetPluginDescription },
			{ "SetPluginEnabled", &UVH_PluginSubsystem::execSetPluginEnabled },
			{ "SetPluginFriendlyName", &UVH_PluginSubsystem::execSetPluginFriendlyName },
			{ "SetPluginLoaded", &UVH_PluginSubsystem::execSetPluginLoaded },
			{ "SetPluginVersion", &UVH_PluginSubsystem::execSetPluginVersion },
			{ "UnregisterPlugin", &UVH_PluginSubsystem::execUnregisterPlugin },
			{ "UpdateAllPlugins", &UVH_PluginSubsystem::execUpdateAllPlugins },
			{ "UpdatePlugin", &UVH_PluginSubsystem::execUpdatePlugin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics
	{
		struct VH_PluginSubsystem_eventGetClassesInPlugin_Parms
		{
			FString packageName;
			TArray<UClass*> classes;
			UClass* classFilter;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_packageName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_packageName;
		static const UECodeGen_Private::FClassPropertyParams NewProp_classes_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_classes;
		static const UECodeGen_Private::FClassPropertyParams NewProp_classFilter;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_packageName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_packageName = { "packageName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventGetClassesInPlugin_Parms, packageName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_packageName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_packageName_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_classes_Inner = { "classes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_classes = { "classes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventGetClassesInPlugin_Parms, classes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_classFilter = { "classFilter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventGetClassesInPlugin_Parms, classFilter), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventGetClassesInPlugin_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventGetClassesInPlugin_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_packageName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_classes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_classes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_classFilter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get all subclasses of the specified class within the specified plugin\n\x09 * WARNING: This function does not seem to work as of 4.26 upgrade\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all subclasses of the specified class within the specified plugin\nWARNING: This function does not seem to work as of 4.26 upgrade" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "GetClassesInPlugin", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::VH_PluginSubsystem_eventGetClassesInPlugin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::VH_PluginSubsystem_eventGetClassesInPlugin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics
	{
		struct VH_PluginSubsystem_eventGetMapsInPlugin_Parms
		{
			FString packagePath;
			TArray<FName> maps;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_packagePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_packagePath;
		static const UECodeGen_Private::FNamePropertyParams NewProp_maps_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_maps;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_packagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_packagePath = { "packagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventGetMapsInPlugin_Parms, packagePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_packagePath_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_packagePath_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_maps_Inner = { "maps", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_maps = { "maps", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventGetMapsInPlugin_Parms, maps), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventGetMapsInPlugin_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventGetMapsInPlugin_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_packagePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_maps_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_maps,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  Returns All Maps in a Plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns All Maps in a Plugin." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "GetMapsInPlugin", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::VH_PluginSubsystem_eventGetMapsInPlugin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::VH_PluginSubsystem_eventGetMapsInPlugin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics
	{
		struct VH_PluginSubsystem_eventGetRegisteredPlugins_Parms
		{
			TMap<FName,FPluginInfo> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FPluginInfo, METADATA_PARAMS(0, nullptr) }; // 1325508982
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventGetRegisteredPlugins_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1325508982
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get all registered plugin info.\n\x09 *\n\x09 * @return Map of plugin name -> isLoaded.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all registered plugin info.\n\n@return Map of plugin name -> isLoaded." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "GetRegisteredPlugins", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::VH_PluginSubsystem_eventGetRegisteredPlugins_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::VH_PluginSubsystem_eventGetRegisteredPlugins_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics
	{
		struct VH_PluginSubsystem_eventHandleGenerateCrashLog_Parms
		{
			TArray<FString> logLines;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_logLines_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_logLines;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::NewProp_logLines_Inner = { "logLines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::NewProp_logLines = { "logLines", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventHandleGenerateCrashLog_Parms, logLines), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::NewProp_logLines_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::NewProp_logLines,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * \\brief Collects extra info (in JSON format) to be included in a crash log header.\n\x09 * \\param logLines The string array to which to append the extra crash info.\n\x09 * \\note logLines expects properly formatted JSON entries.\n\x09 * \\note *IMPORTANT* Must end by adding a final ',' to logLines.\n\x09 * \\note Currently unsupported for BP's.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Collects extra info (in JSON format) to be included in a crash log header.\n* \\param logLines The string array to which to append the extra crash info.\n* \\note logLines expects properly formatted JSON entries.\n* \\note *IMPORTANT* Must end by adding a final ',' to logLines.\n* \\note Currently unsupported for BP's." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "HandleGenerateCrashLog", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::VH_PluginSubsystem_eventHandleGenerateCrashLog_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::VH_PluginSubsystem_eventHandleGenerateCrashLog_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics
	{
		struct VH_PluginSubsystem_eventImportPlugin_Parms
		{
			FString importFile;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_importFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_importFile;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_importFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_importFile = { "importFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventImportPlugin_Parms, importFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_importFile_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_importFile_MetaData) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventImportPlugin_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventImportPlugin_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_importFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Import a new plugin zip from an external location.\n\x09 *\n\x09 * @param importFile full path to the plugin zip file\n\x09 * @return False if the unzip failed or if a uplugin file was not found in the zip.\n\x09 * @note Currently assumes all plugin files are in a zipped archive file, and they are auto-extracted to a local cache.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Import a new plugin zip from an external location.\n\n@param importFile full path to the plugin zip file\n@return False if the unzip failed or if a uplugin file was not found in the zip.\n@note Currently assumes all plugin files are in a zipped archive file, and they are auto-extracted to a local cache." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "ImportPlugin", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::VH_PluginSubsystem_eventImportPlugin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::VH_PluginSubsystem_eventImportPlugin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics
	{
		struct VH_PluginSubsystem_eventRegisterPlugin_Parms
		{
			FName pluginName;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventRegisterPlugin_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_pluginName_MetaData) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventRegisterPlugin_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventRegisterPlugin_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Register a new plugin.\n\x09 *\n\x09 * @param pluginName Name of new plugin to register.\n\x09 * @return False if 'pluginName' is already a registered plugin.\n\x09 * @note Looks up a plugin that has already been loaded by plugin manager and adds it to the plugin list and descriptor cache.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register a new plugin.\n\n@param pluginName Name of new plugin to register.\n@return False if 'pluginName' is already a registered plugin.\n@note Looks up a plugin that has already been loaded by plugin manager and adds it to the plugin list and descriptor cache." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "RegisterPlugin", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::VH_PluginSubsystem_eventRegisterPlugin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::VH_PluginSubsystem_eventRegisterPlugin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics
	{
		struct VH_PluginSubsystem_eventSetPluginAuthor_Parms
		{
			FName pluginName;
			FString pluginAuthor;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginAuthor_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_pluginAuthor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginAuthor_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginAuthor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginAuthor = { "pluginAuthor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginAuthor_Parms, pluginAuthor), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginAuthor_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginAuthor_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::NewProp_pluginAuthor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the author for a plugin.\n\x09 *\n\x09 * @param pluginName Name of plugin.\n\x09 * @param pluginAuthor author for this plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the author for a plugin.\n\n@param pluginName Name of plugin.\n@param pluginAuthor author for this plugin." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "SetPluginAuthor", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::VH_PluginSubsystem_eventSetPluginAuthor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::VH_PluginSubsystem_eventSetPluginAuthor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics
	{
		struct VH_PluginSubsystem_eventSetPluginDeletion_Parms
		{
			FName pluginName;
			bool bShouldDelete;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
		static void NewProp_bShouldDelete_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldDelete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginDeletion_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_pluginName_MetaData) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_bShouldDelete_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventSetPluginDeletion_Parms*)Obj)->bShouldDelete = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_bShouldDelete = { "bShouldDelete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventSetPluginDeletion_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_bShouldDelete_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::NewProp_bShouldDelete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets a plugin to be deleted. On its own, it only sets the slated for deletion boolean \n\x09 * for the corresponding plugin entry in the list of plugins and marks it as dirty.\n\x09 *\n\x09 * @param pluginName Name of plugin to be deleted.\n\x09 * @param bEnabled boolean to determine whether a plugin should be deleted on next restart or not.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets a plugin to be deleted. On its own, it only sets the slated for deletion boolean\nfor the corresponding plugin entry in the list of plugins and marks it as dirty.\n\n@param pluginName Name of plugin to be deleted.\n@param bEnabled boolean to determine whether a plugin should be deleted on next restart or not." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "SetPluginDeletion", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::VH_PluginSubsystem_eventSetPluginDeletion_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::VH_PluginSubsystem_eventSetPluginDeletion_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics
	{
		struct VH_PluginSubsystem_eventSetPluginDescription_Parms
		{
			FName pluginName;
			FString pluginDescription;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginDescription_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_pluginDescription;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginDescription_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginDescription_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginDescription = { "pluginDescription", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginDescription_Parms, pluginDescription), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginDescription_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginDescription_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::NewProp_pluginDescription,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the description for a plugin.\n\x09 *\n\x09 * @param pluginName Name of plugin.\n\x09 * @param friendlyName new description of this plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the description for a plugin.\n\n@param pluginName Name of plugin.\n@param friendlyName new description of this plugin." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "SetPluginDescription", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::VH_PluginSubsystem_eventSetPluginDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::VH_PluginSubsystem_eventSetPluginDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics
	{
		struct VH_PluginSubsystem_eventSetPluginEnabled_Parms
		{
			FName pluginName;
			bool bIsEnabled;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
		static void NewProp_bIsEnabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEnabled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginEnabled_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_pluginName_MetaData) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_bIsEnabled_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventSetPluginEnabled_Parms*)Obj)->bIsEnabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_bIsEnabled = { "bIsEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventSetPluginEnabled_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_bIsEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::NewProp_bIsEnabled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets a plugin to be enabled or disabled. On its own, it only sets the boolean\n\x09 * for the corresponding plugin entry in the list of plugins and marks it as dirty.\n\x09 *\n\x09 * @param pluginName Name of plugin to be enabled or disabled.\n\x09 * @param bEnabled boolean to determine whether a plugin should be enabled or disabled.\n\x09 */" },
#endif
		{ "CPP_Default_bIsEnabled", "true" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets a plugin to be enabled or disabled. On its own, it only sets the boolean\nfor the corresponding plugin entry in the list of plugins and marks it as dirty.\n\n@param pluginName Name of plugin to be enabled or disabled.\n@param bEnabled boolean to determine whether a plugin should be enabled or disabled." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "SetPluginEnabled", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::VH_PluginSubsystem_eventSetPluginEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::VH_PluginSubsystem_eventSetPluginEnabled_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics
	{
		struct VH_PluginSubsystem_eventSetPluginFriendlyName_Parms
		{
			FName pluginName;
			FString friendlyName;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_friendlyName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_friendlyName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginFriendlyName_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_pluginName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_friendlyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_friendlyName = { "friendlyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginFriendlyName_Parms, friendlyName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_friendlyName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_friendlyName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::NewProp_friendlyName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the friendly name for a plugin.\n\x09 *\n\x09 * @param pluginName Name of plugin.\n\x09 * @param friendlyName new friendly name of this plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the friendly name for a plugin.\n\n@param pluginName Name of plugin.\n@param friendlyName new friendly name of this plugin." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "SetPluginFriendlyName", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::VH_PluginSubsystem_eventSetPluginFriendlyName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::VH_PluginSubsystem_eventSetPluginFriendlyName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics
	{
		struct VH_PluginSubsystem_eventSetPluginLoaded_Parms
		{
			FName pluginName;
			bool bIsLoaded;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
		static void NewProp_bIsLoaded_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLoaded;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginLoaded_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_pluginName_MetaData) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_bIsLoaded_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventSetPluginLoaded_Parms*)Obj)->bIsLoaded = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_bIsLoaded = { "bIsLoaded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventSetPluginLoaded_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_bIsLoaded_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventSetPluginLoaded_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventSetPluginLoaded_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_bIsLoaded,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Loads or unloads a plugin dynamically.\n\x09 *\n\x09 * @param pluginName Name of plugin to load/unload.\n\x09 * @param bIsLoaded Set TRUE to load the plugin, or FALSE to unload the plugin.\n\x09 * @note This currently just sets a bool. Actual dynamic/runtime loading and unloading of plugins is WIP.\n\x09 * @return False if 'pluginName' is not a registered plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Loads or unloads a plugin dynamically.\n\n@param pluginName Name of plugin to load/unload.\n@param bIsLoaded Set TRUE to load the plugin, or FALSE to unload the plugin.\n@note This currently just sets a bool. Actual dynamic/runtime loading and unloading of plugins is WIP.\n@return False if 'pluginName' is not a registered plugin." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "SetPluginLoaded", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::VH_PluginSubsystem_eventSetPluginLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::VH_PluginSubsystem_eventSetPluginLoaded_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics
	{
		struct VH_PluginSubsystem_eventSetPluginVersion_Parms
		{
			FName pluginName;
			int32 versionNum;
			FString versionName;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_versionNum;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_versionName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_versionName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginVersion_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_pluginName_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_versionNum = { "versionNum", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginVersion_Parms, versionNum), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_versionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_versionName = { "versionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventSetPluginVersion_Parms, versionName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_versionName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_versionName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_versionNum,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::NewProp_versionName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the version and version name for a plugin.\n\x09 *\n\x09 * @param pluginName Name of plugin.\n\x09 * @param versionNum version number for this plugin.\n\x09 * @param veresionName version string for this plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the version and version name for a plugin.\n\n@param pluginName Name of plugin.\n@param versionNum version number for this plugin.\n@param veresionName version string for this plugin." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "SetPluginVersion", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::VH_PluginSubsystem_eventSetPluginVersion_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::VH_PluginSubsystem_eventSetPluginVersion_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics
	{
		struct VH_PluginSubsystem_eventUnregisterPlugin_Parms
		{
			FName pluginName;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventUnregisterPlugin_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_pluginName_MetaData) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventUnregisterPlugin_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventUnregisterPlugin_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Unregister a plugin.\n\x09 *\n\x09 * @param pluginName Name of plugin to unregister.\n\x09 * @return False if 'pluginName' is not a registered plugin.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unregister a plugin.\n\n@param pluginName Name of plugin to unregister.\n@return False if 'pluginName' is not a registered plugin." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "UnregisterPlugin", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::VH_PluginSubsystem_eventUnregisterPlugin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::VH_PluginSubsystem_eventUnregisterPlugin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics
	{
		struct VH_PluginSubsystem_eventUpdateAllPlugins_Parms
		{
			bool bWithRestart;
		};
		static void NewProp_bWithRestart_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWithRestart;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::NewProp_bWithRestart_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventUpdateAllPlugins_Parms*)Obj)->bWithRestart = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::NewProp_bWithRestart = { "bWithRestart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventUpdateAllPlugins_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::NewProp_bWithRestart_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::NewProp_bWithRestart,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update the plugin descriptor files for all \"dirty\" plugins.\n\x09 * If the plugin descriptor update succeeds, fully restart game to run with new settings.\n\x09 * \n\x09 * @param bWithRestart If false, this function will update the descriptors, but will not fully restart.\n\x09 */" },
#endif
		{ "CPP_Default_bWithRestart", "true" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update the plugin descriptor files for all \"dirty\" plugins.\nIf the plugin descriptor update succeeds, fully restart game to run with new settings.\n\n@param bWithRestart If false, this function will update the descriptors, but will not fully restart." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "UpdateAllPlugins", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::VH_PluginSubsystem_eventUpdateAllPlugins_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::VH_PluginSubsystem_eventUpdateAllPlugins_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics
	{
		struct VH_PluginSubsystem_eventUpdatePlugin_Parms
		{
			FName pluginName;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_pluginName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_pluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_pluginName = { "pluginName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PluginSubsystem_eventUpdatePlugin_Parms, pluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_pluginName_MetaData), Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_pluginName_MetaData) };
	void Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_PluginSubsystem_eventUpdatePlugin_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PluginSubsystem_eventUpdatePlugin_Parms), &Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_pluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhPlugins|PluginSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update the plugin descriptor file for one plugin. \n\x09 *\n\x09 * @param pluginName Name of plugin to update.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update the plugin descriptor file for one plugin.\n\n@param pluginName Name of plugin to update." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_PluginSubsystem, nullptr, "UpdatePlugin", nullptr, nullptr, Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::VH_PluginSubsystem_eventUpdatePlugin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::VH_PluginSubsystem_eventUpdatePlugin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_PluginSubsystem);
	UClass* Z_Construct_UClass_UVH_PluginSubsystem_NoRegister()
	{
		return UVH_PluginSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UVH_PluginSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_PluginSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Plugins,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_PluginSubsystem_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_PluginSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_GetClassesInPlugin, "GetClassesInPlugin" }, // 4214132606
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_GetMapsInPlugin, "GetMapsInPlugin" }, // 3151213407
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_GetRegisteredPlugins, "GetRegisteredPlugins" }, // 2998770946
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_HandleGenerateCrashLog, "HandleGenerateCrashLog" }, // 4161944273
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_ImportPlugin, "ImportPlugin" }, // 2021844940
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_RegisterPlugin, "RegisterPlugin" }, // 3883300562
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginAuthor, "SetPluginAuthor" }, // 645176120
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDeletion, "SetPluginDeletion" }, // 3754741011
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginDescription, "SetPluginDescription" }, // 3559895464
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginEnabled, "SetPluginEnabled" }, // 3909263696
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginFriendlyName, "SetPluginFriendlyName" }, // 2108187646
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginLoaded, "SetPluginLoaded" }, // 3302341607
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_SetPluginVersion, "SetPluginVersion" }, // 420250660
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_UnregisterPlugin, "UnregisterPlugin" }, // 2698330977
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_UpdateAllPlugins, "UpdateAllPlugins" }, // 3160053676
		{ &Z_Construct_UFunction_UVH_PluginSubsystem_UpdatePlugin, "UpdatePlugin" }, // 1855078217
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_PluginSubsystem_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_PluginSubsystem_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * The VH_PluginSubsystem tracks and manages app-level plugins.\n */" },
#endif
		{ "IncludePath", "VH_PluginSubsystem.h" },
		{ "ModuleRelativePath", "Public/VH_PluginSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The VH_PluginSubsystem tracks and manages app-level plugins." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_PluginSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_PluginSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_PluginSubsystem_Statics::ClassParams = {
		&UVH_PluginSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_PluginSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_PluginSubsystem_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_PluginSubsystem()
	{
		if (!Z_Registration_Info_UClass_UVH_PluginSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_PluginSubsystem.OuterSingleton, Z_Construct_UClass_UVH_PluginSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_PluginSubsystem.OuterSingleton;
	}
	template<> VH_PLUGINS_API UClass* StaticClass<UVH_PluginSubsystem>()
	{
		return UVH_PluginSubsystem::StaticClass();
	}
	UVH_PluginSubsystem::UVH_PluginSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_PluginSubsystem);
	UVH_PluginSubsystem::~UVH_PluginSubsystem() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::EnumInfo[] = {
		{ EPluginLoadError_StaticEnum, TEXT("EPluginLoadError"), &Z_Registration_Info_UEnum_EPluginLoadError, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 615494349U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::ScriptStructInfo[] = {
		{ FPluginInfo::StaticStruct, Z_Construct_UScriptStruct_FPluginInfo_Statics::NewStructOps, TEXT("PluginInfo"), &Z_Registration_Info_UScriptStruct_PluginInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPluginInfo), 1325508982U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_PluginSubsystem, UVH_PluginSubsystem::StaticClass, TEXT("UVH_PluginSubsystem"), &Z_Registration_Info_UClass_UVH_PluginSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_PluginSubsystem), 3722776276U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_2137664118(TEXT("/Script/VH_Plugins"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
