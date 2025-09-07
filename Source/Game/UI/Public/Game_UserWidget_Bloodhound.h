#pragma once

#include "Game_UserWidget_Arrow.h"
#include "Game_UserWidget_Bloodhound.generated.h"

UCLASS()
class GAME_API UGame_UserWidget_Bloodhound : public UGame_UserWidget_Arrow
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Members
	// ---------------------------------
private:
	float SecondsToIntercept;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------
public:
	void SetSecondsToIntercept(float secondsToIntercept);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSecondsToInterceptText(const FString& secondsToIntercept);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
    FString GetInterceptString() const;
};
