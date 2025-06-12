#pragma once

#include "VH_GeodeticCoord.h"
#include "VH_QuadKey.h"

#include "Misc/Paths.h"

#include "VH_GlobeTileIdentifier.generated.h"

class FQuadKey;

/*
 *
 */
USTRUCT(BlueprintType)
struct FGlobeTileIdentifier
{
    GENERATED_BODY()

public:
    FGlobeTileIdentifier(int32 level, int32 x, int32 y)
    {
        this->Level = level;
        this->X = x;
        this->Y = y;
    }

    FGlobeTileIdentifier() :
        FGlobeTileIdentifier(-1, -1, -1)
    {
    }

    FGlobeTileIdentifier(const FGlobeTileIdentifier& other)
    {
        this->Level = other.Level;
        this->X = other.X;
        this->Y = other.Y;
    }

    bool IsValid() const { return (X >= 0 && Y >= 0 && Level >= 0); }

    // Builds a tile from a string (built with ToString)
    static VH_GLOBEMATH_API FGlobeTileIdentifier FromGeodetic(int32 level, const FGeodeticCoord2D& geoCoord, double LevelZeroLonDegPerTile = 180.0, double LevelZeroLatDegPerTile = 180.0);

    // Builds a tile from a string (built with ToString)
    static VH_GLOBEMATH_API FGlobeTileIdentifier FromString(const FString& idString);

    // Builds a string for internal token passing
    FString ToString() const { return IsValid() ? FString::Printf(TEXT("z%d_y%d_x%d"), Level, Y, X) : TEXT(""); }

    // Builds a color for debug display
    FColor ToColor() const { return FColor(Level % 255, X % 255, Y % 255, 128); }

    // Builds a string for cache dir, including z/y/x chars (e.g. "z15/y23794/x19294")
    FString ToPath() const { return IsValid() ? FPaths::Combine(FString::Printf(TEXT("z%d"), Level), FString::Printf(TEXT("y%d"), Y), FString::Printf(TEXT("x%d"), X)) : TEXT(""); }

    // Builds a string for cache dir, omitting the z/y/x chars (e.g. "15/23794/19294")
    FString ToCompactPath() const { return IsValid() ? FPaths::Combine(FString::FromInt(Level), FString::FromInt(Y), FString::FromInt(X)) : TEXT(""); }

    // TODO: Consider converting to return a FGeodeticExtent, instead.
    void GetGeodeticExtents(double& minLon, double& maxLon, double& minLat, double& maxLat, double LevelZeroLonDegPerTile = 180.0, double LevelZeroLatDegPerTile = 180.0);

    FQuadKey GetQuadKey(bool isMercator = false);

    /**
	 * Compares this tileID against another for equality.
	 *
	 * @param other The tileID to compare against.
	 * @return true if the two tileID's are equal, otherwise false.
	 */
    FORCEINLINE bool operator==(const FGlobeTileIdentifier& other) const
    {
        return this->Level == other.Level && this->X == other.X && this->Y == other.Y;
    }

    /**
	 * Compares this tileID against another for inequality.
	 *
	 * @param other The tileID to compare against.
	 * @return true if the two tileID's are not equal, otherwise false.
	 */
    FORCEINLINE bool operator!=(const FGlobeTileIdentifier& other) const
    {
        return !(*this == other);
    }

    // ---------------------------------
    // --- Member Variables
    // ---------------------------------
public:
    /** An invalid tileID (-1, -1, -1) */
    static VH_GLOBEMATH_API const FGlobeTileIdentifier InvalidTile;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VhGlobeTileIdentifier")
    int32 Level;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VhGlobeTileIdentifier")
    int32 X;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VhGlobeTileIdentifier")
    int32 Y;
};

FORCEINLINE uint32 GetTypeHash(const FGlobeTileIdentifier& tileID)
{
    return GetTypeHash(tileID.Level) ^ GetTypeHash(tileID.X) ^ GetTypeHash(tileID.Y);
}
