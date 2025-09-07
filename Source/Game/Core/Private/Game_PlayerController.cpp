// Required Includes
#include "Game_PlayerController.h"
#include "Game.h"

// Engine Includes
#include "Net/UnrealNetwork.h"
#include "Engine/UserInterfaceSettings.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "OnlineSubsystemUtils.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/GameViewportClient.h"
#include "Framework/Application/SlateApplication.h"
#include "Engine/GameEngine.h"
#include "GameFramework/HUD.h"

// VH Plugin Includes
#include "Developer_TaskScheduler.h"
#include "VH_DataChannelManager.h"
#include "VH_GlobeMathStatics.h"
#include "VH_GeodeticCoord.h"
#include "VH_COTManager.h"
#include "VH_COTEvent.h"
#include "VH_GlobeReferenceActor.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "Developer_Statics.h"
#include "VR_MotionControllerComponent.h"

#include "VH_COTStatics.h"
#include "VH_KmlInfo.h"

// Game Includes
#include "Game_CameraComponent.h"
#include "Game_VirtualObjective.h"
#include "Game_Mark.h"
#include "Game_MUCComponent_File.h"
#include "Game_TileManager.h"
#include "Game_EntityDB.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_COTComponent_DrawTelestration.h"
#include "Game_Pawn.h"
#include "Game_ImportedMeshComponent.h"
#include "Game_Actor_KmlPlacemark.h"
#include "Game_TutorialManager.h"
#include "Game_Subsystem_Core.h"
#include "Game_Tool.h"
#include "Game_Subsystem_Ribbon.h"
#include "Game_GlobeReferenceActor_Ellipsoid.h"
#include "Game_MovementComponent.h"
#include "Game_MotionControllerComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_PlayerController::AGame_PlayerController(const FObjectInitializer& objectInitializer) :
    Super(objectInitializer)
{
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
    bShowMouseCursor = true;
	QuickturnCooldown = 2;
}

// ---------------------------------
// --- Replication
// ---------------------------------

void AGame_PlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGame_PlayerController, bForceLeaveSession);
	DOREPLIFETIME(AGame_PlayerController, bForceMute);
}

void AGame_PlayerController::PawnLeavingGame()
{
	ReceivePawnLeavingGame();

	Super::PawnLeavingGame();
}

void AGame_PlayerController::SetForceMute(bool shouldForceMute)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		bForceMute = shouldForceMute;
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_PlayerController::SetForceMute | called without authority"));
	}
}

void AGame_PlayerController::Server_VOSetScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FVector& scale3D)
{
	if (virtualObjective != nullptr)
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			if (playerState->GetIsInTOC())
			{
				virtualObjective->SetActorScale3D(scale3D);
			}
		}
	}
}

void AGame_PlayerController::Server_VOSetReplicatedScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FVector& scale3D)
{
	if (virtualObjective != nullptr)
	{
		virtualObjective->SetReplicatedScale3D(scale3D);
	}
}

void AGame_PlayerController::Server_TOCSetReplicatedPosition_Implementation(AGame_VirtualObjective* virtualObjective, const FGeodeticCoord3D& coordinate)
{
	if (virtualObjective != nullptr)
	{
		virtualObjective->SetReplicatedVOGlobeCoordinate(coordinate);
	}
}

void AGame_PlayerController::Server_SetCoord_Implementation(AGame_VirtualObjective* virtualObjective, const FGeodeticCoord3D& coordinate)
{
	if (virtualObjective != nullptr)
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			if (playerState->GetIsInTOC())
			{
				virtualObjective->SetCoord_Implementation(coordinate);
			}
		}
	}
}

void AGame_PlayerController::Client_ConsoleCommand_Implementation(const FString& consoleCommand)
{
	ConsoleCommand(consoleCommand);
}

void AGame_PlayerController::Client_TeleportAndOrientPlayer_Implementation(const FGeodeticCoord3D& coordinate, float bearing)
{
	if (AGame_Pawn* pawn = Cast<AGame_Pawn>(GetPawn()))
	{
		pawn->TeleportToCoordinate(coordinate);
		pawn->RotateToBearing(bearing);
	}
}

void AGame_PlayerController::OnRep_ForceLeaveSession()
{
	if (IOnlineSubsystem* onlineSub = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(UDeveloper_Statics::GetVHWorld());
		
		sessionInterface->DestroySession(NAME_GameSession);
	}

	ConsoleCommand(TEXT("open MainMap_P?listen"));
}

