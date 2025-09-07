// Required Includes
#include "Game_COTComponent_DrawCircle.h"
#include "Game.h"

// Engine Includes
#include "Kismet/KismetMathLibrary.h"
#include "ProceduralMeshComponent.h"
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/GameplayStatics.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_Actor_Mesh.h"
#include "Game_VirtualObjective.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_EditPoint.h"
#include "Game_Arrow.h"
#include "Game_DrawLineData.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Statics.h"
#include "Game_COTManager.h"
#include "Game_CircleLine.h"
#include "Game_PlayerState.h"
#include "Game_DrawContainer.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawCircle::UGame_COTComponent_DrawCircle() :
	CylinderFillActorClass(AGame_Actor_Mesh::StaticClass()),
	PointsToRadiusRatioUU(2),
	LineColor(FColor(255, 255, 255, 255)),
	PolyColor(FColor(255, 255, 255, 255)),
	StyleWidth(3),
	CylinderHeight(0.0f)
{
	bGenerateCallsign = false;
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

double UGame_COTComponent_DrawCircle::GetRadius(UVH_COTEvent* cotEvent)
{
	TArray<FXmlNode*> ellipses = cotEvent->GetNodes(TEXT("detail\tshape\tellipse"));
	if (ellipses.Num() > 0)
	{
		double minor = FCString::Atod(*ellipses[0]->GetAttribute(TEXT("minor")));
		double major = FCString::Atod(*ellipses[0]->GetAttribute(TEXT("major")));

		return FMath::Max<double>(minor, major);
	}

	return 0;
}

void UGame_COTComponent_DrawCircle::SetRadius(UVH_COTEvent* cotEvent, double radius)
{
	TArray<FXmlNode*> ellipses = cotEvent->GetNodes(TEXT("detail\tshape\tellipse"));
	for (int32 i = 0; i < ellipses.Num(); i++)
	{
		ellipses[i]->SetAttribute(TEXT("minor"), FString::Printf(TEXT("%f"), radius * (i + 1)));
		ellipses[i]->SetAttribute(TEXT("major"), FString::Printf(TEXT("%f"), radius * (i + 1)));
	}
}

int32 UGame_COTComponent_DrawCircle::GetNumberEllipses(UVH_COTEvent* cotEvent)
{
	TArray<FXmlNode*> ellipses = cotEvent->GetNodes(TEXT("detail\tshape\tellipse"));

	return ellipses.Num();
}

void UGame_COTComponent_DrawCircle::SetNumberEllipses(UVH_COTEvent* cotEvent, int32 ellipses)
{
	double radius = GetRadius(cotEvent);

	cotEvent->RemoveNodes(TEXT("detail\tshape\tellipse"));

	ellipses = FMath::Max(ellipses, 1);
	for (int32 i = 0; i < ellipses; i++)
	{
		TArray<FXmlAttribute> attributes;
		attributes.Add(FXmlAttribute(TEXT("minor"), FString::Printf(TEXT("%f"), radius * (i + 1))));
		attributes.Add(FXmlAttribute(TEXT("major"), FString::Printf(TEXT("%f"), radius * (i + 1))));
		attributes.Add(FXmlAttribute(TEXT("angle"), TEXT("360")));

		cotEvent->AddNode(TEXT("detail\tshape\tellipse"), attributes);
	}
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawCircle::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	if (Arrow != nullptr)
	{
		Arrow->Destroy();
	}

	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->Destroy();
	}

	if (IsValid(CylinderMesh))
	{
		CylinderMesh->Destroy();
		CylinderMesh = nullptr;
	}

	for (AGame_SimpleSegmentedLineActor* topLine : TopLines)
	{
		topLine->Destroy();
	}
	TopLines.Empty();
}

void UGame_COTComponent_DrawCircle::SnapToGround()
{
	if (ShouldSnapEditPoint(CenterEditPoint))
	{
		UGame_Statics::SnapToGround(CenterEditPoint);
	}
}

