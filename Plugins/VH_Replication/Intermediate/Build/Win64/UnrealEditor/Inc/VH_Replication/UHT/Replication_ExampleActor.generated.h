// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Examples/Public/Replication_ExampleActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_REPLICATION_Replication_ExampleActor_generated_h
#error "Replication_ExampleActor.generated.h already included, missing '#pragma once' in Replication_ExampleActor.h"
#endif
#define VH_REPLICATION_Replication_ExampleActor_generated_h

#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_SPARSE_DATA
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_ReplicationID);


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_ACCESSORS
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAReplication_ExampleActor(); \
	friend struct Z_Construct_UClass_AReplication_ExampleActor_Statics; \
public: \
	DECLARE_CLASS(AReplication_ExampleActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Replication"), NO_API) \
	DECLARE_SERIALIZER(AReplication_ExampleActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ReplicationID=NETFIELD_REP_START, \
		NETFIELD_REP_END=ReplicationID	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AReplication_ExampleActor(AReplication_ExampleActor&&); \
	NO_API AReplication_ExampleActor(const AReplication_ExampleActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AReplication_ExampleActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AReplication_ExampleActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AReplication_ExampleActor) \
	NO_API virtual ~AReplication_ExampleActor();


#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_11_PROLOG
#define FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_SPARSE_DATA \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_ACCESSORS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_REPLICATION_API UClass* StaticClass<class AReplication_ExampleActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
