// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_UI_ContextMenuOption.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UObject;
#ifdef VH_UI_Interface_UI_ContextMenuOption_generated_h
#error "Interface_UI_ContextMenuOption.generated.h already included, missing '#pragma once' in Interface_UI_ContextMenuOption.h"
#endif
#define VH_UI_Interface_UI_ContextMenuOption_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Execute_Implementation() {}; \
	virtual void SetInstigatorAndSource_Implementation(AActor* instigator, UObject* source) {}; \
 \
	DECLARE_FUNCTION(execExecute); \
	DECLARE_FUNCTION(execSetInstigatorAndSource);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_UI_ContextMenuOption(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_UI_ContextMenuOption(UInterface_UI_ContextMenuOption&&); \
	NO_API UInterface_UI_ContextMenuOption(const UInterface_UI_ContextMenuOption&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_UI_ContextMenuOption); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_UI_ContextMenuOption); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_UI_ContextMenuOption) \
	NO_API virtual ~UInterface_UI_ContextMenuOption();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_UI_ContextMenuOption(); \
	friend struct Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics; \
public: \
	DECLARE_CLASS(UInterface_UI_ContextMenuOption, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UInterface_UI_ContextMenuOption)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_UI_ContextMenuOption() {} \
public: \
	typedef UInterface_UI_ContextMenuOption UClassType; \
	typedef IInterface_UI_ContextMenuOption ThisClass; \
	static void Execute_Execute(UObject* O); \
	static void Execute_SetInstigatorAndSource(UObject* O, AActor* instigator, UObject* source); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_10_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UInterface_UI_ContextMenuOption>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
