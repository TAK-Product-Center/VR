// Required Includes
#include "Game_Database_Operation.h"
#include "Game.h"

// Engine Includes
#include "Misc/Paths.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_EntityDB.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Database_Operation::UGame_Database_Operation()
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Database_Operation::Initialize()
{
	Connect();
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_Database_Operation::DuplicateOperation(int32 operationID)
{
	SpatialiteResult result = GetOperation(operationID);
	if (result.Num() > 0)
	{
		FString name = UDatabase_Spatialite::GetString(TEXT("name"), result);
		FString start = UDatabase_Spatialite::GetString(TEXT("start"), result);

		int32 duplicateOperationID = AddOperation(name, start);

		SpatialiteResults viewResults = GetViews(operationID);
		for (const SpatialiteResult& viewResult : viewResults)
		{
			int32 viewID = UDatabase_Spatialite::GetInteger(TEXT("id"), viewResult);
			FString viewName = UDatabase_Spatialite::GetString(TEXT("name"), viewResult);
			int32 orderIndex = UDatabase_Spatialite::GetInteger(TEXT("orderIndex"), viewResult);
			FString viewCoordinate = UDatabase_Spatialite::GetString(TEXT("cameraCoordinate"), viewResult);
			FString viewRotation = UDatabase_Spatialite::GetString(TEXT("cameraRotation"), viewResult);

			FGeodeticCoord3D coord3D;
			coord3D.FromString(viewCoordinate);

			FRotator rotation;
			rotation.InitFromString(viewRotation);

			int32 addedViewID = AddView(duplicateOperationID, viewName, orderIndex, coord3D, rotation);

			SpatialiteResults viewItems = GetViewItems(viewID, TEXT("category"), true);
			for (const SpatialiteResult& viewItem : viewItems)
			{
				FString uid = UDatabase_Spatialite::GetString(TEXT("uid"), viewItem);
				FString category = UDatabase_Spatialite::GetString(TEXT("category"), viewItem);
				bool bVisible = UDatabase_Spatialite::GetInteger(TEXT("visible"), viewItem) == 1;

				FString query = FString::Printf(TEXT("insert into viewItems (viewID, uid, category, visible) values (%d, \"%s\", \"%s\", %d)"), addedViewID, *uid, *category, bVisible ? 1 : 0);
				SyncQuery(query);
			}
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Database_Operation::DuplicateOperation | operation does not exist with ID: %d"), operationID);
	}
}

int32 UGame_Database_Operation::AddOperation(const FString& name, const FString& start)
{
	FString query = FString::Printf(TEXT("insert into operations (name, lastModified, start) values (\"%s\", \"%s\", \"%s\")"), *name, *GetNowDateTime(), *start);
	SyncQuery(query);

	SpatialiteResults results;
	SyncQuery(TEXT("select id from operations order by id desc limit 1"), results);

	return UDatabase_Spatialite::GetInteger(TEXT("id"), results[0]);
}

void UGame_Database_Operation::UpdateOperation(int32 operationID, const FString& name, const FString& start)
{
	FString query = FString::Printf(TEXT("update operations set name = \"%s\", lastModified = \"%s\", start = \"%s\" where id = %d"), *name, *GetNowDateTime(), *start, operationID);
	SyncQuery(query);
}

void UGame_Database_Operation::RemoveOperation(int32 operationID)
{
	SpatialiteResults viewResults = GetViews(operationID);
	for (const SpatialiteResult& viewResult : viewResults)
	{
		int32 viewID = UDatabase_Spatialite::GetInteger(TEXT("id"), viewResult);

		SyncQuery(FString::Printf(TEXT("delete from viewItems where viewID = %d"), viewID));
	}

	SyncQuery(FString::Printf(TEXT("delete from views where operationID = %d"), operationID));
			
	SyncQuery(FString::Printf(TEXT("delete from operations where id = %d"), operationID));
}

SpatialiteResults UGame_Database_Operation::GetOperations(const FString& orderBy, bool bAsc) const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from operations order by %s %s"), *orderBy, bAsc ? TEXT("asc") : TEXT("desc")), results);

	return results;
}

SpatialiteResult UGame_Database_Operation::GetOperation(int32 operationID) const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from operations where id = %d"), operationID), results);

	return results[0];
}

SpatialiteResult UGame_Database_Operation::GetView(int32 viewID) const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from views where id = %d"), viewID), results);

	return results[0];
}

SpatialiteResults UGame_Database_Operation::GetViews(int32 operationID) const
{
	return GetViews(operationID, TEXT("id"), true);
}

SpatialiteResults UGame_Database_Operation::GetViews(int32 operationID, const FString& orderBy, bool bAsc) const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from views where operationID = %d order by %s %s"), operationID, *orderBy, bAsc ? TEXT("asc") : TEXT("desc")), results);

	return results;
}

SpatialiteResults UGame_Database_Operation::GetViewItems(int32 viewID, const FString& orderBy, bool bAsc) const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from viewItems where viewID = %d order by %s %s"), viewID, *orderBy, bAsc ? TEXT("asc") : TEXT("desc")), results);

	return results;
}

SpatialiteResult UGame_Database_Operation::GetViewItem(int32 viewID, const FString& uid) const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select * from viewItems where viewID = %d and uid = \"%s\""), viewID, *uid), results);

	if (results.Num() == 1)
	{
		return results[0];
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Database_Operation::GetViewItem | 0 or more than 1 view item returned | %d | returning empty SpatialiteResult"), results.Num());
	return SpatialiteResult();
}

