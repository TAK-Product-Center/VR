#pragma once

// Parent Includes
#include "Game_UserWidget_DetailSection_EditPoints.h"

// Generated Includes
#include "Game_UserWidget_DetailSection_RoutePoints.generated.h"

UCLASS()
class GAME_API UGame_UserWidget_DetailSection_RoutePoints : public UGame_UserWidget_DetailSection_EditPoints
{
	GENERATED_BODY()


	//--------------------------
	//--- API
	//--------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRoutePoints(const TArray<FGeodeticCoord3D>& geoLocations,const TArray<FString>& callsigns, const TArray<FString>& navCues, const TArray<bool>& checkpointIndicators);

	UFUNCTION(BlueprintCallable)
	void UpdateNavCue(int32 index, const FString& newNavCue);

	UFUNCTION(BlueprintCallable)
	void PromotePoint(int32 index);

	UFUNCTION(BlueprintCallable)
	void DemotePoint(int32 index);

	UFUNCTION(BlueprintCallable)
	void UpdateCallsign(int32 index, const FString& newCallsign);

	UFUNCTION(BlueprintCallable)
	void UpdateEntity();


	//--------------------------
	//--- Implementation
	//--------------------------

protected:
	void virtual PopulateEditPoints() override;

private:
	void PopulateRouteEditPoints();
};