// Required Includes
#include "Game_UserWidget_MapScrape.h"
#include "Game.h"

// Engine Includes
#include "Async/Async.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_COTComponent.h"
#include "VH_COTEvent.h"
#include "VH_GeodeticCoord.h"
#include "Interface_COTReceiver.h"

// Game Includes
#include "Game_DrawContainer.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_COTComponent_DrawRectangle.h"
#include "Game_EditPoint.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_EntityDB.h"
#include "Game_EntityHandler_COT.h"
#include "Game_MatComponent_XML.h"
#include "Game_TileComponent.h"
#include "Game_TileManager.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_PlayerController.h"
#include "Game_Tool.h"
#include "Game_MotionControllerComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_MapScrape::UGame_UserWidget_MapScrape(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_MapScrape::BeginDestroy()
{
	Abort();

	Super::BeginDestroy();
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_MapScrape::LineClicked(AGame_SimpleSegmentedLineActor* line)
{
	if (IsValid(line) && IsValid(line->DrawContainer))
	{
		UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(line->DrawContainer);
		if (Cast<UGame_COTComponent_DrawRectangle>(cotComponent))
		{
			UVH_COTEvent* cotEvent = cotComponent->GetCurrentCOTEvent();
			DrawContainerEntityUID = cotEvent->GetAttribute(TEXT("uid"));

			FGeodeticCoord2D northWestBound;
			FGeodeticCoord2D southEastBound;
			GetBounds(line, northWestBound, southEastBound);

			FGeodeticCoord2D southWestBound;
			southWestBound.Longitude = northWestBound.Longitude;
			southWestBound.Latitude = southEastBound.Latitude;

			FGeodeticCoord2D northEastBound;
			northEastBound.Longitude = southEastBound.Longitude;
			northEastBound.Latitude = northWestBound.Latitude;

			ReceiveChooseBounds(cotEvent->GetAttribute(TEXT("callsign")), FString::Printf(TEXT("Southwest: %.8Lf, %.8Lf"), southWestBound.Latitude, southWestBound.Longitude), FString::Printf(TEXT("Northeast: %.8Lf, %.8Lf"), northEastBound.Latitude, northEastBound.Longitude));
		}
	}
}

void UGame_UserWidget_MapScrape::Abort()
{
	if (IsValid(MapScrapeComponent))
	{
		MapScrapeComponent->RemoveFromRoot();
		MapScrapeComponent = nullptr;
	}
}

bool UGame_UserWidget_MapScrape::Execute(int32 minZoom, int32 maxZoom, const FString& fullPathToOfflineFile, FString& error)
{
	minZoom = FMath::Clamp<int32>(minZoom, 1, 22);
	maxZoom = FMath::Clamp<int32>(maxZoom, 1, 22);

	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			if (AGame_DrawContainer* drawContainer = GetDrawContainer())
			{
				if (UGame_COTComponent_DrawRectangle* component = Cast<UGame_COTComponent_DrawRectangle>(drawContainer->GetDrawComponent()))
				{
					TArray<AGame_SimpleSegmentedLineActor*> lines = component->GetLines();
					if (lines.Num() > 0)
					{
						FGeodeticCoord2D northWestBound;
						FGeodeticCoord2D southEastBound;
						GetBounds(lines[0], northWestBound, southEastBound);

						if (IsValid(MapScrapeComponent))
						{
							MapScrapeComponent->RemoveFromRoot();
							MapScrapeComponent = nullptr;
						}

						MapScrapeComponent = NewObject<UGame_MatComponent_XML>();
						MapScrapeComponent->AddToRoot();

						auto onDownloadFinished = [this]()
						{
							AsyncTask(ENamedThreads::GameThread, [this]()
							{
								if (IsValid(MapScrapeComponent))
								{
									MapScrapeComponent->RemoveFromRoot();
									MapScrapeComponent = nullptr;
								}

								ReceiveMapScrapeFinished();
							});
						};

						auto onProgress = [this](const FString& progress)
						{
							AsyncTask(ENamedThreads::GameThread, [this, progress]()
							{
								ReceiveMapScrapeProgress(progress);
							});
						};

						MapScrapeComponent->DownloadForOffline(northWestBound, southEastBound, minZoom, maxZoom, fullPathToOfflineFile, onProgress, onDownloadFinished);

						return true;
					}
				}
			}
			else
			{
				error = TEXT("No bounding box");

				return false;
			}
		}
	}

	return false;
}

void UGame_UserWidget_MapScrape::SelectTool(TSubclassOf<AGame_Tool> toolClass)
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
		{
			if (subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Desktop)
			{
				// desktop mode only uses the left controller
				playerPawn->LeftController->RemoveAllTools();
				playerPawn->LeftController->AddToolByClass(toolClass);
			}
			else
			{
				if (UVR_MotionControllerComponent* motionControllerComponent = playerPawn->GetMotionControllerLastClickedOnWidget(this))
				{
					motionControllerComponent->RemoveAllTools();
					motionControllerComponent->AddToolByClass(toolClass);
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_MapScrape::Clicked | could not find VR_MotionControllerComponent | aborting"));
				}
			}
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AGame_DrawContainer* UGame_UserWidget_MapScrape::GetDrawContainer() const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		TSet<AActor*> actors = virtualObjective->GetActorsForEntity(DrawContainerEntityUID);
		if (actors.Num() > 0)
		{
			return Cast<AGame_DrawContainer>(*actors.begin());
		}
	}

	return nullptr;
}

void UGame_UserWidget_MapScrape::GetBounds(AGame_SimpleSegmentedLineActor* line, FGeodeticCoord2D& northWestBound, FGeodeticCoord2D& southEastBound) const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			if (UGame_COTComponent_DrawRectangle* component = Cast<UGame_COTComponent_DrawRectangle>(GetDrawContainer()->GetDrawComponent()))
			{
				TArray<AGame_EditPoint*> editPoints;
				component->GetEditPoints(line, editPoints);

				for (int32 i = 0; i < editPoints.Num(); i++)
				{
					FGeodeticCoord3D editPointCoordinate = globeReference->WorldToGeodeticDouble(editPoints[i]->GetActorLocation());

					if (i == 0)
					{
						northWestBound = editPointCoordinate.ToGeodeticCoord2D();
						southEastBound = northWestBound;
					}
					else
					{
						northWestBound.Longitude = FMath::Min<double>(northWestBound.Longitude, editPointCoordinate.Longitude);
						northWestBound.Latitude = FMath::Max<double>(northWestBound.Latitude, editPointCoordinate.Latitude);

						southEastBound.Longitude = FMath::Max<double>(southEastBound.Longitude, editPointCoordinate.Longitude);
						southEastBound.Latitude = FMath::Min<double>(southEastBound.Latitude, editPointCoordinate.Latitude);
					}
				}
			}
		}
	}
}