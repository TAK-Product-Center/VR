#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_UserWidget_GoTo.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_GoTo : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 NumberOfRecentCoordinates;

private:
	TArray<FGeodeticCoord3D> RecentCoordinates;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_GoTo(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	
public:
	virtual void NativeConstruct() override;
	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveRecentCoordinates(const TArray<FGeodeticCoord3D>& coordinates);

	UFUNCTION(BlueprintCallable)
	void AddRecentCoordinate(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintCallable)
	void ClearRecentCoordinates();
};