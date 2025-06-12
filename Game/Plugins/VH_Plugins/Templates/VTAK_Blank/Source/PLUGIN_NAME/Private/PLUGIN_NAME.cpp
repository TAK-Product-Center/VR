#include "PLUGIN_NAME.h"

// Engine
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
#include "Engine/World.h"
#include "Interfaces/IPluginManager.h"
#include "AssetRegistryModule.h"

// VH Platform
#include "VH_COTDelegates.h"
#include "VH_COTManager.h"
#include "VH_PluginSubsystem.h"

// Game
#include "Game_GameInstance.h"
#include "Game_PluginActor.h"

IMPLEMENT_MODULE(FPLUGIN_NAME, PLUGIN_NAME)

DEFINE_LOG_CATEGORY(PLUGIN_NAME);

// ---------------------------------
// --- Interface: IModuleInterface
// ---------------------------------

void FPLUGIN_NAME::StartupModule()
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    // load 3rd party library delay-loaded dlls
	/* For example...
	{
		// load libzip dlls
		FString dllPath = FPaths::ProjectPluginsDir() / TEXT("VH_FileIO/Source/ThirdParty/libzip/bin/x64/release");

		TArray<FString> dllNames;
		dllNames.Add(TEXT("zip.dll"));

		LoadDlls(dllPath, dllNames, DllHandles);
	}
	*/
#endif

	if (UGameInstance* gi = UGame_GameInstance::Get())
	{
		if (UVH_PluginSubsystem* pluginSubsystem = gi->GetSubsystem<UVH_PluginSubsystem>())
		{
			pluginSubsystem->RegisterPlugin(PluginName);
			pluginSubsystem->SetPluginLoaded(PluginName, true);
		}
	}

	PluginActor = nullptr;

	FWorldDelegates::OnPostWorldInitialization.AddRaw(this, &FPLUGIN_NAME::HandlePostWorldInitialization);
	FWorldDelegates::OnWorldCleanup.AddRaw(this, &FPLUGIN_NAME::HandleWorldCleanup);
	FVH_COTDelegates::OnCOTMessageReceived.AddRaw(this, &FPLUGIN_NAME::HandleCOTMessageReceived);
}

void FPLUGIN_NAME::ShutdownModule()
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

void FPLUGIN_NAME::HandleStartGameInstance(UGameInstance* gameInstance)
{
	if (gameInstance)
	{
		if (UVH_PluginSubsystem* pluginSubsystem = gameInstance->GetSubsystem<UVH_PluginSubsystem>())
		{
			pluginSubsystem->RegisterPlugin(PluginName);
			pluginSubsystem->SetPluginLoaded(PluginName, true);
		}
	}
}

void FPLUGIN_NAME::HandlePostWorldInitialization(UWorld* world, const UWorld::InitializationValues initializationValues)
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
				FString blueprintClassReference = TEXT("Blueprint'/PLUGIN_NAME/BP/Core/BP_PLUGIN_NAME_PluginActor.BP_PLUGIN_NAME_PluginActor_C'");

				generatedClass = StaticLoadClass(UObject::StaticClass(), nullptr, *blueprintClassReference);
#else
				FString blueprintClassReference = TEXT("Blueprint'/PLUGIN_NAME/BP/Core/BP_PLUGIN_NAME_PluginActor.BP_PLUGIN_NAME_PluginActor'");

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

void FPLUGIN_NAME::HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources)
{
	// Check for running the game (standalone or PIE) -- not for Editor, EditorPreview, etc.
	if (world->WorldType == EWorldType::Game || world->WorldType == EWorldType::PIE)
	{
		if (world->PersistentLevel && world->PersistentLevel->GetWorld() == world)
		{
			if (PluginActor && !PluginActor->IsPendingKillOrUnreachable() && !PluginActor->IsActorBeingDestroyed())
			{
				PluginActor->Destroy();
				PluginActor = nullptr;
			}
		}
	}
}

void FPLUGIN_NAME::HandleCOTMessageReceived(const FString& messageType, const FVariant& variant)
{
	if (PluginActor != nullptr)
	{
		PluginActor->HandleCOTMessageReceived(messageType);
	}
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void FPLUGIN_NAME::LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles)
{
    for (const auto dllName : dllNames)
    {
        auto dllHandle = FPlatformProcess::GetDllHandle(*(dllPath / dllName));
        if (dllHandle == NULL)
        {
            UE_LOG(PLUGIN_NAME, Warning, TEXT("-- could not load dll: %s"), *(dllPath / dllName));
            continue;
        }

        dllHandles.Add(dllHandle);
    }
}

void FPLUGIN_NAME::FreeDlls(TArray<void*>& dllHandles)
{
	for (auto dllHandle : dllHandles)
	{
		FPlatformProcess::FreeDllHandle(dllHandle);
	}
}
