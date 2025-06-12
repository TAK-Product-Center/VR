// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Developer_TaskScheduler.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class IInterface_Developer_Task;
class UObject;
#ifdef VH_DEVELOPER_Developer_TaskScheduler_generated_h
#error "Developer_TaskScheduler.generated.h already included, missing '#pragma once' in Developer_TaskScheduler.h"
#endif
#define VH_DEVELOPER_Developer_TaskScheduler_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_26_DELEGATE \
static void FTaskAdded_DelegateWrapper(const FMulticastScriptDelegate& TaskAdded, const TScriptInterface<IInterface_Developer_Task>& task);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_28_DELEGATE \
static void FTaskStarted_DelegateWrapper(const FMulticastScriptDelegate& TaskStarted, const TScriptInterface<IInterface_Developer_Task>& task);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_30_DELEGATE \
static void FTaskFinished_DelegateWrapper(const FMulticastScriptDelegate& TaskFinished, const TScriptInterface<IInterface_Developer_Task>& task);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetNumActiveTasks); \
	DECLARE_FUNCTION(execGetNumTasks); \
	DECLARE_FUNCTION(execGetNumTasksOfType); \
	DECLARE_FUNCTION(execRemoveTask); \
	DECLARE_FUNCTION(execAddTask); \
	DECLARE_FUNCTION(execInsertTaskAt); \
	DECLARE_FUNCTION(execHasTask); \
	DECLARE_FUNCTION(execSetMaxConcurrentTasks); \
	DECLARE_FUNCTION(execGetMaxConcurrentTasks); \
	DECLARE_FUNCTION(execSetSecondsBetweenChecks); \
	DECLARE_FUNCTION(execGetSecondsBetweenChecks); \
	DECLARE_FUNCTION(execGetID); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execStart);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_TaskScheduler(); \
	friend struct Z_Construct_UClass_UDeveloper_TaskScheduler_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_TaskScheduler, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_TaskScheduler)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_TaskScheduler(UDeveloper_TaskScheduler&&); \
	NO_API UDeveloper_TaskScheduler(const UDeveloper_TaskScheduler&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_TaskScheduler); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_TaskScheduler); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_TaskScheduler) \
	NO_API virtual ~UDeveloper_TaskScheduler();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_16_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_TaskScheduler>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
