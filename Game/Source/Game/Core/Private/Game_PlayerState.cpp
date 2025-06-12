// Required Includes
#include "Game_PlayerState.h"
#include "Game.h"

// Engine Includes
#include "Net/UnrealNetwork.h"

// VH Plugin Includes
#include "VH_COTManager.h"
#include "VH_DataChannelManager.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Developer_Statics.h"
#include "Game_Component_Talker.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_PlayerController.h"
#include "Game_EntityDB.h"
#include "Game_MUCComponent.h"
#include "Game_MUCComponent_Database.h"
#include "Game_MUCComponent_File.h"
#include "Game_GameState.h"
#include "Game_Subsystem_Core.h"
#include "Game_GameMode.h"
#include "Game_Subsystem_Ribbon.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_PlayerState::AGame_PlayerState() :
	bVoipSpatialized(true),
	bReplicateMUCUpdates(true),
	bIsInTOC(true),
	GameState(nullptr)
{

}

// ---------------------------------
// --- Replication
// ---------------------------------

void AGame_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGame_PlayerState, Callsign);
	DOREPLIFETIME(AGame_PlayerState, CollaborationColor);
	DOREPLIFETIME(AGame_PlayerState, GlobeReferenceScale3D);
	DOREPLIFETIME(AGame_PlayerState, bIsInTOC);
	DOREPLIFETIME(AGame_PlayerState, bSelfMuted);
	DOREPLIFETIME(AGame_PlayerState, bForceMuted);
	DOREPLIFETIME(AGame_PlayerState, MUCComponent_Database);
	DOREPLIFETIME(AGame_PlayerState, MUCComponent_File);
	DOREPLIFETIME(AGame_PlayerState, bTalking);
}

void AGame_PlayerState::Server_SetCallsign_Implementation(const FString& inCallsign)
{
	FString callsign = inCallsign;

	if(GameState == nullptr)
	{
		FindGameState();
	}

	// Check for duplicate callsigns
	if(GameState->PlayerCallsignExists(this, inCallsign))
	{
		callsign = GameState->GenerateUniqueCallsign(inCallsign);
	}

	if (!Callsign.Equals(callsign))
	{
		Callsign = callsign;

		OnCallsignUpdated.Broadcast(Callsign, CollaborationColor);
	}
}

void AGame_PlayerState::Server_SetCollaborationColor_Implementation(const FLinearColor inCollaborationColor)
{
	if (!FMath::IsNearlyEqual(CollaborationColor.A, inCollaborationColor.A)
		|| !FMath::IsNearlyEqual(CollaborationColor.R, inCollaborationColor.R)
		|| !FMath::IsNearlyEqual(CollaborationColor.G, inCollaborationColor.G)
		|| !FMath::IsNearlyEqual(CollaborationColor.B, inCollaborationColor.B))//!CallsignColor.Equals(inCallsign))
	{
		CollaborationColor = inCollaborationColor;

		OnCallsignUpdated.Broadcast(Callsign, CollaborationColor);
	}
}

void AGame_PlayerState::Server_SetGlobeReferenceScale3D_Implementation(const FVector& scale3D)
{
	GlobeReferenceScale3D = scale3D;

	OnGlobeReferenceScale3DUpdated.Broadcast(GlobeReferenceScale3D);
}

void AGame_PlayerState::Server_SetIsInTOC_Implementation(bool isInTOC)
{
	if (isInTOC != bIsInTOC)
	{
		bIsInTOC = isInTOC;

		OnIsInTOCUpdated.Broadcast(bIsInTOC);

		Server_AttemptEndDragPan();
	}
}

void AGame_PlayerState::Server_SetMuteStatus_Implementation(bool inSelfMuted, bool inForceMuted /*= false*/)
{
	SetMuteStatus(inSelfMuted, inForceMuted);
	OnMuteStatusUpdated.Broadcast(inSelfMuted, inForceMuted);
}

void AGame_PlayerState::Server_AttemptBeginDragPan_Implementation()
{
	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		gameState->AttemptBeginDragPan(this);
	}
}

void AGame_PlayerState::Server_AttemptEndDragPan_Implementation()
{
	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		gameState->AttemptEndDragPan(this);
	}
}

void AGame_PlayerState::Server_SetAsPresenter_Implementation()
{
	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		gameState->SetPresentingPlayerState(this);
	}
}

void AGame_PlayerState::Server_StopPresenting_Implementation()
{
	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		gameState->SetPresentingPlayerState(nullptr);
	}
}

void AGame_PlayerState::OnRep_Callsign()
{
	OnCallsignUpdated.Broadcast(Callsign, CollaborationColor);
}

