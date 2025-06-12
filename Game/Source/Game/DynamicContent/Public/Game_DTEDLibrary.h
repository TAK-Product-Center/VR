#pragma once

#include "Game.h"

#include "Game_DTEDLibrary.generated.h"

// copied heavily from https://github.com/doughodson/OpenEaagles/blob/master/src/terrain/dted/DtedFile.cpp

USTRUCT()
struct FUserHeaderLabel
{
	GENERATED_BODY()

	// should be UHL
	char RecognitionSentinel[3];

	// should be 1
	char FixedByStandard[1];

	// SW corner DDDMMSSH
	char OriginLongitude[8];

	// SW corner DDDMMSSH
	char OriginLatitude[8];

	// tenths of seconds
	char DataIntervalLongitude[4];

	// tenths of seconds
	char DataIntervalLatitude[4];

	// meters
	char AbsoluteVerticalAccuracy[4];

	// S: secret, C: confidential, U: unclassified, R: restricted
	char SecurityCode[3];

	// defined by producer, may be blank
	char UniqueRefNumber[12];

	// longitude lines in a full cell
	char NumberLongitudeLines[4];

	// latitude lines in a full cell
	char NumberLatitudeLines[4];

	// 0: single, 1: multiple
	char MultipleAccuracy[1];

	char ReservedFuture[24];
};

// DTED column record header
struct dtedColumnHeader
{
	unsigned char recognition_sentinel[1]; // 252(base 8) = 170
	char sequential_count[3];              // count of block within file, starting at 0
	char longitude_count[2];               // longitude index
	char latitude_count[2];                // latitude index
};
// DTED column record trailer
struct dtedColumnFooter
{
	unsigned char checksum[4];             // sum of bytes within block
};

static const unsigned char  DATA_RECOGNITION_SENTINEL = 170; // 252 base 8

static const FString UHL_RECOGNITION_SENTINEL = TEXT("UHL");

static const FString UHL_FIXED_BY_STANDARD_BYTE = TEXT("1");

static const double TENTHS_OF_SECONDS_PER_DEGREE = 36000.0;

static const int32 NUM_BYTES_IN_DSI = 648;

static const int32 NUM_BYTES_IN_ACC = 2700;

static const int32 NUM_BYTES_COLUMN_HEADER = 8;

static const int32 NUM_BYTES_COLUMN_FOOTER = 4;

UCLASS()
class GAME_API UGame_DTEDLibrary : public UObject
{
	GENERATED_BODY()

public:
	// post spacing in meters
	static bool LoadFile(const FString& filePath, TArray<TArray<int16>>& heightData, double& latitudePostSpacing, double& longitudePostSpacing);
};