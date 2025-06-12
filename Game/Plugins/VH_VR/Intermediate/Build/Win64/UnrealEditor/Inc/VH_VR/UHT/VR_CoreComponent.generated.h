// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/Public/VR_CoreComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_VR_VR_CoreComponent_generated_h
#error "VR_CoreComponent.generated.h already included, missing '#pragma once' in VR_CoreComponent.h"
#endif
#define VH_VR_VR_CoreComponent_generated_h

#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_SPARSE_DATA
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Server_SetRelativeTransform_Implementation(FTransform const& transform); \
 \
	DECLARE_FUNCTION(execServer_SetRelativeTransform);


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVR_CoreComponent(); \
	friend struct Z_Construct_UClass_UVR_CoreComponent_Statics; \
public: \
	DECLARE_CLASS(UVR_CoreComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_VR"), NO_API) \
	DECLARE_SERIALIZER(UVR_CoreComponent)


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVR_CoreComponent(UVR_CoreComponent&&); \
	NO_API UVR_CoreComponent(const UVR_CoreComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVR_CoreComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVR_CoreComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVR_CoreComponent) \
	NO_API virtual ~UVR_CoreComponent();


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_9_PROLOG
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_SPARSE_DATA \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VR_API UClass* StaticClass<class UVR_CoreComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
