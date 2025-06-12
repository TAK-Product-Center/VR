#pragma once

// Parent Includes
#include "Game_ContextMenuOption.h"


// Generated Includees
#include "Game_ContextMenuOption_Delete.generated.h"

class APlayerController;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_ContextMenuOption_Delete : public UGame_ContextMenuOption
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_ContextMenuOption_Delete(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void PostExecute() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	bool GetEntityInfo(FString& entityID, FString& classUID) const;
};