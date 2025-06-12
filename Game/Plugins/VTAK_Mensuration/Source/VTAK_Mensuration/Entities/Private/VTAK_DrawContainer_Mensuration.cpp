// Required Includes
#include "VTAK_DrawContainer_Mensuration.h"

// Module Includes
#include "VTAK_COTComponent_DrawMensuration.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AVTAK_DrawContainer_Mensuration::AVTAK_DrawContainer_Mensuration()
{
	MensurationCOTComponent = CreateDefaultSubobject<UVTAK_COTComponent_DrawMensuration>(TEXT("MensurationCOTComponent"));
}