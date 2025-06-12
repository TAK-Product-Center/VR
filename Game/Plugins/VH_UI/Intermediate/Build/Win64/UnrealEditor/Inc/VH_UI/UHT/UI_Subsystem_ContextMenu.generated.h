// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/UI_Subsystem_ContextMenu.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UObject;
class UUI_Subsystem_ContextMenu_Settings;
class UUserWidget;
#ifdef VH_UI_UI_Subsystem_ContextMenu_generated_h
#error "UI_Subsystem_ContextMenu.generated.h already included, missing '#pragma once' in UI_Subsystem_ContextMenu.h"
#endif
#define VH_UI_UI_Subsystem_ContextMenu_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FContextOptionClasses_Statics; \
	VH_UI_API static class UScriptStruct* StaticStruct();


template<> VH_UI_API UScriptStruct* StaticStruct<struct FContextOptionClasses>();

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleUserWidgetClosed); \
	DECLARE_FUNCTION(execCloseContextMenusOfClass); \
	DECLARE_FUNCTION(execCloseContextMenusForClass); \
	DECLARE_FUNCTION(execRegisterContextMenu); \
	DECLARE_FUNCTION(execGetSourceFromContextMenu); \
	DECLARE_FUNCTION(execGetContextMenuFromSource); \
	DECLARE_FUNCTION(execGetContextOptions); \
	DECLARE_FUNCTION(execOpenContextMenuWithDefaults); \
	DECLARE_FUNCTION(execUpdateSettings);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUI_Subsystem_ContextMenu(); \
	friend struct Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics; \
public: \
	DECLARE_CLASS(UUI_Subsystem_ContextMenu, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UUI_Subsystem_ContextMenu)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_Subsystem_ContextMenu(UUI_Subsystem_ContextMenu&&); \
	NO_API UUI_Subsystem_ContextMenu(const UUI_Subsystem_ContextMenu&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_Subsystem_ContextMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_Subsystem_ContextMenu); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UUI_Subsystem_ContextMenu) \
	NO_API virtual ~UUI_Subsystem_ContextMenu();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_26_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UUI_Subsystem_ContextMenu>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
