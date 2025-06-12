// Required Includes
#include "Game_MatComponent_TAKTICS.h"
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

UGame_MatComponent_TAKTICS::UGame_MatComponent_TAKTICS() : 
	SourceType(TEXT("")),
	TileMatrixSet(TEXT("OGC:4326"))
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MatComponent_TAKTICS::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->RemoveHTTPRequests(this);
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UGame_MatComponent_TAKTICS::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();

	if (GetComponentStatus() == EComponentStatus::Initialized)
	{
		SetComponentStatus(EComponentStatus::HelperThreadStarted);

		FString wmtsURL = TEXT("");
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			wmtsURL = gameSettings->GetSettingString(TEXT("taktics_imagery.WMTS"));

			GammaCorrection = gameSettings->GetSettingDouble(TEXT("taktics_imagery.GammaCorrection"));
		}

		if (!wmtsURL.IsEmpty())
		{
			FHttpModule* http = &FHttpModule::Get();

			TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
			request->SetURL(wmtsURL);
			request->SetVerb(TEXT("GET"));

			// bind callback
			request->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
			{
				if (!response.IsValid() || response->GetResponseCode() != 200)
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid WMTS from TAKTICS"));
					UE_LOG(LogTemp, Warning, TEXT("invalid WMTS from TAKTICS | %s"), *response->GetContentAsString());
					return;
				}

				FXmlFile xmlFile(response->GetContentAsString(), EConstructMethod::ConstructFromBuffer);
				//FXmlFile xmlFile(TEXT("osmTAKTICS.xml"));  // debug
				if (xmlFile.IsValid())
				{
					if (FXmlNode* serviceID = xmlFile.GetRootNode()->FindChildNode(TEXT("ows:ServiceIdentification")))
					{
						if (FXmlNode* title = serviceID->FindChildNode(TEXT("ows:Title")))
						{
							SourceName = FString::Printf(TEXT("takticsImagery-%s"), *title->GetContent());
						}
					}

					if (FXmlNode* contents = xmlFile.GetRootNode()->FindChildNode(TEXT("Contents")))
					{
						if (FXmlNode* layer = contents->FindChildNode(TEXT("Layer")))
						{
							if (FXmlNode* resourceURL = layer->FindChildNode(TEXT("ResourceURL")))
							{
								RequestURL = resourceURL->GetAttribute(TEXT("template"));
							}
						}

						const TArray<FXmlNode*> contentsChildren = contents->GetChildrenNodes();
						for (FXmlNode* contentChild : contentsChildren)
						{
							if (contentChild->GetTag().Equals(TEXT("TileMatrixSet")))
							{
								if (FXmlNode* matrixID = contentChild->FindChildNode(TEXT("ows:Identifier")))
								{
									if (matrixID->GetContent().Equals(TileMatrixSet))
									{
										MinTileMatrix = 1000;
										MaxTileMatrix = -1;

										const TArray<FXmlNode*> matrixSetChildren = contentChild->GetChildrenNodes();
										for (FXmlNode* matrixSetChild : matrixSetChildren)
										{
											if (matrixSetChild->GetTag().Equals(TEXT("TileMatrix")))
											{
												if (FXmlNode* tileMatrixID = matrixSetChild->FindChildNode(TEXT("ows:Identifier")))
												{
													int32 id = FCString::Atoi(*tileMatrixID->GetContent());

													MinTileMatrix = FMath::Min<int32>(MinTileMatrix, id);
													MaxTileMatrix = FMath::Max<int32>(MaxTileMatrix, id);
												}
											}
										}
									}
								}
							}
						}
					}
				}

				if (MinTileMatrix == 1000 || MaxTileMatrix == -1)
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_TAKTICS::ExecuteHelperThreadLogic | invalid min/max tile matrix | %d, %d"), MinTileMatrix, MaxTileMatrix);

					SetComponentStatus(EComponentStatus::HelperThreadFinished);

					return;
				}

				ZoomLevel = FMath::Clamp<int32>(ZoomLevel, MinTileMatrix, MaxTileMatrix);

				RequestURL.ReplaceInline(TEXT("{TileMatrixSet}"), *TileMatrixSet);
				RequestURL.ReplaceInline(TEXT("{TileMatrix}"), *FString::Printf(TEXT("%d"), ZoomLevel));

				MakeHttpRequests();
			});

			request->ProcessRequest();
		}
	}
}

void UGame_MatComponent_TAKTICS::ExecuteGameThreadLogic()
{
	if (GetComponentStatus() == EComponentStatus::HelperThreadFinished)
	{
		SetComponentStatus(EComponentStatus::GameThreadStarted);

		SetComponentStatus(EComponentStatus::GameThreadFinished);

		OnGameLogicCompleted.ExecuteIfBound(this);
	}
}

