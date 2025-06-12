// Required Includes
#include "Game_TileComponent.h"
#include "Game.h"

// Game Includes
#include "Game_TileManager.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TileComponent::UGame_TileComponent() :
	HAEBounds(FVector2D(9999999.0, -9999999.0))
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_TileComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	for (int32 i = 0; i < HTTPRequests.Num(); i++)
	{
		if (HTTPRequests[i]->GetStatus() == EHttpRequestStatus::Processing)
		{
			HTTPRequests[i]->CancelRequest();
		}
	}

	HTTPRequests.Empty();

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

bool UGame_TileComponent::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_TileComponent::DownloadForOffline(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, double minZoom, double maxZoom, const FString& fullPathToOfflineFile, TFunction<void(const FString& progress)> onProgress, TFunction<void()> onDownloadComplete)
{
	UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent::DownloadForOffline | override in child class"));
}

void UGame_TileComponent::SetComponentStatus(const EComponentStatus componentStatus)
{
	if (ComponentStatus != componentStatus)
	{
		ComponentStatus = componentStatus;
	}
}

bool UGame_TileComponent::GlobeReferenceScaleUpdated(const FVector& newScale3D)
{
	return false;
}

void UGame_TileComponent::SetBoundsAndZoom(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, const int32 zoomLevel)
{
	if (tileBounds != TileBounds || ZoomLevel != zoomLevel)
	{
		TileBounds = tileBounds;

		ZoomLevel = zoomLevel;

		if (SetBoundsAndZoomVirtual(tileBounds, zoomLevel))
		{
			SetComponentStatus(EComponentStatus::Initialized);
		}
	}
}

bool UGame_TileComponent::IsMatTooBig(const int32 cols, const int32 rows) const
{
	int64 maxMatSize = FMath::Pow(2.f, 31.f);  // overflow bug in opencv | https://blog.csdn.net/yuezhilanyi/article/details/78115901
	int64 matSize = (int64)cols * (int64)rows;

	return (int64)cols * (int64)rows >= maxMatSize;
}

AGame_VirtualObjective* UGame_TileComponent::GetVirtualObjective() const
{
	return AGame_PlayerController::GetPlayerActiveVO();
}

bool UGame_TileComponent::GetHAEBounds(FVector2D& haeBounds) const
{
	if (bValidHAEBounds)
	{
		haeBounds = HAEBounds;

		return true;
	}

	return false;
}