// Required Includes
#include "Game_EntityDB.h"
#include "Game.h"

// Engine Includes
#include "Async/Async.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Database_Spatialite.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_COTManager.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_MUCComponent_Database.h"
#include "Game_HandlerService.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityDB::UGame_EntityDB() :
    DatabaseFilename(TEXT("EntityDB.sqlite")),
    PrimaryTableName(TEXT("entities"))
{
    PrimaryTableFields.Empty();
    PrimaryTableFields.Add(TEXT("id"), TEXT("integer not null primary key autoincrement"));
    PrimaryTableFields.Add(TEXT("entityUID"), TEXT("string not null"));
    PrimaryTableFields.Add(TEXT("classUID"), TEXT("string not null"));
    PrimaryTableFields.Add(TEXT("categoryID"), TEXT("string not null"));
    PrimaryTableFields.Add(TEXT("data"), TEXT("blob"));
    PrimaryTableFields.Add(TEXT("transient"), TEXT("integer not null"));
    PrimaryTableFields.Add(TEXT("visible"), TEXT("integer not null"));
	PrimaryTableFields.Add(TEXT("dataVersion"), TEXT("string"));

    PrimaryTableAdditionalInitQueries.Empty();
    PrimaryTableAdditionalInitQueries.Add(FString::Printf(TEXT("select AddGeometryColumn('%s', 'northWestBB', 4326, 'POINT', 'XY', 0)"), *PrimaryTableName));
    PrimaryTableAdditionalInitQueries.Add(FString::Printf(TEXT("select AddGeometryColumn('%s', 'southEastBB', 4326, 'POINT', 'XY', 0)"), *PrimaryTableName));
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_EntityDB* UGame_EntityDB::Get()
{
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		return subsystem->EntityDB;
	}

	return nullptr;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_EntityDB::OnGameModeInit()
{
	SetDatabaseFilename(TEXT("EntityDB.sqlite"));

	UpdateConnection();
}

void UGame_EntityDB::OnGameModeStartToLeaveMap()
{
	SyncQuery(FString::Printf(TEXT("delete from %s where transient = 1"), *PrimaryTableName));
}

bool UGame_EntityDB::Delete(const FString& classUID, const FString& entityUID, bool bBroadcast)
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from %s where entityUID = \"%s\" and classUID = \"%s\""), *PrimaryTableName, *entityUID, *classUID), results);

	if (results.Num() > 0)
	{
		// TODO: Display error/warning if more than 1 row found! No duplicates!

		for (const SpatialiteResult& result : results)
		{
			DeleteFromResult(result);
		}

		if (bBroadcast)
		{
			BroadcastEvent(&OnDelete, results);
		}

		return true;
	}

	return false;
}

void UGame_EntityDB::DeleteResults(const SpatialiteResults& results)
{
	for (const SpatialiteResult& result : results)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		Delete(classUID, entityUID);
	}
}

void UGame_EntityDB::DeleteFromResult(const SpatialiteResult& result)
{
	if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
	{
		voManager->DeleteEntityGlobal(result);
	}

	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

	SyncQuery(FString::Printf(TEXT("delete from %s where entityUID = \"%s\" and classUID = \"%s\""), *PrimaryTableName, *entityUID, *classUID));
}

void UGame_EntityDB::Clear()
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from %s"), *PrimaryTableName), results);

	if (UGame_Statics::IsLocalPlayerInSession())
	{
		for (const SpatialiteResult& result : results)
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

			UGame_MUCComponent_Database::MUCDelete(FName(*entityUID), true);
		}
	}
	else
	{
		// call handlers to unload objects
		for (const SpatialiteResult& result : results)
		{
			DeleteFromResult(result);
		}

		BroadcastEvent(&OnDelete, results);
	}

	SyncQuery(FString::Printf(TEXT("delete from %s"), *PrimaryTableName));
}

void UGame_EntityDB::GetEntityOverlayInfo(TMap<FString, FString>& keyValues, const FSpatialiteResult_BP& result)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		handlerService->GetEntityOverlayInfo(result, keyValues);
	}
}

