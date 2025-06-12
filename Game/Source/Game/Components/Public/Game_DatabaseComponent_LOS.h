#pragma once

#include "Components/ActorComponent.h"
#include "VH_GeodeticCoord.h"
#include "Game_DatabaseComponent_LOS.generated.h"

class AVH_GlobeReferenceActor;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_DatabaseComponent_LOS : public UActorComponent
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Members
	// ---------------------------------
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName CategoryID;

private:
	TMap<AActor*, FGeodeticCoord3D> ActorToLocation;

	FString EntityUID;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------
public:
    UGame_DatabaseComponent_LOS();

    UFUNCTION(BlueprintImplementableEvent)
    void SpawnViewpoint(const FVector& worldLocation, const FRotator& rotation, bool bUpdateDatabase);

    UFUNCTION(BlueprintImplementableEvent)
    void SetStance(int32 stance, bool bUpdateDatabase);

    UFUNCTION(BlueprintCallable)
    void Insert(const TArray<AActor*>& viewpoints, int32 stance);

	UFUNCTION(BlueprintCallable)
	void Delete();

    FString GetEntityUID() const { return EntityUID; }

    void PageIn(const FString& entityUID, const TArray<uint8>& blobData);

    void PageOut();

	void SetScale3D(const FVector& scale3D);

	UFUNCTION(BlueprintImplementableEvent)
	TArray<AActor*> GetGlobeReferenceActors();

	void PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);
};