bool UGame_COTComponent_DrawCircle::ShouldSnapEditPoint(AGame_EditPoint* editPoint) const
{
	// We snap only the center edit point to ground if it has height 9999999.0. Others should follow because of attachment.
	return editPoint == CenterEditPoint && Super::ShouldSnapEditPoint(editPoint);
}

TArray<FVector> UGame_COTComponent_DrawCircle::PreModifyVOGlobeReference()
{
	TArray<FVector> positions = Super::PreModifyVOGlobeReference();
	
	if (CenterEditPoint != nullptr)
	{
		positions.Add(CenterEditPoint->GetActorLocation());
	}

	return positions;
}

void UGame_COTComponent_DrawCircle::PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions)
{
	DetachEditPointsFromCenter();
	DetachCylindersFromCenter();

	Super::PostModifyVOGlobeReference(updatedPositions);

	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->SetActorLocation(updatedPositions.Last());
	}

	if (IsValid(CylinderMesh))
	{
		CylinderMesh->SetActorLocation(updatedPositions.Last());
	}
	
	AttachEditPointsToCenter();
	AttachCylindersToCenter();

	SyncCylinderMesh();
}

void UGame_COTComponent_DrawCircle::HandleOwnerSetScale3D(const FVector& scale3D)
{
	DetachEditPointsFromCenter();

	Super::HandleOwnerSetScale3D(scale3D);

	if (CenterEditPoint != nullptr)
	{
		FVector oldScale = CenterEditPoint->GetActorScale3D();
		CenterEditPoint->SetActorScale3D(scale3D);
	}

	AttachEditPointsToCenter();

	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		AGame_CircleLine* gameLine = Cast<AGame_CircleLine>(entry.Key);
		if (gameLine != nullptr)
		{
			gameLine->OnEditPointsUpdated.Broadcast();
		}
	}

	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UGame_COTComponent_DrawCircle::SyncPerimeterEditPoints);
}

void UGame_COTComponent_DrawCircle::HandleOwnerSetHidden(bool bNewHidden)
{
	Super::HandleOwnerSetHidden(bNewHidden);

	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->SetActorHiddenInGame(bNewHidden);
	}
}

void UGame_COTComponent_DrawCircle::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();

		FGeodeticCoord3D coordinate = cotEvent->GetPoint();

		FVector worldLocation = globeReference->GeodeticToWorldDouble(coordinate);
		if (CenterEditPoint == nullptr)
		{
			SpawnCenterEditPoint(worldLocation);
		}

		CenterEditPoint->SetCallsign(cotEvent->GetAttribute(TEXT("callsign")));
		CenterEditPoint->SetGeoLocation(coordinate);
		CenterEditPoint->SyncWorldLocationToGeoLocation();

		CylinderHeight = cotEvent->GetAttribute<double>(TEXT("detail\theight\tvalue"));
		
		TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("detail\tshape\tlink"));
		if (links.Num() > 0)
		{
			FXmlNode* link = links[0];

			LineColor = UVH_COTStatics::FromHex(cotEvent->GetNodeContent(TEXT("detail\tshape\tlink\tStyle\tLineStyle\tcolor")));
			LineColor.A = 255;

			PolyColor = UVH_COTStatics::FromHex(cotEvent->GetNodeContent(TEXT("detail\tshape\tlink\tStyle\tPolyStyle\tcolor")));

			StyleWidth = cotEvent->GetAttribute<double>(TEXT("detail\tshape\tlink\tStyle\tLineStyle\twidth"));

			for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
			{
				entry.Key->Destroy();
			}
			Lines.Empty();
					
			TArray<FXmlNode*> ellipses = cotEvent->GetNodes(TEXT("detail\tshape\tellipse"));
			for (int32 i = 0; i < ellipses.Num(); i++)
			{
				AGame_SimpleSegmentedLineActor* lineActor = SpawnCircleLine();
				lineActor->SetActorRotation(FRotator(0, FCString::Atod(*ellipses[i]->GetAttribute(TEXT("angle"))), 0));

				double minor = FCString::Atod(*ellipses[i]->GetAttribute(TEXT("minor")));
				double major = FCString::Atod(*ellipses[i]->GetAttribute(TEXT("major")));

				if (i == 0)
				{
					MinorRadius_Meters = minor;
					MajorRadius_Meters = major;
				}
				else
				{
					MinorRadius_Meters = FMath::Min(MinorRadius_Meters, minor);
					MajorRadius_Meters = FMath::Min(MajorRadius_Meters, major);
				}
			}
		}

		SyncPerimeterEditPoints();

		SyncColors();
	}
}

