// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_UI_ContextMenu.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UObject;
#ifdef VH_UI_Interface_UI_ContextMenu_generated_h
#error "Interface_UI_ContextMenu.generated.h already included, missing '#pragma once' in Interface_UI_ContextMenu.h"
#endif
#define VH_UI_Interface_UI_ContextMenu_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void SetContextMenuInformation_Implementation(AActor* instigator, UObject* source, TSet<UObject*> const& contextOptions) {}; \
 \
	DECLARE_FUNCTION(execSetContextMenuInformation);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_UI_ContextMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_UI_ContextMenu(UInterface_UI_ContextMenu&&); \
	NO_API UInterface_UI_ContextMenu(const UInterface_UI_ContextMenu&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_UI_ContextMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_UI_ContextMenu); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_UI_ContextMenu) \
	NO_API virtual ~UInterface_UI_ContextMenu();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_UI_ContextMenu(); \
	friend struct Z_Construct_UClass_UInterface_UI_ContextMenu_Statics; \
public: \
	DECLARE_CLASS(UInterface_UI_ContextMenu, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UInterface_UI_ContextMenu)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_UI_ContextMenu() {} \
public: \
	typedef UInterface_UI_ContextMenu UClassType; \
	typedef IInterface_UI_ContextMenu ThisClass; \
	static void Execute_SetContextMenuInformation(UObject* O, AActor* instigator, UObject* source, TSet<UObject*> const& contextOptions); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_9_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UInterface_UI_ContextMenu>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
