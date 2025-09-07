#pragma once

// Parent Includes
#include "UObject/Object.h"
#include "Tickable.h"

// Engine Includes
#include "Dom/JsonObject.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_3DTileNode.generated.h"

class AVH_GlobeReferenceActor;

// ---------------------------------
// --- Structs
// ---------------------------------

struct FImplicitTileInfo
{
	uint32 Level;
	uint32 X;
	uint32 Y;

	FImplicitTileInfo(uint32 level, uint32 x, uint32 y)
	{
		Level = level;
		X = x;
		Y = y;
	}
};

UCLASS(Blueprintable)
class GAME_API UGame_3DTileNode : public UObject, public FTickableGameObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	double GeometricError;

	FString BoundingVolumeType;

	// valid when BoundingVolumeType = region
	FGeodeticCoord3D SouthWestLow;
	FGeodeticCoord3D NorthEastHigh;

	// valid when BoundingVolumeType = sphere
	double RadiusMeters;

	// valid when BoundingVolumeType = box
	mutable FVector ECEFX;
	mutable FVector ECEFY;
	mutable FVector ECEFZ;

	// valid for BoundingVolumeType = sphere or box
	mutable FVector ECEFCenter;
	mutable FVector ECEFCenterRaw;

	FString Refinement;

	FString FullPathToNode;

	FMatrix TransformMatrix;

	const TSharedPtr<FJsonObject>* ImplicitTilingPtr;

	UPROPERTY()
	UGame_3DTileNode* Parent;

	/* contains full file path to content */
	UPROPERTY()
	TSet<FString> Contents;

	UPROPERTY()
	TArray<UGame_3DTileNode*> Children;

	mutable TMap<FVector, FBox> Boxes;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_3DTileNode();


public:
	virtual TStatId GetStatId() const override;

	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	FMatrix GetTransformMatrix() const;

	void TransformECEF();

	void GetImplictTilesToLoad(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, AVH_GlobeReferenceActor* globeReference, double desiredGeometricError, int32& level, TArray<TPair<int32, int32>>& tileXYs);

	bool IntersectsRectangle(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, AVH_GlobeReferenceActor* globeReference, double viewDistanceMeters) const;

	double GetDistanceMeters(const FGeodeticCoord3D& playerCoordinate, AVH_GlobeReferenceActor* globeReference) const;
};