bool UGame_EntityDB::IsCategoryOrChildOf(const FName& categoryID, const FName& otherCategoryID) const
{
	FName testCategoryID = categoryID;
	while (testCategoryID != NAME_None)
	{
		if (!OverlayCategories.Contains(testCategoryID))
		{
			//UE_LOG(Game, Warning, TEXT("-- UGame_EntityDB::IsCategoryOrChildOf | invalid category: '%s'"), *testCategoryID.ToString());
			break;
		}

		if (testCategoryID.Compare(otherCategoryID) == 0)
		{
			return true;
		}
		else
		{
			FSOverlayCategory testCategory;
			if (GetCategory(testCategoryID, testCategory))
			{
				testCategoryID = testCategory.ParentID;
			}
		}
	}

	return false;
}

void UGame_EntityDB::AddCategory(const FSOverlayCategory& categoryToAdd)
{
	const FName id(categoryToAdd.ID);

	if (OverlayCategories.Contains(id))
	{
		OverlayCategories[id].ID = categoryToAdd.ID;
		OverlayCategories[id].ParentID = categoryToAdd.ParentID;
		OverlayCategories[id].DisplayName = categoryToAdd.DisplayName;
		OverlayCategories[id].Icon = categoryToAdd.Icon;
		OverlayCategories[id].Item_ListItemClass = categoryToAdd.Item_ListItemClass;
		OverlayCategories[id].Category_ListItemClass = categoryToAdd.Category_ListItemClass;
	}
	else
	{
		FSOverlayCategory category;
		category.ID = categoryToAdd.ID;
		category.ParentID = categoryToAdd.ParentID;
		category.DisplayName = categoryToAdd.DisplayName;
		category.Icon = categoryToAdd.Icon;
		category.Item_ListItemClass = categoryToAdd.Item_ListItemClass;
		category.Category_ListItemClass = categoryToAdd.Category_ListItemClass;

		OverlayCategories.Add(category.ID, category);
	}
}

bool UGame_EntityDB::GetCategory(const FName& id, FSOverlayCategory& category) const
{
	if (OverlayCategories.Contains(id))
	{
		category = OverlayCategories[id];
		return true;
	}

	return false;
}

TSet<FName> UGame_EntityDB::GetLeafCategoryIDs() const
{
	TSet<FName> ids;

	for (const TPair<FName, FSOverlayCategory>& entry : OverlayCategories)
	{
		if (GetSubcategories(entry.Key).Num() == 0)
		{
			ids.Add(entry.Key);
		}
	}

	return ids;
}

TArray<FSOverlayCategory> UGame_EntityDB::GetSubcategories(const FName& parentID) const
{
	// TODO: Consider returning TArray<FName> instead, since the caller can just use the categoryID's to get to the data. This would avoid copying the structs into an array.
	TArray<FSOverlayCategory> subCategories;

	for (const TPair<FName, FSOverlayCategory>& entry : OverlayCategories)
	{
		if (entry.Value.ParentID.Compare(parentID) == 0)
		{
			subCategories.Add(entry.Value);
		}
	}

	return subCategories;
}

FSpatialiteResults_BP UGame_EntityDB::GetCategoryEntities(const FName& id)
{
	FSOverlayCategory category;
	if (UGame_EntityDB::Get()->GetCategory(id, category))
	{
		if (category.ParentID.IsEqual("team"))
		{
			return GetContactCategoryEntities(id);
		}
	}

	FString query = FString::Printf(TEXT("select * from %s where categoryID = \"%s\" collate nocase"), *PrimaryTableName, *id.ToString());

	SpatialiteResults results;
	SyncQuery(query, results);

	if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
	{
		cotManager->DeleteStaleEntitiesFromResults(results);
	}

	return FSpatialiteResults_BP(results);
}

FSpatialiteResults_BP UGame_EntityDB::GetContactCategoryEntities(const FName& id)
{
	SpatialiteResults categoryResults;

	UVH_COTManager* cotManager = UVH_COTManager::Get();
	if (cotManager == nullptr)
	{
		return FSpatialiteResults_BP(categoryResults);
	}

	FString query = FString::Printf(TEXT("select * from %s where categoryID = \"contact\""), *PrimaryTableName);

	SpatialiteResults queryResults;
	SyncQuery(query, queryResults);

	for (SpatialiteResult result : queryResults)
	{
		TMap<FString, FString> keyValues;
		GetEntityOverlayInfo(keyValues, result);

		bool bAdd = false;
		if (FString* groupName = keyValues.Find(FString("groupName")))
		{
			if (id.IsEqual(TEXT("team_members")))
			{
				bAdd = true;
			}

			if (cotManager->GetGroupColors().Contains(id))
			{
				bAdd = true;
			}
		}
		else if (FString* groupRole = keyValues.Find(FString("groupRole")))
		{
			if (cotManager->GroupRoles.Find(id.ToString()))
			{
				bAdd = true;
			}
		}

		if (bAdd)
		{
			categoryResults.Add(result);
		}
	}

	return FSpatialiteResults_BP(categoryResults);
}

