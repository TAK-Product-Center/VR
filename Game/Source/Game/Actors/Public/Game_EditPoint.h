#pragma once

// Parent Includes
#include "Game_WorldInteractableActor.h"

// Engine Includes
#include "Components/SceneComponent.h"
#include "Components/MaterialBillboardComponent.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_EditPoint.generated.h"

class AGame_VirtualObjective;
class AGame_DrawContainer;
class AGame_SimpleSegmentedLineActor;
class AVH_GlobeReferenceActor;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_EditPoint : public AGame_WorldInteractableActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	AGame_DrawContainer* DrawContainer;

protected:
	UPROPERTY()
	AGame_SimpleSegmentedLineActor* LineActor;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UMaterialInstanceDynamic* ShapeMID;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* ShapeMeshComponent;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UMaterialBillboardComponent* MaterialBillboardComponent;

	FGeodeticCoord3D GeoLocation;

	bool bSelectionEnabled;

	bool bIsActive;

	bool bIsHovered;

	FColor Color;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_EditPoint(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void SetActorHiddenInGame(bool bNewHidden) override;

	virtual AVH_GlobeReferenceActor* GetGlobeReference() const override;

	virtual void PostBeginHover(AActor* actor) override;

	virtual void PostEndHover(AActor* actor) override;

	virtual void ManipulationEnd_Implementation() override;

	virtual double GetSettingScaleMultiplier() const;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SyncGeoLocationToWorldLocation();

	UFUNCTION(BlueprintCallable)
	void SyncWorldLocationToGeoLocation();

	UFUNCTION(BlueprintCallable)
	void SetGeoLocation(const FGeodeticCoord3D& coord) { GeoLocation = coord; }

	UFUNCTION(BlueprintPure)
	FGeodeticCoord3D GetGeoLocation() const { return GeoLocation; }

	UFUNCTION(BlueprintCallable)
	virtual void SetActive(bool bActive);

	UFUNCTION(BlueprintCallable)
	void SetLineActor(AGame_SimpleSegmentedLineActor* inLineActor);

	UFUNCTION(BlueprintPure)
	virtual bool GetActive() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AGame_SimpleSegmentedLineActor* GetLineActor() const;

	/* returns world location to use when syncing line to edit point */
	UFUNCTION(BlueprintNativeEvent)
	FVector GetLineDrawLocation() const;

	/* only taken into account when bIsActive is true */
	UFUNCTION(BlueprintCallable)
	void SetSelectionEnabled(bool bEnabled);

	/*
	 *  syncs GeoLocation to world location, then persists the DrawContainer's COTComponent's COTEvent to the database
	 */
	UFUNCTION(BlueprintCallable)
	void PersistWorldLocation();

	UFUNCTION(BlueprintCallable)
	void SetDrawContainer(AGame_DrawContainer* container);

	virtual void UpdateMaterial();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetColor(const FColor& color);

	void SetColor(const FColor& color);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual AGame_VirtualObjective* GetVirtualObjective() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleLineColorChanged(FLinearColor inColor);

	UFUNCTION()
	void HandleDoubleSettingStored(const FString& setting, double value);
};