// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ConsoleSettingsUtility.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UConsoleCommandSave;
struct FConsoleCommand;
#ifdef VH_ARTUTILITIESEDITOR_ConsoleSettingsUtility_generated_h
#error "ConsoleSettingsUtility.generated.h already included, missing '#pragma once' in ConsoleSettingsUtility.h"
#endif
#define VH_ARTUTILITIESEDITOR_ConsoleSettingsUtility_generated_h

#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSettingsGroup_Statics; \
	VH_ARTUTILITIESEDITOR_API static class UScriptStruct* StaticStruct();


template<> VH_ARTUTILITIESEDITOR_API UScriptStruct* StaticStruct<struct FSettingsGroup>();

#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_45_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FConsoleCommand_Statics; \
	VH_ARTUTILITIESEDITOR_API static class UScriptStruct* StaticStruct();


template<> VH_ARTUTILITIESEDITOR_API UScriptStruct* StaticStruct<struct FConsoleCommand>();

#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_SPARSE_DATA
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetByRef);


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUConsoleCommandList(); \
	friend struct Z_Construct_UClass_UConsoleCommandList_Statics; \
public: \
	DECLARE_CLASS(UConsoleCommandList, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_ArtUtilitiesEditor"), NO_API) \
	DECLARE_SERIALIZER(UConsoleCommandList)


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConsoleCommandList(UConsoleCommandList&&); \
	NO_API UConsoleCommandList(const UConsoleCommandList&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConsoleCommandList); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConsoleCommandList); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UConsoleCommandList) \
	NO_API virtual ~UConsoleCommandList();


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_81_PROLOG
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_SPARSE_DATA \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_84_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_ARTUTILITIESEDITOR_API UClass* StaticClass<class UConsoleCommandList>();

#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_SPARSE_DATA
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadCurrentCommandsSave); \
	DECLARE_FUNCTION(execSaveCommands); \
	DECLARE_FUNCTION(execTryGetMapName); \
	DECLARE_FUNCTION(execGetSaveSlotName);


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUConsoleSettingsUtilityFunctions(); \
	friend struct Z_Construct_UClass_UConsoleSettingsUtilityFunctions_Statics; \
public: \
	DECLARE_CLASS(UConsoleSettingsUtilityFunctions, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_ArtUtilitiesEditor"), NO_API) \
	DECLARE_SERIALIZER(UConsoleSettingsUtilityFunctions)


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UConsoleSettingsUtilityFunctions(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConsoleSettingsUtilityFunctions(UConsoleSettingsUtilityFunctions&&); \
	NO_API UConsoleSettingsUtilityFunctions(const UConsoleSettingsUtilityFunctions&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConsoleSettingsUtilityFunctions); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConsoleSettingsUtilityFunctions); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UConsoleSettingsUtilityFunctions) \
	NO_API virtual ~UConsoleSettingsUtilityFunctions();


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_121_PROLOG
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_SPARSE_DATA \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h_124_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_ARTUTILITIESEDITOR_API UClass* StaticClass<class UConsoleSettingsUtilityFunctions>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleSettingsUtility_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
