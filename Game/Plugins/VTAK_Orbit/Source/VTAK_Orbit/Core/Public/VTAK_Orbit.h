#pragma once

// Required includes
#include "IVTAK_Orbit.h"

// Engine Includes
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Misc/Variant.h"

DECLARE_LOG_CATEGORY_EXTERN(VTAK_Orbit, Warning, All);

// Forware declarations
class AGame_PluginActor;


class FVTAK_Orbit : public IVTAK_Orbit
{
	// ---------------------------------
	// --- Variables
	// ---------------------------------
private:

	const FName PluginName = TEXT("VTAK_Orbit");

	UPROPERTY()
	AGame_PluginActor* PluginActor;

	TArray<void*> DllHandles;


	// ---------------------------------
	// --- Interface: ModuleInterface
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

	void HandleCOTMessageReceived(const FString& messageType, const FVariant& variant);

	/*
	 * Called after the GameInstance is initialized.
	 *
	 * @param gameInstance The new GameInstance that has been initialized.
	 */
	void HandleStartGameInstance(UGameInstance* gameInstance);

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


	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:

	void AddGetCOTBoundingBoxDelegate();

	void FreeDlls(TArray<void*>& dllHandles);

	void LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles);

};

