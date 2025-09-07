#pragma once

// Parent Includes
#include "Developer_ConverterUnit.h"

// Generated Includes
#include "Developer_ConverterUnit_Length_Mile.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_ConverterUnit_Length_Mile : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit_Length_Mile() : UDeveloper_ConverterUnit(1609.344, TEXT("mi"), TEXT("miles"), TEXT("meters")) {}
};
