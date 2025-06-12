// Required Includes
#include "VTAK_ContextOption_DetailMenu.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"

// Module Includes
#include "VTAK_Actor_Mensuration.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVTAK_ContextOption_DetailMenu::PostExecute()
{
	// Get owner of the edit point or line which should be the VTAK_Actor_Mensuration object
	if (AActor* actor = Cast<AActor>(Source))
	{
		if (AVTAK_Actor_Mensuration* mensuration = Cast<AVTAK_Actor_Mensuration>(actor->GetOwner()))
		{
			if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
			{
				if (UVTAK_UmgWidget_MensurationDetail* mensurationMenu = Cast<UVTAK_UmgWidget_MensurationDetail>(subsystem->OpenWithDefaultsByClass(mensuration->MensurationDetailClass)))
				{
					mensurationMenu->Init(mensuration);
				}
			}
		}
	}
}