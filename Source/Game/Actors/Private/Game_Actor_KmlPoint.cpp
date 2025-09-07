// Required Includes
#include "Game_Actor_KmlPoint.h"
#include "Game.h"

// Engine Includes
#include "Components/SceneComponent.h"

// Game Includes
#include "Game_Subsystem_Core.h"
#include "Game_CameraScalingComponent.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Actor_KmlPoint::AGame_Actor_KmlPoint(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Actor_KmlPoint::BeginPlay()
{
	Super::BeginPlay();

	OnBeginCursorOver.AddDynamic(this, &AGame_Actor_KmlPoint::HandleBeginCursorOver);
	OnEndCursorOver.AddDynamic(this, &AGame_Actor_KmlPoint::HandleEndCursorOver);

	if (UGame_CameraScalingComponent* cameraScalingComponent = ReceiveGetTextScalingComponent())
	{
		if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
		{
			cameraScalingComponent->AddDistanceThreshold(subsystem->GetCallsignShowDistanceMeters());
			cameraScalingComponent->OnThresholdCrossed.AddDynamic(this, &AGame_Actor_KmlPoint::HandleDistanceThresholdCrossed);

			HandleEndCursorOver(UGame_Statics::GetVHPlayerPawn());
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Actor_KmlPoint::HandleBeginCursorOver(AActor* actor)
{
	if (USceneComponent* textComponent = ReceiveGetTextComponent())
	{
		textComponent->SetHiddenInGame(false);
	}
}

void AGame_Actor_KmlPoint::HandleEndCursorOver(AActor* actor)
{
	if (USceneComponent* textComponent = ReceiveGetTextComponent())
	{
		bool bComponentHidden = true;
		if (UGame_Subsystem_Core* subsytem = UGame_Subsystem_Core::Get())
		{
			if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
			{
				double distanceMeters = FVector::Distance(playerPawn->GetActorLocation(), GetActorLocation()) / 100.0;
				if (distanceMeters < subsytem->GetCallsignShowDistanceMeters())
				{
					bComponentHidden = false;
				}
			}
		}

		textComponent->SetHiddenInGame(bComponentHidden);
	}
}

void AGame_Actor_KmlPoint::HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters)
{
	if (USceneComponent* textComponent = ReceiveGetTextComponent())
	{
		if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
		{
			textComponent->SetHiddenInGame(distanceMeters > subsystem->GetCallsignShowDistanceMeters());
		}
	}
}