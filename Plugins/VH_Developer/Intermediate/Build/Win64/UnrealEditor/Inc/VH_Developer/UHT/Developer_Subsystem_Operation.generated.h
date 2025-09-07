// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/Developer_Subsystem_Operation.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDeveloper_Operation;
struct FInputActionInstance;
#ifdef VH_DEVELOPER_Developer_Subsystem_Operation_generated_h
#error "Developer_Subsystem_Operation.generated.h already included, missing '#pragma once' in Developer_Subsystem_Operation.h"
#endif
#define VH_DEVELOPER_Developer_Subsystem_Operation_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleInputAction); \
	DECLARE_FUNCTION(execGetOperationsByClass); \
	DECLARE_FUNCTION(execStopOperation); \
	DECLARE_FUNCTION(execStartOperation); \
	DECLARE_FUNCTION(execStartOperationByClass);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Subsystem_Operation(); \
	friend struct Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Subsystem_Operation, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Subsystem_Operation)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Subsystem_Operation(UDeveloper_Subsystem_Operation&&); \
	NO_API UDeveloper_Subsystem_Operation(const UDeveloper_Subsystem_Operation&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Subsystem_Operation); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Subsystem_Operation); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_Subsystem_Operation) \
	NO_API virtual ~UDeveloper_Subsystem_Operation();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_14_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Subsystem_Operation>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
