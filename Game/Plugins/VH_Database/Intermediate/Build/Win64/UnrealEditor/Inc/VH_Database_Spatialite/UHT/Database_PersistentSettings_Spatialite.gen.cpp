// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_Database_Spatialite/Public/Database_PersistentSettings_Spatialite.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDatabase_PersistentSettings_Spatialite() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_Database_Spatialite();
	VH_DATABASE_SPATIALITE_API UClass* Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite();
	VH_DATABASE_SPATIALITE_API UClass* Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_NoRegister();
	VH_DATABASE_SPATIALITE_API UClass* Z_Construct_UClass_UDatabase_Spatialite_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_PersistentSettings();
// End Cross Module References
	void UDatabase_PersistentSettings_Spatialite::StaticRegisterNativesUDatabase_PersistentSettings_Spatialite()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDatabase_PersistentSettings_Spatialite);
	UClass* Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_NoRegister()
	{
		return UDatabase_PersistentSettings_Spatialite::StaticClass();
	}
	struct Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpatialiteDB_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpatialiteDB;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloper_PersistentSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Database_Spatialite,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Database_PersistentSettings_Spatialite.h" },
		{ "ModuleRelativePath", "Public/Database_PersistentSettings_Spatialite.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::NewProp_SpatialiteDB_MetaData[] = {
		{ "ModuleRelativePath", "Public/Database_PersistentSettings_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::NewProp_SpatialiteDB = { "SpatialiteDB", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDatabase_PersistentSettings_Spatialite, SpatialiteDB), Z_Construct_UClass_UDatabase_Spatialite_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::NewProp_SpatialiteDB_MetaData), Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::NewProp_SpatialiteDB_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::NewProp_SpatialiteDB,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDatabase_PersistentSettings_Spatialite>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::ClassParams = {
		&UDatabase_PersistentSettings_Spatialite::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::Class_MetaDataParams), Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite()
	{
		if (!Z_Registration_Info_UClass_UDatabase_PersistentSettings_Spatialite.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDatabase_PersistentSettings_Spatialite.OuterSingleton, Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDatabase_PersistentSettings_Spatialite.OuterSingleton;
	}
	template<> VH_DATABASE_SPATIALITE_API UClass* StaticClass<UDatabase_PersistentSettings_Spatialite>()
	{
		return UDatabase_PersistentSettings_Spatialite::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDatabase_PersistentSettings_Spatialite);
	UDatabase_PersistentSettings_Spatialite::~UDatabase_PersistentSettings_Spatialite() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_PersistentSettings_Spatialite_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_PersistentSettings_Spatialite_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDatabase_PersistentSettings_Spatialite, UDatabase_PersistentSettings_Spatialite::StaticClass, TEXT("UDatabase_PersistentSettings_Spatialite"), &Z_Registration_Info_UClass_UDatabase_PersistentSettings_Spatialite, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDatabase_PersistentSettings_Spatialite), 1560595785U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_PersistentSettings_Spatialite_h_2951866689(TEXT("/Script/VH_Database_Spatialite"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_PersistentSettings_Spatialite_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_PersistentSettings_Spatialite_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
