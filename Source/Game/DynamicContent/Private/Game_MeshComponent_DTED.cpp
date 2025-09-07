// Required Includes
#include "Game_MeshComponent_DTED.h"
#include "Game.h"

// Engine Includes
#include "Async/Async.h"
#include "HAL/FileManager.h"
#include "Misc/CommandLine.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_GlobeMathStatics.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_FileIOStatics.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_DTEDLibrary.h"
#include "Game_TileManager.h"
#include "Game_TerrainTile.h"
#include "Game_Subsystem_Core.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"

#define ENGINE_API_CACHE ENGINE_API
#undef ENGINE_API
#include "formats/dted/DtedElevationSource.h"
#include "feature/GeometryFactory.h"
#include "elevation/ElevationManager.h"
#include "elevation/ElevationSourceManager.h"
#include "elevation/ElevationSource.h"
#undef ENGINE_API
#define ENGINE_API ENGINE_API_CACHE
#undef ENGINE_API_CACHE

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MeshComponent_DTED::UGame_MeshComponent_DTED()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

bool UGame_MeshComponent_DTED::StaticAutoExtractArchive(const FString& defaultDTEDPath)
{
	IFileManager& fileManager = IFileManager::Get();
	FString archiveFile = TEXT("Data/dted0.exe");
	//FString checkFile = TEXT("Version.txt");
	FString checkFile = TEXT("e000/n05.dt0");

	// NOTE: If the checkFile exists, then this assumes the archive was already extracted on a previous run!
	FString fullPathToCheckFile = FPaths::Combine(defaultDTEDPath, checkFile);
	bool bSuccess = fileManager.FileExists(*fullPathToCheckFile);

	if (!bSuccess)
	{
		// TODO: For now, skip the auto-extract step if "-dev" is not specified on commandline! Consider adding this as an async process in the future.
		if (!FParse::Param(FCommandLine::Get(), TEXT("dev")))
		{
			return false;
		}

		FString fullPathToArchiveFile = FPaths::Combine(FPaths::RootDir(), archiveFile);
		if (fileManager.FileExists(*fullPathToArchiveFile))
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_DTED::AutoExtractArchive | extracting default DTED files | archiveFile: \"%s\" | defaultDTEDPath: \"%s\""), *fullPathToArchiveFile, *defaultDTEDPath);

			// Ensure destination directory exists (before copying file)
			FString tempDir = FPaths::GetPath(defaultDTEDPath);
			if (!fileManager.DirectoryExists(*tempDir))
			{
				fileManager.MakeDirectory(*tempDir, true);
			}

			FString tempArchiveFile = FPaths::Combine(tempDir, FPaths::GetCleanFilename(archiveFile));
			fileManager.Copy(*tempArchiveFile, *fullPathToArchiveFile);
			UDeveloper_Statics::ExecuteFile(*tempArchiveFile, TEXT("-y"), true);
			fileManager.Delete(*tempArchiveFile, false, false);


			bSuccess = fileManager.FileExists(*fullPathToCheckFile);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_DTED::AutoExtractArchive | missing archive file: \"%s\""), *fullPathToArchiveFile);
		}
	}

	if (!bSuccess)
	{
		UE_LOG(Game, Error, TEXT("-- UGame_MeshComponent_DTED::AutoExtractArchive | failed extraction of default DTED files"));
	}

	return bSuccess;
}

bool UGame_MeshComponent_DTED::GetHAE(const FGeodeticCoord2D& coordinate, double& hae)
{
	using namespace TAK::Engine::Formats::DTED;
	using namespace TAK::Engine::Elevation;
	using namespace TAK::Engine::Feature;
	using namespace TAK::Engine::Util;

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString paths = gameSettings->GetSettingString(FString::Printf(TEXT("dted_heightmap.FullPathsToDTED")));

		TArray<FString> potentialDTEDPaths;
		paths.ParseIntoArray(potentialDTEDPaths, TEXT("|"), true);

		for (const FString& potentialDTEDPath : potentialDTEDPaths)
		{
			std::shared_ptr<ElevationSource> elevationSourcePtr;
			if (ElevationSourceManager_findSource(elevationSourcePtr, "DTED") == TAKErr::TE_Ok)
			{
				ElevationSourceManager_detach(*elevationSourcePtr.get());
			}

			std::shared_ptr<DtedElevationSource> dtedElevationSourcePtr = std::make_shared<DtedElevationSource>(TCHAR_TO_ANSI(*potentialDTEDPath));
			ElevationSourceManager_attach(dtedElevationSourcePtr);
			
			ElevationSource::QueryParameters queryParameters;
			queryParameters.spatialFilter = std::move(Geometry2Ptr_const(new Point2(coordinate.Longitude, coordinate.Latitude), Memory_deleter_const<Geometry2>));

			TAK::Engine::Port::String dted("DTED");
			if (ElevationManager_getElevation(&hae, &dted, coordinate.Latitude, coordinate.Longitude, queryParameters) == TAKErr::TE_Ok)
			{
				return true;
			}
		}
	}

	return false;
}

