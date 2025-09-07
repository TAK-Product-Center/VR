// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_GeodeticCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GeodeticCoord() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord2D();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord3D();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GeodeticCoord2D;
class UScriptStruct* FGeodeticCoord2D::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GeodeticCoord2D.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GeodeticCoord2D.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGeodeticCoord2D, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("GeodeticCoord2D"));
	}
	return Z_Registration_Info_UScriptStruct_GeodeticCoord2D.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FGeodeticCoord2D>()
{
	return FGeodeticCoord2D::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Longitude_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Longitude;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Latitude_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Latitude;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGeodeticCoord2D>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Longitude_MetaData[] = {
		{ "Category", "GeodeticCoord2D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Longitude in degrees\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Longitude in degrees" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Longitude = { "Longitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGeodeticCoord2D, Longitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Longitude_MetaData), Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Longitude_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Latitude_MetaData[] = {
		{ "Category", "GeodeticCoord2D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Latitude in degrees\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Latitude in degrees" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Latitude = { "Latitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGeodeticCoord2D, Latitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Latitude_MetaData), Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Latitude_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Longitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewProp_Latitude,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"GeodeticCoord2D",
		Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::PropPointers),
		sizeof(FGeodeticCoord2D),
		alignof(FGeodeticCoord2D),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord2D()
	{
		if (!Z_Registration_Info_UScriptStruct_GeodeticCoord2D.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GeodeticCoord2D.InnerSingleton, Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GeodeticCoord2D.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GeodeticCoord3D;
class UScriptStruct* FGeodeticCoord3D::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GeodeticCoord3D.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GeodeticCoord3D.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGeodeticCoord3D, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("GeodeticCoord3D"));
	}
	return Z_Registration_Info_UScriptStruct_GeodeticCoord3D.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FGeodeticCoord3D>()
{
	return FGeodeticCoord3D::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Longitude_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Longitude;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Latitude_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Latitude;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Altitude_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Altitude;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsAltitudeRelativeToGround_MetaData[];
#endif
		static void NewProp_bIsAltitudeRelativeToGround_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAltitudeRelativeToGround;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Holds a Geodetic (Lat-Long) Coordinate and an altitude (usually in meters HAE)\n */" },
#endif
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Holds a Geodetic (Lat-Long) Coordinate and an altitude (usually in meters HAE)" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGeodeticCoord3D>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Longitude_MetaData[] = {
		{ "Category", "GeodeticCoord3D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Longitude in degrees\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Longitude in degrees" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Longitude = { "Longitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGeodeticCoord3D, Longitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Longitude_MetaData), Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Longitude_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Latitude_MetaData[] = {
		{ "Category", "GeodeticCoord3D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Latitude in degrees\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Latitude in degrees" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Latitude = { "Latitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGeodeticCoord3D, Latitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Latitude_MetaData), Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Latitude_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Altitude_MetaData[] = {
		{ "Category", "GeodeticCoord3D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Altitude in meters\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Altitude in meters" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Altitude = { "Altitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGeodeticCoord3D, Altitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Altitude_MetaData), Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Altitude_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_bIsAltitudeRelativeToGround_MetaData[] = {
		{ "Category", "GeodeticCoord3D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// If false, altitude is assumed HAE\n" },
#endif
		{ "ModuleRelativePath", "Public/VH_GeodeticCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If false, altitude is assumed HAE" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_bIsAltitudeRelativeToGround_SetBit(void* Obj)
	{
		((FGeodeticCoord3D*)Obj)->bIsAltitudeRelativeToGround = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_bIsAltitudeRelativeToGround = { "bIsAltitudeRelativeToGround", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGeodeticCoord3D), &Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_bIsAltitudeRelativeToGround_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_bIsAltitudeRelativeToGround_MetaData), Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_bIsAltitudeRelativeToGround_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Longitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Latitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_Altitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewProp_bIsAltitudeRelativeToGround,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"GeodeticCoord3D",
		Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::PropPointers),
		sizeof(FGeodeticCoord3D),
		alignof(FGeodeticCoord3D),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FGeodeticCoord3D()
	{
		if (!Z_Registration_Info_UScriptStruct_GeodeticCoord3D.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GeodeticCoord3D.InnerSingleton, Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GeodeticCoord3D.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GeodeticCoord_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GeodeticCoord_h_Statics::ScriptStructInfo[] = {
		{ FGeodeticCoord2D::StaticStruct, Z_Construct_UScriptStruct_FGeodeticCoord2D_Statics::NewStructOps, TEXT("GeodeticCoord2D"), &Z_Registration_Info_UScriptStruct_GeodeticCoord2D, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGeodeticCoord2D), 3688870805U) },
		{ FGeodeticCoord3D::StaticStruct, Z_Construct_UScriptStruct_FGeodeticCoord3D_Statics::NewStructOps, TEXT("GeodeticCoord3D"), &Z_Registration_Info_UScriptStruct_GeodeticCoord3D, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGeodeticCoord3D), 3754836998U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GeodeticCoord_h_3653085639(TEXT("/Script/VH_GlobeMath"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GeodeticCoord_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GeodeticCoord_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
