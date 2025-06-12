// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Developer_PersistentSettings_XML.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_PersistentSettings_XML() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_PersistentSettings();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_XML();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_XML_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDeveloper_PersistentSettings_XML::execGetFullPathToXMLFile)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFullPathToXMLFile();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_PersistentSettings_XML::execSetFilename)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToXMLFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFilename(Z_Param_fullPathToXMLFile);
		P_NATIVE_END;
	}
	void UDeveloper_PersistentSettings_XML::StaticRegisterNativesUDeveloper_PersistentSettings_XML()
	{
		UClass* Class = UDeveloper_PersistentSettings_XML::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetFullPathToXMLFile", &UDeveloper_PersistentSettings_XML::execGetFullPathToXMLFile },
			{ "SetFilename", &UDeveloper_PersistentSettings_XML::execSetFilename },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics
	{
		struct Developer_PersistentSettings_XML_eventGetFullPathToXMLFile_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_PersistentSettings_XML_eventGetFullPathToXMLFile_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_PersistentSettings_XML.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_PersistentSettings_XML, nullptr, "GetFullPathToXMLFile", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::Developer_PersistentSettings_XML_eventGetFullPathToXMLFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::Developer_PersistentSettings_XML_eventGetFullPathToXMLFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics
	{
		struct Developer_PersistentSettings_XML_eventSetFilename_Parms
		{
			FString fullPathToXMLFile;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToXMLFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToXMLFile;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::NewProp_fullPathToXMLFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::NewProp_fullPathToXMLFile = { "fullPathToXMLFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_PersistentSettings_XML_eventSetFilename_Parms, fullPathToXMLFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::NewProp_fullPathToXMLFile_MetaData), Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::NewProp_fullPathToXMLFile_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::NewProp_fullPathToXMLFile,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * \\brief Set the GameSettings filename.  If already exists, this will also initialize the settings to the file's contents.\n\x09 * \\param fullPathToXMLFile The full path to the GameSettings file.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_PersistentSettings_XML.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Set the GameSettings filename.  If already exists, this will also initialize the settings to the file's contents.\n* \\param fullPathToXMLFile The full path to the GameSettings file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_PersistentSettings_XML, nullptr, "SetFilename", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::Developer_PersistentSettings_XML_eventSetFilename_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::Developer_PersistentSettings_XML_eventSetFilename_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_PersistentSettings_XML);
	UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_XML_NoRegister()
	{
		return UDeveloper_PersistentSettings_XML::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloper_PersistentSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_GetFullPathToXMLFile, "GetFullPathToXMLFile" }, // 1927506066
		{ &Z_Construct_UFunction_UDeveloper_PersistentSettings_XML_SetFilename, "SetFilename" }, // 1443840515
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/Developer_PersistentSettings_XML.h" },
		{ "ModuleRelativePath", "Core/Public/Developer_PersistentSettings_XML.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_PersistentSettings_XML>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::ClassParams = {
		&UDeveloper_PersistentSettings_XML::StaticClass,
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
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UDeveloper_PersistentSettings_XML()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_PersistentSettings_XML.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_PersistentSettings_XML.OuterSingleton, Z_Construct_UClass_UDeveloper_PersistentSettings_XML_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_PersistentSettings_XML.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_PersistentSettings_XML>()
	{
		return UDeveloper_PersistentSettings_XML::StaticClass();
	}
	UDeveloper_PersistentSettings_XML::UDeveloper_PersistentSettings_XML(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_PersistentSettings_XML);
	UDeveloper_PersistentSettings_XML::~UDeveloper_PersistentSettings_XML() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_XML_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_XML_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_PersistentSettings_XML, UDeveloper_PersistentSettings_XML::StaticClass, TEXT("UDeveloper_PersistentSettings_XML"), &Z_Registration_Info_UClass_UDeveloper_PersistentSettings_XML, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_PersistentSettings_XML), 2655118333U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_XML_h_3111015096(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_XML_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_XML_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
