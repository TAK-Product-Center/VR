// Required Includes
#include "Game_TerrainTile.h"
#include "Game.h"

// Engine Includes
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Texture2D.h"
#include "ProceduralMeshComponent.h"
#include "Async/Async.h"

// VH Plugin Includes
#include "Developer_Subsystem_TaskTracker.h"
#include "Developer_TaskScheduler.h"
#include "Developer_Statics.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "VH_GlobeMathStatics.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_PlayerController.h"
#include "Game_TileManager.h"
#include "Game_TileComponent.h"
#include "Game_TileComponent_Mesh.h"
#include "Game_TileComponent_Mat.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_PlayerState.h"
#include "Game_GameInstance.h"
#include "Game_Subsystem_Core.h"
#include "Game_GlobeReferenceActor_Ellipsoid.h"
#include "Game_MeshComponent_Ellipsoid.h"

AGame_TerrainTile::AGame_TerrainTile() :
	TileStatus(ETileStatus::Default),
	TaskStatus(ETaskStatus::Finished),
	TrianglesPerComponent(200000),
	SecondsBetweenComponentCreate(0.05),
	HighResU(-1),
	HighResV(-1),
	HighResElapsed(0),
	HighResCooldown(0.01)
{
    ConstructorHelpers::FObjectFinder<UMaterialInterface> defaultMaterial(TEXT("Material'/Game/VTAK/Materials/SatelliteImagery/M_SatelliteImagery.M_SatelliteImagery'"));
    if (defaultMaterial.Succeeded())
    {
        MaterialTemplate = defaultMaterial.Object;
    }

	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TerrainTileSceneComponent"));
}

void AGame_TerrainTile::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0, 0, 0));

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		TrianglesPerComponent = FMath::RoundToInt(gameSettings->GetSettingDouble(TEXT("TileTrianglesPerComponent")));
		SecondsBetweenComponentCreate = gameSettings->GetSettingDouble(TEXT("TileSecondsBetweenComponentCreate"));
	}

	// todo ohg | need to set tile manager on each tile
	if (AGame_VirtualObjective* activeVO = GetVirtualObjective())
	{
		if (AVH_GlobeReferenceActor* globeRef = activeVO->GetGlobeReference())
		{
			OriginalGlobeScale3D = globeRef->GetActorScale3D();
		}
	}
}

void AGame_TerrainTile::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		taskTracker->RemoveActiveTask(GetTaskTrackerID());
	}

	OnTileStatusChanged.Clear();

	for (FUpdateTextureRegion2D* regionToDelete : Regions)
	{
		delete regionToDelete;
	}
	Regions.Empty();

	if (IsRooted())
	{
		RemoveFromRoot();
	}

	Super::EndPlay(endPlayReason);
}

bool AGame_TerrainTile::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

void AGame_TerrainTile::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (IsRooted() && DestroyCounter.GetValue() == 0)
	{
		RemoveFromRoot();

		Destroy();
	}
	
	if (HighResU >= 0 && HighResV >= 0)
	{
		if (GetTileStatus() == ETileStatus::ReadyForDestroy)
		{
			return;
		}

		HighResElapsed += deltaSeconds;

		if ((HighResU == 0 && HighResV == 0) || HighResElapsed > HighResCooldown)
		{
			int32 width = MatSizeX < 16384 ? 1024 : 2048;
			int32 height = MatSizeX < 16384 ? 1024 : 2048;
			int32 srcX = HighResU * width;
			int32 srcY = HighResV * height;
			int32 destX = srcX;
			int32 destY = srcY;
			
			FUpdateTextureRegion2D* region = new FUpdateTextureRegion2D(destX, destY, srcX, srcY, width, height);
			Regions.Add(region);
			
			DestroyCounter.Increment();
			Texture->UpdateTextureRegions(0, 1, region, MatSizeX * 4, 4, (uint8*)HighResTexturePixels.GetData(), [this, width, height](uint8* srcData, const FUpdateTextureRegion2D* regions)
			{
				if ((regions[0].SrcX == MatSizeX - width) && (regions[0].SrcY == MatSizeX - height))
				{
					HighResTexturePixels.Empty();
				}

				DestroyCounter.Decrement();
			});

			HighResElapsed = 0;

			if ((HighResU * width == MatSizeX - width) && (HighResV * height == MatSizeY - height))
			{
				HighResU = -1;
				HighResV = -1;

				bMaterialDone = true;
				if (bMeshDone)
				{
					SetTileStatus(ETileStatus::GameThreadFinished);
				}
			}
			else
			{
				if (HighResU * width == MatSizeX - width)
				{
					HighResV++;
				}

				HighResU = (HighResU + 1) % (MatSizeX / width);
			}
		}

		HighResCooldown = FMath::Clamp<double>(deltaSeconds < 0.01 ? HighResCooldown - 0.001 : HighResCooldown + 0.001, 0.005, 0.05);
	}
}

