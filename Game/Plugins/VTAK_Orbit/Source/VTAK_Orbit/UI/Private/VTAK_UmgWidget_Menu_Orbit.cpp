// Required Includes
#include "VTAK_UmgWidget_Menu_Orbit.h"

// VH Plugin Includes
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "Developer_Subsystem_UnitConverter.h"
#include "UI_Subsystem_Core.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_Subsystem_Core.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"

// Module Includes
#include "VTAK_DatabaseComponent_Orbit.h"
#include "VTAK_Actor_Orbit.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVTAK_UmgWidget_Menu_Orbit::UVTAK_UmgWidget_Menu_Orbit(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UVTAK_UmgWidget_Menu_Orbit::Initialize()
{
	bool bReturn = Super::Initialize();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->OnStringSettingStored.AddDynamic(this, &UVTAK_UmgWidget_Menu_Orbit::HandleStringSettingStored);
	}
	
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnPageIn.AddDynamic(this, &UVTAK_UmgWidget_Menu_Orbit::HandlePageIn);
		entityDB->OnPageOut.AddDynamic(this, &UVTAK_UmgWidget_Menu_Orbit::HandlePageOut);
		entityDB->OnDelete.AddDynamic(this, &UVTAK_UmgWidget_Menu_Orbit::HandleDelete);
	}

	return bReturn;
}

void UVTAK_UmgWidget_Menu_Orbit::NativeConstruct()
{
	Super::NativeConstruct();

	PopulateFromDatabase();

	BindToOrbitActor(true);
}

// ---------------------------------
// --- API
// ---------------------------------

void UVTAK_UmgWidget_Menu_Orbit::SetRadius(const FString& radiusString)
{
	UDeveloper_Subsystem_UnitConverter* unitConverter = UDeveloper_Subsystem_UnitConverter::Get();
	UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

	if (unitConverter != nullptr && gameSettings != nullptr)
	{
		FString distanceUnit = gameSettings->GetSettingString(TEXT("RangeUnit"));

		FString radiusMeters = unitConverter->ConvertUnits(distanceUnit, radiusString, TEXT("meters"));
		UVTAK_DatabaseComponent_Orbit::SetRadius(FCString::Atod(*radiusMeters));
	}
}

void UVTAK_UmgWidget_Menu_Orbit::SetSpeed(const FString& speedString)
{
	UDeveloper_Subsystem_UnitConverter* unitConverter = UDeveloper_Subsystem_UnitConverter::Get();
	UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

	if (unitConverter != nullptr && gameSettings != nullptr)
	{
		FString distanceUnit = gameSettings->GetSettingString(TEXT("RangeUnit"));

		FString speedMeters = unitConverter->ConvertUnits(distanceUnit, speedString, TEXT("meters"));
		UVTAK_DatabaseComponent_Orbit::SetSpeed(FCString::Atod(*speedMeters));
	}
}

void UVTAK_UmgWidget_Menu_Orbit::ToggleOrbit()
{
	if (AVTAK_Actor_Orbit* orbitActor = GetOrbitActor())
	{
		orbitActor->SetOrbit(!orbitActor->GetOrbit());
	}
}

void UVTAK_UmgWidget_Menu_Orbit::TogglePause()
{
	if (AVTAK_Actor_Orbit* orbitActor = GetOrbitActor())
	{
		orbitActor->SetPause(!orbitActor->GetPause());
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AVTAK_Actor_Orbit* UVTAK_UmgWidget_Menu_Orbit::GetOrbitActor() const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		TSet<AActor*> actors = virtualObjective->GetActorsForEntity(UVTAK_DatabaseComponent_Orbit::GetEntityUID());
		for (AActor* actor : actors)
		{
			return Cast<AVTAK_Actor_Orbit>(actor);
		}
	}

	return nullptr;
}

void UVTAK_UmgWidget_Menu_Orbit::PopulateFromDatabase()
{
	FGeodeticCoord3D coordinate;
	double radius;
	double speed;
	if (UVTAK_DatabaseComponent_Orbit::GetData(coordinate, radius, speed))
	{
		UDeveloper_Subsystem_UnitConverter* unitConverter = UDeveloper_Subsystem_UnitConverter::Get();
		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

		if (unitConverter != nullptr && gameSettings != nullptr)
		{
			ReceiveSetCoordinate(coordinate);

			FString distanceUnit = gameSettings->GetSettingString(TEXT("RangeUnit"));

			FString radiusString = unitConverter->ConvertUnits(TEXT("meters"), FString::Printf(TEXT("%f"), radius), distanceUnit);
			FString radiusUnit = unitConverter->GetAbbreviationFromName(distanceUnit);
			ReceiveSetRadius(radiusString, radiusUnit);

			FString speedString = unitConverter->ConvertUnits(TEXT("meters"), FString::Printf(TEXT("%f"), speed), distanceUnit);
			FString speedUnit = unitConverter->GetAbbreviationFromName(distanceUnit);
			ReceiveSetSpeed(speedString, speedUnit);
		}
	}
}

void UVTAK_UmgWidget_Menu_Orbit::BindToOrbitActor(bool bBind)
{
	if (AVTAK_Actor_Orbit* orbitActor = GetOrbitActor())
	{
		if (bBind)
		{
			orbitActor->OnSetOrbit.AddDynamic(this, &UVTAK_UmgWidget_Menu_Orbit::ReceiveSetOrbit);
			orbitActor->OnSetPause.AddDynamic(this, &UVTAK_UmgWidget_Menu_Orbit::ReceiveSetPause);
		}
		else
		{
			orbitActor->OnSetOrbit.RemoveAll(this);
			orbitActor->OnSetPause.RemoveAll(this);
		}

		ReceiveSetPause(orbitActor->GetPause());
		ReceiveSetOrbit(orbitActor->GetOrbit());
	}
	else
	{
		ReceiveSetPause(false);
		ReceiveSetOrbit(false);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UVTAK_UmgWidget_Menu_Orbit::HandleStringSettingStored(const FString& settingName, const FString& value)
{
	if (settingName.Equals(TEXT("AltitudeUnit")) || settingName.Equals(TEXT("RangeUnit")) || settingName.Equals(TEXT("AltitudeReference")))
	{
		PopulateFromDatabase();
	}
}

void UVTAK_UmgWidget_Menu_Orbit::HandlePageIn(const FString& entityUID, AGame_VirtualObjective* virtualObjective)
{
	if (entityUID.Equals(UVTAK_DatabaseComponent_Orbit::GetEntityUID()))
	{
		BindToOrbitActor(true);
	}
}

void UVTAK_UmgWidget_Menu_Orbit::HandlePageOut(const FString& entityUID, AGame_VirtualObjective* virtualObjective)
{
	if (entityUID.Equals(UVTAK_DatabaseComponent_Orbit::GetEntityUID()))
	{
		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			subsystem->CloseUserWidget(this);
		}

		BindToOrbitActor(false);
	}
}

void UVTAK_UmgWidget_Menu_Orbit::HandleDelete(const FSpatialiteResults_BP& results)
{
	for (const FSpatialiteResult_BP& resultBP : results.Results)
	{
		SpatialiteResult result = resultBP.Result;

		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		if (entityUID.Equals(UVTAK_DatabaseComponent_Orbit::GetEntityUID()))
		{
			if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
			{
				subsystem->CloseUserWidget(this);
			}

			BindToOrbitActor(false);
		}
	}
}