// Required Includes
#include "Game_VectorTile_MapBox.h"
#include "Game.h"

// VH Module Includes
#include "VH_COTManager.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_TileUtilities.h"
#include "Game_TileManager.h"
#include "Game_Statics.h"
#include "Game_ImportedMeshComponent.h"
#include "Game_VectorTile_Actor.h"

// Plugin Includes
#include "vtzero/vector_tile.hpp"


// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_VectorTile_MapBox::UGame_VectorTile_MapBox() :
	StreetsUrl(TEXT("https://api.mapbox.com/v4/mapbox.mapbox-streets-v8/")),
	Source(TEXT("MapBox")),
	SourceType(TEXT("vector-tile")),
	Status(EVectorTileLoadStatus::PendingTerrain)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.1f;
}


// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_VectorTile_MapBox::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(GetOwner()))
	{
		BindToTileManager();

		Task.VectorTileFinishedDelegate.BindUObject(this, &UGame_VectorTile_MapBox::OnVectorTileFinished);
	}
}

void UGame_VectorTile_MapBox::BeginDestroy()
{
	DestroyActors();

	Super::BeginDestroy();
}

void UGame_VectorTile_MapBox::ExecuteGameThreadLogic()
{
	Super::ExecuteGameThreadLogic();

	SetComponentStatus(EComponentStatus::GameThreadFinished);

	OnGameLogicCompletedGeneric.ExecuteIfBound();
}

void UGame_VectorTile_MapBox::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();

	SetComponentStatus(EComponentStatus::HelperThreadStarted);

	VectorTilePath = UGame_Statics::GetVTAKCommonAppDataPath() + TEXT("/VectorTiles/MapBox/");
	
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		AccessToken = gameSettings->GetSettingString(FString::Printf(TEXT("mapbox_vector_tile.MapBoxAccessToken")));
	}
	
	if (AccessToken.Len())
	{
		RequestAccess();
	}
	
	if (RequestsCounter.GetValue() <= 0)
	{
		SetComponentStatus(EComponentStatus::HelperThreadFinished);
	}
}

bool UGame_VectorTile_MapBox::GlobeReferenceScaleUpdated(const FVector& newScale3D)
{
	DestroyActors();
	return Super::GlobeReferenceScaleUpdated(newScale3D);
}

bool UGame_VectorTile_MapBox::SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel)
{
	DestroyActors();
	return Super::SetBoundsAndZoomVirtual(tileBounds, zoomLevel);
}

