#pragma once

#include <chrono>

// Engine Includes
#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "Database_Spatialite.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game.h"
#include "Game_GameInstance.h"
#include "Game_Subsystem_Core.h"
#include "Game_TerrainGameInstanceSubsystem.h"

const int64 ONE_WEEK_MILLIS = 7 * 24 * 60 * 60 * 1000;

namespace TileUtilities
{
	inline int64 TimeSinceEpochMillisec()
	{
		using namespace std::chrono;

		return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	}

	inline FString GetFullPathTo(const FString& databaseName)
	{
		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();
		UGame_GameInstance* gi = UGame_GameInstance::Get();

		if (gameSettings != nullptr && gi != nullptr)
		{
			FString fullPathToDB = TEXT("");

			if (FPaths::GetExtension(databaseName).Equals(TEXT("sqlite")))
			{
				fullPathToDB = databaseName;
			}
			else
			{
				FString imageryDirectory = gameSettings->GetSettingString(TEXT("ImageryDirectory"));
				if (!imageryDirectory.EndsWith(TEXT("\\")))
				{
					imageryDirectory += TEXT("\\");
				}

				fullPathToDB = imageryDirectory + databaseName + TEXT(".sqlite");
			}

			return fullPathToDB;
		}

		UE_LOG(Game, Warning, TEXT("-- UGame_TileUtilities::GetPathTo | could not find path | returning empty string"));
		return TEXT("");
	}


	inline UDatabase_Spatialite* GetImageryDB(const FString& databaseName)
	{
		UDatabase_Spatialite* imageryDB = nullptr;

		FString fullPathToDB = GetFullPathTo(databaseName);

		if (UGame_GameInstance* gi = UGame_GameInstance::Get())
		{
			if (UGame_TerrainGameInstanceSubsystem* terrainSubSystem = gi->GetSubsystem<UGame_TerrainGameInstanceSubsystem>())
			{
				imageryDB = terrainSubSystem->GetImageryDB(fullPathToDB);
			}
		}

		if (imageryDB == nullptr)
		{
			UE_LOG(Game, Warning, TEXT("-- TileUtilities::GetImageryDB | imageryDB is nullptr for %s"), *databaseName);
		}

		return imageryDB;
	}

	inline void Disconnect(const FString& sourceName)
	{
		if (UDatabase_Spatialite* db = GetImageryDB(sourceName))
		{
			UGame_GameInstance* gi = UGame_GameInstance::Get();

			if (UGame_TerrainGameInstanceSubsystem* terrainSubsystem = gi->GetSubsystem<UGame_TerrainGameInstanceSubsystem>())
			{
				terrainSubsystem->Disconnect(db);
			}
		}
	}

	inline int64 GetMinIndexFromTAKKey(int zoomLevel)
	{
		if (zoomLevel < 0 || zoomLevel > 28)
			return -1;
		return (int64)zoomLevel << (int64)(zoomLevel * 2);
	}

	inline int64 GetMaxIndexFromTAKKey(int zoomLevel)
	{
		return GetMinIndexFromTAKKey(zoomLevel + 1) - 1;
	}

	inline int32 GetZoomFromTAKKey(int64 index)
	{
		for (int i = 0; i < 29; i++)
			if (index <= GetMaxIndexFromTAKKey(i))
				return i;
		return -1;
	}

	inline int32 GetTileXFromTAKKey(int64 index)
	{
		int zoomLevel = GetZoomFromTAKKey(index);
		if (zoomLevel < 0)
			return -1;
		index >>= zoomLevel;
		index -= (zoomLevel << zoomLevel);
		return (int)index;
	}

	inline int32 GetTileYFromTAKKey(int64 index)
	{
		int zoomLevel = GetZoomFromTAKKey(index);
		if (zoomLevel < 0)
			return -1;
		return (int)((~(0xFFFFFFFFFFFFFFFFL << (int64)zoomLevel)) & index);
	}

