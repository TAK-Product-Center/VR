// Required Includes
#include "Game_ImportManager.h"
#include "Game.h"

// Engine Includes
#include "Serialization/BufferArchive.h"
#include "XmlFile.h"
#include "Misc/ScopeLock.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "VH_GlobeCoordConverter.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_Subsystem_Core.h"
#include "Developer_Subsystem_Notification.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "VH_COTManager.h"
#include "UI_Subsystem_Core.h"
#include "UI_Statics.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_HandlerService.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Subsystem_Core.h"
#include "Game_GameInstance.h"

UGame_ImportManager* UGame_ImportManager::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ImportManager::UGame_ImportManager()
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		GlobalInstance = this;
	}
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_ImportManager* UGame_ImportManager::Get()
{
    UGame_ImportManager* instance = UGame_ImportManager::GlobalInstance;
    
	return instance != nullptr && instance->IsValidLowLevel() ? instance : nullptr;
}

void UGame_ImportManager::ExtractIfNecessary(const FString& entityUID, const FString& fullPathToFile)
{
	IFileManager& fileManager = IFileManager::Get();
	
	if (!fileManager.FileExists(*fullPathToFile))
	{
		FString fullPathToZipArchive;
		FMD5Hash md5Hash;
		if (GetZipReference(entityUID, fullPathToZipArchive, md5Hash))
		{
			if (fileManager.FileExists(*fullPathToZipArchive))
			{
				FString extractDir = FString(FPlatformProcess::UserTempDir()) / TEXT("VRTAK") / FPaths::GetBaseFilename(fullPathToZipArchive);

				if (fileManager.DirectoryExists(*extractDir))
				{
					fileManager.DeleteDirectory(*extractDir, false, true);
					while (fileManager.DirectoryExists(*extractDir))
					{
						// Wait for OS to entirely delete the dir!
						// TODO: This should be async instead -- or add a "bool bDeleteDir" to UnzipFile() so it can be done async in there!
						FPlatformProcess::Sleep(0.1f);
					}

					// Still need to wait a little longer after the while() loop!
					FPlatformProcess::Sleep(0.1f);
				}

				UVH_FileIOStatics::UnzipFile(fullPathToZipArchive, extractDir);
				RecursivelyExtractZipArchives(extractDir, true);
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_ImportManager::ExtractIfNecessary | could not find original zip to re-extract | aborting"));

				// todo ohg | notify user
			}
		}
	}
}

bool UGame_ImportManager::GetZipReference(const FString& entityUID, FString& fullPathToZipArchive, FMD5Hash& md5Hash)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			return GetZipReference(results[0], fullPathToZipArchive, md5Hash);
		}
	}

	return false;
}

bool UGame_ImportManager::GetZipReference(const FSpatialiteResult_BP& result, FString& fullPathToZipArchive, FMD5Hash& md5Hash)
{
	return GetZipReference(result.Result, fullPathToZipArchive, md5Hash);
}

bool UGame_ImportManager::GetZipReference(const SpatialiteResult& result, FString& fullPathToZipArchive, FMD5Hash& md5Hash)
{
	bool bError = false;

	TArray<uint8> blob = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

	FMemoryReader fromBinary = FMemoryReader(blob);
	if (fromBinary.TotalSize() > sizeof(int64))
	{
		fromBinary.Seek(fromBinary.TotalSize() - sizeof(int64));

		int64 offsetBefore;
		fromBinary << offsetBefore;

		if (offsetBefore >= 0 && offsetBefore < fromBinary.TotalSize())
		{
			fromBinary.Seek(offsetBefore);

			fromBinary << fullPathToZipArchive;
			bError = fromBinary.IsError() || fromBinary.IsCriticalError();
			
			if (!bError)
			{
				fromBinary << md5Hash;
			}

			bError = fromBinary.IsError() || fromBinary.IsCriticalError();
		}
		else
		{
			bError = true;
		}
	}
	else
	{
		bError = true;
	}

	if (bError)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		FString categoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), result);

		UE_LOG(Game, Warning, TEXT("-- UGame_ImportManager::GetZipReference | invalid blob data; most likely need to clear entity from database | uid: %s | category: %s"), *entityUID, *categoryID);

		fullPathToZipArchive = TEXT("");
	}
	
	return !fullPathToZipArchive.IsEmpty();
}

