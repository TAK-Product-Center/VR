// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WheeledVehicle/Public/VH_WheeledVehiclePawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAudioComponent;
class UCameraComponent;
class USceneCaptureComponent2D;
class USpringArmComponent;
class UStaticMeshComponent;
class UTextRenderComponent;
enum class EUnitOfSpeed : uint8;
#ifdef VH_VEHICLE_VH_WheeledVehiclePawn_generated_h
#error "VH_WheeledVehiclePawn.generated.h already included, missing '#pragma once' in VH_WheeledVehiclePawn.h"
#endif
#define VH_VEHICLE_VH_WheeledVehiclePawn_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetLeadVehicleFollowPoints); \
	DECLARE_FUNCTION(execGetEngineSoundComponent); \
	DECLARE_FUNCTION(execGetInCarGear); \
	DECLARE_FUNCTION(execGetInCarSpeed); \
	DECLARE_FUNCTION(execGetSteeringWheel); \
	DECLARE_FUNCTION(execGetInternalCamera); \
	DECLARE_FUNCTION(execGetCamera); \
	DECLARE_FUNCTION(execGetSpringArm); \
	DECLARE_FUNCTION(execTeleportLeadVehicleToRoute); \
	DECLARE_FUNCTION(execGetMaxDrivingSpeed); \
	DECLARE_FUNCTION(execSetMaxDrivingSpeed); \
	DECLARE_FUNCTION(execSetHeadlightsEnabled);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVH_WheeledVehiclePawn(); \
	friend struct Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics; \
public: \
	DECLARE_CLASS(AVH_WheeledVehiclePawn, AWheeledVehiclePawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(AVH_WheeledVehiclePawn) \
	virtual UObject* _getUObject() const override { return const_cast<AVH_WheeledVehiclePawn*>(this); }


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVH_WheeledVehiclePawn(AVH_WheeledVehiclePawn&&); \
	NO_API AVH_WheeledVehiclePawn(const AVH_WheeledVehiclePawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVH_WheeledVehiclePawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVH_WheeledVehiclePawn); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVH_WheeledVehiclePawn) \
	NO_API virtual ~AVH_WheeledVehiclePawn();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_26_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class AVH_WheeledVehiclePawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
