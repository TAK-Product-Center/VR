#pragma once

// Parent Includes
#include "Developer_ConverterUnit.h"

// Generated Include
#include "Developer_ConverterUnit_Time_Second.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_ConverterUnit_Time_Second: public UDeveloper_ConverterUnit
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit_Time_Second() : UDeveloper_ConverterUnit(1.0, TEXT("s"), TEXT("seconds"), TEXT("seconds")) {}
};
