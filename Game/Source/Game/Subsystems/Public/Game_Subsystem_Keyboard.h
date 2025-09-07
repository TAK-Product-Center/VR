#pragma once

// Parent Includes
#include "Keyboard_Subsystem_Core.h"

// Engine Includes
#include "Widgets/SWidget.h"

// Generated Includes
#include "Game_Subsystem_Keyboard.generated.h"

class UGame_Subsystem_Keyboard_Settings;

UCLASS()
class GAME_API UGame_Subsystem_Keyboard : public UKeyboard_Subsystem_Core
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, TSubclassOf<AActor>> KeyboardClassMap;

private:
	TSet<FString> KeyboardWidgets;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Subsystem_Keyboard();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_Keyboard* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* outer) const override;

	virtual UClass* GetKeyboardClass() const override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	UFUNCTION()
	void BindToFocusChange();

	void UpdateSettings(const UGame_Subsystem_Keyboard_Settings* settings);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleFocusChanging(const FFocusEvent& focusEvent, const FWeakWidgetPath& oldFocusedWidgetPath, const TSharedPtr<SWidget>& OldFocusedWidget, const FWidgetPath& newFocusedWidgetPath, const TSharedPtr<SWidget>& newFocusedWidget);
};