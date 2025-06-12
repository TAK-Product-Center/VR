// Required Includes
#include "Game_PointCloudActor.h"
#include "Game.h"

// Engine Includes
#include "TimerManager.h"
#include "LidarPointCloud.h"
#include "IO/LidarPointCloudFileIO.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_Subsystem_TaskTracker.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_EntityDB.h"
#include "Game_ImportManager.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_PointCloudActor::AGame_PointCloudActor() :
	PointCloudScale(1)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_PointCloudActor::BeginPlay()
{
	Super::BeginPlay();

	
}

void AGame_PointCloudActor::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	if (!FullPathToFile.IsEmpty())
	{
		if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
		{
			taskTracker->RemoveActiveTask(FullPathToFile);
		}
	}

	Super::EndPlay(endPlayReason);
}

void AGame_PointCloudActor::SetActorScale3D(FVector newScale3D)
{
	// purposefully not calling super; point cloud scale updated in AGame_PointCloudActor::UpdatePointCloudScale()
	//Super::SetActorScale3D(newScale3D);

	if (PointCloudScale != newScale3D.X)
	{
		ActorScale = newScale3D.X;

		UpdatePointCloudScale();
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_PointCloudActor::SetFile(const FString& fullPathToFile)
{
	if (!fullPathToFile.Equals(FullPathToFile))
	{
		if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
		{
			FullPathToFile = fullPathToFile;

			ActorScale = virtualObjective->GetActorScale().X;

			PointCloudScale = ActorScale;

			CreatePointCloud(ActorScale * 100);

			FTimerHandle timerHandle;
			GetWorldTimerManager().SetTimer(timerHandle, this, &AGame_PointCloudActor::UpdateBoundsInDB, 0.5, false);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- AGame_PointCloudActor::SetFile | Game_PointCloudActor has no virtual objective | aborting"));
		}
	}
}

void AGame_PointCloudActor::SetPointSize(float pointSize)
{
	if (ULidarPointCloudComponent* component = GetPointCloudComponent())
	{
		component->PointSize = pointSize;

		UpdateBlob();
	}
}

void AGame_PointCloudActor::SetColorSource(ELidarPointCloudColorationMode colorSource)
{
	if (ULidarPointCloudComponent* component = GetPointCloudComponent())
	{
		component->ColorSource = colorSource;

		UpdateBlob();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_PointCloudActor::UpdateBlob()
{
	ULidarPointCloudComponent* component = GetPointCloudComponent();

	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	if (component != nullptr && entityDB != nullptr)
	{
		FString entityUID = UGame_VirtualObjectiveManager::GetObjectEntityUID(this);

		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			FString fullPathToZipArchive = TEXT("");
			FMD5Hash md5Hash;
			UGame_ImportManager::GetZipReference(results[0], fullPathToZipArchive, md5Hash);

			FBufferArchive toBinary;
			toBinary << component->PointSize;
			toBinary << component->ColorSource;

			UGame_ImportManager::AddZipReferenceToData(toBinary, fullPathToZipArchive);

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			entityDB->SetData(entityUID, data);
		}
	}
}

void AGame_PointCloudActor::CreatePointCloud(float importScale)
{
	TSharedPtr<FLidarPointCloudImportSettings> importSettings = FLidarPointCloudImportSettings::MakeGeneric(FullPathToFile);
	importSettings->ImportScale = importScale;

	ULidarPointCloud* pointCloud = ULidarPointCloud::CreateFromFile(FullPathToFile, FLidarPointCloudAsyncParameters(true,
	[this, file = FullPathToFile](float progress)
	{
		if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
		{
			taskTracker->AddActiveTask(file, FPaths::GetCleanFilename(file), progress / 100);
		}
	},
	[this, file = FullPathToFile](bool bSuccess)
	{
		if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
		{
			taskTracker->RemoveActiveTask(file);
		}
	}), importSettings);
	
	SetPointCloud(pointCloud);
}

void AGame_PointCloudActor::UpdatePointCloudScale()
{
	if (ULidarPointCloud* pointCloud = GetPointCloud())
	{
		if (pointCloud->GetNumPoints() > 0)
		{
			CreatePointCloud(ActorScale * 100);

			PointCloudScale = ActorScale;
		}
		else
		{
			FTimerManager& timerManager = GetWorldTimerManager();

			timerManager.ClearTimer(UpdatePointCloudScaleTimerHandle);
			timerManager.SetTimer(UpdatePointCloudScaleTimerHandle, this, &AGame_PointCloudActor::UpdatePointCloudScale, 0.5, false);
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_PointCloudActor::QueueBuildCollision | ULidarPointCloud is nullptr"));
	}
}

void AGame_PointCloudActor::UpdateBoundsInDB()
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	ULidarPointCloud* pointCloud = GetPointCloud();

	bool bSetTimer = true;

	if (entityDB != nullptr && pointCloud != nullptr)
	{
		FString entityUID = UGame_VirtualObjectiveManager::GetObjectEntityUID(this);

		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			// if database has invalid bounds, update database bounds 
			TArray<double> northWestArray = UDatabase_Spatialite::GetPoint(TEXT("northWestBB"), results[0]);
			TArray<double> southEastArray = UDatabase_Spatialite::GetPoint(TEXT("southEastBB"), results[0]);

			if (FMath::IsNearlyEqual(northWestArray[0], southEastArray[0]) && FMath::IsNearlyEqual(northWestArray[1], southEastArray[1]))
			{
				if (pointCloud->GetNumPoints() > 0)
				{
					if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
					{
						if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
						{
							FBox bounds = pointCloud->GetBounds();

							FGeodeticCoord3D maxCoord = globeReference->WorldToGeodeticDouble(bounds.Max - pointCloud->LocationOffset);
							FGeodeticCoord3D minCoord = globeReference->WorldToGeodeticDouble(bounds.Min - pointCloud->LocationOffset);

							FGeodeticCoord2D northWest;
							northWest.Latitude = FMath::Max<double>(maxCoord.Latitude, minCoord.Latitude);
							northWest.Longitude = FMath::Min<double>(maxCoord.Longitude, minCoord.Longitude);

							FGeodeticCoord2D southEast;
							southEast.Latitude = FMath::Min<double>(maxCoord.Latitude, minCoord.Latitude);
							southEast.Longitude = FMath::Max<double>(maxCoord.Longitude, minCoord.Longitude);

							entityDB->UpdateBoundingBox(entityUID, northWest, southEast);

							bSetTimer = false;
						}
					}
				}
			}
			else
			{
				bSetTimer = false;
		    }
		}
	}
	
	if (bSetTimer)
	{
		FTimerHandle timerHandle;
		GetWorldTimerManager().SetTimer(timerHandle, this, &AGame_PointCloudActor::UpdateBoundsInDB, 0.5, false);
	}
}
