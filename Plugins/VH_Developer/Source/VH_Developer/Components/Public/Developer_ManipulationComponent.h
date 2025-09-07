#pragma once

// Parent Includes
#include "Components/ActorComponent.h"

// Generated Includes
#include "Developer_ManipulationComponent.generated.h"

class UDeveloper_Subsystem_Manipulation;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_DEVELOPER_API UDeveloper_ManipulationComponent : public UActorComponent
{
	GENERATED_BODY()

	friend class UDeveloper_Subsystem_Manipulation;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ManipulationComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

private:
	UFUNCTION(Server, Reliable)
	void Server_SetWorldLocation(AActor* actor, const FVector& location);

	UFUNCTION(Server, Reliable)
	void Server_SetWorldRotation(AActor* actor, const FQuat& rotation);

	UFUNCTION(Server, Reliable)
	void Server_SetWorldScale(AActor* actor, const FVector& scale);
};