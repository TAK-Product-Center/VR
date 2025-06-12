#pragma once

// Parent Includes
#include "Components/WidgetInteractionComponent.h"

// Generated Includes
#include "VR_WidgetInteractionComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_VR_API UVR_WidgetInteractionComponent : public UWidgetInteractionComponent
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVR_WidgetInteractionComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void ReleasePointerKey(FKey key) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void ForceWidgetPathUpdate();
};