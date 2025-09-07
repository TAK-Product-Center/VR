// Developed by Virtual Heroes, 2019-2020

#pragma once

// Engine includes
#include "Blueprint/UserWidget.h"

// Generated include
#include "Game_UserWidget_Point.generated.h"

/**
 * 
 */
UCLASS(meta = (DisableNativeTick))
class GAME_API UGame_UserWidget_Point : public UUserWidget
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Member variables
	// ---------------------------------

protected:

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, meta = (BindWidget))
	class UTextBlock* CallsignText;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:

	UFUNCTION(BlueprintCallable, Category = "Utilities|Public")
	void SetCallsignText(const FString& newCallsign);

};
