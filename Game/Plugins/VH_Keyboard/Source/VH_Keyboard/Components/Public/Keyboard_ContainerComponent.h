#pragma once

// Parent Includes
#include "Components/ActorComponent.h"

// Engine Includes
#include "Widgets/SWidget.h"
#include "Templates/SharedPointer.h"

// Module Includes
#include "KeyData.h"

// Generated Includes
#include "Keyboard_ContainerComponent.generated.h"

class UWidget;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_KEYBOARD_API UKeyboard_ContainerComponent : public UActorComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCommit, const FString&, entry);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnKeyPressed, const FKeyData&, keyData, const FString&, keyString);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShiftModified, bool, bShiftActive);

	DECLARE_DYNAMIC_DELEGATE_RetVal(FString, FRequestCommitString);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnCommit OnCommit;

	UPROPERTY(BlueprintAssignable)
	FOnKeyPressed OnKeyPressed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnShiftModified OnShiftModified;

	/* send keyboard presses to this widget; nullptr is ignored */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWidget* WidgetToSendPress;

	TSharedPtr<SWidget> SWidgetToSendPress;

	/* key that toggles shift; defaults to Caps Lock */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FKey ShiftToggleKey;

	/* key string that closes keyboard; empty string is ignored */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CloseKeyString;

	/* key string that commits; empty string is ignored */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CommitKeyString;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FRequestCommitString RequestCommitString;

	/* seconds that must pass between presses */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double CooldownSeconds;
	

private:
	bool bShiftActive;

	double LastPressed;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UKeyboard_ContainerComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static FString GetKeyString(const FKeyData& keyData, bool bIsShiftActive);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void KeyPressed(const FKeyData& keyData);

	bool CanPress();
};
