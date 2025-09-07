// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/Public/VH_VehicleAIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
#ifdef VH_VEHICLE_VH_VehicleAIController_generated_h
#error "VH_VehicleAIController.generated.h already included, missing '#pragma once' in VH_VehicleAIController.h"
#endif
#define VH_VEHICLE_VH_VehicleAIController_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual FVector OnNewPathSegment_Implementation(int32 PathPointIndex, FVector StartSegmentLocation, FVector TargetSegmentLocation, const UClass* AreaClass, bool bIsOnNavLink); \
	virtual FVector GetCustomDestination_Implementation(FVector CurrentMoveFocus); \
 \
	DECLARE_FUNCTION(execOnNewPathSegment); \
	DECLARE_FUNCTION(execGetCustomDestination);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVH_VehicleAIController(); \
	friend struct Z_Construct_UClass_AVH_VehicleAIController_Statics; \
public: \
	DECLARE_CLASS(AVH_VehicleAIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(AVH_VehicleAIController)


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVH_VehicleAIController(AVH_VehicleAIController&&); \
	NO_API AVH_VehicleAIController(const AVH_VehicleAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVH_VehicleAIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVH_VehicleAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVH_VehicleAIController) \
	NO_API virtual ~AVH_VehicleAIController();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_9_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class AVH_VehicleAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
