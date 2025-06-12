// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/Keyboard_Subsystem_Core.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UKeyboard_Subsystem_Core_Settings;
class UObject;
#ifdef VH_KEYBOARD_Keyboard_Subsystem_Core_generated_h
#error "Keyboard_Subsystem_Core.generated.h already included, missing '#pragma once' in Keyboard_Subsystem_Core.h"
#endif
#define VH_KEYBOARD_Keyboard_Subsystem_Core_generated_h

#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_22_DELEGATE \
static void FKeyboardSpawnDestroy_DelegateWrapper(const FMulticastScriptDelegate& KeyboardSpawnDestroy, bool bSpawn, AActor* keyboardContainer);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_SPARSE_DATA
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleKeyboardDestroyed); \
	DECLARE_FUNCTION(execIsKeyboardOpen); \
	DECLARE_FUNCTION(execCreateKeyboardByClassForObject); \
	DECLARE_FUNCTION(execCreateKeyboardByClassAtTransform); \
	DECLARE_FUNCTION(execCreateKeyBoardForObject); \
	DECLARE_FUNCTION(execCreateKeyboardAtTransform); \
	DECLARE_FUNCTION(execUpdateSettings);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUKeyboard_Subsystem_Core(); \
	friend struct Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics; \
public: \
	DECLARE_CLASS(UKeyboard_Subsystem_Core, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Keyboard"), NO_API) \
	DECLARE_SERIALIZER(UKeyboard_Subsystem_Core)


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UKeyboard_Subsystem_Core(UKeyboard_Subsystem_Core&&); \
	NO_API UKeyboard_Subsystem_Core(const UKeyboard_Subsystem_Core&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKeyboard_Subsystem_Core); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKeyboard_Subsystem_Core); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UKeyboard_Subsystem_Core) \
	NO_API virtual ~UKeyboard_Subsystem_Core();


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_11_PROLOG
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_SPARSE_DATA \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_KEYBOARD_API UClass* StaticClass<class UKeyboard_Subsystem_Core>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
