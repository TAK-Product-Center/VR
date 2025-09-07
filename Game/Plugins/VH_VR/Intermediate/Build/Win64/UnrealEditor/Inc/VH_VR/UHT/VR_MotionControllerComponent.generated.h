// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/Public/VR_MotionControllerComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
enum class EHardwareInterfaceMode : uint8;
struct FInputActionInstance;
#ifdef VH_VR_VR_MotionControllerComponent_generated_h
#error "VR_MotionControllerComponent.generated.h already included, missing '#pragma once' in VR_MotionControllerComponent.h"
#endif
#define VH_VR_VR_MotionControllerComponent_generated_h

#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_29_DELEGATE \
static void FInputStackTopChanged_DelegateWrapper(const FMulticastScriptDelegate& InputStackTopChanged, AActor* tool);


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_SPARSE_DATA
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Server_SetToolsVisibility_Implementation(bool bVisibleArg); \
	virtual void Server_RemoveAllTools_Implementation(); \
	virtual void Server_RemoveTool_Implementation(AActor* tool); \
	virtual void Server_AddToolByClass_Implementation(TSubclassOf<AActor>  toolClass); \
	virtual void Server_AddTool_Implementation(AActor* tool); \
	virtual void Server_SetRelativeTransform_Implementation(FTransform const& transform); \
 \
	DECLARE_FUNCTION(execHandleInputAction); \
	DECLARE_FUNCTION(execHandleHardwareInterfaceModeChanged); \
	DECLARE_FUNCTION(execHasTool); \
	DECLARE_FUNCTION(execGetInputToolStackTop); \
	DECLARE_FUNCTION(execRemoveAllTools); \
	DECLARE_FUNCTION(execRemoveTool); \
	DECLARE_FUNCTION(execAddToolByClass); \
	DECLARE_FUNCTION(execAddTool); \
	DECLARE_FUNCTION(execOnRep_InputToolStackTop); \
	DECLARE_FUNCTION(execOnRep_RelativeTransform); \
	DECLARE_FUNCTION(execServer_SetToolsVisibility); \
	DECLARE_FUNCTION(execServer_RemoveAllTools); \
	DECLARE_FUNCTION(execServer_RemoveTool); \
	DECLARE_FUNCTION(execServer_AddToolByClass); \
	DECLARE_FUNCTION(execServer_AddTool); \
	DECLARE_FUNCTION(execServer_SetRelativeTransform);


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVR_MotionControllerComponent(); \
	friend struct Z_Construct_UClass_UVR_MotionControllerComponent_Statics; \
public: \
	DECLARE_CLASS(UVR_MotionControllerComponent, UMotionControllerComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_VR"), NO_API) \
	DECLARE_SERIALIZER(UVR_MotionControllerComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		RelativeTransform=NETFIELD_REP_START, \
		InputToolStackTop, \
		NETFIELD_REP_END=InputToolStackTop	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVR_MotionControllerComponent(UVR_MotionControllerComponent&&); \
	NO_API UVR_MotionControllerComponent(const UVR_MotionControllerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVR_MotionControllerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVR_MotionControllerComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVR_MotionControllerComponent) \
	NO_API virtual ~UVR_MotionControllerComponent();


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_18_PROLOG
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_SPARSE_DATA \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VR_API UClass* StaticClass<class UVR_MotionControllerComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
