// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/Public/VR_TraceComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;
#ifdef VH_VR_VR_TraceComponent_generated_h
#error "VR_TraceComponent.generated.h already included, missing '#pragma once' in VR_TraceComponent.h"
#endif
#define VH_VR_VR_TraceComponent_generated_h

#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_SPARSE_DATA
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateTrace); \
	DECLARE_FUNCTION(execGetHitResults); \
	DECLARE_FUNCTION(execRemoveTraceChannel); \
	DECLARE_FUNCTION(execAddTraceChannel);


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_ACCESSORS
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVR_TraceComponent(); \
	friend struct Z_Construct_UClass_UVR_TraceComponent_Statics; \
public: \
	DECLARE_CLASS(UVR_TraceComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_VR"), NO_API) \
	DECLARE_SERIALIZER(UVR_TraceComponent)


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVR_TraceComponent(UVR_TraceComponent&&); \
	NO_API UVR_TraceComponent(const UVR_TraceComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVR_TraceComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVR_TraceComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVR_TraceComponent) \
	NO_API virtual ~UVR_TraceComponent();


#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_12_PROLOG
#define FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_SPARSE_DATA \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_ACCESSORS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VR_API UClass* StaticClass<class UVR_TraceComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
