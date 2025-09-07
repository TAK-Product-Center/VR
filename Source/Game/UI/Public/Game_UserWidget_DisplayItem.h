// Developed by Virtual Heroes, 2019-2020

#pragma once

// Engine includes
#include "Blueprint/UserWidget.h"

// Generated include
#include "Game_UserWidget_DisplayItem.generated.h"

// Forward declarations
class UTextBlock;

/**
 * 
 */
UCLASS()
class GAME_API UGame_UserWidget_DisplayItem : public UUserWidget
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Member
	// ---------------------------------

public:

	UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "Text Entries", meta = (ExposeOnSpawn = "true"))
	FString Title;

	UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "Text Entries", meta = (ExposeOnSpawn = "true"))
	FString Text;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Text Blocks|Public", meta = (BindWidget))
	UTextBlock* TitleTextBlock;

	UPROPERTY(BlueprintReadOnly, Category = "Text Blocks|Public", meta = (BindWidget))
	UTextBlock* TextTextBlock;

	// ---------------------------------
	// --- Inherited Methods
	// ---------------------------------

protected:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------

public:

	UFUNCTION(BlueprintCallable, Category = "Utilities|Public")
	virtual void SetTitle(const FString& titleString);

	UFUNCTION(BlueprintCallable, Category = "Utilities|Public")
	virtual void SetText(const FString& textString);

	// ---------------------------------
	// --- Implementation Methods
	// ---------------------------------

protected:

	virtual void ValidateDisplayItem() const;
};
