#pragma once

#include "VH_GeodeticCoord.h"
#include "Interface_DataChannelManager.h"

#include "Components/AudioComponent.h"
#include "Net/VoiceConfig.h"

#include "Game_EntityDB.h"
#include "Game_PlayerState.generated.h"


class AGame_Pawn;
class AGame_GameState;
class UGame_MUCComponent;
class UGame_MUCComponent_Database;
class UGame_MUCComponent_File;

UCLASS()
class GAME_API AGame_PlayerState : public APlayerState, public IInterface_DataChannelManager
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCallsignUpdated, const FString&, callsign, const FLinearColor, color);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMuteStatusUpdated, bool, selfMuted, bool, forceMuted);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGlobeReferenceScale3DUpdated, const FVector&, scale3D);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIsInTOCUpdated, bool, isInTOC);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FServerDatabaseReady);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTalkingStatusChanged, bool, isTalking);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FCallsignUpdated OnCallsignUpdated;

	UPROPERTY(BlueprintAssignable)
	FGlobeReferenceScale3DUpdated OnGlobeReferenceScale3DUpdated;

	UPROPERTY(BlueprintAssignable)
	FIsInTOCUpdated OnIsInTOCUpdated;

	UPROPERTY(BlueprintAssignable)
	FMuteStatusUpdated OnMuteStatusUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnTalkingStatusChanged OnTalkingStatusChanged;

	UPROPERTY(BlueprintReadOnly)
	AGame_Pawn* OwningPawn;

	UPROPERTY()
	UVOIPTalker* Talker;

	UPROPERTY()
	USynthComponent* PlayingSynthComp;

	/** Cache this for simplicity */
	bool bVoipSpatialized;

	/** Voip Settings to use for player when in Spatialized Mode */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USoundAttenuation* AttenuationSettingsSpatialized;

	/** Voip Settings to use for player when in non-spatialized Mode */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USoundAttenuation* AttenuationSettingsNotSpatialized;

	UPROPERTY(BlueprintAssignable)
	FServerDatabaseReady OnServerDatabaseReady;

	bool bReplicateMUCUpdates;

protected:
	/** Whether or not this player has muted their own voice **/
	UPROPERTY(ReplicatedUsing = OnRep_SelfMuted)
	bool bSelfMuted;

	/** Whether or not this player has been muted by the host**/
	UPROPERTY(ReplicatedUsing = OnRep_ForceMuted)
	bool bForceMuted;

private:
	UPROPERTY(ReplicatedUsing = OnRep_Callsign)
	FString Callsign;

	UPROPERTY(ReplicatedUsing = OnRep_CollaborationColor)
	FLinearColor CollaborationColor;

	UPROPERTY(ReplicatedUsing = OnRep_GlobeReferenceScale3D)
	FVector GlobeReferenceScale3D;

	UPROPERTY(ReplicatedUsing = OnRep_IsInTOC)
	bool bIsInTOC;

	UPROPERTY(ReplicatedUsing = OnRep_MUCComponent_Database)
	UGame_MUCComponent_Database* MUCComponent_Database;

	UPROPERTY(ReplicatedUsing = OnRep_MUCComponent_File)
	UGame_MUCComponent_File* MUCComponent_File;

	UPROPERTY(ReplicatedUsing = OnRep_Talking)
	bool bTalking;

	bool bMUCServerDBReceived;

	UPROPERTY()
	AGame_GameState* GameState;

	// This map will only live on the server and provides suffixes as integer values for generating unique callsigns


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_PlayerState();


	// ---------------------------------
	// --- Replication
	// ---------------------------------
public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_SetCallsign(const FString& inCallsign);
	
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_SetCollaborationColor(const FLinearColor inCollaborationColor);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_SetGlobeReferenceScale3D(const FVector& scale3D);

	UFUNCTION(Server, Reliable)
	void Server_SetIsInTOC(bool isInTOC);

	UFUNCTION(Server, Reliable)
	void Server_SetMuteStatus(bool inSelfMuted, bool inForceMuted = false);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_AttemptBeginDragPan();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_AttemptEndDragPan();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_SetAsPresenter();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_StopPresenting();
	
