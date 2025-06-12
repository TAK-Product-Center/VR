// Required Includes
#include "Game_Actor_KmlPlacemark.h"
#include "Game.h"

// Engine Includes
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_ImageLoader.h"
#include "VH_MeshInfo.h"
#include "VH_KmlInfo.h"
#include "VH_KmlTypes.h"
#include "VH_KmlPlacemark.h"
#include "VH_KmlObject.h"
#include "VH_KmlGeometry.h"
#include "VH_KmlMultiGeometry.h"
#include "VH_KmlModel.h"
#include "VH_KmlLineString.h"
#include "VH_KmlLinearRing.h"
#include "VH_KmlCoordinates.h"
#include "VH_KmlPolygon.h"
#include "VH_KmlPoint.h"
#include "VH_KmlStyle.h"
#include "VH_KmlLineStyle.h"
#include "VH_KmlPolyStyle.h"
#include "VH_KmlIconStyle.h"
#include "VH_KmlLabelStyle.h"
#include "VH_KmlIconStyleIcon.h"
#include "VH_KmlColorStyle.h"

// Game Includes
#include "Game_ImportedMeshComponent.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Statics.h"
#include "Game_TileManager.h"
#include "Game_Pawn.h"
#include "Game_Actor_KmlPoint.h"
#include "Game_Actor_Mesh.h"
#include "Game_SimpleSegmentedLineActor.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Actor_KmlPlacemark::AGame_Actor_KmlPlacemark(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	MeshActorClass(AGame_Actor_Mesh::StaticClass())
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Actor_KmlPlacemark::BeginPlay()
{
	Super::BeginPlay();

	BindToTileManager();
	
	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, this, &AGame_Actor_KmlPlacemark::PeriodicCheckLOD, 1, true);
}

