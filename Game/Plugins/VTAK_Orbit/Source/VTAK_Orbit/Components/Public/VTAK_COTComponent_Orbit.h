#pragma once

// Required includes
#include "VH_COTComponent.h"

// Generated include
#include "VTAK_COTComponent_Orbit.generated.h"

// Forward Declarations
class UVH_COTEvent;
class AVH_GlobeReferenceActor;


UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class VTAK_ORBIT_API UVTAK_COTComponent_Orbit : public UVH_COTComponent
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:

	UVTAK_COTComponent_Orbit();


	// ---------------------------------
	// --- Inherited Methods
	// ---------------------------------
protected:

	// Receieve a COT and do something with it
	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	// Make a COT and send it out
	virtual void PopulateCOT_Virtual() override;


	// ---------------------------------
	// --- API
	// ---------------------------------
public:

	UFUNCTION(BlueprintPure)
	AVH_GlobeReferenceActor* GetGlobeReference() const;

    // insert/update database and add object to player's VO (if not already added)
    UFUNCTION(BlueprintCallable)
    void RegisterWithDatabase();

};
