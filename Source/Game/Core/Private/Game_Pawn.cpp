// Required Includes
#include "Game_Pawn.h"
#include "Game.h"

// Engine Includes
#include "Net/UnrealNetwork.h"
#include "Sound/SoundWaveProcedural.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_COTManager.h"
#include "VH_COTUserIcons.h"
#include "VR_CoreComponent.h"
#include "VR_MotionControllerComponent.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "UI_Subsystem_Core.h"
#include "Developer_Subsystem_Core.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_GameState.h"
#include "Game_PlayerState.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Subsystem_Core.h"
#include "Game_EntityDB.h"
#include "Game_Statics.h"
#include "Game_SessionPlayback_Impl.h"
#include "Game_SessionPlaybackHandler_Player.h"
#include "Game_WidgetComponent_FTUE.h"
#include "Game_Tool.h"
#include "Game_CameraScalingComponent.h"
#include "Game_GlobeReferenceActor_Ellipsoid.h"
#include "Game_CameraComponent.h"
#include "Game_MotionControllerComponent.h"
#include "Game_MovementComponent.h"
#include "Game_Subsystem_Ribbon.h"
#include "Game_PresentationMode_ReplicatedWindowComponent.h"
#include "Game_TutorialManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Pawn::AGame_Pawn() :
	DesktopRelativeCamera(FVector(0, 0, 100)),
	VRRelativeCamera(FVector(0, 0, -72)),
	bReplicateGeoLocation(true)
{
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

	CameraScene = CreateDefaultSubobject<USceneComponent>(TEXT("CameraScene"));
	CameraScene->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UGame_CameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraScene);

	VRMovement = CreateDefaultSubobject<UGame_MovementComponent>(TEXT("VRMovement"));

	LeftController = CreateDefaultSubobject<UGame_MotionControllerComponent>(TEXT("LeftController"));
	LeftController->SetupAttachment(CameraScene);

	RightController = CreateDefaultSubobject<UGame_MotionControllerComponent>(TEXT("RightController"));
	RightController->SetupAttachment(CameraScene);

	FTUEWidget = CreateDefaultSubobject<UGame_WidgetComponent_FTUE>(TEXT("FTUEWidget"));
	FTUEWidget->SetupAttachment(Camera);

	CameraScalingHead = CreateDefaultSubobject<UGame_CameraScalingComponent>(TEXT("CameraScalingHead"));
	CameraScalingHead->SetupAttachment(Camera);

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(CameraScalingHead);
	Head->SetOwnerNoSee(true);

	CameraScalingCallsign = CreateDefaultSubobject<UGame_CameraScalingComponent>(TEXT("CameraScalingCallsign"));
	CameraScalingCallsign->SetupAttachment(Camera);
	CameraScalingCallsign->bRotate = true;

	Callsign = CreateDefaultSubobject<UWidgetComponent>(TEXT("Callsign"));
	Callsign->SetupAttachment(CameraScalingCallsign);
	Callsign->SetOwnerNoSee(true);

	PresentationComponent = CreateDefaultSubobject<UGame_PresentationMode_ReplicatedWindowComponent>(TEXT("PresentationComponent"));

	PrimaryActorTick.bCanEverTick = true;
	
	SetReplicatingMovement(false);
}

// ---------------------------------
// --- Replication
// ---------------------------------

void AGame_Pawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGame_Pawn, bDespatializeVOIP);
	DOREPLIFETIME(AGame_Pawn, PawnRotation);
	DOREPLIFETIME(AGame_Pawn, PlayerCoordinate);
	DOREPLIFETIME(AGame_Pawn, HeadTransform);
	DOREPLIFETIME_CONDITION(AGame_Pawn, CameraSceneRelativeLocation, COND_SkipOwner);
}

void AGame_Pawn::OnRep_DespatializeVOIP()
{
	UpdateVoipSpatialized();
}

bool AGame_Pawn::Server_SetVOIPSpatialization_Validate(bool isSpatialized)
{
	return true;
}

void AGame_Pawn::Server_SetVOIPSpatialization_Implementation(bool isSpatialized)
{
	bDespatializeVOIP = !isSpatialized;

	UpdateVoipSpatialized();
}

void AGame_Pawn::Server_SetPlayerCoordinate_Implementation(const FGeodeticCoord3D& coordinate)
{
	PlayerCoordinate = coordinate;

	OnRep_PlayerCoordinate();
}