void UGame_COTComponent_DrawCircle::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (Lines.Num() < 1 || Lines.Num() > 10)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawCircle::PopulateCOT_Virtual | less than 1 line or more than 10 | %d | aborting"), Lines.Num());
		return;
	}

	if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-c-c"));
		cotEvent->SetPoint(CenterEditPoint->GetGeoLocation());
		cotEvent->PopulateTime(ActiveTime);

		if (CenterEditPoint->GetCallsign().IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("callsign"), TEXT("Circle"));
		}
		else
		{
			cotEvent->SetAttribute(TEXT("callsign"), CenterEditPoint->GetCallsign());
		}

		FColor lineWithAlpha = LineColor;
		lineWithAlpha.A = PolyColor.A;
		cotEvent->SetAttribute(TEXT("fillColor"), UVH_COTStatics::ColorToHexAttribute(lineWithAlpha));
		cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), LineColor);
		cotEvent->SetAttribute<FColor>(TEXT("detail\tcolor\tvalue"), LineColor);
		cotEvent->SetAttribute<FColor>(TEXT("detail\tcolor\targb"), LineColor);
		
		cotEvent->SetAttribute<double>(TEXT("detail\theight\tvalue"), CylinderHeight);
		cotEvent->AddNode(TEXT("detail\theight_unit"), true, TEXT("1")); // meters

		cotEvent->RemoveNodes(TEXT("detail\tshape\tellipse"));

		for (int32 lineIndex = 0; lineIndex < Lines.Num(); lineIndex++)
		{
			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("minor"), FString::Printf(TEXT("%f"), MinorRadius_Meters * (lineIndex + 1))));
			attributes.Add(FXmlAttribute(TEXT("angle"), TEXT("360")));
			attributes.Add(FXmlAttribute(TEXT("major"), FString::Printf(TEXT("%f"), MajorRadius_Meters * (lineIndex + 1))));

			cotEvent->AddNode(TEXT("detail\tshape\tellipse"), attributes);
		}

		cotEvent->SetAttribute(TEXT("detail\tshape\tlink\trelation"), TEXT("p-c"));
		cotEvent->SetAttribute(TEXT("detail\tshape\tlink\tuid"), cotEvent->GetAttribute(TEXT("uid")));
		cotEvent->SetAttribute(TEXT("detail\tshape\tlink\ttype"), TEXT("b-x-KmlStyle"));

		cotEvent->AddNode(TEXT("detail\tshape\tlink\tStyle\tLineStyle\tcolor"), TArray<FXmlAttribute>(), true, UVH_COTStatics::ToHex(LineColor));
		
		cotEvent->AddNode(TEXT("detail\tshape\tlink\tStyle\tLineStyle\twidth"), TArray<FXmlAttribute>(), true, TEXT("3"));  // todo ohg | always 3?
		cotEvent->AddNode(TEXT("detail\tshape\tlink\tStyle\tLineStyle\talpha"), TArray<FXmlAttribute>(), true, FString::Printf(TEXT("%d"), PolyColor.A));

		cotEvent->AddNode(TEXT("detail\tshape\tlink\tStyle\tPolyStyle\tcolor"), TArray<FXmlAttribute>(), true, UVH_COTStatics::ToHex(PolyColor));

		cotEvent->SetPoint(CenterEditPoint->GetGeoLocation());
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_COTComponent_DrawCircle::SpawnDrawElements(const FVector& editPointLocation, const FLinearColor& inColor)
{
	SpawnArrow(editPointLocation);
	SpawnCenterEditPoint(editPointLocation);
	SpawnCircleLine();

	SyncPerimeterEditPoints();

	LineColor = inColor.ToFColor(true);
	PolyColor = LineColor;
		
	SyncColors();
}

