#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// VH Plugin Includes
#include "VH_KmlTypes.h"

//  Generated Includes
#include "Game_Actor_KmlPlacemark.generated.h"

struct FGeodeticCoord3D;
class UGame_ImportedMeshComponent;
class AVH_GlobeReferenceActor;
class AGame_SimpleSegmentedLineActor;
class AGame_Actor_KmlPoint;
class AGame_Actor_Mesh;
class AGame_VirtualObjective;
class UVH_KmlInfo;
class FKmlPlacemark;
class FKmlGeometry;
class FKmlModel;
class FKmlPolygon;
class FKmlPoint;
class FKmlLineStyle;
class FKmlColorStyle;

typedef TSet<AActor*> MeshSet;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Actor_KmlPlacemark : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Actor_Mesh> MeshActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> LowLODActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_SimpleSegmentedLineActor> LineActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Actor_KmlPoint> PointActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* ModelMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* PolygonMaterial;

private:
	UPROPERTY()
	AActor* LowLODActor;
	
	bool bLoadedOnce;

	bool bContainsLODGeometry;

	// garbage collection handled in ~FKmlContainer
	FKmlPlacemark* KmlPlacemark;

	UPROPERTY()
	UVH_KmlInfo* KmlInfo;

	TMap<EKmlElementType, MeshSet> SpawnedActors;

	UPROPERTY()
	TSet<AActor*> SpawnedActorsGC;

	UPROPERTY()
	AVH_GlobeReferenceActor* GlobeReference;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Actor_KmlPlacemark(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void PopulateFromKml(AGame_VirtualObjective* virtualObjective, UVH_KmlInfo* kmlInfo, FKmlPlacemark* kmlPlacemark);
	

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
	
private:
	AVH_GlobeReferenceActor* GetGlobeReference();

	void DestroySpawnedActors();
	
	void LoadKmlPlacemarkNonLOD(FKmlPlacemark* kmlPlacemark);

	void LoadKmlPlacemarkLOD(FKmlPlacemark* kmlPlacemark);

	void LoadKmlGeometry(FKmlGeometry* kmlGeometry);

	void LoadKmlModel(FKmlModel* kmlModel);

	void LoadKmlLineString(FKmlGeometry* kmlGeometry);

	void LoadKmlPolygon(FKmlPolygon* kmlPolygon);

	void LoadKmlPoint(FKmlPoint* kmlPoint);

	void CreateLine(const TArray<FGeodeticCoord3D>& coordinates, const FKmlLineStyle* kmlLineStyle, bool bExtrude, const FKmlColorStyle* kmlLineStyleExtrude);

	AGame_Actor_Mesh* AddMeshActor(EKmlElementType kmlElementType);
	
	void AddActorToSpawnedActors(EKmlElementType kmlElementType, AActor* actor);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void BindToTileManager();

	UFUNCTION()
	void PeriodicCheckLOD();

	UFUNCTION()
	void HandleTerrainUpdate();
};