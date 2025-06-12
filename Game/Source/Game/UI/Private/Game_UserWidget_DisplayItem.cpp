// Developed by Virtual Heroes, 2019-2020

// Required includes
#include "Game_UserWidget_DisplayItem.h"

// Engine includes
#include "Components/TextBlock.h"

// ---------------------------------
// --- Inherited Methods
// ---------------------------------

void UGame_UserWidget_DisplayItem::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (IsDesignTime())
	{
		ValidateDisplayItem();
	}
}

void UGame_UserWidget_DisplayItem::NativeConstruct()
{
	Super::NativeConstruct();

	ValidateDisplayItem();
}

// ---------------------------------
// --- Public Methods
// ---------------------------------

void UGame_UserWidget_DisplayItem::SetTitle(const FString& titleString)
{
	Title = titleString;

	if (ensure(TitleTextBlock))
	{
		TitleTextBlock->SetText(FText::FromString(Title));
	}
}

void UGame_UserWidget_DisplayItem::SetText(const FString& textString)
{
	Text = textString;

	if (ensure(TextTextBlock))
	{
		TextTextBlock->SetText(FText::FromString(Text));
	}
}

// ---------------------------------
// --- Implementation Methods
// ---------------------------------

void UGame_UserWidget_DisplayItem::ValidateDisplayItem() const
{
	if (ensure(TitleTextBlock))
	{
		TitleTextBlock->SetText(FText::FromString(Title));
	}

	if (ensure(TextTextBlock))
	{
		TextTextBlock->SetText(FText::FromString(Text));
	}
}