// Required Includes
#include "VTAK_Actor_Mensuration_Angle.h"
#include "VTAK_Mensuration.h"

// VH Plugin Includes
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "Developer_Subsystem_UnitConverter.h"

// Game Includes
#include "Game_Subsystem_Core.h"

// Module Includes
#include "VTAK_UmgWidget_MensurationLine.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AVTAK_Actor_Mensuration_Angle::AVTAK_Actor_Mensuration_Angle()
{
	AllowedBaseTranslation = EAxisListBlueprint::XY;
	AllowedArrowTranslation = EAxisListBlueprint::Z;

	AllowedBaseRotation = EAxisListBlueprint::Z;
	AllowedArrowRotation = EAxisListBlueprint::Z;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AVTAK_Actor_Mensuration_Angle::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (UVTAK_UmgWidget_MensurationLine* widget = Cast<UVTAK_UmgWidget_MensurationLine>(ArrowWidget))
	{
		UDeveloper_Subsystem_UnitConverter* unitConverter = UDeveloper_Subsystem_UnitConverter::Get();
		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

		if (unitConverter != nullptr && gameSettings != nullptr)
		{
			FString bearingUnit = gameSettings->GetSettingString(TEXT("BearingUnit"));
			
			widget->ReceiveSetAngle(FString::Printf(TEXT("%f%s"), GetAngle(bearingUnit), *unitConverter->GetAbbreviationFromName(bearingUnit)));
		}
	}
}