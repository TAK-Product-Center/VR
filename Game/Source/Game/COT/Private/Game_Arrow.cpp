// Required Includes
#include "Game_Arrow.h"
#include "Game.h"

// Engine Includes
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

// Game Includes
#include "Game_EditPoint.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_UserWidget_Arrow.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_DrawContainer.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Arrow::AGame_Arrow() :
	bSyncLineToEditPoints(true),
	bPointArrowEditPoint(true),
	PercentageOfDistance(0.25)
{
    PrimaryActorTick.bCanEverTick = true;
}


// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Arrow::BeginPlay()
{
    Super::BeginPlay();

	SpawnEditPointsAndLine();

	ArrowWidget = CreateUIWidget();

	if (ArrowWidget != nullptr)
	{
		// not guaranteed that owner has a VO; but worth a shot to try here
		ArrowWidget->VirtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(GetOwner());
	}
}

void AGame_Arrow::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	AGame_DrawContainer* drawContainer = nullptr;

	if (BaseEditPoint != nullptr)
	{
		BaseEditPoint->Destroy();
	}

	if (ArrowEditPoint != nullptr)
	{
		ArrowEditPoint->Destroy();
	}

	if (Line != nullptr)
	{
		drawContainer = Line->DrawContainer;
		Line->Destroy();

		if (drawContainer != nullptr)
		{
			drawContainer->Destroy();
		}
	}

	Super::EndPlay(endPlayReason);
}

void AGame_Arrow::Tick(float deltaSec)
{
    Super::Tick(deltaSec);

	if (BaseEditPoint == nullptr || ArrowEditPoint == nullptr)
	{
		return;
	}

	if (LinkedBaseActor != nullptr)
	{
		BaseEditPoint->SetActorLocation(LinkedBaseActor->GetActorLocation());

		// move down a little if endpoint is on local player
		if (UGame_Statics::GetVHPlayerPawn() == LinkedBaseActor)
		{
			FTransform transform = UGame_Statics::GetWorldTransformOverride(LinkedBaseActor->GetActorLocation());

			BaseEditPoint->SetActorLocation(transform.TransformPosition(FVector(0, 0, -200)));
		}

		BaseEditPoint->SyncGeoLocationToWorldLocation();
	}

	if (LinkedArrowActor != nullptr)
	{
		ArrowEditPoint->SetActorLocation(LinkedArrowActor->GetActorLocation());

		// move down a little if endpoint is on local player
		if (UGame_Statics::GetVHPlayerPawn() == LinkedArrowActor)
		{
			FTransform transform = UGame_Statics::GetWorldTransformOverride(LinkedArrowActor->GetActorLocation());

			ArrowEditPoint->SetActorLocation(transform.TransformPosition(FVector(0, 0, -200)));
		}

		ArrowEditPoint->SyncGeoLocationToWorldLocation();
	}

	if (UWidgetComponent* widgetComponent = GetWidgetComponent())
	{
		bool bIsInTOC = false;
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			bIsInTOC = playerState->GetIsInTOC();
		}

		FVector location;
		// If in the TOC room, set the world location between baseEditPoint and arrowEditPoint in the middle of the line
		if (bIsInTOC)
		{
			location = (BaseEditPoint->GetActorLocation() + ArrowEditPoint->GetActorLocation()) / 2.f;
		}
		// If in the world, set the world location to adjust based on the player location
		else
		{
			APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

			widgetComponent->GetComponentLocation();

			FVector normal = (playerPawn->GetActorLocation() - widgetComponent->GetComponentLocation()).GetSafeNormal();
			double distance = FVector::Dist(playerPawn->GetActorLocation(), widgetComponent->GetComponentLocation());

			// Clamp between 0 and 100% of the distance between the player and the widget
			FMath::Clamp(PercentageOfDistance, 0, 1);
			FVector adjustmentToPlayer = (normal * distance * PercentageOfDistance);

			location = ((BaseEditPoint->GetActorLocation() + ArrowEditPoint->GetActorLocation()) / 2.f) + adjustmentToPlayer;
		}

		SetActorLocation(location);

		if (!bInitialSetLocation)
		{
			ReceiveSetInitialLocation(location);

			bInitialSetLocation = true;
		}
	}

	if (ArrowWidget != nullptr)
	{
		ArrowWidget->Update(GetOwner()->GetActorScale3D(), BaseEditPoint, ArrowEditPoint);
	}

	SyncLineToEditPoints();

	// todo ohg | refactor naming, this isn't necessarily an arrow; more of a line segment
	if (bPointArrowEditPoint)
	{
		// make arrow point away from base
		ArrowEditPoint->SetActorRotation((ArrowEditPoint->GetActorLocation() - BaseEditPoint->GetActorLocation()).GetSafeNormal().Rotation());
	}
}

