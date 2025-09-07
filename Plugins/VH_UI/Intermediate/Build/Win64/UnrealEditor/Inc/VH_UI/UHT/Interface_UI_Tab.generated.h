// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_UI_Tab.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FTabInfo;
#ifdef VH_UI_Interface_UI_Tab_generated_h
#error "Interface_UI_Tab.generated.h already included, missing '#pragma once' in Interface_UI_Tab.h"
#endif
#define VH_UI_Interface_UI_Tab_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTabInfo_Statics; \
	VH_UI_API static class UScriptStruct* StaticStruct();


template<> VH_UI_API UScriptStruct* StaticStruct<struct FTabInfo>();

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void GetTabInfo_Implementation(FTabInfo& tabInfo) const {}; \
 \
	DECLARE_FUNCTION(execGetTabInfo);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_UI_Tab(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_UI_Tab(UInterface_UI_Tab&&); \
	NO_API UInterface_UI_Tab(const UInterface_UI_Tab&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_UI_Tab); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_UI_Tab); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_UI_Tab) \
	NO_API virtual ~UInterface_UI_Tab();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_UI_Tab(); \
	friend struct Z_Construct_UClass_UInterface_UI_Tab_Statics; \
public: \
	DECLARE_CLASS(UInterface_UI_Tab, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UInterface_UI_Tab)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_UI_Tab() {} \
public: \
	typedef UInterface_UI_Tab UClassType; \
	typedef IInterface_UI_Tab ThisClass; \
	static void Execute_GetTabInfo(const UObject* O, FTabInfo& tabInfo); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_34_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_37_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UInterface_UI_Tab>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
