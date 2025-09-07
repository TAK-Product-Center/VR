#pragma once

// Parent Includes
#include "Developer_ConverterUnit.h"

// Generated Includes
#include "Developer_ConverterUnit_Time_Hour.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_ConverterUnit_Time_Hour : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit_Time_Hour() : UDeveloper_ConverterUnit(3600.0, TEXT("hr"), TEXT("hours"), TEXT("seconds")) {}
};
