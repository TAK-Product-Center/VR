// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VH_PluginSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 struct FPluginInfo;
class UObject;
#ifdef VH_PLUGINS_VH_PluginSubsystem_generated_h
#error "VH_PluginSubsystem.generated.h already included, missing '#pragma once' in VH_PluginSubsystem.h"
#endif
#define VH_PLUGINS_VH_PluginSubsystem_generated_h

#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_31_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPluginInfo_Statics; \
	VH_PLUGINS_API static class UScriptStruct* StaticStruct();


template<> VH_PLUGINS_API UScriptStruct* StaticStruct<struct FPluginInfo>();

#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_SPARSE_DATA
#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleGenerateCrashLog); \
	DECLARE_FUNCTION(execImportPlugin); \
	DECLARE_FUNCTION(execUpdateAllPlugins); \
	DECLARE_FUNCTION(execUpdatePlugin); \
	DECLARE_FUNCTION(execSetPluginAuthor); \
	DECLARE_FUNCTION(execSetPluginVersion); \
	DECLARE_FUNCTION(execSetPluginDescription); \
	DECLARE_FUNCTION(execSetPluginFriendlyName); \
	DECLARE_FUNCTION(execSetPluginDeletion); \
	DECLARE_FUNCTION(execSetPluginEnabled); \
	DECLARE_FUNCTION(execSetPluginLoaded); \
	DECLARE_FUNCTION(execGetMapsInPlugin); \
	DECLARE_FUNCTION(execGetClassesInPlugin); \
	DECLARE_FUNCTION(execGetRegisteredPlugins); \
	DECLARE_FUNCTION(execUnregisterPlugin); \
	DECLARE_FUNCTION(execRegisterPlugin);


#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_ACCESSORS
#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_PluginSubsystem(); \
	friend struct Z_Construct_UClass_UVH_PluginSubsystem_Statics; \
public: \
	DECLARE_CLASS(UVH_PluginSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Plugins"), NO_API) \
	DECLARE_SERIALIZER(UVH_PluginSubsystem)


#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_PluginSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_PluginSubsystem(UVH_PluginSubsystem&&); \
	NO_API UVH_PluginSubsystem(const UVH_PluginSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_PluginSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_PluginSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVH_PluginSubsystem) \
	NO_API virtual ~UVH_PluginSubsystem();


#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_103_PROLOG
#define FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_SPARSE_DATA \
	FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_ACCESSORS \
	FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h_106_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_PLUGINS_API UClass* StaticClass<class UVH_PluginSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Plugins_Source_VH_Plugins_Public_VH_PluginSubsystem_h


#define FOREACH_ENUM_EPLUGINLOADERROR(op) \
	op(EPluginLoadError::NoError) \
	op(EPluginLoadError::VersionMismatch) \
	op(EPluginLoadError::UnknownError) 

enum class EPluginLoadError : uint8;
template<> struct TIsUEnumClass<EPluginLoadError> { enum { Value = true }; };
template<> VH_PLUGINS_API UEnum* StaticEnum<EPluginLoadError>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
