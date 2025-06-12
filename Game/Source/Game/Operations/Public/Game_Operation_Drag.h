#pragma once

// Parent Includes
#include "Developer_Operation.h"

// Engine Includes
#include "Engine/EngineBaseTypes.h"

// Generated Includes
#include "Game_Operation_Drag.generated.h"

class AGame_Tool;

UCLASS()
class GAME_API UGame_Operation_Drag : public UDeveloper_Operation
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	UPROPERTY()
	AActor* DraggedActor;

	UPROPERTY()
	AGame_Tool* DraggingTool;

	FVector DragOffset;

	bool bStopOnRightMouseDown;

private:
	double OperationStartTime;

	bool bDelayTimerFinished;

	EMouseCaptureMode MouseCaptureMode;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Operation_Drag(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void PostStart() override;

	virtual void PostStop() override;

	virtual void PostTick(float deltaSeconds) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	AActor* GetDraggedActor() const;

	AGame_Tool* GetDraggingTool() const;

	UFUNCTION(BlueprintCallable)
	virtual void StartDrag(AActor* actor, AGame_Tool* tool, double delaySeconds);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual bool GetDragLocation(FVector& dragLocation) const;

	virtual void PostStartDragInternal();

private:
	void StartDragInternal();
};