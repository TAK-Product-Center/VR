// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/Interface_DataChannelManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_DataChannelManager() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UInterface_DataChannelManager();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UInterface_DataChannelManager_NoRegister();
// End Cross Module References
	void UInterface_DataChannelManager::StaticRegisterNativesUInterface_DataChannelManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_DataChannelManager);
	UClass* Z_Construct_UClass_UInterface_DataChannelManager_NoRegister()
	{
		return UInterface_DataChannelManager::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_DataChannelManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_DataChannelManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_DataChannelManager_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_DataChannelManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/Interface_DataChannelManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_DataChannelManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_DataChannelManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_DataChannelManager_Statics::ClassParams = {
		&UInterface_DataChannelManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000040A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_DataChannelManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_DataChannelManager_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_DataChannelManager()
	{
		if (!Z_Registration_Info_UClass_UInterface_DataChannelManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_DataChannelManager.OuterSingleton, Z_Construct_UClass_UInterface_DataChannelManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_DataChannelManager.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<UInterface_DataChannelManager>()
	{
		return UInterface_DataChannelManager::StaticClass();
	}
	UInterface_DataChannelManager::UInterface_DataChannelManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_DataChannelManager);
	UInterface_DataChannelManager::~UInterface_DataChannelManager() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_DataChannelManager, UInterface_DataChannelManager::StaticClass, TEXT("UInterface_DataChannelManager"), &Z_Registration_Info_UClass_UInterface_DataChannelManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_DataChannelManager), 2373760962U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_518286150(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
