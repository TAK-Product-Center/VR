#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

#include "Game_Database_Ribbon.h"

// Generated Includes
#include "Game_Subsystem_Ribbon.generated.h"

class UUserWidget;
class UGame_Subsystem_Ribbon_Settings;
class UGame_RibbonButtonRegistrar;

UCLASS()
class GAME_API UGame_Subsystem_Ribbon : public UWorldSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRibbonVisibilityChanged, bool, bVisible);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FRibbonVisibilityChanged OnRibbonVisibilityChanged;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> RibbonMenuClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_RibbonButtonRegistrar> ButtonRegistrarClass;

private:
	UPROPERTY()
	UGame_Database_Ribbon* RibbonDB;

	/* left-most has the lowest index */
	TMap<FString, double> TabIndices;
	/* Tab name, category name, category index */
	TMap<FString, TMap<FString, double>> CategoryIndices;
	TMap<FString, FRibbonButtonLocation> ButtonLocations;

	/* key is ID, value is buttonWidget */
	UPROPERTY()
	TMap<FString, UUserWidget*> RegisteredButtons;

	UPROPERTY()
	UUserWidget* RibbonUserWidget;

	UPROPERTY()
	AActor* RibbonWorldUIActor;

	UPROPERTY()
	UGame_RibbonButtonRegistrar* RibbonButtonRegistrar;

	UPROPERTY()
	TMap<FString, int32> EnableConditionValues;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Subsystem_Ribbon();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_Ribbon* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void RegisterButton(UUserWidget* buttonWidget);

	UFUNCTION(BlueprintCallable)
	void UnregisterButton(UUserWidget* buttonWidget);

	UFUNCTION(BlueprintCallable)
	void UnregisterButtonByID(const FString& id);

	UFUNCTION(BlueprintPure)
	UUserWidget* GetRibbonButtonByID(const FString& id) const;

	UFUNCTION(BlueprintCallable)
	void ShowRibbon();

	UFUNCTION(BlueprintCallable)
	void HideRibbon();

	UFUNCTION(BlueprintCallable)
	void ToggleRibbonVisibility();

	UFUNCTION(BlueprintPure)
	bool GetRibbonVisible() const;

	UFUNCTION(BlueprintCallable)
	void CloseAllDropdownMenus();

	UFUNCTION(BlueprintCallable)
	void SetButtonEnabledCondition(const FString& condition, const int32& newValue, bool bUpdateButtons = true);

	UFUNCTION(BlueprintCallable)
	void SyncToGameState();

	//Returns whether the button's state was changed, NOT the new state of the button
	UFUNCTION(BlueprintCallable)
	bool UpdateButtonEnabled(UUserWidget* button);

	UFUNCTION(BlueprintPure)
	bool GetTabIndex(const FString& tabName, double& index);

	UFUNCTION(BlueprintPure)
	bool GetCategoryIndex(const FString& tabName, const FString& categoryName, double& index);

	UFUNCTION(BlueprintPure)
	bool GetButtonLocationInfo(const FString& buttonID, FRibbonButtonLocation& buttonInfo);

	UFUNCTION(BlueprintCallable)
	void RegenerateRibbon();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void ApplySettings(const UGame_Subsystem_Ribbon_Settings* settings);

	void PopulateRibbon();

	void AddButton(UUserWidget* buttonWidget);

	void RemoveButton(UUserWidget* buttonWidget);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void BindToPlayerState();

	UFUNCTION()
	void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);

	UFUNCTION()
	void HandleIsInTOCUpdated(bool bIsInTOC);

	UFUNCTION()
	void HandleTutorialStageChanged(ETutorialStage newStage);
};