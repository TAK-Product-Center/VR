// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/Public/VH_VehicleAIFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AAIController;
class APawn;
class USplineComponent;
class UVH_VehiclePathFollowingComponent;
enum class EUnitOfSpeed : uint8;
#ifdef VH_VEHICLE_VH_VehicleAIFunctionLibrary_generated_h
#error "VH_VehicleAIFunctionLibrary.generated.h already included, missing '#pragma once' in VH_VehicleAIFunctionLibrary.h"
#endif
#define VH_VEHICLE_VH_VehicleAIFunctionLibrary_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFollowSplinePath); \
	DECLARE_FUNCTION(execSetPathPoints); \
	DECLARE_FUNCTION(execConvertToTankSteering); \
	DECLARE_FUNCTION(execConvertVelocityByUnit); \
	DECLARE_FUNCTION(execGetVehiclePathFollowingComponent);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_VehicleAIFunctionLibrary(); \
	friend struct Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UVH_VehicleAIFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(UVH_VehicleAIFunctionLibrary)


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_VehicleAIFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_VehicleAIFunctionLibrary(UVH_VehicleAIFunctionLibrary&&); \
	NO_API UVH_VehicleAIFunctionLibrary(const UVH_VehicleAIFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_VehicleAIFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_VehicleAIFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_VehicleAIFunctionLibrary) \
	NO_API virtual ~UVH_VehicleAIFunctionLibrary();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_17_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class UVH_VehicleAIFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