void AGame_Actor_KmlPlacemark::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	DestroySpawnedActors();

	if (IsValid(LowLODActor))
	{
		LowLODActor->Destroy();
		LowLODActor = nullptr;
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Actor_KmlPlacemark::PopulateFromKml(AGame_VirtualObjective* virtualObjective, UVH_KmlInfo* kmlInfo, FKmlPlacemark* kmlPlacemark)
{
	KmlInfo = kmlInfo;
	KmlPlacemark = kmlPlacemark;

	if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
	{
		FGeodeticCoord3D coordinate;
		if (kmlInfo->GetCenterCoordinate(coordinate))
		{
			SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- AGame_Actor_KmlPlacemark::PopulateFromKml | unable to find center coordinate"));
		}
	}

	// geometry loaded in LoadKmlPlacemarkNonLOD/LoadKmlPlacemarkLOD
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AVH_GlobeReferenceActor* AGame_Actor_KmlPlacemark::GetGlobeReference()
{
	if (GlobeReference == nullptr)
	{
		GlobeReference = UGame_VirtualObjectiveManager::GetObjectGlobeReference(this);
	}

	if (GlobeReference == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_Actor_KmlPlacemark::GetGlobeReference | globeRef is nullptr | %s"), *GetName());
	}

	return GlobeReference;
}

void AGame_Actor_KmlPlacemark::DestroySpawnedActors()
{
	SpawnedActorsGC.Empty();

	for (const TPair<EKmlElementType, TSet<AActor*>>& entry : SpawnedActors)
	{
		for (AActor* actor : entry.Value)
		{
			actor->Destroy();
		}
	}

	SpawnedActors.Empty();
}

void AGame_Actor_KmlPlacemark::LoadKmlPlacemarkNonLOD(FKmlPlacemark* kmlPlacemark)
{
	bContainsLODGeometry = false;

	if (kmlPlacemark != nullptr)
	{
		if (FKmlGeometry* kmlGeometry = kmlPlacemark->Geometry)
		{
			if (kmlGeometry->GetType() == EKmlElementType::MultiGeometry)
			{
				if (FKmlMultiGeometry* multiGeometry = (FKmlMultiGeometry*)kmlGeometry)
				{
					for (const TPair<EKmlElementType, TArray<FKmlGeometry*>>& entry : multiGeometry->GeometryListMap)
					{
						for (FKmlGeometry* geometry : entry.Value)
						{
							if (geometry->GetType() != EKmlElementType::Model)
							{
								LoadKmlGeometry(geometry);
							}
							else
							{
								bContainsLODGeometry = true;
							}
						}
					}
				}
			}
			else
			{
				if (kmlGeometry->GetType() != EKmlElementType::Model)
				{
					LoadKmlGeometry(kmlGeometry);
				}
				else
				{
					bContainsLODGeometry = true;
				}
			}
		}
	}
}

void AGame_Actor_KmlPlacemark::LoadKmlPlacemarkLOD(FKmlPlacemark* kmlPlacemark)
{
	if (kmlPlacemark != nullptr)
	{
		if (FKmlGeometry* kmlGeometry = kmlPlacemark->Geometry)
		{
			if (kmlGeometry->GetType() == EKmlElementType::MultiGeometry)
			{
				if (FKmlMultiGeometry* multiGeometry = (FKmlMultiGeometry*)kmlGeometry)
				{
					for (const TPair<EKmlElementType, TArray<FKmlGeometry*>>& entry : multiGeometry->GeometryListMap)
					{
						for (FKmlGeometry* geometry : entry.Value)
						{
							if (geometry->GetType() == EKmlElementType::Model)
							{
								LoadKmlGeometry(geometry);
							}
						}
					}
				}
			}
			else 
			{
				if (kmlGeometry->GetType() == EKmlElementType::Model)
				{
					LoadKmlGeometry(kmlGeometry);
				}
			}
		}
	}
}

void AGame_Actor_KmlPlacemark::LoadKmlGeometry(FKmlGeometry* kmlGeometry)
{
	if (kmlGeometry != nullptr)
	{
		switch (kmlGeometry->GetType())
		{
			case EKmlElementType::Model:
			{
				LoadKmlModel((FKmlModel*)kmlGeometry);
			}
			break;

			case EKmlElementType::LineString:
			case EKmlElementType::LinearRing:
			{
				LoadKmlLineString(kmlGeometry);
			}
			break;

			case EKmlElementType::Polygon:
			{
				LoadKmlPolygon((FKmlPolygon*)kmlGeometry);
			}
			break;

			case EKmlElementType::Point:
			{
				LoadKmlPoint((FKmlPoint*)kmlGeometry);
			}
			break;
		}
	}
}

void AGame_Actor_KmlPlacemark::LoadKmlModel(FKmlModel* kmlModel)
{
	if (kmlModel != nullptr)
	{
		// location, rotation, scale
		if (AVH_GlobeReferenceActor* globeReference = GetGlobeReference())
		{
			FGeodeticCoord3D coordinate;
			if (kmlModel->bHasLocationTag)
			{
				coordinate = kmlModel->Location;

				coordinate.bIsAltitudeRelativeToGround = kmlModel->AltitudeMode != EKmlAltitudeMode::Absolute;
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- AGame_Actor_KmlPlacemark::LoadGeometry | model does not have location tag | aborting"));

				return;
			}

			FVector worldLocation = globeReference->GeodeticToWorldDouble(coordinate);
			
			SetActorLocation(worldLocation);
			SetActorRotation(UGame_Statics::GetWorldTransformOverride(worldLocation).TransformRotation(kmlModel->Rotation.Quaternion()).Rotator());
		}

		AGame_Actor_Mesh* meshActor = AddMeshActor(EKmlElementType::Model);
		
		if (kmlModel->bHasScaleTag)
		{
			meshActor->ImportedMesh->SetRelativeScale3D(meshActor->ImportedMesh->GetRelativeScale3D() * kmlModel->Scale);
		}
		
		meshActor->ImportedMesh->MaterialTemplate = ModelMaterial;

		meshActor->ImportedMesh->TextureResourceMap.Empty();
		meshActor->ImportedMesh->TextureResourceMap.Append(kmlModel->ResourceMap);

		FString fullPathToFile = FPaths::Combine(FPaths::GetPath(KmlInfo->FullPathToFile), kmlModel->Link);

		FVH_MeshImportOptions importOptions;
		importOptions = UVH_MeshInfo::GetDefaultImportOptions(fullPathToFile);

		meshActor->ImportedMesh->ImportOptions = importOptions;

		// NOTE: Do this last! This triggers building the mesh, if necessary.
		meshActor->ImportedMesh->LoadFromFile(fullPathToFile);
	}
}

void AGame_Actor_KmlPlacemark::LoadKmlLineString(FKmlGeometry* kmlGeometry)
{
	TArray<FGeodeticCoord3D> coordinates;
	bool bExtruded = false;

	if (FKmlLineString* kmlLineString = (FKmlLineString*)kmlGeometry)
	{
		coordinates = kmlLineString->Coordinates->CoordinateList;
		bExtruded = kmlLineString->IsExtruded;
	}
	else if (FKmlLinearRing* kmlLinearRing = (FKmlLinearRing*)kmlGeometry)
	{
		coordinates = kmlLinearRing->Coordinates->CoordinateList;
		bExtruded = kmlLinearRing->IsExtruded;
	}
	else
	{
		return;
	}

	bool bRelativeToGround = kmlGeometry->AltitudeMode != EKmlAltitudeMode::Absolute;

	// location, rotation
	if (AVH_GlobeReferenceActor* globeReference = GetGlobeReference())
	{
		FBox worldExtents;
		for (FGeodeticCoord3D& coordinate : coordinates)
		{
			coordinate.bIsAltitudeRelativeToGround = bRelativeToGround;

			worldExtents += globeReference->GeodeticToWorldDouble(coordinate);
		}

		SetActorLocation(worldExtents.GetCenter());
		SetActorRotation(UGame_Statics::GetWorldTransformOverride(GetActorLocation()).TransformRotation(FRotator::ZeroRotator.Quaternion()).Rotator());
	}

	// line style
	FKmlLineStyle* lineStyle = nullptr;
	if (const FKmlStyle* style = KmlPlacemark->GetStyle())
	{
		lineStyle = style->LineStyle;
	}

	CreateLine(coordinates, lineStyle, bExtruded, nullptr);
}

void AGame_Actor_KmlPlacemark::LoadKmlPolygon(FKmlPolygon* kmlPolygon)
{
	if (kmlPolygon != nullptr)
	{
		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();
		if (globeReference == nullptr)
		{
			return;
		}

		if (const FKmlStyle* kmlStyle = KmlPlacemark->GetStyle())
		{
			if (FKmlLinearRing* kmlLinearRing = kmlPolygon->OuterBoundary)
			{
				TArray<FGeodeticCoord3D> coordinates = kmlLinearRing->Coordinates->CoordinateList;

				bool bRelativeToGround = kmlPolygon->AltitudeMode != EKmlAltitudeMode::Absolute;

				// location, rotation
				FBox worldExtents;
				for (FGeodeticCoord3D& coordinate : coordinates)
				{
					coordinate.bIsAltitudeRelativeToGround = bRelativeToGround;

					worldExtents += globeReference->GeodeticToWorldDouble(coordinate);
				}

				SetActorLocation(worldExtents.GetCenter());
				SetActorRotation(UGame_Statics::GetWorldTransformOverride(GetActorLocation()).TransformRotation(FRotator::ZeroRotator.Quaternion()).Rotator());

				// outline
				if (kmlStyle->PolyStyle != nullptr)
				{
					if (kmlStyle->PolyStyle->IsOutline)
					{
						CreateLine(coordinates, kmlStyle->LineStyle, kmlLinearRing->IsExtruded || kmlPolygon->IsExtruded, kmlStyle->PolyStyle);
					}

					// polygon
					if (kmlStyle->PolyStyle->IsFill)
					{
						// todo ohg | handle polygon->InnerBoundaryList

						TArray<FVector> vertices;
						TArray<FVector2D> polygon2D;
						for (const FGeodeticCoord3D& coordinate : coordinates)
						{
							vertices.Add(globeReference->GeodeticToWorldDouble(coordinate));

							polygon2D.Add(FVector2D(coordinate.Longitude, coordinate.Latitude));
						}

						TArray<int32> triangles;
						bool bWindsClockwise = false;
						if (UDeveloper_Statics::TriangulatePolygon(polygon2D, triangles, bWindsClockwise))
						{
							AGame_Actor_Mesh* meshActor = AddMeshActor(EKmlElementType::Polygon);
							meshActor->ImportedMesh->SetWorldTransform(FTransform::Identity);

							meshActor->ImportedMesh->BuildMeshFromVerticesAndTriangles(vertices, triangles);

							UMaterialInstanceDynamic* materialInstance = UMaterialInstanceDynamic::Create(PolygonMaterial, this);

							materialInstance->SetVectorParameterValue(TEXT("Color"), kmlStyle->PolyStyle->Color);

							meshActor->ImportedMesh->MaterialOverride = materialInstance;
						}
					}
				}
			}
		}
	}
}

void AGame_Actor_KmlPlacemark::LoadKmlPoint(FKmlPoint* kmlPoint)
{
	if (kmlPoint != nullptr)
	{
		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();
		if (globeReference == nullptr)
		{
			return;
		}

		if (kmlPoint->Coordinates != nullptr && kmlPoint->Coordinates->CoordinateList.Num() > 0)
		{
			// location, rotation
			FGeodeticCoord3D coordinate = kmlPoint->Coordinates->CoordinateList[0];

			coordinate.bIsAltitudeRelativeToGround = kmlPoint->AltitudeMode != EKmlAltitudeMode::Absolute;

			SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));
			SetActorRotation(UGame_Statics::GetWorldTransformOverride(GetActorLocation()).TransformRotation(FRotator::ZeroRotator.Quaternion()).Rotator());

			const FKmlStyle* style = KmlPlacemark->GetStyle();

			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			if (AGame_Actor_KmlPoint* pointActor = GetWorld()->SpawnActor<AGame_Actor_KmlPoint>(PointActorClass, GetActorTransform(), spawnParams))
			{
				FKmlLabelStyle* labelStyle = style != nullptr ? style->LabelStyle : nullptr;
				FLinearColor labelColor = labelStyle != nullptr ? labelStyle->Color : FLinearColor::White;

				pointActor->ReceiveSetText(labelColor, KmlPlacemark->Name);

				// default to blue blank
				FString iconHRef = TEXT("http://maps.google.com/mapfiles/kml/pushpin/blu-blank.png");

				FKmlIconStyle* iconStyle = style != nullptr ? style->IconStyle : nullptr;
				if (iconStyle != nullptr)
				{
					pointActor->ReceiveSetColor(iconStyle->Color);

					iconHRef = iconStyle->Icon->HRef;
				}

				UTexture2D* iconTexture = nullptr;

				if (iconHRef.StartsWith(TEXT("http")))
				{
					if (iconHRef.StartsWith(TEXT("http://maps.google.com")))
					{
						FString dbPath = FPaths::Combine(FPaths::RootDir(), TEXT("Data"), TEXT("User_Icons"), TEXT("iconsets.sqlite"));
						FString blobColumn = TEXT("bitmap");
						FString iconsetUID = TEXT("f7f71666-8b28-4b57-9fbb-e38e61d33b79");
						FString groupName = TEXT("Google");
						FString filename = FPaths::GetCleanFilename(iconHRef);
						FString query = FString::Printf(TEXT("select %s from icons where iconset_uid =\"%s\" and groupName = \"%s\" and filename = \"%s\""), *blobColumn, *iconsetUID, *groupName, *filename);

						TArray<uint8> pixelData;
						if (UVH_ImageLoader::LoadImageFromDB(dbPath, query, blobColumn, pixelData))
						{
							iconTexture = UDeveloper_Statics::CreateTextureWithWrapper(EImageFormat::PNG, pixelData);
						}
					}
				}
				else
				{
					FString iconFile = FPaths::Combine(FPaths::GetPath(KmlInfo->FullPathToFile), iconHRef);

					FVector2D scaledDimensions;
					FVector2D originalDimensions;
					TArray<uint8> pixelData;
					if (UVH_ImageLoader::LoadImageFromDisk(iconFile, scaledDimensions, originalDimensions, pixelData))
					{
						iconTexture = UDeveloper_Statics::CreateTextureFromPixels(scaledDimensions.X, scaledDimensions.Y, pixelData);
					}
				}

				if (iconTexture != nullptr)
				{
					pointActor->ReceiveSetTexture(iconTexture);
				}

				if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
				{
					pointActor->SetActorScale3D(virtualObjective->GetActorScale3D());
				}

				AddActorToSpawnedActors(EKmlElementType::Point, pointActor);
			}

			if (kmlPoint->IsExtruded)
			{
				FGeodeticCoord3D groundCoordinate = coordinate;
				groundCoordinate.Altitude = 0;
				groundCoordinate.bIsAltitudeRelativeToGround = true;

				TArray<FGeodeticCoord3D> coordinates;
				coordinates.Add(coordinate);
				coordinates.Add(groundCoordinate);

				CreateLine(coordinates, style != nullptr ? style->LineStyle : nullptr, false, nullptr);
			}
		}
	}
}