void AGame_PlayerState::OnRep_CollaborationColor()
{
	OnCallsignUpdated.Broadcast(Callsign, CollaborationColor);
}

void AGame_PlayerState::OnRep_GlobeReferenceScale3D()
{
	OnGlobeReferenceScale3DUpdated.Broadcast(GlobeReferenceScale3D);
}

void AGame_PlayerState::OnRep_IsInTOC()
{
	OnIsInTOCUpdated.Broadcast(bIsInTOC);
}

void AGame_PlayerState::OnRep_SelfMuted()
{
	OnMuteStatusUpdated.Broadcast(bSelfMuted, bForceMuted);
}

void AGame_PlayerState::OnRep_ForceMuted()
{
	OnMuteStatusUpdated.Broadcast(bSelfMuted, bForceMuted);
}

void AGame_PlayerState::OnRep_MUCComponent_Database()
{
	ServerSetChannelReady(UGame_MUCComponent_Database::GetDataChannelManagerID(), true);
}

void AGame_PlayerState::OnRep_MUCComponent_File()
{
	ServerSetChannelReady(UGame_MUCComponent_File::GetDataChannelManagerID(), true);
}

void AGame_PlayerState::OnRep_Talking()
{
	OnTalkingStatusChanged.Broadcast(bTalking);
}

// ---------------------------------
// --- Interface_DataChannelManager
// ---------------------------------

UVH_DataChannelManager* AGame_PlayerState::GetDCM(int32 id)
{
	if (UGame_MUCComponent* mucComponent = GetMUCComponentFromID(id))
	{
		return mucComponent->GetDCM(id);
	}

	return nullptr;
}

bool AGame_PlayerState::GetChannelReady(int32 id)
{
	if (UGame_MUCComponent* mucComponent = GetMUCComponentFromID(id))
	{
		return mucComponent->GetChannelReady();
	}

	return false;
}

void AGame_PlayerState::SetChannelReady(int32 id, bool bReady)
{
	if (UGame_MUCComponent* mucComponent = GetMUCComponentFromID(id))
	{
		mucComponent->SetChannelReady(bReady);
	}
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bIsInTOC = GetNetMode() == NM_Client || gameSettings->GetSettingBool(TEXT("bInitialInTOC"));
	}

	CreateMUCComponents();

	UpdateCallsignFromCOTManager();

	UpdateCollaborationColor();

	if (GetNetMode() == NM_ListenServer)
	{
		IOnlineVoicePtr voiceInt = IOnlineSubsystem::Get()->GetVoiceInterface();
		if (voiceInt.IsValid())
		{
			voiceInt->AddOnPlayerTalkingStateChangedDelegate_Handle(FOnPlayerTalkingStateChangedDelegate::CreateUObject(this, &AGame_PlayerState::HandlePlayerTalkingStateChanged));
		}
	}

	if (APlayerController* pc = Cast<APlayerController>(GetOwner()))
	{
		if (pc->IsLocalPlayerController())
		{
			UGame_Subsystem_Ribbon::Get()->SyncToGameState();
		}
	}
}

void AGame_PlayerState::BeginDestroy()
{
	OnCallsignUpdated.Clear();

	OnGlobeReferenceScale3DUpdated.Clear();

	OnIsInTOCUpdated.Clear();

	OnServerDatabaseReady.Clear();

	if (GetUniqueId().IsValid())
	{
		IOnlineVoicePtr voiceInt = Online::GetVoiceInterface();
		if (voiceInt.IsValid())
		{
			voiceInt->UnregisterRemoteTalker(*GetUniqueId());
		}
	}

	if (GetNetMode() == NM_ListenServer)
	{
		if (APlayerController* pc = Cast<APlayerController>(GetOwner()))
		{
			if (pc->IsLocalPlayerController())
			{
				if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
				{
					entityDB->OnInsertOrUpdate.RemoveDynamic(this, &AGame_PlayerState::SendDBUpdateToClients);
				}
			}
		}
	}

	Super::BeginDestroy();
}

void AGame_PlayerState::OnReactivated()
{
	Super::OnReactivated();

	CreateMUCComponents();

	UpdateCallsignFromCOTManager();

	UpdateCollaborationColor();
}

// ---------------------------------
// --- API
// ---------------------------------

bool AGame_PlayerState::GetIsTalking() const
{
	return bTalking;
}

USoundAttenuation* AGame_PlayerState::GetAttenuationSettings()
{
	return bVoipSpatialized ? AttenuationSettingsSpatialized : AttenuationSettingsNotSpatialized;
}