int32 UGame_Database_Operation::AddView(int32 operationID, const FString& name, int32 index, const FGeodeticCoord3D& cameraCoordinate, const FRotator& cameraRotation)
{
	FString query = FString::Printf(TEXT("insert into views (operationID, name, orderIndex, cameraCoordinate, cameraRotation) values (%d, \"%s\", %d, \"%s\", \"%s\")"), operationID, *name, index, *cameraCoordinate.ToString(), *cameraRotation.ToString());

	SyncQuery(query);

	UpdateLastModifiedFromOperationID(operationID);

	SpatialiteResults results;
	SyncQuery(TEXT("select id from views order by id desc limit 1"), results);

	return UDatabase_Spatialite::GetInteger(TEXT("id"), results[0]);
}

int32 UGame_Database_Operation::GetIndexForNewView(int32 operationID) const
{ 
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select orderIndex from views where operationID = %d order by orderIndex desc limit 1"), operationID), results);

	if (results.Num() > 0)
	{
		return UDatabase_Spatialite::GetInteger(TEXT("orderIndex"), results[0]) + 1;
	}

	return 0;
}

void UGame_Database_Operation::UpdateView(int32 viewID, const FString& name, int32 index)
{
	FString query = FString::Printf(TEXT("update views set name = \"%s\", orderIndex = %d where id = %d"), *name, index, viewID);

	SyncQuery(query);

	UpdateLastModifiedFromViewID(viewID);
}

void UGame_Database_Operation::UpdateViewCamera(int32 viewID, const FGeodeticCoord3D& cameraCoordinate, const FRotator& cameraRotation)
{
	FString query = FString::Printf(TEXT("update views set cameraCoordinate = \"%s\", cameraRotation = \"%s\" where id = %d"), *cameraCoordinate.ToString(), *cameraRotation.ToString(), viewID);

	SyncQuery(query);

	UpdateLastModifiedFromViewID(viewID);
}

void UGame_Database_Operation::RemoveView(int32 viewID)
{
	UpdateLastModifiedFromViewID(viewID);

	FString query = FString::Printf(TEXT("delete from views where id = %d"), viewID);

	SyncQuery(query);
}

void UGame_Database_Operation::AddViewItems(bool bRemoveExisting, int32 viewID, const TSet<FString>& uids)
{
	if (bRemoveExisting)
	{
		SyncQuery(FString::Printf(TEXT("delete from viewItems where viewID = %d"), viewID));
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		for (const FString& uid : uids)
		{
			SpatialiteResult result = entityDB->QueryUIDForResult(uid).Result;
			FString categoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), result);

			FSOverlayCategory category;
			entityDB->GetCategory(FName(*categoryID), category);

			FString categoryDisplayName = category.DisplayName;
			if (categoryDisplayName.EndsWith(TEXT("s")))
			{
				categoryDisplayName = categoryDisplayName.LeftChop(1);
			}

			FString query = FString::Printf(TEXT("insert into viewItems (viewID, uid, category, visible) values (%d, \"%s\", \"%s\", 1)"), viewID, *uid, *categoryDisplayName);
			SyncQuery(query);
		}
	}

	UpdateLastModifiedFromViewID(viewID);
}

void UGame_Database_Operation::UpdateViewItem(int32 viewID, const FString& uid, bool bVisible)
{
	FString query = FString::Printf(TEXT("update viewItems set visible = %d where viewID = %d and uid = \"%s\""), bVisible ? 1 : 0, viewID, *uid);
	SyncQuery(query);

	UpdateLastModifiedFromViewID(viewID);
}

void UGame_Database_Operation::RemoveViewItem(int32 viewID, const FString& uid)
{
	FString query = FString::Printf(TEXT("delete from viewItems where viewID = %d and uid = \"%s\""), viewID, *uid);
	
	SyncQuery(query);

	UpdateLastModifiedFromViewID(viewID);
}

bool UGame_Database_Operation::IsViewNameInUse(int32 operationID, int32 viewID, const FString& viewName) const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select id from views where operationID = %d and id != %d and name = \"%s\""), operationID, viewID, *viewName), results);

	return results.Num() > 0;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_Database_Operation::UpdateLastModifiedFromOperationID(int32 operationID)
{
	SyncQuery(FString::Printf(TEXT("update operations set lastModified = \"%s\" where id = %d"), *GetNowDateTime(), operationID));
}

void UGame_Database_Operation::UpdateLastModifiedFromViewID(int32 viewID)
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select operationID from views where id = %d"), viewID), results);

	UpdateLastModifiedFromOperationID(UDatabase_Spatialite::GetInteger(TEXT("operationID"), results[0]));
}

FString UGame_Database_Operation::GetNowDateTime() const
{
	return FDateTime::UtcNow().ToString(TEXT("%Y.%m.%d %H.%M.%S"));
}

void UGame_Database_Operation::Connect()
{
	if (OpenDatabase(GetFullPathToDatabase(), true))
	{
		// create tables if necessary
		FString query = TEXT("create table if not exists operations (id integer primary key, name text not null, lastModified text not null, start text not null)");
		SyncQuery(query);
		
		query = TEXT("create table if not exists views (id integer primary key, operationID integer not null, name text not null, orderIndex integer not null, cameraCoordinate text not null, cameraRotation text not null)");
		SyncQuery(query);
		
		query = TEXT("create table if not exists viewItems (id integer primary key, viewID integer not null, uid text not null, category text not null, visible integer not null)");
		SyncQuery(query);
	}
}

FString UGame_Database_Operation::GetFullPathToDatabase() const
{
	return FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("Databases"), TEXT("OperationDB.sqlite"));
}