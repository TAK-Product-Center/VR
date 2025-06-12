// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_DataChannel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_DataChannel() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UChannel();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UVH_DataChannel();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UVH_DataChannel_NoRegister();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UVH_DataChannelManager_NoRegister();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature();
	VH_REPLICATION_API UFunction* Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics
	{
		struct VH_DataChannel_eventClientTransferProgress_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannel_eventClientTransferProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannel, nullptr, "ClientTransferProgress__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::VH_DataChannel_eventClientTransferProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::VH_DataChannel_eventClientTransferProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_DataChannel::FClientTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ClientTransferProgress, float pctComplete)
{
	struct VH_DataChannel_eventClientTransferProgress_Parms
	{
		float pctComplete;
	};
	VH_DataChannel_eventClientTransferProgress_Parms Parms;
	Parms.pctComplete=pctComplete;
	ClientTransferProgress.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics
	{
		struct VH_DataChannel_eventServerTransferProgress_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::NewProp_playerController = { "playerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannel_eventServerTransferProgress_Parms, playerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::NewProp_pctComplete = { "pctComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_DataChannel_eventServerTransferProgress_Parms, pctComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::NewProp_playerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::NewProp_pctComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_DataChannel, nullptr, "ServerTransferProgress__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::VH_DataChannel_eventServerTransferProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::VH_DataChannel_eventServerTransferProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_DataChannel::FServerTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ServerTransferProgress, APlayerController* playerController, float pctComplete)
{
	struct VH_DataChannel_eventServerTransferProgress_Parms
	{
		APlayerController* playerController;
		float pctComplete;
	};
	VH_DataChannel_eventServerTransferProgress_Parms Parms;
	Parms.playerController=playerController;
	Parms.pctComplete=pctComplete;
	ServerTransferProgress.ProcessMulticastDelegate<UObject>(&Parms);
}
	void UVH_DataChannel::StaticRegisterNativesUVH_DataChannel()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_DataChannel);
	UClass* Z_Construct_UClass_UVH_DataChannel_NoRegister()
	{
		return UVH_DataChannel::StaticClass();
	}
	struct Z_Construct_UClass_UVH_DataChannel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_EDITOR
		static const FClassFunctionLinkInfo FuncInfo[];
#endif //WITH_EDITOR
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerControllerOwner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerControllerOwner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DCM_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DCM;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataHandler_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DataHandler;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_DataChannel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UChannel,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::DependentSingletons) < 16);
#if WITH_EDITOR
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_DataChannel_Statics::FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature, "ClientTransferProgress__DelegateSignature" }, // 3705608655
		{ &Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature, "ServerTransferProgress__DelegateSignature" }, // 3558507013
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::FuncInfo) < 2048);
#endif //WITH_EDITOR
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Deprecated/Public/VH_DataChannel.h" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientSendProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientSendProgress = { "OnClientSendProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannel, OnClientSendProgress), Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientSendProgress_MetaData), Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientSendProgress_MetaData) }; // 3705608655
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientReceiveProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientReceiveProgress = { "OnClientReceiveProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannel, OnClientReceiveProgress), Z_Construct_UDelegateFunction_UVH_DataChannel_ClientTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientReceiveProgress_MetaData), Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientReceiveProgress_MetaData) }; // 3705608655
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerSendProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerSendProgress = { "OnServerSendProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannel, OnServerSendProgress), Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerSendProgress_MetaData), Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerSendProgress_MetaData) }; // 3558507013
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerReceiveProgress_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerReceiveProgress = { "OnServerReceiveProgress", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannel, OnServerReceiveProgress), Z_Construct_UDelegateFunction_UVH_DataChannel_ServerTransferProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerReceiveProgress_MetaData), Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerReceiveProgress_MetaData) }; // 3558507013
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_PlayerControllerOwner_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_PlayerControllerOwner = { "PlayerControllerOwner", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannel, PlayerControllerOwner), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_PlayerControllerOwner_MetaData), Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_PlayerControllerOwner_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DCM_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DCM = { "DCM", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannel, DCM), Z_Construct_UClass_UVH_DataChannelManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DCM_MetaData), Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DCM_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DataHandler_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_DataChannel.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DataHandler = { "DataHandler", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_DataChannel, DataHandler), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DataHandler_MetaData), Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DataHandler_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_DataChannel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientSendProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnClientReceiveProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerSendProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_OnServerReceiveProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_PlayerControllerOwner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DCM,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_DataChannel_Statics::NewProp_DataHandler,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_DataChannel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_DataChannel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_DataChannel_Statics::ClassParams = {
		&UVH_DataChannel::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		IF_WITH_EDITOR(FuncInfo, nullptr),
		Z_Construct_UClass_UVH_DataChannel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		IF_WITH_EDITOR(UE_ARRAY_COUNT(FuncInfo), 0),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_DataChannel_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_DataChannel_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_DataChannel()
	{
		if (!Z_Registration_Info_UClass_UVH_DataChannel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_DataChannel.OuterSingleton, Z_Construct_UClass_UVH_DataChannel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_DataChannel.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<UVH_DataChannel>()
	{
		return UVH_DataChannel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_DataChannel);
	UVH_DataChannel::~UVH_DataChannel() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_DataChannel, UVH_DataChannel::StaticClass, TEXT("UVH_DataChannel"), &Z_Registration_Info_UClass_UVH_DataChannel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_DataChannel), 2095650409U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_3445891817(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
