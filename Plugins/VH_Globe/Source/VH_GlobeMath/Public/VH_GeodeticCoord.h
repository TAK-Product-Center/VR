#pragma once

// Module Includes
#include "VH_GlobeMathTypes.h"

// Generated Includes
#include "VH_GeodeticCoord.generated.h"

USTRUCT(BlueprintType)
struct FGeodeticCoord2D
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables 
	// ---------------------------------

public:
	// Longitude in degrees
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeodeticCoord2D")
	double Longitude;

	// Latitude in degrees
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeodeticCoord2D")
	double Latitude;

	/** An invalid geodetic coordinate (999, 999) */
	static VH_GLOBEMATH_API const FGeodeticCoord2D Invalid;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	FGeodeticCoord2D(double longitude, double latitude) :
        Longitude(longitude),
        Latitude(latitude)
    {

    }

    FGeodeticCoord2D(const TArray<double>& doubleArray)
    {
        if (doubleArray.Num() == 2)
        {
            Latitude = doubleArray[0];
            Longitude = doubleArray[1];
        }
    }

	FGeodeticCoord2D(const FVector2D& vector) : 
		FGeodeticCoord2D(vector.X, vector.Y)
	{

	}

	FGeodeticCoord2D() :
        FGeodeticCoord2D(0, 0)
    {

    }

	bool FromString(const FString& inString)
	{
		// Initialize as invalid
		bool bSuccess = false;
		*this = FGeodeticCoord2D::Invalid;

		TArray<FString> parsedParams;
		inString.ParseIntoArray(parsedParams, TEXT(", "), true);
		if (parsedParams.Num() >= 2)
		{
			Longitude = FCString::Atod(*parsedParams[0]);
			Latitude = FCString::Atod(*parsedParams[1]);

			bSuccess = true;
		}

		return bSuccess;
	}

	FString ToString() const
    {
        return FString::Printf(TEXT("%.8Lf, %.8Lf"), Longitude, Latitude);
    }

	TArray<double> ToArray() const
    {
        TArray<double> toReturn;

        toReturn.Add(Longitude);
        toReturn.Add(Latitude);

        return toReturn;
    }

	FVector2D ToVector() const
	{
		return FVector2D(Longitude, Latitude);
	}

	friend VH_GLOBEMATH_API FArchive& operator<<(FArchive& Ar, FGeodeticCoord2D& M)
	{
		Ar << M.Longitude << M.Latitude;
		return Ar;
	}

	bool Serialize(FArchive& Ar)
	{
		if (Ar.UEVer() >= VER_UE4_ADDED_NATIVE_SERIALIZATION_FOR_IMMUTABLE_STRUCTURES)
		{
			Ar << *this;
			return true;
		}
		return false;
	}

	VH_GLOBEMATH_API bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
	{
		Ar << Longitude;
		Ar << Latitude;

		return true;
	}
};

FORCEINLINE uint32 GetTypeHash(const FGeodeticCoord2D& coordinate)
{
    return GetTypeHash(coordinate.Longitude) ^ GetTypeHash(coordinate.Latitude);
}

FORCEINLINE bool operator==(const FGeodeticCoord2D& a, const FGeodeticCoord2D& b)
{
	return (
		FMath::IsNearlyEqual(a.Longitude, b.Longitude) &&
		FMath::IsNearlyEqual(a.Latitude, b.Latitude)
		);
}

FORCEINLINE bool operator!=(const FGeodeticCoord2D& a, const FGeodeticCoord2D& b)
{
    return !(a == b);
}

template<>
struct TStructOpsTypeTraits<FGeodeticCoord2D> : public TStructOpsTypeTraitsBase2<FGeodeticCoord2D>
{
	enum
	{
		WithNetSerializer = true
	};
};

/*
 * Holds a Geodetic (Lat-Long) Coordinate and an altitude (usually in meters HAE)
 */
