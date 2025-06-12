// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_Globe/Public/VH_GlobeReferenceActor.h"
#include "VH_GlobeMath/Public/VH_GeodeticCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GlobeReferenceActor() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VH_Globe();
	VH_GLOBE_API UClass* Z_Construct_UClass_AVH_GlobeReferenceActor();
	VH_GLOBE_API UClass* Z_Construct_UClass_AVH_GlobeReferenceActor_NoRegister();
	VH_GLOBEMATH_API UClass* Z_Construct_UClass_UVH_GlobeCoordConverter_NoRegister();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord2D();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord3D();
// End Cross Module References
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execIsValidMGRS)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_mgrs);
		P_GET_UBOOL_REF(Z_Param_Out_isValidZone);
		P_GET_UBOOL_REF(Z_Param_Out_isValid100kmSquareID);
		P_GET_UBOOL_REF(Z_Param_Out_isValidEasting);
		P_GET_UBOOL_REF(Z_Param_Out_isValidNorthing);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsValidMGRS(Z_Param_mgrs,Z_Param_Out_isValidZone,Z_Param_Out_isValid100kmSquareID,Z_Param_Out_isValidEasting,Z_Param_Out_isValidNorthing);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execMGRSToWorld)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_mgrs);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->MGRSToWorld(Z_Param_mgrs);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execWorldToMGRS)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_worldLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->WorldToMGRS(Z_Param_Out_worldLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execGeodeticToWorldDouble)
	{
		P_GET_STRUCT_REF(FGeodeticCoord3D,Z_Param_Out_geoLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GeodeticToWorldDouble(Z_Param_Out_geoLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execGetGlobeCoordConverter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_GlobeCoordConverter**)Z_Param__Result=P_THIS->GetGlobeCoordConverter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execGeodeticToECEF)
	{
		P_GET_STRUCT_REF(FGeodeticCoord3D,Z_Param_Out_geoLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GeodeticToECEF(Z_Param_Out_geoLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execWorldToGeodeticDouble)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_worldLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGeodeticCoord3D*)Z_Param__Result=P_THIS->WorldToGeodeticDouble(Z_Param_Out_worldLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execGetTerrainElevationDouble)
	{
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geoLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(double*)Z_Param__Result=P_THIS->GetTerrainElevationDouble(Z_Param_Out_geoLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execWorldRotationToPitch)
	{
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_worldRotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(double*)Z_Param__Result=P_THIS->WorldRotationToPitch(Z_Param_Out_worldRotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execWorldRotationToBearing)
	{
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_worldRotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(double*)Z_Param__Result=P_THIS->WorldRotationToBearing(Z_Param_Out_worldRotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_GlobeReferenceActor::execBearingToWorldRotation)
	{
		P_GET_PROPERTY(FDoubleProperty,Z_Param_bearing);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FRotator*)Z_Param__Result=P_THIS->BearingToWorldRotation(Z_Param_bearing);
		P_NATIVE_END;
	}
	void AVH_GlobeReferenceActor::StaticRegisterNativesAVH_GlobeReferenceActor()
	{
		UClass* Class = AVH_GlobeReferenceActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BearingToWorldRotation", &AVH_GlobeReferenceActor::execBearingToWorldRotation },
			{ "GeodeticToECEF", &AVH_GlobeReferenceActor::execGeodeticToECEF },
			{ "GeodeticToWorldDouble", &AVH_GlobeReferenceActor::execGeodeticToWorldDouble },
			{ "GetGlobeCoordConverter", &AVH_GlobeReferenceActor::execGetGlobeCoordConverter },
			{ "GetTerrainElevationDouble", &AVH_GlobeReferenceActor::execGetTerrainElevationDouble },
			{ "IsValidMGRS", &AVH_GlobeReferenceActor::execIsValidMGRS },
			{ "MGRSToWorld", &AVH_GlobeReferenceActor::execMGRSToWorld },
			{ "WorldRotationToBearing", &AVH_GlobeReferenceActor::execWorldRotationToBearing },
			{ "WorldRotationToPitch", &AVH_GlobeReferenceActor::execWorldRotationToPitch },
			{ "WorldToGeodeticDouble", &AVH_GlobeReferenceActor::execWorldToGeodeticDouble },
			{ "WorldToMGRS", &AVH_GlobeReferenceActor::execWorldToMGRS },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics
	{
		struct VH_GlobeReferenceActor_eventBearingToWorldRotation_Parms
		{
			double bearing;
			FRotator ReturnValue;
		};
		static const UECodeGen_Private::FDoublePropertyParams NewProp_bearing;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::NewProp_bearing = { "bearing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventBearingToWorldRotation_Parms, bearing), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventBearingToWorldRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::NewProp_bearing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* returns world rotation given bearing in degrees off of north; north is 0, east is 90, etc */" },
#endif
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "returns world rotation given bearing in degrees off of north; north is 0, east is 90, etc" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "BearingToWorldRotation", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::VH_GlobeReferenceActor_eventBearingToWorldRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::VH_GlobeReferenceActor_eventBearingToWorldRotation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics
	{
		struct VH_GlobeReferenceActor_eventGeodeticToECEF_Parms
		{
			FGeodeticCoord3D geoLocation;
			FVector ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::NewProp_geoLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::NewProp_geoLocation = { "geoLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventGeodeticToECEF_Parms, geoLocation), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::NewProp_geoLocation_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::NewProp_geoLocation_MetaData) }; // 3754836998
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventGeodeticToECEF_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::NewProp_geoLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "GeodeticToECEF", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::VH_GlobeReferenceActor_eventGeodeticToECEF_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::VH_GlobeReferenceActor_eventGeodeticToECEF_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics
	{
		struct VH_GlobeReferenceActor_eventGeodeticToWorldDouble_Parms
		{
			FGeodeticCoord3D geoLocation;
			FVector ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::NewProp_geoLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::NewProp_geoLocation = { "geoLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventGeodeticToWorldDouble_Parms, geoLocation), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::NewProp_geoLocation_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::NewProp_geoLocation_MetaData) }; // 3754836998
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventGeodeticToWorldDouble_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::NewProp_geoLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "GeodeticToWorldDouble", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::VH_GlobeReferenceActor_eventGeodeticToWorldDouble_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::VH_GlobeReferenceActor_eventGeodeticToWorldDouble_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics
	{
		struct VH_GlobeReferenceActor_eventGetGlobeCoordConverter_Parms
		{
			UVH_GlobeCoordConverter* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventGetGlobeCoordConverter_Parms, ReturnValue), Z_Construct_UClass_UVH_GlobeCoordConverter_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "GetGlobeCoordConverter", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::VH_GlobeReferenceActor_eventGetGlobeCoordConverter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::VH_GlobeReferenceActor_eventGetGlobeCoordConverter_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics
	{
		struct VH_GlobeReferenceActor_eventGetTerrainElevationDouble_Parms
		{
			FGeodeticCoord2D geoLocation;
			double ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoLocation;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::NewProp_geoLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::NewProp_geoLocation = { "geoLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventGetTerrainElevationDouble_Parms, geoLocation), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::NewProp_geoLocation_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::NewProp_geoLocation_MetaData) }; // 3688870805
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventGetTerrainElevationDouble_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::NewProp_geoLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* returns terrain elevation HAE (height above ellipsoid, in meters) at the given geodetic coordinates */" },
#endif
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "returns terrain elevation HAE (height above ellipsoid, in meters) at the given geodetic coordinates" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "GetTerrainElevationDouble", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::VH_GlobeReferenceActor_eventGetTerrainElevationDouble_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::VH_GlobeReferenceActor_eventGetTerrainElevationDouble_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics
	{
		struct VH_GlobeReferenceActor_eventIsValidMGRS_Parms
		{
			FString mgrs;
			bool isValidZone;
			bool isValid100kmSquareID;
			bool isValidEasting;
			bool isValidNorthing;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mgrs_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_mgrs;
		static void NewProp_isValidZone_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isValidZone;
		static void NewProp_isValid100kmSquareID_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isValid100kmSquareID;
		static void NewProp_isValidEasting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isValidEasting;
		static void NewProp_isValidNorthing_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isValidNorthing;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_mgrs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_mgrs = { "mgrs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventIsValidMGRS_Parms, mgrs), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_mgrs_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_mgrs_MetaData) };
	void Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidZone_SetBit(void* Obj)
	{
		((VH_GlobeReferenceActor_eventIsValidMGRS_Parms*)Obj)->isValidZone = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidZone = { "isValidZone", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_GlobeReferenceActor_eventIsValidMGRS_Parms), &Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidZone_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValid100kmSquareID_SetBit(void* Obj)
	{
		((VH_GlobeReferenceActor_eventIsValidMGRS_Parms*)Obj)->isValid100kmSquareID = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValid100kmSquareID = { "isValid100kmSquareID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_GlobeReferenceActor_eventIsValidMGRS_Parms), &Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValid100kmSquareID_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidEasting_SetBit(void* Obj)
	{
		((VH_GlobeReferenceActor_eventIsValidMGRS_Parms*)Obj)->isValidEasting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidEasting = { "isValidEasting", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_GlobeReferenceActor_eventIsValidMGRS_Parms), &Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidEasting_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidNorthing_SetBit(void* Obj)
	{
		((VH_GlobeReferenceActor_eventIsValidMGRS_Parms*)Obj)->isValidNorthing = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidNorthing = { "isValidNorthing", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_GlobeReferenceActor_eventIsValidMGRS_Parms), &Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidNorthing_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_GlobeReferenceActor_eventIsValidMGRS_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_GlobeReferenceActor_eventIsValidMGRS_Parms), &Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_mgrs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidZone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValid100kmSquareID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidEasting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_isValidNorthing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "IsValidMGRS", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::VH_GlobeReferenceActor_eventIsValidMGRS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::VH_GlobeReferenceActor_eventIsValidMGRS_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics
	{
		struct VH_GlobeReferenceActor_eventMGRSToWorld_Parms
		{
			FString mgrs;
			FVector ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mgrs_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_mgrs;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::NewProp_mgrs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::NewProp_mgrs = { "mgrs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventMGRSToWorld_Parms, mgrs), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::NewProp_mgrs_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::NewProp_mgrs_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventMGRSToWorld_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::NewProp_mgrs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "MGRSToWorld", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::VH_GlobeReferenceActor_eventMGRSToWorld_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::VH_GlobeReferenceActor_eventMGRSToWorld_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics
	{
		struct VH_GlobeReferenceActor_eventWorldRotationToBearing_Parms
		{
			FRotator worldRotation;
			double ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldRotation;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::NewProp_worldRotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::NewProp_worldRotation = { "worldRotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldRotationToBearing_Parms, worldRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::NewProp_worldRotation_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::NewProp_worldRotation_MetaData) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldRotationToBearing_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::NewProp_worldRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* returns bearing in degrees with 0 as north, 90 as east, etc */" },
#endif
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "returns bearing in degrees with 0 as north, 90 as east, etc" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "WorldRotationToBearing", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::VH_GlobeReferenceActor_eventWorldRotationToBearing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::VH_GlobeReferenceActor_eventWorldRotationToBearing_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics
	{
		struct VH_GlobeReferenceActor_eventWorldRotationToPitch_Parms
		{
			FRotator worldRotation;
			double ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldRotation;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::NewProp_worldRotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::NewProp_worldRotation = { "worldRotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldRotationToPitch_Parms, worldRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::NewProp_worldRotation_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::NewProp_worldRotation_MetaData) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldRotationToPitch_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::NewProp_worldRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "WorldRotationToPitch", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::VH_GlobeReferenceActor_eventWorldRotationToPitch_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::VH_GlobeReferenceActor_eventWorldRotationToPitch_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics
	{
		struct VH_GlobeReferenceActor_eventWorldToGeodeticDouble_Parms
		{
			FVector worldLocation;
			FGeodeticCoord3D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::NewProp_worldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::NewProp_worldLocation = { "worldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldToGeodeticDouble_Parms, worldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::NewProp_worldLocation_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::NewProp_worldLocation_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldToGeodeticDouble_Parms, ReturnValue), Z_Construct_UScriptStruct_FGeodeticCoord3D, METADATA_PARAMS(0, nullptr) }; // 3754836998
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::NewProp_worldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "WorldToGeodeticDouble", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::VH_GlobeReferenceActor_eventWorldToGeodeticDouble_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::VH_GlobeReferenceActor_eventWorldToGeodeticDouble_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics
	{
		struct VH_GlobeReferenceActor_eventWorldToMGRS_Parms
		{
			FVector worldLocation;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldLocation;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::NewProp_worldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::NewProp_worldLocation = { "worldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldToMGRS_Parms, worldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::NewProp_worldLocation_MetaData), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::NewProp_worldLocation_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeReferenceActor_eventWorldToMGRS_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::NewProp_worldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_GlobeReferenceActor, nullptr, "WorldToMGRS", nullptr, nullptr, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::VH_GlobeReferenceActor_eventWorldToMGRS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::VH_GlobeReferenceActor_eventWorldToMGRS_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_GlobeReferenceActor);
	UClass* Z_Construct_UClass_AVH_GlobeReferenceActor_NoRegister()
	{
		return AVH_GlobeReferenceActor::StaticClass();
	}
	struct Z_Construct_UClass_AVH_GlobeReferenceActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobeCoordConverter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GlobeCoordConverter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Globe,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_BearingToWorldRotation, "BearingToWorldRotation" }, // 1491205147
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToECEF, "GeodeticToECEF" }, // 2880502893
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_GeodeticToWorldDouble, "GeodeticToWorldDouble" }, // 2580382524
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_GetGlobeCoordConverter, "GetGlobeCoordConverter" }, // 260212974
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_GetTerrainElevationDouble, "GetTerrainElevationDouble" }, // 2332495239
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_IsValidMGRS, "IsValidMGRS" }, // 3305127129
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_MGRSToWorld, "MGRSToWorld" }, // 3354290907
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToBearing, "WorldRotationToBearing" }, // 1276879614
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldRotationToPitch, "WorldRotationToPitch" }, // 1724552127
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToGeodeticDouble, "WorldToGeodeticDouble" }, // 1851467090
		{ &Z_Construct_UFunction_AVH_GlobeReferenceActor_WorldToMGRS, "WorldToMGRS" }, // 3989568648
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VH_GlobeReferenceActor.h" },
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::NewProp_GlobeCoordConverter_MetaData[] = {
		{ "ModuleRelativePath", "Public/VH_GlobeReferenceActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::NewProp_GlobeCoordConverter = { "GlobeCoordConverter", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_GlobeReferenceActor, GlobeCoordConverter), Z_Construct_UClass_UVH_GlobeCoordConverter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::NewProp_GlobeCoordConverter_MetaData), Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::NewProp_GlobeCoordConverter_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::NewProp_GlobeCoordConverter,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_GlobeReferenceActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::ClassParams = {
		&AVH_GlobeReferenceActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::PropPointers),
		0,
		0x009000A5u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AVH_GlobeReferenceActor()
	{
		if (!Z_Registration_Info_UClass_AVH_GlobeReferenceActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_GlobeReferenceActor.OuterSingleton, Z_Construct_UClass_AVH_GlobeReferenceActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_GlobeReferenceActor.OuterSingleton;
	}
	template<> VH_GLOBE_API UClass* StaticClass<AVH_GlobeReferenceActor>()
	{
		return AVH_GlobeReferenceActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_GlobeReferenceActor);
	AVH_GlobeReferenceActor::~AVH_GlobeReferenceActor() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_GlobeReferenceActor, AVH_GlobeReferenceActor::StaticClass, TEXT("AVH_GlobeReferenceActor"), &Z_Registration_Info_UClass_AVH_GlobeReferenceActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_GlobeReferenceActor), 2415182171U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_1517048004(TEXT("/Script/VH_Globe"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
