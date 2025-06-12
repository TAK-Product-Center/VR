#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_TabButton.generated.h"

class UGame_UserWidget_TabContainer;

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_TabButton : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClicked, UGame_UserWidget_TabButton*, tab);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnClicked OnClicked;

private:
	UPROPERTY()
	UUserWidget* RepresentedTab;

	UPROPERTY()
	UGame_UserWidget_TabContainer* TabContainer;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_TabButton(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTabCountAndIndex(int32 tabCount, int32 tabIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetRepresentedTab(UUserWidget* representedTabArg);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetSelected(bool bSelected);

	void SetSelected(bool bSelected);

	void SetRepresentedTab(UUserWidget* representedTab, UGame_UserWidget_TabContainer* tabContainerArg);

	UFUNCTION(BlueprintPure)
	UUserWidget* GetRepresentedTab() const;

	UFUNCTION(BlueprintPure)
	UGame_UserWidget_TabContainer* GetTabContainer() const;

	UFUNCTION(BlueprintCallable)
	void CloseTab();

	UFUNCTION(BlueprintCallable)
	void MoveToNewTabContainer();
};