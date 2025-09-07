// Required Includes
#include "Game_COTComponent_DrawPolyline.h"
#include "Game.h"

// Engine Includes
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// VH Includes
#include "VH_COTEvent.h"
#include "VH_COTStatics.h"
#include "Developer_Statics.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeCoordConverter.h"

// Game Includes
#include "Game_COTManager.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_EditPoint.h"
#include "Game_DrawContainer.h"
#include "Game_EditPoint_Center.h"
#include "Game_DrawLineData.h"
#include "Game_Actor_Mesh.h"
#include "Game_ImportedMeshComponent.h"
#include "Game_Subsystem_Core.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawPolyline::UGame_COTComponent_DrawPolyline() :
	FillColorAlpha(127)
{
	PrimaryComponentTick.bCanEverTick = true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawPolyline::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	if (IsValid(MeshActor))
	{
		MeshActor->Destroy();
		MeshActor = nullptr;
	}

	if (IsValid(CenterEditPoint))
	{
		CenterEditPoint->Destroy();
	}

	Super::EndPlay(endPlayReason);
}

void UGame_COTComponent_DrawPolyline::HandleOwnerSetHidden(bool bNewHidden)
{
	Super::HandleOwnerSetHidden(bNewHidden);

	if (IsValid(MeshActor))
	{
		MeshActor->SetActorHiddenInGame(bNewHidden);
	}
}

void UGame_COTComponent_DrawPolyline::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	GetWorld()->GetTimerManager().ClearTimer(UpdateFillTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(QueuedLinkTimerHandle);

	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		if (Lines.Num() == 0)
		{
			SpawnLine();
		}

		if (Lines.Num() == 1)
		{
			AGame_SimpleSegmentedLineActor* line = GetLines()[0];
			line->SetColor(cotEvent->GetAttribute<FColor>(TEXT("strokeColor")));

			FString fillColorString = cotEvent->GetAttribute(TEXT("fillColor"));
			FillColorAlpha = fillColorString.IsEmpty() ? 127 : UVH_COTStatics::HexAttributeToColor(fillColorString).A;

			DeleteEditPoints(line);

			QueuedLinks = cotEvent->GetNodes(TEXT("link"));
			
			bClosed = UVH_COTStatics::IsPolylineClosed(cotEvent);
			if (IsValid(MeshActor))
			{
				MeshActor->Destroy();
				MeshActor = nullptr;
			}

			if (IsValid(CenterEditPoint))
			{
				CenterEditPoint->Destroy();
				CenterEditPoint = nullptr;
			}

			FString callsign = cotEvent->GetAttribute(TEXT("callsign"));
			if (bClosed)
			{
				if (callsign.Equals(TEXT("Polyline")))
				{
					cotEvent->SetAttribute(TEXT("callsign"), UGame_Statics::GetUniqueCOTEntityCallsign(cotEvent, TEXT("Shape")));
				}
			}
			else
			{
				if (callsign.Equals(TEXT("Shape")))
				{
					cotEvent->SetAttribute(TEXT("callsign"), UGame_Statics::GetUniqueCOTEntityCallsign(cotEvent, TEXT("Polyline")));
				}
			}

			if (bClosed)
			{
				// spawn CenterEditPoint at center
				FTransform spawnTransform = FTransform(FRotator(0, 0, 0), GetCenterWorldLocation(), GetOwner()->GetActorScale3D());

				CenterEditPoint = GetWorld()->SpawnActorDeferred<AGame_EditPoint_Center>(CenterEditPointClass, spawnTransform, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
				CenterEditPoint->SetDrawContainer(Cast<AGame_DrawContainer>(GetOwner()));

				UGameplayStatics::FinishSpawningActor(CenterEditPoint, spawnTransform);

				CenterEditPoint->SetActive(true);
				CenterEditPoint->SetLineActor(GetLines()[0]);
				CenterEditPoint->SyncGeoLocationToWorldLocation();
				CenterEditPoint->SetCallsign(cotEvent->GetAttribute(TEXT("callsign")));
				CenterEditPoint->SetColor(FColor::White);
				CenterEditPoint->SetActorScale3D(FVector(1, 1, 1));
			}

			AddQueuedLink();
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawPolyline::ReceiveCOTUpdate_Virtual | invalid number of lines: %d"), Lines.Num());
		}
	}
}

