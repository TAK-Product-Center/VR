#pragma once

// Parent Includes
#include "UObject/Object.h"

// Module Includes
#include "VH_KmlDocument.h"
#include "VH_KmlFeature.h"
#include "kml/dom.h"

// Generated Includes
#include "VH_KmlInfo.generated.h"

class FKmlGeometry;
class FKmlPlacemark;
struct FGeodeticCoord3D;

UCLASS(BlueprintType, Config = "VH_FileIO")
class VH_FILEIO_KML_API UVH_KmlInfo : public UObject
{
    GENERATED_BODY()


    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|KmlInfo")
    FString FullPathToFile;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|KmlInfo")
    TMap<FName, FString> XmlNSMap;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|KmlInfo")
    bool bIsValid;

private:
    kmldom::KmlPtr KmlRoot;

    FKmlDocument KmlDocument;


    // ---------------------------------
    // --- Constructors
    // ---------------------------------

public:
    UVH_KmlInfo();

    
    // ---------------------------------
    // --- Static Functions
    // ---------------------------------

public:
    UFUNCTION(BlueprintCallable, Category = "VhFileIO|Kml", meta = (DisplayName = "VH Create KmlInfo"))
    static UVH_KmlInfo* Create(const FString& fullPathToFileArg);

    static UVH_KmlInfo* CreateFromString(const FString& kml);


    // ---------------------------------
    // --- API
    // ---------------------------------

public:
    UFUNCTION(BlueprintCallable, Category = "VhFileIO|Kml")
    bool Parse(const FString& kmlText);

    FKmlDocument& GetKmlDocument();

    int32 GetAllFeatures(TArray<FKmlFeature*>& featureList, EKmlElementType type, bool bRecursive);

    bool GetCenterCoordinate(FGeodeticCoord3D& geodeticCoordinate);

    bool GetCenterCoordinate(FKmlGeometry* kmlGeometry, FKmlPlacemark* kmlPlacemark, FGeodeticCoord3D& centerCoord);

    void LogDump() const;
};
