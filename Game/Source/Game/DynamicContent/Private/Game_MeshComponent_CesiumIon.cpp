// Required Includes
#include "Game_MeshComponent_CesiumIon.h"
#include "Game.h"

// Engine Includes
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Async/Async.h"
#include "Misc/FileHelper.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_GlobeMathStatics.h"
#include "VH_FileIOStatics.h"
#include "VH_GlobeReferenceActor.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_TileManager.h"
#include "Game_TileUtilities.h"
#include "Game_TileManager.h"
#include "Game_Statics.h"

#define ENGINE_API_CACHE ENGINE_API
#undef ENGINE_API
#include "formats/quantizedmesh/QMESourceLayer.h"
#include "formats/quantizedmesh/TileCoord.h"
#include "feature/GeometryFactory.h"
#include "elevation/ElevationManager.h"
#include "elevation/ElevationSourceManager.h"
#include "elevation/ElevationSource.h"
#include "port/STLVectorAdapter.h"
#include "port/STLListAdapter.h"
#include "raster/osm/OSMUtils.h"
#undef ENGINE_API
#define ENGINE_API ENGINE_API_CACHE
#undef ENGINE_API_CACHE

using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Util;
using namespace TAK::Engine;

class Game_QMESourceLayer : public QMESourceLayer
{
public:
	mutable int MinZoomLevel;
	mutable int MaxZoomLevel;
	mutable bool bLocalDirectoryValid = true;
	mutable bool bValid = true;
	mutable bool bEnabled = true;
	mutable Port::String FullPathToRootDirectory;
	mutable int ExtentsMinX;
	mutable int ExtentsMinY;
	mutable int ExtentsMaxX;
	mutable int ExtentsMaxY;
	mutable Port::STLVectorAdapter<TileExtents> Extents;

	/**
	 * Returns the minimum zoom level the source can provide.
	 * @param value returns the minimum zoom level
	 * @return TE_Ok if value is populated, TE_Err otherwise
	 */
	TAKErr getMinZoom(int* value) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- getMinZoom"));

		*value = MinZoomLevel;

