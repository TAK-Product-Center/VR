// Developed by Virtual Heroes, 2019-2020

// Required includes
#include "Game_ListEntry_Overlay_Gen.h"

// Engine includes
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/CheckBox.h"

// VH Plugin Layer
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeCoordConverter.h"

// Game Layer includes
#include "Game_EntityDB.h"
#include "Game_GameInstance.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"

// ---------------------------------
// --- Inherited Methods
// ---------------------------------

void UGame_ListEntry_Overlay_Gen::NativeConstruct()
{
	Super::NativeConstruct();

	if (BtnVisible != nullptr)
	{
		BtnVisible->OnClicked.AddUniqueDynamic(this, &UGame_ListEntry_Overlay_Gen::HandleVisibilityToggleClicked);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::NativeConstruct() -- The BtnVisible is nullptr"));
	}

	if (SelectionCheckbox != nullptr)
	{
		SelectionCheckbox->OnCheckStateChanged.AddUniqueDynamic(this, &UGame_ListEntry_Overlay_Gen::HandleCheckboxStateChanged);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::NativeConstruct() -- The SelectionCheckbox is nullptr"));
	}
}

/////// Native Events ///////

void UGame_ListEntry_Overlay_Gen::HandleInsertOrUpdate_Native(const FSpatialiteResult_BP& dbResult)
{
	bIsVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), Result);

	UpdateUIVisibility();
}

void UGame_ListEntry_Overlay_Gen::SetSelectionCheckboxValue_Native(bool bIsChecked)
{
	if (SelectionCheckbox != nullptr)
	{
		SelectionCheckbox->SetCheckedState(bIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::SetSelectionCheckboxValue_Native() -- The SelectionCheckbox is nullptr"));
	}
}

void UGame_ListEntry_Overlay_Gen::ShowSelectionCheckbox_Native(bool bShouldShow)
{
	if (SelectionCheckbox != nullptr)
	{
		SelectionCheckbox->SetVisibility(bShouldShow ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::ShowSelectionCheckbox_Native() -- The SelectionCheckbox is nullptr"));
	}

	if (BtnVisible != nullptr)
	{
		BtnVisible->SetVisibility(bShouldShow ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::ShowSelectionCheckbox_Native() -- The BtnVisible is nullptr"));
	}
}

void UGame_ListEntry_Overlay_Gen::UpdateUI_Native(const TMap<FString, FString>& overlayInfo)
{
	UpdateUIVisibility();

	if (ImgCategory != nullptr)
	{
		if (UTexture2D* iconTexture = GetIconTexture())
		{
			ImgCategory->SetBrushFromTexture(iconTexture, false);
		}
		else
		{
			ImgCategory->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The ImgCategory is nullptr"));
	}

	if (TextCallsign != nullptr)
	{
		const FString* displayName = overlayInfo.Find(TEXT("displayName"));

		if (displayName != nullptr)
		{
			TextCallsign->SetText(FText::FromString(*displayName));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The displayName is nullptr"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The TextCallsign is nullptr"));
	}

	if (TextHAE != nullptr)
	{
		TextHAE->SetText(FText::FromString(Height + TEXT("m")));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The TextHAE is nullptr"));
	}

	if (TextMGRS && TextDistance && TextBearing)
	{
		if (UGame_GameInstance* gameInstance = UGame_GameInstance::Get())
		{
			if (UVH_GlobeCoordConverter* globeConverter = gameInstance->GetWGS84GlobeCoordConverter())
			{
				FGeodeticCoord2D mgrsLocation = FGeodeticCoord2D(FCString::Atod(*Longitude), FCString::Atod(*Latitude));
				FMgrsCoord mgrs = globeConverter->GeodeticToMGRSDouble(mgrsLocation);

				TextMGRS->SetText(FText::FromString(mgrs.ToString()));

				if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
				{
					if (AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference())
					{
						if (APawn* pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
						{
							FVector distance = globeRef->GeodeticToWorldDouble(mgrsLocation) - pawn->GetActorLocation();
							float bearing = globeRef->WorldRotationToBearing(distance.ToOrientationRotator());

							FString distanceString = FString::SanitizeFloat(distance.Size() / 100.f) + TEXT("m");
							FString bearingString = FString::SanitizeFloat(bearing) + TEXT("°");

							TextDistance->SetText(FText::FromString(distanceString));
							TextBearing->SetText(FText::FromString(bearingString));
						}
						else
						{
							UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The pawn is nullptr."));
						}
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The globeRef is nullptr."));
					}
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The globeConverter is nullptr."));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- The gameInstance is nullptr."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUI_Native() -- One of the UTextBlocks is nullptr."));
	}
}

// ---------------------------------
// --- Public Methods
// ---------------------------------

UTexture2D* UGame_ListEntry_Overlay_Gen::GetIconTexture_Implementation() const
{
	return GetIconTexture_Native();
}

/////// Native Events ///////

UTexture2D* UGame_ListEntry_Overlay_Gen::GetIconTexture_Native() const
{
	return nullptr;
}

// ---------------------------------
// --- Implementation Methods
// ---------------------------------

void UGame_ListEntry_Overlay_Gen::UpdateUIVisibility()
{
	if (ImgVisible != nullptr)
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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::UpdateUIVisibility() -- The ImgVisible is nullptr."));
	}
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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGame_ListEntry_Overlay_Gen::HandleVisibilityToggleClicked() -- The UGame_EntityDB is nullptr."));
	}
}