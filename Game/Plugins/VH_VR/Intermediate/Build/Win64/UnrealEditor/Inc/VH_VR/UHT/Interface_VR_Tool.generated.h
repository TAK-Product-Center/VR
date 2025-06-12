// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Interface_VR_Tool.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UVR_MotionControllerComponent;
struct FInputActionInstance;
#ifdef VH_VR_Interface_VR_Tool_generated_h
#error "Interface_VR_Tool.generated.h already included, missing '#pragma once' in Interface_VR_Tool.h"
#endif
#define VH_VR_Interface_VR_Tool_generated_h

#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_SPARSE_DATA
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool GetRelativeTransformForNonVRPositioning_Implementation(FTransform& transform) const { return false; }; \
	virtual void ActionInput_Implementation(FInputActionInstance const& inputActionInstance) {}; \
	virtual void InputToolStackIndexChanged_Implementation(UVR_MotionControllerComponent* motionControllerComponent, int32 index) {}; \
	virtual void RemovedFromInputToolStack_Implementation(UVR_MotionControllerComponent* motionControllerComponent) {}; \
	virtual void AddedToInputToolStack_Implementation(UVR_MotionControllerComponent* motionControllerComponent) {}; \
 \
	DECLARE_FUNCTION(execGetRelativeTransformForNonVRPositioning); \
	DECLARE_FUNCTION(execActionInput); \
	DECLARE_FUNCTION(execInputToolStackIndexChanged); \
	DECLARE_FUNCTION(execRemovedFromInputToolStack); \
	DECLARE_FUNCTION(execAddedToInputToolStack);


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInterface_VR_Tool(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInterface_VR_Tool(UInterface_VR_Tool&&); \
	NO_API UInterface_VR_Tool(const UInterface_VR_Tool&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInterface_VR_Tool); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInterface_VR_Tool); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInterface_VR_Tool) \
	NO_API virtual ~UInterface_VR_Tool();


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInterface_VR_Tool(); \
	friend struct Z_Construct_UClass_UInterface_VR_Tool_Statics; \
public: \
	DECLARE_CLASS(UInterface_VR_Tool, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_VR"), NO_API) \
	DECLARE_SERIALIZER(UInterface_VR_Tool)


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInterface_VR_Tool() {} \
public: \
	typedef UInterface_VR_Tool UClassType; \
	typedef IInterface_VR_Tool ThisClass; \
	static void Execute_ActionInput(UObject* O, FInputActionInstance const& inputActionInstance); \
	static void Execute_AddedToInputToolStack(UObject* O, UVR_MotionControllerComponent* motionControllerComponent); \
	static bool Execute_GetRelativeTransformForNonVRPositioning(const UObject* O, FTransform& transform); \
	static void Execute_InputToolStackIndexChanged(UObject* O, UVR_MotionControllerComponent* motionControllerComponent, int32 index); \
	static void Execute_RemovedFromInputToolStack(UObject* O, UVR_MotionControllerComponent* motionControllerComponent); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_12_PROLOG
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_SPARSE_DATA \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VR_API UClass* StaticClass<class UInterface_VR_Tool>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
