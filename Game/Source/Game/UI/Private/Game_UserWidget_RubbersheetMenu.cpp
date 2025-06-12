// Required Includes
#include "Game_UserWidget_RubbersheetMenu.h"
#include "Game.h"

// Engine Includes
#include "GenericPlatform/GenericPlatformFile.h"
#include "Misc/FileHelper.h"

// VH Plugin Includes
#include "VH_FileIOStatics.h"
#include "VH_GlobeCoordConverter.h"
#include "VH_UtmCoord.h"

// Game Includes
#include "Game_ImportManager.h"
#include "Game_AdjustableModelImportComponent.h"

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_RubbersheetMenu::ExportToFile(const FString& filename, const FString& entityUID, UGame_AdjustableModelImportComponent* importComponent)
{
	FString zipName = FPaths::GetBaseFilename(filename, true);
	FString archiveFilename = FPaths::Combine(FPaths::GetPath(filename), zipName + TEXT(".zip"));

	IFileManager& fileManager = IFileManager::Get();

	FString stagingPath = FPaths::Combine(FPlatformProcess::UserTempDir(), TEXT("VRTAK"), FString::Printf(TEXT("temp_%s_staging"), *zipName));
	fileManager.DeleteDirectory(*stagingPath, false, true);
	fileManager.MakeDirectory(*stagingPath, true);

	FString zipArchivePath;
	FMD5Hash hash;
	if (UGame_ImportManager::GetZipReference(entityUID, zipArchivePath, hash))
	{
		UVH_FileIOStatics::UnzipFile(zipArchivePath, stagingPath);
		TArray<FString> foundFiles;
		UVH_FileIOStatics::GetFilesInPath(foundFiles, stagingPath, TEXT("prj,xyz"), false, false, true);
		for (FString file : foundFiles)
		{
			fileManager.Delete(*file, true, true, true);
		}
	}
	else
	{
		FString modelSourceLocation = entityUID;
		FString modelDestination = FPaths::Combine(stagingPath, FPaths::GetCleanFilename(modelSourceLocation));

		fileManager.Copy(*modelSourceLocation, *modelDestination, true, true, true);
	}

	// TODO: Need to store this GlobeCoordConverter and config it when making the Load*() request -- or pass it in as a param!.
	UVH_GlobeCoordConverter* globeConverter = NewObject<UVH_GlobeCoordConverter>();
	FUtmCoord utmCoord = globeConverter->GeodeticToUTM(importComponent->GetGeoLocation().ToGeodeticCoord2D());
	double height = importComponent->GetGeoLocation().Altitude;
	FString xyzContent = FString::Printf(TEXT("%.8Lf, %.8Lf, %.8Lf"), utmCoord.Easting, utmCoord.Northing, height);

	FString xyzPath = FPaths::Combine(stagingPath, zipName + TEXT(".xyz"));
	FFileHelper::SaveStringToFile(xyzContent, *xyzPath);

	//"PROJCS[\"WGS 84 / UTM zone %d%s\", GEOGCS[\"WGS 84\", DATUM[\"WGS_1984\", SPHEROID[\"WGS 84\", 6378137, 298.257223563, AUTHORITY[\"EPSG\", \"7030\"]], AUTHORITY[\"EPSG\", \"6326\"]], PRIMEM[\"Greenwich\", 0, AUTHORITY[\"EPSG\", \"8901\"]], UNIT[\"degree\", 0.0174532925199433, AUTHORITY[\"EPSG\", \"9108\"]], AUTHORITY[\"EPSG\", \"4326\"]], PROJECTION[\"Transverse_Mercator\"], PARAMETER[\"central_meridian\", 63], PARAMETER[\"scale_factor\", 0.9996], PARAMETER[\"latitude_of_origin\", 0], PARAMETER[\"false_easting\", 500000], PARAMETER[\"false_northing\", 0], UNIT[\"Meter\", 1], AUTHORITY[\"EPSG\", \"32641\"]]"
	FString prjContent;
	prjContent += TEXT("PROJCS[");
	prjContent += FString::Printf(TEXT("\"WGS 84 / UTM zone %d%s\""), utmCoord.ZoneNumber, *utmCoord.ZoneBand);
	prjContent += TEXT(", GEOGCS[\"WGS 84\"");
	prjContent += TEXT(", DATUM[\"WGS_1984\"");
	prjContent += TEXT(", SPHEROID[\"WGS 84\", 6378137, 298.257223563, AUTHORITY[\"EPSG\", \"7030\"]]");
	prjContent += TEXT(", AUTHORITY[\"EPSG\", \"6326\"]");
	prjContent += TEXT("]");  // DATUM
	prjContent += TEXT(", PRIMEM[\"Greenwich\", 0, AUTHORITY[\"EPSG\", \"8901\"]]");
	prjContent += TEXT(", UNIT[\"degree\", 0.0174532925199433, AUTHORITY[\"EPSG\", \"9108\"]]");
	prjContent += TEXT(", AUTHORITY[\"EPSG\", \"4326\"]");
	prjContent += TEXT("]");  // GEOGCS
	prjContent += TEXT(", PROJECTION[\"Transverse_Mercator\"]");
	prjContent += TEXT(", PARAMETER[\"central_meridian\", 63]");
	prjContent += TEXT(", PARAMETER[\"scale_factor\", 0.9996]");
	prjContent += TEXT(", PARAMETER[\"latitude_of_origin\", 0]");
	prjContent += TEXT(", PARAMETER[\"false_easting\", 500000]");
	prjContent += TEXT(", PARAMETER[\"false_northing\", 0]");
	prjContent += TEXT(", UNIT[\"Meter\", 1]");
	prjContent += TEXT(", AUTHORITY[\"EPSG\", \"32641\"]");
	prjContent += TEXT("]");  // PROJCS

	FString prjPath = FPaths::Combine(stagingPath, zipName + TEXT(".prj"));
	FFileHelper::SaveStringToFile(prjContent, *prjPath);

	TMap<FString, FString> fullPathToNameInZip;
	TArray<FString> allFiles;
	//fileManager.FindFiles(allFiles, *stagingPath, TEXT(""));
	UVH_FileIOStatics::GetFilesInPath(allFiles, stagingPath, TEXT(""), true, false, false);
	for (FString fileName : allFiles)
	{
		FString path = FPaths::Combine(stagingPath, fileName);
		fullPathToNameInZip.Add(path, fileName);
	}

	UVH_FileIOStatics::ZipFile(archiveFilename, fullPathToNameInZip);
	fileManager.DeleteDirectory(*stagingPath, false, true);
}