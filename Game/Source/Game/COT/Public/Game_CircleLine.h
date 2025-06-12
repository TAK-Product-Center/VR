#pragma once

#include "Game_SimpleSegmentedLineActor.h"
#include "Game_CircleLine.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_CircleLine : public AGame_SimpleSegmentedLineActor
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
	
public:
	AGame_CircleLine(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- Delegates
	// ---------------------------------

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEditPointsUpdated);

	UPROPERTY(BlueprintAssignable)
	FOnEditPointsUpdated OnEditPointsUpdated;
	

	// ---------------------------------
	// --- Variables
	// ---------------------------------
	
private:
	float MajorRadiusInMeters;
	float MinorRadiusInMeters;


	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:

	virtual void GenerateMesh() override;

	UFUNCTION(BlueprintCallable)
	void SetMajorRadius(float InMajorRadius);

	UFUNCTION(BlueprintCallable)
	void SetMinorRadius(float InMinorRadius);
	
	UFUNCTION(BlueprintPure)
	float GetMajorRadius() const { return MajorRadiusInMeters; }

	UFUNCTION(BlueprintPure)
	float GetMinorRadius() const { return MinorRadiusInMeters; };

	UFUNCTION(BlueprintCallable)
	FVector GetSouthmostLocation() const;
};