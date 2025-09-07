// Required Includes
#include "Game_MatComponent_XML.h"
#include "Game.h"

// Engine Includes
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Async/Async.h"
#include "XmlFile.h"
#include "HAL/FileManager.h"
#include "Async/ParallelFor.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_FileIOStatics.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_TileUtilities.h"
#include "Game_TileManager.h"
#include "Game_TerrainTile.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MatComponent_XML::UGame_MatComponent_XML() :
	NorthWestTile(TPair<int32, int32>()),
	SouthEastTile(TPair<int32, int32>()),
	SourceName(TEXT("")),
	SourceType(TEXT("")),
	MinZoom(0),
	MaxZoom(0),
	URL(TEXT("")),
	ServerParts(TArray<FString>()),
	PixelWidth(0),
	PixelHeight(0),
	bXMLLoaded(false)
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

TArray<FString> UGame_MatComponent_XML::GetImageryXMLSources()
{
	auto getSourceNames = [](const FString& fullPathToXMLs, TArray<FString>& sourceNames)
	{
		TArray<FString> xmlFiles;
		UVH_FileIOStatics::GetFilesInPath(xmlFiles, fullPathToXMLs, TEXT("xml"), true, true, true);

		for (const FString& xmlFilePath : xmlFiles)
		{
			FXmlFile xmlFile;

			xmlFile.LoadFile(xmlFilePath);

			if (xmlFile.IsValid())
			{
				FXmlNode* rootNode = xmlFile.GetRootNode();
				if (rootNode->GetTag().Equals(TEXT("customMapSource"), ESearchCase::IgnoreCase))
				{
					if (FXmlNode* node = rootNode->FindChildNode(TEXT("name")))
					{
						sourceNames.AddUnique(node->GetContent());
					}
				}
				else if (rootNode->GetTag().Equals(TEXT("customMultiLayerMapSource")))
				{
					if (FXmlNode* node = rootNode->FindChildNode(TEXT("name")))
					{
						sourceNames.AddUnique(node->GetContent());
					}
				}
			}
		}
	};

	TArray<FString> sourceNames;

	// get from database location
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString fullPathToImageryXMLs = gameSettings->GetSettingString(FString::Printf(TEXT("xml_imagery.FullPathsToImageryXMLs")));

		TArray<FString> potentialFilePaths;
		fullPathToImageryXMLs.ParseIntoArray(potentialFilePaths, TEXT("|"), true);

		for (int32 i = 0; i < potentialFilePaths.Num(); i++)
		{
			if (FPaths::DirectoryExists(potentialFilePaths[i]))
			{
				getSourceNames(potentialFilePaths[i], sourceNames);
			}
		}
	}

	// get from default location
	FString fullPathToXMLs = FPaths::Combine(FPaths::RootDir(), TEXT("Data"), TEXT("TerrainXML"));
	if (FPaths::DirectoryExists(fullPathToXMLs))
	{
		getSourceNames(fullPathToXMLs, sourceNames);
	}

	// get offline sources
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString offlineImageryDirectory = gameSettings->GetSettingString(TEXT("OfflineImageryDirectory"));

		TArray<FString> files;
		UVH_FileIOStatics::GetFilesInPath(files, offlineImageryDirectory, TEXT("sqlite"), false, true, true);

		for (const FString& file : files)
		{
			sourceNames.Add(FString::Printf(TEXT("offline.%s"), *FPaths::GetBaseFilename(file)));
		}
	}

	return sourceNames;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MatComponent_XML::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->RemoveHTTPRequests(this);
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UGame_MatComponent_XML::ExecuteHelperThreadLogic()
{
	if (GetComponentStatus() == EComponentStatus::Initialized)
	{
		SetComponentStatus(EComponentStatus::HelperThreadStarted);

		// early out if already generated Mat
		if (bGeneratedMat)
		{
			SetComponentStatus(EComponentStatus::HelperThreadFinished);

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

			if (!bOffline && !bXMLLoaded)
			{
				FString fullPathsToXMLs = TEXT("");
				FString imagerySourceName = TEXT("");
				if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
				{
					fullPathsToXMLs = gameSettings->GetSettingString(FString::Printf(TEXT("xml_imagery.FullPathsToImageryXMLs")));

					imagerySourceName = gameSettings->GetSettingString(FString::Printf(TEXT("xml_imagery.ImagerySourceName")));
				}

				// check if offline database
				if (imagerySourceName.StartsWith(TEXT("offline.")))
				{
					if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
					{
						FString fullPathOnDisk = gameSettings->GetSettingString(TEXT("OfflineImageryDirectory"));

						if (!fullPathOnDisk.EndsWith(TEXT("\\")))
						{
							fullPathOnDisk += TEXT("\\");
						}

						FString sqliteFilename = imagerySourceName;
						sqliteFilename.RemoveFromStart(TEXT("offline."));

						fullPathOnDisk += sqliteFilename + TEXT(".sqlite");
						if (FPaths::FileExists(*fullPathOnDisk))
						{
							bOffline = true;

							URL = TEXT("");

							SourceName = fullPathOnDisk;
						}
					}
				}

				if (!bOffline)
				{
					TArray<FString> potentialFilePaths;
					fullPathsToXMLs.ParseIntoArray(potentialFilePaths, TEXT("|"), true);
					bool successfulRead = false;

					for (int32 i = 0; i < potentialFilePaths.Num(); i++)
					{
						if (ReadFromXML(potentialFilePaths[i], imagerySourceName))
						{
							successfulRead = true;
							break;
						}
					}
					if (!successfulRead)
					{
						// try default location
						FString fullPathToXMLs = FPaths::Combine(FPaths::RootDir(), TEXT("Data"), TEXT("TerrainXML"));
						ReadFromXML(fullPathToXMLs, imagerySourceName);
					}

					if (GetZoomLevel() < MinZoom)
					{
						ZoomLevel = MinZoom;
					}

					if (GetZoomLevel() > MaxZoom)
					{
						ZoomLevel = MaxZoom;
					}
				}
			}

			if (URL.IsEmpty() && !bOffline)
			{
				if (bXMLLoaded)
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_XML::ExecuteHelperThreadLogic | URL is empty | source: %s"), *SourceName);
				}

				SetComponentStatus(EComponentStatus::HelperThreadFinished);

				DestroyCounter.Decrement();

				return;
			}

			// determine tiles to pull
			switch (Attempt)
			{
				case EAttempt::Google:
					TileUtilities::GetTileFromGeodetic(GetNorthWestBound(), GetZoomLevel(), NorthWestTile);
					TileUtilities::GetTileFromGeodetic(GetSouthEastBound(), GetZoomLevel(), SouthEastTile);
					break;

				case EAttempt::TMS:
					TileUtilities::GetTileFromGeodetic_TMS(GetNorthWestBound(), GetZoomLevel(), NorthWestTile);
					TileUtilities::GetTileFromGeodetic_TMS(GetSouthEastBound(), GetZoomLevel(), SouthEastTile);
					break;

				case EAttempt::TMS_Y_Reversed:
					TileUtilities::GetTileFromGeodetic_TMS(GetNorthWestBound(), GetZoomLevel(), NorthWestTile, true);
					TileUtilities::GetTileFromGeodetic_TMS(GetSouthEastBound(), GetZoomLevel(), SouthEastTile, true);
					break;
			}

			UGame_TileManager* tileManager = UGame_TileManager::Get();

			// cache tile data
			if (OfflineDownloadFilename.IsEmpty())
			{
				int32 startY = FMath::Min<int32>(NorthWestTile.Value, SouthEastTile.Value);
				int32 endY = FMath::Max<int32>(NorthWestTile.Value, SouthEastTile.Value);

				int32 startX = FMath::Min<int32>(NorthWestTile.Key, SouthEastTile.Key);
				int32 endX = FMath::Max<int32>(NorthWestTile.Key, SouthEastTile.Key);

				FCriticalSection addCriticalSection;
				
				ParallelFor(endY - startY + 1, [this, &addCriticalSection, startY, endY, startX, endX](int32 y) 
				{
					y += startY;

					ParallelFor(endX - startX + 1, [this, &addCriticalSection, y, endY, startX, endX](int32 x)
					{
						x += startX;

						TPair<int32, int32> tileNumber(x, y);
						
						TArray<uint8> data;
						if (TileUtilities::ReadTileFromDisk(tileNumber, GetZoomLevel(), SourceName, SourceType, data))
						{
							FScopeLock scopeLock(&addCriticalSection);
							TileToMatData.Add(tileNumber, data);
						}
					});
				});
			}

			// get all tiles' imagery data
			if (!bOffline)
			{
				for (int32 y = FMath::Min<int32>(NorthWestTile.Value, SouthEastTile.Value); y <= FMath::Max<int32>(NorthWestTile.Value, SouthEastTile.Value); y++)
				{
					for (int32 x = FMath::Min<int32>(NorthWestTile.Key, SouthEastTile.Key); x <= FMath::Max<int32>(NorthWestTile.Key, SouthEastTile.Key); x++)
					{
						TPair<int32, int32> tileNumber(x, y);
						if (!TileToMatData.Contains(tileNumber))
						{
							FString tileIdentifier = TileUtilities::GetTileIdentifier(tileNumber, GetZoomLevel(), SourceName, SourceType);
								
							FString requestURL = URL;
							requestURL.ReplaceInline(TEXT("{$x}"), *FString::Printf(TEXT("%d"), tileNumber.Key), ESearchCase::IgnoreCase);
							requestURL.ReplaceInline(TEXT("{$y}"), *FString::Printf(TEXT("%d"), tileNumber.Value), ESearchCase::IgnoreCase);
							requestURL.ReplaceInline(TEXT("{$z}"), *FString::Printf(TEXT("%d"), GetZoomLevel()), ESearchCase::IgnoreCase);
							requestURL.ReplaceInline(TEXT("{$q}"), *TileUtilities::TileToQuadKey(GetZoomLevel(), tileNumber.Key, tileNumber.Value), ESearchCase::IgnoreCase);

							if (ServerParts.Num() > 0)
							{
								requestURL.ReplaceInline(TEXT("{$serverpart}"), *ServerParts[FMath::RandHelper(ServerParts.Num())]);
							}

							FHttpModule* http = &FHttpModule::Get();

							TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
							request->SetHeader(TEXT("User-Agent"), TEXT("TAK"));
							request->SetURL(requestURL);
							request->AppendToHeader(TEXT("email"), FString::Printf(TEXT("%d.%d.%d.%s.%s"), tileNumber.Key, tileNumber.Value, GetZoomLevel(), *SourceName, *SourceType));
							request->SetVerb(TEXT("GET"));

							tileManager->AddHTTPRequest(tileIdentifier, this, request);

							RequestsCounter.Increment();
						}
					}
				}
			}

			if (OfflineDownloadFilename.IsEmpty())
			{
				// if everything already exists on disk, skip to populating pixels
				if (RequestsCounter.GetValue() == 0)
				{
					CreateMat();
				}
			}

			DestroyCounter.Decrement();
		});
	}
}