void UGame_COTComponent_DrawPolyline::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (Lines.Num() != 1)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawPolyline::PopulateCOT_Virtual | more than 1 line: %d"), Lines.Num());
		return;
	}

	if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-f"));

		if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			FString callsign = UGame_Statics::GetUniqueCOTEntityCallsign(cotEvent, bClosed ? TEXT("Shape") : TEXT("Polyline"));

			cotEvent->SetAttribute(TEXT("callsign"), callsign);
		}

		cotEvent->PopulateTime(ActiveTime);

		cotEvent->SetAttribute<double>(TEXT("detail\theight\tvalue"), 0);
		cotEvent->SetAttribute<int32>(TEXT("detail\theight_unit\tvalue"), 1);
		
		FColor lineColor = line->GetColor();
		cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), lineColor);

		FColor fillColor = lineColor;
		fillColor.A = FillColorAlpha;
		cotEvent->SetAttribute(TEXT("fillColor"), UVH_COTStatics::ColorToHexAttribute(fillColor));
		
		cotEvent->RemoveNodes(TEXT("link"));

		TArray<AGame_EditPoint*> editPoints = Lines[line]->GetEditPoints();
		for (AGame_EditPoint* editPoint : editPoints)
		{
			FGeodeticCoord3D coordinate = editPoint->GetGeoLocation();

			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(coordinate)));
			
			cotEvent->AddNode(TEXT("link"), attributes);
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------
	
void UGame_COTComponent_DrawPolyline::SetClosed(bool bClosedArg)
{
	if (bClosed != bClosedArg)
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		TArray<AGame_EditPoint*> editPoints;
		GetEditPoints(line, editPoints);

		if (bClosedArg)
		{
			// currently not closed; make it closed
			if (editPoints.Num() > 2)
			{
				bClosed = true;

				AGame_EditPoint* editPoint = SpawnEditPoint(line, FVector(0, 0, 0), nullptr);
				editPoint->SetActive(false);
				editPoint->SetGeoLocation(editPoints[0]->GetGeoLocation());
				editPoint->SyncWorldLocationToGeoLocation();

				GetWorld()->GetTimerManager().SetTimer(UpdateFillTimerHandle, this, &UGame_COTComponent_DrawPolyline::PeriodicUpdateForClosed, 0.25);
			}
		}
		else
		{
			// currently closed; make it not closed
			bClosed = false;

			DeleteEditPoint(line, editPoints[editPoints.Num() - 1]);

			GetWorld()->GetTimerManager().ClearTimer(UpdateFillTimerHandle);

			if (IsValid(MeshActor))
			{
				MeshActor->Destroy();
				MeshActor = nullptr;
			}
		}
	}
}

bool UGame_COTComponent_DrawPolyline::IsClosed() const
{
	return bClosed;
}

void UGame_COTComponent_DrawPolyline::SetFillColorAlpha(int32 alpha)
{
	FillColorAlpha = FMath::Clamp<int32>(alpha, 0, 255);
}

