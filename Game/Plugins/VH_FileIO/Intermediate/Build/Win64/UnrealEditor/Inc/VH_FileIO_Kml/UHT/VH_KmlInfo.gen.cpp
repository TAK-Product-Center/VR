// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_KmlInfo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_KmlInfo() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_FileIO_Kml();
	VH_FILEIO_KML_API UClass* Z_Construct_UClass_UVH_KmlInfo();
	VH_FILEIO_KML_API UClass* Z_Construct_UClass_UVH_KmlInfo_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVH_KmlInfo::execParse)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_kmlText);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Parse(Z_Param_kmlText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_KmlInfo::execCreate)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToFileArg);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_KmlInfo**)Z_Param__Result=UVH_KmlInfo::Create(Z_Param_fullPathToFileArg);
		P_NATIVE_END;
	}
	void UVH_KmlInfo::StaticRegisterNativesUVH_KmlInfo()
	{
		UClass* Class = UVH_KmlInfo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Create", &UVH_KmlInfo::execCreate },
			{ "Parse", &UVH_KmlInfo::execParse },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_KmlInfo_Create_Statics
	{
		struct VH_KmlInfo_eventCreate_Parms
		{
			FString fullPathToFileArg;
			UVH_KmlInfo* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToFileArg_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToFileArg;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::NewProp_fullPathToFileArg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::NewProp_fullPathToFileArg = { "fullPathToFileArg", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_KmlInfo_eventCreate_Parms, fullPathToFileArg), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::NewProp_fullPathToFileArg_MetaData), Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::NewProp_fullPathToFileArg_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_KmlInfo_eventCreate_Parms, ReturnValue), Z_Construct_UClass_UVH_KmlInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::NewProp_fullPathToFileArg,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|Kml" },
		{ "DisplayName", "VH Create KmlInfo" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_KmlInfo, nullptr, "Create", nullptr, nullptr, Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::VH_KmlInfo_eventCreate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::VH_KmlInfo_eventCreate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_KmlInfo_Create()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_KmlInfo_Create_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics
	{
		struct VH_KmlInfo_eventParse_Parms
		{
			FString kmlText;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_kmlText_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_kmlText;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_kmlText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_kmlText = { "kmlText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_KmlInfo_eventParse_Parms, kmlText), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_kmlText_MetaData), Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_kmlText_MetaData) };
	void Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_KmlInfo_eventParse_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_KmlInfo_eventParse_Parms), &Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_kmlText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhFileIO|Kml" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_KmlInfo, nullptr, "Parse", nullptr, nullptr, Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::VH_KmlInfo_eventParse_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::VH_KmlInfo_eventParse_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_KmlInfo_Parse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_KmlInfo_Parse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_KmlInfo);
	UClass* Z_Construct_UClass_UVH_KmlInfo_NoRegister()
	{
		return UVH_KmlInfo::StaticClass();
	}
	struct Z_Construct_UClass_UVH_KmlInfo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FullPathToFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FullPathToFile;
		static const UECodeGen_Private::FStrPropertyParams NewProp_XmlNSMap_ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_XmlNSMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_XmlNSMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_XmlNSMap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[];
#endif
		static void NewProp_bIsValid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_KmlInfo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO_Kml,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_KmlInfo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_KmlInfo_Create, "Create" }, // 353780918
		{ &Z_Construct_UFunction_UVH_KmlInfo_Parse, "Parse" }, // 2959379745
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_KmlInfo_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Core/Public/VH_KmlInfo.h" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlInfo.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_FullPathToFile_MetaData[] = {
		{ "Category", "VhFileIO|KmlInfo" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlInfo.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_FullPathToFile = { "FullPathToFile", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_KmlInfo, FullPathToFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_FullPathToFile_MetaData), Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_FullPathToFile_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap_ValueProp = { "XmlNSMap", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap_Key_KeyProp = { "XmlNSMap_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap_MetaData[] = {
		{ "Category", "VhFileIO|KmlInfo" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlInfo.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap = { "XmlNSMap", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_KmlInfo, XmlNSMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap_MetaData), Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_bIsValid_MetaData[] = {
		{ "Category", "VhFileIO|KmlInfo" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlInfo.h" },
	};
#endif
	void Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_bIsValid_SetBit(void* Obj)
	{
		((UVH_KmlInfo*)Obj)->bIsValid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_KmlInfo), &Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_bIsValid_MetaData), Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_bIsValid_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_KmlInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_FullPathToFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_XmlNSMap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_KmlInfo_Statics::NewProp_bIsValid,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_KmlInfo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_KmlInfo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_KmlInfo_Statics::ClassParams = {
		&UVH_KmlInfo::StaticClass,
		"VH_FileIO",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_KmlInfo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_KmlInfo_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_KmlInfo_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_KmlInfo()
	{
		if (!Z_Registration_Info_UClass_UVH_KmlInfo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_KmlInfo.OuterSingleton, Z_Construct_UClass_UVH_KmlInfo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_KmlInfo.OuterSingleton;
	}
	template<> VH_FILEIO_KML_API UClass* StaticClass<UVH_KmlInfo>()
	{
		return UVH_KmlInfo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_KmlInfo);
	UVH_KmlInfo::~UVH_KmlInfo() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlInfo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlInfo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_KmlInfo, UVH_KmlInfo::StaticClass, TEXT("UVH_KmlInfo"), &Z_Registration_Info_UClass_UVH_KmlInfo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_KmlInfo), 1509132498U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlInfo_h_378660099(TEXT("/Script/VH_FileIO_Kml"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlInfo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlInfo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
