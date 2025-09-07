#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_ExportOperation.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_ExportOperation : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_ExportOperation(const FObjectInitializer& objectInitializer);
};