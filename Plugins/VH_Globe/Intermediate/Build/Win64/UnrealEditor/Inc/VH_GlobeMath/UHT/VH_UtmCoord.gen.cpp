// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_UtmCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_UtmCoord() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FUtmCoord();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_UtmCoord;
class UScriptStruct* FUtmCoord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_UtmCoord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_UtmCoord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FUtmCoord, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("UtmCoord"));
	}
	return Z_Registration_Info_UScriptStruct_UtmCoord.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FUtmCoord>()
{
	return FUtmCoord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FUtmCoord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUtmCoord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Global 2D coordinate in Universal Transverse Mercator (UTM).\n * See https://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system and https://www.maptools.com/tutorials/utm/quick_guide\n */" },
#endif
		{ "ModuleRelativePath", "Public/VH_UtmCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Global 2D coordinate in Universal Transverse Mercator (UTM).\n* See https://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system and https://www.maptools.com/tutorials/utm/quick_guide" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FUtmCoord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FUtmCoord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FUtmCoord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"UtmCoord",
		nullptr,
		0,
		sizeof(FUtmCoord),
		alignof(FUtmCoord),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUtmCoord_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FUtmCoord_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FUtmCoord()
	{
		if (!Z_Registration_Info_UScriptStruct_UtmCoord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_UtmCoord.InnerSingleton, Z_Construct_UScriptStruct_FUtmCoord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_UtmCoord.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UtmCoord_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UtmCoord_h_Statics::ScriptStructInfo[] = {
		{ FUtmCoord::StaticStruct, Z_Construct_UScriptStruct_FUtmCoord_Statics::NewStructOps, TEXT("UtmCoord"), &Z_Registration_Info_UScriptStruct_UtmCoord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FUtmCoord), 1126432294U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UtmCoord_h_3405009475(TEXT("/Script/VH_GlobeMath"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UtmCoord_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_UtmCoord_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