void AGame_TerrainTile::SetBoundsAndZoom(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, const int32 heightmapZoomLevel, const int32 imageryZoomLevel)
{
	TileBounds = tileBounds;

	HeightmapZoomLevel = heightmapZoomLevel;

	ImageryZoomLevel = imageryZoomLevel;

	for (TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (UGame_TileComponent_Mesh* meshComponent = Cast<UGame_TileComponent_Mesh>(entry.Value))
		{
			entry.Value->SetBoundsAndZoom(tileBounds, HeightmapZoomLevel);
		}
		else
		{
			entry.Value->SetBoundsAndZoom(tileBounds, ImageryZoomLevel);
		}
	}

	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		taskTracker->AddActiveTask(GetTaskTrackerID(), GetTaskTrackerDescription(), 0);
	}
}

void AGame_TerrainTile::GetComponentsByStatus(EComponentStatus componentStatus, TArray<UGame_TileComponent*>& components)
{
	for (TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (entry.Value->GetComponentStatus() == componentStatus)
		{
			components.Add(entry.Value);
		}
	}
}

void AGame_TerrainTile::HandleModification(UGame_TileComponent* tileComponent)
{
	bModifiedDuringTask = TaskStatus != ETaskStatus::Finished;
	
	if (!bModifiedDuringTask && tileComponent->GetComponentStatus() == EComponentStatus::GameThreadFinished)
	{
		tileComponent->SetComponentStatus(EComponentStatus::Initialized);

		SetTileStatus(ETileStatus::Default);
	}
}

void AGame_TerrainTile::SetImageryCut(const FGeodeticCoord2D& northWest, const FGeodeticCoord2D& southEast)
{
	ImageryCut = TPair<FGeodeticCoord2D, FGeodeticCoord2D>(northWest, southEast);
	bHasImageryCut = true;

	ApplyCutToMaterial();
}

void AGame_TerrainTile::SetCollisionCut(const FGeodeticCoord2D& northWest, const FGeodeticCoord2D& southEast, bool bAll)
{
	CollisionCut = TPair<FGeodeticCoord2D, FGeodeticCoord2D>(northWest, southEast);

	bHasCollisionCut = true;
	bCutAllCollision = bAll;

	ApplyCutToMesh(nullptr);
}

void AGame_TerrainTile::ClearImageryCut()
{
	if (bHasImageryCut)
	{
		bHasImageryCut = false;

		ApplyCutToMaterial();
	}
}

void AGame_TerrainTile::ClearCollisionCut()
{
	if (bHasCollisionCut)
	{
		bHasCollisionCut = false;
		bCutAllCollision = false;

		ApplyCutToMesh(nullptr);
	}
}

void AGame_TerrainTile::SetDrawDistance(const FVector& center, const double distanceMeters)
{
	for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (UGame_TileComponent_Mesh* meshComponent = Cast<UGame_TileComponent_Mesh>(entry.Value))
		{
			bool bDirty = meshComponent->SetDrawDistance(center, distanceMeters);
			if (bDirty)
			{
				HandleModification(meshComponent);
			}

			return;
		}
	}

	//UE_LOG(Game, Warning, TEXT("-- AGame_TerrainTile::SetDrawDistance | no mesh component"));
}

