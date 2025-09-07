#pragma once

// Parent Includes
#include "GameFramework/Pawn.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"
#include "Developer_Subsystem_Core.h"

// Generated Includes
#include "Game_Pawn.generated.h"

class APlayerState;
class UVR_CoreComponent;
class UGame_MovementComponent;
class UGame_MotionControllerComponent;
class UGame_WidgetComponent_FTUE;
class UCapsuleComponent;
class UWidgetComponent;
class AGame_Tool;
class UGame_CameraScalingComponent;
class AVH_GlobeReferenceActor;
class UGame_CameraComponent;
class UGame_PresentationMode_ReplicatedWindowComponent;

UCLASS()
class GAME_API AGame_Pawn : public APawn
{
    GENERATED_BODY()


	// ---------------------------------
    // --- Constructors
    // ---------------------------------

public:
	AGame_Pawn();


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_DELEGATE_TwoParams(FAddPlaybackEventLocation, const AGame_Pawn*, const FGeodeticCoord3D&);

	DECLARE_DELEGATE_TwoParams(FAddPlaybackEventHead, const AGame_Pawn*, const FRotator&);

	DECLARE_DELEGATE_ThreeParams(FAddPlaybackEventController, const AGame_Pawn*, const FString&, const FTransform&);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerStateUpdated, APlayerState*, newPlayerState, APlayerState*, oldPlayerState);


    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USceneComponent* CameraScene;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_CameraComponent* Camera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_MovementComponent* VRMovement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_MotionControllerComponent* LeftController;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_MotionControllerComponent* RightController;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_WidgetComponent_FTUE* FTUEWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_CameraScalingComponent* CameraScalingHead;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* Head;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_CameraScalingComponent* CameraScalingCallsign;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWidgetComponent* Callsign;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_PresentationMode_ReplicatedWindowComponent* PresentationComponent;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DespatializeVOIP)
	bool bDespatializeVOIP;

	TArray<FAddPlaybackEventLocation> PlaybackEventLambdasLocation;

	TArray<FAddPlaybackEventHead> PlaybackEventLambdasHead;

	TArray<FAddPlaybackEventController> PlaybackEventLambdasController;

	UPROPERTY(BlueprintAssignable, Category="PlayerState")
	FOnPlayerStateUpdated OnPlayerStateUpdated;

	/* set CameraComponent's owner to this relative location when entering desktop and VREmulation mode */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector DesktopRelativeCamera;

	/* set CameraComponent's owner to this relative location when entering VR mode */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector VRRelativeCamera;

	/* replicates pawn's geolocation when true */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bReplicateGeoLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> DesktopHUDClass;

private:
	UPROPERTY(ReplicatedUsing = OnRep_PawnRotation)
	FRotator PawnRotation;

	UPROPERTY(ReplicatedUsing = OnRep_PlayerCoordinate)
	FGeodeticCoord3D PlayerCoordinate;

	UPROPERTY(ReplicatedUsing = OnRep_HeadTransform)
	FTransform HeadTransform;

	UPROPERTY(ReplicatedUsing = OnRep_CameraSceneRelativeLocation)
	FVector CameraSceneRelativeLocation;

	double CachedMaxSpeedWorld;

	bool bUpdateCameraTransform;

	bool bStartAtLastLocation;


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetVOIPSpatialization(bool isSpatialized);

	UFUNCTION()
	virtual void OnRep_DespatializeVOIP();

private:
	UFUNCTION(Server, Reliable)
	void Server_SetPlayerCoordinate(const FGeodeticCoord3D& coordinate);

	UFUNCTION(Server, Reliable)
	void Server_SetPawnRotation(const FRotator& inPawnRotation);

	UFUNCTION(Server, Reliable)
	void Server_SetHeadTransform(const FTransform& headTransformArg);

	UFUNCTION(Server, Reliable)
	void Server_SetCameraSceneRelativeLocation(const FVector& relativeLocation);

	UFUNCTION()
	void OnRep_PlayerCoordinate();

	UFUNCTION()
	void OnRep_PawnRotation();

	UFUNCTION()
	void OnRep_HeadTransform();

	UFUNCTION()
	void OnRep_CameraSceneRelativeLocation();
	

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static FVector GetCameraSceneRelativeLocation();


    // ---------------------------------
    // --- Inherited
    // ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void Tick(float deltaSeconds) override;

	virtual void OnPlayerStateChanged(APlayerState* NewPlayerState, APlayerState* OldPlayerState) override;
	

	// ---------------------------------
    // --- API
    // ---------------------------------

public:
	void ToggleGlobeTransform();

	UFUNCTION(BlueprintCallable)
	void SetTopdownMode(bool bTopdown);

	UFUNCTION(BlueprintPure)
	FGeodeticCoord3D GetPlayerCoordinate() const;

	virtual void UpdateVoipSpatialized();

	UFUNCTION(BLueprintImplementableEvent)
	void OnVoipSpatializationUpdated(bool isSpatialized);

	UFUNCTION(BlueprintCallable)
	void SetVoipSpatialized(bool isSpatialized);

	UFUNCTION(BlueprintCallable)
	void TeleportToCoordinate(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintCallable)
	void StartDraggingWorldUI(UUserWidget* userWidget);

	UFUNCTION(BlueprintCallable)
	void StopDraggingWorldUI(UUserWidget* userWidget);

	bool IsDraggingWorldUI() const;

	UFUNCTION(BlueprintPure)
	UVR_MotionControllerComponent* GetMotionControllerForTool(AActor* tool) const;

	UFUNCTION(BlueprintPure)
	UVR_MotionControllerComponent* GetMotionControllerLastClickedOnWidget(const UUserWidget* userWidget) const;

	void SetModalPopupOpen(bool bOpen, AActor* worldUIActor);

	bool IsToolClassOnTopOfStack(TSubclassOf<AGame_Tool> toolClass) const;

	UFUNCTION(BlueprintCallable)
	void LoadCurrentToolVisualConfiguration();

	bool IsPanning() const;

	// todo ohg | move this to native
	UFUNCTION(BlueprintImplementableEvent)
	void RotateToBearing(float bearing);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCallsign(const FString& callsignArg);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCollaborationColor(const FLinearColor& collaborationColorArg);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetIsInTOC(bool bIsInTOC);

	UFUNCTION(BlueprintNativeEvent)
	void ReceivePlayerStateAssigned(APlayerState* newPlayerState);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveCullMaterialsForTOC(bool bCull);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void UpdateVisualsForTOCStatus(bool bIsInTOC);

	virtual void UpdateCallsignLocation();

private:
	void SetupPlayerState();

	void SetWorldLocationFromCoordinate(const FGeodeticCoord3D& coordinate);

	void AddSessionPlaybackLocationEvent() const;

	void AddSessionPlaybackHeadEvent() const;

	void AddSessionPlaybackControllerOffsetEvent(const FString& controllerName, const FTransform& controllerRelativeTransform) const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);

	UFUNCTION()
	void HandleMovementTypeChanged(EMovementType movementType);

	UFUNCTION()
	void HandleCallsignUpdated(const FString& callsignArg, FLinearColor collaborationColorArg);

	UFUNCTION()
	void HandleIsInTOCUpdated(bool bIsInTOC);

	UFUNCTION()
	void PeriodicUpdateNonLocalPosition();

	UFUNCTION()
	void PeriodicUpdateInitialLocation();

	UFUNCTION()
	void PeriodicUpdatePlayerCoordinate();

	UFUNCTION()
	void HandleBoolSettingStored(const FString& setting, bool bValue);

	UFUNCTION()
	void LatentSetCamera();
};
