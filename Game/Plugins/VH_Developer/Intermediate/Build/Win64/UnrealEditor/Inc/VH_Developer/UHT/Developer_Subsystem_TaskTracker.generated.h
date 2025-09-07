// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/Developer_Subsystem_TaskTracker.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
 class UDeveloper_TaskInfo;
class UDeveloper_TaskInfo;
#ifdef VH_DEVELOPER_Developer_Subsystem_TaskTracker_generated_h
#error "Developer_Subsystem_TaskTracker.generated.h already included, missing '#pragma once' in Developer_Subsystem_TaskTracker.h"
#endif
#define VH_DEVELOPER_Developer_Subsystem_TaskTracker_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_27_DELEGATE \
static void FActiveNumChanged_DelegateWrapper(const FMulticastScriptDelegate& ActiveNumChanged);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_29_DELEGATE \
static void FHistoryNumChanged_DelegateWrapper(const FMulticastScriptDelegate& HistoryNumChanged);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_31_DELEGATE \
static void FTaskInfoChanged_DelegateWrapper(const FMulticastScriptDelegate& TaskInfoChanged, UDeveloper_TaskInfo* taskInfo);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleTaskInfoChanged); \
	DECLARE_FUNCTION(execRemoveHistoryTask); \
	DECLARE_FUNCTION(execAddHistoryTask); \
	DECLARE_FUNCTION(execSetDescription); \
	DECLARE_FUNCTION(execSetPercentComplete); \
	DECLARE_FUNCTION(execRemoveActiveTask); \
	DECLARE_FUNCTION(execAddActiveTask); \
	DECLARE_FUNCTION(execGetActiveIDs); \
	DECLARE_FUNCTION(execGetHistoryIDs); \
	DECLARE_FUNCTION(execGetHistoryTasks); \
	DECLARE_FUNCTION(execGetActiveTasks);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Subsystem_TaskTracker(); \
	friend struct Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Subsystem_TaskTracker, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Subsystem_TaskTracker)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Subsystem_TaskTracker(UDeveloper_Subsystem_TaskTracker&&); \
	NO_API UDeveloper_Subsystem_TaskTracker(const UDeveloper_Subsystem_TaskTracker&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Subsystem_TaskTracker); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Subsystem_TaskTracker); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_Subsystem_TaskTracker) \
	NO_API virtual ~UDeveloper_Subsystem_TaskTracker();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_16_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Subsystem_TaskTracker>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
