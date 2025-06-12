// Required Includes
#include "Game_TileComponent_3DTile.h"
#include "Game.h"

// VH Module Includes
#include "Developer_Statics.h"
#include "VH_COTManager.h"
#include "VH_MeshInfo.h"
#include "Interface_Developer_Task.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "VH_FileIOTypes.h"
#include "VH_GlobeCoordConverter.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_ImportedMeshComponent.h"
#include "Game_TileManager.h"
#include "Game_Statics.h"
#include "Game_TerrainTile.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_3DTileNode.h"
#include "Game_Subsystem_Core.h"
#include "Game_ImportedMeshComponent_3DTile.h"
#include "Game_Actor_3DTile.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TileComponent_3DTile::UGame_TileComponent_3DTile() : 
	bInitialPass(true),
	InitialGeometricError(1024)
{
	ActorClass = AGame_Actor_3DTile::StaticClass();

	PrimaryComponentTick.bCanEverTick = true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_TileComponent_3DTile::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	DestroyLoadedActors();

	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->RemoveHTTPRequests(this);
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UGame_TileComponent_3DTile::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();
}

void UGame_TileComponent_3DTile::ExecuteGameThreadLogic()
{
	if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
	{
		if (terrainTile->GetTileStatus() == ETileStatus::ReadyForDestroy)
		{
			return;
		}
	}

	if (GetComponentStatus() == EComponentStatus::HelperThreadFinished)
	{
		SetComponentStatus(EComponentStatus::GameThreadStarted);
		
		if (UWorld* world = UDeveloper_Statics::GetVHWorld())
		{
			world->GetTimerManager().SetTimer(PeriodicLoadFilesTimerHandle, this, &UGame_TileComponent_3DTile::PeriodicLoadFiles, 0.01, true);
			
			world->GetTimerManager().SetTimer(PeriodicUpdateTilesetTimerHandle, this, &UGame_TileComponent_3DTile::PeriodicUpdateTileset, 0.5, true);

			LastPlayerGeoLocation = GetPlayerGeoLocation();

			bForceUpdateTileset = true;
			PeriodicUpdateTileset();
		}
	}
}

bool UGame_TileComponent_3DTile::SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel)
{
	DestroyLoadedActors();

	if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
	{
		terrainTile->OnTileStatusChanged.AddUObject(this, &UGame_TileComponent_3DTile::HandleTileStatusChanged);
	}

	return true;
}

void UGame_TileComponent_3DTile::OnHTTPRequestComplete(const FString& fullPathToFile, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	// special case for google
	if (RESTBaseURL.Contains(TEXT("tile.googleapis.com")))
	{
		if (!response.IsValid() || response->GetResponseCode() != 200)
		{
			if (LastTilesetRequest == FDateTime::MinValue())
			{
				IFileManager::Get().Delete(*FullPathToTileset);

				if (UGame_TileManager* tileManager = UGame_TileManager::Get())
				{
					tileManager->RemoveHTTPRequests(this);
				}

				ReceiveFileDelegates.Empty();

				LastTilesetRequest = FDateTime::Now();

				FullPathToTileset = TEXT("");
				
				ExecuteHelperThreadLogic();
			}

			return;
		}
	}

	if (ReceiveFileDelegates.Contains(fullPathToFile))
	{
		FFileHelper::SaveArrayToFile(response->GetContent(), *fullPathToFile);

		ReceiveFileDelegates[fullPathToFile].ExecuteIfBound(fullPathToFile);

		ReceiveFileDelegates.Remove(fullPathToFile);
	}
}

bool UGame_TileComponent_3DTile::GlobeReferenceScaleUpdated(const FVector& newScale3D)
{
	DestroyLoadedActors();

	return true;
}

