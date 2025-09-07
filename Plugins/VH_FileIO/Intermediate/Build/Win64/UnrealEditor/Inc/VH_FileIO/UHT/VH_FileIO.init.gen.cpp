// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_FileIO_init() {}
	VH_FILEIO_API UFunction* Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VH_FileIO;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VH_FileIO()
	{
		if (!Z_Registration_Info_UPackage__Script_VH_FileIO.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_ImageLoader_OnImageLoadCompleted__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VH_FileIO",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x47E445EF,
				0x874338FD,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VH_FileIO.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VH_FileIO.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VH_FileIO(Z_Construct_UPackage__Script_VH_FileIO, TEXT("/Script/VH_FileIO"), Z_Registration_Info_UPackage__Script_VH_FileIO, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x47E445EF, 0x874338FD));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