/* \brief Gets visibility state of category
*  \param id ID of category to query
*  \returns category visibility enum value
*/
EOverlayCategoryVisibility UGame_EntityDB::GetCategoryVisibility(const FName& id)
{
	int32 numVisible = 0;
	int32 numHidden = 0;
	return GetCategoryVisiblity_Helper(id, numVisible, numHidden);
}

void UGame_EntityDB::SetCategoryVisibility(const FName& id, bool bVisible)
{
	// set category visibility and all enitities in category (recursively include subcategories)
	if (OverlayCategories.Contains(id))
	{
		SetEntityVisibilityByCategory(id, bVisible);

		// apply to subcategories recursively
		TArray<FSOverlayCategory> subCategories = GetSubcategories(id);
		for (FSOverlayCategory category : subCategories)
		{
			SetCategoryVisibility(category.ID, bVisible);
		}
	}
}

void UGame_EntityDB::SetEntityVisibility(const FString& entityUID, bool bVisible)
{
	FString query = FString::Printf(TEXT("update %s set visible = %d where entityUID = \"%s\""), *PrimaryTableName, bVisible ? 1 : 0, *entityUID);
	SyncQuery(query);

	query = FString::Printf(TEXT("select * from %s where entityUID = \"%s\""), *PrimaryTableName, *entityUID);
	SpatialiteResults results;
	SyncQuery(query, results);

	if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
	{
		for (const SpatialiteResult& result : results)
		{
			voManager->SetEntityVisibilityGlobal(result, bVisible);
		}
	}

	BroadcastEvent(&OnInsertOrUpdate, results);
}

bool UGame_EntityDB::GetEntityVisibility(const FName& entityUID) const
{
	SpatialiteResults results = QueryUID(entityUID.ToString());

	for (const SpatialiteResult& result : results)
	{
		return UDatabase_Spatialite::GetBool(TEXT("visible"), result);
	}

	return false;
}

void UGame_EntityDB::UpdateBoundingBox(const FString& entityUID, const FGeodeticCoord2D& northWestBB, const FGeodeticCoord2D& southEastBB)
{
	FString query = FString::Printf(TEXT("update %s set northWestBB = ?, southEastBB = ? where entityUID = \"%s\""), *PrimaryTableName, *entityUID);

	if (sqlite3_stmt* statement = PrepareStatement(query))
	{
		BindPoint(statement, northWestBB.ToArray(), 1);
		BindPoint(statement, southEastBB.ToArray(), 2);

		SyncQuery(statement);

		// purposefully not claling BroadcastEvent; caused issues with MUC
	}
}

void UGame_EntityDB::SetData(const FString& entityUID, const TArray<uint8>& data)
{
	FString query = FString::Printf(TEXT("update %s set data = ? where entityUID = \"%s\""), *PrimaryTableName, *entityUID);

	if (sqlite3_stmt* statement = PrepareStatement(query))
	{
		BindBlob(statement, data, 1);

		SyncQuery(statement);

		query = FString::Printf(TEXT("select * from %s where entityUID = \"%s\""), *PrimaryTableName, *entityUID);

		SpatialiteResults results;
		SyncQuery(query, results);

		BroadcastEvent(&OnInsertOrUpdate, results);
	}
}

