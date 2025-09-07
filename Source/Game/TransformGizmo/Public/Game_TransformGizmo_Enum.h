#pragma once

// Engine Includes
#include "Misc/EnumRange.h"

// Generated Includes
#include "Game_TransformGizmo_Enum.generated.h"

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class ETransformMode : uint8
{
	ETM_None,
	ETM_Translate,
	ETM_Rotate,
	ETM_Scale,

	ETM_Max
};
ENUM_CLASS_FLAGS(ETransformMode);

UENUM(BlueprintType, meta = (Bitflags, UseEnumVAluesAsMaskVAluesInEditor = "true"))
enum class ETransformOrigin : uint8
{
	ETO_World,
	ETO_Local
};
ENUM_CLASS_FLAGS(ETransformOrigin);

UENUM()
enum class ETransformAxis : uint8
{
	// Axes, used for translation, scale, rotation
	TA_X,
	TA_Y,
	TA_Z,
	// Planes, used for translation and scale
	TA_XY,
	TA_XZ,
	TA_YZ,

	TA_MAX UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(ETransformAxis, ETransformAxis::TA_MAX);
