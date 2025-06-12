// Required Includes
#include "Game_MatComponent_CesiumIon.h"
#include "Game.h"

// Engine Includes
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Async/Async.h"
#include "XmlFile.h"

// VH Includes
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "VH_GlobeReferenceActor.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_TileUtilities.h"
#include "Game_TileManager.h"
#include "Game_TerrainTile.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MatComponent_CesiumIon::UGame_MatComponent_CesiumIon() :
	SourceName(TEXT("")),
	SourceType(TEXT("jpg")),
	MinZoom(0),
	MaxZoom(0),
	URL(TEXT("")),
	PixelWidth(0),
	PixelHeight(0),
	bXMLLoaded(false)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MatComponent_CesiumIon::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->RemoveHTTPRequests(this);
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UGame_MatComponent_CesiumIon::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();

	if (GetComponentStatus() == EComponentStatus::Initialized)
	{
		SetComponentStatus(EComponentStatus::HelperThreadStarted);

		FString accessToken = TEXT("");
		FString assetID = TEXT("");
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			accessToken = gameSettings->GetSettingString(FString::Printf(TEXT("cesium_imagery.CesiumAccessToken")));

			assetID = gameSettings->GetSettingString(FString::Printf(TEXT("cesium_imagery.CesiumAssetID")));
		}

		if (!accessToken.IsEmpty() && !assetID.IsEmpty())
		{
			FString requestURL = FString::Printf(TEXT("https://api.cesium.com/v1/assets/%s/endpoint"), *assetID);

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
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid cesium credentials"));

					return;
				}

				TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*response->GetContentAsString());

				TSharedPtr<FJsonObject> jsonObject;
				if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
				{
					FString accessToken;
					FString url = TEXT("");

					if (!jsonObject->TryGetStringField(TEXT("url"), url) || !jsonObject->TryGetStringField(TEXT("accessToken"), accessToken))
					{
						const TSharedPtr<FJsonObject>* optionsObjectPtr = nullptr;
						if (jsonObject->TryGetObjectField(TEXT("options"), optionsObjectPtr))
						{
							TSharedPtr<FJsonObject> optionsObject = *optionsObjectPtr;
							
							if (url.IsEmpty())
							{
								optionsObject->TryGetStringField(TEXT("url"), url);
							}

							if (accessToken.IsEmpty())
							{
								optionsObject->TryGetStringField(TEXT("accessToken"), accessToken);
							}
						}
					}

					if (!url.IsEmpty())
					{
						// determine file type
						TSharedRef<IHttpRequest, ESPMode::ThreadSafe> fileTypeRequest = (&FHttpModule::Get())->CreateRequest();
						fileTypeRequest->SetURL(FString::Printf(TEXT("%stilemapresource.xml"), *url));
						fileTypeRequest->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *accessToken));
						fileTypeRequest->SetVerb(TEXT("GET"));

						fileTypeRequest->OnProcessRequestComplete().BindLambda([this, assetID, accessToken, url](FHttpRequestPtr fileTypeRequest, FHttpResponsePtr fileTypeResponse, bool bSucceeded)
						{
							FString response = fileTypeResponse->GetContentAsString();

							// Strip off <?xml ... ?> tag. UE5's XML parser doesn't handle it well!
							FString searchStr = TEXT("?>");
							int32 foundPos = response.Find(searchStr);
							if (foundPos >= 0)
							{
								response = response.RightChop(foundPos + searchStr.Len());
							}

							FXmlFile xmlFile(response, EConstructMethod::ConstructFromBuffer);
							if (xmlFile.IsValid())
							{
								Projection = EProjection::Geodetic;
								if (FXmlNode* node = xmlFile.GetRootNode()->FindChildNode(TEXT("TileSets")))
								{
									FString profile = node->GetAttribute(TEXT("profile"));

									if (profile.Equals(TEXT("mercator")))
									{
										Projection = EProjection::Mercator;
										
										TileBounds.Key.Latitude = -TileBounds.Key.Latitude;
										TileBounds.Value.Latitude = -TileBounds.Value.Latitude;
									}
								}

								if (FXmlNode* node = xmlFile.GetRootNode()->FindChildNode(TEXT("TileFormat")))
								{
									SourceType = node->GetAttribute(TEXT("extension"));
									
									if (!SourceType.IsEmpty())
									{
										MakeHttpRequests(assetID, accessToken, url);
									}
									else
									{
										UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_CesiumIon::ExecuteHelperThreadLogic | source type could not be determined | aborting"));
									}
								}
							}
							else
							{
								UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_CesiumIon::ExecuteHelperThreadLogic | invalid TileMapResource file | aborting"));
							}
						});

						fileTypeRequest->ProcessRequest();
					}
				}
			});

			request->ProcessRequest();
		}
	}
}

