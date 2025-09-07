#pragma once

// Parent Includes
#include "Game_COTComponent_Draw.h"

// Game Includes
#include "Game_EditPoint_Center.h"

// Generated Includes
#include "Game_COTComponent_DrawCircle.generated.h"

class AGame_Arrow;
class AGame_Actor_Mesh;
class AGame_SimpleSegmentedLineActor;

/*
 * The COT component the circle draw container uses to create and adjust edit points for ellipses.
 */
UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawCircle : public UGame_COTComponent_Draw
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* The arrow used to draw */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Arrow> ArrowClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_EditPoint_Center> CenterEditPointClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<AGame_Actor_Mesh> CylinderFillActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* CylinderFillMaterial;

protected:
	UPROPERTY()
	AGame_EditPoint_Center* CenterEditPoint;

private:
	/* The arc distance (in Unreal units) between edit points on the circles' perimeters.*/
	float PointsToRadiusRatioUU;

	FColor LineColor;

	FColor PolyColor;

	int32 StyleWidth;

	float CylinderHeight;

	/* Dragged around to determine the radius of the circle.*/
	UPROPERTY()
	AGame_Arrow* Arrow;

	UPROPERTY()
	AGame_Actor_Mesh* CylinderMesh;
	
	/* The minor radius of the circle*/
	float MinorRadius_Meters;

	/* Circles in the COT standard are allowed to be ellipses*/
	float MajorRadius_Meters;
	
	/* Used to avoid recalculating the points when the perimeter hasn't changed.*/
	float Perimeter_UU;

	bool bIgnoreColorDelegate;

	UPROPERTY()
	TSet<AGame_SimpleSegmentedLineActor*> TopLines;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_DrawCircle();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Circle Radius"))
	static double GetRadius(UVH_COTEvent* cotEvent);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Circle Radius"))
	static void SetRadius(UVH_COTEvent* cotEvent, double radius);

	UFUNCTION(BlueprintPure)
	static int32 GetNumberEllipses(UVH_COTEvent* cotEvent);

	UFUNCTION(BlueprintCallable)
	static void SetNumberEllipses(UVH_COTEvent* cotEvent, int32 ellipses);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void SnapToGround() override;

	virtual bool ShouldSnapEditPoint(AGame_EditPoint* editPoint) const override;
	
	virtual TArray<FVector> PreModifyVOGlobeReference() override;

	virtual void PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions) override;

	virtual void HandleOwnerSetScale3D(const FVector& scale3D) override;

	virtual void HandleOwnerSetHidden(bool bNewHidden) override;

protected:
	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void PopulateCOT_Virtual() override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	 *	Creates the arrow, center edit point, and circles.
	 *	@param EditPointLocation - The location of the center edit point.
	 */
	UFUNCTION(BlueprintCallable)
	void SpawnDrawElements(const FVector& editPointLocation, const FLinearColor& inColor);

	/*
	 * Gets the Arrow used by the controller to draw the Circle
	 * @return The drawing Arrow.
	 */
	UFUNCTION(BlueprintPure)
	AGame_Arrow* GetArrow() const;

	/*
	 * Sets the PolyColor.A and updates the circle's rings.
	 * @param inPolyAlpha - The new PolyColor.A
	 */
	UFUNCTION(BlueprintCallable)
	void SetPolyAlpha(uint8 inPolyAlpha);
	
	/*
	 * Gets the center edit point
	 * @return The center edit point.
	 */
	UFUNCTION(BlueprintPure)
	AGame_EditPoint_Center* GetCenterEditPoint() const;

	/*
	 * Gets the minor radius in meters
	 * @return The minor radius
	 */
	UFUNCTION(BlueprintPure)
	float GetMinorRadius() const;

	/* Syncs perimeter editpoints based on current class variable values. Recalculates locations based on center point and radii. */
	UFUNCTION(BlueprintCallable)
	void SyncPerimeterEditPoints();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	/* Syncs cylinder meshes based on current class variable values */
	void SyncCylinderMesh();

	/* syncs line, editpoints, and mesh colors based on current class variable values */
	void SyncColors();

	/*
	 * Spawns the arrow at the specified point.
	 * @param - The point at which to spawn the Arrow.
	 * @return - The spawned Arrow.
	 */
	AGame_Arrow* SpawnArrow(const FVector& editPointLocation);
	
	AGame_EditPoint* SpawnCenterEditPoint(const FVector& location);

	/*
	 * Spawns a CircleLine, gives it an edit point, and attaches it to the CenterEditPoint.
	 * @return - The spawned SimpleSegmentedLineActor.
	 */
	AGame_SimpleSegmentedLineActor* SpawnCircleLine();

	/*
	 *	Detaches circle edit points from center edit point
	 */
	void DetachEditPointsFromCenter();

	/*
	 *	Detaches cylinders from center edit point
	 */
	void DetachCylindersFromCenter();

	/*
	 *	Attaches circle edit points to center edit point
	 */
	void AttachEditPointsToCenter();

	/*
	 *	Attaches cylinders to center edit point
	 */
	void AttachCylindersToCenter();


	// ---------------------------------
	// --- Events/Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleLineColorChanged(FLinearColor inColor);

	UFUNCTION()
	void HandleManipulationBegin(AActor* manipulatedActor);

	UFUNCTION()
	void HandleManipulationEnd(AActor* manipulatedActor);
};
