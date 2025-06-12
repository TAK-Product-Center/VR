#pragma once

// Parent Includes
#include "Keyboard_Subsystem_Core.h"

// Engine Includes
#include "Widgets/SWidget.h"

// Generated Includes
#include "Game_Subsystem_Keyboard.generated.h"

UCLASS()
class GAME_API UGame_Subsystem_Keyboard : public UKeyboard_Subsystem_Core
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TSet<FString> KeyboardWidgets;

	TSharedPtr<SWidget> NewFocusedWidget;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Subsystem_Keyboard();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* outer) const override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	UFUNCTION()
	void BindToFocusChange();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleFocusChanging(const FFocusEvent& focusEvent, const FWeakWidgetPath& oldFocusedWidgetPath, const TSharedPtr<SWidget>& OldFocusedWidget, const FWidgetPath& newFocusedWidgetPath, const TSharedPtr<SWidget>& newFocusedWidget);
};