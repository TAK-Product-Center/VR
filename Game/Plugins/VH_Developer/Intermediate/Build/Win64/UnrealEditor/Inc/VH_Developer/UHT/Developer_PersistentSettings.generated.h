// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Developer_PersistentSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_DEVELOPER_Developer_PersistentSettings_generated_h
#error "Developer_PersistentSettings.generated.h already included, missing '#pragma once' in Developer_PersistentSettings.h"
#endif
#define VH_DEVELOPER_Developer_PersistentSettings_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_20_DELEGATE \
static void FStringSettingStored_DelegateWrapper(const FMulticastScriptDelegate& StringSettingStored, const FString& settingName, const FString& value);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_22_DELEGATE \
static void FBoolSettingStored_DelegateWrapper(const FMulticastScriptDelegate& BoolSettingStored, const FString& settingName, bool bValue);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_24_DELEGATE \
static void FIntSettingStored_DelegateWrapper(const FMulticastScriptDelegate& IntSettingStored, const FString& settingName, int32 value);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_26_DELEGATE \
static void FDoubleSettingStored_DelegateWrapper(const FMulticastScriptDelegate& DoubleSettingStored, const FString& settingName, double value);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAllSettings); \
	DECLARE_FUNCTION(execRemoveSetting); \
	DECLARE_FUNCTION(execStoreDefaultSettingDouble); \
	DECLARE_FUNCTION(execStoreDefaultSettingInt); \
	DECLARE_FUNCTION(execStoreDefaultSettingBool); \
	DECLARE_FUNCTION(execStoreDefaultSettingString); \
	DECLARE_FUNCTION(execGetDefaultSettingDouble); \
	DECLARE_FUNCTION(execGetDefaultSettingInt); \
	DECLARE_FUNCTION(execGetDefaultSettingBool); \
	DECLARE_FUNCTION(execGetDefaultSettingString); \
	DECLARE_FUNCTION(execStoreSettingDouble); \
	DECLARE_FUNCTION(execStoreSettingInt); \
	DECLARE_FUNCTION(execStoreSettingBool); \
	DECLARE_FUNCTION(execStoreSettingString); \
	DECLARE_FUNCTION(execGetSettingDouble); \
	DECLARE_FUNCTION(execGetSettingInt); \
	DECLARE_FUNCTION(execGetSettingBool); \
	DECLARE_FUNCTION(execGetSettingString); \
	DECLARE_FUNCTION(execHasDefaultSetting); \
	DECLARE_FUNCTION(execHasSetting);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_PersistentSettings(); \
	friend struct Z_Construct_UClass_UDeveloper_PersistentSettings_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_PersistentSettings, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_PersistentSettings)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_PersistentSettings(UDeveloper_PersistentSettings&&); \
	NO_API UDeveloper_PersistentSettings(const UDeveloper_PersistentSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_PersistentSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_PersistentSettings); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDeveloper_PersistentSettings) \
	NO_API virtual ~UDeveloper_PersistentSettings();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_9_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_PersistentSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_PersistentSettings_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
