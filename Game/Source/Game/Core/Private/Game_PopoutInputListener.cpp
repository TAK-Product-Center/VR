#include "Game_PopoutInputListener.h"
#include "Game_TOCBoard.h"


// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_PopoutInputListener::AGame_PopoutInputListener()
{
	Listeners = TArray<AGame_TOCBoard*>();
}
	
	
// ---------------------------------
// --- Inherited
// ---------------------------------

bool AGame_PopoutInputListener::HandleKeyDownEvent(FSlateApplication& slateApp, const FKeyEvent& inKeyEvent)
{
	for(AGame_TOCBoard* board : Listeners)
	{
		board->HandleKeyDownEvent(inKeyEvent);
	}
	return false;
}


// ---------------------------------
// --- API
// ---------------------------------

void AGame_PopoutInputListener::RegisterListener(AGame_TOCBoard* board)
{
	Listeners.Add(board);
}

void AGame_PopoutInputListener::UnregisterListener(AGame_TOCBoard* board)
{
	Listeners.Remove(board);
}
