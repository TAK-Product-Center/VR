// Parent includes
#include "VTAK_Orbit.h"

// VH Plugin includes
#include "VH_COTDelegates.h"
#include "VH_COTManager.h"
#include "VH_PluginSubsystem.h"

// Game layer includes
#include "Game_GameInstance.h"
#include "Game_PluginActor.h"

IMPLEMENT_MODULE(FVTAK_Orbit, VTAK_Orbit)

DEFINE_LOG_CATEGORY(VTAK_Orbit);


// ---------------------------------
// --- Interface: ModuleInterface
// ---------------------------------

void FVTAK_Orbit::StartupModule()
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    // load 3rd party library dlls
#endif

	PluginActor = nullptr;

	FWorldDelegates::OnStartGameInstance.AddRaw(this, &FVTAK_Orbit::HandleStartGameInstance);
	if (UGameInstance* gi = UGame_GameInstance::Get())
	{
		HandleStartGameInstance(gi);
	}

	FWorldDelegates::OnPostWorldInitialization.AddRaw(this, &FVTAK_Orbit::HandlePostWorldInitialization);
	FWorldDelegates::OnWorldCleanup.AddRaw(this, &FVTAK_Orbit::HandleWorldCleanup);
	FVH_COTDelegates::OnCOTMessageReceived.AddRaw(this, &FVTAK_Orbit::HandleCOTMessageReceived);
}

void FVTAK_Orbit::ShutdownModule()
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

void FVTAK_Orbit::HandleStartGameInstance(UGameInstance* gameInstance)
{
}

void FVTAK_Orbit::HandlePostWorldInitialization(UWorld* world, const UWorld::InitializationValues initializationValues)
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
				FString blueprintClassReference = TEXT("Blueprint'/VTAK_Orbit/BP/Core/BP_PluginActor_Orbit.BP_PluginActor_Orbit_C'");

				generatedClass = StaticLoadClass(UObject::StaticClass(), nullptr, *blueprintClassReference);
#else
				FString blueprintClassReference = TEXT("Blueprint'/VTAK_Orbit/BP/Core/BP_PluginActor_Orbit.BP_PluginActor_Orbit'");

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

void FVTAK_Orbit::HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources)
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

void FVTAK_Orbit::HandleCOTMessageReceived(const FString& messageType, const FVariant& variant)
{
	if (messageType.Equals(TEXT("COTManagerInitialized")))
	{
		AddGetCOTBoundingBoxDelegate();
	}

	if (PluginActor != nullptr)
	{
		PluginActor->HandleCOTMessageReceived(messageType);
	}
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void FVTAK_Orbit::AddGetCOTBoundingBoxDelegate()
{
	UVH_COTManager::FGetCOTBoundingBox boundingBoxDelegate;

	boundingBoxDelegate.BindLambda([](UVH_COTEvent* cotEvent, FGeodeticCoord2D& northWest, FGeodeticCoord2D& southEast)
	{
		if (cotEvent != nullptr)
		{
			FString type = cotEvent->GetAttribute(TEXT("type"));
			if (type.StartsWith(TEXT("u-d-o")))
			{
				FGeodeticCoord3D coordinate = cotEvent->GetPoint();

				northWest = coordinate.ToGeodeticCoord2D();
				southEast = northWest;

				return true;
			}
		}

		return false;
	});

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		cotManager->COTBoundingBoxLambdas.Add(boundingBoxDelegate);
	}
	else
	{
		UE_LOG(VTAK_Orbit, Warning, TEXT("-- FVTAK_Orbit::AddGetCOTBoundingBoxDelegate | cotManager is nullptr"));
	}
}

void FVTAK_Orbit::LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles)
{
    for (const auto dllName : dllNames)
    {
        auto dllHandle = FPlatformProcess::GetDllHandle(*(dllPath / dllName));
        if (dllHandle == NULL)
        {
            UE_LOG(VTAK_Orbit, Warning, TEXT("-- could not load dll: %s"), *(dllPath / dllName));
            continue;
        }

        dllHandles.Add(dllHandle);
    }
}

void FVTAK_Orbit::FreeDlls(TArray<void*>& dllHandles)
{
	for (auto dllHandle : dllHandles)
	{
		FPlatformProcess::FreeDllHandle(dllHandle);
	}
}