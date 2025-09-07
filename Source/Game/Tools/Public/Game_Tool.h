#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Engine Includes
#include "InputActionValue.h"
#include "Layout/WidgetPath.h"

// VH Plugin Includes
#include "VR_Subsystem_Core.h"
#include "Interface_VR_Tool.h"
#include "Interface_UI_ContextMenuSource.h"
#include "Database_Spatialite.h"

// Generated Includes
#include "Game_Tool.generated.h"

UENUM(BlueprintType)
enum class EPanningState : uint8
{
	NotPanning,
	RequestPanning,
	Panning
};

class UStaticMeshComponent;
class UVR_TraceComponent;
class UVR_WidgetInteractionComponent;
class UVR_MotionControllerComponent;
class APlayerState;
class UMaterialInstanceDynamic;
class UGame_CameraScalingComponent;
struct FInputActionInstance;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Tool : public AActor, public IInterface_VR_Tool, public IInterface_UI_ContextMenuSource
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* MainMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* BeamMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_CameraScalingComponent* CameraScalingBeamEndMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* BeamEndMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UVR_TraceComponent* VRTrace;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UVR_WidgetInteractionComponent* WidgetInteraction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor DefaultBeamColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<TEnumAsByte<ECollisionChannel>, FLinearColor> CollisionChannelToBeamColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> WorldUICollisionChannel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> InteractionCollisionChannel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UObject>> ContextOptionClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TSubclassOf<UUserWidget> ContextMenuClass;

	/* When tool is removed from input stack, if no other tool of same class exists, then close this user widget */
	UPROPERTY()
	UUserWidget* DefaultOptionsUserWidget;

protected:
	UPROPERTY()
	UMaterialInstanceDynamic* BeamMaterial;

	UPROPERTY(ReplicatedUsing = OnRep_BeamColor)
	FLinearColor BeamColor;

	/* if true, replicates beam color and beam transform from owning client to server, than down to all other clients */
	bool bReplicateBeam;

