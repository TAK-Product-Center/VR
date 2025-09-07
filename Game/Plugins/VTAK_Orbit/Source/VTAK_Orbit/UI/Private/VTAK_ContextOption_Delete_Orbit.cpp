// Required Includes
#include "VTAK_ContextOption_Delete_Orbit.h"

// Module Includes
#include "VTAK_Actor_Orbit.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVTAK_ContextOption_Delete_Orbit::PostExecute()
{
	if (AVTAK_Actor_Orbit* orbit = Cast<AVTAK_Actor_Orbit>(Source))
	{
		orbit->RemoveFromEntityDB();
	}
}