bool UGame_TileComponent_3DTile::GetHAEBounds(FVector2D& haeBounds) const
{
	bool bValid = false;

	haeBounds = FVector2D(9999999.0, -9999999.0);

	for (const TPair<UGame_3DTileNode*, TArray<AActor*>>& entry : LoadedActors)
	{
		for (AActor* actor : entry.Value)
		{
			if (UGame_ImportedMeshComponent_3DTile* component = Cast<UGame_ImportedMeshComponent_3DTile>(actor->GetComponentByClass(UGame_ImportedMeshComponent_3DTile::StaticClass())))
			{
				FVector2D actorHAEBounds;
				if (component->GetHAEBounds(actorHAEBounds))
				{
					haeBounds.X = FMath::Min<double>(haeBounds.X, actorHAEBounds.X);
					haeBounds.Y = FMath::Max<double>(haeBounds.Y, actorHAEBounds.Y);

					bValid = true;
				}
			}
		}
	}

	return bValid;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_TileComponent_3DTile::InitializeForLocalTilesets(FString localTilesets)
{
	localTilesets.ReplaceInline(TEXT("\\"), TEXT("/"));

	TArray<FString> tilesets;
	localTilesets.ParseIntoArray(tilesets, TEXT("|"));
		
	for (int32 i = 0; i < tilesets.Num(); i++)
	{
		TArray<FString> tilesetInfo;
		tilesets[i].ParseIntoArray(tilesetInfo, TEXT(";"));
		if (tilesetInfo.Num() > 0)
		{
			PopulateComponentFromInfoArray(i == 0 ? this : nullptr, tilesetInfo);
		}
	}
}

void UGame_TileComponent_3DTile::InitializeForRemoteTileset(const FString& accessToken, FString assetID)
{

}

void UGame_TileComponent_3DTile::PopulateComponentFromInfoArray(UGame_TileComponent* component, TArray<FString> assetInfo)
{

}

void UGame_TileComponent_3DTile::RequestFile(const FString& fullPathToFile, FOnReceiveFile& receiveFileDelegate)
{

}

bool UGame_TileComponent_3DTile::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() ||
		HasAnyFlags(RF_BeginDestroyed) ||
		GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

void UGame_TileComponent_3DTile::DestroyLoadedActors()
{
	{
		FScopeLock lock(&LoadedActorsCritSection);
		for (const TPair<UGame_3DTileNode*, TArray<AActor*>>& entry : LoadedActors)
		{
			for (AActor* actor : entry.Value)
			{
				actor->Destroy();
			}
		}

		LoadedActors.Empty();
	}
}

void UGame_TileComponent_3DTile::LoadFile(FString fullPathToFile)
{
	if (!FPaths::FileExists(fullPathToFile))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadFile | file does not exist: %s"), *fullPathToFile);
		return;
	}

	UGame_3DTileNode* parentNode = nullptr;
	if (!fullPathToFile.Equals(FullPathToTileset))
	{
		if (UGame_3DTileNode** parentNodePtr = PathToNode.Find(fullPathToFile))
		{
			parentNode = *parentNodePtr;
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadFile | json file could not find parent node | aborting | %s"), *fullPathToFile);
			return;
		}
	}

	FString extension = FPaths::GetExtension(fullPathToFile);

	if (extension.Equals(TEXT("json"), ESearchCase::IgnoreCase))
	{
		LoadNode(parentNode, nullptr, fullPathToFile, nullptr);

		return;
	}

	// convert from b3dm to gltf
	if (extension.Equals(TEXT("b3dm"), ESearchCase::IgnoreCase))
	{
		FString fullPathToGLTF = FPaths::Combine(FPaths::GetPath(fullPathToFile), FString::Printf(TEXT("%s.gltf"), *FPaths::GetBaseFilename(fullPathToFile)));
		FString fullPathToGLB = FPaths::Combine(FPaths::GetPath(fullPathToFile), FString::Printf(TEXT("%s.glb"), *FPaths::GetBaseFilename(fullPathToFile)));

		if (!FPaths::FileExists(fullPathToGLB))
		{
			UGame_Statics::StoreB3DMAsGLTF(fullPathToFile, fullPathToGLTF);
			UGame_Statics::StoreGLTFAsGLB(fullPathToGLTF, fullPathToGLB);
		}

		extension = FPaths::GetExtension(fullPathToGLB);

		if (IFileManager::Get().FileSize(*fullPathToGLB) == 0)
		{
			// something bad happened when attempting to convert to glb; abort!
			return;
		}
	}

	if (extension.Equals(TEXT("geojson"), ESearchCase::IgnoreCase))
	{
		Async(EAsyncExecution::ThreadPool, [this, fullPathToFile]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}
			
			FString fileContents;
			FFileHelper::LoadFileToString(fileContents, *fullPathToFile);

			TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(fileContents);

			TSharedPtr<FJsonObject> jsonObject;
			if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
			{
				const TArray<TSharedPtr<FJsonValue>>* featuresArrayPtr;
				if (jsonObject->TryGetArrayField(TEXT("features"), featuresArrayPtr))
				{
					TArray<TSharedPtr<FJsonValue>> features = *featuresArrayPtr;
					for (int32 i = 0; i < features.Num(); i++)
					{
						TSharedPtr<FJsonObject> featureObject = features[i]->AsObject();
						const TSharedPtr<FJsonObject>* propertiesPtr;
						
						if (featureObject->TryGetObjectField(TEXT("properties"), propertiesPtr))
						{
							// get msl
							double msl;
							if ((*propertiesPtr)->TryGetNumberField(TEXT("AMSL"), msl))
							{
								// found msl, now get coordinates
								const TSharedPtr<FJsonObject>* geometryPtr;
								if (featureObject->TryGetObjectField(TEXT("geometry"), geometryPtr))
								{
									TSharedPtr<FJsonObject> geometryObject = *geometryPtr;

									FString type = geometryObject->GetStringField(TEXT("type"));
									if (type.Equals(TEXT("polygon"), ESearchCase::IgnoreCase))
									{
										TArray<TSharedPtr<FJsonValue>> coordinates = geometryObject->GetArrayField(TEXT("coordinates"));
										if (coordinates.Num() >= 1)
										{
											TArray<FGeodeticCoord3D> featureCoordinates;
											TArray<TSharedPtr<FJsonValue>> coordinatesChild = coordinates[0]->AsArray();
											for (const TSharedPtr<FJsonValue>& child : coordinatesChild)
											{
												TArray<TSharedPtr<FJsonValue>> childArray = child->AsArray();
												if (childArray.Num() == 3)
												{
													FGeodeticCoord3D coordinate;

													coordinate.Longitude = childArray[0]->AsNumber();
													coordinate.Latitude = childArray[1]->AsNumber();
													coordinate.Altitude = childArray[2]->AsNumber();

													// successfully parsed coordinate
													featureCoordinates.Add(coordinate);
												}
											}

											AsyncTask(ENamedThreads::GameThread, [this, fullPathToFile, type, featureCoordinates, msl]()
											{
												DestroyCounter.Increment();

												if (!IsSafeToExecute())
												{
													DestroyCounter.Decrement();
													return;
												}

												FGeoJsonNode geoJsonNode;
												geoJsonNode.FullPathToFile = fullPathToFile;
												geoJsonNode.Type = type;
												geoJsonNode.Coordinates.Append(featureCoordinates);
												geoJsonNode.MSL = msl;

												QueuedGeoJson.Add(geoJsonNode);

												DestroyCounter.Decrement();
											});
										}
									}
								}
							}
						}
					}
				}
			}

			DestroyCounter.Decrement();
		});
	}
	else if (extension.Equals(TEXT("glb"), ESearchCase::IgnoreCase) || extension.Equals(TEXT("gltf"), ESearchCase::IgnoreCase))
	{
		FTransform spawnTransform = FTransform::Identity;

		if (AGame_Actor_3DTile* newActor = UDeveloper_Statics::GetVHWorld()->SpawnActorDeferred<AGame_Actor_3DTile>(ActorClass, spawnTransform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn))
		{
			AddLoadedActor(parentNode, newActor);

			// --- Mesh
			FVH_MeshImportOptions importOptions;
			importOptions.RootTransform.SetRotation(FRotator(0, 0, 0).Quaternion());
			importOptions.RootTransform.SetScale3D(FVector(1, 1, 1));
			importOptions.Matrix = parentNode->GetTransformMatrix();

			FString modifiedFullPath = FPaths::Combine(FPaths::GetPath(fullPathToFile), FString::Printf(TEXT("%s.glb"), *FPaths::GetBaseFilename(fullPathToFile)));
			
			newActor->LoadFromFile(modifiedFullPath, importOptions);

			newActor->SetActorHiddenInGame(false);

			newActor->SetOwner(GetOwner());

			newActor->bReverseVertOrder = bReverseVertOrder;

			// --- Finish spawning actor and continue
			UGameplayStatics::FinishSpawningActor(newActor, spawnTransform);

			if (!UGame_Statics::IsLocalPlayerInTOC())  // todo ohg | doesn't render in TOC; why?
			{
				FGeodeticCoord3D nwBound = GetNorthWestBound();
				FGeodeticCoord3D seBound = GetSouthEastBound();
				newActor->ImportedMesh->OnMaterialUpdated.AddLambda([nwBound, seBound](UMaterialInstance* material)
				{
					if (UMaterialInstanceDynamic* mid = Cast<UMaterialInstanceDynamic>(material))
					{
						mid->SetScalarParameterValue(TEXT("bCullByLatLong"), 1);
						mid->SetScalarParameterValue(TEXT("minLongitude"), nwBound.Longitude);
						mid->SetScalarParameterValue(TEXT("minLatitude"), seBound.Latitude);
						mid->SetScalarParameterValue(TEXT("maxLongitude"), seBound.Longitude);
						mid->SetScalarParameterValue(TEXT("maxLatitude"), nwBound.Latitude);
					}
				});
			}
		}
	}
}