void AGame_Pawn::Server_SetPawnRotation_Implementation(const FRotator& inPawnRotation)
{
	PawnRotation = inPawnRotation;

	OnRep_PawnRotation();
}

void AGame_Pawn::Server_SetHeadTransform_Implementation(const FTransform& headTransform)
{
	HeadTransform = headTransform;
	
	OnRep_HeadTransform();
}

void AGame_Pawn::Server_SetCameraSceneRelativeLocation_Implementation(const FVector& relativeLocation)
{
	CameraSceneRelativeLocation = relativeLocation;

	if (!IsLocallyControlled())
	{
		OnRep_CameraSceneRelativeLocation();
	}
}

void AGame_Pawn::OnRep_PlayerCoordinate()
{
	if (!IsLocallyControlled())
	{
		SetWorldLocationFromCoordinate(PlayerCoordinate);
	}
}

void AGame_Pawn::OnRep_PawnRotation()
{
	if (!IsLocallyControlled())
	{
		if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AVH_GlobeReferenceActor* globeReference = playerVO->GetGlobeReference())
			{
				double bearing = PawnRotation.Yaw;
				double pitch = PawnRotation.Pitch;

				FRotator worldRotation = globeReference->BearingPitchToWorldRotation(bearing, pitch);
				SetActorRotation(worldRotation);
			}
		}
	}
}

void AGame_Pawn::OnRep_HeadTransform()
{
	if (!IsLocallyControlled())
	{
		if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AVH_GlobeReferenceActor* globeReference = playerVO->GetGlobeReference())
			{
				FVector worldLocation = globeReference->GeodeticToWorldDouble(FGeodeticCoord3D(HeadTransform.GetLocation()));

				double bearing = HeadTransform.GetRotation().Rotator().Yaw;
				double pitch = HeadTransform.GetRotation().Rotator().Pitch;

				FRotator worldRotation = globeReference->BearingPitchToWorldRotation(bearing, pitch);

				Camera->SetWorldLocationAndRotation(worldLocation, worldRotation);
			}
		}
	}
}

void AGame_Pawn::OnRep_CameraSceneRelativeLocation()
{
	CameraScene->SetRelativeLocation(CameraSceneRelativeLocation);
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

FVector AGame_Pawn::GetCameraSceneRelativeLocation()
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		return playerPawn->CameraScene->GetRelativeLocation();
	}

	return FVector(0, 0, 0);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Pawn::BeginPlay()
{
	Super::BeginPlay();

	VRMovement->OnMovementTypeChanged.AddDynamic(this, &AGame_Pawn::HandleMovementTypeChanged);

	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		if (HasLocalNetOwner())
		{
			subsystem->OnHardwareInterfaceModeChanged.AddDynamic(this, &AGame_Pawn::HandleHardwareInterfaceModeChanged);

			if (IsValid(DesktopHUDClass) && subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Desktop)
			{
				if (UUI_Subsystem_Core* uiSubsystem = UUI_Subsystem_Core::Get())
				{
					uiSubsystem->OpenWithDefaultsByClass(DesktopHUDClass);
				}
			}

			// initialize camera location (and adjust head/callsign)
			CameraSceneRelativeLocation = DesktopRelativeCamera;
			if (GEngine->StereoRenderingDevice != nullptr && GEngine->StereoRenderingDevice->IsStereoEnabled())
			{
				CameraSceneRelativeLocation = VRRelativeCamera;
			}

			OnRep_CameraSceneRelativeLocation();

			Server_SetCameraSceneRelativeLocation(CameraSceneRelativeLocation);

			if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
			{
				bStartAtLastLocation = gameSettings->GetSettingBool(TEXT("bStartAtLastLocation"));

				gameSettings->OnBoolSettingStored.AddDynamic(this, &AGame_Pawn::HandleBoolSettingStored);

				if (GetNetMode() != NM_Client && !gameSettings->GetSettingBool(TEXT("bInitialInTOC")))
				{
					TSet<EMovementType> restrictedMovementTypes;
					restrictedMovementTypes.Add(EMovementType::Teleport);

					VRMovement->SetRestrictedMovementTypes(restrictedMovementTypes);

					VRMovement->SetMovementType(EMovementType::Fly);
				}
			}

			FTimerHandle timerHandle;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_Pawn::PeriodicUpdateInitialLocation, 1, true);
		}
	}
	
	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_Pawn::PeriodicUpdatePlayerCoordinate, 0.25, true);
	
	FTimerHandle timerHandle2;
	GetWorld()->GetTimerManager().SetTimer(timerHandle2, this, &AGame_Pawn::PeriodicUpdateNonLocalPosition, 1, true);
}

