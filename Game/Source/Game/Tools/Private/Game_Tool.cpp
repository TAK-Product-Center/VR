// Required Includes
#include "Game_Tool.h"
#include "Game.h"

// Engine Includes
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerState.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "InputAction.h"
#include "TimerManager.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"
#include "Developer_Subsystem_Selection.h"
#include "VR_MotionControllerComponent.h"
#include "VR_TraceComponent.h"
#include "VR_Statics.h"
#include "VR_WidgetInteractionComponent.h"
#include "Interface_UI_ContextMenuSource.h"
#include "Keyboard_Subsystem_Core.h"
#include "UI_Subsystem_ContextMenu.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_Subsystem_Gizmo.h"
#include "Game_GameState.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerState.h"
#include "Game_TerrainTile.h"
#include "Game_Subsystem_Core.h"
#include "Game_Database_ToolVisual.h"
#include "Game_MotionControllerComponent.h"
#include "Game_CameraComponent.h"
#include "Game_GameInstance.h"
#include "Game_GlobeReferenceActor_Ellipsoid.h"
#include "Game_TileManager.h"
#include "Game_Subsystem_Ribbon.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Tool::AGame_Tool(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	DefaultBeamColor(FLinearColor::Green)
{
	USceneComponent* rootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(rootComponent);

	MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMesh"));
	MainMesh->SetupAttachment(rootComponent);
	MainMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MainMesh->SetIsReplicated(true);

	BeamMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BeamMesh"));
	BeamMesh->SetupAttachment(rootComponent);
	BeamMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BeamMesh->SetIsReplicated(true);
	
	VRTrace = CreateDefaultSubobject<UVR_TraceComponent>(TEXT("VRTrace"));
	VRTrace->SetupAttachment(rootComponent);
	VRTrace->TraceDistance = 1000000000;

	WidgetInteraction = CreateDefaultSubobject<UVR_WidgetInteractionComponent>(TEXT("VRWidgetInteraction"));
	WidgetInteraction->SetupAttachment(rootComponent);
	WidgetInteraction->InteractionDistance = 1000000000;

	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
}

// ---------------------------------
// --- Replication
// ---------------------------------

void AGame_Tool::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AGame_Tool, BeamColor, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(AGame_Tool, OwnerHardwareInterfaceMode, COND_SkipOwner);
}

void AGame_Tool::OnRep_OwnerHardwareInterfaceMode()
{
	bool bDesktopMode = OwnerHardwareInterfaceMode == EHardwareInterfaceMode::Desktop;

	MainMesh->SetHiddenInGame(bDesktopMode);
	BeamMesh->SetHiddenInGame(true);
}

void AGame_Tool::Server_SetBeamColor_Implementation(const FLinearColor& color)
{
	BeamColor = color;

	if (GetNetMode() == NM_ListenServer && !IsLocallyOwned())
	{
		OnRep_BeamColor();
	}
}

void AGame_Tool::OnRep_BeamColor()
{
	if (BeamMaterial != nullptr)
	{
		BeamMaterial->SetVectorParameterValue(TEXT("Color"), BeamColor);
	}
}

void AGame_Tool::Server_SyncToToolVisualization_Implementation(const FSpatialiteResult_BP& result)
{
	SyncToToolVisualization(result.Result);
}

void AGame_Tool::Server_SetOwnerHardwareInterfaceMode_Implementation(EHardwareInterfaceMode hardwareInterfaceMode)
{
	OwnerHardwareInterfaceMode = hardwareInterfaceMode;

	if (GetNetMode() == NM_ListenServer && !IsLocallyOwned())
	{
		OnRep_OwnerHardwareInterfaceMode();
	}
}

// ---------------------------------
// --- Interface_VR_Tool
// ---------------------------------

void AGame_Tool::AddedToInputToolStack_Implementation(UVR_MotionControllerComponent* motionControllerComponent)
{
	AttachToComponent(motionControllerComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

	VRTrace->UpdateTrace();

	if (IsLocallyOwned())
	{
		LoadCurrentToolVisualConfiguration();

		if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
		{
			HandleHardwareInterfaceModeChanged(subsystem->GetHardwareInterfaceMode(), EHardwareInterfaceMode::Unknown);

			subsystem->OnHardwareInterfaceModeChanged.AddUniqueDynamic(this, &AGame_Tool::HandleHardwareInterfaceModeChanged);
		}
	}

	if (GetNetMode() == NM_Standalone || GetNetMode() == NM_ListenServer)
	{
		UVR_Statics::SetWidgetInteractionIndices(WidgetInteraction);

		GetOwner()->OnDestroyed.AddDynamic(this, &AGame_Tool::HandleOwnerDisconnected);
	}

	WidgetInteraction->ForceWidgetPathUpdate();
}

void AGame_Tool::RemovedFromInputToolStack_Implementation(UVR_MotionControllerComponent* motionControllerComponent)
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	if (GetNetMode() == NM_Standalone || GetNetMode() == NM_ListenServer)
	{
		WidgetInteraction->Deactivate();
		
		GetOwner()->OnDestroyed.RemoveDynamic(this, &AGame_Tool::HandleOwnerDisconnected);
	}

	Destroy();
}

void AGame_Tool::InputToolStackIndexChanged_Implementation(UVR_MotionControllerComponent* motionControllerComponent, int32 index)
{

}