void UGame_TileComponent_3DTile::PopulateNodeErrorAndBounding(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject)
{
	if (node->BoundingVolumeType.IsEmpty())
	{
		TSharedPtr<FJsonObject> boundingVolumeObject = rootObject->GetObjectField(TEXT("boundingVolume"));

		const TArray<TSharedPtr<FJsonValue>>* boundingVolumeArrayPtr;
		const TSharedPtr<FJsonObject>* extensionsObject;
		if (boundingVolumeObject->TryGetArrayField(TEXT("region"), boundingVolumeArrayPtr))
		{
			TArray<TSharedPtr<FJsonValue>> boundingVolumeArray = *boundingVolumeArrayPtr;

			// west, south, east, north, low hae, high hae
			double west = FMath::RadiansToDegrees<double>(boundingVolumeArray[0]->AsNumber());
			double south = FMath::RadiansToDegrees<double>(boundingVolumeArray[1]->AsNumber());
			double east = FMath::RadiansToDegrees<double>(boundingVolumeArray[2]->AsNumber());
			double north = FMath::RadiansToDegrees<double>(boundingVolumeArray[3]->AsNumber());

			node->SouthWestLow = FGeodeticCoord3D(west, south, boundingVolumeArray[4]->AsNumber());
			node->NorthEastHigh = FGeodeticCoord3D(east, north, boundingVolumeArray[5]->AsNumber());

			node->BoundingVolumeType = TEXT("region");
		}
		else if (boundingVolumeObject->TryGetArrayField(TEXT("sphere"), boundingVolumeArrayPtr))
		{
			TArray<TSharedPtr<FJsonValue>> boundingVolumeArray = *boundingVolumeArrayPtr;

			node->ECEFCenter.X = boundingVolumeArray[0]->AsNumber();
			node->ECEFCenter.Y = boundingVolumeArray[1]->AsNumber();
			node->ECEFCenter.Z = boundingVolumeArray[2]->AsNumber();

			node->RadiusMeters = boundingVolumeArray[3]->AsNumber();

			node->BoundingVolumeType = TEXT("sphere");
		}
		else if (boundingVolumeObject->TryGetArrayField(TEXT("box"), boundingVolumeArrayPtr))
		{
			TArray<TSharedPtr<FJsonValue>> boundingVolumeArray = *boundingVolumeArrayPtr;

			node->ECEFCenter.X = boundingVolumeArray[0]->AsNumber();
			node->ECEFCenter.Y = boundingVolumeArray[1]->AsNumber();
			node->ECEFCenter.Z = boundingVolumeArray[2]->AsNumber();

			node->ECEFX.X = boundingVolumeArray[3]->AsNumber();
			node->ECEFX.Y = boundingVolumeArray[4]->AsNumber();
			node->ECEFX.Z = boundingVolumeArray[5]->AsNumber();

			node->ECEFY.X = boundingVolumeArray[6]->AsNumber();
			node->ECEFY.Y = boundingVolumeArray[7]->AsNumber();
			node->ECEFY.Z = boundingVolumeArray[8]->AsNumber();

			node->ECEFZ.X = boundingVolumeArray[9]->AsNumber();
			node->ECEFZ.Y = boundingVolumeArray[10]->AsNumber();
			node->ECEFZ.Z = boundingVolumeArray[11]->AsNumber();

			node->BoundingVolumeType = TEXT("box");
		}
		else if (boundingVolumeObject->TryGetObjectField(TEXT("extensions"), extensionsObject))
		{
			node->BoundingVolumeType = TEXT("extensions");
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_3DTile::PopulateNodeErrorAndBounding | unknown boundingVolumeType"));
		}

		node->TransformECEF();

		rootObject->TryGetNumberField(TEXT("geometricError"), node->GeometricError);
	}
}

void UGame_TileComponent_3DTile::PopulateNodeTransformMatrix(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject)
{
	const TArray<TSharedPtr<FJsonValue>>* transformArrayPtr;
	if (rootObject->TryGetArrayField(TEXT("transform"), transformArrayPtr))
	{
		TArray<TSharedPtr<FJsonValue>> transformArray = *transformArrayPtr;

		// assumes json is column-major
		for (int32 i = 0; i < 16; i++)
		{
			node->TransformMatrix.M[i % 4][i / 4] = transformArray[i]->AsNumber();
		}
	}
}

void UGame_TileComponent_3DTile::PopulateNodeChildren(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject)
{
	const TArray<TSharedPtr<FJsonValue>>* childrenPtr;
	if (rootObject->TryGetArrayField(TEXT("children"), childrenPtr))
	{
		bool bHasChildren = !node->Children.IsEmpty();
		TArray<TSharedPtr<FJsonValue>> children = *childrenPtr;
		for (int32 i = 0; i < children.Num(); i++)
		{
			if (bHasChildren)
			{
				if (node->Children.IsValidIndex(i))
				{
					LoadNode(node, node->Children[i], TEXT(""), children[i]->AsObject());
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::PopulateNodeChildren | invalid child index | %d | %d | skipping child"), i, node->Children.Num());
				}
			}
			else
			{
				UGame_3DTileNode* childNode = LoadNode(node, nullptr, TEXT(""), children[i]->AsObject());

				node->Children.Add(childNode);
			}
		}
	}
}

void UGame_TileComponent_3DTile::PopulateNodeContent(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject)
{
	auto handleGoogle = [this](FString& uri)
	{
		if (RESTBaseURL.Contains(TEXT("tile.googleapis.com")))
		{
			TArray<FString> parsed;
			uri.ParseIntoArray(parsed, TEXT("?"));

			if (parsed.Num() == 2)
			{
				Session = parsed[1];

				uri = parsed[0];
			}

			FString shortenedURI = FMD5::HashAnsiString(*uri) + TEXT(".") + FPaths::GetExtension(uri);

			GoogleFilenames.Add(shortenedURI, uri);
			uri = shortenedURI;
		}
	};

	if (node->Contents.IsEmpty())
	{
		FString rootPath = TEXT("");
		UGame_3DTileNode* iterateNode = node;
		
		while (rootPath.IsEmpty() && IsValid(iterateNode))
		{
			rootPath = FPaths::GetPath(iterateNode->FullPathToNode);

			iterateNode = iterateNode->Parent;
		}

		// content
		const TSharedPtr<FJsonObject>* contentObject;
		if (rootObject->TryGetObjectField(TEXT("content"), contentObject))
		{
			FString uri;

			bool bValid = (*contentObject)->TryGetStringField(TEXT("uri"), uri);
			if (!bValid)
			{
				bValid = (*contentObject)->TryGetStringField(TEXT("url"), uri);
			}

			if (bValid)
			{
				// special case for google
				handleGoogle(uri);

				//uri = uri.Replace(TEXT("../../"), TEXT(""));
				FString fullPathToContent = FPaths::Combine(rootPath, uri);
				fullPathToContent = FPaths::ConvertRelativePathToFull(fullPathToContent);

				node->Contents.Add(fullPathToContent);

				PathToNode.Add(fullPathToContent, node);
			}
		}

		// contents
		const TArray<TSharedPtr<FJsonValue>>* contentsPtr;
		if (rootObject->TryGetArrayField(TEXT("contents"), contentsPtr))
		{
			TArray<TSharedPtr<FJsonValue>> contents = *contentsPtr;
			for (int32 i = 0; i < contents.Num(); i++)
			{
				TSharedPtr<FJsonObject> content = contents[i]->AsObject();

				FString uri;

				bool bValid = content->TryGetStringField(TEXT("uri"), uri);
				if (!bValid)
				{
					bValid = content->TryGetStringField(TEXT("url"), uri);
				}

				if (bValid)
				{
					// special case for google
					handleGoogle(uri);

					//uri = uri.Replace(TEXT("../../"), TEXT(""));
					FString fullPathToContent = FPaths::Combine(rootPath, uri);
					fullPathToContent = FPaths::ConvertRelativePathToFull(fullPathToContent);

					node->Contents.Add(fullPathToContent);

					PathToNode.Add(fullPathToContent, node);
				}
			}
		}
	}
}