void UGame_MatComponent_CesiumIon::ExecuteGameThreadLogic()
{
	if (GetComponentStatus() == EComponentStatus::HelperThreadFinished)
	{
		SetComponentStatus(EComponentStatus::GameThreadStarted);

		SetComponentStatus(EComponentStatus::GameThreadFinished);

		OnGameLogicCompleted.ExecuteIfBound(this);
	}
}

float UGame_MatComponent_CesiumIon::GetAlpha()
{
	return 1;
}

bool UGame_MatComponent_CesiumIon::SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel)
{
	Mat.release();

	bGeneratedMat = false;

	return true;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MatComponent_CesiumIon::MakeHttpRequests(const FString& assetID, const FString& accessToken, const FString& url)
{
	SourceName = FString::Printf(TEXT("cesiumImagery%s"), *assetID);
	
	// determine tiles to pull
	switch (Projection)
	{
		case EProjection::Geodetic:
		{
			GetTileFromGeodetic_Geodetic(GetNorthWestBound(), GetZoomLevel(), NorthWestTile);
			GetTileFromGeodetic_Geodetic(GetSouthEastBound(), GetZoomLevel(), SouthEastTile);
		}
		break;

		case EProjection::Mercator:
		{
			TileUtilities::GetTileFromGeodetic(GetNorthWestBound(), GetZoomLevel(), NorthWestTile);
			TileUtilities::GetTileFromGeodetic(GetSouthEastBound(), GetZoomLevel(), SouthEastTile);
		}
		break;
	}

	UGame_TileManager* tileManager = UGame_TileManager::Get();

	// get all tiles' imagery data
	FIntVector2 yValues;
	GetForValuesY(yValues);

	for (int32 y = yValues.X; y <= yValues.Y; y++)
	{
		for (int32 x = NorthWestTile.Key; x <= SouthEastTile.Key; x++)
		{
			TPair<int32, int32> tileNumber(x, y);
			if (!TileUtilities::TileExistsOnDisk(tileNumber, GetZoomLevel(), SourceName, SourceType))
			{
				FString tileIdentifier = TileUtilities::GetTileIdentifier(tileNumber, GetZoomLevel(), SourceName, SourceType);

				FString requestURL = FString::Printf(TEXT("%s%d/%d/%d.%s"), *url, GetZoomLevel(), tileNumber.Key, tileNumber.Value, *SourceType);
				//UE_LOG(LogTemp, Warning, TEXT("-- requestURL: %s"), *requestURL);
				FHttpModule* http = &FHttpModule::Get();

				TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
				request->SetURL(requestURL);
				request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *accessToken));
				request->AppendToHeader(TEXT("email"), FString::Printf(TEXT("%d.%d.%d"), tileNumber.Key, tileNumber.Value, GetZoomLevel()));
				request->SetVerb(TEXT("GET"));

				tileManager->AddHTTPRequest(tileIdentifier, this, request);

				RequestsCounter.Increment();
			}
			else
			{
				TArray<uint8> data;
				if (TileUtilities::ReadTileFromDisk(tileNumber, GetZoomLevel(), SourceName, SourceType, data))
				{
					TileToMatData.Add(tileNumber, data);
				}
			}
		}
	}

	// if everything already exists on disk, skip to populating pixels
	if (RequestsCounter.GetValue() == 0)
	{
		CreateMat();
	}
}