float UGame_MatComponent_TAKTICS::GetAlpha()
{
	return 1;
}

bool UGame_MatComponent_TAKTICS::SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel)
{
	Mat.release();

	bGeneratedMat = false;

	return true;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MatComponent_TAKTICS::MakeHttpRequests()
{
	// determine tiles to pull
	TileUtilities::GetTileFromGeodetic_TMS(GetNorthWestBound(), GetZoomLevel(), NorthWestTile, true);
	TileUtilities::GetTileFromGeodetic_TMS(GetSouthEastBound(), GetZoomLevel(), SouthEastTile, true);

	UGame_TileManager* tileManager = UGame_TileManager::Get();

	// get all tiles' imagery data
	int32 startY = FMath::Min<int32>(NorthWestTile.Value, SouthEastTile.Value);
	int32 endY = FMath::Max<int32>(NorthWestTile.Value, SouthEastTile.Value);

	int32 startX = FMath::Min<int32>(NorthWestTile.Key, SouthEastTile.Key);
	int32 endX = FMath::Max<int32>(NorthWestTile.Key, SouthEastTile.Key);

	FCriticalSection addCriticalSection;

	ParallelFor(endY - startY + 1, [this, &addCriticalSection, startY, startX, endX, tileManager](int32 y) 
	{
		y += startY;

		ParallelFor(endX - startX + 1, [this, &addCriticalSection, y, startX, tileManager](int32 x)
		{
			x += startX;

			TPair<int32, int32> tileNumber(x, y);
			if (!TileUtilities::TileExistsOnDisk(tileNumber, GetZoomLevel(), SourceName, SourceType))
			{
				FString tileIdentifier = TileUtilities::GetTileIdentifier(tileNumber, GetZoomLevel(), SourceName, SourceType);

				FString requestURL = RequestURL;
				requestURL.ReplaceInline(TEXT("{TileCol}"), *FString::Printf(TEXT("%d"), tileNumber.Key));
				requestURL.ReplaceInline(TEXT("{TileRow}"), *FString::Printf(TEXT("%d"), tileNumber.Value));

				FHttpModule* http = &FHttpModule::Get();

				TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
				request->SetURL(requestURL);
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
					FScopeLock scopeLock(&addCriticalSection);
					TileToMatData.Add(tileNumber, data);
				}
			}
		});
	});

	// if everything already exists on disk, skip to populating pixels
	if (RequestsCounter.GetValue() == 0)
	{
		CreateMat();
	}
}

void UGame_MatComponent_TAKTICS::OnHTTPRequestComplete(const FString& tileIdentifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
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
						try
						{
							TArray<uint8> content = response->GetContent();

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

void UGame_MatComponent_TAKTICS::CreateMat()
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
		bool bFoundTile = false;
		for (int32 y = FMath::Min<double>(NorthWestTile.Value, SouthEastTile.Value); y <= FMath::Max<double>(NorthWestTile.Value, SouthEastTile.Value); y++)
		{
			for (int32 x = FMath::Min<double>(NorthWestTile.Key, SouthEastTile.Key); x <= FMath::Max<double>(NorthWestTile.Key, SouthEastTile.Key); x++)
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
			UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_TAKTICS::CreateMat | could not create tileMat | zoom: %d"), GetZoomLevel());

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

		nw = TileUtilities::GetNorthwestCoordinate_TMS(NorthWestTile, GetZoomLevel(), true);
		nw_East = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(NorthWestTile.Key + 1, NorthWestTile.Value), GetZoomLevel(), true);
		nw_South = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(NorthWestTile.Key, NorthWestTile.Value + 1), GetZoomLevel(), true);

		nw_xPercent = (GetNorthWestBound().Longitude - nw.Longitude) / (nw_East.Longitude - nw.Longitude);
		nw_yPercent = (nw.Latitude - GetNorthWestBound().Latitude) / (nw.Latitude - nw_South.Latitude);

		se = TileUtilities::GetNorthwestCoordinate_TMS(SouthEastTile, GetZoomLevel(), true);
		se_East = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(SouthEastTile.Key + 1, SouthEastTile.Value), GetZoomLevel(), true);
		se_South = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(SouthEastTile.Key, SouthEastTile.Value + 1), GetZoomLevel(), true);

		// subtract from 1 because interested in number of pixels not included
		se_xPercent = 1 - ((GetSouthEastBound().Longitude - se.Longitude) / (se_East.Longitude - se.Longitude));
		se_yPercent = 1 - ((se.Latitude - GetSouthEastBound().Latitude) / (se.Latitude - se_South.Latitude));
		
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
			UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_TAKTICS::LoadImagery | crop/resize | opencv error: %s"), ANSI_TO_TCHAR(err_msg));
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_TAKTICS::LoadImagery | crop/resize | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

			// make a crimson mat as fallback
			cv::Mat temp(PixelHeight, PixelWidth, CV_8UC3);
			temp.setTo(cv::Scalar(60, 20, 220));

			Mat = temp.clone();
		}
		
		SetComponentStatus(EComponentStatus::HelperThreadFinished);

		DestroyCounter.Decrement();
	});
}

