// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Deprecated/Public/Interface_DataChannelManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_REPLICATION_Interface_DataChannelManager_generated_h
#error "Interface_DataChannelManager.generated.h already included, missing '#pragma once' in Interface_DataChannelManager.h"
#endif
#define VH_REPLICATION_Interface_DataChannelManager_generated_h

#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_SPARSE_DATA
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_DataChannelManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_DataChannelManager(UInterface_DataChannelManager&&); \
	NO_API UInterface_DataChannelManager(const UInterface_DataChannelManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_DataChannelManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_DataChannelManager); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_DataChannelManager) \
	NO_API virtual ~UInterface_DataChannelManager();


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_DataChannelManager(); \
	friend struct Z_Construct_UClass_UInterface_DataChannelManager_Statics; \
public: \
	DECLARE_CLASS(UInterface_DataChannelManager, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_Replication"), NO_API) \
	DECLARE_SERIALIZER(UInterface_DataChannelManager)


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_DataChannelManager() {} \
public: \
	typedef UInterface_DataChannelManager UClassType; \
	typedef IInterface_DataChannelManager ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_11_PROLOG
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_SPARSE_DATA \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_REPLICATION_API UClass* StaticClass<class UInterface_DataChannelManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_Interface_DataChannelManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
