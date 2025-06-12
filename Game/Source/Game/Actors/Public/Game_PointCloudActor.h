#pragma once

#include "LidarPointCloudActor.h"
#include "LidarPointCloudComponent.h"

#include "Game_PointCloudActor.generated.h"

UCLASS()
class GAME_API AGame_PointCloudActor : public ALidarPointCloudActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	
private:
	float PointCloudScale;

	float ActorScale;

	FTimerHandle UpdatePointCloudScaleTimerHandle;

	FString FullPathToFile;
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_PointCloudActor();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void SetActorScale3D(FVector newScale3D) override;


	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	void SetFile(const FString& fullPathToFile);

	UFUNCTION(BlueprintCallable)
	void SetPointSize(float pointSize);

	UFUNCTION(BlueprintCallable)
	void SetColorSource(ELidarPointCloudColorationMode colorSource);
	

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateBlob();

	void CreatePointCloud(float importScale);

	UFUNCTION()
	void UpdatePointCloudScale();

	UFUNCTION()
	void UpdateBoundsInDB();
};