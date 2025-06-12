#pragma once

//  Parent Includes
#include "VH_COTComponent.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_COTComponent_GRG.generated.h"

class UVH_COTEvent;
class UTexture2D;
class UVH_KmlInfo;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_GRG : public UVH_COTComponent
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_GRG();


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FReceivedGRG, UTexture2D*, texture, const FVector&, location, FRotator, rotation, const FVector&, scale, const FString&, Entity_UID, const FString&, Class_UID);


	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
    UPROPERTY(BlueprintAssignable)
    FReceivedGRG OnReceivedGRG;

private:
	FGeodeticCoord2D NorthWestBB;

	FGeodeticCoord2D SouthEastBB;

	FGeodeticCoord3D Center;

	FRotator WorldRotation;

	FVector OriginalGlobeScale3D;
	FVector Scale3D;

	FString EntityUID;

	UPROPERTY()
	UTexture2D* Texture;

	FVector CachedLocation;
    

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

	virtual void SnapToGround() override;

	virtual bool ShouldHandleStale_Virtual() override { return false; }


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION()
	void LoadFromKML(UVH_KmlInfo* kmlInfo);

	UFUNCTION(BlueprintCallable)
    void GetBoundingBox(FGeodeticCoord2D& northWest, FGeodeticCoord2D& southEast);

	UFUNCTION(BlueprintCallable)
	void UpdateDecalInfo();
};