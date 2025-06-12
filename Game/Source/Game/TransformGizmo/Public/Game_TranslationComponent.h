#pragma once

// Parent Includes
#include "Game_TransformBaseComponent.h"

// Generated Includes
#include "Game_TranslationComponent.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_TranslationComponent : public UGame_TransformBaseComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TranslationComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void UpdateComponentRotation() override;

	virtual void PerformTransform() override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void CalculateNormalAndDirection(FVector& planeNormal, FVector& targetDirection);
};
