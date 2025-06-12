// Required Includes
#include "Game_MovementComponent.h"
#include "Game.h"

// Engine Includes
#include "Kismet/GameplayStatics.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "TimerManager.h"

// VH Plugin Includes
#include "Developer_Subsystem_Operation.h"
#include "VR_TraceComponent.h"
#include "VR_MotionControllerComponent.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_Subsystem_Core.h"
#include "Game_TutorialManager.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_Tool.h"
#include "Game_Operation_Drag_Teleport.h"
#include "Game_Subsystem_Ribbon.h"
#include "Game_TOCTable.h"
#include "Game_PlayerController.h"
#include "Game_MotionControllerComponent.h"
#include "Game_VirtualObjective.h"
#include "Game_GlobeReferenceActor_Ellipsoid.h"
#include "Game_CameraComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MovementComponent::UGame_MovementComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	MaxSettingsMovementMultiplier = 1;

	MinSpeedTOC = 400;
	MaxSpeedTOC = 1200;

	MinSpeedENU = 2000;
	MaxSpeedENU = 60000;

	MinSpeedEllipsoid0 = 25000;
	MaxSpeedEllipsoid0 = 80000000;

	MinSpeedEllipsoid1 = 1000000;
	MaxSpeedEllipsoid1 = 240000000;

	TeleportZOffset = 72;

	bHandleIsInTOCUpdates = true;

	MovementInputMapPriority = 0;

	bInstantAcceleration = true;
	bInstantDeceleration = true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MovementComponent::BeginPlay()
{
	Super::BeginPlay();

	ResetSettingMovementMultiplier();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->OnDoubleSettingStored.AddDynamic(this, &UGame_MovementComponent::HandleDoubleSettingStored);
	}

	MaxSpeed = FMath::Lerp(MinSpeedTOC, MaxSpeedTOC, SettingsMovementMultiplier);

	BindToPlayerState();

	BindInputActions();
}

void UGame_MovementComponent::PostSetWorldTransformOverride(const FTransform& worldTransformOverride)
{
	ResetMaxSpeed();
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MovementComponent::SetMovementType(EMovementType newMovementType)
{
	if (RestrictedMovementTypes.Contains(newMovementType))
	{
		return;
	}

	if (UInputMappingContext** oldMapsPtr = MovementInputMaps.Find(MovementType))
	{	
		UGame_Statics::UnregisterInputMap(*oldMapsPtr);
	}

	// clear ongoing teleport (if any)
	if (DragTeleportOperation != nullptr)
	{
		if (UDeveloper_Subsystem_Operation* subsystem = UDeveloper_Subsystem_Operation::Get())
		{
			subsystem->StopOperation(DragTeleportOperation);

			DragTeleportOperation = nullptr;
		}
	}

	if (TeleportPreviewActor != nullptr)
	{
		TeleportPreviewActor->Destroy();
		TeleportPreviewActor = nullptr;
	}

	TeleportingController = nullptr;


	UGame_TutorialManager* tutorialManager = UGame_TutorialManager::Get();

	switch (newMovementType)
	{
		case EMovementType::Walk:
		{
			Gravity = FVector(0, 0, -500000);

			MovementDirectionMultiplier = FVector(1, 1, 0);

			tutorialManager->TutorialActionOccurred(TEXT("movementMode_Walk"));
		}
		break;

		case EMovementType::Fly:
		{
			Gravity = FVector(0, 0, 0);

			MovementDirectionMultiplier = FVector(1, 1, 1);

			tutorialManager->TutorialActionOccurred(TEXT("movementMode_Fly"));
		}
		break;

		case EMovementType::Globe:
		{
			Gravity = FVector(0, 0, 0);

			MovementDirectionMultiplier = FVector(1, 1, 1);

			tutorialManager->TutorialActionOccurred(TEXT("movementMode_Globe"));
		}
		break;

		case EMovementType::Teleport:
		{
			Gravity = FVector(0, 0, 0);

			tutorialManager->TutorialActionOccurred(TEXT("movementMode_Teleport"));
		}
		break;

		case EMovementType::None:
		{
			Gravity = FVector(0, 0, 0);

			MovementDirectionMultiplier = FVector(0, 0, 0);
		}
		break;
	}

	FTransform overrideNoLocation = GetWorldTransformOverride();
	overrideNoLocation.SetLocation(FVector(0, 0, 0));

	Gravity = overrideNoLocation.TransformPosition(Gravity);

	MovementType = newMovementType;

	if (UInputMappingContext** newMapsPtr = MovementInputMaps.Find(MovementType))
	{
		UGame_Statics::RegisterInputMap(*newMapsPtr, MovementInputMapPriority);
	}

	OnMovementTypeChanged.Broadcast(MovementType);
}

EMovementType UGame_MovementComponent::GetMovementType() const
{
	return MovementType;
}

void UGame_MovementComponent::SetRestrictedMovementTypes(const TSet<EMovementType>& restrictedMovementTypes)
{
	RestrictedMovementTypes.Empty();

	RestrictedMovementTypes.Append(restrictedMovementTypes);

	if (UGame_Subsystem_Ribbon* subsystem = UGame_Subsystem_Ribbon::Get())
	{
		subsystem->SetButtonEnabledCondition("MovementTypeDisabledWalk", RestrictedMovementTypes.Contains(EMovementType::Walk), false);
		subsystem->SetButtonEnabledCondition("MovementTypeDisabledFly", RestrictedMovementTypes.Contains(EMovementType::Fly), false);
		subsystem->SetButtonEnabledCondition("MovementTypeDisabledGlobe", RestrictedMovementTypes.Contains(EMovementType::Globe), false);
		subsystem->SetButtonEnabledCondition("MovementTypeDisabledTP", RestrictedMovementTypes.Contains(EMovementType::Teleport));
	}
}

void UGame_MovementComponent::SetSettingMovementMultiplier(double movementMultiplier)
{
	SettingsMovementMultiplier = FMath::Clamp<double>(movementMultiplier, 0, MaxSettingsMovementMultiplier);
}

double UGame_MovementComponent::GetSettingMovementMultiplier()
{
	return SettingsMovementMultiplier;
}

void UGame_MovementComponent::ResetSettingMovementMultiplier()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		SetSettingMovementMultiplier(gameSettings->GetSettingDouble("MovementSpeed"));
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_MovementComponent::ResetSettingMovementMultiplier, 0.1, false);
	}
}