void UGame_MatComponent_CesiumIon::OnHTTPRequestComplete(const FString& tileIdentifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	Async(EAsyncExecution::ThreadPool, [this, request, response, bWasSuccessful]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		bool bValid = true;

		if (!response.IsValid() || response->GetContent().Num() == 0)
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid imagery received"));

			bValid = false;
		}

		if (bValid)
		{
			FString tileID = request->GetHeader(TEXT("email"));

			TArray<FString> parsedID;
			tileID.ParseIntoArray(parsedID, TEXT("."), false);

			TPair<int32, int32> tileNumber;
			tileNumber.Key = FCString::Atoi(*parsedID[0]);
			tileNumber.Value = FCString::Atoi(*parsedID[1]);
			int32 zoomLevel = FCString::Atoi(*parsedID[2]);

			if (!TileUtilities::TileExistsOnDisk(tileNumber, GetZoomLevel(), SourceName, SourceType))
			{
				if (bValid)
				{
					if (response->GetContentType().Equals(TEXT("application/json; charset=utf-8")) || response->GetContentType().Equals(TEXT("text/html")))
					{
						FPlatformMisc::LowLevelOutputDebugStringf(TEXT("imagery tile does not exist at this zoom level"));

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
					TileUtilities::WriteTileToDisk(tileNumber, zoomLevel, SourceName, SourceType, content);

					TileToMatData.Add(tileNumber, content);
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- invalid imagery: %s | %s"), *TileUtilities::GetTileIdentifier(tileNumber, zoomLevel, SourceName, SourceType), *response->GetContentAsString());
				}
			}
		}

		RequestsCounter.Decrement();

		if (RequestsCounter.GetValue() == 0)
		{
			CreateMat();
		}

		DestroyCounter.Decrement();
	});
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_MatComponent_CesiumIon::GetTileFromGeodetic_Geodetic(const FGeodeticCoord2D& coordinate, const int32 zoomLevel, TPair<int32, int32>& tileNumber)
{
	int32 numTilesY = 1 << zoomLevel;

	double tileX = 2 * numTilesY * ((coordinate.Longitude + 180.0) / 360.0);
	double tileY = (numTilesY * (coordinate.Latitude + 90.0) / 180.0);

	tileNumber.Key = FMath::FloorToInt(tileX);
	tileNumber.Value = FMath::FloorToInt(tileY);
}

FGeodeticCoord2D UGame_MatComponent_CesiumIon::GetNorthwestCoordinate_Geodetic(const TPair<int32, int32>& tileNumber, const int32 zoomLevel)
{
	FGeodeticCoord2D coordinate;

	int32 numTilesY = 1 << zoomLevel;

	coordinate.Longitude = tileNumber.Key * 360.0 / (2 * numTilesY) - 180.0;
	coordinate.Latitude = (tileNumber.Value + 1) * 180.0 / numTilesY - 90.0;

	return coordinate;
}

void UGame_MatComponent_CesiumIon::GetForValuesY(FIntVector2& yValues) const
{
	yValues.X = FMath::Min<int32>(NorthWestTile.Value, SouthEastTile.Value);
	yValues.Y = FMath::Max<int32>(NorthWestTile.Value, SouthEastTile.Value);
}

