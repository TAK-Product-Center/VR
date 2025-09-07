#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_Game_RibbonButton.generated.h"

UINTERFACE(Blueprintable)
class GAME_API UInterface_Game_RibbonButton : public UInterface
{
	GENERATED_BODY()
};

class GAME_API IInterface_Game_RibbonButton
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent)
	FString GetID();

	UFUNCTION(BlueprintNativeEvent)
	bool GetDefaultTab(FString& tab);

	UFUNCTION(BlueprintNativeEvent)
	bool GetDefaultCategory(FString& category);

	UFUNCTION(BlueprintNativeEvent)
	bool GetDefaultIndexInCategory(double& index);

	UFUNCTION(BlueprintNativeEvent)
	bool GetEnableConditions(TMap<FString, int32>& conditions);

	UFUNCTION(BlueprintNativeEvent)
	bool GetCollapseOnDisable();
};