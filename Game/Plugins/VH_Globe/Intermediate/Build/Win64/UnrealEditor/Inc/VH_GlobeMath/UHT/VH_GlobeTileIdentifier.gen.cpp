// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_GlobeMath/Public/VH_GlobeTileIdentifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GlobeTileIdentifier() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_GlobeMath();
	VH_GLOBEMATH_API UScriptStruct* Z_Construct_UScriptStruct_FGlobeTileIdentifier();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GlobeTileIdentifier;
class UScriptStruct* FGlobeTileIdentifier::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GlobeTileIdentifier.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GlobeTileIdentifier.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGlobeTileIdentifier, (UObject*)Z_Construct_UPackage__Script_VH_GlobeMath(), TEXT("GlobeTileIdentifier"));
	}
	return Z_Registration_Info_UScriptStruct_GlobeTileIdentifier.OuterSingleton;
}
template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<FGlobeTileIdentifier>()
{
	return FGlobeTileIdentifier::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_X;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n *\n */" },
#endif
		{ "ModuleRelativePath", "Public/VH_GlobeTileIdentifier.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGlobeTileIdentifier>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Level_MetaData[] = {
		{ "Category", "VhGlobeTileIdentifier" },
		{ "ModuleRelativePath", "Public/VH_GlobeTileIdentifier.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGlobeTileIdentifier, Level), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Level_MetaData), Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Level_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_X_MetaData[] = {
		{ "Category", "VhGlobeTileIdentifier" },
		{ "ModuleRelativePath", "Public/VH_GlobeTileIdentifier.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGlobeTileIdentifier, X), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_X_MetaData), Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_X_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Y_MetaData[] = {
		{ "Category", "VhGlobeTileIdentifier" },
		{ "ModuleRelativePath", "Public/VH_GlobeTileIdentifier.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGlobeTileIdentifier, Y), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Y_MetaData), Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Y_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_X,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewProp_Y,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_GlobeMath,
		nullptr,
		&NewStructOps,
		"GlobeTileIdentifier",
		Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::PropPointers),
		sizeof(FGlobeTileIdentifier),
		alignof(FGlobeTileIdentifier),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FGlobeTileIdentifier()
	{
		if (!Z_Registration_Info_UScriptStruct_GlobeTileIdentifier.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GlobeTileIdentifier.InnerSingleton, Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GlobeTileIdentifier.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTileIdentifier_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTileIdentifier_h_Statics::ScriptStructInfo[] = {
		{ FGlobeTileIdentifier::StaticStruct, Z_Construct_UScriptStruct_FGlobeTileIdentifier_Statics::NewStructOps, TEXT("GlobeTileIdentifier"), &Z_Registration_Info_UScriptStruct_GlobeTileIdentifier, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGlobeTileIdentifier), 920882470U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTileIdentifier_h_2674490104(TEXT("/Script/VH_GlobeMath"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTileIdentifier_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeTileIdentifier_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
