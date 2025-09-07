// Required Includes
#include "Game_SimpleSegmentedLineActor.h"
#include "Game.h"

// Engine Includes
#include "ProceduralMeshComponent.h"
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "UI_Subsystem_ContextMenu.h"
#include "Developer_Statics.h"
#include "UI_Subsystem_Core.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_DrawContainer.h"
#include "Game_TerrainTile.h"
#include "Game_Subsystem_Core.h"
#include "Game_CameraScalingComponent.h"
#include "Game_GameInstance.h"
#include "Game_Statics.h"
#include "Game_UserWidget_MapScrape.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_SimpleSegmentedLineActor::AGame_SimpleSegmentedLineActor(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	BaseThickness(1)
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	SetRootComponent(RootComponent);

	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	ProcMesh->SetupAttachment(RootComponent);
	ProcMesh->bUseAsyncCooking = true;

	PrimaryActorTick.bCanEverTick = true;

    bBuildSectionsWithCollision = true;

	HoveredScaleMultiplier = 1.8f;

	TessellationLength = 250000.0f;

	CameraScalingComponent = CreateDefaultSubobject<UGame_CameraScalingComponent>(TEXT("CameraScalingComponent"));
	CameraScalingComponent->SetupAttachment(RootComponent);

	// same as default color in material
	Color = FLinearColor(0.802083, 0.047809, 0.000000, 1.000000).ToFColor(true);

	UGame_CameraScalingComponent::FGetCameraDistance getDistanceDelegate;
	getDistanceDelegate.BindLambda([this]() -> double
	{
		if (APlayerController* playerController = GetWorld()->GetFirstPlayerController())
		{
			FVector playerLocation;
			FRotator playerRotation;
			playerController->GetPlayerViewPoint(playerLocation, playerRotation);

			return FVector::Distance(playerLocation, GetClosestPointTo(playerLocation));
		}

		return 0;
	});

	CameraScalingComponent->GetDistanceLambda = getDistanceDelegate;
}

// ---------------------------------
// --- IInterface_UI_ContextMenuSource
// ---------------------------------

void AGame_SimpleSegmentedLineActor::GetContextOptionClasses_Implementation(TSet<TSubclassOf<UObject>>& contextOptionClasses)
{
	contextOptionClasses.Append(ContextOptionClasses);
}

// ---------------------------------
// --- Interface_Developer_Manipulation
// ---------------------------------

bool AGame_SimpleSegmentedLineActor::GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::None;

	return true;
}

bool AGame_SimpleSegmentedLineActor::GetRotationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::None;

	return true;
}

bool AGame_SimpleSegmentedLineActor::GetRotationDisabled_Implementation()
{
	EAxisListBlueprint axisList;
	IInterface_Developer_Manipulation::Execute_GetRotationAxisList(this, axisList);

	return axisList == EAxisListBlueprint::None;
}

bool AGame_SimpleSegmentedLineActor::GetScaleAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::None;

	return true;
}

void AGame_SimpleSegmentedLineActor::ManipulationBegin_Implementation()
{
	PostManipulationBegin();

	ReceiveManipulationBegin();

	OnManipulationBegin.Broadcast(this);
}

void AGame_SimpleSegmentedLineActor::ManipulationInProgress_Implementation()
{
	PostManipulationInProgress();

	ReceiveManipulationInProgress();

	OnManipulationInProgress.Broadcast(this);
}

