// Required Includes
#include "VTAK_Actor_Mensuration.h"
#include "VTAK_Mensuration.h"

// Engine Includes
#include "Kismet/KismetMathLibrary.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "Developer_Subsystem_UnitConverter.h"
#include "Game_Subsystem_Core.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_EditPoint.h"
#include "Game_EntityDB.h"
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"
#include "Game_PlayerController.h"

// Module Includes
#include "VTAK_COTComponent_DrawMensuration.h"
#include "VTAK_DrawContainer_Mensuration.h"
#include "VTAK_EditPoint_Mensuration.h"
#include "VTAK_Line_Mensuration.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AVTAK_Actor_Mensuration::AVTAK_Actor_Mensuration()
{
	bPointArrowEditPoint = false;

	AllowedLineRotation = EAxisListBlueprint::Z;
	AllowedLineTranslation = EAxisListBlueprint::XYZ;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AVTAK_Actor_Mensuration::BeginPlay()
{
	Super::BeginPlay();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		AngleUnit = gameSettings->GetSettingString(TEXT("BearingUnit"));
		BearingUnit = AngleUnit;
		
		FString settingsLengthRangeUnit = gameSettings->GetSettingString(TEXT("RangeUnit"));

		if (settingsLengthRangeUnit.Equals(TEXT("miles")))
		{
			LengthUnit = TEXT("feet");
		}
		else if (settingsLengthRangeUnit.Equals(TEXT("kilometers")))
		{
			LengthUnit = TEXT("meters");
		}

		gameSettings->OnStringSettingStored.AddUniqueDynamic(this, &AVTAK_Actor_Mensuration::HandleStringSettingStored);
	}
}

void AVTAK_Actor_Mensuration::SpawnEditPointsAndLine()
{
	Super::SpawnEditPointsAndLine();

	if (UWorld* world = GetWorld())
	{
		if (AVTAK_Line_Mensuration* mensurationLine = Cast<AVTAK_Line_Mensuration>(Line))
		{
			mensurationLine->MensurationActor = this;
		}

		if (AVTAK_EditPoint_Mensuration* mensurationBasePoint = Cast<AVTAK_EditPoint_Mensuration>(BaseEditPoint))
		{
			mensurationBasePoint->MensurationActor = this;
			mensurationBasePoint->bBase = true;
		}

		if (AVTAK_EditPoint_Mensuration* mensurationArrowPoint = Cast<AVTAK_EditPoint_Mensuration>(ArrowEditPoint))
		{
			mensurationArrowPoint->MensurationActor = this;
		}
	}

	PostSpawnEditPoints();

	ReceivePostSpawnEditPoints();
}

// ---------------------------------
// --- API
// ---------------------------------

bool AVTAK_Actor_Mensuration::GetActive() const
{
	if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
	{
		return BaseEditPoint->GetActive() && ArrowEditPoint->GetActive();
	}

	return false;
}

float AVTAK_Actor_Mensuration::GetAngle_Implementation(const FString& unit) const
{
	if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
	{
		FVector baseEditPointLoc = BaseEditPoint->GetActorLocation();
		FVector endEditPointLoc = ArrowEditPoint->GetActorLocation();
		FVector direction = endEditPointLoc - baseEditPointLoc;

		double angle = 0;
		if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
			{
				angle = globeReference->WorldRotationToPitch(direction.Rotation());
			}
		}

		if (UDeveloper_Subsystem_UnitConverter* subsystem = UDeveloper_Subsystem_UnitConverter::Get())
		{
			return FCString::Atof(*subsystem->ConvertUnitsAndFormat(TEXT("degrees"), FString::Printf(TEXT("%f"), angle), unit, 2));
		}
	}

	return 0;
}

float AVTAK_Actor_Mensuration::GetBearing_Implementation(const FString& unit) const
{
	if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
	{
		FVector baseEditPointLoc = BaseEditPoint->GetActorLocation();
		FVector endEditPointLoc = ArrowEditPoint->GetActorLocation();
		FVector direction = endEditPointLoc - baseEditPointLoc;

		float bearing;
		float angle;
		UKismetMathLibrary::GetAzimuthAndElevation(direction, BaseEditPoint->GetTransform(), bearing, angle);

		if (UDeveloper_Subsystem_UnitConverter* subsystem = UDeveloper_Subsystem_UnitConverter::Get())
		{
			bearing = FCString::Atof(*subsystem->ConvertUnitsAndFormat(TEXT("degrees"), FString::Printf(TEXT("%f"), bearing), unit, 2));
		}

		if (bearing < 0.f && unit.Equals(TEXT("degrees")))
		{
			bearing += 360.f;
		}

		return bearing;
	}

	return -1.f;
}

