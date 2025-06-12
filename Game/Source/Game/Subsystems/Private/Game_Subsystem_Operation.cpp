// Required Includes
#include "Game_Subsystem_Operation.h"
#include "Game.h"

// Engine Includes
#include "ImageUtils.h"

#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_COTManager.h"
#include "VH_DataPackage.h"
#include "Developer_PersistentSettings.h"

// Game Includes
#include "Game_Database_Operation.h"
#include "Game_Statics.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"
#include "Game_EntityDB.h"
#include "Game_Pawn.h"
#include "Game_PlayerState.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_Operation::UGame_Subsystem_Operation() :
	CurrentOperationID(-1),
	CurrentViewID(-1)
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Subsystem_Operation* UGame_Subsystem_Operation::Get()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		return world->GetSubsystem<UGame_Subsystem_Operation>();
	}

	return nullptr;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Subsystem_Operation::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	OperationDB = NewObject<UGame_Database_Operation>();
	OperationDB->Initialize();

	LatentInitialize();
}

void UGame_Subsystem_Operation::Deinitialize()
{
	OperationDB->Disconnect();
	OperationDB = nullptr;

	Super::Deinitialize();
}

// ---------------------------------
// --- API
// ---------------------------------

FSpatialiteResults_BP UGame_Subsystem_Operation::GetOperations(const FString& orderBy, bool bAsc) const
{
	return FSpatialiteResults_BP(OperationDB->GetOperations(orderBy, bAsc));
}

FSpatialiteResults_BP UGame_Subsystem_Operation::GetViews(int32 operationID, const FString& orderBy, bool bAsc) const
{
	return FSpatialiteResults_BP(OperationDB->GetViews(operationID, orderBy, bAsc));
}

FSpatialiteResults_BP UGame_Subsystem_Operation::GetViewItems(int32 viewID, const FString& orderBy, bool bAsc) const
{
	return FSpatialiteResults_BP(OperationDB->GetViewItems(viewID, orderBy, bAsc));
}

bool UGame_Subsystem_Operation::GetCurrentOperation(FSpatialiteResult_BP& result) const
{
	if (CurrentOperationID >= 0)
	{
		result = FSpatialiteResult_BP(OperationDB->GetOperation(CurrentOperationID));

		return true;
	}

	return false;
}

bool UGame_Subsystem_Operation::GetCurrentView(FSpatialiteResult_BP& result) const
{
	if (CurrentViewID >= 0)
	{
		result = FSpatialiteResult_BP(OperationDB->GetView(CurrentViewID));

		return true;
	}

	return false;
}

void UGame_Subsystem_Operation::AddOperation(const FString& name, const FString& start)
{
	OperationDB->AddOperation(name, start);

	OnOperationsUpdated.Broadcast();
}

void UGame_Subsystem_Operation::UpdateOperation(int32 operationID, const FString& name, const FString& start)
{
	OperationDB->UpdateOperation(operationID, name, start);

	OnOperationsUpdated.Broadcast();
}

void UGame_Subsystem_Operation::RemoveOperation(int32 operationID)
{
	OperationDB->RemoveOperation(operationID);

	OnOperationsUpdated.Broadcast();
}

void UGame_Subsystem_Operation::DuplicateOperation(int32 operationID)
{
	OperationDB->DuplicateOperation(operationID);

	OnOperationsUpdated.Broadcast();
}

void UGame_Subsystem_Operation::LoadOperation(int32 operationID)
{
	UnloadCurrentOperation();

	CurrentOperationID = operationID;

	SpatialiteResults results = OperationDB->GetViews(operationID);
	if (results.Num() > 0)
	{
		CurrentViewID = UDatabase_Spatialite::GetInteger(TEXT("id"), results[0]);

		LoadView(CurrentViewID);
	}
}

void UGame_Subsystem_Operation::UnloadCurrentOperation()
{
	RestoreCurrentEntitiesToEntityDB();

	CurrentOperationID = -1;
	CurrentViewID = -1;
}

