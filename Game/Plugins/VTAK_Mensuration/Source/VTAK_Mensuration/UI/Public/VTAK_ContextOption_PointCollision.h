#pragma once

// Parent Includes
#include "Game_ContextMenuOption.h"

// Generated Includes
#include "VTAK_ContextOption_PointCollision.generated.h"

UCLASS()
class VTAK_MENSURATION_API UVTAK_ContextOption_PointCollision : public UGame_ContextMenuOption
{
	GENERATED_BODY()
	

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void PostExecute() override;

	virtual FString GetText_Implementation() const override;
};
