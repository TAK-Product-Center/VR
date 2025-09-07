// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_GlobeMathTypes.h"

#include "VH_MgrsCoord.generated.h"

/*
 * Global 2D coordinate in Military Grid Reference System (MGRS).
 * See https://en.wikipedia.org/wiki/Military_Grid_Reference_System and https://www.maptools.com/tutorials/mgrs/quick_guide
 */
USTRUCT(BlueprintType)
struct FMgrsCoord
{
    GENERATED_BODY()

public:
    FMgrsCoord(int32 zoneNumber, const FString& zoneBand, const FString& squareID, double easting, double northing) :
        Easting(easting),
        Northing(northing),
        ZoneNumber(zoneNumber),
        ZoneBand(zoneBand),
        SquareID(squareID)
    {
    }

    FMgrsCoord() :
        FMgrsCoord(31, TEXT("N"), TEXT("AA"), 0.0, 0.0)
    {
    }

    FString GetGridZoneDesignator() const
    {
		if ((ZoneNumber > 0))
		{
			return FString::Printf(TEXT("%02d%s"), ZoneNumber, *ZoneBand);
		}
		
		return ZoneBand;
	}

    FString ToString() const
    {
        FString eastingSubstring = FString::Printf(TEXT("%05d"), FMath::TruncToInt(Easting));
        eastingSubstring = eastingSubstring.Right(5);

        FString northingSubstring = FString::Printf(TEXT("%05d"), FMath::TruncToInt(Northing));
        northingSubstring = northingSubstring.Right(5);

		return FString::Printf(TEXT("%s %s %s %s"), *GetGridZoneDesignator(), *SquareID, *eastingSubstring, *northingSubstring);
    }

    static FMgrsCoord FromString(const FString& mgrsString)
    {
        FMgrsCoord mgrsCoord;

        bool isValidZone = false;
        bool isValid100kmSquareID = false;
        bool isValidEasting = false;
        bool isValidNorthing = false;

        if (IsValidString(mgrsString, isValid100kmSquareID, isValid100kmSquareID, isValidEasting, isValidNorthing))
        {
            TArray<FString> mgrsItems;
            mgrsString.ParseIntoArray(mgrsItems, TEXT(" "));

            int32 zoneNumber = FCString::Atoi(*mgrsItems[0].LeftChop(1));
			zoneNumber = (zoneNumber > 0) ? zoneNumber : -1;

            FString zoneBand = mgrsItems[0].Right(1);
            FString squareID = mgrsItems[1];

            // NOTE: Pad Easting/Northing with 0's, up to 5 length
            FString eastingStr = FString::Printf(TEXT("%s00000"), *mgrsItems[2]).Left(5);
            FString northingStr = FString::Printf(TEXT("%s00000"), *mgrsItems[3]).Left(5);
            double easting = FCString::Atod(*eastingStr);
            double northing = FCString::Atod(*northingStr);

            return FMgrsCoord(zoneNumber, zoneBand, mgrsItems[1], easting, northing);
        }

        return FMgrsCoord();
    }

    static bool IsValidString(const FString& mgrsString, bool& isValidZone, bool& isValid100kmSquareID, bool& isValidEasting, bool& isValidNorthing)
    {
        isValidZone = false;
        isValid100kmSquareID = false;
        isValidEasting = false;
        isValidNorthing = false;

		bool bUseUPS = false;

        TArray<FString> mgrsItems;
        mgrsString.ParseIntoArray(mgrsItems, TEXT(" "), false);
        int32 i = 0;
        for (FString item : mgrsItems)
        {
            item.ToUpperInline();

            switch (i)
            {
                case 0:
                {
                    // ZoneID (e.g. "17S"

					if (item.Len() == 1)
					{
						// Check N/S poles (UPS coords)
						FString zoneBand = item.Right(1);
						FString validBands = TEXT("ABYZ");
						if (validBands.Contains(zoneBand))
						{
							isValidZone = true;
							bUseUPS = true;
						}
					}
					else if (item.Len() >= 2 && item.Len() <= 3)
                    {
						// Between N/S poles (UTM coords)
                        FString zoneNumString = item.LeftChop(1);
						if (zoneNumString.IsNumeric())
                        {
							int32 zoneNumber = FCString::Atoi(*zoneNumString);
                            if (zoneNumber >= 1 && zoneNumber <= 60)
                            {
								FString zoneBand = item.Right(1);
								FString validBands = TEXT("CDEFGHJKLMNPQRSTUVWX");
                                if (validBands.Contains(zoneBand))
                                {
                                    isValidZone = true;
                                }
                            }
						}
					}

                    break;
                }

                case 1:
                {
                    // SquareID (e.g. "KR")
                    if (item.Len() == 2)
                    {
						FString validBandCol = bUseUPS ? TEXT("ABCFGHJKLPQRSTUXYZ") : TEXT("ABCDEFGHJKLMNPQRSTUVWXYZ");
						FString validBandRow = bUseUPS ? TEXT("ABCDEFGHJKLMNPQRSTUVWXYZ") : TEXT("ABCDEFGHJKLMNPQRSTUV");
						FString bandCol = item.Left(1);
                        FString bandRow = item.Right(1);

                        if (validBandCol.Contains(bandCol) && validBandRow.Contains(bandRow))
                        {
                            isValid100kmSquareID = true;
                        }
                    }

                    break;
                }

                case 2:
                    // Easting
                    isValidEasting = (item.Len() >= 1 && item.Len() <= 5 && item.IsNumeric() && !item.Contains(TEXT(".")) && !item.Contains(TEXT("-")));
                    break;

                case 3:
                {
                    // Northing
                    isValidNorthing = (item.Len() >= 1 && item.Len() <= 5 && item.IsNumeric() && !item.Contains(TEXT(".")) && !item.Contains(TEXT("-")));
                    break;
                }

                default:
                    break;
            }

            i++;
        }

        return (isValidZone && isValid100kmSquareID && isValidEasting && isValidNorthing);
    }

public:
    // Easting/Northing offsets in meters
    double Easting;
    double Northing;

    // Zone ID (e.g. "31N")
    int32 ZoneNumber;  // e.g. 31
    FString ZoneBand;  // e.g. "N"

    // 100km square id (e.g. "AA")
    FString SquareID;
};

FORCEINLINE bool operator==(const FMgrsCoord& a, const FMgrsCoord& b)
{
    // clang-format off
	return (
		FMath::IsNearlyEqual(a.Easting, b.Easting) &&
		FMath::IsNearlyEqual(a.Northing, b.Northing) &&
		a.ZoneNumber == b.ZoneNumber &&
		a.ZoneBand.Equals(b.ZoneBand, ESearchCase::IgnoreCase) &&
		a.SquareID.Equals(b.SquareID, ESearchCase::IgnoreCase)
		);
    // clang-format on
}
