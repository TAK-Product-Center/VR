// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_GlobeTangentCoord.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GlobeTangentCoord() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGlobeTangentCoord();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGlobeTangentCoord2D();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D;
class UScriptStruct* FGlobeTangentCoord2D::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGlobeTangentCoord2D, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("GlobeTangentCoord2D"));
	}
	return Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FGlobeTangentCoord2D>()
{
	return FGlobeTangentCoord2D::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VH_GlobeTangentCoord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGlobeTangentCoord2D>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"GlobeTangentCoord2D",
		nullptr,
		0,
		sizeof(FGlobeTangentCoord2D),
		alignof(FGlobeTangentCoord2D),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGlobeTangentCoord2D()
	{
		if (!Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D.InnerSingleton, Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GlobeTangentCoord;
class UScriptStruct* FGlobeTangentCoord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GlobeTangentCoord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GlobeTangentCoord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGlobeTangentCoord, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("GlobeTangentCoord"));
	}
	return Z_Registration_Info_UScriptStruct_GlobeTangentCoord.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FGlobeTangentCoord>()
{
	return FGlobeTangentCoord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n *\n */" },
#endif
		{ "ModuleRelativePath", "Public/VH_GlobeTangentCoord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGlobeTangentCoord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"GlobeTangentCoord",
		nullptr,
		0,
		sizeof(FGlobeTangentCoord),
		alignof(FGlobeTangentCoord),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGlobeTangentCoord()
	{
		if (!Z_Registration_Info_UScriptStruct_GlobeTangentCoord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GlobeTangentCoord.InnerSingleton, Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GlobeTangentCoord.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTangentCoord_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTangentCoord_h_Statics::ScriptStructInfo[] = {
		{ FGlobeTangentCoord2D::StaticStruct, Z_Construct_UScriptStruct_FGlobeTangentCoord2D_Statics::NewStructOps, TEXT("GlobeTangentCoord2D"), &Z_Registration_Info_UScriptStruct_GlobeTangentCoord2D, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGlobeTangentCoord2D), 2468266538U) },
		{ FGlobeTangentCoord::StaticStruct, Z_Construct_UScriptStruct_FGlobeTangentCoord_Statics::NewStructOps, TEXT("GlobeTangentCoord"), &Z_Registration_Info_UScriptStruct_GlobeTangentCoord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGlobeTangentCoord), 2742884294U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTangentCoord_h_798838634(TEXT("/Script/VH_GlobeMath"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTangentCoord_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTangentCoord_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
