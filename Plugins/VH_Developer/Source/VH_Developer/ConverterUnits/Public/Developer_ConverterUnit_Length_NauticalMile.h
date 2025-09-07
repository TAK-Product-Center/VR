#pragma once

// Parent Includes
#include "Developer_ConverterUnit.h"

// Generated Includes
#include "Developer_ConverterUnit_Length_NauticalMile.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_ConverterUnit_Length_NauticalMile: public UDeveloper_ConverterUnit
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit_Length_NauticalMile() : UDeveloper_ConverterUnit(1852.0, TEXT("NM"), TEXT("nautical miles"), TEXT("meters")) {}
};