void AGame_Arrow::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	if (ArrowWidget != nullptr)
	{
		ArrowWidget->SetVisibility(bNewHidden ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}

	if (BaseEditPoint != nullptr)
	{
		BaseEditPoint->SetActorHiddenInGame(bNewHidden);
	}

	if (ArrowEditPoint != nullptr)
	{
		ArrowEditPoint->SetActorHiddenInGame(bNewHidden);
	}

	if (Line != nullptr)
	{
		Line->SetActorHiddenInGame(bNewHidden);
	}
}

void AGame_Arrow::SetActorScale3D(FVector newScale3D)
{
	Super::SetActorScale3D(newScale3D);

	if (BaseEditPoint != nullptr)
	{
		BaseEditPoint->SetActorScale3D(newScale3D);
	}

	if (ArrowEditPoint != nullptr)
	{
		ArrowEditPoint->SetActorScale3D(newScale3D);
	}

	if (Line != nullptr)
	{
		Line->SetActorScale3D(newScale3D);
	}
}


// ---------------------------------
// --- API
// ---------------------------------

AGame_SimpleSegmentedLineActor* AGame_Arrow::GetLine() const
{
	return Line;
}

AGame_EditPoint* AGame_Arrow::GetBaseEditPoint() const
{
	return BaseEditPoint;
}

AGame_EditPoint* AGame_Arrow::GetArrowEditPoint() const
{
	return ArrowEditPoint;
}

UGame_UserWidget_Arrow* AGame_Arrow::GetUIWidget() const
{
	return ArrowWidget;
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_Arrow::SpawnEditPointsAndLine()
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	Line = Cast<AGame_SimpleSegmentedLineActor>(GetWorld()->SpawnActor<AGame_SimpleSegmentedLineActor>(LineClass, spawnParams));
	Line->SetActorScale3D(GetOwner()->GetActorScale3D());

	BaseEditPoint = Cast<AGame_EditPoint>(GetWorld()->SpawnActor<AGame_EditPoint>(BaseEditPointClass, GetActorLocation(), FRotator(), spawnParams));
	BaseEditPoint->SetActive(true);
	BaseEditPoint->SetLineActor(Line);
	BaseEditPoint->SetActorScale3D(GetOwner()->GetActorScale3D());

	ArrowEditPoint = Cast<AGame_EditPoint>(GetWorld()->SpawnActor<AGame_EditPoint>(ArrowEditPointClass, GetActorLocation(), FRotator(), spawnParams));
	ArrowEditPoint->SetActive(true);
	ArrowEditPoint->SetLineActor(Line);
	ArrowEditPoint->SetActorScale3D(GetOwner()->GetActorScale3D());
}

void AGame_Arrow::SyncLineToEditPoints()
{
	if (bSyncLineToEditPoints)
	{
		if (Line != nullptr)
		{
			TArray<AGame_EditPoint*> editPoints;
			editPoints.Add(BaseEditPoint);
			editPoints.Add(ArrowEditPoint);

			bool bGenerateMesh = false;

			if (Line->LinePoints.Num() != editPoints.Num() || !Line->AreCoordinatesValid())
			{
				Line->LinePoints.Empty();

				for (int32 i = 0; i < editPoints.Num(); i++)
				{
					Line->AddLocationAndGeoLocation(editPoints[i]->GetActorLocation(), editPoints[i]->GetGeoLocation());
				}

				bGenerateMesh = true;
			}
			else
			{
				for (int32 i = 0; i < editPoints.Num(); i++)
				{
					FVector currentLocation = editPoints[i]->GetLineDrawLocation();
					FGeodeticCoord3D currentGeoLocation = editPoints[i]->GetGeoLocation();

					if (!currentLocation.Equals(Line->LinePoints[i].Location) || currentGeoLocation != Line->GetGeoLocation(i))
					{
						if (currentLocation.IsZero())
						{
							UE_LOG(Game, Warning, TEXT("-- AGame_Arrow::SyncLineToEditPoints | EditPoints[%d] line draw location is [0, 0, 0]"), i);
						}
						if (currentGeoLocation == FGeodeticCoord3D(0, 0, 0))
						{
							UE_LOG(Game, Warning, TEXT("-- AGame_Arrow::SyncLineToEditPoints | EditPoints[%d] geodetic location is [0, 0, 0]"), i);
						}

						Line->UpdateLocationAndGeoLocation(i, currentLocation, currentGeoLocation);
						bGenerateMesh = true;
					}
				}
			}

			if (bGenerateMesh)
			{
				Line->GenerateMesh();
			}
		}
	}
}