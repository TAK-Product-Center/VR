#include "Game_UserWidget_Bloodhound.h"

// ---------------------------------
// --- Public Methods
// ---------------------------------

void UGame_UserWidget_Bloodhound::SetSecondsToIntercept(float secondsToIntercept)
{
	if (SecondsToIntercept != secondsToIntercept)
	{
		SecondsToIntercept = secondsToIntercept;

		UpdateSecondsToInterceptText(GetInterceptString());
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

FString UGame_UserWidget_Bloodhound::GetInterceptString() const
{
    FTimespan time = FTimespan::FromSeconds(SecondsToIntercept);

    FNumberFormattingOptions NumberFormatOptions;
    NumberFormatOptions.AlwaysSign = false;
    NumberFormatOptions.UseGrouping = true;
    NumberFormatOptions.RoundingMode = ERoundingMode::HalfToEven;
    NumberFormatOptions.MinimumIntegralDigits = 2;
    NumberFormatOptions.MaximumIntegralDigits = 324;
    NumberFormatOptions.MinimumFractionalDigits = 0;
    NumberFormatOptions.MaximumFractionalDigits = 2;

    FString seconds = FText::AsNumber(time.GetSeconds(), &NumberFormatOptions).ToString();
    FString minutes = FText::AsNumber(time.GetMinutes(), &NumberFormatOptions).ToString();
    FString hours = FText::AsNumber(time.GetHours(), &NumberFormatOptions).ToString();

    return FString::Printf(TEXT("%s:%s:%s"), *hours, *minutes, *seconds);
}