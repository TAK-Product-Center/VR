#pragma once

// Parent Includes
#include "Game_COTComponent_Draw.h"

// Generated Includes
#include "Game_COTComponent_DrawPolyline.generated.h"

class FXmlNode;
class AGame_Actor_Mesh;
class UMaterialInstanceDynamic;
class AGame_EditPoint_Center;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawPolyline : public UGame_COTComponent_Draw
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_EditPoint_Center> CenterEditPointClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Actor_Mesh> MeshActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* PolygonMaterial;

private:
	UPROPERTY()
	AGame_EditPoint_Center* CenterEditPoint;

	TArray<FXmlNode*> QueuedLinks;

	bool bClosed;

	UPROPERTY()
	AGame_Actor_Mesh* MeshActor;

	uint8 FillColorAlpha;

	UPROPERTY()
	UMaterialInstanceDynamic* FillMaterialInstance;

	FTimerHandle UpdateFillTimerHandle;
	
	FTimerHandle QueuedLinkTimerHandle;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_DrawPolyline();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void HandleOwnerSetHidden(bool bNewHidden) override;

	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void PopulateCOT_Virtual() override;


	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintCallable)
	void SetClosed(bool bClosedArg);

	UFUNCTION(BlueprintPure)
	bool IsClosed() const;

	UFUNCTION(BlueprintCallable)
	void SetFillColorAlpha(int32 alpha);

	UFUNCTION(BlueprintPure)
	int32 GetFillColorAlpha() const;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	FVector GetCenterWorldLocation() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void AddQueuedLink();

	UFUNCTION()
	void PeriodicUpdateForClosed();
};