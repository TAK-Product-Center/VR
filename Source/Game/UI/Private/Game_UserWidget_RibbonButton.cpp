// Required Includes
#include "Game_UserWidget_RibbonButton.h"
#include "Game.h"

// Engine Plugins
#include "Misc/Guid.h"
#include "Blueprint/SlateBlueprintLibrary.h"

// VH Plugin Includes
#include "VR_MotionControllerComponent.h"
#include "UI_Subsystem_ContextMenu.h"
#include "Interface_UI_ContextMenuSource.h"
#include "UI_Subsystem_Core.h"
#include "VR_TraceComponent.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_Pawn.h"
#include "Game_Tool.h"
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_MotionControllerComponent.h"
#include "Game_Subsystem_Ribbon.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonButton::UGame_UserWidget_RibbonButton(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Interface_Game_RibbonButton
// ---------------------------------

FString UGame_UserWidget_RibbonButton::GetID_Implementation()
{
	if (ID.IsEmpty())
	{
		ID = FGuid::NewGuid().ToString();
	}

	return ID;
}

bool UGame_UserWidget_RibbonButton::GetDefaultTab_Implementation(FString& tab)
{
	tab = DefaultTab;

	return DefaultTab.IsEmpty();
}

bool UGame_UserWidget_RibbonButton::GetDefaultCategory_Implementation(FString& category)
{
	category = DefaultCategory;

	return !DefaultCategory.IsEmpty();
}

bool UGame_UserWidget_RibbonButton::GetDefaultIndexInCategory_Implementation(double& index)
{
	index = DefaultIndexInCategory;

	return DefaultIndexInCategory > 0;
}

bool UGame_UserWidget_RibbonButton::GetEnableConditions_Implementation(TMap<FString, int32>& conditions)
{
	conditions = EnableConditions;
	return EnableConditions.Num() > 0;
}

