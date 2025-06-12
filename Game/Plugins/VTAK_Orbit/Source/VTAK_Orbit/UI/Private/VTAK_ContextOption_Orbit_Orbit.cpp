// Required include
#include "VTAK_ContextOption_Orbit_Orbit.h"

// VTAK Orbit module includes
#include "VTAK_Actor_Orbit.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVTAK_ContextOption_Orbit_Orbit::PostExecute()
{
	if (AVTAK_Actor_Orbit* orbit = Cast<AVTAK_Actor_Orbit>(Source))
	{
		orbit->SetOrbit(!orbit->GetOrbit());
	}
}