TArray<AVTAK_EditPoint_Mensuration*> AVTAK_Actor_Mensuration::GetEditPoints_Implementation() const
{
	TArray<AVTAK_EditPoint_Mensuration*> editPoints;

	editPoints.Add(Cast<AVTAK_EditPoint_Mensuration>(GetBaseEditPoint()));
	editPoints.Add(Cast<AVTAK_EditPoint_Mensuration>(GetArrowEditPoint()));

	return editPoints;
}

float AVTAK_Actor_Mensuration::GetLength_Implementation(const FString& unit) const
{
	if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
	{
		float lengthInMeters = FVector::Dist(BaseEditPoint->GetActorLocation(), ArrowEditPoint->GetActorLocation()) / 100.f;

		if (UDeveloper_Subsystem_UnitConverter* subsystem = UDeveloper_Subsystem_UnitConverter::Get())
		{
			return FCString::Atof(*subsystem->ConvertUnitsAndFormat(TEXT("meters"), FString::Printf(TEXT("%f"), lengthInMeters), unit, 2));
		}
	}

	return -1.f;
}

bool AVTAK_Actor_Mensuration::GetPointCollision() const
{
	if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
	{
		AVTAK_EditPoint_Mensuration* baseMensurationEditPoint = Cast<AVTAK_EditPoint_Mensuration>(BaseEditPoint);
		AVTAK_EditPoint_Mensuration* endMensurationEditPoint = Cast<AVTAK_EditPoint_Mensuration>(ArrowEditPoint);

		if (baseMensurationEditPoint && endMensurationEditPoint)
		{
			return baseMensurationEditPoint->bCollideDuringManipulation || endMensurationEditPoint->bCollideDuringManipulation;
		}
	}

	return false;
}

bool AVTAK_Actor_Mensuration::SetActive(bool bActive)
{
	if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
	{
		BaseEditPoint->SetActive(bActive);
		ArrowEditPoint->SetActive(bActive);

		return true;
	}
	
	return false;
}

bool AVTAK_Actor_Mensuration::SetAngle_Implementation(float angle, const FString& unit)
{
	if (UDeveloper_Subsystem_UnitConverter* subsystem = UDeveloper_Subsystem_UnitConverter::Get())
	{
		float angleInDegrees = FCString::Atof(*subsystem->ConvertUnitsAndFormat(unit, FString::Printf(TEXT("%f"), angle), TEXT("degrees"), 2));

		if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
		{
			FVector baseEditPointLoc = BaseEditPoint->GetActorLocation();
			FVector endEditPointLoc = ArrowEditPoint->GetActorLocation();
			FVector direction = endEditPointLoc - baseEditPointLoc;

			float outBearing;
			float outAngle;
			UKismetMathLibrary::GetAzimuthAndElevation(direction, BaseEditPoint->GetTransform(), outBearing, outAngle);

			FVector rightVectorOfDirection = FVector::CrossProduct(direction, FVector::UpVector).GetSafeNormal();
			direction = direction.RotateAngleAxis(angleInDegrees - outAngle, rightVectorOfDirection);

			if (AVTAK_EditPoint_Mensuration* endPoint = Cast<AVTAK_EditPoint_Mensuration>(ArrowEditPoint))
			{
				endPoint->SetActorLocation(baseEditPointLoc + direction);

				endPoint->PersistWorldLocation();

				return true;
			}
		}
	}

	return false;
}

bool AVTAK_Actor_Mensuration::SetBearing_Implementation(float bearing, const FString& unit)
{
	if (UDeveloper_Subsystem_UnitConverter* subsystem = UDeveloper_Subsystem_UnitConverter::Get())
	{
		float bearingInDegrees = FCString::Atof(*subsystem->ConvertUnitsAndFormat(unit, FString::Printf(TEXT("%f"), bearing), TEXT("degrees"), 2));

		if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
		{
			FVector baseEditPointLoc = BaseEditPoint->GetActorLocation();
			FVector endEditPointLoc = ArrowEditPoint->GetActorLocation();
			FVector direction = endEditPointLoc - baseEditPointLoc;

			float outBearing;
			float outAngle;
			UKismetMathLibrary::GetAzimuthAndElevation(direction, BaseEditPoint->GetTransform(), outBearing, outAngle);

			direction = direction.RotateAngleAxis(bearingInDegrees - outBearing, FVector::UpVector);

			if (AVTAK_EditPoint_Mensuration* endPoint = Cast<AVTAK_EditPoint_Mensuration>(ArrowEditPoint))
			{
				endPoint->SetActorLocation(baseEditPointLoc + direction);

				endPoint->PersistWorldLocation();

				return true;
			}
		}
	}

	return false;
}

