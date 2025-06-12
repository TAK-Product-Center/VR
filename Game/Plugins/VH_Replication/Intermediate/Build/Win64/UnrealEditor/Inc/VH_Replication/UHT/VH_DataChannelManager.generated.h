// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Deprecated/Public/VH_DataChannelManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
#ifdef VH_REPLICATION_VH_DataChannelManager_generated_h
#error "VH_DataChannelManager.generated.h already included, missing '#pragma once' in VH_DataChannelManager.h"
#endif
#define VH_REPLICATION_VH_DataChannelManager_generated_h

#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_15_DELEGATE \
static void FDataReceived_DelegateWrapper(const FMulticastScriptDelegate& DataReceived, TArray<uint8> const& data);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_16_DELEGATE \
static void FServerChannelCreated_DelegateWrapper(const FMulticastScriptDelegate& ServerChannelCreated, APlayerController* pc);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_17_DELEGATE \
static void FServerChannelClosed_DelegateWrapper(const FMulticastScriptDelegate& ServerChannelClosed, APlayerController* pc);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_18_DELEGATE \
static void FClientTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ClientTransferProgress, float pctComplete);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_19_DELEGATE \
static void FServerTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ServerTransferProgress, APlayerController* playerController, float pctComplete);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_SPARSE_DATA
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleServerReceiveProgress); \
	DECLARE_FUNCTION(execHandleServerSendProgress); \
	DECLARE_FUNCTION(execHandleClientReceiveProgress); \
	DECLARE_FUNCTION(execHandleClientSendProgress);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_DataChannelManager(); \
	friend struct Z_Construct_UClass_UVH_DataChannelManager_Statics; \
public: \
	DECLARE_CLASS(UVH_DataChannelManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Replication"), NO_API) \
	DECLARE_SERIALIZER(UVH_DataChannelManager)


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_DataChannelManager(UVH_DataChannelManager&&); \
	NO_API UVH_DataChannelManager(const UVH_DataChannelManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_DataChannelManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_DataChannelManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_DataChannelManager) \
	NO_API virtual ~UVH_DataChannelManager();


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_6_PROLOG
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_SPARSE_DATA \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_REPLICATION_API UClass* StaticClass<class UVH_DataChannelManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannelManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
