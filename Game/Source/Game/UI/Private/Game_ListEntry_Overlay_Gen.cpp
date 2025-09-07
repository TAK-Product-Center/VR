// Required Includes
#include "Game_ListEntry_Overlay_Gen.h"
#include "Game.h"

// Engine includes
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/CheckBox.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_ListEntry_Overlay_Gen::NativeConstruct()
{
	Super::NativeConstruct();

	BtnVisible->OnClicked.AddUniqueDynamic(this, &UGame_ListEntry_Overlay_Gen::HandleVisibilityToggleClicked);

	SelectionCheckbox->OnCheckStateChanged.AddUniqueDynamic(this, &UGame_ListEntry_Overlay_Gen::HandleCheckboxStateChanged);
}

void UGame_ListEntry_Overlay_Gen::HandleInsertOrUpdate_Native(const FSpatialiteResult_BP& dbResult)
{
	bIsVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), Result);

	UpdateUIVisibility();
}

void UGame_ListEntry_Overlay_Gen::SetSelectionCheckboxValue_Native(bool bIsChecked)
{
	SelectionCheckbox->SetCheckedState(bIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
}

void UGame_ListEntry_Overlay_Gen::ShowSelectionCheckbox_Native(bool bShouldShow)
{
	SelectionCheckbox->SetVisibility(bShouldShow ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);

	BtnVisible->SetVisibility(bShouldShow ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
}

void UGame_ListEntry_Overlay_Gen::UpdateUI_Native(const TMap<FString, FString>& overlayInfo)
{
	UpdateUIVisibility();

	if (UTexture2D* iconTexture = GetIconTexture())
	{
		ImgCategory->SetBrushFromTexture(iconTexture, false);
	}
	else
	{
		ImgCategory->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (const FString* displayName = overlayInfo.Find(TEXT("displayName")))
	{
		TextCallsign->SetText(FText::FromString(*displayName));
	}

	FGeodeticCoord3D coordinate(FCString::Atod(*Longitude), FCString::Atod(*Latitude), FCString::Atod(*Height));

	ReceiveSetCoordinate(UGame_Statics::GetCoordinateStringInPreferredUnits(coordinate, true));
}

// ---------------------------------
// --- API
// ---------------------------------

UTexture2D* UGame_ListEntry_Overlay_Gen::GetIconTexture_Implementation() const
{
	return GetIconTexture_Native();
}

UTexture2D* UGame_ListEntry_Overlay_Gen::GetIconTexture_Native() const
{
	return nullptr;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_ListEntry_Overlay_Gen::UpdateUIVisibility()
{
	FLinearColor visibilityColor = FLinearColor();

	if (bIsVisible)
	{
		// Turn the image to a green color
		visibilityColor = FLinearColor(0.171875f, 1.f, 0.19616f, 1.f);
	}
	else
	{
		// Turn the image to a red color
		visibilityColor = FLinearColor(0.583333f, 0.030382f, 0.030382f, 1.f);
	}

	ImgVisible->SetColorAndOpacity(visibilityColor);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_ListEntry_Overlay_Gen::HandleCheckboxStateChanged(bool bIsChecked)
{
	TArray<FString> uids = { EntityUID };

	OnSelectionToggled.Broadcast(uids);
}

void UGame_ListEntry_Overlay_Gen::HandleVisibilityToggleClicked()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		bIsVisible = !bIsVisible;

		entityDB->SetEntityVisibility(EntityUID, bIsVisible);

		UpdateUIVisibility();
	}
}