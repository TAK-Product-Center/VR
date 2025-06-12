#pragma once

// Parent Includes
#include "Game_Point.h"

// Generated Includes
#include "Game_Point_Vehicle.generated.h"

class AGame_VehicleRepresentative;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Point_Vehicle : public AGame_Point
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UChildActorComponent* VehicleComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName COTType;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Point_Vehicle(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool GetRotationAxisList_Implementation(EAxisListBlueprint& axisList) override;

	virtual bool GetRotationDisabled_Implementation() override;

	virtual void SetActorHiddenInGame(bool bNewHidden) override;

	virtual void HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetActorRepresentative(TSubclassOf<AGame_VehicleRepresentative> vehicleClass);
};
