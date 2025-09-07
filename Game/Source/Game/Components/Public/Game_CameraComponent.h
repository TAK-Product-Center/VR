#pragma once

// Parent Includes
#include "Camera/CameraComponent.h"

// Generated Includes
#include "Game_CameraComponent.generated.h"

UCLASS(Blueprintable)
class GAME_API UGame_CameraComponent : public UCameraComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	double QuickTurnYaw;

	/* only effects VR camera */
	FTransform CameraTransformOverride;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_CameraComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void HandleXRCamera() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	FTransform GetCameraTransformOverride() const;

	UFUNCTION(BlueprintCallable)
	void SetCameraTransformOverride(const FTransform& transform, bool bResetQuickTurn);

	void AddQuickTurn(double deltaYaw);

	UFUNCTION(BlueprintCallable)
	void SetQuickTurn(double yaw);
};