#pragma once

// Parent Includes
#include "Components/ActorComponent.h"

// Generated Includes
#include "VR_CoreComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_VR_API UVR_CoreComponent : public UActorComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FTransform LastReplicatedTransform;
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVR_CoreComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

private:
	UFUNCTION(Server, Unreliable)
	void Server_SetRelativeTransform(const FTransform& transform);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;
};
