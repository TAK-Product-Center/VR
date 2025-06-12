#pragma once

#include "Developer_ConverterUnit.h"

#include "VH_GlobeMathStatics.h"
#include "VH_GeodeticCoord.h"

#include "Globe_ConverterUnit_AltitudeRef_MSL.generated.h"

UCLASS(Blueprintable)
class VH_GLOBE_API UGlobe_ConverterUnit_AltitudeRef_MSL : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()

public:
	UGlobe_ConverterUnit_AltitudeRef_MSL() : UDeveloper_ConverterUnit(0, TEXT("MSL"), TEXT("altitudeRef_MSL"), TEXT("altitudeRef_HAE")) { }

	FString ConvertFromStandard_Implementation(const FString& standardValue) override
	{
		FGeodeticCoord3D geoLocation;
		geoLocation.FromString(standardValue);

		geoLocation.Altitude = UVH_GlobeMathStatics::HAEToMSL(geoLocation.ToGeodeticCoord2D(), geoLocation.Altitude);

		return geoLocation.ToString();
	}

	FString ConvertToStandard_Implementation(const FString& unitValue) override
	{
		FGeodeticCoord3D geoLocation;
		geoLocation.FromString(unitValue);

		geoLocation.Altitude = UVH_GlobeMathStatics::MSLToHAE(geoLocation.ToGeodeticCoord2D(), geoLocation.Altitude);

		return geoLocation.ToString();
	}

};
