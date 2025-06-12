// Required Includes
#include "Game_ListView.h"
#include "Game.h"

// Game Includes
#include "Interface_ListItemObject.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

UUserWidget& UGame_ListView::OnGenerateEntryWidgetInternal(UObject* item, TSubclassOf<UUserWidget> desiredEntryClass, const TSharedRef<STableViewBase>& ownerTable)
{
	if (item->GetClass()->ImplementsInterface(UInterface_ListItemObject::StaticClass()))
	{
		FString id = IInterface_ListItemObject::Execute_GetID(item);

		if (TSubclassOf<UUserWidget>* classPtr = IDToWidgetClass.Find(id))
		{
			return Super::OnGenerateEntryWidgetInternal(item, *classPtr, ownerTable);
		}
	}

	return Super::OnGenerateEntryWidgetInternal(item, desiredEntryClass, ownerTable);
}