void AGame_PlayerController::OnRep_ForceMuted()
{
	// if bForceMute is true; player should be muted (and locked)
	// if bForceMute is false; player should be muted (and not locked)
	ToggleSpeaking(false);
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

AGame_VirtualObjective* AGame_PlayerController::GetPlayerActiveVO()
{
	if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
	{
		return pc->GetActiveVO();
	}

	return nullptr;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		ToggleSpeaking(true);
	}

	RequestSpeakingChangedCallback();

	if (UGameEngine* gameEngine = Cast<UGameEngine>(GEngine))
	{
		gameEngine->OnNetworkFailure().AddUObject(this, &AGame_PlayerController::HandleNetworkFailure);
	}

	// todo ohg | better place for this?
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		UUserInterfaceSettings* userInterfaceSettings = GetMutableDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass());
		userInterfaceSettings->ApplicationScale = gameSettings->GetSettingDouble(TEXT("ApplicationScale"));
	}

	if (UGame_Subsystem_Ribbon* subsystem = UGame_Subsystem_Ribbon::Get())
	{
		if (IsLocalPlayerController())
		{
			subsystem->ShowRibbon();
		}
	}

	SetMouseMode(EMouseCaptureMode::CaptureDuringRightMouseDown);
}

void AGame_PlayerController::ClientEnableNetworkVoice_Implementation(bool bEnable)
{
	Super::ClientEnableNetworkVoice_Implementation(bEnable);

	bAlwaysBroadcast = bEnable;
}

void AGame_PlayerController::ToggleSpeaking(bool bInSpeaking)
{
	if (bForceMute)
	{
		bInSpeaking = false;
	}

	Super::ToggleSpeaking(bInSpeaking);

	if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(PlayerState))
	{
		playerState->SetMuteStatus(!bInSpeaking, bForceMute);
	}

	bBroadcastOn = bInSpeaking;
}

void AGame_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		inputComponent->BindAction(ToggleMouseLookInputAction, ETriggerEvent::Triggered, this, &AGame_PlayerController::HandleToggleMouseMode);
		inputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &AGame_PlayerController::HandleLook);
		inputComponent->BindAction(QuickturnInputAction, ETriggerEvent::Triggered, this, &AGame_PlayerController::HandleVRQuickturn);
		inputComponent->BindAction(QuickturnInputAction, ETriggerEvent::Completed, this, &AGame_PlayerController::HandleVRQuickturnReset);
	}
}

// same as APlayerController::GetHitResultAtScreenPosition except use multi to capture first overlap instead of first blocking
bool AGame_PlayerController::GetHitResultAtScreenPosition(const FVector2D screenPosition, const ECollisionChannel traceChannel, const FCollisionQueryParams& collisionQueryParams, FHitResult& hitResult) const
{
	// Early out if we clicked on a HUD hitbox
	if (GetHUD() != NULL && GetHUD()->GetHitBoxAtCoordinates(screenPosition, true))
	{
		return false;
	}

	FVector WorldOrigin;
	FVector WorldDirection;
	if (UGameplayStatics::DeprojectScreenToWorld(this, screenPosition, WorldOrigin, WorldDirection) == true)
	{
		TArray<FHitResult> hitResults;
		GetWorld()->LineTraceMultiByChannel(hitResults, WorldOrigin, WorldOrigin + WorldDirection * HitResultTraceDistance, traceChannel, collisionQueryParams);

		if (hitResults.Num() > 0 && hitResults[0].GetActor() != nullptr)
		{
			hitResult = hitResults[0];

			return true;
		}
	}

	return false;
}

// same as APlayerController::GetHitResultAtScreenPosition except use multi to capture first overlap instead of first blocking
bool AGame_PlayerController::GetHitResultAtScreenPosition(const FVector2D screenPosition, const TArray<TEnumAsByte<EObjectTypeQuery>>& objectTypes, bool bTraceComplex, FHitResult& hitResult) const
{
	// Early out if we clicked on a HUD hitbox
	if (GetHUD() != NULL && GetHUD()->GetHitBoxAtCoordinates(screenPosition, true))
	{
		return false;
	}

	FVector worldOrigin;
	FVector worldDirection;
	if (UGameplayStatics::DeprojectScreenToWorld(this, screenPosition, worldOrigin, worldDirection) == true)
	{
		TArray<FHitResult> hitResults;

		FCollisionObjectQueryParams const objParam(objectTypes);
		GetWorld()->LineTraceMultiByObjectType(hitResults, worldOrigin, worldOrigin + worldDirection * HitResultTraceDistance, objParam, FCollisionQueryParams(SCENE_QUERY_STAT(ClickableTrace), bTraceComplex));

		if (hitResults.Num() > 0 && hitResults[0].GetActor() != nullptr)
		{
			hitResult = hitResults[0];

			return true;
		}
	}

	return false;
}

