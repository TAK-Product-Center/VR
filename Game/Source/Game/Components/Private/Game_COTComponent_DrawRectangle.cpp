// Parent Includes
#include "Game_COTComponent_DrawRectangle.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_Actor_Mesh.h"
#include "Game_COTManager.h"
#include "Game_DrawContainer.h"
#include "Game_EditPoint.h"
#include "Game_EditPoint_Center.h"
#include "Game_EditPoint_RectangleRotator.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_DrawLineData.h"
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_ImportedMeshComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawRectangle::UGame_COTComponent_DrawRectangle() :
	CuboidFillActorClass(AGame_Actor_Mesh::StaticClass()),
	CuboidHeightMeters(0.0f),
	MeshStyleAlpha(128),
	MeshStyleColor(FColor(255, 255, 255, 128)),
	bFixOppositeWhileResizing(true),
	bFixCenterWhileRotating(true)
{
	bGenerateCallsign = false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawRectangle::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->Destroy();
	}

	for (int32 rotatorIndex = 0; rotatorIndex < RotatorEditPoints.Num(); rotatorIndex++)
	{
		RotatorEditPoints[rotatorIndex]->Destroy();
	}

	if (CuboidMeshes.IsValidIndex(0))
	{
		for (int32 cuboidMeshIndex = 0; cuboidMeshIndex < CuboidMeshes.Num(); cuboidMeshIndex++)
		{
			CuboidMeshes[cuboidMeshIndex]->Destroy();
		}
	}
}

void UGame_COTComponent_DrawRectangle::SnapToGround()
{
	if (ShouldSnapEditPoint(CenterEditPoint))
	{
		UGame_Statics::SnapToGround(CenterEditPoint);
	}
}

bool UGame_COTComponent_DrawRectangle::ShouldSnapEditPoint(AGame_EditPoint* editPoint) const
{
	// snap only the center edit point to ground if it has height 9999999.0; others should follow because of attachment
	return editPoint == CenterEditPoint && Super::ShouldSnapEditPoint(editPoint);
}

void UGame_COTComponent_DrawRectangle::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();

		// spawn all edit points
		FGeodeticCoord3D trueCenterLocGeo = cotEvent->GetPoint();
		FVector trueCenterLocWorld = globeReference->GeodeticToWorldDouble(trueCenterLocGeo);

		SpawnDrawElements(trueCenterLocWorld, cotEvent->GetAttribute<FColor>(TEXT("strokeColor")));
		CenterEditPoint->SetCallsign(cotEvent->GetAttribute(TEXT("callsign")));
		CenterEditPoint->SetGeoLocation(trueCenterLocGeo);

		// extract height and color
		CuboidHeightMeters = cotEvent->GetAttribute<double>(TEXT("detail\theight\tvalue"));

		// strokeColor is line
		FColor lineColor = cotEvent->GetAttribute<FColor>(TEXT("strokeColor"));
		lineColor.A = 255;

		GetLines()[0]->SetColor(lineColor);

		MeshStyleColor = UVH_COTStatics::HexAttributeToColor(cotEvent->GetAttribute(TEXT("fillColor")));
		MeshStyleAlpha = MeshStyleColor.A;

		UVH_COTStatics::CalculateRectangleAttributesAsDoubles(cotEvent, trueCenterLocGeo, LengthInMeters, WidthInMeters, RotationInDegrees);
		
		UpdateRectangleFromFields(false);
		
		UpdateCuboidMesh();
	}
}

void UGame_COTComponent_DrawRectangle::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
	{
		if (GetLines().Num() == 0)
		{
			UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawRectangle::PopulateCOT_Virtual() -- No lines found."));
			return;
		}

		TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();

		if (editPoints.Num() != PointsInShape + 1)
		{
			// A rectangle needs 5 edit points, the 5th is for wrapping the line around 
			UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawRectangle::PopulateCOT_Virtual() -- Expected %d edit points."), PointsInShape + 1);
			return;
		}

		if (CenterEditPoint == nullptr)
		{
			UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawRectangle::PopulateCOT_Virtual() | CenterEditPoint is nullptr"));
			return;
		}

		cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-r"));
		cotEvent->SetAttribute<float>(TEXT("height"), CuboidHeightMeters);
		cotEvent->SetAttribute(TEXT("height_unit"), TEXT("1"));  // meters

		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		FColor lineColor = line->GetColor();
		lineColor.A = MeshStyleAlpha;

		// strokeColor is the line
		cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), lineColor);

		cotEvent->SetAttribute(TEXT("detail\tstrokeStyle\tvalue"), TEXT("solid"));

		// By default, we'll want the mesh to match the color of the line
		MeshStyleColor = lineColor;
		MeshStyleColor.A = MeshStyleAlpha;

		// color and fillcolor are the mesh
		cotEvent->SetAttribute(TEXT("detail\tcolor\tvalue"), UVH_COTStatics::ColorToHexAttribute(MeshStyleColor));
		cotEvent->SetAttribute(TEXT("fillColor"), UVH_COTStatics::ColorToHexAttribute(MeshStyleColor));
		
		if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("callsign"), TEXT("Rectangle"));
		}

		if (CenterEditPoint != nullptr)
		{
			CenterEditPoint->SetCallsign(cotEvent->GetAttribute(TEXT("callsign")));
		}

		cotEvent->RemoveNodes(TEXT("link"));
		
		cotEvent->PopulateTime(ActiveTime);

		// Assign COT Point for this COT event 
		cotEvent->SetPoint(CenterEditPoint->GetGeoLocation());

		// Assign COT Detail links for this COT event, 5th edit point not stored. 
		for (int32 pointIndex = 0; pointIndex < PointsInShape; ++pointIndex)
		{
			FGeodeticCoord3D coordinate = editPoints[pointIndex]->GetGeoLocation();

			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(coordinate)));

			cotEvent->AddNode(TEXT("link"), attributes);
		}
	}
}

