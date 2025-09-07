#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "IImageWrapper.h"
#include "Misc/Variant.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "VH_COTStatics.generated.h"

class UVH_COTEvent;
class FXmlNode;
class UTexture2D;

UCLASS()
class VH_COT_API UVH_COTStatics : public UObject
{
    GENERATED_BODY()

public:
    static UTexture2D* CreateTexture(const TArray<uint8>& imageBytes, EImageFormat imageFormat);

	UFUNCTION(BlueprintCallable)
	static void BroadcastCOTMessage(const FString& messageType);

    // @brief converts FDateTime to ISO 8601 (2019-01-31T22:03:33Z)
    static FString GetISOTime(const FDateTime& dateTime);
    
    // converts ISO 8601 (2019-01-31T22:03:33Z) to FDateTime
    static FDateTime GetDateTime(const FString& cotTime);

    static FString VariantToString(const FVariant& variant);

    static void PopulateVariant(FVariant& variant, const FString& valueString);

    /// @brief cast to hex, to uint32, to in32, then FString
    UFUNCTION(BlueprintPure)
    static FString ColorToHexAttribute(const FColor& color);

    /// @brief to cast to int32, to uint32, to hex, then color
    UFUNCTION(BlueprintPure)
    static FColor HexAttributeToColor(const FString& hexAttribute);

    /// @brief expects AARRGGBB
    UFUNCTION(BlueprintPure)
    static FColor FromHex(const FString& hex);

    /// @brief gives AARRGGBB
    UFUNCTION(BlueprintPure)
    static FString ToHex(const FColor& color);

    /// @brief typical way to pass colors in cots (particularly strokeColor)
    UFUNCTION(BlueprintPure)
    static FString ColorToDecimalAttribute(const FColor& color);

    /// @brief typical way to pass colors in cots (particularly strokeColor)
    UFUNCTION(BlueprintPure)
    static FColor DecimalAttributeToColor(const FString& decimalAttribute);

    static void CalculateRectangleAttributesAsDoubles(UVH_COTEvent* cotEvent, const FGeodeticCoord3D& center, double& lengthMeters, double& widthMeters, double& rotationDegrees);

	static void CalculateRectangleLengthWidth(const FGeodeticCoord2D& geoPoint0, const FGeodeticCoord2D& geoPoint1, const FGeodeticCoord2D& geoPoint2, const FGeodeticCoord2D& geoPoint3, double& lengthMeters, double& widthMeters);

    /// @brief returns coordinate of link
    static FGeodeticCoord3D LinkToCoordinate(FXmlNode* link);

    /// @brief sets coordinate to coordinate of link
    static FString GetLongLatHAE(const FGeodeticCoord3D& coordinate);

    static FString GetNodeContent(FXmlNode* rootNode, const FString& pathToNode);

    UFUNCTION(BlueprintCallable)
    static double GetLinksDistanceMeters(UVH_COTEvent* cotEvent);

    UFUNCTION(BlueprintCallable)
    static FString GetParentCallsign(UVH_COTEvent* cotEvent);

    UFUNCTION(BlueprintPure)
    static bool IsPolylineClosed(UVH_COTEvent* cotEvent);

	UFUNCTION(BlueprintCallable)
	static void SetPolylineClosed(UVH_COTEvent* cotEvent, bool bClosed);

    static FString SanitizeRawCOTAttributes(const FString& inCot);
};