void UGame_EntityDB::InsertOrUpdate(const FString& entityUID, const FString& classUID, const FName& categoryID, const FGeodeticCoord2D& northWestBB, const FGeodeticCoord2D& southEastBB, const TArray<uint8>& data, bool bTransient, bool bVisible) const
{
	FString query = FString::Printf(TEXT("replace into %s (id, entityUID, classUID, categoryID, transient, visible, northWestBB, southEastBB, data)"), *PrimaryTableName);
	query += FString::Printf(TEXT(" values ((select id from %s where entityUID = \"%s\")"), *PrimaryTableName, *entityUID);
	query += FString::Printf(TEXT(", \"%s\""), *entityUID);
	query += FString::Printf(TEXT(", \"%s\""), *classUID);
	query += FString::Printf(TEXT(", \"%s\""), *categoryID.ToString());
	query += FString::Printf(TEXT(", %d"), bTransient ? 1 : 0);
	query += FString::Printf(TEXT(", %d"), bVisible ? 1 : 0);
	query += FString::Printf(TEXT(", ?, ?, ?)"));

	if (sqlite3_stmt* statement = PrepareStatement(query))
	{
		BindPoint(statement, northWestBB.ToArray(), 1);
		BindPoint(statement, southEastBB.ToArray(), 2);
		BindBlob(statement, data, 3);

		SyncQuery(statement);

		query = FString::Printf(TEXT("select * from %s where entityUID = \"%s\""), *PrimaryTableName, *entityUID);

		SpatialiteResults results;
		SyncQuery(query, results);

		BroadcastEvent(&OnInsertOrUpdate, results);
	}
}

void UGame_EntityDB::InsertOrUpdateResult(const SpatialiteResult& result)
{
	SpatialiteResults results;
	results.Add(result);

	InsertOrUpdateResults(results);
}

void UGame_EntityDB::InsertOrUpdateResults(const SpatialiteResults& results)
{
	for (const SpatialiteResult& result : results)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);
		FString categoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), result);
		TArray<uint8> data = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
		bool bTransient = UDatabase_Spatialite::GetBool(TEXT("transient"), result);
		bool bVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), result);
		FString dataVersion = UDatabase_Spatialite::GetString(TEXT("dataVersion"), result);
		TArray<double> northWestBB = UDatabase_Spatialite::GetPoint(TEXT("northWestBB"), result);
		TArray<double> southEastBB = UDatabase_Spatialite::GetPoint(TEXT("southEastBB"), result);

		FString query = FString::Printf(TEXT("replace into %s (id, entityUID, classUID, categoryID, transient, visible, dataVersion, northWestBB, southEastBB, data)"), *PrimaryTableName);
		query += FString::Printf(TEXT(" values ((select id from %s where entityUID = \"%s\")"), *PrimaryTableName, *entityUID);
		query += FString::Printf(TEXT(", \"%s\""), *entityUID);
		query += FString::Printf(TEXT(", \"%s\""), *classUID);
		query += FString::Printf(TEXT(", \"%s\""), *categoryID);
		query += FString::Printf(TEXT(", %d"), bTransient ? 1 : 0);
		query += FString::Printf(TEXT(", %d"), bVisible ? 1 : 0);
		query += FString::Printf(TEXT(", \"%s\""), *dataVersion);
		query += FString::Printf(TEXT(", ?, ?, ?)"));

		if (sqlite3_stmt* statement = PrepareStatement(query))
		{
			BindPoint(statement, northWestBB, 1);
			BindPoint(statement, southEastBB, 2);
			BindBlob(statement, data, 3);

			SyncQuery(statement);
		}
	}

	BroadcastEvent(&OnInsertOrUpdate, results);
}

bool UGame_EntityDB::LoadEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UObject* handler /*= nullptr*/, int32 detailLevel /* = 1*/)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		SpatialiteResults results = QueryUID(entityUID);
		if (results.Num() > 0)
		{
			LoadEntity(virtualObjective, results[0], handler, detailLevel);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_EntityDB::LoadEntity | no results for entityUID: %s"), *entityUID);
		}

		return true;
	}

	return false;
}

bool UGame_EntityDB::LoadEntity(AGame_VirtualObjective* virtualObjective, const SpatialiteResult& result, UObject* handler /*= nullptr*/, int32 detailLevel /* = 1*/)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		handlerService->SetEntityDetailStatus(virtualObjective, result, detailLevel);

		bool bVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), result);
		handlerService->SetEntityVisibility(virtualObjective, result, bVisible);

		handlerService->SetEntityScale3D(virtualObjective, result, virtualObjective->GetActorScale3D());

		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		OnPageIn.Broadcast(entityUID, virtualObjective);

		return true;
	}

	return false;
}

bool UGame_EntityDB::UnloadEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UObject* handler)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		SpatialiteResults results = QueryUID(entityUID);
		if (results.Num() > 0)
		{
			handlerService->SetEntityDetailStatus(virtualObjective, results[0], 0);

			OnPageOut.Broadcast(entityUID, virtualObjective);

			return true;
		}
		
		UE_LOG(Game, Warning, TEXT("-- UGame_EntityDB::UnloadEntity | no results for entityUID: %s"), *entityUID);
	}

	return false;
}