void UGame_VectorTile_MapBox::AddVectorTileActor(AGame_VectorTile_Actor* actor)
{
	if (IsValid(actor))
	{
		VectorTileActors.Add(actor);
	}

	check(VectorTileActors.Num() <= TileData.Num());
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_VectorTile_MapBox::RequestTiles()
{
	// Calculate tile boundaries (left-most, top-most, right-most, and bottom-most tiles)
	TileUtilities::GetTileFromGeodetic(GetNorthWestBound(), ZoomLevel, NorthWestTile);
	TileUtilities::GetTileFromGeodetic(GetSouthEastBound(), ZoomLevel, SouthEastTile);
	
	// Get the start/end tile ranges.  Using Min/Max prevents issues with inverted bounds.
	int32 nStartY	= FMath::Min<int32>(SouthEastTile.Value, NorthWestTile.Value);
	int32 nEndY		= FMath::Max<int32>(SouthEastTile.Value, NorthWestTile.Value);
	int32 nStartX	= FMath::Min<int32>(SouthEastTile.Key, NorthWestTile.Key);
	int32 nEndX		= FMath::Max<int32>(SouthEastTile.Key, NorthWestTile.Key);

	// After zoom level 15, the resolution of heightmap vs vector tiles vs satellite imagery is all different.
	// This little delta calculation keeps the vector tiles in the same resolution as the heightmap.
	int32 nZoomDelta = 1;
	if (ZoomLevel > 15)
	{
		nZoomDelta = ZoomLevel - 15;
	}

	// Create an HTTP Request for each tile
	for (int32 y = nStartY; y <= nEndY; y += nZoomDelta)
	{
		for (int32 x = nStartX; x <= nEndX; x += nZoomDelta)
		{
			const TPair<int32, int32> tile(x, y);
			if (!TileUtilities::TileExistsOnDisk(tile, ZoomLevel, Source, SourceType))
			{
				// The tile doesn't exist locally on the disk, so request the tile from MapBox
				// Pass the request to the tile manager, which will handle the rest for us

				FString tileIdentifier = TileUtilities::GetTileIdentifier(tile, ZoomLevel, Source, SourceType);
				UGame_TileManager::Get()->AddHTTPRequest(tileIdentifier, this, RequestVectorTile(x, y));
			}
			else
			{
				const FIntPoint tilePt = FIntPoint(tile.Key, tile.Value);
				FRawData& data = TileData.FindOrAdd(tilePt);
				if (data.Data.IsEmpty() && !TileUtilities::ReadTileFromDisk(tile, ZoomLevel, Source, SourceType, data.Data))
				{
					TileData.Remove(tilePt);
				}
			}
		}
	}
}

void UGame_VectorTile_MapBox::OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	RequestsCounter.Decrement();
	DestroyCounter.Decrement();

	bool bValid = true;

	if (response.IsValid())
	{
		const FString sContentType = response->GetContentType();
		if (response->GetContentType().Equals(TEXT("application/json; charset=utf-8")) ||
			response->GetContentType().Equals(TEXT("text/html")))
		{
			UE_LOG(Game, Warning, TEXT("A vector tile does not exist at: %s | %s"), *identifier, *response->GetContentAsString());
			bValid = false;
		}

		if (bValid)
		{
			TArray<FString> parsedID;
			request->GetHeader(TEXT("email")).ParseIntoArray(parsedID, TEXT("."), false);

			const TPair<int32, int32> tile(FCString::Atoi(*parsedID[0]), FCString::Atoi(*parsedID[1]));

			TArray<uint8>& content = const_cast<TArray<uint8>&>(response->GetContent());
			TileUtilities::WriteTileToDisk(tile, ZoomLevel, Source, SourceType, content);

			TileData.FindOrAdd(FIntPoint(tile.Key, tile.Value), content);
		}
	}
	else
	{
		bValid = false;
		UE_LOG(Game, Verbose, TEXT("UGame_VectorTile_MapBox::OnHTTPRequestComplete() | Request failed."));
	}

	if (RequestsCounter.GetValue() <= 0)
	{
		SetComponentStatus(EComponentStatus::HelperThreadFinished);
	}
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> UGame_VectorTile_MapBox::RequestVectorTile(int32 tileX, int32 tileY)
{
	RequestsCounter.Increment();
	DestroyCounter.Increment();

	FString url = StreetsUrl + FString::Printf(TEXT("%d/%d/%d.vector.pbf?access_token=%s"), ZoomLevel, tileX, tileY, *AccessToken);

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = FHttpModule::Get().CreateRequest();
	request->SetURL(url);
	request->AppendToHeader(TEXT("email"), FString::Printf(TEXT("%d.%d"), tileX, tileY));
	request->SetVerb(TEXT("GET"));
	return request;
}

void UGame_VectorTile_MapBox::RequestAccess()
{
	// MapBox URL to request access to their tile database
	const FString sUrl = TEXT("https://api.mapbox.com/tokens/v2?access_token=") + AccessToken;

	// Build a request object using the URL
	FHttpRequestPtr request = FHttpModule::Get().CreateRequest();
	request->SetVerb(TEXT("GET"));
	request->SetURL(sUrl);

	request->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
	{
		RequestsCounter.Decrement();
		DestroyCounter.Decrement();

		if (response.IsValid())
		{
			FString content = response.Get()->GetContentAsString();
			if (content.Contains("TokenValid"))
			{
				// The token is valid!
				RequestTiles();
			}
			else if (content.Contains(TEXT("TokenInvalid")))
			{
				SetComponentStatus(EComponentStatus::HelperThreadFinished);
				UE_LOG(Game, Error, TEXT("UGame_VectorTile_MapBox::RequestAccess() | MapBox access token is invalid."));
			}
			else if (content.Contains("TokenMalformed"))
			{
				SetComponentStatus(EComponentStatus::HelperThreadFinished);
				UE_LOG(Game, Error, TEXT("UGame_VectorTile_MapBox::RequestAccess() | MapBox access token is malformed!  Check the format and try again."));
			}
			else
			{
				SetComponentStatus(EComponentStatus::HelperThreadFinished);
				UE_LOG(Game, Error, TEXT("UGame_VectorTile_MapBox::RequestAccess() | Unknown issue.  Unable to validate the MapBox access token."));
			}
		}
		else
		{
			SetComponentStatus(EComponentStatus::HelperThreadFinished);
			UE_LOG(Game, Error, TEXT("UGame_VectorTile_MapBox::RequestAccess() | Request failed."));
		}

		if (RequestsCounter.GetValue() <= 0)
		{
			SetComponentStatus(EComponentStatus::HelperThreadFinished);
		}
	});

	RequestsCounter.Increment();
	DestroyCounter.Increment();

	request->ProcessRequest();
}

