#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Game Includes
#include "Game_EntityDB.h"

// Generated Includes
#include "Game_UserWidget_DetailSection_EditPoints.generated.h"

class UUserWidget;
class UVH_COTEvent;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_UserWidget_DetailSection_EditPoints : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FString EntityUID;

protected:
	UPROPERTY()
	UVH_COTEvent* COTEvent;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void NativeConstruct() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetEntityUID(const FString& entityUID);

	UFUNCTION(BlueprintCallable)
	void UpdateCOTEvent();

	UFUNCTION(BlueprintCallable)
	void SetEditPointLocation(int32 index, FGeodeticCoord3D geoLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateEditPoints(const TArray<FGeodeticCoord3D>& geoLocations);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void PopulateEditPoints();

private:
	void PopulateRectangleEditPoints();

	void PopulatePolylineEditPoints();

	void PopulateRouteEditPoints();

	void PopulateRangeBearingEditPoints();

	void SetRectangleLocation(int32 index, const FGeodeticCoord3D& geoLocation);

	void SetPolylineLocation(int32 index, const FGeodeticCoord3D& geoLocation);

	void SetRouteLocation(int32 index, const FGeodeticCoord3D& geoLocation);

	void SetRangeBearingLocation(int32 index, const FGeodeticCoord3D& coordinate);

	void UpdateEntity();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleDatabaseInsertUpdate(const FSpatialiteResults_BP& results);
};