void AGame_Actor_KmlPlacemark::CreateLine(const TArray<FGeodeticCoord3D>& coordinates, const FKmlLineStyle* kmlLineStyle, bool bExtrude, const FKmlColorStyle* kmlLineStyleExtrude)
{
	if (coordinates.Num() <= 1)
	{
		return;
	}

	AVH_GlobeReferenceActor* globeReference = GetGlobeReference();
	if (globeReference == nullptr)
	{
		return;
	}

	FLinearColor lineColor = kmlLineStyle != nullptr ? kmlLineStyle->Color : FLinearColor::White;
	double lineWidth = kmlLineStyle != nullptr ? kmlLineStyle->Width : 1.0;

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (AGame_SimpleSegmentedLineActor* lineActor = GetWorld()->SpawnActor<AGame_SimpleSegmentedLineActor>(LineActorClass, GetActorTransform(), spawnParams))
	{
		lineActor->DefaultWidth = lineWidth;
		lineActor->SetColor(lineColor.ToFColor(true));

		for (const FGeodeticCoord3D& coordinate : coordinates)
		{
			lineActor->AddLocationAndGeoLocation(globeReference->GeodeticToWorldDouble(coordinate), coordinate);
		}

		AddActorToSpawnedActors(EKmlElementType::LineString, lineActor);
	}

	if (bExtrude)
	{
		// draw line with same coordinates except at ground level
		TArray<FGeodeticCoord3D> coordinatesGroundLevel;
		for (const FGeodeticCoord3D& coordinate : coordinates)
		{
			FGeodeticCoord3D groundCoordinate = coordinate;
			groundCoordinate.Altitude = 0;
			groundCoordinate.bIsAltitudeRelativeToGround = true;

			if (globeReference->GeodeticToWorldDouble(coordinate).Equals(globeReference->GeodeticToWorldDouble(groundCoordinate), 0.001))
			{
				// already on the ground, cannot extrude downward
				return;
			}

			coordinatesGroundLevel.Add(groundCoordinate);
		}

		CreateLine(coordinatesGroundLevel, kmlLineStyle, false, nullptr);

		// draw mesh between lines
		TArray<FVector> lowerVertices;
		for (const FGeodeticCoord3D& coordinateGroundLevel : coordinatesGroundLevel)
		{
			lowerVertices.Add(globeReference->GeodeticToWorldDouble(coordinateGroundLevel));
		}

		TArray<FVector> upperVertices;
		for (const FGeodeticCoord3D& coordinate : coordinates)
		{
			upperVertices.Add(globeReference->GeodeticToWorldDouble(coordinate));
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

		AGame_Actor_Mesh* meshActor = AddMeshActor(EKmlElementType::LineString);
		meshActor->ImportedMesh->SetWorldTransform(FTransform::Identity);

		meshActor->ImportedMesh->BuildMeshFromVerticesAndTriangles(vertices, triangles);

		UMaterialInstanceDynamic* materialInstance = UMaterialInstanceDynamic::Create(PolygonMaterial, this);

		FLinearColor extrudeColor = kmlLineStyleExtrude != nullptr ? kmlLineStyleExtrude->Color : FLinearColor(0.25, 0.25, 0.25, 0.75);
		materialInstance->SetVectorParameterValue(TEXT("Color"), extrudeColor);

		meshActor->ImportedMesh->MaterialOverride = materialInstance;
	}
}

AGame_Actor_Mesh* AGame_Actor_KmlPlacemark::AddMeshActor(EKmlElementType kmlElementType)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AGame_Actor_Mesh* meshActor = GetWorld()->SpawnActor<AGame_Actor_Mesh>(MeshActorClass, GetActorTransform(), spawnParams);

	AddActorToSpawnedActors(kmlElementType, meshActor);

	if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
	{
		meshActor->SetActorScale3D(virtualObjective->GetActorScale3D());
	}

	return meshActor;
}

