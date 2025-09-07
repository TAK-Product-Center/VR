// Required Includes
#include "Game_MeshComponent_Mapbox.h"
#include "Game.h"

// Engine Includes
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Async/Async.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_TerrainTile.h"
#include "Game_TileUtilities.h"
#include "Game_TileManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MeshComponent_Mapbox::UGame_MeshComponent_Mapbox()
{
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

// todo ohg | first time this is called the method returns false because the request hasn't had time to complete
bool UGame_MeshComponent_Mapbox::GetHAE(const FGeodeticCoord2D& coord, double& hae)
{
	int32 zoomLevel = 14;

	TPair<int32, int32> tileNumber;
	TileUtilities::GetTileFromGeodetic(coord, zoomLevel, tileNumber);

	if (!TileUtilities::TileExistsOnDisk(tileNumber, zoomLevel, TEXT("mapboxHeight"), TEXT("png")))
	{
		FString mapboxKey = TEXT("");
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			gameSettings->GetSettingString(FString::Printf(TEXT("mapbox_heightmap.MapboxKey")));
		}

		FString requestURL = FString::Printf(TEXT("https://api.mapbox.com/v4/mapbox.terrain-rgb/%d/%d/%d.pngraw?access_token=%s"), zoomLevel, tileNumber.Key, tileNumber.Value, *mapboxKey);

		FHttpModule* http = &FHttpModule::Get();

		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
		request->SetURL(requestURL);
		request->AppendToHeader(TEXT("email"), FString::Printf(TEXT("%d.%d.%d"), tileNumber.Key, tileNumber.Value, zoomLevel));
		request->SetVerb(TEXT("GET"));
		
		request->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
		{
			UGame_MeshComponent_Mapbox::HandleHTTPRequestComplete(request, response, bSucceeded);
		});

		request->ProcessRequest();
	}

	cv::Mat tileMat;
	if (TileUtilities::GetTileMatFromDisk(tileNumber, zoomLevel, TEXT("mapboxHeight"), TEXT("png"), tileMat))
	{
		cv::Vec3b pixelColor = tileMat.at<cv::Vec3b>(tileMat.rows / 2, tileMat.cols / 2);

		// from https://blog.mapbox.com/global-elevation-data-6689f1d0ba65 (-10000 min, 1667721.5 max)
		hae = -10000 + ((pixelColor[2] * 256 * 256 + pixelColor[1] * 256 + pixelColor[0]) * 0.1);
		hae = UVH_GlobeMathStatics::MSLToHAE(coord, hae);

		return true;

	}

	hae = 0;
	return false;
}

