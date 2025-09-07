#pragma once

// Engine Includes
#include "Engine\World.h"

#include "Modules\ModuleManager.h"

struct FActorsInitializedParams;

class FVH_PluginsModule : public IModuleInterface
{
	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	friend class UVH_PluginSubsystem;

	// ---------------------------------
	// --- Interface: IModuleInterface
	// ---------------------------------
public:
	/** IModuleInterface implementation */
	// executes after your module is loaded into memory (but after global variables are initialized)
	virtual void StartupModule() override;

	// called during shutdown to clean up your module
	// for modules that support dynamic reloading, called before unloading the module
	virtual void ShutdownModule() override;

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	/*
	 * Called after a world is initialized.
	 *
	 * @param world The new world that has been initialized.
	 * @param initializationValues Struct of world initialization values.
	 */
	void HandlePostWorldInitialization(UWorld* world, const UWorld::InitializationValues initializationValues);

};