void AGame_Actor_KmlPlacemark::AddActorToSpawnedActors(EKmlElementType kmlElementType, AActor* actor)
{
	SpawnedActorsGC.Add(actor);

	if (TSet<AActor*>* actorSet = SpawnedActors.Find(kmlElementType))
	{
		actorSet->Add(actor);
	}
	else
	{
		TSet<AActor*> newActorSet;
		newActorSet.Add(actor);

		SpawnedActors.Add(kmlElementType, newActorSet);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Actor_KmlPlacemark::BindToTileManager()
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->OnTerrainUpdate.AddDynamic(this, &AGame_Actor_KmlPlacemark::HandleTerrainUpdate);
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_Actor_KmlPlacemark::BindToTileManager, 0.5);
	}
}

void AGame_Actor_KmlPlacemark::PeriodicCheckLOD()
{
	if (KmlPlacemark != nullptr)
	{
		// 0 don't load; 1 load low LOD; 2 load normal LOD
		int32 loadType = 0;

		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			if (tileManager->IsEnabled())
			{
				if (!tileManager->PendingTiles())
				{
					if (LowLODActorClass != nullptr && !UGame_Statics::IsLocalPlayerInTOC())
					{
						if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
						{
							if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
							{
								double distanceMeters = FVector::Distance(playerPawn->GetActorLocation(), GetActorLocation()) / virtualObjective->GetUnrealUnitsPerMeter();

								loadType = distanceMeters > virtualObjective->GetViewDistance() ? 1 : 2;
							}
						}
					}
					else
					{
						loadType = 2;
					}
				}
			}
		}
		
		if (loadType == 1)
		{
			// load low LOD
			if (!IsValid(LowLODActor))
			{
				// destroy LOD'd geometry
				if (TSet<AActor*>* actors = SpawnedActors.Find(EKmlElementType::Model))
				{
					for (AActor* actor : *actors)
					{
						SpawnedActorsGC.Remove(actor);

						if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
						{
							virtualObjective->RemoveObjectFromEntity(UGame_VirtualObjectiveManager::GetObjectEntityUID(this), actor);
						}

						actor->Destroy();
					}
				}
				SpawnedActors.Remove(EKmlElementType::Model);

				if (!bLoadedOnce)
				{
					LoadKmlPlacemarkNonLOD(KmlPlacemark);
				}

				// spawn low LOD actor (hide if no LOD'd geometry)
				FActorSpawnParameters spawnParameters;
				spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				FTransform transform;
				transform.SetLocation(GetActorLocation());

				LowLODActor = GetWorld()->SpawnActor(LowLODActorClass, &transform, spawnParameters);
				LowLODActor->SetActorHiddenInGame(!bContainsLODGeometry);

				bLoadedOnce = true;
			}
		}
		else if (loadType == 2)
		{
			// load normal LOD
			bool bValidLowLODActor = IsValid(LowLODActor);
			if (bValidLowLODActor || !bLoadedOnce)
			{
				if (bValidLowLODActor)
				{
					LowLODActor->Destroy();
					LowLODActor = nullptr;
				}

				if (!bLoadedOnce)
				{
					LoadKmlPlacemarkNonLOD(KmlPlacemark);
				}

				LoadKmlPlacemarkLOD(KmlPlacemark);
				
				bLoadedOnce = true;
			}
		}
	}
}

void AGame_Actor_KmlPlacemark::HandleTerrainUpdate()
{
	DestroySpawnedActors();

	if (IsValid(LowLODActor))
	{
		LowLODActor->Destroy();
		LowLODActor = nullptr;
	}

	bLoadedOnce = false;
}