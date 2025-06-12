// Required Includes
#include "Game_UserWidget_RibbonButton_Orientation.h"
#include "Game.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"
#include "UI_Subsystem_Core.h"
#include "VR_MotionControllerComponent.h"

// Game Includes
#include "Game_Pawn.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_Tool.h"
#include "Game_MotionControllerComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonButton_Orientation::UGame_UserWidget_RibbonButton_Orientation(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_UserWidget_RibbonButton_Orientation::Initialize()
{
	bool bToReturn = Super::Initialize();

	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode::Unknown, subsystem->GetHardwareInterfaceMode());
	}

	return bToReturn;
}

void UGame_UserWidget_RibbonButton_Orientation::NativeConstruct()
{
	Super::NativeConstruct();

	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		TSet<UUserWidget*> widgets = subsystem->GetUserWidgetsByClass(DesktopOrientationWidgetClass, false);
		if (widgets.Num() > 0)
		{
			OrientationWidget = widgets.Array()[0];
		}
		else
		{
			widgets = subsystem->GetUserWidgetsByClass(VROrientationWidgetClass, false);
			if (widgets.Num() > 0)
			{
				OrientationWidget = widgets.Array()[0];
			}
		}
	}

	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode::Unknown, subsystem->GetHardwareInterfaceMode());
	}
}

void UGame_UserWidget_RibbonButton_Orientation::PostClicked()
{
	if (!IsValid(OrientationWidget))
	{
		// create orientation widget
		UDeveloper_Subsystem_Core* subsystemDeveloper = UDeveloper_Subsystem_Core::Get();
		UUI_Subsystem_Core* subsystemUI = UUI_Subsystem_Core::Get();

		if (subsystemDeveloper != nullptr && subsystemUI != nullptr)
		{
			switch (subsystemDeveloper->GetHardwareInterfaceMode())
			{
				case EHardwareInterfaceMode::Desktop:
				{
					OrientationWidget = subsystemUI->OpenWithDefaultsByClass(DesktopOrientationWidgetClass);
				}
				break;

				case EHardwareInterfaceMode::VR:
				case EHardwareInterfaceMode::VREmulation:
				{
					OrientationWidget = subsystemUI->OpenWithDefaultsByClass(VROrientationWidgetClass);

					if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
					{
						AGame_Tool* tool = nullptr;
						AttachedController = playerPawn->GetMotionControllerLastClickedOnWidget(this);
						if (AttachedController != nullptr)
						{
							tool = Cast<AGame_Tool>(AttachedController->GetInputToolStackTop());
						}

						if (tool == nullptr)
						{
							AttachedController = playerPawn->LeftController;

							tool = Cast<AGame_Tool>(AttachedController->GetInputToolStackTop());
						}

						AttachWidgetToTool(tool);
					}
				}
				break;
			}

			SetSelected(true);
		}
	}
	else
	{
		// close orientation widget
		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			subsystem->CloseUserWidget(OrientationWidget);

			SetSelected(false);
			
			OrientationWidget = nullptr;
		}
	}
}

void UGame_UserWidget_RibbonButton_Orientation::PostSetSelected(bool bSelectedArg)
{
	if (!bSelectedArg)
	{
		AttachedController = nullptr;
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_RibbonButton_Orientation::AttachWidgetToTool(AActor* tool)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		FTransform toolTransform = tool->GetActorTransform();

		FVector worldLocation = toolTransform.TransformPosition(VROffsetFromTool);

		AActor* worldUIActor = subsystem->GetUserWidgetWorldUIActor(OrientationWidget);
		worldUIActor->SetActorLocationAndRotation(worldLocation, worldUIActor->GetActorRotation());

		subsystem->SetUserWidgetScale(OrientationWidget, VRScale);

		worldUIActor->AttachToActor(tool, FAttachmentTransformRules::KeepWorldTransform);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_RibbonButton_Orientation::HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		if (IsValid(OrientationWidget))
		{
			subsystem->CloseUserWidget(OrientationWidget);
			OrientationWidget = nullptr;

			if (GetIsSelected())
			{
				SetSelected(false);
			}
		}
	}
}

void UGame_UserWidget_RibbonButton_Orientation::HandleInputStackTopChanged(AActor* tool)
{
	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		EHardwareInterfaceMode mode = subsystem->GetHardwareInterfaceMode();
		if (mode == EHardwareInterfaceMode::VREmulation || mode == EHardwareInterfaceMode::VR)
		{
			if (GetIsSelected())
			{
				AttachWidgetToTool(tool);
			}
		}
	}
}