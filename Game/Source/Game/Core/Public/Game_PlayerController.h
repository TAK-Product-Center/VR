#pragma once

// Parent Includes
#include "VH_PlayerController_Replication.h"

// Engine Includes
#include "Online.h"
#include "Interfaces/VoiceInterface.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "InputActionValue.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_PlayerController.generated.h"

class AGame_Mark;
class UDeveloper_TaskScheduler;
class AGame_VirtualObjective;
class UVH_DataChannelManager;
class UGame_MUCComponent;
class AGame_Tool;
class UInputAction;

UCLASS()
class GAME_API AGame_PlayerController : public AVH_PlayerController_Replication
{
    GENERATED_BODY()

	
	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseCaptureModeChanged, EMouseCaptureMode, mouseCaptureMode);

	UPROPERTY(BlueprintAssignable)
	FMouseCaptureModeChanged OnMouseCaptureModeChanged;


    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
	/* True if we are set to always broadcast without requiring a key press */
	UPROPERTY(BlueprintReadWrite)
	bool bAlwaysBroadcast;

	/* True if we will broadcast our voice if we were to speak */
	UPROPERTY(BlueprintReadWrite)
	bool bBroadcastOn;

	/* True if we are currently broadcasting our voice */
	UPROPERTY(BlueprintReadWrite)
	bool bBroadcastingVoice;

	UPROPERTY(ReplicatedUsing = OnRep_ForceLeaveSession)
	bool bForceLeaveSession;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float QuickturnSpeed;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UInputAction* ToggleMouseLookInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* LookInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* QuickturnInputAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double QuickturnCooldown;

