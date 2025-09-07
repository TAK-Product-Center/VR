// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_GlobeMathTypes.h"

#include "VH_UpsCoord.generated.h"

/*
 * Global 2D coordinate in Universal Polar Stereographic (UPS) coordinate system.
 * See https://en.wikipedia.org/wiki/Universal_polar_stereographic_coordinate_system and https://earth-info.nga.mil/GandG/publications/NGA_SIG_0012_2_0_0_UTMUPS/NGA.SIG.0012_2.0.0_UTMUPS.pdf
 */
USTRUCT(BlueprintType)
struct FUpsCoord
{
    GENERATED_BODY()

public:
    // TODO: Add option to specify N/S hemisphere instead of C-X zoneBand. In this case, zone band should be calculated and cached internally? Or calculated on demand?

    FUpsCoord(const FString& zoneBand, double easting, double northing) :
        Easting(easting),
        Northing(northing),
        ZoneBand(zoneBand)
    {
    }

    FUpsCoord(const FString& zoneBand) :
        FUpsCoord(zoneBand, 0.0, 0.0)
    {
    }

    FUpsCoord() :
        FUpsCoord(TEXT("A"))
    {
    }

    FString ToString() const
    {
        return FString::Printf(TEXT("%s %.3Lf %.3Lf"), *ZoneBand, Easting, Northing);
    }

public:
    // Easting/Northing offsets in meters
    double Easting;
    double Northing;

    FString ZoneBand;  // e.g. A/B at south pole, or Y/Z at north pole
};

FORCEINLINE bool operator==(const FUpsCoord& a, const FUpsCoord& b)
{
    // clang-format off
	return (
		FMath::IsNearlyEqual(a.Easting, b.Easting) &&
		FMath::IsNearlyEqual(a.Northing, b.Northing) &&
		a.ZoneBand.Equals(b.ZoneBand, ESearchCase::IgnoreCase)
		);
    // clang-format on
}