UGame_TileComponent* AGame_TerrainTile::AddTileComponent(const FString& id, TSubclassOf<UGame_TileComponent> tileComponentClass)
{
	// only allow one UGame_TileComponent_Mesh
	if ((*tileComponentClass)->IsChildOf(UGame_TileComponent_Mesh::StaticClass()))
	{
		for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
		{
			if (Cast<UGame_TileComponent_Mesh>(entry.Value) != nullptr)
			{
				UE_LOG(Game, Warning, TEXT("-- attempted to add more than one UGame_TileComponent_Mesh to a AGame_TerrainTile, aborting add"));
				return nullptr;
			}
		}
	}

	UGame_TileComponent* tileComponent = NewObject<UGame_TileComponent>(this, tileComponentClass);
	tileComponent->OnComponentCreated();
	tileComponent->SetRelativeLocation(FVector(0, 0, 0));
	tileComponent->SetWorldLocation(FVector(0, 0, 0));

	if (tileComponent->bAutoRegister)
	{
		tileComponent->RegisterComponent();
	}

	TileComponents.Add(id, tileComponent);

	int32 zoomLevel = GetImageryZoomLevel();
	if (UGame_TileComponent_Mat* matComponent = Cast<UGame_TileComponent_Mat>(tileComponent))
	{
		matComponent->OnGameLogicCompleted.BindUObject(this, &AGame_TerrainTile::HandleMatGameLogicCompleted);
	}
	else if (UGame_TileComponent_Mesh* meshComponent = Cast<UGame_TileComponent_Mesh>(tileComponent))
	{
		meshComponent->OnGameLogicCompleted.BindUObject(this, &AGame_TerrainTile::HandleMeshGameLogicCompleted);

		zoomLevel = GetHeightmapZoomLevel();
	}
	else 
	{
		tileComponent->OnGameLogicCompletedGeneric.BindUObject(this, &AGame_TerrainTile::HandleGameLogicCompletedGeneric);
	}

	tileComponent->SetBoundsAndZoom(GetTileBounds(), zoomLevel);

	return tileComponent;
}

void AGame_TerrainTile::HandleGameLogicCompletedGeneric()
{
	for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (entry.Value->GetComponentStatus() != EComponentStatus::GameThreadFinished)
		{
			return;
		}
	}
	
	// if task is not scheduled or running
	if (TaskStatus == ETaskStatus::Finished)
	{
		SetTileStatus(ETileStatus::GameThreadFinished);
	}
}

void AGame_TerrainTile::HandleMatGameLogicCompleted(UGame_TileComponent_Mat* tileComponent)
{
	bMaterialDone = false;

	CreateMaterial();

	AddTaskIfComponentsReady();
}

void AGame_TerrainTile::HandleMeshGameLogicCompleted(const TArray<FVector>& vertices, const TArray<int32>& triangles, const TArray<FVector2D>& uvs)
{
	Vertices.Empty();
	Triangles.Empty();
	UVs.Empty();

	Vertices.Append(vertices);
	Triangles.Append(triangles);
	UVs.Append(uvs);

	bool bRemoveMercator = false;
	AGame_GlobeReferenceActor_Ellipsoid* globeReference = nullptr;
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		globeReference = Cast<AGame_GlobeReferenceActor_Ellipsoid>(virtualObjective->GetGlobeReference());
		if (IsValid(globeReference))
		{
			bRemoveMercator = true;
		}
	}

	for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (UGame_MeshComponent_Ellipsoid* meshComponent = Cast<UGame_MeshComponent_Ellipsoid>(entry.Value))
		{
			// UGame_MeshComponent_Ellipsoid already removes mercator
			bRemoveMercator = false;
		}
	}

	if (bRemoveMercator)
	{
		double northBound = TileBounds.Key.Latitude;
		double southBound = TileBounds.Value.Latitude;

		double topMercator = FMath::Loge(FMath::Tan((PI / 4.f) + (FMath::DegreesToRadians(northBound / 2.f))));
		double bottomMercator = FMath::Loge(FMath::Tan((PI / 4.f) + (FMath::DegreesToRadians(southBound / 2.f))));
		double totalMercatorDistance = topMercator - bottomMercator;

		for (int32 i = 0; i < UVs.Num(); i++)
		{
			double yDegrees = globeReference->WorldToGeodeticDouble(Vertices[i]).Latitude;
			double yRadians = FMath::DegreesToRadians(yDegrees);
			double mercator = FMath::Loge(FMath::Tan((PI / 4.f) + (yRadians / 2.f)));

			// imagery has mercator projection, so transform uvY coord to offset distortion caused by mercator projection
			double uvY = (topMercator - mercator) / totalMercatorDistance;
		
			UVs[i].Y = uvY;
		}
	}

	AddTaskIfComponentsReady();
}

