#pragma once

#include "Developer_ConverterUnit.h"

#include "VH_GlobeMathStatics.h"
#include "VH_GeodeticCoord.h"

#include "Globe_ConverterUnit_AltitudeRef_AGL.generated.h"

UCLASS(Blueprintable)
class VH_GLOBE_API UGlobe_ConverterUnit_AltitudeRef_AGL : public UDeveloper_ConverterUnit
{
	GENERATED_BODY()

public:
	UGlobe_ConverterUnit_AltitudeRef_AGL() : UDeveloper_ConverterUnit(0, TEXT("AGL"), TEXT("altitudeRef_AGL"), TEXT("altitudeRef_HAE")) { }

	FString ConvertFromStandard_Implementation(const FString& standardValue) override
	{
		FGeodeticCoord3D geoLocation;
		geoLocation.FromString(standardValue);

		double groundHAE = GetGroundAltitude(geoLocation.ToGeodeticCoord2D());
		geoLocation.Altitude -= groundHAE;

		return geoLocation.ToString();
	}

	FString ConvertToStandard_Implementation(const FString& unitValue) override
	{
		FGeodeticCoord3D geoLocation;
		geoLocation.FromString(unitValue);

		double groundHAE = GetGroundAltitude(geoLocation.ToGeodeticCoord2D());
		geoLocation.Altitude += groundHAE;

		return geoLocation.ToString();
	}

	/**
	 * NOTE: If successfully traces a line to the ground, returns the altitude in meters.
	 */
	virtual double GetGroundAltitude(const FGeodeticCoord2D& geoLocation2D)
	{
		// TODO: Do raycast/lookup to find difference in ground level and HAE
		return 0;
	}

};
