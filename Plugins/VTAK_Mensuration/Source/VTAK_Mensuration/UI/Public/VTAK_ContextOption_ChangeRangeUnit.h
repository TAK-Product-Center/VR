#pragma once

// Parent Includes
#include "Game_ContextMenuOption.h"

// Generated Includes
#include "VTAK_ContextOption_ChangeRangeUnit.generated.h"

// Forward declarations
class UVTAK_UmgWidget_MensurationLine;

UCLASS()
class VTAK_MENSURATION_API UVTAK_ContextOption_ChangeRangeUnit : public UGame_ContextMenuOption
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual FString GetText_Implementation() const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/**
	 * Returns the UI widget of the Mensuration from the mensuration line
	 */
	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	UVTAK_UmgWidget_MensurationLine* GetUIWidget(UObject* context) const;
};
