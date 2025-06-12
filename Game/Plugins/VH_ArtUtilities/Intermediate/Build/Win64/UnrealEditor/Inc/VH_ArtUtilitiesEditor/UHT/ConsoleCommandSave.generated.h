// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ConsoleCommandSave.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 class UConsoleCommandList;
struct FConsoleCommand;
struct FSettingsGroup;
#ifdef VH_ARTUTILITIESEDITOR_ConsoleCommandSave_generated_h
#error "ConsoleCommandSave.generated.h already included, missing '#pragma once' in ConsoleCommandSave.h"
#endif
#define VH_ARTUTILITIESEDITOR_ConsoleCommandSave_generated_h

#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSavedCommandsStruct_Statics; \
	VH_ARTUTILITIESEDITOR_API static class UScriptStruct* StaticStruct();


template<> VH_ARTUTILITIESEDITOR_API UScriptStruct* StaticStruct<struct FSavedCommandsStruct>();

#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_SPARSE_DATA
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRetrieveSaveGameVariables); \
	DECLARE_FUNCTION(execPopulateSaveGameVariables);


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_ACCESSORS
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUConsoleCommandSave(); \
	friend struct Z_Construct_UClass_UConsoleCommandSave_Statics; \
public: \
	DECLARE_CLASS(UConsoleCommandSave, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_ArtUtilitiesEditor"), NO_API) \
	DECLARE_SERIALIZER(UConsoleCommandSave)


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UConsoleCommandSave(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConsoleCommandSave(UConsoleCommandSave&&); \
	NO_API UConsoleCommandSave(const UConsoleCommandSave&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConsoleCommandSave); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConsoleCommandSave); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UConsoleCommandSave) \
	NO_API virtual ~UConsoleCommandSave();


#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_54_PROLOG
#define FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_SPARSE_DATA \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_ACCESSORS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h_57_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_ARTUTILITIESEDITOR_API UClass* StaticClass<class UConsoleCommandSave>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilitiesEditor_Public_ConsoleCommandSave_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
