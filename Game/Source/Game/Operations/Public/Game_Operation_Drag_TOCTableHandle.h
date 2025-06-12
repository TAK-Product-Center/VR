#pragma once

// Parent Includes
#include "Game_Operation_Drag.h"

// Generated Includes
#include "Game_Operation_Drag_TOCTableHandle.generated.h"

class AGame_Tool;

UCLASS()
class GAME_API UGame_Operation_Drag_TOCTableHandle : public UGame_Operation_Drag
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Operation_Drag_TOCTableHandle(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void StartDrag(AActor* actor, AGame_Tool* tool, double delaySeconds) override;

protected:
	virtual bool GetDragLocation(FVector& dragLocation) const override;
};