bool UGame_TileComponent_3DTile::NodeIntersects(UGame_3DTileNode* node)
{
	AGame_VirtualObjective* virtualObjective = GetVirtualObjective();
	AVH_GlobeReferenceActor* globeReference = nullptr;
	
	if (virtualObjective != nullptr)
	{
		globeReference = virtualObjective->GetGlobeReference();
	}

	AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController();

	if (playerController == nullptr || globeReference == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::NodeIntersects | playerController or globeReference is nullptr; returning false"));

		return false;
	}

	bool bIsInTOC = UGame_Statics::IsLocalPlayerInTOC();
	
	double maxDistanceMeters = 2000;
	if (!bInitialPass)
	{
		maxDistanceMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(GetNorthWestBound(), GetSouthEastBound());
	}

	FGeodeticCoord2D northWestBound;
	FGeodeticCoord2D southEastBound;

	if (!bIsInTOC)
	{
		// load rectangle in front of player based on player's field of view
		FVector playerLocation;
		FRotator playerRotation;
		playerController->GetPlayerViewPoint(playerLocation, playerRotation);

		float fov = playerController->PlayerCameraManager->GetFOVAngle();

		float hypotenuseDistance = maxDistanceMeters / FMath::Cos(FMath::DegreesToRadians(fov / 2.f));

		FGeodeticCoord3D playerGeoLocation = GetPlayerGeoLocation();

		globeReference = virtualObjective->GetGlobeReference();
		float bearing = globeReference->WorldRotationToBearing(playerRotation);

		FGeodeticCoord2D rightCorner = UVH_GlobeMathStatics::CalculateSurfaceDestination(playerGeoLocation.ToGeodeticCoord2D(), bearing + (fov / 2.f), hypotenuseDistance);
		FGeodeticCoord2D leftCorner = UVH_GlobeMathStatics::CalculateSurfaceDestination(playerGeoLocation.ToGeodeticCoord2D(), bearing - (fov / 2.f), hypotenuseDistance);

		float sideDistance = FMath::Sin(FMath::DegreesToRadians(fov / 2.f)) * hypotenuseDistance;
		FGeodeticCoord2D leftBottomCorner = UVH_GlobeMathStatics::CalculateSurfaceDestination(playerGeoLocation.ToGeodeticCoord2D(), bearing - 100, sideDistance);
		FGeodeticCoord2D rightBottomCorner = UVH_GlobeMathStatics::CalculateSurfaceDestination(playerGeoLocation.ToGeodeticCoord2D(), bearing + 100, sideDistance);

		double north = rightCorner.Latitude;
		double east = rightCorner.Longitude;
		double south = north;
		double west = east;

		north = FMath::Max(north, leftCorner.Latitude);
		east = FMath::Max(east, leftCorner.Longitude);
		south = FMath::Min(south, leftCorner.Latitude);
		west = FMath::Min(west, leftCorner.Longitude);

		north = FMath::Max(north, leftBottomCorner.Latitude);
		east = FMath::Max(east, leftBottomCorner.Longitude);
		south = FMath::Min(south, leftBottomCorner.Latitude);
		west = FMath::Min(west, leftBottomCorner.Longitude);

		north = FMath::Max(north, rightBottomCorner.Latitude);
		east = FMath::Max(east, rightBottomCorner.Longitude);
		south = FMath::Min(south, rightBottomCorner.Latitude);
		west = FMath::Min(west, rightBottomCorner.Longitude);

		northWestBound = FGeodeticCoord2D(west, north);
		southEastBound = FGeodeticCoord2D(east, south);
	}
	else
	{
		// default to entire terrain tile
		northWestBound = GetNorthWestBound();
		southEastBound = GetSouthEastBound();
	}

	// clamp to tile bounds
	FGeodeticCoord2D tileBoundNW = GetNorthWestBound();
	FGeodeticCoord2D tileBoundSE = GetSouthEastBound();
	
	northWestBound.Longitude = FMath::Clamp<double>(northWestBound.Longitude, tileBoundNW.Longitude, tileBoundSE.Longitude);
	northWestBound.Latitude = FMath::Clamp<double>(northWestBound.Latitude, tileBoundSE.Latitude, tileBoundNW.Latitude);

	southEastBound.Longitude = FMath::Clamp<double>(southEastBound.Longitude, tileBoundNW.Longitude, tileBoundSE.Longitude);
	southEastBound.Latitude = FMath::Clamp<double>(southEastBound.Latitude, tileBoundSE.Latitude, tileBoundNW.Latitude);

	return node->IntersectsRectangle(northWestBound, southEastBound, globeReference, maxDistanceMeters);
}

