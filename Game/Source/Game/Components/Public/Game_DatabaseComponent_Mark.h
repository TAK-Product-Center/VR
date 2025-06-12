#pragma once

#include "Components/ActorComponent.h"
#include "VH_GeodeticCoord.h"
#include "Game_DatabaseComponent_Mark.generated.h"

class AVH_GlobeReferenceActor;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_DatabaseComponent_Mark : public UActorComponent
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Members
	// ---------------------------------
public:
	//Might not even need a category
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName CategoryID;

private:
	TMap<AActor*, FGeodeticCoord3D> ActorToLocation;

	FString EntityUID;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------
public:
    UGame_DatabaseComponent_Mark();

    UFUNCTION(BlueprintImplementableEvent)
    void SpawnMark(const FVector& worldLocation, bool bUpdateDatabase);

    UFUNCTION(BlueprintCallable)
    void Insert();

	UFUNCTION(BlueprintCallable)
	void Delete();

	UFUNCTION(BlueprintCallable)
	FString GetEntityUID() const { return EntityUID; }

	UFUNCTION(BlueprintCallable)
	void SetEntityUID(FString inUID) { EntityUID = inUID; }

    void PageIn(const FString& entityUID, const TArray<uint8>& blobData);

    void PageOut();

	void SetScale3D(const FVector& scale3D);

	void PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);
};
