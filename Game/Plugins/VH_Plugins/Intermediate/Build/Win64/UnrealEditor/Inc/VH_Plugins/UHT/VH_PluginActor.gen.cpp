// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_Plugins/Public/VH_PluginActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_PluginActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VH_Plugins();
	VH_PLUGINS_API UClass* Z_Construct_UClass_AVH_PluginActor();
	VH_PLUGINS_API UClass* Z_Construct_UClass_AVH_PluginActor_NoRegister();
// End Cross Module References
	void AVH_PluginActor::StaticRegisterNativesAVH_PluginActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_PluginActor);
	UClass* Z_Construct_UClass_AVH_PluginActor_NoRegister()
	{
		return AVH_PluginActor::StaticClass();
	}
	struct Z_Construct_UClass_AVH_PluginActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_PluginActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Plugins,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_PluginActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_PluginActor_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Use this actor to perform plugin-specific setup that relies on an actor\n * All children of this class found in plugins are intended to be spawned immediately when the game starts\n * Those children may contain their own logic to perform UI Setup, spawn other actors in the world, etc.\n */" },
#endif
		{ "IncludePath", "VH_PluginActor.h" },
		{ "ModuleRelativePath", "Public/VH_PluginActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use this actor to perform plugin-specific setup that relies on an actor\nAll children of this class found in plugins are intended to be spawned immediately when the game starts\nThose children may contain their own logic to perform UI Setup, spawn other actors in the world, etc." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_PluginActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_PluginActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_PluginActor_Statics::ClassParams = {
		&AVH_PluginActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_PluginActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_PluginActor_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AVH_PluginActor()
	{
		if (!Z_Registration_Info_UClass_AVH_PluginActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_PluginActor.OuterSingleton, Z_Construct_UClass_AVH_PluginActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_PluginActor.OuterSingleton;
	}
	template<> VH_PLUGINS_API UClass* StaticClass<AVH_PluginActor>()
	{
		return AVH_PluginActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_PluginActor);
	AVH_PluginActor::~AVH_PluginActor() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_PluginActor, AVH_PluginActor::StaticClass, TEXT("AVH_PluginActor"), &Z_Registration_Info_UClass_AVH_PluginActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_PluginActor), 795111639U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginActor_h_198521589(TEXT("/Script/VH_Plugins"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