void AGame_SimpleSegmentedLineActor::ManipulationEnd_Implementation()
{
	PostManipulationEnd();

	ReceiveManipulationEnd();

	OnManipulationEnd.Broadcast(this);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_SimpleSegmentedLineActor::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(Material))
	{
		MaterialInstance = UMaterialInstanceDynamic::Create(Material, this);

		ProcMesh->SetMaterial(0, MaterialInstance);
	}

	SetCollision(bBuildSectionsWithCollision);

	// todo ohg | remove when remove BaseThickness
	DefaultWidth = BaseThickness;

	OnClicked.AddDynamic(this, &AGame_SimpleSegmentedLineActor::HandleClickPressed);

	OnReleased.AddDynamic(this, &AGame_SimpleSegmentedLineActor::HandleClickReleased);

	OnBeginCursorOver.AddDynamic(this, &AGame_SimpleSegmentedLineActor::HandleBeginCursorOver);

	OnEndCursorOver.AddDynamic(this, &AGame_SimpleSegmentedLineActor::HandleEndCursorOver);

	UpdateMaterialForVO();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->OnDoubleSettingStored.AddDynamic(this, &AGame_SimpleSegmentedLineActor::HandleDoubleSettingStored);

		DatabaseScaleMultiplier = gameSettings->GetSettingDouble(FString(TEXT("LineScale")));
	}
}

void AGame_SimpleSegmentedLineActor::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (ShouldGenerateMesh())
	{
		GenerateMeshInternal();

		bGenerateMesh = false;
	}
}