		return TAKErr::TE_Ok;
	}

	/**
	 * Returns the maximum zoom level the source can provide.
	 * @param value returns the maximum zoom level
	 * @return TE_Ok if value is populated, TE_Err otherwise
	 */
	TAKErr getMaxZoom(int* value) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- getMaxZoom"));

		*value = MaxZoomLevel;

		return TAKErr::TE_Ok;
	}

	/**
	* Indicates if the local storage location exists and appears to be usable
	* @param value on successful return, is set to true if local storage location exists and appears to be usable, false otherwise
	* @return TE_Ok if value is populated, TE_Err otherwise
	*/
	TAKErr isLocalDirectoryValid(bool* value) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- isLocalDirectoryValid"));

		*value = bLocalDirectoryValid;

		return TAKErr::TE_Ok;
	}

	/**
	* Get the closest level that can be provided by the source layer given a geodetic span
	* @param geodeticSpan Geodetic span, in degrees
	* @param value on successful return, is set to closed level to the provided span
	* @return TE_Ok if value is populated, TE_Err otherwise
	*/
	TAKErr getClosestLevel(int* value, double geodeticSpan) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- getClosestLevel | %d"), MinZoomLevel);

		*value = MinZoomLevel;

		return TAKErr::TE_Ok;
	}

	/**
	* Get the max level of detail available to the source layer
	* @param value on successful return, is set to maximum level of detail
	* @return TE_Ok if value is populated, TE_Err otherwise
	*/
	TAKErr getMaxLevel(int* value) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- getClosestLevel | %d"), MaxZoomLevel);

		*value = MaxZoomLevel;

		return TAKErr::TE_Ok;
	}

	/**
	 * Obtain the local directory that houses all tiles for the entire source layer.
	 * The implementation must provide 'dirname' as an absolute path string.
	 * @param dirname String to receive the directory name
	 * @return TE_Ok if the dirname is populated, TE_Err if an error occurs
	 */
	TAKErr getDirectory(Port::String* dirname) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- getDirectory | %s"), *FullPathToRootDirectory);

		*dirname = FullPathToRootDirectory;

		return TAKErr::TE_Ok;
	}

	/**
	 * Obtain the local directory that houses tiles for the given z level in this source layer.
	 * The implementation must provide 'dirname' as an absolute path string, and it is expected
	 * that dirname be somewhere below the location returned by getDirectory().
	 * @param dirname String to receive the directory name
	 * @param z the z level to get the directory name for
	 * @return TE_Ok if the dirname is populated, TE_Err if an error occurs
	 */
	TAKErr getLevelDirName(Port::String* dirname, int z) const NOTHROWS
	{
		FString fullPathToDirectory = FString::Printf(TEXT("%s/%d"), ANSI_TO_TCHAR(FullPathToRootDirectory.get()), z);
		//UE_LOG(LogTemp, Warning, TEXT("-- getLevelDirName | %d | %s"), z, *fullPathToDirectory);

		Port::String toReturn(TCHAR_TO_ANSI(*fullPathToDirectory));
		*dirname = toReturn;

		return TAKErr::TE_Ok;
	}

	/**
	 * Obtain the local filename representing the tile for the given x, y, z coordinates in this source layer.
	 * The implementation must provide 'filename' as an absolute path string.
	 * @param filename String to receive the directory name
	 * @param x the x coordinate of the tile to get the local filename for
	 * @param y the y coordinate of the tile to get the local filename for
	 * @param z the z level of the tile to get the local filename for
	 * @return TE_Ok if the filename is populated, TE_Err if an error occurs
	 */
	TAKErr getTileFilename(Port::String* filename, int x, int y, int z) const NOTHROWS
	{
		FString fullPathToFile = FString::Printf(TEXT("%s/%d/%d/%d.terrain"), ANSI_TO_TCHAR(FullPathToRootDirectory.get()), z, x, y);

		//UE_LOG(LogTemp, Warning, TEXT("-- getTileFilename | %d | %d | %d | %s"), z, x, y, *fullPathToFile)

		Port::String toReturn(TCHAR_TO_ANSI(*fullPathToFile));
		*filename = toReturn;

		return TAKErr::TE_Ok;
	}

	/**
	* Check if this layer is valid. A backing layer is valid if it has
	* a valid source from which to make requests for tiles to
	* @param value on successful return, is set to true if valid, false otherwise
	* @return TE_Ok if value is populated, TE_Err otherwise
	*/
	TAKErr isValid(bool* value) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- isValid"));

		*value = bValid;

		return TAKErr::TE_Ok;
	}

	/**
	 * Check if this source layer is presently enabled
	* @param value on successful return, is set to true if source layer is enabled, false otherwise
	* @return TE_Ok if value is populated, TE_Err otherwise
	 */
	TAKErr isEnabled(bool* value) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- isEnabled"));

		*value = bEnabled;

		return TAKErr::TE_Ok;
	}

	/**
	* Check if a tile with specific coordinates is available for this layer.
	*
	* @param value on successful return, is set to true if layer has tile for specified coordinates
	* @param x X coordinate
	* @param y Y coordinate
	* @param level Level
	* @return TE_Ok if value is populated, TE_Err otherwise
	*/
	TAKErr hasTile(bool* value, int x, int y, int level) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- hasTile | %d | %d | %d"), level, x, y)

		FString fullPathToFile = FString::Printf(TEXT("%s/%d/%d/%d.terrain"), ANSI_TO_TCHAR(FullPathToRootDirectory.get()), level, x, y);

		IFileManager& fileManager = IFileManager::Get();
		bool bExists = fileManager.FileExists(*fullPathToFile);

		*value = bExists;

		return TAKErr::TE_Ok;
	}

	/**
	 * Get a list of TileExtents available to this source layer at the given level.
	 * @param extents Vector to receive the TileExtents
	 * @param level the level to query
	 * @return TE_Ok if extents is populated, TE_Err otherwise
	 */
	TAKErr getAvailableExtents(Port::Vector<TileExtents>* extents, int level) const NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- getAvailableExtents: %d"), level);

		return (*extents).add(TileExtents(ExtentsMinX, ExtentsMinY, ExtentsMaxX, ExtentsMaxY, level));

		//return TAKErr::TE_Ok;
	}

	/**
	 * Start an asynchronous data request for the tile at the given x, y, z location.
	 * The Layer implementation will request and populate the tile to the appropriate local
	 * file store location (see getTileFilename()).
	 *
	 * @param x x coordinate
	 * @param y y coordinate
	 * @param z level
	 * @return TE_Ok if request is submitted successfully, TE_Err otherwise
	 */
	TAKErr startDataRequest(int x, int y, int z) NOTHROWS
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- startDataRequest | %d | %d | %d"), z, x, y)
		return TAKErr::TE_Ok;
	}
};

