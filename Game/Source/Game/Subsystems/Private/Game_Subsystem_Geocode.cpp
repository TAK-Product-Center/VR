// Required Includes
#include "Game_Subsystem_Geocode.h"
#include "Game.h"

// Engine Includes
#include "Misc/Guid.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "GenericPlatform/GenericPlatformHttp.h"
#include "Engine/GameInstance.h"
#include "Serialization/JsonReader.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonValue.h"
#include "Engine/World.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"
#include "Developer_Statics.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_Geocode::UGame_Subsystem_Geocode()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Subsystem_Geocode* UGame_Subsystem_Geocode::Get()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		if (UGameInstance* gameInstance = world->GetGameInstance())
		{
			return gameInstance->GetSubsystem<UGame_Subsystem_Geocode>();
		}
	}

	return nullptr;
}

// ---------------------------------
// --- API
// ---------------------------------

FString UGame_Subsystem_Geocode::ForwardGeocode(const FString& search)
{
	FString accessToken = TEXT("");
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		accessToken = gameSettings->GetSettingString(TEXT("mapboxGeocodeToken"));
	}

	FString url = FString::Printf(TEXT("https://api.mapbox.com/search/geocode/v6/forward?q=%s&access_token=%s"), *FGenericPlatformHttp::UrlEncode(search), *accessToken);

	FHttpModule* http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
	request->SetURL(url);
	request->SetVerb(TEXT("GET"));

	FString guid = FGuid::NewGuid().ToString();

	request->OnProcessRequestComplete().BindLambda([this, guid](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
	{
		if (bSucceeded)
		{
			TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*response->GetContentAsString());

			TSharedPtr<FJsonObject> jsonObject;
			if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
			{
				const TArray<TSharedPtr<FJsonValue>>* featuresArrayPtr;
				if (jsonObject->TryGetArrayField(TEXT("features"), featuresArrayPtr))
				{
					TArray<TSharedPtr<FJsonValue>> featuresArray = *featuresArrayPtr;
					for (int32 i = 0; i < featuresArray.Num(); i++)
					{
						TSharedPtr<FJsonObject> featuresObject = featuresArray[i]->AsObject();

						const TSharedPtr<FJsonObject>* geometryPtr;
						if (featuresObject->TryGetObjectField(TEXT("geometry"), geometryPtr))
						{
							TSharedPtr<FJsonObject> geometry = *geometryPtr;

							const TArray<TSharedPtr<FJsonValue>>* coordinatesArrayPtr;
							if (geometry->TryGetArrayField(TEXT("coordinates"), coordinatesArrayPtr))
							{
								TArray<TSharedPtr<FJsonValue>> coordinatesArray = *coordinatesArrayPtr;

								FGeodeticCoord2D coordinate;
								coordinate.Longitude = coordinatesArray[0]->AsNumber();
								coordinate.Latitude = coordinatesArray[1]->AsNumber();

								OnForwardGeocodeReceived.Broadcast(guid, coordinate);

								return;
							}
						}
					}
				}
			}
		}
	});

	request->ProcessRequest();

	return guid;
}

FString UGame_Subsystem_Geocode::ReverseGeocode(const FGeodeticCoord2D& coordinate)
{
	FString accessToken = TEXT("");
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		accessToken = gameSettings->GetSettingString(TEXT("mapboxGeocodeToken"));
	}

	FString url = FString::Printf(TEXT("https://api.mapbox.com/search/geocode/v6/reverse?longitude=%.8Lf&latitude=%.8Lf&access_token=%s"), coordinate.Longitude, coordinate.Latitude, *accessToken);

	FHttpModule* http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
	request->SetURL(url);
	request->SetVerb(TEXT("GET"));

	FString guid = FGuid::NewGuid().ToString();

	request->OnProcessRequestComplete().BindLambda([this, guid](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
	{
		if (bSucceeded)
		{
			TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*response->GetContentAsString());

			TSharedPtr<FJsonObject> jsonObject;
			if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
			{
				const TArray<TSharedPtr<FJsonValue>>* featuresArrayPtr;
				if (jsonObject->TryGetArrayField(TEXT("features"), featuresArrayPtr))
				{
					TArray<TSharedPtr<FJsonValue>> featuresArray = *featuresArrayPtr;
					for (int32 i = 0; i < featuresArray.Num(); i++)
					{
						TSharedPtr<FJsonObject> featuresObject = featuresArray[i]->AsObject();

						const TSharedPtr<FJsonObject>* propertiesPtr;
						if (featuresObject->TryGetObjectField(TEXT("properties"), propertiesPtr))
						{
							TSharedPtr<FJsonObject> properties = *propertiesPtr;

							FString address;
							if (properties->TryGetStringField(TEXT("full_address"), address))
							{
								OnReverseGeocodeReceived.Broadcast(guid, address);

								return;
							}
						}
					}
				}
			}
		}
	});

	request->ProcessRequest();

	return guid;
}