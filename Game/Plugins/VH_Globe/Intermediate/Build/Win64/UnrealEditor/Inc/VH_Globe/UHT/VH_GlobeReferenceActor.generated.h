// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VH_GlobeReferenceActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UVH_GlobeCoordConverter;
struct FGeodeticCoord2D;
struct FGeodeticCoord3D;
#ifdef VH_GLOBE_VH_GlobeReferenceActor_generated_h
#error "VH_GlobeReferenceActor.generated.h already included, missing '#pragma once' in VH_GlobeReferenceActor.h"
#endif
#define VH_GLOBE_VH_GlobeReferenceActor_generated_h

#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_SPARSE_DATA
#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsValidMGRS); \
	DECLARE_FUNCTION(execMGRSToWorld); \
	DECLARE_FUNCTION(execWorldToMGRS); \
	DECLARE_FUNCTION(execGeodeticToWorldDouble); \
	DECLARE_FUNCTION(execGetGlobeCoordConverter); \
	DECLARE_FUNCTION(execGeodeticToECEF); \
	DECLARE_FUNCTION(execWorldToGeodeticDouble); \
	DECLARE_FUNCTION(execGetTerrainElevationDouble); \
	DECLARE_FUNCTION(execWorldRotationToPitch); \
	DECLARE_FUNCTION(execWorldRotationToBearing); \
	DECLARE_FUNCTION(execBearingToWorldRotation);


#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_ACCESSORS
#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVH_GlobeReferenceActor(); \
	friend struct Z_Construct_UClass_AVH_GlobeReferenceActor_Statics; \
public: \
	DECLARE_CLASS(AVH_GlobeReferenceActor, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Globe"), NO_API) \
	DECLARE_SERIALIZER(AVH_GlobeReferenceActor)


#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVH_GlobeReferenceActor(AVH_GlobeReferenceActor&&); \
	NO_API AVH_GlobeReferenceActor(const AVH_GlobeReferenceActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVH_GlobeReferenceActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVH_GlobeReferenceActor); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AVH_GlobeReferenceActor) \
	NO_API virtual ~AVH_GlobeReferenceActor();


#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_14_PROLOG
#define FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_SPARSE_DATA \
	FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_ACCESSORS \
	FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_GLOBE_API UClass* StaticClass<class AVH_GlobeReferenceActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Globe_Source_VH_Globe_Public_VH_GlobeReferenceActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