void AGame_Pawn::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
	
	UpdateCallsignLocation();

	if (IsLocallyControlled())
	{
		if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(playerVO->GetGlobeReference()))
			{
				FGeodeticCoord3D playerCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(GetActorLocation());

				double terrainHAE = globeReferenceEllipsoid->GetTerrainElevationDouble(playerCoordinate.ToGeodeticCoord2D());
				if (UGame_Subsystem_Ribbon* subsystem = UGame_Subsystem_Ribbon::Get())
				{
					if (!FMath::IsNearlyEqual(terrainHAE, -999999.f))
					{
						double playerAGL = playerCoordinate.Altitude - terrainHAE;

						subsystem->SetButtonEnabledCondition("IsNearSurface", playerAGL <= 5000, true);
					}
				}

				if (!VRMovement->GetWorldTransformOverride().Equals(FTransform::Identity))
				{
					FTransform surfaceTransform = globeReferenceEllipsoid->GetSurfaceTransform(GetActorLocation());
					VRMovement->SetWorldTransformOverride(surfaceTransform);

					Camera->SetCameraTransformOverride(VRMovement->GetWorldTransformOverride(), false);
				}
			}
		}
	}
}

void AGame_Pawn::OnPlayerStateChanged(APlayerState* NewPlayerState, APlayerState* OldPlayerState)
{
	Super::OnPlayerStateChanged(NewPlayerState, OldPlayerState);

	ReceivePlayerStateAssigned(NewPlayerState);

	SetupPlayerState();

	AddSessionPlaybackLocationEvent();

	OnPlayerStateUpdated.Broadcast(NewPlayerState, OldPlayerState);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Pawn::ToggleGlobeTransform()
{
	if (IsLocallyControlled())
	{
		if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(playerVO->GetGlobeReference()))
			{
				FGeodeticCoord3D playerCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(GetActorLocation());

				if (VRMovement->GetWorldTransformOverride().Equals(FTransform::Identity))
				{
					// current: top-down | desired: first person
					FTransform surfaceTransform = globeReferenceEllipsoid->GetSurfaceTransform(GetActorLocation());
					VRMovement->SetWorldTransformOverride(surfaceTransform);

					TSet<EMovementType> restrictedMovementTypes;
					restrictedMovementTypes.Add(EMovementType::Globe);

					VRMovement->SetRestrictedMovementTypes(restrictedMovementTypes);

					VRMovement->SetMovementType(EMovementType::Fly);

					Camera->SetWorldRotation(surfaceTransform.GetRotation());
					Camera->SetCameraTransformOverride(surfaceTransform, true);
				}
				else
				{
					// current: first person | desired: top-down
					VRMovement->SetWorldTransformOverride(FTransform::Identity);

					TSet<EMovementType> restrictedMovementTypes;
					restrictedMovementTypes.Add(EMovementType::Walk);
					restrictedMovementTypes.Add(EMovementType::Fly);
					restrictedMovementTypes.Add(EMovementType::Teleport);

					VRMovement->SetRestrictedMovementTypes(restrictedMovementTypes);

					VRMovement->SetMovementType(EMovementType::Globe);

					// change camera to look towards center of Earth
					FQuat rotationToEarthCenter = FRotationMatrix::MakeFromX(FVector(0, 0, 0) - GetActorLocation()).ToQuat();
					Camera->SetWorldRotation(rotationToEarthCenter);

					Camera->SetQuickTurn(0);

					FTransform transform = Camera->GetCameraTransformOverride();
					transform.SetRotation(rotationToEarthCenter);

					Camera->SetCameraTransformOverride(transform, true);
				}

				// todo ohg | fixes the horizon slant after camera change but there's probably a better way to do this
				FTimerHandle timerHandle;
				UDeveloper_Statics::GetVHWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_Pawn::LatentSetCamera, 0.1);

				if (UDeveloper_Subsystem_Core* developerSubsystem = UDeveloper_Subsystem_Core::Get())
				{
					EHardwareInterfaceMode hardwareMode = developerSubsystem->GetHardwareInterfaceMode();
					if (hardwareMode == EHardwareInterfaceMode::VR || hardwareMode == EHardwareInterfaceMode::VREmulation)
					{
						if (UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
						{
							if (ribbonSubsystem->GetRibbonVisible())
							{
								ribbonSubsystem->HideRibbon();

								FTimerHandle timerHandle2;
								GetWorld()->GetTimerManager().SetTimer(timerHandle2, ribbonSubsystem, &UGame_Subsystem_Ribbon::ShowRibbon, 0.25, false);
							}
						}
					}
				}
			}
		}
	}
}

