#pragma once

// Parent Includes
#include "VR_MovementComponent.h"

// Engine Includes
#include "InputActionValue.h"
#include "InputTriggers.h"

// Generated Includes
#include "Game_MovementComponent.generated.h"

class UGame_Operation_Drag_Teleport;
class AGame_Tool;
class AGame_TOCTable;
class UInputAction;
class UVR_MotionControllerComponent;
class UInputMappingContext;


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Walk,
	Fly,
	Globe,
	Teleport,
	None  // stops movement
};

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MovementComponent : public UVR_MovementComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMovementTypeChanged, EMovementType, movementType);

	DECLARE_DYNAMIC_DELEGATE_RetVal(FTransform, FOverrideMovementTransform);

public:
	UPROPERTY(BlueprintAssignable)
	FMovementTypeChanged OnMovementTypeChanged;


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MinSpeedTOC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MaxSpeedTOC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MinSpeedENU;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MaxSpeedENU;

	// used when database slider at 0
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MinSpeedEllipsoid0;

	// used when database slider at 0
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MaxSpeedEllipsoid0;

	// used when database slider at 1
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MinSpeedEllipsoid1;

	// used when database slider at 1
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MaxSpeedEllipsoid1;

	/// @brief Max multiplier allowed from database; effects max slider value in settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double MaxSettingsMovementMultiplier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> TeleportPreviewClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_Operation_Drag_Teleport> DragTeleportOperationClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> TOCTeleportCollisionChannel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double TeleportZOffset;
	
	UPROPERTY(EditDefaultsOnly)
	bool bHandleIsInTOCUpdates;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* WalkMoveInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* FlyMoveInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* FlyElevationInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* TeleportInitiateLeftInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* TeleportFinalizeLeftInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* TeleportInitiateRightInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* TeleportFinalizeRightInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (IsBindableEvent = "true"))
	FOverrideMovementTransform OnOverrideMovementTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MovementInputMapPriority;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputMappingContext* TOCInputMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputMappingContext* WorldInputMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EMovementType, UInputMappingContext*> MovementInputMaps;

private:
	TSet<EMovementType> RestrictedMovementTypes;

	double SettingsMovementMultiplier;

	EMovementType MovementType;

	UPROPERTY()
	UGame_Operation_Drag_Teleport* DragTeleportOperation;

	UPROPERTY()
	AActor* TeleportPreviewActor;

	UPROPERTY()
	UVR_MotionControllerComponent* TeleportingController;

	UPROPERTY()
	mutable AGame_TOCTable* TOCTable;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MovementComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void PostSetWorldTransformOverride(const FTransform& worldTransformOverride) override;

	virtual FVector GetGravityOverride() const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetMovementType(EMovementType newMovementType);

	UFUNCTION(BlueprintPure)
	EMovementType GetMovementType() const;

	UFUNCTION(BlueprintCallable)
	void SetRestrictedMovementTypes(const TSet<EMovementType>& restrictedMovementTypes);

	UFUNCTION(BlueprintCallable)
	void SetSettingMovementMultiplier(double movementMultiplier);

	UFUNCTION(BlueprintCallable)
	double GetSettingMovementMultiplier();

	/* sets SettingMovementMultiplier to database value */
	UFUNCTION(BlueprintCallable)
	void ResetSettingMovementMultiplier();

	UFUNCTION(BlueprintCallable)
	void SetAllowMovement(bool bAllowMovement);

	void ResetMaxSpeed();

	bool GetTeleportDragLocation(AGame_Tool* teleportingTool, FVector& dragLocation) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void BindToPlayerState();

	void BindInputActions();

	AGame_TOCTable* GetTOCTable() const;

	void InternalMove(const FVector& localDirection);

	void TeleportInitiate(UVR_MotionControllerComponent* requestingController);

	void TeleportFinalize(UVR_MotionControllerComponent* requestingController);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleDoubleSettingStored(const FString& settingName, double value);

	UFUNCTION()
	void HandleIsInTOCUpdated(bool bIsInTOC);

	void HandleWalkMove(const FInputActionValue& inputActionValue);
	
	void HandleFlyMove(const FInputActionValue& inputActionValue);

	void HandleFlyElevation(const FInputActionValue& inputActionValue);

	void HandleTeleportLeftInitiate();

	void HandleTeleportLeftFinalize();

	void HandleTeleportRightInitiate();

	void HandleTeleportRightFinalize();
};