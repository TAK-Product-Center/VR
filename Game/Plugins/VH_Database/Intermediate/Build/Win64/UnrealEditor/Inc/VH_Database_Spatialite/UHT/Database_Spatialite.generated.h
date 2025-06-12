// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Database_Spatialite.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSpatialiteResult_BP;
struct FSpatialiteResults_BP;
#ifdef VH_DATABASE_SPATIALITE_Database_Spatialite_generated_h
#error "Database_Spatialite.generated.h already included, missing '#pragma once' in Database_Spatialite.h"
#endif
#define VH_DATABASE_SPATIALITE_Database_Spatialite_generated_h

#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_71_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics; \
	VH_DATABASE_SPATIALITE_API static class UScriptStruct* StaticStruct();


template<> VH_DATABASE_SPATIALITE_API UScriptStruct* StaticStruct<struct FSpatialiteResult_BP>();

#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_137_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics; \
	VH_DATABASE_SPATIALITE_API static class UScriptStruct* StaticStruct();


template<> VH_DATABASE_SPATIALITE_API UScriptStruct* StaticStruct<struct FSpatialiteResults_BP>();

#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_170_DELEGATE \
static void FDBEvent_DelegateWrapper(const FMulticastScriptDelegate& DBEvent, FSpatialiteResults_BP const& results);


#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_SPARSE_DATA
#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInitialize); \
	DECLARE_FUNCTION(execSetString); \
	DECLARE_FUNCTION(execGetPoint); \
	DECLARE_FUNCTION(execGetBlob); \
	DECLARE_FUNCTION(execGetString); \
	DECLARE_FUNCTION(execGetDouble); \
	DECLARE_FUNCTION(execGetInteger64); \
	DECLARE_FUNCTION(execGetInteger); \
	DECLARE_FUNCTION(execGetBool);


#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_ACCESSORS
#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDatabase_Spatialite(); \
	friend struct Z_Construct_UClass_UDatabase_Spatialite_Statics; \
public: \
	DECLARE_CLASS(UDatabase_Spatialite, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Database_Spatialite"), NO_API) \
	DECLARE_SERIALIZER(UDatabase_Spatialite)


#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDatabase_Spatialite(UDatabase_Spatialite&&); \
	NO_API UDatabase_Spatialite(const UDatabase_Spatialite&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDatabase_Spatialite); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDatabase_Spatialite); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDatabase_Spatialite) \
	NO_API virtual ~UDatabase_Spatialite();


#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_159_PROLOG
#define FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_SPARSE_DATA \
	FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_ACCESSORS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_162_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DATABASE_SPATIALITE_API UClass* StaticClass<class UDatabase_Spatialite>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
