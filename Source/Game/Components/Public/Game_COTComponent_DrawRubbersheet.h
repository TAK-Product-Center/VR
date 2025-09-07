#pragma once

#include "Game_COTComponent_DrawRectangle.h"
#include "Game_COTComponent_DrawRubbersheet.generated.h"

class AGame_EditPoint_Center;
class UGame_AdjustableModelImportComponent;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawRubbersheet : public UGame_COTComponent_DrawRectangle
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_COTComponent_DrawRubbersheet();


	// ---------------------------------
	// --- Variables
	// ---------------------------------
private:
	/* The actor to transform when the rectangle changes. */
	UPROPERTY()
	AActor* WatchActor;

	UPROPERTY()
	UGame_AdjustableModelImportComponent* ImportComponent;

	/* The EntityUID to watch */
	FString WatchEntityUID;

	/* The initial distance between the centers of edge 0 - 1 and edge 2 - 3. Used to compare against inherited WidthInMeters to determine model scale. */
	double InitialWidthInMeters;

	/* The initial distance between the centers of edge 1 - 2 and edge 3 - 0. Used to compare against inherited LengthInMeters to determine model scale. */
	double InitialLengthInMeters;

	FVector InitialScale;
	
	/* height difference between actor and center edit point */
	float HeightDiffUU;
	FVector CenterEditPointLocationCache;


	// ---------------------------------
	// --- Inherited 
	// ---------------------------------
public:
	/*
	 *	Reinforces a rectangle shape based on an edit point the user has selected
	 *  by updating adjacent points' locations. Keeps signed length and with information unlike the base rectangle's.
	 *	@param inManipulatedPoint - The point that was moved
	 */
	virtual void UpdateRectangleShape(AGame_EditPoint* inManipulatedPoint) override;

	virtual void PostManipulationEnd(AActor* manipulatedActor) override;

	virtual AGame_VirtualObjective* GetVirtualObjective() const override;

	virtual AVH_GlobeReferenceActor* GetGlobeReference() const override;

	/*
	 *	Modifies the watched actor according to how the rubbersheet was modified.
	 *	@param inManipulatedPoint - The point that was moved
	 */
	virtual void UpdateRectangleRotation(AGame_EditPoint_RectangleRotator* inManipulatedPoint);

	/* rubbersheet rectangle not stored in database; overridden to store rubbersheet data in Watch entity's data */
	virtual void RegisterWithDatabase(AGame_VirtualObjective* virtualObjective = nullptr) override;


	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	/*
	 *	Sets the entityUID of the entity to watch and sets the rubbersheet's dimensions accordingly.
	 *	@param inWatchEntityUID - The entityUID of the entity to apply rubbersheet.
	 */
	UFUNCTION(BlueprintCallable)
	void SetWatchEntityUID(const FString& inWatchEntityUID);

	UFUNCTION(BlueprintPure)
	UGame_AdjustableModelImportComponent* GetImportComponent() const;

	UFUNCTION(BlueprintCallable)
	void UpdateRectangle();
	

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	FVector ComputeScale();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	UFUNCTION()
	void HandleWatchActorDestroyed(AActor* destroyedActor);
};