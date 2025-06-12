// Required Includes
#include "Game_Actor_Viewshed.h"
#include "Game.h"

// Engine Includes
#include "LidarPointCloud.h"
#include "IO/LidarPointCloudFileIO.h"
#include "LidarPointCloudComponent.h"
#include "Misc/Guid.h"
#include "Kismet/GameplayStatics.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

// VH Plugin Includes
#include "VH_GlobeCoordConverter.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_Subsystem_TaskTracker.h"

// Game Includes
#include "Game_PlayerController.h"
#include "Game_TileManager.h"
#include "Game_EntityDB.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Statics.h"
#include "Game_EntityHandler_Viewshed.h"
#include "Game_GameInstance.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Actor_Viewshed::AGame_Actor_Viewshed(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(Root);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool AGame_Actor_Viewshed::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Actor_Viewshed::CreateViewshedPointCloud(const FString& entityUID, const FGeodeticCoord3D& coordinate, int32 gridX, int32 gridY, double radiusMeters, int32 pointsPerBeam, double pointSize, bool bTraceGroundArg)
{
	if (UGame_Statics::IsLocalPlayerInTOC())
	{
		return;
	}

	if (entityUID.IsEmpty())
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_Actor_Viewshed::CreateViewshedPointCloud | entityUID is empty | aborting"));

		return;
	}

	UpdateTaskTracker(0);

	AVH_GlobeReferenceActor* globeReference = nullptr;
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		globeReference = virtualObjective->GetGlobeReference();
	}

	if (!IsValid(globeReference))
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_Actor_Viewshed::CreateViewshedPointCloud | globeReference is not valid | aborting"));
		
		return;
	}

	EntityUID = entityUID;

	Coordinate = coordinate;
	GridX = gridX;
	GridY = gridY;
	RadiusMeters = radiusMeters;
	PointsPerBeam = pointsPerBeam;
	PointSize = pointSize;
	bTraceGround = bTraceGroundArg;

	InsertOrUpdateDatabase();

	FVector viewshedCenter = globeReference->GeodeticToWorldDouble(coordinate);

	SetActorLocation(viewshedCenter);

	PeriodicAttemptToLoad();
}

void AGame_Actor_Viewshed::SetPointSize(float pointSize)
{
	if (ULidarPointCloudComponent* component = GetPointCloudComponent())
	{
		PointSize = pointSize;

		component->PointSize = PointSize;

		InsertOrUpdateDatabase();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_Actor_Viewshed::UpdateTaskTracker(double progress)
{
	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		if (progress != 1)
		{
			taskTracker->AddActiveTask(TEXT("viewshed"), TEXT("viewshed"), progress);
		}
		else
		{
			taskTracker->RemoveActiveTask(TEXT("viewshed"));
		}
	}
}

void AGame_Actor_Viewshed::InsertOrUpdateDatabase()
{
	if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this, true))
	{
		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			FBufferArchive toBinary;

			toBinary << Coordinate;

			toBinary << GridX;

			toBinary << GridY;

			toBinary << RadiusMeters;

			toBinary << PointsPerBeam;

			toBinary << PointSize;

			toBinary << bTraceGround;

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			FGeodeticCoord2D coordinate2D = Coordinate.ToGeodeticCoord2D();

			/*FBox2D bounds;
			bounds += UVH_GlobeMathStatics::CalculateSurfaceDestination(coordinate2D, 0, RadiusMeters).ToVector();
			bounds += UVH_GlobeMathStatics::CalculateSurfaceDestination(coordinate2D, 90, RadiusMeters).ToVector();
			bounds += UVH_GlobeMathStatics::CalculateSurfaceDestination(coordinate2D, 180, RadiusMeters).ToVector();
			bounds += UVH_GlobeMathStatics::CalculateSurfaceDestination(coordinate2D, 270, RadiusMeters).ToVector();*/

			entityDB->InsertOrUpdate(EntityUID, UGame_EntityHandler_Viewshed::StaticGetClassUID(), TEXT("viewshed"), coordinate2D, coordinate2D, data, true, true);

			//UpdateBoundsInDB();
		}
	}
}

