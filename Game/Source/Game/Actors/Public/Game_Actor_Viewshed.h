#pragma once

// Parent Includes
#include "LidarPointCloudActor.h"

// Engine Includes
#include "LidarPointCloudShared.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_Actor_Viewshed.generated.h"

class UHierarchicalInstancedStaticMeshComponent;
class USceneComponent;

UCLASS()
class GAME_API AGame_Actor_Viewshed : public ALidarPointCloudActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USceneComponent* Root;

private:
	FString EntityUID;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	FGeodeticCoord3D Coordinate;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	int32 GridX;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	int32 GridY;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	double RadiusMeters;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	int32 PointsPerBeam;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	double PointSize;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	bool bTraceGround;

	TArray<FLidarPointCloudPoint> PointsToAdd;

	FThreadSafeCounter DestroyCounter;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Actor_Viewshed(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool IsReadyForFinishDestroy() override;


	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintCallable)
	void CreateViewshedPointCloud(const FString& entityUID, const FGeodeticCoord3D& coordinateParam, int32 gridXParam, int32 gridYParam, double radiusMetersParam, int32 pointsPerBeamParam, double pointSizeParam, bool bTraceGroundArg);

	UFUNCTION(BlueprintCallable)
	void SetPointSize(float pointSizeParam);

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateTaskTracker(double progress);

	void InsertOrUpdateDatabase();

	bool IsSafeToExecute();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void PeriodicAttemptToLoad();
};