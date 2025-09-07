#pragma once

// Parent Includes
#include "UObject/Object.h"

// Generated Includes
#include "VR_Statics.generated.h"

class UWidgetInteractionComponent;

UCLASS()
class VH_VR_API UVR_Statics : public UObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	static int32 UniqueIndex;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVR_Statics(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	static int32 GetUniqueIndex();

	UFUNCTION(BlueprintCallable)
	static void SetWidgetInteractionIndices(UWidgetInteractionComponent* widgetInteractionComponent);

	UFUNCTION(BlueprintPure)
	static bool IsUsingHMD();
};