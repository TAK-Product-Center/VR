// Required Includes
#include "VTAK_Mensuration.h"

// Engine Includes
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"

// VH Plugin Includes
#include "VH_COTDelegates.h"
#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "VH_PluginSubsystem.h"

// Game Includes
#include "Game_GameInstance.h"
#include "Game_PluginActor.h"

IMPLEMENT_MODULE(FVTAK_Mensuration, VTAK_Mensuration)

DEFINE_LOG_CATEGORY(VTAK_Mensuration);


// ---------------------------------
// --- Interface_ModuleInterface
// ---------------------------------

void FVTAK_Mensuration::StartupModule()
{
	PluginActor = nullptr;

	FWorldDelegates::OnPostWorldInitialization.AddRaw(this, &FVTAK_Mensuration::HandlePostWorldInitialization);
	FWorldDelegates::OnWorldCleanup.AddRaw(this, &FVTAK_Mensuration::HandleWorldCleanup);
	FVH_COTDelegates::OnCOTMessageReceived.AddRaw(this, &FVTAK_Mensuration::HandleCOTMessageReceived);
}

void FVTAK_Mensuration::ShutdownModule()
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
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void FVTAK_Mensuration::HandlePostWorldInitialization(UWorld* world, const UWorld::InitializationValues initializationValues)
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
				FString blueprintClassReference = TEXT("Blueprint'/VTAK_Mensuration/BP/Core/BP_PluginActor_Mensuration.BP_PluginActor_Mensuration_C'");

				generatedClass = StaticLoadClass(UObject::StaticClass(), nullptr, *blueprintClassReference);
#else
				FString blueprintClassReference = TEXT("Blueprint'/VTAK_Mensuration/BP/Core/BP_PluginActor_Mensuration.BP_PluginActor_Mensuration'");

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

void FVTAK_Mensuration::HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources)
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

void FVTAK_Mensuration::HandleCOTMessageReceived(const FString& messageType, const FVariant& variant)
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

void FVTAK_Mensuration::AddGetCOTBoundingBoxDelegate()
{
	UVH_COTManager::FGetCOTBoundingBox boundingBoxDelegate;
	boundingBoxDelegate.BindLambda([](UVH_COTEvent* cotEvent, FGeodeticCoord2D& northWest, FGeodeticCoord2D& southEast)
	{
		FString type = cotEvent->GetAttribute(TEXT("type"));
		if (type.StartsWith(TEXT("u-d-m")))
		{
			// mensuration

			double southLatitude = 180;
			double westLongitude = 180;

			double northLatitude = -180;
			double eastLongitude = -180;

			TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
			for (FXmlNode* link : links)
			{
				FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(link);

				double pointLongitude = coordinate.Longitude;
				double pointLatitude = coordinate.Latitude;

				westLongitude = FMath::Min<double>(westLongitude, pointLongitude);
				eastLongitude = FMath::Max<double>(eastLongitude, pointLongitude);

				southLatitude = FMath::Min<double>(southLatitude, pointLatitude);
				northLatitude = FMath::Max<double>(northLatitude, pointLatitude);
			}

			northWest.Latitude = northLatitude;
			northWest.Longitude = westLongitude;

			southEast.Latitude = southLatitude;
			southEast.Longitude = eastLongitude;

			return true;
		}

		return false;
	});

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		cotManager->COTBoundingBoxLambdas.Add(boundingBoxDelegate);
	}
	else
	{
		UE_LOG(VTAK_Mensuration, Warning, TEXT("-- FVTAK_Mensuration::AddGetCOTBoundingBoxDelegate | cotManager is nullptr"));
	}
}