#pragma once

// Parent Includes
#include "UObject/Object.h"

// Generated Includes
#include "VH_ImageLoader.generated.h"

class UTexture2D;

/*
Utility class for asynchronously loading an image into a texture.
Allows Blueprint scripts to request asynchronous loading of an image and be notified when loading is complete.
*/
UCLASS(BlueprintType)
class VH_FILEIO_API UVH_ImageLoader : public UObject
{
    GENERATED_BODY()

    
    // ---------------------------------
    // --- Delegates
    // ---------------------------------

private:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImageLoadCompleted, UTexture2D*, Texture);


    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
    UPROPERTY(BlueprintAssignable)
    FOnImageLoadCompleted OnLoadCompleted;


    // ---------------------------------
    // --- API
    // ---------------------------------

public:
    /**
	Loads an image file from disk into a texture. This will block the calling thread until completed. Scales to nearest power of 2.
	@return A texture created from the loaded image file.
	*/
    UFUNCTION(BlueprintCallable)
    static bool LoadImageFromDisk(const FString& imagePath, FVector2D& scaledDimensions, FVector2D& originalDimensions, TArray<uint8>& pixelData);

    UFUNCTION(BlueprintCallable)
    static bool LoadImageFromDB(const FString& dbPath, const FString& dbQuery, const FString& blobColumn, TArray<uint8>& pixelData);
};
