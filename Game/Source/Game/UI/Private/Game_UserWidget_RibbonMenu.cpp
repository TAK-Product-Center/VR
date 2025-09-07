// Required Includes
#include "Game_UserWidget_RibbonMenu.h"
#include "Game.h"

// Engine Includes
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/PanelWidget.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "Developer_Subsystem_Core.h"
#include "UI_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonMenu::UGame_UserWidget_RibbonMenu(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Interface_Game_RibbonMenu
// ---------------------------------

void UGame_UserWidget_RibbonMenu::AddButton_Implementation(UUserWidget* buttonWidget, const FString& tab, double indexOfTab, const FString& category, double indexOfCategory, double indexWithinCategory)
{
	// add tab if doesn't already exist
	AddTab(tab, indexOfTab);

	// add category if doesn't already exist
	AddCategoryToTab(tab, category, indexOfCategory);

	AddButtonToCategory(buttonWidget, tab, category, indexWithinCategory);
}

void UGame_UserWidget_RibbonMenu::RemoveButton_Implementation(UUserWidget* buttonWidget, const FString& tab, const FString& category)
{
	RemoveButtonFromCategory(buttonWidget, tab, category);
}

void UGame_UserWidget_RibbonMenu::UpdateContainerVisibility_Implementation()
{
	for (const TPair<FString, FRibbonTabInfo>& tabEntry : TabInfos)
	{
		bool newTabVisibility = false;
		for (const TPair<FString, FRibbonCategoryInfo>& catEntry : tabEntry.Value.Categories)
		{
			bool newCatVisibility = false;
			for (const TPair<UWidget*, double>& buttonEntry : catEntry.Value.Buttons)
			{
				if(buttonEntry.Key->GetVisibility() != ESlateVisibility::Collapsed)
				{
					newCatVisibility = true;
					break;
				}
			}
			catEntry.Value.Widget->SetVisibility(newCatVisibility ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
			newTabVisibility |= newCatVisibility;
		}
		tabEntry.Value.TabButton->SetVisibility(newTabVisibility ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
}

void UGame_UserWidget_RibbonMenu::Clear_Implementation()
{
	GetTabsPanelWidget()->ClearChildren();
	GetTabButtonsPanelWidget()->ClearChildren();
	TabInfos.Empty();
}

// ---------------------------------
// --- Implementation
// ---------------------------------

double UGame_UserWidget_RibbonMenu::GetTabIndex(UWidget* tabWidget) const
{
	for (const TPair<FString, FRibbonTabInfo>& entry : TabInfos)
	{
		if (entry.Value.Tab == tabWidget)
		{
			return entry.Value.Index;
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_RibbonMenu::GetTabIndex | unable to find tabWidget | returning -1"));
	return -1;
}

double UGame_UserWidget_RibbonMenu::GetCategoryIndex(const FRibbonTabInfo& tabInfo, UWidget* categoryWidget) const
{
	for (const TPair<FString, FRibbonCategoryInfo>& entry : tabInfo.Categories)
	{
		if (entry.Value.Widget == categoryWidget)
		{
			return entry.Value.Index;
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_RibbonMenu::GetCategoryIndex | unable to find categoryWidget | returning -1"));
	return -1;
}

double UGame_UserWidget_RibbonMenu::GetButtonIndex(const FRibbonCategoryInfo& categoryInfo, UWidget* buttonWidget) const
{
	if (const double* indexPtr = categoryInfo.Buttons.Find(buttonWidget))
	{
		return *indexPtr;
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_RibbonMenu::GetButtonIndex | unable to find buttonWidget | returning -1"));
	return -1;
}

void UGame_UserWidget_RibbonMenu::AddTab(const FString& tab, double tabIndex)
{
	FRibbonTabInfo* tabInfoPtr = TabInfos.Find(tab);
	if (tabInfoPtr == nullptr)
	{
		FRibbonTabInfo tabInfo;
		tabInfo.ID = tab;
		tabInfo.Tab = UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), TabWidgetClass, FName(*FGuid::NewGuid().ToString()));
		tabInfo.Index = tabIndex;
		tabInfo.TabButton = UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), TabButtonWidgetClass, FName(*FGuid::NewGuid().ToString()));

		TabInfos.Add(tab, tabInfo);

		TabInfos.ValueSort([](FRibbonTabInfo infoA, FRibbonTabInfo infoB) -> bool
		{
			return infoA.Index < infoB.Index;
		});

		UPanelWidget* tabsPanelWidget = GetTabsPanelWidget();
		tabsPanelWidget->ClearChildren();

		UPanelWidget* tabButtonsPanelWidget = GetTabButtonsPanelWidget();
		tabButtonsPanelWidget->ClearChildren();

		for (const TPair<FString, FRibbonTabInfo>& entry : TabInfos)
		{
			tabsPanelWidget->AddChild(entry.Value.Tab);

			tabButtonsPanelWidget->AddChild(entry.Value.TabButton);

			ReceiveTabButtonAdded(entry.Value.TabButton, entry.Value.ID, entry.Value.Tab);
		}
	}
}

void UGame_UserWidget_RibbonMenu::AddCategoryToTab(const FString& tab, const FString& category, double categoryIndex)
{
	if (FRibbonTabInfo* tabInfo = TabInfos.Find(tab))
	{
		FRibbonCategoryInfo* categoryInfoPtr = tabInfo->Categories.Find(category);
		if (categoryInfoPtr == nullptr)
		{
			FRibbonCategoryInfo categoryInfo;
			categoryInfo.ID = category;
			categoryInfo.Widget = UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), CategoryWidgetClass, FName(*FGuid::NewGuid().ToString()));
			categoryInfo.Index = categoryIndex;

			tabInfo->Categories.Add(category, categoryInfo);

			tabInfo->Categories.ValueSort([](FRibbonCategoryInfo infoA, FRibbonCategoryInfo infoB) -> bool
			{
				return infoA.Index < infoB.Index;
			});

			UPanelWidget* categoriesPanelWidget = GetPanelWidgetOfTab(tabInfo->Tab);
			categoriesPanelWidget->ClearChildren();

			for (const TPair<FString, FRibbonCategoryInfo>& entry : tabInfo->Categories)
			{
				categoriesPanelWidget->AddChild(entry.Value.Widget);
			}

			ReceiveCategoryAdded(categoryInfo.Widget, categoryInfo.ID);
		}
	}
}

void UGame_UserWidget_RibbonMenu::AddButtonToCategory(UUserWidget* buttonWidget, const FString& tab, const FString& category, double buttonIndex)
{
	if (FRibbonTabInfo* tabInfo = TabInfos.Find(tab))
	{
		if (FRibbonCategoryInfo* categoryInfo = tabInfo->Categories.Find(category))
		{
			categoryInfo->Buttons.Add(buttonWidget, buttonIndex);

			categoryInfo->Buttons.ValueSort([](double indexA, double indexB) -> bool
			{
				return indexA < indexB;
			});
			
			UPanelWidget* buttonPanelWidget = GetPanelWidgetOfCategory(categoryInfo->Widget);
			buttonPanelWidget->ClearChildren();

			for (const TPair<UWidget*, double>& entry : categoryInfo->Buttons)
			{
				buttonPanelWidget->AddChild(entry.Key);
			}
		}
	}
}

void UGame_UserWidget_RibbonMenu::RemoveButtonFromCategory(UUserWidget* buttonWidget, const FString& tab, const FString& category)
{
	if (FRibbonTabInfo* tabInfo = TabInfos.Find(tab))
	{
		if (FRibbonCategoryInfo* categoryInfo = tabInfo->Categories.Find(category))
		{
			UPanelWidget* buttonPanelWidget = GetPanelWidgetOfCategory(categoryInfo->Widget);

			buttonPanelWidget->RemoveChild(buttonWidget);
			
			categoryInfo->Buttons.Remove(buttonWidget);

			if (!buttonPanelWidget->HasAnyChildren())
			{
				RemoveCategoryFromTab(tab, category);
			}
		}
	}
}

void UGame_UserWidget_RibbonMenu::RemoveCategoryFromTab(const FString& tab, const FString& category)
{
	if (FRibbonTabInfo* tabInfo = TabInfos.Find(tab))
	{
		if (FRibbonCategoryInfo* categoryInfo = tabInfo->Categories.Find(category))
		{
			UPanelWidget* categoriesPanelWidget = GetPanelWidgetOfTab(tabInfo->Tab);

			categoriesPanelWidget->RemoveChild(categoryInfo->Widget);

			if (!categoriesPanelWidget->HasAnyChildren())
			{
				RemoveTab(tab);
			}
		}

		tabInfo->Categories.Remove(category);
	}
}

void UGame_UserWidget_RibbonMenu::RemoveTab(const FString& tab)
{
	if (FRibbonTabInfo* tabInfo = TabInfos.Find(tab))
	{
		UPanelWidget* tabsPanelWidget = GetTabsPanelWidget();
		UPanelWidget* tabButtonsPanelWidget = GetTabButtonsPanelWidget();
		
		tabsPanelWidget->RemoveChild(tabInfo->Tab);
		tabButtonsPanelWidget->RemoveChild(tabInfo->TabButton);

		TabInfos.Remove(tab);
	}
}