void UGame_MatComponent_CesiumIon::CreateMat()
{
	if (bGeneratedMat || RequestsCounter.GetValue() != 0)
	{
		return;
	}

	bGeneratedMat = true;

	// create one large mat of all tiles' imagery
	Async(EAsyncExecution::ThreadPool, [this]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}
		
		// assumes all tiles have same width/height; should be OK since all came from same source
		FIntVector2 yValues;
		GetForValuesY(yValues);

		bool bFoundTile = false;
		for (int32 y = yValues.X; y <= yValues.Y; y++)
		{
			for (int32 x = NorthWestTile.Key; x <= SouthEastTile.Key; x++)
			{
				TPair<int32, int32> tileNumber(x, y);

				cv::Mat tileMat;
				if (GetCachedMat(tileNumber, tileMat))
				{
					PixelWidth = tileMat.cols;
					PixelHeight = tileMat.rows;

					bFoundTile = true;

					break;
				}
			}

			if (bFoundTile)
			{
				break;
			}
		}
		
		if (!bFoundTile)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_CesiumIon::CreateMat | could not create tileMat | zoom: %d"), GetZoomLevel());

			// make a crimson mat to show no source data
			cv::Mat temp(256, 256, CV_8UC3);
			temp.setTo(cv::Scalar(60, 20, 220));

  			Mat = temp.clone();

			SetComponentStatus(EComponentStatus::HelperThreadFinished);

			DestroyCounter.Decrement();
			return;
		}

		int32 numTilesX = FMath::Abs(SouthEastTile.Key - NorthWestTile.Key) + 1;
		int32 numTilesY = FMath::Abs(NorthWestTile.Value - SouthEastTile.Value) + 1;
		
		int32 allPixelsX = (numTilesX * PixelWidth) - (numTilesX - 1);
		int32 allPixelsY = (numTilesY * PixelHeight) - (numTilesY - 1);
		
		cv::Mat allTiles = CreateMatOfAllTiles(allPixelsX, allPixelsY);
		
		// crop large mat based on northWest and southEast bounds
		FGeodeticCoord2D nw;
		FGeodeticCoord2D nw_East;
		FGeodeticCoord2D nw_South;

		float nw_xPercent = 0;
		float nw_yPercent = 0;

		FGeodeticCoord2D se;
		FGeodeticCoord2D se_East;
		FGeodeticCoord2D se_South;

		float se_xPercent = 0;
		float se_yPercent = 0;

		int32 southIncrement = NorthWestTile.Value <= SouthEastTile.Value ? 1 : -1;

		switch (Projection)
		{
			case EProjection::Geodetic:
			{
				southIncrement = NorthWestTile.Value == SouthEastTile.Value ? -1 : southIncrement;

				nw = GetNorthwestCoordinate_Geodetic(NorthWestTile, GetZoomLevel());
				nw_East = GetNorthwestCoordinate_Geodetic(TPair<int32, int32>(NorthWestTile.Key + 1, NorthWestTile.Value), GetZoomLevel());
				nw_South = GetNorthwestCoordinate_Geodetic(TPair<int32, int32>(NorthWestTile.Key, NorthWestTile.Value + southIncrement), GetZoomLevel());

				nw_xPercent = (GetNorthWestBound().Longitude - nw.Longitude) / (nw_East.Longitude - nw.Longitude);
				nw_yPercent = (nw.Latitude - GetNorthWestBound().Latitude) / (nw.Latitude - nw_South.Latitude);

				se = GetNorthwestCoordinate_Geodetic(SouthEastTile, GetZoomLevel());
				se_East = GetNorthwestCoordinate_Geodetic(TPair<int32, int32>(SouthEastTile.Key + 1, SouthEastTile.Value), GetZoomLevel());
				se_South = GetNorthwestCoordinate_Geodetic(TPair<int32, int32>(SouthEastTile.Key, SouthEastTile.Value + southIncrement), GetZoomLevel());

				// subtract from 1 because interested in number of pixels not included
				se_xPercent = 1 - ((GetSouthEastBound().Longitude - se.Longitude) / (se_East.Longitude - se.Longitude));
				se_yPercent = 1 - ((se.Latitude - GetSouthEastBound().Latitude) / (se.Latitude - se_South.Latitude));
			}
			break;

			case EProjection::Mercator:
			{
				southIncrement = NorthWestTile.Value == SouthEastTile.Value ? 1 : southIncrement;

				nw = TileUtilities::GetNorthwestCoordinate(NorthWestTile, GetZoomLevel());
				nw_East = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(NorthWestTile.Key + 1, NorthWestTile.Value), GetZoomLevel());
				nw_South = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(NorthWestTile.Key, NorthWestTile.Value + southIncrement), GetZoomLevel());

				nw_xPercent = (GetNorthWestBound().Longitude - nw.Longitude) / (nw_East.Longitude - nw.Longitude);
				nw_yPercent = (-nw.Latitude - -GetNorthWestBound().Latitude) / (-nw.Latitude - -nw_South.Latitude);

				se = TileUtilities::GetNorthwestCoordinate(SouthEastTile, GetZoomLevel());
				se_East = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(SouthEastTile.Key + 1, SouthEastTile.Value), GetZoomLevel());
				se_South = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(SouthEastTile.Key, SouthEastTile.Value + southIncrement), GetZoomLevel());

				se_xPercent = 1 - ((GetSouthEastBound().Longitude - se.Longitude) / (se_East.Longitude - se.Longitude));
				se_yPercent = 1 - ((-se.Latitude - -GetSouthEastBound().Latitude) / (-se.Latitude - -se_South.Latitude));
			}
			break;
		}

		try
		{
			cv::Rect rect;
			rect.x = nw_xPercent * PixelWidth;
			rect.y = nw_yPercent * PixelHeight;
			rect.width = allPixelsX - (nw_xPercent * PixelWidth) - (se_xPercent * PixelWidth);
			rect.height = allPixelsY - (nw_yPercent * PixelHeight) - (se_yPercent * PixelHeight);

			cv::Mat croppedMat = allTiles(rect);

			Mat = croppedMat.clone();
		}
		catch (cv::Exception& e)
		{
			const char* err_msg = e.what();
			UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_CesiumIon::LoadImagery | crop/resize | opencv error: %s"), ANSI_TO_TCHAR(err_msg));
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_CesiumIon::LoadImagery | crop/resize | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

			// make a crimson mat as fallback
			cv::Mat temp(PixelHeight, PixelWidth, CV_8UC3);
			temp.setTo(cv::Scalar(60, 20, 220));

			Mat = temp.clone();
		}
		
		SetComponentStatus(EComponentStatus::HelperThreadFinished);
		
		DestroyCounter.Decrement();
	});
}

