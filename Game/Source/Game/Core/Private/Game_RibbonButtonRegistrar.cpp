// Required Includes
#include "Game_RibbonButtonRegistrar.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"

// VH Plugin Includes
#include "Developer_Statics.h"

// Game Includes
#include "Game_Subsystem_Ribbon.h"
#include "Game_Tool.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_RibbonButtonRegistrar::UGame_RibbonButtonRegistrar(const FObjectInitializer& objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

UWorld* UGame_RibbonButtonRegistrar::GetWorld() const
{
	return World;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_RibbonButtonRegistrar::RegisterRibbonButtons(UWorld* world)
{
	World = world;

	ReceiveRegisterRibbonButtons();

	UGame_Subsystem_Ribbon* subsystem = UGame_Subsystem_Ribbon::Get();

	for (const FRibbonButtonInfo& ribbonButtonInfo : RibbonButtonInfos)
	{
		UGame_UserWidget_RibbonButton* ribbonButton = Cast<UGame_UserWidget_RibbonButton>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), ribbonButtonInfo.RibbonButtonClass, FName(*FGuid::NewGuid().ToString())));
		
		ribbonButton->ID = ribbonButtonInfo.ID.IsEmpty() ? FGuid::NewGuid().ToString() : ribbonButtonInfo.ID;
		ribbonButton->DefaultTab = ribbonButtonInfo.Tab;
		ribbonButton->DefaultCategory = ribbonButtonInfo.Category;
		ribbonButton->DefaultIndexInCategory = ribbonButtonInfo.IndexInCategory;
		ribbonButton->Icon = ribbonButtonInfo.Icon;
		ribbonButton->Text = ribbonButtonInfo.Text;
		ribbonButton->ToolClass = ribbonButtonInfo.ToolClass;
		ribbonButton->MenuClass = ribbonButtonInfo.WidgetClass;
		ribbonButton->DropdownClass = ribbonButtonInfo.DropdownClass;
		ribbonButton->bCollapseOnDisable = ribbonButtonInfo.bCollapseOnDisable;
		ribbonButton->SetToolTipText(FText::FromString(ribbonButtonInfo.RibbonToolTipText));
		ribbonButton->EnableConditions.Empty();
		ribbonButton->EnableConditions.Append(ribbonButtonInfo.EnableConditions);

		subsystem->RegisterButton(ribbonButton);
	}

	ReceiveFinishedRegisterRibbonButtons();
}