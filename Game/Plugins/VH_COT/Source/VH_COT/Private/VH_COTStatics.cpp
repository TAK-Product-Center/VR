// Required Includes
#include "VH_COTStatics.h"
#include "VH_COT.h"

// Engine Includes
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "RenderingThread.h"
#include "Rendering/Texture2DResource.h"

// VH Plugin Includes
#include "Developer_Statics.h"

// Module Includes
#include "VH_GlobeMathStatics.h"
#include "VH_COTEvent.h"
#include "VH_COTDelegates.h"
#include "VH_COTManager.h"

#include <bitset>

UTexture2D* UVH_COTStatics::CreateTexture(const TArray<uint8>& imageBytes, EImageFormat imageFormat)
{
    IImageWrapperModule& imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

    auto imageWrapper = imageWrapperModule.CreateImageWrapper(imageFormat);
    if (imageWrapper->SetCompressed(imageBytes.GetData(), imageBytes.Num()))
    {
        TArray<uint8> uncompressedBGRA;
        if (imageWrapper->GetRaw(ERGBFormat::BGRA, 8, uncompressedBGRA))
        {
            UTexture2D* texture = UTexture2D::CreateTransient(imageWrapper->GetWidth(), imageWrapper->GetHeight(), PF_B8G8R8A8);

            void* textureData = texture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
            FMemory::Memcpy(textureData, uncompressedBGRA.GetData(), uncompressedBGRA.Num());
            texture->GetPlatformData()->Mips[0].BulkData.Unlock();

            texture->UpdateResource();

            return texture;
        }
    }

    UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTStatics::CreateTexture | could not create texture"));

    return nullptr;
}

void UVH_COTStatics::BroadcastCOTMessage(const FString& messageType)
{
	FVH_COTDelegates::OnCOTMessageReceived.Broadcast(messageType, FVariant());
}

FString UVH_COTStatics::GetISOTime(const FDateTime& dateTime)
{
	return dateTime.ToIso8601();
}

// converts ISO 8601 (2019-01-31T22:03:33Z) to FDateTime
FDateTime UVH_COTStatics::GetDateTime(const FString& cotTime)
{
	FDateTime dateTime;
	FDateTime::ParseIso8601(*cotTime, dateTime);

	return dateTime;
}

FString UVH_COTStatics::VariantToString(const FVariant& variant)
{
    switch (variant.GetType())
    {
        case EVariantTypes::Bool:
            return FString::Printf(TEXT("%d"), variant.GetValue<bool>());

        case EVariantTypes::Double:
            return FString::Printf(TEXT("%f"), variant.GetValue<double>());

        case EVariantTypes::Float:
            return FString::Printf(TEXT("%f"), variant.GetValue<float>());

        case EVariantTypes::Int32:
            return FString::Printf(TEXT("%d"), variant.GetValue<int32>());

        case EVariantTypes::Name:
            return variant.GetValue<FName>().ToString();

        case EVariantTypes::String:
            return variant.GetValue<FString>();

        default:
            UE_LOG(VH_COT, Warning, TEXT("UVH_COTStatics::VariantToString | variant type %d not implemented | returning empty string"), (int32)variant.GetType());
            break;
    }

    return TEXT("");
}

void UVH_COTStatics::PopulateVariant(FVariant& variant, const FString& valueString)
{
    switch (variant.GetType())
    {
        case EVariantTypes::Bool:
        {
            if (valueString.Equals(TEXT("1")) || valueString.Equals(TEXT("true"), ESearchCase::IgnoreCase))
            {
                variant = true;
            }
            else
            {
                variant = false;
            }
        }
        break;

        case EVariantTypes::Double:
        {
            variant = FCString::Atod(*valueString);
        }
        break;

        case EVariantTypes::Float:
        {
            variant = FCString::Atof(*valueString);
        }
        break;

        case EVariantTypes::Int32:
        {
            variant = FCString::Atoi(*valueString);
        }
        break;

        case EVariantTypes::Name:
        {
            variant = FName(*valueString);
        }
        break;

        case EVariantTypes::String:
        {
            variant = valueString;
        }
        break;

        default:
            UE_LOG(VH_COT, Warning, TEXT("UVH_COTStatics::PopulateVariant | variant type %d not implemented | not modifying passed in variant"), (int32)variant.GetType());
            break;
    }
}

FString UVH_COTStatics::ColorToHexAttribute(const FColor& color)
{
    // convert from RGBA (unreal) to ARGB (cot)
    FString hex = ToHex(color);

    uint32 unsignedInt = UDeveloper_Statics::HexToDecimal(hex);
    
    return FString::Printf(TEXT("%d"), (int32)unsignedInt);
}

