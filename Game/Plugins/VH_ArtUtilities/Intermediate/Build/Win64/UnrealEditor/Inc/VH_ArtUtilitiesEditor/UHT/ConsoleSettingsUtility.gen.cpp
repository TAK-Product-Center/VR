// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_ArtUtilitiesEditor/Public/ConsoleSettingsUtility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConsoleSettingsUtility() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleCommandList();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleCommandList_NoRegister();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleCommandSave_NoRegister();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleSettingsUtilityFunctions();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleSettingsUtilityFunctions_NoRegister();
	VH_ARTUTILITIESEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FConsoleCommand();
	VH_ARTUTILITIESEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FSettingsGroup();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SettingsGroup;
class UScriptStruct* FSettingsGroup::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SettingsGroup.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SettingsGroup.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSettingsGroup, (UObject*)Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor(), TEXT("SettingsGroup"));
	}
	return Z_Registration_Info_UScriptStruct_SettingsGroup.OuterSingleton;
}
template<> VH_ARTUTILITIESEDITOR_API UScriptStruct* StaticStruct<FSettingsGroup>()
{
	return FSettingsGroup::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSettingsGroup_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSettingsGroup_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Structs\n// ---------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Structs" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSettingsGroup>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_ID_MetaData[] = {
		{ "Category", "SettingsGroup" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSettingsGroup, ID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_ID_MetaData), Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_ID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_DisplayName_MetaData[] = {
		{ "Category", "SettingsGroup" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSettingsGroup, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_DisplayName_MetaData), Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_DisplayName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSettingsGroup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_ID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewProp_DisplayName,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSettingsGroup_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor,
		nullptr,
		&NewStructOps,
		"SettingsGroup",
		Z_Construct_UScriptStruct_FSettingsGroup_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSettingsGroup_Statics::PropPointers),
		sizeof(FSettingsGroup),
		alignof(FSettingsGroup),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSettingsGroup_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSettingsGroup_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSettingsGroup_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FSettingsGroup()
	{
		if (!Z_Registration_Info_UScriptStruct_SettingsGroup.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SettingsGroup.InnerSingleton, Z_Construct_UScriptStruct_FSettingsGroup_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SettingsGroup.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ConsoleCommand;
class UScriptStruct* FConsoleCommand::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ConsoleCommand.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ConsoleCommand.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FConsoleCommand, (UObject*)Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor(), TEXT("ConsoleCommand"));
	}
	return Z_Registration_Info_UScriptStruct_ConsoleCommand.OuterSingleton;
}
template<> VH_ARTUTILITIESEDITOR_API UScriptStruct* StaticStruct<FConsoleCommand>()
{
	return FConsoleCommand::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FConsoleCommand_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EditorName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EditorName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CommandBody_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CommandBody;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tooltip_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Tooltip;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConsoleCommand_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FConsoleCommand>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_ID_MetaData[] = {
		{ "Category", "ConsoleCommand" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FConsoleCommand, ID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_ID_MetaData), Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_ID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_EditorName_MetaData[] = {
		{ "Category", "ConsoleCommand" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_EditorName = { "EditorName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FConsoleCommand, EditorName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_EditorName_MetaData), Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_EditorName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_CommandBody_MetaData[] = {
		{ "Category", "ConsoleCommand" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_CommandBody = { "CommandBody", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FConsoleCommand, CommandBody), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_CommandBody_MetaData), Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_CommandBody_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Tooltip_MetaData[] = {
		{ "Category", "ConsoleCommand" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Tooltip = { "Tooltip", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FConsoleCommand, Tooltip), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Tooltip_MetaData), Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Tooltip_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "ConsoleCommand" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FConsoleCommand, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Value_MetaData), Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FConsoleCommand_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_ID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_EditorName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_CommandBody,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Tooltip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewProp_Value,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FConsoleCommand_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor,
		nullptr,
		&NewStructOps,
		"ConsoleCommand",
		Z_Construct_UScriptStruct_FConsoleCommand_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::PropPointers),
		sizeof(FConsoleCommand),
		alignof(FConsoleCommand),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FConsoleCommand_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConsoleCommand_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FConsoleCommand()
	{
		if (!Z_Registration_Info_UScriptStruct_ConsoleCommand.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ConsoleCommand.InnerSingleton, Z_Construct_UScriptStruct_FConsoleCommand_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ConsoleCommand.InnerSingleton;
	}
	DEFINE_FUNCTION(UConsoleCommandList::execGetByRef)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_index);
		P_GET_STRUCT_REF(FConsoleCommand,Z_Param_Out_foundCommand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetByRef(Z_Param_index,Z_Param_Out_foundCommand);
		P_NATIVE_END;
	}
	void UConsoleCommandList::StaticRegisterNativesUConsoleCommandList()
	{
		UClass* Class = UConsoleCommandList::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetByRef", &UConsoleCommandList::execGetByRef },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics
	{
		struct ConsoleCommandList_eventGetByRef_Parms
		{
			int32 index;
			FConsoleCommand foundCommand;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_index;
		static const UECodeGen_Private::FStructPropertyParams NewProp_foundCommand;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandList_eventGetByRef_Parms, index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_foundCommand = { "foundCommand", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandList_eventGetByRef_Parms, foundCommand), Z_Construct_UScriptStruct_FConsoleCommand, METADATA_PARAMS(0, nullptr) }; // 1269050330
	void Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ConsoleCommandList_eventGetByRef_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ConsoleCommandList_eventGetByRef_Parms), &Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_foundCommand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Returns a reference to a specific command\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns a reference to a specific command" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConsoleCommandList, nullptr, "GetByRef", nullptr, nullptr, Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::PropPointers), sizeof(Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::ConsoleCommandList_eventGetByRef_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::ConsoleCommandList_eventGetByRef_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UConsoleCommandList_GetByRef()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConsoleCommandList_GetByRef_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UConsoleCommandList);
	UClass* Z_Construct_UClass_UConsoleCommandList_NoRegister()
	{
		return UConsoleCommandList::StaticClass();
	}
	struct Z_Construct_UClass_UConsoleCommandList_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Commands_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Commands_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Commands;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConsoleCommandList_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandList_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UConsoleCommandList_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UConsoleCommandList_GetByRef, "GetByRef" }, // 2220485532
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandList_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandList_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Class\n// ---------------------------------\n" },
#endif
		{ "IncludePath", "ConsoleSettingsUtility.h" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Class" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConsoleCommandList_Statics::NewProp_Commands_Inner = { "Commands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FConsoleCommand, METADATA_PARAMS(0, nullptr) }; // 1269050330
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandList_Statics::NewProp_Commands_MetaData[] = {
		{ "Category", "ConsoleCommandList" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UConsoleCommandList_Statics::NewProp_Commands = { "Commands", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UConsoleCommandList, Commands), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandList_Statics::NewProp_Commands_MetaData), Z_Construct_UClass_UConsoleCommandList_Statics::NewProp_Commands_MetaData) }; // 1269050330
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UConsoleCommandList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandList_Statics::NewProp_Commands_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandList_Statics::NewProp_Commands,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConsoleCommandList_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConsoleCommandList>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UConsoleCommandList_Statics::ClassParams = {
		&UConsoleCommandList::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UConsoleCommandList_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandList_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandList_Statics::Class_MetaDataParams), Z_Construct_UClass_UConsoleCommandList_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandList_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UConsoleCommandList()
	{
		if (!Z_Registration_Info_UClass_UConsoleCommandList.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UConsoleCommandList.OuterSingleton, Z_Construct_UClass_UConsoleCommandList_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UConsoleCommandList.OuterSingleton;
	}
	template<> VH_ARTUTILITIESEDITOR_API UClass* StaticClass<UConsoleCommandList>()
	{
		return UConsoleCommandList::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConsoleCommandList);
	UConsoleCommandList::~UConsoleCommandList() {}
	DEFINE_FUNCTION(UConsoleSettingsUtilityFunctions::execLoadCurrentCommandsSave)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UConsoleCommandSave**)Z_Param__Result=UConsoleSettingsUtilityFunctions::LoadCurrentCommandsSave();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UConsoleSettingsUtilityFunctions::execSaveCommands)
	{
		P_GET_OBJECT(UConsoleCommandSave,Z_Param_save);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UConsoleSettingsUtilityFunctions::SaveCommands(Z_Param_save);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UConsoleSettingsUtilityFunctions::execTryGetMapName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UConsoleSettingsUtilityFunctions::TryGetMapName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UConsoleSettingsUtilityFunctions::execGetSaveSlotName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UConsoleSettingsUtilityFunctions::GetSaveSlotName();
		P_NATIVE_END;
	}
	void UConsoleSettingsUtilityFunctions::StaticRegisterNativesUConsoleSettingsUtilityFunctions()
	{
		UClass* Class = UConsoleSettingsUtilityFunctions::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetSaveSlotName", &UConsoleSettingsUtilityFunctions::execGetSaveSlotName },
			{ "LoadCurrentCommandsSave", &UConsoleSettingsUtilityFunctions::execLoadCurrentCommandsSave },
			{ "SaveCommands", &UConsoleSettingsUtilityFunctions::execSaveCommands },
			{ "TryGetMapName", &UConsoleSettingsUtilityFunctions::execTryGetMapName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics
	{
		struct ConsoleSettingsUtilityFunctions_eventGetSaveSlotName_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleSettingsUtilityFunctions_eventGetSaveSlotName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Authoritative source of the save slot name for the game.\n\x09 * @return The string \"ConsoleCommands\"\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Authoritative source of the save slot name for the game.\n* @return The string \"ConsoleCommands\"" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConsoleSettingsUtilityFunctions, nullptr, "GetSaveSlotName", nullptr, nullptr, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::ConsoleSettingsUtilityFunctions_eventGetSaveSlotName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::ConsoleSettingsUtilityFunctions_eventGetSaveSlotName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics
	{
		struct ConsoleSettingsUtilityFunctions_eventLoadCurrentCommandsSave_Parms
		{
			UConsoleCommandSave* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleSettingsUtilityFunctions_eventLoadCurrentCommandsSave_Parms, ReturnValue), Z_Construct_UClass_UConsoleCommandSave_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Saves the provided SaveGame in the predefined slot\n\x09 * @return The SaveGameToSlot return value\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Saves the provided SaveGame in the predefined slot\n* @return The SaveGameToSlot return value" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConsoleSettingsUtilityFunctions, nullptr, "LoadCurrentCommandsSave", nullptr, nullptr, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::PropPointers), sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::ConsoleSettingsUtilityFunctions_eventLoadCurrentCommandsSave_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::ConsoleSettingsUtilityFunctions_eventLoadCurrentCommandsSave_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics
	{
		struct ConsoleSettingsUtilityFunctions_eventSaveCommands_Parms
		{
			UConsoleCommandSave* save;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_save;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::NewProp_save = { "save", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleSettingsUtilityFunctions_eventSaveCommands_Parms, save), Z_Construct_UClass_UConsoleCommandSave_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ConsoleSettingsUtilityFunctions_eventSaveCommands_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ConsoleSettingsUtilityFunctions_eventSaveCommands_Parms), &Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::NewProp_save,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Saves the provided SaveGame in the predefined slot\n\x09 * @return The SaveGameToSlot return value\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Saves the provided SaveGame in the predefined slot\n* @return The SaveGameToSlot return value" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConsoleSettingsUtilityFunctions, nullptr, "SaveCommands", nullptr, nullptr, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::PropPointers), sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::ConsoleSettingsUtilityFunctions_eventSaveCommands_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::ConsoleSettingsUtilityFunctions_eventSaveCommands_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics
	{
		struct ConsoleSettingsUtilityFunctions_eventTryGetMapName_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleSettingsUtilityFunctions_eventTryGetMapName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Tries to access the current world and retun its name.\n\x09 * @return Map name, empty if world is not found.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Tries to access the current world and retun its name.\n* @return Map name, empty if world is not found." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConsoleSettingsUtilityFunctions, nullptr, "TryGetMapName", nullptr, nullptr, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::ConsoleSettingsUtilityFunctions_eventTryGetMapName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::ConsoleSettingsUtilityFunctions_eventTryGetMapName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UConsoleSettingsUtilityFunctions);
	UClass* Z_Construct_UClass_UConsoleSettingsUtilityFunctions_NoRegister()
	{
		return UConsoleSettingsUtilityFunctions::StaticClass();
	}
	struct Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_GetSaveSlotName, "GetSaveSlotName" }, // 3307072249
		{ &Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_LoadCurrentCommandsSave, "LoadCurrentCommandsSave" }, // 587867943
		{ &Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_SaveCommands, "SaveCommands" }, // 709267275
		{ &Z_Construct_UFunction_UConsoleSettingsUtilityFunctions_TryGetMapName, "TryGetMapName" }, // 2461403549
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Console Settings Utility allows users to create groups of console commands that are executed upon button press and beginning play.\n */" },
#endif
		{ "IncludePath", "ConsoleSettingsUtility.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ConsoleSettingsUtility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Console Settings Utility allows users to create groups of console commands that are executed upon button press and beginning play." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConsoleSettingsUtilityFunctions>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::ClassParams = {
		&UConsoleSettingsUtilityFunctions::StaticClass,
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
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::Class_MetaDataParams), Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UConsoleSettingsUtilityFunctions()
	{
		if (!Z_Registration_Info_UClass_UConsoleSettingsUtilityFunctions.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UConsoleSettingsUtilityFunctions.OuterSingleton, Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UConsoleSettingsUtilityFunctions.OuterSingleton;
	}
	template<> VH_ARTUTILITIESEDITOR_API UClass* StaticClass<UConsoleSettingsUtilityFunctions>()
	{
		return UConsoleSettingsUtilityFunctions::StaticClass();
	}
	UConsoleSettingsUtilityFunctions::UConsoleSettingsUtilityFunctions(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConsoleSettingsUtilityFunctions);
	UConsoleSettingsUtilityFunctions::~UConsoleSettingsUtilityFunctions() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_Statics::ScriptStructInfo[] = {
		{ FSettingsGroup::StaticStruct, Z_Construct_UScriptStruct_FSettingsGroup_Statics::NewStructOps, TEXT("SettingsGroup"), &Z_Registration_Info_UScriptStruct_SettingsGroup, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSettingsGroup), 1537245753U) },
		{ FConsoleCommand::StaticStruct, Z_Construct_UScriptStruct_FConsoleCommand_Statics::NewStructOps, TEXT("ConsoleCommand"), &Z_Registration_Info_UScriptStruct_ConsoleCommand, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FConsoleCommand), 1269050330U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UConsoleCommandList, UConsoleCommandList::StaticClass, TEXT("UConsoleCommandList"), &Z_Registration_Info_UClass_UConsoleCommandList, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UConsoleCommandList), 1589923407U) },
		{ Z_Construct_UClass_UConsoleSettingsUtilityFunctions, UConsoleSettingsUtilityFunctions::StaticClass, TEXT("UConsoleSettingsUtilityFunctions"), &Z_Registration_Info_UClass_UConsoleSettingsUtilityFunctions, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UConsoleSettingsUtilityFunctions), 3724246918U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_1014126243(TEXT("/Script/VH_ArtUtilitiesEditor"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