private:
	bool bActionModifier;

	bool bInteract;

	UPROPERTY()
	TSet<UPrimitiveComponent*> ClickedComponents;

	ECollisionChannel GizmoCollisionChannel;

	ECollisionChannel KeyboardCollisionChannel;

	ECollisionChannel ContextMenuCollisionChannel;

	EPanningState PanningState;

	FVector PreviousPanningLocation;
	
	UPROPERTY()
	AActor* HoveredActor;

	UPROPERTY()
	UPrimitiveComponent* HoveredComponent;

	FWeakWidgetPath LastWidgetPath;

	FDateTime TimeOfLastClick;

	bool bModalPopupOpen;

	UPROPERTY()
	AActor* ModalPopupWorldUIActor;

	FVector InitialRelativeBeamScale;

	UPROPERTY(ReplicatedUsing = OnRep_OwnerHardwareInterfaceMode)
	EHardwareInterfaceMode OwnerHardwareInterfaceMode;

	FLinearColor LastRPCBeamColor;

	double UpdateTraceStartEndMUC;
	bool bSkipEarthPan;

	bool bShowRibbonAfterPan;

	UPROPERTY()
	AActor* DraggedWorldUIActor;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Tool(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UFUNCTION()
	void OnRep_OwnerHardwareInterfaceMode();

	UFUNCTION(Server, Reliable)
	void Server_SetBeamColor(const FLinearColor& color);

	UFUNCTION()
	void OnRep_BeamColor();

	UFUNCTION(Server, Reliable)
	void Server_SyncToToolVisualization(const FSpatialiteResult_BP& result);

	UFUNCTION(Server, Reliable)
	void Server_SetOwnerHardwareInterfaceMode(EHardwareInterfaceMode hardwareInterfaceMode);


	// ---------------------------------
	// --- Interface_VR_Tool
	// ---------------------------------

public:
	virtual void AddedToInputToolStack_Implementation(UVR_MotionControllerComponent* motionControllerComponent) override;

	virtual void RemovedFromInputToolStack_Implementation(UVR_MotionControllerComponent* motionControllerComponent) override;

	virtual void InputToolStackIndexChanged_Implementation(UVR_MotionControllerComponent* motionControllerComponent, int32 index) override;

	virtual void ActionInput_Implementation(const FInputActionInstance& inputActionInstance) override;

	virtual bool GetRelativeTransformForNonVRPositioning_Implementation(FTransform& transform) const override;
	

	// ---------------------------------
	// --- Interface_UI_ContextMenuSource
	// ---------------------------------

public:
	virtual void GetContextOptionClasses_Implementation(TSet<TSubclassOf<UObject>>& contextOptionClasses) override;

	virtual void GetContextMenuClass_Implementation(TSubclassOf<UUserWidget>& contextMenuClass) override;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void OnRep_Owner() override;

	virtual void Tick(float deltaSeconds) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetBeamColor(const FLinearColor& color);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTriggerReleased();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveActionInput(const FString& action, EInputEvent inputEvent);

	UFUNCTION(BlueprintPure)
	bool GetInteractionHitLocation(FVector& dragLocation) const;

	UFUNCTION(BlueprintPure)
	bool GetWorldUIHitLocation(FVector& dragLocation) const;

	bool GetTerrainHitLocation(FVector& hitLocation) const;

	void AddTraceIgnoredActor(AActor* actor);

	void RemoveTraceIgnoredActor(AActor* actor);

	bool StartDraggingWorldUI(UUserWidget* userWidget, AActor* worldUIActor);

	void StopDraggingWorldUI(UUserWidget* userWidget, AActor* worldUIActor);

	bool GetInteractionHitResults(TArray<FHitResult>& hitResults) const;
	
	UFUNCTION(BlueprintPure)
	bool IsHoveringOverUserWidget(const UUserWidget* userWidget) const;

	UFUNCTION(BlueprintPure)
	AActor* GetHoveredActor() const;

	UFUNCTION(BlueprintPure)
	UPrimitiveComponent* GetHoveredComponent() const;

	FDateTime GetTimeOfLastClick() const;

	void SetModalPopupOpen(bool bOpen, AActor* worldUIActor);

	/* returns true if the input for DragPan is pressed */
	UFUNCTION(BlueprintPure)
	bool GetActionModifierPressed() const;

	/* returns true if the input for Interact is pressed */
	bool GetInteract() const;

	UFUNCTION(BlueprintCallable)
	void AddClickedComponent(UPrimitiveComponent* component);

	void LoadCurrentToolVisualConfiguration();

	bool IsDraggingWorldUI() const;

	bool IsPanning() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	bool IsLocallyOwned() const;

	bool ImplementsContextMenu(AActor* actor) const;

	virtual void PostTriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults);

	virtual void PostTriggerReleased();

	virtual void PostTickUpdateBeam(float deltaSeconds);

	virtual void PostActionInput(const FInputActionInstance& inputActionInstance);

	virtual void PostTriggerActionPressed();

	void TriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults);

	virtual void TickUpdateBeam(float deltaSeconds);

	virtual void TickNonOwningBeamUpdate();

private:
	bool ShouldUpdateBeam();

	bool CheckInputBlocked();

	void TriggerReleased();

	void TickUpdatePanning(float deltaSeconds);

	bool IsHoveringOverTerrain() const;

	FVector GetPanDelta();

	// returns true if pan is requested
	bool CheckForPanningInput(const FInputActionInstance& inputActionInstance);

	bool IsKeyboardOpen() const;

	void SyncToToolVisualization(const SpatialiteResult& result);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleBoolSettingStored(const FString& settingName, bool bValue);

	UFUNCTION()
	void HandleDoubleSettingStored(const FString& settingName, double value);

	UFUNCTION()
	void HandleStringSettingStored(const FString& settingName, const FString& value);

	UFUNCTION()
	void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);

	UFUNCTION()
	void HandlePanningPlayerStateUpdated(APlayerState* playerState);

	UFUNCTION()
	void HandleKeyboardSpawnDestroy(bool bSpawn, AActor* keyboardContainer);

	UFUNCTION()
	void HandleOwnerDisconnected(AActor* owningActor);

	UFUNCTION()
	void PeriodicBeamUpdateForRPCs();

	void HandleGlobeZoom(const FInputActionValue& inputActionValue);
};