// todo ohg | work-in-progress; finish
void UGame_TileComponent_3DTile::LoadImplicitTiles(UGame_3DTileNode* node)
{
	TSharedPtr<FJsonObject> implicitTiling = *node->ImplicitTilingPtr;
	
	FString subdivisionScheme;
	implicitTiling->TryGetStringField(TEXT("subdivisionScheme"), subdivisionScheme);

	FString subtreeURI;
	const TSharedPtr<FJsonObject>* subtreesPtr;
	if (implicitTiling->TryGetObjectField(TEXT("subtrees"), subtreesPtr))
	{
		(*subtreesPtr)->TryGetStringField(TEXT("uri"), subtreeURI);
	}

	// error checks
	if (subtreeURI.IsEmpty())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadImplicitTiles | subtreeURI is empty | aborting"));

		return;
	}

	if (!subtreeURI.EndsWith(TEXT("subtree")))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadImplicitTiles | json subtrees unsupported | aborting"));

		return;
	}

	if (!subdivisionScheme.Equals(TEXT("QUADTREE")))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadImplicitTiles | unimplemented subdivision scheme: %s | aborting"), *subdivisionScheme);

		return;
	}

	if (node->Contents.IsEmpty())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadImplicitTiles | node->Contents is empty | aborting"));

		return;
	}

	FString rootPath = TEXT("");
	UGame_3DTileNode* iterateNode = node;

	while (rootPath.IsEmpty() && IsValid(iterateNode))
	{
		rootPath = FPaths::GetPath(iterateNode->FullPathToNode);

		iterateNode = iterateNode->Parent;
	}

	FString subtreeRootPath = FString::Printf(TEXT("%s/%s"), *rootPath, *subtreeURI);
	FString tileRootPath = node->Contents.Array()[0];

	// QUADTREE implementation
	auto loadSubtree = [](const FString& fullPathToSubtree, TArray<uint8>& tileAvailability, bool& bTileAvailabilityConstant, TArray<uint8>& childSubtreeAvailability, bool& bChildSubtreeConstant)
	{
		if (!FPaths::FileExists(fullPathToSubtree))
		{
			return false;
		}

		TArray<uint8> data;
		if (!FFileHelper::LoadFileToArray(data, *fullPathToSubtree))
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadImplicitTiles | unable to load subtree: %s | aborting"), *fullPathToSubtree);

			return false;
		}

		if (data.Num() < 24)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_OWT::LoadImplicitTiles | subtree file too small: %s | aborting"), *fullPathToSubtree);

			return false;
		}

		FMemoryReader fromBinary = FMemoryReader(data);
		fromBinary.Seek(4);

		uint32 version;
		fromBinary << version;

		uint64 jsonByteLength;
		fromBinary << jsonByteLength;

		uint64 binaryByteLength;
		fromBinary << binaryByteLength;

		FString json;
		FFileHelper::BufferToString(json, data.GetData() + 24, jsonByteLength);

		bTileAvailabilityConstant = false;
		bChildSubtreeConstant = false;

		TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(json);

		TSharedPtr<FJsonObject> jsonObject;
		if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
		{
			const TArray<TSharedPtr<FJsonValue>>* bufferViewsPtr;
			jsonObject->TryGetArrayField(TEXT("bufferViews"), bufferViewsPtr);

			const TSharedPtr<FJsonObject>* childSubtreeAvailabilityPtr;
			if (jsonObject->TryGetObjectField(TEXT("childSubtreeAvailability"), childSubtreeAvailabilityPtr))
			{
				if (TSharedPtr<FJsonValue> childSubtreeAvailabilityBitstream = (*childSubtreeAvailabilityPtr)->TryGetField(TEXT("bitstream")))
				{
					int32 index = (int32)childSubtreeAvailabilityBitstream->AsNumber();

					if (TSharedPtr<FJsonObject> bufferViewObject = (*bufferViewsPtr)[index]->AsObject())
					{
						//int32 bufferIndex = (int32)bufferViewObject->TryGetField(TEXT("buffer"))->AsNumber();
						int32 byteOffset = (int32)bufferViewObject->TryGetField(TEXT("byteOffset"))->AsNumber();
						int32 byteLength = (int32)bufferViewObject->TryGetField(TEXT("byteLength"))->AsNumber();

						childSubtreeAvailability.AddZeroed(byteLength);
						FMemory::Memcpy(childSubtreeAvailability.GetData(), data.GetData() + 24 + jsonByteLength + byteOffset, byteLength);
					}
				}
				else if (TSharedPtr<FJsonValue> childSubtreeAvailabilityConstant = (*childSubtreeAvailabilityPtr)->TryGetField(TEXT("constant")))
				{
					bChildSubtreeConstant = childSubtreeAvailabilityConstant->AsNumber() != 0;
				}
			}

			const TSharedPtr<FJsonObject>* tileAvailabilityPtr;
			if (jsonObject->TryGetObjectField(TEXT("tileAvailability"), tileAvailabilityPtr))
			{
				if (TSharedPtr<FJsonValue> tileAvailabilityBitstream = (*tileAvailabilityPtr)->TryGetField(TEXT("bitstream")))
				{
					int32 index = (int32)tileAvailabilityBitstream->AsNumber();

					if (TSharedPtr<FJsonObject> bufferViewObject = (*bufferViewsPtr)[index]->AsObject())
					{
						//int32 bufferIndex = (int32)bufferViewObject->TryGetField(TEXT("buffer"))->AsNumber();
						int32 byteOffset = (int32)bufferViewObject->TryGetField(TEXT("byteOffset"))->AsNumber();
						int32 byteLength = (int32)bufferViewObject->TryGetField(TEXT("byteLength"))->AsNumber();

						tileAvailability.AddZeroed(byteLength);
						FMemory::Memcpy(tileAvailability.GetData(), data.GetData() + 24 + jsonByteLength + byteOffset, byteLength);
					}
				}
				else if (TSharedPtr<FJsonValue> tileAvailabilityConstant = (*tileAvailabilityPtr)->TryGetField(TEXT("constant")))
				{
					bTileAvailabilityConstant = tileAvailabilityConstant->AsNumber() != 0;
				}
			}
		}

		return true;
	};

	// returns true if bitIndex is in bitArray and bit at bitIndex is 1
	auto checkBit = [](int64 bitIndex, const TArray<uint8>& bitArray)
	{
		int64 arrayIndex = FMath::FloorToInt64(bitIndex / 8.f);

		if (bitArray.IsValidIndex(arrayIndex))
		{
			int32 bitToCheck = bitIndex % 8;
			uint8 byte = bitArray[arrayIndex];

			return (byte & (1 << bitToCheck)) == 1;
		};

		return false;
	};

	auto getBitIndex = [](uint32 level, uint32 x, uint32 y, bool bUseStartingIndex = false, uint32 startingIndexOverride = -1)
	{
		uint32 startingIndex = 0;

		if (bUseStartingIndex)
		{
			startingIndex = startingIndexOverride;
		}
		else
		{
			uint32 add = 1;
			for (uint32 i = 0; i < level; i++)
			{
				startingIndex += add;
				add *= 4;
			}
		}
		
		TArray<uint8> xBits;
		xBits.AddZeroed(4);
		FMemory::Memcpy(xBits.GetData(), &x, 4);

		TArray<uint8> yBits;
		yBits.AddZeroed(4);
		FMemory::Memcpy(yBits.GetData(), &y, 4);

		TArray<uint8> interleaved;
		interleaved.AddZeroed(8);

		int32 interleavedByteIndex = 7;
		int32 interleavedBitIndex = 7;
		for (int32 byteIndex = 3; byteIndex >= 0; byteIndex--)
		{
			for (int32 bitIndex = 7; bitIndex >= 0; bitIndex--)
			{
				if (yBits[byteIndex] & (1 << bitIndex))
				{
					interleaved[interleavedByteIndex] |= (1 << interleavedBitIndex);
				}
				interleavedBitIndex--;

				if (xBits[byteIndex] & (1 << bitIndex))
				{
					interleaved[interleavedByteIndex] |= (1 << interleavedBitIndex);

				}
				interleavedBitIndex--;

				if (interleavedBitIndex == -1)
				{
					interleavedBitIndex = 7;
					interleavedByteIndex--;
				}
			}
		}

		uint64 interleavedIndex;
		FMemory::Memcpy(&interleavedIndex, interleaved.GetData(), 8);
		
		return startingIndex + interleavedIndex;
	};

	auto getFullPathToSubtree = [](const FString& subtreeRootPath, uint32 level, uint32 x, uint32 y)
	{
		FString fullPathToSubtree = subtreeRootPath;
		fullPathToSubtree.ReplaceInline(TEXT("{level}"), *FString::FromInt(level));
		fullPathToSubtree.ReplaceInline(TEXT("{x}"), *FString::FromInt(x));
		fullPathToSubtree.ReplaceInline(TEXT("{y}"), *FString::FromInt(y));

		return fullPathToSubtree;
	};

	auto getFileToLoadForTile = [&loadSubtree, &checkBit, &getBitIndex, &getFullPathToSubtree](const FString& subtreeRootPath, const FString& tileRootPath, uint32 level, uint32 x, uint32 y, FString& fullPathToTileToLoad)
	{
		// self and parent tiles with lowest level first
		TArray<FImplicitTileInfo> selfAndParentChain;
		selfAndParentChain.Add(FImplicitTileInfo(level, x, y));
		
		uint32 parentX = x;
		uint32 parentY = y;
		for (uint32 i = level; i > 0; i--)
		{
			parentX = FMath::Floor<uint32>(parentX / 2.f);
			parentY = FMath::Floor<uint32>(parentY / 2.f);

			selfAndParentChain.Insert(FImplicitTileInfo(i - 1, parentX, parentY), 0);
		}

		// find highest level in selfAndParentChain that is available
		TArray<uint8> tileAvailability;
		bool bTileAvailabilityConstant = false;
		
		TArray<uint8> childSubtreeAvailability;
		bool bChildSubtreeConstant = false;

		bool bSubtreeLoaded = false;

		for (int32 i = 0; i < selfAndParentChain.Num(); i++)
		{
			FImplicitTileInfo tile = selfAndParentChain[i];

			// load the correct subtree (or child subtree) for this tile
			if (bSubtreeLoaded)
			{
				if (bChildSubtreeConstant || checkBit(getBitIndex(tile.Level, tile.X, tile.Y, true, 0), childSubtreeAvailability))
				{
					// tile contained in child subtree of currently loaded subtree; load child subtree
					FString fullPathToSubtree = getFullPathToSubtree(subtreeRootPath, tile.Level, tile.X, tile.Y);
					bSubtreeLoaded = loadSubtree(fullPathToSubtree, tileAvailability, bTileAvailabilityConstant, childSubtreeAvailability, bChildSubtreeConstant);
				}
			}
			else
			{
				// no subtree loaded; try to load subtree of tile
				FString fullPathToSubtree = getFullPathToSubtree(subtreeRootPath, tile.Level, tile.X, tile.Y);
				bSubtreeLoaded = loadSubtree(fullPathToSubtree, tileAvailability, bTileAvailabilityConstant, childSubtreeAvailability, bChildSubtreeConstant);
			}

			// there is subtree info available
			if (bSubtreeLoaded)
			{
				// check loaded subtree's tileAvailability for this tile
				if (bTileAvailabilityConstant || checkBit(getBitIndex(tile.Level, tile.X, tile.Y), tileAvailability))
				{
					fullPathToTileToLoad = getFullPathToSubtree(tileRootPath, tile.Level, tile.X, tile.Y);
				}
			}
		}

		return !fullPathToTileToLoad.IsEmpty();
	};

	AVH_GlobeReferenceActor* globeReference = nullptr;

	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		globeReference = virtualObjective->GetGlobeReference();
	}

	// determine desired tiles to load (based on geometric error and long/lat bounds)
	if (!IsValid(node->Parent))
	{
		return;
	}
	
	int32 desiredLevel;
	TArray<TPair<int32, int32>> tileXYs;
	node->Parent->GetImplictTilesToLoad(GetNorthWestBound(), GetSouthEastBound(), globeReference, MinGeometricErrorWithinLOD, desiredLevel, tileXYs);
	
	// for each desired tile; get highest level (up to desired level) tile at that position and queue it for filtering
	TArray<FString> fullPathToFilesToLoad;

	FString fullPathToTileToLoad;
	for (int32 i = 0; i < tileXYs.Num(); i++)
	{
		if (getFileToLoadForTile(subtreeRootPath, tileRootPath, desiredLevel, tileXYs[i].Key, tileXYs[i].Value, fullPathToTileToLoad))
		{
			PathToNode.Add(fullPathToTileToLoad, node);

			fullPathToFilesToLoad.Add(fullPathToTileToLoad);
		}
	}

	// for each tile in queue; remove any lower levels that overlap with higher level tile in queue
	// todo ohg | implement

	// load queued tiles
	{
		FScopeLock lock(&FilesToLoadCritSection);

		for (const FString& fullPathToTile : fullPathToFilesToLoad)
		{
			FilesToLoad.Add(fullPathToTile);
		}
	}
}