AGame_Arrow* UGame_COTComponent_DrawCircle::GetArrow() const
{
	return Arrow;
}

void UGame_COTComponent_DrawCircle::SetPolyAlpha(uint8 inMeshAlpha)
{
	PolyColor.A = inMeshAlpha;

	SyncColors();
}

AGame_EditPoint_Center* UGame_COTComponent_DrawCircle::GetCenterEditPoint() const
{
	return CenterEditPoint;
}

float UGame_COTComponent_DrawCircle::GetMinorRadius() const
{
	return MinorRadius_Meters;
}

void UGame_COTComponent_DrawCircle::SyncPerimeterEditPoints()
{
	double unitsPerMeter = 100;
	float minorRadius_UU = 0;
	float majorRadius_UU = 0;

	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		unitsPerMeter = virtualObjective->GetActorScale3D().X * 100.f;
	}

	if (Arrow != nullptr && !Arrow->IsHidden())
	{
		minorRadius_UU = (Arrow->GetArrowEditPoint()->GetActorLocation() - Arrow->GetBaseEditPoint()->GetActorLocation()).Size();
		majorRadius_UU = minorRadius_UU;

		// Default use is making circles. Ellipsis manufacturing would be done in details pane.
		MinorRadius_Meters = minorRadius_UU / unitsPerMeter;
		MajorRadius_Meters = MinorRadius_Meters;
	}
	else
	{
		minorRadius_UU = MinorRadius_Meters * unitsPerMeter;
		majorRadius_UU = MajorRadius_Meters * unitsPerMeter;
	}

	if (minorRadius_UU != 0.0 && majorRadius_UU != 0.0)
	{
		// increase PointsToRadiusRatioUU based on minorRadius_UU
		double circumferenceUU = PI * minorRadius_UU * 2;
		
		PointsToRadiusRatioUU = FMath::Max<float>(10, FMath::RoundToInt32(circumferenceUU / 100.f));

		TArray<AGame_SimpleSegmentedLineActor*> outKeys;
		Lines.GetKeys(outKeys);

		for (int32 keysIndex = 0; keysIndex < outKeys.Num(); keysIndex++)
		{
			AGame_SimpleSegmentedLineActor* currentLine = outKeys[keysIndex];
			if (currentLine != nullptr)
			{
				if (CenterEditPoint != nullptr && minorRadius_UU > 0.0)
				{
					int32 newPointCount = FMath::FloorToInt(circumferenceUU / PointsToRadiusRatioUU);
					float newPerimeter = circumferenceUU;

					if (!FMath::IsNearlyEqual(Perimeter_UU, newPerimeter) || newPointCount != Lines[currentLine]->GetEditPoints().Num())
					{
						// If there are more EditPoints than we now need, get rid of them.
						for (int32 editPointsIndex = Lines[currentLine]->GetEditPoints().Num() - 1; editPointsIndex >= newPointCount; editPointsIndex--)
						{
							DeleteEditPoint(currentLine, Lines[currentLine]->GetEditPoints()[editPointsIndex]);
						}

						// todo: calculate an ellipse rather than a circle if we ever support those.
						for (int32 newEditPointsIndex = 0; newEditPointsIndex < newPointCount; newEditPointsIndex++)
						{
							float angleInRadians = 0;
							if (newPointCount > 1)
							{
								angleInRadians = newEditPointsIndex * (2 * PI) / (newPointCount - 1);
							}
							
							FVector location
							{
								FMath::Sin(angleInRadians) * minorRadius_UU * (keysIndex + 1),
								FMath::Cos(angleInRadians) * minorRadius_UU * (keysIndex + 1),
								0
							};
							
							location = UGame_Statics::GetWorldTransformOverride(CenterEditPoint->GetActorLocation()).Rotator().RotateVector(location);
							location += CenterEditPoint->GetActorLocation();

							if (newEditPointsIndex >= currentLine->LinePoints.Num())
							{
								AGame_EditPoint* newEditPoint = SpawnEditPoint(currentLine, location, nullptr);
								newEditPoint->SetActive(false);
								newEditPoint->SyncGeoLocationToWorldLocation();

								currentLine->AddLocationAndGeoLocation(newEditPoint->GetActorLocation(), newEditPoint->GetGeoLocation());

								FAttachmentTransformRules attachmentRules(EAttachmentRule::KeepWorld, false);
								newEditPoint->AttachToActor(CenterEditPoint, attachmentRules);
							}
							else
							{
								Lines[currentLine]->MoveEditPoint(location, newEditPointsIndex);
							}
						}

						Perimeter_UU = newPerimeter;
					}
				}

				AGame_CircleLine* circleLine = Cast<AGame_CircleLine>(currentLine);
				if (circleLine != nullptr)
				{
					// todo: support ellipses
					circleLine->SetMajorRadius(MinorRadius_Meters * (keysIndex + 1));
					circleLine->SetMinorRadius(MinorRadius_Meters * (keysIndex + 1));
					circleLine->OnEditPointsUpdated.Broadcast();
				}
			}
		}

		SyncCylinderMesh();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_COTComponent_DrawCircle::SyncCylinderMesh()
{
	if (IsValid(CylinderMesh))
	{
		CylinderMesh->Destroy();
	}
	CylinderMesh = nullptr;

	for (AGame_SimpleSegmentedLineActor* topLine : TopLines)
	{
		topLine->Destroy();
	}
	TopLines.Empty();

	AVH_GlobeReferenceActor* globeReference = nullptr;
	if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(GetOwner()))
	{
		globeReference = virtualObjective->GetGlobeReference();
	}
	
	if (globeReference == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawCircle::SyncCylinderMesh | globeReference is nullptr | aborting"));

		return;
	}

	// find outer circle and add lines for top of cylinder
	double maxRadius = 0;
	TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*> maxEntry = { nullptr, nullptr };
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		TArray<AGame_EditPoint*> editPoints = entry.Value->GetEditPoints();

		// find outer circle
		double radius = (editPoints[0]->GetActorLocation() - CenterEditPoint->GetActorLocation()).Size();
		if (radius > maxRadius)
		{
			maxRadius = radius;
			maxEntry.Key = entry.Key;
			maxEntry.Value = entry.Value;
		}

		if (CylinderHeight > 0)
		{
			// add lines for top of cylinder
			FTransform spawnTransform = FTransform(FRotator(0, 0, 0), FVector(0, 0, 0), GetOwner()->GetActorScale3D());

			AGame_SimpleSegmentedLineActor* topLine = Cast<AGame_SimpleSegmentedLineActor>(GetWorld()->SpawnActorDeferred<AGame_SimpleSegmentedLineActor>(LineClass, spawnTransform, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn));
			topLine->SetDrawContainer(Cast<AGame_DrawContainer>(GetOwner()));

			UGameplayStatics::FinishSpawningActor(topLine, spawnTransform);
			
			for (AGame_EditPoint* editPoint : editPoints)
			{
				FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(editPoint->GetActorLocation());
				coordinate.Altitude += CylinderHeight;

				FVector worldLocation = globeReference->GeodeticToWorldDouble(coordinate);

				topLine->AddLocationAndGeoLocation(worldLocation, coordinate);
			}

			topLine->SetColor(LineColor);

			TopLines.Add(topLine);
		}
	}

	TArray<AGame_EditPoint*> editPoints = maxEntry.Value->GetEditPoints();
	
	// 0 height cylinder mesh has triangles for bottom
	// > 0 height cylinder mesh has triangles for bottom, side, and top
	
	TArray<int32> triangles;
	TArray<FVector> vertices;

	// add triangles for side of cylinder
	if (CylinderHeight > 0)
	{
		TArray<int32> triIndexTriplets;
		TArray<FVector> quadVertices;

		quadVertices.Empty();

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

			coordinate0.Altitude += CylinderHeight;
			coordinate1.Altitude += CylinderHeight;

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

		// add triangles for top of cylinder
		int32 numVertices = vertices.Num();
		FVector centerLocation = CenterEditPoint->GetActorLocation();

		TArray<FVector2D> topPolygon2D;
		for (int32 i = 0; i < editPoints.Num() - 1; i++)  // don't add last editPoint as it overlaps first
		{
			FVector editPointLocation = editPoints[i]->GetActorLocation();

			FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(editPointLocation);
			coordinate.Altitude += CylinderHeight;
			
			topPolygon2D.Add(FVector2D(coordinate.Longitude * 1000000, coordinate.Latitude * 1000000));  // multiplier to space apart verts for TriangulatePolygon algorithm

			vertices.Add(globeReference->GeodeticToWorldDouble(coordinate) - centerLocation);
		}

		bool bWindsClockwise = false;
		TArray<int32> topTriangles;
		if (UDeveloper_Statics::TriangulatePolygon(topPolygon2D, topTriangles, bWindsClockwise))
		{
			for (int32& triangle : topTriangles)
			{
				triangle += numVertices;
			}

			triangles.Append(topTriangles);
		}
	}

	// add triangles for bottom of cylinder
	int32 numVertices = vertices.Num();
	FVector centerLocation = CenterEditPoint->GetActorLocation();

	TArray<FVector2D> bottomPolygon2D;
	for (int32 i = 0; i < editPoints.Num() - 1; i++)  // don't add last editPoint as it overlaps first
	{
		FVector editPointLocation = editPoints[i]->GetActorLocation();

		FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(editPointLocation);
		bottomPolygon2D.Add(FVector2D(coordinate.Longitude * 1000000, coordinate.Latitude * 1000000));  // multiplier to space apart verts for TriangulatePolygon algorithm

		vertices.Add(editPointLocation - centerLocation);
	}

	bool bWindsClockwise = false;
	TArray<int32> bottomTriangles;
	if (UDeveloper_Statics::TriangulatePolygon(bottomPolygon2D, bottomTriangles, bWindsClockwise))
	{
		for (int32& triangle : bottomTriangles)
		{
			triangle += numVertices;
		}

		triangles.Append(bottomTriangles);
	}

	FTransform spawnTransform = FTransform::Identity;
	spawnTransform.SetLocation(CenterEditPoint->GetActorLocation());

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = GetOwner();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	CylinderMesh = GetWorld()->SpawnActor<AGame_Actor_Mesh>(CylinderFillActorClass, spawnTransform, spawnParams);

	UMaterialInstanceDynamic* dynMaterial = Cast<UMaterialInstanceDynamic>(CylinderMesh->ProceduralMesh->GetMaterial(0));

	if (dynMaterial == nullptr)
	{
		dynMaterial = UMaterialInstanceDynamic::Create(CylinderFillMaterial, GetOwner(), TEXT(""));
	}

	if (dynMaterial != nullptr)
	{
		dynMaterial->SetVectorParameterValue(FName(TEXT("Color")), PolyColor);
	}

	CylinderMesh->BuildMeshFromVerticesAndTriangles(vertices, triangles, dynMaterial);
				
	CylinderMesh->AttachToActor(CenterEditPoint, FAttachmentTransformRules::KeepWorldTransform);
	CylinderMesh->SetActorRelativeLocation(FVector::ZeroVector, false);
}

