#pragma once

// Parent Includes
#include "Game_WorldInteractableActor.h"

// Generated Includes
#include "Game_TOCTableHandleActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_TOCTableHandleActor : public AGame_WorldInteractableActor
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_TOCTableHandleActor(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_Developer_Manipulation
	// ---------------------------------

public:
	virtual bool GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList) override;
};