SpatialiteResults UGame_EntityDB::QuerySquare2D(const FGeodeticCoord2D& center, double halfWidthMeters) const
{
	SpatialiteResults results;

	if (halfWidthMeters < 0)
	{
		return results;
	}

	FString query = FString::Printf(TEXT("select * from %s where %s"), *PrimaryTableName, *MatchInsideSquareForQuery(center, halfWidthMeters));
	SyncQuery(query, results);

	/*for (const SpatialiteResult& result : results)
	{
		int32 rowID = UDatabase_Spatialite::GetInteger(TEXT("id"), result);
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);
		TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

		UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("  rowID=%d, entityUID=%s, classUID=%s, blob=\"%s\""), rowID, *entityUID, *classUID, *BytesToString(blob.GetData(), blob.Num())), false, false, true, false, ELogMessageColor::Cyan);
	}*/

	return results;
}

FSpatialiteResult_BP UGame_EntityDB::QueryUIDForResult(const FString& entityUID) const
{
	FSpatialiteResult_BP result_BP;

	SpatialiteResults results = QueryUID(entityUID);
	if (results.Num() > 0)
	{
		result_BP.Result = results[0];
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_EntityDB::QueryUIDForResult | no results for entityUID: %s"), *entityUID);
	}

	return result_BP;
}

void UGame_EntityDB::QueryUID(const FString& entityUID, FString& classUID, FString& categoryID, TArray<uint8>& blobData, bool& bTransient, bool& bVisible, FString& dataVersion) const
{
	SpatialiteResults results = QueryUID(entityUID);

	if (results.Num() > 0)
	{
		classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), results[0]);
		categoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), results[0]);
		blobData.Append(UDatabase_Spatialite::GetBlob(TEXT("data"), results[0]));
		bTransient = UDatabase_Spatialite::GetBool(TEXT("transient"), results[0]);
		bVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), results[0]);
		dataVersion = UDatabase_Spatialite::GetString(TEXT("dataVersion"), results[0]);
	}
}

SpatialiteResults UGame_EntityDB::QueryUID(const FString& entityUID) const
{
	FString query = FString::Printf(TEXT("select * from %s where entityUID = \"%s\" "), *PrimaryTableName, *entityUID);

	SpatialiteResults results;
	SyncQuery(query, results);

	return results;
}

SpatialiteResults UGame_EntityDB::QueryCategory(const FString& categoryID) const
{
	FString query = FString::Printf(TEXT("select * from %s where categoryID = \"%s\" "), *PrimaryTableName, *categoryID);

	SpatialiteResults results;
	SyncQuery(query, results);

	return results;
}

bool UGame_EntityDB::IsEntityInDB(const FString& entityUID) const
{
	return !QueryUID(entityUID).IsEmpty();
}

FString UGame_EntityDB::GetDatabasePath() const
{
	if (DatabasePath.IsEmpty())
	{
		return FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("Databases"));
	}

	return DatabasePath;
}

FString UGame_EntityDB::GetDatabaseFilename() const
{
	return DatabaseFilename;
}

void UGame_EntityDB::SetDatabasePath(const FString& databasePath)
{
	DatabasePath = databasePath;
}

void UGame_EntityDB::SetDatabaseFilename(const FString& databaseFilename)
{
	if (!databaseFilename.Equals(DatabaseFilename, ESearchCase::IgnoreCase))
	{
		if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
		{
			voManager->PageOutEntitiesGlobal();

			bConnected = false;
			DatabaseFilename = databaseFilename;

			UpdateConnection();

			voManager->TriggerUpdateGlobal();
		}
	}
}

SpatialiteResults UGame_EntityDB::QueryAllEntities() const
{
	SpatialiteResults results;

	FString query = FString::Printf(TEXT("select * from %s"), *PrimaryTableName);
	SyncQuery(query, results);

	return results;
}

FSpatialiteResults_BP UGame_EntityDB::K2_QueryAllEntities() const
{
	FSpatialiteResults_BP results(QueryAllEntities());

	return results;
}

