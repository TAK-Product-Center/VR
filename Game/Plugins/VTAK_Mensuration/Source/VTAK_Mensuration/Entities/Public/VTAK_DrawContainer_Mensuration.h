#pragma once

// Paren Includes
#include "Game_DrawContainer.h"

// Generated Includes
#include "VTAK_DrawContainer_Mensuration.generated.h"

class UVTAK_COTComponent_DrawMensuration;

UCLASS(Blueprintable, BlueprintType)
class VTAK_MENSURATION_API AVTAK_DrawContainer_Mensuration : public AGame_DrawContainer
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UVTAK_COTComponent_DrawMensuration* MensurationCOTComponent;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_DrawContainer_Mensuration();
};