	inline FString TileToTAKKey(int32 zoomLevel, float tileX, float tileY)
	{
		int64 tileXInt = FMath::FloorToInt(tileX);
		int64 tileYInt = FMath::FloorToInt(tileY);
		int64 zoom = zoomLevel;

		int64 key = (((zoom << zoom) + tileXInt) << zoom) + tileYInt;

		return FString::Printf(TEXT("%lld"), key);
	}

	inline FString TileToQuadKey(int32 zoomLevel, const float tileX, const float tileY)
	{
		int32 tileXInt = FMath::FloorToInt(tileX);
		int32 tileYInt = FMath::FloorToInt(tileY);

		FString quadKey = TEXT("");
		for (int32 i = zoomLevel; i > 0; i--)
		{
			int32 digit = 0;
			int32 mask = 1 << (i - 1);
			if ((tileXInt & mask) != 0)
			{
				digit++;
			}
			if ((tileYInt & mask) != 0)
			{
				digit += 2;
			}
			quadKey.AppendChar(FString::FromInt(digit).GetCharArray()[0]);
		}

		return quadKey;
	}

	// returns northwest corner of tile (Y starts north, goes south like Google, Bing)
	inline FGeodeticCoord2D GetNorthwestCoordinate(const TPair<int32, int32>& tileNumber, int32 zoomLevel)
	{
		double divisor = FMath::Pow(2.f, zoomLevel);

		FGeodeticCoord2D nwCorner;

		nwCorner.Longitude = (double)tileNumber.Key / divisor * 360.0 - 180.0;

		double latRadians = FMath::Atan(FMath::Sinh(PI * (1.0 - 2.0 * (double)tileNumber.Value / divisor)));
		nwCorner.Latitude = latRadians * (180.0 / PI);

		return nwCorner;
	}

	// returns northwest corner of tile (Y starts south, goes north)
	inline FGeodeticCoord2D GetNorthwestCoordinate_TMS(TPair<int32, int32> tileNumber, int32 zoomLevel, bool bNorthToSouth = false)
	{
		int32 numTilesY = 1 << zoomLevel;

		if (bNorthToSouth)
		{
			tileNumber.Value = numTilesY - tileNumber.Value - 1;
		}

		FGeodeticCoord2D coordinate;

		coordinate.Longitude = tileNumber.Key * 360.0 / (2 * numTilesY) - 180.0;
		coordinate.Latitude = (tileNumber.Value + 1) * 180.0 / numTilesY - 90.0;

		return coordinate;
	}

	inline FString GetTileIdentifier(const TPair<int32, int32>& tileNumber, int32 zoomLevel, const FString& sourceName, const FString& sourceType)
	{
		return FString::Printf(TEXT("%s/%d/%d/%d.%s"), *sourceName, zoomLevel, tileNumber.Key, tileNumber.Value, *sourceType);
	}

	inline bool TileExistsOnDisk(const TPair<int32, int32>& tileNumber, int32 zoomLevel, const FString& sourceName, const FString& sourceType)
	{
		if (UDatabase_Spatialite* db = GetImageryDB(sourceName))
		{
			FString query = TEXT("select name from sqlite_master where type = 'table' and name = \"ATAK_Catalog\"");

			SpatialiteResults results;
			db->SyncQuery(query, results);
			if (results.Num() > 0)
			{
				query = FString::Printf(TEXT("select expiration from ATAK_catalog where key = %s"), *TileToTAKKey(zoomLevel, tileNumber.Key, tileNumber.Value));

				results.Empty();
				db->SyncQuery(query, results);

				if (results.Num() > 0)
				{
					// check if now is greater than expiration
					int64 expiration = UDatabase_Spatialite::GetInteger64(TEXT("expiration"), results[0]);

					if (TimeSinceEpochMillisec() < expiration)
					{
						return true;
					}
				}
			}
			
			// no ATAK_catalog table or no entry in ATAK_catalog for the key
			query = FString::Printf(TEXT("select key from tiles where key = %s"), *TileToTAKKey(zoomLevel, tileNumber.Key, tileNumber.Value));
			
			results.Empty();
			db->SyncQuery(query, results);

			return results.Num() > 0;
		}

		return false;
	}

