#pragma once

// Parent Includes
#include "Game_Operation_Drag.h"

// Generated Includes
#include "Game_Operation_Drag_Teleport.generated.h"

UCLASS()
class GAME_API UGame_Operation_Drag_Teleport : public UGame_Operation_Drag
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FRotator InitialToolRotation;

	FRotator InitialTeleportPreviewRotation;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Operation_Drag_Teleport(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void ActionInput_Implementation(const FInputActionInstance& inputActionInstance) override;
	
	virtual void StartDrag(AActor* actor, AGame_Tool* tool, double delaySeconds) override;

protected:
	virtual void PostTick(float deltaSeconds) override;

	virtual bool GetDragLocation(FVector& dragLocation) const override;
};