#pragma once

// Parent Includes
#include "Components/ActorComponent.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "VTAK_DatabaseComponent_Orbit.generated.h"

class AVH_GlobeReferenceActor;
class AGame_VirtualObjective;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class VTAK_ORBIT_API UVTAK_DatabaseComponent_Orbit : public UActorComponent
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TMap<AActor*, FGeodeticCoord3D> ActorToLocation;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVTAK_DatabaseComponent_Orbit();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Orbit EntityUID"))
	static FString GetEntityUID();

	static FString GetCategoryID();

	static bool GetData(FGeodeticCoord3D& coordinate, double& radius, double& speed);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Orbit Coordinate"))
	static void SetCoordinate(const FGeodeticCoord3D& coordinate);

	static void SetRadius(double radius);
	
	static void SetSpeed(double speed);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void Delete();

	void Insert();

	void Update(AGame_VirtualObjective* virtualObjective, const TArray<uint8>& blobData);

    void PageIn(const FString& entityUID, const TArray<uint8>& blobData);

    void PageOut();

	void PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void SetScale3D(const FVector& scale3D);
};
