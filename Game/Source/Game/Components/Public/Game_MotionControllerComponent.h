#pragma once

// Parent Includes
#include "VR_MotionControllerComponent.h"

// VH Module Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_MotionControllerComponent.generated.h"

UCLASS()
class GAME_API UGame_MotionControllerComponent : public UVR_MotionControllerComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	
private:
	UPROPERTY(ReplicatedUsing = OnRep_TraceStartCoordinate)
	FGeodeticCoord3D TraceStartCoordinate;

	UPROPERTY(ReplicatedUsing = OnRep_TraceEndCoordinate)
	FGeodeticCoord3D TraceEndCoordinate;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MotionControllerComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& outLifetimeProps) const override;

	UFUNCTION(Server, Reliable)
	void Server_SetTraceCoordinates(const FGeodeticCoord3D& startCoordinate, const FGeodeticCoord3D& endCoordinate);

private:
	UFUNCTION()
	void OnRep_TraceStartCoordinate();

	UFUNCTION()
	void OnRep_TraceEndCoordinate();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

protected:
	virtual void PreReplication(IRepChangedPropertyTracker& changedPropertyTracker) override;

	virtual void ReplicateTransform() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	FGeodeticCoord3D GetTraceStartCoordinate() const;

	FGeodeticCoord3D GetTraceEndCoordinate() const;
};