void UGame_TileComponent_3DTile::LoadNodeContent(UGame_3DTileNode* node)
{
	if (node->Refinement.Equals(TEXT("replace"), ESearchCase::IgnoreCase))
	{
		// remove existing objects loaded for this node's parent
		UnloadNodeContent(node->Parent, true);
	}

	for (const FString& content : node->Contents)
	{
		if (UGame_3DTileNode** contentNodePtr = Nodes.Find(content))
		{
			UGame_3DTileNode* contentNode = *contentNodePtr;
			
			LoadNode(contentNode->Parent, contentNode, content, nullptr);
		}
		else
		{
			if (!LoadedActors.Contains(node))
			{
				if (node->ImplicitTilingPtr != nullptr && node->ImplicitTilingPtr->IsValid())
				{
					LoadImplicitTiles(node);
				}
				else
				{
					FScopeLock lock(&FilesToLoadCritSection);
					
					FilesToLoad.Add(content);
				}
			}
		}
	}
}

void UGame_TileComponent_3DTile::UnloadNodeContent(UGame_3DTileNode* node, bool bIncludeParentNodes)
{
	FScopeLock lock(&LoadedActorsCritSection);
	while (IsValid(node))
	{
		if (TArray<AActor*>* actorsPtr = LoadedActors.Find(node))
		{
			TArray<AActor*> actors = *actorsPtr;

			for (int32 i = 0; i < actors.Num(); i++)
			{
				ActorReference.Remove(actors[i]);

				AsyncTask(ENamedThreads::GameThread, [actor = actors[i]]()
				{
					actor->Destroy();
				});
			}
		}

		LoadedActors.Remove(node);

		if (bIncludeParentNodes)
		{
			node = node->Parent;
		}
	}
}

