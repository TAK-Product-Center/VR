// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_GlobeMathTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GlobeMathTypes() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UEnum* Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGeoLocationType;
	static UEnum* EGeoLocationType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EGeoLocationType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EGeoLocationType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("EGeoLocationType"));
		}
		return Z_Registration_Info_UEnum_EGeoLocationType.OuterSingleton;
	}
	template<> VH_GLOBEMATH_API UEnum* StaticEnum<EGeoLocationType>()
	{
		return EGeoLocationType_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::Enumerators[] = {
		{ "EGeoLocationType::Geodetic", (int64)EGeoLocationType::Geodetic },
		{ "EGeoLocationType::MGRS", (int64)EGeoLocationType::MGRS },
		{ "EGeoLocationType::UTM", (int64)EGeoLocationType::UTM },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n *\n */" },
#endif
		{ "Geodetic.Comment", "/*\n *\n */" },
		{ "Geodetic.Name", "EGeoLocationType::Geodetic" },
		{ "MGRS.Comment", "/*\n *\n */" },
		{ "MGRS.Name", "EGeoLocationType::MGRS" },
		{ "ModuleRelativePath", "Public/VH_GlobeMathTypes.h" },
		{ "UTM.Comment", "/*\n *\n */" },
		{ "UTM.Name", "EGeoLocationType::UTM" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		"EGeoLocationType",
		"EGeoLocationType",
		Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType()
	{
		if (!Z_Registration_Info_UEnum_EGeoLocationType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGeoLocationType.InnerSingleton, Z_Construct_UEnum_VH_GlobeMath_EGeoLocationType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EGeoLocationType.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathTypes_h_Statics::EnumInfo[] = {
		{ EGeoLocationType_StaticEnum, TEXT("EGeoLocationType"), &Z_Registration_Info_UEnum_EGeoLocationType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3937859126U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathTypes_h_1623872490(TEXT("/Script/VH_GlobeMath"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