void UGame_ImportManager::AddZipReferenceToData(const FString& entityUID, const FString& fullPathToZipArchive)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			TArray<uint8> blob = UDatabase_Spatialite::GetBlob(TEXT("data"), results[0]);

			FBufferArchive toBinary;
			toBinary.Serialize(blob.GetData(), blob.Num());
			toBinary.Seek(toBinary.TotalSize());

			int64 offsetBefore = toBinary.Tell();

			FMD5Hash md5hash = FMD5Hash::HashFile(*fullPathToZipArchive);

			FString pathToZip = fullPathToZipArchive;
			toBinary << pathToZip;
			toBinary << md5hash;
			toBinary << offsetBefore;
			
			TArray<uint8> data = (TArray<uint8>&)toBinary;
			
			entityDB->SetData(entityUID, data);
		}
	}
}

void UGame_ImportManager::AddZipReferenceToData(FBufferArchive& toBinary, const FString& fullPathToZipArchive)
{
	int64 offsetBefore = toBinary.Tell();

	FMD5Hash md5hash = FMD5Hash::HashFile(*fullPathToZipArchive);

	FString pathToZip = fullPathToZipArchive;
	toBinary << pathToZip;
	toBinary << md5hash;
	toBinary << offsetBefore;
}

bool UGame_ImportManager::GetGeoLocationForFile(const FString& fullPathToFile, FGeodeticCoord3D& coordinate)
{
	FString path = FPaths::GetPath(fullPathToFile);
	FPaths::NormalizeDirectoryName(path);

	// To avoid bubbling up and testing every file in the Temp/ dir, strip out entire path to "Temp/VTAK/", if present.
	// TODO: Consider passing in a root path to strip out -- then it would work for other root dirs too.
	FString tempPath = FPaths::Combine(FPlatformProcess::UserTempDir(), TEXT("VRTAK"));
	FString tempRelativePath;
	FPaths::NormalizeDirectoryName(tempPath);
	bool bIsInTempPath = path.StartsWith(tempPath, ESearchCase::IgnoreCase);
	if (bIsInTempPath)
	{
		tempRelativePath = path.Replace(*tempPath, TEXT(""), ESearchCase::IgnoreCase);
	}

	while (!path.IsEmpty() && !(bIsInTempPath && tempRelativePath.IsEmpty()))
	{
		TArray<FString> files;
		UVH_FileIOStatics::GetFilesInPath(files, path, TEXT(""), false, true, true);

		for (const FString& file : files)
		{
			if (GetGeoLocationFromFile(file, coordinate))
			{
				return true;
			}
		}

		// returns empty when at root directory
		path = FPaths::GetPath(path);
		tempRelativePath = bIsInTempPath ? FPaths::GetPath(tempRelativePath) : TEXT("");
	}

	return false;
}

void UGame_ImportManager::RecursivelyExtractZipArchives(const FString& fullPath, bool bDeleteZipArchives)
{
	IFileManager& fileManager = IFileManager::Get();

	TArray<FString> files;
	UVH_FileIOStatics::GetFilesInPath(files, fullPath, TEXT(""), true, true, true);

	bool bRunAgain = false;
	for (const FString& file : files)
	{
		if (UVH_FileIOStatics::IsZipArchive(file))
		{
			FString extractDir = FPaths::GetPath(file) / FPaths::GetBaseFilename(file);
			UVH_FileIOStatics::UnzipFile(file, extractDir);

			if (bDeleteZipArchives)
			{
				fileManager.Delete(*file);
			}

			bRunAgain = true;
		}
	}

	if (bRunAgain)
	{
		RecursivelyExtractZipArchives(fullPath, bDeleteZipArchives);
	}
}


