// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_MgrsCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_MgrsCoord() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FMgrsCoord();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MgrsCoord;
class UScriptStruct* FMgrsCoord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MgrsCoord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MgrsCoord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMgrsCoord, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("MgrsCoord"));
	}
	return Z_Registration_Info_UScriptStruct_MgrsCoord.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FMgrsCoord>()
{
	return FMgrsCoord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMgrsCoord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMgrsCoord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Global 2D coordinate in Military Grid Reference System (MGRS).\n * See https://en.wikipedia.org/wiki/Military_Grid_Reference_System and https://www.maptools.com/tutorials/mgrs/quick_guide\n */" },
#endif
		{ "ModuleRelativePath", "Public/VH_MgrsCoord.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Global 2D coordinate in Military Grid Reference System (MGRS).\n* See https://en.wikipedia.org/wiki/Military_Grid_Reference_System and https://www.maptools.com/tutorials/mgrs/quick_guide" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FMgrsCoord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMgrsCoord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMgrsCoord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"MgrsCoord",
		nullptr,
		0,
		sizeof(FMgrsCoord),
		alignof(FMgrsCoord),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMgrsCoord_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMgrsCoord_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMgrsCoord()
	{
		if (!Z_Registration_Info_UScriptStruct_MgrsCoord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MgrsCoord.InnerSingleton, Z_Construct_UScriptStruct_FMgrsCoord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MgrsCoord.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_MgrsCoord_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_MgrsCoord_h_Statics::ScriptStructInfo[] = {
		{ FMgrsCoord::StaticStruct, Z_Construct_UScriptStruct_FMgrsCoord_Statics::NewStructOps, TEXT("MgrsCoord"), &Z_Registration_Info_UScriptStruct_MgrsCoord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMgrsCoord), 674317956U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_MgrsCoord_h_3554470941(TEXT("/Script/VH_GlobeMath"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_MgrsCoord_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_MgrsCoord_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