void AGame_PlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	ReceivePlayerStateAssigned(PlayerState);
}

void AGame_PlayerController::CleanupPlayerState()
{
	Super::CleanupPlayerState();

	ReceivePlayerStateAssigned(PlayerState);
}

void AGame_PlayerController::InitPlayerState()
{
	Super::InitPlayerState();

	ReceivePlayerStateAssigned(PlayerState);
}

// ---------------------------------
// --- API
// ---------------------------------

UDeveloper_TaskScheduler* AGame_PlayerController::GetMeshBuilder()
{
	if (MeshBuilder == nullptr)
	{
		MeshBuilder = NewObject<UDeveloper_TaskScheduler>();

		MeshBuilder->SetSecondsBetweenChecks(0.1);

		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			MeshBuilder->SetMaxConcurrentTasks(gameSettings->GetSettingInt(TEXT("MaxConcurrentMeshBuilders")));

			gameSettings->OnIntSettingStored.AddDynamic(this, &AGame_PlayerController::HandleIntSettingChanged);
		}
		// if the settings were not able to be grabbed for whatever reason, set it to 5 by default.
		else
		{
			MeshBuilder->SetMaxConcurrentTasks(5);
		}

		MeshBuilder->Start(TEXT("MeshBuilder"));
	}

	return MeshBuilder;
}

UDeveloper_TaskScheduler* AGame_PlayerController::GetMeshLoader()
{
	if (MeshLoader == nullptr)
	{
		MeshLoader = NewObject<UDeveloper_TaskScheduler>();

		MeshLoader->SetSecondsBetweenChecks(0.1);
		MeshLoader->SetMaxConcurrentTasks(5);
		MeshLoader->Start(TEXT("MeshLoader"));
	}

	return MeshLoader;
}

UDeveloper_TaskScheduler* AGame_PlayerController::GetTerrainTileBuilder()
{
	if (TerrainTileBuilder == nullptr)
	{
		TerrainTileBuilder = NewObject<UDeveloper_TaskScheduler>();

		TerrainTileBuilder->SetSecondsBetweenChecks(0.1);
		TerrainTileBuilder->SetMaxConcurrentTasks(4);
		TerrainTileBuilder->Start(TEXT("TerrainTileBuilder"));
	}

	return TerrainTileBuilder;
}

AGame_Mark* AGame_PlayerController::GetRedX(FString& outEntityUID) const
{
	outEntityUID = RedXEntityUID;

	return RedX;
}

void AGame_PlayerController::SetRedX(AGame_Mark* inRedX)
{
	RedX = inRedX;
}

void AGame_PlayerController::SetRedXEntityUID(const FString& entityUID)
{
	RedXEntityUID = entityUID;
}

void AGame_PlayerController::SetActiveVO(AGame_VirtualObjective* virtualObjective)
{
	if (ActiveVO != virtualObjective)
	{
		ActiveVO = virtualObjective;

		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			tileManager->SetVirtualObjective(virtualObjective);
		}

		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(virtualObjective->GetGlobeReference()))
			{
				playerPawn->VRMovement->SetWorldTransformOverride(globeReferenceEllipsoid->GetSurfaceTransform(playerPawn->GetActorLocation()));
			}
			else
			{
				playerPawn->VRMovement->SetWorldTransformOverride(FTransform::Identity);
			}
		}
	}
}

AGame_VirtualObjective* AGame_PlayerController::GetActiveVO() const
{
	if (ActiveVO == nullptr)
	{
		UE_LOG(Game, Verbose, TEXT("-- AGame_PlayerController::GetActiveVO | activeVO is nullptr"));
	}

	return ActiveVO;
}

