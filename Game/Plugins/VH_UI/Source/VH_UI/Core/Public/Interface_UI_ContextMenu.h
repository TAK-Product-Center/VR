#pragma once

#include "UObject/Interface.h"

#include "Interface_UI_ContextMenu.generated.h"

class UI_ContextOption;

UINTERFACE(Blueprintable)
class VH_UI_API UInterface_UI_ContextMenu : public UInterface
{
	GENERATED_BODY()
};

class VH_UI_API IInterface_UI_ContextMenu
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent)
	void SetContextMenuInformation(AActor* instigator, UObject* source, const TSet<UObject*>& contextOptions);
};
