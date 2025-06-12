// Required Includes
#include "VTAK_ContextOption_ChangeRangeUnit.h"

// Module Includes
#include "VTAK_Actor_Mensuration.h"
#include "VTAK_EditPoint_Mensuration.h"
#include "VTAK_Line_Mensuration.h"
#include "VTAK_UmgWidget_MensurationLine.h"

FString UVTAK_ContextOption_ChangeRangeUnit::GetText_Implementation() const
{
	if (UGame_UserWidget_Arrow* uiArrowWidget = GetUIWidget(Source))
	{
		if (UVTAK_UmgWidget_MensurationLine* uiMensurationLineWidget = Cast<UVTAK_UmgWidget_MensurationLine>(uiArrowWidget))
		{
			return uiMensurationLineWidget->GetRangeUnitString();
		}
	}

	return TEXT("");
}

// ---------------------------------
// --- API
// ---------------------------------

UVTAK_UmgWidget_MensurationLine* UVTAK_ContextOption_ChangeRangeUnit::GetUIWidget_Implementation(UObject* context) const
{
	AVTAK_Line_Mensuration* line = Cast<AVTAK_Line_Mensuration>(context);
	if (!line)
	{
		if (AVTAK_EditPoint_Mensuration* point = Cast<AVTAK_EditPoint_Mensuration>(context))
		{
			if (AGame_SimpleSegmentedLineActor* gameLine = point->GetLineActor())
			{
				line = Cast<AVTAK_Line_Mensuration>(gameLine);
			}
		}
	}

	if (line)
	{
		if (AVTAK_Actor_Mensuration* mensuration = Cast<AVTAK_Actor_Mensuration>(line->GetOwner()))
		{
			return Cast<UVTAK_UmgWidget_MensurationLine>(mensuration->GetUIWidget());
		}
	}

	return nullptr;
}