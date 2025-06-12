// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Database_MySQL.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FMySQLResult_BP;
#ifdef VH_DATABASE_MYSQL_Database_MySQL_generated_h
#error "Database_MySQL.generated.h already included, missing '#pragma once' in Database_MySQL.h"
#endif
#define VH_DATABASE_MYSQL_Database_MySQL_generated_h

#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_100_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMySQLResult_BP_Statics; \
	VH_DATABASE_MYSQL_API static class UScriptStruct* StaticStruct();


template<> VH_DATABASE_MYSQL_API UScriptStruct* StaticStruct<struct FMySQLResult_BP>();

#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_119_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMySQLResults_BP_Statics; \
	VH_DATABASE_MYSQL_API static class UScriptStruct* StaticStruct();


template<> VH_DATABASE_MYSQL_API UScriptStruct* StaticStruct<struct FMySQLResults_BP>();

#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_SPARSE_DATA
#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetString); \
	DECLARE_FUNCTION(execGetBlob); \
	DECLARE_FUNCTION(execGetString); \
	DECLARE_FUNCTION(execGetDouble); \
	DECLARE_FUNCTION(execGetInteger64); \
	DECLARE_FUNCTION(execGetInteger); \
	DECLARE_FUNCTION(execGetBool);


#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_ACCESSORS
#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDatabase_MySQL(); \
	friend struct Z_Construct_UClass_UDatabase_MySQL_Statics; \
public: \
	DECLARE_CLASS(UDatabase_MySQL, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Database_MySQL"), NO_API) \
	DECLARE_SERIALIZER(UDatabase_MySQL)


#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDatabase_MySQL(UDatabase_MySQL&&); \
	NO_API UDatabase_MySQL(const UDatabase_MySQL&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDatabase_MySQL); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDatabase_MySQL); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDatabase_MySQL) \
	NO_API virtual ~UDatabase_MySQL();


#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_143_PROLOG
#define FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_SPARSE_DATA \
	FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_ACCESSORS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_146_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DATABASE_MYSQL_API UClass* StaticClass<class UDatabase_MySQL>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