void AGame_Pawn::SetTopdownMode(bool bTopdown)
{
	bool bIdentity = VRMovement->GetWorldTransformOverride().Equals(FTransform::Identity);
	if (bTopdown && !bIdentity || (!bTopdown && bIdentity))
	{
		ToggleGlobeTransform();
	}
}

FGeodeticCoord3D AGame_Pawn::GetPlayerCoordinate() const
{
	return PlayerCoordinate;
}

void AGame_Pawn::UpdateVoipSpatialized()
{
	if (AGame_PlayerState* ps = GetPlayerState<AGame_PlayerState>())
	{
		ps->UpdateVoipSpatialized(!bDespatializeVOIP);
	}

	OnVoipSpatializationUpdated(!bDespatializeVOIP);
}

void AGame_Pawn::SetVoipSpatialized(bool isSpatialized)
{
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		Server_SetVOIPSpatialization(isSpatialized);
	}
	else
	{
		bDespatializeVOIP = !isSpatialized;
		UpdateVoipSpatialized();
	}
}

void AGame_Pawn::TeleportToCoordinate(const FGeodeticCoord3D& coordinate)
{
	if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (UGame_Statics::IsLocalPlayerInTOC())
		{
			playerVO->SetCoord(coordinate, true);
		}
		else
		{
			if (AVH_GlobeReferenceActor* globeReference = playerVO->GetGlobeReference())
			{
				SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));
			}
		}
	}
}

void AGame_Pawn::StartDraggingWorldUI(UUserWidget* userWidget)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		if (AActor* worldUIActor = subsystem->GetUserWidgetWorldUIActor(userWidget))
		{
			if (UVR_MotionControllerComponent* motionController = GetMotionControllerLastClickedOnWidget(userWidget))
			{
				if (AGame_Tool* gameTool = Cast<AGame_Tool>(motionController->GetInputToolStackTop()))
				{
					gameTool->StartDraggingWorldUI(userWidget, worldUIActor);
				}
			}
		}
	}
}

void AGame_Pawn::StopDraggingWorldUI(UUserWidget* userWidget)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		if (AActor* worldUIActor = subsystem->GetUserWidgetWorldUIActor(userWidget))
		{
			worldUIActor->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

			if (UVR_MotionControllerComponent* motionController = GetMotionControllerLastClickedOnWidget(userWidget))
			{
				if (AGame_Tool* gameTool = Cast<AGame_Tool>(motionController->GetInputToolStackTop()))
				{
					gameTool->StopDraggingWorldUI(userWidget, worldUIActor);
				}
			}
		}
	}
}

bool AGame_Pawn::IsDraggingWorldUI() const
{
	if (AGame_Tool* tool = Cast<AGame_Tool>(LeftController->GetInputToolStackTop()))
	{
		if (tool->IsDraggingWorldUI())
		{
			return true;
		}
	}

	if (AGame_Tool* tool = Cast<AGame_Tool>(RightController->GetInputToolStackTop()))
	{
		if (tool->IsDraggingWorldUI())
		{
			return true;
		}
	}

	return false;
}

UVR_MotionControllerComponent* AGame_Pawn::GetMotionControllerForTool(AActor* tool) const
{
	if (LeftController->HasTool(tool))
	{
		return LeftController;
	}
	else if (RightController->HasTool(tool))
	{
		return RightController;
	}

	return nullptr;
}

UVR_MotionControllerComponent* AGame_Pawn::GetMotionControllerLastClickedOnWidget(const UUserWidget* userWidget) const
{
	bool bLeftHovered = false;
	FDateTime lastClickLeft;
	
 	if (AGame_Tool* gameTool = Cast<AGame_Tool>(LeftController->GetInputToolStackTop()))
	{
		if (gameTool->IsHoveringOverUserWidget(userWidget))
		{
			bLeftHovered = true;
			lastClickLeft = gameTool->GetTimeOfLastClick();
		}
	}

	bool bRightHovered = false;
	FDateTime lastClickRight;
	if (AGame_Tool* gameTool = Cast<AGame_Tool>(RightController->GetInputToolStackTop()))
	{
		if (gameTool->IsHoveringOverUserWidget(userWidget))
		{
			bRightHovered = true;
			lastClickRight = gameTool->GetTimeOfLastClick();
		}
	}

	if (bLeftHovered && !bRightHovered)
	{
		return LeftController;
	}
	else if (!bLeftHovered && bRightHovered)
	{
		return RightController;
	}
	else if (bLeftHovered && bRightHovered)
	{
		FTimespan leftDifference = FDateTime::Now() - lastClickLeft;
		FTimespan rightDifference = FDateTime::Now() - lastClickRight;

		if (leftDifference < rightDifference)
		{
			return LeftController;
		}
		
		return RightController;
	}

	return nullptr;
}

