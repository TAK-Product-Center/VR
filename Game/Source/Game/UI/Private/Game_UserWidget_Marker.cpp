// Required Includes
#include "Game_UserWidget_Marker.h"
#include "Game.h"

// Engine Includes
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_Subsystem_UnitConverter.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_VirtualObjective.h"
#include "Game_TileManager.h"
#include "Game_UserWidget_DisplayItem.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Subsystem_Core.h"
#include "Game_MovementComponent.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_Marker::UGame_UserWidget_Marker(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/) :
	Super(ObjectInitializer),
	AltitudeNumDigits(2),
	DistanceNumDigits(1),
	BearingNumDigits(0),
	ElevationNumDigits(0)
{
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_Marker::NativeConstruct()
{
	Super::NativeConstruct();

	BindToPlayerState();
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_Marker::SetData(AGame_VirtualObjective* virtualObjective, const FVector& sourceLocation, const FVector& targetLocation)
{
	if (virtualObjective == nullptr)
	{
		UE_LOG(Game, Error, TEXT("Passed empty virtual objective | Marker::SetData() terminated"));
		return;
	}

	if (AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference())
	{
		FGeodeticCoord3D targetCoordinate = globeRef->WorldToGeodeticDouble(targetLocation);
		FGeodeticCoord3D sourceCoordinate = globeRef->WorldToGeodeticDouble(sourceLocation);

		SetBearing(globeRef, sourceLocation, targetLocation);
		SetDistance(sourceCoordinate, targetCoordinate);
		SetElevation(globeRef, sourceLocation, targetLocation);

		SetAltitude(targetCoordinate);
		SetLatitude(targetCoordinate.Latitude);
		SetLongitude(targetCoordinate.Longitude);
		SetMGRS(globeRef, targetLocation);
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_Marker::GetGlobeHAE(FGeodeticCoord3D& coordinate, bool& bInnerLoaded)
{
	// use dted for altitude when inner tile is not loaded
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		if (tileManager->GetTile(ETileID::Inner))
		{
			bInnerLoaded = true;
		}
		else
		{
			double hae;
			if (tileManager->GetHAEFromDTED(coordinate.ToGeodeticCoord2D(), hae))
			{
				coordinate.Altitude = hae;

				bInnerLoaded = false;
			}
		}
	}
}

void UGame_UserWidget_Marker::BindToPlayerState()
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		HandleIsInTOCUpdated(playerState->GetIsInTOC());

		playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_UserWidget_Marker::HandleIsInTOCUpdated);

		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			playerPawn->VRMovement->OnWorldTransformOverrideUpdated.AddDynamic(this, &UGame_UserWidget_Marker::HandleWorldTransformOverrideUpdated);
		}
	}
	else
	{
		FTimerHandle timeHandler;

		UWorld* world = GetWorld();
		if (ensure(world))
		{
			world->GetTimerManager().SetTimer(timeHandler, this, &UGame_UserWidget_Marker::BindToPlayerState, 0.5f, false);
		}
	}
}

void UGame_UserWidget_Marker::SetAltitude(const FGeodeticCoord3D& coordinate)
{
	UGame_TileManager* tileManager = UGame_TileManager::Get();
	if (ensure(AltitudeItem) && IsValid(tileManager))
	{
		bool bInnerLoaded = false;
		FGeodeticCoord3D modifiedCoordinate = coordinate;
		GetGlobeHAE(modifiedCoordinate, bInnerLoaded);

		double lon = modifiedCoordinate.Longitude;
		double lat = modifiedCoordinate.Latitude;
		double alt = modifiedCoordinate.Altitude;

		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

		// Adjust altitude to preferred AltitudeReference
		FString altitudeRefPref = gameSettings->GetSettingString(TEXT("AltitudeReference"));
		FGeodeticCoord3D convertedGeoLocation(lon, lat, alt);
		FString converteredString = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnits(TEXT("altitudeRef_HAE"), convertedGeoLocation.ToString(), altitudeRefPref);
		convertedGeoLocation.FromString(converteredString);
		alt = convertedGeoLocation.Altitude;

		// Get preferred AltitudeReference's display abbreviation
		// TODO: Consider adding "GetAbbrev()" call to UDeveloper_Subsystem_UnitConverter for this, instead!
		TMap<FString, FString> altitudeRefDisplayMap;
		altitudeRefDisplayMap.Add(TEXT("altitudeRef_HAE"), TEXT("HAE"));
		altitudeRefDisplayMap.Add(TEXT("altitudeRef_MSL"), TEXT("MSL"));
		altitudeRefDisplayMap.Add(TEXT("altitudeRef_AGL"), TEXT("AGL"));

		FString altitudeRefText = TEXT("HAE");
		if (altitudeRefDisplayMap.Contains(altitudeRefPref))
		{
			altitudeRefText = altitudeRefDisplayMap[altitudeRefPref];
		}

		// Adjust altitude to preferred AltitudeUnit
		FString altitudeUnitPref = gameSettings->GetSettingString(TEXT("AltitudeUnit"));
		FString altitudeText = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnitsAndFormat(TEXT("meters"), FString::Printf(TEXT("%.8Lf"), alt), altitudeUnitPref, AltitudeNumDigits);
		altitudeText += TEXT(" ") + altitudeRefText;

		int32 dtedLevel = 0;
		if (tileManager->GetDTEDLevel(lat, lon, dtedLevel) || !bInnerLoaded)
		{
			altitudeText += FString::Printf(TEXT(" DTED: %d"), dtedLevel);
		}
		
		AltitudeItem->SetText(altitudeText);
	}
}

