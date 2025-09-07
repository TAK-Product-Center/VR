// Required Includes
#include "Game_UserWidget_ContactsList.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeMathStatics.h"
#include "VH_COTEvent.h"
#include "VH_COTManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_ContactsList::UGame_UserWidget_ContactsList(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

TArray<UVH_COTEvent*> UGame_UserWidget_ContactsList::GetSortedContacts(EContactSortingMethod sortingMethod)
{
	TArray<UVH_COTEvent*> contacts;

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		cotManager->GetContacts().GenerateValueArray(contacts);

		switch (sortingMethod)
		{
			case EContactSortingMethod::Callsign:
				contacts.Sort([cotManager](UVH_COTEvent& a, UVH_COTEvent& b)
				{
					return a.GetAttribute(TEXT("callsign")) < b.GetAttribute(TEXT("callsign"));
				});
				break;

			case EContactSortingMethod::Proximity:
				contacts.Sort([cotManager](UVH_COTEvent& a, UVH_COTEvent& b)
				{
					FGeodeticCoord2D playerCoordinate = cotManager->GetGeodeticLocation().ToGeodeticCoord2D();

					FGeodeticCoord2D aCoordinate(a.GetAttribute<double>(TEXT("longitude")), a.GetAttribute<double>(TEXT("latitude")));
					FGeodeticCoord2D bCoordinate(a.GetAttribute<double>(TEXT("longitude")), a.GetAttribute<double>(TEXT("latitude")));

					return UVH_GlobeMathStatics::CalculateSurfaceDistance(playerCoordinate, bCoordinate) < UVH_GlobeMathStatics::CalculateSurfaceDistance(playerCoordinate, bCoordinate);
				});
				break;

			case EContactSortingMethod::UnreadMessage:
				contacts.Sort([cotManager](UVH_COTEvent& a, UVH_COTEvent& b)
				{
					return cotManager->GetNumberOfNewChats(FName(*a.GetAttribute(TEXT("uid")))) > UVH_COTManager::Get()->GetNumberOfNewChats(FName(*b.GetAttribute(TEXT("uid"))));
				});
				break;

			case EContactSortingMethod::OnlinePresence:
				contacts.Sort([](UVH_COTEvent& a, UVH_COTEvent& b)
				{
					return a.GetAttribute<FDateTime>(TEXT("time")) > b.GetAttribute<FDateTime>(TEXT("time"));
				});
				break;

			default:
				// Any undefined sorting type will not sort
				break;
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Game_UserWidget_ContactsList::PopulateContacts_Implementation() -- COTManager was nullptr"));
	}

	return contacts;
}
