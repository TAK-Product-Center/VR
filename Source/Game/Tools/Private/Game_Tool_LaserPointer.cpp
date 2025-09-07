// Required Includes
#include "Game_Tool_LaserPointer.h"
#include "Game.h"

// Engine Includes
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"

// Game Includes
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_UserWidget_HUD_Desktop.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Tool_LaserPointer::AGame_Tool_LaserPointer(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Replication
// ---------------------------------

void AGame_Tool_LaserPointer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AGame_Tool_LaserPointer, bShowBeamToAll, COND_SkipOwner);
}

void AGame_Tool_LaserPointer::Server_ShowBeamToAll_Implementation(bool bShowBeam)
{
	bShowBeamToAll = bShowBeam;

	if (GetNetMode() == NM_ListenServer && !HasLocalNetOwner())
	{
		BeamMesh->SetHiddenInGame(!bShowBeamToAll);
	}
}

void AGame_Tool_LaserPointer::OnRep_ShowBeamToAll()
{
	BeamMesh->SetHiddenInGame(!bShowBeamToAll);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Tool_LaserPointer::OnRep_Owner()
{
	Super::OnRep_Owner();

	BindToPlayerState();
}

void AGame_Tool_LaserPointer::PostTriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults)
{
	ShowBeam();
}

void AGame_Tool_LaserPointer::PostTriggerActionPressed()
{
	ShowBeam();
}

void AGame_Tool_LaserPointer::PostTriggerReleased()
{
	Super::PostTriggerReleased();

	Server_ShowBeamToAll(false);

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		SetCursorColor(FColor::White.ReinterpretAsLinear());
	}

	bReplicateBeam = false;
}

void AGame_Tool_LaserPointer::PostTickUpdateBeam(float deltaSeconds)
{
	if (IsLocallyOwned() && bReplicateBeam)
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			BeamColor = playerState->GetCollaborationColor();
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_Tool_LaserPointer::ShowBeam()
{
	Server_ShowBeamToAll(true);

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		SetCursorColor(playerState->GetCollaborationColor());

		BeamColor = playerState->GetCollaborationColor();

		BeamMaterial->SetVectorParameterValue(TEXT("Color"), BeamColor);

		Server_SetBeamColor(BeamColor);
	}

	bReplicateBeam = true;
}

void AGame_Tool_LaserPointer::SetCursorColor(const FLinearColor& color)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		TSet<UGame_UserWidget_HUD_Desktop*> huds = subsystem->GetUserWidgetsByClass<UGame_UserWidget_HUD_Desktop>(true);

		for (UGame_UserWidget_HUD_Desktop* hud : huds)
		{
			hud->ReceiveSetCursorColor(color);
		}
	}
}

void AGame_Tool_LaserPointer::BindToPlayerState()
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		HandleCallsignChanged(playerState->GetCallsign(), playerState->GetCollaborationColor());
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_Tool_LaserPointer::BindToPlayerState, 0.5, false);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Tool_LaserPointer::HandleCallsignChanged(const FString& callsign, const FLinearColor& collaborationColor)
{
	if (BeamMaterial != nullptr)
	{
		BeamMaterial->SetVectorParameterValue(TEXT("Color"), collaborationColor);
	}

	Server_SetBeamColor(collaborationColor);
}