void AGame_Pawn::SetModalPopupOpen(bool bOpen, AActor* worldUIActor)
{
	VRMovement->SetAllowMovement(!bOpen);
	
	if (AGame_Tool* gameTool = Cast<AGame_Tool>(LeftController->GetInputToolStackTop()))
	{
		gameTool->SetModalPopupOpen(bOpen, worldUIActor);
	}

	if (AGame_Tool* gameTool = Cast<AGame_Tool>(RightController->GetInputToolStackTop()))
	{
		gameTool->SetModalPopupOpen(bOpen, worldUIActor);
	}
}

bool AGame_Pawn::IsToolClassOnTopOfStack(TSubclassOf<AGame_Tool> toolClass) const
{
	if (AGame_Tool* gameTool = Cast<AGame_Tool>(LeftController->GetInputToolStackTop()))
	{
		if (gameTool->GetClass() == toolClass)
		{
			return true;
		}
	}

	if (AGame_Tool* gameTool = Cast<AGame_Tool>(RightController->GetInputToolStackTop()))
	{
		if (gameTool->GetClass() == toolClass)
		{
			return true;
		}
	}

	return false;
}

void AGame_Pawn::LoadCurrentToolVisualConfiguration()
{
	if (AGame_Tool* gameTool = Cast<AGame_Tool>(LeftController->GetInputToolStackTop()))
	{
		gameTool->LoadCurrentToolVisualConfiguration();
	}

	if (AGame_Tool* gameTool = Cast<AGame_Tool>(RightController->GetInputToolStackTop()))
	{
		gameTool->LoadCurrentToolVisualConfiguration();
	}
}

bool AGame_Pawn::IsPanning() const
{
	if (AGame_Tool* gameTool = Cast<AGame_Tool>(LeftController->GetInputToolStackTop()))
	{
		if (gameTool->IsPanning())
		{
			return true;
		}
	}

	if (AGame_Tool* gameTool = Cast<AGame_Tool>(RightController->GetInputToolStackTop()))
	{
		if (gameTool->IsPanning())
		{
			return true;
		}
	}

	return false;
}

void AGame_Pawn::ReceivePlayerStateAssigned_Implementation(APlayerState* newPlayerState)
{
	// No need for C++ changes for now
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_Pawn::UpdateVisualsForTOCStatus(bool bIsInTOC)
{
	// if local player is in TOC and this player is in world (or vice versa); scale accordingly
	double headScaleMultiplier = 1;
	double callsignScaleMultiplier = 1;

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		bool localPlayerInTOC = playerState->GetIsInTOC();

		if (localPlayerInTOC != bIsInTOC)
		{
			if (localPlayerInTOC)
			{
				// local player is TOC but this player is in the world; scale it down
				headScaleMultiplier = 0.5;
				callsignScaleMultiplier = 0.5;
				
				ReceiveCullMaterialsForTOC(true);
			}
		}
		else
		{
			if (localPlayerInTOC)
			{
				// both in TOC; don't cull
				ReceiveCullMaterialsForTOC(false);
			}
		}
	}

	CameraScalingHead->CustomScaleMultiplier = headScaleMultiplier;
	CameraScalingCallsign->CustomScaleMultiplier = callsignScaleMultiplier;
}

