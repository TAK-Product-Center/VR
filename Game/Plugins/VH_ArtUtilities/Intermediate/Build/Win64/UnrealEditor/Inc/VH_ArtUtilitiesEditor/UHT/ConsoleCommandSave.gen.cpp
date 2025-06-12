// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_ArtUtilitiesEditor/Public/ConsoleCommandSave.h"
#include "VH_ArtUtilitiesEditor/Public/ConsoleSettingsUtility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConsoleCommandSave() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	UPackage* Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleCommandList_NoRegister();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleCommandSave();
	VH_ARTUTILITIESEDITOR_API UClass* Z_Construct_UClass_UConsoleCommandSave_NoRegister();
	VH_ARTUTILITIESEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FConsoleCommand();
	VH_ARTUTILITIESEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FSavedCommandsStruct();
	VH_ARTUTILITIESEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FSettingsGroup();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SavedCommandsStruct;
class UScriptStruct* FSavedCommandsStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SavedCommandsStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SavedCommandsStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSavedCommandsStruct, (UObject*)Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor(), TEXT("SavedCommandsStruct"));
	}
	return Z_Registration_Info_UScriptStruct_SavedCommandsStruct.OuterSingleton;
}
template<> VH_ARTUTILITIESEDITOR_API UScriptStruct* StaticStruct<FSavedCommandsStruct>()
{
	return FSavedCommandsStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Commands_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Commands_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Commands;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Substitute for UConsoleCommandList whose data can be saved more easily.\n */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Substitute for UConsoleCommandList whose data can be saved more easily." },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSavedCommandsStruct>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewProp_Commands_Inner = { "Commands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FConsoleCommand, METADATA_PARAMS(0, nullptr) }; // 1269050330
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewProp_Commands_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * FConsoleCommand datas to save.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* FConsoleCommand datas to save." },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewProp_Commands = { "Commands", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSavedCommandsStruct, Commands), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewProp_Commands_MetaData), Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewProp_Commands_MetaData) }; // 1269050330
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewProp_Commands_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewProp_Commands,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor,
		nullptr,
		&NewStructOps,
		"SavedCommandsStruct",
		Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::PropPointers),
		sizeof(FSavedCommandsStruct),
		alignof(FSavedCommandsStruct),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FSavedCommandsStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_SavedCommandsStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SavedCommandsStruct.InnerSingleton, Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SavedCommandsStruct.InnerSingleton;
	}
	DEFINE_FUNCTION(UConsoleCommandSave::execRetrieveSaveGameVariables)
	{
		P_GET_TARRAY_REF(FSettingsGroup,Z_Param_Out_InSettingGroups);
		P_GET_TARRAY_REF(FConsoleCommand,Z_Param_Out_InGeneralCommands);
		P_GET_TMAP_REF(int32,UConsoleCommandList*,Z_Param_Out_InGroupToGeneralCommands);
		P_GET_TMAP_REF(int32,UConsoleCommandList*,Z_Param_Out_InGroupToSpecificCommands);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_InCurrentGroupID);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_InCurrentCommandID);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RetrieveSaveGameVariables(Z_Param_Out_InSettingGroups,Z_Param_Out_InGeneralCommands,Z_Param_Out_InGroupToGeneralCommands,Z_Param_Out_InGroupToSpecificCommands,Z_Param_Out_InCurrentGroupID,Z_Param_Out_InCurrentCommandID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UConsoleCommandSave::execPopulateSaveGameVariables)
	{
		P_GET_TARRAY(FSettingsGroup,Z_Param_InSettingGroups);
		P_GET_TARRAY(FConsoleCommand,Z_Param_InGeneralCommands);
		P_GET_TMAP(int32,UConsoleCommandList*,Z_Param_InGroupToGeneralCommands);
		P_GET_TMAP(int32,UConsoleCommandList*,Z_Param_InGroupToSpecificCommands);
		P_GET_PROPERTY(FIntProperty,Z_Param_InCurrentGroupID);
		P_GET_PROPERTY(FIntProperty,Z_Param_InCurrentCommandID);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PopulateSaveGameVariables(Z_Param_InSettingGroups,Z_Param_InGeneralCommands,Z_Param_InGroupToGeneralCommands,Z_Param_InGroupToSpecificCommands,Z_Param_InCurrentGroupID,Z_Param_InCurrentCommandID);
		P_NATIVE_END;
	}
	void UConsoleCommandSave::StaticRegisterNativesUConsoleCommandSave()
	{
		UClass* Class = UConsoleCommandSave::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PopulateSaveGameVariables", &UConsoleCommandSave::execPopulateSaveGameVariables },
			{ "RetrieveSaveGameVariables", &UConsoleCommandSave::execRetrieveSaveGameVariables },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics
	{
		struct ConsoleCommandSave_eventPopulateSaveGameVariables_Parms
		{
			TArray<FSettingsGroup> InSettingGroups;
			TArray<FConsoleCommand> InGeneralCommands;
			TMap<int32,UConsoleCommandList*> InGroupToGeneralCommands;
			TMap<int32,UConsoleCommandList*> InGroupToSpecificCommands;
			int32 InCurrentGroupID;
			int32 InCurrentCommandID;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_InSettingGroups_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InSettingGroups;
		static const UECodeGen_Private::FStructPropertyParams NewProp_InGeneralCommands_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InGeneralCommands;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InGroupToGeneralCommands_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InGroupToGeneralCommands_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_InGroupToGeneralCommands;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InGroupToSpecificCommands_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InGroupToSpecificCommands_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_InGroupToSpecificCommands;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InCurrentGroupID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InCurrentCommandID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InSettingGroups_Inner = { "InSettingGroups", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSettingsGroup, METADATA_PARAMS(0, nullptr) }; // 1537245753
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InSettingGroups = { "InSettingGroups", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventPopulateSaveGameVariables_Parms, InSettingGroups), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1537245753
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGeneralCommands_Inner = { "InGeneralCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FConsoleCommand, METADATA_PARAMS(0, nullptr) }; // 1269050330
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGeneralCommands = { "InGeneralCommands", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventPopulateSaveGameVariables_Parms, InGeneralCommands), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1269050330
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_ValueProp = { "InGroupToGeneralCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UConsoleCommandList_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_Key_KeyProp = { "InGroupToGeneralCommands_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands = { "InGroupToGeneralCommands", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventPopulateSaveGameVariables_Parms, InGroupToGeneralCommands), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_ValueProp = { "InGroupToSpecificCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UConsoleCommandList_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_Key_KeyProp = { "InGroupToSpecificCommands_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands = { "InGroupToSpecificCommands", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventPopulateSaveGameVariables_Parms, InGroupToSpecificCommands), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InCurrentGroupID = { "InCurrentGroupID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventPopulateSaveGameVariables_Parms, InCurrentGroupID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InCurrentCommandID = { "InCurrentCommandID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventPopulateSaveGameVariables_Parms, InCurrentCommandID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InSettingGroups_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InSettingGroups,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGeneralCommands_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGeneralCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InCurrentGroupID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::NewProp_InCurrentCommandID,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Loads the provided SaveGame in the predefined slot\n\x09 * @param InSettingGroups - The groups of commands to save.\n\x09 * @param InGeneralCommands - The commands found in every group.\n\x09 * @param InGroupToGeneralCommands - The values of the commands found in each group.\n\x09 * @param InGroupToSpecificCommands - The specific commands in each group and their values.\n\x09 * @param InCurrentGroupID - The ID of the most recently made group.\n\x09 * @param InCurrentCommandID - The ID of the most recently made command.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Loads the provided SaveGame in the predefined slot\n* @param InSettingGroups - The groups of commands to save.\n* @param InGeneralCommands - The commands found in every group.\n* @param InGroupToGeneralCommands - The values of the commands found in each group.\n* @param InGroupToSpecificCommands - The specific commands in each group and their values.\n* @param InCurrentGroupID - The ID of the most recently made group.\n* @param InCurrentCommandID - The ID of the most recently made command." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConsoleCommandSave, nullptr, "PopulateSaveGameVariables", nullptr, nullptr, Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::PropPointers), sizeof(Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::ConsoleCommandSave_eventPopulateSaveGameVariables_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::ConsoleCommandSave_eventPopulateSaveGameVariables_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics
	{
		struct ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms
		{
			TArray<FSettingsGroup> InSettingGroups;
			TArray<FConsoleCommand> InGeneralCommands;
			TMap<int32,UConsoleCommandList*> InGroupToGeneralCommands;
			TMap<int32,UConsoleCommandList*> InGroupToSpecificCommands;
			int32 InCurrentGroupID;
			int32 InCurrentCommandID;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_InSettingGroups_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InSettingGroups;
		static const UECodeGen_Private::FStructPropertyParams NewProp_InGeneralCommands_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InGeneralCommands;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InGroupToGeneralCommands_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InGroupToGeneralCommands_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_InGroupToGeneralCommands;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InGroupToSpecificCommands_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InGroupToSpecificCommands_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_InGroupToSpecificCommands;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InCurrentGroupID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_InCurrentCommandID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InSettingGroups_Inner = { "InSettingGroups", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSettingsGroup, METADATA_PARAMS(0, nullptr) }; // 1537245753
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InSettingGroups = { "InSettingGroups", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms, InSettingGroups), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1537245753
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGeneralCommands_Inner = { "InGeneralCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FConsoleCommand, METADATA_PARAMS(0, nullptr) }; // 1269050330
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGeneralCommands = { "InGeneralCommands", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms, InGeneralCommands), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1269050330
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_ValueProp = { "InGroupToGeneralCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UConsoleCommandList_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_Key_KeyProp = { "InGroupToGeneralCommands_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands = { "InGroupToGeneralCommands", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms, InGroupToGeneralCommands), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_ValueProp = { "InGroupToSpecificCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UConsoleCommandList_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_Key_KeyProp = { "InGroupToSpecificCommands_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands = { "InGroupToSpecificCommands", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms, InGroupToSpecificCommands), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InCurrentGroupID = { "InCurrentGroupID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms, InCurrentGroupID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InCurrentCommandID = { "InCurrentCommandID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms, InCurrentCommandID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InSettingGroups_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InSettingGroups,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGeneralCommands_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGeneralCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToGeneralCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InGroupToSpecificCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InCurrentGroupID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::NewProp_InCurrentCommandID,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Saves the provided SaveGame in the predefined slot\n\x09 * @param InSettingGroups - The groups of commands to save.\n\x09 * @param InGeneralCommands - The commands cound in each group.\n\x09 * @param InGroupToGeneralCommands - The values of the commands found in each group.\n\x09 * @param InGroupToSpecificCommands - The specific commands in each group and their values.\n\x09 * @param InCurrentGroupID - The ID of the most recently made group.\n\x09 * @param InCurrentCommandID - The ID of the most recently made command.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Saves the provided SaveGame in the predefined slot\n* @param InSettingGroups - The groups of commands to save.\n* @param InGeneralCommands - The commands cound in each group.\n* @param InGroupToGeneralCommands - The values of the commands found in each group.\n* @param InGroupToSpecificCommands - The specific commands in each group and their values.\n* @param InCurrentGroupID - The ID of the most recently made group.\n* @param InCurrentCommandID - The ID of the most recently made command." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConsoleCommandSave, nullptr, "RetrieveSaveGameVariables", nullptr, nullptr, Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::PropPointers), sizeof(Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::Function_MetaDataParams), Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::ConsoleCommandSave_eventRetrieveSaveGameVariables_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UConsoleCommandSave);
	UClass* Z_Construct_UClass_UConsoleCommandSave_NoRegister()
	{
		return UConsoleCommandSave::StaticClass();
	}
	struct Z_Construct_UClass_UConsoleCommandSave_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SettingGroups_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SettingGroups_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SettingGroups;
		static const UECodeGen_Private::FStructPropertyParams NewProp_GeneralCommands_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeneralCommands_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_GeneralCommands;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentGroupID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentGroupID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCommandID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCommandID;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PrivateGroupToGeneralCommands_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PrivateGroupToGeneralCommands_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PrivateGroupToGeneralCommands_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_PrivateGroupToGeneralCommands;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PrivateGroupToSpecificCommands_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PrivateGroupToSpecificCommands_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PrivateGroupToSpecificCommands_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_PrivateGroupToSpecificCommands;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConsoleCommandSave_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilitiesEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UConsoleCommandSave_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UConsoleCommandSave_PopulateSaveGameVariables, "PopulateSaveGameVariables" }, // 2685353648
		{ &Z_Construct_UFunction_UConsoleCommandSave_RetrieveSaveGameVariables, "RetrieveSaveGameVariables" }, // 4242046323
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandSave_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Describes a save for the console commands for each setting and level\n */" },
#endif
		{ "IncludePath", "ConsoleCommandSave.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes a save for the console commands for each setting and level" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_SettingGroups_Inner = { "SettingGroups", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSettingsGroup, METADATA_PARAMS(0, nullptr) }; // 1537245753
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_SettingGroups_MetaData[] = {
		{ "Category", "ConsoleCommandSave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Groups of commands\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Groups of commands" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_SettingGroups = { "SettingGroups", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UConsoleCommandSave, SettingGroups), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_SettingGroups_MetaData), Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_SettingGroups_MetaData) }; // 1537245753
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_GeneralCommands_Inner = { "GeneralCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FConsoleCommand, METADATA_PARAMS(0, nullptr) }; // 1269050330
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_GeneralCommands_MetaData[] = {
		{ "Category", "ConsoleCommandSave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Commands found in all groups\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Commands found in all groups" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_GeneralCommands = { "GeneralCommands", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UConsoleCommandSave, GeneralCommands), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_GeneralCommands_MetaData), Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_GeneralCommands_MetaData) }; // 1269050330
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentGroupID_MetaData[] = {
		{ "Category", "ConsoleCommandSave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * The ID of the most recently made group\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The ID of the most recently made group" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentGroupID = { "CurrentGroupID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UConsoleCommandSave, CurrentGroupID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentGroupID_MetaData), Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentGroupID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentCommandID_MetaData[] = {
		{ "Category", "ConsoleCommandSave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * The ID of the most recently made command\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The ID of the most recently made command" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentCommandID = { "CurrentCommandID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UConsoleCommandSave, CurrentCommandID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentCommandID_MetaData), Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentCommandID_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands_ValueProp = { "PrivateGroupToGeneralCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FSavedCommandsStruct, METADATA_PARAMS(0, nullptr) }; // 2106539368
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands_Key_KeyProp = { "PrivateGroupToGeneralCommands_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * The values of the commands found in each group.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The values of the commands found in each group." },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands = { "PrivateGroupToGeneralCommands", nullptr, (EPropertyFlags)0x0040000001000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UConsoleCommandSave, PrivateGroupToGeneralCommands), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands_MetaData), Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands_MetaData) }; // 2106539368
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands_ValueProp = { "PrivateGroupToSpecificCommands", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FSavedCommandsStruct, METADATA_PARAMS(0, nullptr) }; // 2106539368
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands_Key_KeyProp = { "PrivateGroupToSpecificCommands_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * The values of the commands found in specific groups.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ConsoleCommandSave.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The values of the commands found in specific groups." },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands = { "PrivateGroupToSpecificCommands", nullptr, (EPropertyFlags)0x0040000001000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UConsoleCommandSave, PrivateGroupToSpecificCommands), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands_MetaData), Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands_MetaData) }; // 2106539368
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UConsoleCommandSave_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_SettingGroups_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_SettingGroups,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_GeneralCommands_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_GeneralCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentGroupID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_CurrentCommandID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToGeneralCommands,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConsoleCommandSave_Statics::NewProp_PrivateGroupToSpecificCommands,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConsoleCommandSave_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConsoleCommandSave>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UConsoleCommandSave_Statics::ClassParams = {
		&UConsoleCommandSave::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UConsoleCommandSave_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::Class_MetaDataParams), Z_Construct_UClass_UConsoleCommandSave_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UConsoleCommandSave_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UConsoleCommandSave()
	{
		if (!Z_Registration_Info_UClass_UConsoleCommandSave.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UConsoleCommandSave.OuterSingleton, Z_Construct_UClass_UConsoleCommandSave_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UConsoleCommandSave.OuterSingleton;
	}
	template<> VH_ARTUTILITIESEDITOR_API UClass* StaticClass<UConsoleCommandSave>()
	{
		return UConsoleCommandSave::StaticClass();
	}
	UConsoleCommandSave::UConsoleCommandSave(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConsoleCommandSave);
	UConsoleCommandSave::~UConsoleCommandSave() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_Statics::ScriptStructInfo[] = {
		{ FSavedCommandsStruct::StaticStruct, Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics::NewStructOps, TEXT("SavedCommandsStruct"), &Z_Registration_Info_UScriptStruct_SavedCommandsStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSavedCommandsStruct), 2106539368U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UConsoleCommandSave, UConsoleCommandSave::StaticClass, TEXT("UConsoleCommandSave"), &Z_Registration_Info_UClass_UConsoleCommandSave, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UConsoleCommandSave), 3079324304U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_1488734263(TEXT("/Script/VH_ArtUtilitiesEditor"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