int32 AGame_PlayerController::GetTotalTasks() const
{
	int32 totalTasks = 0;

	if (MeshBuilder != nullptr)
	{
		totalTasks = MeshBuilder->GetNumTasks() + MeshBuilder->GetNumActiveTasks();
	}

	if (MeshLoader != nullptr)
	{
		totalTasks += MeshLoader->GetNumTasks() + MeshLoader->GetNumActiveTasks();
	}
	
	if (TerrainTileBuilder != nullptr)
	{
		totalTasks += TerrainTileBuilder->GetNumTasks() + TerrainTileBuilder->GetNumActiveTasks();
	}

	return totalTasks;
}

void AGame_PlayerController::ReceivePlayerStateAssigned_Implementation(APlayerState* newPlayerState)
{
	// Do nothing for now, but here if someone wants to do something
}

void AGame_PlayerController::SetMouseMode(EMouseCaptureMode mouseCaptureMode)
{
	switch (mouseCaptureMode)
	{
		case EMouseCaptureMode::CaptureDuringRightMouseDown:
		case EMouseCaptureMode::CaptureDuringMouseDown:
		{
			FInputModeGameAndUI inputMode = FInputModeGameAndUI();
			inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture);
			inputMode.SetHideCursorDuringCapture(true);

			SetInputMode(inputMode);

			if (bMousePositionAtCaptureSet)
			{
				GetWorld()->GetGameViewport()->Viewport->SetMouse(MousePositionAtCapture.X, MousePositionAtCapture.Y);

				bMousePositionAtCaptureSet = false;
			}

			SetShowMouseCursor(true);
		}
		break;

		case EMouseCaptureMode::CapturePermanently:
		{
			FInputModeGameOnly inputMode = FInputModeGameOnly();
			SetInputMode(inputMode);

			SetShowMouseCursor(false);

			GetWorld()->GetGameViewport()->GetMousePosition(MousePositionAtCapture);

			// copied from FSceneViewport::AcquireFocusAndCapture
			// The slate app will correct mouse positions for non-standard screen / viewport resolution combos
			// We want to save the mouse position pre-correction so it isn't applied twice when restoring mouse position
			TSharedPtr<SViewport> viewportWidget = GetWorld()->GetGameViewport()->GetGameViewportWidget();
			TSharedPtr<SWindow> window = FSlateApplication::Get().FindWidgetWindow(viewportWidget.ToSharedRef());
			if (FSlateApplication::Get().GetTransformFullscreenMouseInput() && !GIsEditor && window.IsValid() && window->GetWindowMode() == EWindowMode::Fullscreen)
			{
				FDisplayMetrics cachedDisplayMetrics;
				FSlateApplication::Get().GetCachedDisplayMetrics(cachedDisplayMetrics);
				FVector2D windowSize = window->GetSizeInScreen();
				FVector2D displaySize = {(float)cachedDisplayMetrics.PrimaryDisplayWidth, (float)cachedDisplayMetrics.PrimaryDisplayHeight};
				FVector2D correctionScale = displaySize / windowSize;
				MousePositionAtCapture.X = (int32)(MousePositionAtCapture.X * correctionScale.X);
				MousePositionAtCapture.Y = (int32)(MousePositionAtCapture.Y * correctionScale.Y);
			};

			bMousePositionAtCaptureSet = true;
		}
		break;
	}

	UGameplayStatics::SetViewportMouseCaptureMode(GetWorld(), mouseCaptureMode);

	if (UGame_TutorialManager* tutorialManager = UGame_TutorialManager::Get())
	{
		switch (mouseCaptureMode)
		{
			case EMouseCaptureMode::CaptureDuringRightMouseDown:
			{
				if (tutorialManager->GetCanSwitchMouseLook())
				{
					if (!tutorialManager->GetHasSwitchedMouseLook())
					{
						tutorialManager->SetHasSwitchedMouseLook(true);
						tutorialManager->TutorialActionOccurred(TEXT("toggleNoPointer"));
					}
					else
					{
						tutorialManager->TutorialActionOccurred(TEXT("togglePointer"));
					}
				}
			}
			break;
		}
	}

	OnMouseCaptureModeChanged.Broadcast(mouseCaptureMode);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_PlayerController::RequestSpeakingChangedCallback()
{
	IOnlineVoicePtr voiceInt = Online::GetVoiceInterface();
	
	if (voiceInt.IsValid())
	{
		voiceInt->AddOnPlayerTalkingStateChangedDelegate_Handle(FOnPlayerTalkingStateChangedDelegate::CreateUObject(this, &AGame_PlayerController::HandleTalkStatusChanged));
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------
//
void AGame_PlayerController::HandleTalkStatusChanged(TSharedRef<const FUniqueNetId> talkerID, bool isTalking)
{
	if (PlayerState != nullptr && PlayerState->GetUniqueId().GetUniqueNetId() == talkerID)
	{
		bBroadcastingVoice = isTalking;
	}
}

void AGame_PlayerController::HandleNetworkFailure(UWorld* world, UNetDriver* netDriver, ENetworkFailure::Type failureType, const FString& errorString)
{
	if (GetNetMode() == NM_Client)
	{
		if (IOnlineSubsystem* onlineSub = IOnlineSubsystem::Get())
		{
			IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(UDeveloper_Statics::GetVHWorld());

			sessionInterface->DestroySession(NAME_GameSession);
		}
	}
}

void AGame_PlayerController::HandleIntSettingChanged(const FString& settingName, const int32 value)
{
	if (settingName.Equals(TEXT("MaxConcurrentMeshBuilders"), ESearchCase::IgnoreCase))
	{
		MeshBuilder->SetMaxConcurrentTasks(value);
	}
}

void AGame_PlayerController::HandleToggleMouseMode()
{
	EMouseCaptureMode mouseCaptureMode = UGameplayStatics::GetViewportMouseCaptureMode(GetWorld());

	if (mouseCaptureMode == EMouseCaptureMode::CaptureDuringRightMouseDown)
	{
		SetMouseMode(EMouseCaptureMode::CapturePermanently);
	}
	else
	{
		SetMouseMode(EMouseCaptureMode::CaptureDuringRightMouseDown);
	}
}

void AGame_PlayerController::HandleLook(const FInputActionValue& actionValue)
{
	// transform is localToWorld
	FTransform worldTransformOverride = FTransform::Identity;
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		worldTransformOverride = playerPawn->VRMovement->GetWorldTransformOverride();

		worldTransformOverride.SetLocation(FVector(0, 0, 0));

		FVector2D value = actionValue.Get<FVector2D>();

		FQuat cameraLocal = worldTransformOverride.InverseTransformRotation(playerPawn->Camera->GetComponentQuat());

		FRotator newLocalRotation;
		newLocalRotation.Pitch = FMath::Clamp<float>(cameraLocal.Rotator().Pitch + value.Y, -89.9, 89.9);
		newLocalRotation.Yaw = cameraLocal.Rotator().Yaw + value.X;
		newLocalRotation.Roll = 0;
		
		FQuat modifiedCameraLocal = newLocalRotation.Quaternion();
	
		FQuat modifiedCameraWorld = worldTransformOverride.TransformRotation(modifiedCameraLocal);
	
		playerPawn->Camera->SetWorldRotation(modifiedCameraWorld);
	}
}

void AGame_PlayerController::HandleVRQuickturn(const FInputActionValue& value)
{
	if (GetWorld()->TimeSeconds - LastQuickturn > QuickturnCooldown)
	{
		if (AGame_Pawn* playerPawn = Cast<AGame_Pawn>(GetPawn()))
		{
			if (!playerPawn->IsDraggingWorldUI())
			{
				float deltaYaw = (value.Get<float>() > 0 ? 45 : -45) * QuickturnSpeed;

				playerPawn->Camera->AddQuickTurn(deltaYaw);

				LastQuickturn = GetWorld()->TimeSeconds;

				// if ribbon is open, close and re-open to keep it in front of player
				if (UGame_Subsystem_Ribbon* subsystem = UGame_Subsystem_Ribbon::Get())
				{
					if (subsystem->GetRibbonVisible())
					{
						subsystem->HideRibbon();
					
						FTimerHandle timerHandle;
						GetWorld()->GetTimerManager().SetTimer(timerHandle, subsystem, &UGame_Subsystem_Ribbon::ShowRibbon, 0.25, false);
					}
				}
			}
		}
	}
}

void AGame_PlayerController::HandleVRQuickturnReset(const FInputActionValue& value)
{
	LastQuickturn = 0;
}

// ---------------------------------
// --- Debug/Testing
// ---------------------------------

void AGame_PlayerController::QA_InterpPoints(const FString& startLon, const FString& startLat, const FString& startAlt, const FString& endLon, const FString& endLat, const FString& endAlt, float interpDistMeters, bool bUseConstDist /*= false*/)
{
	FGeodeticCoord3D geoStart(FCString::Atod(*startLon), FCString::Atod(*startLat), FCString::Atod(*startAlt));
	FGeodeticCoord3D geoEnd(FCString::Atod(*endLon), FCString::Atod(*endLat), FCString::Atod(*endAlt));

	float avgAlt = (geoStart.Altitude + geoEnd.Altitude) * 0.5f;
	double surfaceDistMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(geoStart.ToGeodeticCoord2D(), geoEnd.ToGeodeticCoord2D(), avgAlt);
	double bearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(geoStart.ToGeodeticCoord2D(), geoEnd.ToGeodeticCoord2D());
	UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("QA_InterpPoints() | surface distMeters=%.8Lf | bearing=%.8Lf"), surfaceDistMeters, bearing), false, true, true, false, ELogMessageColor::White);

	TArray<FGeodeticCoord3D> points = UVH_GlobeMathStatics::InterpolateLocations(geoStart, geoEnd, interpDistMeters, bUseConstDist);
	int32 i = 0;
	for (const FGeodeticCoord3D& point : points)
	{
		UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("-->[%d] %s"), i, *point.ToString()), false, true, true, false, ELogMessageColor::White);
		i++;
	}
}