void UGame_MovementComponent::SetAllowMovement(bool bAllowMovement)
{
	if (!bAllowMovement)
	{
		Gravity = FVector(0, 0, 0);

		MovementDirectionMultiplier = FVector(0, 0, 0);
	}
	else
	{
		SetMovementType(MovementType);
	}
}

void UGame_MovementComponent::ResetMaxSpeed()
{
	ResetSettingMovementMultiplier();

	if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			if (playerState->GetIsInTOC())
			{
				MaxSpeed = FMath::Lerp(MinSpeedTOC, MaxSpeedTOC, SettingsMovementMultiplier);
			}
			else if (!GetWorldTransformOverride().Equals(FTransform::Identity))
			{
				MaxSpeed = FMath::Lerp(MinSpeedENU, MaxSpeedENU, SettingsMovementMultiplier);
			}
			else
			{
				if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(playerVO->GetGlobeReference()))
				{
					double alpha = SettingsMovementMultiplier;
					double minSpeed = FMath::Lerp(MinSpeedEllipsoid0, MinSpeedEllipsoid1, alpha);
					double maxSpeed = FMath::Lerp(MaxSpeedEllipsoid0, MaxSpeedEllipsoid1, alpha);

					FGeodeticCoord3D playerCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(GetOwner()->GetActorLocation());

					alpha = 1;
					double terrainHAE = globeReferenceEllipsoid->GetTerrainElevationDouble(playerCoordinate.ToGeodeticCoord2D());
					if (!FMath::IsNearlyEqual(terrainHAE, -999999.f))
					{
						double metersAGL = playerCoordinate.Altitude - terrainHAE;

						if (metersAGL < 1000000)
						{
							alpha = metersAGL / 1000000.0;
						}
					}

					MaxSpeed = FMath::Lerp(minSpeed, maxSpeed, alpha);
				}
			}
		}
	}
}