void UGame_MatComponent_XML::ExecuteGameThreadLogic()
{
	if (GetComponentStatus() == EComponentStatus::HelperThreadFinished)
	{
		SetComponentStatus(EComponentStatus::GameThreadStarted);

		SetComponentStatus(EComponentStatus::GameThreadFinished);

		OnGameLogicCompleted.ExecuteIfBound(this);
	}
}

float UGame_MatComponent_XML::GetAlpha()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
		{
			FString alphaID = FString::Printf(TEXT("xml_imagery.%s.alpha"), *terrainTile->GetComponentID(this));
			if (gameSettings->HasSetting(alphaID))
			{
				return gameSettings->GetSettingDouble(alphaID);
			}
		}
	}

	return 1;
}

void UGame_MatComponent_XML::DownloadForOffline(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, double minZoom, double maxZoom, const FString& fullPathToOfflineFile, TFunction<void(const FString& progress)> onProgress, TFunction<void()> onDownloadComplete)
{
	FString fullPathsToXMLs = TEXT("");
	FString imagerySourceName = TEXT("");
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		fullPathsToXMLs = gameSettings->GetSettingString(FString::Printf(TEXT("xml_imagery.FullPathsToImageryXMLs")));

		imagerySourceName = gameSettings->GetSettingString(FString::Printf(TEXT("xml_imagery.ImagerySourceName")));
	}

	// check if offline database
	if (imagerySourceName.StartsWith(TEXT("offline.")))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_XML::DownloadForOffline | cannot download for offline use from an offline source | aborting"));

		RemoveFromRoot();

		return;
	}

	OfflineDownloadFilename = FPaths::GetCleanFilename(fullPathToOfflineFile);

	TileBounds.Key = northWestBound;
	TileBounds.Value = southEastBound;

	ZoomLevel = minZoom;

	SetComponentStatus(EComponentStatus::Initialized);
	ExecuteHelperThreadLogic();

	Async(EAsyncExecution::ThreadPool, [this, minZoom, maxZoom, fullPathToOfflineFile, onProgress, onDownloadComplete]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();

			RemoveFromRoot();

			return;
		}

		while (GetComponentStatus() == EComponentStatus::HelperThreadStarted)
		{
			if (onProgress != nullptr)
			{
				onProgress(FString::Printf(TEXT("%d: %d tiles remaining"), ZoomLevel, RequestsCounter.GetValue()));
			}
			
			if (!IsRooted())
			{
				DestroyCounter.Decrement();

				DestroyComponent();

				return;
			}

			FPlatformProcess::Sleep(0.1f);
		}

		// MinZoom and MaxZoom are set in first call to ExecuteHelperThreadLogic()
		while (ZoomLevel < maxZoom)
		{
			ZoomLevel += 1;
			if (ZoomLevel > MaxZoom)
			{
				break;
			}

			SetComponentStatus(EComponentStatus::Initialized);
			ExecuteHelperThreadLogic();

			while (GetComponentStatus() == EComponentStatus::HelperThreadStarted)
			{
				if (!IsRooted())
				{
					DestroyCounter.Decrement();

					DestroyComponent();

					return;
				}

				if (onProgress != nullptr)
				{
					onProgress(FString::Printf(TEXT("%d: %d tiles remaining"), ZoomLevel, RequestsCounter.GetValue()));
				}

				FPlatformProcess::Sleep(0.1f);
			}
		}

		TileUtilities::Disconnect(OfflineDownloadFilename);

		// add sqlite extension
		FString extensionAdded = fullPathToOfflineFile;
		if (!FPaths::GetExtension(fullPathToOfflineFile).Equals(TEXT("sqlite")))
		{
			extensionAdded += TEXT(".sqlite");
		}

		IFileManager& fileManager = IFileManager::Get();
		fileManager.Move(*extensionAdded, *TileUtilities::GetFullPathTo(OfflineDownloadFilename), true);

		if (onDownloadComplete != nullptr)
		{
			onDownloadComplete();
		}
		
		DestroyCounter.Decrement();
		
		RemoveFromRoot();
	});
}