FColor UVH_COTStatics::HexAttributeToColor(const FString& hexAttribute)
{ 
    int32 signedInt = FCString::Atoi(*hexAttribute);

    // get hex value as ARGB
    FString hex = UDeveloper_Statics::DecimalToHex(uint32(signedInt));

    return FromHex(hex);
}

FColor UVH_COTStatics::FromHex(const FString& hex)
{
	FColor initialColor = FColor::FromHex(hex);
	
	FColor color;
	color.A = initialColor.R;
	color.R = initialColor.G;
	color.G = initialColor.B;
	color.B = initialColor.A;

	return color;
};

FString UVH_COTStatics::ToHex(const FColor& color)
{
    return FString::Printf(TEXT("%02X%02X%02X%02X"), color.A, color.R, color.G, color.B);
}


FString UVH_COTStatics::ColorToDecimalAttribute(const FColor& color)
{
    FString hex = color.ToHex();
    hex = hex.Mid(0, hex.Len() - 2);

    return FString::Printf(TEXT("%d"), (int32)FParse::HexNumber(*hex) - 16777216);
}

FColor UVH_COTStatics::DecimalAttributeToColor(const FString& decimalAttribute)
{
    int32 decimal = FCString::Atoi(*decimalAttribute);
    decimal += 16777216;

    std::stringstream ss;
    ss << std::hex << decimal;

    FString hex = FString(ss.str().c_str());
    if (hex.Len() < 6)
    {
        auto numZeroes = 6 - hex.Len();
        for (auto i = 0; i < numZeroes; i++)
        {
            hex = TEXT("0") + hex;
        }
    }

    return FColor::FromHex(hex);
}

void UVH_COTStatics::CalculateRectangleAttributesAsDoubles(UVH_COTEvent* cotEvent, const FGeodeticCoord3D& center, double& lengthMeters, double& widthMeters, double& rotationDegrees)
{
	lengthMeters = 0;
	widthMeters = 0;
	rotationDegrees = 0;

    TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
    if (links.Num() != 4)
    {
        UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTStatics::CalculateRectangleLengthWidth() | attempt to calculate height length without 4 points | aborting"));

		return;
    }

	// comes in as:
	// 0 3
	// 1 2
	FGeodeticCoord2D geoPoint0 = LinkToCoordinate(links[0]).ToGeodeticCoord2D();  // nw
	FGeodeticCoord2D geoPoint1 = LinkToCoordinate(links[1]).ToGeodeticCoord2D();  // sw
	FGeodeticCoord2D geoPoint2 = LinkToCoordinate(links[2]).ToGeodeticCoord2D();  // se
	FGeodeticCoord2D geoPoint3 = LinkToCoordinate(links[3]).ToGeodeticCoord2D();  // ne

	// CalculateRectangleLengthWidth expects:
	// 3 0
	// 2 1
	CalculateRectangleLengthWidth(geoPoint3, geoPoint2, geoPoint1, geoPoint0, lengthMeters, widthMeters);

	// rotation

	// 3   0
	//    
	//   x->
	//     
	// 2   1
	double bearing_0to1 = UVH_GlobeMathStatics::CalculateSurfaceBearing(geoPoint0, geoPoint1);
	double range_0to1 = UVH_GlobeMathStatics::CalculateSurfaceDistance(geoPoint0, geoPoint1);
	FGeodeticCoord2D edgeCenter_01 = UVH_GlobeMathStatics::CalculateSurfaceDestination(geoPoint0, bearing_0to1, range_0to1 / 2);
	rotationDegrees = UVH_GlobeMathStatics::CalculateSurfaceBearing(center.ToGeodeticCoord2D(), edgeCenter_01);
}