void AGame_Tool::ActionInput_Implementation(const FInputActionInstance& inputActionInstance)
{
	FString action = inputActionInstance.GetSourceAction()->ActionDescription.ToString();
	ETriggerEvent triggerEvent = inputActionInstance.GetTriggerEvent();
	
	if (CheckInputBlocked())
	{
		return;
	}
	
	if (action.Equals(TEXT("Tool_GlobeZoom"), ESearchCase::IgnoreCase))
	{
		HandleGlobeZoom(inputActionInstance.GetValue());
	}
	else if (action.Equals(TEXT("Tool_ActionModifier"), ESearchCase::IgnoreCase))
	{
		bActionModifier = triggerEvent == ETriggerEvent::Triggered;
	}
	else if (action.Equals(TEXT("Tool_Interact"), ESearchCase::IgnoreCase))
	{
		bInteract = true;

		if (triggerEvent == ETriggerEvent::Started)
		{
			if (WidgetInteraction->IsActive())
			{
				// cleared in UWidgetInteractionComponent on click, so store prior to click
				LastWidgetPath = WidgetInteraction->GetHoveredWidgetPath();
				TimeOfLastClick = FDateTime::Now();

				WidgetInteraction->PressPointerKey(EKeys::LeftMouseButton);
			}
			
			TArray<FHitResult> hitResults;
			if (IsKeyboardOpen())
			{
				if (VRTrace->GetHitResults(KeyboardCollisionChannel, hitResults))
				{
					// dispatch click
					if (UPrimitiveComponent* componentToClick = hitResults[0].GetComponent())
					{
						componentToClick->GetOwner()->OnClicked.Broadcast(this, EKeys::LeftMouseButton);
						componentToClick->OnClicked.Broadcast(componentToClick, EKeys::LeftMouseButton);

						ClickedComponents.Add(componentToClick);
					}
				}
			}
			else
			{
				if (VRTrace->GetHitResults(GizmoCollisionChannel, hitResults))
				{
					// dispatch click
					if (UPrimitiveComponent* componentToClick = hitResults[0].GetComponent())
					{
						componentToClick->GetOwner()->OnClicked.Broadcast(this, EKeys::LeftMouseButton);
						componentToClick->OnClicked.Broadcast(componentToClick, EKeys::LeftMouseButton);

						ClickedComponents.Add(componentToClick);
					}
				}
				else if (VRTrace->GetHitResults(ContextMenuCollisionChannel, hitResults))
				{
					// do nothing
				}
				else if (VRTrace->GetHitResults(WorldUICollisionChannel, hitResults))
				{
					// do nothing
				}
				else if (VRTrace->GetHitResults(InteractionCollisionChannel, hitResults))
				{
					if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
					{
						if (subsystem->DestroyGizmo())
						{
							// early out if gizmo was valid
							return;
						}
					}

					if (!CheckForPanningInput(inputActionInstance))
					{
						// ignore terrain
						if (hitResults.Num() > 1)
						{
							if (hitResults[0].GetActor() != nullptr && hitResults[0].GetActor()->GetClass() == AGame_TerrainTile::StaticClass())
							{
								hitResults.RemoveAt(0);
							}
						}
						
						if (UPrimitiveComponent* componentToClick = hitResults[0].GetComponent())
						{
							componentToClick->GetOwner()->OnClicked.Broadcast(this, EKeys::LeftMouseButton);
							componentToClick->OnClicked.Broadcast(componentToClick, EKeys::LeftMouseButton);

							ClickedComponents.Add(componentToClick);
						}
						
						if (!ImplementsContextMenu(hitResults[0].GetActor()))
						{
							TriggerPressed(InteractionCollisionChannel, hitResults);
						}
					}
				}
				else
				{
					PostTriggerActionPressed();
				}
			}
		}
		else if (triggerEvent == ETriggerEvent::Completed)
		{
			bInteract = false;

			if (IsKeyboardOpen())
			{
				for (UPrimitiveComponent* componentToRelease : ClickedComponents)
				{
					if (componentToRelease != nullptr)
					{
						componentToRelease->GetOwner()->OnReleased.Broadcast(this, EKeys::LeftMouseButton);
						componentToRelease->OnReleased.Broadcast(componentToRelease, EKeys::LeftMouseButton);
					}
				}

				ClickedComponents.Empty();
			}
			else
			{
				if (WidgetInteraction->IsActive())
				{
					WidgetInteraction->ReleasePointerKey(EKeys::LeftMouseButton);
				}

				CheckForPanningInput(inputActionInstance);

				for (UPrimitiveComponent* componentToRelease : ClickedComponents)
				{
					if (componentToRelease != nullptr)
					{
						componentToRelease->GetOwner()->OnReleased.Broadcast(this, EKeys::LeftMouseButton);
						componentToRelease->OnReleased.Broadcast(componentToRelease, EKeys::LeftMouseButton);
					}
				}

				ClickedComponents.Empty();

				TriggerReleased();
			}
		}
	}

	// todo ohg | switch params to inputActionInstance
	switch (triggerEvent)
	{
		case ETriggerEvent::Started:
			ReceiveActionInput(action, EInputEvent::IE_Pressed);
			break;

		case ETriggerEvent::Completed:
			ReceiveActionInput(action, EInputEvent::IE_Released);
			break;
	}
	
	PostActionInput(inputActionInstance);
}

