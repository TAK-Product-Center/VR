#pragma once

// Parent include
#include "Game_ContextMenuOption.h"

// Generated Includes
#include "VTAK_ContextOption_Orbit_Orbit.generated.h"

UCLASS()
class VTAK_ORBIT_API UVTAK_ContextOption_Orbit_Orbit : public UGame_ContextMenuOption
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
