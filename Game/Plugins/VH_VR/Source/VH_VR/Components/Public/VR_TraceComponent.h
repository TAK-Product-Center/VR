#pragma once

// Parent Includes
#include "Components/SceneComponent.h"

// Engine Includes
#include "Engine/HitResult.h"

// Generated Includes
#include "VR_TraceComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_VR_API UVR_TraceComponent : public USceneComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSet<TEnumAsByte<ECollisionChannel>> DefaultChannelsToTrace;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bShouldTrace;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double TraceDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<AActor*> IgnoredActors;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bDrawDebugLine;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double TraceCooldown;
	
private:
	TMap<ECollisionChannel, TArray<FHitResult>> TraceResults;

	double LastTrace;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVR_TraceComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	TSet<ECollisionChannel> GetChannelsToTrace() const;

	UFUNCTION(BlueprintCallable)
	void AddTraceChannel(ECollisionChannel collisionChannel);

	UFUNCTION(BlueprintCallable)
	void RemoveTraceChannel(ECollisionChannel collisionChannel);

	UFUNCTION(BlueprintPure)
	bool GetHitResults(ECollisionChannel collisionChannel, TArray<FHitResult>& hitResults) const;

	UFUNCTION(BlueprintCallable)
	void UpdateTrace();

	void GetStartAndEnd(FVector& start, FVector& end) const;
};