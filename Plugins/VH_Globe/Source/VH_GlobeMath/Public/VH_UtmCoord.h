// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_GlobeMathTypes.h"

#include "VH_UtmCoord.generated.h"

/*
 * Global 2D coordinate in Universal Transverse Mercator (UTM).
 * See https://en.wikipedia.org/wiki/Universal_Transverse_Mercator_coordinate_system and https://www.maptools.com/tutorials/utm/quick_guide
 */
USTRUCT(BlueprintType)
struct FUtmCoord
{
    GENERATED_BODY()

public:
    // TODO: Add option to specify N/S hemisphere instead of C-X zoneBand. In this case, zone band should be calculated and cached internally? Or calculated on demand?

    FUtmCoord(int32 zoneNumber, const FString& zoneBand, double easting, double northing) :
        Easting(easting),
        Northing(northing),
        ZoneNumber(zoneNumber),
        ZoneBand(zoneBand)
    {
    }

    FUtmCoord(int32 zoneNumber, const FString& zoneBand) :
        FUtmCoord(zoneNumber, zoneBand, 0.0, 0.0)
    {
    }

    FUtmCoord(int32 zoneNumber) :
        FUtmCoord(zoneNumber, TEXT("N"), 0.0, 0.0)
    {
    }

    FUtmCoord() :
        FUtmCoord(31, TEXT("N"), 0.0, 0.0)
    {
    }

	bool IsValid() const
    {
		return ZoneNumber > 0 && ZoneNumber <= 60;
    }
	
    FString GetGridZoneDesignator() const
    {
        return FString::Printf(TEXT("%02d%s"), ZoneNumber, *ZoneBand);
    }

    FString ToString() const
    {
        return FString::Printf(TEXT("%s %.3Lf %.3Lf"), *GetGridZoneDesignator(), Easting, Northing);
    }

public:
    // Easting/Northing offsets in meters
    double Easting;
    double Northing;

    // Zone ID (e.g. "31N")
    int32 ZoneNumber;  // e.g. 31
    FString ZoneBand;  // e.g. "N"
};

FORCEINLINE bool operator==(const FUtmCoord& a, const FUtmCoord& b)
{
    // clang-format off
	return (
		FMath::IsNearlyEqual(a.Easting, b.Easting) &&
		FMath::IsNearlyEqual(a.Northing, b.Northing) &&
		a.ZoneNumber == b.ZoneNumber &&
		a.ZoneBand.Equals(b.ZoneBand, ESearchCase::IgnoreCase)
		);
    // clang-format on
}