cv::Mat UGame_MatComponent_TAKTICS::CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY)
{
	cv::Mat allTiles(pixelsY, pixelsX, CV_8UC3);

	int32 startY = FMath::Min<int32>(NorthWestTile.Value, SouthEastTile.Value);
	int32 endY = FMath::Max<int32>(NorthWestTile.Value, SouthEastTile.Value);

	int32 startX = FMath::Min<int32>(NorthWestTile.Key, SouthEastTile.Key);
	int32 endX = FMath::Max<int32>(NorthWestTile.Key, SouthEastTile.Key);

	ParallelFor(endY - startY + 1, [this, &allTiles, startY, endY, startX, endX](int32 y) 
	{
		y += startY;

		ParallelFor(endX - startX + 1, [this, &allTiles, startY, y, endY, startX, endX](int32 x)
		{
			x += startX;

			TPair<int32, int32> tileNumber(x, y);

			int32 xPos = (x - startX) * (PixelWidth - 1);
			int32 yPos = (y - startY) * (PixelHeight - 1);

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
						cv::Mat gammaCorrected;
						AddGammaCorrection(tileMat, gammaCorrected, GammaCorrection);

						gammaCorrected.copyTo(allTiles(cv::Rect(xPos, yPos, gammaCorrected.cols, gammaCorrected.rows)));
					}
				}
				catch (cv::Exception& e)
				{
					const char* err_msg = e.what();
					UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_TAKTICS::CreateMatOfAllTiles | copyTo | %d | %d | %d | %d | %d | %d opencv error: %s"), tileMat.type(), allTiles.type(), xPos, yPos, tileMat.cols, tileMat.rows, ANSI_TO_TCHAR(err_msg));
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_TAKTICS::CreateMatOfAllTiles | copyTo | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

					bHandled = false;
				}
			}
			else
			{
				bHandled = false;
			}

			if (!bHandled)
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_TAKTICS::CreateMatOfAllTiles | unable to load imagery for | zoomLevel: %d | tile: %f, %f"), GetZoomLevel(), x, y);

				// make a crimson mat to show no source data
				cv::Mat temp(PixelHeight, PixelWidth, CV_8UC3);
				temp.setTo(cv::Scalar(60, 20, 220));

				temp.copyTo(allTiles(cv::Rect(xPos, yPos, temp.cols, temp.rows)));
			}
		});
	});

	return allTiles.clone();
}

bool UGame_MatComponent_TAKTICS::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

bool UGame_MatComponent_TAKTICS::GetCachedMat(const TPair<int32, int32>& tileNumber, cv::Mat& tileMat)
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

void UGame_MatComponent_TAKTICS::AddGammaCorrection(cv::Mat& src, cv::Mat& dst, float fGamma)
{
	unsigned char lut[256];
	for (int i = 0; i < 256; i++)
	{
		lut[i] = cv::saturate_cast<uchar>(FMath::Pow((float)(i / 255.0), fGamma) * 255.0f);
	}
	dst = src.clone();

	int32 channels = dst.channels();
	switch (channels)
	{
		case 1:
		{
			cv::MatIterator_<uchar> it, end;
			for (it = dst.begin<uchar>(), end = dst.end<uchar>(); it != end; it++)
			{
				*it = lut[(*it)];
			}
			
		}
		break;

		case 3:
		{
			cv::MatIterator_<cv::Vec3b> it, end;
			for (it = dst.begin<cv::Vec3b>(), end = dst.end<cv::Vec3b>(); it != end; it++)
			{
				(*it)[0] = lut[((*it)[0])];
				(*it)[1] = lut[((*it)[1])];
				(*it)[2] = lut[((*it)[2])];
			}
		}

		case 4:
		{
			cv::MatIterator_<cv::Vec4b> it, end;
			for (it = dst.begin<cv::Vec4b>(), end = dst.end<cv::Vec4b>(); it != end; it++)
			{
				(*it)[0] = lut[((*it)[0])];
				(*it)[1] = lut[((*it)[1])];
				(*it)[2] = lut[((*it)[2])];
			}
		}
	}
}