UGame_3DTileNode* UGame_TileComponent_3DTile::LoadNode(UGame_3DTileNode* nodeParent, UGame_3DTileNode* node, const FString& fullPathToNode, TSharedPtr<FJsonObject> rootObject)
{
	// abort if tile is marked for destruction
	if (AGame_TerrainTile* terrainTile = Cast<AGame_TerrainTile>(GetOwner()))
	{
		if (terrainTile->GetTileStatus() == ETileStatus::ReadyForDestroy)
		{
			return nullptr;
		}
	}

	// create and add node to persist Parent and FullPathToNode in case we need to request file
	if (node == nullptr)
	{
		if (UGame_3DTileNode** nodePtr = Nodes.Find(fullPathToNode))
		{
			// if node is already populated (to some degree), use populated node
			node = *nodePtr;
		}
		else
		{
			// else create a new node and add it
			node = NewObject<UGame_3DTileNode>();
			node->FullPathToNode = fullPathToNode;
			node->Parent = nodeParent;

			if (!node->FullPathToNode.IsEmpty())
			{
				// only add nodes with files on local disk
				Nodes.Add(fullPathToNode, node);
			}
		}
	}
	else
	{
		node->FullPathToNode = fullPathToNode;
		node->Parent = nodeParent;

		if (!node->FullPathToNode.IsEmpty())
		{
			// only add nodes with files on local disk
			Nodes.Add(fullPathToNode, node);
		}
	}

	if (!rootObject.IsValid())
	{
		if (FPaths::FileExists(fullPathToNode))
		{
			FString nodeContents;
			FFileHelper::LoadFileToString(nodeContents, *fullPathToNode);

			TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(nodeContents);

			TSharedPtr<FJsonObject> jsonObject;
			if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
			{
				rootObject = jsonObject->GetObjectField(TEXT("root"));
			}
		}
		else
		{
			{
				FScopeLock lock(&FilesToLoadCritSection);
				
				FilesToLoad.Add(node->FullPathToNode);
			}
		}
	}

	if (rootObject.IsValid())
	{
		//TODO- Cacheable? Need to make sure was loaded properly before adding to Nodes list
		rootObject->TryGetStringField(TEXT("refine"), node->Refinement);

		rootObject->TryGetObjectField(TEXT("implicitTiling"), node->ImplicitTilingPtr);

		// if unspecified, use refinement of parent
		if (node->Refinement.IsEmpty())
		{
			UGame_3DTileNode* iterateNode = node->Parent;

			while (node->Refinement.IsEmpty() && IsValid(iterateNode))
			{
				node->Refinement = iterateNode->Refinement;

				iterateNode = iterateNode->Parent;
			}
		}

		PopulateNodeTransformMatrix(node, rootObject);

		PopulateNodeErrorAndBounding(node, rootObject);

		if (NodeIntersects(node))
		{
			bool bLoadContent = false;

			double desiredMaxGeometricError = GetDesiredMaxGeometricErrorForNode(node);
			if (node->GeometricError > desiredMaxGeometricError)
			{
				// node's geometric error is too high; populate node's children (which recursively calls PopulateNode on children)
				PopulateNodeChildren(node, rootObject);

				// node has no children, this is as good as it gets; load it
				if (node->Children.Num() == 0)
				{
					bLoadContent = true;
				}
			}
			else
			{
				bLoadContent = true;
			}

			if (bLoadContent)
			{
				// node's geometric error is low enough OR edge case with no children; populate node's content
				PopulateNodeContent(node, rootObject);

				LoadNodeContent(node);
			}
		}
	}

	return node;
}

FGeodeticCoord3D UGame_TileComponent_3DTile::GetPlayerGeoLocation() const
{
	FGeodeticCoord3D playerGeoLocation;

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		playerGeoLocation = cotManager->GetGeodeticLocation();
	}

	return playerGeoLocation;
}

bool UGame_TileComponent_3DTile::IsLoadComplete() const
{
	if (FilesToLoad.Num() != 0)
	{
		return false;
	}

	{
		FScopeLock lock(&LoadedActorsCritSection);
		for (const TPair<UGame_3DTileNode*, TArray<AActor*>>& entry : LoadedActors)
		{
			for (AActor* actor : entry.Value)
			{
				if (UGame_ImportedMeshComponent* meshComponent = Cast<UGame_ImportedMeshComponent>(actor->GetComponentByClass(UGame_ImportedMeshComponent::StaticClass())))
				{
					if (meshComponent->GetClass()->ImplementsInterface(UInterface_Developer_Task::StaticClass()))
					{
						if (IInterface_Developer_Task::Execute_GetTaskStatus(meshComponent) != ETaskStatus::Finished)
						{
							return false;
						}
					}
				}
			}
		}
	}

	return true;
}

AActor* UGame_TileComponent_3DTile::SpawnPolygon(const TArray<FGeodeticCoord3D>& coordinates, double msl)
{
	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			TArray<FVector> lowerVertices;
			TArray<FVector> upperVertices;
			for (const FGeodeticCoord3D& coordinate : coordinates)
			{
				lowerVertices.Add(globeReference->GeodeticToWorldDouble(coordinate));

				FGeodeticCoord3D upperCoordinate = coordinate;
				upperCoordinate.Altitude = UVH_GlobeMathStatics::MSLToHAE(coordinate.ToGeodeticCoord2D(), msl);
				upperVertices.Add(globeReference->GeodeticToWorldDouble(upperCoordinate));
			}

			TArray<int32> triangles;
			for (int32 i = 0; i < lowerVertices.Num() - 1; i++)
			{
				triangles.Add(i);
				triangles.Add(i + lowerVertices.Num());
				triangles.Add(i + 1);

				triangles.Add(i + 1 + lowerVertices.Num());
				triangles.Add(i + lowerVertices.Num());
				triangles.Add(i + 1);
			}

			TArray<FVector> vertices;
			vertices.Append(lowerVertices);
			vertices.Append(upperVertices);

			FTransform spawnTransform = FTransform::Identity;
			
			FActorSpawnParameters spawnParams;
			spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			spawnParams.Owner = GetOwner();
			AGame_Actor_3DTile* newActor = UDeveloper_Statics::GetVHWorld()->SpawnActor<AGame_Actor_3DTile>(ActorClass, spawnTransform, spawnParams);
			
			newActor->SetActorHiddenInGame(false);
			
			if (UGame_ImportedMeshComponent* meshComponent = Cast<UGame_ImportedMeshComponent>(newActor->GetComponentByClass(UGame_ImportedMeshComponent::StaticClass())))
			{
				meshComponent->BuildMeshFromVerticesAndTriangles(vertices, triangles);
			}
			
			UMaterialInstanceDynamic* mid = UMaterialInstanceDynamic::Create(PolygonMaterial, this);
			
			TArray<FLinearColor> colors;
			colors.Add(FLinearColor(FColor::Cyan));
			colors.Add(FLinearColor(FColor::Yellow));
			
			mid->SetVectorParameterValue(FName(TEXT("Color")), colors[FMath::RandHelper(colors.Num())]);
			
			newActor->SetMaterialOverride(mid);

			return newActor;
		}
	}

	UE_LOG(Game, Warning, TEXT("UGame_TileComponent_3DTile::SpawnPolygon | error spawning polygon | returning nullptr"));

	return nullptr;
}