void UGame_Subsystem_Operation::AddView(const FString& name, int32 index)
{
	if (CurrentOperationID >= 0)
	{
		FVector headLocation;
		FRotator headRotation;
		UGame_Statics::GetVHPlayerController()->GetPlayerViewPoint(headLocation, headRotation);

		FString uniqueName = name;

		if (IsViewNameInUse(CurrentOperationID, -1, uniqueName))
		{
			int32 nameSuffix = index;

			while (IsViewNameInUse(CurrentOperationID, -1, uniqueName + FString::FromInt(nameSuffix))) 
			{ 
				nameSuffix++; 
			};
			
			uniqueName += FString::FromInt(nameSuffix);
		}

		headRotation.Roll = 0;
		int32 viewID = OperationDB->AddView(CurrentOperationID, uniqueName, index, GetCoordinate(headLocation), headRotation);

		OperationDB->AddViewItems(true, viewID, GetViewItems());

		OnOperationUpdated.Broadcast(CurrentOperationID);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::AddView | no operation is loaded"));
	}
}

FSpatialiteResult_BP UGame_Subsystem_Operation::GetView(int32 viewID) const
{
	return FSpatialiteResult_BP(OperationDB->GetView(viewID));
}

void UGame_Subsystem_Operation::UpdateView(int32 viewID, const FString& name, int32 index, bool bIsSelected)
{
	if (CurrentOperationID >= 0)
	{
		OperationDB->UpdateView(viewID, name, index);

		OnTextUpdated.Broadcast(CurrentOperationID, viewID, bIsSelected);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::UpdateView | no operation is loaded"));
	}
}

void UGame_Subsystem_Operation::UpdateViewCamera(int32 viewID)
{
	if (CurrentOperationID >= 0)
	{
		FVector headLocation;
		FRotator headRotation;

		if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
		{
			playerController->GetPlayerViewPoint(headLocation, headRotation);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::UpdateViewCameraCoordinate | playerController is nullptr"));
		}

		headRotation.Roll = 0;
		OperationDB->UpdateViewCamera(viewID, GetCoordinate(headLocation), headRotation);

		OperationDB->AddViewItems(true, viewID, GetViewItems());

		OnOperationUpdated.Broadcast(CurrentOperationID);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::UpdateViewCameraCoordinate | no operation is loaded"));
	}
}

void UGame_Subsystem_Operation::RemoveView(int32 viewID, UUserWidget* widget)
{
	if (widget != nullptr)
	{
		OnOperationViewRemoved.Broadcast(widget, false);

		SpatialiteResult result = OperationDB->GetView(viewID);

		OperationDB->RemoveView(viewID);

		OnOperationUpdated.Broadcast(CurrentOperationID);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::RemoveView | no widget passed in / found"));
	}
}

void UGame_Subsystem_Operation::LoadView(int32 viewID)
{
	if (CurrentOperationID >= 0)
	{
		// go to world if not already in world
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			if (playerState->GetIsInTOC())
			{
				if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
				{
					pc->ConsoleCommand(TEXT("ce GoToWorld"));
				}
			}
		}

		UnloadCurrentView();

		CurrentViewID = viewID;

		// set player pawn to view's camera location/rotation
		if (AGame_Pawn* playerPawn = Cast<AGame_Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
		{
			SpatialiteResult result = OperationDB->GetView(CurrentViewID);

			FString coordinateString = UDatabase_Spatialite::GetString(TEXT("cameraCoordinate"), result);
			
			FGeodeticCoord3D coord3D;
			coord3D.FromString(coordinateString);

			playerPawn->TeleportToCoordinate(coord3D);

			if (UCameraComponent* camera = playerPawn->FindComponentByClass<UCameraComponent>())
			{
				FString rotationString = UDatabase_Spatialite::GetString(TEXT("cameraRotation"), result);

				FRotator rotation;
				rotation.InitFromString(rotationString);

				camera->SetWorldRotation(rotation);
			}
		}

		// on timer to allow virtual objective to update loaded entities after potentially changing location when moving to view's location
		FTimerDelegate timerCallback;
		timerCallback.BindLambda([this]
		{
			// update entities in new view
			SpatialiteResults results = OperationDB->GetViewItems(CurrentViewID, TEXT("category"), true);
			for (const SpatialiteResult& result : results)
			{
				UpdateEntityToOperation(result);
			}
		});

		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, timerCallback, 1.0f, false);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::LoadView | no operation loaded | aborting"));
	}
}