TArray<FVector> UGame_COTComponent_DrawRectangle::PreModifyVOGlobeReference()
{
	TArray<FVector> locations = Super::PreModifyVOGlobeReference();

	for (int rotatorIndex = 0; rotatorIndex < PointsInShape; rotatorIndex++)
	{
		locations.Add(RotatorEditPoints[rotatorIndex]->GetActorLocation());
	}
	
	if (CenterEditPoint != nullptr)
	{
		locations.Add(CenterEditPoint->GetActorLocation());
	}

	return locations;
}

void UGame_COTComponent_DrawRectangle::PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions)
{
	DetachPointsFromCenter();
	DetachMeshFromCenter();

	Super::PostModifyVOGlobeReference(updatedPositions);

	int32 finalEditPointIndex = GetRectangleEditPoints().Num();
	finalEditPointIndex += 2; //The first edit point is updatedPosition index 2, not 0.
	for (int32 rotatorIndex = 0; rotatorIndex < PointsInShape; rotatorIndex++)
	{
		if (updatedPositions.IsValidIndex(rotatorIndex + finalEditPointIndex))
		{
			RotatorEditPoints[rotatorIndex]->SetActorLocation(updatedPositions[rotatorIndex + finalEditPointIndex]);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_DrawRectangle::PostModifyVOGlobeReference | %d | mismatch between RotatorEditPoints index and and updatedPositions (%d)"), rotatorIndex + finalEditPointIndex, updatedPositions.Num());
		}
	}

	
	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->SetActorLocation(updatedPositions.Last());
	}

	for (int32 cuboidMeshIndex = 0; cuboidMeshIndex < CuboidMeshes.Num(); cuboidMeshIndex++)
	{
		CuboidMeshes[cuboidMeshIndex]->SetActorLocation(updatedPositions.Last());
	}

	AttachPointsToCenter();
	AttachMeshToCenter();
}

void UGame_COTComponent_DrawRectangle::HandleOwnerSetScale3D(const FVector& scale3D)
{
	DetachPointsFromCenter();
	DetachMeshFromCenter();

	Super::HandleOwnerSetScale3D(scale3D);

	if (RotatorEditPoints.Num() == PointsInShape)
	{
		for (int32 rotatorIndex = 0; rotatorIndex < PointsInShape; rotatorIndex++)
		{
			RotatorEditPoints[rotatorIndex]->SetActorScale3D(scale3D);
			RotatorEditPoints[rotatorIndex]->SetThickness(scale3D.IsUniform() ? scale3D.X : 1.f);
		}
	}
	
	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->SetActorScale3D(scale3D);
	}

	for (AGame_Actor_Mesh* simpleMeshActor : CuboidMeshes)
	{
		simpleMeshActor->SetActorScale3D(scale3D);
	}

	AttachPointsToCenter();
	AttachMeshToCenter();

	bool bActive = false;
	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();
	if (editPoints.IsValidIndex(0))
	{
		bActive = editPoints[0]->GetActive();
	}

	GetWorld()->GetTimerManager().SetTimerForNextTick([this, bActive]()
	{
		UpdateRectangleFromFields(bActive);
		
		UpdateCuboidMesh();
	});
}

void UGame_COTComponent_DrawRectangle::SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive)
{
	Super::SetEditPointsActive(line, bActive);

	// fifth edit point is never active
	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();

	if (editPoints.IsValidIndex(PointsInShape))
	{
		editPoints[PointsInShape]->SetActive(false);
	}

	if (RotatorEditPoints.Num() == PointsInShape)
	{
		for (int32 editPointIndex = 0; editPointIndex < PointsInShape; editPointIndex++)
		{
			RotatorEditPoints[editPointIndex]->SetActive(bActive);
		}
	}
}

void UGame_COTComponent_DrawRectangle::HandleOwnerSetHidden(bool bNewHidden)
{
	Super::HandleOwnerSetHidden(bNewHidden);

	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->SetActorHiddenInGame(bNewHidden);
	}

	if (CuboidMeshes.IsValidIndex(0))
	{
		for (int32 cuboidMeshIndex = 0; cuboidMeshIndex < CuboidMeshes.Num(); cuboidMeshIndex++)
		{
			CuboidMeshes[cuboidMeshIndex]->SetActorHiddenInGame(bNewHidden);
		}
	}
}

void UGame_COTComponent_DrawRectangle::PostManipulationEnd(AActor* manipulatedActor)
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_COTComponent_DrawRectangle::SpawnDrawElements(const FVector& centerPointLocation, const FLinearColor& inColor)
{
	// destroy existing lines to ensure clean slate
	TArray<UGame_DrawLineData*> lineDatas;
	Lines.GenerateValueArray(lineDatas);

	for (int32 i = 0; i < lineDatas.Num(); i++)
	{
		lineDatas[i]->ConditionalBeginDestroy();
	}
	Lines.Empty();

	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->Destroy();
		CenterEditPoint = nullptr;
	}

	const int32 numRotators = RotatorEditPoints.Num();
	for(int32 rotatorIndex = numRotators -1; rotatorIndex >= 0; rotatorIndex--)
	{
		RotatorEditPoints[rotatorIndex]->Destroy();
	}
	RotatorEditPoints.Empty();
	
	// spawn line
	AGame_SimpleSegmentedLineActor* line = SpawnLine();
	line->OnColorChanged.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleLineColorChanged);

	// spawn outer 5
	for (int32 i = 0; i < PointsInShape + 1; ++i)
	{
		AGame_EditPoint* editPoint = SpawnEditPoint(line, centerPointLocation, nullptr);
		
		// bind to all except 5th in order to update other points and center
		if (i != PointsInShape + 1)
		{
			editPoint->OnManipulationBegin.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleManipulationBegin);
			editPoint->OnManipulationInProgress.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleManipulationInProgress);
			editPoint->OnManipulationEnd.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleManipulationEnd);
		}
	}

	// spawn rotators
	for (int32 rotatorIndex = 0; rotatorIndex < PointsInShape; rotatorIndex++)
	{
		AGame_EditPoint_RectangleRotator* rotatorEditPoint = SpawnRotatorEditPoint(centerPointLocation, nullptr);

		rotatorEditPoint->OnManipulationBegin.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleManipulationBegin);
		rotatorEditPoint->OnManipulationInProgress.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleManipulationInProgress);
		rotatorEditPoint->OnManipulationEnd.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleRotatorManipulationEnd);
	}

	SetEditPointsActive(line, true);

	// spawn center
	SpawnCenterEditPoint(centerPointLocation);

	// attach outer 5
	AttachPointsToCenter();
	
	line->SetColor(inColor.ToFColor(true));
}

