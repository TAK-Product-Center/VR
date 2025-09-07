#pragma once

// Parent Includes
#include "IVTAK_Mensuration.h"

// Engine Includes
#include "Engine/World.h"
#include "Misc/Variant.h"

class AGame_PluginActor;

DECLARE_LOG_CATEGORY_EXTERN(VTAK_Mensuration, Warning, All);

class FVTAK_Mensuration : public IVTAK_Mensuration
{
	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	const FName PluginName = TEXT("VTAK_Mensuration");

	UPROPERTY()
	AGame_PluginActor* PluginActor;

	TArray<void*> DllHandles;


	// ---------------------------------
	// --- IModuleInterface
	// ---------------------------------

public:
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

	/*
	 * Called when world starts to cleanup before being destroyed.
	 *
	 * @note bSessionEnded and bCleanupResources are typically TRUE, but may be FALSE in very special circumstances.
	 * @param world The world that is about to be destroyed.
	 * @param bSessionEnded TRUE if the session is ending.
	 * @param bCleanupResources TRUE if world resources should be cleaned up.
	 */
	void HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources);

	void HandleCOTMessageReceived(const FString& messageType, const FVariant& variant);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void AddGetCOTBoundingBoxDelegate();
};

