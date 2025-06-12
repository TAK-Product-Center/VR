// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_Developer_Manipulation.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EAxisListBlueprint : uint8;
#ifdef VH_DEVELOPER_Interface_Developer_Manipulation_generated_h
#error "Interface_Developer_Manipulation.generated.h already included, missing '#pragma once' in Interface_Developer_Manipulation.h"
#endif
#define VH_DEVELOPER_Interface_Developer_Manipulation_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ManipulationEnd_Implementation() {}; \
	virtual void ManipulationInProgress_Implementation() {}; \
	virtual void ManipulationBegin_Implementation() {}; \
	virtual bool GetWorldTransform_Implementation(FTransform& localToWorld) { return false; }; \
	virtual bool GetScaleAxisList_Implementation(EAxisListBlueprint& axisList) { return false; }; \
	virtual bool GetRotationDisabled_Implementation() { return false; }; \
	virtual bool GetRotationAxisList_Implementation(EAxisListBlueprint& axisList) { return false; }; \
	virtual bool GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList) { return false; }; \
 \
	DECLARE_FUNCTION(execManipulationEnd); \
	DECLARE_FUNCTION(execManipulationInProgress); \
	DECLARE_FUNCTION(execManipulationBegin); \
	DECLARE_FUNCTION(execGetWorldTransform); \
	DECLARE_FUNCTION(execGetScaleAxisList); \
	DECLARE_FUNCTION(execGetRotationDisabled); \
	DECLARE_FUNCTION(execGetRotationAxisList); \
	DECLARE_FUNCTION(execGetTranslationAxisList);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_Developer_Manipulation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_Developer_Manipulation(UInterface_Developer_Manipulation&&); \
	NO_API UInterface_Developer_Manipulation(const UInterface_Developer_Manipulation&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_Developer_Manipulation); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_Developer_Manipulation); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_Developer_Manipulation) \
	NO_API virtual ~UInterface_Developer_Manipulation();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_Developer_Manipulation(); \
	friend struct Z_Construct_UClass_UInterface_Developer_Manipulation_Statics; \
public: \
	DECLARE_CLASS(UInterface_Developer_Manipulation, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UInterface_Developer_Manipulation)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_Developer_Manipulation() {} \
public: \
	typedef UInterface_Developer_Manipulation UClassType; \
	typedef IInterface_Developer_Manipulation ThisClass; \
	static bool Execute_GetRotationAxisList(UObject* O, EAxisListBlueprint& axisList); \
	static bool Execute_GetRotationDisabled(UObject* O); \
	static bool Execute_GetScaleAxisList(UObject* O, EAxisListBlueprint& axisList); \
	static bool Execute_GetTranslationAxisList(UObject* O, EAxisListBlueprint& axisList); \
	static bool Execute_GetWorldTransform(UObject* O, FTransform& localToWorld); \
	static void Execute_ManipulationBegin(UObject* O); \
	static void Execute_ManipulationEnd(UObject* O); \
	static void Execute_ManipulationInProgress(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_23_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_26_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UInterface_Developer_Manipulation>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h


#define FOREACH_ENUM_EAXISLISTBLUEPRINT(op) \
	op(EAxisListBlueprint::None) \
	op(EAxisListBlueprint::X) \
	op(EAxisListBlueprint::Y) \
	op(EAxisListBlueprint::Z) \
	op(EAxisListBlueprint::XY) \
	op(EAxisListBlueprint::XZ) \
	op(EAxisListBlueprint::YZ) \
	op(EAxisListBlueprint::XYZ) 

enum class EAxisListBlueprint : uint8;
template<> struct TIsUEnumClass<EAxisListBlueprint> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<EAxisListBlueprint>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