void UGame_COTComponent_DrawCircle::SyncColors()
{
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		AGame_SimpleSegmentedLineActor* currentLine = entry.Key;
		
		if (currentLine->GetColor() != LineColor)
		{
			currentLine->SetColor(LineColor);
		}
	}

	for (AGame_SimpleSegmentedLineActor* topLine : TopLines)
	{
		topLine->SetColor(LineColor);
	}

	if (IsValid(CylinderMesh))
	{
		if (UMaterialInstanceDynamic* dynMaterial = Cast<UMaterialInstanceDynamic>(CylinderMesh->ProceduralMesh->GetMaterial(0)))
		{
			dynMaterial->SetVectorParameterValue(FName("Color"), PolyColor);
		}
	}

	if (CenterEditPoint != nullptr)
	{
		CenterEditPoint->SetColor(LineColor);
	}
}

AGame_Arrow* UGame_COTComponent_DrawCircle::SpawnArrow(const FVector& editPointLocation)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = GetOwner();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	Arrow = Cast<AGame_Arrow>(GetWorld()->SpawnActor<AGame_Arrow>(ArrowClass, editPointLocation, FRotator(0, 0, 0), spawnParams));

	AGame_EditPoint* baseEditPoint = Arrow->GetBaseEditPoint();
	AGame_EditPoint* arrowEditPoint = Arrow->GetArrowEditPoint();
	AGame_DrawContainer* drawContainer = Cast<AGame_DrawContainer>(GetOwner());

	baseEditPoint->SetDrawContainer(drawContainer);
	baseEditPoint->SyncGeoLocationToWorldLocation();

	arrowEditPoint->SetDrawContainer(drawContainer);
	arrowEditPoint->SyncGeoLocationToWorldLocation();

	Arrow->GetLine()->SetDrawContainer(drawContainer);
	
	Arrow->GetLine()->SetCollision(false);
	Arrow->SetActorEnableCollision(false);

	return Arrow;
}

