// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Developer_Operation.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionInstance;
#ifdef VH_DEVELOPER_Developer_Operation_generated_h
#error "Developer_Operation.generated.h already included, missing '#pragma once' in Developer_Operation.h"
#endif
#define VH_DEVELOPER_Developer_Operation_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ActionInput_Implementation(FInputActionInstance const& inputActionInstance); \
 \
	DECLARE_FUNCTION(execActionInput);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Operation(); \
	friend struct Z_Construct_UClass_UDeveloper_Operation_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Operation, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Operation)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Operation(UDeveloper_Operation&&); \
	NO_API UDeveloper_Operation(const UDeveloper_Operation&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Operation); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Operation); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDeveloper_Operation) \
	NO_API virtual ~UDeveloper_Operation();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_16_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Operation>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