bool UGame_MeshComponent_DTED::GetHeightData(TArray<double>& haeValues, const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, double postSpacingMetersLongitude, double postSpacingMetersLatitude, int32& totalLongitudePosts, int32& totalLatitudePosts)
{
	using namespace TAK::Engine::Formats::DTED;
	using namespace TAK::Engine::Elevation;
	using namespace TAK::Engine::Feature;
	using namespace TAK::Engine::Util;

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString paths = gameSettings->GetSettingString(FString::Printf(TEXT("dted_heightmap.FullPathsToDTED")));

		TArray<FString> potentialDTEDPaths;
		paths.ParseIntoArray(potentialDTEDPaths, TEXT("|"), true);

		for (const FString& potentialDTEDPath : potentialDTEDPaths)
		{
			double westEastMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWestBound, FGeodeticCoord2D(southEastBound.Longitude, northWestBound.Latitude));
			double northSouthMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWestBound, FGeodeticCoord2D(northWestBound.Longitude, southEastBound.Latitude));

			double longitudeDivisor = westEastMeters / postSpacingMetersLongitude;
			double latitudeDivisor = northSouthMeters / postSpacingMetersLatitude;

			double longitudeIncrement = (southEastBound.Longitude - northWestBound.Longitude) / longitudeDivisor;
			double latitudeIncrement = (northWestBound.Latitude - southEastBound.Latitude) / latitudeDivisor;

			// northwest -> southeast
			totalLongitudePosts = 0;
			totalLatitudePosts = 0;
			TArray<double> srcLatitude;
			TArray<double> srcLongitude;
			for (double latitude = northWestBound.Latitude; latitude >= southEastBound.Latitude; latitude -= latitudeIncrement)
			{
				for (double longitude = northWestBound.Longitude; longitude <= southEastBound.Longitude; longitude += longitudeIncrement)
				{
					srcLatitude.Add(latitude);
					srcLongitude.Add(longitude);
									
					if (latitude == northWestBound.Latitude)
					{
						totalLongitudePosts++;
					}

					if (longitude == northWestBound.Longitude)
					{
						totalLatitudePosts++;
					}
				}
			}

			haeValues.Empty();
			haeValues.AddZeroed(totalLongitudePosts * totalLatitudePosts);

			// early out when posts are sufficiently far apart (all 0s for post heights)
			if (postSpacingMetersLongitude > 900)
			{
				return true;
			}

			// required by TAK Kernel
			for (int32 i = 0; i < haeValues.Num(); i++)
			{
				haeValues[i] = std::nan("1");
			}

			std::shared_ptr<ElevationSource> elevationSourcePtr;
			if (ElevationSourceManager_findSource(elevationSourcePtr, "DTED") == TAKErr::TE_Ok)
			{
				ElevationSourceManager_detach(*elevationSourcePtr.get());
			}

			std::shared_ptr<DtedElevationSource> dtedElevationSourcePtr = std::make_shared<DtedElevationSource>(TCHAR_TO_ANSI(*potentialDTEDPath));
			ElevationSourceManager_attach(dtedElevationSourcePtr);

			LineString2 ring;
			ring.addPoint(northWestBound.Longitude, northWestBound.Latitude);
			ring.addPoint(southEastBound.Longitude, northWestBound.Latitude);
			ring.addPoint(southEastBound.Longitude, southEastBound.Latitude);
			ring.addPoint(northWestBound.Longitude, southEastBound.Latitude);
			ring.addPoint(northWestBound.Longitude, northWestBound.Latitude);

			ElevationSource::QueryParameters queryParameters;
			queryParameters.spatialFilter = Geometry2Ptr(new Polygon2(ring), Memory_deleter_const<Geometry2>);

			TAKErr error = ElevationManager_getElevation(haeValues.GetData(), haeValues.Num(), srcLatitude.GetData(), srcLongitude.GetData(), 1, 1, 1, queryParameters);
			if (error == TAKErr::TE_Ok || error == TAKErr::TE_Done)
			{
				// todo ohg | check with Chris about returning TE_Done (I think this shouldn't be considered success)
				return true;
			}
		}
	}

	return false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MeshComponent_DTED::ExecuteHelperThreadLogic()
{
	using namespace TAK::Engine::Formats::DTED;
	using namespace TAK::Engine::Elevation;
	using namespace TAK::Engine::Feature;
	using namespace TAK::Engine::Util;
	using namespace TAK::Engine::DB;
	using namespace TAK::Engine::Raster::Mosaic;

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

				AVH_GlobeReferenceActor* globeRef = GetGlobeReference();
				if (globeRef == nullptr)
				{
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

				TArray<double> haeValues;
				int32 totalLongitudePosts = 0;
				int32 totalLatitudePosts = 0;
				if (GetHeightData(haeValues, GetNorthWestBound(), GetSouthEastBound(), postSpacingMeters, postSpacingMeters, totalLongitudePosts, totalLatitudePosts))
				{
					// determine xStepUU and yStepUU
					FGeodeticCoord2D nwCoord = GetNorthWestBound();
					FGeodeticCoord2D seCoord = GetSouthEastBound();
					FGeodeticCoord2D swCoord(nwCoord.Longitude, seCoord.Latitude);

					TArray<FVector> vertices;
					TArray<FVector2D> uvs;

					HAEBounds = FVector2D(9999999, -9999999);

					// vertex for each post
					for (int32 y = 0; y < totalLatitudePosts; y++)
					{
						for (int32 x = 0; x < totalLongitudePosts; x++)
						{
							int32 index = (y * totalLongitudePosts) + x;

							double hae = haeValues[index];

							if (hae > -12000 || hae < 9000) // valid heights according to dted specification
							{
								// northwest -> southeast
								FGeodeticCoord3D vertexCoordinate;
								vertexCoordinate.Longitude = FMath::Lerp<double>(swCoord.Longitude, seCoord.Longitude, x / (totalLongitudePosts - 1.f));
								vertexCoordinate.Latitude = FMath::Lerp<double>(nwCoord.Latitude, swCoord.Latitude, y / (totalLatitudePosts - 1.f));
								vertexCoordinate.Altitude = hae;

								vertices.Add(globeRef->GeodeticToWorldDouble(vertexCoordinate));

								HAEBounds.X = FMath::Min<double>(HAEBounds.X, hae);
								HAEBounds.Y = FMath::Max<double>(HAEBounds.Y, hae);

								float uvX = (float)x / (float)(totalLongitudePosts - 1);
								float uvY = (float)y / (float)(totalLatitudePosts - 1);
								uvs.Add(FVector2D(uvX, uvY));
							}
						}
					}

					// generate triangles
					TArray<int32> triangles;
					for (int32 y = 0; y < totalLatitudePosts; y++)
					{
						for (int32 x = 0; x < totalLongitudePosts - 1; x++)
						{
							if (y > 0)
							{
								int32 start = y * totalLongitudePosts;

								int32 bottomLeft = start + x;
								int32 bottomRight = start + x + 1;
								int32 topRight = start - totalLongitudePosts + x + 1;
								int32 topLeft = start - totalLongitudePosts + x;

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

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_MeshComponent_DTED::GetDTEDInfo(FGeodeticCoord2D coordinate, int32& dtedLevel) const
{
	if (coordinate.Longitude >= 180)
	{
		coordinate.Longitude -= 360;
	}

	// prepend 0s (2 digits for lat, 3 digits for long)
	FString longitudeText = FString::Printf(TEXT("%d"), FMath::Abs<int32>(coordinate.Longitude));
	for (int32 i = longitudeText.Len(); i < 3; i++)
	{
		longitudeText = TEXT("0") + longitudeText;
	}

	FString latitudeText = FString::Printf(TEXT("%d"), FMath::Abs<int32>(coordinate.Latitude));
	for (int32 i = latitudeText.Len(); i < 2; i++)
	{
		latitudeText = TEXT("0") + latitudeText;
	}

	// prepend direction
	if (coordinate.Longitude < 0)
	{
		longitudeText = TEXT("w") + longitudeText;
	}
	else
	{
		longitudeText = TEXT("e") + longitudeText;
	}

	if (coordinate.Latitude < 0)
	{
		latitudeText = TEXT("s") + latitudeText;
	}
	else
	{
		latitudeText = TEXT("n") + latitudeText;
	}

	TArray<FString> potentialFilePaths;

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString paths = gameSettings->GetSettingString(FString::Printf(TEXT("dted_heightmap.FullPathsToDTED")));

		paths.ParseIntoArray(potentialFilePaths, TEXT("|"), true);

		for (int32 i = 0; i < potentialFilePaths.Num(); i++)
		{
			potentialFilePaths[i] = FPaths::Combine(potentialFilePaths[i], longitudeText, latitudeText);
		}
	}

	// use highest level dted
	FString fullPathToFile = TEXT("");
	bool bFoundDTED = false;
	for (int32 i = 5; i >= 0; i--)
	{
		if (!bFoundDTED)
		{
			for (int j = 0; j < potentialFilePaths.Num(); j++)
			{
				fullPathToFile = potentialFilePaths[j];

				FString fileToCheck = FString::Printf(TEXT("%s.dt%d"), *fullPathToFile, i);

				if (FPaths::FileExists(*fileToCheck))
				{
					fullPathToFile = fileToCheck;
					bFoundDTED = true;

					dtedLevel = i;

					break;
				}
			}
		}
	}

	if (!bFoundDTED)
	{
		// fallback to default path
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			fullPathToFile = gameSettings->GetDefaultSettingString(TEXT("dted_heightmap.FullPathsToDTED"));
			fullPathToFile = FPaths::Combine(fullPathToFile, longitudeText, latitudeText);

			for (int32 i = 5; i >= 0; i--)
			{
				if (!bFoundDTED)
				{
					FString fileToCheck = FString::Printf(TEXT("%s.dt%d"), *fullPathToFile, i);

					if (FPaths::FileExists(*fileToCheck))
					{
						fullPathToFile = fileToCheck;
						bFoundDTED = true;

						dtedLevel = i;

						break;
					}
				}
			}
		}
	}

	return bFoundDTED;
}