FString AGame_PlayerState::GetCallsign() const
{
	return Callsign;
}

FLinearColor AGame_PlayerState::GetCollaborationColor() const
{
	return CollaborationColor;
}

FVector AGame_PlayerState::GetGlobeReferenceScale3D() const
{
	return GlobeReferenceScale3D;
}

bool AGame_PlayerState::GetIsInTOC() const
{
	return bIsInTOC;
}

void AGame_PlayerState::SetIsInTOC(bool isInTOC)
{
	if (GetNetMode() == NM_Client)
	{
		bIsInTOC = isInTOC;
		
		OnRep_IsInTOC();
		
		Server_AttemptEndDragPan();
	}

	Server_SetIsInTOC(isInTOC);
}

void AGame_PlayerState::SetOwningPawn(AGame_Pawn* newOwningPawn)
{
	OwningPawn = newOwningPawn;

	// TODO: only create Component if there is not one already

	Talker = NewObject<UGame_Component_Talker>(this);
	if (Talker != nullptr)
	{
		Talker->RegisterWithPlayerState(this);
		Talker->Settings.AttenuationSettings = GetAttenuationSettings();
		Talker->Settings.ComponentToAttachTo = OwningPawn->GetRootComponent();
	}
}

void AGame_PlayerState::SetMuteStatus(bool inSelfMuted, bool inForceMuted)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		bSelfMuted = inSelfMuted;
		bForceMuted = inForceMuted;

		OnMuteStatusUpdated.Broadcast(inSelfMuted, inForceMuted);
	}
	else
	{
		Server_SetMuteStatus(inSelfMuted, inForceMuted);
	}
}

void AGame_PlayerState::SetPlayingSynthComp(USynthComponent* inSynthComp)
{
	PlayingSynthComp = inSynthComp;

	if (PlayingSynthComp != nullptr)
	{
		PlayingSynthComp->AttachToComponent(OwningPawn->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);

		PlayingSynthComp->bOverrideAttenuation = false;
		PlayingSynthComp->AttenuationSettings = GetAttenuationSettings();

		PlayingSynthComp->SetVolumeMultiplier(2.f);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_PlayerState::SetPlayingSynthComp | inSynthComp is nullptr"));
	}
}

void AGame_PlayerState::UpdateVoipSpatialized(bool isSpatialized)
{
	bVoipSpatialized = isSpatialized;

	if (PlayingSynthComp != nullptr)
	{
		if (Talker != nullptr)
		{
			Talker->Settings.AttenuationSettings = GetAttenuationSettings();
		}

		if (UAudioComponent* comp = PlayingSynthComp->GetAudioComponent())
		{
			comp->AttenuationSettings = GetAttenuationSettings();
			comp->AdjustAttenuation(comp->AttenuationSettings->Attenuation);
		}

		PlayingSynthComp->AttenuationSettings = GetAttenuationSettings();
	}
}

void AGame_PlayerState::SetMUCServerDBReceived(bool bReceived)
{
	bMUCServerDBReceived = bReceived;
}

bool AGame_PlayerState::IsMUCServerDBReceived() const
{
	return bMUCServerDBReceived;
}

void AGame_PlayerState::SendDBDeleteToClients(const FSpatialiteResults_BP& results)
{
	if (AGameState* gameState = GetWorld()->GetGameState<AGameState>())
	{
		for (int32 i = 0; i < gameState->PlayerArray.Num(); i++)
		{
			if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(gameState->PlayerArray[i]))
			{
				if (playerState != this)
				{
					int32 id = UGame_MUCComponent_Database::GetDataChannelManagerID();
					if (UGame_MUCComponent_Database* mucComponent = Cast<UGame_MUCComponent_Database>(playerState->GetMUCComponentFromID(id)))
					{
						mucComponent->SendDBDeleteToClients(results);
						return;
					}
				}
			}
		}
	}
}

UGame_MUCComponent* AGame_PlayerState::GetMUCComponentFromID(int32 id) const
{
	if (id == UGame_MUCComponent_Database::GetDataChannelManagerID())
	{
		return MUCComponent_Database;
	}
	else if (id == UGame_MUCComponent_File::GetDataChannelManagerID())
	{
		return MUCComponent_File;
	}

	UE_LOG(Game, Warning, TEXT("-- AGame_PlayerState::GetMUCComponentFromID | unknown ID: %d"), id);

	return nullptr;
}

