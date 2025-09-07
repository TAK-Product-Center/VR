// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_Database_Spatialite_init() {}
	VH_DATABASE_SPATIALITE_API UFunction* Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VH_Database_Spatialite;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VH_Database_Spatialite()
	{
		if (!Z_Registration_Info_UPackage__Script_VH_Database_Spatialite.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VH_Database_Spatialite",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xF2924B87,
				0xC533025E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VH_Database_Spatialite.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VH_Database_Spatialite.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VH_Database_Spatialite(Z_Construct_UPackage__Script_VH_Database_Spatialite, TEXT("/Script/VH_Database_Spatialite"), Z_Registration_Info_UPackage__Script_VH_Database_Spatialite, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF2924B87, 0xC533025E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