bool AGame_Tool::GetRelativeTransformForNonVRPositioning_Implementation(FTransform& transform) const
{
	transform = VRTrace->GetRelativeTransform();

	return true;
}

// ---------------------------------
// --- Interface_UI_ContextMenuSource
// ---------------------------------

void AGame_Tool::GetContextOptionClasses_Implementation(TSet<TSubclassOf<UObject>>& contextOptionClasses)
{
	contextOptionClasses = ContextOptionClasses;
}

void AGame_Tool::GetContextMenuClass_Implementation(TSubclassOf<UUserWidget>& contextMenuClass)
{
	contextMenuClass = ContextMenuClass;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Tool::BeginPlay()
{
	Super::BeginPlay();

	if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
	{
		GizmoCollisionChannel = subsystem->GizmoCollisionChannel;
	}

	if (UKeyboard_Subsystem_Core* subsystem = UKeyboard_Subsystem_Core::Get())
	{
		KeyboardCollisionChannel = subsystem->KeyboardCollisionChannel;

		subsystem->OnKeyboardSpawnDestroy.AddDynamic(this, &AGame_Tool::HandleKeyboardSpawnDestroy);
	}

	if (UUI_Subsystem_ContextMenu* subsystem = UUI_Subsystem_ContextMenu::Get())
	{
		ContextMenuCollisionChannel = subsystem->ContextMenuCollisionChannel;
	}

	VRTrace->AddTraceChannel(KeyboardCollisionChannel);
	VRTrace->AddTraceChannel(WorldUICollisionChannel);
	VRTrace->AddTraceChannel(GizmoCollisionChannel);
	VRTrace->AddTraceChannel(InteractionCollisionChannel);
	VRTrace->AddTraceChannel(ContextMenuCollisionChannel);
	VRTrace->AddTraceChannel(UGame_GameInstance::GetTerrainCollisionChannel());
	
	VRTrace->UpdateTrace();
	
	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		gameState->OnPanningPlayerStateUpdated.AddDynamic(this, &AGame_Tool::HandlePanningPlayerStateUpdated);
	}

	if (GetWorld()->GetNetMode() != NM_DedicatedServer)
	{
		BeamMaterial = BeamMesh->CreateDynamicMaterialInstance(0);

		BeamMaterial->SetVectorParameterValue(TEXT("Color"), BeamColor);

		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_Tool::PeriodicBeamUpdateForRPCs, 0.25, true);
	}

	InitialRelativeBeamScale = BeamMesh->GetRelativeScale3D();
}

void AGame_Tool::OnRep_Owner()
{
	Super::OnRep_Owner();

	if (IsLocallyOwned())
	{
		UVR_Statics::SetWidgetInteractionIndices(WidgetInteraction);

		LoadCurrentToolVisualConfiguration();

		if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
		{
			HandleHardwareInterfaceModeChanged(subsystem->GetHardwareInterfaceMode(), EHardwareInterfaceMode::Unknown);

			subsystem->OnHardwareInterfaceModeChanged.AddUniqueDynamic(this, &AGame_Tool::HandleHardwareInterfaceModeChanged);
		}
	}
	else
	{
		WidgetInteraction->Deactivate();

		InitialRelativeBeamScale = BeamMesh->GetRelativeScale3D();
	}
}

void AGame_Tool::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	TickUpdateBeam(deltaSeconds);

	TickUpdatePanning(deltaSeconds);

	TickNonOwningBeamUpdate();
}

// ---------------------------------
// --- API
// ---------------------------------

bool AGame_Tool::GetInteractionHitLocation(FVector& dragLocation) const
{
	TArray<FHitResult> hitResults;
	if (VRTrace->GetHitResults(InteractionCollisionChannel, hitResults))
	{
		//UE_LOG(LogTemp, Warning, TEXT("-- %s | distance: %f"), hitResults[0].GetActor() ? *hitResults[0].GetActor()->GetName() : TEXT("null"), hitResults[0].Distance);

		dragLocation = hitResults[0].Location;

		return true;
	}

	return false;
}

bool AGame_Tool::GetWorldUIHitLocation(FVector& dragLocation) const
{
	TArray<FHitResult> hitResults;
	if (VRTrace->GetHitResults(WorldUICollisionChannel, hitResults))
	{
		dragLocation = hitResults[0].Location;

		return true;
	}

	return false;
}

bool AGame_Tool::GetTerrainHitLocation(FVector& hitLocation) const
{
	TArray<FHitResult> hitResults;
	if (VRTrace->GetHitResults(UGame_GameInstance::GetTerrainCollisionChannel(), hitResults))
	{
		hitLocation = hitResults[0].Location;

		return true;
	}

	return false;
}

void AGame_Tool::AddTraceIgnoredActor(AActor* actor)
{
	VRTrace->IgnoredActors.Add(actor);
}

void AGame_Tool::RemoveTraceIgnoredActor(AActor* actor)
{
	VRTrace->IgnoredActors.Remove(actor);
}

bool AGame_Tool::StartDraggingWorldUI(UUserWidget* userWidget, AActor* worldUIActor)
{
	if (IsHoveringOverUserWidget(userWidget))
	{
		worldUIActor->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

		return true;
	}

	return false;
}