void AGame_SimpleSegmentedLineActor::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	SetCollision(!bNewHidden);

	if (!bNewHidden)
	{
		GenerateMesh();
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_SimpleSegmentedLineActor::GenerateMesh()
{
	bGenerateMesh = true;
}

void AGame_SimpleSegmentedLineActor::SetCollision(bool bShouldCollide)
{
	ProcMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	ProcMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

	ProcMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, bShouldCollide ? ECR_Overlap : ECR_Ignore);

	ProcMesh->SetCollisionEnabled(bShouldCollide ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
}

void AGame_SimpleSegmentedLineActor::SetMaterialColor_Implementation(const FColor& newColor)
{
	Color = newColor;

	if (IsValid(MaterialInstance))
	{
		FLinearColor linearColor = FLinearColor(GetColor());
		MaterialInstance->SetVectorParameterValue(FName(TEXT("Color")), linearColor);

		OnColorChanged.Broadcast(linearColor);
	}
}

void AGame_SimpleSegmentedLineActor::SetMaterialHighlighted_Implementation(bool isHighlighted)
{
	if (MaterialInstance != nullptr)
	{
		MaterialInstance->SetScalarParameterValue(FName(TEXT("isHighlighted")), isHighlighted ? 1.0f : 0.f);
	}
}

void AGame_SimpleSegmentedLineActor::SetColor(const FColor& newColor)
{
	SetMaterialColor(newColor);
}

FColor AGame_SimpleSegmentedLineActor::GetColor() const
{ 
	return Color;
}

void AGame_SimpleSegmentedLineActor::AddLocation(const FVector& location)
{
	LinePoints.Add(FLinePoint(location, DefaultWidth));
}

bool AGame_SimpleSegmentedLineActor::RemoveLastLocation()
{
	if (LinePoints.Num() > 0)
	{
		LinePoints.RemoveAt(LinePoints.Num() - 1);
	}

	return LinePoints.Num() == 0;
}

FVector AGame_SimpleSegmentedLineActor::GetPointLocation(int32 index, bool& isValid) const
{
	if (LinePoints.IsValidIndex(index))
	{
		isValid = true;
		return LinePoints[index].Location;
	}

	isValid = false;
	return FVector::ZeroVector;
}

TArray<FVector> AGame_SimpleSegmentedLineActor::GetLocationArray() const
{
	TArray<FVector> locations;
	for (const FLinePoint& linePoint : LinePoints)
	{
		locations.Add(linePoint.Location);
	}

	return locations;
}

FVector AGame_SimpleSegmentedLineActor::GetAverageLocation() const
{
	if (LinePoints.Num() > 0)
	{
		FBox bbox;
		for (const FLinePoint& linePoint : LinePoints)
		{
			bbox += linePoint.Location;
		}

		return bbox.GetCenter();
	}

	return FVector::ZeroVector;
}

bool AGame_SimpleSegmentedLineActor::GetExtents(FVector& extentsMin, FVector& extentsMax) const
{
	if (LinePoints.Num() > 0)
	{
		FBox bbox;
		for (const FLinePoint& linePoint : LinePoints)
		{
			bbox += linePoint.Location;
		}

		extentsMin = bbox.Min;
		extentsMax = bbox.Max;
		
		return true;
	}

	extentsMin = FVector::ZeroVector;
	extentsMax = FVector::ZeroVector;

	return false;
}

void AGame_SimpleSegmentedLineActor::SnapToGround()
{
	for (int32 i = 0; i < LinePoints.Num(); i++)
	{
		bool bShouldSnap = true;
		if (Coords.IsValidIndex(i))
		{
			FGeodeticCoord3D coord = Coords[i];
			if (!FMath::IsNearlyEqual(coord.Altitude, 9999999.0))
			{
				bShouldSnap = false;
			}
		}

		if (bShouldSnap)
		{
			FVector worldLocation = LinePoints[i].Location;

			// snap to ground to find Z
			FTransform surfaceTransform = UGame_Statics::GetWorldTransformOverride(worldLocation);
			surfaceTransform.SetLocation(worldLocation);

			FVector startLocation = surfaceTransform.TransformPosition(FVector(0, 0, 10000000));
			FVector endLocation = surfaceTransform.TransformPosition(FVector(0, 0, -10000000));

			FHitResult hit;
			if (GetWorld()->LineTraceSingleByChannel(hit, startLocation, endLocation, UGame_GameInstance::GetTerrainCollisionChannel()))
			{
				LinePoints[i].Location = hit.Location;
			}
		}
	}

	GenerateMesh();
}

void AGame_SimpleSegmentedLineActor::AddLocationAndGeoLocation(const FVector& worldLocation, const FGeodeticCoord3D& coord)
{
	AddLocation(worldLocation);

	Coords.Add(coord);
}

void AGame_SimpleSegmentedLineActor::AddLocationAndGeoLocation(const FVector& worldLocation)
{
	if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
	{
		AddLocationAndGeoLocation(worldLocation, globeRef->WorldToGeodeticDouble(worldLocation));
	}
}

void AGame_SimpleSegmentedLineActor::UpdateLocationAndGeoLocation(int32 index, const FVector& worldLocation, const FGeodeticCoord3D& coord)
{
	if (LinePoints.IsValidIndex(index) && Coords.IsValidIndex(index))
	{
		LinePoints[index].Location = worldLocation;
		Coords[index] = coord;
	}
}

FGeodeticCoord3D AGame_SimpleSegmentedLineActor::GetGeoLocation(int32 index) const
{
	if (Coords.Num() == LinePoints.Num())
	{
		if (Coords.IsValidIndex(index))
		{
			return Coords[index];
		}

		UE_LOG(Game, Warning, TEXT("-- AGame_SimpleSegementedLineActor::GetGeoLocation | invalid index: %d"), index);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_SimpleSegementedLineActor::GetGeoLocation | Coords.Num() different from LinePoints.Num() | Coords: %d, LinePoints: %d"), Coords.Num(), LinePoints.Num());
	}

	return FGeodeticCoord3D();
}

bool AGame_SimpleSegmentedLineActor::AreCoordinatesValid()
{
	return Coords.Num() == LinePoints.Num();
}

void AGame_SimpleSegmentedLineActor::SetMaxDrawDistance(float dist)
{
	ProcMesh->SetCachedMaxDrawDistance(dist);
}

void AGame_SimpleSegmentedLineActor::SetDrawContainer(AGame_DrawContainer* container)
{
	DrawContainer = container;

	UpdateMaterialForVO();
}

void AGame_SimpleSegmentedLineActor::ClearLinePoints()
{
	LinePoints.Empty();

	Coords.Empty();
}

FVector AGame_SimpleSegmentedLineActor::GetClosestPointTo(const FVector& worldLocation) const
{
	FVector toReturn = worldLocation;

	double closestDistance = DBL_MAX;

	for (const FLinePoint& linePoint : LinePoints)
	{
		double distance = FVector::DistSquared(linePoint.Location, worldLocation);

		if (distance < closestDistance)
		{
			toReturn = linePoint.Location;

			closestDistance = distance;
		}
	}

	return toReturn;
}

bool AGame_SimpleSegmentedLineActor::Overlaps(const FGeodeticCoord2D& start, const FGeodeticCoord2D& end, FGeodeticCoord2D& intersection)
{
	for (int32 i = 0; i < Coords.Num() - 2; i++)
	{
		FVector intersectionVector;
		if (FMath::SegmentIntersection2D(FVector(start.ToVector(), 0), FVector(end.ToVector(), 0), FVector(Coords[i].ToGeodeticCoord2D().ToVector(), 0), FVector(Coords[i + 1].ToGeodeticCoord2D().ToVector(), 0), intersectionVector))
		{
			intersection.Longitude = intersectionVector.X;
			intersection.Latitude = intersectionVector.Y;

			return true;
		}
	}

	return false;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool AGame_SimpleSegmentedLineActor::ShouldGenerateMesh()
{
	if (IsHidden())
	{
		return false;
	}

	if (bGenerateMesh)
	{
		return true;
	}

	// check if points or thickness has changed
	if (CachedLinePoints.Num() != LinePoints.Num())
	{
		return true;
	}

	for (int32 i = 0; i < CachedLinePoints.Num(); i++)
	{
		FLinePoint cached = CachedLinePoints[i];
		FLinePoint actual = LinePoints[i];

		if (!cached.Location.Equals(actual.Location) || cached.Width != actual.Width)
		{
			return true;
		}
	}

	FGeodeticCoord3D playerCoordinate = UGame_Statics::GetPlayerCoordinate();
	if (!LastCoordinateAtGenerate.Equals(playerCoordinate, 0.001, 200))
	{
		LastCoordinateAtGenerate = playerCoordinate;

		return true;
	}

	return false;
}

void AGame_SimpleSegmentedLineActor::PreGenerateMesh()
{
	SetPointThickness();
}

void AGame_SimpleSegmentedLineActor::GenerateMeshInternal()
{
	PreGenerateMesh();

	CachedLinePoints.Empty();
	CachedLinePoints.Append(LinePoints);

	ProcMesh->ClearAllMeshSections();

	// must have at least 2 points for a line
	if (LinePoints.Num() < 2)
	{
		return;
	}

	TArray<FLinePoint> points(LinePoints);
	ModifyMeshPoints(points);

	for (int32 i = 1; i < points.Num(); i++)
	{
		FVector startPoint = points[i - 1].Location;
		FVector endPoint = points[i].Location;

		// skip degenerate segments (i.e. duplicate adjacent points)
		if (startPoint.Equals(endPoint, 0.0001f))
		{
			points.RemoveAt(i, 1);
			i--;
		}
	}
	
	if (points.Num() >= 2)
	{
		TArray<FVector> vertices;
		TArray<int32> triangles;
		TArray<FVector> normals;
		TArray<FVector2D> uvs;
		GenerateMeshInternal(points, vertices, triangles, normals, uvs);

		ProcMesh->SetWorldTransform(FTransform::Identity);
		ProcMesh->CreateMeshSection(0, vertices, triangles, normals, uvs, uvs, uvs, uvs, TArray<FColor>(), TArray<FProcMeshTangent>(), bBuildSectionsWithCollision);
		ProcMesh->SetMaterial(0, MaterialInstance);
	}
}

void AGame_SimpleSegmentedLineActor::GenerateMeshInternal(const TArray<FLinePoint>& points, TArray<FVector>& vertices, TArray<int32>& triangles, TArray<FVector>& normals, TArray<FVector2D>& uvs)
{
	for (int32 i = 0; i < points.Num() - 1; i++)
	{
		FTransform pointTransform;
		pointTransform.SetLocation(points[i].Location);
		pointTransform.SetRotation((points[i + 1].Location - points[i].Location).ToOrientationQuat());
		pointTransform.SetScale3D(FVector(1, 1, 1));

		double length = (points[i + 1].Location - points[i].Location).Size();
		double halfWidth = points[i].Width * 0.5;

		// draw from previous endpoints to avoid gaps between segments
		double previousLength = 0;
		double previousHalfWidth = halfWidth;
		FTransform previousTransform = pointTransform;
		if (i > 0)
		{
			previousTransform.SetLocation(points[i - 1].Location);
			previousTransform.SetRotation((points[i].Location - points[i - 1].Location).ToOrientationQuat());
			previousTransform.SetScale3D(FVector(1, 1, 1));

			previousLength = (points[i].Location - points[i - 1].Location).Size();
			previousHalfWidth = points[i - 1].Width * 0.5;
		}

		// two triangles at beginning of line
		if (i == 0)
		{
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
			uvs.Add(FVector2D(0, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, -halfWidth)));
			uvs.Add(FVector2D(0, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));

			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, halfWidth)));
			uvs.Add(FVector2D(1, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
			uvs.Add(FVector2D(0, 0));

			FVector normal = pointTransform.TransformPosition(FVector(-1, 0, 0));
			for (int32 j = 0; j < 6; j++)
			{
				normals.Add(normal);
			}
		}

		if (i > 0)
		{
			// connect end of last segment to start of current segment
			// left
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, -previousHalfWidth, previousHalfWidth)));
			uvs.Add(FVector2D(1, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
			uvs.Add(FVector2D(0, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, -halfWidth)));
			uvs.Add(FVector2D(0, 1));

			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, -previousHalfWidth, previousHalfWidth)));
			uvs.Add(FVector2D(1, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, -halfWidth)));
			uvs.Add(FVector2D(0, 1));
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, -previousHalfWidth, -previousHalfWidth)));
			uvs.Add(FVector2D(1, 1));

			FVector normal = pointTransform.TransformPosition(FVector(0, -1, 0));
			for (int32 j = 0; j < 6; j++)
			{
				normals.Add(normal);
			}

			// right
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, halfWidth)));
			uvs.Add(FVector2D(1, 0));
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, previousHalfWidth, previousHalfWidth)));
			uvs.Add(FVector2D(0, 0));

			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, previousHalfWidth, -previousHalfWidth)));
			uvs.Add(FVector2D(0, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, previousHalfWidth, previousHalfWidth)));
			uvs.Add(FVector2D(0, 0));

			normal = pointTransform.TransformPosition(FVector(0, 1, 0));
			for (int32 j = 0; j < 6; j++)
			{
				normals.Add(normal);
			}

			// bottom
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, -previousHalfWidth, -previousHalfWidth)));
			uvs.Add(FVector2D(0, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));

			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, -previousHalfWidth, -previousHalfWidth)));
			uvs.Add(FVector2D(0, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, previousHalfWidth, -previousHalfWidth)));
			uvs.Add(FVector2D(0, 1));

			normal = pointTransform.TransformPosition(FVector(0, 0, -1));
			for (int32 j = 0; j < 6; j++)
			{
				normals.Add(normal);
			}

			// top
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, halfWidth)));
			uvs.Add(FVector2D(1, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
			uvs.Add(FVector2D(1, 0));
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, -previousHalfWidth, previousHalfWidth)));
			uvs.Add(FVector2D(0, 0));

			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, previousHalfWidth, previousHalfWidth)));
			uvs.Add(FVector2D(0, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, halfWidth)));
			uvs.Add(FVector2D(1, 1));
			vertices.Add(previousTransform.TransformPosition(FVector(previousLength, -previousHalfWidth, previousHalfWidth)));
			uvs.Add(FVector2D(0, 0));

			normal = pointTransform.TransformPosition(FVector(0, 0, 1));
			for (int32 j = 0; j < 6; j++)
			{
				normals.Add(normal);
			}
		}

		// two triangles for each of 4 sides
		// left
		vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
		uvs.Add(FVector2D(1, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, halfWidth)));
		uvs.Add(FVector2D(0, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, -halfWidth)));
		uvs.Add(FVector2D(0, 1));

		vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
		uvs.Add(FVector2D(1, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, -halfWidth)));
		uvs.Add(FVector2D(0, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, -halfWidth)));
		uvs.Add(FVector2D(1, 1));

		FVector normal = pointTransform.TransformPosition(FVector(0, -1, 0));
		for (int32 j = 0; j < 6; j++)
		{
			normals.Add(normal);
		}

		// right
		vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, -halfWidth)));
		uvs.Add(FVector2D(1, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, halfWidth)));
		uvs.Add(FVector2D(1, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, halfWidth)));
		uvs.Add(FVector2D(0, 0));

		vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
		uvs.Add(FVector2D(0, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, -halfWidth)));
		uvs.Add(FVector2D(1, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, halfWidth)));
		uvs.Add(FVector2D(0, 0));

		normal = pointTransform.TransformPosition(FVector(0, 1, 0));
		for (int32 j = 0; j < 6; j++)
		{
			normals.Add(normal);
		}

		// bottom
		vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, -halfWidth)));
		uvs.Add(FVector2D(0, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, -halfWidth)));
		uvs.Add(FVector2D(1, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, -halfWidth)));
		uvs.Add(FVector2D(1, 1));

		vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, -halfWidth)));
		uvs.Add(FVector2D(0, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, -halfWidth)));
		uvs.Add(FVector2D(1, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, -halfWidth)));
		uvs.Add(FVector2D(0, 1));

		normal = pointTransform.TransformPosition(FVector(0, 0, -1));
		for (int32 j = 0; j < 6; j++)
		{
			normals.Add(normal);
		}

		// top
		vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, halfWidth)));
		uvs.Add(FVector2D(1, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, halfWidth)));
		uvs.Add(FVector2D(1, 0));
		vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
		uvs.Add(FVector2D(0, 0));

		vertices.Add(pointTransform.TransformPosition(FVector(0, halfWidth, halfWidth)));
		uvs.Add(FVector2D(0, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, halfWidth)));
		uvs.Add(FVector2D(1, 1));
		vertices.Add(pointTransform.TransformPosition(FVector(0, -halfWidth, halfWidth)));
		uvs.Add(FVector2D(0, 0));

		normal = pointTransform.TransformPosition(FVector(0, 0, 1));
		for (int32 j = 0; j < 6; j++)
		{
			normals.Add(normal);
		}

		// two triangles at end of line
		if (i + 1 == points.Num() - 1)
		{
			vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, -halfWidth)));
			uvs.Add(FVector2D(0, 1));
			vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, halfWidth)));
			uvs.Add(FVector2D(0, 0));

			vertices.Add(pointTransform.TransformPosition(FVector(length, -halfWidth, halfWidth)));
			uvs.Add(FVector2D(0, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, halfWidth)));
			uvs.Add(FVector2D(1, 0));
			vertices.Add(pointTransform.TransformPosition(FVector(length, halfWidth, -halfWidth)));
			uvs.Add(FVector2D(1, 1));

			normal = pointTransform.TransformPosition(FVector(1, 0, 0));
			for (int32 j = 0; j < 6; j++)
			{
				normals.Add(normal);
			}
		}
	}

	// vertices are ordered sets of 3
	for (int32 i = 0; i < vertices.Num(); i++)
	{
		triangles.Add(i);
	}
}

