// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_Globe/Public/VH_GlobeReferenceActor_ENU.h"
#include "VH_GlobeMath/Public/VH_GeodeticCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GlobeReferenceActor_ENU() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_Globe();
	VH_GLOBE_API UClass* Z_Construct_UClass_AVH_GlobeReferenceActor();
	VH_GLOBE_API UClass* Z_Construct_UClass_AVH_GlobeReferenceActor_ENU();
	VH_GLOBE_API UClass* Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_NoRegister();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord3D();
// End Cross Module References
	DEFINE_FUNCTION(AVH_GlobeReferenceActor_ENU::execSetGeodeticLocation)
	{
		P_GET_STRUCT_REF(FGeodeticCoord3D,Z_Param_Out_coordinate);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGeodeticLocation(Z_Param_Out_coordinate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor_ENU::execGetLocation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGeodeticCoord3D*)Z_Param__Result=P_THIS->GetLocation();
		P_NATIVE_END;
	}
	void AVH_GlobeReferenceActor_ENU::StaticRegisterNativesAVH_GlobeReferenceActor_ENU()
	{
		UClass* Class = AVH_GlobeReferenceActor_ENU::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetLocation", &AVH_GlobeReferenceActor_ENU::execGetLocation },
			{ "SetGeodeticLocation", &AVH_GlobeReferenceActor_ENU::execSetGeodeticLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics
	{
		struct VH_GlobeReferenceActor_ENU_eventGetLocation_Parms
		{
			FGeodeticCoord3D ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_ENU_eventGetLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(0, nullptr) }; // 3754836998
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor_ENU.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor_ENU, nullptr, "GetLocation", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::VH_GlobeReferenceActor_ENU_eventGetLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::VH_GlobeReferenceActor_ENU_eventGetLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics
	{
		struct VH_GlobeReferenceActor_ENU_eventSetGeodeticLocation_Parms
		{
			FGeodeticCoord3D coordinate;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_coordinate_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_coordinate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::NewProp_coordinate_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::NewProp_coordinate = { "coordinate", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_ENU_eventSetGeodeticLocation_Parms, coordinate), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::NewProp_coordinate_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::NewProp_coordinate_MetaData) }; // 3754836998
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::NewProp_coordinate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// TODO: Switch to string-based BP version, then create double-precision native version!\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor_ENU.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "TODO: Switch to string-based BP version, then create double-precision native version!" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor_ENU, nullptr, "SetGeodeticLocation", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::VH_GlobeReferenceActor_ENU_eventSetGeodeticLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::VH_GlobeReferenceActor_ENU_eventSetGeodeticLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_GlobeReferenceActor_ENU);
	UClass* Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_NoRegister()
	{
		return AVH_GlobeReferenceActor_ENU::StaticClass();
	}
	struct Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeoLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GeoLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVH_GlobeReferenceActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Globe,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_GetLocation, "GetLocation" }, // 3170658424
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_ENU_SetGeodeticLocation, "SetGeodeticLocation" }, // 2198848740
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VH_GlobeReferenceActor_ENU.h" },
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor_ENU.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::NewProp_GeoLocation_MetaData[] = {
		{ "Category", "VH_GlobeReferenceActor_ENU" },
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor_ENU.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::NewProp_GeoLocation = { "GeoLocation", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_GlobeReferenceActor_ENU, GeoLocation), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::NewProp_GeoLocation_MetaData), Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::NewProp_GeoLocation_MetaData) }; // 3754836998
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::NewProp_GeoLocation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_GlobeReferenceActor_ENU>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::ClassParams = {
		&AVH_GlobeReferenceActor_ENU::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AVH_GlobeReferenceActor_ENU()
	{
		if (!Z_Registration_Info_UClass_AVH_GlobeReferenceActor_ENU.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_GlobeReferenceActor_ENU.OuterSingleton, Z_Construct_UClass_AVH_GlobeReferenceActor_ENU_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_GlobeReferenceActor_ENU.OuterSingleton;
	}
	template<> VH_GLOBE_API UClass* StaticClass<AVH_GlobeReferenceActor_ENU>()
	{
		return AVH_GlobeReferenceActor_ENU::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_GlobeReferenceActor_ENU);
	AVH_GlobeReferenceActor_ENU::~AVH_GlobeReferenceActor_ENU() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_ENU_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_ENU_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_GlobeReferenceActor_ENU, AVH_GlobeReferenceActor_ENU::StaticClass, TEXT("AVH_GlobeReferenceActor_ENU"), &Z_Registration_Info_UClass_AVH_GlobeReferenceActor_ENU, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_GlobeReferenceActor_ENU), 3447528435U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_ENU_h_2780156459(TEXT("/Script/VH_Globe"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_ENU_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_ENU_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
