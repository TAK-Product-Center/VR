// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_GlobeMathTypes.h"
#include "VH_GeodeticCoord.h"

#include "VH_GlobeTangentCoord.generated.h"

USTRUCT(BlueprintType)
struct FGlobeTangentCoord2D
{
    GENERATED_BODY()

public:
    FGlobeTangentCoord2D(const FGeodeticCoord2D& geodeticRef, double easting, double northing) :
        Easting(easting),
        Northing(northing),
        GeodeticRef(geodeticRef)
    {
    }

    FGlobeTangentCoord2D() :
        FGlobeTangentCoord2D(FGeodeticCoord2D(0, 0), 0, 0)
    {
    }

    FString ToString() const
    {
        return FString::Printf(TEXT("%.3Lfm E, %.3Lfm N from (%.8Lf, %.8Lf)"), Easting, Northing, GeodeticRef.Longitude, GeodeticRef.Latitude);
    }

public:
    // Easting/Northing offsets in meters
    double Easting;
    double Northing;

    // Geodetic reference point
    FGeodeticCoord2D GeodeticRef;
};

FORCEINLINE bool operator==(const FGlobeTangentCoord2D& a, const FGlobeTangentCoord2D& b)
{
    // clang-format off
	return (
		FMath::IsNearlyEqual(a.Easting, b.Easting) &&
		FMath::IsNearlyEqual(a.Northing, b.Northing) &&
		a.GeodeticRef == b.GeodeticRef
		);
    // clang-format on
}

/*
 *
 */
USTRUCT(BlueprintType)
struct FGlobeTangentCoord
{
    GENERATED_BODY()

public:
    FGlobeTangentCoord(const FGeodeticCoord3D& geodeticRef, double easting, double northing, double height) :
        Easting(easting),
        Northing(northing),
        Height(height),
		GeodeticRef(geodeticRef)
	{
    }

    FGlobeTangentCoord(const FGeodeticCoord3D& geodeticRef, double easting, double northing) :
        FGlobeTangentCoord(geodeticRef, easting, northing, 0)
    {
    }

    FGlobeTangentCoord() :
        FGlobeTangentCoord(FGeodeticCoord3D(0, 0, 0), 0, 0, 0)
    {
    }

    FGlobeTangentCoord(const FGlobeTangentCoord2D& globeTangent2D, double height) :
        FGlobeTangentCoord(FGeodeticCoord3D(globeTangent2D.GeodeticRef), globeTangent2D.Easting, globeTangent2D.Northing, height)
    {
    }

    FGlobeTangentCoord(const FGlobeTangentCoord2D& globeTangent2D) :
        FGlobeTangentCoord(globeTangent2D, 0)
    {
    }

	// NOTE: 'tangentOffset' is interpreted as X-axis pointing North
    FGlobeTangentCoord(const FGeodeticCoord3D& geodeticRef, const FVector& tangentOffset) :
        FGlobeTangentCoord(geodeticRef, tangentOffset.Y, tangentOffset.X, tangentOffset.Z)
    {
    }

    FVector GetTangentOffset() const
    {
        // NOTE: North = +X axis, East = +Y axis, Height = +Z axis
        return FVector(Northing, Easting, Height);
    }

    FGlobeTangentCoord2D ToGlobeTangentCoord2D() const
    {
        return FGlobeTangentCoord2D(GeodeticRef.ToGeodeticCoord2D(), Easting, Northing);
    }

    FString ToString() const
    {
        return FString::Printf(TEXT("%.8Lfm E, %.8Lfm N, %.8Lfm from (%s)"), Easting, Northing, Height, *GeodeticRef.ToString());
    }

public:
    // Easting/Northing offsets in meters
    double Easting;
    double Northing;

	// Height in meters (relative to GeodeticRef)
	double Height;

	// Geodetic reference point
    FGeodeticCoord3D GeodeticRef;
};

FORCEINLINE bool operator==(const FGlobeTangentCoord& a, const FGlobeTangentCoord& b)
{
    // clang-format off
	return (
		FMath::IsNearlyEqual(a.Easting, b.Easting) &&
		FMath::IsNearlyEqual(a.Northing, b.Northing) &&
		FMath::IsNearlyEqual(a.Height, b.Height) &&
		a.GeodeticRef == b.GeodeticRef
		);
    // clang-format on
}