void UGame_Subsystem_Operation::UnloadCurrentView()
{
	if (CurrentOperationID >= 0)
	{
		if (CurrentViewID >= 0)
		{
			RestoreCurrentEntitiesToEntityDB();

			CurrentViewID = -1;
		}
	}
}

int32 UGame_Subsystem_Operation::GetIndexForNewView(int32 operationID) const
{
	return OperationDB->GetIndexForNewView(operationID);
}

void UGame_Subsystem_Operation::UpdateViewItem(int32 viewID, const FString& uid, bool bVisible)
{
	if (CurrentOperationID >= 0)
	{
		OperationDB->UpdateViewItem(viewID, uid, bVisible);

		if (viewID == CurrentViewID)
		{
			UpdateEntityToOperation(OperationDB->GetViewItem(viewID, uid));
		}

		OnOperationUpdated.Broadcast(CurrentOperationID);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::UpdateViewItem | no operation loaded | aborting"));
	}
}

void UGame_Subsystem_Operation::RemoveViewItem(const FString& uid)
{
	if (CurrentOperationID >= 0 && CurrentViewID >= 0)
	{
		OperationDB->RemoveViewItem(CurrentViewID, uid);

		OnOperationUpdated.Broadcast(CurrentOperationID);
	}
}

bool UGame_Subsystem_Operation::IsExporting() const
{
	return GetWorld()->GetTimerManager().IsTimerActive(ExportTimerHandle);
}

void UGame_Subsystem_Operation::ExportOperation(int32 operationID, const TArray<int32>& viewIndices, double timeoutOverride, const FString& fullPathToScreenshots, const FString& fullPathToDataPackages)
{
	if (viewIndices.Num() == 0)
	{
		return;
	}

	if (fullPathToScreenshots.IsEmpty() && fullPathToDataPackages.IsEmpty())
	{
		return;
	}

	if (IsExporting())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::ExportOperation | operation already exporting | aborting"));

		return;
	}

	CurrentOperationIDCache = CurrentOperationID;
	CurrentViewIDCache = CurrentViewID;

	OnOperationExportBegin.Broadcast(operationID);

	UnloadCurrentOperation();

	CurrentOperationID = operationID;

	if (!fullPathToDataPackages.IsEmpty())
	{
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			SpatialiteResult operationResult = OperationDB->GetOperation(CurrentOperationID);
			
			FString operationName = UDatabase_Spatialite::GetString(TEXT("name"), operationResult);

			SpatialiteResults viewResults = OperationDB->GetViews(CurrentOperationID);
			for (const SpatialiteResult& viewResult : viewResults)
			{
				FString dataPackageName = FString::Printf(TEXT("%s_%s"), *operationName, *UDatabase_Spatialite::GetString(TEXT("name"), viewResult));

				UVH_DataPackage* dataPackage = cotManager->AddDataPackage(dataPackageName);

				SpatialiteResults viewItemResults = OperationDB->GetViewItems(UDatabase_Spatialite::GetInteger(TEXT("id"), viewResult), TEXT("id"), true);
				for (const SpatialiteResult& viewItemResult : viewItemResults)
				{
					if (UDatabase_Spatialite::GetBool(TEXT("visible"), viewItemResult))
					{
						FString entityID = UDatabase_Spatialite::GetString(TEXT("uid"), viewItemResult);
						
						dataPackage->AddUID(entityID);
					}
				}

				FString fullPathToDataPackage = FString::Printf(TEXT("%s/%s.zip"), *fullPathToDataPackages, *dataPackageName);

				dataPackage->CreateZipFile(fullPathToDataPackage);
			}
		}
	}

	if (!fullPathToScreenshots.IsEmpty())
	{
		AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController();

		LoadView(viewIndices[0]);
		
		FTimerDelegate timerDelegate;
		timerDelegate.BindUFunction(this, "HandleExportTimer", 0, viewIndices, timeoutOverride, fullPathToScreenshots);

		double timerDelay = timeoutOverride > 0 ? timeoutOverride : 5;
		GetWorld()->GetTimerManager().SetTimer(ExportTimerHandle, timerDelegate, timerDelay, false);
	}
}

