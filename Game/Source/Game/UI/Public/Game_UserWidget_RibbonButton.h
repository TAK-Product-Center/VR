#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Game Includes
#include "Interface_Game_RibbonButton.h"

// Generated Includes
#include "Game_UserWidget_RibbonButton.generated.h"

class AGame_Tool;
class UVR_MotionControllerComponent;

UENUM(BlueprintType)
enum class EHandWithLinkedToolClass : uint8
{
	None,
	Left,
	Right,
	Both
};

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_RibbonButton : public UUserWidget, public IInterface_Game_RibbonButton
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClicked, UGame_UserWidget_RibbonButton*, ribbonButton);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetSelected, bool, bSelected);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetIcon, const FSlateBrush&, icon);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetText, const FString&, test);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetRibbonToolTip, const FString&, toolTip);
	 
	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnClicked OnClicked;

	UPROPERTY(BlueprintAssignable)
	FOnSetSelected OnSetSelected;

	UPROPERTY(BlueprintAssignable)
	FOnSetIcon OnSetIcon;

	UPROPERTY(BlueprintAssignable)
	FOnSetText OnSetText;

	UPROPERTY(BlueprintAssignable)
	FOnSetRibbonToolTip OnSetRibbonToolTip;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString Text;

	// Note: TODO: Make Tool Tips work in VR
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString RibbonToolTip;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FSlateBrush Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	EHandWithLinkedToolClass EquippedHands;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString DefaultTab;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString DefaultCategory;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	float DefaultIndexInCategory;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TSubclassOf<AGame_Tool> ToolClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TSubclassOf<UUserWidget> MenuClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TSubclassOf<UUserWidget> DropdownClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	bool bCollapseOnDisable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TMap<FString, int32> EnableConditions;

private:
	bool bSelected;

	UPROPERTY()
	UUserWidget* SpawnedDropdownMenu;

	UPROPERTY()
	UVR_MotionControllerComponent* LastClickedMotionController;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonButton(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_Game_RibbonButton
	// ---------------------------------
	
public:
	FString GetID_Implementation();

	bool GetDefaultTab_Implementation(FString& tab);

	bool GetDefaultCategory_Implementation(FString& category);

	bool GetDefaultIndexInCategory_Implementation(double& index);

	bool GetEnableConditions_Implementation(TMap<FString, int32>& conditions);

	bool GetCollapseOnDisable_Implementation();

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool Initialize() override;


	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintPure)
	bool ShouldShowDropdownButton() const;

	UFUNCTION(BlueprintCallable)
	virtual void ToggleDropdown(AGame_Tool* tool);

	UFUNCTION(BlueprintCallable)
	virtual void CloseDropdownMenu();

	UFUNCTION(BlueprintCallable)
	void Clicked();

	UFUNCTION(BlueprintCallable)
	void SetIcon(const FSlateBrush& iconArg);

	UFUNCTION(BlueprintCallable)
	void SetText(const FString& textArg);

	UFUNCTION(BlueprintCallable)
	void SetRibbonToolTip(const FString& toolTipArg);
	
	UFUNCTION(BlueprintPure)
	bool GetIsSelected() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetSelected(bool bSelectedArg);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetIcon(const FSlateBrush& iconArg);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetText(const FString& textArg);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetRibbonToolTip(const FString& textArg);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void PostClicked();

	virtual void PostSetSelected(bool bSelectedArg);

	virtual void PostInputStackTopChanged(AActor* tool);

	void SetSelected(bool bSelectedArg);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	virtual void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);

	UFUNCTION()
	virtual void HandleInputStackTopChanged(AActor* tool);

	UFUNCTION()
	void HandleUserWidgetClosed(UUserWidget* userWidget);
};