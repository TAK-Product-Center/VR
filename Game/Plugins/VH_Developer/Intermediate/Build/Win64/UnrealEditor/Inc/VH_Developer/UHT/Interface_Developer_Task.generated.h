// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_Developer_Task.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ETaskStatus : uint8;
#ifdef VH_DEVELOPER_Interface_Developer_Task_generated_h
#error "Interface_Developer_Task.generated.h already included, missing '#pragma once' in Interface_Developer_Task.h"
#endif
#define VH_DEVELOPER_Interface_Developer_Task_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void StartTask_Implementation() {}; \
	virtual bool InitializeTask_Implementation() { return false; }; \
	virtual ETaskStatus GetTaskStatus_Implementation() const { return (ETaskStatus)0; }; \
 \
	DECLARE_FUNCTION(execStartTask); \
	DECLARE_FUNCTION(execInitializeTask); \
	DECLARE_FUNCTION(execGetTaskStatus);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_Developer_Task(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_Developer_Task(UInterface_Developer_Task&&); \
	NO_API UInterface_Developer_Task(const UInterface_Developer_Task&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_Developer_Task); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_Developer_Task); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_Developer_Task) \
	NO_API virtual ~UInterface_Developer_Task();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_Developer_Task(); \
	friend struct Z_Construct_UClass_UInterface_Developer_Task_Statics; \
public: \
	DECLARE_CLASS(UInterface_Developer_Task, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UInterface_Developer_Task)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_Developer_Task() {} \
public: \
	typedef UInterface_Developer_Task UClassType; \
	typedef IInterface_Developer_Task ThisClass; \
	static ETaskStatus Execute_GetTaskStatus(const UObject* O); \
	static bool Execute_InitializeTask(UObject* O); \
	static void Execute_StartTask(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_23_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_26_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UInterface_Developer_Task>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h


#define FOREACH_ENUM_ETASKSTATUS(op) \
	op(ETaskStatus::Invalid) \
	op(ETaskStatus::Initialized) \
	op(ETaskStatus::Started) \
	op(ETaskStatus::Finished) 

enum class ETaskStatus : uint8;
template<> struct TIsUEnumClass<ETaskStatus> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<ETaskStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