bool UGame_Subsystem_Operation::IsViewNameInUse(int32 operationID, int32 viewID, const FString& viewName)
{
	return OperationDB->IsViewNameInUse(operationID, viewID, viewName);
}

void UGame_Subsystem_Operation::HandleScreenshotTimer(int32 currentViewIndex, const TArray<int32>& viewIndices, double timeoutOverride, const FString& fullPathToScreenshots)
{
	if (FScreenshotRequest::IsScreenshotRequested())
	{
		FTimerDelegate timerDelegate;
		timerDelegate.BindUFunction(this, "HandleScreenshotTimer", currentViewIndex, viewIndices, timeoutOverride, fullPathToScreenshots);

		GetWorld()->GetTimerManager().SetTimer(ExportTimerHandle, timerDelegate, 1, false);
	}
	else
	{
		LoadView(viewIndices[currentViewIndex]);

		FTimerDelegate timerDelegate;
		timerDelegate.BindUFunction(this, "HandleExportTimer", currentViewIndex, viewIndices, timeoutOverride, fullPathToScreenshots);

		double timerDelay = timeoutOverride > 0 ? timeoutOverride : 5;
		GetWorld()->GetTimerManager().SetTimer(ExportTimerHandle, timerDelegate, timerDelay, false);
	}
}

void UGame_Subsystem_Operation::HandleExportTimer(int32 currentViewIndex, const TArray<int32>& viewIndices, double timeoutOverride, const FString& fullPathToScreenshots)
{
	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		if (currentViewIndex == viewIndices.Num())
		{
			// finished!
			int32 operationID = CurrentOperationID;

			UnloadCurrentOperation();

			OnOperationExportEnd.Broadcast(operationID);

			CurrentOperationID = CurrentOperationIDCache;
			CurrentViewID = CurrentViewIDCache;

			CurrentOperationIDCache = -1;
			CurrentViewIDCache = -1;

			return;
		}

		bool bReadyForScreenshot = false;

		if (timeoutOverride > 0)
		{
			bReadyForScreenshot = true;
		}
		else
		{
			bReadyForScreenshot = playerController->GetTotalTasks() == 0;
		}

		if (bReadyForScreenshot)
		{
			// create screenshot
			if (UGameViewportClient* gameViewportClient = GetWorld()->GetGameViewport())
			{
				// create directory if it doesn't exist
				IFileManager& fileManager = IFileManager::Get();
				if (fileManager.MakeDirectory(*fullPathToScreenshots, true))
				{
					// request screenshot
					SpatialiteResult operationResult = OperationDB->GetOperation(CurrentOperationID);
					FString operationName = UDatabase_Spatialite::GetString(TEXT("name"), operationResult);
					
					SpatialiteResult result = OperationDB->GetView(viewIndices[currentViewIndex]);
					FString viewName = UDatabase_Spatialite::GetString(TEXT("name"), result);

					FString fullPathToScreenshot = FString::Printf(TEXT("%s\\%s_%s.png"), *fullPathToScreenshots, *operationName.Replace(TEXT(" "), TEXT("")), *viewName.Replace(TEXT(" "), TEXT("")));

					fileManager.Delete(*fullPathToScreenshot);

					FScreenshotRequest::RequestScreenshot(fullPathToScreenshot, false);
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::HandleExportTimer | could not create screenshot directory: %s"), *fullPathToScreenshots);
				}
			}
			
			// queue load next view after requested screenshot finishes
			int32 nextViewIndex = currentViewIndex + 1;

			FTimerDelegate timerDelegate;
			timerDelegate.BindUFunction(this, "HandleScreenshotTimer", nextViewIndex, viewIndices, timeoutOverride, fullPathToScreenshots);

			GetWorld()->GetTimerManager().SetTimer(ExportTimerHandle, timerDelegate, 1, false);
		}
		else
		{
			// continue waiting for current view to finish loading
			FTimerDelegate timerDelegate;
			timerDelegate.BindUFunction(this, "HandleExportTimer", currentViewIndex, viewIndices, timeoutOverride, fullPathToScreenshots);

			GetWorld()->GetTimerManager().SetTimer(ExportTimerHandle, timerDelegate, 5, false);
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

FGeodeticCoord3D UGame_Subsystem_Operation::GetCoordinate(const FVector& worldLocation) const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			return globeReference->WorldToGeodeticDouble(worldLocation);
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::GetCoordinate | failed to find globe reference | returning empty FGeodeticCoord3D"));
	return FGeodeticCoord3D();
}

FVector UGame_Subsystem_Operation::GetWorldLocation(const FGeodeticCoord3D& coordinate) const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			return globeReference->GeodeticToWorldDouble(coordinate);
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::GetWorldLocation | failed to find globe reference | returning empty FVector"));
	return FVector();
}