bool UGame_MovementComponent::GetTeleportDragLocation(AGame_Tool* teleportingTool, FVector& dragLocation) const
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		if (playerState->GetIsInTOC())
		{
			APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

			FVector start;
			FVector end;
			teleportingTool->VRTrace->GetStartAndEnd(start, end);

			FCollisionQueryParams queryParams(NAME_None, true);
			queryParams.AddIgnoredActor(playerPawn);

			FHitResult hitResultStatic;
			GetWorld()->LineTraceSingleByChannel(hitResultStatic, start, end, ECC_WorldStatic, queryParams);

			FHitResult hitResultTeleport;
			GetWorld()->LineTraceSingleByChannel(hitResultTeleport, start, end, TOCTeleportCollisionChannel, queryParams);

			if (hitResultTeleport.bBlockingHit)
			{
				if (hitResultStatic.bBlockingHit)
				{
					double staticDistance = FVector::Distance(hitResultStatic.Location, playerPawn->GetActorLocation());
					double teleportDistance = FVector::Distance(hitResultTeleport.Location, playerPawn->GetActorLocation());

					// if the world static trace hits something, only allow if the teleport trace hits the same or closer
					if (hitResultStatic.Location.Equals(hitResultTeleport.Location) || (teleportDistance < staticDistance))
					{
						if (AGame_TOCTable* tocTable = GetTOCTable())
						{
							FVector2D testVector;
							testVector.X = hitResultTeleport.Location.X;
							testVector.Y = hitResultTeleport.Location.Y;

							if (UGame_Statics::IsPointInBox(testVector, tocTable->ReceiveGetBoundsForTeleport()))
							{
								return false;
							}
						}

						dragLocation = hitResultTeleport.Location;

						return true;
					}
				}
				else
				{
					// if world static misses, allow where the teleport trace hit
					dragLocation = hitResultTeleport.Location;

					return true;
				}
			}
		}
		else
		{
			if (teleportingTool->GetInteractionHitLocation(dragLocation))
			{
				return true;
			}
		}
	}
	
	return false;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_MovementComponent::BindToPlayerState()
{
	if (bHandleIsInTOCUpdates)
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			if (playerState->GetIsInTOC())
			{
				TSet<EMovementType> retrictedMovementTypes;

				retrictedMovementTypes.Add(EMovementType::Fly);
				retrictedMovementTypes.Add(EMovementType::Globe);

				SetRestrictedMovementTypes(retrictedMovementTypes);
			}

			playerState->OnIsInTOCUpdated.AddDynamic(this, &UGame_MovementComponent::HandleIsInTOCUpdated);
		}
		else
		{
			FTimerHandle timerHandle;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_MovementComponent::BindToPlayerState, 0.5, false);
		}
	}
}

void UGame_MovementComponent::BindInputActions()
{
	if (APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		if (UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(playerController->InputComponent))
		{
			inputComponent->BindAction(WalkMoveInputAction, ETriggerEvent::Triggered, this, &UGame_MovementComponent::HandleWalkMove);
			inputComponent->BindAction(FlyMoveInputAction, ETriggerEvent::Triggered, this, &UGame_MovementComponent::HandleFlyMove);
			inputComponent->BindAction(FlyElevationInputAction, ETriggerEvent::Triggered, this, &UGame_MovementComponent::HandleFlyElevation);
			inputComponent->BindAction(TeleportInitiateLeftInputAction, ETriggerEvent::Triggered, this, &UGame_MovementComponent::HandleTeleportLeftInitiate);
			inputComponent->BindAction(TeleportFinalizeLeftInputAction, ETriggerEvent::Triggered, this, &UGame_MovementComponent::HandleTeleportLeftFinalize);
			inputComponent->BindAction(TeleportInitiateRightInputAction, ETriggerEvent::Triggered, this, &UGame_MovementComponent::HandleTeleportRightInitiate);
			inputComponent->BindAction(TeleportFinalizeRightInputAction, ETriggerEvent::Triggered, this, &UGame_MovementComponent::HandleTeleportRightFinalize);
		}
	}
}

AGame_TOCTable* UGame_MovementComponent::GetTOCTable() const
{
	if (TOCTable == nullptr)
	{
		TArray<AActor*> actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGame_TOCTable::StaticClass(), actors);

		if (actors.Num() > 0)
		{
			TOCTable = Cast<AGame_TOCTable>(actors[0]);
		}
	}

	return TOCTable;
}

