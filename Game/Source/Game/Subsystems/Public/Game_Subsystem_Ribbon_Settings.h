#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Engine Includes
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Game_Subsystem_Ribbon_Settings.generated.h"

class UUserWidget;
class UGame_RibbonButtonRegistrar;


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FTabCategoryOrder 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, double> CategoryIndices;

	FTabCategoryOrder() { }
};

UCLASS(BlueprintType, Blueprintable, Config = Game)
class GAME_API UGame_Subsystem_Ribbon_Settings : public UDeveloperSettings
{
	GENERATED_BODY()


	// --------------------
	// --- Variables
	// --------------------

public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> RibbonMenuClass;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_RibbonButtonRegistrar> ButtonRegistrarClass;

	/* left-most tab has the lowest index */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<FString, double> TabIndices;

	/* left-most category in each tab has the lowest index */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<FString, FTabCategoryOrder> CategoryIndices;
};
