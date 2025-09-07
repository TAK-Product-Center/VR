#pragma once

// Required Includes
#include "VTAK_Actor_Mensuration.h"

// Generated Includes
#include "VTAK_Actor_Mensuration_Height.generated.h"

UCLASS()
class VTAK_MENSURATION_API AVTAK_Actor_Mensuration_Height : public AVTAK_Actor_Mensuration
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_Actor_Mensuration_Height();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void PostSpawnEditPoints() override;

	virtual bool SetLength_Implementation(float length, const FString& unit = TEXT("meters")) override;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleManipulationBegin(AActor* manipulatedActor);

	UFUNCTION()
	void HandleManipulationEnd(AActor* manipulatedActor);
};
