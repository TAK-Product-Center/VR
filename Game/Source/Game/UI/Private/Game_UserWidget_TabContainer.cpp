// Required Includes
#include "Game_UserWidget_TabContainer.h"
#include "Game.h"

// Engine Includes
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/WidgetSwitcher.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"
#include "VR_MotionControllerComponent.h"
#include "VR_TraceComponent.h"

// Game Includes
#include "Game_UserWidget_TabButton.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_Tool.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_TabContainer::UGame_UserWidget_TabContainer(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	ResizeMultiplier(0.0325)
{

}

// ---------------------------------
// --- Interface_UI_TabContainer
// ---------------------------------

void UGame_UserWidget_TabContainer::AddTab_Implementation(UUserWidget* tab)
{
	UGame_UserWidget_TabButton* tabButton = ReceiveAddTab(tab);
	tabButton->SetRepresentedTab(tab, this);
	tabButton->OnClicked.AddDynamic(this, &UGame_UserWidget_TabContainer::HandleTabButtonClicked);

	TabToTabButton.Add(tab, tabButton);

	if (TabToTabButton.Num() == 1)
	{
		tabButton->SetSelected(true);

		LastFocusedTab = FocusedTab;
		FocusedTab = tab;
	}

	SyncTabButtonsToCountAndIndex();
}

void UGame_UserWidget_TabContainer::RemoveTab_Implementation(UUserWidget* tab)
{
	if (UGame_UserWidget_TabButton** tabButtonPtr = TabToTabButton.Find(tab))
	{
		// remove tab
		UGame_UserWidget_TabButton* tabButton = *tabButtonPtr;

		ReceiveRemoveTab(tab, tabButton);

		TabToTabButton.Remove(tab);

		// select last focused tab (if valid)
		bool bFoundNewTab = false;
		if (IsValid(LastFocusedTab))
		{
			if (UGame_UserWidget_TabButton** focusButtonPtr = TabToTabButton.Find(LastFocusedTab))
			{
				HandleTabButtonClicked(*focusButtonPtr);

				bFoundNewTab = true;
			}
		}
		
		if (!bFoundNewTab)
		{
			// select a tab
			for (const TPair<UUserWidget*, UGame_UserWidget_TabButton*>& entry : TabToTabButton)
			{
				HandleTabButtonClicked(entry.Value);

				break;
			}
		}
	}

	SyncTabButtonsToCountAndIndex();
}

void UGame_UserWidget_TabContainer::RemoveAllTabs_Implementation()
{
	TArray<UUserWidget*> tabs;
	TabToTabButton.GenerateKeyArray(tabs);

	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		for (UUserWidget* tab : tabs)
		{
			subsystem->CloseUserWidget(tab);
		}
	}
}

void UGame_UserWidget_TabContainer::SetFocusedTab_Implementation(UUserWidget* tab)
{
	if (UGame_UserWidget_TabButton** buttonPtr = TabToTabButton.Find(tab))
	{
		HandleTabButtonClicked(*buttonPtr);
	}
}

int32 UGame_UserWidget_TabContainer::GetNumberOfTabs_Implementation() const
{
	return TabToTabButton.Num();
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_TabContainer::NativeTick(const FGeometry& myGeometry, float inDeltaSeconds)
{
	Super::NativeTick(myGeometry, inDeltaSeconds);

	if (bResizing)
	{
		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			FVector localPlaneIntersection;
			if (GetLocalPlaneIntersection(localPlaneIntersection))
			{
				FVector2D newSize;

				newSize.X = ResizingInitialSize.X + (localPlaneIntersection.Y - ResizingInitialPlaneIntersection.Y) * ResizeMultiplier;
				newSize.Y = ResizingInitialSize.Y + (localPlaneIntersection.Z - ResizingInitialPlaneIntersection.Z) * ResizeMultiplier;

				newSize.X = FMath::Max<double>(newSize.X, 200);
				newSize.Y = FMath::Max<double>(newSize.Y, 200);

				subsystem->SetUserWidgetSize(this, newSize);
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_TabContainer::SetIsResizing(bool bResizingArg)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		bResizing = bResizingArg;

		if (bResizingArg)
		{
			if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
			{
				ResizingMotionControllerComponent = playerPawn->GetMotionControllerLastClickedOnWidget(this);

				if (GetLocalPlaneIntersection(ResizingInitialPlaneIntersection))
				{
					ResizingInitialSize = subsystem->GetUserWidgetSize(this);
				}
				else
				{
					SetIsResizing(false);
				}
			}
		}
		else
		{
			ResizingMotionControllerComponent = nullptr;
		}
	}
}

bool UGame_UserWidget_TabContainer::GetIsResizing() const
{
	return bResizing;
}

bool UGame_UserWidget_TabContainer::IsAttachedToPlayer()
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		if (AActor* worldUIActor = subsystem->GetUserWidgetWorldUIActor(this))
		{
			return worldUIActor->IsAttachedTo(UGame_Statics::GetVHPlayerPawn());
		}
	}

	return false;
}

