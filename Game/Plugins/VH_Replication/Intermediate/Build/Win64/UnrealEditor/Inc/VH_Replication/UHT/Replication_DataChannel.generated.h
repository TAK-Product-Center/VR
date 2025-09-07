// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Replication_DataChannel.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_REPLICATION_Replication_DataChannel_generated_h
#error "Replication_DataChannel.generated.h already included, missing '#pragma once' in Replication_DataChannel.h"
#endif
#define VH_REPLICATION_Replication_DataChannel_generated_h

#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_SPARSE_DATA
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUReplication_DataChannel(); \
	friend struct Z_Construct_UClass_UReplication_DataChannel_Statics; \
public: \
	DECLARE_CLASS(UReplication_DataChannel, UChannel, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/VH_Replication"), NO_API) \
	DECLARE_SERIALIZER(UReplication_DataChannel)


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReplication_DataChannel(UReplication_DataChannel&&); \
	NO_API UReplication_DataChannel(const UReplication_DataChannel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReplication_DataChannel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReplication_DataChannel); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReplication_DataChannel) \
	NO_API virtual ~UReplication_DataChannel();


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_22_PROLOG
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_SPARSE_DATA \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_REPLICATION_API UClass* StaticClass<class UReplication_DataChannel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h


#define FOREACH_ENUM_EREPLICATIONDATATYPE(op) \
	op(EReplicationDataType::InitialParameters) \
	op(EReplicationDataType::Data) 

enum class EReplicationDataType : uint8;
template<> struct TIsUEnumClass<EReplicationDataType> { enum { Value = true }; };
template<> VH_REPLICATION_API UEnum* StaticEnum<EReplicationDataType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