void AGame_TerrainTile::AddTaskIfComponentsReady()
{
	if (TileStatus == ETileStatus::ReadyForDestroy)
	{
		return;
	}

	for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (Cast<UGame_TileComponent_Mesh>(entry.Value) || Cast<UGame_TileComponent_Mat>(entry.Value))
		{
			if (entry.Value->GetComponentStatus() != EComponentStatus::GameThreadFinished)
			{
				return;
			}
		}
	}
	
	if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
	{
		if (!pc->GetTerrainTileBuilder()->HasTask(TScriptInterface<IInterface_Developer_Task>(this)))
		{
			pc->GetTerrainTileBuilder()->AddTask(TScriptInterface<IInterface_Developer_Task>(this));

			if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
			{
				taskTracker->AddActiveTask(GetTaskTrackerID(), GetTaskTrackerDescription(), 0.5);
			}
		}
	}
}

void AGame_TerrainTile::SetTileStatus(const ETileStatus tileStatus)
{
	if (TileStatus == ETileStatus::ReadyForDestroy)
	{
		UE_LOG(Game, Log, TEXT("-- AGame_TerrainTile::SetTileStatus | trying to set tile status to '%s' (%d), but it is 'ReadyForDestroy'"), *UEnum::GetValueAsString(TEXT("Game.ETileStatus"), tileStatus), (int32)tileStatus);
		return;
	}

	if (tileStatus == TileStatus)
	{
		return;
	}

	TileStatus = tileStatus;

	if (TileStatus == ETileStatus::GameThreadFinished)
	{
		TaskStatus = ETaskStatus::Finished;

		if (bModifiedDuringTask)
		{
			// modified while task was running, reset components and status
			for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
			{
				entry.Value->SetComponentStatus(EComponentStatus::Initialized);
			}

			TileStatus = ETileStatus::Default;

			bModifiedDuringTask = false;
		}
	}
	else if (TileStatus == ETileStatus::ReadyForDestroy)
	{
		TaskStatus = ETaskStatus::Finished;
	}

	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		switch (TileStatus)
		{
			case ETileStatus::Default:
				taskTracker->AddActiveTask(GetTaskTrackerID(), GetTaskTrackerDescription(), 0);
				break;

			case ETileStatus::GameThreadFinished:
			case ETileStatus::ReadyForDestroy:
				taskTracker->RemoveActiveTask(GetTaskTrackerID());
				break;

			default:
				break;
		}
	}

	OnTileStatusChanged.Broadcast(this, TileStatus);
}

FString AGame_TerrainTile::GetComponentID(UGame_TileComponent* tileComponent) const
{
	for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (entry.Value == tileComponent)
		{
			return entry.Key;
		}
	}

	return TEXT("");
}

bool AGame_TerrainTile::GetHAEBounds(FVector2D& haeBounds) const
{
	// prefer mesh components
	for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (UGame_TileComponent_Mesh* meshComponent = Cast<UGame_TileComponent_Mesh>(entry.Value))
		{
			if (meshComponent->GetHAEBounds(haeBounds))
			{
				return true;
			}
		}
	}

	// try any component
	for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
	{
		if (entry.Value->GetHAEBounds(haeBounds))
		{
			return true;
		}
	}

	// fall back to DTED
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		FGeodeticCoord2D coordinate;
		coordinate.Longitude = (TileBounds.Key.Longitude + TileBounds.Value.Longitude) / 2.f;
		coordinate.Latitude = (TileBounds.Key.Latitude + TileBounds.Value.Latitude) / 2.f;

		double hae;
		if (tileManager->GetHAE(coordinate, hae))
		{
			haeBounds.X = hae;
			haeBounds.Y = hae;
			
			return true;
		}
	}

	UE_LOG(Game, Warning, TEXT("-- AGame_TerrainTile::GetHAEBounds | unable to determine | returning false"));
	
	return false;
}

void AGame_TerrainTile::GlobeReferenceScaleUpdated(const FVector& newScale3D)
{
	FVector toSet = newScale3D / OriginalGlobeScale3D;

	if (!toSet.Equals(GetActorScale3D()))
	{
		SetActorScale3D(toSet);

		for (const TPair<FString, UGame_TileComponent*>& entry : TileComponents)
		{
			if (entry.Value->GlobeReferenceScaleUpdated(newScale3D))
			{
				HandleModification(entry.Value);
			}
		}
	}
}