int32 UGame_COTComponent_DrawPolyline::GetFillColorAlpha() const
{
	return FillColorAlpha;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

FVector UGame_COTComponent_DrawPolyline::GetCenterWorldLocation() const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			FGeodeticCoord3D centerCoordinate(0, 0, 0, false);

			FVector centerECEF = FVector::Zero();
			int32 divisor = 1;

			AGame_SimpleSegmentedLineActor* line = GetLines()[0];

			TArray<AGame_EditPoint*> editPoints;
			GetEditPoints(line, editPoints);

			if (editPoints.Num() > 1)
			{
				for (int32 i = 0; i < editPoints.Num() - 1; i++)  // last point of closed polyline is same as first point
				{
					FGeodeticCoord3D coordinate = editPoints[i]->GetGeoLocation();

					FVector ecef = globeReference->GeodeticToECEF(coordinate);
							
					centerECEF += ecef;
				}

				divisor = editPoints.Num() - 1;
			}
			else if (QueuedLinks.Num() > 1)
			{
				for (int32 i = 0; i < QueuedLinks.Num() - 1; i++)  // last point of closed polyline is same as first point
				{
					FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(QueuedLinks[i]);

					FVector ecef = globeReference->GeodeticToECEF(coordinate);
							
					centerECEF += ecef;
				}

				divisor = QueuedLinks.Num() - 1;
			}

			centerECEF /= divisor;
			
			centerCoordinate = globeReference->ECEFToGeodetic(centerECEF);
						
			return globeReference->GeodeticToWorldDouble(centerCoordinate);
		}
	}

	return FVector::ZeroVector;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_COTComponent_DrawPolyline::AddQueuedLink()
{
	if (QueuedLinks.Num() > 0)
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		AGame_EditPoint* editPoint = SpawnEditPoint(line, FVector(0, 0, 0), nullptr);
		editPoint->SetActive(false);
		editPoint->SetGeoLocation(UVH_COTStatics::LinkToCoordinate(QueuedLinks[0]));
		editPoint->SyncWorldLocationToGeoLocation();

		QueuedLinks.RemoveAt(0, 1);

		if (QueuedLinks.Num() > 0)
		{
			GetWorld()->GetTimerManager().SetTimer(QueuedLinkTimerHandle, this, &UGame_COTComponent_DrawPolyline::AddQueuedLink, 0.01);
		}
		else if (bClosed)
		{
			GetWorld()->GetTimerManager().SetTimer(UpdateFillTimerHandle, this, &UGame_COTComponent_DrawPolyline::PeriodicUpdateForClosed, 0.25);
		}
	}
}

void UGame_COTComponent_DrawPolyline::PeriodicUpdateForClosed()
{
	if (bClosed)
	{
		if (IsValid(CenterEditPoint))
		{
			CenterEditPoint->SetActorLocation(GetCenterWorldLocation());
		}

		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		TArray<AGame_EditPoint*> editPoints;
		GetEditPoints(line, editPoints);

		AGame_EditPoint* lastEditPoint = editPoints[editPoints.Num() - 1];
		lastEditPoint->SetActive(false);
		lastEditPoint->SetActorLocation(editPoints[0]->GetActorLocation());
		lastEditPoint->SyncGeoLocationToWorldLocation();

		TArray<FVector> vertices;
		TArray<FVector2D> polygon2D;
		FGeodeticCoord3D center(0, 0, 0, false);
		for (int32 i = 0; i < editPoints.Num(); i++)
		{
			vertices.Add(editPoints[i]->GetActorLocation() - GetOwner()->GetActorLocation());

			FGeodeticCoord3D coordinate = editPoints[i]->GetGeoLocation();
			polygon2D.Add(FVector2D(coordinate.Longitude, coordinate.Latitude));
		}

		if (!IsValid(MeshActor))
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = GetOwner();
			spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			FTransform transform = FTransform::Identity;
			transform.SetLocation(GetOwner()->GetActorLocation());

			MeshActor = GetWorld()->SpawnActor<AGame_Actor_Mesh>(MeshActorClass, transform, spawnParams);
			MeshActor->SetActorHiddenInGame(line->IsHidden());
		}
		else
		{
			MeshActor->SetActorLocation(GetOwner()->GetActorLocation());
		}

		TArray<int32> triangles;
		bool bWindsClockwise = false;
		if (UDeveloper_Statics::TriangulatePolygon(polygon2D, triangles, bWindsClockwise))
		{
			if (FillMaterialInstance == nullptr)
			{
				FillMaterialInstance = UMaterialInstanceDynamic::Create(PolygonMaterial, this);
			}

			FColor fillColor = line->GetColor();
			fillColor.A = FillColorAlpha;
			FillMaterialInstance->SetVectorParameterValue(TEXT("Color"), fillColor);

			MeshActor->BuildMeshFromVerticesAndTriangles(vertices, triangles, FillMaterialInstance);
		}

		GetWorld()->GetTimerManager().SetTimer(UpdateFillTimerHandle, this, &UGame_COTComponent_DrawPolyline::PeriodicUpdateForClosed, 0.25);
	}
}