AGame_EditPoint* UGame_COTComponent_DrawCircle::SpawnCenterEditPoint(const FVector& location)
{
	// Only return an edit point if we made a new one.
	if (CenterEditPoint != nullptr)
	{
		return nullptr;
	}

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	spawnParams.Owner = GetOwner();

	AGame_EditPoint_Center* editPoint = GetWorld()->SpawnActor<AGame_EditPoint_Center>(CenterEditPointClass, location, FRotator(0, 0, 0), spawnParams);
	editPoint->SetActorScale3D(GetOwner()->GetActorScale3D());
	editPoint->SetActive(true);
	editPoint->DrawContainer = Cast<AGame_DrawContainer>(GetOwner());
	editPoint->SyncGeoLocationToWorldLocation();
	editPoint->SetCallsign("Circle");
	editPoint->OnManipulationBegin.AddDynamic(this, &UGame_COTComponent_DrawCircle::HandleManipulationBegin);
	editPoint->OnManipulationEnd.AddDynamic(this, &UGame_COTComponent_DrawCircle::HandleManipulationEnd);

	CenterEditPoint = editPoint;
	return CenterEditPoint;
}

AGame_SimpleSegmentedLineActor* UGame_COTComponent_DrawCircle::SpawnCircleLine()
{
	AGame_SimpleSegmentedLineActor* line = SpawnLine();

	if (CenterEditPoint != nullptr && CenterEditPoint->GetLineActor() == nullptr)
	{
		/* Set center edit point line actor to first line spawned */
		CenterEditPoint->SetLineActor(line);
	}

	line->SetDrawContainer(Cast<AGame_DrawContainer>(GetOwner()));
	line->OnColorChanged.AddDynamic(this, &UGame_COTComponent_DrawCircle::HandleLineColorChanged);

	return line;
}