AGame_VirtualObjective* AGame_TerrainTile::GetVirtualObjective() const
{
	return UGame_TileManager::Get()->GetVirtualObjective();
}

void AGame_TerrainTile::GetVerticesWithin(const TArray<FBox2D>& gridBoxes, TArray<TSet<FVector>>& gridBoxVertices) const
{
	for (const FVector& vertexWorldLocation : Vertices)
	{
		for (int32 i = 0; i < gridBoxes.Num(); i++)
		{
			if (gridBoxes[i].IsInside(FVector2D(vertexWorldLocation.X, vertexWorldLocation.Y)))
			{
				gridBoxVertices[i].Add(vertexWorldLocation);

				break;
			}
		}
	}
}

void AGame_TerrainTile::PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	PreModifyVOGlobeCoord = globeReference->WorldToGeodeticDouble(GetActorLocation());
}

void AGame_TerrainTile::PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	FVector worldLocation = globeReference->GeodeticToWorldDouble(PreModifyVOGlobeCoord);
	SetActorLocation(worldLocation);
}

void AGame_TerrainTile::ApplyCutToMaterial()
{
	if (MaterialInstance != nullptr)
	{
		if (bHasImageryCut)
		{
			if (AGame_VirtualObjective* activeVO = GetVirtualObjective())
			{
				if (AVH_GlobeReferenceActor_Ellipsoid* globeReferenceEllipse = Cast<AVH_GlobeReferenceActor_Ellipsoid>(activeVO->GetGlobeReference()))
				{
					FGeodeticCoord2D nwCoordinate = ImageryCut.Key;
					FGeodeticCoord2D seCoordinate = ImageryCut.Value;

					MaterialInstance->SetScalarParameterValue(TEXT("bHasCut"), 1);
					MaterialInstance->SetScalarParameterValue(TEXT("cutMinLongitude"), FMath::Min<double>(nwCoordinate.Longitude, seCoordinate.Longitude));
					MaterialInstance->SetScalarParameterValue(TEXT("cutMinLatitude"), FMath::Min<double>(nwCoordinate.Latitude, seCoordinate.Latitude));
					MaterialInstance->SetScalarParameterValue(TEXT("cutMaxLongitude"), FMath::Max<double>(nwCoordinate.Longitude, seCoordinate.Longitude));
					MaterialInstance->SetScalarParameterValue(TEXT("cutMaxLatitude"), FMath::Max<double>(nwCoordinate.Latitude, seCoordinate.Latitude));
				}
			}
		}
		else
		{
			MaterialInstance->SetScalarParameterValue(TEXT("bHasCut"), 0);
		}
	}
}

void AGame_TerrainTile::ApplyCutToMesh(UProceduralMeshComponent* meshComponent)
{
	auto applyCut = [this](AVH_GlobeReferenceActor* globeReference, UProceduralMeshComponent* meshComponent)
	{
		if (bHasCollisionCut)
		{
			meshComponent->bCutAllCollision = bCutAllCollision;
			if (!meshComponent->bCutAllCollision)
			{
				if (AGame_VirtualObjective* activeVO = GetVirtualObjective())
				{
					if (AVH_GlobeReferenceActor_Ellipsoid* globeReferenceEllipse = Cast<AVH_GlobeReferenceActor_Ellipsoid>(activeVO->GetGlobeReference()))
					{
						// determine bounds of cut
						FGeodeticCoord2D nwCoordinate = CollisionCut.Key;
						FGeodeticCoord2D seCoordinate = CollisionCut.Value;

						FGeodeticCoord3D centerCoordinate;
						centerCoordinate.Latitude = (seCoordinate.Latitude + nwCoordinate.Latitude) / 2.f;
						centerCoordinate.Longitude = (seCoordinate.Longitude + nwCoordinate.Longitude) / 2.f;

						FGeodeticCoord3D xCoordinate = centerCoordinate;
						xCoordinate.Longitude = seCoordinate.Longitude;

						FGeodeticCoord3D yCoordinate = centerCoordinate;
						yCoordinate.Latitude = nwCoordinate.Latitude;

						FGeodeticCoord3D zCoordinate = centerCoordinate;
						zCoordinate.Altitude = 99999999;

						FVector center = globeReferenceEllipse->GeodeticToWorldDouble(centerCoordinate);
						FVector halfBoxX = globeReferenceEllipse->GeodeticToWorldDouble(xCoordinate) - center;
						FVector halfBoxY = globeReferenceEllipse->GeodeticToWorldDouble(yCoordinate) - center;
						FVector halfBoxZ = globeReferenceEllipse->GeodeticToWorldDouble(zCoordinate) - center;

						// create transform based on cut bounds
						FTransform boxTransform(halfBoxX, halfBoxY, halfBoxZ, center);

						meshComponent->NoCollisionWithinBoxTransform = boxTransform;
					}
				}
			}
		}
		else
		{
			meshComponent->bCutAllCollision = false;
			meshComponent->NoCollisionWithinBoxTransform = FTransform::Identity;
		}

		meshComponent->UpdateCollisionPublic();
	};

	if (AGame_VirtualObjective* activeVO = GetVirtualObjective())
	{
		if (AVH_GlobeReferenceActor* globeReference = activeVO->GetGlobeReference())
		{
			if (meshComponent != nullptr)
			{
				applyCut(globeReference, meshComponent);
			}
			else
			{
				for (UProceduralMeshComponent* proceduralMeshComponent : ProceduralMeshComponents)
				{
					applyCut(globeReference, proceduralMeshComponent);
				}
			}
		}
	}
}

