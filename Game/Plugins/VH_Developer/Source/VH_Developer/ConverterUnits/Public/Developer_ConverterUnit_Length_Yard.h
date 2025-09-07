#pragma once

// Parent Includes
#include "Developer_ConverterUnit.h"

// Generated Includes
#include "Developer_ConverterUnit_Length_Yard.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_ConverterUnit_Length_Yard : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit_Length_Yard() : UDeveloper_ConverterUnit(0.9144, TEXT("yd"), TEXT("yards"), TEXT("meters")) {}
};
