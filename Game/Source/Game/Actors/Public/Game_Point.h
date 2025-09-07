#pragma once

// Parent Includes
#include "Game_WorldInteractableActor.h"

// VH Plugin Includes
#include "Interface_COTReceiver.h"
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_Point.generated.h"

class UGame_WidgetComponent;
class AGame_Tracking;
class UGame_COTComponent;
class UGame_UserWidget_Point;
class AGame_VirtualObjective;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Point : public AGame_WorldInteractableActor, public IInterface_COTReceiver
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Callsign")
	TSubclassOf<UGame_UserWidget_Point> CallsignWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Callsign")
	UGame_WidgetComponent* CallsignComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_COTComponent* COTComponent;

private:
	UPROPERTY()
	UGame_UserWidget_Point* CallsignWidget;

	UPROPERTY()
	AGame_Tracking* Breadcrumb;

	bool bRegisteredMapIcon;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Point(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_COTReceiver
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UVH_COTComponent* GetCOTComponent() const;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void ManipulationEnd_Implementation() override;
	
	virtual double GetSettingScaleMultiplier() const override;

	virtual void PostBeginHover(AActor* actor) override;

	virtual void PostEndHover(AActor* actor) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	float GetBearingToPoint(FVector locationOfOrigin) const;

	UFUNCTION(BlueprintCallable)
	FString GetCallsign() const;

	UFUNCTION(BlueprintCallable)
	void SyncCallsignWidget();

	UFUNCTION(BlueprintCallable)
	virtual void SetType(const FName& type);

	UFUNCTION(BlueprintCallable)
	void InitTracking();

	/* if virtualObjective is nullptr will use UGame_VirtualObjectiveManager::GetObjectVO(this) */
	UFUNCTION(BlueprintCallable)
	void SyncGeolocationToWorldLocation(AGame_VirtualObjective* virtualObjective);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	AGame_VirtualObjective* GetVirtualObjective() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:
	UFUNCTION(BlueprintCallable)
	virtual void HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent);

	UFUNCTION()
	virtual void HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters);

private:
	UFUNCTION()
	void HandleDoubleSettingStored(const FString& setting, double value);
};
