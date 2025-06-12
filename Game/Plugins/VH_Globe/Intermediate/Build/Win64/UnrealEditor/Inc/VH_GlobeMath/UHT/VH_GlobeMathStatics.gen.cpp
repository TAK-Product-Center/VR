// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_GlobeMathStatics.h"
#include "VH_GlobeMath/Public/VH_GeodeticCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GlobeMathStatics() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UClass* Z_Construct_UClass_UVH_GlobeMathStatics();
	VH_GLOBEMATH_API UClass* Z_Construct_UClass_UVH_GlobeMathStatics_NoRegister();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord2D();
// End Cross Module References
	DEFINE_FUNCTION(UVH_GlobeMathStatics::execCalculateSurfaceDestination)
	{
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geoStart);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_bearing);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_distanceMeters);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_altitudeMeters);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGeodeticCoord2D*)Z_Param__Result=UVH_GlobeMathStatics::CalculateSurfaceDestination(Z_Param_Out_geoStart,Z_Param_bearing,Z_Param_distanceMeters,Z_Param_altitudeMeters);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeMathStatics::execCalculateSurfaceBearing)
	{
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geoStart);
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geoEnd);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(double*)Z_Param__Result=UVH_GlobeMathStatics::CalculateSurfaceBearing(Z_Param_Out_geoStart,Z_Param_Out_geoEnd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_GlobeMathStatics::execCalculateSurfaceDistance)
	{
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geoStart);
		P_GET_STRUCT_REF(FGeodeticCoord2D,Z_Param_Out_geoEnd);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_altitudeMeters);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(double*)Z_Param__Result=UVH_GlobeMathStatics::CalculateSurfaceDistance(Z_Param_Out_geoStart,Z_Param_Out_geoEnd,Z_Param_altitudeMeters);
		P_NATIVE_END;
	}
	void UVH_GlobeMathStatics::StaticRegisterNativesUVH_GlobeMathStatics()
	{
		UClass* Class = UVH_GlobeMathStatics::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalculateSurfaceBearing", &UVH_GlobeMathStatics::execCalculateSurfaceBearing },
			{ "CalculateSurfaceDestination", &UVH_GlobeMathStatics::execCalculateSurfaceDestination },
			{ "CalculateSurfaceDistance", &UVH_GlobeMathStatics::execCalculateSurfaceDistance },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics
	{
		struct VH_GlobeMathStatics_eventCalculateSurfaceBearing_Parms
		{
			FGeodeticCoord2D geoStart;
			FGeodeticCoord2D geoEnd;
			double ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoStart_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoEnd_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoEnd;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoStart_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoStart = { "geoStart", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceBearing_Parms, geoStart), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoStart_MetaData), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoStart_MetaData) }; // 3688870805
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoEnd_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoEnd = { "geoEnd", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceBearing_Parms, geoEnd), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoEnd_MetaData), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoEnd_MetaData) }; // 3688870805
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceBearing_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_geoEnd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobeMath" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \\brief Calculate the bearing (deg) for the most direct path between 2 points on a geo-ellipsoid.\n\x09 * \\param geoStart Starting geodetic position.\n\x09 * \\param geoEnd Ending/destination geodetic position.\n\x09 * \\return The bearing (degrees) for the most direct path between geoStart and geoEnd.\n\x09 * \\note Bearing is interpreted as: 0 = True North, with values [0..360) winding clockwise as viewed from above the surface.\n\x09 */// Calculate the bearing (deg) for the most direct path between 2 points on a geo-ellipsoid.\n" },
#endif
		{ "DisplayName", "VH Calculate Surface Bearing" },
		{ "ModuleRelativePath", "Public/VH_GlobeMathStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Calculate the bearing (deg) for the most direct path between 2 points on a geo-ellipsoid.\n\\param geoStart Starting geodetic position.\n\\param geoEnd Ending/destination geodetic position.\n\\return The bearing (degrees) for the most direct path between geoStart and geoEnd.\n\\note Bearing is interpreted as: 0 = True North, with values [0..360) winding clockwise as viewed from above the surface.\n        // Calculate the bearing (deg) for the most direct path between 2 points on a geo-ellipsoid." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeMathStatics, nullptr, "CalculateSurfaceBearing", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::VH_GlobeMathStatics_eventCalculateSurfaceBearing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::VH_GlobeMathStatics_eventCalculateSurfaceBearing_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics
	{
		struct VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms
		{
			FGeodeticCoord2D geoStart;
			double bearing;
			double distanceMeters;
			double altitudeMeters;
			FGeodeticCoord2D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoStart_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoStart;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_bearing;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_distanceMeters;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_altitudeMeters;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_geoStart_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_geoStart = { "geoStart", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms, geoStart), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_geoStart_MetaData), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_geoStart_MetaData) }; // 3688870805
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_bearing = { "bearing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms, bearing), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_distanceMeters = { "distanceMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms, distanceMeters), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_altitudeMeters = { "altitudeMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms, altitudeMeters), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms, ReturnValue), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(0, nullptr) }; // 3688870805
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_geoStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_bearing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_distanceMeters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_altitudeMeters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobeMath" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \\brief Calculate the destination of movement distance (m) along the surface of a geo-ellipsoid.\n\x09 * \\param geoStart Starting geodetic position.\n\x09 * \\param bearing Direction (degrees) to travel from the starting point.\n\x09 * \\param distanceMeters Distance (meters) to travel from the starting point.\n\x09 * \\param altitudeMeters Altitude (meters) above the surface of the geo-ellipsoid.\n\x09 * \\return The destination geodetic position.\n\x09 * \\note Bearing is interpreted as: 0 = True North, with values [0..360) winding clockwise as viewed from above the surface.\n\x09 */" },
#endif
		{ "CPP_Default_altitudeMeters", "0.000000" },
		{ "DisplayName", "VH Calculate Surface Destination" },
		{ "ModuleRelativePath", "Public/VH_GlobeMathStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Calculate the destination of movement distance (m) along the surface of a geo-ellipsoid.\n\\param geoStart Starting geodetic position.\n\\param bearing Direction (degrees) to travel from the starting point.\n\\param distanceMeters Distance (meters) to travel from the starting point.\n\\param altitudeMeters Altitude (meters) above the surface of the geo-ellipsoid.\n\\return The destination geodetic position.\n\\note Bearing is interpreted as: 0 = True North, with values [0..360) winding clockwise as viewed from above the surface." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeMathStatics, nullptr, "CalculateSurfaceDestination", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::VH_GlobeMathStatics_eventCalculateSurfaceDestination_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics
	{
		struct VH_GlobeMathStatics_eventCalculateSurfaceDistance_Parms
		{
			FGeodeticCoord2D geoStart;
			FGeodeticCoord2D geoEnd;
			double altitudeMeters;
			double ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoStart_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_geoEnd_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_geoEnd;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_altitudeMeters;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoStart_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoStart = { "geoStart", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDistance_Parms, geoStart), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoStart_MetaData), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoStart_MetaData) }; // 3688870805
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoEnd_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoEnd = { "geoEnd", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDistance_Parms, geoEnd), Z_Construct_UScriptStruct_FGeodeticCoord2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoEnd_MetaData), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoEnd_MetaData) }; // 3688870805
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_altitudeMeters = { "altitudeMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDistance_Parms, altitudeMeters), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_GlobeMathStatics_eventCalculateSurfaceDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_geoEnd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_altitudeMeters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGlobeMath" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \\brief Calculate the distance (m) for the most direct path between 2 points along the surface of a geo-ellipsoid.\n\x09 * \\param geoStart Starting geodetic position.\n\x09 * \\param geoEnd Ending/destination geodetic position.\n\x09 * \\param altitudeMeters Altitude (meters) above the surface of the geo-ellipsoid.\n\x09 * \\return Surface distance (meters) between geoStart and geoEnd at the given altitudeMeters.\n\x09 */" },
#endif
		{ "CPP_Default_altitudeMeters", "0.000000" },
		{ "DisplayName", "VH Calculate Surface Distance" },
		{ "ModuleRelativePath", "Public/VH_GlobeMathStatics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Calculate the distance (m) for the most direct path between 2 points along the surface of a geo-ellipsoid.\n\\param geoStart Starting geodetic position.\n\\param geoEnd Ending/destination geodetic position.\n\\param altitudeMeters Altitude (meters) above the surface of the geo-ellipsoid.\n\\return Surface distance (meters) between geoStart and geoEnd at the given altitudeMeters." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_GlobeMathStatics, nullptr, "CalculateSurfaceDistance", nullptr, nullptr, Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::VH_GlobeMathStatics_eventCalculateSurfaceDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::VH_GlobeMathStatics_eventCalculateSurfaceDistance_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_GlobeMathStatics);
	UClass* Z_Construct_UClass_UVH_GlobeMathStatics_NoRegister()
	{
		return UVH_GlobeMathStatics::StaticClass();
	}
	struct Z_Construct_UClass_UVH_GlobeMathStatics_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_GlobeMathStatics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeMathStatics_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_GlobeMathStatics_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceBearing, "CalculateSurfaceBearing" }, // 1647583430
		{ &Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDestination, "CalculateSurfaceDestination" }, // 3321701434
		{ &Z_Construct_UFunction_UVH_GlobeMathStatics_CalculateSurfaceDistance, "CalculateSurfaceDistance" }, // 126200048
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeMathStatics_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_GlobeMathStatics_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "VH_GlobeMathStatics.h" },
		{ "ModuleRelativePath", "Public/VH_GlobeMathStatics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_GlobeMathStatics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_GlobeMathStatics>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_GlobeMathStatics_Statics::ClassParams = {
		&UVH_GlobeMathStatics::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_GlobeMathStatics_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_GlobeMathStatics_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_GlobeMathStatics()
	{
		if (!Z_Registration_Info_UClass_UVH_GlobeMathStatics.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_GlobeMathStatics.OuterSingleton, Z_Construct_UClass_UVH_GlobeMathStatics_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_GlobeMathStatics.OuterSingleton;
	}
	template<> VH_GLOBEMATH_API UClass* StaticClass<UVH_GlobeMathStatics>()
	{
		return UVH_GlobeMathStatics::StaticClass();
	}
	UVH_GlobeMathStatics::UVH_GlobeMathStatics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_GlobeMathStatics);
	UVH_GlobeMathStatics::~UVH_GlobeMathStatics() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathStatics_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathStatics_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_GlobeMathStatics, UVH_GlobeMathStatics::StaticClass, TEXT("UVH_GlobeMathStatics"), &Z_Registration_Info_UClass_UVH_GlobeMathStatics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_GlobeMathStatics), 4109965101U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathStatics_h_2921019198(TEXT("/Script/VH_GlobeMath"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathStatics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathStatics_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
