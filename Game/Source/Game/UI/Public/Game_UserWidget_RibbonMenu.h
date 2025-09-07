#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Game Includes
#include "Interface_Game_RibbonMenu.h"

// Generated Includes
#include "Game_UserWidget_RibbonMenu.generated.h"

class UPanelWidget;

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT()
struct FRibbonCategoryInfo
{
	GENERATED_BODY()

	FString ID;

	UPROPERTY()
	UUserWidget* Widget;

	double Index;

	UPROPERTY()
	TMap<UWidget*, double> Buttons;
};

USTRUCT()
struct FRibbonTabInfo
{
	GENERATED_BODY()

	FString ID;

	UPROPERTY()
	UUserWidget* Tab;

	UPROPERTY()
	UUserWidget* TabButton;

	double Index;

	/* key is category, value is FCategoryInfo for that category */
	UPROPERTY()
	TMap<FString, FRibbonCategoryInfo> Categories;
};

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_RibbonMenu : public UUserWidget, public IInterface_Game_RibbonMenu
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> TabWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> TabButtonWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> CategoryWidgetClass;

private:
	/* key is tab, value is FTabInfo for that tab */
	UPROPERTY()
	TMap<FString, FRibbonTabInfo> TabInfos;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonMenu(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_Game_RibbonMenu
	// ---------------------------------

public:
	void AddButton_Implementation(UUserWidget* buttonWidget, const FString& tab, double indexOfTab, const FString& category, double indexOfCategory, double indexWithinCategory);

	void RemoveButton_Implementation(UUserWidget* buttonWidget, const FString& tab, const FString& category);

	void UpdateContainerVisibility_Implementation();

	void Clear_Implementation() override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

	/* returns UPanelWidget that contains tabs */
	UFUNCTION(BlueprintImplementableEvent)
	UPanelWidget* GetTabsPanelWidget() const;

	/* returns UPanelWidget that contains tab buttons */
	UFUNCTION(BlueprintImplementableEvent)
	UPanelWidget* GetTabButtonsPanelWidget() const;

	/* returns UPanelWidget of a tab that contains that tab's category widgets */
	UFUNCTION(BlueprintImplementableEvent)
	UPanelWidget* GetPanelWidgetOfTab(UUserWidget* tabWidget) const;

	/* returns UPanelWidget of a category that contains that category's button widgets */
	UFUNCTION(BlueprintImplementableEvent)
	UPanelWidget* GetPanelWidgetOfCategory(UUserWidget* categoryWidget) const;

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTabButtonAdded(UUserWidget* tabButton, const FString& tab, UUserWidget* tabWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveCategoryAdded(UUserWidget* categoryWidget, const FString& category);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	double GetTabIndex(UWidget* tabWidget) const;

	double GetCategoryIndex(const FRibbonTabInfo& tabInfo, UWidget* categoryWidget) const;

	double GetButtonIndex(const FRibbonCategoryInfo& categoryInfo, UWidget* buttonWidget) const;

	void AddTab(const FString& tab, double tabIndex);

	void AddCategoryToTab(const FString& tab, const FString& category, double categoryIndex);

	void AddButtonToCategory(UUserWidget* buttonWidget, const FString& tab, const FString& category, double buttonIndex);

	void RemoveButtonFromCategory(UUserWidget* buttonWidget, const FString& tab, const FString& category);

	void RemoveCategoryFromTab(const FString& tab, const FString& category);

	void RemoveTab(const FString& tab);
};