bool UGame_UserWidget_RibbonButton::GetCollapseOnDisable_Implementation()
{
	return bCollapseOnDisable;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_UserWidget_RibbonButton::Initialize()
{
	bool bToReturn = Super::Initialize();

	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		subsystem->OnHardwareInterfaceModeChanged.AddDynamic(this, &UGame_UserWidget_RibbonButton::HandleHardwareInterfaceModeChanged);
	}

	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		playerPawn->LeftController->OnInputStackTopChanged.AddDynamic(this, &UGame_UserWidget_RibbonButton::HandleInputStackTopChanged);

		playerPawn->RightController->OnInputStackTopChanged.AddDynamic(this, &UGame_UserWidget_RibbonButton::HandleInputStackTopChanged);
	}

	if (UUI_Subsystem_Core* coreSubsystem = UUI_Subsystem_Core::Get()) 
	{
		coreSubsystem->OnUserWidgetClosed.AddUniqueDynamic(this, &UGame_UserWidget_RibbonButton::HandleUserWidgetClosed);
	}

	return bToReturn;
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_UserWidget_RibbonButton::ShouldShowDropdownButton() const
{
	if (DropdownClass != nullptr)
	{
		return true;
	}

	if (ToolClass != nullptr) 
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (AActor* leftTool = playerPawn->LeftController->GetInputToolStackTop())
			{
				if (leftTool->GetClass() == ToolClass)
				{
					TSet<TSubclassOf<UObject>> contextOptionClasses;
					IInterface_UI_ContextMenuSource::Execute_GetContextOptionClasses(leftTool, contextOptionClasses);

					if (contextOptionClasses.Num() > 0)
					{
						return true;
					}
				}
			}

			if (AActor* rightTool = playerPawn->RightController->GetInputToolStackTop())
			{
				if (rightTool->GetClass() == ToolClass)
				{
					TSet<TSubclassOf<UObject>> contextOptionClasses;
					IInterface_UI_ContextMenuSource::Execute_GetContextOptionClasses(rightTool, contextOptionClasses);

					if (contextOptionClasses.Num() > 0)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

void UGame_UserWidget_RibbonButton::ToggleDropdown(AGame_Tool* tool)
{
	if (ShouldShowDropdownButton()) 
	{
		UUI_Subsystem_ContextMenu* contextMenuSubsystem = UUI_Subsystem_ContextMenu::Get();
		UUI_Subsystem_Core* coreSubsystem = UUI_Subsystem_Core::Get();
		UDeveloper_Subsystem_Core* developerSubsystem = UDeveloper_Subsystem_Core::Get();

		if (contextMenuSubsystem != nullptr && coreSubsystem != nullptr && developerSubsystem != nullptr)
		{
			if (SpawnedDropdownMenu != nullptr)
			{
				coreSubsystem->CloseUserWidget(SpawnedDropdownMenu);
				SpawnedDropdownMenu = nullptr;
			}
			else if (DropdownClass != nullptr)
			{
				SpawnedDropdownMenu = coreSubsystem->OpenWithDefaultsByClass(DropdownClass);
			}
			else if (ToolClass != nullptr)
			{
				if (tool == nullptr)
				{
					if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
					{
						if (developerSubsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Desktop)
						{
							// desktop only has left controller
							tool = Cast<AGame_Tool>(playerPawn->LeftController->GetInputToolStackTop());
						}
						else
						{
							if (UVR_MotionControllerComponent* motionControllerComponent = playerPawn->GetMotionControllerLastClickedOnWidget(this))
							{
								tool = Cast<AGame_Tool>(motionControllerComponent->GetInputToolStackTop());
							}
						}
					}
				}

				if (tool != nullptr)
				{
					SpawnedDropdownMenu = contextMenuSubsystem->OpenContextMenuWithDefaults(tool, tool);
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_RibbonButton::ToggleDropdown | tool is nullptr"));
				}
			}

			if (SpawnedDropdownMenu != nullptr) 
			{
				if (developerSubsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Desktop)
				{
					FVector2D outPixel;
					FVector2D outViewport;
					USlateBlueprintLibrary::AbsoluteToViewport(GetWorld(), GetCachedGeometry().GetAbsolutePositionAtCoordinates(FVector2D(0.5, 1)), outPixel, outViewport);

					coreSubsystem->SetUserWidgetPosition(SpawnedDropdownMenu, outPixel);
				}
				else if (tool != nullptr)
				{
					FVector location;
					tool->GetWorldUIHitLocation(location);

					// move 50 unreal units towards the tool so the context menu gets trace before ribbon
					double distance = FVector::Distance(location, tool->GetActorLocation());

					location = location + ((tool->GetActorLocation() - location).GetSafeNormal() * 50);

					coreSubsystem->MoveUserWidgetToWorldLocation(SpawnedDropdownMenu, location);
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_RibbonButton::ToggleDropdown | tool is nullptr"));
				}
			}
		}
	}
}

void UGame_UserWidget_RibbonButton::CloseDropdownMenu()
{
	if (UUI_Subsystem_Core* coreSubsystem = UUI_Subsystem_Core::Get())
	{
		if (SpawnedDropdownMenu != nullptr)
		{
			coreSubsystem->CloseUserWidget(SpawnedDropdownMenu);
			SpawnedDropdownMenu = nullptr;
		}
	}
}

void UGame_UserWidget_RibbonButton::Clicked()
{
	if (ToolClass != nullptr)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (UDeveloper_Subsystem_Core* subsystemCore = UDeveloper_Subsystem_Core::Get())
			{
				if (UGame_Subsystem_Ribbon* subsystemRibbon = UGame_Subsystem_Ribbon::Get())
				{
					if (subsystemCore->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Desktop)
					{
						bool bSwappedToNull = false;

						// desktop mode only uses the left controller
						if (AActor* toolStackTop = playerPawn->LeftController->GetInputToolStackTop())
						{
							if (toolStackTop->GetClass() == ToolClass)
							{
								playerPawn->LeftController->RemoveAllTools();
								playerPawn->LeftController->AddToolByClass(subsystemRibbon->NullToolClass);
								
								bSwappedToNull = true;
							}
						}

						if (!bSwappedToNull)
						{
							playerPawn->LeftController->RemoveAllTools();
							playerPawn->LeftController->AddToolByClass(ToolClass);
						}
					}
					else
					{
						if (UVR_MotionControllerComponent* motionControllerComponent = playerPawn->GetMotionControllerLastClickedOnWidget(this))
						{
							bool bSwappedToNull = false;

							if (AActor* toolStackTop = motionControllerComponent->GetInputToolStackTop())
							{
								if (motionControllerComponent->GetInputToolStackTop()->GetClass() == ToolClass)
								{
									motionControllerComponent->RemoveAllTools();
									motionControllerComponent->AddToolByClass(subsystemRibbon->NullToolClass);

									bSwappedToNull = true;
								}
							}

							if (!bSwappedToNull)
							{
								motionControllerComponent->RemoveAllTools();
								motionControllerComponent->AddToolByClass(ToolClass);
							}
						}
						else
						{
							UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_RibbonButton::Clicked | could not find VR_MotionControllerComponent | aborting"));
						}
					}
				}
			}
		}
	}

	if (ToolClass == nullptr && MenuClass != nullptr)
	{
		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			if (subsystem->GetUserWidgetsByClass(MenuClass, true).Num() == 0)
			{
				subsystem->OpenWithDefaultsByClass(MenuClass);
			}
		}
	}

	// Show context menu if one is set
	if (ToolClass == nullptr)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (UVR_MotionControllerComponent* motionControllerComponent = playerPawn->GetMotionControllerLastClickedOnWidget(this))
			{
				AGame_Tool* tool = Cast<AGame_Tool>(motionControllerComponent->GetInputToolStackTop());
				ToggleDropdown(tool);
			}
		}
	}

	PostClicked();

	ReceiveClicked();

	OnClicked.Broadcast(this);
}