void AGame_SimpleSegmentedLineActor::ModifyMeshPoints(TArray<FLinePoint>& points)
{
	TArray<FLinePoint> newPoints;

	for (int32 i = 0; i < points.Num() - 1; i++)
	{
		newPoints.Add(points[i]);

		if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
		{
			if (Coords.IsValidIndex(i) && Coords.IsValidIndex(i + 1))
			{
				FGeodeticCoord3D firstCoord = Coords[i];
				if (firstCoord.Altitude == 9999999.0f)
				{
					firstCoord.Altitude = 0;
				}
				FGeodeticCoord3D secondCoord = Coords[i + 1];
				if (secondCoord.Altitude == 9999999.0f)
				{
					secondCoord.Altitude = 0;
				}

				TArray<FGeodeticCoord3D> newCoords = UVH_GlobeMathStatics::InterpolateLocations(firstCoord, secondCoord, TessellationLength);
				for (int32 j = 1; j < newCoords.Num() - 1; j++)
				{
					// Copy the first point and just change its location
					FLinePoint point(points[0]);

					newCoords[j].Altitude = Coords[i].Altitude;
					point.Location = globeRef->GeodeticToWorldDouble(newCoords[j]);
					newPoints.Add(point);
				}
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("AGame_SimpleSegmentedLineActor::ModifyMeshPoints() -- Coords array is out of sync with LinePoints"));
			}
		}
	}

	// Add last point
	newPoints.Add(points.Last());
	
	points.Empty();
	for (int32 i = 0; i < newPoints.Num(); i++)
	{
		points.Add(newPoints[i]);
	}
}