void AGame_Pawn::UpdateCallsignLocation()
{
	// Warning! Dependent on CameraScalingCallsign's scaling; magic numbers abound
	if (!IsLocallyControlled())
	{
		AGame_PlayerState* localPlayerState = UGame_Statics::GetLocalPlayerState();
		AGame_PlayerState* playerState = GetPlayerState<AGame_PlayerState>();
		if (IsValid(localPlayerState) && IsValid(playerState))
		{
			bool localPlayerInTOC = localPlayerState->GetIsInTOC();

			double scaleZ = CameraScalingCallsign->GetRelativeScale3D().Z;
			double offsetZ = 20;

			if (localPlayerInTOC != playerState->GetIsInTOC())
			{
				if (localPlayerInTOC)
				{
					// local player in toc, this player is in world
					offsetZ = 10;
				}
				else
				{
					// local player in world, this player is in TOC
					if (scaleZ < 0.6)
					{
						offsetZ = FMath::Lerp<double>(-1, 20, scaleZ / 0.6f);
					}
					else if (scaleZ > 0.65)
					{
						offsetZ = FMath::Lerp<double>(20, 40, (scaleZ - 0.65) / 1.35f);
					}
				}
			}
			else if (!localPlayerInTOC)
			{
				// both in world
				double distance = FVector::Distance(GetActorLocation(), UGame_Statics::GetVHPlayerPawn()->GetActorLocation());
				if (distance <= 500000)
				{
					if (scaleZ <= 45)
					{
						offsetZ = FMath::Lerp<double>(150, 1250, (scaleZ - 5) / 40.f);
					}
					else if (scaleZ > 45)
					{
						offsetZ = FMath::Lerp<double>(1250, 2000, (scaleZ - 45) / 155.f);
					}
				}
				else
				{
					offsetZ = 0;
				}
			}

			CameraScalingCallsign->SetRelativeLocation(FVector(0, 0, offsetZ));
		}
	}
}

void AGame_Pawn::SetupPlayerState()
{
	if (AGame_PlayerState* playerState = GetPlayerState<AGame_PlayerState>())
	{
		playerState->SetOwningPawn(this);

		ReceiveSetCallsign(playerState->GetCallsign());
		ReceiveSetCollaborationColor(playerState->GetCollaborationColor());
		ReceiveSetIsInTOC(playerState->GetIsInTOC());

		playerState->OnCallsignUpdated.AddUniqueDynamic(this, &AGame_Pawn::HandleCallsignUpdated);
		playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &AGame_Pawn::HandleIsInTOCUpdated);
	}
}

void AGame_Pawn::SetWorldLocationFromCoordinate(const FGeodeticCoord3D& coordinate)
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference())
		{
			FVector worldLocation = globeRef->GeodeticToWorldDouble(coordinate);
			SetActorLocation(worldLocation);
			
			AddSessionPlaybackLocationEvent();
		}
	}
}

void AGame_Pawn::AddSessionPlaybackLocationEvent() const
{
	if (UGame_Statics::IsSessionPlaybackRecording())
	{
		for (const FAddPlaybackEventLocation& playbackLocationDelegate : PlaybackEventLambdasLocation)
		{
			playbackLocationDelegate.Execute(this, PlayerCoordinate);
		}

		if (UGame_SessionPlaybackHandler_Player* handler = Cast<UGame_SessionPlaybackHandler_Player>(UGame_SessionPlayback_Impl::GetHandler(UGame_SessionPlaybackHandler_Player::GetHandlerUIDStatic())))
		{
			handler->AddPawnLocationEvent(this, PlayerCoordinate);
		}
	}
}

void AGame_Pawn::AddSessionPlaybackHeadEvent() const
{
	if (UGame_Statics::IsSessionPlaybackRecording() && AGame_PlayerController::GetPlayerActiveVO() != nullptr)
	{
		if (AController* controller = GetController())
		{
			if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
			{
				if (AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference())
				{
					FVector headLocation;
					FRotator headRotation;
					controller->GetPlayerViewPoint(headLocation, headRotation);

					for (const FAddPlaybackEventHead& playbackDelegate : PlaybackEventLambdasHead)
					{
						playbackDelegate.Execute(this, headRotation);
					}

					if (UGame_SessionPlaybackHandler_Player* handler = Cast<UGame_SessionPlaybackHandler_Player>(UGame_SessionPlayback_Impl::GetHandler(UGame_SessionPlaybackHandler_Player::GetHandlerUIDStatic())))
					{
						handler->AddHeadPositionEvent(this, headRotation.Quaternion());
					}
				}
			}
		}
	}
}

