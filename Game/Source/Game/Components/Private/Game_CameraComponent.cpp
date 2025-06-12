// Required Includes
#include "Game_CameraComponent.h"
#include "Game.h"

// Engine Includes
#include "IXRTrackingSystem.h"
#include "IXRCamera.h"
#include "Engine/Engine.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_CameraComponent::UGame_CameraComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_CameraComponent::HandleXRCamera()
{
	FTransform worldTransformOverride = CameraTransformOverride;

	IXRTrackingSystem* xrSystem = GEngine->XRSystem.Get();
	auto xrCamera = xrSystem->GetXRCamera();

	if (!xrCamera.IsValid())
	{
		return;
	}

	FTransform parentWorld = CalcNewComponentToWorld(FTransform());

	xrCamera->SetupLateUpdate(parentWorld, this, bLockToHmd == 0);

	if (bLockToHmd)
	{
		ResetRelativeTransform();

		FQuat orientation;
		FVector position;
		if (xrCamera->UpdatePlayerCamera(orientation, position))
		{
			worldTransformOverride.SetLocation(GetOwner()->GetActorLocation() + AGame_Pawn::GetCameraSceneRelativeLocation());

			orientation = worldTransformOverride.TransformRotation(orientation);
			position = worldTransformOverride.TransformPosition(position);

			SetWorldTransform(FTransform(orientation, position));
		}
	}

	xrCamera->OverrideFOV(FieldOfView);
}