bool AGame_Tool::GetInteractionHitResults(TArray<FHitResult>& hitResults) const
{
	return VRTrace->GetHitResults(InteractionCollisionChannel, hitResults);
}

bool AGame_Tool::IsHoveringOverUserWidget(const UUserWidget* userWidget) const
{
	// * gives a raw reference; & gives address of reference (aka a pointer to it)
	return WidgetInteraction->GetHoveredWidgetPath().ContainsWidget(&(*userWidget->GetCachedWidget())) || LastWidgetPath.ContainsWidget(&(*userWidget->GetCachedWidget()));  
}

AActor* AGame_Tool::GetHoveredActor() const
{
	return HoveredActor;
}

UPrimitiveComponent* AGame_Tool::GetHoveredComponent() const
{
	return HoveredComponent;
}

FDateTime AGame_Tool::GetTimeOfLastClick() const
{
	return TimeOfLastClick;
}

void AGame_Tool::SetModalPopupOpen(bool bOpen, AActor* worldUIActor)
{
	bModalPopupOpen = bOpen;

	ModalPopupWorldUIActor = worldUIActor;
}

bool AGame_Tool::GetActionModifierPressed() const
{
	return bActionModifier;
}

bool AGame_Tool::GetInteract() const
{
	return bInteract;
}

void AGame_Tool::AddClickedComponent(UPrimitiveComponent* component)
{
	ClickedComponents.Add(component);
}

void AGame_Tool::LoadCurrentToolVisualConfiguration()
{
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		UGame_Database_ToolVisual* toolVisualDatabase = subsystem->GetToolVisualDatabase();

		SpatialiteResult result;
		if (toolVisualDatabase->LoadConfiguration(toolVisualDatabase->GetCurrentConfiguration(), result))
		{
			SyncToToolVisualization(result);

			if (GetNetMode() == NM_Client)
			{
				Server_SyncToToolVisualization(FSpatialiteResult_BP(result));
			}
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool AGame_Tool::IsLocallyOwned() const
{
	if (APawn* owner = Cast<APawn>(GetOwner()))
	{
		return owner->IsLocallyControlled();
	}

	UE_LOG(Game, Warning, TEXT("-- AGame_Tool::IsLocallyOwned | owner could not be cast to pawn | returning false"));
	return false;
}

bool AGame_Tool::ImplementsContextMenu(AActor* actor) const
{
	while (actor != nullptr)
	{
		if (actor->GetClass()->ImplementsInterface(UInterface_UI_ContextMenuSource::StaticClass()))
		{
			return true;
		}

		actor = actor->GetOwner();
	}

	return false;
}

void AGame_Tool::PostTriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults)
{

}

void AGame_Tool::PostTriggerReleased()
{

}

void AGame_Tool::PostTickUpdateBeam(float deltaSeconds)
{

}

void AGame_Tool::PostActionInput(const FInputActionInstance& inputActionInstance)
{

}

void AGame_Tool::PostTriggerActionPressed()
{

}

void AGame_Tool::TriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults)
{
	PostTriggerPressed(traceChannel, hitResults);

	ReceiveTriggerPressed(traceChannel, hitResults);
}

