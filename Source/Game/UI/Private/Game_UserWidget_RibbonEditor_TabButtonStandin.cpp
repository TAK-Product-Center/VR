#include "Game_UserWidget_RibbonEditor_TabButtonStandin.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonEditor_TabButtonStandin::UGame_UserWidget_RibbonEditor_TabButtonStandin(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

void UGame_UserWidget_RibbonEditor_TabButtonStandin::HandleOnClick(UGame_UserWidget_RibbonEditor_TabButtonStandin* tabButton)
{
	OnClick.Broadcast(tabButton);
}
