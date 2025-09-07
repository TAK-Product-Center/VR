// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Data/Public/VH_VehicleEnums.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_VEHICLE_VH_VehicleEnums_generated_h
#error "VH_VehicleEnums.generated.h already included, missing '#pragma once' in VH_VehicleEnums.h"
#endif
#define VH_VEHICLE_VH_VehicleEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Data_Public_VH_VehicleEnums_h


#define FOREACH_ENUM_EUNITOFSPEED(op) \
	op(EUnitOfSpeed::MilesPerHour) \
	op(EUnitOfSpeed::KilometersPerHour) \
	op(EUnitOfSpeed::CentimetersPerSecond) 

enum class EUnitOfSpeed : uint8;
template<> struct TIsUEnumClass<EUnitOfSpeed> { enum { Value = true }; };
template<> VH_VEHICLE_API UEnum* StaticEnum<EUnitOfSpeed>();

#define FOREACH_ENUM_E_CROWDSIMULATIONSTATE(op) \
	op(E_CrowdSimulationState::Enabled) \
	op(E_CrowdSimulationState::ObstacleOnly) \
	op(E_CrowdSimulationState::Disabled) 

enum class E_CrowdSimulationState : uint8;
template<> struct TIsUEnumClass<E_CrowdSimulationState> { enum { Value = true }; };
template<> VH_VEHICLE_API UEnum* StaticEnum<E_CrowdSimulationState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