void AGame_TerrainTile::CreateMaterial()
{
	if (Texture == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_TerrainTile::CreateMaterial | Texture is nullptr | aborting"));
		
		return;
	}

	// early out
	if (IsValid(MaterialInstance))
	{
		ApplyCutToMaterial();

		bMaterialDone = true;
		if (bMeshDone)
		{
			SetTileStatus(ETileStatus::GameThreadFinished);
		}

		return;
	}

	MaterialInstance = nullptr;
	
	// check for a UGame_TileComponent_Mat and early out if none exist
	bool bMatComponentExists = false;
	for (TPair<FString, UGame_TileComponent*> entry : TileComponents)
	{
		if (Cast<UGame_TileComponent_Mat>(entry.Value))
		{
			bMatComponentExists = true;

			break;
		}
	}

	if (!bMatComponentExists)
	{
		bMaterialDone = true;
		if (bMeshDone)
		{
			SetTileStatus(ETileStatus::GameThreadFinished);
		}

		return;
	}

	// combine mats and populate pixels on helper thread
	Async(EAsyncExecution::ThreadPool, [this]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}
		
		// combine mats
		cv::Mat combinedMat(MatSizeX, MatSizeY, CV_8UC3);

		int32 numberMatComponents = 0;
		for (TPair<FString, UGame_TileComponent*> entry : TileComponents)
		{
			UGame_TileComponent_Mat* matComponent = Cast<UGame_TileComponent_Mat>(entry.Value);

			if (matComponent != nullptr &&
				matComponent->IsValidLowLevelFast() &&
				matComponent->GetComponentStatus() == EComponentStatus::GameThreadFinished &&
				!matComponent->Mat.empty())
			{
				numberMatComponents++;
			}
		}
		
		try
		{
			for (TPair<FString, UGame_TileComponent*> entry : TileComponents)
			{
				UGame_TileComponent_Mat* matComponent = Cast<UGame_TileComponent_Mat>(entry.Value);

				if (matComponent != nullptr &&
					matComponent->IsValidLowLevelFast() &&
					matComponent->GetComponentStatus() == EComponentStatus::GameThreadFinished &&
					!matComponent->Mat.empty())
				{
					// get alpha
					float alpha = matComponent->GetAlpha();

					if (matComponent->Mat.rows == MatSizeY && matComponent->Mat.cols == MatSizeX)
					{
						if (numberMatComponents > 1)
						{
							combinedMat += (alpha * matComponent->Mat);
						}
						else
						{
							combinedMat = matComponent->Mat;
						}
					}
					else
					{
						cv::Mat resizedMat;
						cv::resize(matComponent->Mat, resizedMat, cv::Size(MatSizeX, MatSizeY));
						
						if (numberMatComponents > 1)
						{
							combinedMat += (alpha * resizedMat);
						}
						else
						{
							combinedMat = resizedMat;
						}
					}
				}
			}

			cv::Mat combinedMatAlpha(MatSizeX, MatSizeY, CV_8UC4);
			cvtColor(combinedMat, combinedMatAlpha, CV_BGR2BGRA);
			
			combinedMat = combinedMatAlpha;
		}
		catch (cv::Exception& e)
		{
			const char* err_msg = e.what();
			UE_LOG(Game, Warning, TEXT("-- AGame_TerrainTile::CreateMaterial | combining material | opencv error: %s"), ANSI_TO_TCHAR(err_msg));
		}
		
		// capture pixel values
		int32 dataLength = combinedMat.rows * combinedMat.cols * combinedMat.elemSize();

		HighResTexturePixels.Empty();
		HighResTexturePixels.AddZeroed(dataLength);

		uint8* data = HighResTexturePixels.GetData();
		FMemory::Memcpy(HighResTexturePixels.GetData(), combinedMat.ptr(0), dataLength);
		
		// create texture on game thread
		AsyncTask(ENamedThreads::GameThread, [this]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}
			
			MaterialInstance = UMaterialInstanceDynamic::Create(MaterialTemplate, this);
			MaterialInstance->SetTextureParameterValue(FName("texture"), Texture);

			// bounds don't work in TOC because material function is for ECEF and TOC is ENU
			if (!UGame_Statics::IsLocalPlayerInTOC())
			{
				MaterialInstance->SetScalarParameterValue(TEXT("bHasBound"), 1);
				MaterialInstance->SetScalarParameterValue(TEXT("boundMinLongitude"), TileBounds.Key.Longitude);
				MaterialInstance->SetScalarParameterValue(TEXT("boundMinLatitude"), TileBounds.Value.Latitude);
				MaterialInstance->SetScalarParameterValue(TEXT("boundMaxLongitude"), TileBounds.Value.Longitude);
				MaterialInstance->SetScalarParameterValue(TEXT("boundMaxLatitude"), TileBounds.Key.Latitude);
			}

			ApplyCutToMaterial();

			for (UProceduralMeshComponent* proceduralMeshComponent : ProceduralMeshComponents)
			{
				proceduralMeshComponent->SetMaterial(0, MaterialInstance);
			}

			// start high res updates (see AGame_TerrainTile::Tick)
			HighResU = 0;
			HighResV = 0;
			HighResElapsed = 0;

			DestroyCounter.Decrement();
		});

		DestroyCounter.Decrement();
	});
}