void UGame_MeshComponent_Mapbox::HandleHTTPRequestComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	bool bValid = true;

	if (!response.IsValid())
	{
		FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid heightmap received"));

		bValid = false;
	}

	if (bValid)
	{
		if (response->GetContentType().Equals(TEXT("application/json; charset=utf-8")) || response->GetContentType().Equals(TEXT("text/html")))
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("heightmap tile does not exist at this zoom level"));

			bValid = false;
		}
		else
		{
			TArray<uint8> content = response->GetContent();

			try
			{
				cv::Mat temp;
				std::vector<unsigned char> dataVector(content.GetData(), content.GetData() + content.Num());
				temp = cv::imdecode(dataVector, cv::IMREAD_UNCHANGED);

				if (temp.data == nullptr)
				{
					bValid = false;
				}

				temp.release();
			}
			catch (cv::Exception& e)
			{
				const char* err_msg = e.what();
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid imagery tile | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

				bValid = false;
			}
		}
	}

	if (bValid)
	{
		TArray<uint8> content = response->GetContent();

		FString tileID = request->GetHeader(TEXT("email"));

		TArray<FString> parsedID;
		tileID.ParseIntoArray(parsedID, TEXT("."), false);

		TPair<int32, int32> tileNumber;
		tileNumber.Key = FCString::Atoi(*parsedID[0]);
		tileNumber.Value = FCString::Atoi(*parsedID[1]);
		int32 zoomLevel = FCString::Atoi(*parsedID[2]);

		TileUtilities::WriteTileToDisk(tileNumber, zoomLevel, TEXT("mapboxHeight"), TEXT("png"), content);
	}
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MeshComponent_Mapbox::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();

	if (GetComponentStatus() == EComponentStatus::Initialized)
	{
		SetComponentStatus(EComponentStatus::HelperThreadStarted);

		if (Vertices.Num() == 0)
		{
			Async(EAsyncExecution::ThreadPool, [this]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					DestroyCounter.Decrement();
					return;
				}

				ZoomLevel = GetZoomLevel();

				FString mapboxKey = TEXT("");
				if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
				{
					mapboxKey = gameSettings->GetSettingString(FString::Printf(TEXT("mapbox_heightmap.AccessToken")));
				}

				if (mapboxKey.IsEmpty())
				{
					DestroyCounter.Decrement();
					return;
				}

				// determine tiles to pull
				TileUtilities::GetTileFromGeodetic(GetNorthWestBound(), GetZoomLevel(), NorthWestTile);
				TileUtilities::GetTileFromGeodetic(GetSouthEastBound(), GetZoomLevel(), SouthEastTile);

				UGame_TileManager* tileManager = UGame_TileManager::Get();

				// get all tiles' imagery data
				for (auto y = NorthWestTile.Value; y <= SouthEastTile.Value; y++)
				{
					for (auto x = NorthWestTile.Key; x <= SouthEastTile.Key; x++)
					{
						TPair<int32, int32> tileNumber(x, y);
						if (!TileUtilities::TileExistsOnDisk(tileNumber, GetZoomLevel(), TEXT("mapboxHeight"), TEXT("png")))
						{
							FString tileIdentifier = TileUtilities::GetTileIdentifier(tileNumber, GetZoomLevel(), TEXT("mapboxHeight"), TEXT("png"));
								
							FString requestURL = FString::Printf(TEXT("https://api.mapbox.com/v4/mapbox.terrain-rgb/%d/%d/%d.pngraw?access_token=%s"), GetZoomLevel(), tileNumber.Key, tileNumber.Value, *mapboxKey);

							FHttpModule* http = &FHttpModule::Get();

							TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
							request->SetURL(requestURL);
							request->AppendToHeader(TEXT("email"), FString::Printf(TEXT("%d.%d.%d"), tileNumber.Key, tileNumber.Value, GetZoomLevel()));
							request->SetVerb(TEXT("GET"));

							tileManager->AddHTTPRequest(tileIdentifier, this, request);

							RequestsCounter.Increment();
						}
					}
				}

				// if everything already exists on disk, skip to populating pixels
				if (RequestsCounter.GetValue() == 0)
				{
					CreateMat();
				}

				DestroyCounter.Decrement();
			});
		}
		else if (bDrawDistanceDirty)
		{
			// ApplyDrawDistance calls SetComponentStatus(HelperThreadFinished) when finished
			ApplyDrawDistance();
		}
		else
		{
			SetComponentStatus(EComponentStatus::HelperThreadFinished);
		}
	}
}

