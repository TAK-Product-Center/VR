#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Engine Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "UI_Subsystem_ContextMenu.generated.h"

class APlayerController;
class UUserWidget;
class UUI_Subsystem_ContextMenu_Settings;
class UObject;

USTRUCT(BlueprintType)
struct FContextOptionClasses
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UObject>> ContextOptionClasses;
};

UCLASS()
class VH_UI_API UUI_Subsystem_ContextMenu : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UObject>, FContextOptionClasses> AdditionalContextOptionsPerClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> DefaultContextMenuClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> ContextMenuCollisionChannel;

	/// @brief Context menu classes that should only allow one instance at a time
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UUserWidget>> UniqueContextMenuClasses;

	/// @brief Context menu options that should not show in any context menu
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UObject>> DisabledContextOptionClasses;

private:
	TMap<UObject*, UUserWidget*> SourceToContextMenu;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UUI_Subsystem_ContextMenu();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UUI_Subsystem_ContextMenu* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Convenience function to set class variables
	* \param settings Settings object to use to set class variables
	*/
	UFUNCTION(BlueprintCallable)
	void UpdateSettings(TSubclassOf<UUI_Subsystem_ContextMenu_Settings> settingsClass);

	/* \brief Opens context menu using default options based on source and contextMenuClass; calls RegisterContextMenu
	*  \note closes any existing context menus for source that are registered with this subsystem 
	*  \param instigator Actor that caused the context menu to open
	*  \param source Object that was clicked on (if any) to generate the generate this option
	*/
	UFUNCTION(BlueprintCallable)
	UUserWidget* OpenContextMenuWithDefaults(AActor* instigator, UObject* source);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	bool GetContextOptions(AActor* instigator, UObject* source, TSet<UObject*>& contextOptions) const;

	UFUNCTION(BlueprintPure)
	UUserWidget* GetContextMenuFromSource(UObject* source) const;

	UFUNCTION(BlueprintCallable)
	UObject* GetSourceFromContextMenu(UUserWidget* contextMenu) const;

	/* \brief Registers context menu for source with this subsystem. 
	*/
	UFUNCTION(BlueprintCallable)
	void RegisterContextMenu(UUserWidget* contextMenu, UObject* source);

	/* \brief Closes all context menus that have a source of a particular class
	*  \param sourceClass Class to search for when determining which context menus to close
	*/
	UFUNCTION(BlueprintCallable)
	void CloseContextMenusForClass(TSubclassOf<UObject> sourceClass);

	/* \brief Closes all context menus of a particular class
	*  \param sourceClass Class to search for when determining which context menus to close
	*/
	UFUNCTION(BlueprintCallable)
	void CloseContextMenusOfClass(TSubclassOf<UObject> contextMenuClass);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateSettings(const UUI_Subsystem_ContextMenu_Settings* settings);

	void BindToCore();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleUserWidgetClosed(UUserWidget* userWidget);
};