bool UGame_MatComponent_XML::SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel)
{
	Mat.release();

	bGeneratedMat = false;

	return true;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MatComponent_XML::OnHTTPRequestComplete(const FString& tileIdentifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
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

			FString sourceName = parsedID[3];
			FString sourceType = parsedID[4];

			if (!TileUtilities::TileExistsOnDisk(tileNumber, GetZoomLevel(), sourceName, sourceType))
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
					TileUtilities::WriteTileToDisk(tileNumber, zoomLevel, sourceName, sourceType, content);
					
					TileToMatData.Add(tileNumber, content);
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- invalid imagery: %s"), *TileUtilities::GetTileIdentifier(tileNumber, zoomLevel, sourceName, sourceType));
				}
			}
		}

		RequestsCounter.Decrement();

		if (RequestsCounter.GetValue() == 0)
		{
			if (OfflineDownloadFilename.IsEmpty())
			{
				CreateMat();
			}
			else
			{
				SetComponentStatus(EComponentStatus::HelperThreadFinished);
			}
		}

		DestroyCounter.Decrement();
	});
}

void UGame_MatComponent_XML::ReadFromXML(FXmlNode* rootNode)
{
	if (FXmlNode* node = rootNode->FindChildNode(TEXT("name")))
	{
		if (OfflineDownloadFilename.IsEmpty())
		{
			SourceName = node->GetContent();
		}
		else
		{
			SourceName = OfflineDownloadFilename;
		}
	}

	if (FXmlNode* node = rootNode->FindChildNode(TEXT("minZoom")))
	{
		MinZoom = FCString::Atoi(*node->GetContent());
	}

	if (FXmlNode* node = rootNode->FindChildNode(TEXT("maxZoom")))
	{
		MaxZoom = FCString::Atoi(*node->GetContent());
	}

	if (FXmlNode* node = rootNode->FindChildNode(TEXT("tileType")))
	{
		SourceType = node->GetContent();

		if (SourceType.Equals(TEXT("image/jpeg"), ESearchCase::IgnoreCase))
		{
			SourceType = TEXT("jpg");
		}
	}

	if (FXmlNode* node = rootNode->FindChildNode(TEXT("url")))
	{
		URL = node->GetContent();
		URL.ReplaceInline(TEXT("&amp;"), TEXT("&"), ESearchCase::IgnoreCase);
	}

	if (FXmlNode* node = rootNode->FindChildNode(TEXT("serverParts")))
	{
		FString serverParts = node->GetContent();

		ServerParts.Empty();
		serverParts.ParseIntoArray(ServerParts, TEXT(" "));
	}

	bXMLLoaded = true;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_MatComponent_XML::ReadFromXML(const FString& fullPathToXMLs, const FString& sourceName)
{
	if (!FPaths::DirectoryExists(fullPathToXMLs))
	{
		return false;
	}

	FXmlFile xmlFile;
	bXMLLoaded = false;

	TArray<FString> xmlFiles;
	UVH_FileIOStatics::GetFilesInPath(xmlFiles, fullPathToXMLs, TEXT("xml"), true, true, true);

	for (const FString& xmlFilePath : xmlFiles)
	{
		xmlFile.LoadFile(xmlFilePath);

		if (xmlFile.IsValid())
		{
			FXmlNode* rootNode = xmlFile.GetRootNode();
			if (rootNode->GetTag().Equals(TEXT("customMapSource")))
			{
				if (FXmlNode* node = rootNode->FindChildNode(TEXT("name")))
				{
					if (sourceName.Equals(node->GetContent(), ESearchCase::IgnoreCase))
					{
						bXMLLoaded = true;
						break;
					}
				}
			}
			else if (rootNode->GetTag().Equals(TEXT("customMultiLayerMapSource")))
			{
				if (FXmlNode* node = rootNode->FindChildNode(TEXT("name")))
				{
					if (sourceName.Equals(node->GetContent(), ESearchCase::IgnoreCase))
					{
						bXMLLoaded = true;
						break;
					}
				}
			}
		}
	}

	if (bXMLLoaded)
	{
		FXmlNode* rootNode = xmlFile.GetRootNode();

		if (rootNode->GetTag().Equals(TEXT("customMultiLayerMapSource")))
		{
			FString id = TEXT("genericName");
			if (FXmlNode* nameNode = rootNode->FindChildNode(TEXT("name")))
			{
				id = nameNode->GetContent();
			}

			FString alphaString = TEXT("");
			if (FXmlNode* alphaNode = rootNode->FindChildNode(TEXT("layersAlpha")))
			{
				alphaString = alphaNode->GetContent();
			}

			TArray<FString> alphaParts;
			alphaString.ParseIntoArray(alphaParts, TEXT(" "));

			if (FXmlNode* layersNode = rootNode->FindChildNode(TEXT("layers")))
			{
				TArray<FXmlNode*> layers = layersNode->GetChildrenNodes();

				if (AGame_TerrainTile* owningTile = Cast<AGame_TerrainTile>(GetOwner()))
				{
					// create components layers
					for (int32 i = 0; i < layers.Num(); i++)
					{
						FString layerName = TEXT("genericLayer");
						if (FXmlNode* layerNameNode = layers[i]->FindChildNode(TEXT("name")))
						{
							layerName = layerNameNode->GetContent();
						}

						FString componentID = FString::Printf(TEXT("%s_%s"), *id, *layerName);

						if (UGame_MatComponent_XML* xmlComponent = Cast<UGame_MatComponent_XML>(owningTile->AddTileComponent(componentID, UGame_MatComponent_XML::StaticClass())))
						{
							xmlComponent->ReadFromXML(layers[i]);
						}

						FString alpha = TEXT("");
						if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
						{
							FString settingName = FString::Printf(TEXT("xml_imagery.%s.alpha"), *componentID);
							if (gameSettings->HasSetting(settingName))
							{
								alpha = FString::Printf(TEXT("%f"), gameSettings->GetSettingDouble(settingName));
							}
							else
							{
								alpha = alphaParts.IsValidIndex(i) ? alphaParts[i] : TEXT("1");
							}
						}

						if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
						{
							FString settingName = FString::Printf(TEXT("%s.%s"), TEXT("xml_imagery"), *FString::Printf(TEXT("%s.alpha"), *componentID));

							gameSettings->StoreSettingString(settingName, alpha);
						}
					}
				}
			}

			bXMLLoaded = false;
		}
		else
		{
			// remove all xml_imagery entries except FullPathsToImageryXMLs and ImagerySourceName (e.g. all the added *.alpha entries)
			if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
			{
				TSet<FString> settingNames = gameSettings->GetAllSettings();
				for (const FString& settingName : settingNames)
				{
					if (settingName.StartsWith(TEXT("xml_imagery")))
					{
						if (!settingName.Equals(TEXT("xml_imagery.FullPathsToImageryXMLs")) && !settingName.Equals(TEXT("xml_imagery.ImagerySourceName")))
						{
							gameSettings->RemoveSetting(settingName);
						}
					}
				}
			}

			ReadFromXML(rootNode);
		}
	}

	return bXMLLoaded;
}

void UGame_MatComponent_XML::CreateMat()
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
		for (int32 y = FMath::Min<int32>(NorthWestTile.Value, SouthEastTile.Value); y <= FMath::Max<int32>(NorthWestTile.Value, SouthEastTile.Value); y++)
		{
			for (int32 x = FMath::Min<int32>(NorthWestTile.Key, SouthEastTile.Key); x <= FMath::Max<int32>(NorthWestTile.Key, SouthEastTile.Key); x++)
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
			if (bOffline && Attempt != EAttempt::TMS_Y_Reversed)
			{
				// retry using different tiling scheme
				switch (Attempt)
				{
					case EAttempt::Google:
						Attempt = EAttempt::TMS;
						break;

					case EAttempt::TMS:
						Attempt = EAttempt::TMS_Y_Reversed;
				}

				DestroyCounter.Decrement();

				bGeneratedMat = false;
				SetComponentStatus(EComponentStatus::Initialized);
				ExecuteHelperThreadLogic();
				return;
			}

			UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_XML::CreateMat | could not create tileMat | zoom: %d"), GetZoomLevel());

			// make a crimson mat to show no source data
			cv::Mat temp(256, 256, CV_8UC3);
			temp.setTo(cv::Scalar(60, 20, 220));

			Mat = temp.clone();

			SetComponentStatus(EComponentStatus::HelperThreadFinished);

			DestroyCounter.Decrement();
			return;
		}

		int32 numTilesX = FMath::Abs(SouthEastTile.Key - NorthWestTile.Key) + 1;
		int32 numTilesY = FMath::Abs(SouthEastTile.Value - NorthWestTile.Value) + 1;
		int32 allPixelsX = (numTilesX * PixelWidth) - (numTilesX - 1);
		int32 allPixelsY = (numTilesY * PixelHeight) - (numTilesY - 1);
		
		cv::Mat allTiles = CreateMatOfAllTiles(allPixelsX, allPixelsY);
		
		// crop large mat based on northWest and southEast bounds
		FGeodeticCoord2D nw;
		FGeodeticCoord2D nw_East;
		FGeodeticCoord2D nw_South;
		switch (Attempt)
		{
			case EAttempt::Google:
				nw = TileUtilities::GetNorthwestCoordinate(NorthWestTile, GetZoomLevel());
				nw_East = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(NorthWestTile.Key + 1, NorthWestTile.Value), GetZoomLevel());
				nw_South = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(NorthWestTile.Key, NorthWestTile.Value + 1), GetZoomLevel());
				break;

			case EAttempt::TMS:
				nw = TileUtilities::GetNorthwestCoordinate_TMS(NorthWestTile, GetZoomLevel());
				nw_East = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(NorthWestTile.Key + 1, NorthWestTile.Value), GetZoomLevel());
				nw_South = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(NorthWestTile.Key, NorthWestTile.Value - 1), GetZoomLevel());
				break;

			case EAttempt::TMS_Y_Reversed:
				nw = TileUtilities::GetNorthwestCoordinate_TMS(NorthWestTile, GetZoomLevel(), true);
				nw_East = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(NorthWestTile.Key + 1, NorthWestTile.Value), GetZoomLevel(), true);
				nw_South = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(NorthWestTile.Key, NorthWestTile.Value + 1), GetZoomLevel(), true);
				break;
		}

		float nw_xPercent = (GetNorthWestBound().Longitude - nw.Longitude) / (nw_East.Longitude - nw.Longitude);
		float nw_yPercent = (nw.Latitude - GetNorthWestBound().Latitude) / (nw.Latitude - nw_South.Latitude);

		FGeodeticCoord2D se;
		FGeodeticCoord2D se_East;
		FGeodeticCoord2D se_South;
		switch (Attempt)
		{
			case EAttempt::Google:
				se = TileUtilities::GetNorthwestCoordinate(SouthEastTile, GetZoomLevel());
				se_East = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(SouthEastTile.Key + 1, SouthEastTile.Value), GetZoomLevel());
				se_South = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(SouthEastTile.Key, SouthEastTile.Value + 1), GetZoomLevel());
				break;

			case EAttempt::TMS:
				se = TileUtilities::GetNorthwestCoordinate_TMS(SouthEastTile, GetZoomLevel());
				se_East = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(SouthEastTile.Key + 1, SouthEastTile.Value), GetZoomLevel());
				se_South = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(SouthEastTile.Key, SouthEastTile.Value - 1), GetZoomLevel());
				break;

			case EAttempt::TMS_Y_Reversed:
				se = TileUtilities::GetNorthwestCoordinate_TMS(SouthEastTile, GetZoomLevel(), true);
				se_East = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(SouthEastTile.Key + 1, SouthEastTile.Value), GetZoomLevel(), true);
				se_South = TileUtilities::GetNorthwestCoordinate_TMS(TPair<int32, int32>(SouthEastTile.Key, SouthEastTile.Value + 1), GetZoomLevel(), true);
				break;
		}

		// subtract from 1 because interested in number of pixels not included
		float se_xPercent = 1 - ((GetSouthEastBound().Longitude - se.Longitude) / (se_East.Longitude - se.Longitude));
		float se_yPercent = 1 - ((se.Latitude - GetSouthEastBound().Latitude) / (se.Latitude - se_South.Latitude));
		
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
			UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_XML::LoadImagery | crop/resize | opencv error: %s"), ANSI_TO_TCHAR(err_msg));
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_XML::LoadImagery | crop/resize | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

			// make a crimson mat as fallback
			cv::Mat temp(PixelHeight, PixelWidth, CV_8UC3);
			temp.setTo(cv::Scalar(60, 20, 220));

			Mat = temp.clone();
		}
		
		SetComponentStatus(EComponentStatus::HelperThreadFinished);
		
		DestroyCounter.Decrement();
	});
}