private:
	UFUNCTION()
	void OnRep_Callsign();
	
	UFUNCTION()
	void OnRep_CollaborationColor();

	UFUNCTION()
	void OnRep_GlobeReferenceScale3D();

	UFUNCTION()
	void OnRep_IsInTOC();

	UFUNCTION()
	void OnRep_SelfMuted();

	UFUNCTION()
	void OnRep_ForceMuted();

	UFUNCTION()
	void OnRep_MUCComponent_Database();

	UFUNCTION()
	void OnRep_MUCComponent_File();

	UFUNCTION()	
	void OnRep_Talking();


	// ---------------------------------
	// --- Interface_DataChannelManager
	// ---------------------------------

public:
	virtual UVH_DataChannelManager* GetDCM(int32 id) override;

	virtual bool GetChannelReady(int32 id) override;

	virtual void SetChannelReady(int32 id, bool bReady) override;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void BeginDestroy() override;

	virtual void OnReactivated() override;


	// ---------------------------------
    // --- API
    // ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	bool GetIsTalking() const;

	UFUNCTION()
	USoundAttenuation* GetAttenuationSettings();

	UFUNCTION(BlueprintPure)
	FString GetCallsign() const;
	
	UFUNCTION(BlueprintPure)
	FLinearColor GetCollaborationColor() const;

	UFUNCTION(BlueprintPure)
	FVector GetGlobeReferenceScale3D() const;

	UFUNCTION(BlueprintPure)
	bool GetIsInTOC() const;

	UFUNCTION(BlueprintCallable)
	void SetIsInTOC(bool isInTOC);

	UFUNCTION(BlueprintPure)
	UVOIPTalker* GetTalker() { return Talker; };

	UFUNCTION(BlueprintCallable)
	bool IsSelfMuted() { return bSelfMuted; }

	UFUNCTION(BlueprintCallable)
	bool IsForceMuted() { return bForceMuted; }

	// to be removed when TAKSettingsMenu blueprint is available
	UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage = "Call Server_SetCallsign instead"))
	void SetCallsign(const FString& inCallsign) { Server_SetCallsign(inCallsign); }

	UFUNCTION()
	void SetOwningPawn(AGame_Pawn* newOwningPawn);

	UFUNCTION()
	void SetMuteStatus(bool inSelfMuted = true, bool inForceMuted = false);

	/** Even though we can set the talker settings, we may need to change settings mid-speech so we need to maintain a handle to the synth component playing the audio */
	UFUNCTION()
	void SetPlayingSynthComp(USynthComponent* inSynthComp);

	UFUNCTION()
	void UpdateVoipSpatialized(bool isSpatialized);

	void SetMUCServerDBReceived(bool bReceived);

	bool IsMUCServerDBReceived() const;

	void SendDBDeleteToClients(const FSpatialiteResults_BP& results);

	UFUNCTION(BlueprintPure)
	UGame_MUCComponent* GetMUCComponentFromID(int32 id) const;

	UFUNCTION(BlueprintCallable)
	bool SendEntitiesToClient(APlayerController* playerController, const TArray<FString>& entityUIDs);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	UFUNCTION()
	void SendEntitiesToClientTimer(AGame_PlayerController* playerController, const FString& entities);

	void CreateMUCComponents();

	void FindGameState();

	UFUNCTION()
	void UpdateCallsignFromCOTManager();

	UFUNCTION()
	void UpdateCollaborationColor();

	UFUNCTION(Reliable, Server)
	void ServerSetChannelReady(int32 id, bool bReady);

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void SendDBUpdateToClients(const FSpatialiteResults_BP& results);

	void HandlePlayerTalkingStateChanged(FUniqueNetIdRef talkerID, bool bIsTalking);
};