	inline bool ReadTileFromDisk(const TPair<int32, int32>& tileNumber, int32 zoomLevel, const FString& sourceName, const FString& sourceType, TArray<uint8>& data)
	{
		if (TileExistsOnDisk(tileNumber, zoomLevel, sourceName, sourceType))
		{
			if (UDatabase_Spatialite* db = GetImageryDB(sourceName))
			{
				SpatialiteResults results;
				FString query = FString::Printf(TEXT("select tile from tiles where key = %s"), *TileToTAKKey(zoomLevel, tileNumber.Key, tileNumber.Value));
				db->SyncQuery(query, results);

				if (results.Num() > 0)
				{
					data.Append(UDatabase_Spatialite::GetBlob(TEXT("tile"), results[0]));
					return true;
				}
			}
		}

		//FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- ReadTileFromDisk | not found | zoom: %d | tile: %d, %d"), zoomLevel, tileNumber.Key, tileNumber.Value);
		//UE_LOG(LogTemp, Warning, TEXT("-- ReadTileFromDisk | not found | zoom: %d | tile: %d, %d | key: %s"), zoomLevel, tileNumber.Key, tileNumber.Value, *TileToTAKKey(zoomLevel, tileNumber.Key, tileNumber.Value));

		return false;
	}

	inline bool GetTileMatFromDisk(const TPair<int32, int32>& tileNumber, int32 zoomLevel, const FString& sourceName, const FString& sourceType, cv::Mat& tileMat, bool bTMS = false)
	{
		int32 minZoomLevel = 4;

		// limit how many zoom levels are checked for performance
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			int32 databaseMinZoomLevel = gameSettings->GetSettingInt(TEXT("MinImageryZoomLevel"));
			
			if (zoomLevel > databaseMinZoomLevel)
			{
				minZoomLevel = databaseMinZoomLevel;
			}
		}

		TPair<int32, int32> originalTile = tileNumber;
		int32 originalZoom = zoomLevel;

		TPair<int32, int32> workingTile = tileNumber;
		int32 workingZoom = zoomLevel;

		TArray<uint8> data;
		while (workingZoom >= minZoomLevel)
		{
			if (ReadTileFromDisk(workingTile, workingZoom, sourceName, sourceType, data))
			{
				break;
			}

			workingZoom--;

			workingTile.Key = FMath::FloorToInt(workingTile.Key / 2.f);
			workingTile.Value = FMath::FloorToInt(workingTile.Value / 2.f);
		}

		if (data.Num() == 0)
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- GetTileMatFromDisk | failed: %s | zoom: %d | tile: %d, %d"), *sourceName, zoomLevel, tileNumber.Key, tileNumber.Value);