void UGame_MovementComponent::InternalMove(const FVector& localDirection)
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(playerVO->GetGlobeReference()))
			{
				if (GetWorldTransformOverride().Equals(FTransform::Identity))
				{
					// player is orbiting the Earth (ECEF); movement moves player around the Earth

					FVector inputVectorNormal;
					if (localDirection.X == 0 && localDirection.Y == 0)
					{
						// if only moving in local Z; move directly away or towards center of the Earth
						// avoids rounding errors in the else block below
						FVector playerLocation = playerPawn->GetActorLocation();

						 inputVectorNormal = localDirection.Z < 0 ? -playerLocation.GetSafeNormal() : playerLocation.GetSafeNormal();
					}
					else
					{
						// movement on X is mapped to latitude
						// movement on Y is mapped to longitude
						// movement on Z moves closer or further from surface of Earth
						FGeodeticCoord3D playerCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(playerPawn->GetActorLocation());

						FGeodeticCoord3D desiredCoordinate = playerCoordinate;
						desiredCoordinate.Latitude += localDirection.X;
						desiredCoordinate.Longitude += localDirection.Y;
						desiredCoordinate.Altitude += localDirection.Z;

						inputVectorNormal = (globeReferenceEllipsoid->GeodeticToWorldDouble(desiredCoordinate) - playerPawn->GetActorLocation()).GetSafeNormal();
						
					}

					AddInputVector(inputVectorNormal, false);
					
					ResetMaxSpeed();

					return;
				}
			}
		}

		// non-ellipsoid movement
		if (localDirection.Equals(FVector(0, 0, 1)) || localDirection.Equals(FVector(0, 0, -1)))
		{
			AddInputVector(localDirection, false);
		}
		else
		{
			// when close to surface of Earth or in the TOC, move in direction of tool (transformed by WorldTransformOverride)
			FQuat cameraRotation = cameraRotation = playerPawn->Camera->GetComponentQuat();

			FTransform transform;
			if (OnOverrideMovementTransform.IsBound())
			{
				transform = OnOverrideMovementTransform.Execute();
			}
			else
			{
				transform.SetComponents(cameraRotation, playerPawn->GetActorLocation(), FVector(1, 1, 1));
			}

			FVector worldForward = transform.TransformPosition(localDirection);

			FVector worldInputVector = (worldForward - transform.GetLocation()).GetSafeNormal();

			FTransform overrideNoLocation = GetWorldTransformOverride();
			overrideNoLocation.SetLocation(FVector(0, 0, 0));

			FVector inputVector = overrideNoLocation.InverseTransformPosition(worldInputVector);

			AddInputVector(inputVector, false);
		}
	}
}

void UGame_MovementComponent::TeleportInitiate(UVR_MotionControllerComponent* requestingController)
{
	if (UGame_TutorialManager* tutorialManager = UGame_TutorialManager::Get())
	{
		tutorialManager->TutorialActionOccurred(TEXT("teleportKeyDown"));
	}

	if (TeleportingController == nullptr && DragTeleportOperation == nullptr)
	{
		if (AGame_Tool* teleportingTool = Cast<AGame_Tool>(requestingController->GetInputToolStackTop()))
		{
			if (UDeveloper_Subsystem_Operation* subsystem = UDeveloper_Subsystem_Operation::Get())
			{
				FVector teleportDragLocation;
				if (GetTeleportDragLocation(teleportingTool, teleportDragLocation))
				{
					teleportingTool->GetInteractionHitLocation(teleportDragLocation);

					FActorSpawnParameters spawnParameters;
					spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
					spawnParameters.Owner = GetOwner();

					TeleportPreviewActor = GetWorld()->SpawnActor<AActor>(TeleportPreviewClass, spawnParameters);
					TeleportPreviewActor->SetActorLocation(teleportDragLocation);

					if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
					{
						FVector playerLocation;
						FRotator playerRotation;
						playerController->GetPlayerViewPoint(playerLocation, playerRotation);

						TeleportPreviewActor->SetActorRotation(playerRotation);
					}

					TeleportingController = requestingController;

					DragTeleportOperation = Cast<UGame_Operation_Drag_Teleport>(subsystem->StartOperationByClass(DragTeleportOperationClass, 0));
					DragTeleportOperation->StartDrag(TeleportPreviewActor, teleportingTool, 0);
				}
			}
		}
	}
}

void UGame_MovementComponent::TeleportFinalize(UVR_MotionControllerComponent* requestingController)
{
	if (TeleportingController == requestingController)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			playerPawn->SetActorLocation(TeleportPreviewActor->GetActorLocation() + FVector(0, 0, TeleportZOffset));

			FRotator rotation;
			FVector location;

			// camera
			UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(rotation, location);
			UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition(TeleportPreviewActor->GetActorRotation().Yaw, EOrientPositionSelector::Orientation);
		}

		if (DragTeleportOperation != nullptr)
		{
			if (UDeveloper_Subsystem_Operation* subsystem = UDeveloper_Subsystem_Operation::Get())
			{
				subsystem->StopOperation(DragTeleportOperation);

				DragTeleportOperation = nullptr;
			}
		}

		if (TeleportPreviewActor != nullptr)
		{
			TeleportPreviewActor->Destroy();
			TeleportPreviewActor = nullptr;
		}

		TeleportingController = nullptr;
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_MovementComponent::HandleDoubleSettingStored(const FString& settingName, double value)
{
	if (settingName.Equals(TEXT("MovementSpeed")))
	{
		SetSettingMovementMultiplier(value);

		ResetMaxSpeed();
	}
}