// 3     0
//
//       l
// 
// 2  w  1
void UVH_COTStatics::CalculateRectangleLengthWidth(const FGeodeticCoord2D& geoPoint0, const FGeodeticCoord2D& geoPoint1, const FGeodeticCoord2D& geoPoint2, const FGeodeticCoord2D& geoPoint3, double& lengthMeters, double& widthMeters)
{
	// width
	double bearing_0to1 = UVH_GlobeMathStatics::CalculateSurfaceBearing(geoPoint0, geoPoint1);
	double range_0to1 = UVH_GlobeMathStatics::CalculateSurfaceDistance(geoPoint0, geoPoint1);
	FGeodeticCoord2D edgeCenter_01 = UVH_GlobeMathStatics::CalculateSurfaceDestination(geoPoint0, bearing_0to1, range_0to1 / 2);
	
	double bearing_2to3 = UVH_GlobeMathStatics::CalculateSurfaceBearing(geoPoint2, geoPoint3);
	double range_2to3 = UVH_GlobeMathStatics::CalculateSurfaceDistance(geoPoint2, geoPoint3);
	FGeodeticCoord2D edgeCenter_23 = UVH_GlobeMathStatics::CalculateSurfaceDestination(geoPoint2, bearing_2to3, range_2to3 / 2);
	
	lengthMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(edgeCenter_01, edgeCenter_23);

	// length
	double bearing_1to2 = UVH_GlobeMathStatics::CalculateSurfaceBearing(geoPoint1, geoPoint2);
	double range_1to2 = UVH_GlobeMathStatics::CalculateSurfaceDistance(geoPoint1, geoPoint2);
	FGeodeticCoord2D edgeCenter_12 = UVH_GlobeMathStatics::CalculateSurfaceDestination(geoPoint1, bearing_1to2, range_1to2 / 2);
	
	double bearing_3to0 = UVH_GlobeMathStatics::CalculateSurfaceBearing(geoPoint3, geoPoint0);
	double range_3to0 = UVH_GlobeMathStatics::CalculateSurfaceDistance(geoPoint3, geoPoint0);
	FGeodeticCoord2D edgeCenter_30 = UVH_GlobeMathStatics::CalculateSurfaceDestination(geoPoint3, bearing_3to0, range_3to0 / 2);
	
	widthMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(edgeCenter_12, edgeCenter_30);
}

FGeodeticCoord3D UVH_COTStatics::LinkToCoordinate(FXmlNode* link)
{
    FGeodeticCoord3D coordinate;

    FString latLongHAE = link->GetAttribute(TEXT("point"));
    if (!latLongHAE.IsEmpty())
	{
		TArray<FString> pointElements;
		latLongHAE.ParseIntoArray(pointElements, TEXT(","));
		if (pointElements.Num() == 2)
		{
			coordinate.Latitude = FCString::Atod(*pointElements[0]);
			coordinate.Longitude = FCString::Atod(*pointElements[1]);
			coordinate.Altitude = 9999999;
		}
		else if (pointElements.Num() == 3)
		{
			coordinate.Latitude = FCString::Atod(*pointElements[0]);
			coordinate.Longitude = FCString::Atod(*pointElements[1]);
			coordinate.Altitude = FCString::Atod(*pointElements[2]);
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTStatics::LinkToCoordinate | improper format: %s"), *latLongHAE);
		}
	}

    return coordinate;
}

FString UVH_COTStatics::GetLongLatHAE(const FGeodeticCoord3D& coordinate)
{
    return FString::Printf(TEXT("%.8Lf,%.8Lf,%.8Lf"), coordinate.Latitude, coordinate.Longitude, coordinate.Altitude);
}

FString UVH_COTStatics::GetNodeContent(FXmlNode* rootNode, const FString& pathToNode)
{
    if (rootNode != nullptr)
	{
        FXmlNode* node = rootNode;

		TArray<FString> parsed;
		pathToNode.ParseIntoArray(parsed, TEXT("\t"));

		for (int32 i = 0; i < parsed.Num(); i++)
		{
			if (i < parsed.Num() - 1)
			{
				if (FXmlNode* child = node->FindChildNode(parsed[i]))
				{
					node = child;
				}
                else
                {
                    return TEXT("");
                }
			}
			else
			{
                return node->GetContent();
			}
		}
	}

    return TEXT("");
}

double UVH_COTStatics::GetLinksDistanceMeters(UVH_COTEvent* cotEvent)
{
    double distanceMeters = 0;

    TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
    if (links.Num() >= 2)
    {
        for (int32 i = 1; i < links.Num(); i++)
        {
            FGeodeticCoord2D previousCoordinate = LinkToCoordinate(links[i - 1]).ToGeodeticCoord2D();
            FGeodeticCoord2D coordinate = LinkToCoordinate(links[i]).ToGeodeticCoord2D();

            distanceMeters += UVH_GlobeMathStatics::CalculateSurfaceDistance(previousCoordinate, coordinate);
        }
    }

    return distanceMeters;
}

FString UVH_COTStatics::GetParentCallsign(UVH_COTEvent* cotEvent)
{
    TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
    if (links.Num() > 0)
    {
        return links[0]->GetAttribute(TEXT("parent_callsign"));
    }

    return TEXT("");
}