bool AGame_Actor_Viewshed::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Actor_Viewshed::PeriodicAttemptToLoad()
{
	bool bWait = true;
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		if (tileManager->IsEnabled())
		{
			if (!tileManager->PendingTiles())
			{
				bWait = false;
			}
		}
	}

	if (bWait)
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_Actor_Viewshed::PeriodicAttemptToLoad, 0.5, false);
		
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

		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			UpdateTaskTracker(0.10);

			FVector viewshedCenter = GetActorLocation();

			TSet<FVector> averageGridVertices;
			if (tileManager->GetTerrainGrid(GridX, GridY, RadiusMeters, viewshedCenter, averageGridVertices))
			{
				UpdateTaskTracker(0.25);

				// trace from viewshedCenter to averageGridVertex 
				if (IsValid(UDeveloper_Statics::GetVHWorld()))
				{
					TArray<FVector> greenStarts;
					TArray<FVector> greenEnds;
					TArray<FVector> redStarts;
					TArray<FVector> redEnds;

					PointsToAdd.Empty();

					FCollisionQueryParams queryParams;
					queryParams.AddIgnoredActor(UGame_Statics::GetVHPlayerController()->GetPawn());

					{
						FCriticalSection addCriticalSection;
						FCriticalSection waitCriticalSection;
						waitCriticalSection.Lock();

						int32 total = averageGridVertices.Num();
						ParallelFor(total, [this, &waitCriticalSection, &addCriticalSection, total, viewshedCenter, averageGridVertices = averageGridVertices.Array(), queryParams, &greenStarts, &greenEnds, &redStarts, &redEnds](int32 i)
						{
							TArray<FHitResult> hitResults;
							GetWorld()->LineTraceMultiByChannel(hitResults, viewshedCenter, averageGridVertices[i], ECollisionChannel::ECC_Visibility, queryParams);

							FVector impactPoint = averageGridVertices[i];
							for (const FHitResult& hitResult : hitResults)
							{
								if (hitResult.GetActor() == nullptr || !hitResult.GetActor()->ActorHasTag(TEXT("ignoreLOS")))
								{
									impactPoint = hitResult.Location;

									break;
								}
							}

							{
								FScopeLock scopeLock(&addCriticalSection);

								greenStarts.Add(viewshedCenter);
								greenEnds.Add(impactPoint);

								if (!viewshedCenter.Equals(impactPoint, 5))
								{
									redStarts.Add(impactPoint);
									redEnds.Add(averageGridVertices[i]);
								}

								if (greenStarts.Num() == total)
								{
									waitCriticalSection.Unlock();
								}
							}
						});

						{
							FScopeLock scopeLock(&waitCriticalSection);
						}
					}
					
					UpdateTaskTracker(0.5);

					TArray<FVector> greenLocations;
					for (int32 i = 0; i < greenStarts.Num(); i++)
					{
						FVector beam = greenEnds[i] - greenStarts[i];
						for (int32 j = 0; j < PointsPerBeam; j++)
						{
							double lerpAmount = (double)j / PointsPerBeam;
							lerpAmount += FMath::RandRange(-0.01, 0.01);

							FVector worldLocation = FMath::Lerp<FVector>(greenStarts[i], greenEnds[i], lerpAmount);

							FLidarPointCloudPoint point;
							point.Color = FColor(0, 255, 0, 255);

							point.Location.X = worldLocation.X;
							point.Location.Y = worldLocation.Y;
							point.Location.Z = worldLocation.Z;

							PointsToAdd.Add(point);
						}
					}
					
					UpdateTaskTracker(0.6);

					{
						FCriticalSection addCriticalSection;
						FCriticalSection waitCriticalSection;
						waitCriticalSection.Lock();

						TArray<FVector> redLocations;
						int32 totalLocations = redStarts.Num() * PointsPerBeam;
						
						ParallelFor(redStarts.Num(), [this, &waitCriticalSection, &addCriticalSection, queryParams, totalLocations, redEnds, redStarts](int32 i)
						{
							ParallelFor(PointsPerBeam, [this, &waitCriticalSection, &addCriticalSection, queryParams, i, totalLocations, redEnds, redStarts](int32 j)
							{
								double lerpAmount = (double)j / PointsPerBeam;
								lerpAmount += FMath::RandRange(-0.01, 0.01);

								FVector worldLocation = FMath::Lerp<FVector>(redStarts[i], redEnds[i], lerpAmount);

								if (bTraceGround)
								{
									FTransform surfaceTransform = UGame_Statics::GetWorldTransformOverride(worldLocation);
									surfaceTransform.SetLocation(worldLocation);
							
									FVector startLocation = surfaceTransform.TransformPosition(FVector(0, 0, 10000000));
									FVector endLocation = surfaceTransform.TransformPosition(FVector(0, 0, -10000000));

									FHitResult hit;
									if (GetWorld()->LineTraceSingleByChannel(hit, startLocation, endLocation, UGame_GameInstance::GetTerrainCollisionChannel(), queryParams))
									{
										worldLocation.Z = hit.Location.Z;
									}
									else
									{
										worldLocation.Z = endLocation.Z;
									}
								}

								FLidarPointCloudPoint point;
								point.Color = FColor(255, 0, 0, 255);

								point.Location.X = worldLocation.X;
								point.Location.Y = worldLocation.Y;
								point.Location.Z = worldLocation.Z;

								{
									FScopeLock scopeLock(&addCriticalSection);

									PointsToAdd.Add(point);

									if (PointsToAdd.Num() == totalLocations)
									{
										waitCriticalSection.Unlock();
									}
								}
							
							});
						});

						{
							FScopeLock scopeLock(&waitCriticalSection);
						}

						UpdateTaskTracker(0.8);
					}
					
					if (ULidarPointCloudComponent* component = GetPointCloudComponent())
					{
						component->PointSize = PointSize;
					}

					AsyncTask(ENamedThreads::GameThread, [this]()
					{
						FLidarPointCloudAsyncParameters params(true, nullptr, [this](bool bSuccess)
						{
							UpdateTaskTracker(1);
						});

						if (ULidarPointCloud* pointCloud = ULidarPointCloud::CreateFromData(PointsToAdd, params))
						{
							SetPointCloud(pointCloud);
						}

						DestroyCounter.Decrement();
					});
				}
			}
		}
	});
}