private:
	UPROPERTY()
	UDeveloper_TaskScheduler* MeshBuilder;

	UPROPERTY()
	UDeveloper_TaskScheduler* MeshLoader;

	UPROPERTY()
	UDeveloper_TaskScheduler* TerrainTileBuilder;

	UPROPERTY()
	AGame_Mark* RedX;

	FString RedXEntityUID;

	/* VO that player is currently interacting */
	UPROPERTY()
	AGame_VirtualObjective* ActiveVO;

	UPROPERTY(ReplicatedUsing = OnRep_ForceMuted)
	bool bForceMute;

	FVector2D MousePositionAtCapture;

	bool bMousePositionAtCaptureSet;

	double LastQuickturn;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_PlayerController(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PawnLeavingGame() override;

	UFUNCTION(BlueprintImplementableEvent)
	void ReceivePawnLeavingGame();

	/* forces player to be muted; should only be called from server */
	UFUNCTION(BlueprintCallable)
	void SetForceMute(bool shouldForceMute);

	UFUNCTION(Server, Reliable)
	void Server_VOSetScale3D(AGame_VirtualObjective* virtualObjective, const FVector& scale3D);

	UFUNCTION(Server, Reliable)
	void Server_VOSetReplicatedScale3D(AGame_VirtualObjective* virtualObjective, const FVector& scale3D);

	UFUNCTION(Server, Reliable)
	void Server_TOCSetReplicatedPosition(AGame_VirtualObjective* virtualObjective, const FGeodeticCoord3D& coordinate);

	UFUNCTION(Server, Reliable)
	void Server_SetCoord(AGame_VirtualObjective* virtualObjective, const FGeodeticCoord3D& coordinate);

	UFUNCTION(Client, Reliable)
	void Client_ConsoleCommand(const FString& consoleCommand);

	UFUNCTION(Client, Reliable)
	void Client_TeleportAndOrientPlayer(const FGeodeticCoord3D& coordinate, float bearing);

	UFUNCTION()
	void OnRep_ForceLeaveSession();

	UFUNCTION()
	void OnRep_ForceMuted();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	static AGame_VirtualObjective* GetPlayerActiveVO();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	/*
	* Tell the client to enable or disable voice chat (not muting)
	* @param bEnable enable or disable voice chat
	*/
	virtual void ClientEnableNetworkVoice_Implementation(bool bEnable) override;

	/*
	* Toggle voice chat on and off.  Local player will not broadcast voice while off.
	* @param bSpeaking enable or disable voice chat
	*/
	virtual void ToggleSpeaking(bool bInSpeaking) override;

	UFUNCTION(BlueprintCallable, Category="Game|PlayerController|VOIP", meta=(DisplayName="Toggle Speaking"))
	virtual void K2_ToggleSpeaking(bool inSpeaking) { ToggleSpeaking(inSpeaking); }

	/* Allows the PlayerController to set up custom input bindings. */
	virtual void SetupInputComponent() override;

	virtual bool GetHitResultAtScreenPosition(const FVector2D screenPosition, const ECollisionChannel traceChannel, const FCollisionQueryParams& collisionQueryParams, FHitResult& hitResult) const override;
	
	virtual bool GetHitResultAtScreenPosition(const FVector2D screenPosition, const TArray<TEnumAsByte<EObjectTypeQuery>>& objectTypes, bool bTraceComplex, FHitResult& hitResult) const override;
	
	virtual void OnRep_PlayerState() override;

	virtual void CleanupPlayerState() override;

	virtual void InitPlayerState() override;
    

	// ---------------------------------
    // --- API
    // ---------------------------------

public:
	/*
	 *	@brief:		This function returns the mesh builder task scheduler. The mesh builder is used for building the meshes of imported
	 *				models and data sets. The mesh builder will create the geometry seen on the model.
	 * 
	 *				If a mesh builder task scheduler has not been created, this getter will create a task scheduler and initialize it
	 *				with the proper Max Concurrent Mesh Builders default settings in game settings and 0.1 checks per second.
	 * 
	 * @return:		This function will return the UVH_TaskScheduler that is being used or was created as of calling the function.
	 * 
	 * @warning:	If the Max Concurrent Mesh Builders default setting is 0 or is set to 0, mesh building will not work in VTAK.
	 */
	UFUNCTION(BlueprintPure)
	UDeveloper_TaskScheduler* GetMeshBuilder();

	UFUNCTION(BlueprintPure)
	UDeveloper_TaskScheduler* GetMeshLoader();

	UFUNCTION(BlueprintPure)
	UDeveloper_TaskScheduler* GetTerrainTileBuilder();

	UFUNCTION(BlueprintPure)
	AGame_Mark* GetRedX(FString& outEntityUID) const;

	UFUNCTION(BlueprintCallable)
	void SetRedX(AGame_Mark* inRedX);

	UFUNCTION(BlueprintCallable)
	void SetRedXEntityUID(const FString& entityUID);

	UFUNCTION(BlueprintCallable)
	void SetActiveVO(AGame_VirtualObjective* virtualObjective);

	UFUNCTION(BlueprintPure)
	AGame_VirtualObjective* GetActiveVO() const;
	
	int32 GetTotalTasks() const;

	UFUNCTION(BlueprintNativeEvent)
	void ReceivePlayerStateAssigned(APlayerState* newPlayerState);
	
	UFUNCTION(BlueprintCallable)
	void SetMouseMode(EMouseCaptureMode mouseCaptureMode);

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void RequestSpeakingChangedCallback();

	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	/* called when the player controller begins or stops sending data through VOIP */
	virtual void HandleTalkStatusChanged(TSharedRef<const FUniqueNetId> talkerID, bool isTalking);

	UFUNCTION()
	void HandleNetworkFailure(UWorld* world, UNetDriver* netDriver, ENetworkFailure::Type failureType, const FString& errorString);

	/*
	 *	@brief:		This function handles whenever the MaxConcurrentMeshBuilders setting is changed. That way, this class can 
	 *				change the max number of concurrent mesh builders on the MeshBuilder task scheduler whenever it is changed
	 *				in the VTAK advanced settings.
	 */
	UFUNCTION()
	void HandleIntSettingChanged(const FString& settingName, const int32 value);

	void HandleToggleMouseMode();

	void HandleLook(const FInputActionValue& value);

	void HandleVRQuickturn(const FInputActionValue& value);

	void HandleVRQuickturnReset(const FInputActionValue& value);
	

	// ---------------------------------
	// --- Debug/Testing
	// ---------------------------------

public:
	UFUNCTION(exec)
	void QA_InterpPoints(const FString& startLon, const FString& startLat, const FString& startAlt, const FString& endLon, const FString& endLat, const FString& endAlt, float interpDistMeters, bool bUseConstDist = false);

	UFUNCTION(exec)
	void QA_GetEndPoint(const FString& startLon, const FString& startLat, const FString& startAlt, const FString& bearing, const FString& distanceMeters);

	UFUNCTION(exec)
	void QA_GetFileFromServer(const FString& fullPathToFile);

	UFUNCTION(exec)
	void QA_VOTriggerUpdateGlobal();

	UFUNCTION(exec)
	void QA_SetMaxConcurrentMeshLoads(int32 maxNumber);

	UFUNCTION(exec)
	void QA_SetViewDistance(float viewDistance);

	UFUNCTION(exec)
	void QA_PageOutEntity(const FString& entityUID);

	UFUNCTION(exec)
	void QA_Doit(int32 intParam, bool bParam);

	UFUNCTION(exec)
	void QA_SetEntityDatabase(const FString& path, const FString& filename);

	UFUNCTION(exec)
	void QA_SetUIScale(float scale);
};
