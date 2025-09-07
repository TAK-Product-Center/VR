// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_Keyboard_Container.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
#ifdef VH_KEYBOARD_Interface_Keyboard_Container_generated_h
#error "Interface_Keyboard_Container.generated.h already included, missing '#pragma once' in Interface_Keyboard_Container.h"
#endif
#define VH_KEYBOARD_Interface_Keyboard_Container_generated_h

#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_SPARSE_DATA
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void InitializeForObject_Implementation(UObject* object) {}; \
	virtual void InitializeAtTransform_Implementation(FTransform const& transform) {}; \
 \
	DECLARE_FUNCTION(execInitializeForObject); \
	DECLARE_FUNCTION(execInitializeAtTransform);


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_ACCESSORS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_Keyboard_Container(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_Keyboard_Container(UInterface_Keyboard_Container&&); \
	NO_API UInterface_Keyboard_Container(const UInterface_Keyboard_Container&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_Keyboard_Container); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_Keyboard_Container); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_Keyboard_Container) \
	NO_API virtual ~UInterface_Keyboard_Container();


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_Keyboard_Container(); \
	friend struct Z_Construct_UClass_UInterface_Keyboard_Container_Statics; \
public: \
	DECLARE_CLASS(UInterface_Keyboard_Container, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_Keyboard"), NO_API) \
	DECLARE_SERIALIZER(UInterface_Keyboard_Container)


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_Keyboard_Container() {} \
public: \
	typedef UInterface_Keyboard_Container UClassType; \
	typedef IInterface_Keyboard_Container ThisClass; \
	static void Execute_InitializeAtTransform(UObject* O, FTransform const& transform); \
	static void Execute_InitializeForObject(UObject* O, UObject* object); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_9_PROLOG
#define FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_SPARSE_DATA \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_ACCESSORS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_KEYBOARD_API UClass* StaticClass<class UInterface_Keyboard_Container>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
