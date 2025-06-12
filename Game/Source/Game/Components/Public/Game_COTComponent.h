#pragma once

#include "VH_COTComponent.h"

#include "Game_COTComponent.generated.h"

// Forward Declarations
class UVH_COTEvent;
class AVH_GlobeReferenceActor;
class AGame_VirtualObjective;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent : public UVH_COTComponent
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
    UGame_COTComponent();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BroadcastCOT() override;

	virtual void SendCOT(const TArray<FName>& contactUIDs) override;

protected:
	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void PopulateCOT_Virtual() override;

	virtual void SnapToGround() override;

	virtual void CleanupStaleEntity() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
    // insert/update database and add object to player's VO (if not already added)
    UFUNCTION(BlueprintCallable)
    virtual void RegisterWithDatabase(AGame_VirtualObjective* virtualObjective = nullptr);

	UFUNCTION(BlueprintPure)
	virtual AGame_VirtualObjective* GetVirtualObjective() const;

	UFUNCTION(BlueprintPure)
	virtual AVH_GlobeReferenceActor* GetGlobeReference() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------
	
private:
	TSet<FString> GetAttachmentsToSend();

	FString GetAttachmentZipForSend(const TSet<FString>& attachmentsToSend);
};
