#pragma once

#include "VH_UmgListEntry.h"

#include "Game_ListEntry_Bloodhound.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_ListEntry_Bloodhound : public UVH_UmgListEntry
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_ListEntry_Bloodhound();

	// ---------------------------------
	// --- Members
	// ---------------------------------
protected:
	UPROPERTY()
	AActor* Actor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* PlayerIcon;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	UFUNCTION(BlueprintCallable)
	void SetActor(AActor* inActor);

	UFUNCTION(BlueprintPure)
	AActor* GetActor() const;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateIcon(const FSlateBrush& icon);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCallsign(const FString& callsign);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMGRS(const FString& mgrs);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBearing(const FString& bearing);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDistance(const FString& distance);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateElevation(const FString& elevation);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	void UpdateListEntryText();

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	UFUNCTION()
	void HandleActorDestroyed(AActor* destroyedActor);
};