bool AGame_Tool::ShouldUpdateBeam()
{
	ENetMode netMode = GetNetMode();
	if (netMode == NM_DedicatedServer || !IsLocallyOwned())
	{
		return false;
	}

	// only left controller active in desktop mode
	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		EHardwareInterfaceMode interfaceMode = subsystem->GetHardwareInterfaceMode();
		if (interfaceMode == EHardwareInterfaceMode::Desktop)
		{
			if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
			{
				if (UVR_MotionControllerComponent* motionControllerComponent = playerPawn->GetMotionControllerForTool(this))
				{
					if (motionControllerComponent != playerPawn->LeftController)
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}

bool AGame_Tool::CheckInputBlocked()
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		if (!playerPawn->InputEnabled())
		{
			return true;
		}
	}

	if (bModalPopupOpen)
	{
		TArray<FHitResult> hitResults;
		if (VRTrace->GetHitResults(WorldUICollisionChannel, hitResults))
		{
			for (const FHitResult& hitResult : hitResults)
			{
				if (hitResult.GetActor() == ModalPopupWorldUIActor)
				{
					return false;
				}
			}
		}

		return true;
	}

	return false;
}

void AGame_Tool::TriggerReleased()
{
	PostTriggerReleased();

	ReceiveTriggerReleased();
}

void AGame_Tool::TickUpdateBeam(float deltaSeconds)
{
	if (ShouldUpdateBeam())
	{
		AActor* hoveredActor = nullptr;
		UPrimitiveComponent* hoveredComponent = nullptr;

		double traceDistance = VRTrace->TraceDistance;
		ECollisionChannel traceChannel = ECollisionChannel::ECC_MAX;

		TArray<FHitResult> hitResults;
		if (VRTrace->GetHitResults(KeyboardCollisionChannel, hitResults))
		{
			traceDistance = hitResults[0].Distance;

			traceChannel = KeyboardCollisionChannel;

			hoveredActor = hitResults[0].GetActor();
			hoveredComponent = hitResults[0].GetComponent();
		}
		else if (VRTrace->GetHitResults(GizmoCollisionChannel, hitResults))
		{
			traceDistance = hitResults[0].Distance;

			traceChannel = GizmoCollisionChannel;

			hoveredActor = hitResults[0].GetActor();
			hoveredComponent = hitResults[0].GetComponent();
		}
		else if (VRTrace->GetHitResults(ContextMenuCollisionChannel, hitResults))
		{
			traceDistance = hitResults[0].Distance;

			traceChannel = ContextMenuCollisionChannel;

			hoveredActor = hitResults[0].GetActor();
			hoveredComponent = hitResults[0].GetComponent();
		}
		else if (VRTrace->GetHitResults(WorldUICollisionChannel, hitResults))
		{
			traceDistance = hitResults[0].Distance;

			traceChannel = WorldUICollisionChannel;
			
			hoveredActor = hitResults[0].GetActor();
			hoveredComponent = hitResults[0].GetComponent();
		}
		else if (VRTrace->GetHitResults(InteractionCollisionChannel, hitResults))
		{
			// ignore terrain
			if (hitResults.Num() > 1)
			{
				if (hitResults[0].GetActor() != nullptr && hitResults[0].GetActor()->GetClass() == AGame_TerrainTile::StaticClass())
				{
					hitResults.RemoveAt(0);
				}
			}

			traceDistance = hitResults[0].Distance;

			if (AActor* hitActor = hitResults[0].GetActor())
			{
				if (ImplementsContextMenu(hitActor))
				{
					traceChannel = InteractionCollisionChannel;
				}

				hoveredActor = hitResults[0].GetActor();
				hoveredComponent = hitResults[0].GetComponent();
			}
		}

		// debug
		//if (hoveredActor != nullptr)
		//{
		//	UE_LOG(LogTemp, Warning, TEXT("-- hovered: %s"), *hoveredActor->GetName());
		//}
		// end debug

		if (hoveredActor != HoveredActor)
		{
			HoveredActor = hoveredActor;

			WidgetInteraction->TraceChannel = traceChannel == ContextMenuCollisionChannel ? ContextMenuCollisionChannel : WorldUICollisionChannel.GetValue();
		}

		UPrimitiveComponent::DispatchMouseOverEvents(HoveredComponent, hoveredComponent);

		HoveredComponent = hoveredComponent;

		FLinearColor color = DefaultBeamColor;
		if (FLinearColor* colorPtr = CollisionChannelToBeamColor.Find(traceChannel))
		{
			color = *colorPtr;
		}
		
		BeamMaterial->SetVectorParameterValue(TEXT("Color"), color);
		BeamColor = color;

		double localTraceDistance = FMath::Min<double>(traceDistance, 65534);  // todo ohg | this is 32767 * 2 | beam mesh stops rendering if move further than 32768 from player; why?

		FTransform localToWorld = VRTrace->GetRelativeTransform();
		
		FTransform beamRelativeTransform;
		beamRelativeTransform.SetLocation(localToWorld.TransformPosition(FVector(localTraceDistance * 0.5, 0, 0)));
		beamRelativeTransform.SetScale3D(FVector(localTraceDistance / 256, InitialRelativeBeamScale.Y, InitialRelativeBeamScale.Z));  // 256 is size of X-axis of mesh used for beam (Engine's cube)
		beamRelativeTransform.SetRotation(VRTrace->GetRelativeRotation().Quaternion());

		BeamMesh->SetRelativeTransform(beamRelativeTransform);

		if (UpdateTraceStartEndMUC > 0.25)
		{
			if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
			{
				if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
				{
					if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
					{
						if (UGame_MotionControllerComponent* motionControllerComponent = Cast<UGame_MotionControllerComponent>(playerPawn->GetMotionControllerForTool(this)))
						{
							FVector beamEndLocation = VRTrace->GetComponentTransform().TransformPosition(FVector(traceDistance, 0, 0));

							motionControllerComponent->Server_SetTraceCoordinates(globeReference->WorldToGeodeticDouble(VRTrace->GetComponentLocation()), globeReference->WorldToGeodeticDouble(beamEndLocation));
						}
					}
				}
			}

			UpdateTraceStartEndMUC = 0;
		}

		UpdateTraceStartEndMUC += deltaSeconds;
	}

	PostTickUpdateBeam(deltaSeconds);
}

void AGame_Tool::TickNonOwningBeamUpdate()
{
	if (!IsLocallyOwned())
	{
		if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
			{
				if (AGame_Pawn* playerPawn = Cast<AGame_Pawn>(GetOwner()))
				{
					if (UGame_MotionControllerComponent* motionControllerComponent = Cast<UGame_MotionControllerComponent>(playerPawn->GetMotionControllerForTool(this)))
					{
						FVector traceStartLocation = globeReference->GeodeticToWorldDouble(motionControllerComponent->GetTraceStartCoordinate());
						FVector traceEndLocation = globeReference->GeodeticToWorldDouble(motionControllerComponent->GetTraceEndCoordinate());

						double traceDistance = FVector::Distance(traceStartLocation, traceEndLocation);

						double nonLocalBeamScale = 1;
						if (AGame_PlayerState* localPlayerState = UGame_Statics::GetLocalPlayerState())
						{
							if (!localPlayerState->GetIsInTOC())
							{
								nonLocalBeamScale = 100;
							}
						}

						FVector localPawnLocation = UGame_Statics::GetVHPlayerPawn()->GetActorLocation();
						double distanceOnLineToLocalPlayer = FVector::Distance(localPawnLocation, FMath::ClosestPointOnInfiniteLine(traceStartLocation, traceEndLocation, localPawnLocation));
						if (distanceOnLineToLocalPlayer > 45000)
						{
							nonLocalBeamScale += FMath::Lerp<double>(0, 15000, distanceOnLineToLocalPlayer / 10000000.f);
						}

						FVector scale;
						scale.X = traceDistance / 256;  // 256 is size of X-axis of mesh used for beam (Engine's cube)
						scale.Y = InitialRelativeBeamScale.Y * nonLocalBeamScale;
						scale.Z = InitialRelativeBeamScale.Z * nonLocalBeamScale;

						FQuat rotation = FRotationMatrix::MakeFromX(traceEndLocation - traceStartLocation).ToQuat();

						FTransform beamRelativeTransform;
						beamRelativeTransform.SetLocation((traceStartLocation + traceEndLocation) * 0.5);
						beamRelativeTransform.SetScale3D(scale);
						beamRelativeTransform.SetRotation(rotation);

						BeamMesh->SetWorldTransform(beamRelativeTransform);
					}
				}
			}
		}
	}
}