void AGame_SimpleSegmentedLineActor::UpdateMaterialForVO()
{
	bool bSetTimer = true;

	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		if (MaterialInstance != nullptr)
		{
			int32 voIndex = virtualObjective->GetVOIndex();
			MaterialInstance->SetScalarParameterValue(FName(TEXT("VOIndex")), voIndex);

			bSetTimer = false;
		}
	}

	if (bSetTimer)
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_SimpleSegmentedLineActor::UpdateMaterialForVO, 0.5, false);
	}
}

AGame_VirtualObjective* AGame_SimpleSegmentedLineActor::GetVirtualObjective() const
{
	// try DrawContainer
	AGame_VirtualObjective* virtualObjective = nullptr;
	if (DrawContainer != nullptr)
	{
		virtualObjective = DrawContainer->GetVirtualObjective();
	}

	// default to player
	if (virtualObjective == nullptr)
	{
		virtualObjective = AGame_PlayerController::GetPlayerActiveVO();
	}

	return virtualObjective;
}

AVH_GlobeReferenceActor* AGame_SimpleSegmentedLineActor::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;
}

void AGame_SimpleSegmentedLineActor::SetPointThickness()
{
	double hoveredScaleMultiplier = bHovered ? HoveredScaleMultiplier : 1;

	for (FLinePoint& linePoint : LinePoints)
	{
		double distance = CameraScalingComponent->GetDistance();
			
		linePoint.Width = hoveredScaleMultiplier * DatabaseScaleMultiplier * CameraScalingComponent->GetScaleForDistance(distance).X * DefaultWidth;
	}
}