cv::Mat UGame_MatComponent_CesiumIon::CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY)
{
	FIntVector2 yValues;
	GetForValuesY(yValues);

	cv::Mat allTiles(pixelsY, pixelsX, CV_8UC3);
	for (int32 y = yValues.X; y <= yValues.Y; y++)
	{
		for (int32 x = NorthWestTile.Key; x <= SouthEastTile.Key; x++)
		{
			TPair<int32, int32> tileNumber(x, y);

			int32 xPos = (x - NorthWestTile.Key) * (PixelWidth - 1);
			int32 yPos = (yValues.Y - y) * (PixelHeight - 1);

			bool bHandled = true;

			cv::Mat tileMat;
			if (GetCachedMat(tileNumber, tileMat))
			{
				try
				{
					if (tileMat.type() != allTiles.type())
					{
						cv::Mat convertMat;

						// todo ohg | better way to do this?
						if (tileMat.type() == CV_8UC1)
						{
							cv::cvtColor(tileMat, convertMat, cv::COLOR_GRAY2BGR);
							convertMat.copyTo(allTiles(cv::Rect(xPos, yPos, convertMat.cols, convertMat.rows)));
						}
						else if (tileMat.type() == CV_8UC2)
						{
							UE_LOG(Game, Warning, TEXT("-- unhandled | CV_8UC2"));
							bHandled = false;
						}
						else if (tileMat.type() == CV_8UC4)
						{
							cv::cvtColor(tileMat, convertMat, cv::COLOR_BGRA2BGR);
							convertMat.copyTo(allTiles(cv::Rect(xPos, yPos, convertMat.cols, convertMat.rows)));
						}
						else
						{
							UE_LOG(Game, Warning, TEXT("-- unhandled | %d"), tileMat.type());
							bHandled = false;
						}
					}
					else
					{
						tileMat.copyTo(allTiles(cv::Rect(xPos, yPos, tileMat.cols, tileMat.rows)));
					}
				}
				catch (cv::Exception& e)
				{
					const char* err_msg = e.what();
					UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_CesiumIon::CreateMatOfAllTiles | copyTo | %d | %d | %d | %d | %d | %d opencv error: %s"), tileMat.type(), allTiles.type(), xPos, yPos, tileMat.cols, tileMat.rows, ANSI_TO_TCHAR(err_msg));
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_CesiumIon::CreateMatOfAllTiles | copyTo | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

					bHandled = false;
				}
			}
			else
			{
				bHandled = false;
			}

			if (!bHandled)
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_CesiumIon::CreateMatOfAllTiles | unable to load imagery for | zoomLevel: %d | tile: %f, %f"), GetZoomLevel(), x, y);

				// make a crimson mat to show no source data
				cv::Mat temp(PixelHeight, PixelWidth, CV_8UC3);
				temp.setTo(cv::Scalar(60, 20, 220));

				temp.copyTo(allTiles(cv::Rect(xPos, yPos, temp.cols, temp.rows)));
			}
		}
	}

	return allTiles.clone();
}

bool UGame_MatComponent_CesiumIon::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

bool UGame_MatComponent_CesiumIon::GetCachedMat(const TPair<int32, int32>& tileNumber, cv::Mat& tileMat)
{
	if (TArray<uint8>* data = TileToMatData.Find(tileNumber))
	{
		std::vector<unsigned char> dataVector(data->GetData(), data->GetData() + data->Num());
		tileMat = cv::imdecode(dataVector, cv::IMREAD_UNCHANGED);

		return true;
	}

	// fallback to get mats when desired zoom level isn't present and GetTileMatFromDisk returns mat for lower zoom level
	return TileUtilities::GetTileMatFromDisk(tileNumber, GetZoomLevel(), SourceName, SourceType, tileMat, true);
}