bool AGame_PlayerState::SendEntitiesToClient(APlayerController* playerController, const TArray<FString>& entityUIDs)
{
	UVH_COTManager* cotManager = UVH_COTManager::Get();
	if (cotManager == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_PlayerState::SendEntitiesToClient | cotManager is nullptr | aborting"));
		return false;
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults validResults;

		for (const FString& entityUID : entityUIDs)
		{
			SpatialiteResults results = entityDB->QueryUID(entityUID);
			if (results.Num() > 0)
			{
				SpatialiteResult result = results[0];

				FString categoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), result);

				if (!categoryID.Equals(TEXT("contact")))
				{
					// cotEvent could legitimately be nullptr here if sending something that doesn't have cot in its blob (e.g. RedX)
					UVH_COTEvent* cotEvent = cotManager->GetCotEventFromUID(entityUID);
					if (!UVH_COTManager::IsVTAKGhost(cotEvent))
					{
						validResults.Add(result);
					}
				}
			}
		}

		EMUCDataType dataType = EMUCDataType::DT_InsertOrUpdate;

		int32 numResults = validResults.Num();

		FBufferArchive toBinary;
		toBinary << dataType;
		toBinary << numResults;

		for (int32 i = 0; i < validResults.Num(); i++)
		{
			SpatialiteResult result = validResults[i];

			toBinary << result;
		}

		TArray<uint8> data = (TArray<uint8>&)toBinary;

		if (AGameState* gameState = GetWorld()->GetGameState<AGameState>())
		{
			for (int32 i = 0; i < gameState->PlayerArray.Num(); i++)
			{
				if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(gameState->PlayerArray[i]))
				{
					if (playerState != this)
					{
						int32 id = UGame_MUCComponent_Database::GetDataChannelManagerID();
						if (UGame_MUCComponent_Database* mucComponent = Cast<UGame_MUCComponent_Database>(playerState->GetMUCComponentFromID(id)))
						{
							if (mucComponent->GetDCM(id)->HasChannelFor(playerController))
							{
								for (const SpatialiteResult& result : validResults)
								{
									mucComponent->AddSendLog(result);
								}

								mucComponent->OnMUCInsertOrUpdateSent.Broadcast(FSpatialiteResults_BP(validResults));

								mucComponent->GetDCM(id)->BroadcastDataToClients(data, playerController->PlayerState->GetPlayerId());
								return true;
							}
						}
					}
				}
			}
		}
	}

	// no DCMs had a channel for playerController; most likely because DCM replication hasn't occurred for that client yet
	// set a timer and try again in a little while
	FString entities = TEXT("");
	for (const FString& entityUID : entityUIDs)
	{
		entities += entityUID + TEXT("|");
	}

	FTimerDelegate timerDel;
	timerDel.BindUFunction(this, FName("SendEntitiesToClientTimer"), playerController, entities);

	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, timerDel, 0.5f, false);

	return false;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_PlayerState::SendEntitiesToClientTimer(AGame_PlayerController* playerController, const FString& entities)
{
	TArray<FString> entityUIDs;

	entities.ParseIntoArray(entityUIDs, TEXT("|"));

	SendEntitiesToClient(playerController, entityUIDs);
}

void AGame_PlayerState::CreateMUCComponents()
{
	if (GetNetMode() == NM_ListenServer)
	{
		if (MUCComponent_Database == nullptr)
		{
			if (APlayerController* pc = Cast<APlayerController>(GetOwner()))
			{
				if (pc->IsLocalPlayerController())
				{
					if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
					{
						entityDB->OnInsertOrUpdate.AddUniqueDynamic(this, &AGame_PlayerState::SendDBUpdateToClients);
					}
				}
				else
				{
					MUCComponent_Database = NewObject<UGame_MUCComponent_Database>(this, UGame_MUCComponent_Database::StaticClass());
					MUCComponent_Database->RegisterComponent();
					MUCComponent_Database->CreateDCM(UGame_MUCComponent_Database::GetDataChannelManagerID());
				}
			}
		}

		if (MUCComponent_File == nullptr)
		{
			if (APlayerController* pc = Cast<APlayerController>(GetOwner()))
			{
				if (!pc->IsLocalPlayerController())
				{
					MUCComponent_File = NewObject<UGame_MUCComponent_File>(this, UGame_MUCComponent_File::StaticClass());
					MUCComponent_File->RegisterComponent();
					MUCComponent_File->CreateDCM(UGame_MUCComponent_File::GetDataChannelManagerID());
				}
			}
		}
	}
}