void AGame_SimpleSegmentedLineActor::PostManipulationBegin()
{

}

void AGame_SimpleSegmentedLineActor::PostManipulationInProgress()
{

}

void AGame_SimpleSegmentedLineActor::PostManipulationEnd()
{

}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_SimpleSegmentedLineActor::HandleBeginCursorOver(AActor* actor)
{
	bHovered = true;

	SetMaterialHighlighted(true);

	ReceiveBeginHover(actor);

	GenerateMesh();
}


void AGame_SimpleSegmentedLineActor::HandleEndCursorOver(AActor* actor)
{
	bHovered = false;

	SetMaterialHighlighted(false);

	ReceiveEndHover(actor);

	GenerateMesh();
}

void AGame_SimpleSegmentedLineActor::HandleClickPressed(AActor* actor, FKey buttonPressed)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		TSet<UGame_UserWidget_MapScrape*> widgets = subsystem->GetUserWidgetsByClass<UGame_UserWidget_MapScrape>(true);
		for (UGame_UserWidget_MapScrape* widget : widgets)
		{
			widget->LineClicked(this);
		}
	}
}

void AGame_SimpleSegmentedLineActor::HandleClickReleased(AActor* actor, FKey buttonReleased)
{
	if (UUI_Subsystem_ContextMenu* subsystem = UUI_Subsystem_ContextMenu::Get())
	{
		subsystem->OpenContextMenuWithDefaults(actor, this);
	}
}

void AGame_SimpleSegmentedLineActor::HandleDoubleSettingStored(const FString& key, double value)
{
	if (key.Equals(TEXT("LineScale")))
	{
		DatabaseScaleMultiplier = value;

		GenerateMesh();
	}
}