void UGame_ImportManager::OpenImportDialog()
{
	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();
		bool bDesktopFileBrowserDisabled = IsValid(gameSettings) ? gameSettings->GetSettingBool(TEXT("DisableDesktopFileBrowser")) : false;

		if (subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::VR || subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::VREmulation || bDesktopFileBrowserDisabled)
		{
			// VR implementation
			UUI_Subsystem_Core::Get()->OpenWithDefaultsByClass(ImportManagerWidgetClass);
		}
		else
		{
			// Desktop implementation
			TMap<FString, FString> fileTypesFilter;
			fileTypesFilter.Add(TEXT("All Known Types"), TEXT("*.obj;*.fbx;*.3ds;*.dae;*.blend;*.kml;*.kmz;*.xml;*.las;*.e57;*.pts;*.txt;*.xyz;*.nc;*.b3dm;*.zip,*.7z"));
			fileTypesFilter.Add(TEXT("Alias Wavefront Model"), TEXT("*.obj"));
			fileTypesFilter.Add(TEXT("Autodesk Model"), TEXT("*.fbx;*.3ds"));
			fileTypesFilter.Add(TEXT("COLLADA Model"), TEXT("*.dae"));
			fileTypesFilter.Add(TEXT("Blender Model"), TEXT("*.blend"));
			fileTypesFilter.Add(TEXT("Google Earth"), TEXT("*.kml;*.kmz"));
			fileTypesFilter.Add(TEXT("Point Cloud"), TEXT("*.las;*.e57;*.pts;*.txt;*.xyz"));
			fileTypesFilter.Add(TEXT("NetCDF"), TEXT("*.nc"));
			fileTypesFilter.Add(TEXT("Batched 3D Model"), TEXT("*.b3dm"));
			fileTypesFilter.Add(TEXT("Zip"), TEXT("*.zip;*.7z"));
			fileTypesFilter.Add(TEXT("All Files"), TEXT("*.*"));

			FString defaultPath = IsValid(gameSettings) ? gameSettings->GetSettingString(TEXT("ImportMgrLastDir")) : TEXT("");

			UUI_Statics::OpenNativeFileBrowserDialogAsync(TEXT("Import File"), defaultPath, fileTypesFilter, false, [this](bool bSuccess, const TArray<FString>& outFiles)
			{
				if (bSuccess)
				{
					UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

					if (IsValid(gameSettings) && outFiles.Num() > 0)
					{
						gameSettings->StoreSettingString(TEXT("ImportMgrLastDir"), FPaths::GetPath(outFiles[0]));
					}

					for (const FString& outFile : outFiles)
					{
						RegisterFileToDatabase(outFile);
						UGame_GameInstance::Get()->MUC_AddCreatedEntityUID(FName(outFile));
					}
				}
			});
		}
	}
}

FString UGame_ImportManager::StringFromBlob(const uint8* srcBuffer, uint32 srcSize)
{
    FString result;
    result.Reserve(srcSize * 3);

    // Convert and append each byte in the buffer
    for (uint32 count = 0; count < srcSize; count++)
    {
        result += FString::Printf(TEXT("%c"), (uint8)srcBuffer[count]);
    }

    return result;
}

