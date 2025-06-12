// Required Includes
#include "Game_TileComponent_NGAGrid.h"

// VH Includes
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

UGame_TileComponent_NGAGrid::UGame_TileComponent_NGAGrid()
{
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_TileComponent_NGAGrid::ExecuteHelperThreadLogic()
{
	SetComponentStatus(EComponentStatus::HelperThreadStarted);

	Async(EAsyncExecution::ThreadPool, [this]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				SetComponentStatus(EComponentStatus::HelperThreadFinished);

				DestroyCounter.Decrement();
				return;
			}

			// check if created by tilemanager or as a result of multiple local tilesets creating multiple tile components
			if (FullPathToTileset.IsEmpty())
			{
				// get config properties
				if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
				{
					FString localTilesets = gameSettings->GetSettingString(FString::Printf(TEXT("nga_grid.LocalTilesets")));

					FString accessToken = gameSettings->GetSettingString(FString::Printf(TEXT("nga_grid.AccessToken")));

					FString assetID = gameSettings->GetSettingString(FString::Printf(TEXT("nga_grid.AssetID")));
					
					// populate RootNodes map with FXmlNode
					if (!localTilesets.IsEmpty())
					{
						// spawn component for each tileset.json; set FullPathToTileset
						InitializeForLocalTilesets(localTilesets);

						SetComponentStatus(EComponentStatus::HelperThreadFinished);
					}
					else if (!accessToken.IsEmpty() && !assetID.IsEmpty())
					{
						// pull tilset.json via Cesium's REST API
						InitializeForRemoteTileset(accessToken, assetID);
					}
				}
			}
			else
			{
				SetComponentStatus(EComponentStatus::HelperThreadFinished);
			}

			DestroyCounter.Decrement();
		});
}

void UGame_TileComponent_NGAGrid::PopulateComponentFromInfoArray(UGame_TileComponent* component, TArray<FString> assetInfo)
{
	Super::PopulateComponentFromInfoArray(component, assetInfo);

	if (component == nullptr)
	{
		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
			{
				component = terrainTile->AddTileComponent(TEXT("nga_grid"), tileManager->IDToTerrainSourceInfo["nga_grid"].ComponentClass);
			}
		}
	}
	
	UGame_TileComponent_NGAGrid* tileComponent = Cast<UGame_TileComponent_NGAGrid>(component);

	tileComponent->FullPathToTileset = assetInfo[0];

	if (assetInfo.Num() >= 3)
	{
		tileComponent->MinGeometricErrorWithinLOD = FCString::Atod(*assetInfo[1]);
		tileComponent->MaxGeometricErrorWithinLOD = FCString::Atod(*assetInfo[2]);

		if (assetInfo.Num() == 4)
		{
			bReverseVertOrder = FCString::Atoi(*assetInfo[3]) == 1;
		}
	}
	else
	{
		tileComponent->MinGeometricErrorWithinLOD = 5;
		tileComponent->MaxGeometricErrorWithinLOD = 60;
	}

	tileComponent->SetComponentStatus(EComponentStatus::HelperThreadFinished);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_TileComponent_NGAGrid::InitializeForRemoteTileset(const FString& accessToken, FString assetID)
{
	// todo ohg | parse to handle multiple assetIDs (similar to local tilesets)

	TArray<FString> tilesetInfo;
	assetID.ParseIntoArray(tilesetInfo, TEXT(";"));

	FullPathToTileset = FPaths::Combine(UGame_Statics::GetVTAKCommonAppDataPath(), TEXT("NGA_Grid"), tilesetInfo[0], TEXT("tileset.json"));

	PopulateComponentFromInfoArray(this, tilesetInfo);

	assetID = tilesetInfo[0];
	
	RESTAccessToken = accessToken;
	RESTBaseURL = TEXT("https://grid.nga.mil/grid/api/product/stream/");

	FString requestURL = RESTBaseURL + assetID;

	FHttpModule* http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
	request->SetURL(requestURL);
	request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *accessToken));
	request->SetVerb(TEXT("GET"));

	// bind callback
	request->OnProcessRequestComplete().BindLambda([this, assetID](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
		{
			if (!response.IsValid() || response->GetResponseCode() != 200)
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid NGA Grid credentials"));

				return;
			}

			if (bSucceeded)
			{
				FOnReceiveFile receiveFileDelegate;
				receiveFileDelegate.BindLambda([this](const FString& fullPathToFile)
					{
						SetComponentStatus(EComponentStatus::HelperThreadFinished);
					});

				RequestFile(FullPathToTileset, receiveFileDelegate);
			}
		});

	request->ProcessRequest();
}

void UGame_TileComponent_NGAGrid::RequestFile(const FString& fullPathToFile, FOnReceiveFile& receiveFileDelegate)
{
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

			FString uri;
			if (FPaths::GetPathLeaf(fullPathToFile).Equals(TEXT("tileset.json"), ESearchCase::IgnoreCase))
			{
				uri = FPaths::GetPathLeaf(FPaths::GetPath(fullPathToFile));
			}
			else
			{
				FString rootFolder = FString(TEXT("NGA_Grid/"));
				int32 rootFolderPos = fullPathToFile.Find(rootFolder);
				uri = fullPathToFile.Mid(rootFolderPos + rootFolder.Len());
			}

			request->SetURL(FPaths::Combine(RESTBaseURL, uri));
			request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *RESTAccessToken));
			request->SetVerb(TEXT("GET"));

			ReceiveFileDelegates.Add(fullPathToFile, receiveFileDelegate);

			tileManager->AddHTTPRequest(fullPathToFile, this, request);
		}
	}
}