cv::Mat UGame_MatComponent_XML::CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY)
{
	cv::Mat allTiles(pixelsY, pixelsX, CV_8UC3);

	int32 startY = FMath::Min<int32>(NorthWestTile.Value, SouthEastTile.Value);
	int32 endY = FMath::Max<int32>(NorthWestTile.Value, SouthEastTile.Value);

	int32 startX = FMath::Min<int32>(NorthWestTile.Key, SouthEastTile.Key);
	int32 endX = FMath::Max<int32>(NorthWestTile.Key, SouthEastTile.Key);

	ParallelFor(endY - startY + 1, [this, &allTiles, startY, endY, startX, endX](int32 y) 
	{
		y += startY;

		ParallelFor(endX - startX + 1, [this, &allTiles, y, endY, startX, startY, endX](int32 x)
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
						tileMat.copyTo(allTiles(cv::Rect(xPos, yPos, tileMat.cols, tileMat.rows)));
					}
				}
				catch (cv::Exception& e)
				{
					const char* err_msg = e.what();
					UE_LOG(Game, Warning, TEXT("-- UGame_MatComponent_XML::CreateMatOfAllTiles | copyTo | %d | %d | %d | %d | %d | %d opencv error: %s"), tileMat.type(), allTiles.type(), xPos, yPos, tileMat.cols, tileMat.rows, ANSI_TO_TCHAR(err_msg));
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_XML::CreateMatOfAllTiles | copyTo | opencv error: %s"), ANSI_TO_TCHAR(err_msg));

					bHandled = false;
				}
			}
			else
			{
				bHandled = false;
			}

			if (!bHandled)
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UGame_MatComponent_XML::CreateMatOfAllTiles | unable to load imagery for | zoomLevel: %d | tile: %f, %f"), GetZoomLevel(), x, y);

				// make a crimson mat to show no source data
				cv::Mat temp(PixelHeight, PixelWidth, CV_8UC3);
				temp.setTo(cv::Scalar(60, 20, 220));

				temp.copyTo(allTiles(cv::Rect(xPos, yPos, temp.cols, temp.rows)));
			}
		});
	});

	return allTiles.clone();
}

bool UGame_MatComponent_XML::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

bool UGame_MatComponent_XML::GetCachedMat(const TPair<int32, int32>& tileNumber, cv::Mat& tileMat)
{
	if (TArray<uint8>* data = TileToMatData.Find(tileNumber))
	{
		std::vector<unsigned char> dataVector(data->GetData(), data->GetData() + data->Num());
		tileMat = cv::imdecode(dataVector, cv::IMREAD_UNCHANGED);

		return true;
	}
	
	// fallback to get mats when desired zoom level isn't present and GetTileMatFromDisk returns mat for lower zoom level
	return TileUtilities::GetTileMatFromDisk(tileNumber, GetZoomLevel(), SourceName, SourceType, tileMat);
}