void UGame_TileComponent_3DTile::AddLoadedActor(UGame_3DTileNode* node, AActor* actor)
{
	{
		FScopeLock lock(&LoadedActorsCritSection);
		if (TArray<AActor*>* actorsPtr = LoadedActors.Find(node))
		{
			actorsPtr->Add(actor);
		}
		else
		{
			TArray<AActor*> actors;
			actors.Add(actor);

			LoadedActors.Add(node, actors);
		}
	}

	ActorReference.Add(actor);
}

double UGame_TileComponent_3DTile::GetDesiredMaxGeometricErrorForNode(UGame_3DTileNode* node) const
{
	AVH_GlobeReferenceActor* globeReference = nullptr;
	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		globeReference = virtualObjective->GetGlobeReference();
	}

	double nodeDistanceMeters = node->GetDistanceMeters(GetPlayerGeoLocation(), globeReference);
	if (nodeDistanceMeters < LODMeters)
	{
		return FMath::Clamp<double>(FMath::Lerp<double>(MinGeometricErrorWithinLOD, MaxGeometricErrorWithinLOD, nodeDistanceMeters / LODMeters), MinGeometricErrorWithinLOD, MaxGeometricErrorWithinLOD);
	}

	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		if (nodeDistanceMeters < tileManager->GetDrawDistanceMeters())
		{
			return GeometricErrorBeyondLOD;
		}
	}
	
	return nodeDistanceMeters;//FMath::Lerp<double>(1000000, 1000, (GetZoomLevel() - 5) / 9.0;
}


// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_TileComponent_3DTile::PeriodicLoadFiles()
{
	// load one file per call; request multiple files per load
	{
		FScopeLock lock(&FilesToLoadCritSection);
		
		for (int32 i = 0; i < FilesToLoad.Num(); i++)
		{
			FString fullPathToFile = FilesToLoad[i];

			FilesToLoad.RemoveAt(i, 1);

			if (FPaths::FileExists(fullPathToFile))
			{
				LoadFile(fullPathToFile);

				break;
			}
			
			if (!RESTBaseURL.IsEmpty())
			{
				// request file if file does not exist on local disk and this is a streamed dataset
				FOnReceiveFile receiveFileDelegate;
				receiveFileDelegate.BindLambda([this](const FString& fullPathToFile)
				{
					{
						FScopeLock lock(&FilesToLoadCritSection);
						FilesToLoad.Add(fullPathToFile);
					}
				});

				RequestFile(fullPathToFile, receiveFileDelegate);

				i--;
			}
		}
	}

	// todo ohg | fix
	/*for (int32 i = 0; i < 5 && QueuedGeoJson.Num() > 0; i++)
	{
		if (QueuedGeoJson[0].Type.Equals(TEXT("polygon"), ESearchCase::IgnoreCase))
		{
			if (AActor* newActor = SpawnPolygon(QueuedGeoJson[0].Coordinates, QueuedGeoJson[0].MSL))
			{
				AddLoadedActor(QueuedGeoJson[0].FullPathToFile, newActor);
			}
		}

		QueuedGeoJson.RemoveAt(0, 1);
	}*/

	if (IsLoadComplete())
	{
		if (GetComponentStatus() == EComponentStatus::GameThreadStarted)
		{
			// fire game logic finished when done with intial load of tiles
			SetComponentStatus(EComponentStatus::GameThreadFinished);
			OnGameLogicCompletedGeneric.ExecuteIfBound();
		}

		if (bInitialPass)
		{
			bInitialPass = false;

			if (!UGame_Statics::IsLocalPlayerInTOC())
			{
				bForceUpdateTileset = true;
			}
		}
	}
}

void UGame_TileComponent_3DTile::PeriodicUpdateTileset()
{
	FGeodeticCoord3D playerGeoLocation = GetPlayerGeoLocation();

	FVector location;
	FRotator playerRotation;
	
	AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController();
	playerController->GetPlayerViewPoint(location, playerRotation);

	bool bUpdateTileset = bForceUpdateTileset;
	if (!bUpdateTileset)
	{
		// update tileset when player has not moved since last update AND player is not in same location as when last update occurred
		FVector playerLocationVector = playerGeoLocation.ToVector();
		bUpdateTileset = playerLocationVector.Equals(LastPlayerGeoLocation.ToVector(), 0.5) && !playerLocationVector.Equals(LastUpdateGeoLocation.ToVector(), 0.5);

		LastPlayerGeoLocation = playerGeoLocation;

		if (bUpdateTileset)
		{
			bInitialPass = true;
		}
		else
		{
			// update tileset when player has not changed view since last update AND player view is not the same as when last update occurred
			bUpdateTileset = playerRotation.Equals(LastPlayerRotation, 0.5) && !playerRotation.Equals(LastUpdatePlayerRotation, 0.5);

			LastPlayerRotation = playerRotation;
		}
	}

	if (bUpdateTileset)
	{
		if (ReceiveFileDelegates.Num() > 0)
		{
			if (UGame_TileManager* tileManager = UGame_TileManager::Get())
			{
				tileManager->RemoveHTTPRequests(this);
			}
		}

		UWorld* world = UDeveloper_Statics::GetVHWorld();

		world->GetTimerManager().PauseTimer(PeriodicLoadFilesTimerHandle);
		world->GetTimerManager().PauseTimer(PeriodicUpdateTilesetTimerHandle);

		bForceUpdateTileset = false;

		LastUpdateGeoLocation = playerGeoLocation;
		LastUpdatePlayerRotation = playerRotation;

		Async(EAsyncExecution::ThreadPool, [this]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}

			LoadNode(nullptr, nullptr, FullPathToTileset, nullptr);

			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				QueuedGeoJson.Empty();

				if (UWorld* world = UDeveloper_Statics::GetVHWorld())
				{
					world->GetTimerManager().UnPauseTimer(PeriodicLoadFilesTimerHandle);
					world->GetTimerManager().UnPauseTimer(PeriodicUpdateTilesetTimerHandle);
				}
			});

			DestroyCounter.Decrement();
		});
	}
}

void UGame_TileComponent_3DTile::HandleTileStatusChanged(AGame_TerrainTile* terrainTile, const ETileStatus tileStatus)
{
	if (tileStatus == ETileStatus::ReadyForDestroy)
	{
		if (UWorld* world = UDeveloper_Statics::GetVHWorld())
		{
			world->GetTimerManager().ClearTimer(PeriodicLoadFilesTimerHandle);

			world->GetTimerManager().ClearTimer(PeriodicUpdateTilesetTimerHandle);
		}

		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			tileManager->RemoveHTTPRequests(this);
		}
	}
}