void AGame_TerrainTile::CreateMesh()
{
	if (Triangles.Num() == 0)
	{
		for (UProceduralMeshComponent* proceduralMeshComponent : ProceduralMeshComponents)
		{
			proceduralMeshComponent->DestroyComponent();
		}
		ProceduralMeshComponents.Empty();

		bMeshDone = true;
		if (bMaterialDone)
		{
			SetTileStatus(ETileStatus::GameThreadFinished);
		}

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
		
		bool bStartOver = TriangleIndex == 0;

		TArray<int32> triangles;
		triangles.Append(Triangles);
		if (TriangleIndex > 0)
		{
			triangles.RemoveAt(0, TriangleIndex);
		}

		int32 toProcess = TrianglesPerComponent * 3;
		bool bTrianglesLeft = false;
		if (triangles.Num() > toProcess)
		{
			triangles.RemoveAt(toProcess, triangles.Num() - toProcess);

			TriangleIndex += toProcess;

			bTrianglesLeft = true;
		}
		else
		{
			TriangleIndex = triangles.Num();
		}

		// create vertices, triangles, uvs for only triangles and vertices referenced in triangles
		TArray<int32> processedTriangles;
		TArray<FVector> processedVertices;
		TArray<FVector2D> processedUVs;

		TMap<FVector, int32> vertToIndex;
		for (int32 i = 0; i < triangles.Num(); i++)
		{
			int32 triangleIndex = triangles[i];

			FVector vertex = Vertices[triangleIndex];
			if (int32* indexPtr = vertToIndex.Find(vertex))
			{
				processedTriangles.Add(*indexPtr);
			}
			else
			{
				int32 index = processedVertices.Add(vertex);

				processedUVs.Add(UVs[triangleIndex]);

				processedTriangles.Add(index);

				vertToIndex.Add(vertex, index);
			}

			// todo ohg | implement MaxVerticesPerComponent
		}

		AsyncTask(ENamedThreads::GameThread, [this, processedTriangles, processedVertices, processedUVs, bTrianglesLeft, bStartOver]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}

			if (bStartOver)
			{
				for (UProceduralMeshComponent* proceduralMeshComponent : ProceduralMeshComponents)
				{
					proceduralMeshComponent->DestroyComponent();
				}
				ProceduralMeshComponents.Empty();
			}

			UProceduralMeshComponent* proceduralMeshComponent = NewObject<UProceduralMeshComponent>(RootComponent, UProceduralMeshComponent::StaticClass());
			proceduralMeshComponent->OnComponentCreated();
			proceduralMeshComponent->SetRelativeLocation(FVector(0, 0, 0));
			proceduralMeshComponent->SetWorldLocation(FVector(0, 0, 0));
			proceduralMeshComponent->bUseAsyncCooking = true;

			ApplyCutToMesh(proceduralMeshComponent);

			proceduralMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

			if (proceduralMeshComponent->bAutoRegister)
			{
				// crash proceduralMeshComponent owner was bad
				proceduralMeshComponent->RegisterComponent();
			}

			// create mesh
			proceduralMeshComponent->CreateMeshSection(0, processedVertices, processedTriangles, TArray<FVector>(), processedUVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);

			proceduralMeshComponent->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;

			// set collision (object type, response to all channels, enabled)
			bool bPlayerCollision = !UGame_Statics::IsLocalPlayerInTOC();
			
			proceduralMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

			proceduralMeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
			proceduralMeshComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
			proceduralMeshComponent->SetCollisionResponseToChannel(UGame_GameInstance::GetTerrainCollisionChannel(), ECR_Block);

			if (bPlayerCollision)
			{
				proceduralMeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
			}

			proceduralMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

			if (MaterialInstance != nullptr)
			{
				proceduralMeshComponent->SetMaterial(0, MaterialInstance);
			}

			ProceduralMeshComponents.Add(proceduralMeshComponent);

			if (bTrianglesLeft)
			{
				GetWorld()->GetTimerManager().SetTimer(BuildMeshTimerHandle, this, &AGame_TerrainTile::CreateMesh, SecondsBetweenComponentCreate);
			}
			else
			{
				// check procedural mesh components are done building collision
				HandleWaitForCollisionTimer();
			}

			DestroyCounter.Decrement();
		});

		DestroyCounter.Decrement();
	});
}

