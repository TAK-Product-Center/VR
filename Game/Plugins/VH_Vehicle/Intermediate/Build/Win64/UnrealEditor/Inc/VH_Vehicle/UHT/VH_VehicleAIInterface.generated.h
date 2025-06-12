// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/VH_VehicleAIInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_VEHICLE_VH_VehicleAIInterface_generated_h
#error "VH_VehicleAIInterface.generated.h already included, missing '#pragma once' in VH_VehicleAIInterface.h"
#endif
#define VH_VEHICLE_VH_VehicleAIInterface_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool OnVehicleStuck_Implementation(FVector& UnStuckLocation) { return false; }; \
 \
	DECLARE_FUNCTION(execOnVehicleStuck);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_VehicleAIInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_VehicleAIInterface(UVH_VehicleAIInterface&&); \
	NO_API UVH_VehicleAIInterface(const UVH_VehicleAIInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_VehicleAIInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_VehicleAIInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_VehicleAIInterface) \
	NO_API virtual ~UVH_VehicleAIInterface();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUVH_VehicleAIInterface(); \
	friend struct Z_Construct_UClass_UVH_VehicleAIInterface_Statics; \
public: \
	DECLARE_CLASS(UVH_VehicleAIInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(UVH_VehicleAIInterface)


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IVH_VehicleAIInterface() {} \
public: \
	typedef UVH_VehicleAIInterface UClassType; \
	typedef IVH_VehicleAIInterface ThisClass; \
	static void Execute_CustomBraking(UObject* O, float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedBrake); \
	static void Execute_CustomSteering(UObject* O, float TargetAngle, float Steering, float DestinationDistance); \
	static void Execute_CustomThrottle(UObject* O, float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedThrottle); \
	static bool Execute_OnVehicleStuck(UObject* O, FVector& UnStuckLocation); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_11_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class UVH_VehicleAIInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
