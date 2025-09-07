#include "VTAK_Example.h"

// Engine
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
#include "Engine/World.h"
#include "Interfaces/IPluginManager.h"
#include "Engine/Level.h"
#include "Engine/Blueprint.h"

// VH Platform
#include "VH_COTDelegates.h"
#include "VH_COTManager.h"
#include "VH_PluginSubsystem.h"

// Game
#include "Game_GameInstance.h"
#include "Game_PluginActor.h"

IMPLEMENT_MODULE(FVTAK_Example, VTAK_Example)

DEFINE_LOG_CATEGORY(VTAK_Example);

// ---------------------------------
// --- Interface: IModuleInterface
// ---------------------------------

void FVTAK_Example::StartupModule()
{
	PluginActor = nullptr;

	FWorldDelegates::OnStartGameInstance.AddRaw(this, &FVTAK_Example::HandleStartGameInstance);
	if (UGameInstance* gi = UGame_GameInstance::Get())
	{
		HandleStartGameInstance(gi);
	}

	FWorldDelegates::OnPostWorldInitialization.AddRaw(this, &FVTAK_Example::HandlePostWorldInitialization);
	FWorldDelegates::OnWorldCleanup.AddRaw(this, &FVTAK_Example::HandleWorldCleanup);
	FVH_COTDelegates::OnCOTMessageReceived.AddRaw(this, &FVTAK_Example::HandleCOTMessageReceived);
}

void FVTAK_Example::ShutdownModule()
{
	if (UGameInstance* gi = UGame_GameInstance::Get())
	{
		if (UVH_PluginSubsystem* pluginSubsystem = gi->GetSubsystem<UVH_PluginSubsystem>())
		{
			pluginSubsystem->UnregisterPlugin(PluginName);
		}
	}

	FWorldDelegates::OnPostWorldInitialization.RemoveAll(this);
	FWorldDelegates::OnWorldCleanup.RemoveAll(this);
	FVH_COTDelegates::OnCOTMessageReceived.RemoveAll(this);

	FreeDlls(DllHandles);
}


// ---------------------------------
// --- Event Handlers
// ---------------------------------

void FVTAK_Example::HandleStartGameInstance(UGameInstance* gameInstance)
{

}

void FVTAK_Example::HandlePostWorldInitialization(UWorld* world, const UWorld::InitializationValues initializationValues)
{
	// Check for running the game (standalone or PIE) -- not for Editor, EditorPreview, etc.
	if (world->WorldType == EWorldType::Game || world->WorldType == EWorldType::PIE)
	{
		// NOTE: Unlike OnPostWorldCreation and OnWorldCleanup, the OnPostWorldInitialization delegate seems to be called ONLY for the persistent level's world!
		//		 This means these checks are unnecessary, but they are include here as a safety check, anyway.
		if (world->PersistentLevel && world->PersistentLevel->GetWorld() == world)
		{
			if (PluginActor == nullptr)
			{
				TSubclassOf<UObject> generatedClass = nullptr;

#if UE_BUILD_SHIPPING || UE_BUILD_TEST
				FString blueprintClassReference = TEXT("Blueprint'/VTAK_Example/BP/Core/BP_Example_PluginActor.BP_Example_PluginActor_C'");

				generatedClass = StaticLoadClass(UObject::StaticClass(), nullptr, *blueprintClassReference);
#else
				FString blueprintClassReference = TEXT("Blueprint'/VTAK_Example/BP/Core/BP_Example_PluginActor.BP_Example_PluginActor'");

				UObject* loadedObject = StaticLoadObject(UObject::StaticClass(), nullptr, *blueprintClassReference);
				if (UBlueprint* blueprintPtr = Cast<UBlueprint>(loadedObject))
				{
					generatedClass = blueprintPtr->GeneratedClass;
				}
#endif

				if (generatedClass != nullptr)
				{
					// if possible, spawn this plugin's blueprint that inherits AGame_PluginActor
					FActorSpawnParameters spawnParams;
					spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
					spawnParams.ObjectFlags |= RF_Transient;

					PluginActor = world->SpawnActor<AGame_PluginActor>(generatedClass, FVector(0, 0, 0), FRotator(0, 0, 0), spawnParams);
				}
				else
				{
					// no blueprint found, spawn this plugin's actor that inherits AGame_PluginActor
				}
			}

			// handle if COTManager already sent COTManagerInitialized message
			if (UVH_COTManager* cotManager = UVH_COTManager::Get())
			{
				HandleCOTMessageReceived(TEXT("COTManagerInitialized"), FVariant());
			}
		}
	}
}

void FVTAK_Example::HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources)
{
	// Check for running the game (standalone or PIE) -- not for Editor, EditorPreview, etc.
	if (world->WorldType == EWorldType::Game || world->WorldType == EWorldType::PIE)
	{
		if (world->PersistentLevel && world->PersistentLevel->GetWorld() == world)
		{
			if (IsValid(PluginActor))
			{
				PluginActor->Destroy();
				PluginActor = nullptr;
			}
		}
	}
}

void FVTAK_Example::HandleCOTMessageReceived(const FString& messageType, const FVariant& variant)
{
	if (PluginActor != nullptr)
	{
		PluginActor->HandleCOTMessageReceived(messageType);
	}
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void FVTAK_Example::LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles)
{
    for (const auto dllName : dllNames)
    {
        auto dllHandle = FPlatformProcess::GetDllHandle(*(dllPath / dllName));
        if (dllHandle == NULL)
        {
            UE_LOG(VTAK_Example, Warning, TEXT("-- could not load dll: %s"), *(dllPath / dllName));
            continue;
        }

        dllHandles.Add(dllHandle);
    }
}

void FVTAK_Example::FreeDlls(TArray<void*>& dllHandles)
{
	for (auto dllHandle : dllHandles)
	{
		FPlatformProcess::FreeDllHandle(dllHandle);
	}
}