void UGame_ImportManager::LoadCoordinatesFromPRJ(const FString& prjFile, const FString& offsetFile, FUtmCoord& outCoord, double& outAltitude)
{
	outCoord = FUtmCoord();
	outAltitude = 0;

    FString normalizedPrjFile = prjFile;
    FPaths::NormalizeFilename(normalizedPrjFile);
    UDeveloper_Statics::FixedCollapseRelativeDirectoriesInline(normalizedPrjFile);

    FString fullPrjFile = FPaths::IsRelative(normalizedPrjFile) ? FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectContentDir(), normalizedPrjFile)) : normalizedPrjFile;
    if (!FPaths::FileExists(fullPrjFile))
    {
        UDeveloper_Statics::PrintMessageWarning(FString::Printf(TEXT("File not found: \"%s\""), *fullPrjFile));
    }

    FString normalizedOffsetFile = offsetFile;
    FPaths::NormalizeFilename(normalizedOffsetFile);
    UDeveloper_Statics::FixedCollapseRelativeDirectoriesInline(normalizedOffsetFile);

    FString fullOffsetFile = FPaths::IsRelative(normalizedOffsetFile) ? FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectContentDir(), normalizedOffsetFile)) : normalizedOffsetFile;
    if (!FPaths::FileExists(fullOffsetFile))
    {
        UDeveloper_Statics::PrintMessageWarning(FString::Printf(TEXT("File not found: \"%s\""), *fullOffsetFile));
    }

    TArray<FString> files;
    files.Add(fullPrjFile);
    files.Add(fullOffsetFile);

    FString UTMZoneID = TEXT("");

    FVector offset = FVector::ZeroVector;

    int32 numErrors = 0;
    for (const FString& file : files)
    {
        bool isPrj = (FPaths::GetExtension(file, false).Equals(TEXT("prj"), ESearchCase::IgnoreCase));

        FString fullFilename = FPaths::IsRelative(file) ? FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectContentDir(), file)) : file;

        // Check if the file exists first
        if (!FPaths::FileExists(fullFilename))
        {
            UDeveloper_Statics::PrintMessageWarning(FString::Printf(TEXT("File not found: %s"), *fullFilename));
            numErrors++;
            continue;
        }

        // Load the compressed byte data from the file
        TArray<uint8> FileData;
        if (!FFileHelper::LoadFileToArray(FileData, *fullFilename))
        {
            UDeveloper_Statics::PrintMessageWarning(FString::Printf(TEXT("Failed to load file: %s"), *fullFilename));
            numErrors++;
            continue;
        }

		// TODO: For now, we're parsing the file(s), looking for specific tags and assuming a given projection. ASAP, this should be updated 
		//		 to read UTM (prj and offset) files with something like GDAL.
		if (isPrj)
        {
            FString dataString = StringFromBlob(&FileData[0], FileData.Num());

            int32 pos = -1;
            int32 pos2 = 0;
			FString tag = TEXT("PROJCS[");
			FString value = TEXT("");

            pos2 = dataString.Find(tag, ESearchCase::IgnoreCase, ESearchDir::FromStart, pos);
            if (pos2 > pos)
            {
                pos = pos2 + tag.Len();
                pos2 = dataString.Find(TEXT(","), ESearchCase::IgnoreCase, ESearchDir::FromStart, pos);
                if (pos2 > pos)
                {
                    value = dataString.Mid(pos, pos2 - pos);
                    value = value.TrimQuotes();

                    TArray<FString> utmZonePrefixes = {
                        TEXT("UTM zone "),
                        TEXT("WGS_1984_UTM_Zone_")};
                    for (FString prefix : utmZonePrefixes)
                    {
                        if (value.Contains(prefix))
                        {
                            int32 utmPos = value.Find(prefix, ESearchCase::IgnoreCase);
                            if (utmPos >= 0)
                            {
                                UTMZoneID = value.Mid(utmPos + prefix.Len());
								outCoord.ZoneNumber = FCString::Atoi(*UTMZoneID.LeftChop(1));
								outCoord.ZoneBand = UTMZoneID.Right(1);
                            }

                            break;
                        }
                    }
                }
            }
        }
        else
        {
            FString dataString = StringFromBlob(&FileData[0], FileData.Num());

            TArray<FString> dataArray;
            const TCHAR* delimiters[] = {TEXT(","), TEXT(" ")};
            dataString.ParseIntoArray(dataArray, delimiters, sizeof(delimiters) / sizeof(TCHAR*), true);

            for (int i = 0; i < 3 && dataArray.IsValidIndex(i); i++)
            {
                offset[i] = FCString::Atod(*dataArray[i]);
				outAltitude = offset.Z;
            }
        }
    }

    if (numErrors == 0)
    {
		// TODO: Need to store this GlobeCoordConverter and config it when making the Load*() request -- or pass it in as a param!.
		outCoord.Easting = offset.X;
		outCoord.Northing = offset.Y;
	}

    //UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("Coordinates:")), false, false, true, false, ELogMessageColor::Cyan);
    //UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("  UTM -- zone: %s, offset: %s"), *UTMZoneID, *offset.ToString()), false, false, true, false, ELogMessageColor::Cyan);
}


