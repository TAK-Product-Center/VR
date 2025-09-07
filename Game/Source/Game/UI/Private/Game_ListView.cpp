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
			if ((*classPtr) != nullptr)
			{
				return Super::OnGenerateEntryWidgetInternal(item, *classPtr, ownerTable);
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_ListView::OnGenerateEntryWidgetInternal | found id: %s, but class is nullptr | object: %s | calling Super"), *id, *item->GetName());
			}
		}
	}

	return Super::OnGenerateEntryWidgetInternal(item, desiredEntryClass, ownerTable);
}