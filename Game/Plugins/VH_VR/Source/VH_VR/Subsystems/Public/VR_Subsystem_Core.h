#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Generated Includes
#include "VR_Subsystem_Core.generated.h"

UCLASS()
class VH_VR_API UVR_Subsystem_Core : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVR_Subsystem_Core();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);
};