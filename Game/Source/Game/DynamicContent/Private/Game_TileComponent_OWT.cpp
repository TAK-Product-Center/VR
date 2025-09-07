// Required Includes
#include "Game_TileComponent_OWT.h"
#include "Game.h"

// Engine Includes
#include "Serialization/JsonSerializer.h"
#include "Misc/Paths.h"

// VH Module Includes
#include "VH_COTManager.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_TileManager.h"
#include "Game_Statics.h"
#include "Game_TerrainTile.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TileComponent_OWT::UGame_TileComponent_OWT()
{
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_TileComponent_OWT::ExecuteHelperThreadLogic()
{
	SetComponentStatus(EComponentStatus::HelperThreadStarted);

	// check if created by tilemanager or as a result of multiple tilesets creating multiple tile components
	if (FullPathToTileset.IsEmpty() && AssetID.IsEmpty())
	{
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			if (UGame_TileManager* tileManager = UGame_TileManager::Get())
			{
				// get config properties
				TArray<FString> activeIDs;
				tileManager->GetActiveComponentIDs(activeIDs);

				if (activeIDs.Contains(TEXT("3dtiles_local")))
				{
					FString localTilesets = gameSettings->GetSettingString(FString::Printf(TEXT("3dtiles_local.Assets")));

					if (!localTilesets.IsEmpty())
					{
						// spawn component for each tileset.json; set FullPathToTileset
						InitializeForLocalTilesets(localTilesets);
					}
				}

				if (activeIDs.Contains(TEXT("3dtiles_cesium")))
				{
					FString accessToken = gameSettings->GetSettingString(FString::Printf(TEXT("3dtiles_cesium.CesiumAccessToken")));

					FString assetID = gameSettings->GetSettingString(FString::Printf(TEXT("3dtiles_cesium.Assets")));
						
					if (!accessToken.IsEmpty() && !assetID.IsEmpty())
					{
						// spawn component for each requested remote asset; set AssetID
						InitializeForRemoteTileset(accessToken, assetID);
					}
				}
			}
		}
	}
	else
	{
		SetComponentStatus(EComponentStatus::HelperThreadFinished);
	}
}

void UGame_TileComponent_OWT::PopulateComponentFromInfoArray(UGame_TileComponent* component, TArray<FString> assetInfo)
{
	Super::PopulateComponentFromInfoArray(component, assetInfo);

	if (component == nullptr)
	{
		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
			{
				component = terrainTile->AddTileComponent(TEXT("3dtiles_local"), tileManager->IDToTerrainSourceInfo["3dtiles_local"].ComponentClass);
			}
		}
	}
	
	UGame_TileComponent_OWT* tileComponent = Cast<UGame_TileComponent_OWT>(component);
	
	tileComponent->FullPathToTileset = assetInfo[0];
	tileComponent->LODMeters = FCString::Atod(*assetInfo[1]);
	tileComponent->MinGeometricErrorWithinLOD = FCString::Atod(*assetInfo[2]);
	tileComponent->MaxGeometricErrorWithinLOD = FCString::Atod(*assetInfo[3]);
	tileComponent->GeometricErrorBeyondLOD = FCString::Atod(*assetInfo[4]);
	tileComponent->bReverseVertOrder = assetInfo[5].Equals(TEXT("1"));

	tileComponent->SetComponentStatus(EComponentStatus::HelperThreadFinished);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_TileComponent_OWT::InitializeForRemoteTileset(const FString& accessToken, FString assetIDs)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
		{
			TArray<FString> assets;
			assetIDs.ParseIntoArray(assets, TEXT("|"));
			for (int32 i = 0; i < assets.Num(); i++)
			{
				TArray<FString> assetInfo;
				assets[i].ParseIntoArray(assetInfo, TEXT(";"));

				UGame_TileComponent_OWT* tileComponent = nullptr;
				if (i == 0 && FullPathToTileset.IsEmpty())  // make sure [this] isn't already in use for local 3DTile dataset
				{
					tileComponent = this;
				}
				else
				{
					tileComponent = Cast<UGame_TileComponent_OWT>(terrainTile->AddTileComponent(TEXT("3dtiles_cesium"), tileManager->IDToTerrainSourceInfo["3dtiles_cesium"].ComponentClass));
				}

				tileComponent->AssetID = assetInfo[0];
				tileComponent->LODMeters = FCString::Atod(*assetInfo[1]);
				tileComponent->MinGeometricErrorWithinLOD = FCString::Atod(*assetInfo[2]);
				tileComponent->MaxGeometricErrorWithinLOD = FCString::Atod(*assetInfo[3]);
				tileComponent->GeometricErrorBeyondLOD = FCString::Atod(*assetInfo[4]);
				tileComponent->bReverseVertOrder = assetInfo[5].Equals(TEXT("1"));

				tileComponent->MakeInitialRequest();
			}
		}
	}
}