void AGame_Pawn::AddSessionPlaybackControllerOffsetEvent(const FString& controllerName, const FTransform& controllerRelativeTransform) const
{
	if (UGame_Statics::IsSessionPlaybackRecording())
	{
		for (const FAddPlaybackEventController& playbackDelegate : PlaybackEventLambdasController)
		{
			playbackDelegate.Execute(this, controllerName, controllerRelativeTransform);
		}

		if (UGame_SessionPlaybackHandler_Player* handler = Cast<UGame_SessionPlaybackHandler_Player>(UGame_SessionPlayback_Impl::GetHandler(UGame_SessionPlaybackHandler_Player::GetHandlerUIDStatic())))
		{
			handler->AddControllerOffsetEvent(this, controllerName, controllerRelativeTransform);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Pawn::HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode)
{
	switch (newMode)
	{
		case EHardwareInterfaceMode::Unknown:
		case EHardwareInterfaceMode::Desktop:
		{
			FRotator cameraRotation = Camera->GetRelativeRotation();
			cameraRotation.Roll = 0;

			Camera->SetRelativeRotation(cameraRotation);
			Camera->SetRelativeLocation(FVector(0, 0, 0));

			CameraSceneRelativeLocation = DesktopRelativeCamera;

			if (IsValid(DesktopHUDClass))
			{
				if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
				{
					subsystem->OpenWithDefaultsByClass(DesktopHUDClass);
				}
			}
		}
		break;

		case EHardwareInterfaceMode::VREmulation:
		{
			CameraSceneRelativeLocation = DesktopRelativeCamera;
		}
		break;

		case EHardwareInterfaceMode::VR:
		{
			CameraSceneRelativeLocation = VRRelativeCamera;
		}
		break;
	}

	OnRep_CameraSceneRelativeLocation();

	Server_SetCameraSceneRelativeLocation(CameraSceneRelativeLocation);
}

void AGame_Pawn::HandleMovementTypeChanged(EMovementType movementType)
{
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	switch (movementType)
	{
		case EMovementType::Walk:
		case EMovementType::Teleport:
		case EMovementType::None:
		{
			Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
			Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
			Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
			Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
		}
		break;
	}
}

void AGame_Pawn::HandleCallsignUpdated(const FString& callsign, FLinearColor collaborationColor)
{
	ReceiveSetCallsign(callsign);
	
	ReceiveSetCollaborationColor(collaborationColor);
}

void AGame_Pawn::HandleIsInTOCUpdated(bool bIsInTOC)
{
	ReceiveSetIsInTOC(bIsInTOC);

	if (IsLocallyControlled())
	{
		// update visuals
		TArray<AActor*> actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGame_Pawn::StaticClass(), actors);
		for (AActor* actor : actors)
		{
			if (AGame_Pawn* pawn = Cast<AGame_Pawn>(actor))
			{
				if (pawn != this)
				{
					if (AGame_PlayerState* playerState = pawn->GetPlayerState<AGame_PlayerState>())
					{
						pawn->UpdateVisualsForTOCStatus(playerState->GetIsInTOC());
					}

					// non-local pawns need an update because they're still in the world location from before local pawn moved to world/TOC
					pawn->OnRep_PlayerCoordinate();
				}
			}
		}		
	}
	else
	{
		UpdateVisualsForTOCStatus(bIsInTOC);
	}

	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			FTransform worldTransformOverride = VRMovement->GetWorldTransformOverride();
			worldTransformOverride.SetLocation(FVector(0, 0, 0));

			FQuat cameraLocal = worldTransformOverride.InverseTransformRotation(Camera->GetComponentQuat());

			FRotator newLocalRotation;

			if (bIsInTOC)
			{
				newLocalRotation.Pitch = 0;
				newLocalRotation.Yaw = 0;
			}
			else
			{
				newLocalRotation.Pitch = FMath::Clamp<float>(Camera->GetComponentRotation().Pitch, -89.9, 89.9);;
				newLocalRotation.Yaw = Camera->GetComponentRotation().Yaw;
			}

			newLocalRotation.Roll = 0;
			
			FQuat modifiedCameraLocal = newLocalRotation.Quaternion();

			FQuat modifiedCameraWorld = worldTransformOverride.TransformRotation(modifiedCameraLocal);

			Camera->SetWorldRotation(modifiedCameraWorld);

			Camera->SetCameraTransformOverride(FTransform::Identity, true);
		}
	}
}

void AGame_Pawn::PeriodicUpdateNonLocalPosition()
{
	if (!IsLocallyControlled())
	{
		OnRep_HeadTransform();
	
		OnRep_PlayerCoordinate();
	
		OnRep_PawnRotation();
	}
}

