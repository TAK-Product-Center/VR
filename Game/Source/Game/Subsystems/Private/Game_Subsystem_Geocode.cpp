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

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_Geocode::UGame_Subsystem_Geocode() :
	Key(TEXT("tOQxncutlw7D2OPRUKUE~ymAisUcQ9mCv-UhZxa0ueg~Aqn9_E5MQoJcntmFBgcSUFBeLP3zkVg7qe0vQPzUe-1Mi2cvgAJKQdbWDAVQZSKV"))
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
	FString url = FString::Printf(TEXT("http://dev.virtualearth.net/REST/v1/Locations?query=%s&maxRes=1&key=%s"), *FGenericPlatformHttp::UrlEncode(search), *Key);

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
				const TArray<TSharedPtr<FJsonValue>>* resourceSetsArrayPtr;
				if (jsonObject->TryGetArrayField(TEXT("resourceSets"), resourceSetsArrayPtr))
				{
					TArray<TSharedPtr<FJsonValue>> resourceSetsArray = *resourceSetsArrayPtr;
					for (int32 i = 0; i < resourceSetsArray.Num(); i++)
					{
						TSharedPtr<FJsonObject> resourceSetObject = resourceSetsArray[i]->AsObject();

						const TArray<TSharedPtr<FJsonValue>>* resourcesArrayPtr;
						if (resourceSetObject->TryGetArrayField(TEXT("resources"), resourcesArrayPtr))
						{
							TArray<TSharedPtr<FJsonValue>> resourcesArray = *resourcesArrayPtr;
							for (int32 j = 0; j < resourcesArray.Num(); j++)
							{
								TSharedPtr<FJsonObject> resourceObject = resourcesArray[j]->AsObject();

								const TSharedPtr<FJsonObject>* pointPtr;
								if (resourceObject->TryGetObjectField(TEXT("point"), pointPtr))
								{
									TSharedPtr<FJsonObject> point = *pointPtr;

									const TArray<TSharedPtr<FJsonValue>>* coordinatesArrayPtr;
									if (point->TryGetArrayField(TEXT("coordinates"), coordinatesArrayPtr))
									{
										TArray<TSharedPtr<FJsonValue>> coordinatesArray = *coordinatesArrayPtr;

										FGeodeticCoord2D coordinate;
										coordinate.Latitude = coordinatesArray[0]->AsNumber();
										coordinate.Longitude = coordinatesArray[1]->AsNumber();

										OnForwardGeocodeReceived.Broadcast(guid, coordinate);

										return;
									}
								}
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
	FString url = FString::Printf(TEXT("http://dev.virtualearth.net/REST/v1/Locations/%.8Lf,%.8Lf?key=%s"), coordinate.Latitude, coordinate.Longitude, *Key);

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
				const TArray<TSharedPtr<FJsonValue>>* resourceSetsArrayPtr;
				if (jsonObject->TryGetArrayField(TEXT("resourceSets"), resourceSetsArrayPtr))
				{
					TArray<TSharedPtr<FJsonValue>> resourceSetsArray = *resourceSetsArrayPtr;
					for (int32 i = 0; i < resourceSetsArray.Num(); i++)
					{
						TSharedPtr<FJsonObject> resourceSetObject = resourceSetsArray[i]->AsObject();

						const TArray<TSharedPtr<FJsonValue>>* resourcesArrayPtr;
						if (resourceSetObject->TryGetArrayField(TEXT("resources"), resourcesArrayPtr))
						{
							TArray<TSharedPtr<FJsonValue>> resourcesArray = *resourcesArrayPtr;
							for (int32 j = 0; j < resourcesArray.Num(); j++)
							{
								TSharedPtr<FJsonObject> resourceObject = resourcesArray[j]->AsObject();

								const TSharedPtr<FJsonObject>* addressPtr;
								if (resourceObject->TryGetObjectField(TEXT("address"), addressPtr))
								{
									TSharedPtr<FJsonObject> address = *addressPtr;

									FString formattedAddress;
									if (address->TryGetStringField(TEXT("formattedAddress"), formattedAddress))
									{
										OnReverseGeocodeReceived.Broadcast(guid, formattedAddress);
										UE_LOG(LogTemp, Warning, TEXT("-- reverse: %s"), *formattedAddress);
										return;
									}
								}
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

// ---------------------------------
// --- Implementation
// ---------------------------------