void AGame_PlayerState::FindGameState()
{
	AGame_GameMode* gameMode = UGame_Statics::GetVHGameMode();
	if (gameMode == nullptr)
	{
		UE_LOG(Game, Error, TEXT("Failed to find game mode"));
		return;
	}

	GameState = gameMode->GetGameState<AGame_GameState>();
	if (GameState == nullptr)
	{
		UE_LOG(Game, Error, TEXT("Failed to find valid GameState from GameMode"));
	}
}

void AGame_PlayerState::UpdateCallsignFromCOTManager()
{
	if (APlayerController* playerController = Cast<APlayerController>(GetOwner()))
	{
		if (playerController->IsLocalPlayerController())
		{
			if (UVH_COTManager* cotManager = UVH_COTManager::Get())
			{
				Server_SetCallsign(cotManager->GetCallsign());

				cotManager->OnUpdatedCallsign.AddUniqueDynamic(this, &AGame_PlayerState::Server_SetCallsign);
			}
			else
			{
				FTimerHandle timerHandle;
				GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_PlayerState::UpdateCallsignFromCOTManager, 0.5, false);
			}
		}
	}
}

void AGame_PlayerState::UpdateCollaborationColor()
{
	if (APlayerController* playerController = Cast<APlayerController>(GetOwner()))
	{
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			FString storedCollaborationColor = gameSettings->GetSettingString(TEXT("CollaborationColor"));

			TArray<FString> colorChannels;
			storedCollaborationColor.ParseIntoArray(colorChannels, TEXT("|"));

			if (colorChannels.Num() == 4)
			{
				FLinearColor linearColor(FCString::Atof(*colorChannels[0]), FCString::Atof(*colorChannels[1]), FCString::Atof(*colorChannels[2]), FCString::Atof(*colorChannels[3]));

				// -1 shows user has not manually set their collaboration color; set collaboration color to unique color
				if (linearColor.A == -1)
				{
					UVH_COTManager* cotManager = UVH_COTManager::Get();
					UWorld* world = GetWorld();

					if (cotManager != nullptr && world != nullptr)
					{
						if (AGame_GameState* gameState = GetWorld()->GetGameState<AGame_GameState>())
						{
							TMap<FName, FLinearColor> nameToColor = cotManager->GetGroupColors();

							// create TMap indexed by color for quicker finds
							TMap<FLinearColor, FName> colorToName;
							for (const TPair<FName, FLinearColor>& entry : nameToColor)
							{
								colorToName.Add(entry.Value, entry.Key);
							}

							for (APlayerState* playerState : gameState->PlayerArray)
							{
								AGame_PlayerState* gamePlayerState = Cast<AGame_PlayerState>(playerState);
								if (IsValid(gamePlayerState) && gamePlayerState != this)
								{
									colorToName.Remove(gamePlayerState->GetCollaborationColor());
								}
							}

							TArray<FLinearColor> colors;
							if (colorToName.Num() > 0)
							{
								colorToName.GenerateKeyArray(colors);
							}
							else
							{
								// no unique colors, pick from original list
								nameToColor.GenerateValueArray(colors);
							}

							linearColor = colors[FMath::RandHelper(colors.Num())];
						}
					}
					else
					{
						FTimerHandle timerHandle;
						GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_PlayerState::UpdateCollaborationColor, 0.5, false);

						linearColor.A = 1;
					}
				}

				Server_SetCollaborationColor(linearColor);
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- AGame_PlayerState::UpdateCollaborationColor | invalid CollaborationColor from database | %s"), *storedCollaborationColor);
			}
		}
	}
}

void AGame_PlayerState::ServerSetChannelReady_Implementation(int32 id, bool bReady)
{
	SetChannelReady(id, true);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_PlayerState::SendDBUpdateToClients(const FSpatialiteResults_BP& results)
{
	if (bReplicateMUCUpdates)
	{
		if (AGameState* gameState = GetWorld()->GetGameState<AGameState>())
		{
			for (int32 i = 0; i < gameState->PlayerArray.Num(); i++)
			{
				if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(gameState->PlayerArray[i]))
				{
					if (playerState != this)
					{
						int32 id = UGame_MUCComponent_Database::GetDataChannelManagerID();
						if (UGame_MUCComponent_Database* mucComponent = Cast<UGame_MUCComponent_Database>(playerState->GetMUCComponentFromID(id)))
						{
							mucComponent->SendDBUpdateToClients(results);
							return;
						}
					}
				}
			}
		}
	}
}

void AGame_PlayerState::HandlePlayerTalkingStateChanged(FUniqueNetIdRef talkerID, bool bIsTalking)
{
	if (GetUniqueId().GetUniqueNetId() == talkerID)
	{
		bTalking = bIsTalking;

		OnTalkingStatusChanged.Broadcast(bTalking);
	}
}