void UGame_EntityDB::SetEntityDataVersion(const FString& entityUID, const FString& dataVersion) const
{
	FString query = FString::Printf(TEXT("update %s set dataVersion = \"%s\" where entityUID = \"%s\""), *PrimaryTableName, *dataVersion, *entityUID);
	SyncQuery(query);

	query = FString::Printf(TEXT("select * from %s where entityUID = \"%s\""), *PrimaryTableName, *entityUID);

	SpatialiteResults results;
	SyncQuery(query, results);

	BroadcastEvent(&OnInsertOrUpdate, results);
}

void UGame_EntityDB::SetEntityTransient(const FString& entityUID, bool bTransient)
{
	FString query = FString::Printf(TEXT("update %s set transient = %d where entityUID = \"%s\""), *PrimaryTableName, bTransient ? 1 : 0, *entityUID);
	SyncQuery(query);
	
	query = FString::Printf(TEXT("select * from %s where entityUID = \"%s\""), *PrimaryTableName, *entityUID);

	SpatialiteResults results;
	SyncQuery(query, results);

	BroadcastEvent(&OnInsertOrUpdate, results);
}

SpatialiteResults UGame_EntityDB::QueryClassUID(const FString& classUID) const
{
	FString query = FString::Printf(TEXT("select * from %s where classUID = \"%s\""), *PrimaryTableName, *classUID);

	SpatialiteResults results;
	SyncQuery(query, results);

	return results;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_EntityDB::UpdateConnection()
{
	if (!bConnected)
	{
		Connect();
		bConnected = true;
	}

	SyncQuery(FString::Printf(TEXT("delete from %s where transient = 1"), *PrimaryTableName));
}

void UGame_EntityDB::Connect()
{
	if (OpenDatabase(FPaths::Combine(GetDatabasePath(), GetDatabaseFilename()), true))
	{
		// create primary table if necessary
		FString query;

		// Build array of formatted fields
		TArray<FString> fields;
		for (const TPair<FString, FString>& field : PrimaryTableFields)
		{
			fields.Add(FString::Printf(TEXT("%s %s"), *field.Key, *field.Value));
		}

		query = FString::Printf(TEXT("create table if not exists %s("), *PrimaryTableName);
		query += FString::Join(fields, TEXT(", "));
		query += TEXT(")");
		SyncQuery(query);

		// Run additional initialization queries
		for (const FString& initQuery : PrimaryTableAdditionalInitQueries)
		{
			SyncQuery(initQuery);
		}
	}
}

void UGame_EntityDB::BroadcastEvent(const FDBEvent* eventDelegate, SpatialiteResults results) const
{
	if (eventDelegate != nullptr && results.Num() > 0)
	{
		if (IsInGameThread())
		{
			FSpatialiteResults_BP results_BP(results);
			eventDelegate->Broadcast(results_BP);
		}
		else
		{
			AsyncTask(ENamedThreads::GameThread, [eventDelegate, results]()
			{
				FSpatialiteResults_BP results_BP(results);
				eventDelegate->Broadcast(results_BP);
			});
		}
	}
}

void UGame_EntityDB::SetEntityVisibilityByCategory(const FName& categoryID, bool bVisible)
{
	// sets visibility of all entities that have categoryID
	FString query = FString::Printf(TEXT("update %s set visible = %d where categoryID = \"%s\" collate nocase"), *PrimaryTableName, bVisible ? 1 : 0, *categoryID.ToString());
	SyncQuery(query);

	// broadcast potentially updated rows
	query = FString::Printf(TEXT("select * from %s where categoryID = \"%s\" collate nocase"), *PrimaryTableName, *categoryID.ToString());

	SpatialiteResults results;
	SyncQuery(query, results);

	if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
	{
		for (const SpatialiteResult& result : results)
		{
			voManager->SetEntityVisibilityGlobal(result, bVisible);
		}
	}

	BroadcastEvent(&OnInsertOrUpdate, results);
}

EOverlayCategoryVisibility UGame_EntityDB::GetCategoryVisiblity_Helper(const FName& id, int32& numVisible, int32& numHidden)
{
	// check visibility of entities in this category
	FSpatialiteResults_BP results = GetCategoryEntities(id);
	for (FSpatialiteResult_BP result_BP : results.Results)
	{
		SpatialiteResult result = result_BP.Result;
		bool bVisible = UDatabase_Spatialite::GetBool("visible", result);

		numVisible += bVisible ? 1 : 0;
		numHidden += bVisible ? 0 : 1;

		if (numVisible > 0 && numHidden > 0)
		{
			return EOverlayCategoryVisibility::Mixed;
		}
	}

	// check visibility of entities in subcategories
	TArray<FSOverlayCategory> subCategories = GetSubcategories(id);
	for (const FSOverlayCategory& category : subCategories)
	{
		GetCategoryVisiblity_Helper(category.ID, numVisible, numHidden);

		if (numVisible > 0 && numHidden > 0)
		{
			return EOverlayCategoryVisibility::Mixed;
		}
	}

	if (numVisible == 0 && numHidden == 0)
	{
		return EOverlayCategoryVisibility::Empty;
	}
	
	return (numVisible > 0) ? EOverlayCategoryVisibility::Visible : EOverlayCategoryVisibility::Hidden;
}

FString UGame_EntityDB::MatchInsideSquareForQuery(const FGeodeticCoord2D& center, double halfWidthMeters) const
{
	FString SRID = TEXT("4326");

	double distanceBetweenDegreesMeters = FMath::Cos(FMath::DegreesToRadians(center.Latitude)) * 111321;
	double radiusDegrees = halfWidthMeters / distanceBetweenDegreesMeters;

	FString circleMbr = FString::Printf(TEXT("BuildCircleMbr(%.8Lf, %.8Lf, %.8Lf, %s)"), center.Longitude, center.Latitude, radiusDegrees, *SRID);
	FString buildMbr = FString::Printf(TEXT("BuildMbr(x(northWestBB), y(northWestBB), x(southEastBB), y(southEastBB), %s)"), *SRID);

	FString overlaps = FString::Printf(TEXT("MbrOverlaps(%s, %s)"), *circleMbr, *buildMbr);
	FString intersects = FString::Printf(TEXT("MbrIntersects(%s, %s)"), *circleMbr, *buildMbr);
	FString contains = FString::Printf(TEXT("MbrContains(%s, %s)"), *circleMbr, *buildMbr);

	return FString::Printf(TEXT("(%s) or (%s) or (%s)"), *overlaps, *intersects, *contains);
}

void UGame_EntityDB::RebuildDatabaseTable() const
{
	// NOTE: Because Sqlite doesn't allow altering tables after creation -- e.g. to change the dataVersion field's type. 
	//		 So then we must create a new table (and copy the values) instead...

	// TODO: Consider change this process to instead backup/rename the original table, and then build the new table and copy values from the backup!
	// TODO: Also, if changed to a single "transaction", then it shouldn't have issues if the sqlite database is accessed between rebuild queries.

	FString tempTableName = PrimaryTableName + TEXT("_temp");
	FString dataVersionFieldName = TEXT("dataVersion");

	// Ensure temp table doesn't exist
	FString query = FString::Printf(TEXT("drop table %s"), *tempTableName);
	SyncQuery(query);

	// Build array of formatted fields (excluding the version field)
	TArray<FString> fields;
	for (const TPair<FString, FString>& field : PrimaryTableFields)
	{
		if (!field.Key.Equals(dataVersionFieldName, ESearchCase::IgnoreCase))
		{
			fields.Add(FString::Printf(TEXT("%s %s"), *field.Key, *field.Value));
		}
	}

	// Create the new (temp) table
	query = FString::Printf(TEXT("create table %s("), *tempTableName);
	query += FString::Join(fields, TEXT(", "));
	query += TEXT(")");
	SyncQuery(query);

	for (const FString& initQuery : PrimaryTableAdditionalInitQueries)
	{
		query = initQuery.Replace(*PrimaryTableName, *tempTableName, ESearchCase::IgnoreCase);
		SyncQuery(query);
	}

	// Append version field. NOTE: Required to be at the end for the table copy to work correctly, since it's at the end in the original (v.6) table!
	query = FString::Printf(TEXT("alter table '%s' add %s %s"), *tempTableName, *dataVersionFieldName, *PrimaryTableFields[dataVersionFieldName]);
	SyncQuery(query);

	// Copy data into temp table
	query = FString::Printf(TEXT("insert into '%s' select * from '%s'"), *tempTableName, *PrimaryTableName);
	SyncQuery(query);

	// Replace the original table with the temp table
	query = FString::Printf(TEXT("drop table %s"), *PrimaryTableName);
	SyncQuery(query);

	query = FString::Printf(TEXT("alter table '%s' rename to '%s'"), *tempTableName, *PrimaryTableName);
	SyncQuery(query);
}
