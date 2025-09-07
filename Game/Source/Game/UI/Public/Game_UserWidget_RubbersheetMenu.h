#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_RubbersheetMenu.generated.h"

class UGame_AdjustableModelImportComponent;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_UserWidget_RubbersheetMenu : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void ExportToFile(const FString& filename, const FString& entityUID, UGame_AdjustableModelImportComponent* importComponent);
};