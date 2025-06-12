// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_SessionPlayback_init() {}
	VH_SESSIONPLAYBACK_API UFunction* Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature();
	VH_SESSIONPLAYBACK_API UFunction* Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VH_SessionPlayback;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VH_SessionPlayback()
	{
		if (!Z_Registration_Info_UPackage__Script_VH_SessionPlayback.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VH_SessionPlayback",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x457CEFFD,
				0xDF37806D,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VH_SessionPlayback.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VH_SessionPlayback.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VH_SessionPlayback(Z_Construct_UPackage__Script_VH_SessionPlayback, TEXT("/Script/VH_SessionPlayback"), Z_Registration_Info_UPackage__Script_VH_SessionPlayback, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x457CEFFD, 0xDF37806D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
