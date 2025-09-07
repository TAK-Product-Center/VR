// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/UI_Subsystem_Core.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UUI_Subsystem_Core_Settings;
class UUserWidget;
enum class EHardwareInterfaceMode : uint8;
enum class EUIType : uint8;
struct FOpenUserWidgetViewportSettings;
struct FOpenUserWidgetWindowSettings;
struct FOpenUserWidgetWorldSettings;
struct FTabContainerSettings;
#ifdef VH_UI_UI_Subsystem_Core_generated_h
#error "UI_Subsystem_Core.generated.h already included, missing '#pragma once' in UI_Subsystem_Core.h"
#endif
#define VH_UI_UI_Subsystem_Core_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_75_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOpenBehavior_Statics; \
	VH_UI_API static class UScriptStruct* StaticStruct();


template<> VH_UI_API UScriptStruct* StaticStruct<struct FOpenBehavior>();

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_93_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOpenUserWidgetViewportSettings_Statics; \
	VH_UI_API static class UScriptStruct* StaticStruct();


template<> VH_UI_API UScriptStruct* StaticStruct<struct FOpenUserWidgetViewportSettings>();

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_121_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOpenUserWidgetWorldSettings_Statics; \
	VH_UI_API static class UScriptStruct* StaticStruct();


template<> VH_UI_API UScriptStruct* StaticStruct<struct FOpenUserWidgetWorldSettings>();

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_152_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOpenUserWidgetWindowSettings_Statics; \
	VH_UI_API static class UScriptStruct* StaticStruct();


template<> VH_UI_API UScriptStruct* StaticStruct<struct FOpenUserWidgetWindowSettings>();

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_296_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTabContainerSettings_Statics; \
	VH_UI_API static class UScriptStruct* StaticStruct();


template<> VH_UI_API UScriptStruct* StaticStruct<struct FTabContainerSettings>();

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_330_DELEGATE \
static void FOnUserWidgetClosed_DelegateWrapper(const FMulticastScriptDelegate& OnUserWidgetClosed, UUserWidget* userWidget);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_332_DELEGATE \
static void FOnUserWidgetOpened_DelegateWrapper(const FMulticastScriptDelegate& OnUserWidgetOpened, UUserWidget* userWidget);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleHardwareInterfaceModeChanged); \
	DECLARE_FUNCTION(execMoveWindowToMonitor); \
	DECLARE_FUNCTION(execGetWindowMonitorIndex); \
	DECLARE_FUNCTION(execGetViewportSize); \
	DECLARE_FUNCTION(execGetViewportPosition); \
	DECLARE_FUNCTION(execGetViewportMonitorIndex); \
	DECLARE_FUNCTION(execSetUserWidgetClassWorldSettings); \
	DECLARE_FUNCTION(execGetUserWidgetClassWorldSettings); \
	DECLARE_FUNCTION(execSetUserWidgetDefaultWorldUIActor); \
	DECLARE_FUNCTION(execGetUserWidgetWorldUIActor); \
	DECLARE_FUNCTION(execGetUserWidgetsByClass); \
	DECLARE_FUNCTION(execSetUserWidgetTabContainer); \
	DECLARE_FUNCTION(execMoveWidgetToNewTabContainer); \
	DECLARE_FUNCTION(execRemoveUserWidgetFromTabContainer); \
	DECLARE_FUNCTION(execGetTabsInTabContainer); \
	DECLARE_FUNCTION(execGetUserWidgetTabContainer); \
	DECLARE_FUNCTION(execGetUserWidgetScale); \
	DECLARE_FUNCTION(execSetUserWidgetScale); \
	DECLARE_FUNCTION(execMoveUserWidgetToWorldLocation); \
	DECLARE_FUNCTION(execGetUserWidgetPosition); \
	DECLARE_FUNCTION(execSetUserWidgetPosition); \
	DECLARE_FUNCTION(execGetUserWidgetSize); \
	DECLARE_FUNCTION(execSetUserWidgetSize); \
	DECLARE_FUNCTION(execCloseAllWidgetsByClass); \
	DECLARE_FUNCTION(execCloseUserWidget); \
	DECLARE_FUNCTION(execCloseTabContainer); \
	DECLARE_FUNCTION(execGetUserWidgetUIType); \
	DECLARE_FUNCTION(execOpenInPopoutWindow); \
	DECLARE_FUNCTION(execOpenInPopoutWindowByClass); \
	DECLARE_FUNCTION(execOpenInWorld); \
	DECLARE_FUNCTION(execOpenInWorldByClass); \
	DECLARE_FUNCTION(execOpenInViewport); \
	DECLARE_FUNCTION(execOpenInViewportByClass); \
	DECLARE_FUNCTION(execOpenWithDefaults); \
	DECLARE_FUNCTION(execOpenWithDefaultsByClass); \
	DECLARE_FUNCTION(execUpdateSettings);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUI_Subsystem_Core(); \
	friend struct Z_Construct_UClass_UUI_Subsystem_Core_Statics; \
public: \
	DECLARE_CLASS(UUI_Subsystem_Core, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UUI_Subsystem_Core)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_Subsystem_Core(UUI_Subsystem_Core&&); \
	NO_API UUI_Subsystem_Core(const UUI_Subsystem_Core&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_Subsystem_Core); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_Subsystem_Core); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UUI_Subsystem_Core) \
	NO_API virtual ~UUI_Subsystem_Core();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_319_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h_322_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UUI_Subsystem_Core>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_Core_h


#define FOREACH_ENUM_EUITYPE(op) \
	op(EUIType::Viewport) \
	op(EUIType::World) \
	op(EUIType::PopoutWindow) 

enum class EUIType : uint8;
template<> struct TIsUEnumClass<EUIType> { enum { Value = true }; };
template<> VH_UI_API UEnum* StaticEnum<EUIType>();

#define FOREACH_ENUM_ETABCONTAINERTYPE(op) \
	op(ETabContainerType::None) \
	op(ETabContainerType::Existing) \
	op(ETabContainerType::New) 

enum class ETabContainerType : uint8;
template<> struct TIsUEnumClass<ETabContainerType> { enum { Value = true }; };
template<> VH_UI_API UEnum* StaticEnum<ETabContainerType>();

#define FOREACH_ENUM_EBLUEPRINTWINDOWSIZINGRULE(op) \
	op(EBlueprintWindowSizingRule::FixedSize) \
	op(EBlueprintWindowSizingRule::Autosized) \
	op(EBlueprintWindowSizingRule::UserSized) 

enum class EBlueprintWindowSizingRule : uint8;
template<> struct TIsUEnumClass<EBlueprintWindowSizingRule> { enum { Value = true }; };
template<> VH_UI_API UEnum* StaticEnum<EBlueprintWindowSizingRule>();

#define FOREACH_ENUM_EBLUEPRINTWINDOWACTIVATIONPOLICY(op) \
	op(EBlueprintWindowActivationPolicy::Never) \
	op(EBlueprintWindowActivationPolicy::Always) \
	op(EBlueprintWindowActivationPolicy::FirstShown) 

enum class EBlueprintWindowActivationPolicy : uint8;
template<> struct TIsUEnumClass<EBlueprintWindowActivationPolicy> { enum { Value = true }; };
template<> VH_UI_API UEnum* StaticEnum<EBlueprintWindowActivationPolicy>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