void UGame_MeshComponent_Mapbox::OnHTTPRequestComplete(const FString& tileIdentifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	Async(EAsyncExecution::ThreadPool, [this, request, response, bWasSuccessful]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		UGame_MeshComponent_Mapbox::HandleHTTPRequestComplete(request, response, bWasSuccessful);

		RequestsCounter.Decrement();

		CreateMat();

		DestroyCounter.Decrement();
	});
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_MeshComponent_Mapbox::CreateMat()
{
	if (RequestsCounter.GetValue() != 0)
	{
		return;
	}

	// create one large mat of all tiles' heightmap
	Async(EAsyncExecution::ThreadPool, [this]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		int32 numTilesX = (SouthEastTile.Key - NorthWestTile.Key) + 1;
		int32 numTilesY = (SouthEastTile.Value - NorthWestTile.Value) + 1;
		int32 allPixelsX = (numTilesX * 256) - (numTilesX - 1);
		int32 allPixelsY = (numTilesY * 256) - (numTilesY - 1);

		cv::Mat allTiles = CreateMatOfAllTiles(allPixelsX, allPixelsY);
		
		// convert to mat of height values
		TArray<float> heightValues;

		cv::MatIterator_<cv::Vec4b> it, end;
		for (it = allTiles.begin<cv::Vec4b>(), end = allTiles.end<cv::Vec4b>(); it != end; it++)
		{
			int32 b = (*it)[0];
			int32 g = (*it)[1];
			int32 r = (*it)[2];

			// from https://blog.mapbox.com/global-elevation-data-6689f1d0ba65 (-10000 min, 1667721.5 max)
			float elevation = -10000 + ((r * 256 * 256 + g * 256 + b) * 0.1);

			heightValues.Add(elevation);
		}

		cv::Mat allTilesHeight(allPixelsY, allPixelsX, CV_32FC1, heightValues.GetData());

		// crop resizedMat based on northWest and southEast bounds
		FGeodeticCoord2D nw = TileUtilities::GetNorthwestCoordinate(NorthWestTile, GetZoomLevel());
		FGeodeticCoord2D nw_East = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(NorthWestTile.Key + 1, NorthWestTile.Value), GetZoomLevel());
		FGeodeticCoord2D nw_South = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(NorthWestTile.Key, NorthWestTile.Value + 1), GetZoomLevel());

		float nw_xPercent = (GetNorthWestBound().Longitude - nw.Longitude) / (nw_East.Longitude - nw.Longitude);
		float nw_yPercent = (nw.Latitude - GetNorthWestBound().Latitude) / (nw.Latitude - nw_South.Latitude);

		FGeodeticCoord2D se = TileUtilities::GetNorthwestCoordinate(SouthEastTile, GetZoomLevel());
		FGeodeticCoord2D se_East = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(SouthEastTile.Key + 1, SouthEastTile.Value), GetZoomLevel());
		FGeodeticCoord2D se_South = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(SouthEastTile.Key, SouthEastTile.Value + 1), GetZoomLevel());

		// subtract from 1 because interested in number of pixels not included
		float se_xPercent = 1 - ((GetSouthEastBound().Longitude - se.Longitude) / (se_East.Longitude - se.Longitude));
		float se_yPercent = 1 - ((se.Latitude - GetSouthEastBound().Latitude) / (se.Latitude - se_South.Latitude));

		cv::Rect rect;
		rect.x = nw_xPercent * 256;
		rect.y = nw_yPercent * 256;
		rect.width = allPixelsX - (nw_xPercent * 256) - (se_xPercent * 256);
		rect.height = allPixelsY - (nw_yPercent * 256) - (se_yPercent * 256);

		cv::Mat croppedMat;

		try
		{
			croppedMat = allTilesHeight(rect);
		}
		catch (cv::Exception& e)
		{
			const char* err_msg = e.what();
			UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_Mapbox::CreateMat | crop | all width: %d, all height: %d | x: %d, y: %d, width: %d, height: %d | opencv error: %s"), allTilesHeight.cols, allTilesHeight.rows, rect.x, rect.y, rect.width, rect.height, ANSI_TO_TCHAR(err_msg));

			DestroyCounter.Decrement();

			return;
		}

		int32 postSpacingMeters = 30;
		switch (GetZoomLevel())
		{
			case 7:
				postSpacingMeters = 7200;
				break;

			case 8:
				postSpacingMeters = 3600;
				break;
							
			case 9:
			case 10:
			case 11:
				postSpacingMeters = 900;
				break;

			default:
				postSpacingMeters = 30;
				break;
		}

		FGeodeticCoord2D ne = GetNorthWestBound();
		ne.Longitude = GetSouthEastBound().Longitude;
		double distanceLongitudeMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(GetNorthWestBound(), ne);

		FGeodeticCoord2D sw = GetNorthWestBound();
		sw.Latitude = GetSouthEastBound().Latitude;
		double distanceLatitudeMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(GetNorthWestBound(), sw);

		int32 resizedNumRows = FMath::CeilToInt((distanceLongitudeMeters / postSpacingMeters) + 1);
		int32 resizedNumCols = FMath::CeilToInt((distanceLatitudeMeters / postSpacingMeters) + 1);

		cv::Mat resizedMat;
		try
		{
			cv::resize(croppedMat, resizedMat, cv::Size(resizedNumCols, resizedNumRows));
		}
		catch (cv::Exception& e)
		{
			const char* err_msg = e.what();
			UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_Mapbox::CreateMat | resize all tiles mat | opencv error: %s"), ANSI_TO_TCHAR(err_msg));
		}

		PopulateMeshData(resizedMat);

		DestroyCounter.Decrement();
	});
}