void UGame_Subsystem_Operation::StoreDefaultSettings()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreDefaultSettingString(FString(TEXT("exportOperationScreenshotPath")), FString::Printf(TEXT("%s/VRTAK/OperationExports"), *UDeveloper_Statics::GetUserAppDataPath()));
		gameSettings->StoreDefaultSettingString(FString(TEXT("exportOperationDataPackagePath")), FString::Printf(TEXT("%s/VRTAK/OperationExports"), *UDeveloper_Statics::GetUserAppDataPath()));
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::StoreDefaultSettings | gameSettings is nullptr"));
	}
}

void UGame_Subsystem_Operation::BindToEntityDB()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnDelete.AddDynamic(this, &UGame_Subsystem_Operation::HandleDatabaseDelete);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Operation::BindToEntityDB | entityDB is nullptr"));
	}
}

void UGame_Subsystem_Operation::RestoreCurrentEntitiesToEntityDB()
{
	if (CurrentOperationID >= 0)
	{
		if (CurrentViewID >= 0)
		{
			// restore entities from old view
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				SpatialiteResults results = OperationDB->GetViewItems(CurrentViewID, TEXT("category"), true);
				for (const SpatialiteResult& result : results)
				{
					SpatialiteResults entityDBResults = entityDB->QueryUID(UDatabase_Spatialite::GetString(TEXT("uid"), result));
					if (entityDBResults.Num() > 0)
					{
						UpdateEntityToEntityDB(entityDBResults[0]);
					}
				}
			}
		}
	}
}

TSet<FString> UGame_Subsystem_Operation::GetViewItems() const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetPagedInEntities();
	}

	return TSet<FString>();
}

void UGame_Subsystem_Operation::UpdateEntityToOperation(const SpatialiteResult& result)
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		TSet<AActor*> actors = virtualObjective->GetActorsForEntity(UDatabase_Spatialite::GetString(TEXT("uid"), result));

		bool bVisible = UDatabase_Spatialite::GetInteger(TEXT("visible"), result) == 1;
		for (AActor* actor : actors)
		{
			actor->SetActorHiddenInGame(!bVisible);
		}
	}
}

void UGame_Subsystem_Operation::UpdateEntityToEntityDB(const SpatialiteResult& result)
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		TSet<AActor*> actors = virtualObjective->GetActorsForEntity(UDatabase_Spatialite::GetString(TEXT("entityUID"), result));

		bool bVisible = UDatabase_Spatialite::GetInteger(TEXT("visible"), result) == 1;
		for (AActor* actor : actors)
		{
			actor->SetActorHiddenInGame(!bVisible);
		}
	}
}

void UGame_Subsystem_Operation::LatentInitialize()
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

	if (entityDB != nullptr && gameSettings != nullptr)
	{
		BindToEntityDB();

		StoreDefaultSettings();
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_Subsystem_Operation::LatentInitialize, 0.5, false);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------	

void UGame_Subsystem_Operation::HandleDatabaseDelete(const FSpatialiteResults_BP& results)
{
	if (CurrentOperationID >= 0)
	{
		if (CurrentViewID >= 0)
		{
			for (const FSpatialiteResult_BP& result : results.Results)
			{
				FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result.Result);

				RemoveViewItem(entityUID);
			}
		}
	}
}