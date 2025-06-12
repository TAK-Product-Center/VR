// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/UI_Statics.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class UWidget;
#ifdef VH_UI_UI_Statics_generated_h
#error "UI_Statics.generated.h already included, missing '#pragma once' in UI_Statics.h"
#endif
#define VH_UI_UI_Statics_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_13_DELEGATE \
static void FOnDialogComplete_DelegateWrapper(const FScriptDelegate& OnDialogComplete, bool bSuccess, TArray<FString> const& files);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSelectFileBrowser); \
	DECLARE_FUNCTION(execSelectFolderBrowser); \
	DECLARE_FUNCTION(execSaveFileBrowser); \
	DECLARE_FUNCTION(execOpenFileBrowser); \
	DECLARE_FUNCTION(execOpenFileExplorer); \
	DECLARE_FUNCTION(execSaveNativeFileBrowserDialogAsync); \
	DECLARE_FUNCTION(execOpenNativeFileBrowserDialogAsync); \
	DECLARE_FUNCTION(execParseExtensionsIntoArray); \
	DECLARE_FUNCTION(execSyncKeyboardFocus);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUI_Statics(); \
	friend struct Z_Construct_UClass_UUI_Statics_Statics; \
public: \
	DECLARE_CLASS(UUI_Statics, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UUI_Statics)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUI_Statics(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_Statics(UUI_Statics&&); \
	NO_API UUI_Statics(const UUI_Statics&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_Statics); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_Statics); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_Statics) \
	NO_API virtual ~UUI_Statics();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_8_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UUI_Statics>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_UI_Statics_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
