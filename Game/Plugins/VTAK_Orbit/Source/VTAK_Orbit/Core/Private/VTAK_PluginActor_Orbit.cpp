// Required Includes
#include "VTAK_PluginActor_Orbit.h"

// VH Plugin Includes
#include "VH_COTManager.h"
#include "Developer_Subsystem_Core.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_ListEntry_Overlay_Gen.h"

// Module Includes
#include "VTAK_Actor_Orbit.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AVTAK_PluginActor_Orbit::AVTAK_PluginActor_Orbit() :
	ControllerID(TEXT("Orbit")),
	OverlayCategoryIcon(nullptr),
	ID(TEXT("orbit")),
	Type(TEXT("u-d-o"))
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AVTAK_PluginActor_Orbit::PostHandleCOTMessageReceived(const FString& messageType)
{
	if (messageType.Equals(TEXT("COTManagerInitialized")))
	{
		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			FSOverlayCategory orbitCategory;
			orbitCategory.ID = ID;
			orbitCategory.DisplayName = TEXT("Orbit Plugin");
			orbitCategory.Icon = OverlayCategoryIcon;
			orbitCategory.Item_ListItemClass = ItemListItemClass;
			orbitCategory.Category_ListItemClass = CategoryListItemClass;

			entityDB->AddCategory(orbitCategory);
		}

		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			cotManager->OverlayCategories.Add(Type, ID);

			FCOTTypeData typeData;
			typeData.ActorClass = OrbitActorClass;

			cotManager->TypeToData.Add(Type, typeData);
		}
	}
}