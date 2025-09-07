// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WheeledVehicle/Public/VH_WheeledVehicleAIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USplineComponent;
enum class EVehiclePathfindingState : uint8;
#ifdef VH_VEHICLE_VH_WheeledVehicleAIController_generated_h
#error "VH_WheeledVehicleAIController.generated.h already included, missing '#pragma once' in VH_WheeledVehicleAIController.h"
#endif
#define VH_VEHICLE_VH_WheeledVehicleAIController_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFindPathInputKeyAtLocationAndDistance); \
	DECLARE_FUNCTION(execSetFollowSplineFromVectorArray); \
	DECLARE_FUNCTION(execSetTargetLocation); \
	DECLARE_FUNCTION(execBeginMoveToTargetLocation); \
	DECLARE_FUNCTION(execForcePathingComplete); \
	DECLARE_FUNCTION(execSuspendPathing); \
	DECLARE_FUNCTION(execGetFollowSpline); \
	DECLARE_FUNCTION(execGetPathingState); \
	DECLARE_FUNCTION(execGetPathingTargetLocation);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVH_WheeledVehicleAIController(); \
	friend struct Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics; \
public: \
	DECLARE_CLASS(AVH_WheeledVehicleAIController, AVH_VehicleAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(AVH_WheeledVehicleAIController)


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVH_WheeledVehicleAIController(AVH_WheeledVehicleAIController&&); \
	NO_API AVH_WheeledVehicleAIController(const AVH_WheeledVehicleAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVH_WheeledVehicleAIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVH_WheeledVehicleAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVH_WheeledVehicleAIController) \
	NO_API virtual ~AVH_WheeledVehicleAIController();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_32_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class AVH_WheeledVehicleAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h


#define FOREACH_ENUM_EVEHICLEPATHFINDINGSTATE(op) \
	op(EVehiclePathfindingState::Inactive) \
	op(EVehiclePathfindingState::InProgress) \
	op(EVehiclePathfindingState::Suspended) 

enum class EVehiclePathfindingState : uint8;
template<> struct TIsUEnumClass<EVehiclePathfindingState> { enum { Value = true }; };
template<> VH_VEHICLE_API UEnum* StaticEnum<EVehiclePathfindingState>();

#define FOREACH_ENUM_EVEHICLEPATHFINDINGRESULT(op) \
	op(EVehiclePathfindingResult::Success) \
	op(EVehiclePathfindingResult::Aborted) \
	op(EVehiclePathfindingResult::Failed) 

enum class EVehiclePathfindingResult : uint8;
template<> struct TIsUEnumClass<EVehiclePathfindingResult> { enum { Value = true }; };
template<> VH_VEHICLE_API UEnum* StaticEnum<EVehiclePathfindingResult>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
