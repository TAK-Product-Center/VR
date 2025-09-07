// Required Includes
#include "Game_DTEDLibrary.h"
#include "Game.h"

// Engine Includes
#include "Misc/FileHelper.h"

#include <string>

#define TOSTRING(a) DTEDHelpers::ToString(a, sizeof(a) / sizeof(char))

namespace DTEDHelpers
{
	FString ToString(char charArray[], int32 arraySize)
	{
		std::string str = "";

		for (int32 i = 0; i < arraySize; i++)
		{
			str = str + charArray[i];
		}

		FString toReturn(str.c_str());

		return toReturn;
	}

	int16 ReadValue(const uint8 highByte, const uint8 lowByte)
	{
		// Data is stored as 2 byte characters (sign and magnitude)
		// with high byte first.  The high bit is the sign bit.  Check for
		// sign bit and then turn it off and set SIGN_VAL accordingly.
		int16 height = 0;
		int16 signVal = 1;
		uint8 nhbyte = highByte;

		if (highByte & ~0177)
		{
			// sign bit set
			nhbyte = highByte & 0177;
			signVal = -1;
		}

		height = (256 * static_cast<int16>(nhbyte) + static_cast<int16>(lowByte)) * signVal;

		return height;

		/*int16 blah = (int16)(((highByte & 0xFF) << 8) | (lowByte & 0xFF));
		
		double val = (1 - (2 * ((blah & 0x8000) >> 15))) * (blah & 0x7FFF);

		return (int16)val;*/
	}

	// returns distance between 2 points in meters
	// TODO: Replace with a call into VH_GlobeMath! This implementation doesn't handle an ellipsoid globe.
	double Distance(double lat1, double lon1, double lat2, double lon2)
	{ 
		double radius = 6378.137; // Radius of earth in KM
		double dLat = lat2 * PI / 180 - lat1 * PI / 180;
		double dLon = lon2 * PI / 180 - lon1 * PI / 180;
		double a = FMath::Sin(dLat / 2) * FMath::Sin(dLat / 2) + FMath::Cos(lat1 * PI / 180) * FMath::Cos(lat2 * PI / 180) * FMath::Sin(dLon / 2) * FMath::Sin(dLon / 2);
		double c = 2 * FMath::Atan2(FMath::Sqrt(a), FMath::Sqrt(1 - a));
		double d = radius * c;

		return d * 1000; // meters
	}
};

bool UGame_DTEDLibrary::LoadFile(const FString& filePath, TArray<TArray<int16>>& heightData, double& latitudePostSpacing, double& longitudePostSpacing)
{
	TArray<uint8> fileData;
	if (FFileHelper::LoadFileToArray(fileData, *filePath))
	{
		FUserHeaderLabel uhl;
		int32 sizeOfUHL = sizeof(uhl);

		if (fileData.Num() >= sizeOfUHL)
		{
			FMemory::Memcpy(&uhl, fileData.GetData(), sizeOfUHL);

			FString recognitionSentinel = TOSTRING(uhl.RecognitionSentinel);
			if (!recognitionSentinel.Equals(UHL_RECOGNITION_SENTINEL))
			{
				UE_LOG(Game, Warning, TEXT("-- invalid recognition sentinel in UHL | filePath: %s"), *filePath);
				return false;
			}

			FString fixedByStandard = TOSTRING(uhl.FixedByStandard);
			if (!fixedByStandard.Equals(UHL_FIXED_BY_STANDARD_BYTE))
			{
				UE_LOG(Game, Warning, TEXT("-- invalid fixed by standard byte in UHL | filePath: %s"), *filePath);
				return false;
			}

			// extract the data intervals for latitude and longitude
			int32 dataIntervalLatitude = FCString::Atoi(*TOSTRING(uhl.DataIntervalLatitude));
			int32 dataIntervalLongitude = FCString::Atoi(*TOSTRING(uhl.DataIntervalLongitude));

			latitudePostSpacing = dataIntervalLatitude / TENTHS_OF_SECONDS_PER_DEGREE;
			longitudePostSpacing = dataIntervalLongitude / TENTHS_OF_SECONDS_PER_DEGREE;

			int32 originLatitude = FCString::Atoi(*DTEDHelpers::ToString(uhl.OriginLatitude, 3));
			int32 originLongitude = FCString::Atoi(*DTEDHelpers::ToString(uhl.OriginLongitude, 3));

			if (uhl.OriginLatitude[7] == 'S')
			{
				originLatitude *= -1;
			}

			if (uhl.OriginLongitude[7] == 'W')
			{
				originLongitude *= -1;
			}

			latitudePostSpacing = DTEDHelpers::Distance(originLatitude, originLongitude, originLatitude + latitudePostSpacing, originLongitude);
			longitudePostSpacing = DTEDHelpers::Distance(originLatitude, originLongitude, originLatitude, originLongitude + longitudePostSpacing);

			// extract the number of latitude and longitude lines
			int32 numLatitudePosts = FCString::Atoi(*TOSTRING(uhl.NumberLatitudeLines));
			int32 numLongitudePosts = FCString::Atoi(*TOSTRING(uhl.NumberLongitudeLines));

			if (numLatitudePosts < 1 && numLongitudePosts < 1)
			{
				UE_LOG(Game, Warning, TEXT("-- UHL indicates empty dted file | filePath: %s"), *filePath);
				return false;
			}

			// add zeroed entries for each post
			heightData.Empty();
			for (int32 i = 0; i < numLongitudePosts; i++)
			{
				TArray<int16> latitudePosts;
				latitudePosts.AddZeroed(numLatitudePosts);

				heightData.Add(latitudePosts);
			}

			// find height at each post and add to heightData
			int32 offset = sizeof(uhl) + NUM_BYTES_IN_DSI + NUM_BYTES_IN_ACC;
			for (int32 longitudePost = 0; longitudePost < numLongitudePosts; longitudePost++)
			{
				offset += NUM_BYTES_COLUMN_HEADER;
				
				for (int32 latitudePost = 0; latitudePost < numLatitudePosts; latitudePost++)
				{
					TArray<uint8> values;
					values.AddZeroed(2);

					FMemory::Memcpy(values.GetData(), fileData.GetData() + offset, 2 * sizeof(uint8));
					offset += 2 * sizeof(uint8);

					int16 height = DTEDHelpers::ReadValue(values[0], values[1]);

					heightData[longitudePost][latitudePost] = height;
				}

				offset += NUM_BYTES_COLUMN_FOOTER;
			}

			return true;
		}
	}

	return false;
}
