// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Developer_TaskInfo.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDeveloper_TaskInfo;
#ifdef VH_DEVELOPER_Developer_TaskInfo_generated_h
#error "Developer_TaskInfo.generated.h already included, missing '#pragma once' in Developer_TaskInfo.h"
#endif
#define VH_DEVELOPER_Developer_TaskInfo_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_23_DELEGATE \
static void FTaskInfoChanged_DelegateWrapper(const FMulticastScriptDelegate& TaskInfoChanged, UDeveloper_TaskInfo* taskInfo);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_25_DELEGATE \
static void FTaskInfoIDChanged_DelegateWrapper(const FMulticastScriptDelegate& TaskInfoIDChanged, UDeveloper_TaskInfo* taskInfo, const FString& oldID);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetPercentComplete); \
	DECLARE_FUNCTION(execGetDescription); \
	DECLARE_FUNCTION(execGetID); \
	DECLARE_FUNCTION(execSetPercentComplete); \
	DECLARE_FUNCTION(execSetDescription); \
	DECLARE_FUNCTION(execSetID);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_TaskInfo(); \
	friend struct Z_Construct_UClass_UDeveloper_TaskInfo_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_TaskInfo, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_TaskInfo)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_TaskInfo(UDeveloper_TaskInfo&&); \
	NO_API UDeveloper_TaskInfo(const UDeveloper_TaskInfo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_TaskInfo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_TaskInfo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_TaskInfo) \
	NO_API virtual ~UDeveloper_TaskInfo();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_12_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_TaskInfo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