void UGame_COTComponent_DrawCircle::DetachEditPointsFromCenter()
{
	FDetachmentTransformRules detachRules(EDetachmentRule::KeepWorld, false);
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		TArray<AGame_EditPoint*> editPoints = entry.Value->GetEditPoints();
		for (int32 editPointIndex = 0; editPointIndex < editPoints.Num(); editPointIndex++)
		{
			editPoints[editPointIndex]->DetachFromActor(detachRules);
		}
	}
}

void UGame_COTComponent_DrawCircle::DetachCylindersFromCenter()
{
	if (IsValid(CylinderMesh))
	{
		FDetachmentTransformRules detachRules(EDetachmentRule::KeepWorld, false);
	
		CylinderMesh->DetachFromActor(detachRules);
	}
}

void UGame_COTComponent_DrawCircle::AttachEditPointsToCenter()
{
	FAttachmentTransformRules attachmentRules(EAttachmentRule::KeepWorld, false);
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		TArray<AGame_EditPoint*> editPoints = entry.Value->GetEditPoints();
		for (int32 editPointIndex = 0; editPointIndex < editPoints.Num(); editPointIndex++)
		{
			editPoints[editPointIndex]->AttachToActor(CenterEditPoint, attachmentRules);
		}
	}

	if (IsValid(CylinderMesh))
	{
		CylinderMesh->AttachToActor(CenterEditPoint, attachmentRules);
	}
}

