// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_DataChannelManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_DataChannelManager() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UVH_DataChannelManager();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UVH_DataChannelManager_NoRegister();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics
	{
		struct VH_DataChannelManager_eventDataReceived_Parms
		{
			TArray<uint8> data;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_data_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_data;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::NewProp_data_Inner = { "data", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::NewProp_data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventDataReceived_Parms, data), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::NewProp_data_MetaData), Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::NewProp_data_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::NewProp_data_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::NewProp_data,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "DataReceived__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::VH_DataChannelManager_eventDataReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::VH_DataChannelManager_eventDataReceived_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_DataChannelManager::FDataReceived_DelegateWrapper(const FMulticastScriptDelegate& DataReceived, TArray<uint8> const& data)
{
	struct VH_DataChannelManager_eventDataReceived_Parms
	{
		TArray<uint8> data;
	};
	VH_DataChannelManager_eventDataReceived_Parms Parms;
	Parms.data=data;
	DataReceived.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics
	{
		struct VH_DataChannelManager_eventServerChannelCreated_Parms
		{
			APlayerController* pc;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_pc;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::NewProp_pc = { "pc", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventServerChannelCreated_Parms, pc), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::NewProp_pc,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "ServerChannelCreated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::VH_DataChannelManager_eventServerChannelCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::VH_DataChannelManager_eventServerChannelCreated_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_DataChannelManager::FServerChannelCreated_DelegateWrapper(const FMulticastScriptDelegate& ServerChannelCreated, APlayerController* pc)
{
	struct VH_DataChannelManager_eventServerChannelCreated_Parms
	{
		APlayerController* pc;
	};
	VH_DataChannelManager_eventServerChannelCreated_Parms Parms;
	Parms.pc=pc;
	ServerChannelCreated.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics
	{
		struct VH_DataChannelManager_eventServerChannelClosed_Parms
		{
			APlayerController* pc;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_pc;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::NewProp_pc = { "pc", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventServerChannelClosed_Parms, pc), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::NewProp_pc,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "ServerChannelClosed__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::VH_DataChannelManager_eventServerChannelClosed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::VH_DataChannelManager_eventServerChannelClosed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_DataChannelManager::FServerChannelClosed_DelegateWrapper(const FMulticastScriptDelegate& ServerChannelClosed, APlayerController* pc)
{
	struct VH_DataChannelManager_eventServerChannelClosed_Parms
	{
		APlayerController* pc;
	};
	VH_DataChannelManager_eventServerChannelClosed_Parms Parms;
	Parms.pc=pc;
	ServerChannelClosed.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics
	{
		struct VH_DataChannelManager_eventClientTransferProgress_Parms
		{
			float pctComplete;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pctComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventClientTransferProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "ClientTransferProgress__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::VH_DataChannelManager_eventClientTransferProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::VH_DataChannelManager_eventClientTransferProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_DataChannelManager::FClientTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ClientTransferProgress, float pctComplete)
{
	struct VH_DataChannelManager_eventClientTransferProgress_Parms
	{
		float pctComplete;
	};
	VH_DataChannelManager_eventClientTransferProgress_Parms Parms;
	Parms.pctComplete=pctComplete;
	ClientTransferProgress.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics
	{
		struct VH_DataChannelManager_eventServerTransferProgress_Parms
		{
			APlayerController* playerController;
			float pctComplete;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_playerController;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pctComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::NewProp_playerController = { "playerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventServerTransferProgress_Parms, playerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventServerTransferProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::NewProp_playerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "ServerTransferProgress__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::VH_DataChannelManager_eventServerTransferProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::VH_DataChannelManager_eventServerTransferProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_DataChannelManager::FServerTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ServerTransferProgress, APlayerController* playerController, float pctComplete)
{
	struct VH_DataChannelManager_eventServerTransferProgress_Parms
	{
		APlayerController* playerController;
		float pctComplete;
	};
	VH_DataChannelManager_eventServerTransferProgress_Parms Parms;
	Parms.playerController=playerController;
	Parms.pctComplete=pctComplete;
	ServerTransferProgress.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UVH_DataChannelManager::execHandleServerReceiveProgress)
	{
		P_GET_OBJECT(APlayerController,Z_Param_playerController);
		P_GET_PROPERTY(FFloatProperty,Z_Param_pctComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleServerReceiveProgress(Z_Param_playerController,Z_Param_pctComplete);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_DataChannelManager::execHandleServerSendProgress)
	{
		P_GET_OBJECT(APlayerController,Z_Param_playerController);
		P_GET_PROPERTY(FFloatProperty,Z_Param_pctComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleServerSendProgress(Z_Param_playerController,Z_Param_pctComplete);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_DataChannelManager::execHandleClientReceiveProgress)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_pctComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleClientReceiveProgress(Z_Param_pctComplete);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_DataChannelManager::execHandleClientSendProgress)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_pctComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleClientSendProgress(Z_Param_pctComplete);
		P_NATIVE_END;
	}
	void UVH_DataChannelManager::StaticRegisterNativesUVH_DataChannelManager()
	{
		UClass* Class = UVH_DataChannelManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleClientReceiveProgress", &UVH_DataChannelManager::execHandleClientReceiveProgress },
			{ "HandleClientSendProgress", &UVH_DataChannelManager::execHandleClientSendProgress },
			{ "HandleServerReceiveProgress", &UVH_DataChannelManager::execHandleServerReceiveProgress },
			{ "HandleServerSendProgress", &UVH_DataChannelManager::execHandleServerSendProgress },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics
	{
		struct VH_DataChannelManager_eventHandleClientReceiveProgress_Parms
		{
			float pctComplete;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pctComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventHandleClientReceiveProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "HandleClientReceiveProgress", nullptr, nullptr, Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::VH_DataChannelManager_eventHandleClientReceiveProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::VH_DataChannelManager_eventHandleClientReceiveProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics
	{
		struct VH_DataChannelManager_eventHandleClientSendProgress_Parms
		{
			float pctComplete;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pctComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventHandleClientSendProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "HandleClientSendProgress", nullptr, nullptr, Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::VH_DataChannelManager_eventHandleClientSendProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::VH_DataChannelManager_eventHandleClientSendProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics
	{
		struct VH_DataChannelManager_eventHandleServerReceiveProgress_Parms
		{
			APlayerController* playerController;
			float pctComplete;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_playerController;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pctComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::NewProp_playerController = { "playerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventHandleServerReceiveProgress_Parms, playerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventHandleServerReceiveProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::NewProp_playerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "HandleServerReceiveProgress", nullptr, nullptr, Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::VH_DataChannelManager_eventHandleServerReceiveProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::VH_DataChannelManager_eventHandleServerReceiveProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics
	{
		struct VH_DataChannelManager_eventHandleServerSendProgress_Parms
		{
			APlayerController* playerController;
			float pctComplete;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_playerController;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pctComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::NewProp_playerController = { "playerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventHandleServerSendProgress_Parms, playerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannelManager_eventHandleServerSendProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::NewProp_playerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannelManager, nullptr, "HandleServerSendProgress", nullptr, nullptr, Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::VH_DataChannelManager_eventHandleServerSendProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::VH_DataChannelManager_eventHandleServerSendProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_DataChannelManager);
	UClass* Z_Construct_UClass_UVH_DataChannelManager_NoRegister()
	{
		return UVH_DataChannelManager::StaticClass();
	}
	struct Z_Construct_UClass_UVH_DataChannelManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OwningActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnDataReceived_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDataReceived;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnServerChannelCreated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnServerChannelCreated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnServerChannelClosed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnServerChannelClosed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnClientSendProgress_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnClientSendProgress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnClientReceiveProgress_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnClientReceiveProgress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnServerSendProgress_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnServerSendProgress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnServerReceiveProgress_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnServerReceiveProgress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_DataChannelManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_DataChannelManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature, "ClientTransferProgress__DelegateSignature" }, // 1159727379
		{ &Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature, "DataReceived__DelegateSignature" }, // 799322859
		{ &Z_Construct_UFunction_UVH_DataChannelManager_HandleClientReceiveProgress, "HandleClientReceiveProgress" }, // 4058052822
		{ &Z_Construct_UFunction_UVH_DataChannelManager_HandleClientSendProgress, "HandleClientSendProgress" }, // 3890088604
		{ &Z_Construct_UFunction_UVH_DataChannelManager_HandleServerReceiveProgress, "HandleServerReceiveProgress" }, // 4185148996
		{ &Z_Construct_UFunction_UVH_DataChannelManager_HandleServerSendProgress, "HandleServerSendProgress" }, // 3091709915
		{ &Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelClosed__DelegateSignature, "ServerChannelClosed__DelegateSignature" }, // 1489030453
		{ &Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature, "ServerChannelCreated__DelegateSignature" }, // 1546071227
		{ &Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature, "ServerTransferProgress__DelegateSignature" }, // 3850479708
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Deprecated/Public/VH_DataChannelManager.h" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OwningActor_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OwningActor = { "OwningActor", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OwningActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OwningActor_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OwningActor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnDataReceived_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnDataReceived = { "OnDataReceived", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OnDataReceived), Z_Construct_UDelegateFunction_UVH_DataChannelManager_DataReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnDataReceived_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnDataReceived_MetaData) }; // 799322859
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelCreated_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelCreated = { "OnServerChannelCreated", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OnServerChannelCreated), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelCreated_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelCreated_MetaData) }; // 1546071227
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelClosed_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelClosed = { "OnServerChannelClosed", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OnServerChannelClosed), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerChannelCreated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelClosed_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelClosed_MetaData) }; // 1546071227
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientSendProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientSendProgress = { "OnClientSendProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OnClientSendProgress), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientSendProgress_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientSendProgress_MetaData) }; // 1159727379
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientReceiveProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientReceiveProgress = { "OnClientReceiveProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OnClientReceiveProgress), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ClientTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientReceiveProgress_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientReceiveProgress_MetaData) }; // 1159727379
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerSendProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerSendProgress = { "OnServerSendProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OnServerSendProgress), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerSendProgress_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerSendProgress_MetaData) }; // 3850479708
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerReceiveProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannelManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerReceiveProgress = { "OnServerReceiveProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannelManager, OnServerReceiveProgress), Z_Construct_UDelegateFunction_UVH_DataChannelManager_ServerTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerReceiveProgress_MetaData), Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerReceiveProgress_MetaData) }; // 3850479708
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_DataChannelManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OwningActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnDataReceived,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelCreated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerChannelClosed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientSendProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnClientReceiveProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerSendProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannelManager_Statics::NewProp_OnServerReceiveProgress,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_DataChannelManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_DataChannelManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_DataChannelManager_Statics::ClassParams = {
		&UVH_DataChannelManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_DataChannelManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_DataChannelManager_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannelManager_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_DataChannelManager()
	{
		if (!Z_Registration_Info_UClass_UVH_DataChannelManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_DataChannelManager.OuterSingleton, Z_Construct_UClass_UVH_DataChannelManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_DataChannelManager.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<UVH_DataChannelManager>()
	{
		return UVH_DataChannelManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_DataChannelManager);
	UVH_DataChannelManager::~UVH_DataChannelManager() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_DataChannelManager, UVH_DataChannelManager::StaticClass, TEXT("UVH_DataChannelManager"), &Z_Registration_Info_UClass_UVH_DataChannelManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_DataChannelManager), 742018530U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_1283796763(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