bool AVTAK_Actor_Mensuration::SetLength_Implementation(float length, const FString& unit)
{
	UE_LOG(LogTemp, Warning, TEXT("-- AVTAK_Actor_Mensuration::SetLength_Implementation"));
	if (!FMath::IsNearlyZero(length, 0.01f))
	{
		if (UDeveloper_Subsystem_UnitConverter* subsystem = UDeveloper_Subsystem_UnitConverter::Get())
		{
			float lengthInMeters = FCString::Atof(*subsystem->ConvertUnitsAndFormat(unit, FString::Printf(TEXT("%f"), length), TEXT("meters"), 2));

			if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
			{
				FVector baseEditPointLoc = BaseEditPoint->GetActorLocation();
				FVector endEditPointLoc = ArrowEditPoint->GetActorLocation();

				FVector direction = endEditPointLoc - baseEditPointLoc;
				FVector directionHeightScaled = direction.GetSafeNormal() * (lengthInMeters * 100.f);

				if (AVTAK_EditPoint_Mensuration* endPoint = Cast<AVTAK_EditPoint_Mensuration>(ArrowEditPoint))
				{
					endPoint->SetActorLocation(baseEditPointLoc + directionHeightScaled);

					endPoint->PersistWorldLocation();

					return true;
				}
			}
		}
	}

	return false;
}

bool AVTAK_Actor_Mensuration::SetPointCollision(bool bEnableCollision)
{
	if (BaseEditPoint != nullptr && ArrowEditPoint != nullptr)
	{
		AVTAK_EditPoint_Mensuration* baseMensurationEditPoint = Cast<AVTAK_EditPoint_Mensuration>(BaseEditPoint);
		AVTAK_EditPoint_Mensuration* endMensurationEditPoint = Cast<AVTAK_EditPoint_Mensuration>(ArrowEditPoint);

		if (baseMensurationEditPoint && endMensurationEditPoint)
		{
			baseMensurationEditPoint->bCollideDuringManipulation = bEnableCollision;
			endMensurationEditPoint->bCollideDuringManipulation = bEnableCollision;

			return true;
		}
	}

	return false;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AVTAK_Actor_Mensuration::PostSpawnEditPoints()
{

}

bool AVTAK_Actor_Mensuration::RemoveEntityFromDB()
{
	if (Line != nullptr)
	{
		UGame_EntityDB* entityDB = UGame_EntityDB::Get();
		AVTAK_DrawContainer_Mensuration* mensurationDrawContainer = Cast<AVTAK_DrawContainer_Mensuration>(Line->DrawContainer);

		if (entityDB && mensurationDrawContainer)
		{
			if (UVTAK_COTComponent_DrawMensuration* mensurationCOTComponent = mensurationDrawContainer->MensurationCOTComponent)
			{
				if (UVH_COTEvent* mensurationCotEvent = mensurationCOTComponent->GetCurrentCOTEvent())
				{
					entityDB->Delete(UVH_COTManager::GetDataLoader_COT_ClassUID(), mensurationCotEvent->GetAttribute(TEXT("uid")));

					return true;
				}
			}
		}
	}

	return false;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AVTAK_Actor_Mensuration::HandleStringSettingStored(const FString& settingName, const FString& settingValue)
{
	if (settingName.Equals(TEXT("BearingUnit")))
	{
		if (!bIsAngleUnitManuallySet && (settingValue.Equals(TEXT("degrees")) || settingValue.Equals(TEXT("milliradians"))))
		{
			AngleUnit = settingValue;
		}

		if (!bIsBearingUnitManuallySet && (settingValue.Equals(TEXT("degrees")) || settingValue.Equals(TEXT("milliradians"))))
		{
			BearingUnit = settingValue;
		}
	}

	if (settingName.Equals(TEXT("RangeUnit")) && !bIsLengthUnitManuallySet)
	{
		if (settingValue.Equals(TEXT("miles")))
		{
			LengthUnit = TEXT("feet");
		}
		else if (settingValue.Equals(TEXT("kilometers")))
		{
			LengthUnit = TEXT("meters");
		}
	}
}