// ---------------------------------
// --- API
// ---------------------------------

bool UGame_ImportManager::GetGeoLocationFromFile(const FString& fullPathToFile, FGeodeticCoord3D& coordinate)
{
	auto verifyXYZ = [](const FString& xyzFile)
	{
		TArray<FString> fileContents;
		FFileHelper::LoadFileToStringArray(fileContents, *xyzFile);
		
		return fileContents.Num() == 1;
	};

	auto checkForPRJ = [fullPathToFile, verifyXYZ](const FString& path, const FString& extension, FGeodeticCoord3D& outCoordinate)
	{
		FString prjFile = TEXT("");
		FString offsetFile = TEXT("");

		if (extension.Equals(TEXT("prj")))
		{
			// it's a prj; look for corresponding xyz or ofs
			prjFile = fullPathToFile;

			TArray<FString> files;
			UVH_FileIOStatics::GetFilesInPath(files, path, TEXT("xyz,ofs"), true, true, true);
			for (const FString& file : files)
			{
				// xyz can also be pointcloud files, verify it's valid before using
				if (FPaths::GetExtension(file).ToLower().Equals(TEXT("xyz")))
				{
					if (verifyXYZ(file))
					{
						offsetFile = file;
						break;
					}
				}
				else
				{
					offsetFile = file;
					break;
				}
			}
		}
		else if (extension.Equals(TEXT("xyz")) || extension.Equals(TEXT("ofs")))
		{
			// xyz can also be pointcloud files, verify it's valid before using
			if (extension.Equals(TEXT("xyz")) && !verifyXYZ(fullPathToFile))
			{
				return false;
			}

			// it's an offset; look for corresponding prj
			offsetFile = fullPathToFile;

			TArray<FString> files;
			UVH_FileIOStatics::GetFilesInPath(files, path, TEXT("prj"), true, true, true);
			if (files.Num() > 0)
			{
				// use first prj file found
				prjFile = files[0];
			}
		}

		if (!prjFile.IsEmpty() && !offsetFile.IsEmpty())
		{
			FUtmCoord outCoord;
			double outAltitude;
			LoadCoordinatesFromPRJ(prjFile, offsetFile, outCoord, outAltitude);

			if(outCoord.ZoneNumber == 0)
			{
				return false;
			}
			
			UVH_GlobeCoordConverter* globeConverter = NewObject<UVH_GlobeCoordConverter>();
			FGeodeticCoord2D geodeticCoords = globeConverter->UTMToGeodetic(outCoord);
			outCoordinate = FGeodeticCoord3D(geodeticCoords.Longitude, geodeticCoords.Latitude, outAltitude);
			globeConverter->ConditionalBeginDestroy();

			return true;
		}

		return false;
	};

	auto checkForXML = [fullPathToFile](const FString& path, const FString& extension, FGeodeticCoord3D& outCoordinate)
	{
		if (extension.Equals(TEXT("xml")))
		{
			FXmlFile xml(fullPathToFile);
			if (xml.IsValid())
			{
				FString projectionType = TEXT("");

				FXmlNode* xmlRoot = xml.GetRootNode();
				if (xmlRoot->GetTag().Equals(TEXT("ModelMetadata"), ESearchCase::IgnoreCase))
				{
					if (FXmlNode* srsNode = xmlRoot->FindChildNode(TEXT("SRS")))
					{
						// <SRS>ENU:35.12280463,-79.16254296</SRS>
						FString nodeContent = srsNode->GetContent();

						TArray<FString> params;
						if (nodeContent.ParseIntoArray(params, TEXT(":"), true) >= 2)
						{
							projectionType = params[0];
							FString geoLoc = params[1];

							if (geoLoc.ParseIntoArray(params, TEXT(","), true) >= 2)
							{
								// purposefully swapped
								outCoordinate = FGeodeticCoord3D(FCString::Atod(*params[1]), FCString::Atod(*params[0]), 0);
							}
						}
					}
					else
					{
						return false;
					}

					// only using altitude
					if (projectionType.Equals(TEXT("ENU"), ESearchCase::IgnoreCase))
					{
						if (FXmlNode* srsOriginNode = xmlRoot->FindChildNode(TEXT("SRSOrigin")))
						{
							// <SRSOrigin>981971.3092,-5129452.912,3649018.779</SRSOrigin>
							FString nodeContent = srsOriginNode->GetContent();

							TArray<FString> params;
							if (nodeContent.ParseIntoArray(params, TEXT(","), true) >= 3)
							{
								FVector srsOriginLocation = FVector(FCString::Atod(*params[0]), FCString::Atod(*params[1]), FCString::Atod(*params[2]));
								
								if (srsOriginLocation.Size() > 100000.0)
								{
									UE_LOG(Game, Warning, TEXT("-- SRSOrigin is very large, likely ECEF instead of ENU | %s | file: %s"), *srsOriginLocation.ToString(), *fullPathToFile);

									srsOriginLocation = FVector::ZeroVector;
								}

								outCoordinate.Altitude = UVH_GlobeMathStatics::MSLToHAE(outCoordinate.ToGeodeticCoord2D(), srsOriginLocation.Z);
							}
						}
					}

					return true;
				}
			}
		}

		return false;
	};

	FString path = FPaths::GetPath(fullPathToFile);
	FString extension = FPaths::GetExtension(fullPathToFile).ToLower();
	
	if (checkForPRJ(path, extension, coordinate))
	{
		return true;
	}
	else if (checkForXML(path, extension, coordinate))
	{
		return true;
	}
	else
	{
		if (UGame_ImportManager* importManager = Cast<UGame_ImportManager>(UGame_ImportManager::Get()))
		{
			for (const FGetGeoLocationFromFile& getGeoLocationFromFileLambda : importManager->GetGeoLocationFromFileLambdas)
			{
				if (getGeoLocationFromFileLambda.Execute(fullPathToFile, coordinate))
				{
					return true;
				}
			}
		}
	}

	return false;
}

