// Required includes
#include "Game_UserWidget_Point.h"
#include "Game.h"

// Engine includes
#include "Components/TextBlock.h"

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_Point::SetCallsignText(const FString& newCallsign)
{
	if (CallsignText != nullptr)
	{
		CallsignText->SetText(FText::FromString(newCallsign));
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Missing text widget named 'CallsignText' | callsign=%s | class=%s"), *newCallsign, *GetClass()->GetName());
	}
}