void AGame_Pawn::PeriodicUpdateInitialLocation()
{
	if (UGame_TutorialManager* tutorialManager = UGame_TutorialManager::Get())
	{
		if (tutorialManager->IsInTutorial())
		{
			return;
		}
	}

	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
			{
				if (bStartAtLastLocation)
				{
					bool bInTOC = UGame_Statics::IsLocalPlayerInTOC();

					FGeodeticCoord3D playerCoordinate;
					if (bInTOC)
					{
						playerCoordinate = globeReference->WorldToGeodeticDouble(virtualObjective->GetViewpointActor()->GetActorLocation());
					}
					else
					{
						playerCoordinate = globeReference->WorldToGeodeticDouble(GetActorLocation());
					}

					gameSettings->StoreSettingString(TEXT("InitialRotation"), Camera->GetComponentRotation().ToString());
					gameSettings->StoreSettingString(TEXT("InitialCoordinate"), FString::Printf(TEXT("%f, %f, %f"), playerCoordinate.Longitude, playerCoordinate.Latitude, playerCoordinate.Altitude));
					gameSettings->StoreSettingBool(TEXT("bInitialInTOC"), bInTOC);
				}
			}
		}
	}
}

void AGame_Pawn::PeriodicUpdatePlayerCoordinate()
{
	if (IsLocallyControlled())
	{
		AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO();
		if (!IsValid(virtualObjective))
		{
			return;
		}

		if (bReplicateGeoLocation)
		{
			if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
			{
				// rotation | replicate pitch and bearing in a rotator
				FRotator toReplicate;
				FRotator pawnRotation = GetActorRotation();

				toReplicate.Yaw = globeReference->WorldRotationToBearing(pawnRotation);
				toReplicate.Pitch = globeReference->WorldRotationToPitch(pawnRotation);
				toReplicate.Roll = 0;

				if (!PawnRotation.Equals(toReplicate))
				{
					PawnRotation = toReplicate;

					Server_SetPawnRotation(toReplicate);
				}

				// location | replicate longitude, latitude, hae
				FGeodeticCoord3D playerCoordinate = globeReference->WorldToGeodeticDouble(GetActorLocation());

				if (!(PlayerCoordinate == playerCoordinate))
				{
					PlayerCoordinate = playerCoordinate;

					Server_SetPlayerCoordinate(PlayerCoordinate);

					AddSessionPlaybackLocationEvent();
				}
			}
		}

		// head
		if (AController* controller = GetController())
		{
			if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
			{
				// package coordinate and bearing/pitch into transform for replication
				FTransform headTransform;

				FGeodeticCoord3D headCoordinate = globeReference->WorldToGeodeticDouble(Camera->GetComponentLocation());

				headTransform.SetLocation(headCoordinate.ToVector());

				FRotator cameraRotation = Camera->GetComponentRotation();
				FRotator toReplicate;
				toReplicate.Yaw = globeReference->WorldRotationToBearing(cameraRotation);
				toReplicate.Pitch = globeReference->WorldRotationToPitch(cameraRotation);
				toReplicate.Roll = 0;

				headTransform.SetRotation(toReplicate.Quaternion());

				if (!headTransform.Equals(HeadTransform))
				{
					Server_SetHeadTransform(headTransform);

					AddSessionPlaybackHeadEvent();
				}
			}
		}

		if (IsValid(LeftController))
		{
			AddSessionPlaybackControllerOffsetEvent(LeftController->GetName(), LeftController->GetRelativeTransform());
		}

		if (IsValid(RightController))
		{
			AddSessionPlaybackControllerOffsetEvent(RightController->GetName(), RightController->GetRelativeTransform());
		}
	}
}

void AGame_Pawn::HandleBoolSettingStored(const FString& setting, bool bValue)
{
	if (setting.Equals(TEXT("bStartAtLastLocation")))
	{
		bStartAtLastLocation = bValue;
	}
}

void AGame_Pawn::LatentSetCamera()
{
	FTransform worldTransformOverride = FTransform::Identity;
	worldTransformOverride = VRMovement->GetWorldTransformOverride();

	worldTransformOverride.SetLocation(FVector(0, 0, 0));

	FVector2D value = FVector2D(0, 0);

	FQuat cameraLocal = worldTransformOverride.InverseTransformRotation(Camera->GetComponentQuat());

	FRotator newLocalRotation;
	newLocalRotation.Pitch = FMath::Clamp<float>(cameraLocal.Rotator().Pitch + value.Y, -89.9, 89.9);
	newLocalRotation.Yaw = cameraLocal.Rotator().Yaw + value.X;
	newLocalRotation.Roll = 0;
		
	FQuat modifiedCameraLocal = newLocalRotation.Quaternion();
	
	FQuat modifiedCameraWorld = worldTransformOverride.TransformRotation(modifiedCameraLocal);
	
	Camera->SetWorldRotation(modifiedCameraWorld);
}