void UGame_ImportManager::RegisterFileToDatabase(const FString& fullPathToFile)
{
	if (!FPaths::FileExists(fullPathToFile))
	{
		UE_LOG(Game, Error, TEXT("-- UGame_ImportManager::RegisterFileToDatabase | file does not exist: \"%s\""), *fullPathToFile);
		HandleRegisterFail(fullPathToFile);
		return;
	}

	if (UVH_FileIOStatics::IsZipArchive(fullPathToFile))
	{
		// early out for datapackages
		if (UVH_FileIOStatics::DirectoryOrFileExistsInZip(fullPathToFile, TEXT("manifest.xml"), false))
		{
			if (UVH_COTManager* cotManager = UVH_COTManager::Get())
			{
				cotManager->LoadDataPackageFromDisk(fullPathToFile, true);
			}

			return;
		}
		
		// it's a zip; extract and register all extracted files
		FString extractDir = FString(FPlatformProcess::UserTempDir()) / TEXT("VRTAK") / FPaths::GetBaseFilename(fullPathToFile);
	
		IFileManager& fileManager = IFileManager::Get();
		if (fileManager.DirectoryExists(*extractDir))
		{
			fileManager.DeleteDirectory(*extractDir, false, true);
			while (fileManager.DirectoryExists(*extractDir))
			{
				// Wait for OS to entirely delete the dir!
				// TODO: This should be async instead -- or add a "bool bDeleteDir" to UnzipFile() so it can be done async in there!
				FPlatformProcess::Sleep(0.1f);
			}

			// Still need to wait a little longer after the while() loop!
			FPlatformProcess::Sleep(0.1f);
		}

		UVH_FileIOStatics::UnzipFile(fullPathToFile, extractDir);
		RecursivelyExtractZipArchives(extractDir, true);
		
		RegisterDirectoryToDatabase(extractDir, fullPathToFile);
	}
	else
	{
		UGame_HandlerService* handlerService = UGame_HandlerService::Get();
		if (handlerService == nullptr)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_ImportManager::RegisterFileToDatabase | handlerService is nullptr | aborting"));
			return;
		}

		TSet<FString> registeredEntityUIDs;
		bool bRegistered = handlerService->RegisterFileToDatabaseFirstPass(fullPathToFile, registeredEntityUIDs);
		if (!bRegistered)
		{
			bRegistered = handlerService->RegisterFileToDatabaseSecondPass(fullPathToFile, registeredEntityUIDs);
		}

		if (bRegistered)
		{
			for (const FString& entityUID : registeredEntityUIDs)
			{
				AddZipReferenceToData(entityUID, TEXT(""));
			}

			HandleRegisterSuccess(handlerService, fullPathToFile);
		}
		else
		{
			HandleRegisterFail(fullPathToFile);
		}
	}
}

