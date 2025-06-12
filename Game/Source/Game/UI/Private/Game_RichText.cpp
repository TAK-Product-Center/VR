// Developed by Virtual Heroes, 2019-2020


#include "Game_RichText.h"
#include "Widgets/Text/SRichTextBlock.h"

void UGame_RichText::SetWrapTextAt(float InWrapTextAt)
{
	WrapTextAt = InWrapTextAt;
	if (MyRichTextBlock.IsValid())
	{
		MyRichTextBlock->SetWrapTextAt(InWrapTextAt);
	}
}
