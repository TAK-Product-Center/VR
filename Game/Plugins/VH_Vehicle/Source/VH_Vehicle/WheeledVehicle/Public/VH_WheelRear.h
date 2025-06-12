
#pragma once

// Engine
#include "CoreMinimal.h"
#include "ChaosVehicleWheel.h"

// Generated
#include "VH_WheelRear.generated.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

UCLASS()
class VH_VEHICLE_API UVH_WheelRear : public UChaosVehicleWheel
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UVH_WheelRear(const FObjectInitializer& objectInitializer);
};

PRAGMA_ENABLE_DEPRECATION_WARNINGS