void UGame_MeshComponent_Mapbox::PopulateMeshData(cv::Mat heightmapMat)
{
	AVH_GlobeReferenceActor* globeRef = GetGlobeReference();
	if (globeRef == nullptr)
	{
		return;
	}

	Async(EAsyncExecution::ThreadPool, [this, globeRef, heightmapMat]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		cv::Mat mat = heightmapMat.clone();

		NumDataX = mat.cols;
		NumDataY = mat.rows;

		// get height data
		TArray<float> heightValues;

		cv::MatIterator_<float> it, end;
		for (it = mat.begin<float>(), end = mat.end<float>(); it != end; it++)
		{
			heightValues.Add(*it);
		}

		// determine xStepUU and yStepUU
		FGeodeticCoord2D nwCoord = GetNorthWestBound();
		FGeodeticCoord2D seCoord = GetSouthEastBound();
		FGeodeticCoord2D neCoord(seCoord.Longitude, nwCoord.Latitude);
		FGeodeticCoord2D swCoord(nwCoord.Longitude, seCoord.Latitude);

		TArray<FVector> vertices;
		TArray<FVector2D> uvs;

		HAEBounds = FVector2D(9999999, -9999999);

		// vertex for each height in heightValues
		for (auto y = 0; y < NumDataY; y++)
		{
			for (auto x = 0; x < NumDataX; x++)
			{
				int32 index = (y * NumDataX) + x;
				double msl = heightValues[index];

				FGeodeticCoord3D vertexCoordinate;
				vertexCoordinate.Longitude = FMath::Lerp<double>(swCoord.Longitude, seCoord.Longitude, x / (NumDataX - 1.f));
				vertexCoordinate.Latitude = FMath::Lerp<double>(nwCoord.Latitude, swCoord.Latitude, y / (NumDataY - 1.f));
				vertexCoordinate.Altitude = UVH_GlobeMathStatics::MSLToHAE(vertexCoordinate.ToGeodeticCoord2D(), msl);

				vertices.Add(globeRef->GeodeticToWorldDouble(vertexCoordinate));

				HAEBounds.X = FMath::Min<double>(HAEBounds.X, vertexCoordinate.Altitude);
				HAEBounds.Y = FMath::Max<double>(HAEBounds.Y, vertexCoordinate.Altitude);

				float uvX = (float)x / (float)(NumDataX - 1);
				float uvY = (float)y / (float)(NumDataY - 1);
				uvs.Add(FVector2D(uvX, uvY));
			}
		}

		// generate triangles
		TArray<int32> triangles;
		for (auto y = 0; y < NumDataY; y++)
		{
			for (auto x = 0; x < NumDataX - 1; x++)
			{
				if (y > 0)
				{
					int32 start = y * NumDataX;

					int32 bottomLeft = start + x;
					int32 bottomRight = start + x + 1;
					int32 topRight = start - NumDataX + x + 1;
					int32 topLeft = start - NumDataX + x;

					//
					//    . .
					//    .
					//
					triangles.Add(topRight);
					triangles.Add(topLeft);
					triangles.Add(bottomLeft);

					//
					//      .
					//    . .
					//
					triangles.Add(bottomLeft);
					triangles.Add(bottomRight);
					triangles.Add(topRight);
				}
			}
		}

		{
			FScopeLock scopeLock(TrianglesCritSection);
			Triangles.Empty();
			Triangles.Append(triangles);
		}

		{
			FScopeLock scopeLock(VerticesCritSection);
			Vertices.Empty();
			Vertices.Append(vertices);
		}

		{
			FScopeLock scopeLock(UVsCritSection);
			UVs.Empty();
			UVs.Append(uvs);
		}

		if (Vertices.Num() == 0)
		{
			UE_LOG(Game, Warning, TEXT("-- verts 0 | %d | %d"), GetZoomLevel(), vertices.Num());
		}

		ApplyDrawDistance();

		DestroyCounter.Decrement();
	});
}

cv::Mat UGame_MeshComponent_Mapbox::CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY)
{
	cv::Mat allTiles(pixelsY, pixelsX, CV_8UC4);

	for (auto y = NorthWestTile.Value; y <= SouthEastTile.Value; y++)
	{
		for (auto x = NorthWestTile.Key; x <= SouthEastTile.Key; x++)
		{
			int32 xPos = (x - NorthWestTile.Key) * 255;
			int32 yPos = (y - NorthWestTile.Value) * 255;

			bool bHandled = true;

			TPair<int32, int32> tileNumber(x, y);

			cv::Mat tileMat;
			if (TileUtilities::GetTileMatFromDisk(tileNumber, GetZoomLevel(), TEXT("mapboxHeight"), TEXT("png"), tileMat))
			{
				try
				{
					tileMat.copyTo(allTiles(cv::Rect(xPos, yPos, tileMat.cols, tileMat.rows)));
				}
				catch (cv::Exception& e)
				{
					const char* err_msg = e.what();
					UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_Mapbox::CreateMatOfAllTiles | copyTo | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

					bHandled = false;
				}
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_Mapbox::CreateMatOfAllTiles | unable to load imagery for | zoom: %d | tile: %d, %d"), GetZoomLevel(), x, y);
			}

			if (!bHandled)
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_Mapbox::CreateMatOfAllTiles | unable to load imagery for | %d, %d"), x, y);

				// make a blank mat to show no source data
				cv::Mat temp(256, 256, CV_8UC3);

				temp.copyTo(allTiles(cv::Rect(xPos, yPos, temp.cols, temp.rows)));
			}
		}
	}

	return allTiles.clone();
}

bool UGame_MeshComponent_Mapbox::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}