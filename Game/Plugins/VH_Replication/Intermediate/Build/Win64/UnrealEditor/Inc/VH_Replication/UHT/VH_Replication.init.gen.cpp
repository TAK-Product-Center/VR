// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_Replication_init() {}
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VH_Replication;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VH_Replication()
	{
		if (!Z_Registration_Info_UPackage__Script_VH_Replication.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VH_Replication",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x522C6333,
				0xC0FA47B5,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VH_Replication.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VH_Replication.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VH_Replication(Z_Construct_UPackage__Script_VH_Replication, TEXT("/Script/VH_Replication"), Z_Registration_Info_UPackage__Script_VH_Replication, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x522C6333, 0xC0FA47B5));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