void AGame_PlayerController::QA_GetEndPoint(const FString& startLon, const FString& startLat, const FString& startAlt, const FString& bearing, const FString& distanceMeters)
{
	//FGeodeticCoord2D basePoint(-79.1631931, 35.1227615);
	//FGeodeticCoord2D endPoint = UVH_GlobeMathStatics::CalculateSurfaceDestination(basePoint, 240.1507019992, 489294.9631215);
	FGeodeticCoord2D geoStart(FCString::Atod(*startLon), FCString::Atod(*startLat));
	double startAltitude = FCString::Atod(*startAlt);
	double bearingDeg = FCString::Atod(*bearing);
	double distMeters = FCString::Atod(*distanceMeters);

	FGeodeticCoord2D geoEnd = UVH_GlobeMathStatics::CalculateSurfaceDestination(geoStart, bearingDeg, distMeters, startAltitude);
	UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("-->endpoint - %s"), *geoEnd.ToString()), false, true, true, false, ELogMessageColor::White);
}

void AGame_PlayerController::QA_GetFileFromServer(const FString& fullPathToFile)
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		if (UGame_MUCComponent_File* mucComponent = Cast<UGame_MUCComponent_File>(playerState->GetMUCComponentFromID(UGame_MUCComponent_File::GetDataChannelManagerID())))
		{
			UGame_EntityDB* entityDB = UGame_EntityDB::Get();

			SpatialiteResults results = entityDB->QueryUID(fullPathToFile);

			//mucComponent->HandleMUCInsertOrUpdate(results);
		}
	}
}