void UGame_TileComponent_OWT::MakeInitialRequest()
{
	if (AssetID.IsEmpty())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::MakeInitialRequest | AssetID is empty | aborting"));

		return;
	}

	FString accessToken = TEXT("");
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		accessToken = gameSettings->GetSettingString(FString::Printf(TEXT("3dtiles_cesium.CesiumAccessToken")));
	}

	if (accessToken.IsEmpty())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::MakeInitialRequest | accessToken is empty | aborting"));

		return;
	}

	SetComponentStatus(EComponentStatus::HelperThreadStarted);

	FullPathToTileset = FPaths::Combine(UGame_Statics::GetVTAKCommonAppDataPath(), TEXT("3DTiles"), AssetID, TEXT("tileset.json"));

	FString requestURL = FString::Printf(TEXT("https://api.cesium.com/v1/assets/%s/endpoint"), *AssetID);

	FHttpModule* http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
	request->SetURL(requestURL);
	request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *accessToken));
	request->SetVerb(TEXT("GET"));

	// bind callback
	request->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
	{
		if (!response.IsValid() || response->GetResponseCode() != 200)
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid cesium credentials"));

			return;
		}

		TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*response->GetContentAsString());

		TSharedPtr<FJsonObject> jsonObject;
		if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
		{
			FString accessToken;
			FString url;

			if (!jsonObject->TryGetStringField(TEXT("url"), url))
			{
				const TSharedPtr<FJsonObject>* optionsObjectPtr = nullptr;
				if (jsonObject->TryGetObjectField(TEXT("options"), optionsObjectPtr))
				{
					jsonObject = *optionsObjectPtr;
					jsonObject->TryGetStringField(TEXT("url"), url);
				}
			}

			if (!url.IsEmpty())
			{
				if (jsonObject->TryGetStringField(TEXT("accessToken"), accessToken))
				{
					RESTBaseURL = FPaths::GetPath(url);
					RESTAccessToken = accessToken; // todo ohg | make this static when add support for multiple assetIDs
				}
				else
				{
					RESTBaseURL = url;
					RESTAccessToken = TEXT("");
				}
				
				FOnReceiveFile receiveFileDelegate;
				receiveFileDelegate.BindLambda([this](const FString& fullPathToFile)
				{
					SetComponentStatus(EComponentStatus::HelperThreadFinished);
				});

				RequestFile(FullPathToTileset, receiveFileDelegate);
			}
		}
	});

	request->ProcessRequest();
}

void UGame_TileComponent_OWT::RequestFile(const FString& fullPathToFile, FOnReceiveFile& receiveFileDelegate)
{
	if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
	{
		if (terrainTile->GetTileStatus() == ETileStatus::ReadyForDestroy)
		{
			return;
		}
	}
	
	if (FPaths::FileExists(fullPathToFile) || RESTBaseURL.IsEmpty())
	{
		receiveFileDelegate.ExecuteIfBound(fullPathToFile);
	}
	else
	{
		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			FHttpModule* http = &FHttpModule::Get();

			TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();

			if (!RESTAccessToken.IsEmpty())
			{
				request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *RESTAccessToken));
			}

			FString pathToStrip = FPaths::GetPath(FullPathToTileset);
			FString uri = fullPathToFile.Replace(*pathToStrip, TEXT(""));

			// special case for google tiles
			if (RESTBaseURL.Contains(TEXT("tile.googleapis.com")))
			{
				if (uri.EndsWith(TEXT("tileset.json")))
				{
					uri = RESTBaseURL;
				}
				else
				{
					TArray<FString> parsedArray;
					RESTBaseURL.ParseIntoArray(parsedArray, TEXT("?"));

					if (parsedArray.Num() == 2)
					{
						if (!Session.IsEmpty())
						{
							if (uri.StartsWith(TEXT("/")))
							{
								uri = uri.RightChop(1);
							}

							if (FString* actualURI = GoogleFilenames.Find(uri))
							{
								uri = *actualURI;
							}
							
							uri = FString::Printf(TEXT("https://tile.googleapis.com%s?%s&%s"), *uri, *Session, *parsedArray[1]);
						}
						else
						{
							uri = FString::Printf(TEXT("https://tile.googleapis.com%s&%s"), *uri, *parsedArray[1]);
						}
					}
				}
			}
			else
			{
				// normal case
				uri = FPaths::Combine(RESTBaseURL, uri);
			}
			
			request->SetURL(uri);
			
			request->SetVerb(TEXT("GET"));

			ReceiveFileDelegates.Add(fullPathToFile, receiveFileDelegate);
			
			tileManager->AddHTTPRequest(fullPathToFile, this, request);
		}
	}
}
