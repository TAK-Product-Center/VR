#pragma once

#include "Game_UserWidget_StringInput.h"

UGame_UserWidget_StringInput::UGame_UserWidget_StringInput(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	
}

void UGame_UserWidget_StringInput::Submit()
{
	FString latestString;
	bool latestStringValid;
	GetLatestString(latestString, latestStringValid);
	if (latestStringValid)
	{
		OnStringSubmitted.Broadcast(latestString);
	}
}