void AGame_Tool::TickUpdatePanning(float deltaSeconds)
{
	AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO();
	
	AVH_GlobeReferenceActor* globeReference = nullptr;
	if (IsValid(virtualObjective))
	{
		globeReference = virtualObjective->GetGlobeReference();
	}

	AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState();
	AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn();

	if (!IsValid(virtualObjective) || !IsValid(globeReference) || !IsValid(playerState) || !IsValid(playerPawn))
	{
		return;
	}

	if (PanningState == EPanningState::Panning)
	{
		if (playerState->GetIsInTOC())
		{
			FVector panDelta = GetPanDelta();
			if (!panDelta.IsNearlyZero(0.05))
			{
				// in TOC 
				virtualObjective->TOCMoveViewpoint(panDelta);
			}
		}
		else
		{
			// viewing full Earth but zoomed out
			// starts to wobble when zoomed far out and pointing to edges of Earth; fixed by skipping every other tick
			if (!bSkipEarthPan)  
			{
				FVector newMouseWorldLocation;
				if (!GetTerrainHitLocation(newMouseWorldLocation))
				{
					return;
				}

				FGeodeticCoord2D oldMouseCoordinate = globeReference->WorldToGeodeticDouble(PreviousPanningLocation).ToGeodeticCoord2D();
				FGeodeticCoord2D newMouseCoordinate = globeReference->WorldToGeodeticDouble(newMouseWorldLocation).ToGeodeticCoord2D();
					
				FGeodeticCoord2D mouseDelta;
				mouseDelta.Longitude = newMouseCoordinate.Longitude - oldMouseCoordinate.Longitude;
				mouseDelta.Latitude = newMouseCoordinate.Latitude - oldMouseCoordinate.Latitude;

				FGeodeticCoord3D playerCoordinate = globeReference->WorldToGeodeticDouble(playerPawn->GetActorLocation());

				playerCoordinate.Longitude -= mouseDelta.Longitude;
				playerCoordinate.Latitude -= mouseDelta.Latitude;

				if (playerCoordinate.Longitude < -180)
				{
					playerCoordinate.Longitude = 360 + playerCoordinate.Longitude;
				}
				else if (playerCoordinate.Longitude > 180)
				{
					playerCoordinate.Longitude = -360 + playerCoordinate.Longitude;
				}

				playerCoordinate.Latitude = FMath::Clamp<double>(playerCoordinate.Latitude, -89, 89);

				playerPawn->SetActorLocation(globeReference->GeodeticToWorldDouble(playerCoordinate));

				// rotate player camera to look at center of the Earth
				FQuat rotationToEarthCenter = FRotationMatrix::MakeFromX(FVector(0, 0, 0) - playerPawn->GetActorLocation()).ToQuat();
				playerPawn->Camera->SetWorldRotation(rotationToEarthCenter);

				playerPawn->Camera->CameraTransformOverride.SetRotation(rotationToEarthCenter);
			}
				
			bSkipEarthPan = !bSkipEarthPan;
		}
	}
}

bool AGame_Tool::IsHoveringOverTerrain() const
{
	TArray<FHitResult> hitResults;
	if (VRTrace->GetHitResults(InteractionCollisionChannel, hitResults))
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			if (playerState->GetIsInTOC())
			{
				// in TOC 
				if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
				{
					for (const FHitResult& hitResult : hitResults)
					{
						if (virtualObjective->IsPointInViewCullBox(hitResult.Location) && Cast<AGame_TerrainTile>(hitResult.GetActor()) != nullptr)
						{
							return true;
						}
					}
				}
			}
			else
			{
				// viewing full Earth but zoomed out
				for (const FHitResult& hitResult : hitResults)
				{
					if (Cast<AGame_TerrainTile>(hitResult.GetActor()) != nullptr)
					{
						return true;
					}
				}
			}

		}
	}

	return false;
}

