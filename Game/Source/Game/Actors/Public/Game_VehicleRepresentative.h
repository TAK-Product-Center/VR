#pragma once

// Parent Includes
#include "Game_Point_Vehicle.h"

// Generated Includes
#include "Game_VehicleRepresentative.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_VehicleRepresentative : public AGame_WorldActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/// @brief displayed to user
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FString FriendlyName;

	/// @brief send in COT
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FString ModelName;

	/// @brief send in COT
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FString ModelCategory;

	/// @brief displayed to user
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName DropperCategory;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_VehicleRepresentative(const FObjectInitializer& objectInitializer);
};
