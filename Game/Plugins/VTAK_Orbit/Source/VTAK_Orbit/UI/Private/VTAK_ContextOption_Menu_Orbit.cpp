// Required Includes
#include "VTAK_ContextOption_Menu_Orbit.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"

// Module Includes
#include "VTAK_UmgWidget_Menu_Orbit.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVTAK_ContextOption_Menu_Orbit::PostExecute()
{
	if (WidgetClass != nullptr)
	{
		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			subsystem->OpenWithDefaultsByClass(WidgetClass);
		}
	}
}