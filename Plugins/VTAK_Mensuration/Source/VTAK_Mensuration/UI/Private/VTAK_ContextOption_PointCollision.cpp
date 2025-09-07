// Required Includes
#include "VTAK_ContextOption_PointCollision.h"

// Module Includes
#include "VTAK_EditPoint_Mensuration.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVTAK_ContextOption_PointCollision::PostExecute()
{
	if (AVTAK_EditPoint_Mensuration* editPoint = Cast<AVTAK_EditPoint_Mensuration>(Source))
	{
		editPoint->bCollideDuringManipulation = !editPoint->bCollideDuringManipulation;

		OnVisualsChanged.Broadcast();
	}
}

FString UVTAK_ContextOption_PointCollision::GetText_Implementation() const
{
	if (AVTAK_EditPoint_Mensuration* editPoint = Cast<AVTAK_EditPoint_Mensuration>(Source))
	{
		return editPoint->bCollideDuringManipulation ? TEXT("Disable Collision") : TEXT("Enable Collision");
	}

	return TEXT("");
}