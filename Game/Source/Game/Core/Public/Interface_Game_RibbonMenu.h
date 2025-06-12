#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_Game_RibbonMenu.generated.h"

UINTERFACE(Blueprintable)
class GAME_API UInterface_Game_RibbonMenu : public UInterface
{
	GENERATED_BODY()
};

class GAME_API IInterface_Game_RibbonMenu
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent)
	void AddButton(UUserWidget* buttonWidget, const FString& tab, double indexOfTab, const FString& category, double indexOfCategory, double indexWithinCategory);

	UFUNCTION(BlueprintNativeEvent)
	void RemoveButton(UUserWidget* buttonWidget, const FString& tab, const FString& category);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateContainerVisibility();
};