			return false;
		}

		try
		{
			// populate tileMat
			std::vector<unsigned char> dataVector(data.GetData(), data.GetData() + data.Num());
			tileMat = cv::imdecode(dataVector, cv::IMREAD_UNCHANGED);

			// crop if loaded lower zoom level
			if (workingZoom != originalZoom)
			{
				int32 divisor = (int32)FMath::Pow(2.f, originalZoom - workingZoom);
				
				int32 xSlot = originalTile.Key % divisor;
				int32 ySlot = originalTile.Value % divisor;

				float xLeftPercent = (float)xSlot / divisor;

				float yTopPercent = 0;
				if (bTMS)
				{
					yTopPercent = (1.f / divisor) * ((divisor - 1) - ySlot);
				}
				else
				{
					yTopPercent = (float)ySlot / divisor;
				}

				int32 pixelWidth = tileMat.cols;
				int32 pixelHeight = tileMat.rows;

				cv::Rect rect;
				rect.x = xLeftPercent * pixelWidth;
				rect.y = yTopPercent * pixelHeight;

				rect.width = pixelWidth * (1.f / divisor);
				rect.height = pixelHeight * (1.f / divisor);

				cv::Mat croppedMat = tileMat(rect);

				// resize croppedMat to pixelWidth and pixelHeight
				cv::Mat resizedMat;
				cv::resize(croppedMat, resizedMat, cv::Size(pixelWidth, pixelHeight));

				tileMat = resizedMat.clone();
			}

			return true;
		}
		catch (cv::Exception& e)
		{
			const char* err_msg = e.what();
			UE_LOG(Game, Warning, TEXT("-- GetTileMatFromDisk | zoom: %d | tile: %d, %d | source: %s | opencv error: %s"), zoomLevel, tileNumber.Key, tileNumber.Value, *sourceName, ANSI_TO_TCHAR(err_msg));
		}

		return false;
	}

	// Y coordinates are numbered from north southwards (Google, Bing)
	inline void GetTileFromGeodetic(const FGeodeticCoord2D& coordinate, int32 zoomLevel, TPair<int32, int32>& tileNumber)
	{
		double divisor = FMath::Pow(2.0, zoomLevel);

		double tileX = divisor * ((coordinate.Longitude + 180.0) / 360.0);

		// edge case
		if (coordinate.Longitude == 180)
		{
			tileX -= 1;
		}

		double tileY;
		if (coordinate.Latitude == -90)  // edge case
		{
			tileY = divisor - 1;
		}
		else if (coordinate.Latitude == 90)  // edge case
		{
			tileY = 0;
		}
		else
		{
			double latitude = coordinate.Latitude * (DOUBLE_PI / 180.0);

			tileY = divisor * (1.0 - (FMath::Loge(FMath::Tan(latitude) + (1.0 / FMath::Cos(latitude))) / DOUBLE_PI)) / 2.0;
		}

		tileNumber.Key = FMath::FloorToInt(tileX);
		tileNumber.Value = FMath::FloorToInt(tileY);
	}

	// Y coordinates are numbered from the south northwards for TMS
	inline void GetTileFromGeodetic_TMS(const FGeodeticCoord2D& coordinate, int32 zoomLevel, TPair<int32, int32>& tileNumber, bool bNorthToSouth = false)
	{
		double nY = FMath::Pow<double>(2, zoomLevel);
		double nX = FMath::Pow<double>(2, zoomLevel + 1);

		tileNumber.Key = FMath::FloorToInt(nX * ((coordinate.Longitude + 180.f) / 360.f));
		tileNumber.Value = FMath::FloorToInt(nY * ((coordinate.Latitude + 90.f) / 180.f));

		if (bNorthToSouth)
		{
			tileNumber.Value = nY - tileNumber.Value - 1;
		}
	}

	inline void WriteTileToDisk(const TPair<int32, int32>& tileNumber, int32 zoomLevel, const FString& sourceName, const FString& sourceType, TArray<uint8>& data)
	{
		if (UDatabase_Spatialite* db = GetImageryDB(sourceName))
		{
			FString key = TileToTAKKey(zoomLevel, tileNumber.Key, tileNumber.Value);

			FString query = TEXT("select name from sqlite_master where type = 'table' and name = \"ATAK_catalog\"");

			SpatialiteResults results;
			db->SyncQuery(query, results);
			if (results.Num() > 0)
			{
				int64 timeSinceEpoch = TimeSinceEpochMillisec();

				query = FString::Printf(TEXT("replace into ATAK_catalog (key, access, expiration, size) values (%s, %lld, %lld, %d)"), *key, timeSinceEpoch, timeSinceEpoch + ONE_WEEK_MILLIS, data.Num());
				db->SyncQuery(query);
			}

			query = FString::Printf(TEXT("replace into tiles (key, provider, tile) values (%s, \"%s\", ?)"), *key, *sourceName);

			if (sqlite3_stmt* statement = db->PrepareStatement(query))
			{
				db->BindBlob(statement, data, 1);

				db->SyncQuery(statement);
			}
		}
	}
};  // namespace TileUtilities