class Game_TAKKernelLogger : public Logger2
{
public:
	Game_TAKKernelLogger() NOTHROWS
	{

	};

	~Game_TAKKernelLogger() NOTHROWS override
	{

	};
	
public:
	int print(const Util::LogLevel lvl, const char* fmt, va_list args) NOTHROWS override
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- LogLevel"));

		return 0;
	}
};


// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MeshComponent_CesiumIon::UGame_MeshComponent_CesiumIon()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

bool UGame_MeshComponent_CesiumIon::GetHAE(const FGeodeticCoord2D& coordinate, double& hae)
{
	//{
	//	FGeodeticCoord2D northWestBound(-78.1, 35.1);
	//	FGeodeticCoord2D southEastBound(-77.9, 34.9);
	//	int32 postSpacingMeters = 900;

	//	double westEastMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWestBound, FGeodeticCoord2D(southEastBound.Longitude, northWestBound.Latitude));
	//	double northSouthMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWestBound, FGeodeticCoord2D(northWestBound.Longitude, southEastBound.Latitude));

	//	double longitudeDivisor = westEastMeters / postSpacingMeters;
	//	double latitudeDivisor = northSouthMeters / postSpacingMeters;

	//	double longitudeIncrement = (southEastBound.Longitude - northWestBound.Longitude) / longitudeDivisor;
	//	double latitudeIncrement = (northWestBound.Latitude - southEastBound.Latitude) / latitudeDivisor;

	//	// northwest -> southeast
	//	int32 totalLongitudePosts = 0;
	//	int32 totalLatitudePosts = 0;
	//	TArray<double> srcLatitude;
	//	TArray<double> srcLongitude;
	//	for (double latitude = northWestBound.Latitude; latitude >= southEastBound.Latitude; latitude -= latitudeIncrement)
	//	{
	//		for (double longitude = northWestBound.Longitude; longitude <= southEastBound.Longitude; longitude += longitudeIncrement)
	//		{
	//			srcLatitude.Add(latitude);
	//			srcLongitude.Add(longitude);

	//			if (latitude == northWestBound.Latitude)
	//			{
	//				totalLongitudePosts++;
	//			}

	//			if (longitude == northWestBound.Longitude)
	//			{
	//				totalLatitudePosts++;
	//			}
	//		}
	//	}

	//	TArray<double> haeValues;
	//	haeValues.Empty();
	//	haeValues.AddZeroed(totalLongitudePosts * totalLatitudePosts);

	//	// early out when posts are sufficiently far apart (all 0s for post heights)
	//	if (postSpacingMeters > 900)
	//	{
	//		return true;
	//	}

	//	// required by TAK Kernel
	//	for (int32 i = 0; i < haeValues.Num(); i++)
	//	{
	//		haeValues[i] = std::nan("1");
	//	}

	//	std::shared_ptr<ElevationSource> elevationSourcePtr;
	//	if (ElevationSourceManager_findSource(elevationSourcePtr, "QME") == TAKErr::TE_Ok)
	//	{
	//		ElevationSourceManager_detach(*elevationSourcePtr.get());
	//	}

	//	std::shared_ptr<QMESourceLayer> qmeSourceLayer = std::make_shared<Game_QMESourceLayer>();

	//	std::shared_ptr<Game_QMESourceLayer> gameQMESourceLayer = static_pointer_cast<Game_QMESourceLayer>(qmeSourceLayer);
	//	gameQMESourceLayer->MinZoomLevel = 14;
	//	gameQMESourceLayer->MaxZoomLevel = 14;
	//	gameQMESourceLayer->FullPathToRootDirectory = Port::String(TCHAR_TO_ANSI(*FString::Printf(TEXT("%s/3DTiles/1"), *UGame_Statics::GetVTAKCommonAppDataPath())));

	//	TPair<int32, int32> nwTile;
	//	TPair<int32, int32> seTile;
	//	TileUtilities::GetTileFromGeodetic_TMS(northWestBound, 14, nwTile);
	//	TileUtilities::GetTileFromGeodetic_TMS(southEastBound, 14, seTile);
	//	gameQMESourceLayer->ExtentsMinX = FMath::Min<int32>(nwTile.Key, seTile.Key);
	//	gameQMESourceLayer->ExtentsMinY = FMath::Min<int32>(nwTile.Value, seTile.Value);
	//	gameQMESourceLayer->ExtentsMaxX = FMath::Max<int32>(nwTile.Key, seTile.Key);
	//	gameQMESourceLayer->ExtentsMaxY = FMath::Max<int32>(nwTile.Value, seTile.Value);

	//	TAKErr attachError = QMESourceLayer_attach(qmeSourceLayer);

	//	ElevationSource::QueryParameters queryParameters;

	//	UE_LOG(LogTemp, Warning, TEXT("-- start2"));
	//	TAK::Engine::Port::String qme;// ("QME");
	//	for (double latitude = northWestBound.Latitude; latitude >= southEastBound.Latitude; latitude -= latitudeIncrement)
	//	{
	//		for (double longitude = northWestBound.Longitude; longitude <= southEastBound.Longitude; longitude += longitudeIncrement)
	//		{
	//			TAKErr error2 = ElevationManager_getElevation(&hae, &qme, latitude, longitude, queryParameters);
	//			if (error2 != TE_Ok)
	//			{
	//				UE_LOG(LogTemp, Warning, TEXT("-- error! %d"), error2);
	//			}
	//			else UE_LOG(LogTemp, Warning, TEXT("-- %f, %f, %f"), latitude, longitude, hae);
	//		}
	//	}
	//	UE_LOG(LogTemp, Warning, TEXT("-- end2"));

	//}

	/////////////////////////////////////////////////////


	/*Game_TAKKernelLogger takKernelLogger;
	LoggerPtr loggerPtr(&takKernelLogger, Memory_leaker_const<Logger2>);
	Logger_setLogger(std::move(loggerPtr));

	Logger_setLevel(Util::LogLevel::TELL_All);*/

	std::shared_ptr<ElevationSource> elevationSourcePtr;
	if (ElevationSourceManager_findSource(elevationSourcePtr, "QME") == TAKErr::TE_Ok)
	{
		ElevationSourceManager_detach(*elevationSourcePtr.get());
	}

	if (ElevationSourceManager_findSource(elevationSourcePtr, "DTED") == TAKErr::TE_Ok)
	{
		ElevationSourceManager_detach(*elevationSourcePtr.get());
	}

	std::shared_ptr<QMESourceLayer> qmeSourceLayer = std::make_shared<Game_QMESourceLayer>();

	std::shared_ptr<Game_QMESourceLayer> gameQMESourceLayer = static_pointer_cast<Game_QMESourceLayer>(qmeSourceLayer);
	gameQMESourceLayer->MinZoomLevel = 14;
	gameQMESourceLayer->MaxZoomLevel = 14;
	gameQMESourceLayer->FullPathToRootDirectory = Port::String(TCHAR_TO_ANSI(*FString::Printf(TEXT("%s/3DTiles/1"), *UGame_Statics::GetVTAKCommonAppDataPath())));

	TPair<int32, int32> tile;
	TileUtilities::GetTileFromGeodetic_TMS(coordinate, 14, tile);
	gameQMESourceLayer->ExtentsMinX = tile.Key;
	gameQMESourceLayer->ExtentsMinY = tile.Value;
	gameQMESourceLayer->ExtentsMaxX = tile.Key;
	gameQMESourceLayer->ExtentsMaxY = tile.Value;

	TAKErr attachError = QMESourceLayer_attach(qmeSourceLayer);

	ElevationSource::QueryParameters queryParameters;

	TAK::Engine::Port::String qme;
	TAKErr error = ElevationManager_getElevation(&hae, &qme, coordinate.Latitude, coordinate.Longitude, queryParameters);
	if (error == TAKErr::TE_Ok)
	{
		UE_LOG(LogTemp, Warning, TEXT("-- (%d, %d) | hae: %f"), tile.Key, tile.Value, hae);
		//return true;
	}
	
	hae = 0;
	//return false;





	// each mesh can contain data from multiple terrain tiles, which will each have their data stored separately
	FString fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), 14, tile.Key, tile.Value);

	TArray<uint8> content;
	if (FFileHelper::LoadFileToArray(content, *fullPathToFile))
	{
		FMemoryReader memReader(content, false);
		memReader.Seek(0);

		// center point of the tile in ECEF coordinates
		double centerX;
		double centerY;
		double centerZ;
		memReader << centerX;
		memReader << centerY;
		memReader << centerZ;

		// minimum and maximum HAE in meters
		float minimumHeight;
		float maximumHeight;
		memReader << minimumHeight;
		memReader << maximumHeight;

		return true;
	}

	hae = 0;
	return false; 
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MeshComponent_CesiumIon::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();

	if (GetComponentStatus() == EComponentStatus::Initialized)
	{
		SetComponentStatus(EComponentStatus::HelperThreadStarted);

		if (Vertices.Num() == 0)
		{
			FString accessToken = TEXT("");
			FString assetID = TEXT("");
			if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
			{
				accessToken = gameSettings->GetSettingString(FString::Printf(TEXT("cesium_heightmap.CesiumAccessToken")));

				assetID = gameSettings->GetSettingString(FString::Printf(TEXT("cesium_heightmap.CesiumAssetID")));
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

					FString responseString = response->GetContentAsString();
					
					TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*response->GetContentAsString());

					TSharedPtr<FJsonObject> jsonObject;
					if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
					{
						FString accessToken;
						FString url;

						if (jsonObject->TryGetStringField(TEXT("url"), url) && jsonObject->TryGetStringField(TEXT("accessToken"), accessToken))
						{
							MakeHttpRequests(assetID, accessToken, url);
						}
						else
						{
							const TSharedPtr<FJsonObject>* optionsObjectPtr = nullptr;
							if (jsonObject->TryGetObjectField(TEXT("options"), optionsObjectPtr))
							{
								TSharedPtr<FJsonObject> optionsObject = *optionsObjectPtr;
								if (optionsObject->TryGetStringField(TEXT("url"), url) && optionsObject->TryGetStringField(TEXT("accessToken"), accessToken))
								{
									MakeHttpRequests(assetID, accessToken, url);
								}
							}
						}
					}
				});

				request->ProcessRequest();
			}
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

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MeshComponent_CesiumIon::MakeHttpRequests(const FString& assetID, const FString& accessToken, const FString& url)
{
	// determine tiles to pull
	GetTileFromGeodetic(GetNorthWestBound(), GetZoomLevel(), NorthWestTile);
	GetTileFromGeodetic(GetSouthEastBound(), GetZoomLevel(), SouthEastTile);

	UGame_TileManager* tileManager = UGame_TileManager::Get();

	// get all tiles' imagery data
	for (int32 y = FMath::Min<int32>(SouthEastTile.Value, NorthWestTile.Value); y <= FMath::Max<int32>(SouthEastTile.Value, NorthWestTile.Value); y++)
	{
		for (int32 x = FMath::Min<int32>(SouthEastTile.Key, NorthWestTile.Key); x <= FMath::Max<int32>(SouthEastTile.Key, NorthWestTile.Key); x++)
		{
			FString fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), GetZoomLevel(), x, y);
			
			TPair<int32, int32> tileNumber(x, y);
			IFileManager& fileManager = IFileManager::Get();
			if (!fileManager.FileExists(*fullPathToFile))
			{
				FString tileIdentifier = TileUtilities::GetTileIdentifier(tileNumber, GetZoomLevel(), TEXT("cesiumHeight"), TEXT("quantized-mesh"));
				
				FString requestURL = FString::Printf(TEXT("%s%d/%d/%d.terrain"), *url, GetZoomLevel(), tileNumber.Key, tileNumber.Value);
				
				FHttpModule* http = &FHttpModule::Get();

				TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
				request->SetURL(requestURL);
				request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *accessToken));
				request->AppendToHeader(TEXT("Accept"), TEXT("application/vnd.quantized-mesh,application/octet-stream;q=0.9"));
				request->AppendToHeader(TEXT("email"), FString::Printf(TEXT("%d.%d.%d"), tileNumber.Key, tileNumber.Value, GetZoomLevel()));
				request->SetVerb(TEXT("GET"));

				tileManager->AddHTTPRequest(tileIdentifier, this, request);

				RequestsCounter.Increment();
			}
		}
	}

	// if everything already exists on disk, skip to reading data
	if (RequestsCounter.GetValue() == 0)
	{
		ReadDataFromAllTiles();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_MeshComponent_CesiumIon::OnHTTPRequestComplete(const FString& tileIdentifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
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

		if (!response.IsValid())
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UGame_MeshComponent_CesiumIon::OnHTTPRequestComplete | invalid heightmap received"));

			bValid = false;
		}

		if (response->GetContentAsString().Contains(TEXT("NoSuchKey")))
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_CesiumIon::OnHTTPRequestComplete | received NoSuchKey"));

			bValid = false;
		}

		if (bValid)
		{
			TArray<uint8> content = response->GetContent();
			FString type = response->GetContentType();

			FJsonSerializableArray headers;
			headers = response->GetAllHeaders();

			FJsonSerializableArray other;
			other = headers;

			FString tileID = request->GetHeader(TEXT("email"));

			TArray<FString> parsedID;
			tileID.ParseIntoArray(parsedID, TEXT("."), false);

			TPair<int32, int32> tileNumber;
			tileNumber.Key = FCString::Atoi(*parsedID[0]);
			tileNumber.Value = FCString::Atoi(*parsedID[1]);
			int32 zoomLevel = FCString::Atoi(*parsedID[2]);

			//TileUtilities::WriteTileToDisk(tileNumber, zoomLevel, TEXT("cesiumHeight"), TEXT("quantized-mesh"), content);
			
			FString fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), zoomLevel, tileNumber.Key, tileNumber.Value);
			FFileHelper::SaveArrayToFile(content, *fullPathToFile);
		}

		RequestsCounter.Decrement();

		ReadDataFromAllTiles();

		DestroyCounter.Decrement();
	});
}

