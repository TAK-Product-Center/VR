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

public:
	/* only effects VR camera */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
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
};