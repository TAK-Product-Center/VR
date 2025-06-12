#pragma once

// Generated
#include "VH_VehicleEnums.generated.h"

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EUnitOfSpeed : uint8
{
	MilesPerHour,
	KilometersPerHour,
	CentimetersPerSecond
};

UENUM()
enum class E_CrowdSimulationState : uint8
{
	Enabled,
	ObstacleOnly,
	Disabled,
};