void UGame_MeshComponent_CesiumIon::ReadDataFromAllTiles()
{
	if (RequestsCounter.GetValue() != 0)
	{
		return;
	}

	Async(EAsyncExecution::ThreadPool, [this]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		float minHAE = MAX_FLT;
		float maxHAE = MIN_flt;

		TArray<FVector> vertices;
		TArray<int32> triangles;
		TArray<FVector2D> uvs;

		// each mesh can contain data from multiple terrain tiles, which will each have their data stored separately
		for (int32 y = FMath::Min<int32>(SouthEastTile.Value, NorthWestTile.Value); y <= FMath::Max<int32>(SouthEastTile.Value, NorthWestTile.Value); y++)
		{
			for (int32 x = FMath::Min<int32>(SouthEastTile.Key, NorthWestTile.Key); x <= FMath::Max<int32>(SouthEastTile.Key, NorthWestTile.Key); x++)
			{
				FString fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), GetZoomLevel(), x, y);

				TArray<uint8> content;
				if (FFileHelper::LoadFileToArray(content, *fullPathToFile))
				//if (TileUtilities::ReadTileFromDisk(TPair<int32, int32>(x, y), GetZoomLevel(), TEXT("cesiumHeight"), TEXT("quantized-mesh"), content))
				{
					FMemoryReader memReader(content, false);
					memReader.Seek(0);

					// -- header
					FVector tileCenterECEF;
					memReader << tileCenterECEF.X;
					memReader << tileCenterECEF.Y;
					memReader << tileCenterECEF.Z;

					// min/max HAE in meters
					float heightBoundMin;
					float heightBoundMax;
					memReader << heightBoundMin;
					memReader << heightBoundMax;

					FVector2D heightBounds(heightBoundMin, heightBoundMax);

					minHAE = FMath::Min<float>(minHAE, heightBounds.X);
					maxHAE = FMath::Max<float>(maxHAE, heightBounds.Y);

					FVector boundingSphereCenterECEF;
					double boundingSphereRadiusMeters;
					memReader << boundingSphereCenterECEF.X;
					memReader << boundingSphereCenterECEF.Y;
					memReader << boundingSphereCenterECEF.Z;
					memReader << boundingSphereRadiusMeters;

					// unused
					// see http://cesiumjs.org/2013/04/25/Horizon-culling/
					FVector horizonOcclusionPointECEF;
					memReader << horizonOcclusionPointECEF.X;
					memReader << horizonOcclusionPointECEF.Y;
					memReader << horizonOcclusionPointECEF.Z;

					// -- vertex data
					uint32 vertexCount;
					memReader << vertexCount;

					TArray<uint16> uBuffer;
					TArray<uint16> vBuffer;
					TArray<uint16> heightBuffer;

					for (uint32 i = 0; i < vertexCount; i++)
					{
						uint16 u;
						memReader << u;
						uBuffer.Add(u);
					}

					for (uint32 i = 0; i < vertexCount; i++)
					{
						uint16 v;
						memReader << v;
						vBuffer.Add(v);
					}

					for (uint32 i = 0; i < vertexCount; i++)
					{
						uint16 height;
						memReader << height;
						heightBuffer.Add(height);
					}

					// -- zig zag decode
					auto zigZagDecode = [](uint16 value)
					{
						return (value >> 1) ^ (-(value & 1));
					};

					uint16 u = 0;
					uint16 v = 0;
					uint16 height = 0;
					for (uint32 i = 0; i < vertexCount; i++)
					{
						u += zigZagDecode(uBuffer[i]);
						v += zigZagDecode(vBuffer[i]);
						height += zigZagDecode(heightBuffer[i]);

						uBuffer[i] = u;
						vBuffer[i] = v;
						heightBuffer[i] = height;
					}

					// -- determine world position of vertices and add to vertices array
					int32 trianglesOffset = vertices.Num();

					AVH_GlobeReferenceActor* globeReference = GetGlobeReference();

					for (uint32 i = 0; i < vertexCount; i++)
					{
						FGeodeticCoord2D northWestTileCoordinate = GetNorthwestCoordinate(TPair<int32, int32>(x, y), GetZoomLevel());
						FGeodeticCoord2D southEastTileCoordinate = GetNorthwestCoordinate(TPair<int32, int32>(x + 1, y - 1), GetZoomLevel());

						// uAlpha is 0 on western edge
						// vAlpha is 0 on southern edge
						double uAlpha = uBuffer[i] / 32767.f;
						double vAlpha = vBuffer[i] / 32767.f;
						
						FGeodeticCoord3D vertexCoordinate;
						vertexCoordinate.Longitude = FMath::Lerp<double>(northWestTileCoordinate.Longitude, southEastTileCoordinate.Longitude, uAlpha);
						vertexCoordinate.Latitude = FMath::Lerp<double>(southEastTileCoordinate.Latitude, northWestTileCoordinate.Latitude, vAlpha);
						vertexCoordinate.Altitude = FMath::Lerp<double>(heightBounds.X, heightBounds.Y, heightBuffer[i] / 32767.f);

						vertices.Add(globeReference->GeodeticToWorldDouble(vertexCoordinate));

						// -- calculate uv
						FGeodeticCoord2D tileNWBound = GetNorthWestBound();
						FGeodeticCoord2D tileSEBound = GetSouthEastBound();

						double uvU = (vertexCoordinate.Longitude - tileNWBound.Longitude) / (tileSEBound.Longitude - tileNWBound.Longitude);
						double uvV = 1 - ((vertexCoordinate.Latitude - tileSEBound.Latitude) / (tileNWBound.Latitude - tileSEBound.Latitude));

						uvs.Add(FVector2D(uvU, uvV));
					}

					// -- triangles	
					uint32 triangleCount;
					memReader << triangleCount;

					if (vertices.Num() - trianglesOffset > 65536)
					{
						uint32 highest = 0;
						for (uint32 i = 0; i < triangleCount * 3; i++)
						{
							uint32 code;
							memReader << code;
					
							triangles.Add(highest - code + trianglesOffset);

							if (code == 0)
							{
								highest++;
							}
						}
					}
					else
					{
						uint16 highest = 0;
						for (uint32 i = 0; i < triangleCount * 3; i++)
						{
							uint16 code;
							memReader << code;

							triangles.Add(highest - code + trianglesOffset);

							if (code == 0)
							{
								highest++;
							}
						}
					}
				}
			}
		}

		{
			FScopeLock scopeLock(UVsCritSection);
			UVs.Empty();
			UVs.Append(uvs);
		}

		{
			FScopeLock scopeLock(VerticesCritSection);
			Vertices.Empty();
			Vertices.Append(vertices);
		}

		{
			FScopeLock scopeLock(TrianglesCritSection);
			Triangles.Empty();
			Triangles.Append(triangles);
		}

		ApplyDrawDistance();

		DestroyCounter.Decrement();
	});
}

bool UGame_MeshComponent_CesiumIon::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

void UGame_MeshComponent_CesiumIon::GetTileFromGeodetic(const FGeodeticCoord2D& coordinate, int32 zoomLevel, TPair<int32, int32>& tileNumber) const
{
	double spacing = 180.f / (1 << zoomLevel);

	tileNumber.Key = FMath::FloorToInt32((coordinate.Longitude + 180) / spacing);
	tileNumber.Value = FMath::FloorToInt32((coordinate.Latitude + 90) / spacing);
}

FGeodeticCoord2D UGame_MeshComponent_CesiumIon::GetNorthwestCoordinate(const TPair<int32, int32>& tileNumber, int32 zoomLevel) const
{
	FGeodeticCoord2D northWestCorner;
	int32 numTilesY = 1 << zoomLevel;

	northWestCorner.Longitude = (tileNumber.Key / (2.f * (float)numTilesY) * 360.0) - 180.0;
	northWestCorner.Latitude = ((tileNumber.Value + 1) / (float)numTilesY * 180.0) - 90.0;

	return northWestCorner;
}