void UGame_COTComponent_DrawCircle::AttachCylindersToCenter()
{
	if (IsValid(CylinderMesh))
	{
		FAttachmentTransformRules attachmentRules(EAttachmentRule::KeepWorld, false);

		CylinderMesh->AttachToActor(CenterEditPoint, attachmentRules);
	}
}

// ---------------------------------
// --- Events/Handlers
// ---------------------------------

void UGame_COTComponent_DrawCircle::HandleLineColorChanged(FLinearColor inColor)
{
	LineColor = inColor.ToFColor(true);
	
	int32 polyAlpha = PolyColor.A;
	PolyColor = LineColor;
	PolyColor.A = polyAlpha;

	UVH_COTEvent* cotEvent = GetCurrentCOTEvent();
	cotEvent->SetAttribute(TEXT("fillColor"), UVH_COTStatics::ColorToHexAttribute(LineColor));
	cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), LineColor);
	cotEvent->SetAttribute<FColor>(TEXT("detail\tcolor\tvalue"), LineColor);
	cotEvent->SetAttribute<FColor>(TEXT("detail\tcolor\targb"), LineColor);
		
	cotEvent->AddNode(TEXT("detail\tshape\tlink\tStyle\tLineStyle\tcolor"), TArray<FXmlAttribute>(), true, UVH_COTStatics::ToHex(LineColor));
	cotEvent->AddNode(TEXT("detail\tshape\tlink\tStyle\tLineStyle\talpha"), TArray<FXmlAttribute>(), true, FString::Printf(TEXT("%d"), PolyColor.A));

	cotEvent->AddNode(TEXT("detail\tshape\tlink\tStyle\tPolyStyle\tcolor"), TArray<FXmlAttribute>(), true, UVH_COTStatics::ToHex(LineColor));

	SyncColors();
}


void UGame_COTComponent_DrawCircle::HandleManipulationBegin(AActor* manipulatedActor)
{
	for (AGame_SimpleSegmentedLineActor* topLine : TopLines)
	{
		topLine->SetActorHiddenInGame(true);
	}
}

void UGame_COTComponent_DrawCircle::HandleManipulationEnd(AActor* manipulatedActor)
{
	for (AGame_SimpleSegmentedLineActor* topLine : TopLines)
	{
		topLine->SetActorHiddenInGame(false);
	}
}