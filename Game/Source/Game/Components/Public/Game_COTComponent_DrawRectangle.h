#pragma once

// Parent Includes
#include "Game_COTComponent_Draw.h"

// Game Includes
#include "Game_EditPoint_Center.h"

// Generated Includes
#include "Game_COTComponent_DrawRectangle.generated.h"

struct FGeodeticCoord3D;
class UVH_COTEvent;
class AGame_Actor_Mesh;
class AGame_EditPoint_RectangleRotator;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawRectangle : public UGame_COTComponent_Draw
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_EditPoint_Center> CenterEditPointClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_EditPoint_RectangleRotator> RotatorEditPointClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Actor_Mesh> CuboidFillActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* CuboidFillMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CuboidHeightMeters;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8 MeshStyleAlpha;

protected:
	UPROPERTY()
	AGame_EditPoint_Center* CenterEditPoint;

	UPROPERTY()
	TArray<AGame_EditPoint_RectangleRotator*> RotatorEditPoints;
	
	const static int32 PointsInShape{ 4 };

	/* The set of triangle meshes that represent height x sides. */
	UPROPERTY()
	TArray<AGame_Actor_Mesh*> CuboidMeshes;

	/* Color for mesh only */
	FColor MeshStyleColor;

	/* VH-specific stored width. The distance between the centers of edge 0 - 1 and edge 2 - 3. */
	double WidthInMeters;

	/* VH-specific stored length. The distance between the centers of edge 1-2 and edge 3-0. */
	double LengthInMeters;

	/* VH-specific stored rotation. Ranges from 0 up to but not including 360. Defined as the bearing between the center point, and the center of edge 0-1. */
	double RotationInDegrees;

	/* When we drag a rectangle point, fix the opposite corner if true. Otherwise, fix the center point and mirror all corners around it. */
	bool bFixOppositeWhileResizing;

	/* When we rotate a rectangle edge, fix the center if true. Otherwise, fix the opposite edge. */
	bool bFixCenterWhileRotating;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_DrawRectangle();	


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void SnapToGround() override;

	virtual bool ShouldSnapEditPoint(AGame_EditPoint* editPoint) const override;

	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void PopulateCOT_Virtual() override;

	virtual TArray<FVector> PreModifyVOGlobeReference() override;

	virtual void PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions) override;
	
	virtual void HandleOwnerSetScale3D(const FVector& scale3D) override;

	virtual void SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive) override;

	virtual void HandleOwnerSetHidden(bool bNewHidden) override;

	virtual void PostManipulationEnd(AActor* manipulatedActor);

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	 *	Spawns center edit point and 5 edit points and line for rectangle, in that order.
	 *	@param centerLocation - location of center edit point
	 */
	UFUNCTION(BlueprintCallable)
	void SpawnDrawElements(const FVector& centerLocation, const FLinearColor& inColor);

	/*
	 * Spawns an edit point used in rotation, but not in line definition.
	 * @param location - The world location of the edit point.
	 * @param existingEditPoint - The edit point, should it already exist.
	 */
	UFUNCTION(BlueprintCallable)
	AGame_EditPoint_RectangleRotator* SpawnRotatorEditPoint(const FVector& location, AGame_EditPoint_RectangleRotator* existingEditPoint);
	
	/*
	 * Gets the center edit point
	 * @return The center edit point.
	 */
	UFUNCTION(BlueprintPure)
	AGame_EditPoint_Center* GetCenterEditPoint() const;

	/*
	 *	Reinforces a rectangle shape based on an edit point the user has selected
	 *  by updating adjacent points' locations.
	 *	@param manipulatedIndex - index of the edit point that was moved.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void UpdateRectangleShape(AGame_EditPoint* manipulatedPoint);

	/*
	 * Preserves a rectangle shape while rotating it around a pivot point.
	 * @param manipulatedPoint - The rotator edit point that was moved.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void UpdateRectangleRotation(AGame_EditPoint_RectangleRotator* manipulatedPoint);

	/* Calculates and returns rectangle length and width in meters from COTEvent.
	 * @param cotEvent - COTEvent for entity
	 * @return lengthMeters
	 * @return widthMeters
	 * @return rotationDegrees
	 */
	UFUNCTION(BlueprintCallable)
	static void CalculateRectangleLengthWidthRotation(UVH_COTEvent* cotEvent, float& lengthMeters, float& widthMeters, float& rotationDegrees);

	UFUNCTION(BlueprintPure)
	AGame_Actor_Mesh* GetCuboidMesh(int32 index) const;

	UFUNCTION(BlueprintCallable)
	void UpdateCuboidMesh();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	/*
	 *	Returns the edit points of this rectangle, assuming the first line in Lines corresponds to the rectangle.
	 *	@return editPoints - array of rectangle edit points.
	 */
	TArray<AGame_EditPoint*> GetRectangleEditPoints();

	/*
	 * Set the edit point and rotator point locations from the rectangle length, width, and rotation.
	 */
	void UpdateRectangleFromFields(bool bActive);
	void UpdateRectangleFromFields(bool bActive, const TArray<int32>& ignoredIndices);
	
	/*
	 *	Detaches rectangle edit points from center edit point
	 */
	void DetachPointsFromCenter();

	/*
	 *	Attaches rectangle edit points to center edit point
	 */
	void AttachPointsToCenter();

	/*
	 *	Detaches cuboid mesh from center edit point
	 */
	void DetachMeshFromCenter();

	/*
	 *	Attaches cuboid mesh to center edit point
	 */
	void AttachMeshToCenter();

	/*
	 * Spawns central edit point.
	 * @param - Location to spawn edit point.
	 */
	void SpawnCenterEditPoint(const FVector& location);

	/*
	 *	Calculates the center of the rectangle and returns a geodetic coordinate
	 *	@param editPoints - array of rectangle edit points.
	 *  @return - location of center point in geodetic coordinates
	 */
	FGeodeticCoord3D CalculateCenterPoint(const TArray<AGame_EditPoint*>& editPoints);

	/*
	 *	@param cotDet - COT Event containing COT links with geodetic coordinates.
	 *  @return - location of center point in geodetic coordinates
	 */
	FGeodeticCoord3D CalculateCenterPoint(UVH_COTEvent* cotEvent);

	/*
	 * Calculates the spin of the rectangle based on the order of the edit points.
	 * @return - The spin of the rectangle. 1 = clockwise, -1 = counterclockwise.
	 */
	int32 CalculateRectangleSpin();


	// ---------------------------------
	// --- Events/Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleManipulationBegin(AActor* manipulatedActor);

	UFUNCTION()
	void HandleManipulationInProgress(AActor* manipulatedActor);

	UFUNCTION()
	void HandleRotatorManipulationEnd(AActor* manipulatedActor);
	
	UFUNCTION()
	void HandleManipulationEnd(AActor* manipulatedActor);
	
	UFUNCTION()
	void HandleLineColorChanged(FLinearColor inColor);
};