#pragma once

#include "Modules/ModuleManager.h"

class FVH_ArtUtilitiesModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
