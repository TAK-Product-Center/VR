#pragma once

// Parent Includes
#include "VTAK_Actor_Mensuration.h"

// Generated Includes
#include "VTAK_Actor_Mensuration_Angle.generated.h"

UCLASS()
class VTAK_MENSURATION_API AVTAK_Actor_Mensuration_Angle : public AVTAK_Actor_Mensuration
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_Actor_Mensuration_Angle();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
    virtual void Tick(float deltaSeconds) override;
};
