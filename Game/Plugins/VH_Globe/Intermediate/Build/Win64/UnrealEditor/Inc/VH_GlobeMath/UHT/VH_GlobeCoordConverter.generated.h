// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VH_GlobeCoordConverter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGeodeticCoord2D;
struct FGeodeticCoord3D;
struct FGlobeTangentCoord;
struct FMgrsCoord;
struct FUpsCoord;
struct FUtmCoord;
#ifdef VH_GLOBEMATH_VH_GlobeCoordConverter_generated_h
#error "VH_GlobeCoordConverter.generated.h already included, missing '#pragma once' in VH_GlobeCoordConverter.h"
#endif
#define VH_GLOBEMATH_VH_GlobeCoordConverter_generated_h

#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSGlobeDefinition_Statics; \
	VH_GLOBEMATH_API static class UScriptStruct* StaticStruct();


template<> VH_GLOBEMATH_API UScriptStruct* StaticStruct<struct FSGlobeDefinition>();

#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_SPARSE_DATA
#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMGRSToGeodetic); \
	DECLARE_FUNCTION(execGeodeticToMGRS); \
	DECLARE_FUNCTION(execGeodeticToECEF); \
	DECLARE_FUNCTION(execENUToGeodetic); \
	DECLARE_FUNCTION(execGeodeticToENU); \
	DECLARE_FUNCTION(execUPSToMGRS); \
	DECLARE_FUNCTION(execMGRSToUPS); \
	DECLARE_FUNCTION(execUTMToMGRS); \
	DECLARE_FUNCTION(execMGRSToUTM); \
	DECLARE_FUNCTION(execUPSToGeodetic); \
	DECLARE_FUNCTION(execGeodeticToUPS); \
	DECLARE_FUNCTION(execUTMToGeodetic); \
	DECLARE_FUNCTION(execGeodeticToUTM); \
	DECLARE_FUNCTION(execK2_SetGlobeDefinition);


#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_ACCESSORS
#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_GlobeCoordConverter(); \
	friend struct Z_Construct_UClass_UVH_GlobeCoordConverter_Statics; \
public: \
	DECLARE_CLASS(UVH_GlobeCoordConverter, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_GlobeMath"), NO_API) \
	DECLARE_SERIALIZER(UVH_GlobeCoordConverter)


#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_GlobeCoordConverter(UVH_GlobeCoordConverter&&); \
	NO_API UVH_GlobeCoordConverter(const UVH_GlobeCoordConverter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_GlobeCoordConverter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_GlobeCoordConverter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVH_GlobeCoordConverter) \
	NO_API virtual ~UVH_GlobeCoordConverter();


#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_53_PROLOG
#define FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_SPARSE_DATA \
	FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_ACCESSORS \
	FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h_56_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_GLOBEMATH_API UClass* StaticClass<class UVH_GlobeCoordConverter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeCoordConverter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
