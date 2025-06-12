#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"
#include "Interface_UI_ContextMenuSource.h"
#include "Interface_Developer_Manipulation.h"

// Generated Includes
#include "Game_SimpleSegmentedLineActor.generated.h"

class AVH_GlobeReferenceActor;
class AGame_DrawContainer;
class AGame_VirtualObjective;
class UGame_CameraScalingComponent;
class UProceduralMeshComponent;
class UMaterialInstanceDynamic;

USTRUCT(Blueprintable, BlueprintType)
struct FLinePoint
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FastLinePoint")
	FVector Location;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FastLinePoint")
	double Width;

	FLinePoint(const FVector& location, double width) :
		Location(location),
		Width(width)
	{

	}

	FLinePoint() :
		FLinePoint(FVector::ZeroVector, 0.0)
	{

	}
};

inline bool operator==(const FLinePoint& lhs, const FLinePoint& rhs)
{
	return lhs.Location.Equals(rhs.Location);
}

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_SimpleSegmentedLineActor : public AActor, public IInterface_UI_ContextMenuSource, public IInterface_Developer_Manipulation
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManipulationInProgress, AActor*, manipulatedActor);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManipulationBegin, AActor*, manipulatedActor);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManipulationEnd, AActor*, manipulatedActor);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FColorChanged, FLinearColor, newColor);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Delegates")
	FColorChanged OnColorChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManipulationInProgress OnManipulationInProgress;

	UPROPERTY(BlueprintAssignable)
	FOnManipulationBegin OnManipulationBegin;

	UPROPERTY(BlueprintAssignable)
	FOnManipulationEnd OnManipulationEnd;

	/* The points used to generate the segmented line. You need at least two. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLinePoint> LinePoints;

	/* Base for calculating final thickness */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseThickness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double DefaultWidth;

	/* All segments use this material. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* Material;

	/* All segments use this material. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMaterialInstanceDynamic* MaterialInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bBuildSectionsWithCollision;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	AGame_DrawContainer* DrawContainer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UObject>> ContextOptionClasses;

	/* How long line segments can get before they segment (such as for curving around the globe). */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TessellationLength;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_CameraScalingComponent* CameraScalingComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float HoveredScaleMultiplier;

private:
	UPROPERTY()
	UProceduralMeshComponent* ProcMesh;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FColor Color;

	TArray<FLinePoint> CachedLinePoints;

	bool bGenerateMesh;

	TArray<FGeodeticCoord3D> Coords;

	double DatabaseScaleMultiplier;

	bool bHovered;

	mutable int32 VirtualObjectiveAttempts;

	FGeodeticCoord3D LastCoordinateAtGenerate;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_SimpleSegmentedLineActor(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- IInterface_UI_ContextMenuSource
	// ---------------------------------

public:
	void GetContextOptionClasses_Implementation(TSet<TSubclassOf<UObject>>& contextOptionClasses);


	// ---------------------------------
	// --- Interface_Developer_Manipulation
	// ---------------------------------

public:
	bool GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList);

	bool GetRotationAxisList_Implementation(EAxisListBlueprint& axisList);

	bool GetRotationDisabled_Implementation();

	bool GetScaleAxisList_Implementation(EAxisListBlueprint& axisList);

	void ManipulationBegin_Implementation();

	void ManipulationInProgress_Implementation();

	void ManipulationEnd_Implementation();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	void BeginPlay() override;

	void Tick(float deltaTime) override;

	void SetActorHiddenInGame(bool bNewHidden) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveBeginHover(AActor* actor);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveEndHover(AActor* actor);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveManipulationBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveManipulationInProgress();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveManipulationEnd();

	UFUNCTION(BlueprintCallable)
	virtual void GenerateMesh();

	UFUNCTION(BlueprintCallable)
	void SetCollision(bool bShouldCollide);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetMaterialColor(const FColor& newColor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetMaterialHighlighted(bool isHighlighted);

	void SetColor(const FColor& newColor);

	FColor GetColor() const;

	/*
	 * Append a new location end of the line.
	 *
	 * @param location The new location to add.
	 */
	UFUNCTION(BlueprintCallable)
	void AddLocation(const FVector& location);

	/*
	 * Remove the last location at the end of the line
	 * @return true if line is empty after removal
	 */
	UFUNCTION(BlueprintCallable)
	bool RemoveLastLocation();

	UFUNCTION(BlueprintPure)
	FVector GetPointLocation(int32 index, bool& isValid) const;

	UFUNCTION(BlueprintPure)
	TArray<FVector> GetLocationArray() const;

	UFUNCTION(BlueprintPure)
	FVector GetAverageLocation() const;

	UFUNCTION(BlueprintPure)
	bool GetExtents(FVector& extentsMin, FVector& extentsMax) const;

	void SnapToGround();

	void AddLocationAndGeoLocation(const FVector& worldLocation, const FGeodeticCoord3D& coord);

	UFUNCTION(BlueprintCallable)
	void AddLocationAndGeoLocation(const FVector& worldLocation);

	void UpdateLocationAndGeoLocation(int32 index, const FVector& worldLocation, const FGeodeticCoord3D& coord);

	FGeodeticCoord3D GetGeoLocation(int32 index) const;

	bool AreCoordinatesValid();

	UFUNCTION(BlueprintCallable)
	void SetMaxDrawDistance(float dist);

	UFUNCTION(BlueprintCallable)
	void SetDrawContainer(AGame_DrawContainer* container);

	void ClearLinePoints();

	FVector GetClosestPointTo(const FVector& worldLocation) const;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool ShouldGenerateMesh();

	void PreGenerateMesh();

	void GenerateMeshInternal();

	void GenerateMeshInternal(const TArray<FLinePoint>& points, TArray<FVector>& vertices, TArray<int32>& triangles, TArray<FVector>& normals, TArray<FVector2D>& uvs);

	/* Modify the points beings used in GenerateMesh. */
	void ModifyMeshPoints(TArray<FLinePoint>& points);

	UFUNCTION()
	void UpdateMaterialForVO();

	AGame_VirtualObjective* GetVirtualObjective() const;

	AVH_GlobeReferenceActor* GetGlobeReference() const;

	void SetPointThickness();

	virtual void PostManipulationBegin();

	virtual void PostManipulationInProgress();

	virtual void PostManipulationEnd();

	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleBeginCursorOver(AActor* actor);

	UFUNCTION()
	void HandleEndCursorOver(AActor* actor);

	UFUNCTION()
	void HandleClickPressed(AActor* actor, FKey buttonPressed);

	UFUNCTION()
	void HandleClickReleased(AActor* actor, FKey buttonReleased);

	UFUNCTION()
	void HandleDoubleSettingStored(const FString& key, double value);
};
