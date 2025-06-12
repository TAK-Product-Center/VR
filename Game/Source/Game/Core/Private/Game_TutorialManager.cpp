// Required Includes
#include "Game_TutorialManager.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"
#include "EnhancedInputSubsystems.h"
#include "Materials/Material.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "Developer_Subsystem_Notification.h"
#include "Developer_Subsystem_Core.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_Subsystem_Core.h"
#include "Game_ImportManager.h"
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"
#include "Game_PlayerController.h"
#include "Game_Pawn.h"
#include "Game_MovementComponent.h"

UGame_TutorialManager* UGame_TutorialManager::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TutorialManager::UGame_TutorialManager() :
	bCanSwitchMouseLook(false),
	bHasSwitchedMouseLook(false)
{
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        GlobalInstance = this;
    }
}

// ---------------------------------
// --- FTickableObjectBase
// ---------------------------------

TStatId UGame_TutorialManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGame_TutorialManager, STATGROUP_Tickables);
}

bool UGame_TutorialManager::IsTickable() const
{
	return false;
}

void UGame_TutorialManager::Tick(float deltaSeconds)
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_TutorialManager* UGame_TutorialManager::Get()
{
    return UGame_TutorialManager::GlobalInstance;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

UWorld* UGame_TutorialManager::GetWorld() const
{
	return UDeveloper_Statics::GetVHWorld();
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_TutorialManager::IsInTutorial() const
{
	return GetTutorialStage() != ETutorialStage::Inactive;
}

bool UGame_TutorialManager::ClearTutorialDatabase()
{
	if (UGame_EntityDB* const entityDB = UGame_EntityDB::Get())
	{
		if (entityDB->GetDatabaseFilename().Equals(TEXT("tutorialEntityDB.sqlite")))
		{
			entityDB->Clear();
			entityDB->SetDatabaseFilename(TEXT("entityDB.sqlite"));

			return true;
		}
	}

	return false;
}

ETutorialStage UGame_TutorialManager::GetTutorialStage() const
{
	return TutorialStage;
}

void UGame_TutorialManager::SetTutorialStage(ETutorialStage tutorialStage)
{
	TutorialStage = tutorialStage;
	
	switch (tutorialStage)
	{
		case ETutorialStage::Inactive:
		{
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				entityDB->SetDatabaseFilename(TEXT("entityDB.sqlite"));
			}

			if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
			{
				if (UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
				{
					inputSubsystem->RemoveMappingContext(TutorialInputMap);
				}
			}

			TutorialUIMaterial->bDisableDepthTest = true;
		}
		break;

		case ETutorialStage::Initial:
		{
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				entityDB->SetDatabaseFilename(TEXT("tutorialEntityDB.sqlite"));

				entityDB->Clear();
			}

			if (!TutorialModelFilename.IsEmpty())
			{
				if (UGame_ImportManager* importManager = UGame_ImportManager::Get())
				{
					FString fullPathToFile = FString::Printf(TEXT("%s/Data/Tutorial/Models/%s"), *FPaths::RootDir(), *TutorialModelFilename);
			
					importManager->RegisterFileToDatabase(fullPathToFile);
				}
			}

			if (AGame_VirtualObjective* activeVO = UGame_Statics::GetVHPlayerController()->GetActiveVO())
			{
				activeVO->SetScale3D(TOCTableScale);

				activeVO->TOCMoveViewpoint(TOCTableOffset);
			}

			if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
			{
				playerController->SetMouseMode(EMouseCaptureMode::CaptureDuringRightMouseDown);

				if (UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
				{
					inputSubsystem->AddMappingContext(TutorialInputMap, 100);
				}
			}

			CameraOrbsFound = 0;

			NumberOfZooms = 0;
		}
		break;

		case ETutorialStage::Quickturn_VR:
		{


		}
		break;

		case ETutorialStage::CameraControl:
		{
			for (AActor* cameraOrb : CameraOrbs)
			{
				cameraOrb->SetActorHiddenInGame(false);
			}
		}
		break;

		case ETutorialStage::MouseLook_Desktop:
		{
			if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
			{
				playerController->SetMouseMode(EMouseCaptureMode::CapturePermanently);
			}
		}
		break;

		case ETutorialStage::Ribbon:
		{
			for (AActor* cameraOrb : CameraOrbs)
			{
				cameraOrb->SetActorHiddenInGame(true);
			}
		}
		break;

		case ETutorialStage::WalkPlayerMovement:
		{
			for (AActor* movementOrb : MovementOrbs)
			{
				movementOrb->SetActorHiddenInGame(false);
			}
		}
		break;

		case ETutorialStage::LookTable:
		{
			for (AActor* movementOrb : MovementOrbs)
			{
				movementOrb->SetActorHiddenInGame(true);
			}
		}
		break;

		case ETutorialStage::Table:
		{
			//ReceiveTutorialStageCompleted(tutorialStage);

			//OnTutorialStageCompleted.Broadcast(tutorialStage);
		}
		break;

		// only needed for testing by starting in FTUE garage map
		case ETutorialStage::TeleportMovementMode:
		{
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				entityDB->SetDatabaseFilename(TEXT("tutorialEntityDB.sqlite"));

				entityDB->Clear();
			}

			if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
			{
				if (UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
				{
					inputSubsystem->AddMappingContext(TutorialInputMap, 100);
				}
			}
		}
		break;

		case ETutorialStage::NavigateToCreateArea:
		{
			TeleportMovementOrb->SetActorHiddenInGame(false);
		}
		break;

		case ETutorialStage::CreateEntity:
		{
			TeleportMovementOrb->SetActorHiddenInGame(true);
		}
		break;

		case ETutorialStage::ModifyEntity:
		{
			TutorialUIMaterial->bDisableDepthTest = false;
		}
		break;

		case ETutorialStage::FlyPlayerMovement:
		{
			FlyMovementOrb->SetActorHiddenInGame(false);
		}
		break;

		case ETutorialStage::CreateEntity2:
		{
			FlyMovementOrb->SetActorHiddenInGame(true);
		}
		break;
	}

	ReceiveTutorialStageChanged(tutorialStage);

	OnTutorialStageChanged.Broadcast(tutorialStage);
}

void UGame_TutorialManager::TutorialActionOccurred(const FString& actionID)
{
	auto notifyComplete = [this](ETutorialStage tutorialStage)
	{
		ReceiveTutorialStageCompleted(tutorialStage);

		OnTutorialStageCompleted.Broadcast(tutorialStage);
	};

	switch (TutorialStage)
	{
		case ETutorialStage::Inactive:
		{
			return;
		}

		case ETutorialStage::Quickturn_VR:
		{
			if(actionID.Equals(QUICKTURN_ACTION))
			{
				NumberOfQuickturns++;

				if (NumberOfQuickturns >= 3)
				{
					NumberOfQuickturns = 0;
					notifyComplete(TutorialStage);
				}
			}
		}

		case ETutorialStage::CameraControl:
		{
			if (actionID.Equals(LOOKED_AT_ORB_ACTION))
			{
				CameraOrbsFound++;
				
				if (CameraOrbsFound >= CameraOrbs.Num())
				{
					bCanSwitchMouseLook = true;
					notifyComplete(TutorialStage);
				}
			}
		}
		break;

		case ETutorialStage::MouseLook_Desktop:
		{
			if (actionID.Equals(TOGGLE_NOPOINTER_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::NoMouseLook_Desktop:
		{
			if (actionID.Equals(TOGGLE_POINTER_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::Ribbon:
		{
			if (actionID.Equals(RIBBON_VISIBLE_ACTION))
			{
				if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
				{
					if (subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Desktop || subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Unknown)
					{
						GoToNextDesktopStage();
					}
					else
					{
						GoToNextVRStage();
					}
				}
			}
		}
		break;

		case ETutorialStage::WalkMovementMode:
		{
			if (actionID.Equals(MOVEMENT_MODE_WALK_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::WalkPlayerMovement:
		{
			if (actionID.Equals(PLAYER_FINISHED_MOVE_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;
		case ETutorialStage::LookTable:
		{
			notifyComplete(TutorialStage);
		}

		case ETutorialStage::Table:
		{
			if (actionID.Equals(TOC_ZOOM_IN_ACTION) || actionID.Equals(TOC_ZOOM_OUT_ACTION))
			{
				NumberOfZooms++;

				if (NumberOfZooms >= 3)
				{
					notifyComplete(TutorialStage);
				}
			}
		}
		break;

		case ETutorialStage::GoToWorld:
		{

		}
		break;

		case ETutorialStage::TeleportMovementMode:
		{
			if (actionID.Equals(MOVEMENT_MODE_TELEPORT_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::TeleportKeyDown:
		{
			if (actionID.Equals(TELEPORT_KEY_DOWN_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::TeleportRotate:
		{
			if (actionID.Equals(TELEPORT_ROTATE_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::NavigateToCreateArea:
		{
			if (actionID.Equals(NAVIGATE_TO_CREATE_AREA_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::CreateEntity:
		{
			if (actionID.Equals(POINT_CREATED_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::ModifyEntity:
		{
			if (actionID.Equals(POINT_MODIFIED_ACTION))
			{
				notifyComplete(TutorialStage);

				TutorialUIMaterial->bDisableDepthTest = true;
			}
		}
		break;

		case ETutorialStage::FlyMovementMode:
		{
			if (actionID.Equals(MOVEMENT_MODE_FLY_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::FlyPlayerMovement:
		{
			if (actionID.Equals(PLAYER_FINISHED_FLY_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::CreateEntity2:
		{
			if (actionID.Equals(POINT_CREATED_ACTION))
			{
				notifyComplete(TutorialStage);
			}
		}
		break;

		case ETutorialStage::Finish:
		{
			if (actionID.Equals(GO_TO_TOC_ACTION))
			{
				PreviousCompletedAction = TEXT("");

				notifyComplete(TutorialStage);

				AbortTutorial();
			}
		}
		break;
	}

	ReceiveTutorialActionOccurred(actionID);

	OnTutorialActionOccurred.Broadcast(actionID);
}

bool UGame_TutorialManager::Initialize()
{
	return true;
}

void UGame_TutorialManager::AbortTutorial()
{
	PreviousCompletedAction = TEXT("");

	CameraOrbsFound = 0;
	
	NumberOfQuickturns = 0;
	
	NumberOfZooms = 0;

	bCanSwitchMouseLook = false;

	bHasSwitchedMouseLook = false;

	SetTutorialStage(ETutorialStage::Inactive);

	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		playerController->ConsoleCommand(TEXT("open MainMap_P"));
	}

	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			inputSubsystem->RemoveMappingContext(TutorialInputMap);
		}
	}
}

void UGame_TutorialManager::GoToNextDesktopStage()
{
	ETutorialStage nextStage = (ETutorialStage)((int32)TutorialStage + 1);

	while(!DesktopStages.Contains(nextStage) && nextStage < ETutorialStage::Finish)
	{
		nextStage = (ETutorialStage)((int32)nextStage + 1);
	}
	
	SetTutorialStage(nextStage);
}

void UGame_TutorialManager::GoToNextVRStage()
{
	ETutorialStage nextStage = (ETutorialStage)((int32)TutorialStage + 1);
	
	while (!VrStages.Contains(nextStage) && nextStage < ETutorialStage::Finish)
	{
		nextStage = (ETutorialStage)((int32)nextStage + 1);
	}
	
	SetTutorialStage(nextStage);
}

void UGame_TutorialManager::UpdateUI(UTexture2D* image, UTexture2D* checkbox, bool bShowEnter, const FString& header, const FString& body, bool bIsVR)
{
	bWaitingOnProgressInput = bShowEnter;
	
	OnUpdateUI.Broadcast(image, checkbox, bShowEnter, header, body, bIsVR);
}

bool UGame_TutorialManager::GetHasSwitchedMouseLook()
{
	return bHasSwitchedMouseLook;
}

void UGame_TutorialManager::SetHasSwitchedMouseLook(bool bNewHasSwitched)
{
	bHasSwitchedMouseLook = bNewHasSwitched;
}

bool UGame_TutorialManager::GetCanSwitchMouseLook()
{
	return bCanSwitchMouseLook;
}
