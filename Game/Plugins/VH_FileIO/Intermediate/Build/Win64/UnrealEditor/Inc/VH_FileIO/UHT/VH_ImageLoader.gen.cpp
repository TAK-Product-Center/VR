// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Misc/Public/VH_ImageLoader.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_ImageLoader() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_FileIO();
	VH_FILEIO_API UClass* Z_Construct_UClass_UVH_ImageLoader();
	VH_FILEIO_API UClass* Z_Construct_UClass_UVH_ImageLoader_NoRegister();
	VH_FILEIO_API UFunction* Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics
	{
		struct VH_ImageLoader_eventOnImageLoadCompleted_Parms
		{
			UTexture2D* Texture;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventOnImageLoadCompleted_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::NewProp_Texture,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Misc/Public/VH_ImageLoader.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_ImageLoader, nullptr, "OnImageLoadCompleted__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::VH_ImageLoader_eventOnImageLoadCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::VH_ImageLoader_eventOnImageLoadCompleted_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_ImageLoader::FOnImageLoadCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnImageLoadCompleted, UTexture2D* Texture)
{
	struct VH_ImageLoader_eventOnImageLoadCompleted_Parms
	{
		UTexture2D* Texture;
	};
	VH_ImageLoader_eventOnImageLoadCompleted_Parms Parms;
	Parms.Texture=Texture;
	OnImageLoadCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UVH_ImageLoader::execLoadImageFromDB)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_dbPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_dbQuery);
		P_GET_PROPERTY(FStrProperty,Z_Param_blobColumn);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_pixelData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_ImageLoader::LoadImageFromDB(Z_Param_dbPath,Z_Param_dbQuery,Z_Param_blobColumn,Z_Param_Out_pixelData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_ImageLoader::execLoadImageFromDisk)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_imagePath);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_scaledDimensions);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_originalDimensions);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_pixelData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_ImageLoader::LoadImageFromDisk(Z_Param_imagePath,Z_Param_Out_scaledDimensions,Z_Param_Out_originalDimensions,Z_Param_Out_pixelData);
		P_NATIVE_END;
	}
	void UVH_ImageLoader::StaticRegisterNativesUVH_ImageLoader()
	{
		UClass* Class = UVH_ImageLoader::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadImageFromDB", &UVH_ImageLoader::execLoadImageFromDB },
			{ "LoadImageFromDisk", &UVH_ImageLoader::execLoadImageFromDisk },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics
	{
		struct VH_ImageLoader_eventLoadImageFromDB_Parms
		{
			FString dbPath;
			FString dbQuery;
			FString blobColumn;
			TArray<uint8> pixelData;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dbPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_dbPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dbQuery_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_dbQuery;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_blobColumn_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_blobColumn;
		static const UECodeGen_Private::FBytePropertyParams NewProp_pixelData_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_pixelData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbPath = { "dbPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDB_Parms, dbPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbPath_MetaData), Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbQuery_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbQuery = { "dbQuery", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDB_Parms, dbQuery), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbQuery_MetaData), Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbQuery_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_blobColumn_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_blobColumn = { "blobColumn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDB_Parms, blobColumn), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_blobColumn_MetaData), Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_blobColumn_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_pixelData_Inner = { "pixelData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_pixelData = { "pixelData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDB_Parms, pixelData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_ImageLoader_eventLoadImageFromDB_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_ImageLoader_eventLoadImageFromDB_Parms), &Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_dbQuery,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_blobColumn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_pixelData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_pixelData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Misc/Public/VH_ImageLoader.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_ImageLoader, nullptr, "LoadImageFromDB", nullptr, nullptr, Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::VH_ImageLoader_eventLoadImageFromDB_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::VH_ImageLoader_eventLoadImageFromDB_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics
	{
		struct VH_ImageLoader_eventLoadImageFromDisk_Parms
		{
			FString imagePath;
			FVector2D scaledDimensions;
			FVector2D originalDimensions;
			TArray<uint8> pixelData;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_imagePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_imagePath;
		static const UECodeGen_Private::FStructPropertyParams NewProp_scaledDimensions;
		static const UECodeGen_Private::FStructPropertyParams NewProp_originalDimensions;
		static const UECodeGen_Private::FBytePropertyParams NewProp_pixelData_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_pixelData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_imagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_imagePath = { "imagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDisk_Parms, imagePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_imagePath_MetaData), Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_imagePath_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_scaledDimensions = { "scaledDimensions", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDisk_Parms, scaledDimensions), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_originalDimensions = { "originalDimensions", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDisk_Parms, originalDimensions), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_pixelData_Inner = { "pixelData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_pixelData = { "pixelData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ImageLoader_eventLoadImageFromDisk_Parms, pixelData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_ImageLoader_eventLoadImageFromDisk_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_ImageLoader_eventLoadImageFromDisk_Parms), &Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_imagePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_scaledDimensions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_originalDimensions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_pixelData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_pixelData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09Loads an image file from disk into a texture. This will block the calling thread until completed. Scales to nearest power of 2.\n\x09@return A texture created from the loaded image file.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Misc/Public/VH_ImageLoader.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Loads an image file from disk into a texture. This will block the calling thread until completed. Scales to nearest power of 2.\n@return A texture created from the loaded image file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_ImageLoader, nullptr, "LoadImageFromDisk", nullptr, nullptr, Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::VH_ImageLoader_eventLoadImageFromDisk_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::VH_ImageLoader_eventLoadImageFromDisk_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_ImageLoader);
	UClass* Z_Construct_UClass_UVH_ImageLoader_NoRegister()
	{
		return UVH_ImageLoader::StaticClass();
	}
	struct Z_Construct_UClass_UVH_ImageLoader_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnLoadCompleted_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLoadCompleted;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_ImageLoader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ImageLoader_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_ImageLoader_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDB, "LoadImageFromDB" }, // 3785492154
		{ &Z_Construct_UFunction_UVH_ImageLoader_LoadImageFromDisk, "LoadImageFromDisk" }, // 1136191071
		{ &Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature, "OnImageLoadCompleted__DelegateSignature" }, // 52484532
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ImageLoader_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_ImageLoader_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\nUtility class for asynchronously loading an image into a texture.\nAllows Blueprint scripts to request asynchronous loading of an image and be notified when loading is complete.\n*/" },
#endif
		{ "IncludePath", "Misc/Public/VH_ImageLoader.h" },
		{ "ModuleRelativePath", "Misc/Public/VH_ImageLoader.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Utility class for asynchronously loading an image into a texture.\nAllows Blueprint scripts to request asynchronous loading of an image and be notified when loading is complete." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_ImageLoader_Statics::NewProp_OnLoadCompleted_MetaData[] = {
		{ "ModuleRelativePath", "Misc/Public/VH_ImageLoader.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_ImageLoader_Statics::NewProp_OnLoadCompleted = { "OnLoadCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_ImageLoader, OnLoadCompleted), Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ImageLoader_Statics::NewProp_OnLoadCompleted_MetaData), Z_Construct_UClass_UVH_ImageLoader_Statics::NewProp_OnLoadCompleted_MetaData) }; // 52484532
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_ImageLoader_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_ImageLoader_Statics::NewProp_OnLoadCompleted,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_ImageLoader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_ImageLoader>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_ImageLoader_Statics::ClassParams = {
		&UVH_ImageLoader::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_ImageLoader_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ImageLoader_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ImageLoader_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_ImageLoader_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ImageLoader_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_ImageLoader()
	{
		if (!Z_Registration_Info_UClass_UVH_ImageLoader.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_ImageLoader.OuterSingleton, Z_Construct_UClass_UVH_ImageLoader_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_ImageLoader.OuterSingleton;
	}
	template<> VH_FILEIO_API UClass* StaticClass<UVH_ImageLoader>()
	{
		return UVH_ImageLoader::StaticClass();
	}
	UVH_ImageLoader::UVH_ImageLoader(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_ImageLoader);
	UVH_ImageLoader::~UVH_ImageLoader() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_ImageLoader, UVH_ImageLoader::StaticClass, TEXT("UVH_ImageLoader"), &Z_Registration_Info_UClass_UVH_ImageLoader, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_ImageLoader), 3321444290U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_3720383699(TEXT("/Script/VH_FileIO"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