void AGame_PlayerController::QA_VOTriggerUpdateGlobal()
{
	if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
	{
		voManager->TriggerUpdateGlobal();
	}
}

void AGame_PlayerController::QA_SetMaxConcurrentMeshLoads(int32 maxNumber)
{
	GetMeshLoader()->SetMaxConcurrentTasks(maxNumber);
}

void AGame_PlayerController::QA_SetViewDistance(float viewDistance)
{
	GetActiveVO()->SetViewDistance(viewDistance);

	UE_LOG(Game, Warning, TEXT("-- AGame_PlayerController::QA_SetViewDistance | viewDistance set to %f"), viewDistance);
}

void AGame_PlayerController::QA_PageOutEntity(const FString& entityUID)
{
	GetActiveVO()->PageOutEntity(entityUID);

	UE_LOG(Game, Warning, TEXT("-- AGame_PlayerController::QA_PageOutEntity | paged out %s"), *entityUID);
}

void AGame_PlayerController::QA_Doit(double param)
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		playerPawn->LeftController->StabilityFactor = param;
		playerPawn->RightController->StabilityFactor = param;
	}
}

void AGame_PlayerController::QA_SetEntityDatabase(const FString& path, const FString& filename)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->SetDatabasePath(path);
		entityDB->SetDatabaseFilename(filename);
	}
}

void AGame_PlayerController::QA_SetUIScale(float scale)
{
	scale = FMath::Max<float>(scale, 0.01);

	UUserInterfaceSettings* userInterfaceSettings = GetMutableDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass());
	userInterfaceSettings->ApplicationScale = scale;
}