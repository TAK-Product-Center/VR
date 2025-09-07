// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/Developer_Subsystem_BuildInfo.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EBuildInfo : uint8;
#ifdef VH_DEVELOPER_Developer_Subsystem_BuildInfo_generated_h
#error "Developer_Subsystem_BuildInfo.generated.h already included, missing '#pragma once' in Developer_Subsystem_BuildInfo.h"
#endif
#define VH_DEVELOPER_Developer_Subsystem_BuildInfo_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetInfo);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Subsystem_BuildInfo(); \
	friend struct Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Subsystem_BuildInfo, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Subsystem_BuildInfo)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Subsystem_BuildInfo(UDeveloper_Subsystem_BuildInfo&&); \
	NO_API UDeveloper_Subsystem_BuildInfo(const UDeveloper_Subsystem_BuildInfo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Subsystem_BuildInfo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Subsystem_BuildInfo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_Subsystem_BuildInfo) \
	NO_API virtual ~UDeveloper_Subsystem_BuildInfo();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_29_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Subsystem_BuildInfo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h


#define FOREACH_ENUM_EBUILDINFO(op) \
	op(EBuildInfo::ProjectName) \
	op(EBuildInfo::ProjectVersion) \
	op(EBuildInfo::BuildType) \
	op(EBuildInfo::BuildNumber) \
	op(EBuildInfo::BuildDateTime) \
	op(EBuildInfo::COUNT) 

enum class EBuildInfo : uint8;
template<> struct TIsUEnumClass<EBuildInfo> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<EBuildInfo>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
