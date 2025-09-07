#include "Game_UserWidget_RibbonEditor_ButtonStandin.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonEditor_ButtonStandin::UGame_UserWidget_RibbonEditor_ButtonStandin(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}


// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_RibbonEditor_ButtonStandin::SetIcon(const FSlateBrush& icon)
{
	Icon = icon;

	ReceiveSetIcon(Icon);

	OnSetIcon.Broadcast(Icon);
}