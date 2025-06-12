#pragma once

// Parent Includes
#include "MotionControllerComponent.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"

// Module Includes
#include "Interface_VR_Tool.h"

// Generated Includes
#include "VR_MotionControllerComponent.generated.h"

class UInputComponent;
class UInputAction;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_VR_API UVR_MotionControllerComponent : public UMotionControllerComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputStackTopChanged, AActor*, tool);

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
public:
	UPROPERTY(BlueprintAssignable)
	FInputStackTopChanged OnInputStackTopChanged;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSet<UInputAction*> InputActions;

	/* Relative location to use for VR Emulation */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector VREmulationRelativeLocation;

	/* prioritized list of collision channels to trace to find end point for rotation during non-VR */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TEnumAsByte<ECollisionChannel>> NonVRCollisionChannels;

protected:
	FVector LastTraceEndLocation;

private:
	EHardwareInterfaceMode HardwareInterfaceMode;

	UPROPERTY(ReplicatedUsing = OnRep_RelativeTransform)
	FTransform RelativeTransform;

	FTransform LastReplicatedTransform;

	UPROPERTY()
	TArray<AActor*> InputToolStack;

	UPROPERTY(ReplicatedUsing = OnRep_InputToolStackTop)
	AActor* InputToolStackTop;

	UPROPERTY()
	UInputComponent* InputComponent;

	FTimerHandle AxisValuesTimerHandle;

	bool bCachedIsTracked;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVR_MotionControllerComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------
	
public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& outLifetimeProps) const override;

private:
	UFUNCTION(Server, Unreliable)
	void Server_SetRelativeTransform(const FTransform& transform);

	UFUNCTION(Server, Reliable)
	void Server_AddTool(AActor* tool);

	UFUNCTION(Server, Reliable)
	void Server_AddToolByClass(TSubclassOf<AActor> toolClass);

	UFUNCTION(Server, Reliable)
	void Server_RemoveTool(AActor* tool);

	UFUNCTION(Server, Reliable)
	void Server_RemoveAllTools();

	UFUNCTION(Server, Reliable)
	void Server_SetToolsVisibility(bool bVisibleArg);

	UFUNCTION()
	void OnRep_RelativeTransform();

	UFUNCTION()
	void OnRep_InputToolStackTop();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Adds specified tool to InputToolStack.  RPC's to server when called without authority.
	*/
	UFUNCTION(BlueprintCallable)
	void AddTool(AActor* tool);

	/*
	* \brief Spawns actor via toolClass, then adds actor to InputToolStack.  RPC's to server when called without authority.
	*/
	UFUNCTION(BlueprintCallable)
	void AddToolByClass(TSubclassOf<AActor> toolClass);

	/*
	* \brief Removes specified tool from InputToolStack.  RPC's to server when called without authority.
	*/
	UFUNCTION(BlueprintCallable)
	void RemoveTool(AActor* tool);

	/*
	* \brief Removes all tools from InputToolStack.  RPC's to server when called without authority.
	*/
	UFUNCTION(BlueprintCallable)
	void RemoveAllTools();

	/* 
	* \brief Returns top of InputToolStack. This actor receives input.
	*/
	UFUNCTION(BlueprintPure)
	AActor* GetInputToolStackTop() const;

	UFUNCTION(BlueprintPure)
	bool HasTool(AActor* toolToFind) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	/*
	* \brief Called each tick on locally controlled client; pushed relative transform to server for replication
	*        Override for custom replication
	*/
	virtual void ReplicateTransform();

	bool IsLocallyControlled() const;

private:
	void SetInputToolStackTop();

	void BindInputComponent();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);

	UFUNCTION()
	void HandleInputAction(const FInputActionInstance& inputActionInstance);
};