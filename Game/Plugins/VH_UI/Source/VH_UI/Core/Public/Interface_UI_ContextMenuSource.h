#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Engine Includes
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Interface_UI_ContextMenuSource.generated.h"

class UUserWidget;
class UObject;

UINTERFACE(Blueprintable)
class VH_UI_API UInterface_UI_ContextMenuSource : public UInterface
{
	GENERATED_BODY()
};

class VH_UI_API IInterface_UI_ContextMenuSource
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent)
	void GetContextOptionClasses(TSet<TSubclassOf<UObject>>& contextOptionClasses);

	UFUNCTION(BlueprintNativeEvent)
	void GetContextMenuClass(TSubclassOf<UUserWidget>& contextMenuClass);
};
