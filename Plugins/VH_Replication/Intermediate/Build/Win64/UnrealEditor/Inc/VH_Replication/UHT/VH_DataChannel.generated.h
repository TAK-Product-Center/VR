// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Deprecated/Public/VH_DataChannel.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
#ifdef VH_REPLICATION_VH_DataChannel_generated_h
#error "VH_DataChannel.generated.h already included, missing '#pragma once' in VH_DataChannel.h"
#endif
#define VH_REPLICATION_VH_DataChannel_generated_h

#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_26_DELEGATE \
static void FClientTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ClientTransferProgress, float pctComplete);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_27_DELEGATE \
static void FServerTransferProgress_DelegateWrapper(const FMulticastScriptDelegate& ServerTransferProgress, APlayerController* playerController, float pctComplete);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_SPARSE_DATA
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_DataChannel(); \
	friend struct Z_Construct_UClass_UVH_DataChannel_Statics; \
public: \
	DECLARE_CLASS(UVH_DataChannel, UChannel, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/VH_Replication"), NO_API) \
	DECLARE_SERIALIZER(UVH_DataChannel)


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_DataChannel(UVH_DataChannel&&); \
	NO_API UVH_DataChannel(const UVH_DataChannel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_DataChannel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_DataChannel); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_DataChannel) \
	NO_API virtual ~UVH_DataChannel();


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_11_PROLOG
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_SPARSE_DATA \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_REPLICATION_API UClass* StaticClass<class UVH_DataChannel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_DataChannel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
