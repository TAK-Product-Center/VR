#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated include
#include "Game_TOCTable.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_TOCTable : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_TOCTable(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	FBox2D ReceiveGetBoundsForTeleport() const;
};