FVector AGame_Tool::GetPanDelta()
{
	if (IsHoveringOverTerrain())
	{
		FVector newPanningLocation;
		GetInteractionHitLocation(newPanningLocation);

		if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
		{
			newPanningLocation.Z = 0;

			FVector rawDelta = PreviousPanningLocation - newPanningLocation;
					
			PreviousPanningLocation = newPanningLocation;

			return rawDelta * (1 / virtualObjective->GetActorScale3D().X) / 100;
		}
	}

	return FVector(0, 0, 0);
}

bool AGame_Tool::CheckForPanningInput(const FInputActionInstance& inputActionInstance)
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		if (inputActionInstance.GetTriggerEvent() == ETriggerEvent::Started &&
			GetActionModifierPressed() &&
			(playerState->GetIsInTOC() || UGame_Statics::GetPlayerWorldTransformOverride().Equals(FTransform::Identity)) &&
			IsHoveringOverTerrain())
		{
			if (playerState->GetIsInTOC())
			{
				GetInteractionHitLocation(PreviousPanningLocation);
				PreviousPanningLocation.Z = 0;

				PanningState = EPanningState::RequestPanning;

				playerState->Server_AttemptBeginDragPan();
			}
			else
			{
				// hide ribbon while panning globe in VR
				bShowRibbonAfterPan = false;

				UDeveloper_Subsystem_Core* developerSubsystem = UDeveloper_Subsystem_Core::Get();
				UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get();
				if (developerSubsystem != nullptr && ribbonSubsystem != nullptr)
				{
					if (developerSubsystem->GetHardwareInterfaceMode() != EHardwareInterfaceMode::Desktop)
					{
						if (ribbonSubsystem->GetRibbonVisible())
						{
							bShowRibbonAfterPan = true;

							ribbonSubsystem->HideRibbon();
						}
					}
				}

				// panning Earth occurs on each client with no replication
				GetTerrainHitLocation(PreviousPanningLocation);

				PanningState = EPanningState::Panning;
			}

			return true;
		}
		
		if (PanningState == EPanningState::Panning)
		{
			if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
			{
				gameState->SetPanningTool(nullptr);
			}

			PanningState = EPanningState::NotPanning;

			playerState->Server_AttemptEndDragPan();

			// show ribbon when finished panning globe in VR
			if (bShowRibbonAfterPan)
			{
				if (UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
				{
					ribbonSubsystem->ShowRibbon();
				}

				bShowRibbonAfterPan = false;
			}
		}
	}

	return false;
}

bool AGame_Tool::IsKeyboardOpen() const
{
	if (UKeyboard_Subsystem_Core* subsystem = UKeyboard_Subsystem_Core::Get())
	{
		return subsystem->IsKeyboardOpen();
	}

	return false;
}

void AGame_Tool::SyncToToolVisualization(const SpatialiteResult& result)
{
	FString motionSource = TEXT("Left");
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		if (UVR_MotionControllerComponent* motionControllerComponent = playerPawn->GetMotionControllerForTool(this))
		{
			motionSource = motionControllerComponent->MotionSource.ToString();
		}
	}

	UGame_Database_ToolVisual* toolVisualDatabase = UGame_Subsystem_Core::Get()->GetToolVisualDatabase();

	FString meshID = UDatabase_Spatialite::GetString(TEXT("mesh"), result);
	if (UStaticMesh** staticMeshPtr = toolVisualDatabase->MeshIDToAsset.Find(meshID + motionSource))
	{
		MainMesh->SetStaticMesh(*staticMeshPtr);
		MainMesh->SetMaterial(0, nullptr);
	}
	
	FVector meshScale;
	meshScale.InitFromString(UDatabase_Spatialite::GetString(TEXT("meshScale"), result));
	MainMesh->SetRelativeScale3D(meshScale);

	FVector beamScale;
	beamScale.InitFromString(UDatabase_Spatialite::GetString(TEXT("beamScale"), result));
	BeamMesh->SetRelativeScale3D(beamScale);

	FVector beamOffset;
	beamOffset.InitFromString(UDatabase_Spatialite::GetString(TEXT("beamOffset"), result));
	VRTrace->SetRelativeLocation(beamOffset);
	WidgetInteraction->SetRelativeLocation(beamOffset);

	FRotator beamRotation;
	beamRotation.InitFromString(UDatabase_Spatialite::GetString(TEXT("beamRotation"), result));
	VRTrace->SetRelativeRotation(beamRotation);
	WidgetInteraction->SetRelativeRotation(beamRotation);

	FLinearColor color;
	color.InitFromString(UDatabase_Spatialite::GetString(TEXT("defaultBeamColor"), result));
	DefaultBeamColor = color;

	color.InitFromString(UDatabase_Spatialite::GetString(TEXT("interactionBeamColor"), result));
	CollisionChannelToBeamColor.Add(InteractionCollisionChannel, color);

	color.InitFromString(UDatabase_Spatialite::GetString(TEXT("vrKeyboardBeamColor"), result));
	CollisionChannelToBeamColor.Add(KeyboardCollisionChannel, color);

	color.InitFromString(UDatabase_Spatialite::GetString(TEXT("transformGizmoBeamColor"), result));
	CollisionChannelToBeamColor.Add(GizmoCollisionChannel, color);

	color.InitFromString(UDatabase_Spatialite::GetString(TEXT("uiBeamColor"), result));
	CollisionChannelToBeamColor.Add(WorldUICollisionChannel, color);

	color.InitFromString(UDatabase_Spatialite::GetString(TEXT("contextMenuBeamColor"), result));
	CollisionChannelToBeamColor.Add(ContextMenuCollisionChannel, color);

	MainMesh->SetTranslucentSortPriority(100);
	BeamMesh->SetTranslucentSortPriority(100);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Tool::HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode)
{
	bool bDesktopMode = newMode == EHardwareInterfaceMode::Desktop;

	MainMesh->SetHiddenInGame(bDesktopMode);
	BeamMesh->SetHiddenInGame(bDesktopMode);

	Server_SetOwnerHardwareInterfaceMode(newMode);

	// only left controller active in desktop mode
	if (bDesktopMode)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (UVR_MotionControllerComponent* motionControllerComponent = playerPawn->GetMotionControllerForTool(this))
			{
				if (motionControllerComponent != playerPawn->LeftController)
				{
					WidgetInteraction->Deactivate();
				}
			}
		}
	}
	else
	{
		WidgetInteraction->Activate();
	}
}

