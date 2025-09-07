#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "UObject/SoftObjectPtr.h"

// Generated Includes
#include "Game_HelpVideo.generated.h"

class UTexture2D;

 // stores metadata about help videos
UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_HelpVideo : public UObject
{
	GENERATED_BODY()


	// ---------------------
	// --- Variables
	// ---------------------

public:
	// full local path to video file
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LocalFileLocation;

	// url to video stream
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RemoteFileLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> IconTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DurationSeconds;
};
