#pragma once

// Parent Includes
#include "Database_Spatialite.h"

// Generated Includes
#include "Game_Database_Ribbon.generated.h"


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FRibbonButtonLocation
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Tab;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Category;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double Index;

	FRibbonButtonLocation()
	{
		Tab = TEXT("");
		Category = TEXT("");
		Index = 0;
	}

	FRibbonButtonLocation(const FString& tab, const FString& category, double index)
	{
		Tab = tab;
		Category = category;
		Index = index;
	}
};

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_Database_Ribbon : public UDatabase_Spatialite
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Database_Ribbon();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void Connect();

	FString GetFullPathToDatabase() const;

	void LoadLayout(TMap<FString, double>& tabs, TMap<FString, TMap<FString, double>>& categories, TMap<FString, FRibbonButtonLocation>& buttons);

	void SaveLayout(const TMap<FString, double>& tabs, const TMap<FString, TMap<FString, double>>& categories, const TMap<FString, FRibbonButtonLocation>& buttons);
};