void UGame_UserWidget_RibbonButton::SetIcon(const FSlateBrush& icon)
{
	Icon = icon;

	ReceiveSetIcon(Icon);

	OnSetIcon.Broadcast(Icon);
}

void UGame_UserWidget_RibbonButton::SetText(const FString& text)
{
	Text = text;

	ReceiveSetText(Text);

	OnSetText.Broadcast(text);
}

void UGame_UserWidget_RibbonButton::SetRibbonToolTip(const FString& toolTipArg)
{
	RibbonToolTip = toolTipArg;

	ReceiveSetRibbonToolTip(RibbonToolTip);

	OnSetRibbonToolTip.Broadcast(toolTipArg);
}

bool UGame_UserWidget_RibbonButton::GetIsSelected() const
{
	return bSelected;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_RibbonButton::PostClicked()
{

}

void UGame_UserWidget_RibbonButton::PostSetSelected(bool bSelectedArg)
{

}

void UGame_UserWidget_RibbonButton::PostInputStackTopChanged(AActor* tool)
{

}

void UGame_UserWidget_RibbonButton::SetSelected(bool bSelectedArg)
{
	bSelected = bSelectedArg;

	PostSetSelected(bSelected);

	ReceiveSetSelected(bSelected);

	OnSetSelected.Broadcast(bSelectedArg);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_RibbonButton::HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode)
{
	if (ToolClass != nullptr)
	{
		// update highlights if switching interface mode
		int32 equippedHands = 0;

		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (AActor* topTool = playerPawn->LeftController->GetInputToolStackTop())
			{
				if (topTool->GetClass() == ToolClass)
				{
					equippedHands += 1;
				}
			}

			if (newMode != EHardwareInterfaceMode::Desktop)
			{
				if (AActor* topTool = playerPawn->RightController->GetInputToolStackTop())
				{
					if (topTool->GetClass() == ToolClass)
					{
						equippedHands += 2;
					}
				}
			}
		}
		
		EquippedHands = static_cast<EHandWithLinkedToolClass>(equippedHands);

		SetSelected(equippedHands > 0);
	}
}

void UGame_UserWidget_RibbonButton::HandleInputStackTopChanged(AActor* tool)
{
	if (ToolClass != nullptr)
	{
		UUI_Subsystem_Core* coreSubsystem = UUI_Subsystem_Core::Get();

		if (SpawnedDropdownMenu != nullptr && coreSubsystem != nullptr)
		{
			coreSubsystem->CloseUserWidget(SpawnedDropdownMenu);
			SpawnedDropdownMenu = nullptr;
		}

		int32 equippedHands = 0;

		// Select if player is using tool of same class with either hand
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (UDeveloper_Subsystem_Core* devSubsystem = UDeveloper_Subsystem_Core::Get())
			{
				if (AActor* topTool = playerPawn->LeftController->GetInputToolStackTop())
				{
					if (topTool->GetClass() == ToolClass)
					{
						equippedHands += 1;
					}
				}

				if (devSubsystem->GetHardwareInterfaceMode() != EHardwareInterfaceMode::Desktop)
				{
					if (AActor* topTool = playerPawn->RightController->GetInputToolStackTop())
					{
						if(topTool->GetClass() == ToolClass)
						{
							equippedHands += 2;
						}
					}
				}
			}
		}
		
		EquippedHands = static_cast<EHandWithLinkedToolClass>(equippedHands);
		SetSelected(equippedHands > 0);

		if (AGame_Tool* gameTool = Cast<AGame_Tool>(tool))
		{
			if (ToolClass == tool->GetClass())
			{
				// Show context menu if one is set
				ToggleDropdown(gameTool);

				// if ToolClass and MenuClass are valid; open MenuClass userwidget
				if (MenuClass != nullptr)
				{
					if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
					{
						if (subsystem->GetUserWidgetsByClass(MenuClass, true).Num() == 0)
						{
							gameTool->DefaultOptionsUserWidget = subsystem->OpenWithDefaultsByClass(MenuClass);
						}
					}
				}
			}
		}
	}

	PostInputStackTopChanged(tool);
}

void UGame_UserWidget_RibbonButton::HandleUserWidgetClosed(UUserWidget* userWidget)
{
	if (SpawnedDropdownMenu == userWidget) 
	{
		SpawnedDropdownMenu = nullptr;
	}
}
