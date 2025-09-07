#pragma once

#include "Developer_ConverterUnit.h"

#include "Globe_ConverterUnit_AltitudeRef_HAE.generated.h"

UCLASS(Blueprintable)
class VH_GLOBE_API UGlobe_ConverterUnit_AltitudeRef_HAE : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()

public:
	UGlobe_ConverterUnit_AltitudeRef_HAE() : UDeveloper_ConverterUnit(1, TEXT("HAE"), TEXT("altitudeRef_HAE"), TEXT("altitudeRef_HAE")) { }

	FString ConvertFromStandard_Implementation(const FString& standardValue) override
	{
		return standardValue;
	}

	FString ConvertToStandard_Implementation(const FString& unitValue) override
	{
		return unitValue;
	}

};
