#pragma once

#include "UObject/Interface.h"

#include "Interface_UI_TabContainer.generated.h"

UINTERFACE(Blueprintable)
class VH_UI_API UInterface_UI_TabContainer : public UInterface
{
	GENERATED_BODY()
};

class VH_UI_API IInterface_UI_TabContainer
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddTab(UUserWidget* tab);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveTab(UUserWidget* tab);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveAllTabs();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetFocusedTab(UUserWidget* tab);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 GetNumberOfTabs() const;
};
