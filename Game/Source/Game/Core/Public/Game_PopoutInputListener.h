#pragma once

#include "Game_TOCBoard.h"
#include "Framework/Application/IInputProcessor.h"

class AGame_TOCBoard;

class AGame_PopoutInputListener : public IInputProcessor
{
	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TArray<AGame_TOCBoard*> Listeners;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_PopoutInputListener();
	
	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	
public:
	virtual void Tick(const float deltaTime, FSlateApplication& slateApp, TSharedRef<ICursor> cursor) override {};
	virtual bool HandleKeyDownEvent( FSlateApplication& slateApp, const FKeyEvent& inKeyEvent ) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void RegisterListener(AGame_TOCBoard* board);
	void UnregisterListener(AGame_TOCBoard* board);
};