void UGame_VectorTile_MapBox::DestroyActors()
{
	Task.StopThread();

	// To prevent tiles from being loaded from previous terrain updates, stop the terrain timer so it can be reset later.
	if (IsValid(GetWorld()) && GetWorld()->GetTimerManager().TimerExists(TerrainTimerHandle))
	{
		GetWorld()->GetTimerManager().ClearTimer(TerrainTimerHandle);
	}

	// Destroy all actors
	if (IsValid(GetWorld()))
	{
		const int32 nNumActors = VectorTileActors.Num();
		for (int32 i = 0; i < nNumActors; ++i)
		{
			if (IsValid(VectorTileActors[i]))
			{
				VectorTileActors[i]->Destroy();
			}
		}

		VectorTileActors.Empty();

		// Restart the terrain update timer
		GetWorld()->GetTimerManager().SetTimer(TerrainTimerHandle, this, &UGame_VectorTile_MapBox::PeriodicCheckLOD, 0.5f, true);
	}
}

void UGame_VectorTile_MapBox::HandleTerrainUpdate()
{
	Status = EVectorTileLoadStatus::PendingTerrain;

	DestroyActors();
}

void UGame_VectorTile_MapBox::PeriodicCheckLOD()
{
	// Need to wait until the terrain is loaded before spawning vector tiles since vector tile data relies on terrain elevation.
	if (Status == EVectorTileLoadStatus::PendingTerrain)
	{
		UGame_TileManager* pTileManager = UGame_TileManager::Get();
		if (IsValid(pTileManager))
		{
			if (pTileManager->IsEnabled())
			{
				// Not pending means the terrain is ready
				if (!pTileManager->PendingTiles() && IsValid(GetWorld()))
				{
					DestroyActors();

					// Time to queue the vector tiles for processing on a background thread

					Status = EVectorTileLoadStatus::LoadingTiles;

					for (TMap<FIntPoint, FRawData>::TIterator iter(TileData); iter && Status == EVectorTileLoadStatus::LoadingTiles; ++iter)
					{
						Task.QueueTile(iter.Key(), ZoomLevel, iter.Value().Data);
					}

					// All tiles have been added, now start the task to begin processing
					Task.StartThread();
				}
			}
		}
	}
}

void UGame_VectorTile_MapBox::OnVectorTileFinished(AGame_VectorTile_Actor* actor)
{
	AddVectorTileActor(actor);
}

void UGame_VectorTile_MapBox::BindToTileManager()
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->OnTerrainUpdate.AddDynamic(this, &UGame_VectorTile_MapBox::HandleTerrainUpdate);
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_VectorTile_MapBox::BindToTileManager, 0.5);
	}
}
