// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI_Statics.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_Statics() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Statics();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Statics_NoRegister();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics
	{
		struct UI_Statics_eventOnDialogComplete_Parms
		{
			bool bSuccess;
			TArray<FString> files;
		};
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UECodeGen_Private::FStrPropertyParams NewProp_files_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_files_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_files;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((UI_Statics_eventOnDialogComplete_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventOnDialogComplete_Parms), &Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_files_Inner = { "files", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_files_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_files = { "files", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOnDialogComplete_Parms, files), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_files_MetaData), Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_files_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_bSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_files_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::NewProp_files,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "OnDialogComplete__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::UI_Statics_eventOnDialogComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::UI_Statics_eventOnDialogComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UUI_Statics::FOnDialogComplete_DelegateWrapper(const FScriptDelegate& OnDialogComplete, bool bSuccess, TArray<FString> const& files)
{
	struct UI_Statics_eventOnDialogComplete_Parms
	{
		bool bSuccess;
		TArray<FString> files;
	};
	UI_Statics_eventOnDialogComplete_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.files=files;
	OnDialogComplete.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UUI_Statics::execSelectFileBrowser)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_windowTitle);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialFilename);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_fileTypes);
		P_GET_UBOOL(Z_Param_bIsSaving);
		P_GET_UBOOL(Z_Param_bIsMultiSelect);
		P_GET_TARRAY_REF(FString,Z_Param_Out_outSelectedFilenames);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_outSelectedFilterIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UUI_Statics::SelectFileBrowser(Z_Param_windowTitle,Z_Param_initialPath,Z_Param_initialFilename,Z_Param_Out_fileTypes,Z_Param_bIsSaving,Z_Param_bIsMultiSelect,Z_Param_Out_outSelectedFilenames,Z_Param_Out_outSelectedFilterIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execSelectFolderBrowser)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_windowTitle);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialPath);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_outSelectedFolder);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UUI_Statics::SelectFolderBrowser(Z_Param_windowTitle,Z_Param_initialPath,Z_Param_Out_outSelectedFolder);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execSaveFileBrowser)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_windowTitle);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialFilename);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_fileType);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_outSelectedFilename);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UUI_Statics::SaveFileBrowser(Z_Param_windowTitle,Z_Param_initialPath,Z_Param_initialFilename,Z_Param_Out_fileType,Z_Param_Out_outSelectedFilename);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execOpenFileBrowser)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_windowTitle);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialFilename);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_fileTypes);
		P_GET_UBOOL(Z_Param_bIsMultiSelect);
		P_GET_TARRAY_REF(FString,Z_Param_Out_outSelectedFilenames);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UUI_Statics::OpenFileBrowser(Z_Param_windowTitle,Z_Param_initialPath,Z_Param_initialFilename,Z_Param_Out_fileTypes,Z_Param_bIsMultiSelect,Z_Param_Out_outSelectedFilenames);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execOpenFileExplorer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_absolutePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UUI_Statics::OpenFileExplorer(Z_Param_absolutePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execSaveNativeFileBrowserDialogAsync)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_dialogTitle);
		P_GET_PROPERTY(FStrProperty,Z_Param_defaultPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_initialFilename);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_fileTypes);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_onDialogComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		UUI_Statics::SaveNativeFileBrowserDialogAsync(Z_Param_dialogTitle,Z_Param_defaultPath,Z_Param_initialFilename,Z_Param_Out_fileTypes,FOnDialogComplete(Z_Param_onDialogComplete));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execOpenNativeFileBrowserDialogAsync)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_dialogTitle);
		P_GET_PROPERTY(FStrProperty,Z_Param_defaultPath);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_fileTypes);
		P_GET_UBOOL(Z_Param_multiSelect);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_onDialogComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		UUI_Statics::OpenNativeFileBrowserDialogAsync(Z_Param_dialogTitle,Z_Param_defaultPath,Z_Param_Out_fileTypes,Z_Param_multiSelect,FOnDialogComplete(Z_Param_onDialogComplete));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execParseExtensionsIntoArray)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_extensions);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=UUI_Statics::ParseExtensionsIntoArray(Z_Param_extensions);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Statics::execSyncKeyboardFocus)
	{
		P_GET_OBJECT(UWidget,Z_Param_widget);
		P_GET_UBOOL_REF(Z_Param_Out_bHasFocus);
		P_GET_UBOOL_REF(Z_Param_Out_bAlreadyHadKeyboardFocus);
		P_FINISH;
		P_NATIVE_BEGIN;
		UUI_Statics::SyncKeyboardFocus(Z_Param_widget,Z_Param_Out_bHasFocus,Z_Param_Out_bAlreadyHadKeyboardFocus);
		P_NATIVE_END;
	}
	void UUI_Statics::StaticRegisterNativesUUI_Statics()
	{
		UClass* Class = UUI_Statics::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OpenFileBrowser", &UUI_Statics::execOpenFileBrowser },
			{ "OpenFileExplorer", &UUI_Statics::execOpenFileExplorer },
			{ "OpenNativeFileBrowserDialogAsync", &UUI_Statics::execOpenNativeFileBrowserDialogAsync },
			{ "ParseExtensionsIntoArray", &UUI_Statics::execParseExtensionsIntoArray },
			{ "SaveFileBrowser", &UUI_Statics::execSaveFileBrowser },
			{ "SaveNativeFileBrowserDialogAsync", &UUI_Statics::execSaveNativeFileBrowserDialogAsync },
			{ "SelectFileBrowser", &UUI_Statics::execSelectFileBrowser },
			{ "SelectFolderBrowser", &UUI_Statics::execSelectFolderBrowser },
			{ "SyncKeyboardFocus", &UUI_Statics::execSyncKeyboardFocus },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics
	{
		struct UI_Statics_eventOpenFileBrowser_Parms
		{
			FString windowTitle;
			FString initialPath;
			FString initialFilename;
			TMap<FString,FString> fileTypes;
			bool bIsMultiSelect;
			TArray<FString> outSelectedFilenames;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_windowTitle_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_windowTitle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialFilename;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fileTypes_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_fileTypes;
		static void NewProp_bIsMultiSelect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMultiSelect;
		static const UECodeGen_Private::FStrPropertyParams NewProp_outSelectedFilenames_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_outSelectedFilenames;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_windowTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_windowTitle = { "windowTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenFileBrowser_Parms, windowTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_windowTitle_MetaData), Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_windowTitle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialPath = { "initialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenFileBrowser_Parms, initialPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialPath_MetaData), Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialFilename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialFilename = { "initialFilename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenFileBrowser_Parms, initialFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialFilename_MetaData), Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialFilename_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes_ValueProp = { "fileTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes_Key_KeyProp = { "fileTypes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes = { "fileTypes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenFileBrowser_Parms, fileTypes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes_MetaData), Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes_MetaData) };
	void Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_bIsMultiSelect_SetBit(void* Obj)
	{
		((UI_Statics_eventOpenFileBrowser_Parms*)Obj)->bIsMultiSelect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_bIsMultiSelect = { "bIsMultiSelect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventOpenFileBrowser_Parms), &Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_bIsMultiSelect_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_outSelectedFilenames_Inner = { "outSelectedFilenames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_outSelectedFilenames = { "outSelectedFilenames", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenFileBrowser_Parms, outSelectedFilenames), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Statics_eventOpenFileBrowser_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventOpenFileBrowser_Parms), &Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_windowTitle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_initialFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_fileTypes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_bIsMultiSelect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_outSelectedFilenames_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_outSelectedFilenames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|FileBrowser" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Open File Browser window\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Open File Browser window" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "OpenFileBrowser", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::UI_Statics_eventOpenFileBrowser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::UI_Statics_eventOpenFileBrowser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_OpenFileBrowser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_OpenFileBrowser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics
	{
		struct UI_Statics_eventOpenFileExplorer_Parms
		{
			FString absolutePath;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_absolutePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_absolutePath;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_absolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_absolutePath = { "absolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenFileExplorer_Parms, absolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_absolutePath_MetaData), Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_absolutePath_MetaData) };
	void Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Statics_eventOpenFileExplorer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventOpenFileExplorer_Parms), &Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_absolutePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|FileExplorer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief\x09This function will open a folder in the File Explorer of Windows (and potentially other platforms in the future if we decide to).\n\x09 * \n\x09 * @param\x09""absolutePath - This is the path to the folder the user would like to be opened.\n\x09 * @return\x09""bool - Returns true if the function is able to find the folder and opens the folder. Returns false if the function is unable\n\x09 *\x09\x09\x09to find the folder or open the folder.\n\x09 */" },
#endif
		{ "DisplayName", "VH Open File Explorer" },
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief       This function will open a folder in the File Explorer of Windows (and potentially other platforms in the future if we decide to).\n\n@param       absolutePath - This is the path to the folder the user would like to be opened.\n@return      bool - Returns true if the function is able to find the folder and opens the folder. Returns false if the function is unable\n                     to find the folder or open the folder." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "OpenFileExplorer", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::UI_Statics_eventOpenFileExplorer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::UI_Statics_eventOpenFileExplorer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_OpenFileExplorer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_OpenFileExplorer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics
	{
		struct UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms
		{
			FString dialogTitle;
			FString defaultPath;
			TMap<FString,FString> fileTypes;
			bool multiSelect;
			FScriptDelegate onDialogComplete;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dialogTitle_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_dialogTitle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_defaultPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_defaultPath;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fileTypes_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_fileTypes;
		static void NewProp_multiSelect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_multiSelect;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_onDialogComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle = { "dialogTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms, dialogTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle_MetaData), Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath = { "defaultPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms, defaultPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath_MetaData), Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_ValueProp = { "fileTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_Key_KeyProp = { "fileTypes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes = { "fileTypes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms, fileTypes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_MetaData), Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_MetaData) };
	void Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_multiSelect_SetBit(void* Obj)
	{
		((UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms*)Obj)->multiSelect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_multiSelect = { "multiSelect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms), &Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_multiSelect_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_onDialogComplete = { "onDialogComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms, onDialogComplete), Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1914651452
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_multiSelect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::NewProp_onDialogComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|FileBrowser" },
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "OpenNativeFileBrowserDialogAsync", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::UI_Statics_eventOpenNativeFileBrowserDialogAsync_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics
	{
		struct UI_Statics_eventParseExtensionsIntoArray_Parms
		{
			FString extensions;
			TArray<FString> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_extensions_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_extensions;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_extensions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_extensions = { "extensions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventParseExtensionsIntoArray_Parms, extensions), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_extensions_MetaData), Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_extensions_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventParseExtensionsIntoArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_extensions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|Archive" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Parses a string of extensions into an array while stripping extraneous characters -- e.g. passing in \".fbx;kml, *.xyz, .obj\" yields { \"fbx\", \"kml\", \"xyz\", \"obj\" } */" },
#endif
		{ "DisplayName", "VH Parse Extensions Into Array" },
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parses a string of extensions into an array while stripping extraneous characters -- e.g. passing in \".fbx;kml, *.xyz, .obj\" yields { \"fbx\", \"kml\", \"xyz\", \"obj\" }" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "ParseExtensionsIntoArray", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::UI_Statics_eventParseExtensionsIntoArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::UI_Statics_eventParseExtensionsIntoArray_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics
	{
		struct UI_Statics_eventSaveFileBrowser_Parms
		{
			FString windowTitle;
			FString initialPath;
			FString initialFilename;
			TMap<FString,FString> fileType;
			FString outSelectedFilename;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_windowTitle_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_windowTitle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialFilename;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileType_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileType_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fileType_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_fileType;
		static const UECodeGen_Private::FStrPropertyParams NewProp_outSelectedFilename;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_windowTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_windowTitle = { "windowTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveFileBrowser_Parms, windowTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_windowTitle_MetaData), Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_windowTitle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialPath = { "initialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveFileBrowser_Parms, initialPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialPath_MetaData), Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialFilename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialFilename = { "initialFilename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveFileBrowser_Parms, initialFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialFilename_MetaData), Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialFilename_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType_ValueProp = { "fileType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType_Key_KeyProp = { "fileType_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType = { "fileType", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveFileBrowser_Parms, fileType), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType_MetaData), Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_outSelectedFilename = { "outSelectedFilename", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveFileBrowser_Parms, outSelectedFilename), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Statics_eventSaveFileBrowser_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventSaveFileBrowser_Parms), &Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_windowTitle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_initialFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_fileType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_outSelectedFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|FileBrowser" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Save File Browser window\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Save File Browser window" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "SaveFileBrowser", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::UI_Statics_eventSaveFileBrowser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::UI_Statics_eventSaveFileBrowser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_SaveFileBrowser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_SaveFileBrowser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics
	{
		struct UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms
		{
			FString dialogTitle;
			FString defaultPath;
			FString initialFilename;
			TMap<FString,FString> fileTypes;
			FScriptDelegate onDialogComplete;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dialogTitle_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_dialogTitle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_defaultPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_defaultPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialFilename;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fileTypes_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_fileTypes;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_onDialogComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle = { "dialogTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms, dialogTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle_MetaData), Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath = { "defaultPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms, defaultPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath_MetaData), Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_initialFilename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_initialFilename = { "initialFilename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms, initialFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_initialFilename_MetaData), Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_initialFilename_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_ValueProp = { "fileTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_Key_KeyProp = { "fileTypes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes = { "fileTypes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms, fileTypes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_MetaData), Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_onDialogComplete = { "onDialogComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms, onDialogComplete), Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1914651452
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_dialogTitle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_defaultPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_initialFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_fileTypes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::NewProp_onDialogComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|FileBrowser" },
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "SaveNativeFileBrowserDialogAsync", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::UI_Statics_eventSaveNativeFileBrowserDialogAsync_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics
	{
		struct UI_Statics_eventSelectFileBrowser_Parms
		{
			FString windowTitle;
			FString initialPath;
			FString initialFilename;
			TMap<FString,FString> fileTypes;
			bool bIsSaving;
			bool bIsMultiSelect;
			TArray<FString> outSelectedFilenames;
			int32 outSelectedFilterIndex;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_windowTitle_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_windowTitle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialFilename;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileTypes_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fileTypes_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_fileTypes;
		static void NewProp_bIsSaving_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSaving;
		static void NewProp_bIsMultiSelect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMultiSelect;
		static const UECodeGen_Private::FStrPropertyParams NewProp_outSelectedFilenames_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_outSelectedFilenames;
		static const UECodeGen_Private::FIntPropertyParams NewProp_outSelectedFilterIndex;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_windowTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_windowTitle = { "windowTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFileBrowser_Parms, windowTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_windowTitle_MetaData), Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_windowTitle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialPath = { "initialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFileBrowser_Parms, initialPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialPath_MetaData), Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialFilename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialFilename = { "initialFilename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFileBrowser_Parms, initialFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialFilename_MetaData), Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialFilename_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes_ValueProp = { "fileTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes_Key_KeyProp = { "fileTypes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes = { "fileTypes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFileBrowser_Parms, fileTypes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes_MetaData), Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes_MetaData) };
	void Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsSaving_SetBit(void* Obj)
	{
		((UI_Statics_eventSelectFileBrowser_Parms*)Obj)->bIsSaving = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsSaving = { "bIsSaving", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventSelectFileBrowser_Parms), &Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsSaving_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsMultiSelect_SetBit(void* Obj)
	{
		((UI_Statics_eventSelectFileBrowser_Parms*)Obj)->bIsMultiSelect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsMultiSelect = { "bIsMultiSelect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventSelectFileBrowser_Parms), &Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsMultiSelect_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_outSelectedFilenames_Inner = { "outSelectedFilenames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_outSelectedFilenames = { "outSelectedFilenames", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFileBrowser_Parms, outSelectedFilenames), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_outSelectedFilterIndex = { "outSelectedFilterIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFileBrowser_Parms, outSelectedFilterIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Statics_eventSelectFileBrowser_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventSelectFileBrowser_Parms), &Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_windowTitle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_initialFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_fileTypes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsSaving,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_bIsMultiSelect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_outSelectedFilenames_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_outSelectedFilenames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_outSelectedFilterIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|FileBrowser" },
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "SelectFileBrowser", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::UI_Statics_eventSelectFileBrowser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::UI_Statics_eventSelectFileBrowser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_SelectFileBrowser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_SelectFileBrowser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics
	{
		struct UI_Statics_eventSelectFolderBrowser_Parms
		{
			FString windowTitle;
			FString initialPath;
			FString outSelectedFolder;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_windowTitle_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_windowTitle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initialPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_initialPath;
		static const UECodeGen_Private::FStrPropertyParams NewProp_outSelectedFolder;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_windowTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_windowTitle = { "windowTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFolderBrowser_Parms, windowTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_windowTitle_MetaData), Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_windowTitle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_initialPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_initialPath = { "initialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFolderBrowser_Parms, initialPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_initialPath_MetaData), Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_initialPath_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_outSelectedFolder = { "outSelectedFolder", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSelectFolderBrowser_Parms, outSelectedFolder), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Statics_eventSelectFolderBrowser_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventSelectFolderBrowser_Parms), &Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_windowTitle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_initialPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_outSelectedFolder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH_UI|FileBrowser" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Open Folder Browser window\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Open Folder Browser window" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "SelectFolderBrowser", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::UI_Statics_eventSelectFolderBrowser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::UI_Statics_eventSelectFolderBrowser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics
	{
		struct UI_Statics_eventSyncKeyboardFocus_Parms
		{
			UWidget* widget;
			bool bHasFocus;
			bool bAlreadyHadKeyboardFocus;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_widget;
		static void NewProp_bHasFocus_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasFocus;
		static void NewProp_bAlreadyHadKeyboardFocus_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlreadyHadKeyboardFocus;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_widget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_widget = { "widget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Statics_eventSyncKeyboardFocus_Parms, widget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_widget_MetaData), Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_widget_MetaData) };
	void Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bHasFocus_SetBit(void* Obj)
	{
		((UI_Statics_eventSyncKeyboardFocus_Parms*)Obj)->bHasFocus = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bHasFocus = { "bHasFocus", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventSyncKeyboardFocus_Parms), &Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bHasFocus_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bAlreadyHadKeyboardFocus_SetBit(void* Obj)
	{
		((UI_Statics_eventSyncKeyboardFocus_Parms*)Obj)->bAlreadyHadKeyboardFocus = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bAlreadyHadKeyboardFocus = { "bAlreadyHadKeyboardFocus", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Statics_eventSyncKeyboardFocus_Parms), &Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bAlreadyHadKeyboardFocus_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_widget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bHasFocus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::NewProp_bAlreadyHadKeyboardFocus,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Sets keyboard focus to widget if widget or any of its descendants has focus\n\x09*  \\param widget Widget to test and set focus\n\x09*  \\param bHasFocus Set to true if widget or descendants have focus\n\x09*  \\param bAlreadyHadKeyboardFocus Set to true if widget already had keyboard focus\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Sets keyboard focus to widget if widget or any of its descendants has focus\n      *  \\param widget Widget to test and set focus\n      *  \\param bHasFocus Set to true if widget or descendants have focus\n      *  \\param bAlreadyHadKeyboardFocus Set to true if widget already had keyboard focus" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Statics, nullptr, "SyncKeyboardFocus", nullptr, nullptr, Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::UI_Statics_eventSyncKeyboardFocus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::UI_Statics_eventSyncKeyboardFocus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_Statics);
	UClass* Z_Construct_UClass_UUI_Statics_NoRegister()
	{
		return UUI_Statics::StaticClass();
	}
	struct Z_Construct_UClass_UUI_Statics_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_Statics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Statics_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_Statics_Statics::FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature, "OnDialogComplete__DelegateSignature" }, // 1914651452
		{ &Z_Construct_UFunction_UUI_Statics_OpenFileBrowser, "OpenFileBrowser" }, // 2561150091
		{ &Z_Construct_UFunction_UUI_Statics_OpenFileExplorer, "OpenFileExplorer" }, // 489419823
		{ &Z_Construct_UFunction_UUI_Statics_OpenNativeFileBrowserDialogAsync, "OpenNativeFileBrowserDialogAsync" }, // 2060391158
		{ &Z_Construct_UFunction_UUI_Statics_ParseExtensionsIntoArray, "ParseExtensionsIntoArray" }, // 3660130154
		{ &Z_Construct_UFunction_UUI_Statics_SaveFileBrowser, "SaveFileBrowser" }, // 1282980663
		{ &Z_Construct_UFunction_UUI_Statics_SaveNativeFileBrowserDialogAsync, "SaveNativeFileBrowserDialogAsync" }, // 4132637180
		{ &Z_Construct_UFunction_UUI_Statics_SelectFileBrowser, "SelectFileBrowser" }, // 370947104
		{ &Z_Construct_UFunction_UUI_Statics_SelectFolderBrowser, "SelectFolderBrowser" }, // 2871909949
		{ &Z_Construct_UFunction_UUI_Statics_SyncKeyboardFocus, "SyncKeyboardFocus" }, // 195845408
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Statics_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Statics_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/UI_Statics.h" },
		{ "ModuleRelativePath", "Core/Public/UI_Statics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_Statics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_Statics>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_Statics_Statics::ClassParams = {
		&UUI_Statics::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Statics_Statics::Class_MetaDataParams), Z_Construct_UClass_UUI_Statics_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UUI_Statics()
	{
		if (!Z_Registration_Info_UClass_UUI_Statics.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_Statics.OuterSingleton, Z_Construct_UClass_UUI_Statics_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_Statics.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UUI_Statics>()
	{
		return UUI_Statics::StaticClass();
	}
	UUI_Statics::UUI_Statics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_Statics);
	UUI_Statics::~UUI_Statics() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_Statics, UUI_Statics::StaticClass, TEXT("UUI_Statics"), &Z_Registration_Info_UClass_UUI_Statics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_Statics), 2963356869U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_417503873(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