AGame_EditPoint_RectangleRotator* UGame_COTComponent_DrawRectangle::SpawnRotatorEditPoint(const FVector& location, AGame_EditPoint_RectangleRotator* existingEditPoint)
{
	FVector ownerScale = GetOwner()->GetActorScale3D();
	FTransform spawnTransform = FTransform(FRotator(0, 0, 0), location, ownerScale);

	AGame_EditPoint_RectangleRotator* rotatorPoint = GetWorld()->SpawnActorDeferred<AGame_EditPoint_RectangleRotator>(RotatorEditPointClass, spawnTransform, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	rotatorPoint->SetDrawContainer(Cast<AGame_DrawContainer>(GetOwner()));

	UGameplayStatics::FinishSpawningActor(rotatorPoint, spawnTransform);

	rotatorPoint->SetThickness(ownerScale.IsUniform() ? ownerScale.X : 1.f);
	rotatorPoint->SetLineActor(GetLines()[0]);
	rotatorPoint->SetActive(true);

	if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
	{
		rotatorPoint->SetGeoLocation(globeRef->WorldToGeodeticDouble(rotatorPoint->GetActorLocation()));
	}

	RotatorEditPoints.Add(rotatorPoint);

	return rotatorPoint;
}

AGame_EditPoint_Center* UGame_COTComponent_DrawRectangle::GetCenterEditPoint() const
{
	return CenterEditPoint;
}

void UGame_COTComponent_DrawRectangle::UpdateRectangleFromFields(bool bActive)
{
	TArray<int32> ignoredIndices;
	UpdateRectangleFromFields(bActive, ignoredIndices);
}

void UGame_COTComponent_DrawRectangle::UpdateRectangleFromFields(bool bActive, const TArray<int32>& ignoredIndices)
{
	if (!IsValid(CenterEditPoint))
	{
		return;
	}

	/* Update locations of the spawned edit points */
	FGeodeticCoord3D trueCenterLocGeo = CenterEditPoint->GetGeoLocation();

	double halfLengthMeters = LengthInMeters / 2;
	double halfWidthMeters = WidthInMeters / 2;

	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();
	double halfDiagonal_meters = FMath::Sqrt(halfWidthMeters * halfWidthMeters + halfLengthMeters * halfLengthMeters);
	
	/* diagonalAngle_degrees is between [center horizontal line] and [center to 0], [center to 1], [center to 2], and [center to 3]; same angle for all of them
	*
	*  3      0
	*  --------
	*  |\    /|
	*  | \  / |
	   |__\/__|
	*  |  /\  |
	*  | /  \ |
	*  --------
	*  2      1
	*/
	double diagonalAngle_degrees = FMath::RadiansToDegrees(FMath::Atan2(halfLengthMeters, halfWidthMeters));
	
	/*
	* edit points are ordered:
	* 3 0
	* 2 1
	* 
	* The angle to reach 3 from center is 270 + diagonalAngle_degrees.
	* The angle to reach 2 from center is 180 + (90 - diagonalAngle_degrees).
	* The angle to reach 1 from center is 180 - (90 - diagonalAngle_degrees).
	* The angle to reach 0 from center is (90 - diagonalAngle_degrees).
	*/
	double oppositeDegrees = 90 - diagonalAngle_degrees;
	double angles[4] { oppositeDegrees, 180 - oppositeDegrees, 180 + oppositeDegrees, 270 + diagonalAngle_degrees };

	for (int32 pointIndex = 0; pointIndex < PointsInShape; pointIndex++)
	{
		if (ignoredIndices.Find(pointIndex) == INDEX_NONE)
		{
			diagonalAngle_degrees = angles[pointIndex] + RotationInDegrees;
			
			FGeodeticCoord2D editPointCoord = UVH_GlobeMathStatics::CalculateSurfaceDestination(trueCenterLocGeo.ToGeodeticCoord2D(), diagonalAngle_degrees, halfDiagonal_meters);
			editPoints[pointIndex]->SetGeoLocation(FGeodeticCoord3D(editPointCoord.Longitude, editPointCoord.Latitude, trueCenterLocGeo.Altitude));
			editPoints[pointIndex]->SyncWorldLocationToGeoLocation();
		}

		editPoints[pointIndex]->SetActive(bActive);
	}

	editPoints.Last()->SetGeoLocation(editPoints[0]->GetGeoLocation());
	editPoints.Last()->SyncWorldLocationToGeoLocation();
	editPoints.Last()->SetActive(false);

	// update locations of the spawned rotator edit points 
	for (int32 i = 0; i < PointsInShape; i++)
	{
		FGeodeticCoord2D first;
		FGeodeticCoord2D second;

		first = editPoints[i]->GetGeoLocation().ToGeodeticCoord2D();
		second = editPoints[(i + 1) % PointsInShape]->GetGeoLocation().ToGeodeticCoord2D();

		double bearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(first, second);
		double range = UVH_GlobeMathStatics::CalculateSurfaceDistance(first, second);
		FGeodeticCoord2D edgeCenter = UVH_GlobeMathStatics::CalculateSurfaceDestination(first, bearing, range / 2);

		RotatorEditPoints[i]->SetGeoLocation(FGeodeticCoord3D(edgeCenter, trueCenterLocGeo.Altitude));
		RotatorEditPoints[i]->SyncWorldLocationToGeoLocation();
		RotatorEditPoints[i]->SetActive(bActive);
	}
}

void UGame_COTComponent_DrawRectangle::UpdateRectangleShape(AGame_EditPoint* manipulatedPoint)
{
	auto getQuadrant = [](double bearing)
	{
		if (bearing <= 90)
		{
			return 0;
		}
		else if (bearing <= 180)
		{
			return 1;
		}
		else if (bearing <= 270)
		{
			return 2;
		}

		return 3;
	};

	AVH_GlobeReferenceActor* globeRef = GetGlobeReference();
	
	AGame_SimpleSegmentedLineActor* line = GetLines()[0];
	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();

	if (editPoints.Num() != PointsInShape + 1)
	{
		// A rectangle needs 5 edit points to wrap the line correctly, if we don't, we shouldn't update anything. 
		UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawRectangle::UpdateRectangleShape() -- Expected 5 edit points."));

		return;
	}

	int32 manipulatedIndex;
	editPoints.Find(manipulatedPoint, manipulatedIndex);

	if (manipulatedIndex == PointsInShape)
	{
		/* The 5th edit point should be hidden and unselectable, so if it is somehow manipulated,
		 * we should return so as to not crash the calculate adjacent points function. */
		UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawRectangle::UpdateRectangleShape() -- User selected 5th inactivated edit point."));

		return;
	}

	/*
	* note: rotation is added later, we factor it out of these calculations
	* 
	* First find new center position.
	* Next get bearing from center to manipulated point.  Since we're not rotated, we can calculate innerRectangleAngle (see below) from the angle of the line between center and manipulated point.
	*	Based on which point is manipulated, modify the bearing so we're getting the innerRectangleAngle.
	* Once we have the innerRectangleAngle, use sin/cos to determine new length and width.
	* Determine new index of manipulated editpoint in the editpoints array.
	* Finally adjust the editpoints adjacent to the manipulated point based on new innerRectangleAngle.
	*/
	manipulatedPoint->SyncGeoLocationToWorldLocation();
	
	FGeodeticCoord2D manipulatedPoint_Geo = manipulatedPoint->GetGeoLocation().ToGeodeticCoord2D();

	AGame_EditPoint* oppositeEditPoint = editPoints[(manipulatedIndex + 2) % PointsInShape];
	FGeodeticCoord2D oppEditPoint_Geo = oppositeEditPoint->GetGeoLocation().ToGeodeticCoord2D();

	if (!bFixOppositeWhileResizing)
	{
		FGeodeticCoord2D center_Geo = CenterEditPoint->GetGeoLocation().ToGeodeticCoord2D();
		
		double manipulatedToCenterDistance = UVH_GlobeMathStatics::CalculateSurfaceDistance(manipulatedPoint_Geo, center_Geo);
		double centerToOppositeBearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(manipulatedPoint_Geo, center_Geo);

		FGeodeticCoord2D matchingOpposite_Geo = UVH_GlobeMathStatics::CalculateSurfaceDestination(center_Geo, centerToOppositeBearing, manipulatedToCenterDistance);

		oppositeEditPoint->SetGeoLocation(FGeodeticCoord3D(matchingOpposite_Geo, CenterEditPoint->GetGeoLocation().Altitude));
		oppositeEditPoint->SyncWorldLocationToGeoLocation();

		oppEditPoint_Geo = oppositeEditPoint->GetGeoLocation().ToGeodeticCoord2D();
	}

	double cornerToCornerDist = UVH_GlobeMathStatics::CalculateSurfaceDistance(manipulatedPoint_Geo, oppEditPoint_Geo);

	double manipulatedToOppositeBearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(manipulatedPoint_Geo, oppEditPoint_Geo);
	FGeodeticCoord2D newCenter_Geo = UVH_GlobeMathStatics::CalculateSurfaceDestination(manipulatedPoint_Geo, manipulatedToOppositeBearing, cornerToCornerDist / 2.f);
	
	double centerToManipulatedBearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(newCenter_Geo, manipulatedPoint_Geo) - RotationInDegrees;
	double uneditedCenterToManipulatedBearing = centerToManipulatedBearing;
	
	/* inner rectangle angle is degrees between [center vertical line] and [center to 0], [center to 1], [center to 2], and [center to 3]; same angle for all of them
	*  3     0
	*  -------
	*  |\ | /|
	*  | \|/ |
	*  | /|\ |
	*  |/ | \| 
	*  -------
	*  2     1
	*/
	double innerRectangleAngleDegrees = centerToManipulatedBearing;
	if (innerRectangleAngleDegrees < 0)
	{
		innerRectangleAngleDegrees += 360;
	}

	int32 quadrant = getQuadrant(innerRectangleAngleDegrees);
	
	switch (quadrant)
	{
		case 1:
			innerRectangleAngleDegrees = 180 - innerRectangleAngleDegrees;
			break;

		case 2:
			innerRectangleAngleDegrees -= 180;
			break;

		case 3:
			innerRectangleAngleDegrees = 360 - innerRectangleAngleDegrees;
			break;
	}

	double innerRectangleAngleRadians = FMath::DegreesToRadians(innerRectangleAngleDegrees);

	double halfWidth = FMath::Sin(innerRectangleAngleRadians) * (cornerToCornerDist / 2.f);
	double halfLength = FMath::Cos(innerRectangleAngleRadians) * (cornerToCornerDist / 2.f);

	WidthInMeters = halfWidth * 2;
	LengthInMeters = halfLength * 2;

	double altitude = manipulatedPoint->GetGeoLocation().Altitude;

	// update edit point locations
	DetachPointsFromCenter();
	DetachMeshFromCenter();

	if (bFixOppositeWhileResizing)
	{
		oppositeEditPoint->SetGeoLocation(FGeodeticCoord3D(oppositeEditPoint->GetGeoLocation().ToGeodeticCoord2D(), altitude));
		oppositeEditPoint->SyncWorldLocationToGeoLocation();
		
		CenterEditPoint->SetGeoLocation(FGeodeticCoord3D(newCenter_Geo, altitude));
		CenterEditPoint->SyncWorldLocationToGeoLocation();
	}

	double halfDiagonal_meters = cornerToCornerDist / 2.f;
	
	
	/* diagonalAngle_degrees is between [center horizontal line] and [center to 0], [center to 1], [center to 2], and [center to 3]; same angle for all of them
	*		so diagonalAngle_degrees + innerRectangleAngleDegrees = 90 
	* 
	*  3      0
	*  --------
	*  |\    /|
	*  | \  / |
	   |__\/__|
	*  |  /\  |
	*  | /  \ |
	*  --------
	*  2      1
	*/
	double diagonalAngle_degrees = 90 - innerRectangleAngleDegrees;
		
	
	double oppositeDegrees = 90 - diagonalAngle_degrees;

	/*
	* edit points are ordered:
	* 3 0
	* 2 1 
	* 
	* see comments for diagonalAngle_degrees and UGame_COTComponent_DrawRectangle::UpdateRectangleFromFields()
	*/
	double angles[4] { oppositeDegrees, 180 - oppositeDegrees, 180 + oppositeDegrees, 270 + diagonalAngle_degrees };

	/* manipulated point may need to be in different position in edit point array
	*
	*  for example: point 3 moved to the right of point 0; now point 3 should be at index 0 and point 0 should be at index 3
	*/
	int32 newManipulatedIndex = -1;
	for (int32 i = 0; i < PointsInShape; i++)
	{
		if (FMath::Abs<double>(uneditedCenterToManipulatedBearing - angles[i]) < 0.000001 || FMath::Abs<double>((uneditedCenterToManipulatedBearing + 360) - angles[i]) < 0.000001)
		{
			newManipulatedIndex = i;
			break;
		}
	}

	if (newManipulatedIndex == -1)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRectangle::UpdateRectangleShape | couldn't determine newManipulatedIndex | aborting"));

		return;
	}
		
	if (newManipulatedIndex != manipulatedIndex)
	{
		AGame_EditPoint* cached = editPoints[newManipulatedIndex];
		editPoints[newManipulatedIndex] = manipulatedPoint;
		editPoints[manipulatedIndex] = cached;

		Lines[line]->SetEditPoints(editPoints);
	}

	// don't adjust manipulated point and point opposite of manipulated point
	TArray<int32> ignoredIndices;
	ignoredIndices.Add(newManipulatedIndex);
	ignoredIndices.Add((newManipulatedIndex + 2) % 4);  

	UpdateRectangleFromFields(true, ignoredIndices);

	UpdateCuboidMesh();

	AttachPointsToCenter();
	AttachMeshToCenter();
}

