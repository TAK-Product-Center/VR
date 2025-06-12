#pragma once

// Parent Includes
#include "Developer_ConverterUnit.h"

// Generated includes
#include "Developer_ConverterUnit_Angle_Mil.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_ConverterUnit_Angle_Mil : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit_Angle_Mil() : UDeveloper_ConverterUnit(180.0 / (1000.0 * PI), TEXT("mil"), TEXT("milliradians"), TEXT("degrees"))	{}
};
