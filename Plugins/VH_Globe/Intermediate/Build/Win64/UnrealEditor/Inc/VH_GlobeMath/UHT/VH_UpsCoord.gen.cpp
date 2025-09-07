// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_UpsCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_UpsCoord() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FUpsCoord();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_UpsCoord;
class UScriptStruct* FUpsCoord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_UpsCoord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_UpsCoord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FUpsCoord, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("UpsCoord"));
	}
	return Z_Registration_Info_UScriptStruct_UpsCoord.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FUpsCoord>()
{
	return FUpsCoord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FUpsCoord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUpsCoord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Global 2D coordinate in Universal Polar Stereographic (UPS) coordinate system.\n * See https://en.wikipedia.org/wiki/Universal_polar_stereographic_coordinate_system and https://earth-info.nga.mil/GandG/publications/NGA_SIG_0012_2_0_0_UTMUPS/NGA.SIG.0012_2.0.0_UTMUPS.pdf\n */" },
#endif
		{ "ModuleRelativePath", "Public/VH_UpsCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Global 2D coordinate in Universal Polar Stereographic (UPS) coordinate system.\n* See https://en.wikipedia.org/wiki/Universal_polar_stereographic_coordinate_system and https://earth-info.nga.mil/GandG/publications/NGA_SIG_0012_2_0_0_UTMUPS/NGA.SIG.0012_2.0.0_UTMUPS.pdf" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FUpsCoord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FUpsCoord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FUpsCoord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"UpsCoord",
		nullptr,
		0,
		sizeof(FUpsCoord),
		alignof(FUpsCoord),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUpsCoord_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FUpsCoord_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FUpsCoord()
	{
		if (!Z_Registration_Info_UScriptStruct_UpsCoord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_UpsCoord.InnerSingleton, Z_Construct_UScriptStruct_FUpsCoord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_UpsCoord.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UpsCoord_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UpsCoord_h_Statics::ScriptStructInfo[] = {
		{ FUpsCoord::StaticStruct, Z_Construct_UScriptStruct_FUpsCoord_Statics::NewStructOps, TEXT("UpsCoord"), &Z_Registration_Info_UScriptStruct_UpsCoord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FUpsCoord), 699914469U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UpsCoord_h_1253707184(TEXT("/Script/VH_GlobeMath"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UpsCoord_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UpsCoord_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
