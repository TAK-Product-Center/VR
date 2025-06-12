#pragma once

// Parent Includes
#include "Developer_ConverterUnit.h"

// Generated Includes
#include "Developer_ConverterUnit_Length_Foot.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_ConverterUnit_Length_Foot : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit_Length_Foot() : UDeveloper_ConverterUnit(0.3048, TEXT("ft"), TEXT("feet"), TEXT("meters")) {}
};