void AGame_Tool::HandlePanningPlayerStateUpdated(APlayerState* playerState)
{
	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		if (UGame_Statics::GetLocalPlayerState() == playerState &&
			gameState->GetPanningTool() == nullptr &&
			PanningState == EPanningState::RequestPanning)
		{
			gameState->SetPanningTool(this);

			PanningState = EPanningState::Panning;
		}
		else
		{
			if (gameState->GetPanningTool() == this)
			{
				gameState->SetPanningTool(nullptr);

				PanningState = EPanningState::NotPanning;
			}
		}
	}
}

void AGame_Tool::HandleKeyboardSpawnDestroy(bool bSpawn, AActor* keyboardContainer)
{
	WidgetInteraction->SetActive(!bSpawn);
}

void AGame_Tool::HandleOwnerDisconnected(AActor* owningActor)
{
	IInterface_VR_Tool::Execute_RemovedFromInputToolStack(this, nullptr);
}

void AGame_Tool::PeriodicBeamUpdateForRPCs()
{
	if (bReplicateBeam && UGame_Statics::IsLocalPlayerInSession() && IsLocallyOwned())
	{
		if (!LastRPCBeamColor.Equals(BeamColor))
		{
			Server_SetBeamColor(BeamColor);

			LastRPCBeamColor = BeamColor;
		}
	}
}

void AGame_Tool::HandleGlobeZoom(const FInputActionValue& inputActionValue)
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		if (AGame_VirtualObjective* playerVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(playerVO->GetGlobeReference()))
			{
				if (UGame_Statics::GetPlayerWorldTransformOverride().Equals(FTransform::Identity))
				{
					// player is orbiting the Earth (ECEF); input zooms player towards or away from Earth
					FGeodeticCoord3D playerCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(playerPawn->GetActorLocation());

					FGeodeticCoord3D destinationCoordinate;

					float zoomAmount = inputActionValue.Get<float>();

					FVector hitLocation;
					if (!GetTerrainHitLocation(hitLocation))
					{
						// user tool rotation and location if did not hit terrain
						double unrealUnitDistance = 10000;

						double terrainHAE = globeReferenceEllipsoid->GetTerrainElevationDouble(playerCoordinate.ToGeodeticCoord2D());
						if (!FMath::IsNearlyEqual(terrainHAE, -999999.f))
						{
							double agl = playerCoordinate.Altitude - terrainHAE;

							unrealUnitDistance = (FMath::Abs<double>(agl) * 100.0) + 10000;
						}
						
						FVector destinationLocation = GetActorTransform().TransformPosition(FVector(unrealUnitDistance, 0, 0));
						
						destinationCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(destinationLocation);
					}
					else
					{
						destinationCoordinate = globeReferenceEllipsoid->WorldToGeodeticDouble(hitLocation);
					}
					
					double alpha = 0.2 * zoomAmount;

					FGeodeticCoord3D lerpCoordinate;
					lerpCoordinate.Longitude = FMath::Lerp<double>(playerCoordinate.Longitude, destinationCoordinate.Longitude, alpha);
					lerpCoordinate.Latitude = FMath::Lerp<double>(playerCoordinate.Latitude, destinationCoordinate.Latitude, alpha);
					lerpCoordinate.Altitude = FMath::Lerp<double>(playerCoordinate.Altitude, destinationCoordinate.Altitude, alpha);

					if (zoomAmount < 0)
					{
						// don't allow further zoom out if reached max zoom distance
						double lerpTerrainHAE = globeReferenceEllipsoid->GetTerrainElevationDouble(lerpCoordinate.ToGeodeticCoord2D());
						if (!FMath::IsNearlyEqual(lerpTerrainHAE, -999999.f))
						{
							double lerpAGL = lerpCoordinate.Altitude - lerpTerrainHAE;
							if (lerpCoordinate.Altitude * 100 < VRTrace->TraceDistance - 200000000)
							{
								playerPawn->SetActorLocation(globeReferenceEllipsoid->GeodeticToWorldDouble(lerpCoordinate));
							}
						}
					}
					else
					{
						playerPawn->SetActorLocation(globeReferenceEllipsoid->GeodeticToWorldDouble(lerpCoordinate));
					}
				}
			}
		}
	}
}