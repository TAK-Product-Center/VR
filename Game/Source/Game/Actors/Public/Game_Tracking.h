// Developed by Virtual Heroes, 2019-2020

#pragma once

// Engine includes
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

// Game includes
#include "Game_WorldActor.h"

// Generated include
#include "Game_Tracking.generated.h"

UCLASS()
class GAME_API AGame_Tracking : public AGame_WorldActor
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Member
	// ---------------------------------

public:

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UHierarchicalInstancedStaticMeshComponent* Breadcrumbs;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Utilities|Public")
	AGame_Point* CurrentTrackedPoint;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Setttings|Public")
	FVector ArrowScale;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Utilities|Public")
	bool bIsBreadcrumbsOn;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------

public:

	UFUNCTION(BlueprintCallable, Category = "Utilities|Public")
	void AddBreadcrumb();

	UFUNCTION(BlueprintCallable, Category = "Utilities|Public")
	bool IsLastBreadcrumbSimilar() const;

	UFUNCTION(BlueprintCallable, Category = "Utilities|Public")
	bool GetBreadcrumbStatus() const;

	UFUNCTION(BlueprintCallable, Category = "Utilities|Public")
	void InitializeTrackingActor(AGame_Point* actorToTrack);

	UFUNCTION(BlueprintCallable)
	void ToggleBreadcrumbs();

	// ---------------------------------
	// --- Implementation Methods
	// ---------------------------------

public:

	AGame_Tracking(const FObjectInitializer& objectInitializer);

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:

	UFUNCTION(BlueprintCallable)
	void OnCOTUpdate(UVH_COTEvent* cotEvent);

};