void UGame_UserWidget_TabContainer::SetAttachedToPlayer(bool bAttach)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		if (AActor* worldUIActor = subsystem->GetUserWidgetWorldUIActor(this))
		{
			if (bAttach)
			{
				worldUIActor->AttachToActor(UGame_Statics::GetVHPlayerPawn(), FAttachmentTransformRules::KeepWorldTransform);
			}
			else
			{
				worldUIActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			}
		}
	}
}

UGame_UserWidget_TabButton* UGame_UserWidget_TabContainer::GetTabButton(UUserWidget* tab) const
{
	if (UGame_UserWidget_TabButton* const* tabButtonPtr = TabToTabButton.Find(tab))
	{
		return *tabButtonPtr;
	}

	return nullptr;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_UserWidget_TabContainer::GetLocalPlaneIntersection(FVector& local) const
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		if (AActor* worldUIActor = subsystem->GetUserWidgetWorldUIActor(this))
		{
			FPlane plane(worldUIActor->GetActorLocation(), worldUIActor->GetActorForwardVector());

			if (IsValid(ResizingMotionControllerComponent))
			{
				if (AGame_Tool* tool = Cast<AGame_Tool>(ResizingMotionControllerComponent->GetInputToolStackTop()))
				{
					FTransform toolTransform = tool->VRTrace->GetComponentTransform();

					FVector hitLocation = toolTransform.TransformPosition(FVector(100000, 0, 0));
					
					FVector planeIntersection = FMath::LinePlaneIntersection(tool->GetActorLocation(), hitLocation, plane);

					local = worldUIActor->GetActorTransform().InverseTransformPosition(hitLocation);

					return true;
				}
			}
		}
	}

	return false;
}


void UGame_UserWidget_TabContainer::SyncTabButtonsToCountAndIndex()
{
	for (const TPair<UUserWidget*, UGame_UserWidget_TabButton*>& entry : TabToTabButton)
	{
		entry.Value->ReceiveTabCountAndIndex(TabToTabButton.Num(), GetTabIndex(entry.Key));
	}
}

void UGame_UserWidget_TabContainer::MoveTab(UUserWidget* tab, int32 indexDelta, UWidgetSwitcher* widgetSwitcher)
{
	if (indexDelta == 0)
	{
		return;
	}

	TArray<UWidget*> tabs = widgetSwitcher->GetAllChildren();

	// move the tab in local array 
	int32 oldIndex = tabs.Find(tab);
	if (oldIndex != INDEX_NONE)
	{
		if (indexDelta > 0)
		{
			int32 newIndex = FMath::Clamp<int32>(oldIndex + indexDelta + 1, 0, tabs.Num());

			tabs.Insert(tab, newIndex);
			tabs.RemoveAt(oldIndex);
		}
		else
		{
			int32 newIndex = FMath::Clamp<int32>(oldIndex + indexDelta, 0, tabs.Num());
			
			tabs.Insert(tab, newIndex);
			tabs.RemoveAt(oldIndex + 1);
		}
	}

	// remove tabs, then add back in the new order
	for (UWidget* tabWidget : tabs)
	{
		IInterface_UI_TabContainer::Execute_RemoveTab(this, Cast<UUserWidget>(tabWidget));
	}

	for (UWidget* tabWidget : tabs)
	{
		IInterface_UI_TabContainer::Execute_AddTab(this, Cast<UUserWidget>(tabWidget));
	}

	// set the moved tab active
	if (UGame_UserWidget_TabButton* tabButton = GetTabButton(tab))
	{
		HandleTabButtonClicked(tabButton);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_TabContainer::HandleTabButtonClicked(UGame_UserWidget_TabButton* tabButton)
{
	for (const TPair<UUserWidget*, UGame_UserWidget_TabButton*>& entry : TabToTabButton)
	{
		if (entry.Value == tabButton)
		{
			ReceiveTabButtonClicked(entry.Value, entry.Key);

			LastFocusedTab = FocusedTab;
			FocusedTab = entry.Key;
		}

		entry.Value->SetSelected(entry.Value == tabButton);
	}
}