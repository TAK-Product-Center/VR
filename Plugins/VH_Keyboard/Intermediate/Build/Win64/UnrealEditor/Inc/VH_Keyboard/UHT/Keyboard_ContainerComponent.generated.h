// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/Public/Keyboard_ContainerComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FKeyData;
#ifdef VH_KEYBOARD_Keyboard_ContainerComponent_generated_h
#error "Keyboard_ContainerComponent.generated.h already included, missing '#pragma once' in Keyboard_ContainerComponent.h"
#endif
#define VH_KEYBOARD_Keyboard_ContainerComponent_generated_h

#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_29_DELEGATE \
static void FOnCommit_DelegateWrapper(const FMulticastScriptDelegate& OnCommit, const FString& entry);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_31_DELEGATE \
static void FOnKeyPressed_DelegateWrapper(const FMulticastScriptDelegate& OnKeyPressed, FKeyData const& keyData, const FString& keyString);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_33_DELEGATE \
static void FOnShiftModified_DelegateWrapper(const FMulticastScriptDelegate& OnShiftModified, bool bShiftActive);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_35_DELEGATE \
static FString FRequestCommitString_DelegateWrapper(const FScriptDelegate& RequestCommitString);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_SPARSE_DATA
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUKeyboard_ContainerComponent(); \
	friend struct Z_Construct_UClass_UKeyboard_ContainerComponent_Statics; \
public: \
	DECLARE_CLASS(UKeyboard_ContainerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Keyboard"), NO_API) \
	DECLARE_SERIALIZER(UKeyboard_ContainerComponent)


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UKeyboard_ContainerComponent(UKeyboard_ContainerComponent&&); \
	NO_API UKeyboard_ContainerComponent(const UKeyboard_ContainerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKeyboard_ContainerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKeyboard_ContainerComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UKeyboard_ContainerComponent) \
	NO_API virtual ~UKeyboard_ContainerComponent();


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_18_PROLOG
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_SPARSE_DATA \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_KEYBOARD_API UClass* StaticClass<class UKeyboard_ContainerComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