void UGame_COTComponent_DrawRectangle::UpdateRectangleRotation(AGame_EditPoint_RectangleRotator* manipulatedPoint)
{
	// get index of point
	int32 manipulatedIndex = RotatorEditPoints.Find(manipulatedPoint);

	manipulatedPoint->SyncGeoLocationToWorldLocation();
	FGeodeticCoord3D manipulatedPointLocation = manipulatedPoint->GetGeoLocation();
	
	if (bFixCenterWhileRotating)
	{
		// find edge of manipulated point
		TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();

		FGeodeticCoord2D first = editPoints[manipulatedIndex]->GetGeoLocation().ToGeodeticCoord2D();
		FGeodeticCoord2D second = editPoints[(manipulatedIndex + 1) % PointsInShape]->GetGeoLocation().ToGeodeticCoord2D();
		double range = UVH_GlobeMathStatics::CalculateSurfaceDistance(first, second);
		double bearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(first, second);
		FGeodeticCoord2D edgeCenter = UVH_GlobeMathStatics::CalculateSurfaceDestination(first, bearing, range / 2);

		// get previous bearing
		FGeodeticCoord3D centerLocation = CenterEditPoint->GetGeoLocation();
		double previousBearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(centerLocation.ToGeodeticCoord2D(), edgeCenter);

		// get new bearing
		double newBearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(centerLocation.ToGeodeticCoord2D(), manipulatedPointLocation.ToGeodeticCoord2D());

		RotationInDegrees += (newBearing - previousBearing);
	}
	else
	{
		int32 spin = CalculateRectangleSpin();
		double originalRotatorBearing_Degrees = spin * 90 * manipulatedIndex + RotationInDegrees;

		double doubleDistToCenter;
		if (manipulatedIndex % 2 == 0)
		{
			doubleDistToCenter = WidthInMeters;
		}
		else
		{
			doubleDistToCenter = LengthInMeters;
		}

		// angle is rotator2-to-rotator0 bearing
		int32 oppositeRotatorIndex = manipulatedIndex + 2;
		if (oppositeRotatorIndex >= 4)
		{
			oppositeRotatorIndex -= 4;
		}

		FGeodeticCoord3D oppositeRotatorLocation = RotatorEditPoints[oppositeRotatorIndex]->GetGeoLocation();
		double manipulatedRotatorBearing_Degrees = UVH_GlobeMathStatics::CalculateSurfaceBearing(oppositeRotatorLocation.ToGeodeticCoord2D(), manipulatedPointLocation.ToGeodeticCoord2D());
		double diff_Degrees = manipulatedRotatorBearing_Degrees - originalRotatorBearing_Degrees;
		RotationInDegrees += diff_Degrees;

		// new center is doubleDistToCenter/2 distance at bearing 180-

		double manipOppBearing_Degrees = UVH_GlobeMathStatics::CalculateSurfaceBearing(manipulatedPointLocation.ToGeodeticCoord2D(), oppositeRotatorLocation.ToGeodeticCoord2D());
		double oppCenterBearing_Degrees = manipOppBearing_Degrees - 180;
		if (oppCenterBearing_Degrees < 0)
		{
			oppCenterBearing_Degrees += 360;
		}

		FGeodeticCoord2D newCenterLocation = UVH_GlobeMathStatics::CalculateSurfaceDestination(oppositeRotatorLocation.ToGeodeticCoord2D(), oppCenterBearing_Degrees, doubleDistToCenter / 2);
		CenterEditPoint->SetGeoLocation(FGeodeticCoord3D(newCenterLocation.Longitude, newCenterLocation.Latitude, CenterEditPoint->GetGeoLocation().Altitude));
	}

	if (RotationInDegrees >= 360)
	{
		RotationInDegrees -= 360;
	}

	if (RotationInDegrees < 0 )
	{
		RotationInDegrees += 360;
	}

	// apply that difference to both sets of points
	UpdateRectangleFromFields(true);

	UpdateCuboidMesh();
}

