#pragma once

// Engine
#include "ChaosVehicleWheel.h"

// Generated
#include "VH_WheelFront.generated.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

UCLASS()
class VH_VEHICLE_API UVH_WheelFront : public UChaosVehicleWheel
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UVH_WheelFront(const FObjectInitializer& objectInitializer);
};

PRAGMA_ENABLE_DEPRECATION_WARNINGS
