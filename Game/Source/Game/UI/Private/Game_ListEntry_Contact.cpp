#include "Game_ListEntry_Contact.h"

#include "VH_UmgListEntry.h"
#include "VH_COTEvent.h"

#include "Game.h"

UGame_ListEntry_Contact::UGame_ListEntry_Contact()
{

}

UVH_COTEvent* UGame_ListEntry_Contact::GetCOTEvent() const
{
	return COTEvent;
}

FName UGame_ListEntry_Contact::GetContactUID() const
{
	if (COTEvent != nullptr)
	{
		return FName(*COTEvent->GetAttribute(TEXT("uid")));
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_ListEntry_Contact::GetContactUID | cotEvent is nullptr"));

	return FName();
}

void UGame_ListEntry_Contact::SetCOTEvent(UVH_COTEvent* cotEvent)
{
	COTEvent = cotEvent;

	ReceiveSetCOTEvent(cotEvent);
}
