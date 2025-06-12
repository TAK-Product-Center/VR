// Required Includes
#include "VTAK_UmgWidget_MensurationDetail.h"

// VH Plugin Includes
#include "VTAK_EditPoint_Mensuration.h"

// Game Includes
#include "Game_SimpleSegmentedLineActor.h"

// Module Includes
#include "VTAK_Actor_Mensuration.h"
#include "VTAK_UmgWidget_MensurationLine.h"

// ---------------------------------
// --- Public
// ---------------------------------

bool UVTAK_UmgWidget_MensurationDetail::Init(AVTAK_Actor_Mensuration* const mensuration)
{
	if (mensuration)
	{
		Mensuration = mensuration;

		UpdateUI();

		Mensuration->GetBaseEditPoint()->OnManipulationEnd.AddDynamic(this, &UVTAK_UmgWidget_MensurationDetail::HandleOnManipulationEnd);
		Mensuration->GetArrowEditPoint()->OnManipulationEnd.AddDynamic(this, &UVTAK_UmgWidget_MensurationDetail::HandleOnManipulationEnd);
		Mensuration->GetLine()->OnManipulationEnd.AddDynamic(this, &UVTAK_UmgWidget_MensurationDetail::HandleOnManipulationEnd);

		return true;
	}

	return false;
}

void UVTAK_UmgWidget_MensurationDetail::UpdateUI()
{
	if (Mensuration)
	{
		UpdateAngle(GetAngle(Mensuration->AngleUnit));
		UpdateAngleUnit(GetAngleUnit());
		UpdateAngleLock(GetAngleLock());
		UpdateBearing(GetBearing(Mensuration->BearingUnit));
		UpdateBearingUnit(GetBearingUnit());
		UpdateBearingLock(GetBearingLock());
		UpdateLength(GetLength(Mensuration->LengthUnit));
		UpdateLengthUnit(GetLengthUnit());
		UpdateLengthLock(GetLengthLock());
		UpdateLock(GetLock());
		UpdatePointCollision(GetPointCollision());
	}
}

const float UVTAK_UmgWidget_MensurationDetail::GetAngle(const FString& unit) const
{
	if (Mensuration)
	{
		return Mensuration->GetAngle(unit);
	}

	return -91.f;
}

const FString UVTAK_UmgWidget_MensurationDetail::GetAngleUnit() const
{
	if (Mensuration)
	{
		return Mensuration->AngleUnit;
	}

	return TEXT("");
}

bool UVTAK_UmgWidget_MensurationDetail::GetAngleLock() const
{
	if (Mensuration)
	{
		return Mensuration->bIsAngleLocked;
	}

	return false;
}

const float UVTAK_UmgWidget_MensurationDetail::GetBearing(const FString& unit) const
{
	if (Mensuration)
	{
		return Mensuration->GetBearing(unit);
	}

	return -1.f;
}

const FString UVTAK_UmgWidget_MensurationDetail::GetBearingUnit() const
{
	if (Mensuration)
	{
		return Mensuration->BearingUnit;
	}

	return TEXT("");
}

bool UVTAK_UmgWidget_MensurationDetail::GetBearingLock() const
{
	if (Mensuration)
	{
		return Mensuration->bIsBearingLocked;
	}

	return false;
}

const float UVTAK_UmgWidget_MensurationDetail::GetLength(const FString& unit) const
{
	if (Mensuration)
	{
		return Mensuration->GetLength(unit);
	}

	return -1.f;
}

const FString UVTAK_UmgWidget_MensurationDetail::GetLengthUnit() const
{
	if (Mensuration)
	{
		return Mensuration->LengthUnit;
	}

	return TEXT("");
}

bool UVTAK_UmgWidget_MensurationDetail::GetLengthLock() const
{
	if (Mensuration)
	{
		return Mensuration->bIsLengthLocked;
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::GetLock() const
{
	if (Mensuration)
	{
		return !Mensuration->GetActive();
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::GetPointCollision() const
{
	if (Mensuration)
	{
		return Mensuration->GetPointCollision();
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetAngle(const float& angle, const FString& unit)
{
	if (Mensuration)
	{
		Mensuration->SetAngle(angle, unit);

		return true;
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetAngleLock(bool bLock)
{
	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetAngleUnit(const FString& unit)
{
	if (Mensuration)
	{
		if ((unit.Equals(TEXT("degrees")) || unit.Equals(TEXT("milliradians"))))
		{
			Mensuration->AngleUnit = unit;

			if (!Mensuration->bIsAngleUnitManuallySet)
			{
				Mensuration->bIsAngleUnitManuallySet = true;
			}

			return true;
		}
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetBearing(const float& bearing, const FString& unit)
{
	if (Mensuration)
	{
		Mensuration->SetBearing(bearing, unit);

		return true;
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetBearingLock(bool bLock)
{
	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetBearingUnit(const FString& unit)
{
	if (Mensuration)
	{
		if ((unit.Equals(TEXT("degrees")) || unit.Equals(TEXT("milliradians"))))
		{
			Mensuration->BearingUnit = unit;

			if (!Mensuration->bIsBearingUnitManuallySet)
			{
				Mensuration->bIsBearingUnitManuallySet = true;
			}

			return true;
		}
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetLength(const float& length, const FString& unit)
{
	if (Mensuration)
	{
		Mensuration->SetLength(length, unit);

		return true;
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetLengthLock(bool bLock)
{
	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetLengthUnit(const FString& unit)
{
	if (Mensuration)
	{
		if ((unit.Equals(TEXT("feet")) || unit.Equals(TEXT("meters"))))
		{
			Mensuration->LengthUnit = unit;

			if (!Mensuration->bIsLengthUnitManuallySet)
			{
				Mensuration->bIsLengthUnitManuallySet = true;
			}
		}

		if (UVTAK_UmgWidget_MensurationLine* lineWidget = Cast<UVTAK_UmgWidget_MensurationLine>(Mensuration->GetUIWidget()))
		{
			lineWidget->SetRangeUnit(unit);

			return true;
		}
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetLock(bool bLock)
{
	if (Mensuration)
	{
		Mensuration->SetActive(!bLock);

		return true;
	}

	return false;
}

bool UVTAK_UmgWidget_MensurationDetail::SetPointCollision(bool bEnableCollision)
{
	if (Mensuration)
	{
		Mensuration->SetPointCollision(bEnableCollision);

		return true;
	}

	return false;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UVTAK_UmgWidget_MensurationDetail::HandleOnManipulationEnd(AActor* manipulatedActor)
{
	UpdateUI();
}