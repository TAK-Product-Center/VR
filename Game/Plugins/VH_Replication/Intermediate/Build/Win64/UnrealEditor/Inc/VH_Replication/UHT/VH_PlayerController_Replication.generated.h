// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Deprecated/Public/VH_PlayerController_Replication.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef VH_REPLICATION_VH_PlayerController_Replication_generated_h
#error "VH_PlayerController_Replication.generated.h already included, missing '#pragma once' in VH_PlayerController_Replication.h"
#endif
#define VH_REPLICATION_VH_PlayerController_Replication_generated_h

#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_SPARSE_DATA
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerSetChannelReady_Validate(int32 , AActor* , bool ); \
	virtual void ServerSetChannelReady_Implementation(int32 id, AActor* actor, bool bReady); \
 \
	DECLARE_FUNCTION(execServerSetChannelReady);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVH_PlayerController_Replication(); \
	friend struct Z_Construct_UClass_AVH_PlayerController_Replication_Statics; \
public: \
	DECLARE_CLASS(AVH_PlayerController_Replication, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Replication"), NO_API) \
	DECLARE_SERIALIZER(AVH_PlayerController_Replication)


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVH_PlayerController_Replication(AVH_PlayerController_Replication&&); \
	NO_API AVH_PlayerController_Replication(const AVH_PlayerController_Replication&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVH_PlayerController_Replication); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVH_PlayerController_Replication); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVH_PlayerController_Replication) \
	NO_API virtual ~AVH_PlayerController_Replication();


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_9_PROLOG
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_SPARSE_DATA \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_REPLICATION_API UClass* StaticClass<class AVH_PlayerController_Replication>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
