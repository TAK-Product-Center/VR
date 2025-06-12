// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_GameMode_Replication.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_GameMode_Replication() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_AVH_GameMode_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_AVH_GameMode_Replication_NoRegister();
// End Cross Module References
	void AVH_GameMode_Replication::StaticRegisterNativesAVH_GameMode_Replication()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_GameMode_Replication);
	UClass* Z_Construct_UClass_AVH_GameMode_Replication_NoRegister()
	{
		return AVH_GameMode_Replication::StaticClass();
	}
	struct Z_Construct_UClass_AVH_GameMode_Replication_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_GameMode_Replication_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GameMode_Replication_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_GameMode_Replication_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Deprecated/Public/VH_GameMode_Replication.h" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_GameMode_Replication.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_GameMode_Replication_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_GameMode_Replication>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_GameMode_Replication_Statics::ClassParams = {
		&AVH_GameMode_Replication::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_GameMode_Replication_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_GameMode_Replication_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AVH_GameMode_Replication()
	{
		if (!Z_Registration_Info_UClass_AVH_GameMode_Replication.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_GameMode_Replication.OuterSingleton, Z_Construct_UClass_AVH_GameMode_Replication_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_GameMode_Replication.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<AVH_GameMode_Replication>()
	{
		return AVH_GameMode_Replication::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_GameMode_Replication);
	AVH_GameMode_Replication::~AVH_GameMode_Replication() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_GameMode_Replication_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_GameMode_Replication_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_GameMode_Replication, AVH_GameMode_Replication::StaticClass, TEXT("AVH_GameMode_Replication"), &Z_Registration_Info_UClass_AVH_GameMode_Replication, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_GameMode_Replication), 3064766417U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_GameMode_Replication_h_115725697(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_GameMode_Replication_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_GameMode_Replication_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
