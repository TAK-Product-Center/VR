#pragma once

// Parent Includes
#include "Game_ContextMenuOption.h"

// Generated Includes
#include "VTAK_ContextOption_DetailMenu.generated.h"

UCLASS()
class VTAK_MENSURATION_API UVTAK_ContextOption_DetailMenu : public UGame_ContextMenuOption
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	/**
	 * This will launch the detail menu when the context option is selected
	 */
	virtual void PostExecute() override;
};
