#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "Interface_UI_TabContainer.h"

// Generated Includes
#include "Game_UserWidget_TabContainer.generated.h"

class UGame_UserWidget_TabButton;
class UWidgetSwitcher;
class UVR_MotionControllerComponent;

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_TabContainer : public UUserWidget, public IInterface_UI_TabContainer
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* converts from pixel to unreal units */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double ResizeMultiplier;

private:
	UPROPERTY()
	TMap<UUserWidget*, UGame_UserWidget_TabButton*> TabToTabButton;

	bool bResizing;

	FVector ResizingInitialPlaneIntersection;

	FVector2D ResizingInitialSize;

	UPROPERTY()
	UUserWidget* FocusedTab;

	UPROPERTY()
	UUserWidget* LastFocusedTab;

	UPROPERTY()
	UVR_MotionControllerComponent* ResizingMotionControllerComponent;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_TabContainer(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_UI_TabContainer
	// ---------------------------------

public:
	virtual void AddTab_Implementation(UUserWidget* tab);

	virtual void RemoveTab_Implementation(UUserWidget* tab);

	virtual void RemoveAllTabs_Implementation();

	virtual void SetFocusedTab_Implementation(UUserWidget* tab);

	virtual int32 GetNumberOfTabs_Implementation() const;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void NativeTick(const FGeometry& myGeometry, float inDeltaSeconds) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	UGame_UserWidget_TabButton* ReceiveAddTab(UUserWidget* tab);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveRemoveTab(UUserWidget* tab, UGame_UserWidget_TabButton* tabButton);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTabButtonClicked(UGame_UserWidget_TabButton* tabButton, UUserWidget* tab);

	UFUNCTION(BlueprintImplementableEvent)
	int32 GetTabIndex(UUserWidget* tab);

	UFUNCTION(BlueprintCallable)
	void SetIsResizing(bool bResizingArg);

	UFUNCTION(BlueprintPure)
	bool GetIsResizing() const;

	UFUNCTION(BlueprintPure)
	bool IsAttachedToPlayer();

	UFUNCTION(BlueprintCallable)
	void SetAttachedToPlayer(bool bAttach);

	UFUNCTION(BlueprintPure)
	UGame_UserWidget_TabButton* GetTabButton(UUserWidget* tab) const;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool GetLocalPlaneIntersection(FVector& local) const;

	void SyncTabButtonsToCountAndIndex();

	UFUNCTION(BlueprintCallable)
	void MoveTab(UUserWidget* tab, int32 indexDelta, UWidgetSwitcher* widgetSwitcher);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleTabButtonClicked(UGame_UserWidget_TabButton* tabButton);
};