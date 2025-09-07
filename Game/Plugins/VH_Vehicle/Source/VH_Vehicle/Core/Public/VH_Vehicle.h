#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogVehicleAI, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(VH_Vehicle, Warning, All);

class FVH_VehicleModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
