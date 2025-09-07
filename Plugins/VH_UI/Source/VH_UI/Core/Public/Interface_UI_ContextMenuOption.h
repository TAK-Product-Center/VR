#pragma once

#include "UObject/Interface.h"

#include "Interface_UI_ContextMenuOption.generated.h"

class APlayerController;
class UObject;

UINTERFACE(Blueprintable)
class VH_UI_API UInterface_UI_ContextMenuOption : public UInterface
{
	GENERATED_BODY()
};

class VH_UI_API IInterface_UI_ContextMenuOption
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Sets instigator and source when this option is created
	* \param instigator Actor that caused this option to be created
	* \param source Object that was clicked on (if any) to generate the generate this option
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetInstigatorAndSource(AActor* instigator, UObject* source);

	/*
	* \brief Called when this option is clicked
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Execute();
};
