// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/Developer_Subsystem_Core.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EHardwareInterfaceMode : uint8;
#ifdef VH_DEVELOPER_Developer_Subsystem_Core_generated_h
#error "Developer_Subsystem_Core.generated.h already included, missing '#pragma once' in Developer_Subsystem_Core.h"
#endif
#define VH_DEVELOPER_Developer_Subsystem_Core_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_46_DELEGATE \
static void FOnHardwareInterfaceModeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnHardwareInterfaceModeChanged, EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTest_SetHardwareInterfaceMode); \
	DECLARE_FUNCTION(execGetHardwareInterfaceMode); \
	DECLARE_FUNCTION(execSetHardwareInterfaceMode);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Subsystem_Core(); \
	friend struct Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Subsystem_Core, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Subsystem_Core)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Subsystem_Core(UDeveloper_Subsystem_Core&&); \
	NO_API UDeveloper_Subsystem_Core(const UDeveloper_Subsystem_Core&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Subsystem_Core); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Subsystem_Core); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_Subsystem_Core) \
	NO_API virtual ~UDeveloper_Subsystem_Core();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_35_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Subsystem_Core>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h


#define FOREACH_ENUM_EHARDWAREINTERFACEMODE(op) \
	op(EHardwareInterfaceMode::Unknown) \
	op(EHardwareInterfaceMode::Desktop) \
	op(EHardwareInterfaceMode::VR) \
	op(EHardwareInterfaceMode::VREmulation) 

enum class EHardwareInterfaceMode : uint8;
template<> struct TIsUEnumClass<EHardwareInterfaceMode> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<EHardwareInterfaceMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
