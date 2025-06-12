// Required Includes
#include "VTAK_Actor_Orbit.h"

// Engine Includes
#include "Engine/GameViewportClient.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetComponent.h"
#include "Components/StaticMeshComponent.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "UI_Subsystem_ContextMenu.h"

// Game Includes
#include "Game_Pawn.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"

// Module Includes
#include "VTAK_COTComponent_Orbit.h"
#include "VTAK_DatabaseComponent_Orbit.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AVTAK_Actor_Orbit::AVTAK_Actor_Orbit(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	COTComponent = CreateDefaultSubobject<UVTAK_COTComponent_Orbit>(TEXT("COTComponent"));
	
	DatabaseComponent = CreateDefaultSubobject<UVTAK_DatabaseComponent_Orbit>(TEXT("DatabaseComponent"));
	
	OrbitCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OrbitCamera"));
	OrbitCamera->SetupAttachment(Root);
}

// ---------------------------------
// --- Interface_COTReceiver
// ---------------------------------

UVH_COTComponent* AVTAK_Actor_Orbit::GetCOTComponent_Implementation() const
{
	return COTComponent;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AVTAK_Actor_Orbit::BeginPlay()
{
	AGame_WorldInteractableActor::BeginPlay();
	
	bIsActive = true;

	ShapeMID = ShapeMeshComponent->CreateDynamicMaterialInstance(0);

	UpdateMaterial();

	RadiusMeters = 300;
	SpeedMetersPerSecond = 20;
}

void AVTAK_Actor_Orbit::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (bOrbit && !bPause)
	{
		if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
		{
			double unrealUnitsPerMeter = virtualObjective->GetUnrealUnitsPerMeter();
	
			SecondsInOrbit += deltaSeconds;

			double circumferenceMeters = RadiusMeters * 2.0 * PI;
			double distanceTraveledMeters = SpeedMetersPerSecond * SecondsInOrbit;
		
			double maxRadians = FMath::DegreesToRadians(360);

			double angleRadians = FMath::Lerp<double>(0, maxRadians, distanceTraveledMeters / circumferenceMeters);
			if (angleRadians >= maxRadians)
			{
				angleRadians = 0;
				SecondsInOrbit = 0;
			}

			FGeodeticCoord3D coordinate = virtualObjective->GetGlobeReference()->WorldToGeodeticDouble(GetActorLocation());

			double radiusUU = RadiusMeters * unrealUnitsPerMeter;
			FVector orbitLocationLocal = FVector(radiusUU * FMath::Cos(angleRadians), radiusUU * FMath::Sin(angleRadians), coordinate.Altitude * unrealUnitsPerMeter);

			FVector center = GetActorLocation();

			FTransform transform = UGame_Statics::GetWorldTransformOverride(center);
			transform.SetLocation(center);

			FVector orbitLocationWorld = transform.TransformPosition(orbitLocationLocal);
			
			if (UGame_Statics::IsLocalPlayerInTOC())
			{
				OrbitCamera->SetWorldLocationAndRotation(orbitLocationWorld, FRotationMatrix::MakeFromX(center - orbitLocationWorld).ToQuat());
			}
			else
			{
				OrbitCamera->SetWorldLocationAndRotation(orbitLocationWorld, FRotationMatrix::MakeFromXZ(center - orbitLocationWorld, transform.TransformPosition(FVector::UpVector)).ToQuat());
			}
		}
	}
}

void AVTAK_Actor_Orbit::SetActive(bool bActive)
{
	// purposefully not calling super
}

bool AVTAK_Actor_Orbit::GetRotationDisabled_Implementation() 
{
	return true;
}

// ---------------------------------
// --- API
// ---------------------------------

void AVTAK_Actor_Orbit::InsertIntoEntityDB()
{
	DatabaseComponent->Insert();
}

void AVTAK_Actor_Orbit::RemoveFromEntityDB()
{
	DatabaseComponent->Delete();
}

void AVTAK_Actor_Orbit::SetPause(bool bShouldPause)
{
	bPause = bShouldPause;

	OnSetPause.Broadcast(bShouldPause);
}

bool AVTAK_Actor_Orbit::GetOrbit() const
{
	return bOrbit;
}

bool AVTAK_Actor_Orbit::GetPause() const
{
	return bPause;
}

void AVTAK_Actor_Orbit::SetOrbit(bool bShouldOrbit)
{
	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			bOrbit = bShouldOrbit;

			if (bOrbit)
			{
				// close all context menus
				if (UUI_Subsystem_ContextMenu* subsystem = UUI_Subsystem_ContextMenu::Get())
				{
					subsystem->CloseContextMenusOfClass(nullptr);
				}

				playerPawn->DisableInput(playerController);

				if (UGameViewportClient* viewport = Cast<UGameViewportClient>(GetWorld()->GetGameViewport()))
				{
					viewport->OnInputKey().AddUObject(this, &AVTAK_Actor_Orbit::HandleInputKey);
				}

				bIgnoreRelease = true;
			}
			else
			{
				playerPawn->EnableInput(playerController);

				if (UGameViewportClient* viewport = Cast<UGameViewportClient>(GetWorld()->GetGameViewport()))
				{
					viewport->OnInputKey().RemoveAll(this);
				}
			}

			playerController->SetShowMouseCursor(true);
			
			playerController->SetViewTargetWithBlend(bOrbit ? Cast<AActor>(this) : Cast<AActor>(playerPawn));

			ShapeMeshComponent->SetVisibility(!bOrbit, true);

			playerPawn->Head->SetHiddenInGame(bOrbit);
			playerPawn->Callsign->SetHiddenInGame(bOrbit);

			OnSetOrbit.Broadcast(bOrbit);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AVTAK_Actor_Orbit::HandleInputKey(const FInputKeyEventArgs& eventArgs)
{
	if (eventArgs.Event == EInputEvent::IE_Released)
	{
		if (bIgnoreRelease)
		{
			bIgnoreRelease = false;

			return;
		}

		if (bOrbit)
		{
			if (eventArgs.Key == EKeys::P)
			{
				SetPause(!bPause);
			}
			else
			{
				SetOrbit(false);
			}
		}
	}
}