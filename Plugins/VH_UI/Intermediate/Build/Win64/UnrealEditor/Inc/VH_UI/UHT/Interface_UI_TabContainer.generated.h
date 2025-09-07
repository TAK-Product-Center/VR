// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_UI_TabContainer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UUserWidget;
#ifdef VH_UI_Interface_UI_TabContainer_generated_h
#error "Interface_UI_TabContainer.generated.h already included, missing '#pragma once' in Interface_UI_TabContainer.h"
#endif
#define VH_UI_Interface_UI_TabContainer_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual int32 GetNumberOfTabs_Implementation() const { return 0; }; \
	virtual void SetFocusedTab_Implementation(UUserWidget* tab) {}; \
	virtual void RemoveAllTabs_Implementation() {}; \
	virtual void RemoveTab_Implementation(UUserWidget* tab) {}; \
	virtual void AddTab_Implementation(UUserWidget* tab) {}; \
 \
	DECLARE_FUNCTION(execGetNumberOfTabs); \
	DECLARE_FUNCTION(execSetFocusedTab); \
	DECLARE_FUNCTION(execRemoveAllTabs); \
	DECLARE_FUNCTION(execRemoveTab); \
	DECLARE_FUNCTION(execAddTab);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_UI_TabContainer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_UI_TabContainer(UInterface_UI_TabContainer&&); \
	NO_API UInterface_UI_TabContainer(const UInterface_UI_TabContainer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_UI_TabContainer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_UI_TabContainer); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_UI_TabContainer) \
	NO_API virtual ~UInterface_UI_TabContainer();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_UI_TabContainer(); \
	friend struct Z_Construct_UClass_UInterface_UI_TabContainer_Statics; \
public: \
	DECLARE_CLASS(UInterface_UI_TabContainer, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UInterface_UI_TabContainer)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_UI_TabContainer() {} \
public: \
	typedef UInterface_UI_TabContainer UClassType; \
	typedef IInterface_UI_TabContainer ThisClass; \
	static void Execute_AddTab(UObject* O, UUserWidget* tab); \
	static int32 Execute_GetNumberOfTabs(const UObject* O); \
	static void Execute_RemoveAllTabs(UObject* O); \
	static void Execute_RemoveTab(UObject* O, UUserWidget* tab); \
	static void Execute_SetFocusedTab(UObject* O, UUserWidget* tab); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_7_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UInterface_UI_TabContainer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
