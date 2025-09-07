// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VH_GlobeMathTypes.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_GLOBEMATH_VH_GlobeMathTypes_generated_h
#error "VH_GlobeMathTypes.generated.h already included, missing '#pragma once' in VH_GlobeMathTypes.h"
#endif
#define VH_GLOBEMATH_VH_GlobeMathTypes_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Globe_Source_VH_GlobeMath_Public_VH_GlobeMathTypes_h


#define FOREACH_ENUM_EGEOLOCATIONTYPE(op) \
	op(EGeoLocationType::Geodetic) \
	op(EGeoLocationType::MGRS) \
	op(EGeoLocationType::UTM) 

enum class EGeoLocationType : uint8;
template<> struct TIsUEnumClass<EGeoLocationType> { enum { Value = true }; };
template<> VH_GLOBEMATH_API UEnum* StaticEnum<EGeoLocationType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
