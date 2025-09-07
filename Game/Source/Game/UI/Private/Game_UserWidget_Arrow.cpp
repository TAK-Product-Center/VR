// Required includes
#include "Game_UserWidget_Arrow.h"
#include "Game.h"

// VH Plugin includes
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_Subsystem_UnitConverter.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_EditPoint.h"
#include "Game_VirtualObjective.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_Arrow::UGame_UserWidget_Arrow(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	RangeMeters = -1.f;
	BearingDegrees = -1.f;
	bExplicitUnitSelected = false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_UserWidget_Arrow::Initialize()
{
	if (Super::Initialize())
	{
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			RangeUnit = gameSettings->GetSettingString(TEXT("RangeUnit"));
			BearingUnit = gameSettings->GetSettingString(TEXT("BearingUnit"));

			gameSettings->OnStringSettingStored.AddUniqueDynamic(this, &ThisClass::HandleStringSettingChanged);
		}
		else
		{
			RangeUnit = TEXT("miles");
			BearingUnit = TEXT("degrees");
		}

		return true;
	}

	return false;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_Arrow::Update(const FVector& scale3D, const AGame_EditPoint* baseEditPoint, const AGame_EditPoint* arrowEditPoint)
{
	if (baseEditPoint && arrowEditPoint)
	{
		// update BearingDegrees
		if (IsValid(VirtualObjective))
		{
			if (AVH_GlobeReferenceActor* globeReference = VirtualObjective->GetGlobeReference())
			{
				FGeodeticCoord3D baseCoordinate = globeReference->WorldToGeodeticDouble(baseEditPoint->GetActorLocation());
				FGeodeticCoord3D arrowCoordinate = globeReference->WorldToGeodeticDouble(arrowEditPoint->GetActorLocation());

				switch (RangeType)
				{
					case ERangeType::Both:
						RangeMeters = (baseEditPoint->GetActorLocation() - arrowEditPoint->GetActorLocation()).Size() / VirtualObjective->GetUnrealUnitsPerMeter();
						break;

					case ERangeType::Vertical:
						RangeMeters = FMath::Abs<float>(arrowCoordinate.Altitude - baseCoordinate.Altitude);
						break;

					case ERangeType::Horizontal:
						RangeMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(baseCoordinate.ToGeodeticCoord2D(), arrowCoordinate.ToGeodeticCoord2D());
						break;
				}

				UpdateRangeText(GetRangeString());

				BearingDegrees = UVH_GlobeMathStatics::CalculateSurfaceBearing(baseCoordinate.ToGeodeticCoord2D(), arrowCoordinate.ToGeodeticCoord2D());
				UpdateBearingText(GetBearingString());
			}
		}
	}
}

FString UGame_UserWidget_Arrow::GetRangeString() const
{
	FString rangeConvert = RangeUnit;
	if (rangeConvert.Equals(TEXT("miles")) && RangeMeters < 1609.344f)
	{
		// If our unit is miles but we have less than a mile
		rangeConvert = TEXT("feet");
	}
	else if (rangeConvert.Equals(TEXT("kilometers")) && RangeMeters < 1000.f)
	{
		// If our unit is kilometers but we have less than a kilometer
		rangeConvert = TEXT("meters");
	}

	if (UDeveloper_Subsystem_UnitConverter* unitConv = UDeveloper_Subsystem_UnitConverter::Get())
	{
		return unitConv->ConvertUnitsAndFormat(TEXT("meters"), FString::Printf(TEXT("%f"), RangeMeters), rangeConvert, 2);
	}

	return FString();
}

FString UGame_UserWidget_Arrow::GetBearingString() const
{
	if (UDeveloper_Subsystem_UnitConverter* unitConv = UDeveloper_Subsystem_UnitConverter::Get())
	{
		return unitConv->ConvertUnitsAndFormat(TEXT("degrees"), FString::Printf(TEXT("%f"), BearingDegrees), BearingUnit, 2);
	}

	return FString();
}

FString UGame_UserWidget_Arrow::GetRangeUnitString() const
{
	if (RangeUnit.Equals(TEXT("miles")) || RangeUnit.Equals(TEXT("feet")))
	{
		return TEXT("FT/MI");
	}
	else if (RangeUnit.Equals(TEXT("kilometers")) || RangeUnit.Equals(TEXT("meters")))
	{
		return TEXT("M/KM");
	}
	else if (RangeUnit.Equals(TEXT("nautical miles")))
	{
		return TEXT("NM");
	}

	return TEXT("");
}

void UGame_UserWidget_Arrow::SetRangeUnit(FString rangeUnit)
{
	if (rangeUnit != RangeUnit)
	{
		RangeUnit = rangeUnit;

		UpdateRangeText(GetRangeString());

		bExplicitUnitSelected = true;
	}
}


// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_Arrow::HandleStringSettingChanged(const FString& settingName, const FString& value)
{
	// determine if the user has selected a unit context option, if the value is the same as the current range,
	// and that the settings changed the range setting (we don't care about other settings that are changed)
	if (settingName.Equals(TEXT("RangeUnit")) && !bExplicitUnitSelected && RangeUnit != value)
	{
		RangeUnit = value;

		UpdateRangeText(GetRangeString());
	}

	if (settingName.Equals(TEXT("BearingUnit")) && !bExplicitUnitSelected && BearingUnit != value)
	{
		BearingUnit = value;

		UpdateBearingText(GetBearingString());
	}
}
