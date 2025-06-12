// Developed by Virtual Heroes, 2019-2020

#pragma once

// Game layer includes
#include "Game_COTComponent_Draw.h"

// Generated includes
#include "VTAK_COTComponent_DrawMensuration.generated.h"


// Forward declarations
class AVTAK_DrawContainer_Mensuration;
class AVTAK_Actor_Mensuration;


UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class VTAK_MENSURATION_API UVTAK_COTComponent_DrawMensuration : public UGame_COTComponent_Draw
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:

	UVTAK_COTComponent_DrawMensuration();


	// ---------------------------------
	// --- Member
	// ---------------------------------
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AVTAK_Actor_Mensuration> MensurationClass;

private:

	UPROPERTY()
	AVTAK_Actor_Mensuration* Mensuration;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:

	virtual void PopulateCOT_Virtual() override;

protected:

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive) override;

	virtual void SnapToGround() override;

	virtual void HandleOwnerSetHidden(bool bNewHidden) override;

	virtual void HandleOwnerSetScale3D(const FVector& scale3D) override;


	// ---------------------------------
	// --- API
	// ---------------------------------
public:

	UFUNCTION(BlueprintCallable)
	AVTAK_Actor_Mensuration* SpawnMensuration(const FVector& editPointLocation, const TSubclassOf<AVTAK_Actor_Mensuration> mnsClass = nullptr);

	UFUNCTION(BlueprintPure)
	AVTAK_Actor_Mensuration* GetMensuration() const;
};
