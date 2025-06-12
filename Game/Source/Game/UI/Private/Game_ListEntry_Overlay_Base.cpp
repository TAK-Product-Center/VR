// Developed by Virtual Heroes, 2019-2020

// Required includes
#include "Game_ListEntry_Overlay_Base.h"

// Game layer includes
#include "Game.h"
#include "Game_HandlerService.h"
#include "Game_COTManager.h"
#include "Game_EntityDB.h"

// ---------------------------------
// --- Inherited Methods
// ---------------------------------

void UGame_ListEntry_Overlay_Base::NativeConstruct()
{
	Super::NativeConstruct();

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.AddUniqueDynamic(this, &UGame_ListEntry_Overlay_Base::HandleDBInsertOrUpdate);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_ListEntry_Overlay_Base::GetHighlightOnSelection() const
{
	return bHighlightOnSelection;
}

void UGame_ListEntry_Overlay_Base::SetHighlightOnSelection(bool bHighlight)
{
	bHighlightOnSelection = bHighlight;

	ReceiveSetHighlightOnSelection(bHighlightOnSelection);
}

EMinimalDisplay UGame_ListEntry_Overlay_Base::GetMinimalDisplayType() const
{
	return MinimalDisplayType;
}

void UGame_ListEntry_Overlay_Base::SetMinimalDisplayType(EMinimalDisplay displayType)
{
	MinimalDisplayType = displayType;

	ReceiveSetMinimalDisplayType(MinimalDisplayType);
}

TArray<FString> UGame_ListEntry_Overlay_Base::GetUIDs_Implementation()
{
	return GetUIDs_Native();
}

void UGame_ListEntry_Overlay_Base::SetResult(const FSpatialiteResult_BP& inResult)
{
	Result = inResult;

	EntityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), Result);
	ClassUID = UDatabase_Spatialite::GetString(TEXT("classUID"), Result);
	CategoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), Result);
	bIsTransient = UDatabase_Spatialite::GetBool(TEXT("transient"), Result);
	bIsVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), Result);

	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		FGeodeticCoord3D coordinate;
		handlerService->GetGoToCoord(Result, coordinate);

		Longitude = FString::Printf(TEXT("%.8Lf"), coordinate.Longitude);
		Latitude = FString::Printf(TEXT("%.8Lf"), coordinate.Latitude);
		Height = FString::Printf(TEXT("%.8Lf"), coordinate.Altitude);
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		TMap<FString, FString> keyValues;
		entityDB->GetEntityOverlayInfo(keyValues, Result);

		UpdateUI_Native(keyValues);
		UpdateUI(keyValues);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("UGame_ListEntry_Overlay_Base::SetResult() -- The entityDB is nullptr."));
	}
}

void UGame_ListEntry_Overlay_Base::HandleInsertOrUpdate_Implementation(const FSpatialiteResult_BP& dbResult)
{
	HandleInsertOrUpdate_Native(dbResult);
}

void UGame_ListEntry_Overlay_Base::SetSelectionCheckboxValue_Implementation(bool bIsChecked)
{
	SetSelectionCheckboxValue_Native(bIsChecked);
}

void UGame_ListEntry_Overlay_Base::ShowSelectionCheckbox_Implementation(bool bShouldShow)
{
	ShowSelectionCheckbox_Native(bShouldShow);
}

void UGame_ListEntry_Overlay_Base::UpdateUI_Implementation(const TMap<FString, FString>& overlayInfo)
{
	UpdateUI_Native(overlayInfo);
}


// ---------------------------------
// --- Implementation Methods
// ---------------------------------

TArray<FString> UGame_ListEntry_Overlay_Base::GetUIDs_Native()
{
	TArray<FString> uids = { EntityUID };
	return uids;
}

void UGame_ListEntry_Overlay_Base::HandleInsertOrUpdate_Native(const FSpatialiteResult_BP& dbResult)
{

}

void UGame_ListEntry_Overlay_Base::SetSelectionCheckboxValue_Native(bool bIsChecked)
{

}

void UGame_ListEntry_Overlay_Base::ShowSelectionCheckbox_Native(bool bShouldShow)
{

}

void UGame_ListEntry_Overlay_Base::UpdateUI_Native(const TMap<FString, FString>& overlayInfo)
{

}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_ListEntry_Overlay_Base::HandleDBInsertOrUpdate(const FSpatialiteResults_BP& dbResults)
{
	for (FSpatialiteResult_BP result : dbResults.Results)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

		if (entityUID.Equals(EntityUID))
		{
			SetResult(result);

			HandleInsertOrUpdate(result);
		}
	}
}