// ---------------------------------
// --- Implementation
// ---------------------------------

TArray<AGame_EditPoint*> UGame_COTComponent_DrawRectangle::GetRectangleEditPoints()
{
	TArray<AGame_EditPoint*> editPoints;

	if (Lines.Num() > 0)
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];
		if (line != nullptr)
		{
			editPoints = Lines[line]->GetEditPoints();
			return editPoints;
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRectangle::GetRectangleEditPoints | line is nullptr"));

	return editPoints;
}

void UGame_COTComponent_DrawRectangle::DetachPointsFromCenter()
{
	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();

	FDetachmentTransformRules detachmentRules(EDetachmentRule::KeepWorld, false);
	for (AGame_EditPoint* point : editPoints)
	{
		point->DetachFromActor(detachmentRules);
	}

	for(AGame_EditPoint_RectangleRotator* rotatorPoint : RotatorEditPoints)
	{
		rotatorPoint->DetachFromActor(detachmentRules);
	}
}

void UGame_COTComponent_DrawRectangle::AttachPointsToCenter()
{
	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();

	if (CenterEditPoint != nullptr)
	{
		FAttachmentTransformRules attachmentRules(EAttachmentRule::KeepWorld, false);
		for (AGame_EditPoint* point : editPoints)
		{
			point->AttachToActor(CenterEditPoint, attachmentRules);
		}

		for (AGame_EditPoint_RectangleRotator* rotatorPoint : RotatorEditPoints)
		{
			rotatorPoint->AttachToActor(CenterEditPoint, attachmentRules);
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawRectangle::AttachPointsToCenter() -- Center edit point was null."))
	}
}

void UGame_COTComponent_DrawRectangle::DetachMeshFromCenter()
{
	if (!CuboidMeshes.IsValidIndex(0))
	{
		return;
	}

	FDetachmentTransformRules detachRules(EDetachmentRule::KeepWorld, false);
	for (int32 cuboidMeshIndex = 0; cuboidMeshIndex < CuboidMeshes.Num(); cuboidMeshIndex++)
	{
		CuboidMeshes[cuboidMeshIndex]->DetachFromActor(detachRules);
	}
}

void UGame_COTComponent_DrawRectangle::AttachMeshToCenter()
{
	if (!CuboidMeshes.IsValidIndex(0))
	{
		return;
	}

	if (CenterEditPoint == nullptr)
	{
		return;
	}

	FAttachmentTransformRules attachmentRules(EAttachmentRule::KeepWorld, false);
	for (int32 cuboidMeshIndex = 0; cuboidMeshIndex < CuboidMeshes.Num(); cuboidMeshIndex++)
	{
		CuboidMeshes[cuboidMeshIndex]->AttachToActor(CenterEditPoint, attachmentRules);
	}
}

void UGame_COTComponent_DrawRectangle::SpawnCenterEditPoint(const FVector& location)
{
	// Only return an edit point if we made a new one.
	if (CenterEditPoint != nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRectangle::SpawnCenterEditPoint | CenterEditPoint already exists"));

		CenterEditPoint->Destroy();
		CenterEditPoint = nullptr;
	}

	FTransform spawnTransform = FTransform(FRotator(0, 0, 0), location, GetOwner()->GetActorScale3D());

	CenterEditPoint = GetWorld()->SpawnActorDeferred<AGame_EditPoint_Center>(CenterEditPointClass, spawnTransform, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	CenterEditPoint->SetDrawContainer(Cast<AGame_DrawContainer>(GetOwner()));

	UGameplayStatics::FinishSpawningActor(CenterEditPoint, spawnTransform);

	CenterEditPoint->SetActive(true);
	CenterEditPoint->SetLineActor(GetLines()[0]);
	CenterEditPoint->SyncGeoLocationToWorldLocation();
	CenterEditPoint->SetCallsign(TEXT("Rectangle"));

	CenterEditPoint->OnManipulationEnd.AddDynamic(this, &UGame_COTComponent_DrawRectangle::HandleManipulationEnd);
}

FGeodeticCoord3D UGame_COTComponent_DrawRectangle::CalculateCenterPoint(const TArray<AGame_EditPoint*>& editPoints)
{
	/* Explicitly ensure clean construction */
	FGeodeticCoord3D ret = FGeodeticCoord3D(0, 0, 0);

	/* We don't include the location of the 5th edit point; that will skew the average. */
	for (int32 pointIndex = 0; pointIndex < PointsInShape; pointIndex++)
	{
		if (editPoints.IsValidIndex(pointIndex))
		{
			FGeodeticCoord3D pointLoc = editPoints[pointIndex]->GetGeoLocation();
			ret.Latitude += pointLoc.Latitude;
			ret.Longitude += pointLoc.Longitude;
			ret.Altitude += pointLoc.Altitude;
		}
	}

	ret.Latitude = ret.Latitude / PointsInShape;
	ret.Longitude = ret.Longitude / PointsInShape;
	ret.Altitude = ret.Altitude / PointsInShape;

	return ret;
}

FGeodeticCoord3D UGame_COTComponent_DrawRectangle::CalculateCenterPoint(UVH_COTEvent* cotEvent)
{
	/* Explicitly ensure clean construction */
	FGeodeticCoord3D coordinate = FGeodeticCoord3D(0, 0, 0);

	if (cotEvent == nullptr)
	{
		return coordinate;
	}

	/* Find average coordinate location of the points in the links to get center point location */ 
	TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
	for (int32 linkIndex = 0; linkIndex < links.Num(); linkIndex++)
	{
		FGeodeticCoord3D linkCoordinate = UVH_COTStatics::LinkToCoordinate(links[linkIndex]);

		coordinate.Latitude += linkCoordinate.Latitude;
		coordinate.Longitude += linkCoordinate.Longitude;
		coordinate.Altitude += linkCoordinate.Altitude;
	}

	coordinate.Latitude = coordinate.Latitude / links.Num();
	coordinate.Longitude = coordinate.Longitude / links.Num();
	coordinate.Altitude = coordinate.Altitude / links.Num();

	return coordinate;
}

int32 UGame_COTComponent_DrawRectangle::CalculateRectangleSpin()
{
	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();
	FGeodeticCoord3D centerEditPoint_Geo = CenterEditPoint->GetGeoLocation();
	int spin = 1;
	double bearingPoint0 = UVH_GlobeMathStatics::CalculateSurfaceBearing(centerEditPoint_Geo.ToGeodeticCoord2D(), editPoints[0]->GetGeoLocation().ToGeodeticCoord2D());
	double bearingPoint1 = UVH_GlobeMathStatics::CalculateSurfaceBearing(centerEditPoint_Geo.ToGeodeticCoord2D(), editPoints[1]->GetGeoLocation().ToGeodeticCoord2D());
	double bearingPoint2 = UVH_GlobeMathStatics::CalculateSurfaceBearing(centerEditPoint_Geo.ToGeodeticCoord2D(), editPoints[2]->GetGeoLocation().ToGeodeticCoord2D());
	FVector cross = FVector::ZeroVector;
	if (bearingPoint0 < 270)
	{
		FVector centerTo0 = FVector(sin(bearingPoint0),
			cos(bearingPoint0),
			0.0);
		FVector centerTo1 = FVector(sin(bearingPoint1),
			cos(bearingPoint1),
			0.0);
		cross = FVector::CrossProduct(centerTo0, centerTo1);
	}
	else
	{
		FVector centerTo1 = FVector(sin(bearingPoint1),
			cos(bearingPoint1),
			0.0);
		FVector centerTo2 = FVector(sin(bearingPoint2),
			cos(bearingPoint2),
			0.0);
		cross = FVector::CrossProduct(centerTo1, centerTo2);
	}
	
	if (cross.Z <= 0)
	{
		spin = -1;
	}
	return spin;
}

AGame_Actor_Mesh* UGame_COTComponent_DrawRectangle::GetCuboidMesh(int32 index) const
{
	if (index < CuboidMeshes.Num())
	{
		return CuboidMeshes[index];
	}
	return nullptr;
}

void UGame_COTComponent_DrawRectangle::UpdateCuboidMesh()
{
	while (CuboidMeshes.Num() > Lines.Num())
	{
		CuboidMeshes.RemoveAt(CuboidMeshes.Num() - 1);
	}

	AVH_GlobeReferenceActor* globeReference = nullptr;
	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		globeReference = virtualObjective->GetGlobeReference();
	}

	if (globeReference == nullptr)
	{
		return;
	}

	TArray<int32> triIndexTriplets;
	TArray<FVector> quadVertices;
	TArray<AGame_SimpleSegmentedLineActor*> outKeys;
	Lines.GetKeys(outKeys);

	/* TODO: consider getting rid of this loop, since rectangle should only have one line... */
	for (int32 keysIndex = 0; keysIndex < outKeys.Num(); keysIndex++)
	{
		AGame_SimpleSegmentedLineActor* rectangleLine = outKeys[keysIndex];
		if (rectangleLine != nullptr)
		{
			quadVertices.Empty();

			bool newMesh = false;
			if (CuboidMeshes.Num() < keysIndex + 1)
			{
				/* Create mesh for given line if we haven't already */
				FTransform spawnTransform = FTransform::Identity;
				spawnTransform.SetLocation(CenterEditPoint->GetActorLocation());

				FActorSpawnParameters spawnParams;
				spawnParams.Owner = GetOwner();
				spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				AGame_Actor_Mesh* newMeshActor = GetWorld()->SpawnActor<AGame_Actor_Mesh>(CuboidFillActorClass, spawnTransform, spawnParams);
				CuboidMeshes.Add(newMeshActor);

				newMesh = true;
			}

			// Set vertex locations and create triangles to comprise the rectangle mesh
			if (CuboidMeshes[keysIndex] != nullptr)
			{
				CuboidMeshes[keysIndex]->SetActorScale3D(FVector::OneVector);

				TArray<AGame_EditPoint*> editPoints = Lines[rectangleLine]->GetEditPoints();

				TArray<int32> triangles;
				TArray<FVector> vertices;
				for (int32 lineVertexIndex = 0; lineVertexIndex < editPoints.Num(); lineVertexIndex++)
				{
					int32 nextIndex = lineVertexIndex + 1;
					if (nextIndex >= editPoints.Num())
					{
						nextIndex = 0;
					}
					quadVertices.SetNum(4, false);

					FVector currentWorldLocation = editPoints[lineVertexIndex]->GetActorLocation();
					FVector nextWorldLocation = editPoints[nextIndex]->GetActorLocation();

					quadVertices[0] = nextWorldLocation;
					FGeodeticCoord3D coordinate0 = globeReference->WorldToGeodeticDouble(nextWorldLocation);

					quadVertices[1] = currentWorldLocation;
					FGeodeticCoord3D coordinate1 = globeReference->WorldToGeodeticDouble(currentWorldLocation);

					coordinate0.Altitude += CuboidHeightMeters;
					coordinate1.Altitude += CuboidHeightMeters;

					quadVertices[2] = globeReference->GeodeticToWorldDouble(coordinate1);
					quadVertices[3] = globeReference->GeodeticToWorldDouble(coordinate0);

					int32 verticesOffset = vertices.Num();

					FVector centerWorldLocation = CenterEditPoint->GetActorLocation();
					vertices.Add(quadVertices[0] - centerWorldLocation);
					vertices.Add(quadVertices[1] - centerWorldLocation);
					vertices.Add(quadVertices[2] - centerWorldLocation);
					vertices.Add(quadVertices[3] - centerWorldLocation);

					const int32 numIndices = 6;
					triIndexTriplets.SetNum(numIndices, false);
					triIndexTriplets[0] = 3;
					triIndexTriplets[1] = 0;
					triIndexTriplets[2] = 2;

					triIndexTriplets[3] = 2;
					triIndexTriplets[4] = 0;
					triIndexTriplets[5] = 1;

					for (int32 triIndex = 0; triIndex < numIndices; triIndex += 3)
					{
						triangles.Add(verticesOffset + triIndexTriplets[triIndex]);
						triangles.Add(verticesOffset + triIndexTriplets[triIndex + 1]);
						triangles.Add(verticesOffset + triIndexTriplets[triIndex + 2]);
					}
				}

				// always draw mesh on bottom of rectangle
				int32 numVertices = vertices.Num();
				FVector centerLocation = CenterEditPoint->GetActorLocation();

				TArray<FVector2D> polygon2D;
				for (AGame_EditPoint* editPoint : editPoints)
				{
					FVector editPointLocation = editPoint->GetActorLocation();

					FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(editPointLocation);
					polygon2D.Add(FVector2D(coordinate.Longitude * 1000000, coordinate.Latitude * 1000000));  // multiplier to space apart verts for TriangulatePolygon algorithm

					vertices.Add(editPointLocation - centerLocation);
				}

				bool bWindsClockwise = false;
				TArray<int32> bottomTriangles;
				if (UDeveloper_Statics::TriangulatePolygon(polygon2D, bottomTriangles, bWindsClockwise))
				{
					for (int32& triangle : bottomTriangles)
					{
						triangle += numVertices;
					}

					triangles.Append(bottomTriangles);
				}

				// Set color of mesh material 
				UMaterialInstanceDynamic* dynMaterial = Cast<UMaterialInstanceDynamic>(CuboidMeshes[keysIndex]->ProceduralMesh->GetMaterial(0));

				if (dynMaterial == nullptr)
				{
					dynMaterial = UMaterialInstanceDynamic::Create(CuboidFillMaterial, GetOwner(), TEXT(""));
				}

				if (dynMaterial != nullptr)
				{
					dynMaterial->SetVectorParameterValue(FName(TEXT("Color")), MeshStyleColor);
				}

				CuboidMeshes[keysIndex]->BuildMeshFromVerticesAndTriangles(vertices, triangles, dynMaterial);
				
				CuboidMeshes[keysIndex]->AttachToActor(CenterEditPoint, FAttachmentTransformRules::KeepWorldTransform);
				CuboidMeshes[keysIndex]->SetActorRelativeLocation(FVector::ZeroVector, false);
			}
		}
	}
}

void UGame_COTComponent_DrawRectangle::CalculateRectangleLengthWidthRotation(UVH_COTEvent* cotEvent, float& lengthMeters, float& widthMeters, float& rotationDegrees)
{
	double length = 0;
	double width = 0;
	double rotation = 0;

	UVH_COTStatics::CalculateRectangleAttributesAsDoubles(cotEvent, cotEvent->GetPoint(), length, width, rotation);

	lengthMeters = (float)length;
	widthMeters = (float)width;
	rotationDegrees = (float)rotation;
}


// ---------------------------------
// --- Events/Handlers
// ---------------------------------

void UGame_COTComponent_DrawRectangle::HandleManipulationBegin(AActor* manipulatedActor)
{
	// not called for center

	AGame_SimpleSegmentedLineActor* line = GetLines()[0];
	line->SetActorEnableCollision(false);

	// temporarily disable actor collision to avoid issues
	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();
	for (AGame_EditPoint* editPoint : editPoints)
	{
		if (editPoint->GetActive())
		{
			editPoint->SetActorEnableCollision(false);
		}
	}

	for(AGame_EditPoint_RectangleRotator* rotatorPoint : RotatorEditPoints)
	{
		if (rotatorPoint->GetActive())
		{
			rotatorPoint->SetActorEnableCollision(false);
		}
	}

	CenterEditPoint->SetActorEnableCollision(false);
}

void UGame_COTComponent_DrawRectangle::HandleManipulationInProgress(AActor* manipulatedActor)
{
	// not called for center

	if (AGame_EditPoint_RectangleRotator* editPointRotator = Cast<AGame_EditPoint_RectangleRotator>(manipulatedActor))
	{
		UpdateRectangleRotation(editPointRotator);

		return;
	}

	if (AGame_EditPoint* editPoint = Cast<AGame_EditPoint>(manipulatedActor))
	{
		UpdateRectangleShape(editPoint);
	}
}

void UGame_COTComponent_DrawRectangle::HandleRotatorManipulationEnd(AActor* manipulatedActor)
{
	UpdateRectangleFromFields(true);
	HandleManipulationEnd(manipulatedActor);
}

void UGame_COTComponent_DrawRectangle::HandleManipulationEnd(AActor* manipulatedActor)
{
	// called for center and attached

	AGame_SimpleSegmentedLineActor* line = GetLines()[0];
	line->SetActorEnableCollision(true);

	TArray<AGame_EditPoint*> editPoints = GetRectangleEditPoints();
	for (AGame_EditPoint* editPoint : editPoints)
	{
		if (editPoint->GetActive())
		{
			editPoint->SetActorEnableCollision(true);
		}
	}

	for (AGame_EditPoint_RectangleRotator* rotatorPoint : RotatorEditPoints)
	{
		if (rotatorPoint->GetActive())
		{
			rotatorPoint->SetActorEnableCollision(true);
		}
	}

	CenterEditPoint->SetActorEnableCollision(true);

	if (manipulatedActor == CenterEditPoint)
	{
		// center point moved, which moves attached edit points
		// update attached edit points geolocations
		for (AGame_EditPoint* editPoint : editPoints)
		{
			editPoint->SyncGeoLocationToWorldLocation();
		}

		for (AGame_EditPoint_RectangleRotator* rotatorPoint : RotatorEditPoints)
		{
			rotatorPoint->SyncGeoLocationToWorldLocation();
		}
	}

	PostManipulationEnd(manipulatedActor);

	RegisterWithDatabase();
}

void UGame_COTComponent_DrawRectangle::HandleLineColorChanged(FLinearColor inColor)
{
	FColor colorReceived = inColor.ToFColor(true);

	MeshStyleColor = FColor(colorReceived.R, colorReceived.G, colorReceived.B, MeshStyleAlpha);

	UVH_COTEvent* cotEvent = GetCurrentCOTEvent();
	cotEvent->SetAttribute(TEXT("detail\tcolor\tvalue"), UVH_COTStatics::ColorToHexAttribute(MeshStyleColor));
	cotEvent->SetAttribute(TEXT("fillColor"), UVH_COTStatics::ColorToHexAttribute(MeshStyleColor));
	
	for (AGame_Actor_Mesh* cuboidMeshes : CuboidMeshes)
	{
		if (cuboidMeshes != nullptr)
		{
			if (UMaterialInstanceDynamic* material = Cast<UMaterialInstanceDynamic>(cuboidMeshes->ProceduralMesh->GetMaterial(0)))
			{
				material->SetVectorParameterValue(FName(TEXT("Color")), MeshStyleColor);
			}
		}
	}
}