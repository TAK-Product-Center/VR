#pragma once

// Parent Includes
#include "Game_TransformBaseComponent.h"

// Generated Includes
#include "Game_RotationComponent.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_RotationComponent : public UGame_TransformBaseComponent
{
	GENERATED_BODY()
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_RotationComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void UpdateComponentRotation() override;

	virtual void PerformTransform() override;
};
