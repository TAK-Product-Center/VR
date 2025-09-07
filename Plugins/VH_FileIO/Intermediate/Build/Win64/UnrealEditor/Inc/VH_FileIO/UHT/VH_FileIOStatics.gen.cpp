// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_FileIOStatics.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_FileIOStatics() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_FileIO();
	VH_FILEIO_API UClass* Z_Construct_UClass_UVH_FileIOStatics();
	VH_FILEIO_API UClass* Z_Construct_UClass_UVH_FileIOStatics_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVH_FileIOStatics::execOpenFileWithDefaultProgram)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_filepath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_FileIOStatics::OpenFileWithDefaultProgram(Z_Param_filepath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execIsZipArchive)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_FileIOStatics::IsZipArchive(Z_Param_fullPathToFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execParseExtensionsIntoArray)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_extensions);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=UVH_FileIOStatics::ParseExtensionsIntoArray(Z_Param_extensions);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execDirectoryOrFileExistsInZip)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToZip);
		P_GET_PROPERTY(FStrProperty,Z_Param_targetName);
		P_GET_UBOOL(Z_Param_isDir);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_FileIOStatics::DirectoryOrFileExistsInZip(Z_Param_fullPathToZip,Z_Param_targetName,Z_Param_isDir);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execUnzipFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_inFilename);
		P_GET_PROPERTY(FStrProperty,Z_Param_outDirectory);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVH_FileIOStatics::UnzipFile(Z_Param_inFilename,Z_Param_outDirectory);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execZipFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToZip);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_fullPathToNameInZip);
		P_GET_UBOOL(Z_Param_bOverwrite);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVH_FileIOStatics::ZipFile(Z_Param_fullPathToZip,Z_Param_Out_fullPathToNameInZip,Z_Param_bOverwrite);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execLoadAssetsInPath)
	{
		P_GET_TARRAY_REF(UObject*,Z_Param_Out_assets);
		P_GET_PROPERTY(FStrProperty,Z_Param_searchRootDir);
		P_GET_UBOOL(Z_Param_bIsRecursive);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_FileIOStatics::LoadAssetsInPath(Z_Param_Out_assets,Z_Param_searchRootDir,Z_Param_bIsRecursive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execGetDirectoriesInPath)
	{
		P_GET_TARRAY_REF(FString,Z_Param_Out_directories);
		P_GET_PROPERTY(FStrProperty,Z_Param_searchRootDir);
		P_GET_UBOOL(Z_Param_bIsRecursive);
		P_GET_UBOOL(Z_Param_bIncludeRootPath);
		P_GET_UBOOL(Z_Param_bAbsolutePaths);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_FileIOStatics::GetDirectoriesInPath(Z_Param_Out_directories,Z_Param_searchRootDir,Z_Param_bIsRecursive,Z_Param_bIncludeRootPath,Z_Param_bAbsolutePaths);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_FileIOStatics::execGetFilesInPath)
	{
		P_GET_TARRAY_REF(FString,Z_Param_Out_files);
		P_GET_PROPERTY(FStrProperty,Z_Param_searchRootDir);
		P_GET_PROPERTY(FStrProperty,Z_Param_fileExtensionPriority);
		P_GET_UBOOL(Z_Param_bIsRecursive);
		P_GET_UBOOL(Z_Param_bIncludeRootPath);
		P_GET_UBOOL(Z_Param_bAbsolutePaths);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_FileIOStatics::GetFilesInPath(Z_Param_Out_files,Z_Param_searchRootDir,Z_Param_fileExtensionPriority,Z_Param_bIsRecursive,Z_Param_bIncludeRootPath,Z_Param_bAbsolutePaths);
		P_NATIVE_END;
	}
	void UVH_FileIOStatics::StaticRegisterNativesUVH_FileIOStatics()
	{
		UClass* Class = UVH_FileIOStatics::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DirectoryOrFileExistsInZip", &UVH_FileIOStatics::execDirectoryOrFileExistsInZip },
			{ "GetDirectoriesInPath", &UVH_FileIOStatics::execGetDirectoriesInPath },
			{ "GetFilesInPath", &UVH_FileIOStatics::execGetFilesInPath },
			{ "IsZipArchive", &UVH_FileIOStatics::execIsZipArchive },
			{ "LoadAssetsInPath", &UVH_FileIOStatics::execLoadAssetsInPath },
			{ "OpenFileWithDefaultProgram", &UVH_FileIOStatics::execOpenFileWithDefaultProgram },
			{ "ParseExtensionsIntoArray", &UVH_FileIOStatics::execParseExtensionsIntoArray },
			{ "UnzipFile", &UVH_FileIOStatics::execUnzipFile },
			{ "ZipFile", &UVH_FileIOStatics::execZipFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics
	{
		struct VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms
		{
			FString fullPathToZip;
			FString targetName;
			bool isDir;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToZip_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToZip;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_targetName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_targetName;
		static void NewProp_isDir_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isDir;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_fullPathToZip_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_fullPathToZip = { "fullPathToZip", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms, fullPathToZip), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_fullPathToZip_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_fullPathToZip_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_targetName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_targetName = { "targetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms, targetName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_targetName_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_targetName_MetaData) };
	void Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_isDir_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms*)Obj)->isDir = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_isDir = { "isDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_isDir_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_fullPathToZip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_targetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_isDir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|Archive" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Checks if directory or file exists at root level of zip file */" },
#endif
		{ "DisplayName", "VH Directory Exists In Zip" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks if directory or file exists at root level of zip file" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "DirectoryOrFileExistsInZip", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::VH_FileIOStatics_eventDirectoryOrFileExistsInZip_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics
	{
		struct VH_FileIOStatics_eventGetDirectoriesInPath_Parms
		{
			TArray<FString> directories;
			FString searchRootDir;
			bool bIsRecursive;
			bool bIncludeRootPath;
			bool bAbsolutePaths;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_directories_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_directories;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_searchRootDir_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_searchRootDir;
		static void NewProp_bIsRecursive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRecursive;
		static void NewProp_bIncludeRootPath_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeRootPath;
		static void NewProp_bAbsolutePaths_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAbsolutePaths;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_directories_Inner = { "directories", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_directories = { "directories", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventGetDirectoriesInPath_Parms, directories), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_searchRootDir_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_searchRootDir = { "searchRootDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventGetDirectoriesInPath_Parms, searchRootDir), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_searchRootDir_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_searchRootDir_MetaData) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIsRecursive_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetDirectoriesInPath_Parms*)Obj)->bIsRecursive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIsRecursive = { "bIsRecursive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetDirectoriesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIsRecursive_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIncludeRootPath_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetDirectoriesInPath_Parms*)Obj)->bIncludeRootPath = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIncludeRootPath = { "bIncludeRootPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetDirectoriesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIncludeRootPath_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bAbsolutePaths_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetDirectoriesInPath_Parms*)Obj)->bAbsolutePaths = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bAbsolutePaths = { "bAbsolutePaths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetDirectoriesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bAbsolutePaths_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetDirectoriesInPath_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetDirectoriesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_directories_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_directories,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_searchRootDir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIsRecursive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bIncludeRootPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_bAbsolutePaths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get list of all directories (and optionally, in all subdirectories) in the specified 'searchRootDir'.\n\x09 * Relative directory paths are relative to the project's Content dir. Returns FALSE if aborted.\n\x09 */" },
#endif
		{ "CPP_Default_bAbsolutePaths", "false" },
		{ "CPP_Default_bIncludeRootPath", "true" },
		{ "CPP_Default_bIsRecursive", "true" },
		{ "DisplayName", "VH Get Directories In Path" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get list of all directories (and optionally, in all subdirectories) in the specified 'searchRootDir'.\nRelative directory paths are relative to the project's Content dir. Returns FALSE if aborted." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "GetDirectoriesInPath", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::VH_FileIOStatics_eventGetDirectoriesInPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::VH_FileIOStatics_eventGetDirectoriesInPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics
	{
		struct VH_FileIOStatics_eventGetFilesInPath_Parms
		{
			TArray<FString> files;
			FString searchRootDir;
			FString fileExtensionPriority;
			bool bIsRecursive;
			bool bIncludeRootPath;
			bool bAbsolutePaths;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_files_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_files;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_searchRootDir_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_searchRootDir;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fileExtensionPriority_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fileExtensionPriority;
		static void NewProp_bIsRecursive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRecursive;
		static void NewProp_bIncludeRootPath_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeRootPath;
		static void NewProp_bAbsolutePaths_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAbsolutePaths;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_files_Inner = { "files", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_files = { "files", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventGetFilesInPath_Parms, files), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_searchRootDir_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_searchRootDir = { "searchRootDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventGetFilesInPath_Parms, searchRootDir), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_searchRootDir_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_searchRootDir_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_fileExtensionPriority_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_fileExtensionPriority = { "fileExtensionPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventGetFilesInPath_Parms, fileExtensionPriority), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_fileExtensionPriority_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_fileExtensionPriority_MetaData) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIsRecursive_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetFilesInPath_Parms*)Obj)->bIsRecursive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIsRecursive = { "bIsRecursive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetFilesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIsRecursive_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIncludeRootPath_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetFilesInPath_Parms*)Obj)->bIncludeRootPath = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIncludeRootPath = { "bIncludeRootPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetFilesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIncludeRootPath_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bAbsolutePaths_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetFilesInPath_Parms*)Obj)->bAbsolutePaths = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bAbsolutePaths = { "bAbsolutePaths", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetFilesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bAbsolutePaths_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventGetFilesInPath_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventGetFilesInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_files_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_files,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_searchRootDir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_fileExtensionPriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIsRecursive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bIncludeRootPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_bAbsolutePaths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get list of all files in a directory (and optionally, in all subdirectories) that match an extension. All files are listed\n\x09 * if 'fileExtension' is left blank. Can specify multiple extensions separated by ',' or ';' (e.g. \"jpg,png\").\n\x09 * Relative directory paths are relative to the root dir. Found files are appended to 'files' array in order of extension list.\n\x09 * Returns TRUE if any files are found and appended.\n\x09 */" },
#endif
		{ "CPP_Default_bAbsolutePaths", "false" },
		{ "CPP_Default_bIncludeRootPath", "true" },
		{ "CPP_Default_bIsRecursive", "true" },
		{ "CPP_Default_fileExtensionPriority", "" },
		{ "DisplayName", "VH Get Files In Path" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get list of all files in a directory (and optionally, in all subdirectories) that match an extension. All files are listed\nif 'fileExtension' is left blank. Can specify multiple extensions separated by ',' or ';' (e.g. \"jpg,png\").\nRelative directory paths are relative to the root dir. Found files are appended to 'files' array in order of extension list.\nReturns TRUE if any files are found and appended." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "GetFilesInPath", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::VH_FileIOStatics_eventGetFilesInPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::VH_FileIOStatics_eventGetFilesInPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics
	{
		struct VH_FileIOStatics_eventIsZipArchive_Parms
		{
			FString fullPathToFile;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToFile;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_fullPathToFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_fullPathToFile = { "fullPathToFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventIsZipArchive_Parms, fullPathToFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_fullPathToFile_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_fullPathToFile_MetaData) };
	void Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventIsZipArchive_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventIsZipArchive_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_fullPathToFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|Archive" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "IsZipArchive", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::VH_FileIOStatics_eventIsZipArchive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::VH_FileIOStatics_eventIsZipArchive_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics
	{
		struct VH_FileIOStatics_eventLoadAssetsInPath_Parms
		{
			TArray<UObject*> assets;
			FString searchRootDir;
			bool bIsRecursive;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_assets_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_assets;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_searchRootDir_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_searchRootDir;
		static void NewProp_bIsRecursive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRecursive;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_assets_Inner = { "assets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_assets = { "assets", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventLoadAssetsInPath_Parms, assets), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_searchRootDir_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_searchRootDir = { "searchRootDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventLoadAssetsInPath_Parms, searchRootDir), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_searchRootDir_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_searchRootDir_MetaData) };
	void Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_bIsRecursive_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventLoadAssetsInPath_Parms*)Obj)->bIsRecursive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_bIsRecursive = { "bIsRecursive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventLoadAssetsInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_bIsRecursive_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventLoadAssetsInPath_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventLoadAssetsInPath_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_assets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_assets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_searchRootDir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_bIsRecursive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get list of all uassets in a directory (and optionally, in all subdirectories). This also loads the assets into memory.\n\x09 * Relative directory paths are relative to the project's Content dir. Returns FALSE if aborted.\n\x09 */" },
#endif
		{ "CPP_Default_bIsRecursive", "true" },
		{ "DisplayName", "VH Load Assets In Path" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get list of all uassets in a directory (and optionally, in all subdirectories). This also loads the assets into memory.\nRelative directory paths are relative to the project's Content dir. Returns FALSE if aborted." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "LoadAssetsInPath", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::VH_FileIOStatics_eventLoadAssetsInPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::VH_FileIOStatics_eventLoadAssetsInPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics
	{
		struct VH_FileIOStatics_eventOpenFileWithDefaultProgram_Parms
		{
			FString filepath;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_filepath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_filepath;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_filepath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_filepath = { "filepath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventOpenFileWithDefaultProgram_Parms, filepath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_filepath_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_filepath_MetaData) };
	void Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventOpenFileWithDefaultProgram_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventOpenFileWithDefaultProgram_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_filepath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|FileBrowser" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "OpenFileWithDefaultProgram", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::VH_FileIOStatics_eventOpenFileWithDefaultProgram_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::VH_FileIOStatics_eventOpenFileWithDefaultProgram_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics
	{
		struct VH_FileIOStatics_eventParseExtensionsIntoArray_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_extensions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_extensions = { "extensions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventParseExtensionsIntoArray_Parms, extensions), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_extensions_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_extensions_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventParseExtensionsIntoArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_extensions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|Archive" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Parses a string of extensions into an array while stripping extraneous characters -- e.g. passing in \".fbx;kml, *.xyz, .obj\" yields { \"fbx\", \"kml\", \"xyz\", \"obj\" } */" },
#endif
		{ "DisplayName", "VH Parse Extensions Into Array" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parses a string of extensions into an array while stripping extraneous characters -- e.g. passing in \".fbx;kml, *.xyz, .obj\" yields { \"fbx\", \"kml\", \"xyz\", \"obj\" }" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "ParseExtensionsIntoArray", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::VH_FileIOStatics_eventParseExtensionsIntoArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::VH_FileIOStatics_eventParseExtensionsIntoArray_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics
	{
		struct VH_FileIOStatics_eventUnzipFile_Parms
		{
			FString inFilename;
			FString outDirectory;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_inFilename;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_outDirectory_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_outDirectory;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_inFilename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_inFilename = { "inFilename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventUnzipFile_Parms, inFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_inFilename_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_inFilename_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_outDirectory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_outDirectory = { "outDirectory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventUnzipFile_Parms, outDirectory), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_outDirectory_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_outDirectory_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_inFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::NewProp_outDirectory,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|Archive" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unzip inFilename to outDirectory */" },
#endif
		{ "DisplayName", "VH Unzip File" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unzip inFilename to outDirectory" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "UnzipFile", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::VH_FileIOStatics_eventUnzipFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::VH_FileIOStatics_eventUnzipFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics
	{
		struct VH_FileIOStatics_eventZipFile_Parms
		{
			FString fullPathToZip;
			TMap<FString,FString> fullPathToNameInZip;
			bool bOverwrite;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToZip_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToZip;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToNameInZip_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToNameInZip_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToNameInZip_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_fullPathToNameInZip;
		static void NewProp_bOverwrite_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverwrite;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToZip_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToZip = { "fullPathToZip", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventZipFile_Parms, fullPathToZip), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToZip_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToZip_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip_ValueProp = { "fullPathToNameInZip", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip_Key_KeyProp = { "fullPathToNameInZip_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip = { "fullPathToNameInZip", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_FileIOStatics_eventZipFile_Parms, fullPathToNameInZip), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip_MetaData), Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip_MetaData) };
	void Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_bOverwrite_SetBit(void* Obj)
	{
		((VH_FileIOStatics_eventZipFile_Parms*)Obj)->bOverwrite = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_bOverwrite = { "bOverwrite", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_FileIOStatics_eventZipFile_Parms), &Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_bOverwrite_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToZip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_fullPathToNameInZip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::NewProp_bOverwrite,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|Archive" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Zip fullPathToFiles to fullPathToZip */" },
#endif
		{ "CPP_Default_bOverwrite", "true" },
		{ "DisplayName", "VH Zip Files" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Zip fullPathToFiles to fullPathToZip" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_FileIOStatics, nullptr, "ZipFile", nullptr, nullptr, Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::VH_FileIOStatics_eventZipFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::VH_FileIOStatics_eventZipFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_FileIOStatics_ZipFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_FileIOStatics_ZipFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_FileIOStatics);
	UClass* Z_Construct_UClass_UVH_FileIOStatics_NoRegister()
	{
		return UVH_FileIOStatics::StaticClass();
	}
	struct Z_Construct_UClass_UVH_FileIOStatics_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_FileIOStatics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_FileIOStatics_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_FileIOStatics_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_FileIOStatics_DirectoryOrFileExistsInZip, "DirectoryOrFileExistsInZip" }, // 2195758722
		{ &Z_Construct_UFunction_UVH_FileIOStatics_GetDirectoriesInPath, "GetDirectoriesInPath" }, // 705149692
		{ &Z_Construct_UFunction_UVH_FileIOStatics_GetFilesInPath, "GetFilesInPath" }, // 3101661604
		{ &Z_Construct_UFunction_UVH_FileIOStatics_IsZipArchive, "IsZipArchive" }, // 3610341282
		{ &Z_Construct_UFunction_UVH_FileIOStatics_LoadAssetsInPath, "LoadAssetsInPath" }, // 193474284
		{ &Z_Construct_UFunction_UVH_FileIOStatics_OpenFileWithDefaultProgram, "OpenFileWithDefaultProgram" }, // 895215062
		{ &Z_Construct_UFunction_UVH_FileIOStatics_ParseExtensionsIntoArray, "ParseExtensionsIntoArray" }, // 285697058
		{ &Z_Construct_UFunction_UVH_FileIOStatics_UnzipFile, "UnzipFile" }, // 1825113187
		{ &Z_Construct_UFunction_UVH_FileIOStatics_ZipFile, "ZipFile" }, // 152539019
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_FileIOStatics_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_FileIOStatics_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/VH_FileIOStatics.h" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOStatics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_FileIOStatics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_FileIOStatics>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_FileIOStatics_Statics::ClassParams = {
		&UVH_FileIOStatics::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_FileIOStatics_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_FileIOStatics_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_FileIOStatics()
	{
		if (!Z_Registration_Info_UClass_UVH_FileIOStatics.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_FileIOStatics.OuterSingleton, Z_Construct_UClass_UVH_FileIOStatics_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_FileIOStatics.OuterSingleton;
	}
	template<> VH_FILEIO_API UClass* StaticClass<UVH_FileIOStatics>()
	{
		return UVH_FileIOStatics::StaticClass();
	}
	UVH_FileIOStatics::UVH_FileIOStatics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_FileIOStatics);
	UVH_FileIOStatics::~UVH_FileIOStatics() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_FileIOStatics, UVH_FileIOStatics::StaticClass, TEXT("UVH_FileIOStatics"), &Z_Registration_Info_UClass_UVH_FileIOStatics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_FileIOStatics), 4003039402U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_3341238618(TEXT("/Script/VH_FileIO"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
