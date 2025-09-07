// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Mesh/Public/VH_MeshInfo.h"
#include "VH_FileIOTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_MeshInfo() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_FileIO();
	VH_FILEIO_API UClass* Z_Construct_UClass_UVH_MeshInfo();
	VH_FILEIO_API UClass* Z_Construct_UClass_UVH_MeshInfo_NoRegister();
	VH_FILEIO_API UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportMeshData();
	VH_FILEIO_API UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportMeshNode();
	VH_FILEIO_API UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportOptions();
// End Cross Module References
	DEFINE_FUNCTION(UVH_MeshInfo::execGetDefaultImportOptions)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_meshFilename);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVH_MeshImportOptions*)Z_Param__Result=UVH_MeshInfo::GetDefaultImportOptions(Z_Param_meshFilename);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_MeshInfo::execCreate)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_meshFilename);
		P_GET_STRUCT_REF(FVH_MeshImportOptions,Z_Param_Out_importOptions);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_MeshInfo**)Z_Param__Result=UVH_MeshInfo::Create(Z_Param_meshFilename,Z_Param_Out_importOptions);
		P_NATIVE_END;
	}
	void UVH_MeshInfo::StaticRegisterNativesUVH_MeshInfo()
	{
		UClass* Class = UVH_MeshInfo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Create", &UVH_MeshInfo::execCreate },
			{ "GetDefaultImportOptions", &UVH_MeshInfo::execGetDefaultImportOptions },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_MeshInfo_Create_Statics
	{
		struct VH_MeshInfo_eventCreate_Parms
		{
			FString meshFilename;
			FVH_MeshImportOptions importOptions;
			UVH_MeshInfo* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_meshFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_meshFilename;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_importOptions_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_importOptions;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_meshFilename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_meshFilename = { "meshFilename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_MeshInfo_eventCreate_Parms, meshFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_meshFilename_MetaData), Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_meshFilename_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_importOptions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_importOptions = { "importOptions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_MeshInfo_eventCreate_Parms, importOptions), Z_Construct_UScriptStruct_FVH_MeshImportOptions, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_importOptions_MetaData), Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_importOptions_MetaData) }; // 3180495876
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_MeshInfo_eventCreate_Parms, ReturnValue), Z_Construct_UClass_UVH_MeshInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_meshFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_importOptions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|MeshInfo" },
		{ "DisplayName", "VH Create MeshInfo" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_MeshInfo, nullptr, "Create", nullptr, nullptr, Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::VH_MeshInfo_eventCreate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::VH_MeshInfo_eventCreate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_MeshInfo_Create()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_MeshInfo_Create_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics
	{
		struct VH_MeshInfo_eventGetDefaultImportOptions_Parms
		{
			FString meshFilename;
			FVH_MeshImportOptions ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_meshFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_meshFilename;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::NewProp_meshFilename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::NewProp_meshFilename = { "meshFilename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_MeshInfo_eventGetDefaultImportOptions_Parms, meshFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::NewProp_meshFilename_MetaData), Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::NewProp_meshFilename_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_MeshInfo_eventGetDefaultImportOptions_Parms, ReturnValue), Z_Construct_UScriptStruct_FVH_MeshImportOptions, METADATA_PARAMS(0, nullptr) }; // 3180495876
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::NewProp_meshFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|MeshInfo" },
		{ "DisplayName", "VH Create MeshInfo" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_MeshInfo, nullptr, "GetDefaultImportOptions", nullptr, nullptr, Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::VH_MeshInfo_eventGetDefaultImportOptions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::VH_MeshInfo_eventGetDefaultImportOptions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_MeshInfo);
	UClass* Z_Construct_UClass_UVH_MeshInfo_NoRegister()
	{
		return UVH_MeshInfo::StaticClass();
	}
	struct Z_Construct_UClass_UVH_MeshInfo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Filename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FullFilename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FullFilename;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[];
#endif
		static void NewProp_bIsValid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
		static const UECodeGen_Private::FStructPropertyParams NewProp_NodeList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_NodeList;
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshDataList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshDataList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_MeshDataList;
		static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaterialList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_MaterialList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImportOptions_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImportOptions;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnableLogDump_MetaData[];
#endif
		static void NewProp_EnableLogDump_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_EnableLogDump;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_MeshInfo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_MeshInfo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_MeshInfo_Create, "Create" }, // 738710577
		{ &Z_Construct_UFunction_UVH_MeshInfo_GetDefaultImportOptions, "GetDefaultImportOptions" }, // 3561570851
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Mesh/Public/VH_MeshInfo.h" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_Filename_MetaData[] = {
		{ "Category", "VhFileIO|MeshInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Filename for mesh to import. Absolute paths are allowed. If relative, it will be relative to project/game's Content folder. */" },
#endif
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Filename for mesh to import. Absolute paths are allowed. If relative, it will be relative to project/game's Content folder." },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_MeshInfo, Filename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_Filename_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_Filename_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_FullFilename_MetaData[] = {
		{ "Category", "VhFileIO|MeshInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Filename for mesh to import, including fully-qualified (i.e. absolute) path. */" },
#endif
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Filename for mesh to import, including fully-qualified (i.e. absolute) path." },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_FullFilename = { "FullFilename", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_MeshInfo, FullFilename), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_FullFilename_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_FullFilename_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_bIsValid_MetaData[] = {
		{ "Category", "VhFileIO|MeshInfo" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	void Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_bIsValid_SetBit(void* Obj)
	{
		((UVH_MeshInfo*)Obj)->bIsValid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_MeshInfo), &Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_bIsValid_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_bIsValid_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_NodeList_Inner = { "NodeList", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVH_MeshImportMeshNode, METADATA_PARAMS(0, nullptr) }; // 3443388292
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_NodeList_MetaData[] = {
		{ "Category", "VhFileIO|MeshInfo" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_NodeList = { "NodeList", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_MeshInfo, NodeList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_NodeList_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_NodeList_MetaData) }; // 3443388292
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MeshDataList_Inner = { "MeshDataList", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVH_MeshImportMeshData, METADATA_PARAMS(0, nullptr) }; // 1565652211
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MeshDataList_MetaData[] = {
		{ "Category", "VhFileIO|MeshInfo" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MeshDataList = { "MeshDataList", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_MeshInfo, MeshDataList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MeshDataList_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MeshDataList_MetaData) }; // 1565652211
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MaterialList_Inner = { "MaterialList", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MaterialList_MetaData[] = {
		{ "Category", "VhFileIO|MeshInfo" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MaterialList = { "MaterialList", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_MeshInfo, MaterialList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MaterialList_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MaterialList_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_ImportOptions_MetaData[] = {
		{ "Category", "VhFileIO|MeshInfo" },
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_ImportOptions = { "ImportOptions", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_MeshInfo, ImportOptions), Z_Construct_UScriptStruct_FVH_MeshImportOptions, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_ImportOptions_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_ImportOptions_MetaData) }; // 3180495876
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_EnableLogDump_MetaData[] = {
		{ "ModuleRelativePath", "Mesh/Public/VH_MeshInfo.h" },
	};
#endif
	void Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_EnableLogDump_SetBit(void* Obj)
	{
		((UVH_MeshInfo*)Obj)->EnableLogDump = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_EnableLogDump = { "EnableLogDump", nullptr, (EPropertyFlags)0x0020080000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_MeshInfo), &Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_EnableLogDump_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_EnableLogDump_MetaData), Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_EnableLogDump_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_MeshInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_Filename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_FullFilename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_bIsValid,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_NodeList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_NodeList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MeshDataList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MeshDataList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MaterialList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_MaterialList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_ImportOptions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_MeshInfo_Statics::NewProp_EnableLogDump,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_MeshInfo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_MeshInfo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_MeshInfo_Statics::ClassParams = {
		&UVH_MeshInfo::StaticClass,
		"VH_FileIO",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_MeshInfo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_MeshInfo_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_MeshInfo_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_MeshInfo()
	{
		if (!Z_Registration_Info_UClass_UVH_MeshInfo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_MeshInfo.OuterSingleton, Z_Construct_UClass_UVH_MeshInfo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_MeshInfo.OuterSingleton;
	}
	template<> VH_FILEIO_API UClass* StaticClass<UVH_MeshInfo>()
	{
		return UVH_MeshInfo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_MeshInfo);
	UVH_MeshInfo::~UVH_MeshInfo() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_MeshInfo, UVH_MeshInfo::StaticClass, TEXT("UVH_MeshInfo"), &Z_Registration_Info_UClass_UVH_MeshInfo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_MeshInfo), 1471358314U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_3720535907(TEXT("/Script/VH_FileIO"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
