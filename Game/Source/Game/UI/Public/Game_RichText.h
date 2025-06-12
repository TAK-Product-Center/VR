// Developed by Virtual Heroes, 2019-2020

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlock.h"
#include "Game_RichText.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UGame_RichText : public URichTextBlock
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Appearance")
	void SetWrapTextAt(float InWrapTextAt);
	
};
