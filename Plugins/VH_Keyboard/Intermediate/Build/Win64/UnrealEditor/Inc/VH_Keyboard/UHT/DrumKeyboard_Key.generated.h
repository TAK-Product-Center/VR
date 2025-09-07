// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Examples/Public/DrumKeyboard_Key.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UKeyboard_ContainerComponent;
struct FKey;
#ifdef VH_KEYBOARD_DrumKeyboard_Key_generated_h
#error "DrumKeyboard_Key.generated.h already included, missing '#pragma once' in DrumKeyboard_Key.h"
#endif
#define VH_KEYBOARD_DrumKeyboard_Key_generated_h

#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_SPARSE_DATA
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleClickReleased); \
	DECLARE_FUNCTION(execHandleClickPressed); \
	DECLARE_FUNCTION(execHandleShiftModified); \
	DECLARE_FUNCTION(execSetContainerComponent); \
	DECLARE_FUNCTION(execPressed);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADrumKeyboard_Key(); \
	friend struct Z_Construct_UClass_ADrumKeyboard_Key_Statics; \
public: \
	DECLARE_CLASS(ADrumKeyboard_Key, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Keyboard"), NO_API) \
	DECLARE_SERIALIZER(ADrumKeyboard_Key)


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADrumKeyboard_Key(ADrumKeyboard_Key&&); \
	NO_API ADrumKeyboard_Key(const ADrumKeyboard_Key&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADrumKeyboard_Key); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADrumKeyboard_Key); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADrumKeyboard_Key) \
	NO_API virtual ~ADrumKeyboard_Key();


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_14_PROLOG
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_SPARSE_DATA \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_KEYBOARD_API UClass* StaticClass<class ADrumKeyboard_Key>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
