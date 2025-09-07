// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/Public/VH_VehiclePathFollowingComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class E_CrowdSimulationState : uint8;
enum class EUnitOfSpeed : uint8;
struct FVehicleHandlingConfig;
#ifdef VH_VEHICLE_VH_VehiclePathFollowingComponent_generated_h
#error "VH_VehiclePathFollowingComponent.generated.h already included, missing '#pragma once' in VH_VehiclePathFollowingComponent.h"
#endif
#define VH_VEHICLE_VH_VehiclePathFollowingComponent_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_26_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics; \
	VH_VEHICLE_API static class UScriptStruct* StaticStruct();


template<> VH_VEHICLE_API UScriptStruct* StaticStruct<struct FVehicleHandlingConfig>();

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execToggleDebug); \
	DECLARE_FUNCTION(execSetHandlingConfig); \
	DECLARE_FUNCTION(execGetHandlingConfig); \
	DECLARE_FUNCTION(execIsStuck); \
	DECLARE_FUNCTION(execSetStuckStatus); \
	DECLARE_FUNCTION(execSetStuckDetection); \
	DECLARE_FUNCTION(execSetCustomControl); \
	DECLARE_FUNCTION(execSetVehicleCrowdSimulation); \
	DECLARE_FUNCTION(execSetDesiredSpeed); \
	DECLARE_FUNCTION(execSetDestinationRotation); \
	DECLARE_FUNCTION(execIsReversing); \
	DECLARE_FUNCTION(execSetAutoReverse); \
	DECLARE_FUNCTION(execSetReverse); \
	DECLARE_FUNCTION(execGetPathPointDataByIndex);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_VehiclePathFollowingComponent(); \
	friend struct Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics; \
public: \
	DECLARE_CLASS(UVH_VehiclePathFollowingComponent, UCrowdFollowingComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(UVH_VehiclePathFollowingComponent)


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_VehiclePathFollowingComponent(UVH_VehiclePathFollowingComponent&&); \
	NO_API UVH_VehiclePathFollowingComponent(const UVH_VehiclePathFollowingComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_VehiclePathFollowingComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_VehiclePathFollowingComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_VehiclePathFollowingComponent) \
	NO_API virtual ~UVH_VehiclePathFollowingComponent();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_71_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_74_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class UVH_VehiclePathFollowingComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
