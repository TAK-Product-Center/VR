// Required Includes
#include "Game_UserWidget_TabButton.h"
#include "Game.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_TabButton::UGame_UserWidget_TabButton(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_TabButton::SetSelected(bool bSelected)
{
	ReceiveSetSelected(bSelected);
}

void UGame_UserWidget_TabButton::SetRepresentedTab(UUserWidget* representedTab, UGame_UserWidget_TabContainer* tabContainerArg)
{
	RepresentedTab = representedTab;

	TabContainer = tabContainerArg;

	ReceiveSetRepresentedTab(representedTab);
}

UUserWidget* UGame_UserWidget_TabButton::GetRepresentedTab() const
{
	return RepresentedTab;
}

UGame_UserWidget_TabContainer* UGame_UserWidget_TabButton::GetTabContainer() const
{
	return TabContainer;
}

void UGame_UserWidget_TabButton::CloseTab()
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		subsystem->CloseUserWidget(GetRepresentedTab());
	}
}

void UGame_UserWidget_TabButton::MoveToNewTabContainer()
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		subsystem->MoveWidgetToNewTabContainer(GetRepresentedTab());
	}
}