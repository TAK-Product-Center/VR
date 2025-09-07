#pragma once

// Parent Includes
#include "Game_ContextMenuOption.h"

// Generated Includes
#include "VTAK_ContextOption_Menu_Orbit.generated.h"

class UVTAK_UmgWidget_Menu_Orbit;

UCLASS()
class VTAK_ORBIT_API UVTAK_ContextOption_Menu_Orbit : public UGame_ContextMenuOption
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UVTAK_UmgWidget_Menu_Orbit> WidgetClass;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void PostExecute() override;
};