void UGame_MovementComponent::HandleIsInTOCUpdated(bool bIsInTOC)
{
	ResetSettingMovementMultiplier();

	UEnhancedInputLocalPlayerSubsystem* inputSubsystem = nullptr;

	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
	}
	
	if (bIsInTOC)
	{
		TSet<EMovementType> restrictedMovementTypes;

		restrictedMovementTypes.Add(EMovementType::Fly);
		restrictedMovementTypes.Add(EMovementType::Globe);

		SetRestrictedMovementTypes(restrictedMovementTypes);

		ResetMaxSpeed();
		
		SetMovementType(EMovementType::Walk);

		if (IsValid(inputSubsystem))
		{
			inputSubsystem->RemoveMappingContext(WorldInputMap);

			if (TOCInputMap != nullptr)
			{
				inputSubsystem->AddMappingContext(TOCInputMap, 0);
			}
		}
	}
	else
	{
		TSet<EMovementType> restrictedMovementTypes;
		SetRestrictedMovementTypes(restrictedMovementTypes);

		SetMovementType(EMovementType::Fly);

		ResetMaxSpeed();
		
		if (IsValid(inputSubsystem))
		{
			inputSubsystem->RemoveMappingContext(TOCInputMap);

			if (WorldInputMap != nullptr)
			{
				inputSubsystem->AddMappingContext(WorldInputMap, 0);
			}
		}
	}
}

void UGame_MovementComponent::HandleWalkMove(const FInputActionValue& inputActionValue)
{
	if (APawn* pawn = Cast<APawn>(GetOwner()))
	{
		if (!pawn->InputEnabled())
		{
			return;
		}
	}

	InternalMove(FVector(inputActionValue.Get<FVector2D>(), 0));
}

void UGame_MovementComponent::HandleFlyMove(const FInputActionValue& inputActionValue)
{
	if (APawn* pawn = Cast<APawn>(GetOwner()))
	{
		if (!pawn->InputEnabled())
		{
			return;
		}
	}

	InternalMove(FVector(inputActionValue.Get<FVector2D>(), 0));
}

void UGame_MovementComponent::HandleFlyElevation(const FInputActionValue& inputActionValue)
{
	if (APawn* pawn = Cast<APawn>(GetOwner()))
	{
		if (!pawn->InputEnabled())
		{
			return;
		}
	}

	bool bAllowMovement = true;

	float value = inputActionValue.Get<float>();

	// don't allow further zoom out if reached max zoom distance
	if (value > 0)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
			{
				if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(playerVO->GetGlobeReference()))
				{
					if (AGame_Tool* tool = Cast<AGame_Tool>(playerPawn->LeftController->GetInputToolStackTop()))
					{
						FGeodeticCoord3D playerCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(playerPawn->GetActorLocation());

						double playerTerrainHAE = globeReferenceEllipsoid->GetTerrainElevationDouble(playerCoordinate.ToGeodeticCoord2D());
						if (!FMath::IsNearlyEqual(playerTerrainHAE, -999999.f))
						{
							double playerAGL = playerCoordinate.Altitude - playerTerrainHAE;

							bAllowMovement = playerCoordinate.Altitude * 100 < tool->VRTrace->TraceDistance - 200000000;
						}
					}
				}
			}
		}
	}

	if (bAllowMovement)
	{
		InternalMove(FVector(0, 0, value));
	}
}

void UGame_MovementComponent::HandleTeleportLeftInitiate()
{
	if (APawn* pawn = Cast<APawn>(GetOwner()))
	{
		if (!pawn->InputEnabled())
		{
			return;
		}
	}

	if (AGame_Pawn* pawn = UGame_Statics::GetVHPlayerPawn())
	{
		TeleportInitiate(pawn->LeftController);
	}
}

void UGame_MovementComponent::HandleTeleportLeftFinalize()
{
	if (AGame_Pawn* pawn = UGame_Statics::GetVHPlayerPawn())
	{
		TeleportFinalize(pawn->LeftController);
	}
}

void UGame_MovementComponent::HandleTeleportRightInitiate()
{
	if (APawn* pawn = Cast<APawn>(GetOwner()))
	{
		if (!pawn->InputEnabled())
		{
			return;
		}
	}

	if (AGame_Pawn* pawn = UGame_Statics::GetVHPlayerPawn())
	{
		TeleportInitiate(pawn->RightController);
	}
}

void UGame_MovementComponent::HandleTeleportRightFinalize()
{
	if (AGame_Pawn* pawn = UGame_Statics::GetVHPlayerPawn())
	{
		TeleportFinalize(pawn->RightController);
	}
}