void AGame_TerrainTile::HandleWaitForCollisionTimer()
{
	for (UProceduralMeshComponent* meshComponent : ProceduralMeshComponents)
	{
		if (meshComponent->GetNumCollisionsQueued() > 0)
		{
			GetWorld()->GetTimerManager().SetTimer(WaitForCollisionTimerHandle, this, &AGame_TerrainTile::HandleWaitForCollisionTimer, 1);
			return;
		}
	}

	bMeshDone = true;
	if (bMaterialDone)
	{
		SetTileStatus(ETileStatus::GameThreadFinished);
	}
}

ETaskStatus AGame_TerrainTile::GetTaskStatus_Implementation() const
{
	return TaskStatus;
}

bool AGame_TerrainTile::InitializeTask_Implementation()
{
	bMeshDone = false;
	bMaterialDone = false;

	TaskStatus = ETaskStatus::Initialized;

	return true;
}

void AGame_TerrainTile::StartTask_Implementation()
{
	TaskStatus = ETaskStatus::Started;
	
	TriangleIndex = 0;
	
	CreateMesh();
}

bool AGame_TerrainTile::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() ||
		HasAnyFlags(RF_BeginDestroyed) ||
		GetClass() == nullptr ||
		GetTileStatus() == ETileStatus::ReadyForDestroy ||
		IsRooted())
	{
		return false;
	}

	return true;
}

FString AGame_TerrainTile::GetTaskTrackerID() const
{
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds = GetTileBounds();

	FString boundsString = FString::Printf(TEXT("%s_%s"), *tileBounds.Key.ToString(), *tileBounds.Value.ToString());

	return FString::Printf(TEXT("Terrain_Tile_%s"), *boundsString);
}

FString AGame_TerrainTile::GetTaskTrackerDescription() const
{
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds = GetTileBounds();

	FString boundsString = FString::Printf(TEXT("NW: %s | SE: %s"), *tileBounds.Key.ToString(), *tileBounds.Value.ToString());

	return FString::Printf(TEXT("Terrain Tile | %s"), *boundsString);
}