USTRUCT(BlueprintType)
struct FGeodeticCoord3D
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	// Longitude in degrees
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeodeticCoord3D")
	double Longitude;

	// Latitude in degrees
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeodeticCoord3D")
	double Latitude;

	// Altitude in meters
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeodeticCoord3D")
	double Altitude;

	// If false, altitude is assumed HAE
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeodeticCoord3D")
	bool bIsAltitudeRelativeToGround;

	/* An invalid geodetic coordinate (999, 999, 0, false) */
	static VH_GLOBEMATH_API const FGeodeticCoord3D Invalid;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	FGeodeticCoord3D(double longitude, double latitude, double altitude, bool bRelativeToGround) :
        Longitude(longitude),
        Latitude(latitude),
		Altitude(altitude),
		bIsAltitudeRelativeToGround(bRelativeToGround)
    {

    }

	FGeodeticCoord3D(double longitude, double latitude, double altitude) :
		FGeodeticCoord3D(longitude, latitude, altitude, false)
	{

	}

	FGeodeticCoord3D(double longitude, double latitude) :
        FGeodeticCoord3D(longitude, latitude, 0, false)
    {

    }

	FGeodeticCoord3D() :
        FGeodeticCoord3D(0, 0, 0, false)
    {

    }

	FGeodeticCoord3D(const FGeodeticCoord2D& geodetic2D, double altitude, bool bRelativeToGround) :
		FGeodeticCoord3D(geodetic2D.Longitude, geodetic2D.Latitude, altitude, bRelativeToGround)
	{

	}

	FGeodeticCoord3D(const FGeodeticCoord2D& geodetic2D, double altitude) :
        FGeodeticCoord3D(geodetic2D.Longitude, geodetic2D.Latitude, altitude, false)
    {

    }

    FGeodeticCoord3D(const FGeodeticCoord2D& geodetic2D) :
        FGeodeticCoord3D(geodetic2D, 0, false)
    {

    }

	FGeodeticCoord3D(const FVector& vector, bool bRelativeToGround) :
		FGeodeticCoord3D(vector.X, vector.Y, vector.Z, bRelativeToGround)
	{

	}

	FGeodeticCoord3D(const FVector& vector) :
		FGeodeticCoord3D(vector.X, vector.Y, vector.Z, false)
	{

	}

	bool FromString(const FString& inString)
	{
		// Initialize as invalid
		bool bSuccess = false;
		*this = FGeodeticCoord3D::Invalid;

		TArray<FString> parsedParams;
		inString.ParseIntoArray(parsedParams, TEXT(", "), true);
		if (parsedParams.Num() >= 3)
		{
			Longitude = FCString::Atod(*parsedParams[0]);
			Latitude = FCString::Atod(*parsedParams[1]);

			TArray<FString> altParsedParams;
			parsedParams[2].ParseIntoArray(altParsedParams, TEXT(" "), true);
			Altitude = FCString::Atod(*altParsedParams[0]);
			if (altParsedParams.Num() >= 2)
			{
				bIsAltitudeRelativeToGround = altParsedParams[1].Equals(TEXT("AGL"), ESearchCase::IgnoreCase);
			}

			bSuccess = true;
		}
		else if (parsedParams.Num() == 2)
		{
			FGeodeticCoord2D coord2D;
			if (coord2D.FromString(inString))
			{
				FGeodeticCoord3D(coord2D, 0, false);
				bSuccess = true;
			}
		}

		return bSuccess;
	}

	FString ToString() const
    {
		return FString::Printf(TEXT("%.8Lf, %.8Lf, %.8Lf%s"), Longitude, Latitude, Altitude, bIsAltitudeRelativeToGround ? TEXT(" AGL") : TEXT(""));
	}

	// Assumes altitude is interpreted as HAE. Caller should check bIsAltitudeRelativeToGround, otherwise.
	TArray<double> ToArray() const
    {
        TArray<double> toReturn;

        toReturn.Add(Longitude);
        toReturn.Add(Latitude);
        toReturn.Add(Altitude);

        return toReturn;
    }

	// Assumes altitude is interpreted as HAE. Caller should check bIsAltitudeRelativeToGround, otherwise.
	FVector ToVector() const
	{
		return FVector(Longitude, Latitude, Altitude);
	}

	FGeodeticCoord2D ToGeodeticCoord2D() const 
	{ 
		return FGeodeticCoord2D(Longitude, Latitude); 
	}

	bool Equals(const FGeodeticCoord3D& other, double degreeVariance, double altitudeVariance)
	{
		if (FMath::Abs<double>(other.Longitude - Longitude) > degreeVariance)
		{
			return false;
		}

		if (FMath::Abs<double>(other.Latitude - Latitude) > degreeVariance)
		{
			return false;
		}

		if (FMath::Abs<double>(other.Altitude - Altitude) > altitudeVariance)
		{
			return false;
		}

		return true;
	}

	friend VH_GLOBEMATH_API FArchive& operator<<(FArchive& Ar, FGeodeticCoord3D& M)
	{
		Ar << M.Longitude << M.Latitude << M.Altitude << M.bIsAltitudeRelativeToGround;
		return Ar;
	}

	VH_GLOBEMATH_API bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
	{
		Ar << Longitude;
		Ar << Latitude;
		Ar << Altitude;
		Ar << bIsAltitudeRelativeToGround;

		return true;
	}

	FGeodeticCoord3D operator - (const FGeodeticCoord3D& other)
	{
		FGeodeticCoord3D result;
		result.Longitude = Longitude - other.Longitude;
		result.Latitude = Latitude - other.Latitude;
		result.Altitude = Altitude - other.Altitude;

		return result;
	}

	FGeodeticCoord3D operator + (const FGeodeticCoord3D& other)
	{
		FGeodeticCoord3D result;
		result.Longitude = Longitude + other.Longitude;
		result.Latitude = Latitude + other.Latitude;
		result.Altitude = Altitude + other.Altitude;

		return result;
	}
};

FORCEINLINE bool operator==(const FGeodeticCoord3D& a, const FGeodeticCoord3D& b)
{
	return (
		FMath::IsNearlyEqual(a.Longitude, b.Longitude) &&
		FMath::IsNearlyEqual(a.Latitude, b.Latitude) &&
		FMath::IsNearlyEqual(a.Altitude, b.Altitude) &&
		a.bIsAltitudeRelativeToGround == b.bIsAltitudeRelativeToGround
	);
}

FORCEINLINE bool operator!=(const FGeodeticCoord3D& a, const FGeodeticCoord3D& b)
{
	return !(a == b);
}

template<>
struct TStructOpsTypeTraits<FGeodeticCoord3D> : public TStructOpsTypeTraitsBase2<FGeodeticCoord3D>
{
	enum
	{
		WithNetSerializer = true
	};
};
