// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_Vehicle_init() {}
	VH_VEHICLE_API UFunction* Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature();
	VH_VEHICLE_API UFunction* Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VH_Vehicle;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VH_Vehicle()
	{
		if (!Z_Registration_Info_UPackage__Script_VH_Vehicle.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VH_Vehicle",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x0C44F8E4,
				0xAF7479DB,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VH_Vehicle.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VH_Vehicle.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VH_Vehicle(Z_Construct_UPackage__Script_VH_Vehicle, TEXT("/Script/VH_Vehicle"), Z_Registration_Info_UPackage__Script_VH_Vehicle, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0C44F8E4, 0xAF7479DB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
