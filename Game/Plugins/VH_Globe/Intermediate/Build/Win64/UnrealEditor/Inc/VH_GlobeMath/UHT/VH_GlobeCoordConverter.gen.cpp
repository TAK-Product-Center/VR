// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_GlobeCoordConverter.h"
#include "VH_GlobeMath/Public/VH_GeodeticCoord.h"
#include "VH_GlobeMath/Public/VH_GlobeTangentCoord.h"
#include "VH_GlobeMath/Public/VH_MgrsCoord.h"
#include "VH_GlobeMath/Public/VH_UpsCoord.h"
#include "VH_GlobeMath/Public/VH_UtmCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GlobeCoordConverter() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UClass* Z_Construct_UClass_UVH_GlobeCoordConverter();
	VH_GLOBEMATH_API UClass* Z_Construct_UClass_UVH_GlobeCoordConverter_NoRegister();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord2D();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord3D();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGlobeTangentCoord();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FMgrsCoord();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FSGlobeDefinition();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FUpsCoord();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FUtmCoord();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SGlobeDefinition;
class UScriptStruct* FSGlobeDefinition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SGlobeDefinition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SGlobeDefinition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSGlobeDefinition, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("SGlobeDefinition"));
	}
	return Z_Registration_Info_UScriptStruct_SGlobeDefinition.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FSGlobeDefinition>()
{
	return FSGlobeDefinition::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSGlobeDefinition_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSGlobeDefinition_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSGlobeDefinition_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSGlobeDefinition>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSGlobeDefinition_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"SGlobeDefinition",
		nullptr,
		0,
		sizeof(FSGlobeDefinition),
		alignof(FSGlobeDefinition),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSGlobeDefinition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSGlobeDefinition_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSGlobeDefinition()
	{
		if (!Z_Registration_Info_UScriptStruct_SGlobeDefinition.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SGlobeDefinition.InnerSingleton, Z_Construct_UScriptStruct_FSGlobeDefinition_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SGlobeDefinition.InnerSingleton;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execMGRSToGeodetic)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_mgrs);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_longitude);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_latitude);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MGRSToGeodetic(Z_Param_mgrs,Z_Param_Out_longitude,Z_Param_Out_latitude);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execGeodeticToMGRS)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_longitude);
		P_GET_PROPERTY(FStrProperty,Z_Param_latitude);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GeodeticToMGRS(Z_Param_longitude,Z_Param_latitude);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execGeodeticToECEF)
	{
		P_GET_STRUCT_REF(FGeodeticCoord3D,Z_Param_Out_geodeticCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GeodeticToECEF(Z_Param_Out_geodeticCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execENUToGeodetic)
	{
		P_GET_STRUCT_REF(FGlobeTangentCoord,Z_Param_Out_enu);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGeodeticCoord3D*)Z_Param__Result=P_THIS->ENUToGeodetic(Z_Param_Out_enu);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execGeodeticToENU)
	{
		P_GET_STRUCT_REF(FGeodeticCoord3D,Z_Param_Out_geodeticCoord);
		P_GET_STRUCT_REF(FGeodeticCoord3D,Z_Param_Out_geodeticRef);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGlobeTangentCoord*)Z_Param__Result=P_THIS->GeodeticToENU(Z_Param_Out_geodeticCoord,Z_Param_Out_geodeticRef);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execUPSToMGRS)
	{
		P_GET_STRUCT_REF(FUpsCoord,Z_Param_Out_upsCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FMgrsCoord*)Z_Param__Result=P_THIS->UPSToMGRS(Z_Param_Out_upsCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execMGRSToUPS)
	{
		P_GET_STRUCT_REF(FMgrsCoord,Z_Param_Out_mgrsCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FUpsCoord*)Z_Param__Result=P_THIS->MGRSToUPS(Z_Param_Out_mgrsCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execUTMToMGRS)
	{
		P_GET_STRUCT_REF(FUtmCoord,Z_Param_Out_utmCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FMgrsCoord*)Z_Param__Result=P_THIS->UTMToMGRS(Z_Param_Out_utmCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execMGRSToUTM)
	{
		P_GET_STRUCT_REF(FMgrsCoord,Z_Param_Out_mgrsCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FUtmCoord*)Z_Param__Result=P_THIS->MGRSToUTM(Z_Param_Out_mgrsCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execUPSToGeodetic)
	{
		P_GET_STRUCT_REF(FUpsCoord,Z_Param_Out_upsCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGeodeticCoord2D*)Z_Param__Result=P_THIS->UPSToGeodetic(Z_Param_Out_upsCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execGeodeticToUPS)
	{
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geodeticCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FUpsCoord*)Z_Param__Result=P_THIS->GeodeticToUPS(Z_Param_Out_geodeticCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execUTMToGeodetic)
	{
		P_GET_STRUCT_REF(FUtmCoord,Z_Param_Out_utmCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGeodeticCoord2D*)Z_Param__Result=P_THIS->UTMToGeodetic(Z_Param_Out_utmCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execGeodeticToUTM)
	{
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geodeticCoord);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FUtmCoord*)Z_Param__Result=P_THIS->GeodeticToUTM(Z_Param_Out_geodeticCoord);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeCoordConverter::execK2_SetGlobeDefinition)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_semiMajorAxis);
		P_GET_PROPERTY(FStrProperty,Z_Param_semiMinorAxis);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->K2_SetGlobeDefinition(Z_Param_semiMajorAxis,Z_Param_semiMinorAxis);
		P_NATIVE_END;
	}
	void UVH_GlobeCoordConverter::StaticRegisterNativesUVH_GlobeCoordConverter()
	{
		UClass* Class = UVH_GlobeCoordConverter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ENUToGeodetic", &UVH_GlobeCoordConverter::execENUToGeodetic },
			{ "GeodeticToECEF", &UVH_GlobeCoordConverter::execGeodeticToECEF },
			{ "GeodeticToENU", &UVH_GlobeCoordConverter::execGeodeticToENU },
			{ "GeodeticToMGRS", &UVH_GlobeCoordConverter::execGeodeticToMGRS },
			{ "GeodeticToUPS", &UVH_GlobeCoordConverter::execGeodeticToUPS },
			{ "GeodeticToUTM", &UVH_GlobeCoordConverter::execGeodeticToUTM },
			{ "K2_SetGlobeDefinition", &UVH_GlobeCoordConverter::execK2_SetGlobeDefinition },
			{ "MGRSToGeodetic", &UVH_GlobeCoordConverter::execMGRSToGeodetic },
			{ "MGRSToUPS", &UVH_GlobeCoordConverter::execMGRSToUPS },
			{ "MGRSToUTM", &UVH_GlobeCoordConverter::execMGRSToUTM },
			{ "UPSToGeodetic", &UVH_GlobeCoordConverter::execUPSToGeodetic },
			{ "UPSToMGRS", &UVH_GlobeCoordConverter::execUPSToMGRS },
			{ "UTMToGeodetic", &UVH_GlobeCoordConverter::execUTMToGeodetic },
			{ "UTMToMGRS", &UVH_GlobeCoordConverter::execUTMToMGRS },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics
	{
		struct VH_GlobeCoordConverter_eventENUToGeodetic_Parms
		{
			FGlobeTangentCoord enu;
			FGeodeticCoord3D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_enu_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_enu;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::NewProp_enu_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::NewProp_enu = { "enu", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventENUToGeodetic_Parms, enu), Z_Construct_UScriptStruct_FGlobeTangentCoord, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::NewProp_enu_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::NewProp_enu_MetaData) }; // 2742884294
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventENUToGeodetic_Parms, ReturnValue), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(0, nullptr) }; // 3754836998
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::NewProp_enu,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "ENUToGeodetic", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::VH_GlobeCoordConverter_eventENUToGeodetic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::VH_GlobeCoordConverter_eventENUToGeodetic_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics
	{
		struct VH_GlobeCoordConverter_eventGeodeticToECEF_Parms
		{
			FGeodeticCoord3D geodeticCoord;
			FVector ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geodeticCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geodeticCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::NewProp_geodeticCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::NewProp_geodeticCoord = { "geodeticCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToECEF_Parms, geodeticCoord), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::NewProp_geodeticCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::NewProp_geodeticCoord_MetaData) }; // 3754836998
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToECEF_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::NewProp_geodeticCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "DisplayName", "GeodeticToECEF" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "GeodeticToECEF", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::VH_GlobeCoordConverter_eventGeodeticToECEF_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::VH_GlobeCoordConverter_eventGeodeticToECEF_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics
	{
		struct VH_GlobeCoordConverter_eventGeodeticToENU_Parms
		{
			FGeodeticCoord3D geodeticCoord;
			FGeodeticCoord3D geodeticRef;
			FGlobeTangentCoord ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geodeticCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geodeticCoord;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geodeticRef_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geodeticRef;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticCoord = { "geodeticCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToENU_Parms, geodeticCoord), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticCoord_MetaData) }; // 3754836998
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticRef_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticRef = { "geodeticRef", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToENU_Parms, geodeticRef), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticRef_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticRef_MetaData) }; // 3754836998
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToENU_Parms, ReturnValue), Z_Construct_UScriptStruct_FGlobeTangentCoord, METADATA_PARAMS(0, nullptr) }; // 2742884294
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_geodeticRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "GeodeticToENU", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::VH_GlobeCoordConverter_eventGeodeticToENU_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::VH_GlobeCoordConverter_eventGeodeticToENU_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics
	{
		struct VH_GlobeCoordConverter_eventGeodeticToMGRS_Parms
		{
			FString longitude;
			FString latitude;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_longitude;
		static const UECodeGen_Private::FStrPropertyParams NewProp_latitude;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::NewProp_longitude = { "longitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToMGRS_Parms, longitude), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::NewProp_latitude = { "latitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToMGRS_Parms, latitude), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToMGRS_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::NewProp_longitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::NewProp_latitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "GeodeticToMGRS", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::VH_GlobeCoordConverter_eventGeodeticToMGRS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::VH_GlobeCoordConverter_eventGeodeticToMGRS_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics
	{
		struct VH_GlobeCoordConverter_eventGeodeticToUPS_Parms
		{
			FGeodeticCoord2D geodeticCoord;
			FUpsCoord ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geodeticCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geodeticCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::NewProp_geodeticCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::NewProp_geodeticCoord = { "geodeticCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToUPS_Parms, geodeticCoord), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::NewProp_geodeticCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::NewProp_geodeticCoord_MetaData) }; // 3688870805
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToUPS_Parms, ReturnValue), Z_Construct_UScriptStruct_FUpsCoord, METADATA_PARAMS(0, nullptr) }; // 699914469
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::NewProp_geodeticCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "GeodeticToUPS", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::VH_GlobeCoordConverter_eventGeodeticToUPS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::VH_GlobeCoordConverter_eventGeodeticToUPS_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics
	{
		struct VH_GlobeCoordConverter_eventGeodeticToUTM_Parms
		{
			FGeodeticCoord2D geodeticCoord;
			FUtmCoord ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geodeticCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geodeticCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::NewProp_geodeticCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::NewProp_geodeticCoord = { "geodeticCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToUTM_Parms, geodeticCoord), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::NewProp_geodeticCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::NewProp_geodeticCoord_MetaData) }; // 3688870805
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventGeodeticToUTM_Parms, ReturnValue), Z_Construct_UScriptStruct_FUtmCoord, METADATA_PARAMS(0, nullptr) }; // 1126432294
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::NewProp_geodeticCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "GeodeticToUTM", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::VH_GlobeCoordConverter_eventGeodeticToUTM_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::VH_GlobeCoordConverter_eventGeodeticToUTM_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics
	{
		struct VH_GlobeCoordConverter_eventK2_SetGlobeDefinition_Parms
		{
			FString semiMajorAxis;
			FString semiMinorAxis;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_semiMajorAxis_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_semiMajorAxis;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_semiMinorAxis_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_semiMinorAxis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMajorAxis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMajorAxis = { "semiMajorAxis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventK2_SetGlobeDefinition_Parms, semiMajorAxis), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMajorAxis_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMajorAxis_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMinorAxis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMinorAxis = { "semiMinorAxis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventK2_SetGlobeDefinition_Parms, semiMinorAxis), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMinorAxis_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMinorAxis_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMajorAxis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::NewProp_semiMinorAxis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "DisplayName", "SetGlobeDefinition" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "K2_SetGlobeDefinition", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::VH_GlobeCoordConverter_eventK2_SetGlobeDefinition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::VH_GlobeCoordConverter_eventK2_SetGlobeDefinition_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics
	{
		struct VH_GlobeCoordConverter_eventMGRSToGeodetic_Parms
		{
			FString mgrs;
			FString longitude;
			FString latitude;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mgrs_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_mgrs;
		static const UECodeGen_Private::FStrPropertyParams NewProp_longitude;
		static const UECodeGen_Private::FStrPropertyParams NewProp_latitude;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_mgrs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_mgrs = { "mgrs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventMGRSToGeodetic_Parms, mgrs), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_mgrs_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_mgrs_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_longitude = { "longitude", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventMGRSToGeodetic_Parms, longitude), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_latitude = { "latitude", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventMGRSToGeodetic_Parms, latitude), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_mgrs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_longitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::NewProp_latitude,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "MGRSToGeodetic", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::VH_GlobeCoordConverter_eventMGRSToGeodetic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::VH_GlobeCoordConverter_eventMGRSToGeodetic_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics
	{
		struct VH_GlobeCoordConverter_eventMGRSToUPS_Parms
		{
			FMgrsCoord mgrsCoord;
			FUpsCoord ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mgrsCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_mgrsCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::NewProp_mgrsCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::NewProp_mgrsCoord = { "mgrsCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventMGRSToUPS_Parms, mgrsCoord), Z_Construct_UScriptStruct_FMgrsCoord, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::NewProp_mgrsCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::NewProp_mgrsCoord_MetaData) }; // 674317956
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventMGRSToUPS_Parms, ReturnValue), Z_Construct_UScriptStruct_FUpsCoord, METADATA_PARAMS(0, nullptr) }; // 699914469
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::NewProp_mgrsCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "MGRSToUPS", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::VH_GlobeCoordConverter_eventMGRSToUPS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::VH_GlobeCoordConverter_eventMGRSToUPS_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics
	{
		struct VH_GlobeCoordConverter_eventMGRSToUTM_Parms
		{
			FMgrsCoord mgrsCoord;
			FUtmCoord ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mgrsCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_mgrsCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::NewProp_mgrsCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::NewProp_mgrsCoord = { "mgrsCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventMGRSToUTM_Parms, mgrsCoord), Z_Construct_UScriptStruct_FMgrsCoord, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::NewProp_mgrsCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::NewProp_mgrsCoord_MetaData) }; // 674317956
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventMGRSToUTM_Parms, ReturnValue), Z_Construct_UScriptStruct_FUtmCoord, METADATA_PARAMS(0, nullptr) }; // 1126432294
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::NewProp_mgrsCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "MGRSToUTM", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::VH_GlobeCoordConverter_eventMGRSToUTM_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::VH_GlobeCoordConverter_eventMGRSToUTM_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics
	{
		struct VH_GlobeCoordConverter_eventUPSToGeodetic_Parms
		{
			FUpsCoord upsCoord;
			FGeodeticCoord2D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_upsCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_upsCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::NewProp_upsCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::NewProp_upsCoord = { "upsCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUPSToGeodetic_Parms, upsCoord), Z_Construct_UScriptStruct_FUpsCoord, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::NewProp_upsCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::NewProp_upsCoord_MetaData) }; // 699914469
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUPSToGeodetic_Parms, ReturnValue), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(0, nullptr) }; // 3688870805
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::NewProp_upsCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "UPSToGeodetic", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::VH_GlobeCoordConverter_eventUPSToGeodetic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::VH_GlobeCoordConverter_eventUPSToGeodetic_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics
	{
		struct VH_GlobeCoordConverter_eventUPSToMGRS_Parms
		{
			FUpsCoord upsCoord;
			FMgrsCoord ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_upsCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_upsCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::NewProp_upsCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::NewProp_upsCoord = { "upsCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUPSToMGRS_Parms, upsCoord), Z_Construct_UScriptStruct_FUpsCoord, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::NewProp_upsCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::NewProp_upsCoord_MetaData) }; // 699914469
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUPSToMGRS_Parms, ReturnValue), Z_Construct_UScriptStruct_FMgrsCoord, METADATA_PARAMS(0, nullptr) }; // 674317956
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::NewProp_upsCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "UPSToMGRS", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::VH_GlobeCoordConverter_eventUPSToMGRS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::VH_GlobeCoordConverter_eventUPSToMGRS_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics
	{
		struct VH_GlobeCoordConverter_eventUTMToGeodetic_Parms
		{
			FUtmCoord utmCoord;
			FGeodeticCoord2D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_utmCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_utmCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::NewProp_utmCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::NewProp_utmCoord = { "utmCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUTMToGeodetic_Parms, utmCoord), Z_Construct_UScriptStruct_FUtmCoord, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::NewProp_utmCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::NewProp_utmCoord_MetaData) }; // 1126432294
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUTMToGeodetic_Parms, ReturnValue), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(0, nullptr) }; // 3688870805
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::NewProp_utmCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "UTMToGeodetic", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::VH_GlobeCoordConverter_eventUTMToGeodetic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::VH_GlobeCoordConverter_eventUTMToGeodetic_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics
	{
		struct VH_GlobeCoordConverter_eventUTMToMGRS_Parms
		{
			FUtmCoord utmCoord;
			FMgrsCoord ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_utmCoord_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_utmCoord;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::NewProp_utmCoord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::NewProp_utmCoord = { "utmCoord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUTMToMGRS_Parms, utmCoord), Z_Construct_UScriptStruct_FUtmCoord, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::NewProp_utmCoord_MetaData), Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::NewProp_utmCoord_MetaData) }; // 1126432294
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeCoordConverter_eventUTMToMGRS_Parms, ReturnValue), Z_Construct_UScriptStruct_FMgrsCoord, METADATA_PARAMS(0, nullptr) }; // 674317956
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::NewProp_utmCoord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobe|Math|Conversions" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeCoordConverter, nullptr, "UTMToMGRS", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::VH_GlobeCoordConverter_eventUTMToMGRS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::VH_GlobeCoordConverter_eventUTMToMGRS_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_GlobeCoordConverter);
	UClass* Z_Construct_UClass_UVH_GlobeCoordConverter_NoRegister()
	{
		return UVH_GlobeCoordConverter::StaticClass();
	}
	struct Z_Construct_UClass_UVH_GlobeCoordConverter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobeDefinition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GlobeDefinition;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_ENUToGeodetic, "ENUToGeodetic" }, // 583062518
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToECEF, "GeodeticToECEF" }, // 3303958981
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToENU, "GeodeticToENU" }, // 779472517
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToMGRS, "GeodeticToMGRS" }, // 2618917510
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUPS, "GeodeticToUPS" }, // 1211224443
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_GeodeticToUTM, "GeodeticToUTM" }, // 149537085
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_K2_SetGlobeDefinition, "K2_SetGlobeDefinition" }, // 1308106432
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToGeodetic, "MGRSToGeodetic" }, // 4212718096
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUPS, "MGRSToUPS" }, // 3795511647
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_MGRSToUTM, "MGRSToUTM" }, // 951427355
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToGeodetic, "UPSToGeodetic" }, // 3855969442
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_UPSToMGRS, "UPSToMGRS" }, // 1442191469
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToGeodetic, "UTMToGeodetic" }, // 2551184248
		{ &Z_Construct_UFunction_UVH_GlobeCoordConverter_UTMToMGRS, "UTMToMGRS" }, // 4119385938
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// NOTE: Built-in C++ trig functions (sin, cos, tan, atan2, etc) are used in this INSTEAD of their FMath variants, because almost all of FMath is single-precision)\n" },
#endif
		{ "IncludePath", "VH_GlobeCoordConverter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NOTE: Built-in C++ trig functions (sin, cos, tan, atan2, etc) are used in this INSTEAD of their FMath variants, because almost all of FMath is single-precision)" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::NewProp_GlobeDefinition_MetaData[] = {
		{ "Category", "VH_GlobeCoordConverter" },
		{ "ModuleRelativePath", "Public/VH_GlobeCoordConverter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::NewProp_GlobeDefinition = { "GlobeDefinition", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_GlobeCoordConverter, GlobeDefinition), Z_Construct_UScriptStruct_FSGlobeDefinition, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::NewProp_GlobeDefinition_MetaData), Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::NewProp_GlobeDefinition_MetaData) }; // 32354274
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::NewProp_GlobeDefinition,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_GlobeCoordConverter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::ClassParams = {
		&UVH_GlobeCoordConverter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_GlobeCoordConverter()
	{
		if (!Z_Registration_Info_UClass_UVH_GlobeCoordConverter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_GlobeCoordConverter.OuterSingleton, Z_Construct_UClass_UVH_GlobeCoordConverter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_GlobeCoordConverter.OuterSingleton;
	}
	template<> VH_GLOBEMATH_API UClass* StaticClass<UVH_GlobeCoordConverter>()
	{
		return UVH_GlobeCoordConverter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_GlobeCoordConverter);
	UVH_GlobeCoordConverter::~UVH_GlobeCoordConverter() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_Statics::ScriptStructInfo[] = {
		{ FSGlobeDefinition::StaticStruct, Z_Construct_UScriptStruct_FSGlobeDefinition_Statics::NewStructOps, TEXT("SGlobeDefinition"), &Z_Registration_Info_UScriptStruct_SGlobeDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSGlobeDefinition), 32354274U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_GlobeCoordConverter, UVH_GlobeCoordConverter::StaticClass, TEXT("UVH_GlobeCoordConverter"), &Z_Registration_Info_UClass_UVH_GlobeCoordConverter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_GlobeCoordConverter), 1946193419U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_567954333(TEXT("/Script/VH_GlobeMath"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
