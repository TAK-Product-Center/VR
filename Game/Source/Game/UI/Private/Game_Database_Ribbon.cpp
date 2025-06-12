// Required Includes
#include "Game_Database_Ribbon.h"
#include "Game.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_COTManager.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Database_Ribbon::UGame_Database_Ribbon()
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_Database_Ribbon::Connect()
{
	if (OpenDatabase(GetFullPathToDatabase(), true))
	{
		// create tables if necessary
		FString query = TEXT("create table if not exists tabOrder (name TEXT not null primary key, ");
		query += TEXT("tabIndex REAL not null)");
		
		SyncQuery(query);

		query = TEXT("create table if not exists categoryOrder (tab TEXT not null, ");
		query += TEXT("name TEXT not null, ");
		query += TEXT("catIndex REAL not null)");

		SyncQuery(query);

		query = TEXT("create table if not exists buttonOrder (buttonID TEXT not null primary key, ");
		query += TEXT("tab TEXT not null, ");
		query += TEXT("category TEXT not null, ");
		query += TEXT("buttonIndex REAL not null)");

		SyncQuery(query);
	}
}

FString UGame_Database_Ribbon::GetFullPathToDatabase() const
{
	return FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("Databases"), TEXT("RibbonDB.sqlite"));
}

void UGame_Database_Ribbon::LoadLayout(TMap<FString, double>& tabs, TMap<FString, TMap<FString, double>>& categories, TMap<FString, FRibbonButtonLocation>& buttons)
{
	FString query = FString::Printf(TEXT("select * from tabOrder"));
	
	SpatialiteResults results;
	SyncQuery(query, results);

	for (const SpatialiteResult& tabResult : results)
	{
		tabs.Add(UDatabase_Spatialite::GetString(TEXT("name"), tabResult), UDatabase_Spatialite::GetDouble(TEXT("tabIndex"), tabResult));
	}

	query = FString::Printf(TEXT("select * from categoryOrder"));
	results.Empty();

	SyncQuery(query, results);

	for (const SpatialiteResult& categoryResult : results)
	{
		FString tabName = UDatabase_Spatialite::GetString(TEXT("tab"), categoryResult);
		TMap<FString, double>* category = categories.Find(tabName);

		if (category == nullptr)
		{
			category = &categories.Add(tabName, TMap<FString, double>());
		}

		category->Add(UDatabase_Spatialite::GetString(TEXT("name"), categoryResult), UDatabase_Spatialite::GetDouble(TEXT("catIndex"), categoryResult));
	}

	query = FString::Printf(TEXT("select * from buttonOrder"));
	results.Empty();

	SyncQuery(query, results);

	for (const SpatialiteResult& buttonResult : results)
	{
		buttons.Add(
			UDatabase_Spatialite::GetString(TEXT("buttonID"), buttonResult),
			FRibbonButtonLocation(
				UDatabase_Spatialite::GetString(TEXT("tab"), buttonResult),
				UDatabase_Spatialite::GetString(TEXT("category"), buttonResult),
				UDatabase_Spatialite::GetDouble(TEXT("buttonIndex"), buttonResult)
			)
		);
	}
}

void UGame_Database_Ribbon::SaveLayout(const TMap<FString, double>& tabs, const TMap<FString, TMap<FString, double>>& categories, const TMap<FString, FRibbonButtonLocation>& buttons)
{
	SyncQuery(TEXT("BEGIN TRANSACTION"));

	FString query = FString::Printf(TEXT("delete from tabOrder"));
	SyncQuery(query);
	query = FString::Printf(TEXT("delete from categoryOrder"));
	SyncQuery(query);
	query = FString::Printf(TEXT("delete from buttonOrder"));
	SyncQuery(query);

	for (const TPair<FString, double>& tabData : tabs)
	{
		query = TEXT("insert into tabOrder (name, tabIndex) values (");
		query += FString::Printf(TEXT("\"%s\", "), *tabData.Key);
		query += FString::Printf(TEXT("%f)"), tabData.Value);

		SyncQuery(query);
	}

	for (const TPair<FString, TMap<FString, double>>& fullData : categories)
	{
		for (const TPair<FString, double>& categoryData : tabs)
		{
			query = TEXT("insert into categoryOrder (tab, name, catIndex) values (");
			query += FString::Printf(TEXT("\"%s\", "), *fullData.Key);
			query += FString::Printf(TEXT("\"%s\", "), *categoryData.Key);
			query += FString::Printf(TEXT("%f)"), categoryData.Value);

			SyncQuery(query);
		}
	}

	for (const TPair<FString, FRibbonButtonLocation>& tabData : buttons)
	{
		query = TEXT("insert into tabOrder (buttonID, tab, category, buttonIndex) values (");
		query += FString::Printf(TEXT("\"%s\", "), *tabData.Key);
		query += FString::Printf(TEXT("\"%s\", "), *tabData.Value.Tab);
		query += FString::Printf(TEXT("\"%s\", "), *tabData.Value.Category);
		query += FString::Printf(TEXT("%f)"), tabData.Value.Index);

		SyncQuery(query);
	}

	SyncQuery(TEXT("COMMIT"));
}