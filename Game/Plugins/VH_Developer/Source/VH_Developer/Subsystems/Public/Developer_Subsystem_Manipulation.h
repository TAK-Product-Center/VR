#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Generated Includes
#include "Developer_Subsystem_Manipulation.generated.h"

class AActor;
class UDeveloper_ManipulationComponent;
enum class EAxisListBlueprint : uint8;

UCLASS()
class VH_DEVELOPER_API UDeveloper_Subsystem_Manipulation : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
private:
	UPROPERTY()
	UDeveloper_ManipulationComponent* ManipulationComponent;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Subsystem_Manipulation();

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void AddOffsetInWorldSpace(const TSet<AActor*>& actors, const FVector& offset);

	UFUNCTION(BlueprintCallable)
	void AddOffsetInLocalSpace(const TSet<AActor*>& actors, const FVector& offset);

	UFUNCTION(BlueprintCallable)
	void AddOffsetInTransformSpace(const TSet<AActor*>& actors, const FVector& offset, const FTransform& transform);

	UFUNCTION(BlueprintCallable)
	void SetLocationInWorldSpace(const TSet<AActor*>& actors, const FVector& location);

	UFUNCTION(BlueprintCallable)
	void SetLocationInTransformSpace(const TSet<AActor*>& actors, const FVector& location, const FTransform& transform);

	UFUNCTION(BlueprintCallable)
	void AddRotationInWorldSpace(const TSet<AActor*>& actors, const FRotator& rotation);
	void AddRotationInWorldSpace(const TSet<AActor*>& actors, const FQuat& rotation);

	UFUNCTION(BlueprintCallable)
	void AddRotationInLocalSpace(const TSet<AActor*>& actors, const FRotator& rotation);
	void AddRotationInLocalSpace(const TSet<AActor*>& actors, const FQuat& rotation);

	UFUNCTION(BlueprintCallable)
	void AddRotationInTransformSpace(const TSet<AActor*>& actors, const FRotator& rotation, const FTransform& transform);
	void AddRotationInTransformSpace(const TSet<AActor*>& actors, const FQuat& rotation, const FTransform& transform);

	UFUNCTION(BlueprintCallable)
	void SetRotationInWorldSpace(const TSet<AActor*>& actors, const FRotator& rotation);
	void SetRotationInWorldSpace(const TSet<AActor*>& actors, const FQuat& rotation);

	UFUNCTION(BlueprintCallable)
	void SetRotationInTransformSpace(const TSet<AActor*>& actors, const FRotator& rotation, const FTransform& transform);
	void SetRotationInTransformSpace(const TSet<AActor*>& actors, const FQuat& rotation, const FTransform& transform);

	UFUNCTION(BlueprintCallable)
	void AddScaleInWorldSpace(const TSet<AActor*>& actors, const FVector& scale);

	UFUNCTION(BlueprintCallable)
	void AddScaleInLocalSpace(const TSet<AActor*>& actors, const FVector& scale);

	UFUNCTION(BlueprintCallable)
	void SetScaleInWorldSpace(const TSet<AActor*>& actors, const FVector& scale);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void SetWorldLocation(AActor* actor, const FVector& location);

	void SetWorldRotation(AActor* actor, const FQuat& rotation);

	void SetWorldScale(AActor* actor, const FVector& scale);

	UDeveloper_ManipulationComponent* GetManipulationComponent();
};