void UGame_ImportManager::RegisterDirectoryToDatabase(const FString& fullPath)
{
	RegisterDirectoryToDatabase(fullPath, TEXT(""));
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_ImportManager::RegisterDirectoryToDatabase(const FString& fullPath, const FString& fullPathToZipArchive)
{
	auto isChildPath = [](const FString& childPath, const TSet<FString>& registeredPaths)
	{
		if (registeredPaths.Contains(childPath))
		{
			return true;
		}

		for (const FString& registeredPath : registeredPaths)
		{
			FString path = FPaths::GetPath(childPath);

			while (!path.IsEmpty())
			{
				if (path.Equals(registeredPath))
				{
					return true;
				}

				path = FPaths::GetPath(path);
			}
		}

		return false;
	};

	UGame_HandlerService* handlerService = UGame_HandlerService::Get();
	if (handlerService == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportManager::RegisterDirectoryToDatabase | handlerService is nullptr | aborting"));
		return;
	}
	
	TArray<FString> files;
	UVH_FileIOStatics::GetFilesInPath(files, fullPath, TEXT(""), true, true, true);

	TSet<FString> registeredPaths;
	for (const FString& file : files)
	{
		FString path = FPaths::GetPath(file);
		if (!isChildPath(path, registeredPaths))
		{
			TSet<FString> registeredEntityUIDs;
			if (handlerService->RegisterFileToDatabaseFirstPass(file, registeredEntityUIDs))
			{
				for (const FString& entityUID : registeredEntityUIDs)
				{
					AddZipReferenceToData(entityUID, fullPathToZipArchive);
				}

				HandleRegisterSuccess(handlerService, file);

				registeredPaths.Add(path);
			}
		}
	}
	
	for (const FString& file : files)
	{
		if (!isChildPath(FPaths::GetPath(file), registeredPaths))
		{
			TSet<FString> registeredEntityUIDs;
			if (handlerService->RegisterFileToDatabaseSecondPass(file, registeredEntityUIDs))
			{
				for (const FString& entityUID : registeredEntityUIDs)
				{
					AddZipReferenceToData(entityUID, fullPathToZipArchive);
				}

				HandleRegisterSuccess(handlerService, file);
			}
			else
			{
				HandleRegisterFail(file);
			}
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_ImportManager::HandleRegisterSuccess(UGame_HandlerService* handlerService, const FString& fullPathToFile)
{
	if (!IsInGameThread())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportManager::HandleRegisterSuccess | called from outside the game thread | aborting"));

		return;
	}

	// kick the active VO so it will check if the newly registered entity should be paged even if player does not move
	if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
	{
		voManager->TriggerUpdateGlobal();
	}

	if (UDeveloper_Subsystem_Notification* subsystem = UDeveloper_Subsystem_Notification::Get())
	{
		subsystem->AddNotification(FNotificationData(FString::Printf(TEXT("\"%s\" imported"), *FPaths::GetCleanFilename(fullPathToFile)), 5, true));
	}
}

void UGame_ImportManager::HandleRegisterFail(const FString& fullPathToFile)
{
	if (!IsInGameThread())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportManager::HandleRegisterFail | called from outside the game thread | aborting"));
		
		return;
	}

	/*if (UDeveloper_Subsystem_Notification* subsystem = UDeveloper_Subsystem_Notification::Get())
	{
		subsystem->AddNotification(FNotificationData(FString::Printf(TEXT("\"%s\" failed to import"), *FPaths::GetCleanFilename(fullPathToFile)), 5, true));
	}*/
}
