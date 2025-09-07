#pragma once

// Engine
#include "GameFramework/Actor.h"

// Generated
#include "VH_RoadSpline.generated.h"

// Forward declarations
class UFoliageInstancedStaticMeshComponent;
class USplineComponent;


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(Blueprintable)
struct FRoadData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RoadBank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RoadWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RoadThickness;

	FRoadData()
	{
		RoadBank = 0.f;
		RoadWidth = 1.f;
		RoadThickness = 2.f;
	}
};

USTRUCT(Blueprintable)
struct FFoliageTransforms
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTransform> Transforms;

	FFoliageTransforms()
	{
		
	}
};

UCLASS(Blueprintable, BlueprintType)
class AVH_RoadSpline : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Road", meta = (AllowPrivateAccess = "true"))
	USplineComponent* Spline;

protected:
	/** The spline mesh construction information for each road segment. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track Setup")
	TArray<FRoadData> RoadDataArray;

	/**  The road data that new road segments are initialized to. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track Setup")
	FRoadData RoadMeshDefaults;
	
	/** Should this road build an additional segment to close the loop */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track Setup")
	bool bLoopingTrack;

	/** How far each segment should trace down to find a blocking floor. If no floor is found, the segment will not be adjusted. Always applied to -Z */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track Setup")
	float FloorTraceLength;

	/** The cached transforms of destroyed foliage actors. Used for the restoration function. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage")
	TMap<UFoliageInstancedStaticMeshComponent*, FFoliageTransforms> DestroyedFoliage;

	/** If enabled, foliage will be destroyed on begin play */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage")
	bool bDestroyFoliage;

	/** The trace radius for foliage destruction. Should be greater than the width of the road. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage")
	float FoliageSphereTraceRadius;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVH_RoadSpline();

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	USplineComponent* GetSplineComponent() const { return Spline; }
};

