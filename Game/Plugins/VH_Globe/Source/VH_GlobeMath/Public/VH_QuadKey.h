
#pragma once

#include "VH_GlobeTileIdentifier.h"
#include "VH_GeodeticCoord.h"

struct FGlobeTileIdentifier;
struct FGeodeticCoord2D;

/**
 * QuadKey class to represent a tile/geodetic location in a compact format.
 *
 * NOTE: This stores the quadkey value as a 64-bit int, where the lowest 5 bits (0b11111L, see LevelMask constant) hold 
 *       the zoom level, and the highest bits (from the 64th bit downwards) hold the actual quadkey index value.
 *       This allows for a 64-bit int to represent all zoom levels up to and including level 29 ((64-5) / 2).
 */
class VH_GLOBEMATH_API FQuadKey
{

public:
    FQuadKey(uint64 inValue = 0);
    FQuadKey(const FString& inString);


    // ---------------------------------
    // --- Methods
    // ---------------------------------
public:
    uint64 GetValue() const;
    void SetValue(uint64 inValue);

    FString GetStringValue() const;
    void SetStringValue(const FString& inStringValue);

    int32 GetLevel(bool isMercator = false) const;

    FGlobeTileIdentifier ToTile(bool isMercator = false) const;
    static FQuadKey FromTile(const FGlobeTileIdentifier& tileID, bool isMercator = false);
    static FQuadKey FromGeodetic(int32 level, const FGeodeticCoord2D& geodetic, bool isMercator = false);

    static bool IsParentOf(const FQuadKey& parentQK, const FQuadKey& childQK);


    // ---------------------------------
    // --- Implementation
    // ---------------------------------
private:
    static int32 ExtractLevel(uint64 inValue);

    FString EncodeStringValue(uint64 inValue) const;
    uint64 DecodeStringValue(const FString& inStringValue) const;


    // ---------------------------------
    // --- Member Variables
    // ---------------------------------
private:
    uint64 Value;

    static const uint64 LevelMask;
    static const uint64 ValueMasks[];
};
