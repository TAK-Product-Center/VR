// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_VR_init() {}
	VH_VR_API UFunction* Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature();
	VH_VR_API UFunction* Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VH_VR;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VH_VR()
	{
		if (!Z_Registration_Info_UPackage__Script_VH_VR.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VH_VR",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x2DB3760C,
				0x21AC2B4E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VH_VR.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VH_VR.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VH_VR(Z_Construct_UPackage__Script_VH_VR, TEXT("/Script/VH_VR"), Z_Registration_Info_UPackage__Script_VH_VR, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x2DB3760C, 0x21AC2B4E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