void UGame_UserWidget_Marker::SetBearing(AVH_GlobeReferenceActor* globeRef, const FVector& sourceLocation, const FVector& targetLocation)
{
	if (ensure(BearingItem) && ensure(globeRef))
	{
		FVector sourceToTarget = targetLocation - sourceLocation;
		FRotator sourceToTargetRotation = FRotationMatrix::MakeFromX(sourceToTarget).Rotator();
		float sourceToTargetBearing = globeRef->WorldRotationToBearing(sourceToTargetRotation);

		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();
		FString bearingUnit = gameSettings->GetSettingString(TEXT("BearingUnit"));

		FString bearing = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnitsAndFormat(TEXT("degrees"), FString::Printf(TEXT("%.8Lf"), sourceToTargetBearing), bearingUnit, BearingNumDigits);
		bearing += TEXT(" T");

		BearingItem->SetText(bearing);
	}
}

void UGame_UserWidget_Marker::SetDistance(const FGeodeticCoord3D& sourceCoordinate, const FGeodeticCoord3D& targetCoordinate)
{
	if (ensure(DistanceItem))
	{
		FGeodeticCoord3D modifiedTargetCoordinate = targetCoordinate;

		bool bInnerLoaded = false;
		GetGlobeHAE(modifiedTargetCoordinate, bInnerLoaded);

		float sourceToTargetDistance = FMath::Abs<double>(sourceCoordinate.Altitude - modifiedTargetCoordinate.Altitude);

		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

		FString rangeUnit = gameSettings->GetSettingString(TEXT("RangeUnit"));

		if (rangeUnit == TEXT("miles") && sourceToTargetDistance < 1609.34f)
		{
			rangeUnit = TEXT("feet");
		}
		if (rangeUnit == TEXT("kilometers") && sourceToTargetDistance < 1000.f)
		{
			rangeUnit = TEXT("meters");
		}

		FString distanceString = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnitsAndFormat(TEXT("meters"), FString::Printf(TEXT("%.8Lf"), sourceToTargetDistance), rangeUnit, DistanceNumDigits);

		DistanceItem->SetText(distanceString);
	}
}

void UGame_UserWidget_Marker::SetElevation(AVH_GlobeReferenceActor* globeRef, const FVector& sourceLocation, const FVector& targetLocation)
{
	if (ensure(ElevationItem))
	{
		FVector sourceToTarget = targetLocation - sourceLocation;

		double sourceToTargetPitch = globeRef->WorldRotationToPitch((targetLocation - sourceLocation).Rotation());

		//float sourceToTargetPitch = FRotationMatrix::MakeFromX(sourceToTarget).Rotator().Pitch;

		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();
		FString bearingUnit = gameSettings->GetSettingString(TEXT("BearingUnit"));

		FString elevationString = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnitsAndFormat(TEXT("degrees"), FString::Printf(TEXT("%.8Lf"), sourceToTargetPitch), bearingUnit, ElevationNumDigits);

		if (elevationString[0] != TCHAR('-'))
		{
			elevationString = TEXT("+") + elevationString;
		}

		ElevationItem->SetText(elevationString);
	}
}

void UGame_UserWidget_Marker::SetLatitude(double latitude)
{
	if (ensure(LatitudeItem))
	{
		LatitudeItem->SetText(FString::Printf(TEXT("%.8Lf"), latitude));
	}
}

void UGame_UserWidget_Marker::SetLongitude(double longitude)
{
	if (ensure(LongitudeItem))
	{
		LongitudeItem->SetText(FString::Printf(TEXT("%.8Lf"), longitude));
	}
}

void UGame_UserWidget_Marker::SetMGRS(AVH_GlobeReferenceActor* globeRef, const FVector& targetLocation)
{
	if (ensure(MGRSItem) && ensure(globeRef))
	{
		FString mgrsString = globeRef->WorldToMGRS(targetLocation);
		MGRSItem->SetText(mgrsString);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_Marker::HandleIsInTOCUpdated(bool bIsInTOC)
{
	if (ensure(BottomVerticalBox))
	{
		BottomVerticalBox->SetVisibility(bIsInTOC ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}

	if (ensure(Separator))
	{
		Separator->SetVisibility(bIsInTOC ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}

	if (ensure(TopVerticalBox))
	{
		UVerticalBoxSlot* topBoxSlot = Cast<UVerticalBoxSlot>(TopVerticalBox->Slot);

		if (ensure(topBoxSlot))
		{
			topBoxSlot->SetPadding(bIsInTOC ? FMargin(10.f, 10.f, 10.f, 10.f) : FMargin(10.f, 10.f, 10.f, 0.f));
		}
	}
}

void UGame_UserWidget_Marker::HandleWorldTransformOverrideUpdated(const FTransform& worldTransform)
{
	if (!UGame_Statics::IsLocalPlayerInTOC())
	{
		bool bFirstPerson = !worldTransform.Equals(FTransform::Identity);

		BearingItem->SetVisibility(bFirstPerson ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
		ElevationItem->SetVisibility(bFirstPerson ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
}